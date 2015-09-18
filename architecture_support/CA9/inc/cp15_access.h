/*
* Copyright 2015 Giancarlo Parodi
* 
* cp15_access.h
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

#ifndef CP15_ACCESS_H
#define CP15_ACCESS_H

#include <stdint.h>

extern void enable_neon_vfp_access_priv(void);
extern void enable_neon_vfp_access_full(void);
extern void disable_neon_vfp_access(void);
extern void neon_vfp_on(void);
extern void neon_vfp_off(void);

// does not change the cache configuration
extern void enable_mmu(void);
extern void disable_mmu(void);

extern void VbarSet(const uint32_t location);
extern void SetLowVectors(void);
extern void SetHighVectors(void);
      
#endif

