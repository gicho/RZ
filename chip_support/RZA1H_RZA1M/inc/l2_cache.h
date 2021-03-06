/*
* Copyright 2015 Giancarlo Parodi
* 
* l2_cache.h
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

#ifndef L2_CACHE_H
#define L2_CACHE_H

#define L2CACHE_ID_REG					0x000
#define L2CACHE_TYPE_REG				0x004
#define L2CACHE_CTRL_REG				0x100
#define L2CACHE_AUXCTRL_REG				0x104
#define L2CACHE_TAG_LATENCY_CTRL_REG	0x108
#define L2CACHE_DATA_LATENCY_CTRL_REG	0x10C
#define L2CACHE_EVENT_CNT_CTRL_REG		0x200
#define L2CACHE_EVENT_CNT1_CFG_REG		0x204
#define L2CACHE_EVENT_CNT0_CFG_REG		0x208
#define L2CACHE_EVENT_CNT1_VAL_REG		0x20C
#define L2CACHE_EVENT_CNT0_VAL_REG		0x210
#define L2CACHE_INTR_MASK_REG			0x214
#define L2CACHE_MASKED_INTR_STAT_REG	0x218
#define L2CACHE_RAW_INTR_STAT_REG		0x21C
#define L2CACHE_INTR_CLEAR_REG			0x220
#define L2CACHE_CACHE_SYNC_REG			0x730
#define L2CACHE_DUMMY_REG				0x740
#define L2CACHE_INV_LINE_PA_REG			0x770
#define L2CACHE_INV_WAY_REG				0x77C
#define L2CACHE_CLEAN_LINE_PA_REG		0x7B0
#define L2CACHE_CLEAN_LINE_IDX_REG		0x7B8
#define L2CACHE_CLEAN_WAY_REG			0x7BC
#define L2CACHE_CLEAN_INV_LINE_PA_REG	0x7F0
#define L2CACHE_CLEAN_INV_LINE_IDX_REG	0x7F8
#define L2CACHE_CLEAN_INV_WAY_REG		0x7FC

/* PL310 has 8 lockdown registers */
#define L2CACHE_LOCKDOWN_WAY_D_BASE_REG	0x900
#define L2CACHE_LOCKDOWN_WAY_I_BASE_REG	0x904
#define L2CACHE_LOCKDOWN_STRIDE_REG		0x08
#define L2CACHE_ADDR_FILTER_START_REG	0xC00
#define L2CACHE_ADDR_FILTER_END_REG		0xC04
#define L2CACHE_TEST_OPERATION_REG		0xF00
#define L2CACHE_LINE_DATA_REG			0xF10
#define L2CACHE_LINE_TAG_REG			0xF30
#define L2CACHE_DEBUG_CTRL_REG			0xF40
#define L2CACHE_PREFETCH_CTRL_REG		0xF60
#define L2CACHE_POWER_CTRL_REG			0xF80

#define L2CACHE_DYNAMIC_CLK_GATING_ENA	(1 << 1)
#define L2CACHE_STANDBY_MODE_ENA		(1 << 0)

/* Registers shifts and masks */
#define L2CACHE_CACHE_ID_PART_MSK		(0xf << 6)
#define L2CACHE_CACHE_ID_PART_PL310		(3 << 6)

#define L2CACHE_CACHE_ID_RTL_MSK	0x3f
#define L2CACHE_CACHE_ID_RTL_R0P0   0x0
#define L2CACHE_CACHE_ID_RTL_R1P0   0x2
#define L2CACHE_CACHE_ID_RTL_R2P0   0x4
#define L2CACHE_CACHE_ID_RTL_R3P0   0x5
#define L2CACHE_CACHE_ID_RTL_R3P1   0x6
#define L2CACHE_CACHE_ID_RTL_R3P2   0x8

#define L2CACHE_AUX_CTRL_MASK					0xc0000fff
#define L2CACHE_AUX_CTRL_DATA_RD_LATENCY_SHIFT	0
#define L2CACHE_AUX_CTRL_DATA_RD_LATENCY_MASK	0x7

#define L2CACHE_AUX_CTRL_DATA_WR_LATENCY_SHIFT	3
#define L2CACHE_AUX_CTRL_DATA_WR_LATENCY_MASK	(0x7 << 3)

#define L2CACHE_AUX_CTRL_TAG_LATENCY_SHIFT		6
#define L2CACHE_AUX_CTRL_TAG_LATENCY_MASK		(0x7 << 6)

#define L2CACHE_AUX_CTRL_DIRTY_LATENCY_SHIFT	9
#define L2CACHE_AUX_CTRL_DIRTY_LATENCY_MASK		(0x7 << 9)

#define L2CACHE_AUX_CTRL_EXCLUSIVE_CACHE_SHIFT	12
#define L2CACHE_AUX_CTRL_EXCLUSIVE_CACHE_MASK	(0x1 << 12)

#define L2CACHE_AUX_CTRL_ASSOCIATIVITY_SHIFT	16

#define L2CACHE_AUX_CTRL_WAY_SIZE_SHIFT			17
#define L2CACHE_AUX_CTRL_WAY_SIZE_MASK			(0x7 << 17)

#define L2CACHE_AUX_CTRL_SHARE_OVERRIDE_SHIFT	22
#define L2CACHE_AUX_CTRL_NS_LOCKDOWN_SHIFT		26
#define L2CACHE_AUX_CTRL_NS_INT_CTRL_SHIFT		27
#define L2CACHE_AUX_CTRL_DATA_PREFETCH_SHIFT	28
#define L2CACHE_AUX_CTRL_INSTR_PREFETCH_SHIFT	29
#define L2CACHE_AUX_CTRL_EARLY_BRESP_SHIFT		30

#define L2CACHE_LATENCY_CTRL_SETUP_SHIFT	0
#define L2CACHE_LATENCY_CTRL_RD_SHIFT		4
#define L2CACHE_LATENCY_CTRL_WR_SHIFT		8

#define L2CACHE_ADDR_FILTER_EN		1
#define L2CACHE_CTRL_EN				1
#define L2CACHE_WAY_SIZE_SHIFT		3

#define min(a, b) (((a) < (b)) ? (a) : (b))

#define L2CacheController 0x3FFFF000
#define CACHE_LINE_SIZE	32
#define L2CacheWayMask ((1 << 8) - 1)
#define L2CacheSize 0x20000l


extern void L2CacheInit(void);

void L2CacheCleanAndInvalidate(void);
void L2CacheCleanAndInvalidateRange(unsigned long start, unsigned long end);

void L2CacheClean(void);
void L2CacheCleanRange(unsigned long start, unsigned long end);

void L2CacheInvalidate(void);
void L2CacheInvalidateRange(unsigned long start, unsigned long end);


#define WRITE_ALLOCATE_WRITE_BACK 	(0xF)
#define READ_ALLOCATE_WRITE_BACK 	(0x7)
#define READ_ALLOCATE_WRITE_THROUGH (0x6)


#endif /* _L2_CACHE_H */

