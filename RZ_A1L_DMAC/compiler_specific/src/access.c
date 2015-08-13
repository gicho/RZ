#include "access.h"

extern void enable_neon_vfp_access_priv_asm(void);
extern void enable_neon_vfp_access_full_asm(void);
extern void disable_neon_vfp_access_asm(void);
extern void neon_vfp_on_asm(void);
extern void neon_vfp_off_asm(void);
extern void enable_mmu_asm(void);
extern void disable_mmu_asm(void);
extern void VbarSet_asm(const uint32_t address);
extern void SetLowVectors_asm(void);   
extern void SetHighVectors_asm(void);

void enable_neon_vfp_access_private(void) {
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

void VbarSet(const uint32_t address) {
  VbarSet_asm(address);
}

void SetLowVectors(void) {
  SetLowVectors_asm();
}

void SetHighVectors(void) {
  SetHighVectors_asm();
}



