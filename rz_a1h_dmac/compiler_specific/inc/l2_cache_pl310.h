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

void L2CacheInit(void);

// Accessor functions

// Register r0
unsigned get_pl310_l2cc_CacheID(void);
unsigned get_pl310_l2cc_CacheType(void);

// Register r1
void pl310_l2cc_enable(unsigned set);

unsigned get_pl310_l2cc_AuxCtrl(void);
void set_pl310_l2cc_AuxCtrl(unsigned data);
unsigned get_pl310_l2cc_TagRAMLatencyCtrl(void);
void set_pl310_l2cc_TagRAMLatencyCtrl(unsigned data);
unsigned get_pl310_l2cc_DataRAMLatencyCtrl(void);
void set_pl310_l2cc_DataRAMLatencyCtrl(unsigned data);

// Register r2
unsigned get_pl310_l2cc_EvtCtrCtrl(void);
void set_pl310_l2cc_EvtCtrCtrl(unsigned data);
unsigned get_pl310_l2cc_EvtCtr1Cnfg(void);
void set_pl310_l2cc_EvtCtr1Cnfg(unsigned data);
unsigned get_pl310_l2cc_EvtCtr0Cnfg(void);
void set_pl310_l2cc_EvtCtr0Cnfg(unsigned data);
unsigned get_pl310_l2cc_EvtCtr1Val(void);
void set_pl310_l2cc_EvtCtr1Val(unsigned data);
unsigned get_pl310_l2cc_EvtCtr0Val(void);
void set_pl310_l2cc_EvtCtr0Val(unsigned data);
unsigned get_pl310_l2cc_IntrMask(void);
void set_pl310_l2cc_IntrMask(unsigned data);
unsigned get_pl310_l2cc_MaskIntrStatus(void);
unsigned get_pl310_l2cc_RawIntrStatus(void);
void set_pl310_l2cc_IntrClr(unsigned data);

// Register r7
unsigned get_pl310_l2cc_CacheSync(void);
void set_pl310_l2cc_CacheSync(unsigned data);
unsigned get_pl310_l2cc_InvalLineByPA(void);
void set_pl310_l2cc_InvalLineByPA(unsigned data);
unsigned get_pl310_l2cc_InvalByWay(void);
void set_pl310_l2cc_InvalByWay(unsigned data);
unsigned get_pl310_l2cc_CleanLineByPA(void);
void set_pl310_l2cc_CleanLineByPA(unsigned data);
unsigned get_pl310_l2cc_CleanLineByIndexWay(void);
void set_pl310_l2cc_CleanLineByIndexWay(unsigned data);
unsigned get_pl310_l2cc_CleanByWay(void);
void set_pl310_l2cc_CleanByWay(unsigned data);
unsigned get_pl310_l2cc_CleanInvalByPA(void);
void set_pl310_l2cc_CleanInvalByPA(unsigned data);
unsigned get_pl310_l2cc_CleanInvalByIndexWay(void);
void set_pl310_l2cc_CleanInvalByIndexWay(unsigned data);
unsigned get_pl310_l2cc_CleanInvalByWay(void);
void set_pl310_l2cc_CleanInvalByWay(unsigned data);

// Register r9
unsigned get_pl310_l2cc_DataLockdownByWay(unsigned master_id);
void set_pl310_l2cc_DataLockdownByWay(unsigned master_id, unsigned data);
unsigned get_pl310_l2cc_InstrLockdownByWay(unsigned master_id);
void set_pl310_l2cc_InstrLockdownByWay(unsigned master_id, unsigned data);
unsigned get_pl310_l2cc_LockdownByLineEnable(void);
void set_pl310_l2cc_LockdownByLineEnable(unsigned data);
unsigned get_pl310_l2cc_UnlockAllLinesByWay(void);
void set_pl310_l2cc_UnlockAllLinesByWay(unsigned data);

// Register r12
unsigned get_pl310_l2cc_AddrFilteringStart(void);
void set_pl310_l2cc_AddrFilteringStart(unsigned data);
unsigned get_pl310_l2cc_AddrFilteringEnd(void);
void set_pl310_l2cc_AddrFilteringEnd(unsigned data);

// Register r15
unsigned get_pl310_l2cc_DebugCtrl(void);
void set_pl310_l2cc_DebugCtrl(unsigned data);
unsigned get_pl310_l2cc_PrefetchCtrl(void);
void set_pl310_l2cc_PrefetchCtrl(unsigned data);
unsigned get_pl310_l2cc_PowerCtrl(void);
void set_pl310_l2cc_PowerCtrl(unsigned data);


#endif /* _L2CACHE_PL310_ */
