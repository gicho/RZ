/*
* Copyright 2015 Giancarlo Parodi
* 
* mutex.c
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
#include "mutex.h"
#include "compiler_settings.h"

extern void lock_mutex_asm(uint32_t address);
extern void unlock_mutex_asm(uint32_t address);

void lock_mutex(mutex_t* mutex) {
  lock_mutex_asm((uint32_t)mutex);
}

void unlock_mutex(mutex_t* mutex) {
  unlock_mutex_asm((uint32_t)mutex);
}

