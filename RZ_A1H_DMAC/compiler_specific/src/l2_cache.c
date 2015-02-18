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

#include "compiler_settings.h"
#include "l2_cache.h"
#include "l2_cache_pl310.h"


#define min(x, y) ({ x < y ? x : y; })

static inline void _writeReg(unsigned long val, volatile void *addr)
{
	__asm__ volatile ("str %1, %0"
		     : "+Qo" (*(volatile unsigned long *)addr)
		     : "r" (val)
		     );
}

static void *L2CacheController = (void*)0x3FFFF000;

#define CACHE_LINE_SIZE		32
static unsigned long L2CacheWayMask = (1 << 8) - 1; /* Bitmask of active ways (8) */
static unsigned long L2CacheSize = 0x20000l; 		/* 128 KBytes L2 Cache Controller PL-310 */


static inline void L2CacheSync(void)
{
	void *base = L2CacheController;
	_writeReg(0, base + L2CACHE_CACHE_SYNC_REG);
}

static inline void L2CacheCleanLine(unsigned long addr)
{
	void *base = L2CacheController;
	_writeReg(addr, base + L2CACHE_CLEAN_LINE_PA_REG);
}

static inline void L2CacheInvalidateLine(unsigned long addr)
{
	void  *base = L2CacheController;
	_writeReg(addr, base + L2CACHE_INV_LINE_PA_REG);
}

static inline void L2CacheFlushLine(unsigned long addr)
{
	void  *base = L2CacheController;
	_writeReg(addr, base + L2CACHE_CLEAN_INV_LINE_PA_REG);
}


void L2CacheFlush(void)
{
	/* clean all ways */
	__disable_irq();  	// added this to make sure there are no other tasks writing to the control registers
						// before completion

	_writeReg(L2CacheWayMask, L2CacheController + L2CACHE_CLEAN_INV_WAY_REG);
	while(getL2CacheCleanInvalByWay() & 0xFF); // wait since it is a background operation

	__enable_irq();

	L2CacheSync();
}


void L2CacheClean(void)
{
	/* clean all ways */
	__disable_irq();  	// added this to make sure there are no other tasks writing to the control registers
						// before completion

	_writeReg(L2CacheWayMask, L2CacheController + L2CACHE_CLEAN_WAY_REG);
	while(getL2CacheCleanByWay() & 0xFF); // wait since it is a background operation

	__enable_irq();

	L2CacheSync();
}

void L2CacheInvalidate(void)
{
	__disable_irq();  	// added this to make sure there are no other tasks writing to the control registers
						// before completion

	_writeReg(L2CacheWayMask, L2CacheController + L2CACHE_INV_WAY_REG);
	while(getL2CacheInvalByWay() & 0xFF); // wait since it is a background operation

	__enable_irq();
	L2CacheSync();
}

void L2CacheInvalidateRange(unsigned long start, unsigned long end)
{
	if (start & (CACHE_LINE_SIZE - 1)) {
		start &= (unsigned long)~(CACHE_LINE_SIZE - 1);
		L2CacheFlushLine(start);
		start += CACHE_LINE_SIZE;
	}

	if (end & (CACHE_LINE_SIZE - 1)) {
		end &= (unsigned long)~(CACHE_LINE_SIZE - 1);
		L2CacheFlushLine(end);
	}

	while (start < end) {
		unsigned long blk_end = start + min(end - start, 4096UL);

		while (start < blk_end) {
			L2CacheInvalidateLine(start);
			start += CACHE_LINE_SIZE;
		}
	}
	L2CacheSync();
}

void L2CacheCleanRange(unsigned long start, unsigned long end)
{
	if ((end - start) >= L2CacheSize) {
		L2CacheClean();
		return;
	}

	start &= (unsigned long)~(CACHE_LINE_SIZE - 1);
	while (start < end) {
		unsigned long blk_end = start + min(end - start, 4096UL);

		while (start < blk_end) {
			L2CacheCleanLine(start);
			start += CACHE_LINE_SIZE;
		}
	}
	L2CacheSync();
}

void L2CacheFlushRange(unsigned long start, unsigned long end)
{
	if ((end - start) >= L2CacheSize) {
		L2CacheFlush();
		return;
	}

	start &= (unsigned long)~(CACHE_LINE_SIZE - 1);
	while (start < end) {
		unsigned long blk_end = start + min(end - start, 4096UL);

		while (start < blk_end) {
			L2CacheFlushLine(start);
			start += CACHE_LINE_SIZE;
		}

	}
	L2CacheSync();
}

void L2CacheDisable(void)
{
	L2CacheFlush();
	_writeReg(0, L2CacheController + L2CACHE_CTRL_REG);
}
