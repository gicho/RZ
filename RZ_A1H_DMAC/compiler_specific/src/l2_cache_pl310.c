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

#include "l2_cache_pl310.h"
#include "l2_cache.h"


/*
At boot time you must perform a Secure write to the Invalidate by Way, offset 0x77C, to
invalidate all entries in the cache.

As an example, a typical cache controller start-up programming sequence consists of the
following register operations:
1. Write to the Auxiliary, Tag RAM Latency, Data RAM Latency, Prefetch, and Power
Control registers using a read-modify-write to set up global configurations:
• associativity, Way Size
• latencies for RAM accesses
• allocation policy
• prefetch and power capabilities.
2. Secure write to the Invalidate by Way, offset 0x77C, to invalidate all entries in cache:
• Write 0xFFFF to 0x77C
• Poll cache maintenance register until invalidate operation is complete.
3. Write to the Lockdown D and Lockdown I Register 9 if required.
4. Write to interrupt clear register to clear any residual raw interrupts set.
5. Write to the Interrupt Mask Register if you want to enable interrupts.
6. Write to Control Register 1 with the LSB set to 1 to enable the cache.

You must disable the L2 cache by writing to
the Control Register 1 before writing to the Auxiliary, Tag RAM Latency, or Data RAM Latency
Control Register.

*/



void L2CacheInit(void)
{
/*
	You must disable the L2 cache by writing to
	the Control Register 1 before writing to the Auxiliary, Tag RAM Latency, or Data RAM Latency
	Control Register.
	*/
	// disable L2 controller
	L2CacheEnable(0x00000000);
/*
	1. Write to the Auxiliary, Tag RAM Latency, Data RAM Latency, Prefetch, and Power
	Control registers using a read-modify-write to set up global configurations:
	• associativity, Way Size
	• latencies for RAM accesses
	• allocation policy
	• prefetch and power capabilities.
*/

	// 8-way, 16kb way-size, tag/data RAM latency = 0
	setL2CacheAuxCtrl(WAY_SIZE | ASSOCIATIVITY | SHARED_OVERRIDE | NONEXCLUSIVE_CACHE);			// auxiliary
	setL2CacheTagRAMLatencyCtrl(0x000);															// tag ram
	setL2CacheDataRAMLatencyCtrl(0x000);														// data ram

  // prefetch control register left at default (no double linefill, no data or instruction prefetch)
  // power control register already set in reset_handler.s


/*
  2. Secure write to the Invalidate by Way, offset 0x77C, to invalidate all entries in cache:
  • Write 0xFFFF to 0x77C
  • Poll cache maintenance register until invalidate operation is complete.
*/

	setL2CacheInvalByWay(0x000000ff);

	// wait for all bits to clear to signal all ways invalidated
	// during operations ways are locked
	while(getL2CacheInvalByWay() & 0xFF);


/*
  3. Write to the Lockdown D and Lockdown I Register 9 if required.
  4. Write to interrupt clear register to clear any residual raw interrupts set.
  5. Write to the Interrupt Mask Register if you want to enable interrupts.
*/

	// clear interrupts
	setL2CacheIntrClr(0x000001ff);

	// enable interrupts
	setL2CacheIntrMask(0x000001ff);

/*
  6. Write to Control Register 1 with the LSB set to 1 to enable the cache.
*/

	L2CacheEnable(0x00000001);

}

void L2CacheEnable(unsigned set)
{
    L2_CACHE_CONTROLLER.Ctrl = set;
}


unsigned getL2CacheControl(void)
{
    return L2_CACHE_CONTROLLER.Ctrl;
}

unsigned getL2CacheCacheID(void)
{
  return L2_CACHE_CONTROLLER.CacheID;
}

unsigned getL2CacheCacheType(void)
{
  return L2_CACHE_CONTROLLER.CacheType;
}

unsigned getL2CacheAuxCtrl(void)
{
  return L2_CACHE_CONTROLLER.AuxCtrl;
}

void setL2CacheAuxCtrl(unsigned data)
{
  L2_CACHE_CONTROLLER.AuxCtrl = data;
}

unsigned getL2CacheTagRAMLatencyCtrl(void)
{
  return L2_CACHE_CONTROLLER.TagRAMLatencyCtrl;
}

void setL2CacheTagRAMLatencyCtrl(unsigned data)
{
  L2_CACHE_CONTROLLER.TagRAMLatencyCtrl = data;
}

unsigned getL2CacheDataRAMLatencyCtrl(void)
{
  return L2_CACHE_CONTROLLER.DataRAMLatencyCtrl;
}

void setL2CacheDataRAMLatencyCtrl(unsigned data)
{
  L2_CACHE_CONTROLLER.DataRAMLatencyCtrl = data;
}

unsigned getL2CacheEvtCtrCtrl(void)
{
  return L2_CACHE_CONTROLLER.EvtCtrCtrl;
}

void setL2CacheEvtCtrCtrl(unsigned data)
{
  L2_CACHE_CONTROLLER.EvtCtrCtrl = data;
}

unsigned getL2CacheEvtCtr1Cnfg(void)
{
  return L2_CACHE_CONTROLLER.EvtCtr1Cnfg;
}

void setL2CacheEvtCtr1Cnfg(unsigned data)
{
  L2_CACHE_CONTROLLER.EvtCtr1Cnfg = data;
}

unsigned getL2CacheEvtCtr0Cnfg(void)
{
  return L2_CACHE_CONTROLLER.EvtCtr0Cnfg;
}

void setL2CacheEvtCtr0Cnfg(unsigned data)
{
  L2_CACHE_CONTROLLER.EvtCtr0Cnfg = data;
}

unsigned getL2CacheEvtCtr1Val(void)
{
  return L2_CACHE_CONTROLLER.EvtCtr1Val;
}

void setL2CacheEvtCtr1Val(unsigned data)
{
  L2_CACHE_CONTROLLER.EvtCtr1Val = data;
}

unsigned getL2CacheEvtCtr0Val(void)
{
  return L2_CACHE_CONTROLLER.EvtCtr0Val;
}

void setL2CacheEvtCtr0Val(unsigned data)
{
  L2_CACHE_CONTROLLER.EvtCtr0Val = data;
}

unsigned getL2CacheIntrMask(void)
{
  return L2_CACHE_CONTROLLER.IntrMask;
}

void setL2CacheIntrMask(unsigned data)
{
  L2_CACHE_CONTROLLER.IntrMask = data;
}

unsigned getL2CacheMaskIntrStatus(void)
{
  return L2_CACHE_CONTROLLER.MaskIntrStatus;
}

unsigned getL2CacheRawIntrStatus(void)
{
  return L2_CACHE_CONTROLLER.RawIntrStatus;
}

void setL2CacheIntrClr(unsigned data)
{
  L2_CACHE_CONTROLLER.IntrClr = data;
}

// Register r7
unsigned getL2CacheCacheSync(void)
{
  return L2_CACHE_CONTROLLER.CacheSync;
}

void setL2CacheCacheSync(unsigned data)
{
  L2_CACHE_CONTROLLER.CacheSync = data;
}

unsigned getL2CacheInvalLineByPA(void)
{
  return L2_CACHE_CONTROLLER.InvalLineByPA;
}

void setL2CacheInvalLineByPA(unsigned data)
{
  L2_CACHE_CONTROLLER.InvalLineByPA = data;
}

unsigned getL2CacheInvalByWay(void)
{
  return L2_CACHE_CONTROLLER.InvalByWay;
}

void setL2CacheInvalByWay(unsigned data)
{
  L2_CACHE_CONTROLLER.InvalByWay = data;
}

unsigned getL2CacheCleanLineByPA(void)
{
  return L2_CACHE_CONTROLLER.CleanLineByPA;
}

void setL2CacheCleanLineByPA(unsigned data)
{
  L2_CACHE_CONTROLLER.CleanLineByPA = data;
}

unsigned getL2CacheCleanLineByIndexWay(void)
{
  return L2_CACHE_CONTROLLER.CleanLineByIndexWay;
}

void setL2CacheCleanLineByIndexWay(unsigned data)
{
  L2_CACHE_CONTROLLER.CleanLineByIndexWay = data;
}

unsigned getL2CacheCleanByWay(void)
{
  return L2_CACHE_CONTROLLER.CleanByWay;
}

void setL2CacheCleanByWay(unsigned data)
{
  L2_CACHE_CONTROLLER.CleanByWay = data;
}

unsigned getL2CacheCleanInvalByPA(void)
{
  return L2_CACHE_CONTROLLER.CleanInvalByPA;
}

void setL2CacheCleanInvalByPA(unsigned data)
{
  L2_CACHE_CONTROLLER.CleanInvalByPA = data;
}

unsigned getL2CacheCleanInvalByIndexWay(void)
{
  return L2_CACHE_CONTROLLER.CleanInvalByIndexWay;
}

void setL2CacheCleanInvalByIndexWay(unsigned data)
{
  L2_CACHE_CONTROLLER.CleanInvalByIndexWay = data;
}

unsigned getL2CacheCleanInvalByWay(void)
{
  return L2_CACHE_CONTROLLER.CleanInvalByWay;
}

void setL2CacheCleanInvalByWay(unsigned data)
{
  L2_CACHE_CONTROLLER.CleanInvalByWay = data;
}

unsigned getL2CacheDataLockdownByWay(unsigned master_id)
{
  switch(master_id) {
    case 0:
      return L2_CACHE_CONTROLLER.DataLockdown0ByWay;
    case 1:
      return L2_CACHE_CONTROLLER.DataLockdown1ByWay;
    case 2:
      return L2_CACHE_CONTROLLER.DataLockdown2ByWay;
    case 3:
      return L2_CACHE_CONTROLLER.DataLockdown3ByWay;
    case 4:
      return L2_CACHE_CONTROLLER.DataLockdown4ByWay;
    case 5:
      return L2_CACHE_CONTROLLER.DataLockdown5ByWay;
    case 6:
      return L2_CACHE_CONTROLLER.DataLockdown6ByWay;
    case 7:
      return L2_CACHE_CONTROLLER.DataLockdown7ByWay;
    default:
      return 0;
  }
}

void setL2CacheDataLockdownByWay(unsigned master_id, unsigned data)
{
  switch(master_id) {
    case 0:
      L2_CACHE_CONTROLLER.DataLockdown0ByWay = data;
      break;
    case 1:
      L2_CACHE_CONTROLLER.DataLockdown1ByWay = data;
      break;
    case 2:
      L2_CACHE_CONTROLLER.DataLockdown2ByWay = data;
      break;
    case 3:
      L2_CACHE_CONTROLLER.DataLockdown3ByWay = data;
      break;
    case 4:
      L2_CACHE_CONTROLLER.DataLockdown4ByWay = data;
      break;
    case 5:
      L2_CACHE_CONTROLLER.DataLockdown5ByWay = data;
      break;
    case 6:
      L2_CACHE_CONTROLLER.DataLockdown6ByWay = data;
      break;
    case 7:
      L2_CACHE_CONTROLLER.DataLockdown7ByWay = data;
      break;
  }
}

unsigned getL2CacheInstrLockdownByWay(unsigned master_id)
{
  switch(master_id) {
    case 0:
      return L2_CACHE_CONTROLLER.InstrLockdown0ByWay;
    case 1:
      return L2_CACHE_CONTROLLER.InstrLockdown1ByWay;
    case 2:
      return L2_CACHE_CONTROLLER.InstrLockdown2ByWay;
    case 3:
      return L2_CACHE_CONTROLLER.InstrLockdown3ByWay;
    case 4:
      return L2_CACHE_CONTROLLER.InstrLockdown4ByWay;
    case 5:
      return L2_CACHE_CONTROLLER.InstrLockdown5ByWay;
    case 6:
      return L2_CACHE_CONTROLLER.InstrLockdown6ByWay;
    case 7:
      return L2_CACHE_CONTROLLER.InstrLockdown7ByWay;
    default:
      return 0;
  }
}

void setL2CacheInstrLockdownByWay(unsigned master_id, unsigned data)
{
  switch(master_id) {
    case 0:
      L2_CACHE_CONTROLLER.InstrLockdown0ByWay = data;
      break;
    case 1:
      L2_CACHE_CONTROLLER.InstrLockdown1ByWay = data;
      break;
    case 2:
      L2_CACHE_CONTROLLER.InstrLockdown2ByWay = data;
      break;
    case 3:
      L2_CACHE_CONTROLLER.InstrLockdown3ByWay = data;
      break;
    case 4:
      L2_CACHE_CONTROLLER.InstrLockdown4ByWay = data;
      break;
    case 5:
      L2_CACHE_CONTROLLER.InstrLockdown5ByWay = data;
      break;
    case 6:
      L2_CACHE_CONTROLLER.InstrLockdown6ByWay = data;
      break;
    case 7:
      L2_CACHE_CONTROLLER.InstrLockdown7ByWay = data;
      break;
  }
}

unsigned getL2CacheLockdownByLineEnable(void)
{
  return L2_CACHE_CONTROLLER.LockdownByLineEnable;
}

void setL2CacheLockdownByLineEnable(unsigned data)
{
  L2_CACHE_CONTROLLER.LockdownByLineEnable = data;
}

unsigned getL2CacheUnlockAllLinesByWay(void)
{
  return L2_CACHE_CONTROLLER.UnlockAllLinesByWay;
}

void setL2CacheUnlockAllLinesByWay(unsigned data)
{
  L2_CACHE_CONTROLLER.UnlockAllLinesByWay = data;
}

unsigned getL2CacheAddrFilteringStart(void)
{
  return L2_CACHE_CONTROLLER.AddressFilteringStart;
}

void setL2CacheAddrFilteringStart(unsigned data)
{
  L2_CACHE_CONTROLLER.AddressFilteringStart = data;
}

unsigned getL2CacheAddrFilteringEnd(void)
{
  return L2_CACHE_CONTROLLER.AddressFilteringEnd;
}

void setL2CacheAddrFilteringEnd(unsigned data)
{
  L2_CACHE_CONTROLLER.AddressFilteringEnd = data;
}

unsigned getL2CacheDebugCtrl(void)
{
  return L2_CACHE_CONTROLLER.DebugCtrl;
}

void setL2CacheDebugCtrl(unsigned data)
{
  L2_CACHE_CONTROLLER.DebugCtrl = data;
}

unsigned getL2CachePrefetchCtrl(void)
{
  return L2_CACHE_CONTROLLER.PrefetchCtrl;
}

void setL2CachePrefetchCtrl(unsigned data)
{
  L2_CACHE_CONTROLLER.PrefetchCtrl = data;
}

unsigned getL2CachePowerCtrl(void)
{
  return L2_CACHE_CONTROLLER.PowerCtrl;
}

void setL2CachePowerCtrl(unsigned data)
{
  L2_CACHE_CONTROLLER.PowerCtrl = data;
}



