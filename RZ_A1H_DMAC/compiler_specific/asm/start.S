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
* Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name     : start.S
* Device(s)     : RZ/A1H (R7S721001)
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : This is the code to be executed on the target
                  The copyright string signifies the end of the Vector table
*                 Note boot strap sequence is as follows:
*
*                 start->reset_handler->PowerON_Reset()->main()
*
*                 start - first code to be executed on the target
                  start jumps to reset_handler the asm startup routine
*                 reset_handler jumps to PowerON_Reset() C entry point
*                 PowerON_Reset() calls main() C User code entry point
*******************************************************************************/
/*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*                 21.03.2014 2.00
*******************************************************************************/

    .text
    .arm

    .global APP_vector_table
    .func   APP_vector_table

APP_vector_table:
    LDR pc, =APP_reset_handler
    LDR pc, =APP_undefined_handler
    LDR pc, =APP_svc_handler
    LDR pc, =APP_prefetch_handler
    LDR pc, =APP_abort_handler
    LDR pc, =APP_reserved_handler
    LDR pc, =APP_irq_handler
    LDR pc, =APP_fiq_handler
   .align
   .end

