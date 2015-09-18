/*
* Copyright 2015 Giancarlo Parodi
* 
* irqfiq_handler_iar.s
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

    NAME IRQ_FIQ_HANDLER_S
    SECTION IRQ_FIQ_HANDLER:CODE(4)
    ARM
    
/* Standard definitions of mode bits and interrupt (I & F) flags in PSRs */
SYS_MODE                EQU 0x1F
FIQ_MODE                EQU 0x11
INTC_ICCIAR_ADDR        EQU 0xE820200C
INTC_ICCHPIR_ADDR       EQU 0xE8202018
INTC_ICCEOIR_ADDR       EQU 0xE8202010
INTC_ICDIPR0_ADDR       EQU 0xE8201400

        PUBLIC APP_irq_handler
        PUBLIC APP_fiq_handler
        
        IMPORT FiqHandler_Interrupt
        IMPORT INTC_Handler_Interrupt
        
/*
* Entry point for the FIQ handler 
* FIQ has registers r8-r12 banked so there is no need to preserve these
* FIQ cannot be nested so no need to switch to system mode in the handler
*/
APP_fiq_handler:
  
/*
* errata 733075 for GIC
* force recalculation of highest priority interrupt
* read interrupt priority register 0 into r9 - errata 733075 for GIC
* write back the same value
* ensure write completes before other ICCHIPR or ICCIAR register reads
*/    
    LDR     r8, =INTC_ICDIPR0_ADDR	
    LDR     r9, [r8]				
    STR		r9, [r8]				
    DSB												

/*
* save AACPS stack on FIQ stack since the handler is a C function
*/
    PUSH    {r0-r3, r12, lr}	

/* execute C interrupt handler */
    BL    FiqHandler_Interrupt 		

/* 
* restore AACPS frame
*/
    POP     {r0-r3, r12, lr}			

APP_fiq_handler_end:
/*
* errata 801120 for GIC
* load highest priority pending interrupt register address
* read value, can discard the result
* do this here in case FIQ preempts IRQ just before ICCHPIR read
*/
    LDR     r8, =INTC_ICCHPIR_ADDR	
    LDR     r9, [r8]		    								    

/* return from the FIQ mode stack */
    SUBS pc, lr, #4


/* ================================================================== */
/* Entry point for the IRQ handler */
/* ================================================================== */
APP_irq_handler:

    SUB 	lr, lr, #4				// adjust the return address for exception return
    SRSFD   sp!, #SYS_MODE			// save LR_irq and PSR_irq on the SYSTEM mode stack

    CPS     #SYS_MODE				// now change to system mode
    PUSH    {r0-r3, r12, lr}        // save AACPS frame on system mode stack

    LDR     r2, =INTC_ICDIPR0_ADDR	// force recalculation of highest priority interrupt
    LDR     r0, [r2]				// read interrupt priority register 0 into r0 - errata 733075 for GIC
    STR		r0, [r2]				// write back the same value
    DSB								// ensure write completes before other ICCHIPR or ICCIAR register reads

    LDR     r2, =INTC_ICCHPIR_ADDR	// load highest priority pending interrupt register address
    LDR     r0, [r2]				// read into r0 - errata 801120 for GIC
    								// can discard the result

    LDR     r2, =INTC_ICCIAR_ADDR	// load interrupt acknowledge register address
    LDR     r0, [r2]				// read into r0
    PUSH    {r0}					// save r0 on the system mode stack 
                                    // the interrupt id is also the parameter of the handler function

    AND     r1, sp, #4				// align stack pointer to 8 bytes
    SUB     sp, sp, r1				// adjust as necessary
    PUSH    {r1}				    // store adjustment 

    CPSIE   i                       // enable nested interrupts
    
    BL      INTC_Handler_Interrupt	// branch to IRQ handler
    
    CPSID   i                       // disable interrupts 
    
    POP     {r1}				    // restore LR_sys
    ADD     sp, sp, r1				// un-adjust stack

    POP     {r0}					// get interrupt id back from stack

    LDR     r2, =INTC_ICCEOIR_ADDR  // load end of interrupt register address
    STR     r0, [r2]				// signal end of interrupt by writing back the id

APP_irq_handler_end:

    POP     {r0-r3, r12, lr}		// restore AACPS registers
    
    RFEFD   sp!						// return from the SYSTEM mode stack


    END
  