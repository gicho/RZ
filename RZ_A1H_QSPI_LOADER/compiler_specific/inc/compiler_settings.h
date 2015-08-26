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

#ifdef __ICCARM__

#include "intrinsics.h"

#define SOFT_DELAY	__no_operation()
#define EXEC_RAM    __ramfunc
#define WEAK        __weak

#define DSB()         __DSB()
#define ISB()         __ISB()
#define DMB()         __DMB()

#endif


#ifdef __GNUC__

#define SOFT_DELAY __asm__("nop")
#define EXEC_RAM 

#endif

extern void __enable_irq(void);
extern void __disable_irq(void);
extern void __enable_fiq(void);
extern void __disable_fiq(void);


/* COMPILER_SETTINGS_H */
#endif  

/* End of File */
