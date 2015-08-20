/*
* Copyright 2015 Giancarlo Parodi
* 
* flash_type_definitions.h
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

/* 
* These symbols are defined in the linker scripts 
* Code, data and bss for the QSPI reconfiguration routines needs to be copied
* to RAM and executed from there
*/

#ifdef __GNUC__

extern uint32_t __qspi_reconfigure_code_start__;
extern uint32_t __qspi_reconfigure_code_end__;
extern uint32_t __qspi_reconfigure_code_rom_start__;
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

/* Functions required for the initialization */
extern EXEC_RAM void qspiReconfigure(void);
extern void copyArmCodeToRam(uint32_t* rom_start, uint32_t* ram_start, uint32_t* ram_end);

typedef void (*fPtr)(void);

/*******************************************************************************
* Function Name: PowerON_Reset
* Description  :
* Arguments    : none
* Return Value : none
*******************************************************************************/
void PowerON_Reset (void)
{
  volatile fPtr applicationEntry = (fPtr) DEF_USER_PROGRAM_SRC;
  uint32_t *ram_code_start,*ram_code_end, *rom_code_start;
  uint8_t  *dataSrc, *dataDst, *dataEnd;
  uint8_t  *bssDst, *bssEnd;
  
#ifdef __GNUC__
  
  /* these are the destination (run-time) locations of the code */
  ram_code_start = &__qspi_reconfigure_code_start__;
  ram_code_end = &__qspi_reconfigure_code_end__;
  
  /* this is where in rom the section is located */
  rom_code_start = &__qspi_reconfigure_code_rom_start__;

  /* setup any of the other .data, .const or .bss initialized sections */
  dataSrc = (uint8_t*) &__data_rom_start__;
  dataDst = (uint8_t*) &__data_start__;
  dataEnd = (uint8_t*) &__data_end__;  
  
  bssDst = (uint8_t*) &__bss_start__;
  bssEnd = (uint8_t*) &__bss_end__;
  
#endif
  
#ifdef __ICCARM__     
  
  /* these are the destination (run-time) locations of the code */
  ram_code_start = __section_begin("RAM_CODE");
  ram_code_end = __section_end("RAM_CODE");
  
  /* this is where in rom the section is located */
  rom_code_start = __section_begin("RAM_CODE_IN_ROM");
  
  /* setup any of the other .data, .const or .bss initialized sections */
  dataSrc = __section_begin("RAM_DATA_IN_ROM");
  dataDst = __section_begin("RAM_DATA");
  dataEnd = __section_end("RAM_DATA");

  bssDst = __section_begin("RAM_BSS");
  bssEnd = __section_end("RAM_BSS");
  
#endif
  
  /* warning this is copying in multiple of 4 bytes */
  copyArmCodeToRam(rom_code_start, ram_code_start, ram_code_end);
  
  /* ROM has data at end of text; copy it. */
  while (dataDst < dataEnd) {
    *dataDst++ = *dataSrc++;
  }
   
  /* Zero bss */
  while(bssDst< bssEnd)
    *bssDst++ = 0;
  
  /* at this point the qspi reconfiguration code is in ram and initialized */
  /* execute the reconfiguration */
  qspiReconfigure();
  
  /* now jump to the program application entry point */
  (*applicationEntry)();
  
}




