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
Undefined_Addr: DCD   QSPI_BL_undefined_handler
SVC_Addr:       DCD   QSPI_BL_svc_handler
Prefetch_Addr:  DCD   QSPI_BL_prefetch_handler
Abort_Addr:     DCD   QSPI_BL_abort_handler
Reserved_Addr:  DCD   QSPI_BL_reserved_handler 
IRQ_Addr:       DCD   QSPI_BL_irq_handler
FIQ_Addr:       DCD   QSPI_BL_fiq_handler


/*
* Interrupt routines might be overridden when used
* Default empty implementations are provided in this file
*/
    CODE

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


    END 



    

