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
    
    PUBLIC APP_vector_table
    EXTERN  __iar_program_start
    
    PUBWEAK APP_undefined_handler
    PUBWEAK APP_svc_handler
    PUBWEAK APP_prefetch_handler
    PUBWEAK APP_abort_handler
    PUBWEAK APP_irq_handler
    PUBWEAK APP_fiq_handler 
    
/*
* Vector table must be aligned to 2 Byte boundary! (Bit 0-4 = 0)
* use ROOT(5) as 2^5= 32
*/    
    SECTION .intvec:CODE:ROOT(5)
    ARM    

/*
* This is the vector table located in Flash, does not use interrupts yet
* so all handlers are defined as dummy handlers
*/

APP_vector_table:

        LDR     PC, Reset_Addr           
        LDR     PC, Undefined_Addr       
        LDR     PC, SVC_Addr             
        LDR     PC, Prefetch_Addr        
        LDR     PC, Abort_Addr          
        LDR     PC, Reserved_Addr     
        LDR     PC, IRQ_Addr            
        LDR     PC, FIQ_Addr        

Reset_Addr:     DCD   __iar_program_start
Undefined_Addr: DCD   APP_undefined_handler
SVC_Addr:       DCD   APP_svc_handler
Prefetch_Addr:  DCD   APP_prefetch_handler
Abort_Addr:     DCD   APP_abort_handler
Reserved_Addr:  DCD   APP_dummy_handler 
IRQ_Addr:       DCD   APP_irq_handler
FIQ_Addr:       DCD   APP_fiq_handler


    SECTION RAM_IRQ_VECTOR_TABLE:CODE:ROOT(5)
    ARM
    
    PUBLIC APP_vector_table_RAM

/*
* This is the vector table located in RAM, so here we do find the real 
* interrupt handler addresses for the application
*/

APP_vector_table_RAM:

        LDR     PC, RAM_Reset_Addr           
        LDR     PC, RAM_Undefined_Addr       
        LDR     PC, RAM_SVC_Addr             
        LDR     PC, RAM_Prefetch_Addr        
        LDR     PC, RAM_Abort_Addr          
        LDR     PC, RAM_Reserved_Addr     
        LDR     PC, RAM_IRQ_Addr            
        LDR     PC, RAM_FIQ_Addr        

RAM_Reset_Addr:     DCD   __iar_program_start
RAM_Undefined_Addr: DCD   APP_undefined_handler
RAM_SVC_Addr:       DCD   APP_svc_handler
RAM_Prefetch_Addr:  DCD   APP_prefetch_handler
RAM_Abort_Addr:     DCD   APP_abort_handler
RAM_Reserved_Addr:  DCD   APP_dummy_handler 
RAM_IRQ_Addr:       DCD   APP_irq_handler
RAM_FIQ_Addr:       DCD   APP_fiq_handler



        SECTION DEFAULT_INT_VECTORS:CODE:ROOT(4)
        ARM
    
        
/*
* Interrupt routines might be overridden when used
* Default empty implementations are provided in this file
*/

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

        
APP_dummy_handler:
    B APP_dummy_handler

        END 



    

