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

#ifndef _L2CACHE_PL310_
#define _L2CACHE_PL310_

struct l2_cache_pl310
{
  // Register r0
  const volatile unsigned CacheID;              // 0x000
  const volatile unsigned CacheType;            // 0x004
  volatile unsigned Reserved0[(0x100-0x08)/4];  // 0x008-0x0FC

  // Register r1
  volatile unsigned Ctrl;                       // 0x100
  volatile unsigned AuxCtrl;                    // 0x104
  volatile unsigned TagRAMLatencyCtrl;          // 0x108
  volatile unsigned DataRAMLatencyCtrl;         // 0x10C
  volatile unsigned Reserved1[(0x200-0x110)/4]; // 0x110-0x1FC

  // Register r2
  volatile unsigned EvtCtrCtrl;                 // 0x200
  volatile unsigned EvtCtr1Cnfg;                // 0x204
  volatile unsigned EvtCtr0Cnfg;                // 0x208
  volatile unsigned EvtCtr1Val;                 // 0x20C
  volatile unsigned EvtCtr0Val;                 // 0x210
  volatile unsigned IntrMask;                   // 0x214
  const volatile unsigned MaskIntrStatus;       // 0x218
  const volatile unsigned RawIntrStatus;        // 0x21C
  volatile unsigned IntrClr;                    // 0x220 (WO)
  volatile unsigned Reserved2[(0x730-0x224)/4]; // 0x224-0x72c

  // Register r7
  volatile unsigned CacheSync;                   // 0x730
  volatile unsigned Reserved71[(0x770-0x734)/4]; // 0x734-0x76C
  volatile unsigned InvalLineByPA;               // 0x770
  volatile unsigned Reserved72[(0x77C-0x774)/4]; // 0x774-0x778
  volatile unsigned InvalByWay;                  // 0x77C
  volatile unsigned Reserved73[(0x7B0-0x780)/4]; // 0x780-0x7AC
  volatile unsigned CleanLineByPA;               // 0x7B0
  volatile unsigned Reserved74;                  // 0x7B4
  volatile unsigned CleanLineByIndexWay;         // 0x7B8
  volatile unsigned CleanByWay;                  // 0x7BC
  volatile unsigned Reserved75[(0x7F0-0x7C0)/4]; // 0x7C0-0x7EC
  volatile unsigned CleanInvalByPA;              // 0x7F0
  volatile unsigned Reserved76;                  // 0x7F4
  volatile unsigned CleanInvalByIndexWay;        // 0x7F8
  volatile unsigned CleanInvalByWay;             // 0x7FC
  volatile unsigned Reserved77[(0x900-0x800)/4]; // 0x800-0x8FC

  // Register r9
  volatile unsigned DataLockdown0ByWay;          // 0x900
  volatile unsigned InstrLockdown0ByWay;         // 0x904
  volatile unsigned DataLockdown1ByWay;          // 0x908
  volatile unsigned InstrLockdown1ByWay;         // 0x90C
  volatile unsigned DataLockdown2ByWay;          // 0x910
  volatile unsigned InstrLockdown2ByWay;         // 0x914
  volatile unsigned DataLockdown3ByWay;          // 0x918
  volatile unsigned InstrLockdown3ByWay;         // 0x91C
  volatile unsigned DataLockdown4ByWay;          // 0x920
  volatile unsigned InstrLockdown4ByWay;         // 0x924
  volatile unsigned DataLockdown5ByWay;          // 0x928
  volatile unsigned InstrLockdown5ByWay;         // 0x92C
  volatile unsigned DataLockdown6ByWay;          // 0x930
  volatile unsigned InstrLockdown6ByWay;         // 0x934
  volatile unsigned DataLockdown7ByWay;          // 0x938
  volatile unsigned InstrLockdown7ByWay;         // 0x93C
  volatile unsigned Reserved90[(0x950-0x940)/4]; // 0x940-0x94C
  volatile unsigned LockdownByLineEnable;        // 0x950
  volatile unsigned UnlockAllLinesByWay;         // 0x954
  volatile unsigned Reserved91[(0xC00-0x958)/4]; // 0x958-0x9FC

  // Register r12
  volatile unsigned AddressFilteringStart;       // 0xC00
  volatile unsigned AddressFilteringEnd;         // 0xC04
  volatile unsigned Reserved12[(0xF40-0xC08)/4]; // 0xC08-0xF3C

  // Register r15
  volatile unsigned DebugCtrl;                   // 0xF40
  volatile unsigned PrefetchCtrl;                // 0xF60
  volatile unsigned PowerCtrl;                   // 0xF80
};

/* L2 cache controller */
#define L2_CACHE_CONTROLLER  (*(volatile struct l2_cache_pl310 *)0x3FFFF000)

#define WAY_SIZE_16K_CFG 			(0x1)
#define ASSOCIATIVITY_8_CFG 		(0x0)
#define SHARED_OVERRIDE_ENABLE_CFG 	(0x1)
#define EXCLUSIVE_CACHE_CFG			(0x1)
#define NONEXCLUSIVE_CACHE_CFG		(0x0)

#define WAY_SIZE 			(WAY_SIZE_16K_CFG << L2CACHE_AUX_CTRL_WAY_SIZE_SHIFT)
#define ASSOCIATIVITY 		(ASSOCIATIVITY_8_CFG << L2CACHE_AUX_CTRL_ASSOCIATIVITY_SHIFT)
#define SHARED_OVERRIDE 	(SHARED_OVERRIDE_ENABLE_CFG << L2CACHE_AUX_CTRL_SHARE_OVERRIDE_SHIFT)
#define NONEXCLUSIVE_CACHE	(NONEXCLUSIVE_CACHE_CFG<< L2CACHE_AUX_CTRL_EXCLUSIVE_CACHE_SHIFT)


// initialize the cache controller
void L2CacheInit(void);
void L2CacheEnable(unsigned set);

// read functions
unsigned getL2CacheControl(void);
unsigned getL2CacheCacheID(void);
unsigned getL2CacheCacheType(void);
unsigned getL2CacheAuxCtrl(void);
unsigned getL2CacheTagRAMLatencyCtrl(void);
unsigned getL2CacheDataRAMLatencyCtrl(void);
unsigned getL2CacheEvtCtrCtrl(void);
unsigned getL2CacheEvtCtr1Cnfg(void);
unsigned getL2CacheEvtCtr0Cnfg(void);
unsigned getL2CacheEvtCtr1Val(void);
unsigned getL2CacheEvtCtr0Val(void);
unsigned getL2CacheIntrMask(void);
unsigned getL2CacheMaskIntrStatus(void);
unsigned getL2CacheRawIntrStatus(void);
unsigned getL2CacheCacheSync(void);
unsigned getL2CacheInvalLineByPA(void);
unsigned getL2CacheInvalByWay(void);
unsigned getL2CacheCleanLineByPA(void);
unsigned getL2CacheCleanLineByIndexWay(void);
unsigned getL2CacheCleanByWay(void);
unsigned getL2CacheCleanInvalByPA(void);
unsigned getL2CacheCleanInvalByIndexWay(void);
unsigned getL2CacheCleanInvalByWay(void);
unsigned getL2CacheDataLockdownByWay(unsigned master_id);
unsigned getL2CacheInstrLockdownByWay(unsigned master_id);
unsigned getL2CacheLockdownByLineEnable(void);
unsigned getL2CacheUnlockAllLinesByWay(void);
unsigned getL2CacheAddrFilteringStart(void);
unsigned getL2CacheAddrFilteringEnd(void);
unsigned getL2CacheDebugCtrl(void);
unsigned getL2CachePrefetchCtrl(void);
unsigned getL2CachePowerCtrl(void);

// write functions
void setL2CacheAuxCtrl(unsigned data);
void setL2CacheTagRAMLatencyCtrl(unsigned data);
void setL2CacheDataRAMLatencyCtrl(unsigned data);
void setL2CacheEvtCtrCtrl(unsigned data);
void setL2CacheEvtCtr1Cnfg(unsigned data);
void setL2CacheEvtCtr0Cnfg(unsigned data);
void setL2CacheEvtCtr1Val(unsigned data);
void setL2CacheEvtCtr0Val(unsigned data);
void setL2CacheIntrMask(unsigned data);
void setL2CacheIntrClr(unsigned data);
void setL2CacheCacheSync(unsigned data);
void setL2CacheInvalLineByPA(unsigned data);
void setL2CacheInvalByWay(unsigned data);
void setL2CacheCleanLineByPA(unsigned data);
void setL2CacheCleanLineByIndexWay(unsigned data);
void setL2CacheCleanByWay(unsigned data);
void setL2CacheCleanInvalByPA(unsigned data);
void setL2CacheCleanInvalByIndexWay(unsigned data);
void setL2CacheCleanInvalByWay(unsigned data);
void setL2CacheDataLockdownByWay(unsigned master_id, unsigned data);
void setL2CacheInstrLockdownByWay(unsigned master_id, unsigned data);
void setL2CacheLockdownByLineEnable(unsigned data);
void setL2CacheUnlockAllLinesByWay(unsigned data);
void setL2CacheAddrFilteringStart(unsigned data);
void setL2CacheAddrFilteringEnd(unsigned data);
void setL2CacheDebugCtrl(unsigned data);
void setL2CachePrefetchCtrl(unsigned data);
void setL2CachePowerCtrl(unsigned data);


#endif /* _L2CACHE_PL310_ */
