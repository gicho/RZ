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
#ifndef _L1_CACHE_H_
#define _L1_CACHE_H_

#include "assembler_macros.h"

extern void L1CachesEnable(void);
extern void flush_cache(void);
extern void dcache_clean_all();


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
extern void dma_buffer_issue(uint32_t start, uint32_t size, uint32_t dir);


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
extern void dma_buffer_reclaim(uint32_t start, uint32_t size, uint32_t dir);

#endif /* _L1_CACHE_H_ */

