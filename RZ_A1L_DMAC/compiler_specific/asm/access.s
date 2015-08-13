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

    .text
    .code 32

        .global enable_neon_vfp_access_priv_asm
        .global enable_neon_vfp_access_full_asm
        .global disable_neon_vfp_access_asm
        .global neon_vfp_on_asm
        .global neon_vfp_off_asm
        .global enable_mmu_asm
        .global disable_mmu_asm
        .global VbarSet_asm
        .global SetLowVectors_asm
        .global SetHighVectors_asm

/* ========================================================================== */
/* Enable access to NEON/VFP by enabling access to Coprocessors 10 and 11.    */
/* Enables Privileged Access i.e. in both privileged and non privileged modes */
/* ========================================================================== */
    .func   enable_neon_vfp_access_priv_asm
enable_neon_vfp_access_priv_asm:
    MRC  p15, 0, r0, c1, c0, 2 /* Read Coprocessor Access Register (CPACR)    */
    ORR  r0, r0, #(0x5 << 20)  /* Enable access to CP 10 & 11                 */
    BIC  r0, r0, #(3 << 30)    /* Clear ASEDIS/D32DIS if set                  */
    MCR  p15, 0, r0, c1, c0, 2 /* Write Coprocessor Access Register (CPACR)   */
    ISB
    BX        lr
    .endfunc
    .align 4
    
/* ========================================================================== */
/* Enable access to NEON/VFP by enabling access to Coprocessors 10 and 11.    */
/* Enables Full Access i.e. in both privileged and non privileged modes       */
/* ========================================================================== */
    .func   enable_neon_vfp_access_full_asm
enable_neon_vfp_access_full_asm:
    MRC  p15, 0, r0, c1, c0, 2 /* Read Coprocessor Access Register (CPACR)    */
    ORR  r0, r0, #(0xF << 22)  /* Enable access to CP 10 & 11                 */
    BIC  r0, r0, #(3 << 30)    /* Clear ASEDIS/D32DIS if set                  */
    MCR  p15, 0, r0, c1, c0, 2 /* Write Coprocessor Access Register (CPACR)   */
    ISB
    BX        lr
    .endfunc
    .align 4

    
/* ========================================================================== */
/* Disable access to NEON/VFP by enabling access to Coprocessors 10 and 11.   */
/* ========================================================================== */
    .func   disable_neon_vfp_access_asm
disable_neon_vfp_access_asm:
    MRC  p15, 0, r0, c1, c0, 2 /* Read Coprocessor Access Register (CPACR)    */
    BIC  r0, r0, #(0xF << 20)  /* Disable access to CP 10 & 11                */
    MCR  p15, 0, r0, c1, c0, 2 /* Write Coprocessor Access Register (CPACR)   */
    ISB
    BX        lr
    .align 4
    .endfunc
    
/* ========================================================================== */
/*  Switch on the VFP and NEON hardware                                       */
/* ========================================================================== */
    .func neon_vfp_on_asm
neon_vfp_on_asm:
    MOV  r0, #0x40000000
    VMSR FPEXC, r0                        /* Write FPEXC register, EN bit set */
    ISB
    BX        lr
    .endfunc
    .align 4

/* ========================================================================== */
/*  Switch off the VFP and NEON hardware                                      */
/* ========================================================================== */
    .func neon_vfp_off_asm
neon_vfp_off_asm:
    MOV  r0, #0x00000000
    VMSR FPEXC, r0                      /* Write FPEXC register, EN bit clear */
    ISB
    BX        lr
    .endfunc
    .align 4

/* ========================================================================== */
/* Enable MMU                                                                 */
/* Leaving the caches disabled.                                               */
/* ========================================================================== */
    .func enable_mmu_asm
enable_mmu_asm:
    MRC  p15, 0, r0, c1, c0, 0     /* Read CP15 System Control register (SCTLR) */
    BIC  r0, r0, #(0x1 << 12)             /* Clear I bit 12 to disable I Cache */
    BIC  r0, r0, #(0x1 <<  2)             /* Clear C bit  2 to disable D Cache */
    BIC  r0, r0, #0x2       /* Clear A bit 1 to disable alignment fault check */
    ORR  r0, r0, #0x1      /* Set M bit 1 to enable MMU before scatter loading */
    MCR  p15, 0, r0, c1, c0, 0            /* Write CP15 System Control register */
    ISB
    BX        lr
    .endfunc
    .align 4

/* ========================================================================== */
/* Disable MMU                                                                */
/* Leaving the caches disabled.                                               */
/* ========================================================================== */
        .func disable_mmu_asm
disable_mmu_asm:
        MRC  p15, 0, r0, c1, c0, 0       /* Read CP15 System Control register */
        BIC  r0, r0, #(0x1 << 12)        /* Clear I bit 12 to disable I Cache */
        BIC  r0, r0, #(0x1 <<  2)        /* Clear C bit  2 to disable D Cache */
        BIC  r0, r0, #0x2   /* Clear A bit 1 to disable alignment fault check */
        BIC  r0, r0, #0x1 /* Set M bit 0 to enable MMU before scatter loading */
        MCR  p15, 0, r0, c1, c0, 0      /* Write CP15 System Control register */
        BX   lr
        .endfunc
        .align 4


/* ========================================================================== */
/* VbarSet                                                                    */
/* ========================================================================== */
	.func VbarSet_asm
VbarSet_asm:
/* ========================================================================== */
/* Reconfigure Vector Base Address Register to point to application's vector table    */
/* ========================================================================== */
	MCR p15, 0, r0, c12, c0, 0

	BX		lr
	.endfunc

/* ========================================================================== */
/* Set SCTLR Low Vectors                                                      */
/*      0 = Normal (Low address) Vectors                                      */
/*      1 = High (High address) Vectors                                       */
/* ========================================================================== */
    .func SetLowVectors_asm
SetLowVectors_asm:
    MRC  p15, 0, r0, c1, c0, 0   /* Read CP15 System Control register (SCTLR) */
    BIC  r0, r0, #(0x1 << 13)           /* Clear V bit 13 to set Low Vectors  */
    MCR  p15, 0, r0, c1, c0, 0          /* Write CP15 System Control register */
    ISB
    BX        lr
    .endfunc
    .align 4

/* ========================================================================== */
/* Set SCTLR High Vectors                                                     */
/*      0 = Normal (Low address) Vectors                                      */
/*      1 = High (High address) Vectors                                       */
/* ========================================================================== */
    .func SetHighVectors_asm
SetHighVectors_asm:
    MRC  p15, 0, r0, c1, c0, 0   /* Read CP15 System Control register (SCTLR) */
    ORR  r0, r0, #(0x1 << 13)           /* Set V bit 13 to set High Vectors   */
    MCR  p15, 0, r0, c1, c0, 0          /* Write CP15 System Control register */
    ISB
    BX        lr
    .endfunc
	.align 4
	.end



