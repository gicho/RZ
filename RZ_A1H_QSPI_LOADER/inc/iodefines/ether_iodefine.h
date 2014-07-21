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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : ether_iodefine.h
* $Rev: 809 $
* $Date:: 2014-03-28 19:15:55 +0000#$
* Description : Definition of I/O Register (V0.50j)
******************************************************************************/
#ifndef ETHER_IODEFINE_H
#define ETHER_IODEFINE_H

struct st_ether
{                                                          /* ETHER            */
    uint32_t       EDSR0;                                  /*  EDSR0           */
    uint8_t        dummy224[12];                           /*                  */
    uint32_t       TDLAR0;                                 /*  TDLAR0          */
    uint32_t       TDFAR0;                                 /*  TDFAR0          */
    uint32_t       TDFXR0;                                 /*  TDFXR0          */
    uint32_t       TDFFR0;                                 /*  TDFFR0          */
    uint8_t        dummy225[16];                           /*                  */
    uint32_t       RDLAR0;                                 /*  RDLAR0          */
    uint32_t       RDFAR0;                                 /*  RDFAR0          */
    uint32_t       RDFXR0;                                 /*  RDFXR0          */
    uint32_t       RDFFR0;                                 /*  RDFFR0          */
    uint8_t        dummy226[960];                          /*                  */
    uint32_t       EDMR0;                                  /*  EDMR0           */
    uint8_t        dummy227[4];                            /*                  */
    uint32_t       EDTRR0;                                 /*  EDTRR0          */
    uint8_t        dummy228[4];                            /*                  */
    uint32_t       EDRRR0;                                 /*  EDRRR0          */
    uint8_t        dummy229[20];                           /*                  */
    uint32_t       EESR0;                                  /*  EESR0           */
    uint8_t        dummy230[4];                            /*                  */
    uint32_t       EESIPR0;                                /*  EESIPR0         */
    uint8_t        dummy231[4];                            /*                  */
    uint32_t       TRSCER0;                                /*  TRSCER0         */
    uint8_t        dummy232[4];                            /*                  */
    uint32_t       RMFCR0;                                 /*  RMFCR0          */
    uint8_t        dummy233[4];                            /*                  */
    uint32_t       TFTR0;                                  /*  TFTR0           */
    uint8_t        dummy234[4];                            /*                  */
    uint32_t       FDR0;                                   /*  FDR0            */
    uint8_t        dummy235[4];                            /*                  */
    uint32_t       RMCR0;                                  /*  RMCR0           */
    uint8_t        dummy236[4];                            /*                  */
    uint32_t       RPADIR0;                                /*  RPADIR0         */
    uint8_t        dummy237[4];                            /*                  */
    uint32_t       FCFTR0;                                 /*  FCFTR0          */
    uint8_t        dummy238[120];                          /*                  */
    uint32_t       CSMR;                                   /*  CSMR            */
    uint32_t       CSSBM;                                  /*  CSSBM           */
    uint32_t       CSSMR;                                  /*  CSSMR           */
    uint8_t        dummy239[16];                           /*                  */
    uint32_t       ECMR0;                                  /*  ECMR0           */
    uint8_t        dummy240[4];                            /*                  */
    uint32_t       RFLR0;                                  /*  RFLR0           */
    uint8_t        dummy241[4];                            /*                  */
    uint32_t       ECSR0;                                  /*  ECSR0           */
    uint8_t        dummy242[4];                            /*                  */
    uint32_t       ECSIPR0;                                /*  ECSIPR0         */
    uint8_t        dummy243[4];                            /*                  */
    uint32_t       PIR0;                                   /*  PIR0            */
    uint8_t        dummy244[48];                           /*                  */
    uint32_t       APR0;                                   /*  APR0            */
    uint32_t       MPR0;                                   /*  MPR0            */
    uint32_t       PFTCR0;                                 /*  PFTCR0          */
    uint32_t       PFRCR0;                                 /*  PFRCR0          */
    uint32_t       TPAUSER0;                               /*  TPAUSER0        */
    uint8_t        dummy245[88];                           /*                  */
    uint32_t       MAHR0;                                  /*  MAHR0           */
    uint8_t        dummy246[4];                            /*                  */
    uint32_t       MALR0;                                  /*  MALR0           */
    uint8_t        dummy247[372];                          /*                  */
    uint32_t       CEFCR0;                                 /*  CEFCR0          */
    uint8_t        dummy248[4];                            /*                  */
    uint32_t       FRECR0;                                 /*  FRECR0          */
    uint8_t        dummy249[4];                            /*                  */
    uint32_t       TSFRCR0;                                /*  TSFRCR0         */
    uint8_t        dummy250[4];                            /*                  */
    uint32_t       TLFRCR0;                                /*  TLFRCR0         */
    uint8_t        dummy251[4];                            /*                  */
    uint32_t       RFCR0;                                  /*  RFCR0           */
    uint8_t        dummy252[20];                           /*                  */
    uint32_t       MAFCR0;                                 /*  MAFCR0          */
    uint8_t        dummy253[4228];                         /*                  */
    uint32_t       ARSTR;                                  /*  ARSTR           */
    uint32_t       TSU_CTRST;                              /*  TSU_CTRST       */
    uint8_t        dummy254[80];                           /*                  */
    uint32_t       TSU_VTAG0;                              /*  TSU_VTAG0       */
    uint8_t        dummy255[4];                            /*                  */
    uint32_t       TSU_ADSBSY;                             /*  TSU_ADSBSY      */
    uint32_t       TSU_TEN;                                /*  TSU_TEN         */
    uint8_t        dummy256[24];                           /*                  */
    uint32_t       TXNLCR0;                                /*  TXNLCR0         */
    uint32_t       TXALCR0;                                /*  TXALCR0         */
    uint32_t       RXNLCR0;                                /*  RXNLCR0         */
    uint32_t       RXALCR0;                                /*  RXALCR0         */
    uint8_t        dummy257[112];                          /*                  */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH0;                              /*  TSU_ADRH0       */
    uint32_t       TSU_ADRL0;                              /*  TSU_ADRL0       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH1;                              /*  TSU_ADRH1       */
    uint32_t       TSU_ADRL1;                              /*  TSU_ADRL1       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH2;                              /*  TSU_ADRH2       */
    uint32_t       TSU_ADRL2;                              /*  TSU_ADRL2       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH3;                              /*  TSU_ADRH3       */
    uint32_t       TSU_ADRL3;                              /*  TSU_ADRL3       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH4;                              /*  TSU_ADRH4       */
    uint32_t       TSU_ADRL4;                              /*  TSU_ADRL4       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH5;                              /*  TSU_ADRH5       */
    uint32_t       TSU_ADRL5;                              /*  TSU_ADRL5       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH6;                              /*  TSU_ADRH6       */
    uint32_t       TSU_ADRL6;                              /*  TSU_ADRL6       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH7;                              /*  TSU_ADRH7       */
    uint32_t       TSU_ADRL7;                              /*  TSU_ADRL7       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH8;                              /*  TSU_ADRH8       */
    uint32_t       TSU_ADRL8;                              /*  TSU_ADRL8       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH9;                              /*  TSU_ADRH9       */
    uint32_t       TSU_ADRL9;                              /*  TSU_ADRL9       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH10;                             /*  TSU_ADRH10      */
    uint32_t       TSU_ADRL10;                             /*  TSU_ADRL10      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH11;                             /*  TSU_ADRH11      */
    uint32_t       TSU_ADRL11;                             /*  TSU_ADRL11      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH12;                             /*  TSU_ADRH12      */
    uint32_t       TSU_ADRL12;                             /*  TSU_ADRL12      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH13;                             /*  TSU_ADRH13      */
    uint32_t       TSU_ADRL13;                             /*  TSU_ADRL13      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH14;                             /*  TSU_ADRH14      */
    uint32_t       TSU_ADRL14;                             /*  TSU_ADRL14      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH15;                             /*  TSU_ADRH15      */
    uint32_t       TSU_ADRL15;                             /*  TSU_ADRL15      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH16;                             /*  TSU_ADRH16      */
    uint32_t       TSU_ADRL16;                             /*  TSU_ADRL16      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH17;                             /*  TSU_ADRH17      */
    uint32_t       TSU_ADRL17;                             /*  TSU_ADRL17      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH18;                             /*  TSU_ADRH18      */
    uint32_t       TSU_ADRL18;                             /*  TSU_ADRL18      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH19;                             /*  TSU_ADRH19      */
    uint32_t       TSU_ADRL19;                             /*  TSU_ADRL19      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH20;                             /*  TSU_ADRH20      */
    uint32_t       TSU_ADRL20;                             /*  TSU_ADRL20      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH21;                             /*  TSU_ADRH21      */
    uint32_t       TSU_ADRL21;                             /*  TSU_ADRL21      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH22;                             /*  TSU_ADRH22      */
    uint32_t       TSU_ADRL22;                             /*  TSU_ADRL22      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH23;                             /*  TSU_ADRH23      */
    uint32_t       TSU_ADRL23;                             /*  TSU_ADRL23      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH24;                             /*  TSU_ADRH24      */
    uint32_t       TSU_ADRL24;                             /*  TSU_ADRL24      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH25;                             /*  TSU_ADRH25      */
    uint32_t       TSU_ADRL25;                             /*  TSU_ADRL25      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH26;                             /*  TSU_ADRH26      */
    uint32_t       TSU_ADRL26;                             /*  TSU_ADRL26      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH27;                             /*  TSU_ADRH27      */
    uint32_t       TSU_ADRL27;                             /*  TSU_ADRL27      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH28;                             /*  TSU_ADRH28      */
    uint32_t       TSU_ADRL28;                             /*  TSU_ADRL28      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH29;                             /*  TSU_ADRH29      */
    uint32_t       TSU_ADRL29;                             /*  TSU_ADRL29      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH30;                             /*  TSU_ADRH30      */
    uint32_t       TSU_ADRL30;                             /*  TSU_ADRL30      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    uint32_t       TSU_ADRH31;                             /*  TSU_ADRH31      */
    uint32_t       TSU_ADRL31;                             /*  TSU_ADRL31      */
/* end of struct st_ether_from_tsu_adrh0 */
};


struct st_ether_from_tsu_adrh0
{
    uint32_t       TSU_ADRH0;                              /*  TSU_ADRH0       */
    uint32_t       TSU_ADRL0;                              /*  TSU_ADRL0       */
};


#define ETHER   (*(volatile struct st_ether   *)0xE8203000uL) /* ETHER */


/* Start of channnel array defines of ETHER */

/* Channnel array defines of ETHER_FROM_TSU_ADRH0_ARRAY */
/*(Sample) value = ETHER_FROM_TSU_ADRH0_ARRAY[ channel ]->TSU_ADRH0; */
#define ETHER_FROM_TSU_ADRH0_ARRAY_COUNT  32
#define ETHER_FROM_TSU_ADRH0_ARRAY_ADDRESS_LIST \
    &ETHER_FROM_TSU_ADRH0, &ETHER_FROM_TSU_ADRH1, &ETHER_FROM_TSU_ADRH2, &ETHER_FROM_TSU_ADRH3, &ETHER_FROM_TSU_ADRH4, &ETHER_FROM_TSU_ADRH5, &ETHER_FROM_TSU_ADRH6, &ETHER_FROM_TSU_ADRH7, \
    &ETHER_FROM_TSU_ADRH8, &ETHER_FROM_TSU_ADRH9, &ETHER_FROM_TSU_ADRH10, &ETHER_FROM_TSU_ADRH11, &ETHER_FROM_TSU_ADRH12, &ETHER_FROM_TSU_ADRH13, &ETHER_FROM_TSU_ADRH14, &ETHER_FROM_TSU_ADRH15, \
    &ETHER_FROM_TSU_ADRH16, &ETHER_FROM_TSU_ADRH17, &ETHER_FROM_TSU_ADRH18, &ETHER_FROM_TSU_ADRH19, &ETHER_FROM_TSU_ADRH20, &ETHER_FROM_TSU_ADRH21, &ETHER_FROM_TSU_ADRH22, &ETHER_FROM_TSU_ADRH23, \
    &ETHER_FROM_TSU_ADRH24, &ETHER_FROM_TSU_ADRH25, &ETHER_FROM_TSU_ADRH26, &ETHER_FROM_TSU_ADRH27, &ETHER_FROM_TSU_ADRH28, &ETHER_FROM_TSU_ADRH29, &ETHER_FROM_TSU_ADRH30, &ETHER_FROM_TSU_ADRH31
#define ETHER_FROM_TSU_ADRH0 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH0) /* ETHER_FROM_TSU_ADRH0 */
#define ETHER_FROM_TSU_ADRH1 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH1) /* ETHER_FROM_TSU_ADRH1 */
#define ETHER_FROM_TSU_ADRH2 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH2) /* ETHER_FROM_TSU_ADRH2 */
#define ETHER_FROM_TSU_ADRH3 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH3) /* ETHER_FROM_TSU_ADRH3 */
#define ETHER_FROM_TSU_ADRH4 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH4) /* ETHER_FROM_TSU_ADRH4 */
#define ETHER_FROM_TSU_ADRH5 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH5) /* ETHER_FROM_TSU_ADRH5 */
#define ETHER_FROM_TSU_ADRH6 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH6) /* ETHER_FROM_TSU_ADRH6 */
#define ETHER_FROM_TSU_ADRH7 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH7) /* ETHER_FROM_TSU_ADRH7 */
#define ETHER_FROM_TSU_ADRH8 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH8) /* ETHER_FROM_TSU_ADRH8 */
#define ETHER_FROM_TSU_ADRH9 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH9) /* ETHER_FROM_TSU_ADRH9 */
#define ETHER_FROM_TSU_ADRH10 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH10) /* ETHER_FROM_TSU_ADRH10 */
#define ETHER_FROM_TSU_ADRH11 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH11) /* ETHER_FROM_TSU_ADRH11 */
#define ETHER_FROM_TSU_ADRH12 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH12) /* ETHER_FROM_TSU_ADRH12 */
#define ETHER_FROM_TSU_ADRH13 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH13) /* ETHER_FROM_TSU_ADRH13 */
#define ETHER_FROM_TSU_ADRH14 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH14) /* ETHER_FROM_TSU_ADRH14 */
#define ETHER_FROM_TSU_ADRH15 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH15) /* ETHER_FROM_TSU_ADRH15 */
#define ETHER_FROM_TSU_ADRH16 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH16) /* ETHER_FROM_TSU_ADRH16 */
#define ETHER_FROM_TSU_ADRH17 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH17) /* ETHER_FROM_TSU_ADRH17 */
#define ETHER_FROM_TSU_ADRH18 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH18) /* ETHER_FROM_TSU_ADRH18 */
#define ETHER_FROM_TSU_ADRH19 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH19) /* ETHER_FROM_TSU_ADRH19 */
#define ETHER_FROM_TSU_ADRH20 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH20) /* ETHER_FROM_TSU_ADRH20 */
#define ETHER_FROM_TSU_ADRH21 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH21) /* ETHER_FROM_TSU_ADRH21 */
#define ETHER_FROM_TSU_ADRH22 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH22) /* ETHER_FROM_TSU_ADRH22 */
#define ETHER_FROM_TSU_ADRH23 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH23) /* ETHER_FROM_TSU_ADRH23 */
#define ETHER_FROM_TSU_ADRH24 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH24) /* ETHER_FROM_TSU_ADRH24 */
#define ETHER_FROM_TSU_ADRH25 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH25) /* ETHER_FROM_TSU_ADRH25 */
#define ETHER_FROM_TSU_ADRH26 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH26) /* ETHER_FROM_TSU_ADRH26 */
#define ETHER_FROM_TSU_ADRH27 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH27) /* ETHER_FROM_TSU_ADRH27 */
#define ETHER_FROM_TSU_ADRH28 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH28) /* ETHER_FROM_TSU_ADRH28 */
#define ETHER_FROM_TSU_ADRH29 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH29) /* ETHER_FROM_TSU_ADRH29 */
#define ETHER_FROM_TSU_ADRH30 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH30) /* ETHER_FROM_TSU_ADRH30 */
#define ETHER_FROM_TSU_ADRH31 (*(volatile struct st_ether_from_tsu_adrh0 *)&ETHER.TSU_ADRH31) /* ETHER_FROM_TSU_ADRH31 */

/* End of channnel array defines of ETHER */


#define ETHEREDSR0 ETHER.EDSR0
#define ETHERTDLAR0 ETHER.TDLAR0
#define ETHERTDFAR0 ETHER.TDFAR0
#define ETHERTDFXR0 ETHER.TDFXR0
#define ETHERTDFFR0 ETHER.TDFFR0
#define ETHERRDLAR0 ETHER.RDLAR0
#define ETHERRDFAR0 ETHER.RDFAR0
#define ETHERRDFXR0 ETHER.RDFXR0
#define ETHERRDFFR0 ETHER.RDFFR0
#define ETHEREDMR0 ETHER.EDMR0
#define ETHEREDTRR0 ETHER.EDTRR0
#define ETHEREDRRR0 ETHER.EDRRR0
#define ETHEREESR0 ETHER.EESR0
#define ETHEREESIPR0 ETHER.EESIPR0
#define ETHERTRSCER0 ETHER.TRSCER0
#define ETHERRMFCR0 ETHER.RMFCR0
#define ETHERTFTR0 ETHER.TFTR0
#define ETHERFDR0 ETHER.FDR0
#define ETHERRMCR0 ETHER.RMCR0
#define ETHERRPADIR0 ETHER.RPADIR0
#define ETHERFCFTR0 ETHER.FCFTR0
#define ETHERCSMR ETHER.CSMR
#define ETHERCSSBM ETHER.CSSBM
#define ETHERCSSMR ETHER.CSSMR
#define ETHERECMR0 ETHER.ECMR0
#define ETHERRFLR0 ETHER.RFLR0
#define ETHERECSR0 ETHER.ECSR0
#define ETHERECSIPR0 ETHER.ECSIPR0
#define ETHERPIR0 ETHER.PIR0
#define ETHERAPR0 ETHER.APR0
#define ETHERMPR0 ETHER.MPR0
#define ETHERPFTCR0 ETHER.PFTCR0
#define ETHERPFRCR0 ETHER.PFRCR0
#define ETHERTPAUSER0 ETHER.TPAUSER0
#define ETHERMAHR0 ETHER.MAHR0
#define ETHERMALR0 ETHER.MALR0
#define ETHERCEFCR0 ETHER.CEFCR0
#define ETHERFRECR0 ETHER.FRECR0
#define ETHERTSFRCR0 ETHER.TSFRCR0
#define ETHERTLFRCR0 ETHER.TLFRCR0
#define ETHERRFCR0 ETHER.RFCR0
#define ETHERMAFCR0 ETHER.MAFCR0
#define ETHERARSTR ETHER.ARSTR
#define ETHERTSU_CTRST ETHER.TSU_CTRST
#define ETHERTSU_VTAG0 ETHER.TSU_VTAG0
#define ETHERTSU_ADSBSY ETHER.TSU_ADSBSY
#define ETHERTSU_TEN ETHER.TSU_TEN
#define ETHERTXNLCR0 ETHER.TXNLCR0
#define ETHERTXALCR0 ETHER.TXALCR0
#define ETHERRXNLCR0 ETHER.RXNLCR0
#define ETHERRXALCR0 ETHER.RXALCR0
#define ETHERTSU_ADRH0 ETHER.TSU_ADRH0
#define ETHERTSU_ADRL0 ETHER.TSU_ADRL0
#define ETHERTSU_ADRH1 ETHER.TSU_ADRH1
#define ETHERTSU_ADRL1 ETHER.TSU_ADRL1
#define ETHERTSU_ADRH2 ETHER.TSU_ADRH2
#define ETHERTSU_ADRL2 ETHER.TSU_ADRL2
#define ETHERTSU_ADRH3 ETHER.TSU_ADRH3
#define ETHERTSU_ADRL3 ETHER.TSU_ADRL3
#define ETHERTSU_ADRH4 ETHER.TSU_ADRH4
#define ETHERTSU_ADRL4 ETHER.TSU_ADRL4
#define ETHERTSU_ADRH5 ETHER.TSU_ADRH5
#define ETHERTSU_ADRL5 ETHER.TSU_ADRL5
#define ETHERTSU_ADRH6 ETHER.TSU_ADRH6
#define ETHERTSU_ADRL6 ETHER.TSU_ADRL6
#define ETHERTSU_ADRH7 ETHER.TSU_ADRH7
#define ETHERTSU_ADRL7 ETHER.TSU_ADRL7
#define ETHERTSU_ADRH8 ETHER.TSU_ADRH8
#define ETHERTSU_ADRL8 ETHER.TSU_ADRL8
#define ETHERTSU_ADRH9 ETHER.TSU_ADRH9
#define ETHERTSU_ADRL9 ETHER.TSU_ADRL9
#define ETHERTSU_ADRH10 ETHER.TSU_ADRH10
#define ETHERTSU_ADRL10 ETHER.TSU_ADRL10
#define ETHERTSU_ADRH11 ETHER.TSU_ADRH11
#define ETHERTSU_ADRL11 ETHER.TSU_ADRL11
#define ETHERTSU_ADRH12 ETHER.TSU_ADRH12
#define ETHERTSU_ADRL12 ETHER.TSU_ADRL12
#define ETHERTSU_ADRH13 ETHER.TSU_ADRH13
#define ETHERTSU_ADRL13 ETHER.TSU_ADRL13
#define ETHERTSU_ADRH14 ETHER.TSU_ADRH14
#define ETHERTSU_ADRL14 ETHER.TSU_ADRL14
#define ETHERTSU_ADRH15 ETHER.TSU_ADRH15
#define ETHERTSU_ADRL15 ETHER.TSU_ADRL15
#define ETHERTSU_ADRH16 ETHER.TSU_ADRH16
#define ETHERTSU_ADRL16 ETHER.TSU_ADRL16
#define ETHERTSU_ADRH17 ETHER.TSU_ADRH17
#define ETHERTSU_ADRL17 ETHER.TSU_ADRL17
#define ETHERTSU_ADRH18 ETHER.TSU_ADRH18
#define ETHERTSU_ADRL18 ETHER.TSU_ADRL18
#define ETHERTSU_ADRH19 ETHER.TSU_ADRH19
#define ETHERTSU_ADRL19 ETHER.TSU_ADRL19
#define ETHERTSU_ADRH20 ETHER.TSU_ADRH20
#define ETHERTSU_ADRL20 ETHER.TSU_ADRL20
#define ETHERTSU_ADRH21 ETHER.TSU_ADRH21
#define ETHERTSU_ADRL21 ETHER.TSU_ADRL21
#define ETHERTSU_ADRH22 ETHER.TSU_ADRH22
#define ETHERTSU_ADRL22 ETHER.TSU_ADRL22
#define ETHERTSU_ADRH23 ETHER.TSU_ADRH23
#define ETHERTSU_ADRL23 ETHER.TSU_ADRL23
#define ETHERTSU_ADRH24 ETHER.TSU_ADRH24
#define ETHERTSU_ADRL24 ETHER.TSU_ADRL24
#define ETHERTSU_ADRH25 ETHER.TSU_ADRH25
#define ETHERTSU_ADRL25 ETHER.TSU_ADRL25
#define ETHERTSU_ADRH26 ETHER.TSU_ADRH26
#define ETHERTSU_ADRL26 ETHER.TSU_ADRL26
#define ETHERTSU_ADRH27 ETHER.TSU_ADRH27
#define ETHERTSU_ADRL27 ETHER.TSU_ADRL27
#define ETHERTSU_ADRH28 ETHER.TSU_ADRH28
#define ETHERTSU_ADRL28 ETHER.TSU_ADRL28
#define ETHERTSU_ADRH29 ETHER.TSU_ADRH29
#define ETHERTSU_ADRL29 ETHER.TSU_ADRL29
#define ETHERTSU_ADRH30 ETHER.TSU_ADRH30
#define ETHERTSU_ADRL30 ETHER.TSU_ADRL30
#define ETHERTSU_ADRH31 ETHER.TSU_ADRH31
#define ETHERTSU_ADRL31 ETHER.TSU_ADRL31
#endif
