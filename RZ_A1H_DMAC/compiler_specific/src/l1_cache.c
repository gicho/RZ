/*
* Copyright 2015 Giancarlo Parodi
* 
* l1_cache.c
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

#include "l1_cache.h"


#define L1DCACHE_INVALIDATE  			(0)         /* L1D cache invalidate           */
#define L1DCACHE_CLEAN       			(1)         /* L1D cache clean (write back)   */
#define L1DCACHE_CLEAN_AND_INVALIDATE   (2)         /* L1D cache clean and invalidate */

extern void L1_CachesEnable_asm(void);

extern void L1_D_CacheOperation_asm(const uint32_t parameter);

extern void L1_I_CacheInvalidate_asm(void);
extern void L1_I_CacheEnable_asm(void);
extern void L1_I_CacheDisable_asm(void);

extern void L1_D_CacheEnable_asm(void);
extern void L1_D_CacheDisable_asm(void);

extern void L1D_PrefetchEnable_asm(void);
extern void L1D_PrefetchDisable_asm(void);

extern void L1_EnableBranchPrediction_asm(void);
extern void L1_DisableBranchPrediction_asm(void);

extern void invalidate_dcache_range_asm(uint32_t start, uint32_t end);
extern void clean_dcache_range_asm(uint32_t start, uint32_t end);


void L1_CachesEnable(void) {
	L1_CachesEnable_asm();
}

void L1_D_CacheDisable(void) {
	L1_D_CacheDisable_asm();
}

void L1_D_CacheEnable(void) {
	L1_D_CacheEnable_asm();
}

void L1D_CacheInvalidate(void) {
	L1_D_CacheOperation_asm(L1DCACHE_INVALIDATE);
}

void L1D_CacheClean(void) {
	L1_D_CacheOperation_asm(L1DCACHE_CLEAN);
}

void L1D_CacheCleanAndInvalidate(void) {
	L1_D_CacheOperation_asm(L1DCACHE_CLEAN_AND_INVALIDATE);
}


void L1_I_CacheInvalidate(void) {
	L1_I_CacheInvalidate_asm();
}

void L1_I_CacheDisable(void) {
	L1_I_CacheDisable_asm();
}

void L1_I_CacheEnable(void) {
	L1_I_CacheEnable_asm();
}

void L1D_PrefetchDisable(void) {
	L1D_PrefetchDisable_asm();
}

void L1D_PrefetchEnable(void) {
	L1D_PrefetchEnable_asm();
}

void L1_DisableBranchPrediction(void) {
	L1_DisableBranchPrediction_asm();
}

void L1_EnableBranchPrediction(void) {
	L1_EnableBranchPrediction_asm();
}

void dma_buffer_reclaim(const uint32_t start, const uint32_t size, const uint32_t dir) {
	if(DMA_FROM_DEVICE == dir) invalidate_dcache_range_asm(start, start + size);
	// dma_buffer_reclaim_asm(start, size, dir);
}

void dma_buffer_issue(const uint32_t start, const uint32_t size, const uint32_t dir) {

	if(DMA_FROM_DEVICE == dir) invalidate_dcache_range_asm(start, start + size);
	if(DMA_TO_DEVICE == dir) clean_dcache_range_asm(start, start + size);
	// dma_buffer_issue_asm(start, size, dir);
}


