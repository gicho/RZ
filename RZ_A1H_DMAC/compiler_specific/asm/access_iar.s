/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name     : access.S
* Device(s)     : RZ/A1H (R7S721001)
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : This is the code provides access to the co-processors
*******************************************************************************/
/*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*               : 21.03.2014 2.00
*******************************************************************************/
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

/* ========================================================================== */
/* Enable access to NEON/VFP by enabling access to Coprocessors 10 and 11.    */
/* Enables Privileged Access i.e. in both privileged and non privileged modes */
/* ========================================================================== */

enable_neon_vfp_access_priv_asm:
    MRC  p15, 0, r0, c1, c0, 2 /* Read Coprocessor Access Register (CPACR)    */
    ORR  r0, r0, #(0x5 << 20)  /* Enable access to CP 10 & 11                 */
    BIC  r0, r0, #(3 << 30)    /* Clear ASEDIS/D32DIS if set                  */
    MCR  p15, 0, r0, c1, c0, 2 /* Write Coprocessor Access Register (CPACR)   */
    ISB
    BX        lr

/* ========================================================================== */
/* Enable access to NEON/VFP by enabling access to Coprocessors 10 and 11.    */
/* Enables Full Access i.e. in both privileged and non privileged modes       */
/* ========================================================================== */

enable_neon_vfp_access_full_asm:
    MRC  p15, 0, r0, c1, c0, 2 /* Read Coprocessor Access Register (CPACR)    */
    ORR  r0, r0, #(0xF << 20)  /* Enable access to CP 10 & 11                 */
    BIC  r0, r0, #(3 << 30)    /* Clear ASEDIS/D32DIS if set                  */
    MCR  p15, 0, r0, c1, c0, 2 /* Write Coprocessor Access Register (CPACR)   */
    ISB
    BX        lr
    
/* ========================================================================== */
/* Disable access to NEON/VFP by enabling access to Coprocessors 10 and 11.   */
/* ========================================================================== */

disable_neon_vfp_access_asm:
    MRC  p15, 0, r0, c1, c0, 2 /* Read Coprocessor Access Register (CPACR)    */
    BIC  r0, r0, #(0xF << 20)  /* Disable access to CP 10 & 11                */
    MCR  p15, 0, r0, c1, c0, 2 /* Write Coprocessor Access Register (CPACR)   */
    ISB
    BX        lr
    
/* ========================================================================== */
/*  Switch on the VFP and NEON hardware                                       */
/* ========================================================================== */
neon_vfp_on_asm:
    MOV  r0, #0x40000000
    VMSR FPEXC, r0                        /* Write FPEXC register, EN bit set */
    ISB
    BX        lr

/* ========================================================================== */
/*  Switch off the VFP and NEON hardware                                      */
/* ========================================================================== */
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

/* ========================================================================== */
/* Enable MMU                                                                 */
/* Leaving the caches disabled.                                               */
/* ========================================================================== */
enable_mmu_asm:
    /* Read CP15 SCTLR */
    MRC  p15, 0, r0, c1, c0, 0

    /* 	Clear V bit 13 to set low vectors
    	Clear I bit 12 to disable I Cache
    	Clear Z bit 11 to disable flow prediction
    	Clear C bit  2 to disable D Cache
    	Clear A bit  1 to disable strict alignment
    	Set   M bit  0 to enable MMU
    */
    /* BIC has 8 bit immediate + 4 bit rotation so cannot address directly above first byte */
    BIC  r0, r0, #(V_BIT)
    BIC  r0, r0, #(I_BIT)
    BIC  r0, r0, #(Z_BIT)
    BIC  r0, r0, #(C_BIT | A_BIT)
    ORR  r0, r0, #(M_BIT)

    /* Write value back to CP15 SCR */
    MCR  p15, 0, r0, c1, c0, 0
    ISB
    
    BX   lr

/* ========================================================================== */
/* Disable MMU                                                                */
/* Leaving the caches disabled.                                               */
/* ========================================================================== */
disable_mmu_asm:
    /* Read CP15 SCTLR */
    MRC  p15, 0, r0, c1, c0, 0

    /* 	Clear V bit 13 to set low vectors
    	Clear I bit 12 to disable I Cache
    	Clear Z bit 11 to disable flow prediction
    	Clear C bit  2 to disable D Cache
    	Clear A bit  1 to disable strict alignment
    	Clear M bit  0 to disable MMU
    */
    /* BIC has 8 bit immediate + 4 bit rotation so cannot address directly above first byte */
    BIC  r0, r0, #(V_BIT)
    BIC  r0, r0, #(I_BIT)
    BIC  r0, r0, #(Z_BIT)
    BIC  r0, r0, #(C_BIT | A_BIT | M_BIT)

    /* Write value back to CP15 SCR */
    MCR  p15, 0, r0, c1, c0, 0
    ISB
    
    BX   lr

/* ========================================================================== */
/* VbarSet                                                                    */
/* ========================================================================== */
VbarSet_asm:
/* ========================================================================== */
/* Reconfigure Vector Base Address Register to point to application's vector table    */
/* ========================================================================== */
    MCR p15, 0, r0, c12, c0, 0
    ISB
    BX	lr

/* ========================================================================== */
/* Set SCTLR Low Vectors                                                      */
/*      0 = Normal (Low address) Vectors                                      */
/*      1 = High (High address) Vectors                                       */
/* ========================================================================== */
SetLowVectors_asm:
    /* Read CP15 SCTLR */
    MRC  p15, 0, r0, c1, c0, 0

    /* 	Clear V bit 13 to set low vectors */
    BIC  r0, r0, #(V_BIT)

    /* Write value back to CP15 SCR */
    MCR  p15, 0, r0, c1, c0, 0
    ISB
    
    BX        lr

/* ========================================================================== */
/* Set SCTLR High Vectors                                                     */
/*      0 = Normal (Low address) Vectors                                      */
/*      1 = High (High address) Vectors                                       */
/* ========================================================================== */
SetHighVectors_asm:
    /* Read CP15 SCTLR */
    MRC  p15, 0, r0, c1, c0, 0

    /* 	Set V bit 13 to set high vectors */
    /* BIC has 8 bit immediate + 4 bit rotation so cannot address directly above first byte */
    ORR  r0, r0, #(V_BIT)

    /* Write value back to CP15 SCR */
    MCR  p15, 0, r0, c1, c0, 0
    ISB

    BX        lr


    END



