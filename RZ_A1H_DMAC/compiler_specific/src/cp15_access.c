/*
* Copyright 2015 Giancarlo Parodi
* 
* cp15_access.c
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
#include "cp15_access.h"

extern void enable_neon_vfp_access_priv_asm(void);
extern void enable_neon_vfp_access_full_asm(void);
extern void disable_neon_vfp_access_asm(void);
extern void neon_vfp_on_asm(void);
extern void neon_vfp_off_asm(void);
extern void enable_mmu_asm(void);
extern void disable_mmu_asm(void);
extern void VbarSet_asm(const uint32_t location);
extern void SetLowVectors_asm(void);  
extern void SetHighVectors_asm(void);
      
void enable_neon_vfp_access_priv(void) {
  enable_neon_vfp_access_priv_asm();
}

void enable_neon_vfp_access_full(void) {
  enable_neon_vfp_access_full_asm();
}

void disable_neon_vfp_access(void) {
  disable_neon_vfp_access_asm();
}

void neon_vfp_on(void) {
  neon_vfp_on_asm();
}

void neon_vfp_off(void) {
  neon_vfp_off_asm();
}

void enable_mmu(void) {
  enable_mmu_asm();
}

void disable_mmu(void) {
  disable_mmu_asm();
}

void VbarSet(const uint32_t location) {
  VbarSet_asm(location);
}

void SetLowVectors(void) {
  SetLowVectors_asm();
}

void SetHighVectors(void) {
  SetHighVectors_asm();
}

