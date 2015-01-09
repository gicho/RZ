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

#include "l2_cache.h"
#include "l2_cache_pl310.h"

/*
 * min() macros
 */
#define min(x, y) ({				\
	x < y ? x : y; })



static inline void __raw_writel(unsigned long val, volatile void *addr)
{
	__asm__ volatile ("str %1, %0"
		     : "+Qo" (*(volatile unsigned long *)addr)
		     : "r" (val)
		     );
}

#define writel_relaxed(v,c)	__raw_writel(v,c)


#define CACHE_LINE_SIZE		32

static void *l2x0_base = (void*)0x3FFFF000;

static unsigned long l2x0_way_mask = (1 << 8) - 1;/* Bitmask of active ways */
static unsigned long l2x0_size = 0x20000l; /* 128 KBytes L2C-310 */
static unsigned long sync_reg_offset = L2X0_CACHE_SYNC;



static inline void cache_sync(void)
{
	void *base = l2x0_base;
	writel_relaxed(0, base + sync_reg_offset);
}

static inline void l2x0_clean_line(unsigned long addr)
{
	void *base = l2x0_base;
	writel_relaxed(addr, base + L2X0_CLEAN_LINE_PA);
}

static inline void l2x0_inv_line(unsigned long addr)
{
	void  *base = l2x0_base;
	writel_relaxed(addr, base + L2X0_INV_LINE_PA);
}



#ifdef CONFIG_PL310_ERRATA_588369
static inline void l2x0_flush_line(unsigned long addr)
{
	void  *base = l2x0_base;

	/* Clean by PA followed by Invalidate by PA */
	writel_relaxed(addr, base + L2X0_CLEAN_LINE_PA);
	writel_relaxed(addr, base + L2X0_INV_LINE_PA);
}
#else
static inline void l2x0_flush_line(unsigned long addr)
{
	void  *base = l2x0_base;
	writel_relaxed(addr, base + L2X0_CLEAN_INV_LINE_PA);
}
#endif


void l2x0_flush_all(void)
{
	/* clean all ways */
	writel_relaxed(l2x0_way_mask, l2x0_base + L2X0_CLEAN_INV_WAY);
	while(getL2CacheInvalByWay() & 0xFF);
	cache_sync();
}


void l2x0_clean_all(void)
{
	/* clean all ways */
	writel_relaxed(l2x0_way_mask, l2x0_base + L2X0_CLEAN_WAY);
	while(getL2CacheInvalByWay() & 0xFF);
	cache_sync();
}

void l2x0_inv_all(void)
{
	/* invalidate all ways */
	/* Invalidating when L2 is enabled is a nono */
	//BUG_ON(readl(l2x0_base + L2X0_CTRL) & L2X0_CTRL_EN);
	writel_relaxed(l2x0_way_mask, l2x0_base + L2X0_INV_WAY);
	while(getL2CacheInvalByWay() & 0xFF);
	cache_sync();
}

void l2x0_inv_range(unsigned long start, unsigned long end)
{
	if (start & (CACHE_LINE_SIZE - 1)) {
		start &= (unsigned long)~(CACHE_LINE_SIZE - 1);
		l2x0_flush_line(start);
		start += CACHE_LINE_SIZE;
	}

	if (end & (CACHE_LINE_SIZE - 1)) {
		end &= (unsigned long)~(CACHE_LINE_SIZE - 1);
		l2x0_flush_line(end);
	}

	while (start < end) {
		unsigned long blk_end = start + min(end - start, 4096UL);

		while (start < blk_end) {
			l2x0_inv_line(start);
			start += CACHE_LINE_SIZE;
		}
	}
	cache_sync();
}

void l2x0_clean_range(unsigned long start, unsigned long end)
{
	if ((end - start) >= l2x0_size) {
		l2x0_clean_all();
		return;
	}

	start &= (unsigned long)~(CACHE_LINE_SIZE - 1);
	while (start < end) {
		unsigned long blk_end = start + min(end - start, 4096UL);

		while (start < blk_end) {
			l2x0_clean_line(start);
			start += CACHE_LINE_SIZE;
		}
	}
	cache_sync();
}

void l2x0_flush_range(unsigned long start, unsigned long end)
{
	if ((end - start) >= l2x0_size) {
		l2x0_flush_all();
		return;
	}

	start &= (unsigned long)~(CACHE_LINE_SIZE - 1);
	while (start < end) {
		unsigned long blk_end = start + min(end - start, 4096UL);

		while (start < blk_end) {
			l2x0_flush_line(start);
			start += CACHE_LINE_SIZE;
		}

	}
	cache_sync();
}

void l2x0_disable(void)
{
	l2x0_flush_all();
	writel_relaxed(0, l2x0_base + L2X0_CTRL);
}
