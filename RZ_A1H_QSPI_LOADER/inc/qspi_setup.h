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
* File Name   : qspi_setup.h
* Description : Flash settings
*******************************************************************************/
#ifndef __QSPI_SETUP_H__
#define __QSPI_SETUP_H__

/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_typedefs.h"
#include "iodefine.h"
// #include "spibsc.h"

#include "rza_io_regrw.h"

/******************************************************************************
Typedef definitions
******************************************************************************/


/******************************************************************************
Macro definitions
******************************************************************************/

/* single or dual SPI is configured within the build rule */

/* this defines where the SPI flash is connected in the address space */
#define SPI_BASE_ADDRESS	0x18000000


#ifdef SINGLE_QSPI_BOARD

#define QSPI_HARDWARE	SINGLE_MEMORY
#warning "Building for *SINGLE* QSPI Application"

#endif

#ifdef DUAL_QSPI_BOARD

#define QSPI_HARDWARE	DUAL_MEMORY
#warning "Building for *DUAL* QSPI Application"

#endif

/* this defines where in flash the application is located, @0x18080000 */
/* needs to be a multiple of the flash sector size! */
/* it refers to the second logical sector for a single QSPI */
/* for a dual spi, it refers to the first logical sector for each chip */
/* offset is fixed to 0x18080000 and matches the application linker script */
#define APPLICATION_FLASH_OFFSET	0x80000

// define where the user program image is located
// needs to match the application linker script
#define DEF_USER_PROGRAM_SRC (SPI_BASE_ADDRESS + APPLICATION_FLASH_OFFSET)

/* warning: the signature is located just below the ISR table + literals */
/* if the location is changed, the linker scripts needs to be adapted too */
#define DEF_USER_SIGNATURE          (DEF_USER_PROGRAM_SRC + 0x40)


#endif /* __QSPI_SETUP_H__ */

/* End of File */
