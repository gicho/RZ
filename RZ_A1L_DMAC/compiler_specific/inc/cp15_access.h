#ifndef _CP15_ACCESS_
#define _CP15_ACCESS_

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

