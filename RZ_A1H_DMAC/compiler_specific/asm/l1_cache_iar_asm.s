/*
* Copyright 2015 Giancarlo Parodi
* 
* l1_cache_iar_asm.s
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*     http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

    MODULE ASM_MACROS_MOD
    SECTION ASM_MACROS:CODE:NOROOT(4)
    ARM
  
    PUBLIC L1_CachesEnable
   	PUBLIC L1D_CacheOperation_asm
   	PUBLIC L1I_CacheInvalidate

   	PUBLIC L1D_PrefetchDisable
   	PUBLIC L1D_PrefetchEnable

   	PUBLIC L1_DisableBranchPrediction
   	PUBLIC L1_EnableBranchPrediction

   	PUBLIC L1D_CacheDisable
	PUBLIC L1D_CacheEnable

   	PUBLIC L1I_CacheDisable
   	PUBLIC L1I_CacheEnable

	PUBLIC L1D_CacheCleanRange
	PUBLIC L1D_CacheInvalidateRange
	PUBLIC L1D_CacheCleanAndInvalidateRange    
        
        
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

/*
* Enable all caches
*/
L1_CachesEnable:

    /* Read CP15 SCTLR */
    MRC  p15, 0, r0, c1, c0, 0

    /* 	Set I bit 12 to enable I Cache
    	Set Z bit 11 to enable flow prediction
    	Set C bit  2 to enable D Cache
    */
    /* 
    * BIC has 8 bit immediate + 4 bit rotation 
    * so cannot address directly above first byte 
    */
    ORR  r0, r0, #(I_BIT)
    ORR  r0, r0, #(Z_BIT)
    ORR  r0, r0, #(C_BIT)
    MCR  p15, 0, r0, c1, c0, 0		     /* Write CP15 register 1 */
    ISB
    
    /* Enable D-side prefetch */
    MRC  p15, 0, r0, c1, c0, 1         /* Read Auxiliary Control Register */
    ORR  r0, r0, #(0x1 << 2)		     /* Enable Dside prefetch */
    MCR  p15, 0, r0, c1, c0, 1	  /* Write Auxiliary Control Register */
    ISB
    BX   lr
    
/*
* Function Name : L1_D_CacheOperationAsm
* Description   : r0 = 0 : DCISW. Invalidate data or unified cache line by set/way.
*               : r0 = 1 : DCCSW. Clean data or unified cache line by set/way.
*               : r0 = 2 : DCCISW. Clean and Invalidate data or unified cache line by set/way.
*/
L1D_CacheOperation_asm: 

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


/*
* Function Name : L1_I_CacheInvalidate
* Description   : Invalidate all instruction caches to PoU.
*/
L1I_CacheInvalidate:

    MOV  r0, #0
    MCR  p15, 0, r0, c7, c5, 0
    DSB
    ISB

    BX   lr

/*
* Function Name : L1_I_CacheEnable
* Description   : Enable instruction caches.
*/
L1I_CacheEnable:

    MRC  p15, 0, r0, c1, c0, 0       ;Read CP15 register 1
    ORR  r0, r0, #(I_BIT)            ;Enable I Cache
    MCR  p15, 0, r0, c1, c0, 0       ;Write CP15 register 1

    BX   lr

/*
* Function Name : L1_I_CacheDisable
* Description   : Disable instruction caches.
*/
L1I_CacheDisable:

    MRC  p15, 0, r0, c1, c0, 0          ;; Read CP15 register 1
    BIC  r0, r0, #(0x1 << 12)           ;; Disable I Cache
    MCR  p15, 0, r0, c1, c0, 0          ;; Write CP15 register 1
    ISB

    BX   lr

/*
* Function Name : L1_D_CacheEnable
* Description   : Enable data caches.
*/
L1D_CacheEnable:

    ;; D-cache is controlled by bit 2

    MRC  p15, 0, r0, c1, c0, 0          ;; Read CP15 register 1
    ORR  r0, r0, #(0x1 << 2)            ;; Enable D Cache
    MCR  p15, 0, r0, c1, c0, 0          ;; Write CP15 register 1

    BX   lr

/*
* Function Name : L1_D_CacheDisable
* Description   : Disable data caches.
*/
L1D_CacheDisable: 

    ;; D-cache is controlled by bit 2

    MRC  p15, 0, r0, c1, c0, 0          ;; Read CP15 register 1
    BIC  r0, r0, #(0x1 << 2)            ;; Disable D Cache
    MCR  p15, 0, r0, c1, c0, 0          ;; Write CP15 register 1
    ISB

    BX   lr

/*
* Function Name : L1_EnableBranchPrediction
* Description   : Enable program flow prediction.
*/
L1_EnableBranchPrediction: 

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

/*
* Function Name : L1_DisableBranchPrediction
* Description   : Disable program flow prediction.
*/
L1_DisableBranchPrediction:

    MRC  p15, 0, r0, c1, c0, 0          ;; Read System Control Register
    BIC  r0, r0, #(Z_BIT)
    MCR  p15, 0, r0, c1, c0, 0          ;; Write System Control Register

    BX   lr

/*
* Function Name : L1_PrefetchEnable
* Description   : Enable Dside prefetch.
*/
L1D_PrefetchEnable: 

    MRC  p15, 0, r0, c1, c0, 1          ;; Read Auxiliary Control Register
    ORR  r0, r0, #(0x1 << 2)            ;; Enable Dside prefetch
    MCR  p15, 0, r0, c1, c0, 1          ;; Write Auxiliary Control Register
    ISB

    BX   lr

/*
* Function Name : L1_PrefetchDisable
* Description   : Disable Dside prefetch
*/
L1D_PrefetchDisable: 

    MRC  p15, 0, r0, c1, c0, 1          ;; Read Auxiliary Control Register
    BIC  r0, r0, #(0x1 << 2)            ;; Disable Dside prefetch
    MCR  p15, 0, r0, c1, c0, 1          ;; Write Auxiliary Control Register

    BX   lr

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
*	L1D_CacheCleanRange(start,end)
*
*	Used to clean a range of virtual addresses in data cache
*
*	start: virtual start address of cached region
*	end: virtual end address of cached region
*
*/
L1D_CacheCleanRange:

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
 *	L1D_CacheInvalidateRange(start,end)
 *
 *	Used to invalidate a range of virtual addresses in data cache
 *
 *	start: virtual start address of cached region
 *	end: virtual end address of cached region
 *
********************************************************************************/
L1D_CacheInvalidateRange:
    
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
 *	L1D_CacheCleanAndInvalidateRange(start,end)
 *
 *	Used to clean and invalidate a range of virtual addresses in data cache
 *
 *	start: virtual start address of cached region
 *	end: virtual end address of cached region
 *
********************************************************************************/
L1D_CacheCleanAndInvalidateRange:

	dcache_line_size r2, r3
	sub	r3, r2, #1
	bic	r0, r0, r3
	dsb
	nop

_loop_clean_invalidate_dcache_range:

	mcr	p15, 0, r0, c7, c14, 1		; clean & invalidate line by VA
	add	r0, r0, r2
	cmp	r0, r1
	blo	_loop_clean_invalidate_dcache_range
	dsb
	mov	pc, lr

       
       
    END



/* end of file */


