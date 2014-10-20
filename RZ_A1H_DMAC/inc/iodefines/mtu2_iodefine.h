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
*******************************************************************************/
/*******************************************************************************
* Copyright (C) 2013 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
*   File Name   : mtu2_iodefine.h
*   H/W Platform: 
*   Description : mtu2 interface file
*******************************************************************************/
/*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*******************************************************************************/
#ifndef __MTU2_IODEFINE_H__
#define __MTU2_IODEFINE_H__

#include "typedefine.h"

struct st_mtu2{                                 /* struct MTU2  */
       union {                                  /* TCR_2        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TPSC:3U;              /*   TPSC       */
                    _UBYTE CKEG:2U;              /*   CKEG       */
                    _UBYTE CCLR:2U;              /*   CCLR       */
                    _UBYTE :1U;
                    } BIT;                      /*              */
             } TCR_2;                           /*              */
       union {                                  /* TMDR_2       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE MD:4U;                /*   MD         */
                    _UBYTE :4U;                  /*              */
                    } BIT;                      /*              */
             } TMDR_2;                          /*              */
       union {                                  /* TIOR_2       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE IOA:4U;               /*   IOA        */
                    _UBYTE IOB:4U;               /*   IOB        */
                    } BIT;                      /*              */
             } TIOR_2;                          /*              */
       _UBYTE wk0[1];                           /*              */
       union {                                  /* TIER_2       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TGIEA:1U;             /*   TGIEA      */
                    _UBYTE TGIEB:1U;             /*   TGIEB      */
                    _UBYTE :2U;                  /*              */
                    _UBYTE TCIEV:1U;             /*   TCIEV      */
                    _UBYTE TCIEU:1U;             /*   TCIEU      */
                    _UBYTE :1U;                  /*              */
                    _UBYTE TTGE:1U;              /*   TTGE       */
                    } BIT;                      /*              */
             } TIER_2;                          /*              */
       union {                                  /* TSR_2        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TGFA:1U;              /*   TGFA       */
                    _UBYTE TGFB:1U;              /*   TGFB       */
                    _UBYTE :1U;                  /*              */
                    _UBYTE :1U;                  /*             */
                    _UBYTE TCFV:1U;              /*   TCFV       */
                    _UBYTE TCFU:1U;              /*   TCFU       */
                    _UBYTE :1U;                  /*              */
                    _UBYTE TCFD:1U;              /*   TCFD       */
                    } BIT;                      /*              */
             } TSR_2;                           /*              */
       union {                                  /* TCNT_2       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TCNT_2;                          /*              */
       union {                                  /* TGRA_2       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRA_2;                          /*              */
       union {                                  /* TGRB_2       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRB_2;                          /*              */
       _UBYTE wk1[500];                         /*              */
       union {                                  /* TCR_3        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TPSC:3U;              /*   TPSC       */
                    _UBYTE CKEG:2U;              /*   CKEG       */
                    _UBYTE CCLR:3U;              /*   CCLR       */
                    } BIT;                      /*              */
             } TCR_3;                           /*              */
       union {                                  /* TCR_4        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TPSC:3U;              /*   TPSC       */
                    _UBYTE CKEG:2U;              /*   CKEG       */
                    _UBYTE CCLR:3U;              /*   CCLR       */
                    } BIT;                      /*              */
             } TCR_4;                           /*              */
       union {                                  /* TMDR_3       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE MD:4U;                /*   MD         */
                    _UBYTE BFA:1U;               /*   BFA        */
                    _UBYTE BFB:1U;               /*   BFB        */
                    _UBYTE :2U;                  /*              */
                    } BIT;                      /*              */
             } TMDR_3;                          /*              */
       union {                                  /* TMDR_4       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE MD:4U;                /*   MD         */
                    _UBYTE BFA:1U;               /*   BFA        */
                    _UBYTE BFB:1U;               /*   BFB        */
                    _UBYTE :2U;                  /*              */
                    } BIT;                      /*              */
             } TMDR_4;                          /*              */
       union {                                  /* TIORH_3      */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE IOA:4U;               /*   IOA        */
                    _UBYTE IOB:4U;               /*   IOB        */
                    } BIT;                      /*              */
             } TIORH_3;                         /*              */
       union {                                  /* TIORL_3      */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE IOC:4U;               /*   IOC        */
                    _UBYTE IOD:4U;               /*   IOD        */
                    } BIT;                      /*              */
             } TIORL_3;                         /*              */
       union {                                  /* TIORH_4      */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE IOA:4U;               /*   IOA        */
                    _UBYTE IOB:4U;               /*   IOB        */
                    } BIT;                      /*              */
             } TIORH_4;                         /*              */
       union {                                  /* TIORL_4      */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE IOC:4U;               /*   IOC        */
                    _UBYTE IOD:4U;               /*   IOD        */
                    } BIT;                      /*              */
             } TIORL_4;                         /*              */
       union {                                  /* TIER_3       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TGIEA:1U;             /*   TGIEA      */
                    _UBYTE TGIEB:1U;             /*   TGIEB      */
                    _UBYTE TGIEC:1U;             /*   TGIEC      */
                    _UBYTE TGIED:1U;             /*   TGIED      */
                    _UBYTE TCIEV:1U;             /*   TCIEV      */
                    _UBYTE :2U;                  /*              */
                    _UBYTE TTGE:1U;              /*   TTGE       */
                    } BIT;                      /*              */
             } TIER_3;                          /*              */
       union {                                  /* TIER_4       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TGIEA:1U;             /*   TGIEA      */
                    _UBYTE TGIEB:1U;             /*   TGIEB      */
                    _UBYTE TGIEC:1U;             /*   TGIEC      */
                    _UBYTE TGIED:1U;             /*   TGIED      */
                    _UBYTE TCIEV:1U;             /*   TCIEV      */
                    _UBYTE :1U;                  /*              */
                    _UBYTE TTGE2:1U;             /*   TTGE2      */
                    _UBYTE TTGE:1U;              /*   TTGE       */
                    } BIT;                      /*              */
             } TIER_4;                          /*              */
       union {                                  /* TOER         */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE OE3B:1U;              /*   OE3B       */
                    _UBYTE OE4A:1U;              /*   OE4A       */
                    _UBYTE OE4B:1U;              /*   OE4B       */
                    _UBYTE OE3D:1U;              /*   OE3D       */
                    _UBYTE OE4C:1U;              /*   OE4C       */
                    _UBYTE OE4D:1U;              /*   OE4D       */
                    _UBYTE :2U;                  /*              */
                    } BIT;                      /*              */
             } TOER;                            /*              */
       _UBYTE wk2[2];                           /*              */
       union {                                  /* TGCR         */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE UF:1U;                /*   UF         */
                    _UBYTE VF:1U;                /*   VF         */
                    _UBYTE WF:1U;                /*   WF         */
                    _UBYTE FB:1U;                /*   FB         */
                    _UBYTE P:1U;                 /*   P          */
                    _UBYTE N:1U;                 /*   N          */
                    _UBYTE BDC:1U;               /*   BDC        */
                    _UBYTE :1U;                  /*              */
                    } BIT;                      /*              */
             } TGCR;                            /*              */
       union {                                  /* TOCR1        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE OLSP:1U;              /*   OLSP       */
                    _UBYTE OLSN:1U;              /*   OLSN       */
                    _UBYTE TOCS:1U;              /*   TOCS       */
                    _UBYTE TOCL:1U;              /*   TOCL       */
                    _UBYTE :2U;                  /*              */
                    _UBYTE PSYE:1U;              /*   PSYE       */
                    _UBYTE :1U;                  /*              */
                    } BIT;                      /*              */
             } TOCR1;                           /*              */
       union {                                  /* TOCR2        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE OLS1P:1U;             /*   OLS1P      */
                    _UBYTE OLS1N:1U;             /*   OLS1N      */
                    _UBYTE OLS2P:1U;             /*   OLS2P      */
                    _UBYTE OLS2N:1U;             /*   OLS2N      */
                    _UBYTE OLS3P:1U;             /*   OLS3P      */
                    _UBYTE OLS3N:1U;             /*   OLS3N      */
                    _UBYTE BF:2U;                /*   BF         */
                    } BIT;                      /*              */
             } TOCR2;                           /*              */
       union {                                  /* TCNT_3       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TCNT_3;                          /*              */
       union {                                  /* TCNT_4       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TCNT_4;                          /*              */
       union {                                  /* TCDR        */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TCDR;                            /*              */
       union {                                  /* TDDR        */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TDDR;                            /*              */
       union {                                  /* TGRA_3       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRA_3;                          /*              */
       union {                                  /* TGRB_3       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRB_3;                          /*              */
       union {                                  /* TGRA_4       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16;                /*   D          */
                    } BIT;                      /*              */
             } TGRA_4;                          /*              */
       union {                                  /* TGRB_4       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRB_4;                          /*              */
       union {                                  /* TCNTS        */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TCNTS;                           /*              */
       union {                                  /* TCBR         */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TCBR;                            /*              */
       union {                                  /* TGRC_3       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRC_3;                          /*              */
       union {                                  /* TGRD_3       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRD_3;                          /*              */
       union {                                  /* TGRC_4       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRC_4;                          /*              */
       union {                                  /* TGRD_4       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRD_4;                          /*              */
       union {                                  /* TSR_3        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TGFA:1U;              /*   TGFA       */
                    _UBYTE TGFB:1U;              /*   TGFB       */
                    _UBYTE TGFC:1U;              /*   TGFC       */
                    _UBYTE TGFD:1U;              /*   TGFD       */
                    _UBYTE TCFV:1U;              /*   TCFV       */
                    _UBYTE :2U;                  /*              */
                    _UBYTE TCFD:1U;              /*   TCFD       */
                    } BIT;                      /*              */
             } TSR_3;                           /*              */
       union {                                  /* TSR_4        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TGFA:1U;              /*   TGFA       */
                    _UBYTE TGFB:1U;              /*   TGFB       */
                    _UBYTE TGFC:1U;              /*   TGFC       */
                    _UBYTE TGFD:1U;              /*   TGFD       */
                    _UBYTE TCFV:1U;              /*   TCFV       */
                    _UBYTE :2U;                  /*              */
                    _UBYTE TCFD:1U;              /*   TCFD       */
                    } BIT;                      /*              */
             } TSR_4;                           /*              */
       _UBYTE wk3[2];                           /*              */
       union {                                  /* TITCR        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE _4VCOR:3U;            /*   _4VCOR     */
                    _UBYTE T4VEN:1U;             /*   T4VEN      */
                    _UBYTE _3ACOR:3U;            /*   _3ACOR     */
                    _UBYTE T3AEN:1U;             /*   T3AEN      */
                    } BIT;                      /*              */
             } TITCR;                           /*              */
       union {                                  /* TITCNT       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE _4VCNT:3U;            /*   _4VCNT     */
                    _UBYTE :1U;                  /*              */
                    _UBYTE _3ACNT:3U;            /*   _3ACNT     */
                    _UBYTE :1U;                  /*              */
                    } BIT;                      /*              */
             } TITCNT;                          /*              */
       union {                                  /* TBTER        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE BTE:2U;               /*   BTE        */
                    _UBYTE :6U;                  /*              */
                    } BIT;                      /*              */
             } TBTER;                           /*              */
       _UBYTE wk4[1];                           /*              */
       union {                                  /* TDER         */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TDER:1U;              /*   TDER       */
                    _UBYTE :7U;                  /*              */
                    } BIT;                      /*              */
             } TDER;                            /*              */
       _UBYTE wk5[1];                           /*              */
       union {                                  /* TOLBR        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE OLS1P:1U;             /*   OLS1P      */
                    _UBYTE OLS1N:1U;             /*   OLS1N      */
                    _UBYTE OLS2P:1U;             /*   OLS2P      */
                    _UBYTE OLS2N:1U;             /*   OLS2N      */
                    _UBYTE OLS3P:1U;             /*   OLS3P      */
                    _UBYTE OLS3N:1U;             /*   OLS3N      */
                    _UBYTE :2U;                  /*              */
                    } BIT;                      /*              */
             } TOLBR;                           /*              */
       _UBYTE wk6[1];                           /*              */
       union {                                  /* TBTM_3       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TTSA:1U;              /*   TTSA       */
                    _UBYTE TTSB:1U;              /*   TTSB       */
                    _UBYTE :6U;                  /*              */
                    } BIT;                      /*              */
             } TBTM_3;                          /*              */
       union {                                  /* TBTM_4       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TTSA:1U;              /*   TTSA       */
                    _UBYTE TTSB:1U;              /*   TTSB       */
                    _UBYTE :6U;                  /*              */
                    } BIT;                      /*              */
             } TBTM_4;                          /*              */
       _UBYTE wk7[6];                           /*              */
       union {                                  /* TADCR        */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD ITB4VE:1U;            /*   ITB4VE     */
                    _UWORD ITB3AE:1U;            /*   ITB3AE     */
                    _UWORD ITA4VE:1U;            /*   ITA4VE     */
                    _UWORD ITA3AE:1U;            /*   ITA3AE     */
                    _UWORD DT4BE:1U;             /*   DT4BE      */
                    _UWORD UT4BE:1U;             /*   UT4BE      */
                    _UWORD DT4AE:1U;             /*   DT4AE      */
                    _UWORD UT4AE:1U;             /*   UT4AE      */
                    _UWORD :6U;                  /*              */
                    _UWORD BF:2U;                /*   BF         */
                    } BIT;                      /*              */
             } TADCR;                           /*              */
       _UBYTE wk8[2];                           /*              */
       union {                                  /* TADCORA_4    */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TADCORA_4;                       /*              */
       union {                                  /* TADCORB_4    */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TADCORB_4;                       /*              */
       union {                                  /* TADCOBRA_4   */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TADCOBRA_4;                      /*              */
       union {                                  /* TADCOBRB_4   */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TADCOBRB_4;                      /*              */
       _UBYTE wk9[20];                          /*              */
       union {                                  /* TWCR         */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE WRE:1U;               /*   WRE        */
                    _UBYTE :6U;                  /*              */
                    _UBYTE CCE:1U;               /*   CCE        */
                    } BIT;                      /*              */
             } TWCR;                            /*              */
       _UBYTE wk10[31];                         /*              */
       union {                                  /* TSTR         */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE CST0:1U;              /*   CST0       */
                    _UBYTE CST1:1U;              /*   CST1       */
                    _UBYTE CST2:1U;              /*   CST2       */
                    _UBYTE :3U;                  /*              */
                    _UBYTE CST3:1U;              /*   CST3       */
                    _UBYTE CST4:1U;              /*   CST4       */
                    } BIT;                      /*              */
             } TSTR;                            /*              */
       union {                                  /* TSYR         */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE SYNC0:1U;             /*   SYNC0      */
                    _UBYTE SYNC1:1U;             /*   SYNC1      */
                    _UBYTE SYNC2:1U;             /*   SYNC2      */
                    _UBYTE :3U;                  /*              */
                    _UBYTE SYNC3:1U;             /*   SYNC3      */
                    _UBYTE SYNC4:1U;             /*   SYNC4      */
                    } BIT;                      /*              */
             } TSYR;                            /*              */
       _UBYTE wk11[2];                          /*              */
       union {                                  /* TRWER        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE RWE:1U;               /*   RWE        */
                    _UBYTE :7U;                  /*              */
                    } BIT;                      /*              */
             } TRWER;                           /*              */
       _UBYTE wk12[123];                        /*              */
       union {                                  /* TCR_0        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TPSC:3U;              /*   TPSC       */
                    _UBYTE CKEG:2U;              /*   CKEG       */
                    _UBYTE CCLR:3U;              /*   CCLR       */
                    } BIT;                      /*              */
             } TCR_0;                           /*              */
       union {                                  /* TMDR_0       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE MD:4U;                /*   MD         */
                    _UBYTE BFA:1U;               /*   BFA        */
                    _UBYTE BFB:1U;               /*   BFB        */
                    _UBYTE BFE:1U;               /*   BFE        */
                    _UBYTE :1U;                  /*              */
                    } BIT;                      /*              */
             } TMDR_0;                          /*              */
       union {                                  /* TIORH_0      */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE IOA:4U;               /*   IOA        */
                    _UBYTE IOB:4U;               /*   IOB        */
                    } BIT;                      /*              */
             } TIORH_0;                         /*              */
       union {                                  /* TIORL_0      */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE IOC:4U;               /*   IOC        */
                    _UBYTE IOD:4U;               /*   IOD        */
                    } BIT;                      /*              */
             } TIORL_0;                         /*              */
       union {                                  /* TIER_0       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TGIEA:1U;             /*   TGIEA      */
                    _UBYTE TGIEB:1U;             /*   TGIEB      */
                    _UBYTE TGIEC:1U;             /*   TGIEC      */
                    _UBYTE TGIED:1U;             /*   TGIED      */
                    _UBYTE TCIEV:1U;             /*   TCIEV      */
                    _UBYTE :2U;                  /*              */
                    _UBYTE TTGE:1U;              /*   TTGE       */
                    } BIT;                      /*              */
             } TIER_0;                          /*              */
       union {                                  /* TSR_0        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TGFA:1U;              /*   TGFA       */
                    _UBYTE TGFB:1U;              /*   TGFB       */
                    _UBYTE TGFC:1U;              /*   TGFC       */
                    _UBYTE TGFD:1U;              /*   TGFD       */
                    _UBYTE TCFV:1U;              /*   TCFV       */
                    _UBYTE :3U;                  /*              */
                    } BIT;                      /*              */
             } TSR_0;                           /*              */
       union {                                  /* TCNT_0       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TCNT_0;                          /*              */
       union {                                  /* TGRA_0       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRA_0;                          /*              */
       union {                                  /* TGRB_0       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRB_0;                          /*              */
       union {                                  /* TGRC_0       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRC_0;                          /*              */
       union {                                  /* TGRD_0       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRD_0;                          /*              */
       _UBYTE wk13[16];                         /*              */
       union {                                  /* TGRE_0       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRE_0;                          /*              */
       union {                                  /* TGRF_0       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRF_0;                          /*              */
       union {                                  /* TIER2_0      */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TGIEE:1U;             /*   TGIEE      */
                    _UBYTE TGIEF:1U;             /*   TGIEF      */
                    _UBYTE :5U;                  /*              */
                    _UBYTE TTGE2:1U;             /*   TTGE2      */
                    } BIT;                      /*              */
             } TIER2_0;                         /*              */
       union {                                  /* TSR2_0       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TGFE:1U;              /*   TGFE       */
                    _UBYTE TGFF:1U;              /*   TGFF       */
                    _UBYTE :6U;                  /*              */
                    } BIT;                      /*              */
             } TSR2_0;                          /*              */
       union {                                  /* TBTM_0       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TTSA:1U;              /*   TTSA       */
                    _UBYTE TTSB:1U;              /*   TTSB       */
                    _UBYTE TTSE:1U;              /*   TTSE       */
                    _UBYTE :5U;                  /*              */
                    } BIT;                      /*              */
             } TBTM_0;                          /*              */
       _UBYTE wk14[89];                         /*              */
       union {                                  /* TCR_1        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TPSC:3U;              /*   TPSC       */
                    _UBYTE CKEG:2U;              /*   CKEG       */
                    _UBYTE CCLR:2U;              /*   CCLR       */
                    _UBYTE :1U;
                    } BIT;                      /*              */
             } TCR_1;                           /*              */
       union {                                  /* TMDR_1       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE MD:4U;                /*   MD         */
                    _UBYTE :4U;                  /*              */
                    } BIT;                      /*              */
             } TMDR_1;                          /*              */
       union {                                  /* TIOR_1       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE IOA:4U;               /*   IOA        */
                    _UBYTE IOB:4U;               /*   IOB        */
                    } BIT;                      /*              */
             } TIOR_1;                          /*              */
       _UBYTE wk15[1];                          /*              */
       union {                                  /* TIER_1       */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TGIEA:1U;             /*   TGIEA      */
                    _UBYTE TGIEB:1U;             /*   TGIEB      */
                    _UBYTE :2U;                  /*              */
                    _UBYTE TCIEV:1U;             /*   TCIEV      */
                    _UBYTE TCIEU:1U;             /*   TCIEU      */
                    _UBYTE :1U;                  /*              */
                    _UBYTE TTGE:1U;              /*   TTGE       */
                    } BIT;                      /*              */
             } TIER_1;                          /*              */
       union {                                  /* TSR_1        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE TGFA:1U;              /*   TGFA       */
                    _UBYTE TGFB:1U;              /*   TGFB       */
                    _UBYTE :2U;                  /*              */
                    _UBYTE TCFV:1U;              /*   TCFV       */
                    _UBYTE TCFU:1U;              /*   TCFU       */
                    _UBYTE :1U;                  /*              */
                    _UBYTE TCFD:1U;              /*   TCFD       */
                    } BIT;                      /*              */
             } TSR_1;                           /*              */
       union {                                  /* TCNT_1       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TCNT_1;                          /*              */
       union {                                  /* TGRA_1       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRA_1;                          /*              */
       union {                                  /* TGRB_1       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD D:16U;                /*   D          */
                    } BIT;                      /*              */
             } TGRB_1;                          /*              */
       _UBYTE wk16[4];                          /*              */
       union {                                  /* TICCR        */
             _UBYTE BYTE;                       /*  Byte Access */
             struct {                           /*  Bit Access  */
                    _UBYTE I1AE:1U;              /*   I1AE       */
                    _UBYTE I1BE:1U;              /*   I1BE       */
                    _UBYTE I2AE:1U;              /*   I2AE       */
                    _UBYTE I2BE:1U;              /*   I2BE       */
                    _UBYTE :4U;                  /*              */
                    } BIT;                      /*              */
             } TICCR;                           /*              */
};                                              /*              */


#define MTU2 (*(volatile struct st_mtu2 *)0xFCFF0000UL)  /* MTU2 Address */

#endif /* __MTU2_IODEFINE_H__ */
/* End of File */
