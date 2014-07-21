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
* Copyright (C) 2013 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name   : spibsc_init2.c
* Description : Flash boot setting
*******************************************************************************/
#ifndef __QSPI_SETUP_H__
#define __QSPI_SETUP_H__

/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_typedefs.h"
#include "iodefine.h"
#include "spibsc.h"

#include "rza_io_regrw.h"

/******************************************************************************
Typedef definitions
******************************************************************************/


/******************************************************************************
Macro definitions
******************************************************************************/
// define where the user program image is located
// needs to match the application linker script
#define DEF_USER_PROGRAM_SRC        (0x18080000)

/* warning: the signature is located just below the ISR table + literals */
/* if the location is changed, the linker scripts needs to be adapted too */
#define DEF_USER_SIGNATURE          (DEF_USER_PROGRAM_SRC + 0x40)

// which spi channel is being used - 0 for the boot mode
#define SPI_CHANNEL				0

// configure for single or dual mode (one or two spi devices per channel)
#define SINGLE_QSPI_CHIP			(0)
#define DUAL_QSPI_CHIP				(1)

#define SPI_DEVICES 			DUAL_QSPI_CHIP

#define QUAD_MODE			(1u)
#define SERIAL_DUAL_MODE	(0u)
#define CFREG_QUAD_BIT          (0x02)          /* Quad mode bit(Configuration Register) */
#define PROGRAM_ERASE_ERROR 0x60

/******************************************************************************
Imported global variables and functions (from other files)
******************************************************************************/

/******************************************************************************
Exported global variables and functions (to be accessed by other files)
******************************************************************************/

/******************************************************************************
Private global variables and functions
******************************************************************************/



#endif /* __QSPI_SETUP_H__ */

/* End of File */
