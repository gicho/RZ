/*
* Copyright 2015 Giancarlo Parodi
* 
* start_iar.s
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

    MODULE RESET_HANDLER_MOD
    
    SECTION .intvec:CODE:ROOT(4)
    ARM
    
    PUBLIC APP_vector_table
    EXTERN  __iar_program_start
    
    PUBWEAK APP_undefined_handler
    PUBWEAK APP_svc_handler
    PUBWEAK APP_prefetch_handler
    PUBWEAK APP_abort_handler
    PUBWEAK APP_irq_handler
    PUBWEAK APP_fiq_handler    

/*
* This is the vector table located in Flash, does not use interrupts yet
* so all handlers are defined as dummy handlers
*/

APP_vector_table:

        LDR     PC,Reset_Addr           ; Reset
        LDR     PC,Undefined_Addr       ; Undefined instructions
        LDR     PC,SVC_Addr             ; Software interrupt (SWI/SVC)
        LDR     PC,Prefetch_Addr        ; Prefetch abort
        LDR     PC,Abort_Addr           ; Data abort
        LDR     PC,Reserved_Addr        ; RESERVED
        LDR     PC,IRQ_Addr             ; IRQ
        LDR     PC,FIQ_Addr             ; FIQ

        DATA

Reset_Addr:     DCD   __iar_program_start
Undefined_Addr: DCD   APP_dummy_handler
SVC_Addr:       DCD   APP_dummy_handler
Prefetch_Addr:  DCD   APP_dummy_handler
Abort_Addr:     DCD   APP_dummy_handler
Reserved_Addr:  DCD   APP_dummy_handler 
IRQ_Addr:       DCD   APP_dummy_handler
FIQ_Addr:       DCD   APP_dummy_handler

        CODE
        
APP_dummy_handler:
    B APP_dummy_handler




    SECTION RAM_IRQ_VECTOR_TABLE:CODE:ROOT(4)
    ARM
    
    PUBLIC APP_vector_table_RAM

/*
* This is the vector table located in RAM, so here we do find the real 
* interrupt handler addresses for the application
*/


APP_vector_table_RAM:

        LDR     PC,Reset_Addr_RAM           
        LDR     PC,Undefined_Addr_RAM       
        LDR     PC,SVC_Addr_RAM             
        LDR     PC,Prefetch_Addr_RAM        
        LDR     PC,Abort_Addr_RAM           
        LDR     PC,Reserved_Addr_RAM        
        LDR     PC,IRQ_Addr_RAM             
        LDR     PC,FIQ_Addr_RAM             

        DATA

Reset_Addr_RAM:     DCD   __iar_program_start
Undefined_Addr_RAM: DCD   APP_undefined_handler
SVC_Addr_RAM:       DCD   APP_svc_handler
Prefetch_Addr_RAM:  DCD   APP_prefetch_handler
Abort_Addr_RAM:     DCD   APP_abort_handler
Reserved_Addr_RAM:  DCD   APP_dummy_handler 
IRQ_Addr_RAM:       DCD   APP_irq_handler
FIQ_Addr_RAM:       DCD   APP_fiq_handler


/*
* Interrupt routines might be overridden when used
* Default empty implementations are provided in this file
*/
        CODE

APP_undefined_handler:
    B    APP_undefined_handler

APP_svc_handler:
    B    APP_svc_handler

APP_prefetch_handler:
    B    APP_prefetch_handler

APP_abort_handler:
    B    APP_abort_handler

APP_irq_handler:
    B    APP_irq_handler

APP_fiq_handler:
    B    APP_fiq_handler

        END 



    

