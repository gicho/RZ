/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
*******************************************************************************/
/*******************************************************************************
* Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name     : start.S
* Device(s)     : RZ/A1H RSK2+RZA1H
* Tool-Chain    : GCC
* H/W Platform  : RSK2+RZA1H CPU Board
* Description   : This is the vector table
*******************************************************************************/
/*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 24.06.2013 1.01 added comments on directives
*******************************************************************************/

    MODULE RESET_HANDLER_MOD
    SECTION RESET_HANDLER:CODE:ROOT(4)
    ARM
    
    EXTERN  QSPI_BL_reset_handler
    EXTERN  QSPI_BL_undefined_handler
    EXTERN  QSPI_BL_svc_handler
    EXTERN  QSPI_BL_prefetch_handler
    EXTERN  QSPI_BL_abort_handler
    EXTERN  QSPI_BL_reserved_handler
    EXTERN  QSPI_BL_irq_handler
    EXTERN  QSPI_BL_fiq_handler   

        LDR     PC,Reset_Addr           ; Reset
        LDR     PC,Undefined_Addr       ; Undefined instructions
        LDR     PC,SVC_Addr             ; Software interrupt (SWI/SVC)
        LDR     PC,Prefetch_Addr        ; Prefetch abort
        LDR     PC,Abort_Addr           ; Data abort
        LDR     PC,Reserved_Addr        ; RESERVED
        LDR     PC,IRQ_Addr             ; IRQ
        LDR     PC,FIQ_Addr             ; FIQ

        DATA

Reset_Addr:     DCD   QSPI_BL_reset_handler
Undefined_Addr: DCD   QSPI_BL_undefined_handler
SVC_Addr:       DCD   QSPI_BL_svc_handler
Prefetch_Addr:  DCD   QSPI_BL_prefetch_handler
Abort_Addr:     DCD   QSPI_BL_abort_handler
Reserved_Addr:  DCD   QSPI_BL_reserved_handler 
IRQ_Addr:       DCD   QSPI_BL_irq_handler
FIQ_Addr:       DCD   QSPI_BL_fiq_handler

        END 



    

