/*
* Copyright 2015 Giancarlo Parodi
*
* low_level_init_gcc.c
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


static void copy_arm_code_section_to_ram(uint32_t* rom_start, uint32_t* ram_start, uint32_t* ram_end);
extern int main(void);

/*******************************************************************************
* Function Name: PowerON_Reset
* Description  :
* Arguments    : none
* Return Value : none
*******************************************************************************/
void PowerON_Reset (void)
{

	uint32_t *pRam;
	uint32_t *pRom;

	/* copy the reconfiguration routine in RAM */
	/* these are the destination (run-time) locations of the code */
	/* this is where in rom the section is located */
	/* warning this is copying in multiple of 4 bytes */
	pRom = (uint32_t *)&__qspi_reconfigure_code_rom_start__;
    for (pRam = &__qspi_reconfigure_code_start__; pRam < &__qspi_reconfigure_code_end__; pRam++) {
        *pRam = *pRom++;
    }

	/* setup initialized data section */
	pRom = (uint32_t *)&__data_rom_start__;
    for (pRam = &__data_start__; pRam < &__data_end__; pRam++) {
        *pRam = *pRom++;
    }

	/* Zero bss */
    for (pRam = &__bss_start__; pRam < &__bss_end__; pRam++) {
        *pRam = 0;
    }
    
    // at this point the qspi reconfigure code is in ram and initialized
    // jump in ram and reconfigure the QSPI
	main();

	/* Stops program from running off */
    while(1);

}




