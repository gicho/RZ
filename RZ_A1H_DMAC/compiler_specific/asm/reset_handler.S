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
/******************************************************************************
* File Name     : reset_handler.S
* Device(s)     : RZ/A1H (R7S721001)
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : Called by reset vector (start.S/mirrorstart.S)
*               : As such its the startpoint for this software
******************************************************************************/
/******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*               : 21.03.2014 2.00
******************************************************************************/

    .global APP_reset_handler
    .global APP_undefined_handler
    .global APP_svc_handler
    .global APP_prefetch_handler
    .global APP_abort_handler
    .global APP_reserved_handler
    .global APP_irq_handler
    .global APP_fiq_handler
	.global APP_dummy_handler

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
APP_reset_handler:

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
    LDR  r0, =0x3FFFFF80
    LDR  r1, =0x00000001
    LDR  r2, [r0]                    /* test read */
    STR  r1, [r0]
    LDR  r0, [r0]                    /* dummy read */

/* program the frequency control register
 Bit[14] = 0 - clock output enable control (unstable = 0, fixed low = 1)
 Bit[13,12] = 01b - output clock when active, keep low when using power save modes
 Bit[9,8] = 00b - CPU clock ratio = 1/1 with PLL
 Bit [5,4,2,0] - fixed to 1
 XTAL = 13,33 MHz, PLL = x30, CPU CLOCK = 400 MHz
*/
    LDR  r0, =0xFCFE0010
    LDR  r1, =0x1035
    STRH r1, [r0]
    LDRH r0, [r0]			/* dummy read 16 bits wide */
/* BCLK is 1/3 = 133,33 MHz fixed ratio */
/* P0CLK is 1/6 = 66,67 MHz fixed ratio */
/* P1CLK is 1/12 = 33,33 MHz fixed ratio */

/* program the frequency control register 2
 Bit [1,0] = 01b - Graphics clock ratio of 2/3
 GCLK = 266,67 MHz
*/
    LDR  r0, =0xFCFE0014
    LDR  r1, =0x0001
    STRH r1, [r0]
    LDRH r0, [r0]           /* dummy read 16 bits wide */


/* enable data retention ram */
    LDR  r0, =0xFCFE0408
    LDR  r1, =0x0F
    STRB r1, [r0]
    LDRB r0, [r0]           /* dummy read 8 bits wide */

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

    /* Read CP15 SCTLR */
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

	/* Now set Vbar to the Application vector table */
    LDR r0, = APP_vector_table
    MCR p15, 0, r0, c12, c0, 0

/* ========================================================================= */
/*  Setting up Stack Areas defined in the linker script                      */
/* ========================================================================= */
/* SVC Mode(Default)                                                         */
    CPS  #SVC_MODE
    LDR  sp, =__svc_stack_end__

/* IRQ Mode                                                                  */
    CPS  #IRQ_MODE
    LDR  sp, =__irq_stack_end__

/* FRQ Mode                                                                  */
    CPS  #FIQ_MODE
    LDR  sp, =__fiq_stack_end__

/* ABT_MODE                                                                  */
    CPS  #ABT_MODE
    LDR  sp, =__abt_stack_end__

/* SYS_MODE                                                                  */
    CPS  #SYS_MODE
    LDR  sp, =__program_stack_end__

/* ========================================================================= */
/*  TLB maintenance, Invalidate Data and Instruction TLBs                    */
/* ========================================================================= */
    MOV  r0,#0
    MCR  p15, 0, r0, c8, c7, 0 /* I-TLB & D-TLB invalidation (TLBIALL)       */

/* ========================================================================= */
/* Invalidate instruction cache, also flushes branch target cache            */
/* ========================================================================= */
    MOV  r0, #0                   /* SBZ                                     */
    MCR  p15, 0, r0, c7, c5, 0 /* ICIALLU                                    */

/* ========================================================================= */
/* Cache Invalidation code for Cortex-A9                                     */
/* ========================================================================= */
                                          /* Invalidate L1 Instruction Cache */
    MRC  p15, 1, r0, c0, c0, 1        /* Read Cache Level ID Register (CLIDR)*/
    TST  r0, #0x3                                         /*  Harvard Cache? */
    MOV  r0, #0
    MCRNE   p15, 0, r0, c7, c5, 0            /* Invalidate Instruction Cache */

                                           /* Invalidate Data/Unified Caches */
    MRC  p15, 1, r0, c0, c0, 1                                 /* Read CLIDR */
    ANDS r3, r0, #0x07000000                      /* Extract coherency level */
    MOV  r3, r3, LSR #23                          /* Total cache levels << 1 */
    BEQ  Finished                                  /* If 0, no need to clean */

    MOV  r10, #0                       /* R10 holds current cache level << 1 */
Loop1:
    ADD  r2, r10, r10, LSR #1               /* R2 holds cache "Set" position */
    MOV  r1, r0, LSR r2   /* Bottom 3 bits are the Cache-type for this level */
    AND  r1, r1, #7                            /* Isolate those lower 3 bits */
    CMP  r1, #2
    BLT  Skip            /* No cache or only instruction cache at this level */

    MCR  p15, 2, r10, c0, c0, 0  /* Write the Cache Size selection  (CSSELR) */
    ISB                     /* ISB to sync the change to the CacheSizeID reg */
    MRC  p15, 1, r1, c0, c0, 0       /* Reads current Cache Size ID (CCSIDR) */
    AND  r2, r1, #7                         /* Extract the line length field */
    ADD  r2, r2, #4      /* Add 4 for the line length offset (log2 16 bytes) */
    LDR  r4, =0x3FF
    ANDS r4, r4, r1, LSR #3          /* R4 is the max number on the way size */
    CLZ  r5, r4          /* R5 is the bit position of the way size increment */
    LDR  r7, =0x7FFF
    ANDS r7, r7, r1, LSR #13       /* R7 is the max number of the index size */
Loop2:
    MOV  r9, r4                      /* R9 working copy of the max way size  */

Loop3:
    ORR  r11, r10, r9, LSL r5 /* Factor in the Way and cache number into R11 */
    ORR  r11, r11, r7, LSL r2                    /* Factor in the Set number */
    MCR  p15, 0, r11, c7, c6, 2             /* Invalidate by Set/Way (DCISW) */
    SUBS r9, r9, #1                              /* Decrement the Way number */
    BGE  Loop3
    SUBS r7, r7, #1                              /* Decrement the Set number */
    BGE  Loop2
Skip:
    ADD  r10, r10, #2                          /* increment the cache number */
    CMP  r3, r10
    BGT  Loop1

Finished:
/* ========================================================================= */
/* TTB initialize                                                            */
/* ========================================================================= */
    BL    init_TTB                                         /* Initialize TTB */

/* ========================================================================= */
/* Setup domain control register - Enable all domains to client mode         */
/* ========================================================================= */
	MRC  p15, 0, r0, c3, c0, 0     /* Read Domain Access Control Register    */
	LDR  r0, =0x55555555    /* Initialize every domain entry to b01 (client) */
	MCR  p15, 0, r0, c3, c0, 0       /* Write Domain Access Control Register */

/* ========================================================================= */
/* Enable access to NEON/VFP by enabling access to Coprocessors 10 and 11.   */
/* Enables Full Access i.e. in both privileged and non privileged modes      */
/* ========================================================================= */
    MRC  p15, 0, r0, c1, c0, 2   /* Read Coprocessor Access Control Register */
/* TODO check if this is correct */
    ORR  r0, r0, #(0xF << 20)                 /* Enable access to CP 10 & 11 */
    MCR  p15, 0, r0, c1, c0, 2  /* Write Coprocessor Access Control Register */
    ISB

/* ========================================================================= */
/* Switch on the VFP and NEON hardware                                       */
/* ========================================================================= */
    BL neon_vfp_on

/* ========================================================================= */
/* Enable MMU  - leaves caches off                                           */
/* ========================================================================= */
    BL enable_mmu
    
/* ========================================================================= */
/* Branch to C library entry point                                           */
/* ========================================================================= */
    LDR  r12,=PowerON_Reset
    BX   r12                              /* Branch to C library entry point */


APP_reset_handler_end:
	B APP_reset_handler_end

/* ========================================================================= */
/* Other Handlers                                                            */
/* ========================================================================= */
APP_undefined_handler:
    B    APP_undefined_handler

APP_svc_handler:
    B    APP_svc_handler

APP_prefetch_handler:
    B    APP_prefetch_handler

APP_abort_handler:
    B    APP_abort_handler

APP_reserved_handler:
    B    APP_reserved_handler


APP_dummy_handler:
	B APP_dummy_handler

.end


.end

