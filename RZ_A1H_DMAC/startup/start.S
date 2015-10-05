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

    .global APP_vector_table

    .weak APP_undefined_handler
    .weak APP_svc_handler
    .weak APP_prefetch_handler
    .weak APP_abort_handler
    .weak APP_reserved_handler
    .weak APP_irq_handler
    .weak APP_fiq_handler

APP_vector_table:
    LDR pc, =APP_reset_handler
    LDR pc, =APP_undefined_handler
    LDR pc, =APP_svc_handler
    LDR pc, =APP_prefetch_handler
    LDR pc, =APP_abort_handler
    LDR pc, =APP_reserved_handler
    LDR pc, =APP_irq_handler
    LDR pc, =APP_fiq_handler


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

APP_irq_handler:
    B    APP_irq_handler

APP_fiq_handler:
    B    APP_fiq_handler


   .align
   .end

