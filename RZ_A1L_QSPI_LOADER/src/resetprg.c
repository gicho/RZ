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
* File Name     : resetprg.c
* Device(s)     : RZ/A1H RSK+RZA1H
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : Sample Program - C library entry point
*               : Variants of this file must be created for each compiler
******************************************************************************/
/******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
******************************************************************************/
#include <stdint.h>
#include "iodefine.h"
#include "rza_io_regrw.h"

#include "qspi_setup.h"

#ifdef __GNUC__

/* Global variables are specified in the linker script (GCC-QSPI-BL.ld) */
/* These are related to the code which gets copied to ram and reconfigures the QSPI */
extern uint32_t __qspi_reconfigure_code_start__;
extern uint32_t __qspi_reconfigure_code_end__;
extern uint32_t __qspi_reconfigure_code_rom_start__;

/* These are related to the rest of the code */
extern uint32_t __data_rom_start__;
extern uint32_t __data_start__;
extern uint32_t __data_end__;

extern uint32_t __bss_start__;
extern uint32_t __bss_end__;

#endif

#ifdef __ICCARM__

#pragma section = "RAM_CODE"
#pragma section = "RAM_CODE_IN_ROM"
#pragma section = "RAM_DATA"
#pragma section = "RAM_DATA_IN_ROM"
#pragma section = "RAM_BSS"

#endif

extern EXEC_RAM void qspi_change_config_and_start_application(void);
extern EXEC_RAM void copy_arm_code_section_to_ram(uint32_t* rom_start, uint32_t* ram_start, uint32_t* ram_end);

/*******************************************************************************
* Function Name: PowerON_Reset
* Description  :
* Arguments    : none
* Return Value : none
*******************************************************************************/
void PowerON_Reset (void)
{
        volatile uint32_t *ram_code_start,*ram_code_end;
	uint32_t *rom_code_start;
	uint8_t  *src, *dst, *end;

	// TODO add one stage to speed up QSPI to 33 Mhz first?
#ifdef __GNUC__
        /* copy the reconfiguration routine in RAM */
	/* these are the destination (run-time) locations of the code */
	ram_code_start = &__qspi_reconfigure_code_start__;
	ram_code_end = &__qspi_reconfigure_code_end__;

    /* this is where in rom the section is located */
	rom_code_start = &__qspi_reconfigure_code_rom_start__;
#endif

#ifdef __ICCARM__     
        
        /* Copy QSPI reconfiguration code to ram */
	/* these are the destination (run-time) locations of the code */
	ram_code_start = __section_begin("RAM_CODE");
	ram_code_end = __section_end("RAM_CODE");

        /* this is where in rom the section is located */
	rom_code_start = __section_begin("RAM_CODE_IN_ROM");
#endif
        
	/* warning this is copying in multiple of 4 bytes */
	copy_arm_code_section_to_ram((uint32_t *)rom_code_start, (uint32_t *)ram_code_start, (uint32_t *)ram_code_end);

#ifdef __GNUC__
        
	/* setup any of the other .data, .const or .bss initialized sections */
	src = (uint8_t*) &__data_rom_start__;
	dst = (uint8_t*) &__data_start__;
	end = (uint8_t*) &__data_end__;

#endif
        
#ifdef __ICCARM__   
        
        /* Initialize data in ram */
	src = __section_begin("RAM_DATA_IN_ROM");
	dst = __section_begin("RAM_DATA");
	end = __section_end("RAM_DATA");

#endif        
	/* ROM has data at end of text; copy it. */
	while (dst < end) {
	  *dst++ = *src++;
	}

#ifdef __GNUC__
        
	dst = (uint8_t*) &__bss_start__;
	end = (uint8_t*) &__bss_end__;

#endif
        
#ifdef __ICCARM__  
	dst = __section_begin("RAM_BSS");
	end = __section_end("RAM_BSS");

#endif
        
	/* Zero bss */
	while(dst< end)
		*dst++ = 0;
    
    // at this point the qspi reconfigure code is in ram and initialized
    // jump in ram and reconfigure the QSPI
	qspi_change_config_and_start_application();

	/* Stops program from running off */
    while(1);

}




