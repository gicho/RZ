/*
* Copyright 2015 Giancarlo Parodi
* 
* qspi_setup.h
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

#ifndef __QSPI_SETUP_H__
#define __QSPI_SETUP_H__

#include "iodefine.h"
#include "rza_io_regrw.h"


/* single or dual SPI is configured within the build rule */

/* this defines where the SPI flash is connected in the address space */
#define SPI_BASE_ADDRESS	0x18000000


#ifdef SINGLE_QSPI_BOARD
  #define QSPI_HARDWARE	SINGLE_MEMORY
#endif

#ifdef DUAL_QSPI_BOARD
  #define QSPI_HARDWARE	DUAL_MEMORY
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


#endif /* __QSPI_SETUP_H__ */

/* End of File */
