/*
* Copyright 2015 Giancarlo Parodi
* 
* l2_cache_pl310.h
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
