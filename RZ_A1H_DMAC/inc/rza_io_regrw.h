/*
* Copyright 2015 Giancarlo Parodi
* 
* rza_io_regrw.h
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
/*******************************************************************************
* File Name   : rza_io_regrw.h
* $Rev: 1320 $
* $Date:: 2015-01-29 15:54:51 +0900#$
* Description : Low level register read/write header
*******************************************************************************/
#ifndef RZA_IO_REGRW_H
#define RZA_IO_REGRW_H

/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
/* ==== includes each bit mask header ==== */
#include "iobitmasks/cpg_iobitmask.h"
#include "iobitmasks/intc_iobitmask.h"
#include "iobitmasks/bsc_iobitmask.h"
#include "iobitmasks/ostm_iobitmask.h"
#include "iobitmasks/scif_iobitmask.h"
#include "iobitmasks/gpio_iobitmask.h"

#include "compiler_settings.h"

/******************************************************************************
Functions Prototypes
******************************************************************************/
EXEC_RAM void     RZA_IO_RegWrite_8 (volatile uint8_t  * ioreg, const uint8_t  write_value, const uint8_t  shift, const uint8_t  mask);
EXEC_RAM void     RZA_IO_RegWrite_16(volatile uint16_t * ioreg, const uint16_t write_value, const uint16_t shift, const uint16_t mask);
EXEC_RAM void     RZA_IO_RegWrite_32(volatile uint32_t * ioreg, const uint32_t write_value, const uint32_t shift, const uint32_t mask);
EXEC_RAM uint8_t  RZA_IO_RegRead_8  (volatile uint8_t  * ioreg, const uint8_t  shift, const uint8_t  mask);
EXEC_RAM uint16_t RZA_IO_RegRead_16 (volatile uint16_t * ioreg, const uint16_t shift, const uint16_t mask);
EXEC_RAM uint32_t RZA_IO_RegRead_32 (volatile uint32_t * ioreg, const uint32_t shift, const uint32_t mask);


#endif  /* RZA_IO_REGRW_H */

/* End of File */
