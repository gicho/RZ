/*
* Copyright 2015 Giancarlo Parodi
*
* start.s
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
    .text
    .arm

    .global QSPI_BL_vector_table

    .weak QSPI_BL_undefined_handler
    .weak QSPI_BL_svc_handler
    .weak QSPI_BL_prefetch_handler
    .weak QSPI_BL_abort_handler
    .weak QSPI_BL_reserved_handler
    .weak QSPI_BL_irq_handler
    .weak QSPI_BL_fiq_handler

QSPI_BL_vector_table:

    LDR pc, =QSPI_BL_reset_handler
    LDR pc, =QSPI_BL_undefined_handler
    LDR pc, =QSPI_BL_svc_handler
    LDR pc, =QSPI_BL_prefetch_handler
    LDR pc, =QSPI_BL_abort_handler
    LDR pc, =QSPI_BL_reserved_handler
    LDR pc, =QSPI_BL_irq_handler
    LDR pc, =QSPI_BL_fiq_handler

    .align 4
    .end


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


