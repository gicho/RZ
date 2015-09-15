/*
* Copyright 2015 Giancarlo Parodi
*
* resetprog.c
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


extern void copy_arm_code_section_to_ram(uint32_t* rom_start, uint32_t* ram_start, uint32_t* ram_end);
extern int main(void);

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
        /* copy the reconfiguration routine in RAM */
	/* these are the destination (run-time) locations of the code */
	ram_code_start = &__qspi_reconfigure_code_start__;
	ram_code_end = &__qspi_reconfigure_code_end__;

    /* this is where in rom the section is located */
	rom_code_start = &__qspi_reconfigure_code_rom_start__;

	/* warning this is copying in multiple of 4 bytes */
	copy_arm_code_section_to_ram((uint32_t *)rom_code_start, (uint32_t *)ram_code_start, (uint32_t *)ram_code_end);

	/* setup any of the other .data, .const or .bss initialized sections */
	src = (uint8_t*) &__data_rom_start__;
	dst = (uint8_t*) &__data_start__;
	end = (uint8_t*) &__data_end__;

	/* ROM has data at end of text; copy it. */
	while (dst < end) {
	  *dst++ = *src++;
	}

	dst = (uint8_t*) &__bss_start__;
	end = (uint8_t*) &__bss_end__;
        
	/* Zero bss */
	while(dst< end)
		*dst++ = 0;
    
    // at this point the qspi reconfigure code is in ram and initialized
    // jump in ram and reconfigure the QSPI
	main();

	/* Stops program from running off */
    while(1);

}




