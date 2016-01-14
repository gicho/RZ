/*
* Copyright 2015 Giancarlo Parodi
*
* reset_handler.s
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
    .global QSPI_BL_reset_handler


    .text
    
/* Standard definitions of mode bits and interrupt flags in PSRs */
    .equ    USR_MODE , 0x10
    .equ    FIQ_MODE , 0x11
    .equ    IRQ_MODE , 0x12
    .equ    SVC_MODE , 0x13
    .equ    ABT_MODE , 0x17
    .equ    UND_MODE , 0x1b
    .equ    SYS_MODE , 0x1f
    
    .equ    THUMB_BIT, 0x20  /* CPSR/SPSR Thumb bit */

/* Standard definitions of CPSR bits */
    .equ    V_BIT , 0x2000
    .equ    I_BIT , 0x1000
    .equ    Z_BIT , 0x800
    .equ    C_BIT , 0x4
    .equ    A_BIT , 0x2
    .equ    M_BIT , 0x1

QSPI_BL_reset_handler:

/* ========================================================================= */
/* Cache and MMU maintenance    											 */
/* ========================================================================= */
/* Disable cache and MMU just to be sure */

    /* Read CP15 SCTLR */
    MRC  p15, 0, r0, c1, c0, 0

    /* 	Clear V bit 13 to set low vectors
    	Clear I bit 12 to disable I Cache
    	Clear Z bit 11 to disable flow prediction
    	Clear C bit  2 to disable D Cache
    	Clear A bit  1 to disable strict alignment check
    	Clear M bit  0 to disable MMU
    */
    /* BIC has 8 bit immediate + 4 bit rotation so cannot address directly above first byte */
    BIC  r0, r0, #(V_BIT)
    BIC  r0, r0, #(I_BIT)
    BIC  r0, r0, #(Z_BIT)
    BIC  r0, r0, #(C_BIT | A_BIT | M_BIT)

    /* Write value back to CP15 SCR */
    MCR  p15, 0, r0, c1, c0, 0
	ISB

/* ========================================================================= */
/* Invalidate instruction cache												 */
/* ========================================================================= */
	MOV  r0,#0
	MCR  p15, 0, r0, c7, c5, 0
/* ========================================================================= */
/*  Invalidate branch prediction array		 								 */
/* ========================================================================= */
    MCR  p15, 0, r0, c7, c5, 6
/* ========================================================================= */
/* Invalidate TLB															 */
/* ========================================================================= */
  	MCR  p15, 0, r0, c8, c7, 0	/* Invalidate entire unified TLB */
   	MCR  p15, 0, r0, c8, c6, 0	/* Invalidate entire data TLB*/
  	MCR  p15, 0, r0, c8, c5, 0	/* Invalidate entire instruction TLB*/
	ISB
/* ========================================================================= */
/* Enable instruction cache & branch prediction							     */
/* ========================================================================= */
    MRC  p15, 0, r0, c1, c0, 0
    ORR  r0, r0, #(I_BIT)
    ORR  r0, r0, #(Z_BIT)
    MCR  p15, 0, r0, c1, c0, 0
	ISB

/* ========================================================================= */
/* Setup domain control register - Enable all domains to client mode         */
/* ========================================================================= */
	MRC  p15, 0, r0, c3, c0, 0     /* Read Domain Access Control Register    */
	LDR  r0, =0x55555555    /* Initialize every domain entry to b01 (client) */
	MCR  p15, 0, r0, c3, c0, 0       /* Write Domain Access Control Register */

/* ========================================================================= */
/* Vector Table Setting							     */
/* ========================================================================= */
/*
 After QSPI, eSD or eMMC boot mode the system is configured to use High address
 0 = Normal (Low address) Vectors 0x00000000
 1 = High (High address) Vectors 0xFFFF0000
 Change this to use the bootloader vector table just in case we want to use
 interrupts (not the case in this example loader)
 Could use MMU, or VBAR, or address remapping on the bus (CS0<>RAM0)
 Here we can use VBAR since we chose low vectors in CP15
*/

/* Now set Vbar to the BL vector table instead of the ROM vector table  */
    LDR r0, = QSPI_BL_vector_table
    MCR p15, 0, r0, c12, c0, 0


/* ========================================================================= */
/* Clock Setting							     */
/* ========================================================================= */

/* Set standby_mode_en of Power Control Register
 Needed before changing frequency
 Located in PL310 L2 cache controller
 reg15_power_ctrl @ offset 0xF80
 Base register is @ H'3FFFF000
*/
set_standby_mode_en:

    .equ    STBY_MODE_EN      , 0x1
    .equ    DYNCLK_GATING_DIS , 0x0
    .equ    PWR_CTRL_BITS     , (STBY_MODE_EN | DYNCLK_GATING_DIS)

    LDR  r0, =0x3FFFFF80
    LDR  r1, =PWR_CTRL_BITS
    STR  r1, [r0]
    ISB
    LDR  r0, [r0]


/* program the frequency control register
 Bit[14] = 0 - clock output enable control (unstable = 0, fixed low = 1)
 Bit[13,12] = 01b - output clock when active, keep low when using power save modes
 Bit[9,8] = 00b - CPU clock ratio = 1/1 with PLL
 Bit [5,4,2,0] - fixed to 1
 XTAL = 13,33 MHz, PLL = x30, CPU CLOCK = 400 MHz
*/
set_frqcr_reg:

    .equ    CPUSTS_REG	, 0xFCFE0018
    .equ    ISBUSY_BIT  , 0x10
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

/* check if frequency change is in progress*/
	LDR  r0, =CPUSTS_REG
frqcr_wait:
    LDRB r1, [r0]
    ANDS r1, r1, #ISBUSY_BIT
    BNE  frqcr_wait


/* BCLK is 1/3 = 133,33 MHz fixed ratio */
/* P0CLK is 1/6 = 66,67 MHz fixed ratio */
/* P1CLK is 1/12 = 33,33 MHz fixed ratio */

/* program the frequency control register 2
 Bit [1,0] = 01b - Graphics clock ratio of 2/3
 GCLK = 266,67 MHz
*/
set_frqcr2_reg:

    .equ    GFC_BITS , 0x1

    LDR  r0, =0xFCFE0014
    LDR  r1, =GFC_BITS
    STRH r1, [r0]
    ISB
    LDRH r0, [r0]

/* check if frequency change is in progress*/
	LDR  r0, =CPUSTS_REG
frqcr2_wait:
    LDRB r1, [r0]
    ANDS r1, r1, #ISBUSY_BIT
    BNE  frqcr2_wait

/* enable data retention ram via SYSCR3 register */
    LDR  r0, =0xFCFE0408
    LDR  r1, =0x0F
    STRB r1, [r0]
    LDRB r0, [r0]           /* dummy read 8 bits wide */


/* ========================================================================= */
/*  Setting up Stack Area	                                             */
/* ========================================================================= */
/* Configure the supervisor mode just to be sure (default from QSPI boot)    */
    CPS  #SVC_MODE
    LDR  sp, =__svc_stack_end__

/* IRQ Mode                                                                  */
    CPS  #IRQ_MODE
    LDR  sp, =__irq_stack_end__

/* FIQ Mode                                                                  */
    CPS  #FIQ_MODE
    LDR  sp, =__fiq_stack_end__

/* UND Mode                                                                  */
    CPS  #UND_MODE
    LDR  sp, =__und_stack_end__

	/* ABT_MODE                                                                  */
    CPS  #ABT_MODE
    LDR  sp, =__abt_stack_end__

/* SYS_MODE, shares stack space and register set with user mode              */
    CPS  #SYS_MODE
    LDR  sp, =__program_stack_end__

/* ========================================================================= */
/* Branch to C library entry point                                           */
/* ========================================================================= */
    /* safe to do so since the SVC stack is setup */
    LDR  r12,=PowerON_Reset
    BX   r12

.end

     


