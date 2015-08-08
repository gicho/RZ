/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2015 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/

#include "assembler_macros.h"

    MODULE ASM_MACROS_MOD
    SECTION ASM_MACROS:CODE:NOROOT(4)
    ARM
  
   	PUBLIC L1_D_CacheOperation_asm
   	PUBLIC L1_I_CacheInvalidate_asm

   	PUBLIC L1D_PrefetchDisable_asm
   	PUBLIC L1D_PrefetchEnable_asm

   	PUBLIC L1_DisableBranchPrediction_asm
   	PUBLIC L1_EnableBranchPrediction_asm

   	PUBLIC L1_D_CacheDisable_asm
	PUBLIC L1_D_CacheEnable_asm

   	PUBLIC L1_I_CacheDisable_asm
   	PUBLIC L1_I_CacheEnable_asm

	PUBLIC clean_dcache_range_asm
	PUBLIC invalidate_dcache_range_asm
	PUBLIC clean_invalidate_dcache_range_asm    
        
        
/* Standard definitions of CPSR bits */
V_BIT EQU 0x2000
I_BIT EQU 0x1000
Z_BIT EQU 0x800
C_BIT EQU 0x4
A_BIT EQU 0x2
M_BIT EQU 0x1

/*
	Clear V bit 13 to set low vectors
    Clear I bit 12 to disable I Cache
    Clear Z bit 11 to disable flow prediction
    Clear C bit  2 to disable D Cache
    Clear A bit  1 to disable strict alignment
    Clear M bit  0 to disable MMU
*/


/******************************************************************************
* Function Name : L1_D_CacheOperationAsm
* Description   : r0 = 0 : DCISW. Invalidate data or unified cache line by set/way.
*               : r0 = 1 : DCCSW. Clean data or unified cache line by set/way.
*               : r0 = 2 : DCCISW. Clean and Invalidate data or unified cache line by set/way.
*******************************************************************************/
L1_D_CacheOperation_asm: 

    PUSH {r4-r11}

    MRC  p15, 1, r6, c0, c0, 1      ;; Read CLIDR
    ANDS r3, r6, #0x07000000        ;; Extract coherency level
    MOV  r3, r3, LSR #23            ;; Total cache levels << 1
    BEQ  Finished                   ;; If 0, no need to clean

    MOV  r10, #0                    ;; R10 holds current cache level << 1
Loop1:
    ADD  r2, r10, r10, LSR #1       ;; R2 holds cache "Set" position
    MOV  r1, r6, LSR r2             ;; Bottom 3 bits are the Cache-type for this level
    AND  r1, r1, #7                 ;; Isolate those lower 3 bits
    CMP  r1, #2
    BLT  Skip                       ;; No cache or only instruction cache at this level

    MCR  p15, 2, r10, c0, c0, 0     ;; Write the Cache Size selection register (CSSELR)
    ISB                             ;; ISB to sync the change to the CacheSizeID reg
    MRC  p15, 1, r1, c0, c0, 0      ;; Reads current Cache Size ID register (CCSIDR)
    AND  r2, r1, #7                 ;; Extract the line length field
    ADD  r2, r2, #4                 ;; Add 4 for the line length offset (log2 16 bytes)
    LDR  r4, =0x3FF
    ANDS r4, r4, r1, LSR #3         ;; R4 is the max number on the way size (right aligned)
    CLZ  r5, r4                     ;; R5 is the bit position of the way size increment
    LDR  r7, =0x7FFF
    ANDS r7, r7, r1, LSR #13        ;; R7 is the max number of the index size (right aligned)
Loop2:
    MOV  r9, r4                     ;; R9 working copy of the max way size (right aligned)

Loop3:
    ORR  r11, r10, r9, LSL r5       ;; Factor in the Way number and cache number into R11
    ORR  r11, r11, r7, LSL r2       ;; Factor in the Set number
    CMP  r0, #0
    BNE  Dccsw
    MCR  p15, 0, r11, c7, c6, 2     ;; Invalidate by Set/Way (DCISW)
    B    Count
Dccsw:
    CMP  r0, #1
    BNE  Dccisw
    MCR  p15, 0, r11, c7, c10, 2    ;; Clean by set/way (DCCSW)
    B    Count
Dccisw:
    MCR  p15, 0, r11, c7, c14, 2    ;; Clean and Invalidate by set/way (DCCISW)
Count:
    SUBS r9, r9, #1                 ;; Decrement the Way number
    BGE  Loop3
    SUBS r7, r7, #1                 ;; Decrement the Set number
    BGE  Loop2
Skip:
    ADD  r10, r10, #2               ;; increment the cache number
    CMP  r3, r10
    BGT  Loop1

Finished:
    DSB
    POP  {r4-r11}
    BX   lr


/******************************************************************************
 * Function Name : L1_I_CacheInvalidate
 * Description   : Invalidate all instruction caches to PoU.
******************************************************************************/
L1_I_CacheInvalidate_asm:

    MOV  r0, #0
    MCR  p15, 0, r0, c7, c5, 0
    DSB
    ISB

    BX   lr

/******************************************************************************
* Function Name : L1_I_CacheEnableAsm
* Description   : Enable instruction caches.
******************************************************************************/
L1_I_CacheEnable_asm:

    MRC  p15, 0, r0, c1, c0, 0       ;Read CP15 register 1
    ORR  r0, r0, #(I_BIT)            ;Enable I Cache
    MCR  p15, 0, r0, c1, c0, 0       ;Write CP15 register 1

    BX   lr

/******************************************************************************
 Function Name : L1_I_CacheDisableAsm
 Description   : Disable instruction caches.
******************************************************************************/
L1_I_CacheDisable_asm:

    MRC  p15, 0, r0, c1, c0, 0          ;; Read CP15 register 1
    BIC  r0, r0, #(0x1 << 12)           ;; Disable I Cache
    MCR  p15, 0, r0, c1, c0, 0          ;; Write CP15 register 1
    ISB

    BX   lr

/******************************************************************************
 Function Name : L1_D_CacheEnableAsm
 Description   : Enable data caches.
******************************************************************************/
L1_D_CacheEnable_asm:

    ;; D-cache is controlled by bit 2

    MRC  p15, 0, r0, c1, c0, 0          ;; Read CP15 register 1
    ORR  r0, r0, #(0x1 << 2)            ;; Enable D Cache
    MCR  p15, 0, r0, c1, c0, 0          ;; Write CP15 register 1

    BX   lr

/******************************************************************************
 Function Name : L1_D_CacheDisableAsm
 Description   : Disable data caches.
******************************************************************************/
L1_D_CacheDisable_asm: 

    ;; D-cache is controlled by bit 2

    MRC  p15, 0, r0, c1, c0, 0          ;; Read CP15 register 1
    BIC  r0, r0, #(0x1 << 2)            ;; Disable D Cache
    MCR  p15, 0, r0, c1, c0, 0          ;; Write CP15 register 1
    ISB

    BX   lr

/******************************************************************************
 Function Name : L1_EnableBranchPrediction_asm
 Description   : Enable program flow prediction.
******************************************************************************/
L1_EnableBranchPrediction_asm: 

    ;; Turning on branch prediction requires a general enable
    ;; CP15, c1. Control Register

    ;; Bit 11 [Z] bit Program flow prediction:
    ;; 0 = Program flow prediction disabled
    ;; 1 = Program flow prediction enabled.

    MRC  p15, 0, r0, c1, c0, 0          ;; Read System Control Register
    ORR  r0, r0, #(Z_BIT)
    MCR  p15, 0, r0, c1, c0, 0          ;; Write System Control Register
    ISB

    BX   lr

/******************************************************************************
 Function Name : L1_DisableBranchPrediction_asm
 Description   : Disable program flow prediction.
******************************************************************************/
L1_DisableBranchPrediction_asm:

    MRC  p15, 0, r0, c1, c0, 0          ;; Read System Control Register
    BIC  r0, r0, #(Z_BIT)
    MCR  p15, 0, r0, c1, c0, 0          ;; Write System Control Register

    BX   lr

/******************************************************************************
 Function Name : L1PrefetchEnableAsm
 Description   : Enable Dside prefetch.
******************************************************************************/
L1D_PrefetchEnable_asm: 

    MRC  p15, 0, r0, c1, c0, 1          ;; Read Auxiliary Control Register
    ORR  r0, r0, #(0x1 << 2)            ;; Enable Dside prefetch
    MCR  p15, 0, r0, c1, c0, 1          ;; Write Auxiliary Control Register
    ISB

    BX   lr

/******************************************************************************
 Function Name : L1PrefetchDisableAsm
 Description   : Disable Dside prefetch
******************************************************************************/
L1D_PrefetchDisable_asm: 

    MRC  p15, 0, r0, c1, c0, 1          ;; Read Auxiliary Control Register
    BIC  r0, r0, #(0x1 << 2)            ;; Disable Dside prefetch
    MCR  p15, 0, r0, c1, c0, 1          ;; Write Auxiliary Control Register

    BX   lr


/*******************************************************************************
*
* constant definitions
*
********************************************************************************/
/*
 * dcache_line_size - get the minimum D-cache line size from the CTR register
 * on ARMv7.
 */

dcache_line_size macro reg tmp
	mrc	p15, 0, tmp, c0, c0, 1	; read ctr
	lsr	tmp, tmp, #16
	and	tmp, tmp, #0xf		; cache line size encoding
	mov	reg, #4			; bytes per word
	mov	reg, reg, lsl tmp	; actual cache line size
        endm
/*        
	.macro	dcache_line_size reg, tmp
	mrc	p15, 0, \tmp, c0, c0, 1		; read ctr
	lsr	\tmp, \tmp, #16
	and	\tmp, \tmp, #0xf		; cache line size encoding
	mov	\reg, #4			; bytes per word
	mov	\reg, \reg, lsl \tmp		; actual cache line size
	.endm
*/
/*
 * icache_line_size - get the minimum I-cache line size from the CTR register
 * on ARMv7.
 */

icache_line_size macro reg tmp
	mrc	p15, 0, tmp, c0, c0, 1	; read ctr
	and	tmp, tmp, #0xf		; cache line size encoding
	mov	reg, #4			; bytes per word
	mov	reg, reg, lsl tmp	; actual cache line size
        endm 

/*
	.macro	icache_line_size, reg, tmp
	mrc	p15, 0, \tmp, c0, c0, 1		; read ctr
	and	\tmp, \tmp, #0xf		; cache line size encoding
	mov	\reg, #4			; bytes per word
	mov	\reg, \reg, lsl \tmp		; actual cache line size
	.endm
*/


/*******************************************************************************
 *	clean_dcache_range(start,end)
 *
 *	Used to clean a range of virtual addresses in data cache
 *
 *	start: virtual start address of cached region
 *	end: virtual end address of cached region
 *
********************************************************************************/
clean_dcache_range_asm:

	dcache_line_size r2, r3
	sub	r3, r2, #1
	bic	r0, r0, r3
	dsb
	nop

_loop_clean_dcache_range:

	mcr	p15, 0, r0, c7, c10, 1		; clean line by VA
	add	r0, r0, r2
	cmp	r0, r1
	blo	_loop_clean_dcache_range
	dsb
	mov	pc, lr

/*******************************************************************************
 *	invalidate_dcache_range(start,end)
 *
 *	Used to invalidate a range of virtual addresses in data cache
 *
 *	start: virtual start address of cached region
 *	end: virtual end address of cached region
 *
********************************************************************************/
invalidate_dcache_range_asm:
/*
	dcache_line_size r2, r3
	sub	r3, r2, #1
	tst	r0, r3
	bic	r0, r0, r3
    dsb
	nop
	mcrne	p15, 0, r0, c7, c14, 1		 clean & invalidate D / U line
	tst	r1, r3
	bic	r1, r1, r3
	mcrne	p15, 0, r1, c7, c14, 1		 clean & invalidate D / U line
*/
	dcache_line_size r2, r3
	sub	r3, r2, #1
	bic	r0, r0, r3
	dsb
	nop

_loop_invalidate_dcache_range:

	mcr	p15, 0, r0, c7, c6, 1		; invalidate D / U line
	add	r0, r0, r2
	cmp	r0, r1
	blo	_loop_invalidate_dcache_range
	dsb
	mov	pc, lr


/*******************************************************************************
 *	clean_invalidate_dcache_range(start,end)
 *
 *	Used to clean and invalidate a range of virtual addresses in data cache
 *
 *	start: virtual start address of cached region
 *	end: virtual end address of cached region
 *
********************************************************************************/
clean_invalidate_dcache_range_asm:

	dcache_line_size r2, r3
	sub	r3, r2, #1
	bic	r0, r0, r3
	dsb
	nop

_loop_clean_invalidate_dcache_range:

	mcr	p15, 0, r0, c7, c14, 1		; clean line by VA
	add	r0, r0, r2
	cmp	r0, r1
	blo	_loop_clean_invalidate_dcache_range
	dsb
	mov	pc, lr



/*******************************************************************************
 *	flush_dcache_range()
 *
 *	Used to flush a range of virtual addresses in data cache
 *
 *	start: virtual start address of cached region
 *	end: virtual end address of cached region
 *
********************************************************************************/
flush_dcache_range:

	dcache_line_size r2, r3
	sub	r3, r2, #1
	bic	r0, r0, r3
	dsb
	nop

_loop_flush_dcache_range:

	mcr	p15, 0, r0, c7, c14, 1		; clean & invalidate D / U line
	add	r0, r0, r2
	cmp	r0, r1
	blo	_loop_flush_dcache_range
	dsb
	mov	pc, lr


/*******************************************************************************
 *	flush_icache()
 *
 *	Used to flush the complete instruction cache
********************************************************************************/
flush_icache:

    mov	r0, #0
	mcr	p15, 0, r0, c7, c1, 0		; invalidate instruction cache inner shareable
	mcr	p15, 0, r0, c7, c5, 0		; instruction and BTB cache invalidate
	mov	pc, lr

/*******************************************************************************
 *	flush_lou_dcache()
 *
 *	Used to flush the complete data cache up to the level of unification
 *
********************************************************************************/
flush_lou_dcache:

	dmb							; ensure ordering with previous memory accesses
	mrc	p15, 1, r0, c0, c0, 1	; read clidr, r0 = clidr
	ands r3, r0, #(7 << 21)  	; extract LoUIS from clidr
	ands r3, r0, #(7 << 27) 	; extract LoUU from clidr
	mov	r3, r3, lsr #20 		; r3 = LoUIS * 2
	mov	r3, r3, lsr #26 		; r3 = LoUU * 2
	moveq pc, lr				; return if level == 0
	mov	r10, #0					; r10 (starting level) = 0
	b	flush_levels			; start flushing cache levels


/*******************************************************************************
 *	flush_dcache()
 *
 *	Used to flush the complete data cache
 *
********************************************************************************/
flush_dcache:

	dmb							; ensure ordering with previous memory accesses
	mrc	p15, 1, r0, c0, c0, 1	; read clidr
	ands	r3, r0, #0x7000000	; extract loc from clidr
	mov	r3, r3, lsr #23			; left align loc bit field
	beq	finished				; if loc is 0, then no need to clean
	mov	r10, #0					; start clean at cache level 0

flush_levels:
	add	r2, r10, r10, lsr #1	; work out 3x current cache level
	mov	r1, r0, lsr r2			; extract cache type bits from clidr
	and	r1, r1, #7				; mask of the bits for current cache only
	cmp	r1, #2					; see what cache we have at this level
	blt	skip					; skip if no cache, or just i-cache

	mcr	p15, 2, r10, c0, c0, 0	; select current cache level in cssr
	isb							; isb to sych the new cssr&csidr
	mrc	p15, 1, r1, c0, c0, 0	; read the new csidr

        and	r2, r1, #7				; extract the length of the cache lines
	add	r2, r2, #4				; add 4 (line length offset)
	ldr	r4, =0x3ff
	ands	r4, r4, r1, lsr #3	; find maximum number on the way size
	clz	r5, r4					; find bit position of way size increment
	ldr	r7, =0x7fff
	ands	r7, r7, r1, lsr #13	; extract max number of the index size
loop1:
	mov	r9, r4					; create working copy of max way size
loop2:
    orr	r11, r10, r9, lsl r5	; factor way and cache number into r11
    orr	r11, r11, r7, lsl r2	; factor index number into r11
	mcr	p15, 0, r11, c7, c14, 2	; clean & invalidate by set/way
	subs	r9, r9, #1			; decrement the way
	bge	loop2
	subs	r7, r7, #1			; decrement the index
	bge	loop1
skip:
	add	r10, r10, #2			; increment cache number
	cmp	r3, r10
	bgt	flush_levels
finished:
	mov	r10, #0					; swith back to cache level 0
	mcr	p15, 2, r10, c0, c0, 0	; select current cache level in cssr
	dsb
	isb
	mov	pc, lr


/*******************************************************************************
 *	flush_cache()
 *
 *	Used to flush the complete data and instruction cache
 *
 *  The data cache flush is now achieved using atomic clean / invalidates
 *  working outwards from L1 cache. This is done using Set/Way based cache
 *  maintenance instructions.
 *  The instruction cache can still be invalidated back to the point of
 *  unification in a single instruction.
 *
********************************************************************************/
flush_cache:

	stmfd	sp!, {r4-r5, r7, r9-r11, lr}
	bl	flush_dcache
	mov	r0, #0
	mcr	p15, 0, r0, c7, c1, 0	; invalidate I-cache inner shareable
	mcr	p15, 0, r0, c7, c5, 0	; I+BTB cache invalidate
        ldmfd	sp!, {r4-r5, r7, r9-r11, lr}
	mov	pc, lr

/*******************************************************************************
 *	flush_lou_cache()
 *
 *	Used to flush the complete data cache up tp the level of unification
 *  Invalidates the instruction cache to the point of unification
 *
********************************************************************************/
flush_lou_cache:

	stmfd	sp!, {r4-r5, r7, r9-r11, lr}

	bl	flush_lou_dcache
	mov	r0, #0
	mcr	p15, 0, r0, c7, c1, 0	; invalidate I-cache inner shareable
	mcr	p15, 0, r0, c7, c5, 0	; I+BTB cache invalidate
	ldmfd	sp!, {r4-r5, r7, r9-r11, lr}
	mov	pc, lr


/*******************************************************************************
 *	make_memory_coherent(start,end)
 *
 *	Ensure coherency among instruction and data caches
 *  Used when code gets copied into a memory region
 *
 *	start: virtual start address of cached region
 *	end: virtual end address of cached region
 *
********************************************************************************/
make_memory_coherent:

	dcache_line_size r2, r3
	sub	r3, r2, #1
	bic	r12, r0, r3
ONE:
    mcr	p15, 0, r12, c7, c11, 1	 	; clean D line to the point of unification
	add	r12, r12, r2
	cmp	r12, r1
	blo	ONE
	dsb
	icache_line_size r2, r3
	sub	r3, r2, #1
	bic	r12, r0, r3
TWO:
    mcr	p15, 0, r12, c7, c5, 1	 	; invalidate I line
	add	r12, r12, r2
	cmp	r12, r1
	blo	TWO
	mov	r0, #0
	mcr	p15, 0, r0, c7, c1, 6	; invalidate BTB Inner Shareable
	mcr	p15, 0, r0, c7, c5, 6	; invalidate BTB
	dsb
	isb
	mov	pc, lr

        END



/* end of file */


