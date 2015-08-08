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
* Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name     : l1_cache_init.S
* Device(s)     : RZ/A1H (R7S721001)
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : This code provides basic global enable for Cortex-A9 cache.
*               : It also enables branch prediction.
*               : This code must be run from a privileged mode.
*******************************************************************************/
/*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*               : 21.03.2014 2.00
*******************************************************************************/
    NAME L1_CACHE_INIT_S
    SECTION L1_CACHE_INIT:CODE(4)
    ARM

    PUBLIC L1_CachesEnable_asm
    PUBLIC

/* Standard definitions of CPSR bits */
V_BIT EQU 0x2000
I_BIT EQU 0x1000
Z_BIT EQU 0x800
C_BIT EQU 0x4
A_BIT EQU 0x2
M_BIT EQU 0x1

L1_CachesEnable_asm:

/******************************************************************************/
/* Enable caches                                                              */
/******************************************************************************/
    /* Read CP15 SCTLR */
    MRC  p15, 0, r0, c1, c0, 0

    /* 	Set I bit 12 to enable I Cache
    	Set Z bit 11 to enable flow prediction
    	Set C bit  2 to en D Cache
    */
    /* BIC has 8 bit immediate + 4 bit rotation so cannot address directly above first byte */
    ORR  r0, r0, #(I_BIT)
    ORR  r0, r0, #(Z_BIT)
    ORR  r0, r0, #(C_BIT)
    MCR  p15, 0, r0, c1, c0, 0		     /* Write CP15 register 1 */
    ISB
    
/******************************************************************************/
/* Enable D-side prefetch                                                     */
/******************************************************************************/
    MRC  p15, 0, r0, c1, c0, 1         /* Read Auxiliary Control Register */
    ORR  r0, r0, #(0x1 << 2)		     /* Enable Dside prefetch */
    MCR  p15, 0, r0, c1, c0, 1	  /* Write Auxiliary Control Register */
    ISB
    BX   lr

        END
