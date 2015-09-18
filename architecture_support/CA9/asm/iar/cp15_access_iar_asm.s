/*
* Copyright 2015 Giancarlo Parodi
* 
* cp15_access_iar_asm.s
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

    NAME ACCESS_IAR_S
    SECTION ACCESS_IAR:CODE(4)
    ARM
       
    PUBLIC enable_neon_vfp_access_priv_asm
    PUBLIC enable_neon_vfp_access_full_asm
    PUBLIC disable_neon_vfp_access_asm
    PUBLIC neon_vfp_on_asm
    PUBLIC neon_vfp_off_asm
    PUBLIC enable_mmu_asm
    PUBLIC disable_mmu_asm
    PUBLIC VbarSet_asm
    PUBLIC SetLowVectors_asm  
    PUBLIC SetHighVectors_asm

/*
* Enable access to NEON/VFP by enabling access to Coprocessors 10 and 11.    
* Enables Privileged Access i.e. in both privileged and non privileged modes
*/

enable_neon_vfp_access_priv_asm:
    MRC  p15, 0, r0, c1, c0, 2 /* Read Coprocessor Access Register (CPACR)    */
    ORR  r0, r0, #(0x5 << 20)  /* Enable access to CP 10 & 11                 */
    BIC  r0, r0, #(3 << 30)    /* Clear ASEDIS/D32DIS if set                  */
    MCR  p15, 0, r0, c1, c0, 2 /* Write Coprocessor Access Register (CPACR)   */
    ISB
    BX        lr

/*
* Enable access to NEON/VFP by enabling access to Coprocessors 10 and 11
* Enables Full Access i.e. in both privileged and non privileged modes
*/

enable_neon_vfp_access_full_asm:
    MRC  p15, 0, r0, c1, c0, 2 /* Read Coprocessor Access Register (CPACR)    */
    ORR  r0, r0, #(0xF << 20)  /* Enable access to CP 10 & 11                 */
    BIC  r0, r0, #(3 << 30)    /* Clear ASEDIS/D32DIS if set                  */
    MCR  p15, 0, r0, c1, c0, 2 /* Write Coprocessor Access Register (CPACR)   */
    ISB
    BX        lr
    
/*
* Disable access to NEON/VFP by disabling access to Coprocessors 10 and 11
*/

disable_neon_vfp_access_asm:
    MRC  p15, 0, r0, c1, c0, 2 /* Read Coprocessor Access Register (CPACR)    */
    BIC  r0, r0, #(0xF << 20)  /* Disable access to CP 10 & 11                */
    MCR  p15, 0, r0, c1, c0, 2 /* Write Coprocessor Access Register (CPACR)   */
    ISB
    BX        lr
    
/*
*  Switch on the VFP and NEON hardware
*/
neon_vfp_on_asm:
    MOV  r0, #0x40000000
    VMSR FPEXC, r0                        /* Write FPEXC register, EN bit set */
    ISB
    BX        lr

/*
*  Switch off the VFP and NEON hardware
*/
neon_vfp_off_asm:
    MOV  r0, #0x00000000
    VMSR FPEXC, r0                      /* Write FPEXC register, EN bit clear */
    ISB
    BX        lr

/* Standard definitions of CPSR bits */
V_BIT EQU 0x2000
I_BIT EQU 0x1000
Z_BIT EQU 0x800
C_BIT EQU 0x4
A_BIT EQU 0x2
M_BIT EQU 0x1

/*
* Enable MMU, does not change cache configuration 
*/
enable_mmu_asm:
    MRC  p15, 0, r1, c1, c0, 0

    /* 	Clear V bit 13 to set low vectors
    	Clear I bit 12 to disable I Cache
    	Clear Z bit 11 to disable flow prediction
    	Clear C bit  2 to disable D Cache
    	Clear A bit  1 to disable strict alignment
    	Set   M bit  0 to enable MMU
    */
    ORR  r0, r0, #(M_BIT)
    MCR  p15, 0, r1, c1, c0, 0
    ISB
    BX   lr

/*
* Disable MMU, does not change the cache configuration
*/
disable_mmu_asm:
    MRC  p15, 0, r0, c1, c0, 0
    /* 	Clear V bit 13 to set low vectors
    	Clear I bit 12 to disable I Cache
    	Clear Z bit 11 to disable flow prediction
    	Clear C bit  2 to disable D Cache
    	Clear A bit  1 to disable strict alignment
    	Clear M bit  0 to disable MMU
    */
    BIC  r0, r0, #(M_BIT)
    MCR  p15, 0, r0, c1, c0, 0
    ISB
    BX   lr

/* 
* VbarSet reconfigures the vector base address register */
*/
VbarSet_asm:
    MCR p15, 0, r0, c12, c0, 0
    ISB
    BX	lr

/*
* Set SCTLR Low Vectors
* 0 = Normal (Low address) Vectors
* 1 = High (High address) Vectors
*/
SetLowVectors_asm:
    MRC  p15, 0, r0, c1, c0, 0
    BIC  r0, r0, #(V_BIT) /* 	Clear V bit 13 to set low vectors */
    MCR  p15, 0, r0, c1, c0, 0
    ISB
    BX        lr

/*  
* Set SCTLR High Vectors
* 0 = Normal (Low address) Vectors
* 1 = High (High address) Vectors
*/
SetHighVectors_asm:
    MRC  p15, 0, r0, c1, c0, 0
    ORR  r0, r0, #(V_BIT) /* 	Set V bit 13 to set high vectors */
    MCR  p15, 0, r0, c1, c0, 0
    ISB
    BX        lr


    END



