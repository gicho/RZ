;/*******************************************************************************
;* DISCLAIMER
;* This software is supplied by Renesas Electronics Corporation and is only
;* intended for use with Renesas products. No other uses are authorized. This
;* software is owned by Renesas Electronics Corporation and is protected under
;* all applicable laws, including copyright laws.
;* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
;* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
;* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
;* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
;* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
;* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
;* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
;* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
;* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
;* Renesas reserves the right, without notice, to make changes to this software
;* and to discontinue the availability of this software. By using this software,
;* you agree to the additional terms and conditions found by accessing the
;* following link:
;* http://www.renesas.com/disclaimer
;* Copyright (C) 2012 - 2015 Renesas Electronics Corporation. All rights reserved.
;*******************************************************************************/

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
}

void dma_buffer_issue(const uint32_t start, const uint32_t size, const uint32_t dir) {

	if(DMA_FROM_DEVICE == dir) invalidate_dcache_range_asm(start, start + size);
	if(DMA_TO_DEVICE == dir) clean_dcache_range_asm(start, start + size);
}


