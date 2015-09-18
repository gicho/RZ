/*
* Copyright 2015 Giancarlo Parodi
* 
* l1_cache.h
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
#ifndef L1_CACHE_H
#define L1_CACHE_H

#include <stdint.h>
#include "assembler_macros.h"

extern void L1_CachesEnable(void);	/* enables all caches (I,D), branch prediction, D-Side prefetch */

extern void L1D_CacheDisable(void);
extern void L1D_CacheEnable(void);

extern void L1D_CacheInvalidate(void);
extern void L1D_CacheClean(void);
extern void L1D_CacheCleanAndInvalidate(void);

extern void L1D_CacheInvalidateRange(const uint32_t start, const uint32_t end);
extern void L1D_CacheCleanRange(const uint32_t start, const uint32_t end);
extern void L1D_CacheCleanAndInvalidateRange(const uint32_t start, const uint32_t end);

extern void L1I_CacheInvalidate(void);
extern void L1I_CacheDisable(void);
extern void L1I_CacheEnable(void);

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

