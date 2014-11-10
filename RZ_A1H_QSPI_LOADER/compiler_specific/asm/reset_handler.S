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
/******************************************************************************
* File Name     : reset_handler.S
* Device(s)     : RZ/A1H RSK2+RZA1H
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK2+RZA1H CPU Board
* Description   : Called by reset vector (start.S/mirrorstart.S)
*               : As such its the startpoint for this software
******************************************************************************/
/******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 03.03.2014 1.00
******************************************************************************/

    .global QSPI_BL_reset_handler
    .global QSPI_BL_undefined_handler
    .global QSPI_BL_svc_handler
    .global QSPI_BL_prefetch_handler
    .global QSPI_BL_abort_handler
    .global QSPI_BL_reserved_handler
    .global QSPI_BL_irq_handler
    .global QSPI_BL_fiq_handler

    .text

/* Standard definitions of mode bits and interrupt flags in PSRs */
    .equ    USR_MODE , 0x10
    .equ    FIQ_MODE , 0x11
    .equ    IRQ_MODE , 0x12
    .equ    SVC_MODE , 0x13
    .equ    ABT_MODE , 0x17
    .equ    UND_MODE , 0x1b
    .equ    SYS_MODE , 0x1f
    .equ    Thum_bit , 0x20                           /* CPSR/SPSR Thumb bit */


/* Standard definitions of CPSR bits */
    .equ    V_BIT , 0x2000
    .equ    I_BIT , 0x1000
    .equ    Z_BIT , 0x800
    .equ    C_BIT , 0x4
    .equ    A_BIT , 0x2
    .equ    M_BIT , 0x1

/* ========================================================================= */
/* Entry point for the Reset handler */
/* ========================================================================= */
//;******************************************************************************
//; Function Name : reset_handler
//; Description   : This function is the assembler function executed after reset
//;               : cancellation. After initial setting for the stack pointer or
//;               : the MMU and reset cancellation, executes initial setting for
//;               : the minimum required peripheral functions. Calls the __main
//;               : of the standard library function to execute the main function.
//;******************************************************************************
QSPI_BL_reset_handler:

/* ========================================================================= */
/* Multi-core startup (future proofing boot code)                            */
/* Check core, if not core 0  put to sleep.                                  */
/* ========================================================================= */
/* not needed on single processor systems, removed from module */
.if 0
        MRC     p15, 0, r0, c0, c0, 5	/* cp,  OP1,  Rd,  CRn, CRm,  OP2 */
        								/* read in R0 the value of the MPIDR register */
        ANDS    r0, r0, #3				/* bit[1:0] = CPU ID */
        								/* bit[11:8] = Cluster ID */
        								/* bit[30] = U Bit, 1 means uniprocessor */
        								/* bit[31] = always 1 */
goToSleep:
        WFINE							/* if non zero, sleep */
        BNE     goToSleep

.endif

/* ========================================================================= */
/* Clock Setting															 */
/* ========================================================================= */

/* Set standby_mode_en of Power Control Register
 Needed before changing frequency
 Located in PL310 L2 cache controller
 reg15_power_ctrl @ offset 0xF80
 Base register is @ H'3FFFF000
*/
/*
    .equ    STBY_MODE_EN      , (0x1)
    .equ    DYNCLK_GATING_DIS , (0x0)
    .equ    PWR_CTRL_BITS     , (STBY_MODE_EN | DYNCLK_GATING_DIS)

    LDR  r0, =0x3FFFFF80
    LDR  r1, =PWR_CTRL_BITS
    STR  r1, [r0]
    ISB
    LDR  r0, [r0]
*/

/* program the frequency control register
 Bit[14] = 0 - clock output enable control (unstable = 0, fixed low = 1)
 Bit[13,12] = 01b - output clock when active, keep low when using power save modes
 Bit[9,8] = 00b - CPU clock ratio = 1/1 with PLL
 Bit [5,4,2,0] - fixed to 1
 XTAL = 13,33 MHz, PLL = x30, CPU CLOCK = 400 MHz
*/
/*
    .equ    CKOEN2_BIT , (0x1 << 14)
    .equ    CKOEN_BITS , (0x1 << 12)
    .equ    IFC_BITS   , (0x0 << 8)
    .equ    CONST_BITS , (0x35)
    .equ    FRQCR      , (CKOEN2_BIT | CKOEN_BITS | IFC_BITS | CONST_BITS)

    LDR  r0, =0xFCFE0010
    LDR  r1, =FRQCR
    STRH r1, [r0]
    ISB
    LDRH r0, [r0]
*/
/* BCLK is 1/3 = 133,33 MHz fixed ratio */
/* P0CLK is 1/6 = 66,67 MHz fixed ratio */
/* P1CLK is 1/12 = 33,33 MHz fixed ratio */

/* program the frequency control register 2
 Bit [1,0] = 01b - Graphics clock ratio of 2/3
 GCLK = 266,67 MHz
*/
/*
    .equ    GFC_BITS , (0x1)

    LDR  r0, =0xFCFE0014
    LDR  r1, =GFC_BITS
    STRH r1, [r0]
    ISB
    LDRH r0, [r0]
    */

/* ========================================================================= */
/* Vector Table Setting															 */
/* ========================================================================= */

/* Disable cache and MMU just to be sure
 After QSPI, eSD or eMMC boot mode the system is configured to use High address
 0 = Normal (Low address) Vectors 0x00000000
 1 = High (High address) Vectors 0xFFFF0000
 Need to change this to use the application vector table located at address 0x0
 Could use MMU, or VBAR, or address remapping on the bus (CS0<>RAM0)
 Here we use VBAR
*/

    /* Read CP15 SCTLR                            */
    MRC  p15, 0, r0, c1, c0, 0

    /* 	Clear V bit 13 to set low vectors
    	Clear I bit 12 to disable I Cache
    	Clear Z bit 11 to disable flow prediction
    	Clear C bit  2 to disable D Cache
    	Clear A bit  1 to disable strict alignment
    	Clear M bit  0 to disable MMU
    */
    /* BIC has 8 bit immediate + 4 bit rotation so cannot address directly above first byte */
    BIC  r0, r0, #(V_BIT)
    BIC  r0, r0, #(I_BIT)
    BIC  r0, r0, #(Z_BIT)
    BIC  r0, r0, #(C_BIT | A_BIT | M_BIT)

    /* Write value back to CP15 SCR */
    MCR  p15, 0, r0, c1, c0, 0

/* Now set Vbar to the BL vector table                                       */
    LDR r0, = QSPI_BL_vector_table
    MCR p15, 0, r0, c12, c0, 0


/* ========================================================================= */
/*  Setting up Stack Area									                 */
/* ========================================================================= */
/* Configure to supervisor mode just to be sure (default)                                                         */
    CPS  #SVC_MODE						/* switch to supervisor mode 	*/
    LDR  sp, =__svc_stack_end__			/* setup the SVC stack pointer  */

/* ========================================================================= */
/* Branch to C library entry point                                           */
/* ========================================================================= */
    /* safe to do so since the SVC stack is setup */
    LDR  r12,=PowerON_Reset
    BX   r12


QSPI_BL_reset_handler_end:
    B    QSPI_BL_reset_handler_end

/* ========================================================================= */
/* Other Handlers                                                            */
/* ========================================================================= */
QSPI_BL_undefined_handler:
    B    QSPI_BL_undefined_handler

QSPI_BL_svc_handler:
    B    QSPI_BL_svc_handler

QSPI_BL_prefetch_handler:
    B    QSPI_BL_prefetch_handler

QSPI_BL_abort_handler:
    B    QSPI_BL_abort_handler

QSPI_BL_reserved_handler:
    B    QSPI_BL_reserved_handler

QSPI_BL_irq_handler:
    B    QSPI_BL_irq_handler

QSPI_BL_fiq_handler:
    B    QSPI_BL_fiq_handler

.end

