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

#include <stdint.h>
#include "assembler_macros.h"

/* enables all caches (I,D), branch prediction, D-Side prefetch */
extern void L1_CachesEnable(void);	

extern void L1_D_CacheDisable(void);
extern void L1_D_CacheEnsable(void);

extern void L1D_CacheInvalidate(void);
extern void L1D_CacheClean(void);
extern void L1D_CacheCleanAndInvalidate(void);

extern void L1_I_CacheInvalidate(void);
extern void L1_I_CacheDisable(void);
extern void L1_I_CacheEnable(void);

extern void L1D_PrefetchDisable(void);
extern void L1D_PrefetchEnable(void);

extern void L1_DisableBranchPrediction(void);
extern void L1_EnableBranchPrediction(void);

extern void VbarSet(uint32_t address);


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
extern void dma_buffer_issue(const uint32_t start, const uint32_t size, const uint32_t dir);


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
extern void dma_buffer_reclaim(const uint32_t start, const uint32_t size, const uint32_t dir);

#endif /* _L1_CACHE_H_ */

