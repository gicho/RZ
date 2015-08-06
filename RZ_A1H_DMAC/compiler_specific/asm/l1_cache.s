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


/*******************************************************************************
 *	flush_dcache()
 *
 *	Used to flush the complete data cache
 *
********************************************************************************/
   .globl dcache_clean_all
   .align 4

dcache_clean_all:

	dmb							@ ensure ordering with previous memory accesses
	mrc	p15, 1, r0, c0, c0, 1	@ read clidr
	ands	r3, r0, #0x7000000	@ extract loc from clidr
	mov	r3, r3, lsr #23			@ left align loc bit field, cache level value
	beq	finished_clean			@ if loc is 0, then no need to clean
	mov	r10, #0					@ start clean at cache level 0

loop1_clean:
	add	r2, r10, r10, lsr #1	@ work out 3x current cache level
	mov	r1, r0, lsr r2			@ bottom 3 bits are the cache type for this level
	and	r1, r1, #7				@ mask of the bits for current cache only
	cmp	r1, #2					@ see what cache we have at this level
	blt	skip_clean  			@ skip if no cache, or just i-cache (2= data cache only, 3= separate i&d, 4= unified)

	mcr	p15, 2, r10, c0, c0, 0	@ select current cache level in cssr, write CSSELR
	isb							@ isb to sych the new CCSIDR
	mrc	p15, 1, r1, c0, c0, 0	@ read the new CCSIDR

	and	r2, r1, #7				@ extract the length of the cache lines
	add	r2, r2, #4				@ add 4 for the line length offset (log2 16 bytes)
	ldr	r4, =0x3ff
	ands	r4, r4, r1, lsr #3	@ R4: find maximum number on the way size
	clz	r5, r4					@ R5: find bit position of way size increment
	mov	r9, r4					@ create working copy of max way size
loop2_clean:
	ldr	r7, =0x00007fff
	ands	r7, r7, r1, lsr #13	@ R7: extract max number of the index size
loop3_clean:
    orr	r11, r10, r9, lsl r5	@ factor way and cache number into r11
    orr	r11, r11, r7, lsl r2	@ factor index number into r11
	mcr	p15, 0, r11, c7, c10, 2	@ DCCSW, clean by set/way
	subs	r7, r7, #1			@ decrement the index
	bge	loop3_clean
	subs	r9, r9, #1			@ decrement the way
	bge	loop2_clean
skip_clean:
	add	r10, r10, #2			@ increment cache number
	cmp	r3, r10
	bgt	loop1_clean
	dsb
finished_clean:
	mov	r10, #0					@ switch back to cache level 0
	mcr	p15, 2, r10, c0, c0, 0	@ select current cache level in cssr
	dsb
	isb
	mov	pc, lr

  	.type dcache_clean_invalidate_all , %function
  	.align 4



/*
 * dcache_line_size - get the minimum D-cache line size from the CTR register
 * on ARMv7.
 */
	.macro	dcache_line_size reg, tmp
	mrc	p15, 0, \tmp, c0, c0, 1		@ read ctr
	lsr	\tmp, \tmp, #16
	and	\tmp, \tmp, #0xf		@ cache line size encoding
	mov	\reg, #4			@ bytes per word
	mov	\reg, \reg, lsl \tmp		@ actual cache line size
	.endm

/*
 * icache_line_size - get the minimum I-cache line size from the CTR register
 * on ARMv7.
 */
	.macro	icache_line_size, reg, tmp
	mrc	p15, 0, \tmp, c0, c0, 1		@ read ctr
	and	\tmp, \tmp, #0xf		@ cache line size encoding
	mov	\reg, #4			@ bytes per word
	mov	\reg, \reg, lsl \tmp		@ actual cache line size
	.endm


	.text
	.code 32

/*******************************************************************************
*
* constant definitions
*
********************************************************************************/

	.equiv DMA_FROM_DEVICE,1
	.equiv DMA_TO_DEVICE,2



/*******************************************************************************
 *	dma_buffer_issue(start,size,direction)
 *
 *	Used by the CPU to provide a buffer to the dma controller
 *
 *	start: virtual start address of cached region
 *	size: size of the memory region
 *	direction: DMA_FROM_DEVICE or DMA_TO_DEVICE
 *
 *	if the dma needs to transfer data from memory to a device, the CPU needs to
 *	write back any buffer content that might be in L1 cache
 *
 *  if the dma needs to transfer data from a device to memory, the CPU needs to
 *	invalidate any old data still in L1 cache
 *
********************************************************************************/
   	.globl dma_buffer_issue
  	.align 4

dma_buffer_issue:

	add	r1, r1, r0				@ calculate the end address in r1
	teq	r2, #DMA_FROM_DEVICE	@ check the direction
	beq	invalidate_dcache_range	@ if 'from device', invalidate data in L1 cache
	b	clean_dcache_range		@ otherwise if 'to device', write back CPU data in L1 before transfer

  	.type dma_buffer_issue , %function
  	.align 4

/*******************************************************************************
 *	dma_buffer_reclaim(start,size,direction)
 *
 *	Used by the CPU to reclaim a buffer from the dma controller
 *
 *	start: virtual start address of cached region
 *	size: size of the memory region
 *	direction: DMA_FROM_DEVICE or DMA_TO_DEVICE
 *
 *	if the dma has transferred from memory to a device, the CPU does not need to
 *	do anything since the data has been written back before issuing the buffer
 *  any new access to the buffer will be cached again as necessary
 *
 *  if the dma has transferred data from a device to memory, now the CPU needs to
 *	invalidate any old data still in L1 cache
 *
********************************************************************************/
   	.globl dma_buffer_reclaim
  	.align 4

dma_buffer_reclaim:

	add	r1, r1, r0				@ calculate the end address in r1
	teq	r2, #DMA_TO_DEVICE		@ check the direction
	bne	invalidate_dcache_range	@ if 'from device', invalidate data in L1 cache
	mov	pc, lr

  	.type dma_buffer_reclaim , %function
  	.align 4


/*******************************************************************************
 *	clean_dcache_range(start,end)
 *
 *	Used to clean a range of virtual addresses in data cache
 *
 *	start: virtual start address of cached region
 *	end: virtual end address of cached region
 *
********************************************************************************/
   	.globl clean_dcache_range
  	.align 4

clean_dcache_range:

	dcache_line_size r2, r3
	sub	r3, r2, #1
	bic	r0, r0, r3
	dsb
	nop

_loop_clean_dcache_range:

	mcr	p15, 0, r0, c7, c10, 1		@ clean D / U line
	add	r0, r0, r2
	cmp	r0, r1
	blo	_loop_clean_dcache_range
	dsb
	mov	pc, lr

  	.type clean_dcache_range , %function
  	.align 4


/*******************************************************************************
 *	invalidate_dcache_range(start,end)
 *
 *	Used to invalidate a range of virtual addresses in data cache
 *
 *	start: virtual start address of cached region
 *	end: virtual end address of cached region
 *
********************************************************************************/
   	.globl invalidate_dcache_range
  	.align 4

invalidate_dcache_range:

	dcache_line_size r2, r3
	sub	r3, r2, #1
	tst	r0, r3
	bic	r0, r0, r3
    dsb
	nop
	mcrne	p15, 0, r0, c7, c14, 1		@ clean & invalidate D / U line
	tst	r1, r3
	bic	r1, r1, r3
	mcrne	p15, 0, r1, c7, c14, 1		@ clean & invalidate D / U line

_loop_invalidate_dcache_range:

	mcr	p15, 0, r0, c7, c6, 1		@ invalidate D / U line
	add	r0, r0, r2
	cmp	r0, r1
	blo	_loop_invalidate_dcache_range
	dsb
	mov	pc, lr

  	.type invalidate_dcache_range , %function
  	.align 4

/*******************************************************************************
 *	flush_dcache_range()
 *
 *	Used to flush a range of virtual addresses in data cache
 *
 *	start: virtual start address of cached region
 *	end: virtual end address of cached region
 *
********************************************************************************/
   	.globl flush_dcache_range
  	.align 4

flush_dcache_range:

	dcache_line_size r2, r3
	sub	r3, r2, #1
	bic	r0, r0, r3
	dsb
	nop

_loop_flush_dcache_range:

	mcr	p15, 0, r0, c7, c14, 1		@ clean & invalidate D / U line
	add	r0, r0, r2
	cmp	r0, r1
	blo	_loop_flush_dcache_range
	dsb
	mov	pc, lr

  	.type flush_dcache_range , %function
  	.align 4



/*******************************************************************************
 *	flush_icache()
 *
 *	Used to flush the complete instruction cache
********************************************************************************/
   .globl flush_icache
   .align 4

flush_icache:

    mov	r0, #0
	mcr	p15, 0, r0, c7, c1, 0		@ invalidate instruction cache inner shareable
	mcr	p15, 0, r0, c7, c5, 0		@ instruction and BTB cache invalidate
	mov	pc, lr

  	.type flush_icache , %function
  	.align 4

/*******************************************************************************
 *	flush_lou_dcache()
 *
 *	Used to flush the complete data cache up to the level of unification
 *
********************************************************************************/

   .globl flush_lou_dcache
   .align 4

flush_lou_dcache:

	dmb							@ ensure ordering with previous memory accesses
	mrc	p15, 1, r0, c0, c0, 1	@ read clidr, r0 = clidr
	ands r3, r0, #(7 << 21)  	@ extract LoUIS from clidr
	ands r3, r0, #(7 << 27) 	@ extract LoUU from clidr
	mov	r3, r3, lsr #20 		@ r3 = LoUIS * 2
	mov	r3, r3, lsr #26 		@ r3 = LoUU * 2
	moveq pc, lr				@ return if level == 0
	mov	r10, #0					@ r10 (starting level) = 0
	b	flush_levels			@ start flushing cache levels

  	.type flush_lou_dcache , %function
  	.align 4


/*******************************************************************************
 *	flush_dcache()
 *
 *	Used to flush the complete data cache
 *
********************************************************************************/
   .globl flush_dcache
   .align 4

flush_dcache:

	dmb							@ ensure ordering with previous memory accesses
	mrc	p15, 1, r0, c0, c0, 1	@ read clidr
	ands	r3, r0, #0x7000000	@ extract loc from clidr
	mov	r3, r3, lsr #23			@ left align loc bit field
	beq	finished				@ if loc is 0, then no need to clean
	mov	r10, #0					@ start clean at cache level 0

flush_levels:
	add	r2, r10, r10, lsr #1	@ work out 3x current cache level
	mov	r1, r0, lsr r2			@ extract cache type bits from clidr
	and	r1, r1, #7				@ mask of the bits for current cache only
	cmp	r1, #2					@ see what cache we have at this level
	blt	skip					@ skip if no cache, or just i-cache

@#ifdef CONFIG_PREEMPT
@	save_and_disable_irqs_notrace r9	@ make cssr&csidr read atomic
@#endif

	mcr	p15, 2, r10, c0, c0, 0	@ select current cache level in cssr
	isb							@ isb to sych the new cssr&csidr
	mrc	p15, 1, r1, c0, c0, 0	@ read the new csidr
@#ifdef CONFIG_PREEMPT
@	restore_irqs_notrace r9
@#endif
	and	r2, r1, #7				@ extract the length of the cache lines
	add	r2, r2, #4				@ add 4 (line length offset)
	ldr	r4, =0x3ff
	ands	r4, r4, r1, lsr #3	@ find maximum number on the way size
	clz	r5, r4					@ find bit position of way size increment
	ldr	r7, =0x7fff
	ands	r7, r7, r1, lsr #13	@ extract max number of the index size
loop1:
	mov	r9, r4					@ create working copy of max way size
loop2:
    orr	r11, r10, r9, lsl r5	@ factor way and cache number into r11
    orr	r11, r11, r7, lsl r2	@ factor index number into r11
	mcr	p15, 0, r11, c7, c14, 2	@ clean & invalidate by set/way
	subs	r9, r9, #1			@ decrement the way
	bge	loop2
	subs	r7, r7, #1			@ decrement the index
	bge	loop1
skip:
	add	r10, r10, #2			@ increment cache number
	cmp	r3, r10
	bgt	flush_levels
finished:
	mov	r10, #0					@ swith back to cache level 0
	mcr	p15, 2, r10, c0, c0, 0	@ select current cache level in cssr
	dsb
	isb
	mov	pc, lr

  	.type flush_dcache , %function
  	.align 4

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
   .globl flush_cache
   .align 4

flush_cache:

	stmfd	sp!, {r4-r5, r7, r9-r11, lr}
	bl	flush_dcache
	mov	r0, #0
	mcr	p15, 0, r0, c7, c1, 0	@ invalidate I-cache inner shareable
	mcr	p15, 0, r0, c7, c5, 0	@ I+BTB cache invalidate
    ldmfd	sp!, {r4-r5, r7, r9-r11, lr}
	mov	pc, lr

  	.type flush_cache , %function
  	.align 4

/*******************************************************************************
 *	flush_lou_cache()
 *
 *	Used to flush the complete data cache up to the level of unification
 *  Invalidates the instruction cache to the point of unification
 *
********************************************************************************/
   .globl flush_lou_cache
   .align 4

flush_lou_cache:

	stmfd	sp!, {r4-r5, r7, r9-r11, lr}

	bl	flush_lou_dcache
	mov	r0, #0
	mcr	p15, 0, r0, c7, c1, 0	@ invalidate I-cache inner shareable
	mcr	p15, 0, r0, c7, c5, 0	@ I+BTB cache invalidate
	ldmfd	sp!, {r4-r5, r7, r9-r11, lr}
	mov	pc, lr

  	.type flush_lou_cache , %function
  	.align 4

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
   .globl make_memory_coherent
   .align 4

make_memory_coherent:

	dcache_line_size r2, r3
	sub	r3, r2, #1
	bic	r12, r0, r3
1:
    mcr	p15, 0, r12, c7, c11, 1	 	@ clean D line to the point of unification
	add	r12, r12, r2
	cmp	r12, r1
	blo	1b
	dsb
	icache_line_size r2, r3
	sub	r3, r2, #1
	bic	r12, r0, r3
2:
    mcr	p15, 0, r12, c7, c5, 1	 	@ invalidate I line
	add	r12, r12, r2
	cmp	r12, r1
	blo	2b
	mov	r0, #0
	mcr	p15, 0, r0, c7, c1, 6	@ invalidate BTB Inner Shareable
	mcr	p15, 0, r0, c7, c5, 6	@ invalidate BTB
	dsb
	isb
	mov	pc, lr

  	.type make_memory_coherent , %function
  	.align 4



/* end of file */


