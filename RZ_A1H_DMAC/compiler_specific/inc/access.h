#ifndef _ACCESS_H_
#define _ACCESS_H_

#include <stdint.h>
#include "assembler_macros.h"

extern void enable_neon_vfp_access(void);
extern void enable_neon_vfp_access_full(void);
extern void disable_neon_vfp_access(void);
extern void neon_vfp_on(void);
extern void neon_vfp_off(void);
extern void enable_mmu(void);
extern void disable_mmu(void);
extern void VbarSet(const uint32_t address);
extern void SetLowVectors(void);   
extern void SetHighVectors(void);

#endif