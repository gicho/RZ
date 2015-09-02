/*
* Copyright 2015 Giancarlo Parodi
* 
* l2_cache.c
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

#include <stdint.h>
#include "compiler_settings.h"
#include "l2_cache.h"
#include "l2_cache_pl310.h"



static inline void L2CacheSync(void)
{
	(*(volatile uint32_t *)(L2CacheController + L2CACHE_CACHE_SYNC_REG)) = 0;
}

static inline void L2CacheCleanLine(unsigned long addr)
{
	(*(volatile uint32_t *)(L2CacheController + L2CACHE_CLEAN_LINE_PA_REG)) = addr;
}

static inline void L2CacheInvalidateLine(unsigned long addr)
{
	(*(volatile uint32_t *)(L2CacheController + L2CACHE_INV_LINE_PA_REG)) = addr;
}

static inline void L2CacheCleanAndInvalidateLine(unsigned long addr)
{
	(*(volatile uint32_t *)(L2CacheController + L2CACHE_CLEAN_INV_LINE_PA_REG)) = addr;
}


void L2CacheCleanAndInvalidate(void)
{
	/* clean all ways */
	__disable_irq();  	// added this to make sure there are no other tasks writing to the control registers
						// before completion

	(*(volatile uint32_t *)(L2CacheController + L2CACHE_CLEAN_INV_WAY_REG)) = L2CacheWayMask;
	while(getL2CacheCleanInvalByWay() & 0xFF); // wait since it is a background operation

	__enable_irq();

	L2CacheSync();
}


void L2CacheClean(void)
{
	/* clean all ways */
	__disable_irq();  	// added this to make sure there are no other tasks writing to the control registers
						// before completion

	(*(volatile uint32_t *) (L2CacheController + L2CACHE_CLEAN_WAY_REG)) = L2CacheWayMask;
	while(getL2CacheCleanByWay() & 0xFF); // wait since it is a background operation

	__enable_irq();

	L2CacheSync();
}

void L2CacheInvalidate(void)
{
	__disable_irq();  	// added this to make sure there are no other tasks writing to the control registers
						// before completion

	(*(volatile uint32_t *) (L2CacheController + L2CACHE_INV_WAY_REG)) = L2CacheWayMask;
	while(getL2CacheInvalByWay() & 0xFF); // wait since it is a background operation

	__enable_irq();
	L2CacheSync();
}

void L2CacheInvalidateRange(unsigned long start, unsigned long end)
{
	unsigned long blk_end;
        
        if (start & (CACHE_LINE_SIZE - 1)) {
		start &= (unsigned long)~(CACHE_LINE_SIZE - 1);
		L2CacheCleanAndInvalidateLine(start);
		start += CACHE_LINE_SIZE;
	}

	if (end & (CACHE_LINE_SIZE - 1)) {
		end &= (unsigned long)~(CACHE_LINE_SIZE - 1);
		L2CacheCleanAndInvalidateLine(end);
	}

	while (start < end) {
		blk_end = start + min(end - start, 4096UL);

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

void L2CacheCleanAndInvalidateRange(unsigned long start, unsigned long end)
{
	if ((end - start) >= L2CacheSize) {
		L2CacheCleanAndInvalidate();
		return;
	}

	start &= (unsigned long)~(CACHE_LINE_SIZE - 1);
	while (start < end) {
		unsigned long blk_end = start + min(end - start, 4096UL);

		while (start < blk_end) {
			L2CacheCleanAndInvalidateLine(start);
			start += CACHE_LINE_SIZE;
		}

	}
	L2CacheSync();
}

void L2CacheDisable(void)
{
	L2CacheCleanAndInvalidate();
	(*(volatile uint32_t *) ( L2CacheController + L2CACHE_CTRL_REG)) = 0;
}
