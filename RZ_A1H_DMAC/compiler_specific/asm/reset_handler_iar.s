/*
* Copyright 2015 Giancarlo Parodi
* 
* reset_handler_iar.s
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

    NAME RESET_HANDLER_S
    SECTION RESET_HANDLER:CODE(4)
    ARM
    
    PUBLIC APP_reset_handler    /* This is the entry point */
    PUBLIC __iar_program_start

    
    IMPORT APP_vector_table     /* Vector table */
    IMPORT __cmain              /* C initalization routine */


/* 
* The stack definitions are exported from the linker script (.icf)
*/
    IMPORT CSTACK$$Limit
    IMPORT SVC_STACK$$Limit
    IMPORT IRQ_STACK$$Limit
    IMPORT FIQ_STACK$$Limit
    IMPORT UND_STACK$$Limit
    IMPORT ABT_STACK$$Limit

    IMPORT init_TTB_asm
    IMPORT neon_vfp_on_asm
    IMPORT enable_neon_vfp_access_full_asm
    IMPORT enable_mmu_asm

__svc_stack_end__ 		EQU SVC_STACK$$Limit
__irq_stack_end__ 		EQU IRQ_STACK$$Limit
__fiq_stack_end__ 		EQU FIQ_STACK$$Limit
__und_stack_end__ 		EQU UND_STACK$$Limit
__abt_stack_end__ 		EQU ABT_STACK$$Limit
__program_stack_end__ 	EQU  CSTACK$$Limit   

/* Standard definitions of mode bits and interrupt flags in PSRs */
USR_MODE EQU 0x10
FIQ_MODE EQU 0x11
IRQ_MODE EQU 0x12
SVC_MODE EQU 0x13
ABT_MODE EQU 0x17
UND_MODE EQU 0x1b
SYS_MODE EQU 0x1f
    
/* Standard definitions of CPSR bits */
V_BIT EQU 0x2000
I_BIT EQU 0x1000
Z_BIT EQU 0x800
C_BIT EQU 0x4
A_BIT EQU 0x2
M_BIT EQU 0x1


/* Entry point for the Reset handler */
__iar_program_start:
APP_reset_handler:

/* 
* Cache and MMU maintenance 
*
* Clear V bit 13 to set low vectors
* Clear I bit 12 to disable I Cache
* Clear Z bit 11 to disable flow prediction
* Clear C bit  2 to disable D Cache
* Clear A bit  1 to disable strict alignment
* Clear M bit  0 to disable MMU
*/

/* Disable cache and MMU just to be sure */
    MRC  p15, 0, r0, c1, c0, 0

    /* BIC has 8 bit immediate + 4 bit rotation */
    /* Need to clear separately above first byte */
    BIC  r0, r0, #(I_BIT)
    BIC  r0, r0, #(Z_BIT)
    BIC  r0, r0, #(C_BIT | A_BIT | M_BIT)

    /* Write value back to CP15 SCR and sync */
    MCR  p15, 0, r0, c1, c0, 0
    ISB

/* Invalidate instruction cache */ 
    MOV  r0,#0
    MCR  p15, 0, r0, c7, c5, 0
        
/* Invalidate branch prediction array */
    MCR  p15, 0, r0, c7, c5, 6

/* Invalidate TLB */
    MCR  p15, 0, r0, c8, c7, 0	/* Invalidate entire unified TLB */
    MCR  p15, 0, r0, c8, c6, 0	/* Invalidate entire data TLB */
    MCR  p15, 0, r0, c8, c5, 0	/* Invalidate entire instruction TLB */
    ISB
    
/* Enable instruction cache & branch prediction */
    MRC  p15, 0, r0, c1, c0, 0
    ORR  r0, r0, #(I_BIT)
    ORR  r0, r0, #(Z_BIT)
    MCR  p15, 0, r0, c1, c0, 0
    ISB

/* Setup domain control register - Enable all domains to client mode */
    MRC  p15, 0, r0, c3, c0, 0  /* Read Domain Access Control Register */
    LDR  r0, =0x55555555        /* Initialize domains (client) */
    MCR  p15, 0, r0, c3, c0, 0  /* Write Domain Access Control Register */

/* 
* Vector Table Setting	
* 
* After QSPI, eSD or eMMC boot mode the system is configured to use High address
* 0 = Normal (Low address) Vectors 0x00000000
* 1 = High (High address) Vectors 0xFFFF0000
* Change this to use the bootloader vector table just in case we want to use
* interrupts (not the case in this example loader)
* Could use MMU, or VBAR, or address remapping on the bus (CS0<>RAM0)
* Here we can use VBAR since we chose low vectors in CP15
*/

/* Now set Vbar to the Application vector table in flash  */
    LDR r0, = APP_vector_table
    MCR p15, 0, r0, c12, c0, 0

/* * Clear V bit 13 to set low vectors */
    MRC  p15, 0, r0, c1, c0, 0
    BIC  r0, r0, #(V_BIT)

    /* Write value back to CP15 SCR and sync */
    MCR  p15, 0, r0, c1, c0, 0
    ISB

/*
* Clock Settings 
* 
* Set standby_mode_en of Power Control Register
* Needed before changing frequency
* Located in PL310 L2 cache controller
* reg15_power_ctrl @ offset 0xF80
* Base register is @ H'3FFFF000
*/
set_standby_mode_en:

STBY_MODE_EN        EQU 0x1
DYNCLK_GATING_DIS   EQU 0x0
PWR_CTRL_BITS       EQU (STBY_MODE_EN | DYNCLK_GATING_DIS)

    LDR  r0, =0x3FFFFF80
    LDR  r1, =PWR_CTRL_BITS
    STR  r1, [r0]
    ISB

/* 
* Program the frequency control register 1
* 
* Bit[14] = 1 - clock output enable control (unstable = 0, fixed low = 1)
* Bit[13,12] = 01b - output clock when active, keep low during power save modes
* Bit[9,8] = 00b - CPU clock ratio = 1/1 with PLL
* Bit [5,4,2,0] - fixed to 1
*
* If XTAL = 13,33 MHz (mode 0), PLL = x30, CLOCKS:
* CPU = 400MHz, Gf = 266.67MHz, Bf = 133MHz, P1 = 66.67MHz, P2 = 33.33MHz 
* (x30, I:G:B:P1:P0 = 30:20:10:5:5/2)
*
* If XTAL = 48 MHz (mode 1), PLL = x32, CLOCKS
* CPU = 384MHz, Gf = 256MHz, Bf = 128MHz, P1 = 64MHz, P2 = 32MHz 
* (x32, I:G:B:P1:P0 = 8:16/3:8/3:4/3:2/3)
*
* BCLK is 1/3 of CPU CLK fixed ratio 
* P0CLK is 1/6 of CPU CLK fixed ratio 
* P1CLK is 1/12 of CPU CLK fixed ratio 
*/
set_frqcr_reg:

CPUSTS_REG  EQU 0xFCFE0018
ISBUSY_BIT  EQU 0x10
CKOEN2_BIT  EQU (0x1 << 14)
CKOEN_BITS  EQU (0x1 << 12)
IFC_BITS    EQU (0x0 << 8)
CONST_BITS  EQU (0x35)
FRQCR EQU (CKOEN2_BIT | CKOEN_BITS | IFC_BITS | CONST_BITS)

    LDR  r0, =0xFCFE0010
    LDR  r1, =FRQCR
    STRH r1, [r0]
    ISB

/* check if frequency change is still in progress*/
    LDR  r0, =CPUSTS_REG
frqcr_wait:
    LDRB r1, [r0]
    ANDS r1, r1, #ISBUSY_BIT
    BNE  frqcr_wait

/* 
* Program the frequency control register 2
* This affects only the Image Renderers and the OpenVG block
*
* Bit [1,0] = 01b - Graphics clock ratio of 2/3
* If XTAL = 13,33 MHz (mode 0) Gf = 266.67MHz
* If XTAL = 48 MHz (mode 1), Gf = 256MHz
*/

set_frqcr2_reg:

GFC_BITS EQU 0x1

    LDR  r0, =0xFCFE0014
    LDR  r1, =GFC_BITS
    STRH r1, [r0]
    ISB

/* check if frequency change is still in progress*/
    LDR  r0, =CPUSTS_REG
frqcr2_wait:
    LDRB r1, [r0]
    ANDS r1, r1, #ISBUSY_BIT
    BNE  frqcr2_wait
	
/* 
* Setup Stacks
* Note: SYS_MODE shares stack space and register set with user mode
*/
    CPS  #SVC_MODE
    LDR  sp, =__svc_stack_end__
    CPS  #IRQ_MODE
    LDR  sp, =__irq_stack_end__
    CPS  #FIQ_MODE
    LDR  sp, =__fiq_stack_end__
    CPS  #UND_MODE
    LDR  sp, =__und_stack_end__
    CPS  #ABT_MODE
    LDR  sp, =__abt_stack_end__
    CPS  #SYS_MODE 
    LDR  sp, =__program_stack_end__

/* TTB initialize */
    BL    init_TTB_asm                                        

/*
* Enable access to NEON/VFP by enabling access to Coprocessors 10 and 11
* Enables Full Access i.e. in both privileged and non privileged modes    
*/
    BL enable_neon_vfp_access_full_asm

/* Switch on the VFP and NEON hardware */
    BL neon_vfp_on_asm

/* Enable MMU - does not change the caches configuration */
    BL enable_mmu_asm
	
/* Branch to C library entry point */
    B __cmain

    
          END
          
     


