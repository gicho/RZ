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
* Copyright (C) 2013 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/******************************************************************************
* File Name     : gnu_io.c
* Device(s)     : RZ/A1H RSK+RZA1H
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : Sample Program - GCC support for serial I/O
*               : Variants of this file can be created for each compiler
******************************************************************************/
/******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
******************************************************************************/

/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include <stdio.h>
#include "compiler_settings.h"
#include "r_typedefs.h"                   /* Default  type definition header */
#include "dev_drv.h"                          /* Device Driver common header */
#include "devdrv_scif_uart.h"                          /* UART Driver header */
#include "devdrv_intc.h"                               /* INTC Driver Header */
#include "sio_char.h"                                /* Character I/O header */
#include "iodefine.h"                            /* I/O Register root header */
#include "gnu_io.h"             /* Compiler specific UART i/O support header */


/******************************************************************************
Typedef definitions
******************************************************************************/

/******************************************************************************
Macro definitions
******************************************************************************/

/******************************************************************************
Imported global variables and functions (from other files)
******************************************************************************/

/******************************************************************************
Exported global variables and functions (to be accessed by other files)
******************************************************************************/

/******************************************************************************
Private global variables and functions
******************************************************************************/

/******************************************************************************
* Function Name: PutString
* Description  : GNU interface to low-level I/O putchar replacement
* Arguments    : int file_no
*              : const char *buffer
*              : unsigned int n
* Return Value : none
******************************************************************************/
void PutString(char *pString)
{
    while(*pString != 0)
        IoPutchar(*pString++);
}

/******************************************************************************
* Function Name: GetString
* Description  : GNU interface to low-level I/O getchar replacement
* Arguments    : int file_no
*              : const char *buffer
*              : unsigned int n
* Return Value : none
******************************************************************************/
void GetString(char *pString)
{
    char *ptr = pString;

    do
    {
        *ptr = IoGetchar();
        IoPutchar(*ptr);
        if(*ptr == '\r')
        {
            *ptr = 0;
            break;
        }
    }
    while(*ptr++ != '\0');
    IoPutchar('\r');
    IoPutchar('\n');
}
