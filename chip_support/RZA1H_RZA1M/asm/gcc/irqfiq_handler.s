/*
* Copyright 2015 Giancarlo Parodi
*
* irqfiq_handler.s
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

/* Standard definitions of mode bits and interrupt (I & F) flags in PSRs */
    .equ    SYS_MODE          , 0x1F
    .equ    INTC_ICCIAR_ADDR  , 0xE820200C
    .equ    INTC_ICCHPIR_ADDR , 0xE8202018
    .equ    INTC_ICCEOIR_ADDR , 0xE8202010
    .equ    INTC_ICDIPR0_ADDR , 0xE8201400
	.equ	INTC_ICDABR0_ADDR , 0xE8201300

/* ================================================================== */
/* Entry point for the FIQ handler */
/* ================================================================== */
    .global  APP_irq_handler
    .global  APP_fiq_handler

APP_fiq_handler:

    LDR     r8, =INTC_ICDIPR0_ADDR	// force recalculation of highest priority interrupt
    LDR     r9, [r8]				// read interrupt priority register 0 into r9 - errata 733075 for GIC
    STR		r9, [r8]				// write back the same value
    DSB								// ensure write completes before other ICCHIPR or ICCIAR register reads

    SUB     lr, lr, #4 				// adjust the return address for exception return
    SRSDB   sp!, #SYS_MODE 			// save LR_fiq and PSR_fiq on the SYSTEM mode stack

    CPS    	#SYS_MODE				// change to system mode
    PUSH    {r0-r3, r12}			// save AACPS stack on system mode stack
    								// since the handler is a C function

    AND     r0, sp, #4				// align stack pointer to 8 bytes (could be skipped since FIQ is not nested?)
    SUB     sp, sp, r0				// adjust as necessary
    PUSH    {r0, lr}				// store adjustment and lr to SYSTEM stack

    BL    FiqHandler_Interrupt 		// execute handler

    POP     {r0, lr}				// restore LR_sys and r0
    ADD     sp, sp, r0				// un-adjust stack

    POP     {r0-r3, r12}			// restore AACPS registers

APP_fiq_handler_end:

    LDR     r8, =INTC_ICCHPIR_ADDR	// load highest priority pending interrupt register address
    LDR     r9, [r8]				// read into r9 - errata 801120 for GIC
    								// can discard the result
    								// do this here in case FIQ preempts IRQ just before ICCHPIR read

    RFEFD   sp!

/* ================================================================== */
/* Entry point for the IRQ handler */
/* ================================================================== */
    .func APP_irq_handler
APP_irq_handler:

    SUB 	lr, lr, #4				// adjust the return address for exception return
    SRSDB   sp!, #SYS_MODE			// save LR_irq and PSR_irq on the SYSTEM mode stack

    CPS     #SYS_MODE				// change to system mode
    PUSH    {r0-r3, r12}			// save AACPS stack on system mode stack

    LDR     r2, =INTC_ICCHPIR_ADDR	// load highest priority pending interrupt register address
    LDR     r0, [r2]				// read into r0 - errata 801120 for GIC, can discard the result

    LDR     r2, =INTC_ICCIAR_ADDR	// load interrupt acknowledge register address
    LDR     r0, [r2]				// read ICCIAR into r0

    LDR     r2, =0x3FF         		// Load the interrupt ID mask
    AND     r3, r0, r2				// Extract the interrupt ID (removing the SGI source CPU ID)
    LDR     r1, =0x3FE         		// Interrupt IDs 0x3FE and 0x3FF are also possibly affected by 733075
    CMP     r3, r1
    BPL     APP_irq_not_active		// jump to spurious interrupt handling if >= 1023 (0x3FE)
    CMP     r3, #0                  // Read data of 0x0 (SGI ID0 from CPU0) is possibly affected by 733075
    BEQ     APP_irq_check			// if zero is detected check for the

APP_irq_ok:
    PUSH    {r0}					// store r0 on the system mode stack (interrupt id, parameter for the handler)

    AND     r1, sp, #4				// align stack pointer to 8 bytes
    SUB     sp, sp, r1				// adjust as necessary
    PUSH    {r1, lr}				// store adjustment and lr to SYSTEM stack

	CPSIE   i                       // enable nested interrupts

    BL      INTC_Handler_Interrupt	// branch to IRQ handler

	CPSID   i                       // disable interrupts

    POP     {r1, lr}				// restore LR_sys
    ADD     sp, sp, r1				// un-adjust stack

    POP     {r0}					// get interrupt id back from stack
    LDR     r2, =INTC_ICCEOIR_ADDR  // load end of interrupt register address
    STR     r0, [r2]				// quit interrupt by writing id

APP_irq_handler_end:
    POP     {r0-r3, r12}			// restore AACPS registers
    RFEFD   sp!						// return from the SYSTEM mode stack

APP_irq_check:
    LDR     r2, =INTC_ICDABR0_ADDR  // Erratum 733075 - Only SGI ID0 from CPU0 can be affected by this erratum.
    LDR     r3, [r2]
    AND     r3, r3, #0x1     		// It is a real activation of ID0 if active bit is now set, and the active bit was not previously set
    CMP     r3, #0
    BNE     APP_irq_ok

APP_irq_not_active:
    LDR     r2, =INTC_ICDIPR0_ADDR	// force recalculation of highest priority interrupt
    LDR     r3, [r2]				// read interrupt priority register 0 - errata 733075 for GIC
    STR		r3, [r2]				// write back the same value
    DSB								// ensure write completes before other ICCHIPR or ICCIAR register reads
    B		APP_irq_handler_end

    .endfunc
    .end
