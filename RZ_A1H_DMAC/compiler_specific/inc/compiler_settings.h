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
/******************************************************************************
* File Name     : compiler_settings.h
* Device(s)     : RZ/A1H (R7S721001)
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : Any compiler specific settings are stored here.
*               : Variants of this file must be created for each compiler
******************************************************************************/
/******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*               : 21.03.2014 2.00
******************************************************************************/

#ifndef COMPILER_SETTINGS_H
#define COMPILER_SETTINGS_H

/******************************************************************************
Macro definitions
******************************************************************************/
#ifdef __ICCARM__

#include "intrinsics.h"

#define SOFT_DELAY	__no_operation()
#define EXEC_RAM        __ramfunc

#define INITIALIZATION_CODE _Pragma("location=\".hardware_init\"") 
#define DMA_RAM_BUFFER _Pragma("location=\".DMA_BUFFER_IRAM\"")
#define DMA_RAM_CACHED_BUFFER _Pragma("location=\".DMA_BUFFER_CACHED_IRAM\"")
#define DMA_SDRAM_BUFFER _Pragma("location=\".DMA_BUFFER_SDRAM\"")
#define DMA_SDRAM_CACHED_BUFFER _Pragma("location=\".DMA_BUFFER_CACHED_SDRAM\"")

#define VRAM_SECTION  _Pragma("location=\".display_buffer_section\"")

#define IMAGE_DATA_BUF _Pragma("location=\".IMAGE_DATA\"")

#endif


#ifdef __GNUC__

#define SOFT_DELAY __asm__("nop")
#define EXEC_RAM 

#define INITIALIZATION_CODE __attribute__((section (".hardware_init")))  

#define DMA_RAM_BUFFER __attribute__ ((section (".DMA_BUFFER_IRAM")))
#define DMA_RAM_CACHED_BUFFER __attribute__ ((section (".DMA_BUFFER_CACHED_IRAM")))

#define DMA_SDRAM_BUFFER __attribute__ ((section (".DMA_BUFFER_SDRAM")))
#define DMA_SDRAM_CACHED_BUFFER __attribute__ ((section (".DMA_BUFFER_CACHED_SDRAM")))

// #define BSS_SDRAM_SECTION   __attribute__ ((section (".BSS_DMAC_SAMPLE_SDRAM")))
#define VRAM_SECTION  __attribute__ ((section (".display_buffer_section")))

#define IMAGE_DATA_BUF _Pragma("location=\".IMAGE_DATA\"")

#endif


/******************************************************************************
Variable External definitions and Function External definitions
******************************************************************************/

extern void __enable_irq(void);
extern void __disable_irq(void);
extern void __enable_fiq(void);
extern void __disable_fiq(void);


/******************************************************************************
Functions Prototypes
******************************************************************************/

/* COMPILER_SETTINGS_H */
#endif  

/* End of File */
