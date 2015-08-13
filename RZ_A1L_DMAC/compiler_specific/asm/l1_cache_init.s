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

	.text
	.code 32

	.global L1_CachesEnable_asm

	.func L1_CachesEnable_asm
L1_CachesEnable_asm:

/******************************************************************************
* Enable caches                                                              *
******************************************************************************/
	MRC  p15, 0, r0, c1, c0, 0			    /* Read CP15 register 1 */
	ORR  r0, r0, #(0x1 << 12)			    /* Enable I Cache */
	ORR  r0, r0, #(0x1 << 11)				/* Enable program flow prediction */
	ORR  r0, r0, #(0x1 << 2)			    /* Enable D Cache */
	MCR  p15, 0, r0, c1, c0, 0			    /* Write CP15 register 1 */
	ISB

/******************************************************************************/
/* Enable D-side prefetch                                                     */
/******************************************************************************/
	MRC  p15, 0, r0, c1, c0, 1			   /* Read Auxiliary Control Register */
	ORR  r0, r0, #(0x1 << 2)			     /* Enable Dside prefetch */
	MCR  p15, 0, r0, c1, c0, 1			/* Write Auxiliary Control Register */
	ISB

	BX   lr

	.endfunc
	.align 4

	.end

