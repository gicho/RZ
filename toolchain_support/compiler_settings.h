/*
* Copyright 2015 Giancarlo Parodi
*
* compiler_settings.h
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


#ifndef COMPILER_SETTINGS_H
#define COMPILER_SETTINGS_H

/******************************************************************************
Macro definitions
******************************************************************************/
#ifdef __ICCARM__

#include "intrinsics.h"

#define EXEC_RAM            __ramfunc

#define SOFT_DELAY()	        __no_operation()
#define WAIT_FOR_INTERRUPT()    __WFI()

#define MUTEX(foo) _Pragma("data_alignment=32") mutex_t foo = UNLOCKED;

#define ISB     __ISB
#define DSB     __DSB
#define DMB     __DMB

#define INITIALIZATION_CODE _Pragma("location=\".hardware_init\"") 
#define DMA_RAM_BUFFER _Pragma("location=\".DMA_BUFFER_IRAM\"")
#define DMA_RAM_CACHED_BUFFER _Pragma("location=\".DMA_BUFFER_CACHED_IRAM\"")
#define DMA_SDRAM_BUFFER _Pragma("location=\".DMA_BUFFER_SDRAM\"")
#define DMA_SDRAM_CACHED_BUFFER _Pragma("location=\".DMA_BUFFER_CACHED_SDRAM\"")

#define VRAM_SECTION  _Pragma("location=\".display_buffer_section\"")
#define IMAGE_DATA_BUF _Pragma("location=\".IMAGE_DATA\"")



#endif


#ifdef __GNUC__

#define ISB()               __asm__("isb")
#define DSB()               __asm__("dsb")
#define DMB()               __asm__("dmb")

#define MUTEX(foo) _Pragma("data_alignment=32") mutex_t foo = UNLOCKED;

#define SOFT_DELAY()        	__asm__("nop")
#define EXEC_RAM 
#define WAIT_FOR_INTERRUPT()    __asm__("wfi")

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
