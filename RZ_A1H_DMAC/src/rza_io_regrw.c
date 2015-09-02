/*
* Copyright 2015 Giancarlo Parodi
* 
* rza_io_regrw.c
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
#include <stdint.h>
#include "compiler_settings.h"


EXEC_RAM void RZA_IO_RegWrite_8(volatile uint8_t * ioreg,
		               const uint8_t write_value,
		               const uint8_t shift,
		               const uint8_t mask)
{
    uint8_t reg_value;

    /* Read from register */
    reg_value = *ioreg;

    /* Modify value       */
    reg_value = (uint8_t)((reg_value & (~mask)) | (write_value << shift));

    /* Write to register  */
    *ioreg    = reg_value;
}

EXEC_RAM void RZA_IO_RegWrite_16(volatile uint16_t * ioreg,
		                const uint16_t write_value,
		                const uint16_t shift,
		                const uint16_t mask)
{
    uint16_t reg_value;

    /* Read from register */
    reg_value = *ioreg;

    /* Modify value       */
    reg_value = (uint16_t)((reg_value & (~mask)) | (write_value << shift));

    /* Write to register  */
    *ioreg    = reg_value;
}

EXEC_RAM void RZA_IO_RegWrite_32(volatile uint32_t * ioreg,
		                   const uint32_t write_value, 
                           const uint32_t shift, 
                           const uint32_t mask)
{
    uint32_t reg_value;

    /* Read from register */
    reg_value = *ioreg;
    /* Modify value       */
    reg_value = (reg_value & (~mask)) | (write_value << shift);
    /* Write to register  */
    *ioreg    = reg_value;
}

EXEC_RAM uint8_t RZA_IO_RegRead_8(volatile uint8_t * ioreg, const uint8_t shift, const uint8_t mask)
{
    uint8_t reg_value;

    /* Read from register */
    reg_value = *ioreg;

    /* Clear other bit and Bit shift */
    reg_value = (uint8_t)((reg_value & mask) >> shift);

    return reg_value;
}

EXEC_RAM uint16_t RZA_IO_RegRead_16(volatile uint16_t * ioreg,
		                                          const uint16_t shift, const uint16_t mask)
{
    uint16_t reg_value;

    /* Read from register */
    reg_value = *ioreg;

    /* Clear other bit and Bit shift */
    reg_value = (uint16_t)((reg_value & mask) >> shift);

    return reg_value;
}

EXEC_RAM uint32_t RZA_IO_RegRead_32(volatile uint32_t * ioreg, const uint32_t shift, const uint32_t mask)
{
    uint32_t reg_value;

    /* Read from register */
    reg_value = *ioreg;
    /* Clear other bit and Bit shift */
    reg_value = (reg_value & mask) >> shift;

    return reg_value;
}



