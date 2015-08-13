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
