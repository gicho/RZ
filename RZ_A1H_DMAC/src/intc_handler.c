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
* File Name     : intc_handler.c
* Device(s)     : RZ/A1H (R7S721001)
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : Sample Program - Handler process
*******************************************************************************/
/*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*               : 21.03.2014 2.00
*******************************************************************************/

/*******************************************************************************
Includes   <System Includes> , "Project Includes"
*******************************************************************************/
/* Interchangeable compiler specific header */
#include "compiler_settings.h"

/* Default  type definition header */
#include "r_typedefs.h"
/* INTC Driver Header */
#include "devdrv_intc.h"
/* I/O Register root header */
#include "iodefine.h"
/* INTC system header */
//#include "intc_handler.h"

/*******************************************************************************
* Function Name: INTC_Handler_Interrupt
* Description  : This function is the INTC interrupt handler processing called 
*              : by the irq_handler. Executes the handler processing which 
*              : corresponds to the INTC interrupt source ID specified by the
*              : icciar by calling the Userdef_INTC_HandlerExe function. The
*              : IRQ multiple interrupts are enabled. The processing for
*              : unsupported interrupt ID is executed by calling
*              : Userdef_INTC_UndefId function.
*              : In the interrupt handler processing, when the int_sense shows 
*              : "INTC_LEVEL_SENSITIVE", clear the interrupt source because it
*              : means a level sense interrupt. 
*              : Stacks are restored by ASM with the top level to correspond
*              : to multiple interrupts
* Arguments    : uint32_t icciar : Interrupt ID (value of ICCIAR register)
* Return Value : none
*******************************************************************************/
void INTC_Handler_Interrupt(uint32_t icciar)
{
    uint32_t mask;
    uint32_t int_sense;
    uint16_t int_id;
    uint32_t volatile * addr;

    int_id = (uint16_t)(icciar & 0x3FFuL); /* Obtain interrupt ID */

    if (int_id >= INTC_ID_TOTAL)    /* In case of unsupported interrupt ID */
    {
        Userdef_INTC_UndefId(int_id);
    }

    /* ==== Interrupt handler call ==== */
    // __enable_irq();         /* IRQ interrupt enabled */

    /* ICDICFRn has 16 sources in the 32 bits                                  */
    /* The n can be calculated by int_id / 16                                  */
    /* The upper 1 bit out of 2 bits for the bit field width is the target bit */
    /* The target bit can be calculated by ((int_id % 16) * 2) + 1             */
    addr = (volatile uint32_t *)&INTC.ICDICFR0;
    mask = (uint32_t)(1 << (((int_id % 16) * 2) + 1));
    if (0 == (*(addr + (int_id / 16)) & mask))  /* In the case of level sense */
    {
        int_sense = INTC_LEVEL_SENSITIVE;
    }
    else                                        /* In the case of edge trigger */
    {
        int_sense = INTC_EDGE_TRIGGER;
    }

    Userdef_INTC_HandlerExe(int_id, int_sense);     /* Call interrupt handler */

    // __disable_irq();        /* IRQ interrupt disabled */
}

/*******************************************************************************
* Function Name: FiqHandler_Interrupt
* Description  : This function is the INTC interrupt handler processing called
*              : by the fiq_handler.
* Arguments    : none
* Return Value : none
*******************************************************************************/
#define NMIF_BIT	(0x0002)
void FiqHandler_Interrupt(void)
{
	uint16_t dummy_read = 0;

	/* Set the NMI status bit in the user flag */
//    g_switch_press_flg |= NMI_SET_FLG;

    /* Clearing the status flag requires a dummy read */
    dummy_read = INTC.ICR0;

    /* Clear the NMI interrupt flag */
    if (NMIF_BIT == (dummy_read & NMIF_BIT))
	{
    	INTC.ICR0 &= 0xFFFD;
	}
}


/* END of File */

