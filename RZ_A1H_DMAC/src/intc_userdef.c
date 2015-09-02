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
* File Name     : intc_userdef.c
* Device(s)     : RZ/A1H (R7S721001)
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : Interrupt controller use file
*******************************************************************************/
/*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*               : 21.03.2014 2.00
*******************************************************************************/

/*******************************************************************************
Includes   <System Includes> , "Project Includes"
*******************************************************************************/
#include <stdint.h>
/* Interchangeable compiler specific header */
#include "compiler_settings.h"

/* definition of I/O register */
#include "iodefine.h"
/* Default  type definition header */
#include "r_typedefs.h"
/* INTC Driver Header */
#include "devdrv_intc.h"
/* RSK user switches header */
#include "switches.h"
/* Interchangeable compiler specific header */
#include "compiler_settings.h"

/*******************************************************************************
Typedef definitions
*******************************************************************************/


/*******************************************************************************
Macro definitions
*******************************************************************************/
/* Defines the NMI bit in the user switch variable */
#define NMIF_BIT	(0x0002)

/*******************************************************************************
Private global variables and functions
*******************************************************************************/
/* ====  Prototype function ==== */
// static void Userdef_INTC_Dummy_Interrupt(uint32_t int_sense);

/* ==== Global variable ==== */


/*******************************************************************************
* Function Name: Userdef_INTC_RegistIntFunc
* Description  : This function is the user-defined function called by the 
*              : R_INTC_RegistIntFunc. Write the processing to register the 
*              : specified function to the element specified by the int_id in 
*              : INTC interrupt handler function table intc_func_table[].
* Arguments    : uint16_t int_id         : Interrupt ID
*              : void (* func)(uint32_t) : Function to be registered to INTC
*              :                         : interrupt handler table
* Return Value : none
*******************************************************************************/
void Userdef_INTC_RegistIntFunc(uint16_t int_id,
		                                     void (* func)(uint32_t int_sense))
{
    intc_func_table[int_id] = func;
}

/*******************************************************************************
* Function Name: Userdef_INTC_UndefId
* Description  : This function is the user-defined function called by the 
*              : INTC_Handler_Interrupt. Write the processing to be executed
*              : when an unsupported interrupt ID is received. 
* Arguments    : uint16_t int_id    : Interrupt ID
* Return Value : none
*******************************************************************************/
void Userdef_INTC_UndefId(uint16_t int_id)
{
    /* Execute processing when receiving interrupt ID which is not supported */
    while (1)
    {
        /* Do Nothing */
    }
}

/*******************************************************************************
* Function Name: Userdef_INTC_Dummy_Interrupt
* Description  : This function is the dummy processing for interrupt handler.
*              : In this sample code, this function is registered by default in 
*              : all interrupts in the INTC interrupt handler talbe 
*              : intc_func_table[].
* Arguments    : uint32_t int_sense : Interrupt detection
*              :                    :   INTC_LEVEL_SENSITIVE : Level sense
*              :                    :   INTC_EDGE_TRIGGER    : Edge trigger
* Return Value : none
*******************************************************************************/
//static void Userdef_INTC_Dummy_Interrupt(uint32_t int_sense)
//{
//    /* Execute processing of non-registered interrupt ID */
//}

/*******************************************************************************
* Function Name: Userdef_INTC_HandlerExe
* Description  : This function is the user-defined function called by the 
*              : INTC_Handler_Interrupt. Write the handler processing which 
*              : corresponds to the INTC interrupt source ID specified by the 
*              : argument int_id to be executed. In this sample code, the
*              : function registered as an element of the int_id in the INTC
*              : interrupt handler function table intc_func_table[] is executed.
* Arguments    : uint16_t int_id    : Interrupt ID
*              : uint32_t int_sense : Interrupt detection
*              :                    :   INTC_LEVEL_SENSITIVE : Level sense
*              :                    :   INTC_EDGE_TRIGGER    : Edge trigger
* Return Value : none
*******************************************************************************/
/*
void Userdef_INTC_HandlerExe(uint16_t int_id, uint32_t int_sense)
{
    intc_func_table[int_id](int_sense);
}
*/

/*******************************************************************************
* Function Name: Userdef_FIQ_HandlerExe
* Description  : This function is the user-defined function called by 
*              : the FiqHandler_Interrupt.
* Arguments    : none
* Return Value : none
******************************************************************************/
void Userdef_FIQ_HandlerExe(void)
{
	uint16_t dummy_read = 0;

	/* Set the NMI status bit in the user flag */
    g_switch_press_flg |= NMI_SET_FLG;

    /* Clearing the status flag requires a dummy read */
    dummy_read = INTC.ICR0;

    /* Clear the NMI interrupt flag */
    if (NMIF_BIT == (dummy_read & NMIF_BIT))
	{
    	INTC.ICR0 &= 0xFFFD;
	}
}



/* END of File */

