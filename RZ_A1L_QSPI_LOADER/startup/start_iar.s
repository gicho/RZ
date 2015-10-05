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
    SECTION .intvec:CODE:ROOT(5)
    ARM
    
    PUBLIC QSPI_BL_vector_table
    EXTERN __iar_program_start
    
    PUBWEAK QSPI_BL_undefined_handler
    PUBWEAK QSPI_BL_svc_handler
    PUBWEAK QSPI_BL_prefetch_handler
    PUBWEAK QSPI_BL_abort_handler
    PUBWEAK QSPI_BL_reserved_handler
    PUBWEAK QSPI_BL_irq_handler
    PUBWEAK QSPI_BL_fiq_handler
    
QSPI_BL_vector_table:

    LDR     PC, =__iar_program_start        ; Reset
    LDR     PC, =QSPI_BL_undefined_handler  ; Undefined instructions
    LDR     PC, =QSPI_BL_svc_handler        ; Software interrupt (SWI/SVC)
    LDR     PC, =QSPI_BL_prefetch_handler   ; Prefetch abort
    LDR     PC, =QSPI_BL_abort_handler      ; Data abort
    LDR     PC, =QSPI_BL_reserved_handler   ; RESERVED
    LDR     PC, =QSPI_BL_irq_handler        ; IRQ
    LDR     PC, =QSPI_BL_fiq_handler        ; FIQ


/*
* Interrupt routines might be overridden when used
* Default empty implementations are provided in this file
*/
    SECTION .dummy_handlers:CODE:ROOT
    ARM

QSPI_BL_undefined_handler:
    B QSPI_BL_undefined_handler
    
QSPI_BL_svc_handler:
    B QSPI_BL_svc_handler
    
QSPI_BL_reserved_handler:
    B QSPI_BL_reserved_handler

QSPI_BL_prefetch_handler:
    B QSPI_BL_prefetch_handler

QSPI_BL_abort_handler:
    B QSPI_BL_abort_handler
    
QSPI_BL_irq_handler:
    B QSPI_BL_irq_handler
    
QSPI_BL_fiq_handler:
    B QSPI_BL_fiq_handler
    
QSPI_BL_dummy_handler:
    B    QSPI_BL_dummy_handler


    END 



    

