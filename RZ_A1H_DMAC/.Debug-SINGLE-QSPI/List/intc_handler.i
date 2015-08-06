#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\src\\intc_handler.c"
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
* File Name     : intc_handler.c
* Device(s)     : RZ/A1H (R7S721001)
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : Sample Program - Handler process
*******************************************************************************/
/*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*               : 21.03.2014 2.00
*******************************************************************************/

/*******************************************************************************
Includes   <System Includes> , "Project Includes"
*******************************************************************************/
/* Interchangeable compiler specific header */
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\compiler_specific\\inc\\compiler_settings.h"
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
/******************************************************************************
* File Name     : compiler_settings.h
* Device(s)     : RZ/A1H (R7S721001)
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : Any compiler specific settings are stored here.
*               : Variants of this file must be created for each compiler
******************************************************************************/
/******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*               : 21.03.2014 2.00
******************************************************************************/




/******************************************************************************
Macro definitions
******************************************************************************/


#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\intrinsics.h"
/**************************************************
 *
 * This file declares the ARM intrinsic inline functions.
 *
 * Copyright 1999-2006 IAR Systems. All rights reserved.
 *
 * $Revision: 80791 $
 *
 **************************************************/




#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */


  #pragma system_include


/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __AEABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\ycheck.h"




/* A definiton for a function of what effects it has.
   NS  = no_state, i.e. it uses no internal or external state. It may write
         to errno though
   NE  = no_state, no_errno,  i.e. it uses no internal or external state,
         not even writing to errno. 
   NRx = no_read(x), i.e. it doesn't read through pointer parameter x.
   NWx = no_write(x), i.e. it doesn't write through pointer parameter x.
*/

#line 99 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\ycheck.h"









#line 15 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\intrinsics.h"


  #pragma system_include


/*
 * Check that the correct C compiler is used.
 */









#pragma language=save
#pragma language=extended

__intrinsic __nounwind void    __no_operation(void);

__intrinsic __nounwind void    __disable_interrupt(void);
__intrinsic __nounwind void    __enable_interrupt(void);

typedef unsigned long __istate_t;

__intrinsic __nounwind __istate_t __get_interrupt_state(void);
__intrinsic __nounwind void __set_interrupt_state(__istate_t);

#line 69 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\intrinsics.h"

/* "Old" style intrerrupt control routines */
__intrinsic __nounwind void __disable_irq(void);
__intrinsic __nounwind void __enable_irq(void);


__intrinsic __nounwind void __disable_fiq(void);
__intrinsic __nounwind void __enable_fiq(void);


/* ARM-mode intrinsics */

__intrinsic __nounwind unsigned long __SWP( unsigned long, volatile unsigned long * );
__intrinsic __nounwind unsigned char __SWPB( unsigned char, volatile unsigned char * );

typedef unsigned long __ul;





/*  Co-processor access */
__intrinsic __nounwind void          __MCR( unsigned __constrange(0,15) coproc, unsigned __constrange(0,8) opcode_1, __ul src,
                                 unsigned __constrange(0,15) CRn, unsigned __constrange(0,15) CRm, unsigned __constrange(0,8) opcode_2 );
__intrinsic __nounwind unsigned long __MRC( unsigned __constrange(0,15) coproc, unsigned __constrange(0,8) opcode_1,
                                 unsigned __constrange(0,15) CRn, unsigned __constrange(0,15) CRm, unsigned __constrange(0,8) opcode_2 );
__intrinsic __nounwind void          __MCR2( unsigned __constrange(0,15) coproc, unsigned __constrange(0,8) opcode_1, __ul src,
                                  unsigned __constrange(0,15) CRn, unsigned __constrange(0,15) CRm, unsigned __constrange(0,8) opcode_2 );
__intrinsic __nounwind unsigned long __MRC2( unsigned __constrange(0,15) coproc, unsigned __constrange(0,8) opcode_1,
                                  unsigned __constrange(0,15) CRn, unsigned __constrange(0,15) CRm, unsigned __constrange(0,8) opcode_2 );

/* Load coprocessor register. */
__intrinsic __nounwind void __LDC( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul const *src);
__intrinsic __nounwind void __LDCL( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul const *src);
__intrinsic __nounwind void __LDC2( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul const *src);
__intrinsic __nounwind void __LDC2L( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul const *src);

/* Store coprocessor register. */
__intrinsic __nounwind void __STC( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul *dst);
__intrinsic __nounwind void __STCL( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul *dst);
__intrinsic __nounwind void __STC2( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul *dst);
__intrinsic __nounwind void __STC2L( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul *dst);

/* Load coprocessor register (noindexed version with coprocessor option). */
__intrinsic __nounwind void __LDC_noidx( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul const *src,
                              unsigned __constrange(0,255) option);

__intrinsic __nounwind void __LDCL_noidx( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul const *src,
                               unsigned __constrange(0,255) option);

__intrinsic __nounwind void __LDC2_noidx( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul const *src,
                               unsigned __constrange(0,255) option);

__intrinsic __nounwind void __LDC2L_noidx( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul const *src,
                                unsigned __constrange(0,255) option);

/* Store coprocessor register (version with coprocessor option). */
__intrinsic __nounwind void __STC_noidx( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul *dst,
                              unsigned __constrange(0,255) option);

__intrinsic __nounwind void __STCL_noidx( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul *dst,
                               unsigned __constrange(0,255) option);

__intrinsic __nounwind void __STC2_noidx( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul *dst,
                               unsigned __constrange(0,255) option);

__intrinsic __nounwind void __STC2L_noidx( unsigned __constrange(0,15) coproc, unsigned __constrange(0,15) CRn, volatile __ul *dst,
                                unsigned __constrange(0,255) option);






/* Status register access */
__intrinsic __nounwind unsigned long __get_CPSR( void );
__intrinsic __nounwind void          __set_CPSR( unsigned long );


/* Floating-point status and control register access */
__intrinsic __nounwind unsigned long __get_FPSCR( void );
__intrinsic __nounwind void __set_FPSCR( unsigned long );

/* Architecture v5T, CLZ is also available in Thumb mode for Thumb2 cores */
__intrinsic __nounwind unsigned char __CLZ( unsigned long );

/* Architecture v5TE */

__intrinsic __nounwind signed long __QADD( signed long, signed long );
__intrinsic __nounwind signed long __QDADD( signed long, signed long );
__intrinsic __nounwind signed long __QSUB( signed long, signed long );
__intrinsic __nounwind signed long __QDSUB( signed long, signed long );

__intrinsic __nounwind signed long __QDOUBLE( signed long );

__intrinsic __nounwind int         __QFlag( void );
__intrinsic __nounwind void __reset_Q_flag( void );


__intrinsic __nounwind int         __QCFlag( void );
__intrinsic __nounwind void __reset_QC_flag( void );

__intrinsic __nounwind signed long __SMUL( signed short, signed short );

/* Architecture v6, REV and REVSH are also available in thumb mode */
__intrinsic __nounwind unsigned long __REV( unsigned long );
__intrinsic __nounwind signed long __REVSH( short );

__intrinsic __nounwind unsigned long __REV16( unsigned long );
__intrinsic __nounwind unsigned long __RBIT( unsigned long );

__intrinsic __nounwind unsigned char  __LDREXB( volatile unsigned char const * );
__intrinsic __nounwind unsigned short __LDREXH( volatile unsigned short const * );
__intrinsic __nounwind unsigned long  __LDREX ( volatile unsigned long const * );
__intrinsic __nounwind unsigned long long __LDREXD( volatile unsigned long long const * );

__intrinsic __nounwind unsigned long  __STREXB( unsigned char, volatile unsigned char * );
__intrinsic __nounwind unsigned long  __STREXH( unsigned short, volatile unsigned short * );
__intrinsic __nounwind unsigned long  __STREX ( unsigned long, volatile unsigned long * );
__intrinsic __nounwind unsigned long  __STREXD( unsigned long long, volatile unsigned long long * );

__intrinsic __nounwind void __CLREX( void );

__intrinsic __nounwind void __SEV( void );
__intrinsic __nounwind void __WFE( void );
__intrinsic __nounwind void __WFI( void );
__intrinsic __nounwind void __YIELD( void );

__intrinsic __nounwind void __PLI( volatile void const * );
__intrinsic __nounwind void __PLD( volatile void const * );
__intrinsic __nounwind void __PLDW( volatile void const * );

__intrinsic __nounwind   signed long __SSAT     (unsigned long val,
                                      unsigned int __constrange( 1, 32 ) sat );
__intrinsic __nounwind unsigned long __USAT     (unsigned long val,
                                      unsigned int __constrange( 0, 31 ) sat );




/* Architecture v6 Media instructions.... */
__intrinsic __nounwind unsigned long __SEL( unsigned long op1, unsigned long op2 );

__intrinsic __nounwind unsigned long __SADD8    (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __SADD16   (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __SSUB8    (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __SSUB16   (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __SADDSUBX (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __SSUBADDX (unsigned long pair1, unsigned long pair2);

__intrinsic __nounwind unsigned long __SHADD8   (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __SHADD16  (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __SHSUB8   (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __SHSUB16  (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __SHADDSUBX(unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __SHSUBADDX(unsigned long pair1, unsigned long pair2);

__intrinsic __nounwind unsigned long __QADD8    (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __QADD16   (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __QSUB8    (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __QSUB16   (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __QADDSUBX (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __QSUBADDX (unsigned long pair1, unsigned long pair2);

__intrinsic __nounwind unsigned long __UADD8    (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __UADD16   (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __USUB8    (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __USUB16   (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __UADDSUBX (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __USUBADDX (unsigned long pair1, unsigned long pair2);

__intrinsic __nounwind unsigned long __UHADD8   (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __UHADD16  (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __UHSUB8   (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __UHSUB16  (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __UHADDSUBX(unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __UHSUBADDX(unsigned long pair1, unsigned long pair2);

__intrinsic __nounwind unsigned long __UQADD8   (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __UQADD16  (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __UQSUB8   (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __UQSUB16  (unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __UQADDSUBX(unsigned long pair1, unsigned long pair2);
__intrinsic __nounwind unsigned long __UQSUBADDX(unsigned long pair1, unsigned long pair2);

__intrinsic __nounwind unsigned long __USAD8(unsigned long x, unsigned long y );
__intrinsic __nounwind unsigned long __USADA8(unsigned long x, unsigned long y,
                                   unsigned long acc );

__intrinsic __nounwind unsigned long __SSAT16   (unsigned long pair,
                                      unsigned int __constrange( 1, 16 ) sat );
__intrinsic __nounwind unsigned long __USAT16   (unsigned long pair,
                                      unsigned int __constrange( 0, 15 ) sat );

__intrinsic __nounwind long __SMUAD (unsigned long x, unsigned long y);
__intrinsic __nounwind long __SMUSD (unsigned long x, unsigned long y);
__intrinsic __nounwind long __SMUADX(unsigned long x, unsigned long y);
__intrinsic __nounwind long __SMUSDX(unsigned long x, unsigned long y);

__intrinsic __nounwind long __SMLAD (unsigned long x, unsigned long y, long sum);
__intrinsic __nounwind long __SMLSD (unsigned long x, unsigned long y, long sum);
__intrinsic __nounwind long __SMLADX(unsigned long x, unsigned long y, long sum);
__intrinsic __nounwind long __SMLSDX(unsigned long x, unsigned long y, long sum);

__intrinsic __nounwind long long __SMLALD (unsigned long pair1,
                                 unsigned long pair2,
                                 long long acc);

__intrinsic __nounwind long long __SMLALDX(unsigned long pair1,
                                 unsigned long pair2,
                                 long long acc);

__intrinsic __nounwind long long __SMLSLD (unsigned long pair1,
                                 unsigned long pair2,
                                 long long acc);

__intrinsic __nounwind long long __SMLSLDX(unsigned long pair1,
                                 unsigned long pair2,
                                 long long acc);

__intrinsic __nounwind unsigned long __PKHBT(unsigned long x,
                                  unsigned long y,
                                  unsigned __constrange(0,31) count);
__intrinsic __nounwind unsigned long __PKHTB(unsigned long x,
                                  unsigned long y,
                                  unsigned __constrange(0,32) count);

__intrinsic __nounwind long __SMLABB(unsigned long x, unsigned long y, long acc);
__intrinsic __nounwind long __SMLABT(unsigned long x, unsigned long y, long acc);
__intrinsic __nounwind long __SMLATB(unsigned long x, unsigned long y, long acc);
__intrinsic __nounwind long __SMLATT(unsigned long x, unsigned long y, long acc);

__intrinsic __nounwind long __SMLAWB(long x, unsigned long y, long acc);
__intrinsic __nounwind long __SMLAWT(long x, unsigned long y, long acc);

__intrinsic __nounwind long __SMMLA (long x, long y, long acc);
__intrinsic __nounwind long __SMMLAR(long x, long y, long acc);
__intrinsic __nounwind long __SMMLS (long x, long y, long acc);
__intrinsic __nounwind long __SMMLSR(long x, long y, long acc);

__intrinsic __nounwind long __SMMUL (long x, long y);
__intrinsic __nounwind long __SMMULR(long x, long y);

__intrinsic __nounwind long __SMULBB(unsigned long x, unsigned long y);
__intrinsic __nounwind long __SMULBT(unsigned long x, unsigned long y);
__intrinsic __nounwind long __SMULTB(unsigned long x, unsigned long y);
__intrinsic __nounwind long __SMULTT(unsigned long x, unsigned long y);

__intrinsic __nounwind long __SMULWB(long x, unsigned long y);
__intrinsic __nounwind long __SMULWT(long x, unsigned long y);

__intrinsic __nounwind long __SXTAB (long x, unsigned long y);
__intrinsic __nounwind long __SXTAH (long x, unsigned long y);
__intrinsic __nounwind unsigned long __UXTAB (unsigned long x, unsigned long y);
__intrinsic __nounwind unsigned long __UXTAH (unsigned long x, unsigned long y);

__intrinsic __nounwind unsigned long long __UMAAL(unsigned long x,
                                       unsigned long y,
                                       unsigned long a,
                                       unsigned long b);

__intrinsic __nounwind long long __SMLALBB(unsigned long x,
                                 unsigned long y,
                                 long long acc);

__intrinsic __nounwind long long __SMLALBT(unsigned long x,
                                 unsigned long y,
                                 long long acc);

__intrinsic __nounwind long long __SMLALTB(unsigned long x,
                                 unsigned long y,
                                 long long acc);

__intrinsic __nounwind long long __SMLALTT(unsigned long x,
                                 unsigned long y,
                                 long long acc);

__intrinsic __nounwind unsigned long __UXTB16(unsigned long x);
__intrinsic __nounwind unsigned long __UXTAB16(unsigned long acc, unsigned long x);

__intrinsic __nounwind unsigned long __SXTB16(unsigned long x);
__intrinsic __nounwind unsigned long __SXTAB16(unsigned long acc, unsigned long x);

__intrinsic __nounwind unsigned long __SASX(unsigned long, unsigned long) ;
__intrinsic __nounwind unsigned long __SSAX(unsigned long, unsigned long) ;
__intrinsic __nounwind unsigned long __SHASX(unsigned long, unsigned long) ;
__intrinsic __nounwind unsigned long __SHSAX(unsigned long, unsigned long) ;
__intrinsic __nounwind unsigned long __QASX(unsigned long, unsigned long) ;
__intrinsic __nounwind unsigned long __QSAX(unsigned long, unsigned long) ;

__intrinsic __nounwind unsigned long __UASX(unsigned long, unsigned long) ;
__intrinsic __nounwind unsigned long __USAX(unsigned long, unsigned long) ;
__intrinsic __nounwind unsigned long __UHASX(unsigned long, unsigned long) ;
__intrinsic __nounwind unsigned long __UHSAX(unsigned long, unsigned long) ;
__intrinsic __nounwind unsigned long __UQASX(unsigned long, unsigned long) ;
__intrinsic __nounwind unsigned long __UQSAX(unsigned long, unsigned long) ;


/* Architecture v7 instructions.... */
__intrinsic __nounwind void __DMB(void);
__intrinsic __nounwind void __DSB(void);
__intrinsic __nounwind void __ISB(void);




#pragma language=restore





#line 47 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\compiler_specific\\inc\\compiler_settings.h"

















#line 84 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\compiler_specific\\inc\\compiler_settings.h"


/******************************************************************************
Variable External definitions and Function External definitions
******************************************************************************/

extern void __enable_irq(void);
extern void __disable_irq(void);
extern void __enable_fiq(void);
extern void __disable_fiq(void);


/******************************************************************************
Functions Prototypes
******************************************************************************/

/* COMPILER_SETTINGS_H */


/* End of File */
#line 42 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\src\\intc_handler.c"

/* Default  type definition header */
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\r_typedefs.h"
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
* File Name     : r_typedefs.h
* Device(s)     : RZ/A1H (R7S721001)
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : basic type definition
******************************************************************************/
/*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*               : 21.03.2014 2.00
*******************************************************************************/

/* Multiple inclusion prevention macro */



/******************************************************************************
Includes <System Includes> , "Project Includes"
******************************************************************************/
#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\stdint.h"
/* stdint.h standard header */
/* Copyright 2003-2010 IAR Systems AB.  */




  #pragma system_include


#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */


  #pragma system_include


/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __AEABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\ycheck.h"

#line 11 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\stdint.h"
#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"
/* yvals.h internal configuration header file. */
/* Copyright 2001-2010 IAR Systems AB. */





  #pragma system_include


#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */


  #pragma system_include


/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __AEABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\ycheck.h"

#line 12 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"

                /* Convenience macros */









/* Used to refer to '__aeabi' symbols in the library. */ 


                /* Versions */










/*
 * Support for some C99 or other symbols
 *
 * This setting makes available some macros, functions, etc that are
 * beneficial.
 *
 * Default is to include them.
 *
 * Disabling this in C++ mode will not compile (some C++ functions uses C99
 * functionality).
 */


  /* Default turned on when compiling C++, EC++, or C99. */
#line 59 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"





#line 70 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"

                /* Configuration */
#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Defaults.h"
/***************************************************
 *
 * DLib_Defaults.h is the library configuration manager.
 *
 * Copyright 2003-2010 IAR Systems AB.  
 *
 * This configuration header file performs the following tasks:
 *
 * 1. Includes the configuration header file, defined by _DLIB_CONFIG_FILE,
 *    that sets up a particular runtime environment.
 *
 * 2. Includes the product configuration header file, DLib_Product.h, that
 *    specifies default values for the product and makes sure that the
 *    configuration is valid.
 *
 * 3. Sets up default values for all remaining configuration symbols.
 *
 * This configuration header file, the one defined by _DLIB_CONFIG_FILE, and
 * DLib_Product.h configures how the runtime environment should behave. This
 * includes all system headers and the library itself, i.e. all system headers
 * includes this configuration header file, and the library has been built
 * using this configuration header file.
 *
 ***************************************************
 *
 * DO NOT MODIFY THIS FILE!
 *
 ***************************************************/





  #pragma system_include


/* Include the main configuration header file. */
#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\INC\\c\\DLib_Config_Normal.h"
/* Customer-specific DLib configuration. */
/* Copyright (C) 2003 IAR Systems.  All rights reserved. */





  #pragma system_include


/* No changes to the defaults. */

#line 40 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Defaults.h"
  /* _DLIB_CONFIG_FILE_STRING is the quoted variant of above */
#line 47 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Defaults.h"

/* Include the product specific header file. */
#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Product.h"




   #pragma system_include



/*********************************************************************
*
*       Configuration
*
*********************************************************************/

/* Wide character and multi byte character support in library.
 * This is not allowed to vary over configurations, since math-library
 * is built with wide character support.
 */


/* ARM uses the large implementation of DLib */


/* This ensures that the standard header file "string.h" includes
 * the Arm-specific file "DLib_Product_string.h". */


/* This ensures that the standard header file "fenv.h" includes
 * the Arm-specific file "DLib_Product_fenv.h". */


/* Max buffer used for swap in qsort */




/* Enable system locking  */
#line 45 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Product.h"

/* Enable AEABI support */


/* Enable rtmodel for setjump buffer size */


/* Enable parsing of hex floats */






/* Special placement for locale structures when building ropi libraries */




/* CPP-library uses software floatingpoint interface */


/* Use speedy implementation of floats (simple quad). */


/* Configure generic ELF init routines. */
#line 99 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Product.h"







#line 51 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Defaults.h"



/*
 * The remainder of the file sets up defaults for a number of
 * configuration symbols, each corresponds to a feature in the
 * libary.
 *
 * The value of the symbols should either be 1, if the feature should
 * be supported, or 0 if it shouldn't. (Except where otherwise
 * noted.)
 */


/*
 * Small or Large target
 *
 * This define determines whether the target is large or small. It must be 
 * setup in the DLib_Product header or in the compiler itself.
 *
 * For a small target some functionality in the library will not deliver 
 * the best available results. For instance the _accurate variants will not use
 * the extra precision packet for large arguments.
 * 
 */







/*
 * File handling
 *
 * Determines whether FILE descriptors and related functions exists or not.
 * When this feature is selected, i.e. set to 1, then FILE descriptors and
 * related functions (e.g. fprintf, fopen) exist. All files, even stdin,
 * stdout, and stderr will then be handled with a file system mechanism that
 * buffers files before accessing the lowlevel I/O interface (__open, __read,
 * __write, etc).
 *
 * If not selected, i.e. set to 0, then FILE descriptors and related functions
 * (e.g. fprintf, fopen) does not exist. All functions that normally uses
 * stderr will use stdout instead. Functions that uses stdout and stdin (like
 * printf and scanf) will access the lowlevel I/O interface directly (__open,
 * __read, __write, etc), i.e. there will not be any buffering.
 *
 * The default is not to have support for FILE descriptors.
 */





/*
 * Use static buffers for stdout
 *
 * This setting controls whether the stream stdout uses a static 80 bytes
 * buffer or uses a one byte buffer allocated in the file descriptor. This
 * setting is only applicable if the FILE descriptors are enabled above.
 *
 * Default is to use a static 80 byte buffer.
 */





/*
 * Support of locale interface
 *
 * "Locale" is the system in C that support language- and
 * contry-specific settings for a number of areas, including currency
 * symbols, date and time, and multibyte encodings.
 *
 * This setting determines whether the locale interface exist or not.
 * When this feature is selected, i.e. set to 1, the locale interface exist
 * (setlocale, etc). A number of preselected locales can be activated during
 * runtime. The preselected locales and encodings is choosen by defining any
 * number of _LOCALE_USE_xxx and _ENCODING_USE_xxx symbols. The application
 * will start with the "C" locale choosen. (Single byte encoding is always
 * supported in this mode.)
 *
 *
 * If not selected, i.e. set to 0, the locale interface (setlocale, etc) does
 * not exist. One preselected locale and one preselected encoding is then used
 * directly. That locale can not be changed during runtime. The preselected
 * locale and encoding is choosen by defining at most one of _LOCALE_USE_xxx
 * and at most one of _ENCODING_USE_xxx. The default is to use the "C" locale
 * and the single byte encoding, respectively.
 *
 * The default is not to have support for the locale interface with the "C"
 * locale and the single byte encoding.
 *
 * Supported locales
 * -----------------
 * _LOCALE_USE_C                  C standard locale (the default)
 * _LOCALE_USE_POSIX ISO-8859-1   Posix locale
 * _LOCALE_USE_CS_CZ ISO-8859-2   Czech language locale for Czech Republic
 * _LOCALE_USE_DA_DK ISO-8859-1   Danish language locale for Denmark
 * _LOCALE_USE_DA_EU ISO-8859-15  Danish language locale for Europe
 * _LOCALE_USE_DE_AT ISO-8859-1   German language locale for Austria
 * _LOCALE_USE_DE_BE ISO-8859-1   German language locale for Belgium
 * _LOCALE_USE_DE_CH ISO-8859-1   German language locale for Switzerland
 * _LOCALE_USE_DE_DE ISO-8859-1   German language locale for Germany
 * _LOCALE_USE_DE_EU ISO-8859-15  German language locale for Europe
 * _LOCALE_USE_DE_LU ISO-8859-1   German language locale for Luxemburg
 * _LOCALE_USE_EL_EU ISO-8859-7x  Greek language locale for Europe
 *                                (Euro symbol added)
 * _LOCALE_USE_EL_GR ISO-8859-7   Greek language locale for Greece
 * _LOCALE_USE_EN_AU ISO-8859-1   English language locale for Australia
 * _LOCALE_USE_EN_CA ISO-8859-1   English language locale for Canada
 * _LOCALE_USE_EN_DK ISO_8859-1   English language locale for Denmark
 * _LOCALE_USE_EN_EU ISO-8859-15  English language locale for Europe
 * _LOCALE_USE_EN_GB ISO-8859-1   English language locale for United Kingdom
 * _LOCALE_USE_EN_IE ISO-8859-1   English language locale for Ireland
 * _LOCALE_USE_EN_NZ ISO-8859-1   English language locale for New Zealand
 * _LOCALE_USE_EN_US ISO-8859-1   English language locale for USA
 * _LOCALE_USE_ES_AR ISO-8859-1   Spanish language locale for Argentina
 * _LOCALE_USE_ES_BO ISO-8859-1   Spanish language locale for Bolivia
 * _LOCALE_USE_ES_CL ISO-8859-1   Spanish language locale for Chile
 * _LOCALE_USE_ES_CO ISO-8859-1   Spanish language locale for Colombia
 * _LOCALE_USE_ES_DO ISO-8859-1   Spanish language locale for Dominican Republic
 * _LOCALE_USE_ES_EC ISO-8859-1   Spanish language locale for Equador
 * _LOCALE_USE_ES_ES ISO-8859-1   Spanish language locale for Spain
 * _LOCALE_USE_ES_EU ISO-8859-15  Spanish language locale for Europe
 * _LOCALE_USE_ES_GT ISO-8859-1   Spanish language locale for Guatemala
 * _LOCALE_USE_ES_HN ISO-8859-1   Spanish language locale for Honduras
 * _LOCALE_USE_ES_MX ISO-8859-1   Spanish language locale for Mexico
 * _LOCALE_USE_ES_PA ISO-8859-1   Spanish language locale for Panama
 * _LOCALE_USE_ES_PE ISO-8859-1   Spanish language locale for Peru
 * _LOCALE_USE_ES_PY ISO-8859-1   Spanish language locale for Paraguay
 * _LOCALE_USE_ES_SV ISO-8859-1   Spanish language locale for Salvador
 * _LOCALE_USE_ES_US ISO-8859-1   Spanish language locale for USA
 * _LOCALE_USE_ES_UY ISO-8859-1   Spanish language locale for Uruguay
 * _LOCALE_USE_ES_VE ISO-8859-1   Spanish language locale for Venezuela
 * _LOCALE_USE_ET_EE ISO-8859-1   Estonian language for Estonia
 * _LOCALE_USE_EU_ES ISO-8859-1   Basque language locale for Spain
 * _LOCALE_USE_FI_EU ISO-8859-15  Finnish language locale for Europe
 * _LOCALE_USE_FI_FI ISO-8859-1   Finnish language locale for Finland
 * _LOCALE_USE_FO_FO ISO-8859-1   Faroese language locale for Faroe Islands
 * _LOCALE_USE_FR_BE ISO-8859-1   French language locale for Belgium
 * _LOCALE_USE_FR_CA ISO-8859-1   French language locale for Canada
 * _LOCALE_USE_FR_CH ISO-8859-1   French language locale for Switzerland
 * _LOCALE_USE_FR_EU ISO-8859-15  French language locale for Europe
 * _LOCALE_USE_FR_FR ISO-8859-1   French language locale for France
 * _LOCALE_USE_FR_LU ISO-8859-1   French language locale for Luxemburg
 * _LOCALE_USE_GA_EU ISO-8859-15  Irish language locale for Europe
 * _LOCALE_USE_GA_IE ISO-8859-1   Irish language locale for Ireland
 * _LOCALE_USE_GL_ES ISO-8859-1   Galician language locale for Spain
 * _LOCALE_USE_HR_HR ISO-8859-2   Croatian language locale for Croatia
 * _LOCALE_USE_HU_HU ISO-8859-2   Hungarian language locale for Hungary
 * _LOCALE_USE_ID_ID ISO-8859-1   Indonesian language locale for Indonesia
 * _LOCALE_USE_IS_EU ISO-8859-15  Icelandic language locale for Europe
 * _LOCALE_USE_IS_IS ISO-8859-1   Icelandic language locale for Iceland
 * _LOCALE_USE_IT_EU ISO-8859-15  Italian language locale for Europe
 * _LOCALE_USE_IT_IT ISO-8859-1   Italian language locale for Italy
 * _LOCALE_USE_IW_IL ISO-8859-8   Hebrew language locale for Israel
 * _LOCALE_USE_KL_GL ISO-8859-1   Greenlandic language locale for Greenland
 * _LOCALE_USE_LT_LT   BALTIC     Lithuanian languagelocale for Lithuania
 * _LOCALE_USE_LV_LV   BALTIC     Latvian languagelocale for Latvia
 * _LOCALE_USE_NL_BE ISO-8859-1   Dutch language locale for Belgium
 * _LOCALE_USE_NL_EU ISO-8859-15  Dutch language locale for Europe
 * _LOCALE_USE_NL_NL ISO-8859-9   Dutch language locale for Netherlands
 * _LOCALE_USE_NO_EU ISO-8859-15  Norwegian language locale for Europe
 * _LOCALE_USE_NO_NO ISO-8859-1   Norwegian language locale for Norway
 * _LOCALE_USE_PL_PL ISO-8859-2   Polish language locale for Poland
 * _LOCALE_USE_PT_BR ISO-8859-1   Portugese language locale for Brazil
 * _LOCALE_USE_PT_EU ISO-8859-15  Portugese language locale for Europe
 * _LOCALE_USE_PT_PT ISO-8859-1   Portugese language locale for Portugal
 * _LOCALE_USE_RO_RO ISO-8859-2   Romanian language locale for Romania
 * _LOCALE_USE_RU_RU ISO-8859-5   Russian language locale for Russia
 * _LOCALE_USE_SL_SI ISO-8859-2   Slovenian language locale for Slovenia
 * _LOCALE_USE_SV_EU ISO-8859-15  Swedish language locale for Europe
 * _LOCALE_USE_SV_FI ISO-8859-1   Swedish language locale for Finland
 * _LOCALE_USE_SV_SE ISO-8859-1   Swedish language locale for Sweden
 * _LOCALE_USE_TR_TR ISO-8859-9   Turkish language locale for Turkey
 *
 *  Supported encodings
 *  -------------------
 * n/a                            Single byte (used if no other is defined).
 * _ENCODING_USE_UTF8             UTF8 encoding.
 */






/* We need to have the "C" locale if we have full locale support. */






/*
 * Support of multibytes in printf- and scanf-like functions
 *
 * This is the default value for _DLIB_PRINTF_MULTIBYTE and
 * _DLIB_SCANF_MULTIBYTE. See them for a description.
 *
 * Default is to not have support for multibytes in printf- and scanf-like
 * functions.
 */






/*
 * Throw handling in the EC++ library
 *
 * This setting determines what happens when the EC++ part of the library
 * fails (where a normal C++ library 'throws').
 *
 * The following alternatives exists (setting of the symbol):
 * 0                - The application does nothing, i.e. continues with the
 *                    next statement.
 * 1                - The application terminates by calling the 'abort'
 *                    function directly.
 * <anything else>  - An object of class "exception" is created.  This
 *                    object contains a string describing the problem.
 *                    This string is later emitted on "stderr" before
 *                    the application terminates by calling the 'abort'
 *                    function directly.
 *
 * Default is to do nothing.
 */






/*
 * Hexadecimal floating-point numbers in strtod
 *
 * If selected, i.e. set to 1, strtod supports C99 hexadecimal floating-point
 * numbers. This also enables hexadecimal floating-points in internal functions
 * used for converting strings and wide strings to float, double, and long
 * double.
 *
 * If not selected, i.e. set to 0, C99 hexadecimal floating-point numbers
 * aren't supported.
 *
 * Default is not to support hexadecimal floating-point numbers.
 */






/*
 * Printf configuration symbols.
 *
 * All the configuration symbols described further on controls the behaviour
 * of printf, sprintf, and the other printf variants.
 *
 * The library proves four formatters for printf: 'tiny', 'small',
 * 'large', and 'default'.  The setup in this file controls all except
 * 'tiny'.  Note that both small' and 'large' explicitly removes
 * some features.
 */

/*
 * Handle multibytes in printf
 *
 * This setting controls whether multibytes and wchar_ts are supported in
 * printf. Set to 1 to support them, otherwise set to 0.
 *
 * See _DLIB_FORMATTED_MULTIBYTE for the default setting.
 */





/*
 * Long long formatting in printf
 *
 * This setting controls long long support (%lld) in printf. Set to 1 to
 * support it, otherwise set to 0.

 * Note, if long long should not be supported and 'intmax_t' is larger than
 * an ordinary 'long', then %jd and %jn will not be supported.
 *
 * Default is to support long long formatting.
 */

#line 351 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Defaults.h"






/*
 * Floating-point formatting in printf
 *
 * This setting controls whether printf supports floating-point formatting.
 * Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support floating-point formatting.
 */





/*
 * Hexadecimal floating-point formatting in printf
 *
 * This setting controls whether the %a format, i.e. the output of
 * floating-point numbers in the C99 hexadecimal format. Set to 1 to support
 * it, otherwise set to 0.
 *
 * Default is to support %a in printf.
 */





/*
 * Output count formatting in printf
 *
 * This setting controls whether the output count specifier (%n) is supported
 * or not in printf. Set to 1 to support it, otherwise set to 0.
 *
 * Default is to support %n in printf.
 */





/*
 * Support of qualifiers in printf
 *
 * This setting controls whether qualifiers that enlarges the input value
 * [hlLjtz] is supported in printf or not. Set to 1 to support them, otherwise
 * set to 0. See also _DLIB_PRINTF_INT_TYPE_IS_INT and
 * _DLIB_PRINTF_INT_TYPE_IS_LONG.
 *
 * Default is to support [hlLjtz] qualifiers in printf.
 */





/*
 * Support of flags in printf
 *
 * This setting controls whether flags (-+ #0) is supported in printf or not.
 * Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support flags in printf.
 */





/*
 * Support widths and precisions in printf
 *
 * This setting controls whether widths and precisions are supported in printf.
 * Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support widths and precisions in printf.
 */





/*
 * Support of unsigned integer formatting in printf
 *
 * This setting controls whether unsigned integer formatting is supported in
 * printf. Set to 1 to support it, otherwise set to 0.
 *
 * Default is to support unsigned integer formatting in printf.
 */





/*
 * Support of signed integer formatting in printf
 *
 * This setting controls whether signed integer formatting is supported in
 * printf. Set to 1 to support it, otherwise set to 0.
 *
 * Default is to support signed integer formatting in printf.
 */





/*
 * Support of formatting anything larger than int in printf
 *
 * This setting controls if 'int' should be used internally in printf, rather
 * than the largest existing integer type. If 'int' is used, any integer or
 * pointer type formatting use 'int' as internal type even though the
 * formatted type is larger. Set to 1 to use 'int' as internal type, otherwise
 * set to 0.
 *
 * See also next configuration.
 *
 * Default is to internally use largest existing internally type.
 */





/*
 * Support of formatting anything larger than long in printf
 *
 * This setting controls if 'long' should be used internally in printf, rather
 * than the largest existing integer type. If 'long' is used, any integer or
 * pointer type formatting use 'long' as internal type even though the
 * formatted type is larger. Set to 1 to use 'long' as internal type,
 * otherwise set to 0.
 *
 * See also previous configuration.
 *
 * Default is to internally use largest existing internally type.
 */









/*
 * Emit a char a time in printf
 *
 * This setting controls internal output handling. If selected, i.e. set to 1,
 * then printf emits one character at a time, which requires less code but
 * can be slightly slower for some types of output.
 *
 * If not selected, i.e. set to 0, then printf buffers some outputs.
 *
 * Note that it is recommended to either use full file support (see
 * _DLIB_FILE_DESCRIPTOR) or -- for debug output -- use the linker
 * option "-e__write_buffered=__write" to enable buffered I/O rather
 * than deselecting this feature.
 */






/*
 * Scanf configuration symbols.
 *
 * All the configuration symbols described here controls the
 * behaviour of scanf, sscanf, and the other scanf variants.
 *
 * The library proves three formatters for scanf: 'small', 'large',
 * and 'default'.  The setup in this file controls all, however both
 * 'small' and 'large' explicitly removes some features.
 */

/*
 * Handle multibytes in scanf
 *
 * This setting controls whether multibytes and wchar_t:s are supported in
 * scanf. Set to 1 to support them, otherwise set to 0.
 *
 * See _DLIB_FORMATTED_MULTIBYTE for the default.
 */





/*
 * Long long formatting in scanf
 *
 * This setting controls whether scanf supports long long support (%lld). It
 * also controls, if 'intmax_t' is larger than an ordinary 'long', i.e. how
 * the %jd and %jn specifiers behaves. Set to 1 to support them, otherwise set
 * to 0.
 *
 * Default is to support long long formatting in scanf.
 */

#line 566 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Defaults.h"





/*
 * Support widths in scanf
 *
 * This controls whether scanf supports widths. Set to 1 to support them,
 * otherwise set to 0.
 *
 * Default is to support widths in scanf.
 */





/*
 * Support qualifiers [hjltzL] in scanf
 *
 * This setting controls whether scanf supports qualifiers [hjltzL] or not. Set
 * to 1 to support them, otherwise set to 0.
 *
 * Default is to support qualifiers in scanf.
 */





/*
 * Support floating-point formatting in scanf
 *
 * This setting controls whether scanf supports floating-point formatting. Set
 * to 1 to support them, otherwise set to 0.
 *
 * Default is to support floating-point formatting in scanf.
 */





/*
 * Support output count formatting (%n)
 *
 * This setting controls whether scanf supports output count formatting (%n).
 * Set to 1 to support it, otherwise set to 0.
 *
 * Default is to support output count formatting in scanf.
 */





/*
 * Support scansets ([]) in scanf
 *
 * This setting controls whether scanf supports scansets ([]) or not. Set to 1
 * to support them, otherwise set to 0.
 *
 * Default is to support scansets in scanf.
 */





/*
 * Support signed integer formatting in scanf
 *
 * This setting controls whether scanf supports signed integer formatting or
 * not. Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support signed integer formatting in scanf.
 */





/*
 * Support unsigned integer formatting in scanf
 *
 * This setting controls whether scanf supports unsigned integer formatting or
 * not. Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support unsigned integer formatting in scanf.
 */





/*
 * Support assignment suppressing [*] in scanf
 *
 * This setting controls whether scanf supports assignment suppressing [*] or
 * not. Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support assignment suppressing in scanf.
 */





/*
 * Handle multibytes in asctime and strftime.
 *
 * This setting controls whether multibytes and wchar_ts are
 * supported.Set to 1 to support them, otherwise set to 0.
 *
 * See _DLIB_FORMATTED_MULTIBYTE for the default setting.
 */





/*
 * True if "qsort" should be implemented using bubble sort.
 *
 * Bubble sort is less efficient than quick sort but requires less RAM
 * and ROM resources.
 */





/*
 * Set Buffert size used in qsort
 */





/*
 * The default "rand" function uses an array of 32 long:s of memory to
 * store the current state.
 *
 * The simple "rand" function uses only a single long. However, the
 * quality of the generated psuedo-random numbers are not as good as
 * the default implementation.
 */





/*
 * Wide character and multi byte character support in library.
 */





/*
 * Set attributes on the function used by the C-SPY debug interface to set a
 * breakpoint in.
 */





/*
 * Support threading in the library
 *
 * 0    No thread support
 * 1    Thread support with a, b, and d.
 * 2    Thread support with a, b, and e.
 * 3    Thread support with all thread-local storage in a dynamically allocated
 *        memory area and a, and b.
 *      a. Lock on heap accesses
 *      b. Optional lock on file accesses (see _DLIB_FILE_OP_LOCKS below)
 *      d. Use an external thread-local storage interface for all the
 *         libraries static and global variables.
 *      e. Static and global variables aren't safe for access from several
 *         threads.
 *
 * Note that if locks are used the following symbols must be defined:
 *
 *   _DLIB_THREAD_LOCK_ONCE_TYPE
 *   _DLIB_THREAD_LOCK_ONCE_MACRO(control_variable, init_function)
 *   _DLIB_THREAD_LOCK_ONCE_TYPE_INIT
 *
 * They will be used to initialize the needed locks only once. TYPE is the
 * type for the static control variable, MACRO is the expression that will be
 * evaluated at each usage of a lock, and INIT is the initializer for the
 * control variable.
 *
 * Note that if thread model 3 is used the symbol _DLIB_TLS_POINTER must be
 * defined. It is a thread local pointer to a dynamic memory area that
 * contains all used TLS variables for the library. Optionally the following
 * symbols can be defined as well (default is to use the default const data
 * and data memories):
 *
 *   _DLIB_TLS_INITIALIZER_MEMORY The memory to place the initializers for the
 *                                TLS memory area
 *   _DLIB_TLS_MEMORY             The memory to use for the TLS memory area. A
 *                                pointer to this memory must be castable to a
 *                                default pointer and back.
 *   _DLIB_TLS_REQUIRE_INIT       Set to 1 to require __cstart_init_tls
 *                                when needed to initialize the TLS data
 *                                segment for the main thread.
 *   _DLIB_TLS_SEGMENT_DATA       The name of the TLS RAM data segment
 *   _DLIB_TLS_SEGMENT_INIT       The name of the used to initialize the
 *                                TLS data segment.
 *
 * See DLib_Threads.h for a description of what interfaces needs to be
 * defined for thread support.
 */





/*
 * Used by products where one runtime library can be used by applications
 * with different data models, in order to reduce the total number of
 * libraries required. Typically, this is used when the pointer types does
 * not change over the data models used, but the placement of data variables
 * or/and constant variables do.
 *
 * If defined, this symbol is typically defined to the memory attribute that
 * is used by the runtime library. The actual define must use a
 * _Pragma("type_attribute = xxx") construct. In the header files, it is used
 * on all statically linked data objects seen by the application.
 */




#line 812 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Defaults.h"


/*
 * Turn on support for the Target-specific ABI. The ABI is based on the
 * ARM AEABI. A target, except ARM, may deviate from it.
 */

#line 826 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Defaults.h"


  /* Possible AEABI deviations */
#line 836 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Defaults.h"

#line 844 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Defaults.h"
  /*
   * The "difunc" table contains information about C++ objects that
   * should be dynamically initialized, where each entry in the table
   * represents an initialization function that should be called. When
   * the symbol _DLIB_AEABI_DIFUNC_CONTAINS_OFFSETS is true, each
   * entry in the table is encoded as an offset from the entry
   * location. When false, the entries contain the actual addresses to
   * call.
   */






/*
 * Turn on usage of a pragma to tell the linker the number of elements used
 * in a setjmp jmp_buf.
 */





/*
 * If true, the product supplies a "DLib_Product_string.h" file that
 * is included from "string.h".
 */





/*
 * Determine whether the math fma routines are fast or not.
 */




/*
 * Rtti support.
 */

#line 899 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Defaults.h"

/*
 * Use the "pointers to short" or "pointers to long" implementation of 
 * the basic floating point routines (like Dnorm, Dtest, Dscale, and Dunscale).
 */




/*
 * Use 64-bit long long as intermediary type in Dtest, and fabs.
 * Default is to do this if long long is 64-bits.
 */




/*
 * Favor speed versus some size enlargements in floating point functions.
 */




/*
 * Include dlmalloc as an alternative heap manager in product.
 *
 * Typically, an application will use a "malloc" heap manager that is
 * relatively small but not that efficient. An application can
 * optionally use the "dlmalloc" package, which provides a more
 * effective "malloc" heap manager, if it is included in the product
 * and supported by the settings.
 *
 * See the product documentation on how to use it, and whether or not
 * it is included in the product.
 */

  /* size_t/ptrdiff_t must be a 4 bytes unsigned integer. */
#line 943 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Defaults.h"





/*
 * Allow the 64-bit time_t interface?
 *
 * Default is yes if long long is 64 bits.
 */

  #pragma language = save 
  #pragma language = extended





  #pragma language = restore






/*
 * Is time_t 64 or 32 bits?
 *
 * Default is 32 bits.
 */




/*
 * Do we include math functions that demands lots of constant bytes?
 * (like erf, erfc, expm1, fma, lgamma, tgamma, and *_accurate)
 *
 */




/*
 * Set this to __weak, if supported.
 *
 */
#line 997 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Defaults.h"


/*
 * Deleted options
 *
 */







#line 73 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"











                /* Floating-point */

/*
 * Whenever a floating-point type is equal to another, we try to fold those
 * two types into one. This means that if float == double then we fold float to
 * use double internally. Example sinf(float) will use _Sin(double, uint).
 *
 * _X_FNAME is a redirector for internal support routines. The X can be
 *          D (double), F (float), or L (long double). It redirects by using
 *          another prefix. Example calls to Dtest will be __iar_Dtest,
 *          __iar_FDtest, or __iarLDtest.
 * _X_FUN   is a redirector for functions visible to the customer. As above, the
 *          X can be D, F, or L. It redirects by using another suffix. Example
 *          calls to sin will be sin, sinf, or sinl.
 * _X_TYPE  The type that one type is folded to.
 * _X_PTRCAST is a redirector for a cast operation involving a pointer.
 * _X_CAST  is a redirector for a cast involving the float type.
 *
 * _FLOAT_IS_DOUBLE signals that all internal float routines aren't needed.
 * _LONG_DOUBLE_IS_DOUBLE signals that all internal long double routines
 *                        aren't needed.
 */
#line 147 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"





                /* NAMING PROPERTIES */


/* Has support for fixed point types */




/* Has support for secure functions (printf_s, scanf_s, etc) */
/* Will not compile if enabled */
#line 170 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"

/* Has support for complex C types */




/* If is Embedded C++ language */






/* If is true C++ language */






/* True C++ language setup */
#line 233 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"











                /* NAMESPACE CONTROL */
#line 292 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"









#line 308 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"








#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\xencoding_limits.h"
/* xencoding_limits.h internal header file */
/* Copyright 2003-2010 IAR Systems AB.  */





  #pragma system_include


#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */


  #pragma system_include


/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __AEABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\ycheck.h"

#line 12 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\xencoding_limits.h"
#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"
/* yvals.h internal configuration header file. */
/* Copyright 2001-2010 IAR Systems AB. */

#line 707 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"

/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 13 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\xencoding_limits.h"

                                /* Multibyte encoding length. */


#line 24 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\xencoding_limits.h"




#line 42 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\xencoding_limits.h"

                                /* Utility macro */














#line 317 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"



                /* FLOATING-POINT PROPERTIES */

                /* float properties */
#line 335 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"

                /* double properties */
#line 360 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"

                /* long double properties */
                /* (must be same as double) */




#line 382 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"


                /* INTEGER PROPERTIES */

                                /* MB_LEN_MAX */







  #pragma language=save
  #pragma language=extended
  typedef long long _Longlong;
  typedef unsigned long long _ULonglong;
  #pragma language=restore
#line 405 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"






  typedef unsigned short int _Wchart;
  typedef unsigned short int _Wintt;


#line 424 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"

#line 432 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"

                /* POINTER PROPERTIES */


typedef signed int  _Ptrdifft;
typedef unsigned int     _Sizet;

/* IAR doesn't support restrict  */


                /* stdarg PROPERTIES */
#line 454 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"
  typedef _VA_LIST __Va_list;



__intrinsic __nounwind void __iar_Atexit(void (*)(void));



  typedef struct
  {       /* state of a multibyte translation */
    unsigned int _Wchar;
    unsigned int _State;
  } _Mbstatet;
#line 477 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"










typedef struct
{       /* file position */

  _Longlong _Off;    /* can be system dependent */



  _Mbstatet _Wstate;
} _Fpost;







                /* THREAD AND LOCALE CONTROL */

#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Threads.h"
/***************************************************
 *
 * DLib_Threads.h is the library threads manager.
 *
 * Copyright 2004-2010 IAR Systems AB.  
 *
 * This configuration header file sets up how the thread support in the library
 * should work.
 *
 ***************************************************
 *
 * DO NOT MODIFY THIS FILE!
 *
 ***************************************************/





  #pragma system_include


/*
 * DLib can support a multithreaded environment. The preprocessor symbol 
 * _DLIB_THREAD_SUPPORT governs the support. It can be 0 (no support), 
 * 1 (currently not supported), 2 (locks only), and 3 (simulated TLS and locks).
 */

/*
 * This header sets the following symbols that governs the rest of the
 * library:
 * ------------------------------------------
 * _DLIB_MULTI_THREAD     0 No thread support
 *                        1 Multithread support
 * _DLIB_GLOBAL_VARIABLES 0 Use external TLS interface for the libraries global
 *                          and static variables
 *                        1 Use a lock for accesses to the locale and no 
 *                          security for accesses to other global and static
 *                          variables in the library
 * _DLIB_FILE_OP_LOCKS    0 No file-atomic locks
 *                        1 File-atomic locks

 * _DLIB_COMPILER_TLS     0 No Thread-Local-Storage support in the compiler
 *                        1 Thread-Local-Storage support in the compiler
 * _DLIB_TLS_QUAL         The TLS qualifier, define only if _COMPILER_TLS == 1
 *
 * _DLIB_THREAD_MACRO_SETUP_DONE Whether to use the standard definitions of
 *                               TLS macros defined in xtls.h or the definitions
 *                               are provided here.
 *                        0 Use default macros
 *                        1 Macros defined for xtls.h
 *
 * _DLIB_THREAD_LOCK_ONCE_TYPE
 *                        type for control variable in once-initialization of 
 *                        locks
 * _DLIB_THREAD_LOCK_ONCE_MACRO(control_variable, init_function)
 *                        expression that will be evaluated at each lock access
 *                        to determine if an initialization must be done
 * _DLIB_THREAD_LOCK_ONCE_TYPE_INIT
 *                        initial value for the control variable
 *
 ****************************************************************************
 * Description
 * -----------
 *
 * If locks are to be used (_DLIB_MULTI_THREAD != 0), the following options
 * has to be used in ilink: 
 *   --redirect __iar_Locksyslock=__iar_Locksyslock_mtx
 *   --redirect __iar_Unlocksyslock=__iar_Unlocksyslock_mtx
 *   --redirect __iar_Lockfilelock=__iar_Lockfilelock_mtx
 *   --redirect __iar_Unlockfilelock=__iar_Unlockfilelock_mtx
 *   --keep     __iar_Locksyslock_mtx
 * and, if C++ is used, also:
 *   --redirect __iar_Initdynamicfilelock=__iar_Initdynamicfilelock_mtx
 *   --redirect __iar_Dstdynamicfilelock=__iar_Dstdynamicfilelock_mtx
 *   --redirect __iar_Lockdynamicfilelock=__iar_Lockdynamicfilelock_mtx
 *   --redirect __iar_Unlockdynamicfilelock=__iar_Unlockdynamicfilelock_mtx
 * Xlink uses similar options (-e and -g). The following lock interface must
 * also be implemented: 
 *   typedef void *__iar_Rmtx;                   // Lock info object
 *
 *   void __iar_system_Mtxinit(__iar_Rmtx *);    // Initialize a system lock
 *   void __iar_system_Mtxdst(__iar_Rmtx *);     // Destroy a system lock
 *   void __iar_system_Mtxlock(__iar_Rmtx *);    // Lock a system lock
 *   void __iar_system_Mtxunlock(__iar_Rmtx *);  // Unlock a system lock
 * The interface handles locks for the heap, the locale, the file system
 * structure, the initialization of statics in functions, etc. 
 *
 * The following lock interface is optional to be implemented:
 *   void __iar_file_Mtxinit(__iar_Rmtx *);    // Initialize a file lock
 *   void __iar_file_Mtxdst(__iar_Rmtx *);     // Destroy a file lock
 *   void __iar_file_Mtxlock(__iar_Rmtx *);    // Lock a file lock
 *   void __iar_file_Mtxunlock(__iar_Rmtx *);  // Unlock a file lock
 * The interface handles locks for each file stream.
 * 
 * These three once-initialization symbols must also be defined, if the 
 * default initialization later on in this file doesn't work (done in 
 * DLib_product.h):
 *
 *   _DLIB_THREAD_LOCK_ONCE_TYPE
 *   _DLIB_THREAD_LOCK_ONCE_MACRO(control_variable, init_function)
 *   _DLIB_THREAD_LOCK_ONCE_TYPE_INIT
 *
 * If an external TLS interface is used, the following must
 * be defined:
 *   typedef int __iar_Tlskey_t;
 *   typedef void (*__iar_Tlsdtor_t)(void *);
 *   int __iar_Tlsalloc(__iar_Tlskey_t *, __iar_Tlsdtor_t); 
 *                                                    // Allocate a TLS element
 *   int __iar_Tlsfree(__iar_Tlskey_t);               // Free a TLS element
 *   int __iar_Tlsset(__iar_Tlskey_t, void *);        // Set a TLS element
 *   void *__iar_Tlsget(__iar_Tlskey_t);              // Get a TLS element
 *
 */

/* We don't have a compiler that supports tls declarations */



#line 157 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Threads.h"

  /* Thread support, library supports threaded variables in a user specified
     memory area, locks on heap and on FILE */

  /* See Documentation/ThreadsInternal.html for a description. */





  


#line 176 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Threads.h"





#line 187 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Threads.h"





  #pragma language=save 
  #pragma language=extended
  __intrinsic __nounwind void __iar_dlib_perthread_initialize(void  *);
  __intrinsic __nounwind void  *__iar_dlib_perthread_allocate(void);
  __intrinsic __nounwind void __iar_dlib_perthread_destroy(void);
  __intrinsic __nounwind void __iar_dlib_perthread_deallocate(void  *);









  #pragma segment = "__DLIB_PERTHREAD" 
  #pragma segment = "__DLIB_PERTHREAD_init" 


























#line 242 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Threads.h"

  /* The thread-local variable access function */
  void  *__iar_dlib_perthread_access(void  *);
  #pragma language=restore



























    /* Make sure that each destructor is inserted into _Deallocate_TLS */
  









  /* Internal function declarations. */






  





  
  typedef void *__iar_Rmtx;
  

  
  __intrinsic __nounwind void __iar_system_Mtxinit(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_system_Mtxdst(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_system_Mtxlock(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_system_Mtxunlock(__iar_Rmtx *m);

  __intrinsic __nounwind void __iar_file_Mtxinit(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_file_Mtxdst(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_file_Mtxlock(__iar_Rmtx *m);
  __intrinsic __nounwind void __iar_file_Mtxunlock(__iar_Rmtx *m);

  /* Function to destroy the locks. Should be called after atexit and 
     _Close_all. */
  __intrinsic __nounwind void __iar_clearlocks(void);


#line 323 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Threads.h"

  





  

#line 341 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\DLib_Threads.h"

  typedef unsigned _Once_t;



  













#line 506 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"

#line 516 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"

                /* THREAD-LOCAL STORAGE */
#line 524 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"


                /* MULTITHREAD PROPERTIES */

  
  
  /* The lock interface for DLib to use. */ 
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Locale(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Malloc(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Stream(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Debug(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_StaticGuard(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock(unsigned int);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Locale(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Malloc(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Stream(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Debug(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_StaticGuard(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock(unsigned int);

  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Initdynamicfilelock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Dstdynamicfilelock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Lockdynamicfilelock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlockdynamicfilelock(__iar_Rmtx *);
  
  
#line 564 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"

                /* LOCK MACROS */
#line 572 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"

#line 690 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"

                /* MISCELLANEOUS MACROS AND FUNCTIONS*/





#line 705 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\yvals.h"



/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 12 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\stdint.h"


/* Fixed size types. These are all optional. */

  typedef signed char   int8_t;
  typedef unsigned char uint8_t;



  typedef signed short int   int16_t;
  typedef unsigned short int uint16_t;



  typedef signed int   int32_t;
  typedef unsigned int uint32_t;



  #pragma language=save
  #pragma language=extended
  typedef signed long long int   int64_t;
  typedef unsigned long long int uint64_t;
  #pragma language=restore


/* Types capable of holding at least a certain number of bits.
   These are not optional for the sizes 8, 16, 32, 64. */
typedef signed char   int_least8_t;
typedef unsigned char uint_least8_t;

typedef signed short int   int_least16_t;
typedef unsigned short int uint_least16_t;

typedef signed int   int_least32_t;
typedef unsigned int uint_least32_t;

/* This isn't really optional, but make it so for now. */

  #pragma language=save
  #pragma language=extended
  typedef signed long long int int_least64_t;
  #pragma language=restore


  #pragma language=save
  #pragma language=extended
  typedef unsigned long long int uint_least64_t;
  #pragma language=restore


/* The fastest type holding at least a certain number of bits.
   These are not optional for the size 8, 16, 32, 64.
   For now, the 64 bit size is optional in IAR compilers. */
typedef signed int   int_fast8_t;
typedef unsigned int uint_fast8_t;

typedef signed int   int_fast16_t;
typedef unsigned int uint_fast16_t;

typedef signed int   int_fast32_t;
typedef unsigned int uint_fast32_t;


  #pragma language=save
  #pragma language=extended
  typedef signed long long int int_fast64_t;
  #pragma language=restore


  #pragma language=save
  #pragma language=extended
  typedef unsigned long long int uint_fast64_t;
  #pragma language=restore


/* The integer type capable of holding the largest number of bits. */
#pragma language=save
#pragma language=extended
typedef signed long long int   intmax_t;
typedef unsigned long long int uintmax_t;
#pragma language=restore

/* An integer type large enough to be able to hold a pointer.
   This is optional, but always supported in IAR compilers. */
typedef signed long int   intptr_t;
typedef unsigned long int uintptr_t;

/* An integer capable of holding a pointer to a specific memory type. */



typedef int __data_intptr_t; typedef unsigned int __data_uintptr_t;


/* Minimum and maximum limits. */






























































































/* Macros expanding to integer constants. */

































#line 258 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\stdint.h"

/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 45 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\r_typedefs.h"

/* in case <stdio.h> has defined it. */




/******************************************************************************
Macro definitions
******************************************************************************/











/******************************************************************************
Typedef definitions
******************************************************************************/
//typedef char                char_t;
//typedef unsigned int        bool_t;
//typedef int                 int_t;
//typedef signed char         int8_t;
//typedef signed short        int16_t;
//typedef signed long         int32_t;
//typedef signed long long    int64_t;
//typedef unsigned char       uint8_t;
//typedef unsigned short      uint16_t;
//typedef unsigned long       uint32_t;
//typedef unsigned long long  uint64_t;
//typedef float               float32_t;
//typedef double              float64_t;
//typedef long double         float128_t;

/* R_TYPEDEFS_H */


#line 45 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\src\\intc_handler.c"
/* INTC Driver Header */
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\devdrv_intc.h"
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
/******************************************************************************
* File Name     : devdrv_intc.h
* Device(s)     : RZ/A1H (R7S721001)
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : INTC driver header
******************************************************************************/
/*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*               : 21.03.2014 2.00
*******************************************************************************/

/* Multiple inclusion prevention macro */



/******************************************************************************
Macro definitions
******************************************************************************/
/* ==== Interrupt ID ==== */


#line 560 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\devdrv_intc.h"

/* ==== Interrupt detection ==== */




/******************************************************************************
Variable Externs
******************************************************************************/


/******************************************************************************
Functions Prototypes
******************************************************************************/

/* ==== API functions ==== */
int32_t R_INTC_RegistIntFunc(uint16_t int_id, void (* func)(uint32_t int_sense));

_Pragma("location=\".hardware_init\"") void R_INTC_Init(void);

int32_t R_INTC_Enable(uint16_t int_id);
int32_t R_INTC_Disable(uint16_t int_id);
int32_t R_INTC_SetPriority(uint16_t int_id, uint8_t priority);
int32_t R_INTC_SetMaskLevel(uint8_t mask_level);
void    R_INTC_GetMaskLevel(uint8_t * mask_level);
int32_t R_INTC_GetPendingStatus(uint16_t int_id, uint32_t * icdicpr);
int32_t R_INTC_SetConfiguration(uint16_t int_id, uint32_t int_sense);

/* ==== User-defined functions ==== */
void    Userdef_INTC_RegistIntFunc(uint16_t int_id, void (* func)(uint32_t int_sense));
void    Userdef_INTC_UndefId(uint16_t int_id);
void    Userdef_INTC_HandlerExe(uint16_t int_id, uint32_t int_sense);
void    Userdef_FIQ_HandlerExe(void);



/* End of File */
#line 47 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\src\\intc_handler.c"
/* I/O Register root header */
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : iodefine.h
* $Rev: 1275 $
* $Date:: 2014-11-07 15:16:20 +0900#$
* Description : Definition of I/O Register (V1.01a)
******************************************************************************/




enum iodefine_byte_select_t
{
    L = 0, H = 1,
    LL= 0, LH = 1, HL = 2, HH = 3
};

/***********************************************************************
  <<< [iodefine_reg32_t] >>> 
- Padding : sizeof(iodefine_reg32_t) == 4
- Alignment(Offset) : &UINT32==0, &UINT16[0]==0, &UINT16[1]==2
-                     &UINT8[0]==0, &UINT8[1]==1, &UINT8[2]==2, &UINT8[3]==3
- Endian : Independent (Same as CPU endian as register endian)
- Bit-Order : Independent
************************************************************************/
/* ->MISRA 18.4 : Pack unpack union */ /* ->SEC M1.6.2 */
/* ->SEC M1.10.1 : Not magic number */
union iodefine_reg32_t
{
    volatile uint32_t  UINT32;                                  /*  32-bit Access   */
    volatile uint16_t  UINT16[2];                               /*  16-bit Access   */
    volatile uint8_t   UINT8[4];                                /*  8-bit Access    */
};
/* <-SEC M1.10.1 */
/* <-MISRA 18.4 */ /* <-SEC M1.6.2 */

/***********************************************************************
  <<< [iodefine_reg32_16_t] >>> 
- Padding : sizeof(iodefine_reg32_16_t) == 4
- Alignment(Offset) : &UINT32==0, &UINT16[0]==0, &UINT16[1]==2
- Endian : Independent (Same as CPU endian as register endian)
- Bit-Order : Independent
************************************************************************/
/* ->MISRA 18.4 : Pack unpack union */ /* ->SEC M1.6.2 */
/* ->SEC M1.10.1 : Not magic number */
union iodefine_reg32_16_t
{
    volatile uint32_t  UINT32;                                  /*  32-bit Access   */
    volatile uint16_t  UINT16[2];                               /*  16-bit Access   */
};
/* <-SEC M1.10.1 */
/* <-MISRA 18.4 */ /* <-SEC M1.6.2 */

/***********************************************************************
  <<< [iodefine_reg16_8_t] >>> 
- Padding : sizeof(iodefine_reg16_8_t) == 2
- Alignment(Offset) : &UINT16==0, &UINT8[0]==0, &UINT8[1]==1
- Endian : Independent (Same as CPU endian as register endian)
- Bit-Order : Independent
************************************************************************/
/* ->MISRA 18.4 : Pack unpack union */ /* ->SEC M1.6.2 */
/* ->SEC M1.10.1 : Not magic number */
union iodefine_reg16_8_t
{
    volatile uint16_t  UINT16;                                  /*  16-bit Access   */
    volatile uint8_t   UINT8[2];                                /*  8-bit Access    */
};
/* <-SEC M1.10.1 */
/* <-MISRA 18.4 */ /* <-SEC M1.6.2 */






#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/adc_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : adc_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_adc
{                                                          /* ADC              */
    volatile uint16_t ADDRA;                                  /*  ADDRA           */
    volatile uint16_t ADDRB;                                  /*  ADDRB           */
    volatile uint16_t ADDRC;                                  /*  ADDRC           */
    volatile uint16_t ADDRD;                                  /*  ADDRD           */
    volatile uint16_t ADDRE;                                  /*  ADDRE           */
    volatile uint16_t ADDRF;                                  /*  ADDRF           */
    volatile uint16_t ADDRG;                                  /*  ADDRG           */
    volatile uint16_t ADDRH;                                  /*  ADDRH           */
    volatile uint8_t   dummy32[16];                            /*                  */
    volatile uint16_t ADCMPHA;                                /*  ADCMPHA         */
    volatile uint16_t ADCMPLA;                                /*  ADCMPLA         */
    volatile uint16_t ADCMPHB;                                /*  ADCMPHB         */
    volatile uint16_t ADCMPLB;                                /*  ADCMPLB         */
    volatile uint16_t ADCMPHC;                                /*  ADCMPHC         */
    volatile uint16_t ADCMPLC;                                /*  ADCMPLC         */
    volatile uint16_t ADCMPHD;                                /*  ADCMPHD         */
    volatile uint16_t ADCMPLD;                                /*  ADCMPLD         */
    volatile uint16_t ADCMPHE;                                /*  ADCMPHE         */
    volatile uint16_t ADCMPLE;                                /*  ADCMPLE         */
    volatile uint16_t ADCMPHF;                                /*  ADCMPHF         */
    volatile uint16_t ADCMPLF;                                /*  ADCMPLF         */
    volatile uint16_t ADCMPHG;                                /*  ADCMPHG         */
    volatile uint16_t ADCMPLG;                                /*  ADCMPLG         */
    volatile uint16_t ADCMPHH;                                /*  ADCMPHH         */
    volatile uint16_t ADCMPLH;                                /*  ADCMPLH         */
    volatile uint8_t   dummy33[32];                            /*                  */
    volatile uint16_t ADCSR;                                  /*  ADCSR           */
    volatile uint16_t ADCMPER;                                /*  ADCMPER         */
    volatile uint16_t ADCMPSR;                                /*  ADCMPSR         */
};





#line 97 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/adc_iodefine.h"
/* <-SEC M1.10.1 */
#line 98 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/bsc_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : bsc_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_bsc
{                                                          /* BSC              */
    volatile uint32_t  CMNCR;                                  /*  CMNCR           */

    volatile uint32_t  CS0BCR;                                 /*  CS0BCR          */
    volatile uint32_t  CS1BCR;                                 /*  CS1BCR          */
    volatile uint32_t  CS2BCR;                                 /*  CS2BCR          */
    volatile uint32_t  CS3BCR;                                 /*  CS3BCR          */
    volatile uint32_t  CS4BCR;                                 /*  CS4BCR          */
    volatile uint32_t  CS5BCR;                                 /*  CS5BCR          */
    volatile uint8_t   dummy4[12];                             /*                  */

    volatile uint32_t  CS0WCR;                                 /*  CS0WCR          */
    volatile uint32_t  CS1WCR;                                 /*  CS1WCR          */
    volatile uint32_t  CS2WCR;                                 /*  CS2WCR          */
    volatile uint32_t  CS3WCR;                                 /*  CS3WCR          */
    volatile uint32_t  CS4WCR;                                 /*  CS4WCR          */
    volatile uint32_t  CS5WCR;                                 /*  CS5WCR          */
    volatile uint8_t   dummy5[12];                             /*                  */
    volatile uint32_t  SDCR;                                   /*  SDCR            */
    volatile uint32_t  RTCSR;                                  /*  RTCSR           */
    volatile uint32_t  RTCNT;                                  /*  RTCNT           */
    volatile uint32_t  RTCOR;                                  /*  RTCOR           */
    volatile uint8_t   dummy6[4];                              /*                  */

    volatile uint32_t  TOSCOR0;                                /*  TOSCOR0         */
    volatile uint32_t  TOSCOR1;                                /*  TOSCOR1         */
    volatile uint32_t  TOSCOR2;                                /*  TOSCOR2         */
    volatile uint32_t  TOSCOR3;                                /*  TOSCOR3         */
    volatile uint32_t  TOSCOR4;                                /*  TOSCOR4         */
    volatile uint32_t  TOSCOR5;                                /*  TOSCOR5         */
    volatile uint8_t   dummy7[8];                              /*                  */
    volatile uint32_t  TOSTR;                                  /*  TOSTR           */
    volatile uint32_t  TOENR;                                  /*  TOENR           */
};





#line 98 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/bsc_iodefine.h"
/* <-SEC M1.10.1 */
#line 99 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/ceu_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : ceu_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_ceu
{                                                          /* CEU              */
/* start of struct st_ceu_n */
    volatile uint32_t  CAPSR;                                  /*  CAPSR           */
    volatile uint32_t  CAPCR;                                  /*  CAPCR           */
    volatile uint32_t  CAMCR;                                  /*  CAMCR           */
    volatile uint32_t  CMCYR;                                  /*  CMCYR           */
    volatile uint32_t  CAMOR_A;                                /*  CAMOR_A         */
    volatile uint32_t  CAPWR_A;                                /*  CAPWR_A         */
    volatile uint32_t  CAIFR;                                  /*  CAIFR           */
    volatile uint8_t   dummy305[12];                           /*                  */
    volatile uint32_t  CRCNTR;                                 /*  CRCNTR          */
    volatile uint32_t  CRCMPR;                                 /*  CRCMPR          */
    volatile uint32_t  CFLCR_A;                                /*  CFLCR_A         */
    volatile uint32_t  CFSZR_A;                                /*  CFSZR_A         */
    volatile uint32_t  CDWDR_A;                                /*  CDWDR_A         */
    volatile uint32_t  CDAYR_A;                                /*  CDAYR_A         */
    volatile uint32_t  CDACR_A;                                /*  CDACR_A         */
    volatile uint32_t  CDBYR_A;                                /*  CDBYR_A         */
    volatile uint32_t  CDBCR_A;                                /*  CDBCR_A         */
    volatile uint32_t  CBDSR_A;                                /*  CBDSR_A         */
    volatile uint8_t   dummy306[12];                           /*                  */
    volatile uint32_t  CFWCR;                                  /*  CFWCR           */
    volatile uint32_t  CLFCR_A;                                /*  CLFCR_A         */
    volatile uint32_t  CDOCR_A;                                /*  CDOCR_A         */
    volatile uint8_t   dummy307[8];                            /*                  */
    volatile uint32_t  CEIER;                                  /*  CEIER           */
    volatile uint32_t  CETCR;                                  /*  CETCR           */
    volatile uint8_t   dummy308[4];                            /*                  */
    volatile uint32_t  CSTSR;                                  /*  CSTSR           */
    volatile uint8_t   dummy309[4];                            /*                  */
    volatile uint32_t  CDSSR;                                  /*  CDSSR           */
    volatile uint8_t   dummy310[8];                            /*                  */
    volatile uint32_t  CDAYR2_A;                               /*  CDAYR2_A        */
    volatile uint32_t  CDACR2_A;                               /*  CDACR2_A        */
    volatile uint32_t  CDBYR2_A;                               /*  CDBYR2_A        */
    volatile uint32_t  CDBCR2_A;                               /*  CDBCR2_A        */
/* end of struct st_ceu_n */
    volatile uint8_t   dummy3110[3936];                        /*                  */
/* start of struct st_ceu_n */
    volatile uint8_t   dummy3111[4];                           /*                  */
    volatile uint8_t   dummy3112[4];                           /*                  */
    volatile uint8_t   dummy3113[4];                           /*                  */
    volatile uint8_t   dummy3114[4];                           /*                  */
    volatile uint32_t  CAMOR_B;                                /*  CAMOR_B         */
    volatile uint32_t  CAPWR_B;                                /*  CAPWR_B         */
    volatile uint8_t   dummy3120[4];                           /*                  */
    volatile uint8_t   dummy3121[12];                          /*                  */
    volatile uint8_t   dummy3122[4];                           /*                  */
    volatile uint8_t   dummy3123[4];                           /*                  */
    volatile uint32_t  CFLCR_B;                                /*  CFLCR_B         */
    volatile uint32_t  CFSZR_B;                                /*  CFSZR_B         */
    volatile uint32_t  CDWDR_B;                                /*  CDWDR_B         */
    volatile uint32_t  CDAYR_B;                                /*  CDAYR_B         */
    volatile uint32_t  CDACR_B;                                /*  CDACR_B         */
    volatile uint32_t  CDBYR_B;                                /*  CDBYR_B         */
    volatile uint32_t  CDBCR_B;                                /*  CDBCR_B         */
    volatile uint32_t  CBDSR_B;                                /*  CBDSR_B         */
    volatile uint8_t   dummy3130[12];                          /*                  */
    volatile uint8_t   dummy3131[4];                           /*                  */
    volatile uint32_t  CLFCR_B;                                /*  CLFCR_B         */
    volatile uint32_t  CDOCR_B;                                /*  CDOCR_B         */
    volatile uint8_t   dummy3140[8];                           /*                  */
    volatile uint8_t   dummy3141[4];                           /*                  */
    volatile uint8_t   dummy3142[4];                           /*                  */
    volatile uint8_t   dummy3143[4];                           /*                  */
    volatile uint8_t   dummy3144[4];                           /*                  */
    volatile uint8_t   dummy3145[4];                           /*                  */
    volatile uint8_t   dummy3146[4];                           /*                  */
    volatile uint8_t   dummy3147[8];                           /*                  */
    volatile uint32_t  CDAYR2_B;                               /*  CDAYR2_B        */
    volatile uint32_t  CDACR2_B;                               /*  CDACR2_B        */
    volatile uint32_t  CDBYR2_B;                               /*  CDBYR2_B        */
    volatile uint32_t  CDBCR2_B;                               /*  CDBCR2_B        */
/* end of struct st_ceu_n */
    volatile uint8_t   dummy3150[3936];                        /*                  */
/* start of struct st_ceu_n */
    volatile uint8_t   dummy3151[4];                           /*                  */
    volatile uint8_t   dummy3152[4];                           /*                  */
    volatile uint8_t   dummy3153[4];                           /*                  */
    volatile uint8_t   dummy3154[4];                           /*                  */
    volatile uint32_t  CAMOR_M;                                /*  CAMOR_M         */
    volatile uint32_t  CAPWR_M;                                /*  CAPWR_M         */
    volatile uint8_t   dummy3160[4];                           /*                  */
    volatile uint8_t   dummy3161[12];                          /*                  */
    volatile uint8_t   dummy3162[4];                           /*                  */
    volatile uint8_t   dummy3163[4];                           /*                  */
    volatile uint32_t  CFLCR_M;                                /*  CFLCR_M         */
    volatile uint32_t  CFSZR_M;                                /*  CFSZR_M         */
    volatile uint32_t  CDWDR_M;                                /*  CDWDR_M         */
    volatile uint32_t  CDAYR_M;                                /*  CDAYR_M         */
    volatile uint32_t  CDACR_M;                                /*  CDACR_M         */
    volatile uint32_t  CDBYR_M;                                /*  CDBYR_M         */
    volatile uint32_t  CDBCR_M;                                /*  CDBCR_M         */
    volatile uint32_t  CBDSR_M;                                /*  CBDSR_M         */
    volatile uint8_t   dummy3170[12];                          /*                  */
    volatile uint8_t   dummy3171[4];                           /*                  */
    volatile uint32_t  CLFCR_M;                                /*  CLFCR_M         */
    volatile uint32_t  CDOCR_M;                                /*  CDOCR_M         */
    volatile uint8_t   dummy3180[8];                           /*                  */
    volatile uint8_t   dummy3181[4];                           /*                  */
    volatile uint8_t   dummy3182[4];                           /*                  */
    volatile uint8_t   dummy3183[4];                           /*                  */
    volatile uint8_t   dummy3184[4];                           /*                  */
    volatile uint8_t   dummy3185[4];                           /*                  */
    volatile uint8_t   dummy3186[4];                           /*                  */
    volatile uint8_t   dummy3187[8];                           /*                  */
    volatile uint32_t  CDAYR2_M;                               /*  CDAYR2_M        */
    volatile uint32_t  CDACR2_M;                               /*  CDACR2_M        */
    volatile uint32_t  CDBYR2_M;                               /*  CDBYR2_M        */
    volatile uint32_t  CDBCR2_M;                               /*  CDBCR2_M        */
/* end of struct st_ceu_n */
};


struct st_ceu_n
{
    volatile uint32_t  not_common1;                            /*                  */
    volatile uint32_t  not_common2;                            /*                  */
    volatile uint32_t  not_common3;                            /*                  */
    volatile uint32_t  not_common4;                            /*                  */
    volatile uint32_t  CAMOR;                                  /*  CAMOR           */
    volatile uint32_t  CAPWR;                                  /*  CAPWR           */
    volatile uint32_t  not_common5;                            /*                  */
    volatile uint8_t   dummy322[12];                           /*                  */
    volatile uint32_t  not_common6;                            /*                  */
    volatile uint32_t  not_common7;                            /*                  */
    volatile uint32_t  CFLCR;                                  /*  CFLCR           */
    volatile uint32_t  CFSZR;                                  /*  CFSZR           */
    volatile uint32_t  CDWDR;                                  /*  CDWDR           */
    volatile uint32_t  CDAYR;                                  /*  CDAYR           */
    volatile uint32_t  CDACR;                                  /*  CDACR           */
    volatile uint32_t  CDBYR;                                  /*  CDBYR           */
    volatile uint32_t  CDBCR;                                  /*  CDBCR           */
    volatile uint32_t  CBDSR;                                  /*  CBDSR           */
    volatile uint8_t   dummy323[12];                           /*                  */
    volatile uint32_t  not_common8;                            /*                  */
    volatile uint32_t  CLFCR;                                  /*  CLFCR           */
    volatile uint32_t  CDOCR;                                  /*  CDOCR           */
    volatile uint8_t   dummy324[8];                            /*                  */
    volatile uint32_t  not_common9;                            /*                  */
    volatile uint32_t  not_common10;                           /*                  */
    volatile uint8_t   dummy325[4];                            /*                  */
    volatile uint32_t  not_common11;                           /*                  */
    volatile uint8_t   dummy326[4];                            /*                  */
    volatile uint32_t  not_common12;                           /*                  */
    volatile uint8_t   dummy327[8];                            /*                  */
    volatile uint32_t  CDAYR2;                                 /*  CDAYR2          */
    volatile uint32_t  CDACR2;                                 /*  CDACR2          */
    volatile uint32_t  CDBYR2;                                 /*  CDBYR2          */
    volatile uint32_t  CDBCR2;                                 /*  CDBCR2          */
};





/* Start of channnel array defines of CEU */

/* Channnel array defines of CEUn */
/*(Sample) value = CEUn[ channel ]->CAMOR; */
#line 204 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/ceu_iodefine.h"

/* End of channnel array defines of CEU */


#line 268 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/ceu_iodefine.h"
/* <-SEC M1.10.1 */
#line 100 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/cpg_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : cpg_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_cpg
{                                                          /* CPG              */
    volatile uint16_t FRQCR;                                  /*  FRQCR           */
    volatile uint8_t   dummy319[2];                            /*                  */
    volatile uint16_t FRQCR2;                                 /*  FRQCR2          */
    volatile uint8_t   dummy320[2];                            /*                  */
    volatile uint8_t   CPUSTS;                                 /*  CPUSTS          */
    volatile uint8_t   dummy321[7];                            /*                  */
    volatile uint8_t   STBCR1;                                 /*  STBCR1          */
    volatile uint8_t   dummy322[3];                            /*                  */
    volatile uint8_t   STBCR2;                                 /*  STBCR2          */
    volatile uint8_t   dummy323[11];                           /*                  */
    volatile uint8_t   STBREQ1;                                /*  STBREQ1         */
    volatile uint8_t   dummy324[3];                            /*                  */
    volatile uint8_t   STBREQ2;                                /*  STBREQ2         */
    volatile uint8_t   dummy325[11];                           /*                  */
    volatile uint8_t   STBACK1;                                /*  STBACK1         */
    volatile uint8_t   dummy326[3];                            /*                  */
    volatile uint8_t   STBACK2;                                /*  STBACK2         */
    volatile uint8_t   dummy327[955];                          /*                  */
/* start of struct st_cpg_from_syscr1 */
    volatile uint8_t   SYSCR1;                                 /*  SYSCR1          */
    volatile uint8_t   dummy328[3];                            /*                  */
/* end of struct st_cpg_from_syscr1 */
/* start of struct st_cpg_from_syscr1 */
    volatile uint8_t   SYSCR2;                                 /*  SYSCR2          */
    volatile uint8_t   dummy329[3];                            /*                  */
/* end of struct st_cpg_from_syscr1 */
/* start of struct st_cpg_from_syscr1 */
    volatile uint8_t   SYSCR3;                                 /*  SYSCR3          */
    volatile uint8_t   dummy3300[3];                           /*                  */
/* end of struct st_cpg_from_syscr1 */
    volatile uint8_t   dummy3301[20];                          /*                  */
/* start of struct st_cpg_from_stbcr3 */
    volatile uint8_t   STBCR3;                                 /*  STBCR3          */
    volatile uint8_t   dummy331[3];                            /*                  */
/* end of struct st_cpg_from_stbcr3 */
/* start of struct st_cpg_from_stbcr3 */
    volatile uint8_t   STBCR4;                                 /*  STBCR4          */
    volatile uint8_t   dummy332[3];                            /*                  */
/* end of struct st_cpg_from_stbcr3 */
/* start of struct st_cpg_from_stbcr3 */
    volatile uint8_t   STBCR5;                                 /*  STBCR5          */
    volatile uint8_t   dummy333[3];                            /*                  */
/* end of struct st_cpg_from_stbcr3 */
/* start of struct st_cpg_from_stbcr3 */
    volatile uint8_t   STBCR6;                                 /*  STBCR6          */
    volatile uint8_t   dummy334[3];                            /*                  */
/* end of struct st_cpg_from_stbcr3 */
/* start of struct st_cpg_from_stbcr3 */
    volatile uint8_t   STBCR7;                                 /*  STBCR7          */
    volatile uint8_t   dummy335[3];                            /*                  */
/* end of struct st_cpg_from_stbcr3 */
/* start of struct st_cpg_from_stbcr3 */
    volatile uint8_t   STBCR8;                                 /*  STBCR8          */
    volatile uint8_t   dummy336[3];                            /*                  */
/* end of struct st_cpg_from_stbcr3 */
/* start of struct st_cpg_from_stbcr3 */
    volatile uint8_t   STBCR9;                                 /*  STBCR9          */
    volatile uint8_t   dummy337[3];                            /*                  */
/* end of struct st_cpg_from_stbcr3 */
/* start of struct st_cpg_from_stbcr3 */
    volatile uint8_t   STBCR10;                                /*  STBCR10         */
    volatile uint8_t   dummy338[3];                            /*                  */
/* end of struct st_cpg_from_stbcr3 */
/* start of struct st_cpg_from_stbcr3 */
    volatile uint8_t   STBCR11;                                /*  STBCR11         */
    volatile uint8_t   dummy339[3];                            /*                  */
/* end of struct st_cpg_from_stbcr3 */
/* start of struct st_cpg_from_stbcr3 */
    volatile uint8_t   STBCR12;                                /*  STBCR12         */
    volatile uint8_t   dummy3400[3];                           /*                  */
/* end of struct st_cpg_from_stbcr3 */
    volatile uint8_t   dummy3401[24];                          /*                  */
/* start of struct st_cpg_from_swrstcr1 */
    volatile uint8_t   SWRSTCR1;                               /*  SWRSTCR1        */
    volatile uint8_t   dummy341[3];                            /*                  */
/* end of struct st_cpg_from_swrstcr1 */
/* start of struct st_cpg_from_swrstcr1 */
    volatile uint8_t   SWRSTCR2;                               /*  SWRSTCR2        */
    volatile uint8_t   dummy342[3];                            /*                  */
/* end of struct st_cpg_from_swrstcr1 */
/* start of struct st_cpg_from_swrstcr1 */
    volatile uint8_t   SWRSTCR3;                               /*  SWRSTCR3        */
    volatile uint8_t   dummy3430[3];                           /*                  */
/* end of struct st_cpg_from_swrstcr1 */
    volatile uint8_t   dummy3431[4];                           /*                  */
    volatile uint8_t   STBCR13;                                /*  STBCR13         */
    volatile uint8_t   dummy344[70543];                        /*                  */
    volatile uint8_t   RRAMKP;                                 /*  RRAMKP          */
    volatile uint8_t   dummy345[1];                            /*                  */
    volatile uint8_t   DSCTR;                                  /*  DSCTR           */
    volatile uint8_t   dummy346[1];                            /*                  */
    volatile uint16_t DSSSR;                                  /*  DSSSR           */
    volatile uint16_t DSESR;                                  /*  DSESR           */
    volatile uint16_t DSFR;                                   /*  DSFR            */
    volatile uint8_t   dummy347[6];                            /*                  */
    volatile uint8_t   XTALCTR;                                /*  XTALCTR         */
};


struct st_cpg_from_syscr1
{
    volatile uint8_t   SYSCR1;                                 /*  SYSCR1          */
    volatile uint8_t   dummy1[3];                              /*                  */
};


struct st_cpg_from_stbcr3
{
    volatile uint8_t   STBCR3;                                 /*  STBCR3          */
    volatile uint8_t   dummy1[3];                              /*                  */
};


struct st_cpg_from_swrstcr1
{
    volatile uint8_t   SWRSTCR1;                               /*  SWRSTCR1        */
    volatile uint8_t   dummy1[3];                              /*                  */
};





/* Start of channnel array defines of CPG */

/* Channnel array defines of CPG_FROM_SWRSTCR1_ARRAY */
/*(Sample) value = CPG_FROM_SWRSTCR1_ARRAY[ channel ]->SWRSTCR1; */
#line 170 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/cpg_iodefine.h"


/* Channnel array defines of CPG_FROM_STBCR3_ARRAY */
/*(Sample) value = CPG_FROM_STBCR3_ARRAY[ channel ]->STBCR3; */
#line 190 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/cpg_iodefine.h"


/* Channnel array defines of CPG_FROM_SYSCR1_ARRAY */
/*(Sample) value = CPG_FROM_SYSCR1_ARRAY[ channel ]->SYSCR1; */
#line 202 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/cpg_iodefine.h"

/* End of channnel array defines of CPG */


#line 238 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/cpg_iodefine.h"
/* <-SEC M1.10.1 */
#line 101 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/disc_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : disc_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_disc
{                                                          /* DISC             */
    volatile uint32_t  DOCMCR;                                 /*  DOCMCR          */
    volatile uint32_t  DOCMSTR;                                /*  DOCMSTR         */
    volatile uint32_t  DOCMCLSTR;                              /*  DOCMCLSTR       */
    volatile uint32_t  DOCMIENR;                               /*  DOCMIENR        */
    volatile uint8_t   dummy1[4];                              /*                  */
    volatile uint32_t  DOCMPMR;                                /*  DOCMPMR         */
    volatile uint32_t  DOCMECRCR;                              /*  DOCMECRCR       */
    volatile uint32_t  DOCMCCRCR;                              /*  DOCMCCRCR       */
    volatile uint32_t  DOCMSPXR;                               /*  DOCMSPXR        */
    volatile uint32_t  DOCMSPYR;                               /*  DOCMSPYR        */
    volatile uint32_t  DOCMSZXR;                               /*  DOCMSZXR        */
    volatile uint32_t  DOCMSZYR;                               /*  DOCMSZYR        */
    volatile uint32_t  DOCMCRCIR;                              /*  DOCMCRCIR       */
};






/* Start of channnel array defines of DISC */

/* Channnel array defines of DISC */
/*(Sample) value = DISC[ channel ]->DOCMCR; */






/* End of channnel array defines of DISC */


#line 92 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/disc_iodefine.h"
/* <-SEC M1.10.1 */
#line 102 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/dmac_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : dmac_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->QAC 0639 : Over 127 members (C90) */
/* ->SEC M1.10.1 : Not magic number */

struct st_dmac
{                                                          /* DMAC             */
/* start of struct st_dmac_n */
    volatile uint32_t  N0SA_0;                                 /*  N0SA_0          */
    volatile uint32_t  N0DA_0;                                 /*  N0DA_0          */
    volatile uint32_t  N0TB_0;                                 /*  N0TB_0          */
    volatile uint32_t  N1SA_0;                                 /*  N1SA_0          */
    volatile uint32_t  N1DA_0;                                 /*  N1DA_0          */
    volatile uint32_t  N1TB_0;                                 /*  N1TB_0          */
    volatile uint32_t  CRSA_0;                                 /*  CRSA_0          */
    volatile uint32_t  CRDA_0;                                 /*  CRDA_0          */
    volatile uint32_t  CRTB_0;                                 /*  CRTB_0          */
    volatile uint32_t  CHSTAT_0;                               /*  CHSTAT_0        */
    volatile uint32_t  CHCTRL_0;                               /*  CHCTRL_0        */
    volatile uint32_t  CHCFG_0;                                /*  CHCFG_0         */
    volatile uint32_t  CHITVL_0;                               /*  CHITVL_0        */
    volatile uint32_t  CHEXT_0;                                /*  CHEXT_0         */
    volatile uint32_t  NXLA_0;                                 /*  NXLA_0          */
    volatile uint32_t  CRLA_0;                                 /*  CRLA_0          */
/* end of struct st_dmac_n */
/* start of struct st_dmac_n */
    volatile uint32_t  N0SA_1;                                 /*  N0SA_1          */
    volatile uint32_t  N0DA_1;                                 /*  N0DA_1          */
    volatile uint32_t  N0TB_1;                                 /*  N0TB_1          */
    volatile uint32_t  N1SA_1;                                 /*  N1SA_1          */
    volatile uint32_t  N1DA_1;                                 /*  N1DA_1          */
    volatile uint32_t  N1TB_1;                                 /*  N1TB_1          */
    volatile uint32_t  CRSA_1;                                 /*  CRSA_1          */
    volatile uint32_t  CRDA_1;                                 /*  CRDA_1          */
    volatile uint32_t  CRTB_1;                                 /*  CRTB_1          */
    volatile uint32_t  CHSTAT_1;                               /*  CHSTAT_1        */
    volatile uint32_t  CHCTRL_1;                               /*  CHCTRL_1        */
    volatile uint32_t  CHCFG_1;                                /*  CHCFG_1         */
    volatile uint32_t  CHITVL_1;                               /*  CHITVL_1        */
    volatile uint32_t  CHEXT_1;                                /*  CHEXT_1         */
    volatile uint32_t  NXLA_1;                                 /*  NXLA_1          */
    volatile uint32_t  CRLA_1;                                 /*  CRLA_1          */
/* end of struct st_dmac_n */
/* start of struct st_dmac_n */
    volatile uint32_t  N0SA_2;                                 /*  N0SA_2          */
    volatile uint32_t  N0DA_2;                                 /*  N0DA_2          */
    volatile uint32_t  N0TB_2;                                 /*  N0TB_2          */
    volatile uint32_t  N1SA_2;                                 /*  N1SA_2          */
    volatile uint32_t  N1DA_2;                                 /*  N1DA_2          */
    volatile uint32_t  N1TB_2;                                 /*  N1TB_2          */
    volatile uint32_t  CRSA_2;                                 /*  CRSA_2          */
    volatile uint32_t  CRDA_2;                                 /*  CRDA_2          */
    volatile uint32_t  CRTB_2;                                 /*  CRTB_2          */
    volatile uint32_t  CHSTAT_2;                               /*  CHSTAT_2        */
    volatile uint32_t  CHCTRL_2;                               /*  CHCTRL_2        */
    volatile uint32_t  CHCFG_2;                                /*  CHCFG_2         */
    volatile uint32_t  CHITVL_2;                               /*  CHITVL_2        */
    volatile uint32_t  CHEXT_2;                                /*  CHEXT_2         */
    volatile uint32_t  NXLA_2;                                 /*  NXLA_2          */
    volatile uint32_t  CRLA_2;                                 /*  CRLA_2          */
/* end of struct st_dmac_n */
/* start of struct st_dmac_n */
    volatile uint32_t  N0SA_3;                                 /*  N0SA_3          */
    volatile uint32_t  N0DA_3;                                 /*  N0DA_3          */
    volatile uint32_t  N0TB_3;                                 /*  N0TB_3          */
    volatile uint32_t  N1SA_3;                                 /*  N1SA_3          */
    volatile uint32_t  N1DA_3;                                 /*  N1DA_3          */
    volatile uint32_t  N1TB_3;                                 /*  N1TB_3          */
    volatile uint32_t  CRSA_3;                                 /*  CRSA_3          */
    volatile uint32_t  CRDA_3;                                 /*  CRDA_3          */
    volatile uint32_t  CRTB_3;                                 /*  CRTB_3          */
    volatile uint32_t  CHSTAT_3;                               /*  CHSTAT_3        */
    volatile uint32_t  CHCTRL_3;                               /*  CHCTRL_3        */
    volatile uint32_t  CHCFG_3;                                /*  CHCFG_3         */
    volatile uint32_t  CHITVL_3;                               /*  CHITVL_3        */
    volatile uint32_t  CHEXT_3;                                /*  CHEXT_3         */
    volatile uint32_t  NXLA_3;                                 /*  NXLA_3          */
    volatile uint32_t  CRLA_3;                                 /*  CRLA_3          */
/* end of struct st_dmac_n */
/* start of struct st_dmac_n */
    volatile uint32_t  N0SA_4;                                 /*  N0SA_4          */
    volatile uint32_t  N0DA_4;                                 /*  N0DA_4          */
    volatile uint32_t  N0TB_4;                                 /*  N0TB_4          */
    volatile uint32_t  N1SA_4;                                 /*  N1SA_4          */
    volatile uint32_t  N1DA_4;                                 /*  N1DA_4          */
    volatile uint32_t  N1TB_4;                                 /*  N1TB_4          */
    volatile uint32_t  CRSA_4;                                 /*  CRSA_4          */
    volatile uint32_t  CRDA_4;                                 /*  CRDA_4          */
    volatile uint32_t  CRTB_4;                                 /*  CRTB_4          */
    volatile uint32_t  CHSTAT_4;                               /*  CHSTAT_4        */
    volatile uint32_t  CHCTRL_4;                               /*  CHCTRL_4        */
    volatile uint32_t  CHCFG_4;                                /*  CHCFG_4         */
    volatile uint32_t  CHITVL_4;                               /*  CHITVL_4        */
    volatile uint32_t  CHEXT_4;                                /*  CHEXT_4         */
    volatile uint32_t  NXLA_4;                                 /*  NXLA_4          */
    volatile uint32_t  CRLA_4;                                 /*  CRLA_4          */
/* end of struct st_dmac_n */
/* start of struct st_dmac_n */
    volatile uint32_t  N0SA_5;                                 /*  N0SA_5          */
    volatile uint32_t  N0DA_5;                                 /*  N0DA_5          */
    volatile uint32_t  N0TB_5;                                 /*  N0TB_5          */
    volatile uint32_t  N1SA_5;                                 /*  N1SA_5          */
    volatile uint32_t  N1DA_5;                                 /*  N1DA_5          */
    volatile uint32_t  N1TB_5;                                 /*  N1TB_5          */
    volatile uint32_t  CRSA_5;                                 /*  CRSA_5          */
    volatile uint32_t  CRDA_5;                                 /*  CRDA_5          */
    volatile uint32_t  CRTB_5;                                 /*  CRTB_5          */
    volatile uint32_t  CHSTAT_5;                               /*  CHSTAT_5        */
    volatile uint32_t  CHCTRL_5;                               /*  CHCTRL_5        */
    volatile uint32_t  CHCFG_5;                                /*  CHCFG_5         */
    volatile uint32_t  CHITVL_5;                               /*  CHITVL_5        */
    volatile uint32_t  CHEXT_5;                                /*  CHEXT_5         */
    volatile uint32_t  NXLA_5;                                 /*  NXLA_5          */
    volatile uint32_t  CRLA_5;                                 /*  CRLA_5          */
/* end of struct st_dmac_n */
/* start of struct st_dmac_n */
    volatile uint32_t  N0SA_6;                                 /*  N0SA_6          */
    volatile uint32_t  N0DA_6;                                 /*  N0DA_6          */
    volatile uint32_t  N0TB_6;                                 /*  N0TB_6          */
    volatile uint32_t  N1SA_6;                                 /*  N1SA_6          */
    volatile uint32_t  N1DA_6;                                 /*  N1DA_6          */
    volatile uint32_t  N1TB_6;                                 /*  N1TB_6          */
    volatile uint32_t  CRSA_6;                                 /*  CRSA_6          */
    volatile uint32_t  CRDA_6;                                 /*  CRDA_6          */
    volatile uint32_t  CRTB_6;                                 /*  CRTB_6          */
    volatile uint32_t  CHSTAT_6;                               /*  CHSTAT_6        */
    volatile uint32_t  CHCTRL_6;                               /*  CHCTRL_6        */
    volatile uint32_t  CHCFG_6;                                /*  CHCFG_6         */
    volatile uint32_t  CHITVL_6;                               /*  CHITVL_6        */
    volatile uint32_t  CHEXT_6;                                /*  CHEXT_6         */
    volatile uint32_t  NXLA_6;                                 /*  NXLA_6          */
    volatile uint32_t  CRLA_6;                                 /*  CRLA_6          */
/* end of struct st_dmac_n */
/* start of struct st_dmac_n */
    volatile uint32_t  N0SA_7;                                 /*  N0SA_7          */
    volatile uint32_t  N0DA_7;                                 /*  N0DA_7          */
    volatile uint32_t  N0TB_7;                                 /*  N0TB_7          */
    volatile uint32_t  N1SA_7;                                 /*  N1SA_7          */
    volatile uint32_t  N1DA_7;                                 /*  N1DA_7          */
    volatile uint32_t  N1TB_7;                                 /*  N1TB_7          */
    volatile uint32_t  CRSA_7;                                 /*  CRSA_7          */
    volatile uint32_t  CRDA_7;                                 /*  CRDA_7          */
    volatile uint32_t  CRTB_7;                                 /*  CRTB_7          */
    volatile uint32_t  CHSTAT_7;                               /*  CHSTAT_7        */
    volatile uint32_t  CHCTRL_7;                               /*  CHCTRL_7        */
    volatile uint32_t  CHCFG_7;                                /*  CHCFG_7         */
    volatile uint32_t  CHITVL_7;                               /*  CHITVL_7        */
    volatile uint32_t  CHEXT_7;                                /*  CHEXT_7         */
    volatile uint32_t  NXLA_7;                                 /*  NXLA_7          */
    volatile uint32_t  CRLA_7;                                 /*  CRLA_7          */
/* end of struct st_dmac_n */
    volatile uint8_t   dummy187[256];                          /*                  */
/* start of struct st_dmaccommon_n */
    volatile uint32_t  DCTRL_0_7;                              /*  DCTRL_0_7       */
    volatile uint8_t   dummy188[12];                           /*                  */
    volatile uint32_t  DSTAT_EN_0_7;                           /*  DSTAT_EN_0_7    */
    volatile uint32_t  DSTAT_ER_0_7;                           /*  DSTAT_ER_0_7    */
    volatile uint32_t  DSTAT_END_0_7;                          /*  DSTAT_END_0_7   */
    volatile uint32_t  DSTAT_TC_0_7;                           /*  DSTAT_TC_0_7    */
    volatile uint32_t  DSTAT_SUS_0_7;                          /*  DSTAT_SUS_0_7   */
/* end of struct st_dmaccommon_n */
    volatile uint8_t   dummy189[220];                          /*                  */
/* start of struct st_dmac_n */
    volatile uint32_t  N0SA_8;                                 /*  N0SA_8          */
    volatile uint32_t  N0DA_8;                                 /*  N0DA_8          */
    volatile uint32_t  N0TB_8;                                 /*  N0TB_8          */
    volatile uint32_t  N1SA_8;                                 /*  N1SA_8          */
    volatile uint32_t  N1DA_8;                                 /*  N1DA_8          */
    volatile uint32_t  N1TB_8;                                 /*  N1TB_8          */
    volatile uint32_t  CRSA_8;                                 /*  CRSA_8          */
    volatile uint32_t  CRDA_8;                                 /*  CRDA_8          */
    volatile uint32_t  CRTB_8;                                 /*  CRTB_8          */
    volatile uint32_t  CHSTAT_8;                               /*  CHSTAT_8        */
    volatile uint32_t  CHCTRL_8;                               /*  CHCTRL_8        */
    volatile uint32_t  CHCFG_8;                                /*  CHCFG_8         */
    volatile uint32_t  CHITVL_8;                               /*  CHITVL_8        */
    volatile uint32_t  CHEXT_8;                                /*  CHEXT_8         */
    volatile uint32_t  NXLA_8;                                 /*  NXLA_8          */
    volatile uint32_t  CRLA_8;                                 /*  CRLA_8          */
/* end of struct st_dmac_n */
/* start of struct st_dmac_n */
    volatile uint32_t  N0SA_9;                                 /*  N0SA_9          */
    volatile uint32_t  N0DA_9;                                 /*  N0DA_9          */
    volatile uint32_t  N0TB_9;                                 /*  N0TB_9          */
    volatile uint32_t  N1SA_9;                                 /*  N1SA_9          */
    volatile uint32_t  N1DA_9;                                 /*  N1DA_9          */
    volatile uint32_t  N1TB_9;                                 /*  N1TB_9          */
    volatile uint32_t  CRSA_9;                                 /*  CRSA_9          */
    volatile uint32_t  CRDA_9;                                 /*  CRDA_9          */
    volatile uint32_t  CRTB_9;                                 /*  CRTB_9          */
    volatile uint32_t  CHSTAT_9;                               /*  CHSTAT_9        */
    volatile uint32_t  CHCTRL_9;                               /*  CHCTRL_9        */
    volatile uint32_t  CHCFG_9;                                /*  CHCFG_9         */
    volatile uint32_t  CHITVL_9;                               /*  CHITVL_9        */
    volatile uint32_t  CHEXT_9;                                /*  CHEXT_9         */
    volatile uint32_t  NXLA_9;                                 /*  NXLA_9          */
    volatile uint32_t  CRLA_9;                                 /*  CRLA_9          */
/* end of struct st_dmac_n */
/* start of struct st_dmac_n */
    volatile uint32_t  N0SA_10;                                /*  N0SA_10         */
    volatile uint32_t  N0DA_10;                                /*  N0DA_10         */
    volatile uint32_t  N0TB_10;                                /*  N0TB_10         */
    volatile uint32_t  N1SA_10;                                /*  N1SA_10         */
    volatile uint32_t  N1DA_10;                                /*  N1DA_10         */
    volatile uint32_t  N1TB_10;                                /*  N1TB_10         */
    volatile uint32_t  CRSA_10;                                /*  CRSA_10         */
    volatile uint32_t  CRDA_10;                                /*  CRDA_10         */
    volatile uint32_t  CRTB_10;                                /*  CRTB_10         */
    volatile uint32_t  CHSTAT_10;                              /*  CHSTAT_10       */
    volatile uint32_t  CHCTRL_10;                              /*  CHCTRL_10       */
    volatile uint32_t  CHCFG_10;                               /*  CHCFG_10        */
    volatile uint32_t  CHITVL_10;                              /*  CHITVL_10       */
    volatile uint32_t  CHEXT_10;                               /*  CHEXT_10        */
    volatile uint32_t  NXLA_10;                                /*  NXLA_10         */
    volatile uint32_t  CRLA_10;                                /*  CRLA_10         */
/* end of struct st_dmac_n */
/* start of struct st_dmac_n */
    volatile uint32_t  N0SA_11;                                /*  N0SA_11         */
    volatile uint32_t  N0DA_11;                                /*  N0DA_11         */
    volatile uint32_t  N0TB_11;                                /*  N0TB_11         */
    volatile uint32_t  N1SA_11;                                /*  N1SA_11         */
    volatile uint32_t  N1DA_11;                                /*  N1DA_11         */
    volatile uint32_t  N1TB_11;                                /*  N1TB_11         */
    volatile uint32_t  CRSA_11;                                /*  CRSA_11         */
    volatile uint32_t  CRDA_11;                                /*  CRDA_11         */
    volatile uint32_t  CRTB_11;                                /*  CRTB_11         */
    volatile uint32_t  CHSTAT_11;                              /*  CHSTAT_11       */
    volatile uint32_t  CHCTRL_11;                              /*  CHCTRL_11       */
    volatile uint32_t  CHCFG_11;                               /*  CHCFG_11        */
    volatile uint32_t  CHITVL_11;                              /*  CHITVL_11       */
    volatile uint32_t  CHEXT_11;                               /*  CHEXT_11        */
    volatile uint32_t  NXLA_11;                                /*  NXLA_11         */
    volatile uint32_t  CRLA_11;                                /*  CRLA_11         */
/* end of struct st_dmac_n */
/* start of struct st_dmac_n */
    volatile uint32_t  N0SA_12;                                /*  N0SA_12         */
    volatile uint32_t  N0DA_12;                                /*  N0DA_12         */
    volatile uint32_t  N0TB_12;                                /*  N0TB_12         */
    volatile uint32_t  N1SA_12;                                /*  N1SA_12         */
    volatile uint32_t  N1DA_12;                                /*  N1DA_12         */
    volatile uint32_t  N1TB_12;                                /*  N1TB_12         */
    volatile uint32_t  CRSA_12;                                /*  CRSA_12         */
    volatile uint32_t  CRDA_12;                                /*  CRDA_12         */
    volatile uint32_t  CRTB_12;                                /*  CRTB_12         */
    volatile uint32_t  CHSTAT_12;                              /*  CHSTAT_12       */
    volatile uint32_t  CHCTRL_12;                              /*  CHCTRL_12       */
    volatile uint32_t  CHCFG_12;                               /*  CHCFG_12        */
    volatile uint32_t  CHITVL_12;                              /*  CHITVL_12       */
    volatile uint32_t  CHEXT_12;                               /*  CHEXT_12        */
    volatile uint32_t  NXLA_12;                                /*  NXLA_12         */
    volatile uint32_t  CRLA_12;                                /*  CRLA_12         */
/* end of struct st_dmac_n */
/* start of struct st_dmac_n */
    volatile uint32_t  N0SA_13;                                /*  N0SA_13         */
    volatile uint32_t  N0DA_13;                                /*  N0DA_13         */
    volatile uint32_t  N0TB_13;                                /*  N0TB_13         */
    volatile uint32_t  N1SA_13;                                /*  N1SA_13         */
    volatile uint32_t  N1DA_13;                                /*  N1DA_13         */
    volatile uint32_t  N1TB_13;                                /*  N1TB_13         */
    volatile uint32_t  CRSA_13;                                /*  CRSA_13         */
    volatile uint32_t  CRDA_13;                                /*  CRDA_13         */
    volatile uint32_t  CRTB_13;                                /*  CRTB_13         */
    volatile uint32_t  CHSTAT_13;                              /*  CHSTAT_13       */
    volatile uint32_t  CHCTRL_13;                              /*  CHCTRL_13       */
    volatile uint32_t  CHCFG_13;                               /*  CHCFG_13        */
    volatile uint32_t  CHITVL_13;                              /*  CHITVL_13       */
    volatile uint32_t  CHEXT_13;                               /*  CHEXT_13        */
    volatile uint32_t  NXLA_13;                                /*  NXLA_13         */
    volatile uint32_t  CRLA_13;                                /*  CRLA_13         */
/* end of struct st_dmac_n */
/* start of struct st_dmac_n */
    volatile uint32_t  N0SA_14;                                /*  N0SA_14         */
    volatile uint32_t  N0DA_14;                                /*  N0DA_14         */
    volatile uint32_t  N0TB_14;                                /*  N0TB_14         */
    volatile uint32_t  N1SA_14;                                /*  N1SA_14         */
    volatile uint32_t  N1DA_14;                                /*  N1DA_14         */
    volatile uint32_t  N1TB_14;                                /*  N1TB_14         */
    volatile uint32_t  CRSA_14;                                /*  CRSA_14         */
    volatile uint32_t  CRDA_14;                                /*  CRDA_14         */
    volatile uint32_t  CRTB_14;                                /*  CRTB_14         */
    volatile uint32_t  CHSTAT_14;                              /*  CHSTAT_14       */
    volatile uint32_t  CHCTRL_14;                              /*  CHCTRL_14       */
    volatile uint32_t  CHCFG_14;                               /*  CHCFG_14        */
    volatile uint32_t  CHITVL_14;                              /*  CHITVL_14       */
    volatile uint32_t  CHEXT_14;                               /*  CHEXT_14        */
    volatile uint32_t  NXLA_14;                                /*  NXLA_14         */
    volatile uint32_t  CRLA_14;                                /*  CRLA_14         */
/* end of struct st_dmac_n */
/* start of struct st_dmac_n */
    volatile uint32_t  N0SA_15;                                /*  N0SA_15         */
    volatile uint32_t  N0DA_15;                                /*  N0DA_15         */
    volatile uint32_t  N0TB_15;                                /*  N0TB_15         */
    volatile uint32_t  N1SA_15;                                /*  N1SA_15         */
    volatile uint32_t  N1DA_15;                                /*  N1DA_15         */
    volatile uint32_t  N1TB_15;                                /*  N1TB_15         */
    volatile uint32_t  CRSA_15;                                /*  CRSA_15         */
    volatile uint32_t  CRDA_15;                                /*  CRDA_15         */
    volatile uint32_t  CRTB_15;                                /*  CRTB_15         */
    volatile uint32_t  CHSTAT_15;                              /*  CHSTAT_15       */
    volatile uint32_t  CHCTRL_15;                              /*  CHCTRL_15       */
    volatile uint32_t  CHCFG_15;                               /*  CHCFG_15        */
    volatile uint32_t  CHITVL_15;                              /*  CHITVL_15       */
    volatile uint32_t  CHEXT_15;                               /*  CHEXT_15        */
    volatile uint32_t  NXLA_15;                                /*  NXLA_15         */
    volatile uint32_t  CRLA_15;                                /*  CRLA_15         */
/* end of struct st_dmac_n */
    volatile uint8_t   dummy190[256];                          /*                  */
/* start of struct st_dmaccommon_n */
    volatile uint32_t  DCTRL_8_15;                             /*  DCTRL_8_15      */
    volatile uint8_t   dummy191[12];                           /*                  */
    volatile uint32_t  DSTAT_EN_8_15;                          /*  DSTAT_EN_8_15   */
    volatile uint32_t  DSTAT_ER_8_15;                          /*  DSTAT_ER_8_15   */
    volatile uint32_t  DSTAT_END_8_15;                         /*  DSTAT_END_8_15  */
    volatile uint32_t  DSTAT_TC_8_15;                          /*  DSTAT_TC_8_15   */
    volatile uint32_t  DSTAT_SUS_8_15;                         /*  DSTAT_SUS_8_15  */
/* end of struct st_dmaccommon_n */
    volatile uint8_t   dummy192[350095580];                    /*                  */
    volatile uint32_t  DMARS0;                                 /*  DMARS0          */
    volatile uint32_t  DMARS1;                                 /*  DMARS1          */
    volatile uint32_t  DMARS2;                                 /*  DMARS2          */
    volatile uint32_t  DMARS3;                                 /*  DMARS3          */
    volatile uint32_t  DMARS4;                                 /*  DMARS4          */
    volatile uint32_t  DMARS5;                                 /*  DMARS5          */
    volatile uint32_t  DMARS6;                                 /*  DMARS6          */
    volatile uint32_t  DMARS7;                                 /*  DMARS7          */
};


struct st_dmaccommon_n
{
    volatile uint32_t  DCTRL_0_7;                              /*  DCTRL_0_7       */
    volatile uint8_t   dummy1[12];                             /*                  */
    volatile uint32_t  DSTAT_EN_0_7;                           /*  DSTAT_EN_0_7    */
    volatile uint32_t  DSTAT_ER_0_7;                           /*  DSTAT_ER_0_7    */
    volatile uint32_t  DSTAT_END_0_7;                          /*  DSTAT_END_0_7   */
    volatile uint32_t  DSTAT_TC_0_7;                           /*  DSTAT_TC_0_7    */
    volatile uint32_t  DSTAT_SUS_0_7;                          /*  DSTAT_SUS_0_7   */
};


struct st_dmac_n
{
    volatile uint32_t  N0SA_n;                                 /*  N0SA_n          */
    volatile uint32_t  N0DA_n;                                 /*  N0DA_n          */
    volatile uint32_t  N0TB_n;                                 /*  N0TB_n          */
    volatile uint32_t  N1SA_n;                                 /*  N1SA_n          */
    volatile uint32_t  N1DA_n;                                 /*  N1DA_n          */
    volatile uint32_t  N1TB_n;                                 /*  N1TB_n          */
    volatile uint32_t  CRSA_n;                                 /*  CRSA_n          */
    volatile uint32_t  CRDA_n;                                 /*  CRDA_n          */
    volatile uint32_t  CRTB_n;                                 /*  CRTB_n          */
    volatile uint32_t  CHSTAT_n;                               /*  CHSTAT_n        */
    volatile uint32_t  CHCTRL_n;                               /*  CHCTRL_n        */
    volatile uint32_t  CHCFG_n;                                /*  CHCFG_n         */
    volatile uint32_t  CHITVL_n;                               /*  CHITVL_n        */
    volatile uint32_t  CHEXT_n;                                /*  CHEXT_n         */
    volatile uint32_t  NXLA_n;                                 /*  NXLA_n          */
    volatile uint32_t  CRLA_n;                                 /*  CRLA_n          */
};





/* Start of channnel array defines of DMAC */

/* Channnel array defines of DMACn */
/*(Sample) value = DMACn[ channel ]->N0SA_n; */
#line 419 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/dmac_iodefine.h"


/* Channnel array defines of DMACnn */
/*(Sample) value = DMACnn[ channel / 8 ]->DCTRL_0_7; */
#line 430 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/dmac_iodefine.h"


/* Channnel array defines of DMACmm */
/*(Sample) value = DMACmm[ channel / 2 ]->DMARS; */
struct st_dmars_mm
{
    uint32_t       DMARS;                                        /*  DMARS     */
};
#line 451 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/dmac_iodefine.h"

/* End of channnel array defines of DMAC */


#line 731 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/dmac_iodefine.h"
/* <-SEC M1.10.1 */
/* <-QAC 0639 */
#line 103 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/dvdec_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : dvdec_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_dvdec
{                                                          /* DVDEC            */
    volatile uint16_t ADCCR1;                                 /*  ADCCR1          */
    volatile uint8_t   dummy1[4];                              /*                  */

    volatile uint16_t TGCR1;                                  /*  TGCR1           */
    volatile uint16_t TGCR2;                                  /*  TGCR2           */
    volatile uint16_t TGCR3;                                  /*  TGCR3           */
    volatile uint8_t   dummy2[6];                              /*                  */

    volatile uint16_t SYNSCR1;                                /*  SYNSCR1         */
    volatile uint16_t SYNSCR2;                                /*  SYNSCR2         */
    volatile uint16_t SYNSCR3;                                /*  SYNSCR3         */
    volatile uint16_t SYNSCR4;                                /*  SYNSCR4         */
    volatile uint16_t SYNSCR5;                                /*  SYNSCR5         */

    volatile uint16_t HAFCCR1;                                /*  HAFCCR1         */
    volatile uint16_t HAFCCR2;                                /*  HAFCCR2         */
    volatile uint16_t HAFCCR3;                                /*  HAFCCR3         */
    volatile uint16_t VCDWCR1;                                /*  VCDWCR1         */
    volatile uint8_t   dummy3[4];                              /*                  */

    volatile uint16_t DCPCR1;                                 /*  DCPCR1          */
    volatile uint16_t DCPCR2;                                 /*  DCPCR2          */
    volatile uint16_t DCPCR3;                                 /*  DCPCR3          */
    volatile uint16_t DCPCR4;                                 /*  DCPCR4          */
    volatile uint16_t DCPCR5;                                 /*  DCPCR5          */
    volatile uint16_t DCPCR6;                                 /*  DCPCR6          */
    volatile uint16_t DCPCR7;                                 /*  DCPCR7          */
    volatile uint16_t DCPCR8;                                 /*  DCPCR8          */
    volatile uint16_t NSDCR;                                  /*  NSDCR           */
    volatile uint16_t BTLCR;                                  /*  BTLCR           */
    volatile uint16_t BTGPCR;                                 /*  BTGPCR          */

    volatile uint16_t ACCCR1;                                 /*  ACCCR1          */
    volatile uint16_t ACCCR2;                                 /*  ACCCR2          */
    volatile uint16_t ACCCR3;                                 /*  ACCCR3          */
    volatile uint16_t TINTCR;                                 /*  TINTCR          */
    volatile uint16_t YCDCR;                                  /*  YCDCR           */

    volatile uint16_t AGCCR1;                                 /*  AGCCR1          */
    volatile uint16_t AGCCR2;                                 /*  AGCCR2          */
    volatile uint16_t PKLIMITCR;                              /*  PKLIMITCR       */

    volatile uint16_t RGORCR1;                                /*  RGORCR1         */
    volatile uint16_t RGORCR2;                                /*  RGORCR2         */
    volatile uint16_t RGORCR3;                                /*  RGORCR3         */
    volatile uint16_t RGORCR4;                                /*  RGORCR4         */
    volatile uint16_t RGORCR5;                                /*  RGORCR5         */
    volatile uint16_t RGORCR6;                                /*  RGORCR6         */
    volatile uint16_t RGORCR7;                                /*  RGORCR7         */
    volatile uint8_t   dummy4[24];                             /*                  */
    volatile uint16_t AFCPFCR;                                /*  AFCPFCR         */
    volatile uint16_t RUPDCR;                                 /*  RUPDCR          */
    volatile uint16_t VSYNCSR;                                /*  VSYNCSR         */
    volatile uint16_t HSYNCSR;                                /*  HSYNCSR         */

    volatile uint16_t DCPSR1;                                 /*  DCPSR1          */
    volatile uint16_t DCPSR2;                                 /*  DCPSR2          */
    volatile uint8_t   dummy5[4];                              /*                  */
    volatile uint16_t NSDSR;                                  /*  NSDSR           */

    volatile uint16_t CROMASR1;                               /*  CROMASR1        */
    volatile uint16_t CROMASR2;                               /*  CROMASR2        */
    volatile uint16_t SYNCSSR;                                /*  SYNCSSR         */

    volatile uint16_t AGCCSR1;                                /*  AGCCSR1         */
    volatile uint16_t AGCCSR2;                                /*  AGCCSR2         */
    volatile uint8_t   dummy6[108];                            /*                  */

    volatile uint16_t YCSCR3;                                 /*  YCSCR3          */
    volatile uint16_t YCSCR4;                                 /*  YCSCR4          */
    volatile uint16_t YCSCR5;                                 /*  YCSCR5          */
    volatile uint16_t YCSCR6;                                 /*  YCSCR6          */
    volatile uint16_t YCSCR7;                                 /*  YCSCR7          */
    volatile uint16_t YCSCR8;                                 /*  YCSCR8          */
    volatile uint16_t YCSCR9;                                 /*  YCSCR9          */
    volatile uint8_t   dummy7[2];                              /*                  */
    volatile uint16_t YCSCR11;                                /*  YCSCR11         */
    volatile uint16_t YCSCR12;                                /*  YCSCR12         */
    volatile uint8_t   dummy8[104];                            /*                  */
    volatile uint16_t DCPCR9;                                 /*  DCPCR9          */
    volatile uint8_t   dummy9[16];                             /*                  */

    volatile uint16_t YCTWA_F0;                               /*  YCTWA_F0        */
    volatile uint16_t YCTWA_F1;                               /*  YCTWA_F1        */
    volatile uint16_t YCTWA_F2;                               /*  YCTWA_F2        */
    volatile uint16_t YCTWA_F3;                               /*  YCTWA_F3        */
    volatile uint16_t YCTWA_F4;                               /*  YCTWA_F4        */
    volatile uint16_t YCTWA_F5;                               /*  YCTWA_F5        */
    volatile uint16_t YCTWA_F6;                               /*  YCTWA_F6        */
    volatile uint16_t YCTWA_F7;                               /*  YCTWA_F7        */
    volatile uint16_t YCTWA_F8;                               /*  YCTWA_F8        */

    volatile uint16_t YCTWB_F0;                               /*  YCTWB_F0        */
    volatile uint16_t YCTWB_F1;                               /*  YCTWB_F1        */
    volatile uint16_t YCTWB_F2;                               /*  YCTWB_F2        */
    volatile uint16_t YCTWB_F3;                               /*  YCTWB_F3        */
    volatile uint16_t YCTWB_F4;                               /*  YCTWB_F4        */
    volatile uint16_t YCTWB_F5;                               /*  YCTWB_F5        */
    volatile uint16_t YCTWB_F6;                               /*  YCTWB_F6        */
    volatile uint16_t YCTWB_F7;                               /*  YCTWB_F7        */
    volatile uint16_t YCTWB_F8;                               /*  YCTWB_F8        */

    volatile uint16_t YCTNA_F0;                               /*  YCTNA_F0        */
    volatile uint16_t YCTNA_F1;                               /*  YCTNA_F1        */
    volatile uint16_t YCTNA_F2;                               /*  YCTNA_F2        */
    volatile uint16_t YCTNA_F3;                               /*  YCTNA_F3        */
    volatile uint16_t YCTNA_F4;                               /*  YCTNA_F4        */
    volatile uint16_t YCTNA_F5;                               /*  YCTNA_F5        */
    volatile uint16_t YCTNA_F6;                               /*  YCTNA_F6        */
    volatile uint16_t YCTNA_F7;                               /*  YCTNA_F7        */
    volatile uint16_t YCTNA_F8;                               /*  YCTNA_F8        */

    volatile uint16_t YCTNB_F0;                               /*  YCTNB_F0        */
    volatile uint16_t YCTNB_F1;                               /*  YCTNB_F1        */
    volatile uint16_t YCTNB_F2;                               /*  YCTNB_F2        */
    volatile uint16_t YCTNB_F3;                               /*  YCTNB_F3        */
    volatile uint16_t YCTNB_F4;                               /*  YCTNB_F4        */
    volatile uint16_t YCTNB_F5;                               /*  YCTNB_F5        */
    volatile uint16_t YCTNB_F6;                               /*  YCTNB_F6        */
    volatile uint16_t YCTNB_F7;                               /*  YCTNB_F7        */
    volatile uint16_t YCTNB_F8;                               /*  YCTNB_F8        */
    volatile uint8_t   dummy10[38];                            /*                  */
    volatile uint16_t YGAINCR;                                /*  YGAINCR         */
    volatile uint16_t CBGAINCR;                               /*  CBGAINCR        */
    volatile uint16_t CRGAINCR;                               /*  CRGAINCR        */
    volatile uint8_t   dummy11[122];                           /*                  */
    volatile uint16_t PGA_UPDATE;                             /*  PGA_UPDATE      */
    volatile uint16_t PGACR;                                  /*  PGACR           */
    volatile uint16_t ADCCR2;                                 /*  ADCCR2          */
};






/* Start of channnel array defines of DVDEC */

/* Channnel array defines of DVDEC */
/*(Sample) value = DVDEC[ channel ]->ADCCR1; */






/* End of channnel array defines of DVDEC */


#line 390 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/dvdec_iodefine.h"
/* <-SEC M1.10.1 */
#line 104 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/ether_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : ether_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->QAC 0639 : Over 127 members (C90) */
/* ->SEC M1.10.1 : Not magic number */

struct st_ether
{                                                          /* ETHER            */
    volatile uint32_t  EDSR0;                                  /*  EDSR0           */
    volatile uint8_t   dummy207[12];                           /*                  */
    volatile uint32_t  TDLAR0;                                 /*  TDLAR0          */
    volatile uint32_t  TDFAR0;                                 /*  TDFAR0          */
    volatile uint32_t  TDFXR0;                                 /*  TDFXR0          */
    volatile uint32_t  TDFFR0;                                 /*  TDFFR0          */
    volatile uint8_t   dummy208[16];                           /*                  */
    volatile uint32_t  RDLAR0;                                 /*  RDLAR0          */
    volatile uint32_t  RDFAR0;                                 /*  RDFAR0          */
    volatile uint32_t  RDFXR0;                                 /*  RDFXR0          */
    volatile uint32_t  RDFFR0;                                 /*  RDFFR0          */
    volatile uint8_t   dummy209[960];                          /*                  */
    volatile uint32_t  EDMR0;                                  /*  EDMR0           */
    volatile uint8_t   dummy210[4];                            /*                  */
    volatile uint32_t  EDTRR0;                                 /*  EDTRR0          */
    volatile uint8_t   dummy211[4];                            /*                  */
    volatile uint32_t  EDRRR0;                                 /*  EDRRR0          */
    volatile uint8_t   dummy212[20];                           /*                  */
    volatile uint32_t  EESR0;                                  /*  EESR0           */
    volatile uint8_t   dummy213[4];                            /*                  */
    volatile uint32_t  EESIPR0;                                /*  EESIPR0         */
    volatile uint8_t   dummy214[4];                            /*                  */
    volatile uint32_t  TRSCER0;                                /*  TRSCER0         */
    volatile uint8_t   dummy215[4];                            /*                  */
    volatile uint32_t  RMFCR0;                                 /*  RMFCR0          */
    volatile uint8_t   dummy216[4];                            /*                  */
    volatile uint32_t  TFTR0;                                  /*  TFTR0           */
    volatile uint8_t   dummy217[4];                            /*                  */
    volatile uint32_t  FDR0;                                   /*  FDR0            */
    volatile uint8_t   dummy218[4];                            /*                  */
    volatile uint32_t  RMCR0;                                  /*  RMCR0           */
    volatile uint8_t   dummy219[4];                            /*                  */
    volatile uint32_t  RPADIR0;                                /*  RPADIR0         */
    volatile uint8_t   dummy220[4];                            /*                  */
    volatile uint32_t  FCFTR0;                                 /*  FCFTR0          */
    volatile uint8_t   dummy221[120];                          /*                  */
    volatile uint32_t  CSMR;                                   /*  CSMR            */
    volatile uint32_t  CSSBM;                                  /*  CSSBM           */
    volatile uint32_t  CSSMR;                                  /*  CSSMR           */
    volatile uint8_t   dummy222[16];                           /*                  */
    volatile uint32_t  ECMR0;                                  /*  ECMR0           */
    volatile uint8_t   dummy223[4];                            /*                  */
    volatile uint32_t  RFLR0;                                  /*  RFLR0           */
    volatile uint8_t   dummy224[4];                            /*                  */
    volatile uint32_t  ECSR0;                                  /*  ECSR0           */
    volatile uint8_t   dummy225[4];                            /*                  */
    volatile uint32_t  ECSIPR0;                                /*  ECSIPR0         */
    volatile uint8_t   dummy226[4];                            /*                  */
    volatile uint32_t  PIR0;                                   /*  PIR0            */
    volatile uint8_t   dummy227[48];                           /*                  */
    volatile uint32_t  APR0;                                   /*  APR0            */
    volatile uint32_t  MPR0;                                   /*  MPR0            */
    volatile uint32_t  PFTCR0;                                 /*  PFTCR0          */
    volatile uint32_t  PFRCR0;                                 /*  PFRCR0          */
    volatile uint32_t  TPAUSER0;                               /*  TPAUSER0        */
    volatile uint8_t   dummy228[88];                           /*                  */
    volatile uint32_t  MAHR0;                                  /*  MAHR0           */
    volatile uint8_t   dummy229[4];                            /*                  */
    volatile uint32_t  MALR0;                                  /*  MALR0           */
    volatile uint8_t   dummy230[372];                          /*                  */
    volatile uint32_t  CEFCR0;                                 /*  CEFCR0          */
    volatile uint8_t   dummy231[4];                            /*                  */
    volatile uint32_t  FRECR0;                                 /*  FRECR0          */
    volatile uint8_t   dummy232[4];                            /*                  */
    volatile uint32_t  TSFRCR0;                                /*  TSFRCR0         */
    volatile uint8_t   dummy233[4];                            /*                  */
    volatile uint32_t  TLFRCR0;                                /*  TLFRCR0         */
    volatile uint8_t   dummy234[4];                            /*                  */
    volatile uint32_t  RFCR0;                                  /*  RFCR0           */
    volatile uint8_t   dummy235[20];                           /*                  */
    volatile uint32_t  MAFCR0;                                 /*  MAFCR0          */
    volatile uint8_t   dummy236[4228];                         /*                  */
    volatile uint32_t  ARSTR;                                  /*  ARSTR           */
    volatile uint32_t  TSU_CTRST;                              /*  TSU_CTRST       */
    volatile uint8_t   dummy237[80];                           /*                  */
    volatile uint32_t  TSU_VTAG0;                              /*  TSU_VTAG0       */
    volatile uint8_t   dummy238[4];                            /*                  */
    volatile uint32_t  TSU_ADSBSY;                             /*  TSU_ADSBSY      */
    volatile uint32_t  TSU_TEN;                                /*  TSU_TEN         */
    volatile uint8_t   dummy239[24];                           /*                  */
    volatile uint32_t  TXNLCR0;                                /*  TXNLCR0         */
    volatile uint32_t  TXALCR0;                                /*  TXALCR0         */
    volatile uint32_t  RXNLCR0;                                /*  RXNLCR0         */
    volatile uint32_t  RXALCR0;                                /*  RXALCR0         */
    volatile uint8_t   dummy240[112];                          /*                  */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH0;                              /*  TSU_ADRH0       */
    volatile uint32_t  TSU_ADRL0;                              /*  TSU_ADRL0       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH1;                              /*  TSU_ADRH1       */
    volatile uint32_t  TSU_ADRL1;                              /*  TSU_ADRL1       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH2;                              /*  TSU_ADRH2       */
    volatile uint32_t  TSU_ADRL2;                              /*  TSU_ADRL2       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH3;                              /*  TSU_ADRH3       */
    volatile uint32_t  TSU_ADRL3;                              /*  TSU_ADRL3       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH4;                              /*  TSU_ADRH4       */
    volatile uint32_t  TSU_ADRL4;                              /*  TSU_ADRL4       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH5;                              /*  TSU_ADRH5       */
    volatile uint32_t  TSU_ADRL5;                              /*  TSU_ADRL5       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH6;                              /*  TSU_ADRH6       */
    volatile uint32_t  TSU_ADRL6;                              /*  TSU_ADRL6       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH7;                              /*  TSU_ADRH7       */
    volatile uint32_t  TSU_ADRL7;                              /*  TSU_ADRL7       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH8;                              /*  TSU_ADRH8       */
    volatile uint32_t  TSU_ADRL8;                              /*  TSU_ADRL8       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH9;                              /*  TSU_ADRH9       */
    volatile uint32_t  TSU_ADRL9;                              /*  TSU_ADRL9       */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH10;                             /*  TSU_ADRH10      */
    volatile uint32_t  TSU_ADRL10;                             /*  TSU_ADRL10      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH11;                             /*  TSU_ADRH11      */
    volatile uint32_t  TSU_ADRL11;                             /*  TSU_ADRL11      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH12;                             /*  TSU_ADRH12      */
    volatile uint32_t  TSU_ADRL12;                             /*  TSU_ADRL12      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH13;                             /*  TSU_ADRH13      */
    volatile uint32_t  TSU_ADRL13;                             /*  TSU_ADRL13      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH14;                             /*  TSU_ADRH14      */
    volatile uint32_t  TSU_ADRL14;                             /*  TSU_ADRL14      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH15;                             /*  TSU_ADRH15      */
    volatile uint32_t  TSU_ADRL15;                             /*  TSU_ADRL15      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH16;                             /*  TSU_ADRH16      */
    volatile uint32_t  TSU_ADRL16;                             /*  TSU_ADRL16      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH17;                             /*  TSU_ADRH17      */
    volatile uint32_t  TSU_ADRL17;                             /*  TSU_ADRL17      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH18;                             /*  TSU_ADRH18      */
    volatile uint32_t  TSU_ADRL18;                             /*  TSU_ADRL18      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH19;                             /*  TSU_ADRH19      */
    volatile uint32_t  TSU_ADRL19;                             /*  TSU_ADRL19      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH20;                             /*  TSU_ADRH20      */
    volatile uint32_t  TSU_ADRL20;                             /*  TSU_ADRL20      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH21;                             /*  TSU_ADRH21      */
    volatile uint32_t  TSU_ADRL21;                             /*  TSU_ADRL21      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH22;                             /*  TSU_ADRH22      */
    volatile uint32_t  TSU_ADRL22;                             /*  TSU_ADRL22      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH23;                             /*  TSU_ADRH23      */
    volatile uint32_t  TSU_ADRL23;                             /*  TSU_ADRL23      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH24;                             /*  TSU_ADRH24      */
    volatile uint32_t  TSU_ADRL24;                             /*  TSU_ADRL24      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH25;                             /*  TSU_ADRH25      */
    volatile uint32_t  TSU_ADRL25;                             /*  TSU_ADRL25      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH26;                             /*  TSU_ADRH26      */
    volatile uint32_t  TSU_ADRL26;                             /*  TSU_ADRL26      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH27;                             /*  TSU_ADRH27      */
    volatile uint32_t  TSU_ADRL27;                             /*  TSU_ADRL27      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH28;                             /*  TSU_ADRH28      */
    volatile uint32_t  TSU_ADRL28;                             /*  TSU_ADRL28      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH29;                             /*  TSU_ADRH29      */
    volatile uint32_t  TSU_ADRL29;                             /*  TSU_ADRL29      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH30;                             /*  TSU_ADRH30      */
    volatile uint32_t  TSU_ADRL30;                             /*  TSU_ADRL30      */
/* end of struct st_ether_from_tsu_adrh0 */
/* start of struct st_ether_from_tsu_adrh0 */
    volatile uint32_t  TSU_ADRH31;                             /*  TSU_ADRH31      */
    volatile uint32_t  TSU_ADRL31;                             /*  TSU_ADRL31      */
/* end of struct st_ether_from_tsu_adrh0 */
};


struct st_ether_from_tsu_adrh0
{
    volatile uint32_t  TSU_ADRH0;                              /*  TSU_ADRH0       */
    volatile uint32_t  TSU_ADRL0;                              /*  TSU_ADRL0       */
};





/* Start of channnel array defines of ETHER */

/* Channnel array defines of ETHER_FROM_TSU_ADRH0_ARRAY */
/*(Sample) value = ETHER_FROM_TSU_ADRH0_ARRAY[ channel ]->TSU_ADRH0; */
#line 306 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/ether_iodefine.h"

/* End of channnel array defines of ETHER */


#line 425 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/ether_iodefine.h"
/* <-SEC M1.10.1 */
/* <-QAC 0639 */
#line 105 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/flctl_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : flctl_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_flctl
{                                                          /* FLCTL            */
    volatile uint32_t  FLCMNCR;                                /*  FLCMNCR         */
    volatile uint32_t  FLCMDCR;                                /*  FLCMDCR         */
    volatile uint32_t  FLCMCDR;                                /*  FLCMCDR         */
    volatile uint32_t  FLADR;                                  /*  FLADR           */
    volatile uint32_t  FLDATAR;                                /*  FLDATAR         */
    volatile uint32_t  FLDTCNTR;                               /*  FLDTCNTR        */
    volatile uint32_t  FLINTDMACR;                             /*  FLINTDMACR      */
    volatile uint32_t  FLBSYTMR;                               /*  FLBSYTMR        */
    volatile uint32_t  FLBSYCNT;                               /*  FLBSYCNT        */
    volatile uint8_t   dummy555[8];                            /*                  */
    volatile uint8_t   FLTRCR;                                 /*  FLTRCR          */
    volatile uint8_t   dummy556[15];                           /*                  */
    volatile uint32_t  FLADR2;                                 /*  FLADR2          */
    volatile uint8_t   dummy557[16];                           /*                  */
    volatile uint32_t  FLDTFIFO;                               /*  FLDTFIFO        */
    volatile uint8_t   dummy558[12];                           /*                  */
    volatile uint32_t  FLECFIFO;                               /*  FLECFIFO        */
};





#line 71 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/flctl_iodefine.h"
/* <-SEC M1.10.1 */
#line 106 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/gpio_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : gpio_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->QAC 0639 : Over 127 members (C90) */
/* ->SEC M1.10.1 : Not magic number */

struct st_gpio
{                                                          /* GPIO             */
/* start of struct st_gpio_from_p1 */
    volatile uint16_t P1;                                     /*  P1              */
    volatile uint8_t   dummy348[2];                            /*                  */
/* end of struct st_gpio_from_p1 */
/* start of struct st_gpio_from_p1 */
    volatile uint16_t P2;                                     /*  P2              */
    volatile uint8_t   dummy349[2];                            /*                  */
/* end of struct st_gpio_from_p1 */
/* start of struct st_gpio_from_p1 */
    volatile uint16_t P3;                                     /*  P3              */
    volatile uint8_t   dummy350[2];                            /*                  */
/* end of struct st_gpio_from_p1 */
/* start of struct st_gpio_from_p1 */
    volatile uint16_t P4;                                     /*  P4              */
    volatile uint8_t   dummy351[2];                            /*                  */
/* end of struct st_gpio_from_p1 */
/* start of struct st_gpio_from_p1 */
    volatile uint16_t P5;                                     /*  P5              */
    volatile uint8_t   dummy352[2];                            /*                  */
/* end of struct st_gpio_from_p1 */
/* start of struct st_gpio_from_p1 */
    volatile uint16_t P6;                                     /*  P6              */
    volatile uint8_t   dummy353[2];                            /*                  */
/* end of struct st_gpio_from_p1 */
/* start of struct st_gpio_from_p1 */
    volatile uint16_t P7;                                     /*  P7              */
    volatile uint8_t   dummy354[2];                            /*                  */
/* end of struct st_gpio_from_p1 */
/* start of struct st_gpio_from_p1 */
    volatile uint16_t P8;                                     /*  P8              */
    volatile uint8_t   dummy355[2];                            /*                  */
/* end of struct st_gpio_from_p1 */
/* start of struct st_gpio_from_p1 */
    volatile uint16_t P9;                                     /*  P9              */
    volatile uint8_t   dummy356[2];                            /*                  */
/* end of struct st_gpio_from_p1 */
/* start of struct st_gpio_from_p1 */
    volatile uint16_t P10;                                    /*  P10             */
    volatile uint8_t   dummy357[2];                            /*                  */
/* end of struct st_gpio_from_p1 */
/* start of struct st_gpio_from_p1 */
    volatile uint16_t P11;                                    /*  P11             */
    volatile uint8_t   dummy3580[2];                           /*                  */
/* end of struct st_gpio_from_p1 */
    volatile uint8_t   dummy3581[212];                         /*                  */

    volatile uint32_t  PSR1;                                   /*  PSR1            */
    volatile uint32_t  PSR2;                                   /*  PSR2            */
    volatile uint32_t  PSR3;                                   /*  PSR3            */
    volatile uint32_t  PSR4;                                   /*  PSR4            */
    volatile uint32_t  PSR5;                                   /*  PSR5            */
    volatile uint32_t  PSR6;                                   /*  PSR6            */
    volatile uint32_t  PSR7;                                   /*  PSR7            */
    volatile uint32_t  PSR8;                                   /*  PSR8            */
    volatile uint32_t  PSR9;                                   /*  PSR9            */
    volatile uint32_t  PSR10;                                  /*  PSR10           */
    volatile uint32_t  PSR11;                                  /*  PSR11           */
    volatile uint8_t   dummy359[208];                          /*                  */
/* start of struct st_gpio_from_ppr0 */
    volatile uint16_t PPR0;                                   /*  PPR0            */
    volatile uint8_t   dummy360[2];                            /*                  */
/* end of struct st_gpio_from_ppr0 */
/* start of struct st_gpio_from_ppr0 */
    volatile uint16_t PPR1;                                   /*  PPR1            */
    volatile uint8_t   dummy361[2];                            /*                  */
/* end of struct st_gpio_from_ppr0 */
/* start of struct st_gpio_from_ppr0 */
    volatile uint16_t PPR2;                                   /*  PPR2            */
    volatile uint8_t   dummy362[2];                            /*                  */
/* end of struct st_gpio_from_ppr0 */
/* start of struct st_gpio_from_ppr0 */
    volatile uint16_t PPR3;                                   /*  PPR3            */
    volatile uint8_t   dummy363[2];                            /*                  */
/* end of struct st_gpio_from_ppr0 */
/* start of struct st_gpio_from_ppr0 */
    volatile uint16_t PPR4;                                   /*  PPR4            */
    volatile uint8_t   dummy364[2];                            /*                  */
/* end of struct st_gpio_from_ppr0 */
/* start of struct st_gpio_from_ppr0 */
    volatile uint16_t PPR5;                                   /*  PPR5            */
    volatile uint8_t   dummy365[2];                            /*                  */
/* end of struct st_gpio_from_ppr0 */
/* start of struct st_gpio_from_ppr0 */
    volatile uint16_t PPR6;                                   /*  PPR6            */
    volatile uint8_t   dummy366[2];                            /*                  */
/* end of struct st_gpio_from_ppr0 */
/* start of struct st_gpio_from_ppr0 */
    volatile uint16_t PPR7;                                   /*  PPR7            */
    volatile uint8_t   dummy367[2];                            /*                  */
/* end of struct st_gpio_from_ppr0 */
/* start of struct st_gpio_from_ppr0 */
    volatile uint16_t PPR8;                                   /*  PPR8            */
    volatile uint8_t   dummy368[2];                            /*                  */
/* end of struct st_gpio_from_ppr0 */
/* start of struct st_gpio_from_ppr0 */
    volatile uint16_t PPR9;                                   /*  PPR9            */
    volatile uint8_t   dummy369[2];                            /*                  */
/* end of struct st_gpio_from_ppr0 */
/* start of struct st_gpio_from_ppr0 */
    volatile uint16_t PPR10;                                  /*  PPR10           */
    volatile uint8_t   dummy370[2];                            /*                  */
/* end of struct st_gpio_from_ppr0 */
/* start of struct st_gpio_from_ppr0 */
    volatile uint16_t PPR11;                                  /*  PPR11           */
    volatile uint8_t   dummy3710[2];                           /*                  */
/* end of struct st_gpio_from_ppr0 */
    volatile uint8_t   dummy3711[212];                         /*                  */
/* start of struct st_gpio_from_pm1 */
    volatile uint16_t PM1;                                    /*  PM1             */
    volatile uint8_t   dummy372[2];                            /*                  */
/* end of struct st_gpio_from_pm1 */
/* start of struct st_gpio_from_pm1 */
    volatile uint16_t PM2;                                    /*  PM2             */
    volatile uint8_t   dummy373[2];                            /*                  */
/* end of struct st_gpio_from_pm1 */
/* start of struct st_gpio_from_pm1 */
    volatile uint16_t PM3;                                    /*  PM3             */
    volatile uint8_t   dummy374[2];                            /*                  */
/* end of struct st_gpio_from_pm1 */
/* start of struct st_gpio_from_pm1 */
    volatile uint16_t PM4;                                    /*  PM4             */
    volatile uint8_t   dummy375[2];                            /*                  */
/* end of struct st_gpio_from_pm1 */
/* start of struct st_gpio_from_pm1 */
    volatile uint16_t PM5;                                    /*  PM5             */
    volatile uint8_t   dummy376[2];                            /*                  */
/* end of struct st_gpio_from_pm1 */
/* start of struct st_gpio_from_pm1 */
    volatile uint16_t PM6;                                    /*  PM6             */
    volatile uint8_t   dummy377[2];                            /*                  */
/* end of struct st_gpio_from_pm1 */
/* start of struct st_gpio_from_pm1 */
    volatile uint16_t PM7;                                    /*  PM7             */
    volatile uint8_t   dummy378[2];                            /*                  */
/* end of struct st_gpio_from_pm1 */
/* start of struct st_gpio_from_pm1 */
    volatile uint16_t PM8;                                    /*  PM8             */
    volatile uint8_t   dummy379[2];                            /*                  */
/* end of struct st_gpio_from_pm1 */
/* start of struct st_gpio_from_pm1 */
    volatile uint16_t PM9;                                    /*  PM9             */
    volatile uint8_t   dummy380[2];                            /*                  */
/* end of struct st_gpio_from_pm1 */
/* start of struct st_gpio_from_pm1 */
    volatile uint16_t PM10;                                   /*  PM10            */
    volatile uint8_t   dummy381[2];                            /*                  */
/* end of struct st_gpio_from_pm1 */
/* start of struct st_gpio_from_pm1 */
    volatile uint16_t PM11;                                   /*  PM11            */
    volatile uint8_t   dummy3820[2];                           /*                  */
/* end of struct st_gpio_from_pm1 */
    volatile uint8_t   dummy3821[208];                         /*                  */
/* start of struct st_gpio_from_pmc0 */
    volatile uint16_t PMC0;                                   /*  PMC0            */
    volatile uint8_t   dummy383[2];                            /*                  */
/* end of struct st_gpio_from_pmc0 */
/* start of struct st_gpio_from_pmc0 */
    volatile uint16_t PMC1;                                   /*  PMC1            */
    volatile uint8_t   dummy384[2];                            /*                  */
/* end of struct st_gpio_from_pmc0 */
/* start of struct st_gpio_from_pmc0 */
    volatile uint16_t PMC2;                                   /*  PMC2            */
    volatile uint8_t   dummy385[2];                            /*                  */
/* end of struct st_gpio_from_pmc0 */
/* start of struct st_gpio_from_pmc0 */
    volatile uint16_t PMC3;                                   /*  PMC3            */
    volatile uint8_t   dummy386[2];                            /*                  */
/* end of struct st_gpio_from_pmc0 */
/* start of struct st_gpio_from_pmc0 */
    volatile uint16_t PMC4;                                   /*  PMC4            */
    volatile uint8_t   dummy387[2];                            /*                  */
/* end of struct st_gpio_from_pmc0 */
/* start of struct st_gpio_from_pmc0 */
    volatile uint16_t PMC5;                                   /*  PMC5            */
    volatile uint8_t   dummy388[2];                            /*                  */
/* end of struct st_gpio_from_pmc0 */
/* start of struct st_gpio_from_pmc0 */
    volatile uint16_t PMC6;                                   /*  PMC6            */
    volatile uint8_t   dummy389[2];                            /*                  */
/* end of struct st_gpio_from_pmc0 */
/* start of struct st_gpio_from_pmc0 */
    volatile uint16_t PMC7;                                   /*  PMC7            */
    volatile uint8_t   dummy390[2];                            /*                  */
/* end of struct st_gpio_from_pmc0 */
/* start of struct st_gpio_from_pmc0 */
    volatile uint16_t PMC8;                                   /*  PMC8            */
    volatile uint8_t   dummy391[2];                            /*                  */
/* end of struct st_gpio_from_pmc0 */
/* start of struct st_gpio_from_pmc0 */
    volatile uint16_t PMC9;                                   /*  PMC9            */
    volatile uint8_t   dummy392[2];                            /*                  */
/* end of struct st_gpio_from_pmc0 */
/* start of struct st_gpio_from_pmc0 */
    volatile uint16_t PMC10;                                  /*  PMC10           */
    volatile uint8_t   dummy393[2];                            /*                  */
/* end of struct st_gpio_from_pmc0 */
/* start of struct st_gpio_from_pmc0 */
    volatile uint16_t PMC11;                                  /*  PMC11           */
    volatile uint8_t   dummy3940[2];                           /*                  */
/* end of struct st_gpio_from_pmc0 */
    volatile uint8_t   dummy3941[212];                         /*                  */
/* start of struct st_gpio_from_pfc1 */
    volatile uint16_t PFC1;                                   /*  PFC1            */
    volatile uint8_t   dummy395[2];                            /*                  */
/* end of struct st_gpio_from_pfc1 */
/* start of struct st_gpio_from_pfc1 */
    volatile uint16_t PFC2;                                   /*  PFC2            */
    volatile uint8_t   dummy396[2];                            /*                  */
/* end of struct st_gpio_from_pfc1 */
/* start of struct st_gpio_from_pfc1 */
    volatile uint16_t PFC3;                                   /*  PFC3            */
    volatile uint8_t   dummy397[2];                            /*                  */
/* end of struct st_gpio_from_pfc1 */
/* start of struct st_gpio_from_pfc1 */
    volatile uint16_t PFC4;                                   /*  PFC4            */
    volatile uint8_t   dummy398[2];                            /*                  */
/* end of struct st_gpio_from_pfc1 */
/* start of struct st_gpio_from_pfc1 */
    volatile uint16_t PFC5;                                   /*  PFC5            */
    volatile uint8_t   dummy399[2];                            /*                  */
/* end of struct st_gpio_from_pfc1 */
/* start of struct st_gpio_from_pfc1 */
    volatile uint16_t PFC6;                                   /*  PFC6            */
    volatile uint8_t   dummy400[2];                            /*                  */
/* end of struct st_gpio_from_pfc1 */
/* start of struct st_gpio_from_pfc1 */
    volatile uint16_t PFC7;                                   /*  PFC7            */
    volatile uint8_t   dummy401[2];                            /*                  */
/* end of struct st_gpio_from_pfc1 */
/* start of struct st_gpio_from_pfc1 */
    volatile uint16_t PFC8;                                   /*  PFC8            */
    volatile uint8_t   dummy402[2];                            /*                  */
/* end of struct st_gpio_from_pfc1 */
/* start of struct st_gpio_from_pfc1 */
    volatile uint16_t PFC9;                                   /*  PFC9            */
    volatile uint8_t   dummy403[2];                            /*                  */
/* end of struct st_gpio_from_pfc1 */
/* start of struct st_gpio_from_pfc1 */
    volatile uint16_t PFC10;                                  /*  PFC10           */
    volatile uint8_t   dummy404[2];                            /*                  */
/* end of struct st_gpio_from_pfc1 */
/* start of struct st_gpio_from_pfc1 */
    volatile uint16_t PFC11;                                  /*  PFC11           */
    volatile uint8_t   dummy4050[2];                           /*                  */
/* end of struct st_gpio_from_pfc1 */
    volatile uint8_t   dummy4051[212];                         /*                  */
/* start of struct st_gpio_from_pfce1 */
    volatile uint16_t PFCE1;                                  /*  PFCE1           */
    volatile uint8_t   dummy406[2];                            /*                  */
/* end of struct st_gpio_from_pfce1 */
/* start of struct st_gpio_from_pfce1 */
    volatile uint16_t PFCE2;                                  /*  PFCE2           */
    volatile uint8_t   dummy407[2];                            /*                  */
/* end of struct st_gpio_from_pfce1 */
/* start of struct st_gpio_from_pfce1 */
    volatile uint16_t PFCE3;                                  /*  PFCE3           */
    volatile uint8_t   dummy408[2];                            /*                  */
/* end of struct st_gpio_from_pfce1 */
/* start of struct st_gpio_from_pfce1 */
    volatile uint16_t PFCE4;                                  /*  PFCE4           */
    volatile uint8_t   dummy409[2];                            /*                  */
/* end of struct st_gpio_from_pfce1 */
/* start of struct st_gpio_from_pfce1 */
    volatile uint16_t PFCE5;                                  /*  PFCE5           */
    volatile uint8_t   dummy410[2];                            /*                  */
/* end of struct st_gpio_from_pfce1 */
/* start of struct st_gpio_from_pfce1 */
    volatile uint16_t PFCE6;                                  /*  PFCE6           */
    volatile uint8_t   dummy411[2];                            /*                  */
/* end of struct st_gpio_from_pfce1 */
/* start of struct st_gpio_from_pfce1 */
    volatile uint16_t PFCE7;                                  /*  PFCE7           */
    volatile uint8_t   dummy412[2];                            /*                  */
/* end of struct st_gpio_from_pfce1 */
/* start of struct st_gpio_from_pfce1 */
    volatile uint16_t PFCE8;                                  /*  PFCE8           */
    volatile uint8_t   dummy413[2];                            /*                  */
/* end of struct st_gpio_from_pfce1 */
/* start of struct st_gpio_from_pfce1 */
    volatile uint16_t PFCE9;                                  /*  PFCE9           */
    volatile uint8_t   dummy414[2];                            /*                  */
/* end of struct st_gpio_from_pfce1 */
/* start of struct st_gpio_from_pfce1 */
    volatile uint16_t PFCE10;                                 /*  PFCE10          */
    volatile uint8_t   dummy415[2];                            /*                  */
/* end of struct st_gpio_from_pfce1 */
/* start of struct st_gpio_from_pfce1 */
    volatile uint16_t PFCE11;                                 /*  PFCE11          */
    volatile uint8_t   dummy4160[2];                           /*                  */
/* end of struct st_gpio_from_pfce1 */
    volatile uint8_t   dummy4161[212];                         /*                  */
/* start of struct st_gpio_from_pnot1 */
    volatile uint16_t PNOT1;                                  /*  PNOT1           */
    volatile uint8_t   dummy417[2];                            /*                  */
/* end of struct st_gpio_from_pnot1 */
/* start of struct st_gpio_from_pnot1 */
    volatile uint16_t PNOT2;                                  /*  PNOT2           */
    volatile uint8_t   dummy418[2];                            /*                  */
/* end of struct st_gpio_from_pnot1 */
/* start of struct st_gpio_from_pnot1 */
    volatile uint16_t PNOT3;                                  /*  PNOT3           */
    volatile uint8_t   dummy419[2];                            /*                  */
/* end of struct st_gpio_from_pnot1 */
/* start of struct st_gpio_from_pnot1 */
    volatile uint16_t PNOT4;                                  /*  PNOT4           */
    volatile uint8_t   dummy420[2];                            /*                  */
/* end of struct st_gpio_from_pnot1 */
/* start of struct st_gpio_from_pnot1 */
    volatile uint16_t PNOT5;                                  /*  PNOT5           */
    volatile uint8_t   dummy421[2];                            /*                  */
/* end of struct st_gpio_from_pnot1 */
/* start of struct st_gpio_from_pnot1 */
    volatile uint16_t PNOT6;                                  /*  PNOT6           */
    volatile uint8_t   dummy422[2];                            /*                  */
/* end of struct st_gpio_from_pnot1 */
/* start of struct st_gpio_from_pnot1 */
    volatile uint16_t PNOT7;                                  /*  PNOT7           */
    volatile uint8_t   dummy423[2];                            /*                  */
/* end of struct st_gpio_from_pnot1 */
/* start of struct st_gpio_from_pnot1 */
    volatile uint16_t PNOT8;                                  /*  PNOT8           */
    volatile uint8_t   dummy424[2];                            /*                  */
/* end of struct st_gpio_from_pnot1 */
/* start of struct st_gpio_from_pnot1 */
    volatile uint16_t PNOT9;                                  /*  PNOT9           */
    volatile uint8_t   dummy425[2];                            /*                  */
/* end of struct st_gpio_from_pnot1 */
/* start of struct st_gpio_from_pnot1 */
    volatile uint16_t PNOT10;                                 /*  PNOT10          */
    volatile uint8_t   dummy426[2];                            /*                  */
/* end of struct st_gpio_from_pnot1 */
/* start of struct st_gpio_from_pnot1 */
    volatile uint16_t PNOT11;                                 /*  PNOT11          */
    volatile uint8_t   dummy4270[2];                           /*                  */
/* end of struct st_gpio_from_pnot1 */
    volatile uint8_t   dummy4271[212];                         /*                  */

    volatile uint32_t  PMSR1;                                  /*  PMSR1           */
    volatile uint32_t  PMSR2;                                  /*  PMSR2           */
    volatile uint32_t  PMSR3;                                  /*  PMSR3           */
    volatile uint32_t  PMSR4;                                  /*  PMSR4           */
    volatile uint32_t  PMSR5;                                  /*  PMSR5           */
    volatile uint32_t  PMSR6;                                  /*  PMSR6           */
    volatile uint32_t  PMSR7;                                  /*  PMSR7           */
    volatile uint32_t  PMSR8;                                  /*  PMSR8           */
    volatile uint32_t  PMSR9;                                  /*  PMSR9           */
    volatile uint32_t  PMSR10;                                 /*  PMSR10          */
    volatile uint32_t  PMSR11;                                 /*  PMSR11          */
    volatile uint8_t   dummy428[208];                          /*                  */

    volatile uint32_t  PMCSR0;                                 /*  PMCSR0          */
    volatile uint32_t  PMCSR1;                                 /*  PMCSR1          */
    volatile uint32_t  PMCSR2;                                 /*  PMCSR2          */
    volatile uint32_t  PMCSR3;                                 /*  PMCSR3          */
    volatile uint32_t  PMCSR4;                                 /*  PMCSR4          */
    volatile uint32_t  PMCSR5;                                 /*  PMCSR5          */
    volatile uint32_t  PMCSR6;                                 /*  PMCSR6          */
    volatile uint32_t  PMCSR7;                                 /*  PMCSR7          */
    volatile uint32_t  PMCSR8;                                 /*  PMCSR8          */
    volatile uint32_t  PMCSR9;                                 /*  PMCSR9          */
    volatile uint32_t  PMCSR10;                                /*  PMCSR10         */
    volatile uint32_t  PMCSR11;                                /*  PMCSR11         */
    volatile uint8_t   dummy429[212];                          /*                  */
/* start of struct st_gpio_from_pfcae1 */
    volatile uint16_t PFCAE1;                                 /*  PFCAE1          */
    volatile uint8_t   dummy430[2];                            /*                  */
/* end of struct st_gpio_from_pfcae1 */
/* start of struct st_gpio_from_pfcae1 */
    volatile uint16_t PFCAE2;                                 /*  PFCAE2          */
    volatile uint8_t   dummy431[2];                            /*                  */
/* end of struct st_gpio_from_pfcae1 */
/* start of struct st_gpio_from_pfcae1 */
    volatile uint16_t PFCAE3;                                 /*  PFCAE3          */
    volatile uint8_t   dummy432[2];                            /*                  */
/* end of struct st_gpio_from_pfcae1 */
/* start of struct st_gpio_from_pfcae1 */
    volatile uint16_t PFCAE4;                                 /*  PFCAE4          */
    volatile uint8_t   dummy433[2];                            /*                  */
/* end of struct st_gpio_from_pfcae1 */
/* start of struct st_gpio_from_pfcae1 */
    volatile uint16_t PFCAE5;                                 /*  PFCAE5          */
    volatile uint8_t   dummy434[2];                            /*                  */
/* end of struct st_gpio_from_pfcae1 */
/* start of struct st_gpio_from_pfcae1 */
    volatile uint16_t PFCAE6;                                 /*  PFCAE6          */
    volatile uint8_t   dummy435[2];                            /*                  */
/* end of struct st_gpio_from_pfcae1 */
/* start of struct st_gpio_from_pfcae1 */
    volatile uint16_t PFCAE7;                                 /*  PFCAE7          */
    volatile uint8_t   dummy436[2];                            /*                  */
/* end of struct st_gpio_from_pfcae1 */
/* start of struct st_gpio_from_pfcae1 */
    volatile uint16_t PFCAE8;                                 /*  PFCAE8          */
    volatile uint8_t   dummy437[2];                            /*                  */
/* end of struct st_gpio_from_pfcae1 */
/* start of struct st_gpio_from_pfcae1 */
    volatile uint16_t PFCAE9;                                 /*  PFCAE9          */
    volatile uint8_t   dummy438[2];                            /*                  */
/* end of struct st_gpio_from_pfcae1 */
/* start of struct st_gpio_from_pfcae1 */
    volatile uint16_t PFCAE10;                                /*  PFCAE10         */
    volatile uint8_t   dummy439[2];                            /*                  */
/* end of struct st_gpio_from_pfcae1 */
/* start of struct st_gpio_from_pfcae1 */
    volatile uint16_t PFCAE11;                                /*  PFCAE11         */
    volatile uint8_t   dummy4400[2];                           /*                  */
/* end of struct st_gpio_from_pfcae1 */
    volatile uint8_t   dummy4401[464];                         /*                  */
    volatile uint32_t  SNCR;                                   /*  SNCR            */
    volatile uint8_t   dummy441[13308];                        /*                  */
    volatile uint16_t PIBC0;                                  /*  PIBC0           */
    volatile uint8_t   dummy442[2];                            /*                  */
/* start of struct st_gpio_from_pibc1 */
    volatile uint16_t PIBC1;                                  /*  PIBC1           */
    volatile uint8_t   dummy443[2];                            /*                  */
/* end of struct st_gpio_from_pibc1 */
/* start of struct st_gpio_from_pibc1 */
    volatile uint16_t PIBC2;                                  /*  PIBC2           */
    volatile uint8_t   dummy444[2];                            /*                  */
/* end of struct st_gpio_from_pibc1 */
/* start of struct st_gpio_from_pibc1 */
    volatile uint16_t PIBC3;                                  /*  PIBC3           */
    volatile uint8_t   dummy445[2];                            /*                  */
/* end of struct st_gpio_from_pibc1 */
/* start of struct st_gpio_from_pibc1 */
    volatile uint16_t PIBC4;                                  /*  PIBC4           */
    volatile uint8_t   dummy446[2];                            /*                  */
/* end of struct st_gpio_from_pibc1 */
/* start of struct st_gpio_from_pibc1 */
    volatile uint16_t PIBC5;                                  /*  PIBC5           */
    volatile uint8_t   dummy447[2];                            /*                  */
/* end of struct st_gpio_from_pibc1 */
/* start of struct st_gpio_from_pibc1 */
    volatile uint16_t PIBC6;                                  /*  PIBC6           */
    volatile uint8_t   dummy448[2];                            /*                  */
/* end of struct st_gpio_from_pibc1 */
/* start of struct st_gpio_from_pibc1 */
    volatile uint16_t PIBC7;                                  /*  PIBC7           */
    volatile uint8_t   dummy449[2];                            /*                  */
/* end of struct st_gpio_from_pibc1 */
/* start of struct st_gpio_from_pibc1 */
    volatile uint16_t PIBC8;                                  /*  PIBC8           */
    volatile uint8_t   dummy450[2];                            /*                  */
/* end of struct st_gpio_from_pibc1 */
/* start of struct st_gpio_from_pibc1 */
    volatile uint16_t PIBC9;                                  /*  PIBC9           */
    volatile uint8_t   dummy451[2];                            /*                  */
/* end of struct st_gpio_from_pibc1 */
/* start of struct st_gpio_from_pibc1 */
    volatile uint16_t PIBC10;                                 /*  PIBC10          */
    volatile uint8_t   dummy452[2];                            /*                  */
/* end of struct st_gpio_from_pibc1 */
/* start of struct st_gpio_from_pibc1 */
    volatile uint16_t PIBC11;                                 /*  PIBC11          */
    volatile uint8_t   dummy4530[2];                           /*                  */
/* end of struct st_gpio_from_pibc1 */
    volatile uint8_t   dummy4531[212];                         /*                  */
/* start of struct st_gpio_from_pbdc1 */
    volatile uint16_t PBDC1;                                  /*  PBDC1           */
    volatile uint8_t   dummy454[2];                            /*                  */
/* end of struct st_gpio_from_pbdc1 */
/* start of struct st_gpio_from_pbdc1 */
    volatile uint16_t PBDC2;                                  /*  PBDC2           */
    volatile uint8_t   dummy455[2];                            /*                  */
/* end of struct st_gpio_from_pbdc1 */
/* start of struct st_gpio_from_pbdc1 */
    volatile uint16_t PBDC3;                                  /*  PBDC3           */
    volatile uint8_t   dummy456[2];                            /*                  */
/* end of struct st_gpio_from_pbdc1 */
/* start of struct st_gpio_from_pbdc1 */
    volatile uint16_t PBDC4;                                  /*  PBDC4           */
    volatile uint8_t   dummy457[2];                            /*                  */
/* end of struct st_gpio_from_pbdc1 */
/* start of struct st_gpio_from_pbdc1 */
    volatile uint16_t PBDC5;                                  /*  PBDC5           */
    volatile uint8_t   dummy458[2];                            /*                  */
/* end of struct st_gpio_from_pbdc1 */
/* start of struct st_gpio_from_pbdc1 */
    volatile uint16_t PBDC6;                                  /*  PBDC6           */
    volatile uint8_t   dummy459[2];                            /*                  */
/* end of struct st_gpio_from_pbdc1 */
/* start of struct st_gpio_from_pbdc1 */
    volatile uint16_t PBDC7;                                  /*  PBDC7           */
    volatile uint8_t   dummy460[2];                            /*                  */
/* end of struct st_gpio_from_pbdc1 */
/* start of struct st_gpio_from_pbdc1 */
    volatile uint16_t PBDC8;                                  /*  PBDC8           */
    volatile uint8_t   dummy461[2];                            /*                  */
/* end of struct st_gpio_from_pbdc1 */
/* start of struct st_gpio_from_pbdc1 */
    volatile uint16_t PBDC9;                                  /*  PBDC9           */
    volatile uint8_t   dummy462[2];                            /*                  */
/* end of struct st_gpio_from_pbdc1 */
/* start of struct st_gpio_from_pbdc1 */
    volatile uint16_t PBDC10;                                 /*  PBDC10          */
    volatile uint8_t   dummy463[2];                            /*                  */
/* end of struct st_gpio_from_pbdc1 */
/* start of struct st_gpio_from_pbdc1 */
    volatile uint16_t PBDC11;                                 /*  PBDC11          */
    volatile uint8_t   dummy4640[2];                           /*                  */
/* end of struct st_gpio_from_pbdc1 */
    volatile uint8_t   dummy4641[212];                         /*                  */
/* start of struct st_gpio_from_pipc1 */
    volatile uint16_t PIPC1;                                  /*  PIPC1           */
    volatile uint8_t   dummy465[2];                            /*                  */
/* end of struct st_gpio_from_pipc1 */
/* start of struct st_gpio_from_pipc1 */
    volatile uint16_t PIPC2;                                  /*  PIPC2           */
    volatile uint8_t   dummy466[2];                            /*                  */
/* end of struct st_gpio_from_pipc1 */
/* start of struct st_gpio_from_pipc1 */
    volatile uint16_t PIPC3;                                  /*  PIPC3           */
    volatile uint8_t   dummy467[2];                            /*                  */
/* end of struct st_gpio_from_pipc1 */
/* start of struct st_gpio_from_pipc1 */
    volatile uint16_t PIPC4;                                  /*  PIPC4           */
    volatile uint8_t   dummy468[2];                            /*                  */
/* end of struct st_gpio_from_pipc1 */
/* start of struct st_gpio_from_pipc1 */
    volatile uint16_t PIPC5;                                  /*  PIPC5           */
    volatile uint8_t   dummy469[2];                            /*                  */
/* end of struct st_gpio_from_pipc1 */
/* start of struct st_gpio_from_pipc1 */
    volatile uint16_t PIPC6;                                  /*  PIPC6           */
    volatile uint8_t   dummy470[2];                            /*                  */
/* end of struct st_gpio_from_pipc1 */
/* start of struct st_gpio_from_pipc1 */
    volatile uint16_t PIPC7;                                  /*  PIPC7           */
    volatile uint8_t   dummy471[2];                            /*                  */
/* end of struct st_gpio_from_pipc1 */
/* start of struct st_gpio_from_pipc1 */
    volatile uint16_t PIPC8;                                  /*  PIPC8           */
    volatile uint8_t   dummy472[2];                            /*                  */
/* end of struct st_gpio_from_pipc1 */
/* start of struct st_gpio_from_pipc1 */
    volatile uint16_t PIPC9;                                  /*  PIPC9           */
    volatile uint8_t   dummy473[2];                            /*                  */
/* end of struct st_gpio_from_pipc1 */
/* start of struct st_gpio_from_pipc1 */
    volatile uint16_t PIPC10;                                 /*  PIPC10          */
    volatile uint8_t   dummy474[2];                            /*                  */
/* end of struct st_gpio_from_pipc1 */
/* start of struct st_gpio_from_pipc1 */
    volatile uint16_t PIPC11;                                 /*  PIPC11          */
    volatile uint8_t   dummy4750[2];                           /*                  */
/* end of struct st_gpio_from_pipc1 */
    volatile uint8_t   dummy4751[2288];                        /*                  */
    volatile uint16_t JPPR0;                                  /*  JPPR0           */
    volatile uint8_t   dummy476[30];                           /*                  */
    volatile uint16_t JPMC0;                                  /*  JPMC0           */
    volatile uint8_t   dummy477[78];                           /*                  */
    volatile uint32_t  JPMCSR0;                                /*  JPMCSR0         */
    volatile uint8_t   dummy478[876];                          /*                  */
    volatile uint16_t JPIBC0;                                 /*  JPIBC0          */
};


struct st_gpio_from_p1
{
    volatile uint16_t P1;                                     /*  P1              */
    volatile uint8_t   dummy1[3];                              /*                  */
};


struct st_gpio_from_ppr0
{
    volatile uint16_t PPR0;                                   /*  PPR0            */
    volatile uint8_t   dummy1[2];                              /*                  */
};


struct st_gpio_from_pm1
{
    volatile uint16_t PM1;                                    /*  PM1             */
    volatile uint8_t   dummy1[2];                              /*                  */
};


struct st_gpio_from_pmc0
{
    volatile uint16_t PMC0;                                   /*  PMC0            */
    volatile uint8_t   dummy1[2];                              /*                  */
};


struct st_gpio_from_pfc1
{
    volatile uint16_t PFC1;                                   /*  PFC1            */
    volatile uint8_t   dummy1[2];                              /*                  */
};


struct st_gpio_from_pfce1
{
    volatile uint16_t PFCE1;                                  /*  PFCE1           */
    volatile uint8_t   dummy1[2];                              /*                  */
};


struct st_gpio_from_pnot1
{
    volatile uint16_t PNOT1;                                  /*  PNOT1           */
    volatile uint8_t   dummy1[2];                              /*                  */
};


struct st_gpio_from_pfcae1
{
    volatile uint16_t PFCAE1;                                 /*  PFCAE1          */
    volatile uint8_t   dummy1[2];                              /*                  */
};


struct st_gpio_from_pibc1
{
    volatile uint16_t PIBC1;                                  /*  PIBC1           */
    volatile uint8_t   dummy1[2];                              /*                  */
};


struct st_gpio_from_pbdc1
{
    volatile uint16_t PBDC1;                                  /*  PBDC1           */
    volatile uint8_t   dummy1[2];                              /*                  */
};


struct st_gpio_from_pipc1
{
    volatile uint16_t PIPC1;                                  /*  PIPC1           */
    volatile uint8_t   dummy1[2];                              /*                  */
};





/* Start of channnel array defines of GPIO */

/* Channnel array defines of GPIO_FROM_PIPC1_ARRAY */
/*(Sample) value = GPIO_FROM_PIPC1_ARRAY[ channel ]->PIPC1; */
#line 694 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/gpio_iodefine.h"


/* Channnel array defines of GPIO_FROM_PBDC1_ARRAY */
/*(Sample) value = GPIO_FROM_PBDC1_ARRAY[ channel ]->PBDC1; */
#line 715 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/gpio_iodefine.h"


/* Channnel array defines of GPIO_FROM_PIBC1_ARRAY */
/*(Sample) value = GPIO_FROM_PIBC1_ARRAY[ channel ]->PIBC1; */
#line 736 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/gpio_iodefine.h"


/* Channnel array defines of GPIO_FROM_PFCAE1_ARRAY */
/*(Sample) value = GPIO_FROM_PFCAE1_ARRAY[ channel ]->PFCAE1; */
#line 757 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/gpio_iodefine.h"


/* Channnel array defines of GPIO_FROM_PNOT1_ARRAY */
/*(Sample) value = GPIO_FROM_PNOT1_ARRAY[ channel ]->PNOT1; */
#line 778 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/gpio_iodefine.h"


/* Channnel array defines of GPIO_FROM_PFCE1_ARRAY */
/*(Sample) value = GPIO_FROM_PFCE1_ARRAY[ channel ]->PFCE1; */
#line 799 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/gpio_iodefine.h"


/* Channnel array defines of GPIO_FROM_PFC1_ARRAY */
/*(Sample) value = GPIO_FROM_PFC1_ARRAY[ channel ]->PFC1; */
#line 820 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/gpio_iodefine.h"


/* Channnel array defines of GPIO_FROM_PMC0_ARRAY */
/*(Sample) value = GPIO_FROM_PMC0_ARRAY[ channel ]->PMC0; */
#line 842 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/gpio_iodefine.h"


/* Channnel array defines of GPIO_FROM_PM1_ARRAY */
/*(Sample) value = GPIO_FROM_PM1_ARRAY[ channel ]->PM1; */
#line 863 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/gpio_iodefine.h"


/* Channnel array defines of GPIO_FROM_PPR0_ARRAY */
/*(Sample) value = GPIO_FROM_PPR0_ARRAY[ channel ]->PPR0; */
#line 885 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/gpio_iodefine.h"


/* Channnel array defines of GPIO_FROM_P1_ARRAY */
/*(Sample) value = GPIO_FROM_P1_ARRAY[ channel ]->P1; */
#line 906 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/gpio_iodefine.h"

/* End of channnel array defines of GPIO */


#line 1073 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/gpio_iodefine.h"
/* <-SEC M1.10.1 */
/* <-QAC 0639 */
#line 107 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/ieb_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : ieb_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_ieb
{                                                          /* IEB              */
    volatile uint8_t   B0BCR;                                  /*  B0BCR           */
    volatile uint8_t   dummy495[3];                            /*                  */
    volatile uint8_t   B0PSR;                                  /*  B0PSR           */
    volatile uint8_t   dummy496[3];                            /*                  */
    volatile uint16_t B0UAR;                                  /*  B0UAR           */
    volatile uint8_t   dummy497[2];                            /*                  */
    volatile uint16_t B0SAR;                                  /*  B0SAR           */
    volatile uint8_t   dummy498[2];                            /*                  */
    volatile uint16_t B0PAR;                                  /*  B0PAR           */
    volatile uint8_t   dummy499[2];                            /*                  */
    volatile uint16_t B0RSA;                                  /*  B0RSA           */
    volatile uint8_t   dummy500[2];                            /*                  */
    volatile uint8_t   B0CDR;                                  /*  B0CDR           */
    volatile uint8_t   dummy501[3];                            /*                  */
    volatile uint8_t   B0TCD;                                  /*  B0TCD           */
    volatile uint8_t   dummy502[3];                            /*                  */
    volatile uint8_t   B0RCD;                                  /*  B0RCD           */
    volatile uint8_t   dummy503[3];                            /*                  */
    volatile uint8_t   B0DLR;                                  /*  B0DLR           */
    volatile uint8_t   dummy504[3];                            /*                  */
    volatile uint8_t   B0TDL;                                  /*  B0TDL           */
    volatile uint8_t   dummy505[3];                            /*                  */
    volatile uint8_t   B0RDL;                                  /*  B0RDL           */
    volatile uint8_t   dummy506[3];                            /*                  */
    volatile uint8_t   B0CKS;                                  /*  B0CKS           */
    volatile uint8_t   dummy507[3];                            /*                  */
    volatile uint8_t   B0TMS;                                  /*  B0TMS           */
    volatile uint8_t   dummy508[3];                            /*                  */
    volatile uint8_t   B0PCR;                                  /*  B0PCR           */
    volatile uint8_t   dummy509[3];                            /*                  */
    volatile uint16_t B0BSR;                                  /*  B0BSR           */
    volatile uint8_t   dummy510[2];                            /*                  */
    volatile uint8_t   B0SSR;                                  /*  B0SSR           */
    volatile uint8_t   dummy511[3];                            /*                  */
    volatile uint8_t   B0USR;                                  /*  B0USR           */
    volatile uint8_t   dummy512[3];                            /*                  */
    volatile uint8_t   B0ISR;                                  /*  B0ISR           */
    volatile uint8_t   dummy513[3];                            /*                  */
    volatile uint8_t   B0ESR;                                  /*  B0ESR           */
    volatile uint8_t   dummy514[3];                            /*                  */
    volatile uint8_t   B0FSR;                                  /*  B0FSR           */
    volatile uint8_t   dummy515[3];                            /*                  */
    volatile uint8_t   B0SCR;                                  /*  B0SCR           */
    volatile uint8_t   dummy516[3];                            /*                  */
    volatile uint8_t   B0CCR;                                  /*  B0CCR           */
    volatile uint8_t   dummy517[3];                            /*                  */
    volatile uint8_t   B0STC0;                                 /*  B0STC0          */
    volatile uint8_t   dummy518[3];                            /*                  */
    volatile uint8_t   B0STC1;                                 /*  B0STC1          */
    volatile uint8_t   dummy519[3];                            /*                  */
    volatile uint8_t   B0DR;                                   /*  B0DR            */
};





#line 118 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/ieb_iodefine.h"
/* <-SEC M1.10.1 */
#line 108 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/inb_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : inb_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/



struct st_inb
{                                                          /* INB              */
    volatile uint32_t  RMPR;                                   /*  RMPR            */

    volatile uint32_t  AXIBUSCTL0;                             /*  AXIBUSCTL0      */
    volatile uint32_t  AXIBUSCTL1;                             /*  AXIBUSCTL1      */
    volatile uint32_t  AXIBUSCTL2;                             /*  AXIBUSCTL2      */
    volatile uint32_t  AXIBUSCTL3;                             /*  AXIBUSCTL3      */
    volatile uint32_t  AXIBUSCTL4;                             /*  AXIBUSCTL4      */
    volatile uint32_t  AXIBUSCTL5;                             /*  AXIBUSCTL5      */
    volatile uint32_t  AXIBUSCTL6;                             /*  AXIBUSCTL6      */
    volatile uint32_t  AXIBUSCTL7;                             /*  AXIBUSCTL7      */
    volatile uint32_t  AXIBUSCTL8;                             /*  AXIBUSCTL8      */
    volatile uint32_t  AXIBUSCTL9;                             /*  AXIBUSCTL9      */
    volatile uint32_t  AXIBUSCTL10;                            /*  AXIBUSCTL10     */

    volatile uint32_t  AXIRERRCTL0;                            /*  AXIRERRCTL0     */
    volatile uint32_t  AXIRERRCTL1;                            /*  AXIRERRCTL1     */
    volatile uint32_t  AXIRERRCTL2;                            /*  AXIRERRCTL2     */
    volatile uint32_t  AXIRERRCTL3;                            /*  AXIRERRCTL3     */

    volatile uint32_t  AXIRERRST0;                             /*  AXIRERRST0      */
    volatile uint32_t  AXIRERRST1;                             /*  AXIRERRST1      */
    volatile uint32_t  AXIRERRST2;                             /*  AXIRERRST2      */
    volatile uint32_t  AXIRERRST3;                             /*  AXIRERRST3      */

    volatile uint32_t  AXIRERRCLR0;                            /*  AXIRERRCLR0     */
    volatile uint32_t  AXIRERRCLR1;                            /*  AXIRERRCLR1     */
    volatile uint32_t  AXIRERRCLR2;                            /*  AXIRERRCLR2     */
    volatile uint32_t  AXIRERRCLR3;                            /*  AXIRERRCLR3     */
};





#line 109 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/intc_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : intc_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->QAC 0639 : Over 127 members (C90) */
/* ->SEC M1.10.1 : Not magic number */

struct st_intc
{                                                          /* INTC             */
    volatile uint32_t  ICDDCR;                                 /*  ICDDCR          */
    volatile uint32_t  ICDICTR;                                /*  ICDICTR         */
    volatile uint32_t  ICDIIDR;                                /*  ICDIIDR         */
    volatile uint8_t   dummy193[116];                          /*                  */

    volatile uint32_t  ICDISR0;                                /*  ICDISR0         */
    volatile uint32_t  ICDISR1;                                /*  ICDISR1         */
    volatile uint32_t  ICDISR2;                                /*  ICDISR2         */
    volatile uint32_t  ICDISR3;                                /*  ICDISR3         */
    volatile uint32_t  ICDISR4;                                /*  ICDISR4         */
    volatile uint32_t  ICDISR5;                                /*  ICDISR5         */
    volatile uint32_t  ICDISR6;                                /*  ICDISR6         */
    volatile uint32_t  ICDISR7;                                /*  ICDISR7         */
    volatile uint32_t  ICDISR8;                                /*  ICDISR8         */
    volatile uint32_t  ICDISR9;                                /*  ICDISR9         */
    volatile uint32_t  ICDISR10;                               /*  ICDISR10        */
    volatile uint32_t  ICDISR11;                               /*  ICDISR11        */
    volatile uint32_t  ICDISR12;                               /*  ICDISR12        */
    volatile uint32_t  ICDISR13;                               /*  ICDISR13        */
    volatile uint32_t  ICDISR14;                               /*  ICDISR14        */
    volatile uint32_t  ICDISR15;                               /*  ICDISR15        */
    volatile uint32_t  ICDISR16;                               /*  ICDISR16        */
    volatile uint32_t  ICDISR17;                               /*  ICDISR17        */
    volatile uint32_t  ICDISR18;                               /*  ICDISR18        */
    volatile uint8_t   dummy194[52];                           /*                  */

    volatile uint32_t  ICDISER0;                               /*  ICDISER0        */
    volatile uint32_t  ICDISER1;                               /*  ICDISER1        */
    volatile uint32_t  ICDISER2;                               /*  ICDISER2        */
    volatile uint32_t  ICDISER3;                               /*  ICDISER3        */
    volatile uint32_t  ICDISER4;                               /*  ICDISER4        */
    volatile uint32_t  ICDISER5;                               /*  ICDISER5        */
    volatile uint32_t  ICDISER6;                               /*  ICDISER6        */
    volatile uint32_t  ICDISER7;                               /*  ICDISER7        */
    volatile uint32_t  ICDISER8;                               /*  ICDISER8        */
    volatile uint32_t  ICDISER9;                               /*  ICDISER9        */
    volatile uint32_t  ICDISER10;                              /*  ICDISER10       */
    volatile uint32_t  ICDISER11;                              /*  ICDISER11       */
    volatile uint32_t  ICDISER12;                              /*  ICDISER12       */
    volatile uint32_t  ICDISER13;                              /*  ICDISER13       */
    volatile uint32_t  ICDISER14;                              /*  ICDISER14       */
    volatile uint32_t  ICDISER15;                              /*  ICDISER15       */
    volatile uint32_t  ICDISER16;                              /*  ICDISER16       */
    volatile uint32_t  ICDISER17;                              /*  ICDISER17       */
    volatile uint32_t  ICDISER18;                              /*  ICDISER18       */
    volatile uint8_t   dummy195[52];                           /*                  */

    volatile uint32_t  ICDICER0;                               /*  ICDICER0        */
    volatile uint32_t  ICDICER1;                               /*  ICDICER1        */
    volatile uint32_t  ICDICER2;                               /*  ICDICER2        */
    volatile uint32_t  ICDICER3;                               /*  ICDICER3        */
    volatile uint32_t  ICDICER4;                               /*  ICDICER4        */
    volatile uint32_t  ICDICER5;                               /*  ICDICER5        */
    volatile uint32_t  ICDICER6;                               /*  ICDICER6        */
    volatile uint32_t  ICDICER7;                               /*  ICDICER7        */
    volatile uint32_t  ICDICER8;                               /*  ICDICER8        */
    volatile uint32_t  ICDICER9;                               /*  ICDICER9        */
    volatile uint32_t  ICDICER10;                              /*  ICDICER10       */
    volatile uint32_t  ICDICER11;                              /*  ICDICER11       */
    volatile uint32_t  ICDICER12;                              /*  ICDICER12       */
    volatile uint32_t  ICDICER13;                              /*  ICDICER13       */
    volatile uint32_t  ICDICER14;                              /*  ICDICER14       */
    volatile uint32_t  ICDICER15;                              /*  ICDICER15       */
    volatile uint32_t  ICDICER16;                              /*  ICDICER16       */
    volatile uint32_t  ICDICER17;                              /*  ICDICER17       */
    volatile uint32_t  ICDICER18;                              /*  ICDICER18       */
    volatile uint8_t   dummy196[52];                           /*                  */

    volatile uint32_t  ICDISPR0;                               /*  ICDISPR0        */
    volatile uint32_t  ICDISPR1;                               /*  ICDISPR1        */
    volatile uint32_t  ICDISPR2;                               /*  ICDISPR2        */
    volatile uint32_t  ICDISPR3;                               /*  ICDISPR3        */
    volatile uint32_t  ICDISPR4;                               /*  ICDISPR4        */
    volatile uint32_t  ICDISPR5;                               /*  ICDISPR5        */
    volatile uint32_t  ICDISPR6;                               /*  ICDISPR6        */
    volatile uint32_t  ICDISPR7;                               /*  ICDISPR7        */
    volatile uint32_t  ICDISPR8;                               /*  ICDISPR8        */
    volatile uint32_t  ICDISPR9;                               /*  ICDISPR9        */
    volatile uint32_t  ICDISPR10;                              /*  ICDISPR10       */
    volatile uint32_t  ICDISPR11;                              /*  ICDISPR11       */
    volatile uint32_t  ICDISPR12;                              /*  ICDISPR12       */
    volatile uint32_t  ICDISPR13;                              /*  ICDISPR13       */
    volatile uint32_t  ICDISPR14;                              /*  ICDISPR14       */
    volatile uint32_t  ICDISPR15;                              /*  ICDISPR15       */
    volatile uint32_t  ICDISPR16;                              /*  ICDISPR16       */
    volatile uint32_t  ICDISPR17;                              /*  ICDISPR17       */
    volatile uint32_t  ICDISPR18;                              /*  ICDISPR18       */
    volatile uint8_t   dummy197[52];                           /*                  */

    volatile uint32_t  ICDICPR0;                               /*  ICDICPR0        */
    volatile uint32_t  ICDICPR1;                               /*  ICDICPR1        */
    volatile uint32_t  ICDICPR2;                               /*  ICDICPR2        */
    volatile uint32_t  ICDICPR3;                               /*  ICDICPR3        */
    volatile uint32_t  ICDICPR4;                               /*  ICDICPR4        */
    volatile uint32_t  ICDICPR5;                               /*  ICDICPR5        */
    volatile uint32_t  ICDICPR6;                               /*  ICDICPR6        */
    volatile uint32_t  ICDICPR7;                               /*  ICDICPR7        */
    volatile uint32_t  ICDICPR8;                               /*  ICDICPR8        */
    volatile uint32_t  ICDICPR9;                               /*  ICDICPR9        */
    volatile uint32_t  ICDICPR10;                              /*  ICDICPR10       */
    volatile uint32_t  ICDICPR11;                              /*  ICDICPR11       */
    volatile uint32_t  ICDICPR12;                              /*  ICDICPR12       */
    volatile uint32_t  ICDICPR13;                              /*  ICDICPR13       */
    volatile uint32_t  ICDICPR14;                              /*  ICDICPR14       */
    volatile uint32_t  ICDICPR15;                              /*  ICDICPR15       */
    volatile uint32_t  ICDICPR16;                              /*  ICDICPR16       */
    volatile uint32_t  ICDICPR17;                              /*  ICDICPR17       */
    volatile uint32_t  ICDICPR18;                              /*  ICDICPR18       */
    volatile uint8_t   dummy198[52];                           /*                  */

    volatile uint32_t  ICDABR0;                                /*  ICDABR0         */
    volatile uint32_t  ICDABR1;                                /*  ICDABR1         */
    volatile uint32_t  ICDABR2;                                /*  ICDABR2         */
    volatile uint32_t  ICDABR3;                                /*  ICDABR3         */
    volatile uint32_t  ICDABR4;                                /*  ICDABR4         */
    volatile uint32_t  ICDABR5;                                /*  ICDABR5         */
    volatile uint32_t  ICDABR6;                                /*  ICDABR6         */
    volatile uint32_t  ICDABR7;                                /*  ICDABR7         */
    volatile uint32_t  ICDABR8;                                /*  ICDABR8         */
    volatile uint32_t  ICDABR9;                                /*  ICDABR9         */
    volatile uint32_t  ICDABR10;                               /*  ICDABR10        */
    volatile uint32_t  ICDABR11;                               /*  ICDABR11        */
    volatile uint32_t  ICDABR12;                               /*  ICDABR12        */
    volatile uint32_t  ICDABR13;                               /*  ICDABR13        */
    volatile uint32_t  ICDABR14;                               /*  ICDABR14        */
    volatile uint32_t  ICDABR15;                               /*  ICDABR15        */
    volatile uint32_t  ICDABR16;                               /*  ICDABR16        */
    volatile uint32_t  ICDABR17;                               /*  ICDABR17        */
    volatile uint32_t  ICDABR18;                               /*  ICDABR18        */
    volatile uint8_t   dummy199[180];                          /*                  */

    volatile uint32_t  ICDIPR0;                                /*  ICDIPR0         */
    volatile uint32_t  ICDIPR1;                                /*  ICDIPR1         */
    volatile uint32_t  ICDIPR2;                                /*  ICDIPR2         */
    volatile uint32_t  ICDIPR3;                                /*  ICDIPR3         */
    volatile uint32_t  ICDIPR4;                                /*  ICDIPR4         */
    volatile uint32_t  ICDIPR5;                                /*  ICDIPR5         */
    volatile uint32_t  ICDIPR6;                                /*  ICDIPR6         */
    volatile uint32_t  ICDIPR7;                                /*  ICDIPR7         */
    volatile uint32_t  ICDIPR8;                                /*  ICDIPR8         */
    volatile uint32_t  ICDIPR9;                                /*  ICDIPR9         */
    volatile uint32_t  ICDIPR10;                               /*  ICDIPR10        */
    volatile uint32_t  ICDIPR11;                               /*  ICDIPR11        */
    volatile uint32_t  ICDIPR12;                               /*  ICDIPR12        */
    volatile uint32_t  ICDIPR13;                               /*  ICDIPR13        */
    volatile uint32_t  ICDIPR14;                               /*  ICDIPR14        */
    volatile uint32_t  ICDIPR15;                               /*  ICDIPR15        */
    volatile uint32_t  ICDIPR16;                               /*  ICDIPR16        */
    volatile uint32_t  ICDIPR17;                               /*  ICDIPR17        */
    volatile uint32_t  ICDIPR18;                               /*  ICDIPR18        */
    volatile uint32_t  ICDIPR19;                               /*  ICDIPR19        */
    volatile uint32_t  ICDIPR20;                               /*  ICDIPR20        */
    volatile uint32_t  ICDIPR21;                               /*  ICDIPR21        */
    volatile uint32_t  ICDIPR22;                               /*  ICDIPR22        */
    volatile uint32_t  ICDIPR23;                               /*  ICDIPR23        */
    volatile uint32_t  ICDIPR24;                               /*  ICDIPR24        */
    volatile uint32_t  ICDIPR25;                               /*  ICDIPR25        */
    volatile uint32_t  ICDIPR26;                               /*  ICDIPR26        */
    volatile uint32_t  ICDIPR27;                               /*  ICDIPR27        */
    volatile uint32_t  ICDIPR28;                               /*  ICDIPR28        */
    volatile uint32_t  ICDIPR29;                               /*  ICDIPR29        */
    volatile uint32_t  ICDIPR30;                               /*  ICDIPR30        */
    volatile uint32_t  ICDIPR31;                               /*  ICDIPR31        */
    volatile uint32_t  ICDIPR32;                               /*  ICDIPR32        */
    volatile uint32_t  ICDIPR33;                               /*  ICDIPR33        */
    volatile uint32_t  ICDIPR34;                               /*  ICDIPR34        */
    volatile uint32_t  ICDIPR35;                               /*  ICDIPR35        */
    volatile uint32_t  ICDIPR36;                               /*  ICDIPR36        */
    volatile uint32_t  ICDIPR37;                               /*  ICDIPR37        */
    volatile uint32_t  ICDIPR38;                               /*  ICDIPR38        */
    volatile uint32_t  ICDIPR39;                               /*  ICDIPR39        */
    volatile uint32_t  ICDIPR40;                               /*  ICDIPR40        */
    volatile uint32_t  ICDIPR41;                               /*  ICDIPR41        */
    volatile uint32_t  ICDIPR42;                               /*  ICDIPR42        */
    volatile uint32_t  ICDIPR43;                               /*  ICDIPR43        */
    volatile uint32_t  ICDIPR44;                               /*  ICDIPR44        */
    volatile uint32_t  ICDIPR45;                               /*  ICDIPR45        */
    volatile uint32_t  ICDIPR46;                               /*  ICDIPR46        */
    volatile uint32_t  ICDIPR47;                               /*  ICDIPR47        */
    volatile uint32_t  ICDIPR48;                               /*  ICDIPR48        */
    volatile uint32_t  ICDIPR49;                               /*  ICDIPR49        */
    volatile uint32_t  ICDIPR50;                               /*  ICDIPR50        */
    volatile uint32_t  ICDIPR51;                               /*  ICDIPR51        */
    volatile uint32_t  ICDIPR52;                               /*  ICDIPR52        */
    volatile uint32_t  ICDIPR53;                               /*  ICDIPR53        */
    volatile uint32_t  ICDIPR54;                               /*  ICDIPR54        */
    volatile uint32_t  ICDIPR55;                               /*  ICDIPR55        */
    volatile uint32_t  ICDIPR56;                               /*  ICDIPR56        */
    volatile uint32_t  ICDIPR57;                               /*  ICDIPR57        */
    volatile uint32_t  ICDIPR58;                               /*  ICDIPR58        */
    volatile uint32_t  ICDIPR59;                               /*  ICDIPR59        */
    volatile uint32_t  ICDIPR60;                               /*  ICDIPR60        */
    volatile uint32_t  ICDIPR61;                               /*  ICDIPR61        */
    volatile uint32_t  ICDIPR62;                               /*  ICDIPR62        */
    volatile uint32_t  ICDIPR63;                               /*  ICDIPR63        */
    volatile uint32_t  ICDIPR64;                               /*  ICDIPR64        */
    volatile uint32_t  ICDIPR65;                               /*  ICDIPR65        */
    volatile uint32_t  ICDIPR66;                               /*  ICDIPR66        */
    volatile uint32_t  ICDIPR67;                               /*  ICDIPR67        */
    volatile uint32_t  ICDIPR68;                               /*  ICDIPR68        */
    volatile uint32_t  ICDIPR69;                               /*  ICDIPR69        */
    volatile uint32_t  ICDIPR70;                               /*  ICDIPR70        */
    volatile uint32_t  ICDIPR71;                               /*  ICDIPR71        */
    volatile uint32_t  ICDIPR72;                               /*  ICDIPR72        */
    volatile uint32_t  ICDIPR73;                               /*  ICDIPR73        */
    volatile uint32_t  ICDIPR74;                               /*  ICDIPR74        */
    volatile uint32_t  ICDIPR75;                               /*  ICDIPR75        */
    volatile uint32_t  ICDIPR76;                               /*  ICDIPR76        */
    volatile uint32_t  ICDIPR77;                               /*  ICDIPR77        */
    volatile uint32_t  ICDIPR78;                               /*  ICDIPR78        */
    volatile uint32_t  ICDIPR79;                               /*  ICDIPR79        */
    volatile uint32_t  ICDIPR80;                               /*  ICDIPR80        */
    volatile uint32_t  ICDIPR81;                               /*  ICDIPR81        */
    volatile uint32_t  ICDIPR82;                               /*  ICDIPR82        */
    volatile uint32_t  ICDIPR83;                               /*  ICDIPR83        */
    volatile uint32_t  ICDIPR84;                               /*  ICDIPR84        */
    volatile uint32_t  ICDIPR85;                               /*  ICDIPR85        */
    volatile uint32_t  ICDIPR86;                               /*  ICDIPR86        */
    volatile uint32_t  ICDIPR87;                               /*  ICDIPR87        */
    volatile uint32_t  ICDIPR88;                               /*  ICDIPR88        */
    volatile uint32_t  ICDIPR89;                               /*  ICDIPR89        */
    volatile uint32_t  ICDIPR90;                               /*  ICDIPR90        */
    volatile uint32_t  ICDIPR91;                               /*  ICDIPR91        */
    volatile uint32_t  ICDIPR92;                               /*  ICDIPR92        */
    volatile uint32_t  ICDIPR93;                               /*  ICDIPR93        */
    volatile uint32_t  ICDIPR94;                               /*  ICDIPR94        */
    volatile uint32_t  ICDIPR95;                               /*  ICDIPR95        */
    volatile uint32_t  ICDIPR96;                               /*  ICDIPR96        */
    volatile uint32_t  ICDIPR97;                               /*  ICDIPR97        */
    volatile uint32_t  ICDIPR98;                               /*  ICDIPR98        */
    volatile uint32_t  ICDIPR99;                               /*  ICDIPR99        */
    volatile uint32_t  ICDIPR100;                              /*  ICDIPR100       */
    volatile uint32_t  ICDIPR101;                              /*  ICDIPR101       */
    volatile uint32_t  ICDIPR102;                              /*  ICDIPR102       */
    volatile uint32_t  ICDIPR103;                              /*  ICDIPR103       */
    volatile uint32_t  ICDIPR104;                              /*  ICDIPR104       */
    volatile uint32_t  ICDIPR105;                              /*  ICDIPR105       */
    volatile uint32_t  ICDIPR106;                              /*  ICDIPR106       */
    volatile uint32_t  ICDIPR107;                              /*  ICDIPR107       */
    volatile uint32_t  ICDIPR108;                              /*  ICDIPR108       */
    volatile uint32_t  ICDIPR109;                              /*  ICDIPR109       */
    volatile uint32_t  ICDIPR110;                              /*  ICDIPR110       */
    volatile uint32_t  ICDIPR111;                              /*  ICDIPR111       */
    volatile uint32_t  ICDIPR112;                              /*  ICDIPR112       */
    volatile uint32_t  ICDIPR113;                              /*  ICDIPR113       */
    volatile uint32_t  ICDIPR114;                              /*  ICDIPR114       */
    volatile uint32_t  ICDIPR115;                              /*  ICDIPR115       */
    volatile uint32_t  ICDIPR116;                              /*  ICDIPR116       */
    volatile uint32_t  ICDIPR117;                              /*  ICDIPR117       */
    volatile uint32_t  ICDIPR118;                              /*  ICDIPR118       */
    volatile uint32_t  ICDIPR119;                              /*  ICDIPR119       */
    volatile uint32_t  ICDIPR120;                              /*  ICDIPR120       */
    volatile uint32_t  ICDIPR121;                              /*  ICDIPR121       */
    volatile uint32_t  ICDIPR122;                              /*  ICDIPR122       */
    volatile uint32_t  ICDIPR123;                              /*  ICDIPR123       */
    volatile uint32_t  ICDIPR124;                              /*  ICDIPR124       */
    volatile uint32_t  ICDIPR125;                              /*  ICDIPR125       */
    volatile uint32_t  ICDIPR126;                              /*  ICDIPR126       */
    volatile uint32_t  ICDIPR127;                              /*  ICDIPR127       */
    volatile uint32_t  ICDIPR128;                              /*  ICDIPR128       */
    volatile uint32_t  ICDIPR129;                              /*  ICDIPR129       */
    volatile uint32_t  ICDIPR130;                              /*  ICDIPR130       */
    volatile uint32_t  ICDIPR131;                              /*  ICDIPR131       */
    volatile uint32_t  ICDIPR132;                              /*  ICDIPR132       */
    volatile uint32_t  ICDIPR133;                              /*  ICDIPR133       */
    volatile uint32_t  ICDIPR134;                              /*  ICDIPR134       */
    volatile uint32_t  ICDIPR135;                              /*  ICDIPR135       */
    volatile uint32_t  ICDIPR136;                              /*  ICDIPR136       */
    volatile uint32_t  ICDIPR137;                              /*  ICDIPR137       */
    volatile uint32_t  ICDIPR138;                              /*  ICDIPR138       */
    volatile uint32_t  ICDIPR139;                              /*  ICDIPR139       */
    volatile uint32_t  ICDIPR140;                              /*  ICDIPR140       */
    volatile uint32_t  ICDIPR141;                              /*  ICDIPR141       */
    volatile uint32_t  ICDIPR142;                              /*  ICDIPR142       */
    volatile uint32_t  ICDIPR143;                              /*  ICDIPR143       */
    volatile uint32_t  ICDIPR144;                              /*  ICDIPR144       */
    volatile uint32_t  ICDIPR145;                              /*  ICDIPR145       */
    volatile uint32_t  ICDIPR146;                              /*  ICDIPR146       */
    volatile uint8_t   dummy200[436];                          /*                  */

    volatile uint32_t  ICDIPTR0;                               /*  ICDIPTR0        */
    volatile uint32_t  ICDIPTR1;                               /*  ICDIPTR1        */
    volatile uint32_t  ICDIPTR2;                               /*  ICDIPTR2        */
    volatile uint32_t  ICDIPTR3;                               /*  ICDIPTR3        */
    volatile uint32_t  ICDIPTR4;                               /*  ICDIPTR4        */
    volatile uint32_t  ICDIPTR5;                               /*  ICDIPTR5        */
    volatile uint32_t  ICDIPTR6;                               /*  ICDIPTR6        */
    volatile uint32_t  ICDIPTR7;                               /*  ICDIPTR7        */
    volatile uint32_t  ICDIPTR8;                               /*  ICDIPTR8        */
    volatile uint32_t  ICDIPTR9;                               /*  ICDIPTR9        */
    volatile uint32_t  ICDIPTR10;                              /*  ICDIPTR10       */
    volatile uint32_t  ICDIPTR11;                              /*  ICDIPTR11       */
    volatile uint32_t  ICDIPTR12;                              /*  ICDIPTR12       */
    volatile uint32_t  ICDIPTR13;                              /*  ICDIPTR13       */
    volatile uint32_t  ICDIPTR14;                              /*  ICDIPTR14       */
    volatile uint32_t  ICDIPTR15;                              /*  ICDIPTR15       */
    volatile uint32_t  ICDIPTR16;                              /*  ICDIPTR16       */
    volatile uint32_t  ICDIPTR17;                              /*  ICDIPTR17       */
    volatile uint32_t  ICDIPTR18;                              /*  ICDIPTR18       */
    volatile uint32_t  ICDIPTR19;                              /*  ICDIPTR19       */
    volatile uint32_t  ICDIPTR20;                              /*  ICDIPTR20       */
    volatile uint32_t  ICDIPTR21;                              /*  ICDIPTR21       */
    volatile uint32_t  ICDIPTR22;                              /*  ICDIPTR22       */
    volatile uint32_t  ICDIPTR23;                              /*  ICDIPTR23       */
    volatile uint32_t  ICDIPTR24;                              /*  ICDIPTR24       */
    volatile uint32_t  ICDIPTR25;                              /*  ICDIPTR25       */
    volatile uint32_t  ICDIPTR26;                              /*  ICDIPTR26       */
    volatile uint32_t  ICDIPTR27;                              /*  ICDIPTR27       */
    volatile uint32_t  ICDIPTR28;                              /*  ICDIPTR28       */
    volatile uint32_t  ICDIPTR29;                              /*  ICDIPTR29       */
    volatile uint32_t  ICDIPTR30;                              /*  ICDIPTR30       */
    volatile uint32_t  ICDIPTR31;                              /*  ICDIPTR31       */
    volatile uint32_t  ICDIPTR32;                              /*  ICDIPTR32       */
    volatile uint32_t  ICDIPTR33;                              /*  ICDIPTR33       */
    volatile uint32_t  ICDIPTR34;                              /*  ICDIPTR34       */
    volatile uint32_t  ICDIPTR35;                              /*  ICDIPTR35       */
    volatile uint32_t  ICDIPTR36;                              /*  ICDIPTR36       */
    volatile uint32_t  ICDIPTR37;                              /*  ICDIPTR37       */
    volatile uint32_t  ICDIPTR38;                              /*  ICDIPTR38       */
    volatile uint32_t  ICDIPTR39;                              /*  ICDIPTR39       */
    volatile uint32_t  ICDIPTR40;                              /*  ICDIPTR40       */
    volatile uint32_t  ICDIPTR41;                              /*  ICDIPTR41       */
    volatile uint32_t  ICDIPTR42;                              /*  ICDIPTR42       */
    volatile uint32_t  ICDIPTR43;                              /*  ICDIPTR43       */
    volatile uint32_t  ICDIPTR44;                              /*  ICDIPTR44       */
    volatile uint32_t  ICDIPTR45;                              /*  ICDIPTR45       */
    volatile uint32_t  ICDIPTR46;                              /*  ICDIPTR46       */
    volatile uint32_t  ICDIPTR47;                              /*  ICDIPTR47       */
    volatile uint32_t  ICDIPTR48;                              /*  ICDIPTR48       */
    volatile uint32_t  ICDIPTR49;                              /*  ICDIPTR49       */
    volatile uint32_t  ICDIPTR50;                              /*  ICDIPTR50       */
    volatile uint32_t  ICDIPTR51;                              /*  ICDIPTR51       */
    volatile uint32_t  ICDIPTR52;                              /*  ICDIPTR52       */
    volatile uint32_t  ICDIPTR53;                              /*  ICDIPTR53       */
    volatile uint32_t  ICDIPTR54;                              /*  ICDIPTR54       */
    volatile uint32_t  ICDIPTR55;                              /*  ICDIPTR55       */
    volatile uint32_t  ICDIPTR56;                              /*  ICDIPTR56       */
    volatile uint32_t  ICDIPTR57;                              /*  ICDIPTR57       */
    volatile uint32_t  ICDIPTR58;                              /*  ICDIPTR58       */
    volatile uint32_t  ICDIPTR59;                              /*  ICDIPTR59       */
    volatile uint32_t  ICDIPTR60;                              /*  ICDIPTR60       */
    volatile uint32_t  ICDIPTR61;                              /*  ICDIPTR61       */
    volatile uint32_t  ICDIPTR62;                              /*  ICDIPTR62       */
    volatile uint32_t  ICDIPTR63;                              /*  ICDIPTR63       */
    volatile uint32_t  ICDIPTR64;                              /*  ICDIPTR64       */
    volatile uint32_t  ICDIPTR65;                              /*  ICDIPTR65       */
    volatile uint32_t  ICDIPTR66;                              /*  ICDIPTR66       */
    volatile uint32_t  ICDIPTR67;                              /*  ICDIPTR67       */
    volatile uint32_t  ICDIPTR68;                              /*  ICDIPTR68       */
    volatile uint32_t  ICDIPTR69;                              /*  ICDIPTR69       */
    volatile uint32_t  ICDIPTR70;                              /*  ICDIPTR70       */
    volatile uint32_t  ICDIPTR71;                              /*  ICDIPTR71       */
    volatile uint32_t  ICDIPTR72;                              /*  ICDIPTR72       */
    volatile uint32_t  ICDIPTR73;                              /*  ICDIPTR73       */
    volatile uint32_t  ICDIPTR74;                              /*  ICDIPTR74       */
    volatile uint32_t  ICDIPTR75;                              /*  ICDIPTR75       */
    volatile uint32_t  ICDIPTR76;                              /*  ICDIPTR76       */
    volatile uint32_t  ICDIPTR77;                              /*  ICDIPTR77       */
    volatile uint32_t  ICDIPTR78;                              /*  ICDIPTR78       */
    volatile uint32_t  ICDIPTR79;                              /*  ICDIPTR79       */
    volatile uint32_t  ICDIPTR80;                              /*  ICDIPTR80       */
    volatile uint32_t  ICDIPTR81;                              /*  ICDIPTR81       */
    volatile uint32_t  ICDIPTR82;                              /*  ICDIPTR82       */
    volatile uint32_t  ICDIPTR83;                              /*  ICDIPTR83       */
    volatile uint32_t  ICDIPTR84;                              /*  ICDIPTR84       */
    volatile uint32_t  ICDIPTR85;                              /*  ICDIPTR85       */
    volatile uint32_t  ICDIPTR86;                              /*  ICDIPTR86       */
    volatile uint32_t  ICDIPTR87;                              /*  ICDIPTR87       */
    volatile uint32_t  ICDIPTR88;                              /*  ICDIPTR88       */
    volatile uint32_t  ICDIPTR89;                              /*  ICDIPTR89       */
    volatile uint32_t  ICDIPTR90;                              /*  ICDIPTR90       */
    volatile uint32_t  ICDIPTR91;                              /*  ICDIPTR91       */
    volatile uint32_t  ICDIPTR92;                              /*  ICDIPTR92       */
    volatile uint32_t  ICDIPTR93;                              /*  ICDIPTR93       */
    volatile uint32_t  ICDIPTR94;                              /*  ICDIPTR94       */
    volatile uint32_t  ICDIPTR95;                              /*  ICDIPTR95       */
    volatile uint32_t  ICDIPTR96;                              /*  ICDIPTR96       */
    volatile uint32_t  ICDIPTR97;                              /*  ICDIPTR97       */
    volatile uint32_t  ICDIPTR98;                              /*  ICDIPTR98       */
    volatile uint32_t  ICDIPTR99;                              /*  ICDIPTR99       */
    volatile uint32_t  ICDIPTR100;                             /*  ICDIPTR100      */
    volatile uint32_t  ICDIPTR101;                             /*  ICDIPTR101      */
    volatile uint32_t  ICDIPTR102;                             /*  ICDIPTR102      */
    volatile uint32_t  ICDIPTR103;                             /*  ICDIPTR103      */
    volatile uint32_t  ICDIPTR104;                             /*  ICDIPTR104      */
    volatile uint32_t  ICDIPTR105;                             /*  ICDIPTR105      */
    volatile uint32_t  ICDIPTR106;                             /*  ICDIPTR106      */
    volatile uint32_t  ICDIPTR107;                             /*  ICDIPTR107      */
    volatile uint32_t  ICDIPTR108;                             /*  ICDIPTR108      */
    volatile uint32_t  ICDIPTR109;                             /*  ICDIPTR109      */
    volatile uint32_t  ICDIPTR110;                             /*  ICDIPTR110      */
    volatile uint32_t  ICDIPTR111;                             /*  ICDIPTR111      */
    volatile uint32_t  ICDIPTR112;                             /*  ICDIPTR112      */
    volatile uint32_t  ICDIPTR113;                             /*  ICDIPTR113      */
    volatile uint32_t  ICDIPTR114;                             /*  ICDIPTR114      */
    volatile uint32_t  ICDIPTR115;                             /*  ICDIPTR115      */
    volatile uint32_t  ICDIPTR116;                             /*  ICDIPTR116      */
    volatile uint32_t  ICDIPTR117;                             /*  ICDIPTR117      */
    volatile uint32_t  ICDIPTR118;                             /*  ICDIPTR118      */
    volatile uint32_t  ICDIPTR119;                             /*  ICDIPTR119      */
    volatile uint32_t  ICDIPTR120;                             /*  ICDIPTR120      */
    volatile uint32_t  ICDIPTR121;                             /*  ICDIPTR121      */
    volatile uint32_t  ICDIPTR122;                             /*  ICDIPTR122      */
    volatile uint32_t  ICDIPTR123;                             /*  ICDIPTR123      */
    volatile uint32_t  ICDIPTR124;                             /*  ICDIPTR124      */
    volatile uint32_t  ICDIPTR125;                             /*  ICDIPTR125      */
    volatile uint32_t  ICDIPTR126;                             /*  ICDIPTR126      */
    volatile uint32_t  ICDIPTR127;                             /*  ICDIPTR127      */
    volatile uint32_t  ICDIPTR128;                             /*  ICDIPTR128      */
    volatile uint32_t  ICDIPTR129;                             /*  ICDIPTR129      */
    volatile uint32_t  ICDIPTR130;                             /*  ICDIPTR130      */
    volatile uint32_t  ICDIPTR131;                             /*  ICDIPTR131      */
    volatile uint32_t  ICDIPTR132;                             /*  ICDIPTR132      */
    volatile uint32_t  ICDIPTR133;                             /*  ICDIPTR133      */
    volatile uint32_t  ICDIPTR134;                             /*  ICDIPTR134      */
    volatile uint32_t  ICDIPTR135;                             /*  ICDIPTR135      */
    volatile uint32_t  ICDIPTR136;                             /*  ICDIPTR136      */
    volatile uint32_t  ICDIPTR137;                             /*  ICDIPTR137      */
    volatile uint32_t  ICDIPTR138;                             /*  ICDIPTR138      */
    volatile uint32_t  ICDIPTR139;                             /*  ICDIPTR139      */
    volatile uint32_t  ICDIPTR140;                             /*  ICDIPTR140      */
    volatile uint32_t  ICDIPTR141;                             /*  ICDIPTR141      */
    volatile uint32_t  ICDIPTR142;                             /*  ICDIPTR142      */
    volatile uint32_t  ICDIPTR143;                             /*  ICDIPTR143      */
    volatile uint32_t  ICDIPTR144;                             /*  ICDIPTR144      */
    volatile uint32_t  ICDIPTR145;                             /*  ICDIPTR145      */
    volatile uint32_t  ICDIPTR146;                             /*  ICDIPTR146      */
    volatile uint8_t   dummy201[436];                          /*                  */

    volatile uint32_t  ICDICFR0;                               /*  ICDICFR0        */
    volatile uint32_t  ICDICFR1;                               /*  ICDICFR1        */
    volatile uint32_t  ICDICFR2;                               /*  ICDICFR2        */
    volatile uint32_t  ICDICFR3;                               /*  ICDICFR3        */
    volatile uint32_t  ICDICFR4;                               /*  ICDICFR4        */
    volatile uint32_t  ICDICFR5;                               /*  ICDICFR5        */
    volatile uint32_t  ICDICFR6;                               /*  ICDICFR6        */
    volatile uint32_t  ICDICFR7;                               /*  ICDICFR7        */
    volatile uint32_t  ICDICFR8;                               /*  ICDICFR8        */
    volatile uint32_t  ICDICFR9;                               /*  ICDICFR9        */
    volatile uint32_t  ICDICFR10;                              /*  ICDICFR10       */
    volatile uint32_t  ICDICFR11;                              /*  ICDICFR11       */
    volatile uint32_t  ICDICFR12;                              /*  ICDICFR12       */
    volatile uint32_t  ICDICFR13;                              /*  ICDICFR13       */
    volatile uint32_t  ICDICFR14;                              /*  ICDICFR14       */
    volatile uint32_t  ICDICFR15;                              /*  ICDICFR15       */
    volatile uint32_t  ICDICFR16;                              /*  ICDICFR16       */
    volatile uint32_t  ICDICFR17;                              /*  ICDICFR17       */
    volatile uint32_t  ICDICFR18;                              /*  ICDICFR18       */
    volatile uint32_t  ICDICFR19;                              /*  ICDICFR19       */
    volatile uint32_t  ICDICFR20;                              /*  ICDICFR20       */
    volatile uint32_t  ICDICFR21;                              /*  ICDICFR21       */
    volatile uint32_t  ICDICFR22;                              /*  ICDICFR22       */
    volatile uint32_t  ICDICFR23;                              /*  ICDICFR23       */
    volatile uint32_t  ICDICFR24;                              /*  ICDICFR24       */
    volatile uint32_t  ICDICFR25;                              /*  ICDICFR25       */
    volatile uint32_t  ICDICFR26;                              /*  ICDICFR26       */
    volatile uint32_t  ICDICFR27;                              /*  ICDICFR27       */
    volatile uint32_t  ICDICFR28;                              /*  ICDICFR28       */
    volatile uint32_t  ICDICFR29;                              /*  ICDICFR29       */
    volatile uint32_t  ICDICFR30;                              /*  ICDICFR30       */
    volatile uint32_t  ICDICFR31;                              /*  ICDICFR31       */
    volatile uint32_t  ICDICFR32;                              /*  ICDICFR32       */
    volatile uint32_t  ICDICFR33;                              /*  ICDICFR33       */
    volatile uint32_t  ICDICFR34;                              /*  ICDICFR34       */
    volatile uint32_t  ICDICFR35;                              /*  ICDICFR35       */
    volatile uint32_t  ICDICFR36;                              /*  ICDICFR36       */
    volatile uint8_t   dummy202[108];                          /*                  */
    volatile uint32_t  PPI_STATUS;                             /*  PPI_STATUS      */

    volatile uint32_t  SPI_STATUS0;                            /*  SPI_STATUS0     */
    volatile uint32_t  SPI_STATUS1;                            /*  SPI_STATUS1     */
    volatile uint32_t  SPI_STATUS2;                            /*  SPI_STATUS2     */
    volatile uint32_t  SPI_STATUS3;                            /*  SPI_STATUS3     */
    volatile uint32_t  SPI_STATUS4;                            /*  SPI_STATUS4     */
    volatile uint32_t  SPI_STATUS5;                            /*  SPI_STATUS5     */
    volatile uint32_t  SPI_STATUS6;                            /*  SPI_STATUS6     */
    volatile uint32_t  SPI_STATUS7;                            /*  SPI_STATUS7     */
    volatile uint32_t  SPI_STATUS8;                            /*  SPI_STATUS8     */
    volatile uint32_t  SPI_STATUS9;                            /*  SPI_STATUS9     */
    volatile uint32_t  SPI_STATUS10;                           /*  SPI_STATUS10    */
    volatile uint32_t  SPI_STATUS11;                           /*  SPI_STATUS11    */
    volatile uint32_t  SPI_STATUS12;                           /*  SPI_STATUS12    */
    volatile uint32_t  SPI_STATUS13;                           /*  SPI_STATUS13    */
    volatile uint32_t  SPI_STATUS14;                           /*  SPI_STATUS14    */
    volatile uint32_t  SPI_STATUS15;                           /*  SPI_STATUS15    */
    volatile uint32_t  SPI_STATUS16;                           /*  SPI_STATUS16    */
    volatile uint8_t   dummy203[440];                          /*                  */
    volatile uint32_t  ICDSGIR;                                /*  ICDSGIR         */
    volatile uint8_t   dummy204[252];                          /*                  */
    volatile uint32_t  ICCICR;                                 /*  ICCICR          */
    volatile uint32_t  ICCPMR;                                 /*  ICCPMR          */
    volatile uint32_t  ICCBPR;                                 /*  ICCBPR          */
    volatile uint32_t  ICCIAR;                                 /*  ICCIAR          */
    volatile uint32_t  ICCEOIR;                                /*  ICCEOIR         */
    volatile uint32_t  ICCRPR;                                 /*  ICCRPR          */
    volatile uint32_t  ICCHPIR;                                /*  ICCHPIR         */
    volatile uint32_t  ICCABPR;                                /*  ICCABPR         */
    volatile uint8_t   dummy205[220];                          /*                  */
    volatile uint32_t  ICCIIDR;                                /*  ICCIIDR         */
    volatile uint8_t   dummy206[350148352];                    /*                  */
    volatile uint16_t ICR0;                                   /*  ICR0            */
    volatile uint16_t ICR1;                                   /*  ICR1            */
    volatile uint16_t IRQRR;                                  /*  IRQRR           */
};





#line 1024 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/intc_iodefine.h"
/* <-SEC M1.10.1 */
/* <-QAC 0639 */
#line 110 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/irda_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : irda_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/



struct st_irda
{                                                          /* IRDA             */
    volatile uint8_t   IRCR;                                   /*  IRCR            */
};





#line 111 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/jcu_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : jcu_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_jcu
{                                                          /* JCU              */
    volatile uint8_t   JCMOD;                                  /*  JCMOD           */
    volatile uint8_t   JCCMD;                                  /*  JCCMD           */
    volatile uint8_t   dummy145[1];                            /*                  */
    volatile uint8_t   JCQTN;                                  /*  JCQTN           */
    volatile uint8_t   JCHTN;                                  /*  JCHTN           */
    volatile uint8_t   JCDRIU;                                 /*  JCDRIU          */
    volatile uint8_t   JCDRID;                                 /*  JCDRID          */
    volatile uint8_t   JCVSZU;                                 /*  JCVSZU          */
    volatile uint8_t   JCVSZD;                                 /*  JCVSZD          */
    volatile uint8_t   JCHSZU;                                 /*  JCHSZU          */
    volatile uint8_t   JCHSZD;                                 /*  JCHSZD          */
    volatile uint8_t   JCDTCU;                                 /*  JCDTCU          */
    volatile uint8_t   JCDTCM;                                 /*  JCDTCM          */
    volatile uint8_t   JCDTCD;                                 /*  JCDTCD          */
    volatile uint8_t   JINTE0;                                 /*  JINTE0          */
    volatile uint8_t   JINTS0;                                 /*  JINTS0          */
    volatile uint8_t   JCDERR;                                 /*  JCDERR          */
    volatile uint8_t   JCRST;                                  /*  JCRST           */
    volatile uint8_t   dummy146[46];                           /*                  */
    volatile uint32_t  JIFECNT;                                /*  JIFECNT         */
    volatile uint32_t  JIFESA;                                 /*  JIFESA          */
    volatile uint32_t  JIFESOFST;                              /*  JIFESOFST       */
    volatile uint32_t  JIFEDA;                                 /*  JIFEDA          */
    volatile uint32_t  JIFESLC;                                /*  JIFESLC         */
    volatile uint32_t  JIFEDDC;                                /*  JIFEDDC         */
    volatile uint32_t  JIFDCNT;                                /*  JIFDCNT         */
    volatile uint32_t  JIFDSA;                                 /*  JIFDSA          */
    volatile uint32_t  JIFDDOFST;                              /*  JIFDDOFST       */
    volatile uint32_t  JIFDDA;                                 /*  JIFDDA          */
    volatile uint32_t  JIFDSDC;                                /*  JIFDSDC         */
    volatile uint32_t  JIFDDLC;                                /*  JIFDDLC         */
    volatile uint32_t  JIFDADT;                                /*  JIFDADT         */
    volatile uint8_t   dummy147[24];                           /*                  */
    volatile uint32_t  JINTE1;                                 /*  JINTE1          */
    volatile uint32_t  JINTS1;                                 /*  JINTS1          */
    volatile uint32_t  JIFESVSZ;                               /*  JIFESVSZ        */
    volatile uint32_t  JIFESHSZ;                               /*  JIFESHSZ        */
    volatile uint8_t   dummy148[100];                          /*                  */
/* start of struct st_jcu_from_jcqtbl0 */
    volatile uint8_t   JCQTBL0;                                /*  JCQTBL0         */
    volatile uint8_t   dummy149[63];                           /*                  */
/* end of struct st_jcu_from_jcqtbl0 */
/* start of struct st_jcu_from_jcqtbl0 */
    volatile uint8_t   JCQTBL1;                                /*  JCQTBL1         */
    volatile uint8_t   dummy150[63];                           /*                  */
/* end of struct st_jcu_from_jcqtbl0 */
/* start of struct st_jcu_from_jcqtbl0 */
    volatile uint8_t   JCQTBL2;                                /*  JCQTBL2         */
    volatile uint8_t   dummy151[63];                           /*                  */
/* end of struct st_jcu_from_jcqtbl0 */
/* start of struct st_jcu_from_jcqtbl0 */
    volatile uint8_t   JCQTBL3;                                /*  JCQTBL3         */
    volatile uint8_t   dummy152[63];                           /*                  */
/* end of struct st_jcu_from_jcqtbl0 */
    volatile uint8_t   JCHTBD0;                                /*  JCHTBD0         */
    volatile uint8_t   dummy153[31];                           /*                  */
    volatile uint8_t   JCHTBA0;                                /*  JCHTBA0         */
    volatile uint8_t   dummy154[223];                          /*                  */
    volatile uint8_t   JCHTBD1;                                /*  JCHTBD1         */
    volatile uint8_t   dummy155[31];                           /*                  */
    volatile uint8_t   JCHTBA1;                                /*  JCHTBA1         */
};


struct st_jcu_from_jcqtbl0
{
    volatile uint8_t   JCQTBL0;                                /*  JCQTBL0         */
    volatile uint8_t   dummy1[63];                             /*                  */
};





/* Start of channnel array defines of JCU */

/* Channnel array defines of JCU_JCQTBL0 */
/*(Sample) value = JCU_JCQTBL0[ channel ]->JCQTBL0; */
#line 122 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/jcu_iodefine.h"

/* End of channnel array defines of JCU */


#line 168 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/jcu_iodefine.h"
/* <-SEC M1.10.1 */
#line 112 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/l2c_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : l2c_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_l2c
{                                                          /* L2C              */
    volatile uint32_t  REG0_CACHE_ID;                          /*  REG0_CACHE_ID   */
    volatile uint32_t  REG0_CACHE_TYPE;                        /*  REG0_CACHE_TYPE */
    volatile uint8_t   dummy8[248];                            /*                  */
    volatile uint32_t  REG1_CONTROL;                           /*  REG1_CONTROL    */
    volatile uint32_t  REG1_AUX_CONTROL;                       /*  REG1_AUX_CONTROL */
    volatile uint32_t  REG1_TAG_RAM_CONTROL;                   /*  REG1_TAG_RAM_CONTROL */
    volatile uint32_t  REG1_DATA_RAM_CONTROL;                  /*  REG1_DATA_RAM_CONTROL */
    volatile uint8_t   dummy9[240];                            /*                  */
    volatile uint32_t  REG2_EV_COUNTER_CTRL;                   /*  REG2_EV_COUNTER_CTRL */
    volatile uint32_t  REG2_EV_COUNTER1_CFG;                   /*  REG2_EV_COUNTER1_CFG */
    volatile uint32_t  REG2_EV_COUNTER0_CFG;                   /*  REG2_EV_COUNTER0_CFG */
    volatile uint32_t  REG2_EV_COUNTER1;                       /*  REG2_EV_COUNTER1 */
    volatile uint32_t  REG2_EV_COUNTER0;                       /*  REG2_EV_COUNTER0 */
    volatile uint32_t  REG2_INT_MASK;                          /*  REG2_INT_MASK   */
    volatile uint32_t  REG2_INT_MASK_STATUS;                   /*  REG2_INT_MASK_STATUS */
    volatile uint32_t  REG2_INT_RAW_STATUS;                    /*  REG2_INT_RAW_STATUS */
    volatile uint32_t  REG2_INT_CLEAR;                         /*  REG2_INT_CLEAR  */
    volatile uint8_t   dummy10[1292];                          /*                  */
    volatile uint32_t  REG7_CACHE_SYNC;                        /*  REG7_CACHE_SYNC */
    volatile uint8_t   dummy11[60];                            /*                  */
    volatile uint32_t  REG7_INV_PA;                            /*  REG7_INV_PA     */
    volatile uint8_t   dummy12[8];                             /*                  */
    volatile uint32_t  REG7_INV_WAY;                           /*  REG7_INV_WAY    */
    volatile uint8_t   dummy13[48];                            /*                  */
    volatile uint32_t  REG7_CLEAN_PA;                          /*  REG7_CLEAN_PA   */
    volatile uint8_t   dummy14[4];                             /*                  */
    volatile uint32_t  REG7_CLEAN_INDEX;                       /*  REG7_CLEAN_INDEX */
    volatile uint32_t  REG7_CLEAN_WAY;                         /*  REG7_CLEAN_WAY  */
    volatile uint8_t   dummy15[48];                            /*                  */
    volatile uint32_t  REG7_CLEAN_INV_PA;                      /*  REG7_CLEAN_INV_PA */
    volatile uint8_t   dummy16[4];                             /*                  */
    volatile uint32_t  REG7_CLEAN_INV_INDEX;                   /*  REG7_CLEAN_INV_INDEX */
    volatile uint32_t  REG7_CLEAN_INV_WAY;                     /*  REG7_CLEAN_INV_WAY */
    volatile uint8_t   dummy17[256];                           /*                  */
/* start of struct st_l2c_from_reg9_d_lockdown0 */
    volatile uint32_t  REG9_D_LOCKDOWN0;                       /*  REG9_D_LOCKDOWN0 */
    volatile uint32_t  REG9_I_LOCKDOWN0;                       /*  REG9_I_LOCKDOWN0 */
/* end of struct st_l2c_from_reg9_d_lockdown0 */
/* start of struct st_l2c_from_reg9_d_lockdown0 */
    volatile uint32_t  REG9_D_LOCKDOWN1;                       /*  REG9_D_LOCKDOWN1 */
    volatile uint32_t  REG9_I_LOCKDOWN1;                       /*  REG9_I_LOCKDOWN1 */
/* end of struct st_l2c_from_reg9_d_lockdown0 */
/* start of struct st_l2c_from_reg9_d_lockdown0 */
    volatile uint32_t  REG9_D_LOCKDOWN2;                       /*  REG9_D_LOCKDOWN2 */
    volatile uint32_t  REG9_I_LOCKDOWN2;                       /*  REG9_I_LOCKDOWN2 */
/* end of struct st_l2c_from_reg9_d_lockdown0 */
/* start of struct st_l2c_from_reg9_d_lockdown0 */
    volatile uint32_t  REG9_D_LOCKDOWN3;                       /*  REG9_D_LOCKDOWN3 */
    volatile uint32_t  REG9_I_LOCKDOWN3;                       /*  REG9_I_LOCKDOWN3 */
/* end of struct st_l2c_from_reg9_d_lockdown0 */
/* start of struct st_l2c_from_reg9_d_lockdown0 */
    volatile uint32_t  REG9_D_LOCKDOWN4;                       /*  REG9_D_LOCKDOWN4 */
    volatile uint32_t  REG9_I_LOCKDOWN4;                       /*  REG9_I_LOCKDOWN4 */
/* end of struct st_l2c_from_reg9_d_lockdown0 */
/* start of struct st_l2c_from_reg9_d_lockdown0 */
    volatile uint32_t  REG9_D_LOCKDOWN5;                       /*  REG9_D_LOCKDOWN5 */
    volatile uint32_t  REG9_I_LOCKDOWN5;                       /*  REG9_I_LOCKDOWN5 */
/* end of struct st_l2c_from_reg9_d_lockdown0 */
/* start of struct st_l2c_from_reg9_d_lockdown0 */
    volatile uint32_t  REG9_D_LOCKDOWN6;                       /*  REG9_D_LOCKDOWN6 */
    volatile uint32_t  REG9_I_LOCKDOWN6;                       /*  REG9_I_LOCKDOWN6 */
/* end of struct st_l2c_from_reg9_d_lockdown0 */
/* start of struct st_l2c_from_reg9_d_lockdown0 */
    volatile uint32_t  REG9_D_LOCKDOWN7;                       /*  REG9_D_LOCKDOWN7 */
    volatile uint32_t  REG9_I_LOCKDOWN7;                       /*  REG9_I_LOCKDOWN7 */
/* end of struct st_l2c_from_reg9_d_lockdown0 */
    volatile uint8_t   dummy18[16];                            /*                  */
    volatile uint32_t  REG9_LOCK_LINE_EN;                      /*  REG9_LOCK_LINE_EN */
    volatile uint32_t  REG9_UNLOCK_WAY;                        /*  REG9_UNLOCK_WAY */
    volatile uint8_t   dummy19[680];                           /*                  */
    volatile uint32_t  REG12_ADDR_FILTERING_START;             /*  REG12_ADDR_FILTERING_START */
    volatile uint32_t  REG12_ADDR_FILTERING_END;               /*  REG12_ADDR_FILTERING_END */
    volatile uint8_t   dummy20[824];                           /*                  */
    volatile uint32_t  REG15_DEBUG_CTRL;                       /*  REG15_DEBUG_CTRL */
    volatile uint8_t   dummy21[28];                            /*                  */
    volatile uint32_t  REG15_PREFETCH_CTRL;                    /*  REG15_PREFETCH_CTRL */
    volatile uint8_t   dummy22[28];                            /*                  */
    volatile uint32_t  REG15_POWER_CTRL;                       /*  REG15_POWER_CTRL */
};


struct st_l2c_from_reg9_d_lockdown0
{
    volatile uint32_t  REG9_D_LOCKDOWN0;                       /*  REG9_D_LOCKDOWN0 */
    volatile uint32_t  REG9_I_LOCKDOWN0;                       /*  REG9_I_LOCKDOWN0 */
};





/* Start of channnel array defines of L2C */

/* Channnel array defines of L2C_FROM_REG9_D_LOCKDOWN0_ARRAY */
/*(Sample) value = L2C_FROM_REG9_D_LOCKDOWN0_ARRAY[ channel ]->REG9_D_LOCKDOWN0; */
#line 143 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/l2c_iodefine.h"

/* End of channnel array defines of L2C */


#line 194 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/l2c_iodefine.h"
/* <-SEC M1.10.1 */
#line 113 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/lin_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : lin_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->MISRA 18.4 : Pack unpack union */ /* ->SEC M1.6.2 */
/* ->SEC M1.10.1 : Not magic number */

struct st_lin
{                                                          /* LIN              */
    volatile uint8_t   dummy1[1];                              /*                  */
    volatile uint8_t   RLN3nLWBR;                              /*  RLN3nLWBR       */
    union iodefine_reg16_8_t  RLN3nLBRP01;                     /*  RLN3nLBRP01 */
    
    volatile uint8_t   RLN3nLSTC;                              /*  RLN3nLSTC       */
    volatile uint8_t   dummy2[3];                              /*                  */
    volatile uint8_t   RLN3nLMD;                               /*  RLN3nLMD        */
    volatile uint8_t   RLN3nLBFC;                              /*  RLN3nLBFC       */
    volatile uint8_t   RLN3nLSC;                               /*  RLN3nLSC        */
    volatile uint8_t   RLN3nLWUP;                              /*  RLN3nLWUP       */
    volatile uint8_t   RLN3nLIE;                               /*  RLN3nLIE        */
    volatile uint8_t   RLN3nLEDE;                              /*  RLN3nLEDE       */
    volatile uint8_t   RLN3nLCUC;                              /*  RLN3nLCUC       */
    volatile uint8_t   dummy3[1];                              /*                  */
    volatile uint8_t   RLN3nLTRC;                              /*  RLN3nLTRC       */
    volatile uint8_t   RLN3nLMST;                              /*  RLN3nLMST       */
    volatile uint8_t   RLN3nLST;                               /*  RLN3nLST        */
    volatile uint8_t   RLN3nLEST;                              /*  RLN3nLEST       */
    volatile uint8_t   RLN3nLDFC;                              /*  RLN3nLDFC       */
    volatile uint8_t   RLN3nLIDB;                              /*  RLN3nLIDB       */
    volatile uint8_t   RLN3nLCBR;                              /*  RLN3nLCBR       */
    volatile uint8_t   RLN3nLUDB0;                             /*  RLN3nLUDB0      */

    volatile uint8_t   RLN3nLDBR1;                             /*  RLN3nLDBR1      */
    volatile uint8_t   RLN3nLDBR2;                             /*  RLN3nLDBR2      */
    volatile uint8_t   RLN3nLDBR3;                             /*  RLN3nLDBR3      */
    volatile uint8_t   RLN3nLDBR4;                             /*  RLN3nLDBR4      */
    volatile uint8_t   RLN3nLDBR5;                             /*  RLN3nLDBR5      */
    volatile uint8_t   RLN3nLDBR6;                             /*  RLN3nLDBR6      */
    volatile uint8_t   RLN3nLDBR7;                             /*  RLN3nLDBR7      */
    volatile uint8_t   RLN3nLDBR8;                             /*  RLN3nLDBR8      */
    volatile uint8_t   RLN3nLUOER;                             /*  RLN3nLUOER      */
    volatile uint8_t   RLN3nLUOR1;                             /*  RLN3nLUOR1      */
    volatile uint8_t   dummy4[2];                              /*                  */
    union iodefine_reg16_8_t  RLN3nLUTDR;                      /*  RLN3nLUTDR  */
    union iodefine_reg16_8_t  RLN3nLURDR;                      /*  RLN3nLURDR  */
    union iodefine_reg16_8_t  RLN3nLUWTDR;                     /*  RLN3nLUWTDR */
    
};






/* Start of channnel array defines of LIN */

/* Channnel array defines of LIN */
/*(Sample) value = LIN[ channel ]->RLN3nLWBR; */






/* End of channnel array defines of LIN */


#line 172 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/lin_iodefine.h"
/* <-SEC M1.10.1 */
/* <-MISRA 18.4 */ /* <-SEC M1.6.2 */
#line 114 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/lvds_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : lvds_iodefine.h
* $Rev: 1275 $
* $Date:: 2014-11-07 15:16:20 +0900#$
* Description : Definition of I/O Register (V1.01a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_lvds
{                                                          /* LVDS             */
    volatile uint32_t  LVDS_UPDATE;                            /*  LVDS_UPDATE     */
    volatile uint32_t  LVDSFCL;                                /*  LVDSFCL         */
    volatile uint8_t   dummy608[24];                           /*                  */
    volatile uint32_t  LCLKSELR;                               /*  LCLKSELR        */
    volatile uint32_t  LPLLSETR;                               /*  LPLLSETR        */
    volatile uint8_t   dummy609[4];                            /*                  */
    volatile uint32_t  LPHYACC;                                /*  LPHYACC         */
};










/* <-SEC M1.10.1 */
#line 115 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/mlb_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : mlb_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->QAC 0639 : Over 127 members (C90) */
/* ->QAC 0857 : Over 1024 #define (C90) */
/* ->SEC M1.10.1 : Not magic number */

struct st_mlb
{                                                          /* MLB              */
    volatile uint32_t  DCCR;                                   /*  DCCR            */
    volatile uint32_t  SSCR;                                   /*  SSCR            */
    volatile uint32_t  SDCR;                                   /*  SDCR            */
    volatile uint32_t  SMCR;                                   /*  SMCR            */
    volatile uint8_t   dummy156[12];                           /*                  */
    volatile uint32_t  VCCR;                                   /*  VCCR            */
    volatile uint32_t  SBCR;                                   /*  SBCR            */
    volatile uint32_t  ABCR;                                   /*  ABCR            */
    volatile uint32_t  CBCR;                                   /*  CBCR            */
    volatile uint32_t  IBCR;                                   /*  IBCR            */
    volatile uint32_t  CICR;                                   /*  CICR            */
    volatile uint8_t   dummy157[12];                           /*                  */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR0;                                  /*  CECR0           */
    volatile uint32_t  CSCR0;                                  /*  CSCR0           */
    volatile uint32_t  CCBCR0;                                 /*  CCBCR0          */
    volatile uint32_t  CNBCR0;                                 /*  CNBCR0          */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR1;                                  /*  CECR1           */
    volatile uint32_t  CSCR1;                                  /*  CSCR1           */
    volatile uint32_t  CCBCR1;                                 /*  CCBCR1          */
    volatile uint32_t  CNBCR1;                                 /*  CNBCR1          */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR2;                                  /*  CECR2           */
    volatile uint32_t  CSCR2;                                  /*  CSCR2           */
    volatile uint32_t  CCBCR2;                                 /*  CCBCR2          */
    volatile uint32_t  CNBCR2;                                 /*  CNBCR2          */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR3;                                  /*  CECR3           */
    volatile uint32_t  CSCR3;                                  /*  CSCR3           */
    volatile uint32_t  CCBCR3;                                 /*  CCBCR3          */
    volatile uint32_t  CNBCR3;                                 /*  CNBCR3          */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR4;                                  /*  CECR4           */
    volatile uint32_t  CSCR4;                                  /*  CSCR4           */
    volatile uint32_t  CCBCR4;                                 /*  CCBCR4          */
    volatile uint32_t  CNBCR4;                                 /*  CNBCR4          */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR5;                                  /*  CECR5           */
    volatile uint32_t  CSCR5;                                  /*  CSCR5           */
    volatile uint32_t  CCBCR5;                                 /*  CCBCR5          */
    volatile uint32_t  CNBCR5;                                 /*  CNBCR5          */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR6;                                  /*  CECR6           */
    volatile uint32_t  CSCR6;                                  /*  CSCR6           */
    volatile uint32_t  CCBCR6;                                 /*  CCBCR6          */
    volatile uint32_t  CNBCR6;                                 /*  CNBCR6          */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR7;                                  /*  CECR7           */
    volatile uint32_t  CSCR7;                                  /*  CSCR7           */
    volatile uint32_t  CCBCR7;                                 /*  CCBCR7          */
    volatile uint32_t  CNBCR7;                                 /*  CNBCR7          */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR8;                                  /*  CECR8           */
    volatile uint32_t  CSCR8;                                  /*  CSCR8           */
    volatile uint32_t  CCBCR8;                                 /*  CCBCR8          */
    volatile uint32_t  CNBCR8;                                 /*  CNBCR8          */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR9;                                  /*  CECR9           */
    volatile uint32_t  CSCR9;                                  /*  CSCR9           */
    volatile uint32_t  CCBCR9;                                 /*  CCBCR9          */
    volatile uint32_t  CNBCR9;                                 /*  CNBCR9          */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR10;                                 /*  CECR10          */
    volatile uint32_t  CSCR10;                                 /*  CSCR10          */
    volatile uint32_t  CCBCR10;                                /*  CCBCR10         */
    volatile uint32_t  CNBCR10;                                /*  CNBCR10         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR11;                                 /*  CECR11          */
    volatile uint32_t  CSCR11;                                 /*  CSCR11          */
    volatile uint32_t  CCBCR11;                                /*  CCBCR11         */
    volatile uint32_t  CNBCR11;                                /*  CNBCR11         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR12;                                 /*  CECR12          */
    volatile uint32_t  CSCR12;                                 /*  CSCR12          */
    volatile uint32_t  CCBCR12;                                /*  CCBCR12         */
    volatile uint32_t  CNBCR12;                                /*  CNBCR12         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR13;                                 /*  CECR13          */
    volatile uint32_t  CSCR13;                                 /*  CSCR13          */
    volatile uint32_t  CCBCR13;                                /*  CCBCR13         */
    volatile uint32_t  CNBCR13;                                /*  CNBCR13         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR14;                                 /*  CECR14          */
    volatile uint32_t  CSCR14;                                 /*  CSCR14          */
    volatile uint32_t  CCBCR14;                                /*  CCBCR14         */
    volatile uint32_t  CNBCR14;                                /*  CNBCR14         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR15;                                 /*  CECR15          */
    volatile uint32_t  CSCR15;                                 /*  CSCR15          */
    volatile uint32_t  CCBCR15;                                /*  CCBCR15         */
    volatile uint32_t  CNBCR15;                                /*  CNBCR15         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR16;                                 /*  CECR16          */
    volatile uint32_t  CSCR16;                                 /*  CSCR16          */
    volatile uint32_t  CCBCR16;                                /*  CCBCR16         */
    volatile uint32_t  CNBCR16;                                /*  CNBCR16         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR17;                                 /*  CECR17          */
    volatile uint32_t  CSCR17;                                 /*  CSCR17          */
    volatile uint32_t  CCBCR17;                                /*  CCBCR17         */
    volatile uint32_t  CNBCR17;                                /*  CNBCR17         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR18;                                 /*  CECR18          */
    volatile uint32_t  CSCR18;                                 /*  CSCR18          */
    volatile uint32_t  CCBCR18;                                /*  CCBCR18         */
    volatile uint32_t  CNBCR18;                                /*  CNBCR18         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR19;                                 /*  CECR19          */
    volatile uint32_t  CSCR19;                                 /*  CSCR19          */
    volatile uint32_t  CCBCR19;                                /*  CCBCR19         */
    volatile uint32_t  CNBCR19;                                /*  CNBCR19         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR20;                                 /*  CECR20          */
    volatile uint32_t  CSCR20;                                 /*  CSCR20          */
    volatile uint32_t  CCBCR20;                                /*  CCBCR20         */
    volatile uint32_t  CNBCR20;                                /*  CNBCR20         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR21;                                 /*  CECR21          */
    volatile uint32_t  CSCR21;                                 /*  CSCR21          */
    volatile uint32_t  CCBCR21;                                /*  CCBCR21         */
    volatile uint32_t  CNBCR21;                                /*  CNBCR21         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR22;                                 /*  CECR22          */
    volatile uint32_t  CSCR22;                                 /*  CSCR22          */
    volatile uint32_t  CCBCR22;                                /*  CCBCR22         */
    volatile uint32_t  CNBCR22;                                /*  CNBCR22         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR23;                                 /*  CECR23          */
    volatile uint32_t  CSCR23;                                 /*  CSCR23          */
    volatile uint32_t  CCBCR23;                                /*  CCBCR23         */
    volatile uint32_t  CNBCR23;                                /*  CNBCR23         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR24;                                 /*  CECR24          */
    volatile uint32_t  CSCR24;                                 /*  CSCR24          */
    volatile uint32_t  CCBCR24;                                /*  CCBCR24         */
    volatile uint32_t  CNBCR24;                                /*  CNBCR24         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR25;                                 /*  CECR25          */
    volatile uint32_t  CSCR25;                                 /*  CSCR25          */
    volatile uint32_t  CCBCR25;                                /*  CCBCR25         */
    volatile uint32_t  CNBCR25;                                /*  CNBCR25         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR26;                                 /*  CECR26          */
    volatile uint32_t  CSCR26;                                 /*  CSCR26          */
    volatile uint32_t  CCBCR26;                                /*  CCBCR26         */
    volatile uint32_t  CNBCR26;                                /*  CNBCR26         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR27;                                 /*  CECR27          */
    volatile uint32_t  CSCR27;                                 /*  CSCR27          */
    volatile uint32_t  CCBCR27;                                /*  CCBCR27         */
    volatile uint32_t  CNBCR27;                                /*  CNBCR27         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR28;                                 /*  CECR28          */
    volatile uint32_t  CSCR28;                                 /*  CSCR28          */
    volatile uint32_t  CCBCR28;                                /*  CCBCR28         */
    volatile uint32_t  CNBCR28;                                /*  CNBCR28         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR29;                                 /*  CECR29          */
    volatile uint32_t  CSCR29;                                 /*  CSCR29          */
    volatile uint32_t  CCBCR29;                                /*  CCBCR29         */
    volatile uint32_t  CNBCR29;                                /*  CNBCR29         */
/* end of struct st_mlb_from_cecr0 */
/* start of struct st_mlb_from_cecr0 */
    volatile uint32_t  CECR30;                                 /*  CECR30          */
    volatile uint32_t  CSCR30;                                 /*  CSCR30          */
    volatile uint32_t  CCBCR30;                                /*  CCBCR30         */
    volatile uint32_t  CNBCR30;                                /*  CNBCR30         */
/* end of struct st_mlb_from_cecr0 */
    volatile uint8_t   dummy158[80];                           /*                  */

    volatile uint32_t  LCBCR0;                                 /*  LCBCR0          */
    volatile uint32_t  LCBCR1;                                 /*  LCBCR1          */
    volatile uint32_t  LCBCR2;                                 /*  LCBCR2          */
    volatile uint32_t  LCBCR3;                                 /*  LCBCR3          */
    volatile uint32_t  LCBCR4;                                 /*  LCBCR4          */
    volatile uint32_t  LCBCR5;                                 /*  LCBCR5          */
    volatile uint32_t  LCBCR6;                                 /*  LCBCR6          */
    volatile uint32_t  LCBCR7;                                 /*  LCBCR7          */
    volatile uint32_t  LCBCR8;                                 /*  LCBCR8          */
    volatile uint32_t  LCBCR9;                                 /*  LCBCR9          */
    volatile uint32_t  LCBCR10;                                /*  LCBCR10         */
    volatile uint32_t  LCBCR11;                                /*  LCBCR11         */
    volatile uint32_t  LCBCR12;                                /*  LCBCR12         */
    volatile uint32_t  LCBCR13;                                /*  LCBCR13         */
    volatile uint32_t  LCBCR14;                                /*  LCBCR14         */
    volatile uint32_t  LCBCR15;                                /*  LCBCR15         */
    volatile uint32_t  LCBCR16;                                /*  LCBCR16         */
    volatile uint32_t  LCBCR17;                                /*  LCBCR17         */
    volatile uint32_t  LCBCR18;                                /*  LCBCR18         */
    volatile uint32_t  LCBCR19;                                /*  LCBCR19         */
    volatile uint32_t  LCBCR20;                                /*  LCBCR20         */
    volatile uint32_t  LCBCR21;                                /*  LCBCR21         */
    volatile uint32_t  LCBCR22;                                /*  LCBCR22         */
    volatile uint32_t  LCBCR23;                                /*  LCBCR23         */
    volatile uint32_t  LCBCR24;                                /*  LCBCR24         */
    volatile uint32_t  LCBCR25;                                /*  LCBCR25         */
    volatile uint32_t  LCBCR26;                                /*  LCBCR26         */
    volatile uint32_t  LCBCR27;                                /*  LCBCR27         */
    volatile uint32_t  LCBCR28;                                /*  LCBCR28         */
    volatile uint32_t  LCBCR29;                                /*  LCBCR29         */
    volatile uint32_t  LCBCR30;                                /*  LCBCR30         */
};


struct st_mlb_from_cecr0
{
    volatile uint32_t  CECR0;                                  /*  CECR0           */
    volatile uint32_t  CSCR0;                                  /*  CSCR0           */
    volatile uint32_t  CCBCR0;                                 /*  CCBCR0          */
    volatile uint32_t  CNBCR0;                                 /*  CNBCR0          */
};





/* Start of channnel array defines of MLB */

/* Channnel array defines of MLB_FROM_CECR0_ARRAY */
/*(Sample) value = MLB_FROM_CECR0_ARRAY[ channel ]->CECR0; */
#line 326 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/mlb_iodefine.h"

/* End of channnel array defines of MLB */


#line 495 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/mlb_iodefine.h"
/* <-SEC M1.10.1 */
/* <-QAC 0857 */
/* <-QAC 0639 */
#line 116 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/mmc_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : mmc_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_mmc
{                                                          /* MMC              */
    volatile uint16_t CE_CMD_SETH;                      /*  CE_CMD_SETH */
    volatile uint16_t CE_CMD_SETL;                      /*  CE_CMD_SETL */
    volatile uint8_t   dummy182[4];                            /*                  */
    volatile uint32_t  CE_ARG;                                 /*  CE_ARG          */
    volatile uint32_t  CE_ARG_CMD12;                           /*  CE_ARG_CMD12    */
    volatile uint32_t  CE_CMD_CTRL;                            /*  CE_CMD_CTRL     */
    volatile uint32_t  CE_BLOCK_SET;                           /*  CE_BLOCK_SET    */
    volatile uint32_t  CE_CLK_CTRL;                            /*  CE_CLK_CTRL     */
    volatile uint32_t  CE_BUF_ACC;                             /*  CE_BUF_ACC      */

    volatile uint32_t  CE_RESP3;                               /*  CE_RESP3        */
    volatile uint32_t  CE_RESP2;                               /*  CE_RESP2        */
    volatile uint32_t  CE_RESP1;                               /*  CE_RESP1        */
    volatile uint32_t  CE_RESP0;                               /*  CE_RESP0        */
    volatile uint32_t  CE_RESP_CMD12;                          /*  CE_RESP_CMD12   */
    volatile uint32_t  CE_DATA;                                /*  CE_DATA         */
    volatile uint8_t   dummy183[8];                            /*                  */
    volatile uint32_t  CE_INT;                                 /*  CE_INT          */
    volatile uint32_t  CE_INT_EN;                              /*  CE_INT_EN       */
    volatile uint32_t  CE_HOST_STS1;                           /*  CE_HOST_STS1    */
    volatile uint32_t  CE_HOST_STS2;                           /*  CE_HOST_STS2    */
    volatile uint8_t   dummy184[12];                           /*                  */
    volatile uint32_t  CE_DMA_MODE;                            /*  CE_DMA_MODE     */
    volatile uint8_t   dummy185[16];                           /*                  */
    volatile uint32_t  CE_DETECT;                              /*  CE_DETECT       */
    volatile uint32_t  CE_ADD_MODE;                            /*  CE_ADD_MODE     */
    volatile uint8_t   dummy186[4];                            /*                  */
    volatile uint32_t  CE_VERSION;                             /*  CE_VERSION      */
};





#line 91 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/mmc_iodefine.h"
/* <-SEC M1.10.1 */
#line 117 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/mtu2_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : mtu2_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_mtu2
{                                                          /* MTU2             */
    volatile uint8_t   TCR_2;                                  /*  TCR_2           */
    volatile uint8_t   TMDR_2;                                 /*  TMDR_2          */
    volatile uint8_t   TIOR_2;                                 /*  TIOR_2          */
    volatile uint8_t   dummy520[1];                            /*                  */
    volatile uint8_t   TIER_2;                                 /*  TIER_2          */
    volatile uint8_t   TSR_2;                                  /*  TSR_2           */
    volatile uint16_t TCNT_2;                                 /*  TCNT_2          */
    volatile uint16_t TGRA_2;                                 /*  TGRA_2          */
    volatile uint16_t TGRB_2;                                 /*  TGRB_2          */
    volatile uint8_t   dummy521[500];                          /*                  */
    volatile uint8_t   TCR_3;                                  /*  TCR_3           */
    volatile uint8_t   TCR_4;                                  /*  TCR_4           */
    volatile uint8_t   TMDR_3;                                 /*  TMDR_3          */
    volatile uint8_t   TMDR_4;                                 /*  TMDR_4          */
    volatile uint8_t   TIORH_3;                                /*  TIORH_3         */
    volatile uint8_t   TIORL_3;                                /*  TIORL_3         */
    volatile uint8_t   TIORH_4;                                /*  TIORH_4         */
    volatile uint8_t   TIORL_4;                                /*  TIORL_4         */
    volatile uint8_t   TIER_3;                                 /*  TIER_3          */
    volatile uint8_t   TIER_4;                                 /*  TIER_4          */
    volatile uint8_t   TOER;                                   /*  TOER            */
    volatile uint8_t   dummy522[2];                            /*                  */
    volatile uint8_t   TGCR;                                   /*  TGCR            */
    volatile uint8_t   TOCR1;                                  /*  TOCR1           */
    volatile uint8_t   TOCR2;                                  /*  TOCR2           */
    volatile uint16_t TCNT_3;                                 /*  TCNT_3          */
    volatile uint16_t TCNT_4;                                 /*  TCNT_4          */
    volatile uint16_t TCDR;                                   /*  TCDR            */
    volatile uint16_t TDDR;                                   /*  TDDR            */
    volatile uint16_t TGRA_3;                                 /*  TGRA_3          */
    volatile uint16_t TGRB_3;                                 /*  TGRB_3          */
    volatile uint16_t TGRA_4;                                 /*  TGRA_4          */
    volatile uint16_t TGRB_4;                                 /*  TGRB_4          */
    volatile uint16_t TCNTS;                                  /*  TCNTS           */
    volatile uint16_t TCBR;                                   /*  TCBR            */
    volatile uint16_t TGRC_3;                                 /*  TGRC_3          */
    volatile uint16_t TGRD_3;                                 /*  TGRD_3          */
    volatile uint16_t TGRC_4;                                 /*  TGRC_4          */
    volatile uint16_t TGRD_4;                                 /*  TGRD_4          */
    volatile uint8_t   TSR_3;                                  /*  TSR_3           */
    volatile uint8_t   TSR_4;                                  /*  TSR_4           */
    volatile uint8_t   dummy523[2];                            /*                  */
    volatile uint8_t   TITCR;                                  /*  TITCR           */
    volatile uint8_t   TITCNT;                                 /*  TITCNT          */
    volatile uint8_t   TBTER;                                  /*  TBTER           */
    volatile uint8_t   dummy524[1];                            /*                  */
    volatile uint8_t   TDER;                                   /*  TDER            */
    volatile uint8_t   dummy525[1];                            /*                  */
    volatile uint8_t   TOLBR;                                  /*  TOLBR           */
    volatile uint8_t   dummy526[1];                            /*                  */
    volatile uint8_t   TBTM_3;                                 /*  TBTM_3          */
    volatile uint8_t   TBTM_4;                                 /*  TBTM_4          */
    volatile uint8_t   dummy527[6];                            /*                  */
    volatile uint16_t TADCR;                                  /*  TADCR           */
    volatile uint8_t   dummy528[2];                            /*                  */
    volatile uint16_t TADCORA_4;                              /*  TADCORA_4       */
    volatile uint16_t TADCORB_4;                              /*  TADCORB_4       */
    volatile uint16_t TADCOBRA_4;                             /*  TADCOBRA_4      */
    volatile uint16_t TADCOBRB_4;                             /*  TADCOBRB_4      */
    volatile uint8_t   dummy529[20];                           /*                  */
    volatile uint8_t   TWCR;                                   /*  TWCR            */
    volatile uint8_t   dummy530[31];                           /*                  */
    volatile uint8_t   TSTR;                                   /*  TSTR            */
    volatile uint8_t   TSYR;                                   /*  TSYR            */
    volatile uint8_t   dummy531[2];                            /*                  */
    volatile uint8_t   TRWER;                                  /*  TRWER           */
    volatile uint8_t   dummy532[123];                          /*                  */
    volatile uint8_t   TCR_0;                                  /*  TCR_0           */
    volatile uint8_t   TMDR_0;                                 /*  TMDR_0          */
    volatile uint8_t   TIORH_0;                                /*  TIORH_0         */
    volatile uint8_t   TIORL_0;                                /*  TIORL_0         */
    volatile uint8_t   TIER_0;                                 /*  TIER_0          */
    volatile uint8_t   TSR_0;                                  /*  TSR_0           */
    volatile uint16_t TCNT_0;                                 /*  TCNT_0          */
    volatile uint16_t TGRA_0;                                 /*  TGRA_0          */
    volatile uint16_t TGRB_0;                                 /*  TGRB_0          */
    volatile uint16_t TGRC_0;                                 /*  TGRC_0          */
    volatile uint16_t TGRD_0;                                 /*  TGRD_0          */
    volatile uint8_t   dummy533[16];                           /*                  */
    volatile uint16_t TGRE_0;                                 /*  TGRE_0          */
    volatile uint16_t TGRF_0;                                 /*  TGRF_0          */
    volatile uint8_t   TIER2_0;                                /*  TIER2_0         */
    volatile uint8_t   TSR2_0;                                 /*  TSR2_0          */
    volatile uint8_t   TBTM_0;                                 /*  TBTM_0          */
    volatile uint8_t   dummy534[89];                           /*                  */
    volatile uint8_t   TCR_1;                                  /*  TCR_1           */
    volatile uint8_t   TMDR_1;                                 /*  TMDR_1          */
    volatile uint8_t   TIOR_1;                                 /*  TIOR_1          */
    volatile uint8_t   dummy535[1];                            /*                  */
    volatile uint8_t   TIER_1;                                 /*  TIER_1          */
    volatile uint8_t   TSR_1;                                  /*  TSR_1           */
    volatile uint16_t TCNT_1;                                 /*  TCNT_1          */
    volatile uint16_t TGRA_1;                                 /*  TGRA_1          */
    volatile uint16_t TGRB_1;                                 /*  TGRB_1          */
    volatile uint8_t   dummy536[4];                            /*                  */
    volatile uint8_t   TICCR;                                  /*  TICCR           */
};





#line 216 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/mtu2_iodefine.h"
/* <-SEC M1.10.1 */
#line 118 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/ostm_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : ostm_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_ostm
{                                                          /* OSTM             */
    volatile uint32_t  OSTMnCMP;                               /*  OSTMnCMP        */
    volatile uint32_t  OSTMnCNT;                               /*  OSTMnCNT        */
    volatile uint8_t   dummy1[8];                              /*                  */
    volatile uint8_t   OSTMnTE;                                /*  OSTMnTE         */
    volatile uint8_t   dummy2[3];                              /*                  */
    volatile uint8_t   OSTMnTS;                                /*  OSTMnTS         */
    volatile uint8_t   dummy3[3];                              /*                  */
    volatile uint8_t   OSTMnTT;                                /*  OSTMnTT         */
    volatile uint8_t   dummy4[7];                              /*                  */
    volatile uint8_t   OSTMnCTL;                               /*  OSTMnCTL        */
};






/* Start of channnel array defines of OSTM */

/* Channnel array defines of OSTM */
/*(Sample) value = OSTM[ channel ]->OSTMnCMP; */






/* End of channnel array defines of OSTM */


#line 77 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/ostm_iodefine.h"
/* <-SEC M1.10.1 */
#line 119 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/pfc_iodefine.h"
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
*******************************************************************************/
/*******************************************************************************
* Copyright (C) 2013 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name     : pfc_iodefine.h
* Device(s)     : RZ/A1H RSK2+RZA1H
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : Pin function controller interface file
*******************************************************************************/
/*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*******************************************************************************/



#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\typedefine.h"
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
* File Name     : typedefine.h
* Device(s)     : RZ/A1H (R7S721001)
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : Defines exact width integer types.
*******************************************************************************/
/*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*               : 21.03.2014 2.00
*******************************************************************************/

/* Multiple inclusion prevention macro */



#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\stddef.h"
/* stddef.h standard header */
/* Copyright 2009-2010 IAR Systems AB. */




  #pragma system_include


#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */


  #pragma system_include


/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __AEABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\ycheck.h"

#line 11 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\stddef.h"
#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\ysizet.h"
/* ysizet.h internal header file. */
/* Copyright 2003-2010 IAR Systems AB.  */





  #pragma system_include


#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */


  #pragma system_include


/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __AEABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\ycheck.h"

#line 12 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\ysizet.h"



                /* type definitions */




typedef _Sizet size_t;




typedef unsigned int __data_size_t;











#line 13 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\stddef.h"



                /* macros */








                /* type definitions */




  typedef _Ptrdifft ptrdiff_t;




  typedef _Wchart wchar_t;




#line 49 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\stddef.h"


/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 42 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\typedefine.h"
#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\stdbool.h"
/* stdbool.h header */
/* Copyright 2003-2010 IAR Systems AB.  */

/* NOTE: IAR Extensions must be enabled in order to use the bool type! */





  #pragma system_include















/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 43 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\typedefine.h"
#line 1 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\stdint.h"
/* stdint.h standard header */
/* Copyright 2003-2010 IAR Systems AB.  */
#line 235 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\stdint.h"

#line 258 "C:\\work\\dev\\iar_arm7.2\\arm\\inc\\c\\stdint.h"

/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 44 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\typedefine.h"

/*******************************************************************************
Typedef definitions
*******************************************************************************/
typedef signed   char      _SBYTE;
typedef unsigned char      _UBYTE;
typedef signed   short     _SWORD;
typedef unsigned short     _UWORD;
typedef signed   int       _SINT;
typedef unsigned int       _UINT;
typedef signed   long      _SDWORD;
typedef unsigned long      _UDWORD;
typedef signed   long long _SQWORD;
typedef unsigned long long _UQWORD;

/* TYPE_DEFINE_H */


/* End of File */
#line 40 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/pfc_iodefine.h"

struct st_pfc_n {                              /* struct PFC    */
       union {                                  /* Pn           */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD Pn0:1;               /*              */
                    _UWORD Pn1:1;               /*              */
                    _UWORD Pn2:1;               /*              */
                    _UWORD Pn3:1;               /*              */
                    _UWORD Pn4:1;               /*              */
                    _UWORD Pn5:1;               /*              */
                    _UWORD Pn6:1;               /*              */
                    _UWORD Pn7:1;               /*              */
                    _UWORD Pn8:1;               /*              */
                    _UWORD Pn9:1;               /*              */
                    _UWORD Pn10:1;              /*              */
                    _UWORD Pn11:1;              /*              */
                    _UWORD Pn12:1;              /*              */
                    _UWORD Pn13:1;              /*              */
                    _UWORD Pn14:1;              /*              */
                    _UWORD Pn15:1;              /*              */
                    } BIT;                      /*              */
             } Pn;                              /*              */
       _UBYTE wk0[0x100-2];                     /*              */
       union {                                  /* PSRn         */
             _UDWORD LONG;                      /*  Long Access */
             struct {                           /*  WORD Access */
                    _UDWORD ENABLE:16;          /*              */
                    _UDWORD SET:16;             /*              */
                    } SET;
             struct {                           /*  Bit Access  */
                    _UDWORD PSRn0:1;            /*              */
                    _UDWORD PSRn1:1;            /*              */
                    _UDWORD PSRn2:1;            /*              */
                    _UDWORD PSRn3:1;            /*              */
                    _UDWORD PSRn4:1;            /*              */
                    _UDWORD PSRn5:1;            /*              */
                    _UDWORD PSRn6:1;            /*              */
                    _UDWORD PSRn7:1;            /*              */
                    _UDWORD PSRn8:1;            /*              */
                    _UDWORD PSRn9:1;            /*              */
                    _UDWORD PSRn10:1;           /*              */
                    _UDWORD PSRn11:1;           /*              */
                    _UDWORD PSRn12:1;           /*              */
                    _UDWORD PSRn13:1;           /*              */
                    _UDWORD PSRn14:1;           /*              */
                    _UDWORD PSRn15:1;           /*              */
                    _UDWORD PSRn16:1;           /*              */
                    _UDWORD PSRn17:1;           /*              */
                    _UDWORD PSRn18:1;           /*              */
                    _UDWORD PSRn19:1;           /*              */
                    _UDWORD PSRn20:1;           /*              */
                    _UDWORD PSRn21:1;           /*              */
                    _UDWORD PSRn22:1;           /*              */
                    _UDWORD PSRn23:1;           /*              */
                    _UDWORD PSRn24:1;           /*              */
                    _UDWORD PSRn25:1;           /*              */
                    _UDWORD PSRn26:1;           /*              */
                    _UDWORD PSRn27:1;           /*              */
                    _UDWORD PSRn28:1;           /*              */
                    _UDWORD PSRn29:1;           /*              */
                    _UDWORD PSRn30:1;           /*              */
                    _UDWORD PSRn31:1;           /*              */
                    } BIT;                      /*              */
             } PSRn;                            /*              */
       _UBYTE wk1[0x100-4];                     /*              */
       union {                                  /* PPRn         */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD PPRn0:1;             /*              */
                    _UWORD PPRn1:1;             /*              */
                    _UWORD PPRn2:1;             /*              */
                    _UWORD PPRn3:1;             /*              */
                    _UWORD PPRn4:1;             /*              */
                    _UWORD PPRn5:1;             /*              */
                    _UWORD PPRn6:1;             /*              */
                    _UWORD PPRn7:1;             /*              */
                    _UWORD PPRn8:1;             /*              */
                    _UWORD PPRn9:1;             /*              */
                    _UWORD PPRn10:1;            /*              */
                    _UWORD PPRn11:1;            /*              */
                    _UWORD PPRn12:1;            /*              */
                    _UWORD PPRn13:1;            /*              */
                    _UWORD PPRn14:1;            /*              */
                    _UWORD PPRn15:1;            /*              */
                    } BIT;                      /*              */
             } PPRn;                            /*              */
       _UBYTE wk2[0x100-2];                     /*              */
       union {                                  /* PMn          */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD PMn0:1;              /*              */
                    _UWORD PMn1:1;              /*              */
                    _UWORD PMn2:1;              /*              */
                    _UWORD PMn3:1;              /*              */
                    _UWORD PMn4:1;              /*              */
                    _UWORD PMn5:1;              /*              */
                    _UWORD PMn6:1;              /*              */
                    _UWORD PMn7:1;              /*              */
                    _UWORD PMn8:1;              /*              */
                    _UWORD PMn9:1;              /*              */
                    _UWORD PMn10:1;             /*              */
                    _UWORD PMn11:1;             /*              */
                    _UWORD PMn12:1;             /*              */
                    _UWORD PMn13:1;             /*              */
                    _UWORD PMn14:1;             /*              */
                    _UWORD PMn15:1;             /*              */
                    } BIT;                      /*              */
             } PMn;                             /*              */
       _UBYTE wk3[0x100-2];                     /*              */
       union {                                  /* PMCn         */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD PMCn0:1;             /*              */
                    _UWORD PMCn1:1;             /*              */
                    _UWORD PMCn2:1;             /*              */
                    _UWORD PMCn3:1;             /*              */
                    _UWORD PMCn4:1;             /*              */
                    _UWORD PMCn5:1;             /*              */
                    _UWORD PMCn6:1;             /*              */
                    _UWORD PMCn7:1;             /*              */
                    _UWORD PMCn8:1;             /*              */
                    _UWORD PMCn9:1;             /*              */
                    _UWORD PMCn10:1;            /*              */
                    _UWORD PMCn11:1;            /*              */
                    _UWORD PMCn12:1;            /*              */
                    _UWORD PMCn13:1;            /*              */
                    _UWORD PMCn14:1;            /*              */
                    _UWORD PMCn15:1;            /*              */
                     } BIT;                      /*              */
             } PMCn;                            /*              */
       _UBYTE wk4[0x100-2];                     /*              */
       union {                                  /* PFCn         */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD PFCn0:1;             /*              */
                    _UWORD PFCn1:1;             /*              */
                    _UWORD PFCn2:1;             /*              */
                    _UWORD PFCn3:1;             /*              */
                    _UWORD PFCn4:1;             /*              */
                    _UWORD PFCn5:1;             /*              */
                    _UWORD PFCn6:1;             /*              */
                    _UWORD PFCn7:1;             /*              */
                    _UWORD PFCn8:1;             /*              */
                    _UWORD PFCn9:1;             /*              */
                    _UWORD PFCn10:1;            /*              */
                    _UWORD PFCn11:1;            /*              */
                    _UWORD PFCn12:1;            /*              */
                    _UWORD PFCn13:1;            /*              */
                    _UWORD PFCn14:1;            /*              */
                    _UWORD PFCn15:1;            /*              */
                    } BIT;                      /*              */
             } PFCn;                            /*              */
       _UBYTE wk5[0x100-2];                     /*              */
       union {                                  /* PFCEn        */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD PFCEn0:1;            /*              */
                    _UWORD PFCEn1:1;            /*              */
                    _UWORD PFCEn2:1;            /*              */
                    _UWORD PFCEn3:1;            /*              */
                    _UWORD PFCEn4:1;            /*              */
                    _UWORD PFCEn5:1;            /*              */
                    _UWORD PFCEn6:1;            /*              */
                    _UWORD PFCEn7:1;            /*              */
                    _UWORD PFCEn8:1;            /*              */
                    _UWORD PFCEn9:1;            /*              */
                    _UWORD PFCEn10:1;           /*              */
                    _UWORD PFCEn11:1;           /*              */
                    _UWORD PFCEn12:1;           /*              */
                    _UWORD PFCEn13:1;           /*              */
                    _UWORD PFCEn14:1;           /*              */
                    _UWORD PFCEn15:1;           /*              */
                    } BIT;                      /*              */
             } PFCEn;                           /*              */
       _UBYTE wk6[0x100-2];                     /*              */
       union {                                  /* PNOTn        */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD PNOTn0:1;            /*              */
                    _UWORD PNOTn1:1;            /*              */
                    _UWORD PNOTn2:1;            /*              */
                    _UWORD PNOTn3:1;            /*              */
                    _UWORD PNOTn4:1;            /*              */
                    _UWORD PNOTn5:1;            /*              */
                    _UWORD PNOTn6:1;            /*              */
                    _UWORD PNOTn7:1;            /*              */
                    _UWORD PNOTn8:1;            /*              */
                    _UWORD PNOTn9:1;            /*              */
                    _UWORD PNOTn10:1;           /*              */
                    _UWORD PNOTn11:1;           /*              */
                    _UWORD PNOTn12:1;           /*              */
                    _UWORD PNOTn13:1;           /*              */
                    _UWORD PNOTn14:1;           /*              */
                    _UWORD PNOTn15:1;           /*              */
                    } BIT;                      /*              */
             } PNOTn;                           /*              */
       _UBYTE wk7[0x100-2];                     /*              */
       union {                                  /* PMSRn        */
             _UDWORD LONG;                      /*  Long Access */
             struct {                           /*  WORD Access */
                    _UDWORD ENABLE:16;          /*              */
                    _UDWORD SET:16;             /*              */
                    } SET;
             struct {                           /*  Bit Access  */
                    _UDWORD PMSRn0:1;           /*              */
                    _UDWORD PMSRn1:1;           /*              */
                    _UDWORD PMSRn2:1;           /*              */
                    _UDWORD PMSRn3:1;           /*              */
                    _UDWORD PMSRn4:1;           /*              */
                    _UDWORD PMSRn5:1;           /*              */
                    _UDWORD PMSRn6:1;           /*              */
                    _UDWORD PMSRn7:1;           /*              */
                    _UDWORD PMSRn8:1;           /*              */
                    _UDWORD PMSRn9:1;           /*              */
                    _UDWORD PMSRn10:1;          /*              */
                    _UDWORD PMSRn11:1;          /*              */
                    _UDWORD PMSRn12:1;          /*              */
                    _UDWORD PMSRn13:1;          /*              */
                    _UDWORD PMSRn14:1;          /*              */
                    _UDWORD PMSRn15:1;          /*              */
                    _UDWORD PMSRn16:1;          /*              */
                    _UDWORD PMSRn17:1;          /*              */
                    _UDWORD PMSRn18:1;          /*              */
                    _UDWORD PMSRn19:1;          /*              */
                    _UDWORD PMSRn20:1;          /*              */
                    _UDWORD PMSRn21:1;          /*              */
                    _UDWORD PMSRn22:1;          /*              */
                    _UDWORD PMSRn23:1;          /*              */
                    _UDWORD PMSRn24:1;          /*              */
                    _UDWORD PMSRn25:1;          /*              */
                    _UDWORD PMSRn26:1;          /*              */
                    _UDWORD PMSRn27:1;          /*              */
                    _UDWORD PMSRn28:1;          /*              */
                    _UDWORD PMSRn29:1;          /*              */
                    _UDWORD PMSRn30:1;          /*              */
                    _UDWORD PMSRn31:1;          /*              */
                    } BIT;                      /*              */
             } PMSRn;                           /*              */
       _UBYTE wk8[0x100-4];                     /*              */
       union {                                  /* PMCSRn       */
             _UDWORD LONG;                      /*  Long Access */
             struct {                           /*  WORD Access */
                    _UDWORD ENABLE:16;          /*              */
                    _UDWORD SET:16;             /*              */
                    } SET;
             struct {                           /*  Bit Access  */
                    _UDWORD PMCSRn0:1;          /*              */
                    _UDWORD PMCSRn1:1;          /*              */
                    _UDWORD PMCSRn2:1;          /*              */
                    _UDWORD PMCSRn3:1;          /*              */
                    _UDWORD PMCSRn4:1;          /*              */
                    _UDWORD PMCSRn5:1;          /*              */
                    _UDWORD PMCSRn6:1;          /*              */
                    _UDWORD PMCSRn7:1;          /*              */
                    _UDWORD PMCSRn8:1;          /*              */
                    _UDWORD PMCSRn9:1;          /*              */
                    _UDWORD PMCSRn10:1;         /*              */
                    _UDWORD PMCSRn11:1;         /*              */
                    _UDWORD PMCSRn12:1;         /*              */
                    _UDWORD PMCSRn13:1;         /*              */
                    _UDWORD PMCSRn14:1;         /*              */
                    _UDWORD PMCSRn15:1;         /*              */
                    _UDWORD PMCSRn16:1;         /*              */
                    _UDWORD PMCSRn17:1;         /*              */
                    _UDWORD PMCSRn18:1;         /*              */
                    _UDWORD PMCSRn19:1;         /*              */
                    _UDWORD PMCSRn20:1;         /*              */
                    _UDWORD PMCSRn21:1;         /*              */
                    _UDWORD PMCSRn22:1;         /*              */
                    _UDWORD PMCSRn23:1;         /*              */
                    _UDWORD PMCSRn24:1;         /*              */
                    _UDWORD PMCSRn25:1;         /*              */
                    _UDWORD PMCSRn26:1;         /*              */
                    _UDWORD PMCSRn27:1;         /*              */
                    _UDWORD PMCSRn28:1;         /*              */
                    _UDWORD PMCSRn29:1;         /*              */
                    _UDWORD PMCSRn30:1;         /*              */
                    _UDWORD PMCSRn31:1;         /*              */
                    } BIT;                      /*              */
             } PMCSRn;                          /*              */
       _UBYTE wk9[0x100-4];                     /*              */
       union {                                  /* PFACEn       */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD PFCAEn0:1;           /*              */
                    _UWORD PFCAEn1:1;           /*              */
                    _UWORD PFCAEn2:1;           /*              */
                    _UWORD PFCAEn3:1;           /*              */
                    _UWORD PFCAEn4:1;           /*              */
                    _UWORD PFCAEn5:1;           /*              */
                    _UWORD PFCAEn6:1;           /*              */
                    _UWORD PFCAEn7:1;           /*              */
                    _UWORD PFCAEn8:1;           /*              */
                    _UWORD PFCAEn9:1;           /*              */
                    _UWORD PFCAEn10:1;          /*              */
                    _UWORD PFCAEn11:1;          /*              */
                    _UWORD PFCAEn12:1;          /*              */
                    _UWORD PFCAEn13:1;          /*              */
                    _UWORD PFCAEn14:1;          /*              */
                    _UWORD PFCAEn15:1;          /*              */
                    } BIT;                      /*              */
             } PFCAEn;                          /*              */
       _UBYTE wk10[0x4000-0xa00-2];             /*              */
       union {                                  /* PIBCn        */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD PIBCn0:1;            /*              */
                    _UWORD PIBCn1:1;            /*              */
                    _UWORD PIBCn2:1;            /*              */
                    _UWORD PIBCn3:1;            /*              */
                    _UWORD PIBCn4:1;            /*              */
                    _UWORD PIBCn5:1;            /*              */
                    _UWORD PIBCn6:1;            /*              */
                    _UWORD PIBCn7:1;            /*              */
                    _UWORD PIBCn8:1;            /*              */
                    _UWORD PIBCn9:1;            /*              */
                    _UWORD PIBCn10:1;           /*              */
                    _UWORD PIBCn11:1;           /*              */
                    _UWORD PIBCn12:1;           /*              */
                    _UWORD PIBCn13:1;           /*              */
                    _UWORD PIBCn14:1;           /*              */
                    _UWORD PIBCn15:1;           /*              */
                    } BIT;                      /*              */
             } PIBCn;                           /*              */
       _UBYTE wk11[0x100-2];                    /*              */
       union {                                  /* PBDCn        */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD PBDCn0:1;            /*              */
                    _UWORD PBDCn1:1;            /*              */
                    _UWORD PBDCn2:1;            /*              */
                    _UWORD PBDCn3:1;            /*              */
                    _UWORD PBDCn4:1;            /*              */
                    _UWORD PBDCn5:1;            /*              */
                    _UWORD PBDCn6:1;            /*              */
                    _UWORD PBDCn7:1;            /*              */
                    _UWORD PBDCn8:1;            /*              */
                    _UWORD PBDCn9:1;            /*              */
                    _UWORD PBDCn10:1;           /*              */
                    _UWORD PBDCn11:1;           /*              */
                    _UWORD PBDCn12:1;           /*              */
                    _UWORD PBDCn13:1;           /*              */
                    _UWORD PBDCn14:1;           /*              */
                    _UWORD PBDCn15:1;           /*              */
                    } BIT;                      /*              */
             } PBDCn;                           /*              */
       _UBYTE wk12[0x100-2];                    /*              */
       union {                                  /* PIPCn        */
             _UWORD WORD;                       /*  Word Access */
             struct {                           /*  Bit Access  */
                    _UWORD PIPCn0:1;            /*              */
                    _UWORD PIPCn1:1;            /*              */
                    _UWORD PIPCn2:1;            /*              */
                    _UWORD PIPCn3:1;            /*              */
                    _UWORD PIPCn4:1;            /*              */
                    _UWORD PIPCn5:1;            /*              */
                    _UWORD PIPCn6:1;            /*              */
                    _UWORD PIPCn7:1;            /*              */
                    _UWORD PIPCn8:1;            /*              */
                    _UWORD PIPCn9:1;            /*              */
                    _UWORD PIPCn10:1;           /*              */
                    _UWORD PIPCn11:1;           /*              */
                    _UWORD PIPCn12:1;           /*              */
                    _UWORD PIPCn13:1;           /*              */
                    _UWORD PIPCn14:1;           /*              */
                    _UWORD PIPCn15:1;           /*              */
                    } BIT;                      /*              */
             } PIPCn;                           /*              */
       _UBYTE wk13[0x100-2];                    /*              */
};                                              /*              */







#line 430 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/pfc_iodefine.h"



/* End of File */
#line 120 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/pfv_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : pfv_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_pfv
{                                                          /* PFV              */
    volatile uint32_t  PFVCR;                                  /*  PFVCR           */
    volatile uint32_t  PFVICR;                                 /*  PFVICR          */
    volatile uint32_t  PFVISR;                                 /*  PFVISR          */
    volatile uint8_t   dummy1[20];                             /*                  */

    volatile uint32_t  PFVID0;                                 /*  PFVID0          */
    volatile uint32_t  PFVID1;                                 /*  PFVID1          */
    volatile uint32_t  PFVID2;                                 /*  PFVID2          */
    volatile uint32_t  PFVID3;                                 /*  PFVID3          */
    volatile uint32_t  PFVID4;                                 /*  PFVID4          */
    volatile uint32_t  PFVID5;                                 /*  PFVID5          */
    volatile uint32_t  PFVID6;                                 /*  PFVID6          */
    volatile uint32_t  PFVID7;                                 /*  PFVID7          */

    volatile uint32_t  PFVOD0;                                 /*  PFVOD0          */
    volatile uint32_t  PFVOD1;                                 /*  PFVOD1          */
    volatile uint32_t  PFVOD2;                                 /*  PFVOD2          */
    volatile uint32_t  PFVOD3;                                 /*  PFVOD3          */
    volatile uint32_t  PFVOD4;                                 /*  PFVOD4          */
    volatile uint32_t  PFVOD5;                                 /*  PFVOD5          */
    volatile uint32_t  PFVOD6;                                 /*  PFVOD6          */
    volatile uint32_t  PFVOD7;                                 /*  PFVOD7          */
    volatile uint8_t   dummy2[4];                              /*                  */
    volatile uint32_t  PFVIFSR;                                /*  PFVIFSR         */
    volatile uint32_t  PFVOFSR;                                /*  PFVOFSR         */
    volatile uint32_t  PFVACR;                                 /*  PFVACR          */
    volatile uint32_t  PFV_MTX_MODE;                           /*  PFV_MTX_MODE    */
    volatile uint32_t  PFV_MTX_YG_ADJ0;                        /*  PFV_MTX_YG_ADJ0 */
    volatile uint32_t  PFV_MTX_YG_ADJ1;                        /*  PFV_MTX_YG_ADJ1 */
    volatile uint32_t  PFV_MTX_CBB_ADJ0;                       /*  PFV_MTX_CBB_ADJ0 */
    volatile uint32_t  PFV_MTX_CBB_ADJ1;                       /*  PFV_MTX_CBB_ADJ1 */
    volatile uint32_t  PFV_MTX_CRR_ADJ0;                       /*  PFV_MTX_CRR_ADJ0 */
    volatile uint32_t  PFV_MTX_CRR_ADJ1;                       /*  PFV_MTX_CRR_ADJ1 */
    volatile uint32_t  PFVSZR;                                 /*  PFVSZR          */
};






/* Start of channnel array defines of PFV */

/* Channnel array defines of PFV */
/*(Sample) value = PFV[ channel ]->PFVCR; */






/* End of channnel array defines of PFV */


#line 149 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/pfv_iodefine.h"
/* <-SEC M1.10.1 */
#line 121 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/pwm_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : pwm_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->MISRA 18.4 : Pack unpack union */ /* ->SEC M1.6.2 */
/* ->SEC M1.10.1 : Not magic number */

struct st_pwm
{                                                          /* PWM              */
    volatile uint8_t   dummy559[2];                            /*                  */
    union iodefine_reg16_8_t  PWBTCR;                          /*  PWBTCR      */
    
    volatile uint8_t   dummy560[216];                          /*                  */
    
/* start of struct st_pwm_common */
    union iodefine_reg16_8_t  PWCR_1;                          /*  PWCR_1      */
    
    volatile uint8_t   dummy561[2];                            /*                  */
    union iodefine_reg16_8_t  PWPR_1;                          /*  PWPR_1      */
    
    volatile uint16_t PWCYR_1;                                /*  PWCYR_1         */
    volatile uint16_t PWBFR_1A;                               /*  PWBFR_1A        */
    volatile uint16_t PWBFR_1C;                               /*  PWBFR_1C        */
    volatile uint16_t PWBFR_1E;                               /*  PWBFR_1E        */
    volatile uint16_t PWBFR_1G;                               /*  PWBFR_1G        */
/* end of struct st_pwm_common */
    
/* start of struct st_pwm_common */
    union iodefine_reg16_8_t  PWCR_2;                          /*  PWCR_2      */
    
    volatile uint8_t   dummy562[2];                            /*                  */
    union iodefine_reg16_8_t  PWPR_2;                          /*  PWPR_2      */
    
    volatile uint16_t PWCYR_2;                                /*  PWCYR_2         */
    volatile uint16_t PWBFR_2A;                               /*  PWBFR_2A        */
    volatile uint16_t PWBFR_2C;                               /*  PWBFR_2C        */
    volatile uint16_t PWBFR_2E;                               /*  PWBFR_2E        */
    volatile uint16_t PWBFR_2G;                               /*  PWBFR_2G        */
/* end of struct st_pwm_common */
};


struct st_pwm_common
{
    union iodefine_reg16_8_t  PWCR_1;                          /*  PWCR_1      */
    
    volatile uint8_t   dummy572[2];                            /*                  */
    union iodefine_reg16_8_t  PWPR_1;                          /*  PWPR_1      */
    
    volatile uint16_t PWCYR_1;                                /*  PWCYR_1         */
    volatile uint16_t PWBFR_1A;                               /*  PWBFR_1A        */
    volatile uint16_t PWBFR_1C;                               /*  PWBFR_1C        */
    volatile uint16_t PWBFR_1E;                               /*  PWBFR_1E        */
    volatile uint16_t PWBFR_1G;                               /*  PWBFR_1G        */
};





/* Start of channnel array defines of PWM */

/* Channnel array defines of PWMn */
/*(Sample) value = PWMn[ channel ]->PWCR_1.UINT16; */
#line 98 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/pwm_iodefine.h"

/* End of channnel array defines of PWM */


#line 127 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/pwm_iodefine.h"
/* <-SEC M1.10.1 */
/* <-MISRA 18.4 */ /* <-SEC M1.6.2 */
#line 122 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/riic_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : riic_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/



struct st_riic
{                                                          /* RIIC             */

    union iodefine_reg32_t  RIICnCR1;                      /*  RIICnCR1        */
    union iodefine_reg32_t  RIICnCR2;                      /*  RIICnCR2        */

    union iodefine_reg32_t  RIICnMR1;                      /*  RIICnMR1        */
    union iodefine_reg32_t  RIICnMR2;                      /*  RIICnMR2        */
    union iodefine_reg32_t  RIICnMR3;                      /*  RIICnMR3        */
    union iodefine_reg32_t  RIICnFER;                      /*  RIICnFER        */
    union iodefine_reg32_t  RIICnSER;                      /*  RIICnSER        */
    union iodefine_reg32_t  RIICnIER;                      /*  RIICnIER        */

    union iodefine_reg32_t  RIICnSR1;                      /*  RIICnSR1        */
    union iodefine_reg32_t  RIICnSR2;                      /*  RIICnSR2        */

    union iodefine_reg32_t  RIICnSAR0;                     /*  RIICnSAR0       */
    union iodefine_reg32_t  RIICnSAR1;                     /*  RIICnSAR1       */
    union iodefine_reg32_t  RIICnSAR2;                     /*  RIICnSAR2       */
    union iodefine_reg32_t  RIICnBRL;                      /*  RIICnBRL        */
    union iodefine_reg32_t  RIICnBRH;                      /*  RIICnBRH        */
    union iodefine_reg32_t  RIICnDRT;                      /*  RIICnDRT        */
    union iodefine_reg32_t  RIICnDRR;                      /*  RIICnDRR        */
    
};








/* Start of channnel array defines of RIIC */

/* Channnel array defines of RIIC */
/*(Sample) value = RIIC[ channel ]->RIICnCR1.UINT32; */






/* End of channnel array defines of RIIC */


#line 123 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/romdec_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : romdec_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_romdec
{                                                          /* ROMDEC           */
    volatile uint8_t   CROMEN;                                 /*  CROMEN          */
    volatile uint8_t   CROMSY0;                                /*  CROMSY0         */

    volatile uint8_t   CROMCTL0;                               /*  CROMCTL0        */
    volatile uint8_t   CROMCTL1;                               /*  CROMCTL1        */
    volatile uint8_t   dummy23[1];                             /*                  */
    volatile uint8_t   CROMCTL3;                               /*  CROMCTL3        */
    volatile uint8_t   CROMCTL4;                               /*  CROMCTL4        */
    volatile uint8_t   CROMCTL5;                               /*  CROMCTL5        */

    volatile uint8_t   CROMST0;                                /*  CROMST0         */
    volatile uint8_t   CROMST1;                                /*  CROMST1         */
    volatile uint8_t   dummy24[1];                             /*                  */
    volatile uint8_t   CROMST3;                                /*  CROMST3         */
    volatile uint8_t   CROMST4;                                /*  CROMST4         */
    volatile uint8_t   CROMST5;                                /*  CROMST5         */
    volatile uint8_t   CROMST6;                                /*  CROMST6         */
    volatile uint8_t   dummy25[5];                             /*                  */

    volatile uint8_t   CBUFST0;                                /*  CBUFST0         */
    volatile uint8_t   CBUFST1;                                /*  CBUFST1         */
    volatile uint8_t   CBUFST2;                                /*  CBUFST2         */
    volatile uint8_t   dummy26[1];                             /*                  */

    volatile uint8_t   HEAD00;                                 /*  HEAD00          */
    volatile uint8_t   HEAD01;                                 /*  HEAD01          */
    volatile uint8_t   HEAD02;                                 /*  HEAD02          */
    volatile uint8_t   HEAD03;                                 /*  HEAD03          */

    volatile uint8_t   SHEAD00;                                /*  SHEAD00         */
    volatile uint8_t   SHEAD01;                                /*  SHEAD01         */
    volatile uint8_t   SHEAD02;                                /*  SHEAD02         */
    volatile uint8_t   SHEAD03;                                /*  SHEAD03         */
    volatile uint8_t   SHEAD04;                                /*  SHEAD04         */
    volatile uint8_t   SHEAD05;                                /*  SHEAD05         */
    volatile uint8_t   SHEAD06;                                /*  SHEAD06         */
    volatile uint8_t   SHEAD07;                                /*  SHEAD07         */

    volatile uint8_t   HEAD20;                                 /*  HEAD20          */
    volatile uint8_t   HEAD21;                                 /*  HEAD21          */
    volatile uint8_t   HEAD22;                                 /*  HEAD22          */
    volatile uint8_t   HEAD23;                                 /*  HEAD23          */

    volatile uint8_t   SHEAD20;                                /*  SHEAD20         */
    volatile uint8_t   SHEAD21;                                /*  SHEAD21         */
    volatile uint8_t   SHEAD22;                                /*  SHEAD22         */
    volatile uint8_t   SHEAD23;                                /*  SHEAD23         */
    volatile uint8_t   SHEAD24;                                /*  SHEAD24         */
    volatile uint8_t   SHEAD25;                                /*  SHEAD25         */
    volatile uint8_t   SHEAD26;                                /*  SHEAD26         */
    volatile uint8_t   SHEAD27;                                /*  SHEAD27         */
    volatile uint8_t   dummy27[16];                            /*                  */

    volatile uint8_t   CBUFCTL0;                               /*  CBUFCTL0        */
    volatile uint8_t   CBUFCTL1;                               /*  CBUFCTL1        */
    volatile uint8_t   CBUFCTL2;                               /*  CBUFCTL2        */
    volatile uint8_t   CBUFCTL3;                               /*  CBUFCTL3        */
    volatile uint8_t   dummy28[1];                             /*                  */
    volatile uint8_t   CROMST0M;                               /*  CROMST0M        */
    volatile uint8_t   dummy29[186];                           /*                  */
    volatile uint8_t   ROMDECRST;                              /*  ROMDECRST       */
    volatile uint8_t   RSTSTAT;                                /*  RSTSTAT         */
    volatile uint8_t   SSI;                                    /*  SSI             */
    volatile uint8_t   dummy30[5];                             /*                  */
    volatile uint8_t   INTHOLD;                                /*  INTHOLD         */
    volatile uint8_t   INHINT;                                 /*  INHINT          */
    volatile uint8_t   dummy31[246];                           /*                  */

    volatile uint16_t STRMDIN0;                               /*  STRMDIN0        */
    volatile uint16_t STRMDIN2;                               /*  STRMDIN2        */
    volatile uint16_t STRMDOUT0;                              /*  STRMDOUT0       */
};





#line 165 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/romdec_iodefine.h"
/* <-SEC M1.10.1 */
#line 124 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/rscan0_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : rscan0_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->QAC 0639 : Over 127 members (C90) */
/* ->QAC 0857 : Over 1024 #define (C90) */
/* ->SEC M1.10.1 : Not magic number */

struct st_rscan0
{                                                          /* RSCAN0           */
/* start of struct st_rscan_from_rscan0cncfg */
    union iodefine_reg32_t  C0CFG;                         /*  C0CFG           */
    union iodefine_reg32_t  C0CTR;                         /*  C0CTR           */
    union iodefine_reg32_t  C0STS;                         /*  C0STS           */
    union iodefine_reg32_t  C0ERFL;                        /*  C0ERFL          */
/* end of struct st_rscan_from_rscan0cncfg */
    
/* start of struct st_rscan_from_rscan0cncfg */
    union iodefine_reg32_t  C1CFG;                         /*  C1CFG           */
    union iodefine_reg32_t  C1CTR;                         /*  C1CTR           */
    union iodefine_reg32_t  C1STS;                         /*  C1STS           */
    union iodefine_reg32_t  C1ERFL;                        /*  C1ERFL          */
/* end of struct st_rscan_from_rscan0cncfg */
    
/* start of struct st_rscan_from_rscan0cncfg */
    union iodefine_reg32_t  C2CFG;                         /*  C2CFG           */
    union iodefine_reg32_t  C2CTR;                         /*  C2CTR           */
    union iodefine_reg32_t  C2STS;                         /*  C2STS           */
    union iodefine_reg32_t  C2ERFL;                        /*  C2ERFL          */
/* end of struct st_rscan_from_rscan0cncfg */
    
/* start of struct st_rscan_from_rscan0cncfg */
    union iodefine_reg32_t  C3CFG;                         /*  C3CFG           */
    union iodefine_reg32_t  C3CTR;                         /*  C3CTR           */
    union iodefine_reg32_t  C3STS;                         /*  C3STS           */
    union iodefine_reg32_t  C3ERFL;                        /*  C3ERFL          */
/* end of struct st_rscan_from_rscan0cncfg */
    
/* start of struct st_rscan_from_rscan0cncfg */
    union iodefine_reg32_t  C4CFG;                         /*  C4CFG           */
    union iodefine_reg32_t  C4CTR;                         /*  C4CTR           */
    union iodefine_reg32_t  C4STS;                         /*  C4STS           */
    union iodefine_reg32_t  C4ERFL;                        /*  C4ERFL          */
/* end of struct st_rscan_from_rscan0cncfg */
    
    volatile uint8_t   dummy159[52];                           /*                  */
    union iodefine_reg32_t  GCFG;                          /*  GCFG            */
    union iodefine_reg32_t  GCTR;                          /*  GCTR            */
    union iodefine_reg32_t  GSTS;                          /*  GSTS            */
    union iodefine_reg32_t  GERFL;                         /*  GERFL           */
    union iodefine_reg32_16_t  GTSC;                       /*  GTSC            */
    union iodefine_reg32_t  GAFLECTR;                      /*  GAFLECTR        */

    union iodefine_reg32_t  GAFLCFG0;                      /*  GAFLCFG0        */
    union iodefine_reg32_t  GAFLCFG1;                      /*  GAFLCFG1        */
    union iodefine_reg32_t  RMNB;                          /*  RMNB            */

    union iodefine_reg32_t  RMND0;                         /*  RMND0           */
    union iodefine_reg32_t  RMND1;                         /*  RMND1           */
    union iodefine_reg32_t  RMND2;                         /*  RMND2           */
    
    volatile uint8_t   dummy160[4];                            /*                  */

    union iodefine_reg32_t  RFCC0;                         /*  RFCC0           */
    union iodefine_reg32_t  RFCC1;                         /*  RFCC1           */
    union iodefine_reg32_t  RFCC2;                         /*  RFCC2           */
    union iodefine_reg32_t  RFCC3;                         /*  RFCC3           */
    union iodefine_reg32_t  RFCC4;                         /*  RFCC4           */
    union iodefine_reg32_t  RFCC5;                         /*  RFCC5           */
    union iodefine_reg32_t  RFCC6;                         /*  RFCC6           */
    union iodefine_reg32_t  RFCC7;                         /*  RFCC7           */

    union iodefine_reg32_t  RFSTS0;                        /*  RFSTS0          */
    union iodefine_reg32_t  RFSTS1;                        /*  RFSTS1          */
    union iodefine_reg32_t  RFSTS2;                        /*  RFSTS2          */
    union iodefine_reg32_t  RFSTS3;                        /*  RFSTS3          */
    union iodefine_reg32_t  RFSTS4;                        /*  RFSTS4          */
    union iodefine_reg32_t  RFSTS5;                        /*  RFSTS5          */
    union iodefine_reg32_t  RFSTS6;                        /*  RFSTS6          */
    union iodefine_reg32_t  RFSTS7;                        /*  RFSTS7          */

    union iodefine_reg32_t  RFPCTR0;                       /*  RFPCTR0         */
    union iodefine_reg32_t  RFPCTR1;                       /*  RFPCTR1         */
    union iodefine_reg32_t  RFPCTR2;                       /*  RFPCTR2         */
    union iodefine_reg32_t  RFPCTR3;                       /*  RFPCTR3         */
    union iodefine_reg32_t  RFPCTR4;                       /*  RFPCTR4         */
    union iodefine_reg32_t  RFPCTR5;                       /*  RFPCTR5         */
    union iodefine_reg32_t  RFPCTR6;                       /*  RFPCTR6         */
    union iodefine_reg32_t  RFPCTR7;                       /*  RFPCTR7         */

    union iodefine_reg32_t  CFCC0;                         /*  CFCC0           */
    union iodefine_reg32_t  CFCC1;                         /*  CFCC1           */
    union iodefine_reg32_t  CFCC2;                         /*  CFCC2           */
    union iodefine_reg32_t  CFCC3;                         /*  CFCC3           */
    union iodefine_reg32_t  CFCC4;                         /*  CFCC4           */
    union iodefine_reg32_t  CFCC5;                         /*  CFCC5           */
    union iodefine_reg32_t  CFCC6;                         /*  CFCC6           */
    union iodefine_reg32_t  CFCC7;                         /*  CFCC7           */
    union iodefine_reg32_t  CFCC8;                         /*  CFCC8           */
    union iodefine_reg32_t  CFCC9;                         /*  CFCC9           */
    union iodefine_reg32_t  CFCC10;                        /*  CFCC10          */
    union iodefine_reg32_t  CFCC11;                        /*  CFCC11          */
    union iodefine_reg32_t  CFCC12;                        /*  CFCC12          */
    union iodefine_reg32_t  CFCC13;                        /*  CFCC13          */
    union iodefine_reg32_t  CFCC14;                        /*  CFCC14          */
    
    volatile uint8_t   dummy161[36];                           /*                  */

    union iodefine_reg32_t  CFSTS0;                        /*  CFSTS0          */
    union iodefine_reg32_t  CFSTS1;                        /*  CFSTS1          */
    union iodefine_reg32_t  CFSTS2;                        /*  CFSTS2          */
    union iodefine_reg32_t  CFSTS3;                        /*  CFSTS3          */
    union iodefine_reg32_t  CFSTS4;                        /*  CFSTS4          */
    union iodefine_reg32_t  CFSTS5;                        /*  CFSTS5          */
    union iodefine_reg32_t  CFSTS6;                        /*  CFSTS6          */
    union iodefine_reg32_t  CFSTS7;                        /*  CFSTS7          */
    union iodefine_reg32_t  CFSTS8;                        /*  CFSTS8          */
    union iodefine_reg32_t  CFSTS9;                        /*  CFSTS9          */
    union iodefine_reg32_t  CFSTS10;                       /*  CFSTS10         */
    union iodefine_reg32_t  CFSTS11;                       /*  CFSTS11         */
    union iodefine_reg32_t  CFSTS12;                       /*  CFSTS12         */
    union iodefine_reg32_t  CFSTS13;                       /*  CFSTS13         */
    union iodefine_reg32_t  CFSTS14;                       /*  CFSTS14         */
    
    volatile uint8_t   dummy162[36];                           /*                  */

    union iodefine_reg32_t  CFPCTR0;                       /*  CFPCTR0         */
    union iodefine_reg32_t  CFPCTR1;                       /*  CFPCTR1         */
    union iodefine_reg32_t  CFPCTR2;                       /*  CFPCTR2         */
    union iodefine_reg32_t  CFPCTR3;                       /*  CFPCTR3         */
    union iodefine_reg32_t  CFPCTR4;                       /*  CFPCTR4         */
    union iodefine_reg32_t  CFPCTR5;                       /*  CFPCTR5         */
    union iodefine_reg32_t  CFPCTR6;                       /*  CFPCTR6         */
    union iodefine_reg32_t  CFPCTR7;                       /*  CFPCTR7         */
    union iodefine_reg32_t  CFPCTR8;                       /*  CFPCTR8         */
    union iodefine_reg32_t  CFPCTR9;                       /*  CFPCTR9         */
    union iodefine_reg32_t  CFPCTR10;                      /*  CFPCTR10        */
    union iodefine_reg32_t  CFPCTR11;                      /*  CFPCTR11        */
    union iodefine_reg32_t  CFPCTR12;                      /*  CFPCTR12        */
    union iodefine_reg32_t  CFPCTR13;                      /*  CFPCTR13        */
    union iodefine_reg32_t  CFPCTR14;                      /*  CFPCTR14        */
    
    volatile uint8_t   dummy163[36];                           /*                  */
    union iodefine_reg32_t  FESTS;                         /*  FESTS           */
    union iodefine_reg32_t  FFSTS;                         /*  FFSTS           */
    union iodefine_reg32_t  FMSTS;                         /*  FMSTS           */
    union iodefine_reg32_t  RFISTS;                        /*  RFISTS          */
    union iodefine_reg32_t  CFRISTS;                       /*  CFRISTS         */
    union iodefine_reg32_t  CFTISTS;                       /*  CFTISTS         */
    

    volatile uint8_t   TMC0;                                   /*  TMC0            */
    volatile uint8_t   TMC1;                                   /*  TMC1            */
    volatile uint8_t   TMC2;                                   /*  TMC2            */
    volatile uint8_t   TMC3;                                   /*  TMC3            */
    volatile uint8_t   TMC4;                                   /*  TMC4            */
    volatile uint8_t   TMC5;                                   /*  TMC5            */
    volatile uint8_t   TMC6;                                   /*  TMC6            */
    volatile uint8_t   TMC7;                                   /*  TMC7            */
    volatile uint8_t   TMC8;                                   /*  TMC8            */
    volatile uint8_t   TMC9;                                   /*  TMC9            */
    volatile uint8_t   TMC10;                                  /*  TMC10           */
    volatile uint8_t   TMC11;                                  /*  TMC11           */
    volatile uint8_t   TMC12;                                  /*  TMC12           */
    volatile uint8_t   TMC13;                                  /*  TMC13           */
    volatile uint8_t   TMC14;                                  /*  TMC14           */
    volatile uint8_t   TMC15;                                  /*  TMC15           */
    volatile uint8_t   TMC16;                                  /*  TMC16           */
    volatile uint8_t   TMC17;                                  /*  TMC17           */
    volatile uint8_t   TMC18;                                  /*  TMC18           */
    volatile uint8_t   TMC19;                                  /*  TMC19           */
    volatile uint8_t   TMC20;                                  /*  TMC20           */
    volatile uint8_t   TMC21;                                  /*  TMC21           */
    volatile uint8_t   TMC22;                                  /*  TMC22           */
    volatile uint8_t   TMC23;                                  /*  TMC23           */
    volatile uint8_t   TMC24;                                  /*  TMC24           */
    volatile uint8_t   TMC25;                                  /*  TMC25           */
    volatile uint8_t   TMC26;                                  /*  TMC26           */
    volatile uint8_t   TMC27;                                  /*  TMC27           */
    volatile uint8_t   TMC28;                                  /*  TMC28           */
    volatile uint8_t   TMC29;                                  /*  TMC29           */
    volatile uint8_t   TMC30;                                  /*  TMC30           */
    volatile uint8_t   TMC31;                                  /*  TMC31           */
    volatile uint8_t   TMC32;                                  /*  TMC32           */
    volatile uint8_t   TMC33;                                  /*  TMC33           */
    volatile uint8_t   TMC34;                                  /*  TMC34           */
    volatile uint8_t   TMC35;                                  /*  TMC35           */
    volatile uint8_t   TMC36;                                  /*  TMC36           */
    volatile uint8_t   TMC37;                                  /*  TMC37           */
    volatile uint8_t   TMC38;                                  /*  TMC38           */
    volatile uint8_t   TMC39;                                  /*  TMC39           */
    volatile uint8_t   TMC40;                                  /*  TMC40           */
    volatile uint8_t   TMC41;                                  /*  TMC41           */
    volatile uint8_t   TMC42;                                  /*  TMC42           */
    volatile uint8_t   TMC43;                                  /*  TMC43           */
    volatile uint8_t   TMC44;                                  /*  TMC44           */
    volatile uint8_t   TMC45;                                  /*  TMC45           */
    volatile uint8_t   TMC46;                                  /*  TMC46           */
    volatile uint8_t   TMC47;                                  /*  TMC47           */
    volatile uint8_t   TMC48;                                  /*  TMC48           */
    volatile uint8_t   TMC49;                                  /*  TMC49           */
    volatile uint8_t   TMC50;                                  /*  TMC50           */
    volatile uint8_t   TMC51;                                  /*  TMC51           */
    volatile uint8_t   TMC52;                                  /*  TMC52           */
    volatile uint8_t   TMC53;                                  /*  TMC53           */
    volatile uint8_t   TMC54;                                  /*  TMC54           */
    volatile uint8_t   TMC55;                                  /*  TMC55           */
    volatile uint8_t   TMC56;                                  /*  TMC56           */
    volatile uint8_t   TMC57;                                  /*  TMC57           */
    volatile uint8_t   TMC58;                                  /*  TMC58           */
    volatile uint8_t   TMC59;                                  /*  TMC59           */
    volatile uint8_t   TMC60;                                  /*  TMC60           */
    volatile uint8_t   TMC61;                                  /*  TMC61           */
    volatile uint8_t   TMC62;                                  /*  TMC62           */
    volatile uint8_t   TMC63;                                  /*  TMC63           */
    volatile uint8_t   TMC64;                                  /*  TMC64           */
    volatile uint8_t   TMC65;                                  /*  TMC65           */
    volatile uint8_t   TMC66;                                  /*  TMC66           */
    volatile uint8_t   TMC67;                                  /*  TMC67           */
    volatile uint8_t   TMC68;                                  /*  TMC68           */
    volatile uint8_t   TMC69;                                  /*  TMC69           */
    volatile uint8_t   TMC70;                                  /*  TMC70           */
    volatile uint8_t   TMC71;                                  /*  TMC71           */
    volatile uint8_t   TMC72;                                  /*  TMC72           */
    volatile uint8_t   TMC73;                                  /*  TMC73           */
    volatile uint8_t   TMC74;                                  /*  TMC74           */
    volatile uint8_t   TMC75;                                  /*  TMC75           */
    volatile uint8_t   TMC76;                                  /*  TMC76           */
    volatile uint8_t   TMC77;                                  /*  TMC77           */
    volatile uint8_t   TMC78;                                  /*  TMC78           */
    volatile uint8_t   TMC79;                                  /*  TMC79           */
    volatile uint8_t   dummy164[48];                           /*                  */

    volatile uint8_t   TMSTS0;                                 /*  TMSTS0          */
    volatile uint8_t   TMSTS1;                                 /*  TMSTS1          */
    volatile uint8_t   TMSTS2;                                 /*  TMSTS2          */
    volatile uint8_t   TMSTS3;                                 /*  TMSTS3          */
    volatile uint8_t   TMSTS4;                                 /*  TMSTS4          */
    volatile uint8_t   TMSTS5;                                 /*  TMSTS5          */
    volatile uint8_t   TMSTS6;                                 /*  TMSTS6          */
    volatile uint8_t   TMSTS7;                                 /*  TMSTS7          */
    volatile uint8_t   TMSTS8;                                 /*  TMSTS8          */
    volatile uint8_t   TMSTS9;                                 /*  TMSTS9          */
    volatile uint8_t   TMSTS10;                                /*  TMSTS10         */
    volatile uint8_t   TMSTS11;                                /*  TMSTS11         */
    volatile uint8_t   TMSTS12;                                /*  TMSTS12         */
    volatile uint8_t   TMSTS13;                                /*  TMSTS13         */
    volatile uint8_t   TMSTS14;                                /*  TMSTS14         */
    volatile uint8_t   TMSTS15;                                /*  TMSTS15         */
    volatile uint8_t   TMSTS16;                                /*  TMSTS16         */
    volatile uint8_t   TMSTS17;                                /*  TMSTS17         */
    volatile uint8_t   TMSTS18;                                /*  TMSTS18         */
    volatile uint8_t   TMSTS19;                                /*  TMSTS19         */
    volatile uint8_t   TMSTS20;                                /*  TMSTS20         */
    volatile uint8_t   TMSTS21;                                /*  TMSTS21         */
    volatile uint8_t   TMSTS22;                                /*  TMSTS22         */
    volatile uint8_t   TMSTS23;                                /*  TMSTS23         */
    volatile uint8_t   TMSTS24;                                /*  TMSTS24         */
    volatile uint8_t   TMSTS25;                                /*  TMSTS25         */
    volatile uint8_t   TMSTS26;                                /*  TMSTS26         */
    volatile uint8_t   TMSTS27;                                /*  TMSTS27         */
    volatile uint8_t   TMSTS28;                                /*  TMSTS28         */
    volatile uint8_t   TMSTS29;                                /*  TMSTS29         */
    volatile uint8_t   TMSTS30;                                /*  TMSTS30         */
    volatile uint8_t   TMSTS31;                                /*  TMSTS31         */
    volatile uint8_t   TMSTS32;                                /*  TMSTS32         */
    volatile uint8_t   TMSTS33;                                /*  TMSTS33         */
    volatile uint8_t   TMSTS34;                                /*  TMSTS34         */
    volatile uint8_t   TMSTS35;                                /*  TMSTS35         */
    volatile uint8_t   TMSTS36;                                /*  TMSTS36         */
    volatile uint8_t   TMSTS37;                                /*  TMSTS37         */
    volatile uint8_t   TMSTS38;                                /*  TMSTS38         */
    volatile uint8_t   TMSTS39;                                /*  TMSTS39         */
    volatile uint8_t   TMSTS40;                                /*  TMSTS40         */
    volatile uint8_t   TMSTS41;                                /*  TMSTS41         */
    volatile uint8_t   TMSTS42;                                /*  TMSTS42         */
    volatile uint8_t   TMSTS43;                                /*  TMSTS43         */
    volatile uint8_t   TMSTS44;                                /*  TMSTS44         */
    volatile uint8_t   TMSTS45;                                /*  TMSTS45         */
    volatile uint8_t   TMSTS46;                                /*  TMSTS46         */
    volatile uint8_t   TMSTS47;                                /*  TMSTS47         */
    volatile uint8_t   TMSTS48;                                /*  TMSTS48         */
    volatile uint8_t   TMSTS49;                                /*  TMSTS49         */
    volatile uint8_t   TMSTS50;                                /*  TMSTS50         */
    volatile uint8_t   TMSTS51;                                /*  TMSTS51         */
    volatile uint8_t   TMSTS52;                                /*  TMSTS52         */
    volatile uint8_t   TMSTS53;                                /*  TMSTS53         */
    volatile uint8_t   TMSTS54;                                /*  TMSTS54         */
    volatile uint8_t   TMSTS55;                                /*  TMSTS55         */
    volatile uint8_t   TMSTS56;                                /*  TMSTS56         */
    volatile uint8_t   TMSTS57;                                /*  TMSTS57         */
    volatile uint8_t   TMSTS58;                                /*  TMSTS58         */
    volatile uint8_t   TMSTS59;                                /*  TMSTS59         */
    volatile uint8_t   TMSTS60;                                /*  TMSTS60         */
    volatile uint8_t   TMSTS61;                                /*  TMSTS61         */
    volatile uint8_t   TMSTS62;                                /*  TMSTS62         */
    volatile uint8_t   TMSTS63;                                /*  TMSTS63         */
    volatile uint8_t   TMSTS64;                                /*  TMSTS64         */
    volatile uint8_t   TMSTS65;                                /*  TMSTS65         */
    volatile uint8_t   TMSTS66;                                /*  TMSTS66         */
    volatile uint8_t   TMSTS67;                                /*  TMSTS67         */
    volatile uint8_t   TMSTS68;                                /*  TMSTS68         */
    volatile uint8_t   TMSTS69;                                /*  TMSTS69         */
    volatile uint8_t   TMSTS70;                                /*  TMSTS70         */
    volatile uint8_t   TMSTS71;                                /*  TMSTS71         */
    volatile uint8_t   TMSTS72;                                /*  TMSTS72         */
    volatile uint8_t   TMSTS73;                                /*  TMSTS73         */
    volatile uint8_t   TMSTS74;                                /*  TMSTS74         */
    volatile uint8_t   TMSTS75;                                /*  TMSTS75         */
    volatile uint8_t   TMSTS76;                                /*  TMSTS76         */
    volatile uint8_t   TMSTS77;                                /*  TMSTS77         */
    volatile uint8_t   TMSTS78;                                /*  TMSTS78         */
    volatile uint8_t   TMSTS79;                                /*  TMSTS79         */
    volatile uint8_t   dummy165[48];                           /*                  */

    union iodefine_reg32_t  TMTRSTS0;                      /*  TMTRSTS0        */
    union iodefine_reg32_t  TMTRSTS1;                      /*  TMTRSTS1        */
    union iodefine_reg32_t  TMTRSTS2;                      /*  TMTRSTS2        */
    
    volatile uint8_t   dummy166[4];                            /*                  */

    union iodefine_reg32_t  TMTARSTS0;                     /*  TMTARSTS0       */
    union iodefine_reg32_t  TMTARSTS1;                     /*  TMTARSTS1       */
    union iodefine_reg32_t  TMTARSTS2;                     /*  TMTARSTS2       */
    
    volatile uint8_t   dummy167[4];                            /*                  */

    union iodefine_reg32_t  TMTCSTS0;                      /*  TMTCSTS0        */
    union iodefine_reg32_t  TMTCSTS1;                      /*  TMTCSTS1        */
    union iodefine_reg32_t  TMTCSTS2;                      /*  TMTCSTS2        */
    
    volatile uint8_t   dummy168[4];                            /*                  */

    union iodefine_reg32_t  TMTASTS0;                      /*  TMTASTS0        */
    union iodefine_reg32_t  TMTASTS1;                      /*  TMTASTS1        */
    union iodefine_reg32_t  TMTASTS2;                      /*  TMTASTS2        */
    
    volatile uint8_t   dummy169[4];                            /*                  */

    union iodefine_reg32_t  TMIEC0;                        /*  TMIEC0          */
    union iodefine_reg32_t  TMIEC1;                        /*  TMIEC1          */
    union iodefine_reg32_t  TMIEC2;                        /*  TMIEC2          */
    
    volatile uint8_t   dummy170[4];                            /*                  */

    union iodefine_reg32_t  TXQCC0;                        /*  TXQCC0          */
    union iodefine_reg32_t  TXQCC1;                        /*  TXQCC1          */
    union iodefine_reg32_t  TXQCC2;                        /*  TXQCC2          */
    union iodefine_reg32_t  TXQCC3;                        /*  TXQCC3          */
    union iodefine_reg32_t  TXQCC4;                        /*  TXQCC4          */
    
    volatile uint8_t   dummy171[12];                           /*                  */

    union iodefine_reg32_t  TXQSTS0;                       /*  TXQSTS0         */
    union iodefine_reg32_t  TXQSTS1;                       /*  TXQSTS1         */
    union iodefine_reg32_t  TXQSTS2;                       /*  TXQSTS2         */
    union iodefine_reg32_t  TXQSTS3;                       /*  TXQSTS3         */
    union iodefine_reg32_t  TXQSTS4;                       /*  TXQSTS4         */
    
    volatile uint8_t   dummy172[12];                           /*                  */

    union iodefine_reg32_t  TXQPCTR0;                      /*  TXQPCTR0        */
    union iodefine_reg32_t  TXQPCTR1;                      /*  TXQPCTR1        */
    union iodefine_reg32_t  TXQPCTR2;                      /*  TXQPCTR2        */
    union iodefine_reg32_t  TXQPCTR3;                      /*  TXQPCTR3        */
    union iodefine_reg32_t  TXQPCTR4;                      /*  TXQPCTR4        */
    
    volatile uint8_t   dummy173[12];                           /*                  */

    union iodefine_reg32_t  THLCC0;                        /*  THLCC0          */
    union iodefine_reg32_t  THLCC1;                        /*  THLCC1          */
    union iodefine_reg32_t  THLCC2;                        /*  THLCC2          */
    union iodefine_reg32_t  THLCC3;                        /*  THLCC3          */
    union iodefine_reg32_t  THLCC4;                        /*  THLCC4          */
    
    volatile uint8_t   dummy174[12];                           /*                  */

    union iodefine_reg32_t  THLSTS0;                       /*  THLSTS0         */
    union iodefine_reg32_t  THLSTS1;                       /*  THLSTS1         */
    union iodefine_reg32_t  THLSTS2;                       /*  THLSTS2         */
    union iodefine_reg32_t  THLSTS3;                       /*  THLSTS3         */
    union iodefine_reg32_t  THLSTS4;                       /*  THLSTS4         */
    
    volatile uint8_t   dummy175[12];                           /*                  */

    union iodefine_reg32_t  THLPCTR0;                      /*  THLPCTR0        */
    union iodefine_reg32_t  THLPCTR1;                      /*  THLPCTR1        */
    union iodefine_reg32_t  THLPCTR2;                      /*  THLPCTR2        */
    union iodefine_reg32_t  THLPCTR3;                      /*  THLPCTR3        */
    union iodefine_reg32_t  THLPCTR4;                      /*  THLPCTR4        */
    
    volatile uint8_t   dummy176[12];                           /*                  */

    union iodefine_reg32_t  GTINTSTS0;                     /*  GTINTSTS0       */
    union iodefine_reg32_t  GTINTSTS1;                     /*  GTINTSTS1       */
    union iodefine_reg32_t  GTSTCFG;                       /*  GTSTCFG         */
    union iodefine_reg32_t  GTSTCTR;                       /*  GTSTCTR         */
    
    volatile uint8_t   dummy177[12];                           /*                  */
    union iodefine_reg32_16_t  GLOCKK;                     /*  GLOCKK          */
    
    volatile uint8_t   dummy178[128];                          /*                  */
    
/* start of struct st_rscan_from_rscan0gaflidj */
    union iodefine_reg32_t  GAFLID0;                       /*  GAFLID0         */
    union iodefine_reg32_t  GAFLM0;                        /*  GAFLM0          */
    union iodefine_reg32_t  GAFLP00;                       /*  GAFLP00         */
    union iodefine_reg32_t  GAFLP10;                       /*  GAFLP10         */
/* end of struct st_rscan_from_rscan0gaflidj */
    
/* start of struct st_rscan_from_rscan0gaflidj */
    union iodefine_reg32_t  GAFLID1;                       /*  GAFLID1         */
    union iodefine_reg32_t  GAFLM1;                        /*  GAFLM1          */
    union iodefine_reg32_t  GAFLP01;                       /*  GAFLP01         */
    union iodefine_reg32_t  GAFLP11;                       /*  GAFLP11         */
/* end of struct st_rscan_from_rscan0gaflidj */
    
/* start of struct st_rscan_from_rscan0gaflidj */
    union iodefine_reg32_t  GAFLID2;                       /*  GAFLID2         */
    union iodefine_reg32_t  GAFLM2;                        /*  GAFLM2          */
    union iodefine_reg32_t  GAFLP02;                       /*  GAFLP02         */
    union iodefine_reg32_t  GAFLP12;                       /*  GAFLP12         */
/* end of struct st_rscan_from_rscan0gaflidj */
    
/* start of struct st_rscan_from_rscan0gaflidj */
    union iodefine_reg32_t  GAFLID3;                       /*  GAFLID3         */
    union iodefine_reg32_t  GAFLM3;                        /*  GAFLM3          */
    union iodefine_reg32_t  GAFLP03;                       /*  GAFLP03         */
    union iodefine_reg32_t  GAFLP13;                       /*  GAFLP13         */
/* end of struct st_rscan_from_rscan0gaflidj */
    
/* start of struct st_rscan_from_rscan0gaflidj */
    union iodefine_reg32_t  GAFLID4;                       /*  GAFLID4         */
    union iodefine_reg32_t  GAFLM4;                        /*  GAFLM4          */
    union iodefine_reg32_t  GAFLP04;                       /*  GAFLP04         */
    union iodefine_reg32_t  GAFLP14;                       /*  GAFLP14         */
/* end of struct st_rscan_from_rscan0gaflidj */
    
/* start of struct st_rscan_from_rscan0gaflidj */
    union iodefine_reg32_t  GAFLID5;                       /*  GAFLID5         */
    union iodefine_reg32_t  GAFLM5;                        /*  GAFLM5          */
    union iodefine_reg32_t  GAFLP05;                       /*  GAFLP05         */
    union iodefine_reg32_t  GAFLP15;                       /*  GAFLP15         */
/* end of struct st_rscan_from_rscan0gaflidj */
    
/* start of struct st_rscan_from_rscan0gaflidj */
    union iodefine_reg32_t  GAFLID6;                       /*  GAFLID6         */
    union iodefine_reg32_t  GAFLM6;                        /*  GAFLM6          */
    union iodefine_reg32_t  GAFLP06;                       /*  GAFLP06         */
    union iodefine_reg32_t  GAFLP16;                       /*  GAFLP16         */
/* end of struct st_rscan_from_rscan0gaflidj */
    
/* start of struct st_rscan_from_rscan0gaflidj */
    union iodefine_reg32_t  GAFLID7;                       /*  GAFLID7         */
    union iodefine_reg32_t  GAFLM7;                        /*  GAFLM7          */
    union iodefine_reg32_t  GAFLP07;                       /*  GAFLP07         */
    union iodefine_reg32_t  GAFLP17;                       /*  GAFLP17         */
/* end of struct st_rscan_from_rscan0gaflidj */
    
/* start of struct st_rscan_from_rscan0gaflidj */
    union iodefine_reg32_t  GAFLID8;                       /*  GAFLID8         */
    union iodefine_reg32_t  GAFLM8;                        /*  GAFLM8          */
    union iodefine_reg32_t  GAFLP08;                       /*  GAFLP08         */
    union iodefine_reg32_t  GAFLP18;                       /*  GAFLP18         */
/* end of struct st_rscan_from_rscan0gaflidj */
    
/* start of struct st_rscan_from_rscan0gaflidj */
    union iodefine_reg32_t  GAFLID9;                       /*  GAFLID9         */
    union iodefine_reg32_t  GAFLM9;                        /*  GAFLM9          */
    union iodefine_reg32_t  GAFLP09;                       /*  GAFLP09         */
    union iodefine_reg32_t  GAFLP19;                       /*  GAFLP19         */
/* end of struct st_rscan_from_rscan0gaflidj */
    
/* start of struct st_rscan_from_rscan0gaflidj */
    union iodefine_reg32_t  GAFLID10;                      /*  GAFLID10        */
    union iodefine_reg32_t  GAFLM10;                       /*  GAFLM10         */
    union iodefine_reg32_t  GAFLP010;                      /*  GAFLP010        */
    union iodefine_reg32_t  GAFLP110;                      /*  GAFLP110        */
/* end of struct st_rscan_from_rscan0gaflidj */
    
/* start of struct st_rscan_from_rscan0gaflidj */
    union iodefine_reg32_t  GAFLID11;                      /*  GAFLID11        */
    union iodefine_reg32_t  GAFLM11;                       /*  GAFLM11         */
    union iodefine_reg32_t  GAFLP011;                      /*  GAFLP011        */
    union iodefine_reg32_t  GAFLP111;                      /*  GAFLP111        */
/* end of struct st_rscan_from_rscan0gaflidj */
    
/* start of struct st_rscan_from_rscan0gaflidj */
    union iodefine_reg32_t  GAFLID12;                      /*  GAFLID12        */
    union iodefine_reg32_t  GAFLM12;                       /*  GAFLM12         */
    union iodefine_reg32_t  GAFLP012;                      /*  GAFLP012        */
    union iodefine_reg32_t  GAFLP112;                      /*  GAFLP112        */
/* end of struct st_rscan_from_rscan0gaflidj */
    
/* start of struct st_rscan_from_rscan0gaflidj */
    union iodefine_reg32_t  GAFLID13;                      /*  GAFLID13        */
    union iodefine_reg32_t  GAFLM13;                       /*  GAFLM13         */
    union iodefine_reg32_t  GAFLP013;                      /*  GAFLP013        */
    union iodefine_reg32_t  GAFLP113;                      /*  GAFLP113        */
/* end of struct st_rscan_from_rscan0gaflidj */
    
/* start of struct st_rscan_from_rscan0gaflidj */
    union iodefine_reg32_t  GAFLID14;                      /*  GAFLID14        */
    union iodefine_reg32_t  GAFLM14;                       /*  GAFLM14         */
    union iodefine_reg32_t  GAFLP014;                      /*  GAFLP014        */
    union iodefine_reg32_t  GAFLP114;                      /*  GAFLP114        */
/* end of struct st_rscan_from_rscan0gaflidj */
    
/* start of struct st_rscan_from_rscan0gaflidj */
    union iodefine_reg32_t  GAFLID15;                      /*  GAFLID15        */
    union iodefine_reg32_t  GAFLM15;                       /*  GAFLM15         */
    union iodefine_reg32_t  GAFLP015;                      /*  GAFLP015        */
    union iodefine_reg32_t  GAFLP115;                      /*  GAFLP115        */
/* end of struct st_rscan_from_rscan0gaflidj */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID0;                         /*  RMID0           */
    union iodefine_reg32_t  RMPTR0;                        /*  RMPTR0          */
    union iodefine_reg32_t  RMDF00;                        /*  RMDF00          */
    union iodefine_reg32_t  RMDF10;                        /*  RMDF10          */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID1;                         /*  RMID1           */
    union iodefine_reg32_t  RMPTR1;                        /*  RMPTR1          */
    union iodefine_reg32_t  RMDF01;                        /*  RMDF01          */
    union iodefine_reg32_t  RMDF11;                        /*  RMDF11          */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID2;                         /*  RMID2           */
    union iodefine_reg32_t  RMPTR2;                        /*  RMPTR2          */
    union iodefine_reg32_t  RMDF02;                        /*  RMDF02          */
    union iodefine_reg32_t  RMDF12;                        /*  RMDF12          */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID3;                         /*  RMID3           */
    union iodefine_reg32_t  RMPTR3;                        /*  RMPTR3          */
    union iodefine_reg32_t  RMDF03;                        /*  RMDF03          */
    union iodefine_reg32_t  RMDF13;                        /*  RMDF13          */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID4;                         /*  RMID4           */
    union iodefine_reg32_t  RMPTR4;                        /*  RMPTR4          */
    union iodefine_reg32_t  RMDF04;                        /*  RMDF04          */
    union iodefine_reg32_t  RMDF14;                        /*  RMDF14          */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID5;                         /*  RMID5           */
    union iodefine_reg32_t  RMPTR5;                        /*  RMPTR5          */
    union iodefine_reg32_t  RMDF05;                        /*  RMDF05          */
    union iodefine_reg32_t  RMDF15;                        /*  RMDF15          */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID6;                         /*  RMID6           */
    union iodefine_reg32_t  RMPTR6;                        /*  RMPTR6          */
    union iodefine_reg32_t  RMDF06;                        /*  RMDF06          */
    union iodefine_reg32_t  RMDF16;                        /*  RMDF16          */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID7;                         /*  RMID7           */
    union iodefine_reg32_t  RMPTR7;                        /*  RMPTR7          */
    union iodefine_reg32_t  RMDF07;                        /*  RMDF07          */
    union iodefine_reg32_t  RMDF17;                        /*  RMDF17          */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID8;                         /*  RMID8           */
    union iodefine_reg32_t  RMPTR8;                        /*  RMPTR8          */
    union iodefine_reg32_t  RMDF08;                        /*  RMDF08          */
    union iodefine_reg32_t  RMDF18;                        /*  RMDF18          */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID9;                         /*  RMID9           */
    union iodefine_reg32_t  RMPTR9;                        /*  RMPTR9          */
    union iodefine_reg32_t  RMDF09;                        /*  RMDF09          */
    union iodefine_reg32_t  RMDF19;                        /*  RMDF19          */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID10;                        /*  RMID10          */
    union iodefine_reg32_t  RMPTR10;                       /*  RMPTR10         */
    union iodefine_reg32_t  RMDF010;                       /*  RMDF010         */
    union iodefine_reg32_t  RMDF110;                       /*  RMDF110         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID11;                        /*  RMID11          */
    union iodefine_reg32_t  RMPTR11;                       /*  RMPTR11         */
    union iodefine_reg32_t  RMDF011;                       /*  RMDF011         */
    union iodefine_reg32_t  RMDF111;                       /*  RMDF111         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID12;                        /*  RMID12          */
    union iodefine_reg32_t  RMPTR12;                       /*  RMPTR12         */
    union iodefine_reg32_t  RMDF012;                       /*  RMDF012         */
    union iodefine_reg32_t  RMDF112;                       /*  RMDF112         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID13;                        /*  RMID13          */
    union iodefine_reg32_t  RMPTR13;                       /*  RMPTR13         */
    union iodefine_reg32_t  RMDF013;                       /*  RMDF013         */
    union iodefine_reg32_t  RMDF113;                       /*  RMDF113         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID14;                        /*  RMID14          */
    union iodefine_reg32_t  RMPTR14;                       /*  RMPTR14         */
    union iodefine_reg32_t  RMDF014;                       /*  RMDF014         */
    union iodefine_reg32_t  RMDF114;                       /*  RMDF114         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID15;                        /*  RMID15          */
    union iodefine_reg32_t  RMPTR15;                       /*  RMPTR15         */
    union iodefine_reg32_t  RMDF015;                       /*  RMDF015         */
    union iodefine_reg32_t  RMDF115;                       /*  RMDF115         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID16;                        /*  RMID16          */
    union iodefine_reg32_t  RMPTR16;                       /*  RMPTR16         */
    union iodefine_reg32_t  RMDF016;                       /*  RMDF016         */
    union iodefine_reg32_t  RMDF116;                       /*  RMDF116         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID17;                        /*  RMID17          */
    union iodefine_reg32_t  RMPTR17;                       /*  RMPTR17         */
    union iodefine_reg32_t  RMDF017;                       /*  RMDF017         */
    union iodefine_reg32_t  RMDF117;                       /*  RMDF117         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID18;                        /*  RMID18          */
    union iodefine_reg32_t  RMPTR18;                       /*  RMPTR18         */
    union iodefine_reg32_t  RMDF018;                       /*  RMDF018         */
    union iodefine_reg32_t  RMDF118;                       /*  RMDF118         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID19;                        /*  RMID19          */
    union iodefine_reg32_t  RMPTR19;                       /*  RMPTR19         */
    union iodefine_reg32_t  RMDF019;                       /*  RMDF019         */
    union iodefine_reg32_t  RMDF119;                       /*  RMDF119         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID20;                        /*  RMID20          */
    union iodefine_reg32_t  RMPTR20;                       /*  RMPTR20         */
    union iodefine_reg32_t  RMDF020;                       /*  RMDF020         */
    union iodefine_reg32_t  RMDF120;                       /*  RMDF120         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID21;                        /*  RMID21          */
    union iodefine_reg32_t  RMPTR21;                       /*  RMPTR21         */
    union iodefine_reg32_t  RMDF021;                       /*  RMDF021         */
    union iodefine_reg32_t  RMDF121;                       /*  RMDF121         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID22;                        /*  RMID22          */
    union iodefine_reg32_t  RMPTR22;                       /*  RMPTR22         */
    union iodefine_reg32_t  RMDF022;                       /*  RMDF022         */
    union iodefine_reg32_t  RMDF122;                       /*  RMDF122         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID23;                        /*  RMID23          */
    union iodefine_reg32_t  RMPTR23;                       /*  RMPTR23         */
    union iodefine_reg32_t  RMDF023;                       /*  RMDF023         */
    union iodefine_reg32_t  RMDF123;                       /*  RMDF123         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID24;                        /*  RMID24          */
    union iodefine_reg32_t  RMPTR24;                       /*  RMPTR24         */
    union iodefine_reg32_t  RMDF024;                       /*  RMDF024         */
    union iodefine_reg32_t  RMDF124;                       /*  RMDF124         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID25;                        /*  RMID25          */
    union iodefine_reg32_t  RMPTR25;                       /*  RMPTR25         */
    union iodefine_reg32_t  RMDF025;                       /*  RMDF025         */
    union iodefine_reg32_t  RMDF125;                       /*  RMDF125         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID26;                        /*  RMID26          */
    union iodefine_reg32_t  RMPTR26;                       /*  RMPTR26         */
    union iodefine_reg32_t  RMDF026;                       /*  RMDF026         */
    union iodefine_reg32_t  RMDF126;                       /*  RMDF126         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID27;                        /*  RMID27          */
    union iodefine_reg32_t  RMPTR27;                       /*  RMPTR27         */
    union iodefine_reg32_t  RMDF027;                       /*  RMDF027         */
    union iodefine_reg32_t  RMDF127;                       /*  RMDF127         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID28;                        /*  RMID28          */
    union iodefine_reg32_t  RMPTR28;                       /*  RMPTR28         */
    union iodefine_reg32_t  RMDF028;                       /*  RMDF028         */
    union iodefine_reg32_t  RMDF128;                       /*  RMDF128         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID29;                        /*  RMID29          */
    union iodefine_reg32_t  RMPTR29;                       /*  RMPTR29         */
    union iodefine_reg32_t  RMDF029;                       /*  RMDF029         */
    union iodefine_reg32_t  RMDF129;                       /*  RMDF129         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID30;                        /*  RMID30          */
    union iodefine_reg32_t  RMPTR30;                       /*  RMPTR30         */
    union iodefine_reg32_t  RMDF030;                       /*  RMDF030         */
    union iodefine_reg32_t  RMDF130;                       /*  RMDF130         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID31;                        /*  RMID31          */
    union iodefine_reg32_t  RMPTR31;                       /*  RMPTR31         */
    union iodefine_reg32_t  RMDF031;                       /*  RMDF031         */
    union iodefine_reg32_t  RMDF131;                       /*  RMDF131         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID32;                        /*  RMID32          */
    union iodefine_reg32_t  RMPTR32;                       /*  RMPTR32         */
    union iodefine_reg32_t  RMDF032;                       /*  RMDF032         */
    union iodefine_reg32_t  RMDF132;                       /*  RMDF132         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID33;                        /*  RMID33          */
    union iodefine_reg32_t  RMPTR33;                       /*  RMPTR33         */
    union iodefine_reg32_t  RMDF033;                       /*  RMDF033         */
    union iodefine_reg32_t  RMDF133;                       /*  RMDF133         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID34;                        /*  RMID34          */
    union iodefine_reg32_t  RMPTR34;                       /*  RMPTR34         */
    union iodefine_reg32_t  RMDF034;                       /*  RMDF034         */
    union iodefine_reg32_t  RMDF134;                       /*  RMDF134         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID35;                        /*  RMID35          */
    union iodefine_reg32_t  RMPTR35;                       /*  RMPTR35         */
    union iodefine_reg32_t  RMDF035;                       /*  RMDF035         */
    union iodefine_reg32_t  RMDF135;                       /*  RMDF135         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID36;                        /*  RMID36          */
    union iodefine_reg32_t  RMPTR36;                       /*  RMPTR36         */
    union iodefine_reg32_t  RMDF036;                       /*  RMDF036         */
    union iodefine_reg32_t  RMDF136;                       /*  RMDF136         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID37;                        /*  RMID37          */
    union iodefine_reg32_t  RMPTR37;                       /*  RMPTR37         */
    union iodefine_reg32_t  RMDF037;                       /*  RMDF037         */
    union iodefine_reg32_t  RMDF137;                       /*  RMDF137         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID38;                        /*  RMID38          */
    union iodefine_reg32_t  RMPTR38;                       /*  RMPTR38         */
    union iodefine_reg32_t  RMDF038;                       /*  RMDF038         */
    union iodefine_reg32_t  RMDF138;                       /*  RMDF138         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID39;                        /*  RMID39          */
    union iodefine_reg32_t  RMPTR39;                       /*  RMPTR39         */
    union iodefine_reg32_t  RMDF039;                       /*  RMDF039         */
    union iodefine_reg32_t  RMDF139;                       /*  RMDF139         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID40;                        /*  RMID40          */
    union iodefine_reg32_t  RMPTR40;                       /*  RMPTR40         */
    union iodefine_reg32_t  RMDF040;                       /*  RMDF040         */
    union iodefine_reg32_t  RMDF140;                       /*  RMDF140         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID41;                        /*  RMID41          */
    union iodefine_reg32_t  RMPTR41;                       /*  RMPTR41         */
    union iodefine_reg32_t  RMDF041;                       /*  RMDF041         */
    union iodefine_reg32_t  RMDF141;                       /*  RMDF141         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID42;                        /*  RMID42          */
    union iodefine_reg32_t  RMPTR42;                       /*  RMPTR42         */
    union iodefine_reg32_t  RMDF042;                       /*  RMDF042         */
    union iodefine_reg32_t  RMDF142;                       /*  RMDF142         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID43;                        /*  RMID43          */
    union iodefine_reg32_t  RMPTR43;                       /*  RMPTR43         */
    union iodefine_reg32_t  RMDF043;                       /*  RMDF043         */
    union iodefine_reg32_t  RMDF143;                       /*  RMDF143         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID44;                        /*  RMID44          */
    union iodefine_reg32_t  RMPTR44;                       /*  RMPTR44         */
    union iodefine_reg32_t  RMDF044;                       /*  RMDF044         */
    union iodefine_reg32_t  RMDF144;                       /*  RMDF144         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID45;                        /*  RMID45          */
    union iodefine_reg32_t  RMPTR45;                       /*  RMPTR45         */
    union iodefine_reg32_t  RMDF045;                       /*  RMDF045         */
    union iodefine_reg32_t  RMDF145;                       /*  RMDF145         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID46;                        /*  RMID46          */
    union iodefine_reg32_t  RMPTR46;                       /*  RMPTR46         */
    union iodefine_reg32_t  RMDF046;                       /*  RMDF046         */
    union iodefine_reg32_t  RMDF146;                       /*  RMDF146         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID47;                        /*  RMID47          */
    union iodefine_reg32_t  RMPTR47;                       /*  RMPTR47         */
    union iodefine_reg32_t  RMDF047;                       /*  RMDF047         */
    union iodefine_reg32_t  RMDF147;                       /*  RMDF147         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID48;                        /*  RMID48          */
    union iodefine_reg32_t  RMPTR48;                       /*  RMPTR48         */
    union iodefine_reg32_t  RMDF048;                       /*  RMDF048         */
    union iodefine_reg32_t  RMDF148;                       /*  RMDF148         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID49;                        /*  RMID49          */
    union iodefine_reg32_t  RMPTR49;                       /*  RMPTR49         */
    union iodefine_reg32_t  RMDF049;                       /*  RMDF049         */
    union iodefine_reg32_t  RMDF149;                       /*  RMDF149         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID50;                        /*  RMID50          */
    union iodefine_reg32_t  RMPTR50;                       /*  RMPTR50         */
    union iodefine_reg32_t  RMDF050;                       /*  RMDF050         */
    union iodefine_reg32_t  RMDF150;                       /*  RMDF150         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID51;                        /*  RMID51          */
    union iodefine_reg32_t  RMPTR51;                       /*  RMPTR51         */
    union iodefine_reg32_t  RMDF051;                       /*  RMDF051         */
    union iodefine_reg32_t  RMDF151;                       /*  RMDF151         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID52;                        /*  RMID52          */
    union iodefine_reg32_t  RMPTR52;                       /*  RMPTR52         */
    union iodefine_reg32_t  RMDF052;                       /*  RMDF052         */
    union iodefine_reg32_t  RMDF152;                       /*  RMDF152         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID53;                        /*  RMID53          */
    union iodefine_reg32_t  RMPTR53;                       /*  RMPTR53         */
    union iodefine_reg32_t  RMDF053;                       /*  RMDF053         */
    union iodefine_reg32_t  RMDF153;                       /*  RMDF153         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID54;                        /*  RMID54          */
    union iodefine_reg32_t  RMPTR54;                       /*  RMPTR54         */
    union iodefine_reg32_t  RMDF054;                       /*  RMDF054         */
    union iodefine_reg32_t  RMDF154;                       /*  RMDF154         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID55;                        /*  RMID55          */
    union iodefine_reg32_t  RMPTR55;                       /*  RMPTR55         */
    union iodefine_reg32_t  RMDF055;                       /*  RMDF055         */
    union iodefine_reg32_t  RMDF155;                       /*  RMDF155         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID56;                        /*  RMID56          */
    union iodefine_reg32_t  RMPTR56;                       /*  RMPTR56         */
    union iodefine_reg32_t  RMDF056;                       /*  RMDF056         */
    union iodefine_reg32_t  RMDF156;                       /*  RMDF156         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID57;                        /*  RMID57          */
    union iodefine_reg32_t  RMPTR57;                       /*  RMPTR57         */
    union iodefine_reg32_t  RMDF057;                       /*  RMDF057         */
    union iodefine_reg32_t  RMDF157;                       /*  RMDF157         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID58;                        /*  RMID58          */
    union iodefine_reg32_t  RMPTR58;                       /*  RMPTR58         */
    union iodefine_reg32_t  RMDF058;                       /*  RMDF058         */
    union iodefine_reg32_t  RMDF158;                       /*  RMDF158         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID59;                        /*  RMID59          */
    union iodefine_reg32_t  RMPTR59;                       /*  RMPTR59         */
    union iodefine_reg32_t  RMDF059;                       /*  RMDF059         */
    union iodefine_reg32_t  RMDF159;                       /*  RMDF159         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID60;                        /*  RMID60          */
    union iodefine_reg32_t  RMPTR60;                       /*  RMPTR60         */
    union iodefine_reg32_t  RMDF060;                       /*  RMDF060         */
    union iodefine_reg32_t  RMDF160;                       /*  RMDF160         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID61;                        /*  RMID61          */
    union iodefine_reg32_t  RMPTR61;                       /*  RMPTR61         */
    union iodefine_reg32_t  RMDF061;                       /*  RMDF061         */
    union iodefine_reg32_t  RMDF161;                       /*  RMDF161         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID62;                        /*  RMID62          */
    union iodefine_reg32_t  RMPTR62;                       /*  RMPTR62         */
    union iodefine_reg32_t  RMDF062;                       /*  RMDF062         */
    union iodefine_reg32_t  RMDF162;                       /*  RMDF162         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID63;                        /*  RMID63          */
    union iodefine_reg32_t  RMPTR63;                       /*  RMPTR63         */
    union iodefine_reg32_t  RMDF063;                       /*  RMDF063         */
    union iodefine_reg32_t  RMDF163;                       /*  RMDF163         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID64;                        /*  RMID64          */
    union iodefine_reg32_t  RMPTR64;                       /*  RMPTR64         */
    union iodefine_reg32_t  RMDF064;                       /*  RMDF064         */
    union iodefine_reg32_t  RMDF164;                       /*  RMDF164         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID65;                        /*  RMID65          */
    union iodefine_reg32_t  RMPTR65;                       /*  RMPTR65         */
    union iodefine_reg32_t  RMDF065;                       /*  RMDF065         */
    union iodefine_reg32_t  RMDF165;                       /*  RMDF165         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID66;                        /*  RMID66          */
    union iodefine_reg32_t  RMPTR66;                       /*  RMPTR66         */
    union iodefine_reg32_t  RMDF066;                       /*  RMDF066         */
    union iodefine_reg32_t  RMDF166;                       /*  RMDF166         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID67;                        /*  RMID67          */
    union iodefine_reg32_t  RMPTR67;                       /*  RMPTR67         */
    union iodefine_reg32_t  RMDF067;                       /*  RMDF067         */
    union iodefine_reg32_t  RMDF167;                       /*  RMDF167         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID68;                        /*  RMID68          */
    union iodefine_reg32_t  RMPTR68;                       /*  RMPTR68         */
    union iodefine_reg32_t  RMDF068;                       /*  RMDF068         */
    union iodefine_reg32_t  RMDF168;                       /*  RMDF168         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID69;                        /*  RMID69          */
    union iodefine_reg32_t  RMPTR69;                       /*  RMPTR69         */
    union iodefine_reg32_t  RMDF069;                       /*  RMDF069         */
    union iodefine_reg32_t  RMDF169;                       /*  RMDF169         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID70;                        /*  RMID70          */
    union iodefine_reg32_t  RMPTR70;                       /*  RMPTR70         */
    union iodefine_reg32_t  RMDF070;                       /*  RMDF070         */
    union iodefine_reg32_t  RMDF170;                       /*  RMDF170         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID71;                        /*  RMID71          */
    union iodefine_reg32_t  RMPTR71;                       /*  RMPTR71         */
    union iodefine_reg32_t  RMDF071;                       /*  RMDF071         */
    union iodefine_reg32_t  RMDF171;                       /*  RMDF171         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID72;                        /*  RMID72          */
    union iodefine_reg32_t  RMPTR72;                       /*  RMPTR72         */
    union iodefine_reg32_t  RMDF072;                       /*  RMDF072         */
    union iodefine_reg32_t  RMDF172;                       /*  RMDF172         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID73;                        /*  RMID73          */
    union iodefine_reg32_t  RMPTR73;                       /*  RMPTR73         */
    union iodefine_reg32_t  RMDF073;                       /*  RMDF073         */
    union iodefine_reg32_t  RMDF173;                       /*  RMDF173         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID74;                        /*  RMID74          */
    union iodefine_reg32_t  RMPTR74;                       /*  RMPTR74         */
    union iodefine_reg32_t  RMDF074;                       /*  RMDF074         */
    union iodefine_reg32_t  RMDF174;                       /*  RMDF174         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID75;                        /*  RMID75          */
    union iodefine_reg32_t  RMPTR75;                       /*  RMPTR75         */
    union iodefine_reg32_t  RMDF075;                       /*  RMDF075         */
    union iodefine_reg32_t  RMDF175;                       /*  RMDF175         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID76;                        /*  RMID76          */
    union iodefine_reg32_t  RMPTR76;                       /*  RMPTR76         */
    union iodefine_reg32_t  RMDF076;                       /*  RMDF076         */
    union iodefine_reg32_t  RMDF176;                       /*  RMDF176         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID77;                        /*  RMID77          */
    union iodefine_reg32_t  RMPTR77;                       /*  RMPTR77         */
    union iodefine_reg32_t  RMDF077;                       /*  RMDF077         */
    union iodefine_reg32_t  RMDF177;                       /*  RMDF177         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID78;                        /*  RMID78          */
    union iodefine_reg32_t  RMPTR78;                       /*  RMPTR78         */
    union iodefine_reg32_t  RMDF078;                       /*  RMDF078         */
    union iodefine_reg32_t  RMDF178;                       /*  RMDF178         */
/* end of struct st_rscan_from_rscan0rmidp */
    
/* start of struct st_rscan_from_rscan0rmidp */
    union iodefine_reg32_t  RMID79;                        /*  RMID79          */
    union iodefine_reg32_t  RMPTR79;                       /*  RMPTR79         */
    union iodefine_reg32_t  RMDF079;                       /*  RMDF079         */
    union iodefine_reg32_t  RMDF179;                       /*  RMDF179         */
/* end of struct st_rscan_from_rscan0rmidp */
    
    volatile uint8_t   dummy179[768];                          /*                  */
    
/* start of struct st_rscan_from_rscan0rfidm */
    union iodefine_reg32_t  RFID0;                         /*  RFID0           */
    union iodefine_reg32_t  RFPTR0;                        /*  RFPTR0          */
    union iodefine_reg32_t  RFDF00;                        /*  RFDF00          */
    union iodefine_reg32_t  RFDF10;                        /*  RFDF10          */
/* end of struct st_rscan_from_rscan0rfidm */
    
/* start of struct st_rscan_from_rscan0rfidm */
    union iodefine_reg32_t  RFID1;                         /*  RFID1           */
    union iodefine_reg32_t  RFPTR1;                        /*  RFPTR1          */
    union iodefine_reg32_t  RFDF01;                        /*  RFDF01          */
    union iodefine_reg32_t  RFDF11;                        /*  RFDF11          */
/* end of struct st_rscan_from_rscan0rfidm */
    
/* start of struct st_rscan_from_rscan0rfidm */
    union iodefine_reg32_t  RFID2;                         /*  RFID2           */
    union iodefine_reg32_t  RFPTR2;                        /*  RFPTR2          */
    union iodefine_reg32_t  RFDF02;                        /*  RFDF02          */
    union iodefine_reg32_t  RFDF12;                        /*  RFDF12          */
/* end of struct st_rscan_from_rscan0rfidm */
    
/* start of struct st_rscan_from_rscan0rfidm */
    union iodefine_reg32_t  RFID3;                         /*  RFID3           */
    union iodefine_reg32_t  RFPTR3;                        /*  RFPTR3          */
    union iodefine_reg32_t  RFDF03;                        /*  RFDF03          */
    union iodefine_reg32_t  RFDF13;                        /*  RFDF13          */
/* end of struct st_rscan_from_rscan0rfidm */
    
/* start of struct st_rscan_from_rscan0rfidm */
    union iodefine_reg32_t  RFID4;                         /*  RFID4           */
    union iodefine_reg32_t  RFPTR4;                        /*  RFPTR4          */
    union iodefine_reg32_t  RFDF04;                        /*  RFDF04          */
    union iodefine_reg32_t  RFDF14;                        /*  RFDF14          */
/* end of struct st_rscan_from_rscan0rfidm */
    
/* start of struct st_rscan_from_rscan0rfidm */
    union iodefine_reg32_t  RFID5;                         /*  RFID5           */
    union iodefine_reg32_t  RFPTR5;                        /*  RFPTR5          */
    union iodefine_reg32_t  RFDF05;                        /*  RFDF05          */
    union iodefine_reg32_t  RFDF15;                        /*  RFDF15          */
/* end of struct st_rscan_from_rscan0rfidm */
    
/* start of struct st_rscan_from_rscan0rfidm */
    union iodefine_reg32_t  RFID6;                         /*  RFID6           */
    union iodefine_reg32_t  RFPTR6;                        /*  RFPTR6          */
    union iodefine_reg32_t  RFDF06;                        /*  RFDF06          */
    union iodefine_reg32_t  RFDF16;                        /*  RFDF16          */
/* end of struct st_rscan_from_rscan0rfidm */
    
/* start of struct st_rscan_from_rscan0rfidm */
    union iodefine_reg32_t  RFID7;                         /*  RFID7           */
    union iodefine_reg32_t  RFPTR7;                        /*  RFPTR7          */
    union iodefine_reg32_t  RFDF07;                        /*  RFDF07          */
    union iodefine_reg32_t  RFDF17;                        /*  RFDF17          */
/* end of struct st_rscan_from_rscan0rfidm */
    
/* start of struct st_rscan_from_rscan0cfidm */
    union iodefine_reg32_t  CFID0;                         /*  CFID0           */
    union iodefine_reg32_t  CFPTR0;                        /*  CFPTR0          */
    union iodefine_reg32_t  CFDF00;                        /*  CFDF00          */
    union iodefine_reg32_t  CFDF10;                        /*  CFDF10          */
/* end of struct st_rscan_from_rscan0cfidm */
    
/* start of struct st_rscan_from_rscan0cfidm */
    union iodefine_reg32_t  CFID1;                         /*  CFID1           */
    union iodefine_reg32_t  CFPTR1;                        /*  CFPTR1          */
    union iodefine_reg32_t  CFDF01;                        /*  CFDF01          */
    union iodefine_reg32_t  CFDF11;                        /*  CFDF11          */
/* end of struct st_rscan_from_rscan0cfidm */
    
/* start of struct st_rscan_from_rscan0cfidm */
    union iodefine_reg32_t  CFID2;                         /*  CFID2           */
    union iodefine_reg32_t  CFPTR2;                        /*  CFPTR2          */
    union iodefine_reg32_t  CFDF02;                        /*  CFDF02          */
    union iodefine_reg32_t  CFDF12;                        /*  CFDF12          */
/* end of struct st_rscan_from_rscan0cfidm */
    
/* start of struct st_rscan_from_rscan0cfidm */
    union iodefine_reg32_t  CFID3;                         /*  CFID3           */
    union iodefine_reg32_t  CFPTR3;                        /*  CFPTR3          */
    union iodefine_reg32_t  CFDF03;                        /*  CFDF03          */
    union iodefine_reg32_t  CFDF13;                        /*  CFDF13          */
/* end of struct st_rscan_from_rscan0cfidm */
    
/* start of struct st_rscan_from_rscan0cfidm */
    union iodefine_reg32_t  CFID4;                         /*  CFID4           */
    union iodefine_reg32_t  CFPTR4;                        /*  CFPTR4          */
    union iodefine_reg32_t  CFDF04;                        /*  CFDF04          */
    union iodefine_reg32_t  CFDF14;                        /*  CFDF14          */
/* end of struct st_rscan_from_rscan0cfidm */
    
/* start of struct st_rscan_from_rscan0cfidm */
    union iodefine_reg32_t  CFID5;                         /*  CFID5           */
    union iodefine_reg32_t  CFPTR5;                        /*  CFPTR5          */
    union iodefine_reg32_t  CFDF05;                        /*  CFDF05          */
    union iodefine_reg32_t  CFDF15;                        /*  CFDF15          */
/* end of struct st_rscan_from_rscan0cfidm */
    
/* start of struct st_rscan_from_rscan0cfidm */
    union iodefine_reg32_t  CFID6;                         /*  CFID6           */
    union iodefine_reg32_t  CFPTR6;                        /*  CFPTR6          */
    union iodefine_reg32_t  CFDF06;                        /*  CFDF06          */
    union iodefine_reg32_t  CFDF16;                        /*  CFDF16          */
/* end of struct st_rscan_from_rscan0cfidm */
    
/* start of struct st_rscan_from_rscan0cfidm */
    union iodefine_reg32_t  CFID7;                         /*  CFID7           */
    union iodefine_reg32_t  CFPTR7;                        /*  CFPTR7          */
    union iodefine_reg32_t  CFDF07;                        /*  CFDF07          */
    union iodefine_reg32_t  CFDF17;                        /*  CFDF17          */
/* end of struct st_rscan_from_rscan0cfidm */
    
/* start of struct st_rscan_from_rscan0cfidm */
    union iodefine_reg32_t  CFID8;                         /*  CFID8           */
    union iodefine_reg32_t  CFPTR8;                        /*  CFPTR8          */
    union iodefine_reg32_t  CFDF08;                        /*  CFDF08          */
    union iodefine_reg32_t  CFDF18;                        /*  CFDF18          */
/* end of struct st_rscan_from_rscan0cfidm */
    
/* start of struct st_rscan_from_rscan0cfidm */
    union iodefine_reg32_t  CFID9;                         /*  CFID9           */
    union iodefine_reg32_t  CFPTR9;                        /*  CFPTR9          */
    union iodefine_reg32_t  CFDF09;                        /*  CFDF09          */
    union iodefine_reg32_t  CFDF19;                        /*  CFDF19          */
/* end of struct st_rscan_from_rscan0cfidm */
    
/* start of struct st_rscan_from_rscan0cfidm */
    union iodefine_reg32_t  CFID10;                        /*  CFID10          */
    union iodefine_reg32_t  CFPTR10;                       /*  CFPTR10         */
    union iodefine_reg32_t  CFDF010;                       /*  CFDF010         */
    union iodefine_reg32_t  CFDF110;                       /*  CFDF110         */
/* end of struct st_rscan_from_rscan0cfidm */
    
/* start of struct st_rscan_from_rscan0cfidm */
    union iodefine_reg32_t  CFID11;                        /*  CFID11          */
    union iodefine_reg32_t  CFPTR11;                       /*  CFPTR11         */
    union iodefine_reg32_t  CFDF011;                       /*  CFDF011         */
    union iodefine_reg32_t  CFDF111;                       /*  CFDF111         */
/* end of struct st_rscan_from_rscan0cfidm */
    
/* start of struct st_rscan_from_rscan0cfidm */
    union iodefine_reg32_t  CFID12;                        /*  CFID12          */
    union iodefine_reg32_t  CFPTR12;                       /*  CFPTR12         */
    union iodefine_reg32_t  CFDF012;                       /*  CFDF012         */
    union iodefine_reg32_t  CFDF112;                       /*  CFDF112         */
/* end of struct st_rscan_from_rscan0cfidm */
    
/* start of struct st_rscan_from_rscan0cfidm */
    union iodefine_reg32_t  CFID13;                        /*  CFID13          */
    union iodefine_reg32_t  CFPTR13;                       /*  CFPTR13         */
    union iodefine_reg32_t  CFDF013;                       /*  CFDF013         */
    union iodefine_reg32_t  CFDF113;                       /*  CFDF113         */
/* end of struct st_rscan_from_rscan0cfidm */
    
/* start of struct st_rscan_from_rscan0cfidm */
    union iodefine_reg32_t  CFID14;                        /*  CFID14          */
    union iodefine_reg32_t  CFPTR14;                       /*  CFPTR14         */
    union iodefine_reg32_t  CFDF014;                       /*  CFDF014         */
    union iodefine_reg32_t  CFDF114;                       /*  CFDF114         */
/* end of struct st_rscan_from_rscan0cfidm */
    
    volatile uint8_t   dummy180[144];                          /*                  */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID0;                         /*  TMID0           */
    union iodefine_reg32_t  TMPTR0;                        /*  TMPTR0          */
    union iodefine_reg32_t  TMDF00;                        /*  TMDF00          */
    union iodefine_reg32_t  TMDF10;                        /*  TMDF10          */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID1;                         /*  TMID1           */
    union iodefine_reg32_t  TMPTR1;                        /*  TMPTR1          */
    union iodefine_reg32_t  TMDF01;                        /*  TMDF01          */
    union iodefine_reg32_t  TMDF11;                        /*  TMDF11          */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID2;                         /*  TMID2           */
    union iodefine_reg32_t  TMPTR2;                        /*  TMPTR2          */
    union iodefine_reg32_t  TMDF02;                        /*  TMDF02          */
    union iodefine_reg32_t  TMDF12;                        /*  TMDF12          */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID3;                         /*  TMID3           */
    union iodefine_reg32_t  TMPTR3;                        /*  TMPTR3          */
    union iodefine_reg32_t  TMDF03;                        /*  TMDF03          */
    union iodefine_reg32_t  TMDF13;                        /*  TMDF13          */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID4;                         /*  TMID4           */
    union iodefine_reg32_t  TMPTR4;                        /*  TMPTR4          */
    union iodefine_reg32_t  TMDF04;                        /*  TMDF04          */
    union iodefine_reg32_t  TMDF14;                        /*  TMDF14          */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID5;                         /*  TMID5           */
    union iodefine_reg32_t  TMPTR5;                        /*  TMPTR5          */
    union iodefine_reg32_t  TMDF05;                        /*  TMDF05          */
    union iodefine_reg32_t  TMDF15;                        /*  TMDF15          */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID6;                         /*  TMID6           */
    union iodefine_reg32_t  TMPTR6;                        /*  TMPTR6          */
    union iodefine_reg32_t  TMDF06;                        /*  TMDF06          */
    union iodefine_reg32_t  TMDF16;                        /*  TMDF16          */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID7;                         /*  TMID7           */
    union iodefine_reg32_t  TMPTR7;                        /*  TMPTR7          */
    union iodefine_reg32_t  TMDF07;                        /*  TMDF07          */
    union iodefine_reg32_t  TMDF17;                        /*  TMDF17          */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID8;                         /*  TMID8           */
    union iodefine_reg32_t  TMPTR8;                        /*  TMPTR8          */
    union iodefine_reg32_t  TMDF08;                        /*  TMDF08          */
    union iodefine_reg32_t  TMDF18;                        /*  TMDF18          */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID9;                         /*  TMID9           */
    union iodefine_reg32_t  TMPTR9;                        /*  TMPTR9          */
    union iodefine_reg32_t  TMDF09;                        /*  TMDF09          */
    union iodefine_reg32_t  TMDF19;                        /*  TMDF19          */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID10;                        /*  TMID10          */
    union iodefine_reg32_t  TMPTR10;                       /*  TMPTR10         */
    union iodefine_reg32_t  TMDF010;                       /*  TMDF010         */
    union iodefine_reg32_t  TMDF110;                       /*  TMDF110         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID11;                        /*  TMID11          */
    union iodefine_reg32_t  TMPTR11;                       /*  TMPTR11         */
    union iodefine_reg32_t  TMDF011;                       /*  TMDF011         */
    union iodefine_reg32_t  TMDF111;                       /*  TMDF111         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID12;                        /*  TMID12          */
    union iodefine_reg32_t  TMPTR12;                       /*  TMPTR12         */
    union iodefine_reg32_t  TMDF012;                       /*  TMDF012         */
    union iodefine_reg32_t  TMDF112;                       /*  TMDF112         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID13;                        /*  TMID13          */
    union iodefine_reg32_t  TMPTR13;                       /*  TMPTR13         */
    union iodefine_reg32_t  TMDF013;                       /*  TMDF013         */
    union iodefine_reg32_t  TMDF113;                       /*  TMDF113         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID14;                        /*  TMID14          */
    union iodefine_reg32_t  TMPTR14;                       /*  TMPTR14         */
    union iodefine_reg32_t  TMDF014;                       /*  TMDF014         */
    union iodefine_reg32_t  TMDF114;                       /*  TMDF114         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID15;                        /*  TMID15          */
    union iodefine_reg32_t  TMPTR15;                       /*  TMPTR15         */
    union iodefine_reg32_t  TMDF015;                       /*  TMDF015         */
    union iodefine_reg32_t  TMDF115;                       /*  TMDF115         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID16;                        /*  TMID16          */
    union iodefine_reg32_t  TMPTR16;                       /*  TMPTR16         */
    union iodefine_reg32_t  TMDF016;                       /*  TMDF016         */
    union iodefine_reg32_t  TMDF116;                       /*  TMDF116         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID17;                        /*  TMID17          */
    union iodefine_reg32_t  TMPTR17;                       /*  TMPTR17         */
    union iodefine_reg32_t  TMDF017;                       /*  TMDF017         */
    union iodefine_reg32_t  TMDF117;                       /*  TMDF117         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID18;                        /*  TMID18          */
    union iodefine_reg32_t  TMPTR18;                       /*  TMPTR18         */
    union iodefine_reg32_t  TMDF018;                       /*  TMDF018         */
    union iodefine_reg32_t  TMDF118;                       /*  TMDF118         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID19;                        /*  TMID19          */
    union iodefine_reg32_t  TMPTR19;                       /*  TMPTR19         */
    union iodefine_reg32_t  TMDF019;                       /*  TMDF019         */
    union iodefine_reg32_t  TMDF119;                       /*  TMDF119         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID20;                        /*  TMID20          */
    union iodefine_reg32_t  TMPTR20;                       /*  TMPTR20         */
    union iodefine_reg32_t  TMDF020;                       /*  TMDF020         */
    union iodefine_reg32_t  TMDF120;                       /*  TMDF120         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID21;                        /*  TMID21          */
    union iodefine_reg32_t  TMPTR21;                       /*  TMPTR21         */
    union iodefine_reg32_t  TMDF021;                       /*  TMDF021         */
    union iodefine_reg32_t  TMDF121;                       /*  TMDF121         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID22;                        /*  TMID22          */
    union iodefine_reg32_t  TMPTR22;                       /*  TMPTR22         */
    union iodefine_reg32_t  TMDF022;                       /*  TMDF022         */
    union iodefine_reg32_t  TMDF122;                       /*  TMDF122         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID23;                        /*  TMID23          */
    union iodefine_reg32_t  TMPTR23;                       /*  TMPTR23         */
    union iodefine_reg32_t  TMDF023;                       /*  TMDF023         */
    union iodefine_reg32_t  TMDF123;                       /*  TMDF123         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID24;                        /*  TMID24          */
    union iodefine_reg32_t  TMPTR24;                       /*  TMPTR24         */
    union iodefine_reg32_t  TMDF024;                       /*  TMDF024         */
    union iodefine_reg32_t  TMDF124;                       /*  TMDF124         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID25;                        /*  TMID25          */
    union iodefine_reg32_t  TMPTR25;                       /*  TMPTR25         */
    union iodefine_reg32_t  TMDF025;                       /*  TMDF025         */
    union iodefine_reg32_t  TMDF125;                       /*  TMDF125         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID26;                        /*  TMID26          */
    union iodefine_reg32_t  TMPTR26;                       /*  TMPTR26         */
    union iodefine_reg32_t  TMDF026;                       /*  TMDF026         */
    union iodefine_reg32_t  TMDF126;                       /*  TMDF126         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID27;                        /*  TMID27          */
    union iodefine_reg32_t  TMPTR27;                       /*  TMPTR27         */
    union iodefine_reg32_t  TMDF027;                       /*  TMDF027         */
    union iodefine_reg32_t  TMDF127;                       /*  TMDF127         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID28;                        /*  TMID28          */
    union iodefine_reg32_t  TMPTR28;                       /*  TMPTR28         */
    union iodefine_reg32_t  TMDF028;                       /*  TMDF028         */
    union iodefine_reg32_t  TMDF128;                       /*  TMDF128         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID29;                        /*  TMID29          */
    union iodefine_reg32_t  TMPTR29;                       /*  TMPTR29         */
    union iodefine_reg32_t  TMDF029;                       /*  TMDF029         */
    union iodefine_reg32_t  TMDF129;                       /*  TMDF129         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID30;                        /*  TMID30          */
    union iodefine_reg32_t  TMPTR30;                       /*  TMPTR30         */
    union iodefine_reg32_t  TMDF030;                       /*  TMDF030         */
    union iodefine_reg32_t  TMDF130;                       /*  TMDF130         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID31;                        /*  TMID31          */
    union iodefine_reg32_t  TMPTR31;                       /*  TMPTR31         */
    union iodefine_reg32_t  TMDF031;                       /*  TMDF031         */
    union iodefine_reg32_t  TMDF131;                       /*  TMDF131         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID32;                        /*  TMID32          */
    union iodefine_reg32_t  TMPTR32;                       /*  TMPTR32         */
    union iodefine_reg32_t  TMDF032;                       /*  TMDF032         */
    union iodefine_reg32_t  TMDF132;                       /*  TMDF132         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID33;                        /*  TMID33          */
    union iodefine_reg32_t  TMPTR33;                       /*  TMPTR33         */
    union iodefine_reg32_t  TMDF033;                       /*  TMDF033         */
    union iodefine_reg32_t  TMDF133;                       /*  TMDF133         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID34;                        /*  TMID34          */
    union iodefine_reg32_t  TMPTR34;                       /*  TMPTR34         */
    union iodefine_reg32_t  TMDF034;                       /*  TMDF034         */
    union iodefine_reg32_t  TMDF134;                       /*  TMDF134         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID35;                        /*  TMID35          */
    union iodefine_reg32_t  TMPTR35;                       /*  TMPTR35         */
    union iodefine_reg32_t  TMDF035;                       /*  TMDF035         */
    union iodefine_reg32_t  TMDF135;                       /*  TMDF135         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID36;                        /*  TMID36          */
    union iodefine_reg32_t  TMPTR36;                       /*  TMPTR36         */
    union iodefine_reg32_t  TMDF036;                       /*  TMDF036         */
    union iodefine_reg32_t  TMDF136;                       /*  TMDF136         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID37;                        /*  TMID37          */
    union iodefine_reg32_t  TMPTR37;                       /*  TMPTR37         */
    union iodefine_reg32_t  TMDF037;                       /*  TMDF037         */
    union iodefine_reg32_t  TMDF137;                       /*  TMDF137         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID38;                        /*  TMID38          */
    union iodefine_reg32_t  TMPTR38;                       /*  TMPTR38         */
    union iodefine_reg32_t  TMDF038;                       /*  TMDF038         */
    union iodefine_reg32_t  TMDF138;                       /*  TMDF138         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID39;                        /*  TMID39          */
    union iodefine_reg32_t  TMPTR39;                       /*  TMPTR39         */
    union iodefine_reg32_t  TMDF039;                       /*  TMDF039         */
    union iodefine_reg32_t  TMDF139;                       /*  TMDF139         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID40;                        /*  TMID40          */
    union iodefine_reg32_t  TMPTR40;                       /*  TMPTR40         */
    union iodefine_reg32_t  TMDF040;                       /*  TMDF040         */
    union iodefine_reg32_t  TMDF140;                       /*  TMDF140         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID41;                        /*  TMID41          */
    union iodefine_reg32_t  TMPTR41;                       /*  TMPTR41         */
    union iodefine_reg32_t  TMDF041;                       /*  TMDF041         */
    union iodefine_reg32_t  TMDF141;                       /*  TMDF141         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID42;                        /*  TMID42          */
    union iodefine_reg32_t  TMPTR42;                       /*  TMPTR42         */
    union iodefine_reg32_t  TMDF042;                       /*  TMDF042         */
    union iodefine_reg32_t  TMDF142;                       /*  TMDF142         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID43;                        /*  TMID43          */
    union iodefine_reg32_t  TMPTR43;                       /*  TMPTR43         */
    union iodefine_reg32_t  TMDF043;                       /*  TMDF043         */
    union iodefine_reg32_t  TMDF143;                       /*  TMDF143         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID44;                        /*  TMID44          */
    union iodefine_reg32_t  TMPTR44;                       /*  TMPTR44         */
    union iodefine_reg32_t  TMDF044;                       /*  TMDF044         */
    union iodefine_reg32_t  TMDF144;                       /*  TMDF144         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID45;                        /*  TMID45          */
    union iodefine_reg32_t  TMPTR45;                       /*  TMPTR45         */
    union iodefine_reg32_t  TMDF045;                       /*  TMDF045         */
    union iodefine_reg32_t  TMDF145;                       /*  TMDF145         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID46;                        /*  TMID46          */
    union iodefine_reg32_t  TMPTR46;                       /*  TMPTR46         */
    union iodefine_reg32_t  TMDF046;                       /*  TMDF046         */
    union iodefine_reg32_t  TMDF146;                       /*  TMDF146         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID47;                        /*  TMID47          */
    union iodefine_reg32_t  TMPTR47;                       /*  TMPTR47         */
    union iodefine_reg32_t  TMDF047;                       /*  TMDF047         */
    union iodefine_reg32_t  TMDF147;                       /*  TMDF147         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID48;                        /*  TMID48          */
    union iodefine_reg32_t  TMPTR48;                       /*  TMPTR48         */
    union iodefine_reg32_t  TMDF048;                       /*  TMDF048         */
    union iodefine_reg32_t  TMDF148;                       /*  TMDF148         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID49;                        /*  TMID49          */
    union iodefine_reg32_t  TMPTR49;                       /*  TMPTR49         */
    union iodefine_reg32_t  TMDF049;                       /*  TMDF049         */
    union iodefine_reg32_t  TMDF149;                       /*  TMDF149         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID50;                        /*  TMID50          */
    union iodefine_reg32_t  TMPTR50;                       /*  TMPTR50         */
    union iodefine_reg32_t  TMDF050;                       /*  TMDF050         */
    union iodefine_reg32_t  TMDF150;                       /*  TMDF150         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID51;                        /*  TMID51          */
    union iodefine_reg32_t  TMPTR51;                       /*  TMPTR51         */
    union iodefine_reg32_t  TMDF051;                       /*  TMDF051         */
    union iodefine_reg32_t  TMDF151;                       /*  TMDF151         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID52;                        /*  TMID52          */
    union iodefine_reg32_t  TMPTR52;                       /*  TMPTR52         */
    union iodefine_reg32_t  TMDF052;                       /*  TMDF052         */
    union iodefine_reg32_t  TMDF152;                       /*  TMDF152         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID53;                        /*  TMID53          */
    union iodefine_reg32_t  TMPTR53;                       /*  TMPTR53         */
    union iodefine_reg32_t  TMDF053;                       /*  TMDF053         */
    union iodefine_reg32_t  TMDF153;                       /*  TMDF153         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID54;                        /*  TMID54          */
    union iodefine_reg32_t  TMPTR54;                       /*  TMPTR54         */
    union iodefine_reg32_t  TMDF054;                       /*  TMDF054         */
    union iodefine_reg32_t  TMDF154;                       /*  TMDF154         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID55;                        /*  TMID55          */
    union iodefine_reg32_t  TMPTR55;                       /*  TMPTR55         */
    union iodefine_reg32_t  TMDF055;                       /*  TMDF055         */
    union iodefine_reg32_t  TMDF155;                       /*  TMDF155         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID56;                        /*  TMID56          */
    union iodefine_reg32_t  TMPTR56;                       /*  TMPTR56         */
    union iodefine_reg32_t  TMDF056;                       /*  TMDF056         */
    union iodefine_reg32_t  TMDF156;                       /*  TMDF156         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID57;                        /*  TMID57          */
    union iodefine_reg32_t  TMPTR57;                       /*  TMPTR57         */
    union iodefine_reg32_t  TMDF057;                       /*  TMDF057         */
    union iodefine_reg32_t  TMDF157;                       /*  TMDF157         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID58;                        /*  TMID58          */
    union iodefine_reg32_t  TMPTR58;                       /*  TMPTR58         */
    union iodefine_reg32_t  TMDF058;                       /*  TMDF058         */
    union iodefine_reg32_t  TMDF158;                       /*  TMDF158         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID59;                        /*  TMID59          */
    union iodefine_reg32_t  TMPTR59;                       /*  TMPTR59         */
    union iodefine_reg32_t  TMDF059;                       /*  TMDF059         */
    union iodefine_reg32_t  TMDF159;                       /*  TMDF159         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID60;                        /*  TMID60          */
    union iodefine_reg32_t  TMPTR60;                       /*  TMPTR60         */
    union iodefine_reg32_t  TMDF060;                       /*  TMDF060         */
    union iodefine_reg32_t  TMDF160;                       /*  TMDF160         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID61;                        /*  TMID61          */
    union iodefine_reg32_t  TMPTR61;                       /*  TMPTR61         */
    union iodefine_reg32_t  TMDF061;                       /*  TMDF061         */
    union iodefine_reg32_t  TMDF161;                       /*  TMDF161         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID62;                        /*  TMID62          */
    union iodefine_reg32_t  TMPTR62;                       /*  TMPTR62         */
    union iodefine_reg32_t  TMDF062;                       /*  TMDF062         */
    union iodefine_reg32_t  TMDF162;                       /*  TMDF162         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID63;                        /*  TMID63          */
    union iodefine_reg32_t  TMPTR63;                       /*  TMPTR63         */
    union iodefine_reg32_t  TMDF063;                       /*  TMDF063         */
    union iodefine_reg32_t  TMDF163;                       /*  TMDF163         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID64;                        /*  TMID64          */
    union iodefine_reg32_t  TMPTR64;                       /*  TMPTR64         */
    union iodefine_reg32_t  TMDF064;                       /*  TMDF064         */
    union iodefine_reg32_t  TMDF164;                       /*  TMDF164         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID65;                        /*  TMID65          */
    union iodefine_reg32_t  TMPTR65;                       /*  TMPTR65         */
    union iodefine_reg32_t  TMDF065;                       /*  TMDF065         */
    union iodefine_reg32_t  TMDF165;                       /*  TMDF165         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID66;                        /*  TMID66          */
    union iodefine_reg32_t  TMPTR66;                       /*  TMPTR66         */
    union iodefine_reg32_t  TMDF066;                       /*  TMDF066         */
    union iodefine_reg32_t  TMDF166;                       /*  TMDF166         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID67;                        /*  TMID67          */
    union iodefine_reg32_t  TMPTR67;                       /*  TMPTR67         */
    union iodefine_reg32_t  TMDF067;                       /*  TMDF067         */
    union iodefine_reg32_t  TMDF167;                       /*  TMDF167         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID68;                        /*  TMID68          */
    union iodefine_reg32_t  TMPTR68;                       /*  TMPTR68         */
    union iodefine_reg32_t  TMDF068;                       /*  TMDF068         */
    union iodefine_reg32_t  TMDF168;                       /*  TMDF168         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID69;                        /*  TMID69          */
    union iodefine_reg32_t  TMPTR69;                       /*  TMPTR69         */
    union iodefine_reg32_t  TMDF069;                       /*  TMDF069         */
    union iodefine_reg32_t  TMDF169;                       /*  TMDF169         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID70;                        /*  TMID70          */
    union iodefine_reg32_t  TMPTR70;                       /*  TMPTR70         */
    union iodefine_reg32_t  TMDF070;                       /*  TMDF070         */
    union iodefine_reg32_t  TMDF170;                       /*  TMDF170         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID71;                        /*  TMID71          */
    union iodefine_reg32_t  TMPTR71;                       /*  TMPTR71         */
    union iodefine_reg32_t  TMDF071;                       /*  TMDF071         */
    union iodefine_reg32_t  TMDF171;                       /*  TMDF171         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID72;                        /*  TMID72          */
    union iodefine_reg32_t  TMPTR72;                       /*  TMPTR72         */
    union iodefine_reg32_t  TMDF072;                       /*  TMDF072         */
    union iodefine_reg32_t  TMDF172;                       /*  TMDF172         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID73;                        /*  TMID73          */
    union iodefine_reg32_t  TMPTR73;                       /*  TMPTR73         */
    union iodefine_reg32_t  TMDF073;                       /*  TMDF073         */
    union iodefine_reg32_t  TMDF173;                       /*  TMDF173         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID74;                        /*  TMID74          */
    union iodefine_reg32_t  TMPTR74;                       /*  TMPTR74         */
    union iodefine_reg32_t  TMDF074;                       /*  TMDF074         */
    union iodefine_reg32_t  TMDF174;                       /*  TMDF174         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID75;                        /*  TMID75          */
    union iodefine_reg32_t  TMPTR75;                       /*  TMPTR75         */
    union iodefine_reg32_t  TMDF075;                       /*  TMDF075         */
    union iodefine_reg32_t  TMDF175;                       /*  TMDF175         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID76;                        /*  TMID76          */
    union iodefine_reg32_t  TMPTR76;                       /*  TMPTR76         */
    union iodefine_reg32_t  TMDF076;                       /*  TMDF076         */
    union iodefine_reg32_t  TMDF176;                       /*  TMDF176         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID77;                        /*  TMID77          */
    union iodefine_reg32_t  TMPTR77;                       /*  TMPTR77         */
    union iodefine_reg32_t  TMDF077;                       /*  TMDF077         */
    union iodefine_reg32_t  TMDF177;                       /*  TMDF177         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID78;                        /*  TMID78          */
    union iodefine_reg32_t  TMPTR78;                       /*  TMPTR78         */
    union iodefine_reg32_t  TMDF078;                       /*  TMDF078         */
    union iodefine_reg32_t  TMDF178;                       /*  TMDF178         */
/* end of struct st_rscan_from_rscan0tmidp */
    
/* start of struct st_rscan_from_rscan0tmidp */
    union iodefine_reg32_t  TMID79;                        /*  TMID79          */
    union iodefine_reg32_t  TMPTR79;                       /*  TMPTR79         */
    union iodefine_reg32_t  TMDF079;                       /*  TMDF079         */
    union iodefine_reg32_t  TMDF179;                       /*  TMDF179         */
/* end of struct st_rscan_from_rscan0tmidp */
    
    volatile uint8_t   dummy181[768];                          /*                  */

    union iodefine_reg32_t  THLACC0;                       /*  THLACC0         */
    union iodefine_reg32_t  THLACC1;                       /*  THLACC1         */
    union iodefine_reg32_t  THLACC2;                       /*  THLACC2         */
    union iodefine_reg32_t  THLACC3;                       /*  THLACC3         */
    union iodefine_reg32_t  THLACC4;                       /*  THLACC4         */
    
};


struct st_rscan_from_rscan0cncfg
{
    union iodefine_reg32_t  CnCFG;                         /*  CnCFG           */
    union iodefine_reg32_t  CnCTR;                         /*  CnCTR           */
    union iodefine_reg32_t  CnSTS;                         /*  CnSTS           */
    union iodefine_reg32_t  CnERFL;                        /*  CnERFL          */
};


struct st_rscan_from_rscan0gaflidj
{
    union iodefine_reg32_t  GAFLIDj;                       /*  GAFLIDj         */
    union iodefine_reg32_t  GAFLMj;                        /*  GAFLMj          */
    union iodefine_reg32_t  GAFLP0j;                       /*  GAFLP0j         */
    union iodefine_reg32_t  GAFLP1j;                       /*  GAFLP1j         */
};


struct st_rscan_from_rscan0rmidp
{
    union iodefine_reg32_t  RMIDp;                         /*  RMIDp           */
    union iodefine_reg32_t  RMPTRp;                        /*  RMPTRp          */
    union iodefine_reg32_t  RMDF0p;                        /*  RMDF0p          */
    union iodefine_reg32_t  RMDF1p;                        /*  RMDF1p          */
};


struct st_rscan_from_rscan0rfidm
{
    union iodefine_reg32_t  RFIDm;                         /*  RFIDm           */
    union iodefine_reg32_t  RFPTRm;                        /*  RFPTRm          */
    union iodefine_reg32_t  RFDF0m;                        /*  RFDF0m          */
    union iodefine_reg32_t  RFDF1m;                        /*  RFDF1m          */
};


struct st_rscan_from_rscan0tmidp
{
    union iodefine_reg32_t  TMIDp;                         /*  TMIDp           */
    union iodefine_reg32_t  TMPTRp;                        /*  TMPTRp          */
    union iodefine_reg32_t  TMDF0p;                        /*  TMDF0p          */
    union iodefine_reg32_t  TMDF1p;                        /*  TMDF1p          */
};


struct st_rscan_from_rscan0cfidm
{
    union iodefine_reg32_t  CFIDm;                         /*  CFIDm           */
    union iodefine_reg32_t  CFPTRm;                        /*  CFPTRm          */
    union iodefine_reg32_t  CFDF0m;                        /*  CFDF0m          */
    union iodefine_reg32_t  CFDF1m;                        /*  CFDF1m          */
};





/* Start of channnel array defines of RSCAN0 */

/* Channnel array defines of RSCAN_FROM_RSCAN0CFIDm */
/*(Sample) value = RSCAN_FROM_RSCAN0CFIDm[ channel ]->CFIDm.UINT32; */
#line 1920 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/rscan0_iodefine.h"


/* Channnel array defines of RSCAN_FROM_RSCAN0TMIDp */
/*(Sample) value = RSCAN_FROM_RSCAN0TMIDp[ channel ]->TMIDp.UINT32; */
#line 2018 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/rscan0_iodefine.h"


/* Channnel array defines of RSCAN_FROM_RSCAN0RFIDm */
/*(Sample) value = RSCAN_FROM_RSCAN0RFIDm[ channel ]->RFIDm.UINT32; */
#line 2035 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/rscan0_iodefine.h"


/* Channnel array defines of RSCAN_FROM_RSCAN0RMIDp */
/*(Sample) value = RSCAN_FROM_RSCAN0RMIDp[ channel ]->RMIDp.UINT32; */
#line 2133 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/rscan0_iodefine.h"


/* Channnel array defines of RSCAN_FROM_RSCAN0GAFLIDj */
/*(Sample) value = RSCAN_FROM_RSCAN0GAFLIDj[ channel ]->GAFLIDj.UINT32; */
#line 2159 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/rscan0_iodefine.h"


/* Channnel array defines of RSCAN_FROM_RSCAN0CnCFG */
/*(Sample) value = RSCAN_FROM_RSCAN0CnCFG[ channel ]->CnCFG.UINT32; */
#line 2173 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/rscan0_iodefine.h"

/* End of channnel array defines of RSCAN0 */


#line 9035 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/rscan0_iodefine.h"
/* <-SEC M1.10.1 */
/* <-QAC 0857 */
/* <-QAC 0639 */
#line 125 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/rspi_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : rspi_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_rspi
{                                                          /* RSPI             */
    volatile uint8_t   SPCR;                                   /*  SPCR            */
    volatile uint8_t   SSLP;                                   /*  SSLP            */
    volatile uint8_t   SPPCR;                                  /*  SPPCR           */
    volatile uint8_t   SPSR;                                   /*  SPSR            */
    union iodefine_reg32_t  SPDR;                          /*  SPDR            */
    
    volatile uint8_t   SPSCR;                                  /*  SPSCR           */
    volatile uint8_t   SPSSR;                                  /*  SPSSR           */
    volatile uint8_t   SPBR;                                   /*  SPBR            */
    volatile uint8_t   SPDCR;                                  /*  SPDCR           */
    volatile uint8_t   SPCKD;                                  /*  SPCKD           */
    volatile uint8_t   SSLND;                                  /*  SSLND           */
    volatile uint8_t   SPND;                                   /*  SPND            */
    volatile uint8_t   dummy1[1];                              /*                  */

    volatile uint16_t SPCMD0;                                 /*  SPCMD0          */
    volatile uint16_t SPCMD1;                                 /*  SPCMD1          */
    volatile uint16_t SPCMD2;                                 /*  SPCMD2          */
    volatile uint16_t SPCMD3;                                 /*  SPCMD3          */
    volatile uint8_t   dummy2[8];                              /*                  */
    volatile uint8_t   SPBFCR;                                 /*  SPBFCR          */
    volatile uint8_t   dummy3[1];                              /*                  */
    volatile uint16_t SPBFDR;                                 /*  SPBFDR          */
};









/* Start of channnel array defines of RSPI */

/* Channnel array defines of RSPI */
/*(Sample) value = RSPI[ channel ]->SPCR; */






/* End of channnel array defines of RSPI */


#line 201 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/rspi_iodefine.h"
/* <-SEC M1.10.1 */
#line 126 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/rtc_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : rtc_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_rtc
{                                                          /* RTC              */
    volatile uint8_t   R64CNT;                                 /*  R64CNT          */
    volatile uint8_t   dummy537[1];                            /*                  */
    volatile uint8_t   RSECCNT;                                /*  RSECCNT         */
    volatile uint8_t   dummy538[1];                            /*                  */
    volatile uint8_t   RMINCNT;                                /*  RMINCNT         */
    volatile uint8_t   dummy539[1];                            /*                  */
    volatile uint8_t   RHRCNT;                                 /*  RHRCNT          */
    volatile uint8_t   dummy540[1];                            /*                  */
    volatile uint8_t   RWKCNT;                                 /*  RWKCNT          */
    volatile uint8_t   dummy541[1];                            /*                  */
    volatile uint8_t   RDAYCNT;                                /*  RDAYCNT         */
    volatile uint8_t   dummy542[1];                            /*                  */
    volatile uint8_t   RMONCNT;                                /*  RMONCNT         */
    volatile uint8_t   dummy543[1];                            /*                  */
    volatile uint16_t RYRCNT;                                 /*  RYRCNT          */
    volatile uint8_t   RSECAR;                                 /*  RSECAR          */
    volatile uint8_t   dummy544[1];                            /*                  */
    volatile uint8_t   RMINAR;                                 /*  RMINAR          */
    volatile uint8_t   dummy545[1];                            /*                  */
    volatile uint8_t   RHRAR;                                  /*  RHRAR           */
    volatile uint8_t   dummy546[1];                            /*                  */
    volatile uint8_t   RWKAR;                                  /*  RWKAR           */
    volatile uint8_t   dummy547[1];                            /*                  */
    volatile uint8_t   RDAYAR;                                 /*  RDAYAR          */
    volatile uint8_t   dummy548[1];                            /*                  */
    volatile uint8_t   RMONAR;                                 /*  RMONAR          */
    volatile uint8_t   dummy549[1];                            /*                  */
    volatile uint8_t   RCR1;                                   /*  RCR1            */
    volatile uint8_t   dummy550[1];                            /*                  */
    volatile uint8_t   RCR2;                                   /*  RCR2            */
    volatile uint8_t   dummy551[1];                            /*                  */
    volatile uint16_t RYRAR;                                  /*  RYRAR           */
    volatile uint8_t   dummy552[2];                            /*                  */
    volatile uint8_t   RCR3;                                   /*  RCR3            */
    volatile uint8_t   dummy553[1];                            /*                  */
    volatile uint8_t   RCR5;                                   /*  RCR5            */
    volatile uint8_t   dummy554[3];                            /*                  */
    volatile uint16_t RFRH;                                   /*  RFRH            */
    volatile uint16_t RFRL;                                   /*  RFRL            */
};





#line 101 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/rtc_iodefine.h"
/* <-SEC M1.10.1 */
#line 127 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/scif_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : scif_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->QAC 0857 : Over 1024 #define (C90) */
/* ->SEC M1.10.1 : Not magic number */

struct st_scif
{                                                          /* SCIF             */
    volatile uint16_t SCSMR;                                  /*  SCSMR           */
    volatile uint8_t   dummy1[2];                              /*                  */
    volatile uint8_t   SCBRR;                                  /*  SCBRR           */
    volatile uint8_t   dummy2[3];                              /*                  */
    volatile uint16_t SCSCR;                                  /*  SCSCR           */
    volatile uint8_t   dummy3[2];                              /*                  */
    volatile uint8_t   SCFTDR;                                 /*  SCFTDR          */
    volatile uint8_t   dummy4[3];                              /*                  */
    volatile uint16_t SCFSR;                                  /*  SCFSR           */
    volatile uint8_t   dummy5[2];                              /*                  */
    volatile uint8_t   SCFRDR;                                 /*  SCFRDR          */
    volatile uint8_t   dummy6[3];                              /*                  */
    volatile uint16_t SCFCR;                                  /*  SCFCR           */
    volatile uint8_t   dummy7[2];                              /*                  */
    volatile uint16_t SCFDR;                                  /*  SCFDR           */
    volatile uint8_t   dummy8[2];                              /*                  */
    volatile uint16_t SCSPTR;                                 /*  SCSPTR          */
    volatile uint8_t   dummy9[2];                              /*                  */
    volatile uint16_t SCLSR;                                  /*  SCLSR           */
    volatile uint8_t   dummy10[2];                             /*                  */
    volatile uint16_t SCEMR;                                  /*  SCEMR           */
};


#line 68 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/scif_iodefine.h"


/* Start of channnel array defines of SCIF */

/* Channnel array defines of SCIF */
/*(Sample) value = SCIF[ channel ]->SCSMR; */






/* End of channnel array defines of SCIF */


#line 171 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/scif_iodefine.h"
/* <-SEC M1.10.1 */
/* <-QAC 0857 */
#line 128 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/scim_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : scim_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_scim
{                                                          /* SCIM             */
    volatile uint8_t   SMR;                                    /*  SMR             */
    volatile uint8_t   BRR;                                    /*  BRR             */
    volatile uint8_t   SCR;                                    /*  SCR             */
    volatile uint8_t   TDR;                                    /*  TDR             */
    volatile uint8_t   SSR;                                    /*  SSR             */
    volatile uint8_t   RDR;                                    /*  RDR             */
    volatile uint8_t   SCMR;                                   /*  SCMR            */
    volatile uint8_t   SEMR;                                   /*  SEMR            */
    volatile uint8_t   SNFR;                                   /*  SNFR            */
    volatile uint8_t   dummy1[4];                              /*                  */
    volatile uint8_t   SECR;                                   /*  SECR            */
};






/* Start of channnel array defines of SCIM */

/* Channnel array defines of SCIM */
/*(Sample) value = SCIM[ channel ]->SMR; */






/* End of channnel array defines of SCIM */


#line 86 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/scim_iodefine.h"
/* <-SEC M1.10.1 */
#line 129 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/scux_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : scux_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->QAC 0639 : Over 127 members (C90) */
/* ->SEC M1.10.1 : Not magic number */

struct st_scux
{                                                          /* SCUX             */
/* start of struct st_scux_from_ipcir_ipc0_n */
    volatile uint32_t  IPCIR_IPC0_0;                           /*  IPCIR_IPC0_0    */
    volatile uint32_t  IPSLR_IPC0_0;                           /*  IPSLR_IPC0_0    */
    volatile uint8_t   dummy259[248];                          /*                  */
/* end of struct st_scux_from_ipcir_ipc0_n */
/* start of struct st_scux_from_ipcir_ipc0_n */
    volatile uint32_t  IPCIR_IPC0_1;                           /*  IPCIR_IPC0_1    */
    volatile uint32_t  IPSLR_IPC0_1;                           /*  IPSLR_IPC0_1    */
    volatile uint8_t   dummy260[248];                          /*                  */
/* end of struct st_scux_from_ipcir_ipc0_n */
/* start of struct st_scux_from_ipcir_ipc0_n */
    volatile uint32_t  IPCIR_IPC0_2;                           /*  IPCIR_IPC0_2    */
    volatile uint32_t  IPSLR_IPC0_2;                           /*  IPSLR_IPC0_2    */
    volatile uint8_t   dummy261[248];                          /*                  */
/* end of struct st_scux_from_ipcir_ipc0_n */
/* start of struct st_scux_from_ipcir_ipc0_n */
    volatile uint32_t  IPCIR_IPC0_3;                           /*  IPCIR_IPC0_3    */
    volatile uint32_t  IPSLR_IPC0_3;                           /*  IPSLR_IPC0_3    */
    volatile uint8_t   dummy262[248];                          /*                  */
/* end of struct st_scux_from_ipcir_ipc0_n */
/* start of struct st_scux_from_opcir_opc0_n */
    volatile uint32_t  OPCIR_OPC0_0;                           /*  OPCIR_OPC0_0    */
    volatile uint32_t  OPSLR_OPC0_0;                           /*  OPSLR_OPC0_0    */
    volatile uint8_t   dummy263[248];                          /*                  */
/* end of struct st_scux_from_opcir_opc0_n */
/* start of struct st_scux_from_opcir_opc0_n */
    volatile uint32_t  OPCIR_OPC0_1;                           /*  OPCIR_OPC0_1    */
    volatile uint32_t  OPSLR_OPC0_1;                           /*  OPSLR_OPC0_1    */
    volatile uint8_t   dummy264[248];                          /*                  */
/* end of struct st_scux_from_opcir_opc0_n */
/* start of struct st_scux_from_opcir_opc0_n */
    volatile uint32_t  OPCIR_OPC0_2;                           /*  OPCIR_OPC0_2    */
    volatile uint32_t  OPSLR_OPC0_2;                           /*  OPSLR_OPC0_2    */
    volatile uint8_t   dummy265[248];                          /*                  */
/* end of struct st_scux_from_opcir_opc0_n */
/* start of struct st_scux_from_opcir_opc0_n */
    volatile uint32_t  OPCIR_OPC0_3;                           /*  OPCIR_OPC0_3    */
    volatile uint32_t  OPSLR_OPC0_3;                           /*  OPSLR_OPC0_3    */
    volatile uint8_t   dummy266[248];                          /*                  */
/* end of struct st_scux_from_opcir_opc0_n */
/* start of struct st_scux_from_ffdir_ffd0_n */
    volatile uint32_t  FFDIR_FFD0_0;                           /*  FFDIR_FFD0_0    */
    volatile uint32_t  FDAIR_FFD0_0;                           /*  FDAIR_FFD0_0    */
    volatile uint32_t  DRQSR_FFD0_0;                           /*  DRQSR_FFD0_0    */
    volatile uint32_t  FFDPR_FFD0_0;                           /*  FFDPR_FFD0_0    */
    volatile uint32_t  FFDBR_FFD0_0;                           /*  FFDBR_FFD0_0    */
    volatile uint32_t  DEVMR_FFD0_0;                           /*  DEVMR_FFD0_0    */
    volatile uint8_t   dummy267[4];                            /*                  */
    volatile uint32_t  DEVCR_FFD0_0;                           /*  DEVCR_FFD0_0    */
/* end of struct st_scux_from_ffdir_ffd0_n */
    volatile uint8_t   dummy268[224];                          /*                  */
/* start of struct st_scux_from_ffdir_ffd0_n */
    volatile uint32_t  FFDIR_FFD0_1;                           /*  FFDIR_FFD0_1    */
    volatile uint32_t  FDAIR_FFD0_1;                           /*  FDAIR_FFD0_1    */
    volatile uint32_t  DRQSR_FFD0_1;                           /*  DRQSR_FFD0_1    */
    volatile uint32_t  FFDPR_FFD0_1;                           /*  FFDPR_FFD0_1    */
    volatile uint32_t  FFDBR_FFD0_1;                           /*  FFDBR_FFD0_1    */
    volatile uint32_t  DEVMR_FFD0_1;                           /*  DEVMR_FFD0_1    */
    volatile uint8_t   dummy269[4];                            /*                  */
    volatile uint32_t  DEVCR_FFD0_1;                           /*  DEVCR_FFD0_1    */
/* end of struct st_scux_from_ffdir_ffd0_n */
    volatile uint8_t   dummy270[224];                          /*                  */
/* start of struct st_scux_from_ffdir_ffd0_n */
    volatile uint32_t  FFDIR_FFD0_2;                           /*  FFDIR_FFD0_2    */
    volatile uint32_t  FDAIR_FFD0_2;                           /*  FDAIR_FFD0_2    */
    volatile uint32_t  DRQSR_FFD0_2;                           /*  DRQSR_FFD0_2    */
    volatile uint32_t  FFDPR_FFD0_2;                           /*  FFDPR_FFD0_2    */
    volatile uint32_t  FFDBR_FFD0_2;                           /*  FFDBR_FFD0_2    */
    volatile uint32_t  DEVMR_FFD0_2;                           /*  DEVMR_FFD0_2    */
    volatile uint8_t   dummy271[4];                            /*                  */
    volatile uint32_t  DEVCR_FFD0_2;                           /*  DEVCR_FFD0_2    */
/* end of struct st_scux_from_ffdir_ffd0_n */
    volatile uint8_t   dummy272[224];                          /*                  */
/* start of struct st_scux_from_ffdir_ffd0_n */
    volatile uint32_t  FFDIR_FFD0_3;                           /*  FFDIR_FFD0_3    */
    volatile uint32_t  FDAIR_FFD0_3;                           /*  FDAIR_FFD0_3    */
    volatile uint32_t  DRQSR_FFD0_3;                           /*  DRQSR_FFD0_3    */
    volatile uint32_t  FFDPR_FFD0_3;                           /*  FFDPR_FFD0_3    */
    volatile uint32_t  FFDBR_FFD0_3;                           /*  FFDBR_FFD0_3    */
    volatile uint32_t  DEVMR_FFD0_3;                           /*  DEVMR_FFD0_3    */
    volatile uint8_t   dummy273[4];                            /*                  */
    volatile uint32_t  DEVCR_FFD0_3;                           /*  DEVCR_FFD0_3    */
/* end of struct st_scux_from_ffdir_ffd0_n */
    volatile uint8_t   dummy274[224];                          /*                  */
/* start of struct st_scux_from_ffuir_ffu0_n */
    volatile uint32_t  FFUIR_FFU0_0;                           /*  FFUIR_FFU0_0    */
    volatile uint32_t  FUAIR_FFU0_0;                           /*  FUAIR_FFU0_0    */
    volatile uint32_t  URQSR_FFU0_0;                           /*  URQSR_FFU0_0    */
    volatile uint32_t  FFUPR_FFU0_0;                           /*  FFUPR_FFU0_0    */
    volatile uint32_t  UEVMR_FFU0_0;                           /*  UEVMR_FFU0_0    */
    volatile uint8_t   dummy275[4];                            /*                  */
    volatile uint32_t  UEVCR_FFU0_0;                           /*  UEVCR_FFU0_0    */
/* end of struct st_scux_from_ffuir_ffu0_n */
    volatile uint8_t   dummy276[228];                          /*                  */
/* start of struct st_scux_from_ffuir_ffu0_n */
    volatile uint32_t  FFUIR_FFU0_1;                           /*  FFUIR_FFU0_1    */
    volatile uint32_t  FUAIR_FFU0_1;                           /*  FUAIR_FFU0_1    */
    volatile uint32_t  URQSR_FFU0_1;                           /*  URQSR_FFU0_1    */
    volatile uint32_t  FFUPR_FFU0_1;                           /*  FFUPR_FFU0_1    */
    volatile uint32_t  UEVMR_FFU0_1;                           /*  UEVMR_FFU0_1    */
    volatile uint8_t   dummy277[4];                            /*                  */
    volatile uint32_t  UEVCR_FFU0_1;                           /*  UEVCR_FFU0_1    */
/* end of struct st_scux_from_ffuir_ffu0_n */
    volatile uint8_t   dummy278[228];                          /*                  */
/* start of struct st_scux_from_ffuir_ffu0_n */
    volatile uint32_t  FFUIR_FFU0_2;                           /*  FFUIR_FFU0_2    */
    volatile uint32_t  FUAIR_FFU0_2;                           /*  FUAIR_FFU0_2    */
    volatile uint32_t  URQSR_FFU0_2;                           /*  URQSR_FFU0_2    */
    volatile uint32_t  FFUPR_FFU0_2;                           /*  FFUPR_FFU0_2    */
    volatile uint32_t  UEVMR_FFU0_2;                           /*  UEVMR_FFU0_2    */
    volatile uint8_t   dummy279[4];                            /*                  */
    volatile uint32_t  UEVCR_FFU0_2;                           /*  UEVCR_FFU0_2    */
/* end of struct st_scux_from_ffuir_ffu0_n */
    volatile uint8_t   dummy280[228];                          /*                  */
/* start of struct st_scux_from_ffuir_ffu0_n */
    volatile uint32_t  FFUIR_FFU0_3;                           /*  FFUIR_FFU0_3    */
    volatile uint32_t  FUAIR_FFU0_3;                           /*  FUAIR_FFU0_3    */
    volatile uint32_t  URQSR_FFU0_3;                           /*  URQSR_FFU0_3    */
    volatile uint32_t  FFUPR_FFU0_3;                           /*  FFUPR_FFU0_3    */
    volatile uint32_t  UEVMR_FFU0_3;                           /*  UEVMR_FFU0_3    */
    volatile uint8_t   dummy281[4];                            /*                  */
    volatile uint32_t  UEVCR_FFU0_3;                           /*  UEVCR_FFU0_3    */
/* end of struct st_scux_from_ffuir_ffu0_n */
    volatile uint8_t   dummy282[228];                          /*                  */
/* start of struct st_scux_from_srcir0_2src0_n */
    volatile uint32_t  SRCIR0_2SRC0_0;                         /*  SRCIR0_2SRC0_0  */
    volatile uint32_t  SADIR0_2SRC0_0;                         /*  SADIR0_2SRC0_0  */
    volatile uint32_t  SRCBR0_2SRC0_0;                         /*  SRCBR0_2SRC0_0  */
    volatile uint32_t  IFSCR0_2SRC0_0;                         /*  IFSCR0_2SRC0_0  */
    volatile uint32_t  IFSVR0_2SRC0_0;                         /*  IFSVR0_2SRC0_0  */
    volatile uint32_t  SRCCR0_2SRC0_0;                         /*  SRCCR0_2SRC0_0  */
    volatile uint32_t  MNFSR0_2SRC0_0;                         /*  MNFSR0_2SRC0_0  */
    volatile uint32_t  BFSSR0_2SRC0_0;                         /*  BFSSR0_2SRC0_0  */
    volatile uint32_t  SC2SR0_2SRC0_0;                         /*  SC2SR0_2SRC0_0  */
    volatile uint32_t  WATSR0_2SRC0_0;                         /*  WATSR0_2SRC0_0  */
    volatile uint32_t  SEVMR0_2SRC0_0;                         /*  SEVMR0_2SRC0_0  */
    volatile uint8_t   dummy283[4];                            /*                  */
    volatile uint32_t  SEVCR0_2SRC0_0;                         /*  SEVCR0_2SRC0_0  */
    volatile uint32_t  SRCIR1_2SRC0_0;                         /*  SRCIR1_2SRC0_0  */
    volatile uint32_t  SADIR1_2SRC0_0;                         /*  SADIR1_2SRC0_0  */
    volatile uint32_t  SRCBR1_2SRC0_0;                         /*  SRCBR1_2SRC0_0  */
    volatile uint32_t  IFSCR1_2SRC0_0;                         /*  IFSCR1_2SRC0_0  */
    volatile uint32_t  IFSVR1_2SRC0_0;                         /*  IFSVR1_2SRC0_0  */
    volatile uint32_t  SRCCR1_2SRC0_0;                         /*  SRCCR1_2SRC0_0  */
    volatile uint32_t  MNFSR1_2SRC0_0;                         /*  MNFSR1_2SRC0_0  */
    volatile uint32_t  BFSSR1_2SRC0_0;                         /*  BFSSR1_2SRC0_0  */
    volatile uint32_t  SC2SR1_2SRC0_0;                         /*  SC2SR1_2SRC0_0  */
    volatile uint32_t  WATSR1_2SRC0_0;                         /*  WATSR1_2SRC0_0  */
    volatile uint32_t  SEVMR1_2SRC0_0;                         /*  SEVMR1_2SRC0_0  */
    volatile uint8_t   dummy284[4];                            /*                  */
    volatile uint32_t  SEVCR1_2SRC0_0;                         /*  SEVCR1_2SRC0_0  */
    volatile uint32_t  SRCIRR_2SRC0_0;                         /*  SRCIRR_2SRC0_0  */
/* end of struct st_scux_from_srcir0_2src0_n */
    volatile uint8_t   dummy285[148];                          /*                  */
/* start of struct st_scux_from_srcir0_2src0_n */
    volatile uint32_t  SRCIR0_2SRC0_1;                         /*  SRCIR0_2SRC0_1  */
    volatile uint32_t  SADIR0_2SRC0_1;                         /*  SADIR0_2SRC0_1  */
    volatile uint32_t  SRCBR0_2SRC0_1;                         /*  SRCBR0_2SRC0_1  */
    volatile uint32_t  IFSCR0_2SRC0_1;                         /*  IFSCR0_2SRC0_1  */
    volatile uint32_t  IFSVR0_2SRC0_1;                         /*  IFSVR0_2SRC0_1  */
    volatile uint32_t  SRCCR0_2SRC0_1;                         /*  SRCCR0_2SRC0_1  */
    volatile uint32_t  MNFSR0_2SRC0_1;                         /*  MNFSR0_2SRC0_1  */
    volatile uint32_t  BFSSR0_2SRC0_1;                         /*  BFSSR0_2SRC0_1  */
    volatile uint32_t  SC2SR0_2SRC0_1;                         /*  SC2SR0_2SRC0_1  */
    volatile uint32_t  WATSR0_2SRC0_1;                         /*  WATSR0_2SRC0_1  */
    volatile uint32_t  SEVMR0_2SRC0_1;                         /*  SEVMR0_2SRC0_1  */
    volatile uint8_t   dummy286[4];                            /*                  */
    volatile uint32_t  SEVCR0_2SRC0_1;                         /*  SEVCR0_2SRC0_1  */
    volatile uint32_t  SRCIR1_2SRC0_1;                         /*  SRCIR1_2SRC0_1  */
    volatile uint32_t  SADIR1_2SRC0_1;                         /*  SADIR1_2SRC0_1  */
    volatile uint32_t  SRCBR1_2SRC0_1;                         /*  SRCBR1_2SRC0_1  */
    volatile uint32_t  IFSCR1_2SRC0_1;                         /*  IFSCR1_2SRC0_1  */
    volatile uint32_t  IFSVR1_2SRC0_1;                         /*  IFSVR1_2SRC0_1  */
    volatile uint32_t  SRCCR1_2SRC0_1;                         /*  SRCCR1_2SRC0_1  */
    volatile uint32_t  MNFSR1_2SRC0_1;                         /*  MNFSR1_2SRC0_1  */
    volatile uint32_t  BFSSR1_2SRC0_1;                         /*  BFSSR1_2SRC0_1  */
    volatile uint32_t  SC2SR1_2SRC0_1;                         /*  SC2SR1_2SRC0_1  */
    volatile uint32_t  WATSR1_2SRC0_1;                         /*  WATSR1_2SRC0_1  */
    volatile uint32_t  SEVMR1_2SRC0_1;                         /*  SEVMR1_2SRC0_1  */
    volatile uint8_t   dummy287[4];                            /*                  */
    volatile uint32_t  SEVCR1_2SRC0_1;                         /*  SEVCR1_2SRC0_1  */
    volatile uint32_t  SRCIRR_2SRC0_1;                         /*  SRCIRR_2SRC0_1  */
/* end of struct st_scux_from_srcir0_2src0_n */
    volatile uint8_t   dummy288[148];                          /*                  */
/* start of struct st_scux_from_dvuir_dvu0_n */
    volatile uint32_t  DVUIR_DVU0_0;                           /*  DVUIR_DVU0_0    */
    volatile uint32_t  VADIR_DVU0_0;                           /*  VADIR_DVU0_0    */
    volatile uint32_t  DVUBR_DVU0_0;                           /*  DVUBR_DVU0_0    */
    volatile uint32_t  DVUCR_DVU0_0;                           /*  DVUCR_DVU0_0    */
    volatile uint32_t  ZCMCR_DVU0_0;                           /*  ZCMCR_DVU0_0    */
    volatile uint32_t  VRCTR_DVU0_0;                           /*  VRCTR_DVU0_0    */
    volatile uint32_t  VRPDR_DVU0_0;                           /*  VRPDR_DVU0_0    */
    volatile uint32_t  VRDBR_DVU0_0;                           /*  VRDBR_DVU0_0    */
    volatile uint32_t  VRWTR_DVU0_0;                           /*  VRWTR_DVU0_0    */
    volatile uint32_t  VOL0R_DVU0_0;                           /*  VOL0R_DVU0_0    */
    volatile uint32_t  VOL1R_DVU0_0;                           /*  VOL1R_DVU0_0    */
    volatile uint32_t  VOL2R_DVU0_0;                           /*  VOL2R_DVU0_0    */
    volatile uint32_t  VOL3R_DVU0_0;                           /*  VOL3R_DVU0_0    */
    volatile uint32_t  VOL4R_DVU0_0;                           /*  VOL4R_DVU0_0    */
    volatile uint32_t  VOL5R_DVU0_0;                           /*  VOL5R_DVU0_0    */
    volatile uint32_t  VOL6R_DVU0_0;                           /*  VOL6R_DVU0_0    */
    volatile uint32_t  VOL7R_DVU0_0;                           /*  VOL7R_DVU0_0    */
    volatile uint32_t  DVUER_DVU0_0;                           /*  DVUER_DVU0_0    */
    volatile uint32_t  DVUSR_DVU0_0;                           /*  DVUSR_DVU0_0    */
    volatile uint32_t  VEVMR_DVU0_0;                           /*  VEVMR_DVU0_0    */
    volatile uint8_t   dummy289[4];                            /*                  */
    volatile uint32_t  VEVCR_DVU0_0;                           /*  VEVCR_DVU0_0    */
/* end of struct st_scux_from_dvuir_dvu0_n */
    volatile uint8_t   dummy290[168];                          /*                  */
/* start of struct st_scux_from_dvuir_dvu0_n */
    volatile uint32_t  DVUIR_DVU0_1;                           /*  DVUIR_DVU0_1    */
    volatile uint32_t  VADIR_DVU0_1;                           /*  VADIR_DVU0_1    */
    volatile uint32_t  DVUBR_DVU0_1;                           /*  DVUBR_DVU0_1    */
    volatile uint32_t  DVUCR_DVU0_1;                           /*  DVUCR_DVU0_1    */
    volatile uint32_t  ZCMCR_DVU0_1;                           /*  ZCMCR_DVU0_1    */
    volatile uint32_t  VRCTR_DVU0_1;                           /*  VRCTR_DVU0_1    */
    volatile uint32_t  VRPDR_DVU0_1;                           /*  VRPDR_DVU0_1    */
    volatile uint32_t  VRDBR_DVU0_1;                           /*  VRDBR_DVU0_1    */
    volatile uint32_t  VRWTR_DVU0_1;                           /*  VRWTR_DVU0_1    */
    volatile uint32_t  VOL0R_DVU0_1;                           /*  VOL0R_DVU0_1    */
    volatile uint32_t  VOL1R_DVU0_1;                           /*  VOL1R_DVU0_1    */
    volatile uint32_t  VOL2R_DVU0_1;                           /*  VOL2R_DVU0_1    */
    volatile uint32_t  VOL3R_DVU0_1;                           /*  VOL3R_DVU0_1    */
    volatile uint32_t  VOL4R_DVU0_1;                           /*  VOL4R_DVU0_1    */
    volatile uint32_t  VOL5R_DVU0_1;                           /*  VOL5R_DVU0_1    */
    volatile uint32_t  VOL6R_DVU0_1;                           /*  VOL6R_DVU0_1    */
    volatile uint32_t  VOL7R_DVU0_1;                           /*  VOL7R_DVU0_1    */
    volatile uint32_t  DVUER_DVU0_1;                           /*  DVUER_DVU0_1    */
    volatile uint32_t  DVUSR_DVU0_1;                           /*  DVUSR_DVU0_1    */
    volatile uint32_t  VEVMR_DVU0_1;                           /*  VEVMR_DVU0_1    */
    volatile uint8_t   dummy291[4];                            /*                  */
    volatile uint32_t  VEVCR_DVU0_1;                           /*  VEVCR_DVU0_1    */
/* end of struct st_scux_from_dvuir_dvu0_n */
    volatile uint8_t   dummy292[168];                          /*                  */
/* start of struct st_scux_from_dvuir_dvu0_n */
    volatile uint32_t  DVUIR_DVU0_2;                           /*  DVUIR_DVU0_2    */
    volatile uint32_t  VADIR_DVU0_2;                           /*  VADIR_DVU0_2    */
    volatile uint32_t  DVUBR_DVU0_2;                           /*  DVUBR_DVU0_2    */
    volatile uint32_t  DVUCR_DVU0_2;                           /*  DVUCR_DVU0_2    */
    volatile uint32_t  ZCMCR_DVU0_2;                           /*  ZCMCR_DVU0_2    */
    volatile uint32_t  VRCTR_DVU0_2;                           /*  VRCTR_DVU0_2    */
    volatile uint32_t  VRPDR_DVU0_2;                           /*  VRPDR_DVU0_2    */
    volatile uint32_t  VRDBR_DVU0_2;                           /*  VRDBR_DVU0_2    */
    volatile uint32_t  VRWTR_DVU0_2;                           /*  VRWTR_DVU0_2    */
    volatile uint32_t  VOL0R_DVU0_2;                           /*  VOL0R_DVU0_2    */
    volatile uint32_t  VOL1R_DVU0_2;                           /*  VOL1R_DVU0_2    */
    volatile uint32_t  VOL2R_DVU0_2;                           /*  VOL2R_DVU0_2    */
    volatile uint32_t  VOL3R_DVU0_2;                           /*  VOL3R_DVU0_2    */
    volatile uint32_t  VOL4R_DVU0_2;                           /*  VOL4R_DVU0_2    */
    volatile uint32_t  VOL5R_DVU0_2;                           /*  VOL5R_DVU0_2    */
    volatile uint32_t  VOL6R_DVU0_2;                           /*  VOL6R_DVU0_2    */
    volatile uint32_t  VOL7R_DVU0_2;                           /*  VOL7R_DVU0_2    */
    volatile uint32_t  DVUER_DVU0_2;                           /*  DVUER_DVU0_2    */
    volatile uint32_t  DVUSR_DVU0_2;                           /*  DVUSR_DVU0_2    */
    volatile uint32_t  VEVMR_DVU0_2;                           /*  VEVMR_DVU0_2    */
    volatile uint8_t   dummy293[4];                            /*                  */
    volatile uint32_t  VEVCR_DVU0_2;                           /*  VEVCR_DVU0_2    */
/* end of struct st_scux_from_dvuir_dvu0_n */
    volatile uint8_t   dummy294[168];                          /*                  */
/* start of struct st_scux_from_dvuir_dvu0_n */
    volatile uint32_t  DVUIR_DVU0_3;                           /*  DVUIR_DVU0_3    */
    volatile uint32_t  VADIR_DVU0_3;                           /*  VADIR_DVU0_3    */
    volatile uint32_t  DVUBR_DVU0_3;                           /*  DVUBR_DVU0_3    */
    volatile uint32_t  DVUCR_DVU0_3;                           /*  DVUCR_DVU0_3    */
    volatile uint32_t  ZCMCR_DVU0_3;                           /*  ZCMCR_DVU0_3    */
    volatile uint32_t  VRCTR_DVU0_3;                           /*  VRCTR_DVU0_3    */
    volatile uint32_t  VRPDR_DVU0_3;                           /*  VRPDR_DVU0_3    */
    volatile uint32_t  VRDBR_DVU0_3;                           /*  VRDBR_DVU0_3    */
    volatile uint32_t  VRWTR_DVU0_3;                           /*  VRWTR_DVU0_3    */
    volatile uint32_t  VOL0R_DVU0_3;                           /*  VOL0R_DVU0_3    */
    volatile uint32_t  VOL1R_DVU0_3;                           /*  VOL1R_DVU0_3    */
    volatile uint32_t  VOL2R_DVU0_3;                           /*  VOL2R_DVU0_3    */
    volatile uint32_t  VOL3R_DVU0_3;                           /*  VOL3R_DVU0_3    */
    volatile uint32_t  VOL4R_DVU0_3;                           /*  VOL4R_DVU0_3    */
    volatile uint32_t  VOL5R_DVU0_3;                           /*  VOL5R_DVU0_3    */
    volatile uint32_t  VOL6R_DVU0_3;                           /*  VOL6R_DVU0_3    */
    volatile uint32_t  VOL7R_DVU0_3;                           /*  VOL7R_DVU0_3    */
    volatile uint32_t  DVUER_DVU0_3;                           /*  DVUER_DVU0_3    */
    volatile uint32_t  DVUSR_DVU0_3;                           /*  DVUSR_DVU0_3    */
    volatile uint32_t  VEVMR_DVU0_3;                           /*  VEVMR_DVU0_3    */
    volatile uint8_t   dummy295[4];                            /*                  */
    volatile uint32_t  VEVCR_DVU0_3;                           /*  VEVCR_DVU0_3    */
/* end of struct st_scux_from_dvuir_dvu0_n */
    volatile uint8_t   dummy296[168];                          /*                  */
    volatile uint32_t  MIXIR_MIX0_0;                           /*  MIXIR_MIX0_0    */
    volatile uint32_t  MADIR_MIX0_0;                           /*  MADIR_MIX0_0    */
    volatile uint32_t  MIXBR_MIX0_0;                           /*  MIXBR_MIX0_0    */
    volatile uint32_t  MIXMR_MIX0_0;                           /*  MIXMR_MIX0_0    */
    volatile uint32_t  MVPDR_MIX0_0;                           /*  MVPDR_MIX0_0    */
    volatile uint32_t  MDBAR_MIX0_0;                           /*  MDBAR_MIX0_0    */
    volatile uint32_t  MDBBR_MIX0_0;                           /*  MDBBR_MIX0_0    */
    volatile uint32_t  MDBCR_MIX0_0;                           /*  MDBCR_MIX0_0    */
    volatile uint32_t  MDBDR_MIX0_0;                           /*  MDBDR_MIX0_0    */
    volatile uint32_t  MDBER_MIX0_0;                           /*  MDBER_MIX0_0    */
    volatile uint32_t  MIXSR_MIX0_0;                           /*  MIXSR_MIX0_0    */
    volatile uint8_t   dummy297[212];                          /*                  */
    volatile uint32_t  SWRSR_CIM;                              /*  SWRSR_CIM       */
    volatile uint32_t  DMACR_CIM;                              /*  DMACR_CIM       */

    union iodefine_reg32_16_t  DMATD0_CIM;                 /*  DMATD0_CIM      */
    union iodefine_reg32_16_t  DMATD1_CIM;                 /*  DMATD1_CIM      */
    union iodefine_reg32_16_t  DMATD2_CIM;                 /*  DMATD2_CIM      */
    union iodefine_reg32_16_t  DMATD3_CIM;                 /*  DMATD3_CIM      */

    union iodefine_reg32_16_t  DMATU0_CIM;                 /*  DMATU0_CIM      */
    union iodefine_reg32_16_t  DMATU1_CIM;                 /*  DMATU1_CIM      */
    union iodefine_reg32_16_t  DMATU2_CIM;                 /*  DMATU2_CIM      */
    union iodefine_reg32_16_t  DMATU3_CIM;                 /*  DMATU3_CIM      */
    
    volatile uint8_t   dummy298[16];                           /*                  */
    volatile uint32_t  SSIRSEL_CIM;                            /*  SSIRSEL_CIM     */

    volatile uint32_t  FDTSEL0_CIM;                            /*  FDTSEL0_CIM     */
    volatile uint32_t  FDTSEL1_CIM;                            /*  FDTSEL1_CIM     */
    volatile uint32_t  FDTSEL2_CIM;                            /*  FDTSEL2_CIM     */
    volatile uint32_t  FDTSEL3_CIM;                            /*  FDTSEL3_CIM     */

    volatile uint32_t  FUTSEL0_CIM;                            /*  FUTSEL0_CIM     */
    volatile uint32_t  FUTSEL1_CIM;                            /*  FUTSEL1_CIM     */
    volatile uint32_t  FUTSEL2_CIM;                            /*  FUTSEL2_CIM     */
    volatile uint32_t  FUTSEL3_CIM;                            /*  FUTSEL3_CIM     */
    volatile uint32_t  SSIPMD_CIM;                             /*  SSIPMD_CIM      */
    volatile uint32_t  SSICTRL_CIM;                            /*  SSICTRL_CIM     */

    volatile uint32_t  SRCRSEL0_CIM;                           /*  SRCRSEL0_CIM    */
    volatile uint32_t  SRCRSEL1_CIM;                           /*  SRCRSEL1_CIM    */
    volatile uint32_t  SRCRSEL2_CIM;                           /*  SRCRSEL2_CIM    */
    volatile uint32_t  SRCRSEL3_CIM;                           /*  SRCRSEL3_CIM    */
    volatile uint32_t  MIXRSEL_CIM;                            /*  MIXRSEL_CIM     */
};


struct st_scux_from_ipcir_ipc0_n
{
    volatile uint32_t  IPCIR_IPC0_0;                           /*  IPCIR_IPC0_0    */
    volatile uint32_t  IPSLR_IPC0_0;                           /*  IPSLR_IPC0_0    */
    volatile uint8_t   dummy1[248];                            /*                  */
};


struct st_scux_from_opcir_opc0_n
{
    volatile uint32_t  OPCIR_OPC0_0;                           /*  OPCIR_OPC0_0    */
    volatile uint32_t  OPSLR_OPC0_0;                           /*  OPSLR_OPC0_0    */
    volatile uint8_t   dummy1[248];                            /*                  */
};


struct st_scux_from_ffdir_ffd0_n
{
    volatile uint32_t  FFDIR_FFD0_0;                           /*  FFDIR_FFD0_0    */
    volatile uint32_t  FDAIR_FFD0_0;                           /*  FDAIR_FFD0_0    */
    volatile uint32_t  DRQSR_FFD0_0;                           /*  DRQSR_FFD0_0    */
    volatile uint32_t  FFDPR_FFD0_0;                           /*  FFDPR_FFD0_0    */
    volatile uint32_t  FFDBR_FFD0_0;                           /*  FFDBR_FFD0_0    */
    volatile uint32_t  DEVMR_FFD0_0;                           /*  DEVMR_FFD0_0    */
    volatile uint8_t   dummy1[4];                              /*                  */
    volatile uint32_t  DEVCR_FFD0_0;                           /*  DEVCR_FFD0_0    */
};


struct st_scux_from_ffuir_ffu0_n
{
    volatile uint32_t  FFUIR_FFU0_0;                           /*  FFUIR_FFU0_0    */
    volatile uint32_t  FUAIR_FFU0_0;                           /*  FUAIR_FFU0_0    */
    volatile uint32_t  URQSR_FFU0_0;                           /*  URQSR_FFU0_0    */
    volatile uint32_t  FFUPR_FFU0_0;                           /*  FFUPR_FFU0_0    */
    volatile uint32_t  UEVMR_FFU0_0;                           /*  UEVMR_FFU0_0    */
    volatile uint8_t   dummy1[4];                              /*                  */
    volatile uint32_t  UEVCR_FFU0_0;                           /*  UEVCR_FFU0_0    */
};


struct st_scux_from_srcir0_2src0_n
{
    volatile uint32_t  SRCIR0_2SRC0_0;                         /*  SRCIR0_2SRC0_0  */
    volatile uint32_t  SADIR0_2SRC0_0;                         /*  SADIR0_2SRC0_0  */
    volatile uint32_t  SRCBR0_2SRC0_0;                         /*  SRCBR0_2SRC0_0  */
    volatile uint32_t  IFSCR0_2SRC0_0;                         /*  IFSCR0_2SRC0_0  */
    volatile uint32_t  IFSVR0_2SRC0_0;                         /*  IFSVR0_2SRC0_0  */
    volatile uint32_t  SRCCR0_2SRC0_0;                         /*  SRCCR0_2SRC0_0  */
    volatile uint32_t  MNFSR0_2SRC0_0;                         /*  MNFSR0_2SRC0_0  */
    volatile uint32_t  BFSSR0_2SRC0_0;                         /*  BFSSR0_2SRC0_0  */
    volatile uint32_t  SC2SR0_2SRC0_0;                         /*  SC2SR0_2SRC0_0  */
    volatile uint32_t  WATSR0_2SRC0_0;                         /*  WATSR0_2SRC0_0  */
    volatile uint32_t  SEVMR0_2SRC0_0;                         /*  SEVMR0_2SRC0_0  */
    volatile uint8_t   dummy1[4];                              /*                  */
    volatile uint32_t  SEVCR0_2SRC0_0;                         /*  SEVCR0_2SRC0_0  */
    volatile uint32_t  SRCIR1_2SRC0_0;                         /*  SRCIR1_2SRC0_0  */
    volatile uint32_t  SADIR1_2SRC0_0;                         /*  SADIR1_2SRC0_0  */
    volatile uint32_t  SRCBR1_2SRC0_0;                         /*  SRCBR1_2SRC0_0  */
    volatile uint32_t  IFSCR1_2SRC0_0;                         /*  IFSCR1_2SRC0_0  */
    volatile uint32_t  IFSVR1_2SRC0_0;                         /*  IFSVR1_2SRC0_0  */
    volatile uint32_t  SRCCR1_2SRC0_0;                         /*  SRCCR1_2SRC0_0  */
    volatile uint32_t  MNFSR1_2SRC0_0;                         /*  MNFSR1_2SRC0_0  */
    volatile uint32_t  BFSSR1_2SRC0_0;                         /*  BFSSR1_2SRC0_0  */
    volatile uint32_t  SC2SR1_2SRC0_0;                         /*  SC2SR1_2SRC0_0  */
    volatile uint32_t  WATSR1_2SRC0_0;                         /*  WATSR1_2SRC0_0  */
    volatile uint32_t  SEVMR1_2SRC0_0;                         /*  SEVMR1_2SRC0_0  */
    volatile uint8_t   dummy2[4];                              /*                  */
    volatile uint32_t  SEVCR1_2SRC0_0;                         /*  SEVCR1_2SRC0_0  */
    volatile uint32_t  SRCIRR_2SRC0_0;                         /*  SRCIRR_2SRC0_0  */
};


struct st_scux_from_dvuir_dvu0_n
{
    volatile uint32_t  DVUIR_DVU0_0;                           /*  DVUIR_DVU0_0    */
    volatile uint32_t  VADIR_DVU0_0;                           /*  VADIR_DVU0_0    */
    volatile uint32_t  DVUBR_DVU0_0;                           /*  DVUBR_DVU0_0    */
    volatile uint32_t  DVUCR_DVU0_0;                           /*  DVUCR_DVU0_0    */
    volatile uint32_t  ZCMCR_DVU0_0;                           /*  ZCMCR_DVU0_0    */
    volatile uint32_t  VRCTR_DVU0_0;                           /*  VRCTR_DVU0_0    */
    volatile uint32_t  VRPDR_DVU0_0;                           /*  VRPDR_DVU0_0    */
    volatile uint32_t  VRDBR_DVU0_0;                           /*  VRDBR_DVU0_0    */
    volatile uint32_t  VRWTR_DVU0_0;                           /*  VRWTR_DVU0_0    */
    volatile uint32_t  VOL0R_DVU0_0;                           /*  VOL0R_DVU0_0    */
    volatile uint32_t  VOL1R_DVU0_0;                           /*  VOL1R_DVU0_0    */
    volatile uint32_t  VOL2R_DVU0_0;                           /*  VOL2R_DVU0_0    */
    volatile uint32_t  VOL3R_DVU0_0;                           /*  VOL3R_DVU0_0    */
    volatile uint32_t  VOL4R_DVU0_0;                           /*  VOL4R_DVU0_0    */
    volatile uint32_t  VOL5R_DVU0_0;                           /*  VOL5R_DVU0_0    */
    volatile uint32_t  VOL6R_DVU0_0;                           /*  VOL6R_DVU0_0    */
    volatile uint32_t  VOL7R_DVU0_0;                           /*  VOL7R_DVU0_0    */
    volatile uint32_t  DVUER_DVU0_0;                           /*  DVUER_DVU0_0    */
    volatile uint32_t  DVUSR_DVU0_0;                           /*  DVUSR_DVU0_0    */
    volatile uint32_t  VEVMR_DVU0_0;                           /*  VEVMR_DVU0_0    */
    volatile uint8_t   dummy1[4];                              /*                  */
    volatile uint32_t  VEVCR_DVU0_0;                           /*  VEVCR_DVU0_0    */
};





/* Start of channnel array defines of SCUX */

/* Channnel array defines of SCUX_FROM_DVUIR_DVU0_0_ARRAY */
/*(Sample) value = SCUX_FROM_DVUIR_DVU0_0_ARRAY[ channel ]->DVUIR_DVU0_0; */
#line 484 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/scux_iodefine.h"


/* Channnel array defines of SCUX_FROM_SRCIR0_2SRC0_0_ARRAY */
/*(Sample) value = SCUX_FROM_SRCIR0_2SRC0_0_ARRAY[ channel ]->SRCIR0_2SRC0_0; */
#line 495 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/scux_iodefine.h"


/* Channnel array defines of SCUX_FROM_FFUIR_FFU0_0_ARRAY */
/*(Sample) value = SCUX_FROM_FFUIR_FFU0_0_ARRAY[ channel ]->FFUIR_FFU0_0; */
#line 508 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/scux_iodefine.h"


/* Channnel array defines of SCUX_FROM_FFDIR_FFD0_0_ARRAY */
/*(Sample) value = SCUX_FROM_FFDIR_FFD0_0_ARRAY[ channel ]->FFDIR_FFD0_0; */
#line 521 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/scux_iodefine.h"


/* Channnel array defines of SCUX_FROM_OPCIR_OPC0_0_ARRAY */
/*(Sample) value = SCUX_FROM_OPCIR_OPC0_0_ARRAY[ channel ]->OPCIR_OPC0_0; */
#line 534 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/scux_iodefine.h"


/* Channnel array defines of SCUX_FROM_IPCIR_IPC0_0_ARRAY */
/*(Sample) value = SCUX_FROM_IPCIR_IPC0_0_ARRAY[ channel ]->IPCIR_IPC0_0; */
#line 547 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/scux_iodefine.h"

/* End of channnel array defines of SCUX */


#line 806 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/scux_iodefine.h"
/* <-SEC M1.10.1 */
/* <-QAC 0639 */
#line 130 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/sdg_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : sdg_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/



struct st_sdg
{                                                          /* SDG              */
    volatile uint8_t   SGCR1;                                  /*  SGCR1           */
    volatile uint8_t   SGCSR;                                  /*  SGCSR           */
    volatile uint8_t   SGCR2;                                  /*  SGCR2           */
    volatile uint8_t   SGLR;                                   /*  SGLR            */
    volatile uint8_t   SGTFR;                                  /*  SGTFR           */
    volatile uint8_t   SGSFR;                                  /*  SGSFR           */
};








/* Start of channnel array defines of SDG */

/* Channnel array defines of SDG */
/*(Sample) value = SDG[ channel ]->SGCR1; */






/* End of channnel array defines of SDG */


#line 131 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/spdif_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : spdif_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/



struct st_spdif
{                                                          /* SPDIF            */
    volatile uint32_t  TLCA;                                   /*  TLCA            */
    volatile uint32_t  TRCA;                                   /*  TRCA            */
    volatile uint32_t  TLCS;                                   /*  TLCS            */
    volatile uint32_t  TRCS;                                   /*  TRCS            */
    volatile uint32_t  TUI;                                    /*  TUI             */
    volatile uint32_t  RLCA;                                   /*  RLCA            */
    volatile uint32_t  RRCA;                                   /*  RRCA            */
    volatile uint32_t  RLCS;                                   /*  RLCS            */
    volatile uint32_t  RRCS;                                   /*  RRCS            */
    volatile uint32_t  RUI;                                    /*  RUI             */
    volatile uint32_t  CTRL;                                   /*  CTRL            */
    volatile uint32_t  STAT;                                   /*  STAT            */
    volatile uint32_t  TDAD;                                   /*  TDAD            */
    volatile uint32_t  RDAD;                                   /*  RDAD            */
};





#line 132 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/spibsc_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : spibsc_iodefine.h
* $Rev: 1275 $
* $Date:: 2014-11-07 15:16:20 +0900#$
* Description : Definition of I/O Register (V1.01a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_spibsc
{                                                          /* SPIBSC           */
    volatile uint32_t  CMNCR;                                  /*  CMNCR           */
    volatile uint32_t  SSLDR;                                  /*  SSLDR           */
    volatile uint32_t  SPBCR;                                  /*  SPBCR           */
    volatile uint32_t  DRCR;                                   /*  DRCR            */
    volatile uint32_t  DRCMR;                                  /*  DRCMR           */
    volatile uint32_t  DREAR;                                  /*  DREAR           */
    volatile uint32_t  DROPR;                                  /*  DROPR           */
    volatile uint32_t  DRENR;                                  /*  DRENR           */
    volatile uint32_t  SMCR;                                   /*  SMCR            */
    volatile uint32_t  SMCMR;                                  /*  SMCMR           */
    volatile uint32_t  SMADR;                                  /*  SMADR           */
    volatile uint32_t  SMOPR;                                  /*  SMOPR           */
    volatile uint32_t  SMENR;                                  /*  SMENR           */
    volatile uint8_t   dummy1[4];                              /*                  */
    union iodefine_reg32_t  SMRDR0;                        /*  SMRDR0          */
    union iodefine_reg32_t  SMRDR1;                        /*  SMRDR1          */
    union iodefine_reg32_t  SMWDR0;                        /*  SMWDR0          */
    union iodefine_reg32_t  SMWDR1;                        /*  SMWDR1          */
    
    volatile uint32_t  CMNSR;                                  /*  CMNSR           */
    volatile uint8_t   dummy2[4];                              /*                  */
    volatile uint32_t  CKDLY;                                  /*  CKDLY           */
    volatile uint8_t   dummy3[4];                              /*                  */
    volatile uint32_t  DRDMCR;                                 /*  DRDMCR          */
    volatile uint32_t  DRDRENR;                                /*  DRDRENR         */
    volatile uint32_t  SMDMCR;                                 /*  SMDMCR          */
    volatile uint32_t  SMDRENR;                                /*  SMDRENR         */
    volatile uint32_t  SPODLY;                                 /*  SPODLY          */
};






/* Start of channnel array defines of SPIBSC */

/* Channnel array defines of SPIBSC */
/*(Sample) value = SPIBSC[ channel ]->CMNCR; */






/* End of channnel array defines of SPIBSC */


#line 179 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/spibsc_iodefine.h"
/* <-SEC M1.10.1 */
#line 133 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/ssif_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : ssif_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_ssif
{                                                          /* SSIF             */
    volatile uint32_t  SSICR;                                  /*  SSICR           */
    volatile uint32_t  SSISR;                                  /*  SSISR           */
    volatile uint8_t   dummy1[8];                              /*                  */
    volatile uint32_t  SSIFCR;                                 /*  SSIFCR          */
    volatile uint32_t  SSIFSR;                                 /*  SSIFSR          */
    volatile uint32_t  SSIFTDR;                                /*  SSIFTDR         */
    volatile uint32_t  SSIFRDR;                                /*  SSIFRDR         */
    volatile uint32_t  SSITDMR;                                /*  SSITDMR         */
    volatile uint32_t  SSIFCCR;                                /*  SSIFCCR         */
    volatile uint32_t  SSIFCMR;                                /*  SSIFCMR         */
    volatile uint32_t  SSIFCSR;                                /*  SSIFCSR         */
};


#line 55 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/ssif_iodefine.h"


/* Start of channnel array defines of SSIF */

/* Channnel array defines of SSIF */
/*(Sample) value = SSIF[ channel ]->SSICR; */






/* End of channnel array defines of SSIF */


#line 130 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/ssif_iodefine.h"
/* <-SEC M1.10.1 */
#line 134 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/usb20_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : usb20_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->SEC M1.10.1 : Not magic number */

struct st_usb20
{                                                          /* USB20            */
    volatile uint16_t SYSCFG0;                                /*  SYSCFG0         */
    volatile uint16_t BUSWAIT;                                /*  BUSWAIT         */
    volatile uint16_t SYSSTS0;                                /*  SYSSTS0         */
    volatile uint8_t   dummy1[2];                              /*                  */
    volatile uint16_t DVSTCTR0;                               /*  DVSTCTR0        */
    volatile uint8_t   dummy2[2];                              /*                  */
    volatile uint16_t TESTMODE;                               /*  TESTMODE        */
    volatile uint8_t   dummy3[2];                              /*                  */

    volatile uint16_t D0FBCFG;                                /*  D0FBCFG         */
    volatile uint16_t D1FBCFG;                                /*  D1FBCFG         */
    union iodefine_reg32_t  CFIFO;                         /*  CFIFO           */

    union iodefine_reg32_t  D0FIFO;                        /*  D0FIFO          */
    union iodefine_reg32_t  D1FIFO;                        /*  D1FIFO          */
    
    volatile uint16_t CFIFOSEL;                               /*  CFIFOSEL        */
    volatile uint16_t CFIFOCTR;                               /*  CFIFOCTR        */
    volatile uint8_t   dummy4[4];                              /*                  */
/* start of struct st_usb20_from_d0fifosel */
    volatile uint16_t D0FIFOSEL;                              /*  D0FIFOSEL       */
    volatile uint16_t D0FIFOCTR;                              /*  D0FIFOCTR       */
/* end of struct st_usb20_from_d0fifosel */
/* start of struct st_usb20_from_d0fifosel */
    volatile uint16_t D1FIFOSEL;                              /*  D1FIFOSEL       */
    volatile uint16_t D1FIFOCTR;                              /*  D1FIFOCTR       */
/* end of struct st_usb20_from_d0fifosel */

    volatile uint16_t INTENB0;                                /*  INTENB0         */
    volatile uint16_t INTENB1;                                /*  INTENB1         */
    volatile uint8_t   dummy5[2];                              /*                  */
    volatile uint16_t BRDYENB;                                /*  BRDYENB         */
    volatile uint16_t NRDYENB;                                /*  NRDYENB         */
    volatile uint16_t BEMPENB;                                /*  BEMPENB         */
    volatile uint16_t SOFCFG;                                 /*  SOFCFG          */
    volatile uint8_t   dummy6[2];                              /*                  */

    volatile uint16_t INTSTS0;                                /*  INTSTS0         */
    volatile uint16_t INTSTS1;                                /*  INTSTS1         */
    volatile uint8_t   dummy7[2];                              /*                  */
    volatile uint16_t BRDYSTS;                                /*  BRDYSTS         */
    volatile uint16_t NRDYSTS;                                /*  NRDYSTS         */
    volatile uint16_t BEMPSTS;                                /*  BEMPSTS         */
    volatile uint16_t FRMNUM;                                 /*  FRMNUM          */
    volatile uint16_t UFRMNUM;                                /*  UFRMNUM         */
    volatile uint16_t USBADDR;                                /*  USBADDR         */
    volatile uint8_t   dummy8[2];                              /*                  */
    volatile uint16_t USBREQ;                                 /*  USBREQ          */
    volatile uint16_t USBVAL;                                 /*  USBVAL          */
    volatile uint16_t USBINDX;                                /*  USBINDX         */
    volatile uint16_t USBLENG;                                /*  USBLENG         */
    volatile uint16_t DCPCFG;                                 /*  DCPCFG          */
    volatile uint16_t DCPMAXP;                                /*  DCPMAXP         */
    volatile uint16_t DCPCTR;                                 /*  DCPCTR          */
    volatile uint8_t   dummy9[2];                              /*                  */
    volatile uint16_t PIPESEL;                                /*  PIPESEL         */
    volatile uint8_t   dummy10[2];                             /*                  */
    volatile uint16_t PIPECFG;                                /*  PIPECFG         */
    volatile uint16_t PIPEBUF;                                /*  PIPEBUF         */
    volatile uint16_t PIPEMAXP;                               /*  PIPEMAXP        */
    volatile uint16_t PIPEPERI;                               /*  PIPEPERI        */

    volatile uint16_t PIPE1CTR;                               /*  PIPE1CTR        */
    volatile uint16_t PIPE2CTR;                               /*  PIPE2CTR        */
    volatile uint16_t PIPE3CTR;                               /*  PIPE3CTR        */
    volatile uint16_t PIPE4CTR;                               /*  PIPE4CTR        */
    volatile uint16_t PIPE5CTR;                               /*  PIPE5CTR        */
    volatile uint16_t PIPE6CTR;                               /*  PIPE6CTR        */
    volatile uint16_t PIPE7CTR;                               /*  PIPE7CTR        */
    volatile uint16_t PIPE8CTR;                               /*  PIPE8CTR        */
    volatile uint16_t PIPE9CTR;                               /*  PIPE9CTR        */
    volatile uint16_t PIPEACTR;                               /*  PIPEACTR        */
    volatile uint16_t PIPEBCTR;                               /*  PIPEBCTR        */
    volatile uint16_t PIPECCTR;                               /*  PIPECCTR        */
    volatile uint16_t PIPEDCTR;                               /*  PIPEDCTR        */
    volatile uint16_t PIPEECTR;                               /*  PIPEECTR        */
    volatile uint16_t PIPEFCTR;                               /*  PIPEFCTR        */
    volatile uint8_t   dummy11[2];                             /*                  */
/* start of struct st_usb20_from_pipe1tre */
    volatile uint16_t PIPE1TRE;                               /*  PIPE1TRE        */
    volatile uint16_t PIPE1TRN;                               /*  PIPE1TRN        */
/* end of struct st_usb20_from_pipe1tre */
/* start of struct st_usb20_from_pipe1tre */
    volatile uint16_t PIPE2TRE;                               /*  PIPE2TRE        */
    volatile uint16_t PIPE2TRN;                               /*  PIPE2TRN        */
/* end of struct st_usb20_from_pipe1tre */
/* start of struct st_usb20_from_pipe1tre */
    volatile uint16_t PIPE3TRE;                               /*  PIPE3TRE        */
    volatile uint16_t PIPE3TRN;                               /*  PIPE3TRN        */
/* end of struct st_usb20_from_pipe1tre */
/* start of struct st_usb20_from_pipe1tre */
    volatile uint16_t PIPE4TRE;                               /*  PIPE4TRE        */
    volatile uint16_t PIPE4TRN;                               /*  PIPE4TRN        */
/* end of struct st_usb20_from_pipe1tre */
/* start of struct st_usb20_from_pipe1tre */
    volatile uint16_t PIPE5TRE;                               /*  PIPE5TRE        */
    volatile uint16_t PIPE5TRN;                               /*  PIPE5TRN        */
/* end of struct st_usb20_from_pipe1tre */
    volatile uint16_t PIPEBTRE;                               /*  PIPEBTRE        */
    volatile uint16_t PIPEBTRN;                               /*  PIPEBTRN        */
    volatile uint16_t PIPECTRE;                               /*  PIPECTRE        */
    volatile uint16_t PIPECTRN;                               /*  PIPECTRN        */
    volatile uint16_t PIPEDTRE;                               /*  PIPEDTRE        */
    volatile uint16_t PIPEDTRN;                               /*  PIPEDTRN        */
    volatile uint16_t PIPEETRE;                               /*  PIPEETRE        */
    volatile uint16_t PIPEETRN;                               /*  PIPEETRN        */
    volatile uint16_t PIPEFTRE;                               /*  PIPEFTRE        */
    volatile uint16_t PIPEFTRN;                               /*  PIPEFTRN        */
    volatile uint16_t PIPE9TRE;                               /*  PIPE9TRE        */
    volatile uint16_t PIPE9TRN;                               /*  PIPE9TRN        */
    volatile uint16_t PIPEATRE;                               /*  PIPEATRE        */
    volatile uint16_t PIPEATRN;                               /*  PIPEATRN        */
    volatile uint8_t   dummy12[16];                            /*                  */

    volatile uint16_t DEVADD0;                                /*  DEVADD0         */
    volatile uint16_t DEVADD1;                                /*  DEVADD1         */
    volatile uint16_t DEVADD2;                                /*  DEVADD2         */
    volatile uint16_t DEVADD3;                                /*  DEVADD3         */
    volatile uint16_t DEVADD4;                                /*  DEVADD4         */
    volatile uint16_t DEVADD5;                                /*  DEVADD5         */
    volatile uint16_t DEVADD6;                                /*  DEVADD6         */
    volatile uint16_t DEVADD7;                                /*  DEVADD7         */
    volatile uint16_t DEVADD8;                                /*  DEVADD8         */
    volatile uint16_t DEVADD9;                                /*  DEVADD9         */
    volatile uint16_t DEVADDA;                                /*  DEVADDA         */
    volatile uint8_t   dummy13[28];                            /*                  */
    volatile uint16_t SUSPMODE;                               /*  SUSPMODE        */
    volatile uint8_t   dummy14[92];                            /*                  */
/* start of struct st_usb20_from_dmfifob0 */
    volatile uint32_t  D0FIFOB0;                               /*  D0FIFOB0        */
    volatile uint32_t  D0FIFOB1;                               /*  D0FIFOB1        */
    volatile uint32_t  D0FIFOB2;                               /*  D0FIFOB2        */
    volatile uint32_t  D0FIFOB3;                               /*  D0FIFOB3        */
    volatile uint32_t  D0FIFOB4;                               /*  D0FIFOB4        */
    volatile uint32_t  D0FIFOB5;                               /*  D0FIFOB5        */
    volatile uint32_t  D0FIFOB6;                               /*  D0FIFOB6        */
    volatile uint32_t  D0FIFOB7;                               /*  D0FIFOB7        */
/* end of struct st_usb20_from_dmfifob0 */
/* start of struct st_usb20_from_dmfifob0 */
    volatile uint32_t  D1FIFOB0;                               /*  D1FIFOB0        */
    volatile uint32_t  D1FIFOB1;                               /*  D1FIFOB1        */
    volatile uint32_t  D1FIFOB2;                               /*  D1FIFOB2        */
    volatile uint32_t  D1FIFOB3;                               /*  D1FIFOB3        */
    volatile uint32_t  D1FIFOB4;                               /*  D1FIFOB4        */
    volatile uint32_t  D1FIFOB5;                               /*  D1FIFOB5        */
    volatile uint32_t  D1FIFOB6;                               /*  D1FIFOB6        */
    volatile uint32_t  D1FIFOB7;                               /*  D1FIFOB7        */
/* end of struct st_usb20_from_dmfifob0 */
};


struct st_usb20_from_d0fifosel
{
    volatile uint16_t D0FIFOSEL;                              /*  D0FIFOSEL       */
    volatile uint16_t D0FIFOCTR;                              /*  D0FIFOCTR       */
};


struct st_usb20_from_pipe1tre
{
    volatile uint16_t PIPE1TRE;                               /*  PIPE1TRE        */
    volatile uint16_t PIPE1TRN;                               /*  PIPE1TRN        */
};


struct st_usb20_from_dmfifob0
{

    volatile uint32_t  D0FIFOB0;                               /*  D0FIFOB0        */
    volatile uint32_t  D0FIFOB1;                               /*  D0FIFOB1        */
    volatile uint32_t  D0FIFOB2;                               /*  D0FIFOB2        */
    volatile uint32_t  D0FIFOB3;                               /*  D0FIFOB3        */
    volatile uint32_t  D0FIFOB4;                               /*  D0FIFOB4        */
    volatile uint32_t  D0FIFOB5;                               /*  D0FIFOB5        */
    volatile uint32_t  D0FIFOB6;                               /*  D0FIFOB6        */
    volatile uint32_t  D0FIFOB7;                               /*  D0FIFOB7        */
};






/* Start of channnel array defines of USB20 */

/* Channnel array defines of USB20 */
/*(Sample) value = USB20[ channel ]->SYSCFG0; */








/* Channnel array defines of USB20_FROM_D0FIFOB0 */
/*(Sample) value = USB20_FROM_D0FIFOB0[ channel ][ index ]->D0FIFOB0; */
#line 244 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/usb20_iodefine.h"




/* Channnel array defines of USB20_FROM_PIPE1ATRE */
/*(Sample) value = USB20_FROM_PIPE1ATRE[ channel ][ index ]->PIPE1TRE; */
#line 268 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/usb20_iodefine.h"




/* Channnel array defines of USB20_FROM_D0FIFOSEL */
/*(Sample) value = USB20_FROM_D0FIFOSEL[ channel ][ index ]->D0FIFOSEL; */
#line 286 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/usb20_iodefine.h"


/* End of channnel array defines of USB20 */


#line 545 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/usb20_iodefine.h"
/* <-SEC M1.10.1 */
#line 135 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/vdc5_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : vdc5_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/


/* ->QAC 0639 : Over 127 members (C90) */
/* ->SEC M1.10.1 : Not magic number */

struct st_vdc5
{                                                          /* VDC5             */
    volatile uint32_t  INP_UPDATE;                             /*  INP_UPDATE      */
    volatile uint32_t  INP_SEL_CNT;                            /*  INP_SEL_CNT     */
    volatile uint32_t  INP_EXT_SYNC_CNT;                       /*  INP_EXT_SYNC_CNT */
    volatile uint32_t  INP_VSYNC_PH_ADJ;                       /*  INP_VSYNC_PH_ADJ */
    volatile uint32_t  INP_DLY_ADJ;                            /*  INP_DLY_ADJ     */
    volatile uint8_t   dummy1[108];                            /*                  */
    volatile uint32_t  IMGCNT_UPDATE;                          /*  IMGCNT_UPDATE   */

    volatile uint32_t  IMGCNT_NR_CNT0;                         /*  IMGCNT_NR_CNT0  */
    volatile uint32_t  IMGCNT_NR_CNT1;                         /*  IMGCNT_NR_CNT1  */
    volatile uint8_t   dummy2[20];                             /*                  */
    volatile uint32_t  IMGCNT_MTX_MODE;                        /*  IMGCNT_MTX_MODE */
    volatile uint32_t  IMGCNT_MTX_YG_ADJ0;                     /*  IMGCNT_MTX_YG_ADJ0 */
    volatile uint32_t  IMGCNT_MTX_YG_ADJ1;                     /*  IMGCNT_MTX_YG_ADJ1 */
    volatile uint32_t  IMGCNT_MTX_CBB_ADJ0;                    /*  IMGCNT_MTX_CBB_ADJ0 */
    volatile uint32_t  IMGCNT_MTX_CBB_ADJ1;                    /*  IMGCNT_MTX_CBB_ADJ1 */
    volatile uint32_t  IMGCNT_MTX_CRR_ADJ0;                    /*  IMGCNT_MTX_CRR_ADJ0 */
    volatile uint32_t  IMGCNT_MTX_CRR_ADJ1;                    /*  IMGCNT_MTX_CRR_ADJ1 */
    volatile uint8_t   dummy3[4];                              /*                  */
    volatile uint32_t  IMGCNT_DRC_REG;                         /*  IMGCNT_DRC_REG  */
    volatile uint8_t   dummy4[60];                             /*                  */
/* start of struct st_vdc5_from_sc0_scl0_update */
    volatile uint32_t  SC0_SCL0_UPDATE;                        /*  SC0_SCL0_UPDATE */

    volatile uint32_t  SC0_SCL0_FRC1;                          /*  SC0_SCL0_FRC1   */
    volatile uint32_t  SC0_SCL0_FRC2;                          /*  SC0_SCL0_FRC2   */
    volatile uint32_t  SC0_SCL0_FRC3;                          /*  SC0_SCL0_FRC3   */
    volatile uint32_t  SC0_SCL0_FRC4;                          /*  SC0_SCL0_FRC4   */
    volatile uint32_t  SC0_SCL0_FRC5;                          /*  SC0_SCL0_FRC5   */
    volatile uint32_t  SC0_SCL0_FRC6;                          /*  SC0_SCL0_FRC6   */
    volatile uint32_t  SC0_SCL0_FRC7;                          /*  SC0_SCL0_FRC7   */
    volatile uint8_t   dummy5[4];                              /*                  */
    volatile uint32_t  SC0_SCL0_FRC9;                          /*  SC0_SCL0_FRC9   */
    volatile uint16_t SC0_SCL0_MON0;                          /*  SC0_SCL0_MON0   */
    volatile uint16_t SC0_SCL0_INT;                           /*  SC0_SCL0_INT    */

    volatile uint32_t  SC0_SCL0_DS1;                           /*  SC0_SCL0_DS1    */
    volatile uint32_t  SC0_SCL0_DS2;                           /*  SC0_SCL0_DS2    */
    volatile uint32_t  SC0_SCL0_DS3;                           /*  SC0_SCL0_DS3    */
    volatile uint32_t  SC0_SCL0_DS4;                           /*  SC0_SCL0_DS4    */
    volatile uint32_t  SC0_SCL0_DS5;                           /*  SC0_SCL0_DS5    */
    volatile uint32_t  SC0_SCL0_DS6;                           /*  SC0_SCL0_DS6    */
    volatile uint32_t  SC0_SCL0_DS7;                           /*  SC0_SCL0_DS7    */

    volatile uint32_t  SC0_SCL0_US1;                           /*  SC0_SCL0_US1    */
    volatile uint32_t  SC0_SCL0_US2;                           /*  SC0_SCL0_US2    */
    volatile uint32_t  SC0_SCL0_US3;                           /*  SC0_SCL0_US3    */
    volatile uint32_t  SC0_SCL0_US4;                           /*  SC0_SCL0_US4    */
    volatile uint32_t  SC0_SCL0_US5;                           /*  SC0_SCL0_US5    */
    volatile uint32_t  SC0_SCL0_US6;                           /*  SC0_SCL0_US6    */
    volatile uint32_t  SC0_SCL0_US7;                           /*  SC0_SCL0_US7    */
    volatile uint32_t  SC0_SCL0_US8;                           /*  SC0_SCL0_US8    */
    volatile uint8_t   dummy6[4];                              /*                  */
    volatile uint32_t  SC0_SCL0_OVR1;                          /*  SC0_SCL0_OVR1   */
    volatile uint8_t   dummy7[16];                             /*                  */
    volatile uint32_t  SC0_SCL1_UPDATE;                        /*  SC0_SCL1_UPDATE */
    volatile uint8_t   dummy8[4];                              /*                  */

    volatile uint32_t  SC0_SCL1_WR1;                           /*  SC0_SCL1_WR1    */
    volatile uint32_t  SC0_SCL1_WR2;                           /*  SC0_SCL1_WR2    */
    volatile uint32_t  SC0_SCL1_WR3;                           /*  SC0_SCL1_WR3    */
    volatile uint32_t  SC0_SCL1_WR4;                           /*  SC0_SCL1_WR4    */
    volatile uint8_t   dummy9[4];                              /*                  */
    volatile uint32_t  SC0_SCL1_WR5;                           /*  SC0_SCL1_WR5    */
    volatile uint32_t  SC0_SCL1_WR6;                           /*  SC0_SCL1_WR6    */
    volatile uint32_t  SC0_SCL1_WR7;                           /*  SC0_SCL1_WR7    */
    volatile uint32_t  SC0_SCL1_WR8;                           /*  SC0_SCL1_WR8    */
    volatile uint32_t  SC0_SCL1_WR9;                           /*  SC0_SCL1_WR9    */
    volatile uint32_t  SC0_SCL1_WR10;                          /*  SC0_SCL1_WR10   */
/* end of struct st_vdc5_from_sc0_scl0_update */
    volatile uint32_t  SC0_SCL1_WR11;                          /*  SC0_SCL1_WR11   */
    volatile uint32_t  SC0_SCL1_MON1;                          /*  SC0_SCL1_MON1   */
/* start of struct st_vdc5_from_sc0_scl1_pbuf0 */

    volatile uint32_t  SC0_SCL1_PBUF0;                         /*  SC0_SCL1_PBUF0  */
    volatile uint32_t  SC0_SCL1_PBUF1;                         /*  SC0_SCL1_PBUF1  */
    volatile uint32_t  SC0_SCL1_PBUF2;                         /*  SC0_SCL1_PBUF2  */
    volatile uint32_t  SC0_SCL1_PBUF3;                         /*  SC0_SCL1_PBUF3  */
    volatile uint32_t  SC0_SCL1_PBUF_FLD;                      /*  SC0_SCL1_PBUF_FLD */
    volatile uint32_t  SC0_SCL1_PBUF_CNT;                      /*  SC0_SCL1_PBUF_CNT */
/* end of struct st_vdc5_from_sc0_scl1_pbuf0 */
    volatile uint8_t   dummy10[44];                            /*                  */
/* start of struct st_vdc5_from_gr0_update */
    volatile uint32_t  GR0_UPDATE;                             /*  GR0_UPDATE      */
    volatile uint32_t  GR0_FLM_RD;                             /*  GR0_FLM_RD      */

    volatile uint32_t  GR0_FLM1;                               /*  GR0_FLM1        */
    volatile uint32_t  GR0_FLM2;                               /*  GR0_FLM2        */
    volatile uint32_t  GR0_FLM3;                               /*  GR0_FLM3        */
    volatile uint32_t  GR0_FLM4;                               /*  GR0_FLM4        */
    volatile uint32_t  GR0_FLM5;                               /*  GR0_FLM5        */
    volatile uint32_t  GR0_FLM6;                               /*  GR0_FLM6        */

    volatile uint32_t  GR0_AB1;                                /*  GR0_AB1         */
    volatile uint32_t  GR0_AB2;                                /*  GR0_AB2         */
    volatile uint32_t  GR0_AB3;                                /*  GR0_AB3         */
/* end of struct st_vdc5_from_gr0_update */
    volatile uint8_t   dummy11[12];                            /*                  */
/* start of struct st_vdc5_from_gr0_ab7 */
    volatile uint32_t  GR0_AB7;                                /*  GR0_AB7         */
    volatile uint32_t  GR0_AB8;                                /*  GR0_AB8         */
    volatile uint32_t  GR0_AB9;                                /*  GR0_AB9         */
    volatile uint32_t  GR0_AB10;                               /*  GR0_AB10        */
    volatile uint32_t  GR0_AB11;                               /*  GR0_AB11        */
    volatile uint32_t  GR0_BASE;                               /*  GR0_BASE        */
/* end of struct st_vdc5_from_gr0_ab7 */
    volatile uint32_t  GR0_CLUT;                               /*  GR0_CLUT        */
    volatile uint8_t   dummy12[44];                            /*                  */
/* start of struct st_vdc5_from_adj0_update */
    volatile uint32_t  ADJ0_UPDATE;                            /*  ADJ0_UPDATE     */
    volatile uint32_t  ADJ0_BKSTR_SET;                         /*  ADJ0_BKSTR_SET  */

    volatile uint32_t  ADJ0_ENH_TIM1;                          /*  ADJ0_ENH_TIM1   */
    volatile uint32_t  ADJ0_ENH_TIM2;                          /*  ADJ0_ENH_TIM2   */
    volatile uint32_t  ADJ0_ENH_TIM3;                          /*  ADJ0_ENH_TIM3   */

    volatile uint32_t  ADJ0_ENH_SHP1;                          /*  ADJ0_ENH_SHP1   */
    volatile uint32_t  ADJ0_ENH_SHP2;                          /*  ADJ0_ENH_SHP2   */
    volatile uint32_t  ADJ0_ENH_SHP3;                          /*  ADJ0_ENH_SHP3   */
    volatile uint32_t  ADJ0_ENH_SHP4;                          /*  ADJ0_ENH_SHP4   */
    volatile uint32_t  ADJ0_ENH_SHP5;                          /*  ADJ0_ENH_SHP5   */
    volatile uint32_t  ADJ0_ENH_SHP6;                          /*  ADJ0_ENH_SHP6   */

    volatile uint32_t  ADJ0_ENH_LTI1;                          /*  ADJ0_ENH_LTI1   */
    volatile uint32_t  ADJ0_ENH_LTI2;                          /*  ADJ0_ENH_LTI2   */
    volatile uint32_t  ADJ0_MTX_MODE;                          /*  ADJ0_MTX_MODE   */
    volatile uint32_t  ADJ0_MTX_YG_ADJ0;                       /*  ADJ0_MTX_YG_ADJ0 */
    volatile uint32_t  ADJ0_MTX_YG_ADJ1;                       /*  ADJ0_MTX_YG_ADJ1 */
    volatile uint32_t  ADJ0_MTX_CBB_ADJ0;                      /*  ADJ0_MTX_CBB_ADJ0 */
    volatile uint32_t  ADJ0_MTX_CBB_ADJ1;                      /*  ADJ0_MTX_CBB_ADJ1 */
    volatile uint32_t  ADJ0_MTX_CRR_ADJ0;                      /*  ADJ0_MTX_CRR_ADJ0 */
    volatile uint32_t  ADJ0_MTX_CRR_ADJ1;                      /*  ADJ0_MTX_CRR_ADJ1 */
/* end of struct st_vdc5_from_adj0_update */
    volatile uint8_t   dummy13[48];                            /*                  */
/* start of struct st_vdc5_from_gr0_update */
    volatile uint32_t  GR2_UPDATE;                             /*  GR2_UPDATE      */
    volatile uint32_t  GR2_FLM_RD;                             /*  GR2_FLM_RD      */

    volatile uint32_t  GR2_FLM1;                               /*  GR2_FLM1        */
    volatile uint32_t  GR2_FLM2;                               /*  GR2_FLM2        */
    volatile uint32_t  GR2_FLM3;                               /*  GR2_FLM3        */
    volatile uint32_t  GR2_FLM4;                               /*  GR2_FLM4        */
    volatile uint32_t  GR2_FLM5;                               /*  GR2_FLM5        */
    volatile uint32_t  GR2_FLM6;                               /*  GR2_FLM6        */

    volatile uint32_t  GR2_AB1;                                /*  GR2_AB1         */
    volatile uint32_t  GR2_AB2;                                /*  GR2_AB2         */
    volatile uint32_t  GR2_AB3;                                /*  GR2_AB3         */
/* end of struct st_vdc5_from_gr0_update */
    volatile uint32_t  GR2_AB4;                                /*  GR2_AB4         */
    volatile uint32_t  GR2_AB5;                                /*  GR2_AB5         */
    volatile uint32_t  GR2_AB6;                                /*  GR2_AB6         */
/* start of struct st_vdc5_from_gr0_ab7 */
    volatile uint32_t  GR2_AB7;                                /*  GR2_AB7         */
    volatile uint32_t  GR2_AB8;                                /*  GR2_AB8         */
    volatile uint32_t  GR2_AB9;                                /*  GR2_AB9         */
    volatile uint32_t  GR2_AB10;                               /*  GR2_AB10        */
    volatile uint32_t  GR2_AB11;                               /*  GR2_AB11        */
    volatile uint32_t  GR2_BASE;                               /*  GR2_BASE        */
/* end of struct st_vdc5_from_gr0_ab7 */
    volatile uint32_t  GR2_CLUT;                               /*  GR2_CLUT        */
    volatile uint32_t  GR2_MON;                                /*  GR2_MON         */
    volatile uint8_t   dummy14[40];                            /*                  */
/* start of struct st_vdc5_from_gr0_update */
    volatile uint32_t  GR3_UPDATE;                             /*  GR3_UPDATE      */
    volatile uint32_t  GR3_FLM_RD;                             /*  GR3_FLM_RD      */

    volatile uint32_t  GR3_FLM1;                               /*  GR3_FLM1        */
    volatile uint32_t  GR3_FLM2;                               /*  GR3_FLM2        */
    volatile uint32_t  GR3_FLM3;                               /*  GR3_FLM3        */
    volatile uint32_t  GR3_FLM4;                               /*  GR3_FLM4        */
    volatile uint32_t  GR3_FLM5;                               /*  GR3_FLM5        */
    volatile uint32_t  GR3_FLM6;                               /*  GR3_FLM6        */

    volatile uint32_t  GR3_AB1;                                /*  GR3_AB1         */
    volatile uint32_t  GR3_AB2;                                /*  GR3_AB2         */
    volatile uint32_t  GR3_AB3;                                /*  GR3_AB3         */
/* end of struct st_vdc5_from_gr0_update */
    volatile uint32_t  GR3_AB4;                                /*  GR3_AB4         */
    volatile uint32_t  GR3_AB5;                                /*  GR3_AB5         */
    volatile uint32_t  GR3_AB6;                                /*  GR3_AB6         */
/* start of struct st_vdc5_from_gr0_ab7 */
    volatile uint32_t  GR3_AB7;                                /*  GR3_AB7         */
    volatile uint32_t  GR3_AB8;                                /*  GR3_AB8         */
    volatile uint32_t  GR3_AB9;                                /*  GR3_AB9         */
    volatile uint32_t  GR3_AB10;                               /*  GR3_AB10        */
    volatile uint32_t  GR3_AB11;                               /*  GR3_AB11        */
    volatile uint32_t  GR3_BASE;                               /*  GR3_BASE        */
/* end of struct st_vdc5_from_gr0_ab7 */
    volatile uint32_t  GR3_CLUT_INT;                           /*  GR3_CLUT_INT    */
    volatile uint32_t  GR3_MON;                                /*  GR3_MON         */
    volatile uint8_t   dummy15[40];                            /*                  */
    volatile uint32_t  GAM_G_UPDATE;                           /*  GAM_G_UPDATE    */
    volatile uint32_t  GAM_SW;                                 /*  GAM_SW          */

    volatile uint32_t  GAM_G_LUT1;                             /*  GAM_G_LUT1      */
    volatile uint32_t  GAM_G_LUT2;                             /*  GAM_G_LUT2      */
    volatile uint32_t  GAM_G_LUT3;                             /*  GAM_G_LUT3      */
    volatile uint32_t  GAM_G_LUT4;                             /*  GAM_G_LUT4      */
    volatile uint32_t  GAM_G_LUT5;                             /*  GAM_G_LUT5      */
    volatile uint32_t  GAM_G_LUT6;                             /*  GAM_G_LUT6      */
    volatile uint32_t  GAM_G_LUT7;                             /*  GAM_G_LUT7      */
    volatile uint32_t  GAM_G_LUT8;                             /*  GAM_G_LUT8      */
    volatile uint32_t  GAM_G_LUT9;                             /*  GAM_G_LUT9      */
    volatile uint32_t  GAM_G_LUT10;                            /*  GAM_G_LUT10     */
    volatile uint32_t  GAM_G_LUT11;                            /*  GAM_G_LUT11     */
    volatile uint32_t  GAM_G_LUT12;                            /*  GAM_G_LUT12     */
    volatile uint32_t  GAM_G_LUT13;                            /*  GAM_G_LUT13     */
    volatile uint32_t  GAM_G_LUT14;                            /*  GAM_G_LUT14     */
    volatile uint32_t  GAM_G_LUT15;                            /*  GAM_G_LUT15     */
    volatile uint32_t  GAM_G_LUT16;                            /*  GAM_G_LUT16     */

    volatile uint32_t  GAM_G_AREA1;                            /*  GAM_G_AREA1     */
    volatile uint32_t  GAM_G_AREA2;                            /*  GAM_G_AREA2     */
    volatile uint32_t  GAM_G_AREA3;                            /*  GAM_G_AREA3     */
    volatile uint32_t  GAM_G_AREA4;                            /*  GAM_G_AREA4     */
    volatile uint32_t  GAM_G_AREA5;                            /*  GAM_G_AREA5     */
    volatile uint32_t  GAM_G_AREA6;                            /*  GAM_G_AREA6     */
    volatile uint32_t  GAM_G_AREA7;                            /*  GAM_G_AREA7     */
    volatile uint32_t  GAM_G_AREA8;                            /*  GAM_G_AREA8     */
    volatile uint8_t   dummy16[24];                            /*                  */
    volatile uint32_t  GAM_B_UPDATE;                           /*  GAM_B_UPDATE    */
    volatile uint8_t   dummy17[4];                             /*                  */

    volatile uint32_t  GAM_B_LUT1;                             /*  GAM_B_LUT1      */
    volatile uint32_t  GAM_B_LUT2;                             /*  GAM_B_LUT2      */
    volatile uint32_t  GAM_B_LUT3;                             /*  GAM_B_LUT3      */
    volatile uint32_t  GAM_B_LUT4;                             /*  GAM_B_LUT4      */
    volatile uint32_t  GAM_B_LUT5;                             /*  GAM_B_LUT5      */
    volatile uint32_t  GAM_B_LUT6;                             /*  GAM_B_LUT6      */
    volatile uint32_t  GAM_B_LUT7;                             /*  GAM_B_LUT7      */
    volatile uint32_t  GAM_B_LUT8;                             /*  GAM_B_LUT8      */
    volatile uint32_t  GAM_B_LUT9;                             /*  GAM_B_LUT9      */
    volatile uint32_t  GAM_B_LUT10;                            /*  GAM_B_LUT10     */
    volatile uint32_t  GAM_B_LUT11;                            /*  GAM_B_LUT11     */
    volatile uint32_t  GAM_B_LUT12;                            /*  GAM_B_LUT12     */
    volatile uint32_t  GAM_B_LUT13;                            /*  GAM_B_LUT13     */
    volatile uint32_t  GAM_B_LUT14;                            /*  GAM_B_LUT14     */
    volatile uint32_t  GAM_B_LUT15;                            /*  GAM_B_LUT15     */
    volatile uint32_t  GAM_B_LUT16;                            /*  GAM_B_LUT16     */

    volatile uint32_t  GAM_B_AREA1;                            /*  GAM_B_AREA1     */
    volatile uint32_t  GAM_B_AREA2;                            /*  GAM_B_AREA2     */
    volatile uint32_t  GAM_B_AREA3;                            /*  GAM_B_AREA3     */
    volatile uint32_t  GAM_B_AREA4;                            /*  GAM_B_AREA4     */
    volatile uint32_t  GAM_B_AREA5;                            /*  GAM_B_AREA5     */
    volatile uint32_t  GAM_B_AREA6;                            /*  GAM_B_AREA6     */
    volatile uint32_t  GAM_B_AREA7;                            /*  GAM_B_AREA7     */
    volatile uint32_t  GAM_B_AREA8;                            /*  GAM_B_AREA8     */
    volatile uint8_t   dummy18[24];                            /*                  */
    volatile uint32_t  GAM_R_UPDATE;                           /*  GAM_R_UPDATE    */
    volatile uint8_t   dummy19[4];                             /*                  */

    volatile uint32_t  GAM_R_LUT1;                             /*  GAM_R_LUT1      */
    volatile uint32_t  GAM_R_LUT2;                             /*  GAM_R_LUT2      */
    volatile uint32_t  GAM_R_LUT3;                             /*  GAM_R_LUT3      */
    volatile uint32_t  GAM_R_LUT4;                             /*  GAM_R_LUT4      */
    volatile uint32_t  GAM_R_LUT5;                             /*  GAM_R_LUT5      */
    volatile uint32_t  GAM_R_LUT6;                             /*  GAM_R_LUT6      */
    volatile uint32_t  GAM_R_LUT7;                             /*  GAM_R_LUT7      */
    volatile uint32_t  GAM_R_LUT8;                             /*  GAM_R_LUT8      */
    volatile uint32_t  GAM_R_LUT9;                             /*  GAM_R_LUT9      */
    volatile uint32_t  GAM_R_LUT10;                            /*  GAM_R_LUT10     */
    volatile uint32_t  GAM_R_LUT11;                            /*  GAM_R_LUT11     */
    volatile uint32_t  GAM_R_LUT12;                            /*  GAM_R_LUT12     */
    volatile uint32_t  GAM_R_LUT13;                            /*  GAM_R_LUT13     */
    volatile uint32_t  GAM_R_LUT14;                            /*  GAM_R_LUT14     */
    volatile uint32_t  GAM_R_LUT15;                            /*  GAM_R_LUT15     */
    volatile uint32_t  GAM_R_LUT16;                            /*  GAM_R_LUT16     */

    volatile uint32_t  GAM_R_AREA1;                            /*  GAM_R_AREA1     */
    volatile uint32_t  GAM_R_AREA2;                            /*  GAM_R_AREA2     */
    volatile uint32_t  GAM_R_AREA3;                            /*  GAM_R_AREA3     */
    volatile uint32_t  GAM_R_AREA4;                            /*  GAM_R_AREA4     */
    volatile uint32_t  GAM_R_AREA5;                            /*  GAM_R_AREA5     */
    volatile uint32_t  GAM_R_AREA6;                            /*  GAM_R_AREA6     */
    volatile uint32_t  GAM_R_AREA7;                            /*  GAM_R_AREA7     */
    volatile uint32_t  GAM_R_AREA8;                            /*  GAM_R_AREA8     */
    volatile uint8_t   dummy20[24];                            /*                  */
    volatile uint32_t  TCON_UPDATE;                            /*  TCON_UPDATE     */
    volatile uint32_t  TCON_TIM;                               /*  TCON_TIM        */

    volatile uint32_t  TCON_TIM_STVA1;                         /*  TCON_TIM_STVA1  */
    volatile uint32_t  TCON_TIM_STVA2;                         /*  TCON_TIM_STVA2  */

    volatile uint32_t  TCON_TIM_STVB1;                         /*  TCON_TIM_STVB1  */
    volatile uint32_t  TCON_TIM_STVB2;                         /*  TCON_TIM_STVB2  */

    volatile uint32_t  TCON_TIM_STH1;                          /*  TCON_TIM_STH1   */
    volatile uint32_t  TCON_TIM_STH2;                          /*  TCON_TIM_STH2   */

    volatile uint32_t  TCON_TIM_STB1;                          /*  TCON_TIM_STB1   */
    volatile uint32_t  TCON_TIM_STB2;                          /*  TCON_TIM_STB2   */

    volatile uint32_t  TCON_TIM_CPV1;                          /*  TCON_TIM_CPV1   */
    volatile uint32_t  TCON_TIM_CPV2;                          /*  TCON_TIM_CPV2   */

    volatile uint32_t  TCON_TIM_POLA1;                         /*  TCON_TIM_POLA1  */
    volatile uint32_t  TCON_TIM_POLA2;                         /*  TCON_TIM_POLA2  */

    volatile uint32_t  TCON_TIM_POLB1;                         /*  TCON_TIM_POLB1  */
    volatile uint32_t  TCON_TIM_POLB2;                         /*  TCON_TIM_POLB2  */
    volatile uint32_t  TCON_TIM_DE;                            /*  TCON_TIM_DE     */
    volatile uint8_t   dummy21[60];                            /*                  */
    volatile uint32_t  OUT_UPDATE;                             /*  OUT_UPDATE      */
    volatile uint32_t  OUT_SET;                                /*  OUT_SET         */

    volatile uint32_t  OUT_BRIGHT1;                            /*  OUT_BRIGHT1     */
    volatile uint32_t  OUT_BRIGHT2;                            /*  OUT_BRIGHT2     */
    volatile uint32_t  OUT_CONTRAST;                           /*  OUT_CONTRAST    */
    volatile uint32_t  OUT_PDTHA;                              /*  OUT_PDTHA       */
    volatile uint8_t   dummy22[12];                            /*                  */
    volatile uint32_t  OUT_CLK_PHASE;                          /*  OUT_CLK_PHASE   */
    volatile uint8_t   dummy23[88];                            /*                  */

    volatile uint32_t  SYSCNT_INT1;                            /*  SYSCNT_INT1     */
    volatile uint32_t  SYSCNT_INT2;                            /*  SYSCNT_INT2     */
    volatile uint32_t  SYSCNT_INT3;                            /*  SYSCNT_INT3     */
    volatile uint32_t  SYSCNT_INT4;                            /*  SYSCNT_INT4     */
    volatile uint32_t  SYSCNT_INT5;                            /*  SYSCNT_INT5     */
    volatile uint32_t  SYSCNT_INT6;                            /*  SYSCNT_INT6     */
    volatile uint16_t SYSCNT_PANEL_CLK;                       /*  SYSCNT_PANEL_CLK */
    volatile uint16_t SYSCNT_CLUT;                            /*  SYSCNT_CLUT     */
    volatile uint8_t   dummy24[356];                           /*                  */
/* start of struct st_vdc5_from_sc0_scl0_update */
    volatile uint32_t  SC1_SCL0_UPDATE;                        /*  SC1_SCL0_UPDATE */

    volatile uint32_t  SC1_SCL0_FRC1;                          /*  SC1_SCL0_FRC1   */
    volatile uint32_t  SC1_SCL0_FRC2;                          /*  SC1_SCL0_FRC2   */
    volatile uint32_t  SC1_SCL0_FRC3;                          /*  SC1_SCL0_FRC3   */
    volatile uint32_t  SC1_SCL0_FRC4;                          /*  SC1_SCL0_FRC4   */
    volatile uint32_t  SC1_SCL0_FRC5;                          /*  SC1_SCL0_FRC5   */
    volatile uint32_t  SC1_SCL0_FRC6;                          /*  SC1_SCL0_FRC6   */
    volatile uint32_t  SC1_SCL0_FRC7;                          /*  SC1_SCL0_FRC7   */
    volatile uint8_t   dummy25[4];                             /*                  */
    volatile uint32_t  SC1_SCL0_FRC9;                          /*  SC1_SCL0_FRC9   */
    volatile uint16_t SC1_SCL0_MON0;                          /*  SC1_SCL0_MON0   */
    volatile uint16_t SC1_SCL0_INT;                           /*  SC1_SCL0_INT    */

    volatile uint32_t  SC1_SCL0_DS1;                           /*  SC1_SCL0_DS1    */
    volatile uint32_t  SC1_SCL0_DS2;                           /*  SC1_SCL0_DS2    */
    volatile uint32_t  SC1_SCL0_DS3;                           /*  SC1_SCL0_DS3    */
    volatile uint32_t  SC1_SCL0_DS4;                           /*  SC1_SCL0_DS4    */
    volatile uint32_t  SC1_SCL0_DS5;                           /*  SC1_SCL0_DS5    */
    volatile uint32_t  SC1_SCL0_DS6;                           /*  SC1_SCL0_DS6    */
    volatile uint32_t  SC1_SCL0_DS7;                           /*  SC1_SCL0_DS7    */

    volatile uint32_t  SC1_SCL0_US1;                           /*  SC1_SCL0_US1    */
    volatile uint32_t  SC1_SCL0_US2;                           /*  SC1_SCL0_US2    */
    volatile uint32_t  SC1_SCL0_US3;                           /*  SC1_SCL0_US3    */
    volatile uint32_t  SC1_SCL0_US4;                           /*  SC1_SCL0_US4    */
    volatile uint32_t  SC1_SCL0_US5;                           /*  SC1_SCL0_US5    */
    volatile uint32_t  SC1_SCL0_US6;                           /*  SC1_SCL0_US6    */
    volatile uint32_t  SC1_SCL0_US7;                           /*  SC1_SCL0_US7    */
    volatile uint32_t  SC1_SCL0_US8;                           /*  SC1_SCL0_US8    */
    volatile uint8_t   dummy26[4];                             /*                  */
    volatile uint32_t  SC1_SCL0_OVR1;                          /*  SC1_SCL0_OVR1   */
    volatile uint8_t   dummy27[16];                            /*                  */
    volatile uint32_t  SC1_SCL1_UPDATE;                        /*  SC1_SCL1_UPDATE */
    volatile uint8_t   dummy28[4];                             /*                  */

    volatile uint32_t  SC1_SCL1_WR1;                           /*  SC1_SCL1_WR1    */
    volatile uint32_t  SC1_SCL1_WR2;                           /*  SC1_SCL1_WR2    */
    volatile uint32_t  SC1_SCL1_WR3;                           /*  SC1_SCL1_WR3    */
    volatile uint32_t  SC1_SCL1_WR4;                           /*  SC1_SCL1_WR4    */
    volatile uint8_t   dummy29[4];                             /*                  */
    volatile uint32_t  SC1_SCL1_WR5;                           /*  SC1_SCL1_WR5    */
    volatile uint32_t  SC1_SCL1_WR6;                           /*  SC1_SCL1_WR6    */
    volatile uint32_t  SC1_SCL1_WR7;                           /*  SC1_SCL1_WR7    */
    volatile uint32_t  SC1_SCL1_WR8;                           /*  SC1_SCL1_WR8    */
    volatile uint32_t  SC1_SCL1_WR9;                           /*  SC1_SCL1_WR9    */
    volatile uint32_t  SC1_SCL1_WR10;                          /*  SC1_SCL1_WR10   */
/* end of struct st_vdc5_from_sc0_scl0_update */
    volatile uint32_t  SC1_SCL1_WR11;                          /*  SC1_SCL1_WR11   */
    volatile uint32_t  SC1_SCL1_MON1;                          /*  SC1_SCL1_MON1   */
/* start of struct st_vdc5_from_sc0_scl1_pbuf0 */

    volatile uint32_t  SC1_SCL1_PBUF0;                         /*  SC1_SCL1_PBUF0  */
    volatile uint32_t  SC1_SCL1_PBUF1;                         /*  SC1_SCL1_PBUF1  */
    volatile uint32_t  SC1_SCL1_PBUF2;                         /*  SC1_SCL1_PBUF2  */
    volatile uint32_t  SC1_SCL1_PBUF3;                         /*  SC1_SCL1_PBUF3  */
    volatile uint32_t  SC1_SCL1_PBUF_FLD;                      /*  SC1_SCL1_PBUF_FLD */
    volatile uint32_t  SC1_SCL1_PBUF_CNT;                      /*  SC1_SCL1_PBUF_CNT */
/* end of struct st_vdc5_from_sc0_scl1_pbuf0 */
    volatile uint8_t   dummy30[44];                            /*                  */
/* start of struct st_vdc5_from_gr0_update */
    volatile uint32_t  GR1_UPDATE;                             /*  GR1_UPDATE      */
    volatile uint32_t  GR1_FLM_RD;                             /*  GR1_FLM_RD      */

    volatile uint32_t  GR1_FLM1;                               /*  GR1_FLM1        */
    volatile uint32_t  GR1_FLM2;                               /*  GR1_FLM2        */
    volatile uint32_t  GR1_FLM3;                               /*  GR1_FLM3        */
    volatile uint32_t  GR1_FLM4;                               /*  GR1_FLM4        */
    volatile uint32_t  GR1_FLM5;                               /*  GR1_FLM5        */
    volatile uint32_t  GR1_FLM6;                               /*  GR1_FLM6        */

    volatile uint32_t  GR1_AB1;                                /*  GR1_AB1         */
    volatile uint32_t  GR1_AB2;                                /*  GR1_AB2         */
    volatile uint32_t  GR1_AB3;                                /*  GR1_AB3         */
/* end of struct st_vdc5_from_gr0_update */
    volatile uint32_t  GR1_AB4;                                /*  GR1_AB4         */
    volatile uint32_t  GR1_AB5;                                /*  GR1_AB5         */
    volatile uint32_t  GR1_AB6;                                /*  GR1_AB6         */
/* start of struct st_vdc5_from_gr0_ab7 */
    volatile uint32_t  GR1_AB7;                                /*  GR1_AB7         */
    volatile uint32_t  GR1_AB8;                                /*  GR1_AB8         */
    volatile uint32_t  GR1_AB9;                                /*  GR1_AB9         */
    volatile uint32_t  GR1_AB10;                               /*  GR1_AB10        */
    volatile uint32_t  GR1_AB11;                               /*  GR1_AB11        */
    volatile uint32_t  GR1_BASE;                               /*  GR1_BASE        */
/* end of struct st_vdc5_from_gr0_ab7 */
    volatile uint32_t  GR1_CLUT;                               /*  GR1_CLUT        */
    volatile uint32_t  GR1_MON;                                /*  GR1_MON         */
    volatile uint8_t   dummy31[40];                            /*                  */
/* start of struct st_vdc5_from_adj0_update */
    volatile uint32_t  ADJ1_UPDATE;                            /*  ADJ1_UPDATE     */
    volatile uint32_t  ADJ1_BKSTR_SET;                         /*  ADJ1_BKSTR_SET  */

    volatile uint32_t  ADJ1_ENH_TIM1;                          /*  ADJ1_ENH_TIM1   */
    volatile uint32_t  ADJ1_ENH_TIM2;                          /*  ADJ1_ENH_TIM2   */
    volatile uint32_t  ADJ1_ENH_TIM3;                          /*  ADJ1_ENH_TIM3   */

    volatile uint32_t  ADJ1_ENH_SHP1;                          /*  ADJ1_ENH_SHP1   */
    volatile uint32_t  ADJ1_ENH_SHP2;                          /*  ADJ1_ENH_SHP2   */
    volatile uint32_t  ADJ1_ENH_SHP3;                          /*  ADJ1_ENH_SHP3   */
    volatile uint32_t  ADJ1_ENH_SHP4;                          /*  ADJ1_ENH_SHP4   */
    volatile uint32_t  ADJ1_ENH_SHP5;                          /*  ADJ1_ENH_SHP5   */
    volatile uint32_t  ADJ1_ENH_SHP6;                          /*  ADJ1_ENH_SHP6   */

    volatile uint32_t  ADJ1_ENH_LTI1;                          /*  ADJ1_ENH_LTI1   */
    volatile uint32_t  ADJ1_ENH_LTI2;                          /*  ADJ1_ENH_LTI2   */
    volatile uint32_t  ADJ1_MTX_MODE;                          /*  ADJ1_MTX_MODE   */
    volatile uint32_t  ADJ1_MTX_YG_ADJ0;                       /*  ADJ1_MTX_YG_ADJ0 */
    volatile uint32_t  ADJ1_MTX_YG_ADJ1;                       /*  ADJ1_MTX_YG_ADJ1 */
    volatile uint32_t  ADJ1_MTX_CBB_ADJ0;                      /*  ADJ1_MTX_CBB_ADJ0 */
    volatile uint32_t  ADJ1_MTX_CBB_ADJ1;                      /*  ADJ1_MTX_CBB_ADJ1 */
    volatile uint32_t  ADJ1_MTX_CRR_ADJ0;                      /*  ADJ1_MTX_CRR_ADJ0 */
    volatile uint32_t  ADJ1_MTX_CRR_ADJ1;                      /*  ADJ1_MTX_CRR_ADJ1 */
/* end of struct st_vdc5_from_adj0_update */
    volatile uint8_t   dummy32[48];                            /*                  */
    volatile uint32_t  GR_VIN_UPDATE;                          /*  GR_VIN_UPDATE   */
    volatile uint8_t   dummy33[28];                            /*                  */

    volatile uint32_t  GR_VIN_AB1;                             /*  GR_VIN_AB1      */
    volatile uint32_t  GR_VIN_AB2;                             /*  GR_VIN_AB2      */
    volatile uint32_t  GR_VIN_AB3;                             /*  GR_VIN_AB3      */
    volatile uint32_t  GR_VIN_AB4;                             /*  GR_VIN_AB4      */
    volatile uint32_t  GR_VIN_AB5;                             /*  GR_VIN_AB5      */
    volatile uint32_t  GR_VIN_AB6;                             /*  GR_VIN_AB6      */
    volatile uint32_t  GR_VIN_AB7;                             /*  GR_VIN_AB7      */
    volatile uint8_t   dummy34[16];                            /*                  */
    volatile uint32_t  GR_VIN_BASE;                            /*  GR_VIN_BASE     */
    volatile uint8_t   dummy35[4];                             /*                  */
    volatile uint32_t  GR_VIN_MON;                             /*  GR_VIN_MON      */
    volatile uint8_t   dummy36[40];                            /*                  */
    volatile uint32_t  OIR_SCL0_UPDATE;                        /*  OIR_SCL0_UPDATE */

    volatile uint32_t  OIR_SCL0_FRC1;                          /*  OIR_SCL0_FRC1   */
    volatile uint32_t  OIR_SCL0_FRC2;                          /*  OIR_SCL0_FRC2   */
    volatile uint32_t  OIR_SCL0_FRC3;                          /*  OIR_SCL0_FRC3   */
    volatile uint32_t  OIR_SCL0_FRC4;                          /*  OIR_SCL0_FRC4   */
    volatile uint32_t  OIR_SCL0_FRC5;                          /*  OIR_SCL0_FRC5   */
    volatile uint32_t  OIR_SCL0_FRC6;                          /*  OIR_SCL0_FRC6   */
    volatile uint32_t  OIR_SCL0_FRC7;                          /*  OIR_SCL0_FRC7   */
    volatile uint8_t   dummy37[12];                            /*                  */

    volatile uint32_t  OIR_SCL0_DS1;                           /*  OIR_SCL0_DS1    */
    volatile uint32_t  OIR_SCL0_DS2;                           /*  OIR_SCL0_DS2    */
    volatile uint32_t  OIR_SCL0_DS3;                           /*  OIR_SCL0_DS3    */
    volatile uint8_t   dummy38[12];                            /*                  */
    volatile uint32_t  OIR_SCL0_DS7;                           /*  OIR_SCL0_DS7    */
    volatile uint32_t  OIR_SCL0_US1;                           /*  OIR_SCL0_US1    */
    volatile uint32_t  OIR_SCL0_US2;                           /*  OIR_SCL0_US2    */
    volatile uint32_t  OIR_SCL0_US3;                           /*  OIR_SCL0_US3    */
    volatile uint8_t   dummy39[16];                            /*                  */
    volatile uint32_t  OIR_SCL0_US8;                           /*  OIR_SCL0_US8    */
    volatile uint8_t   dummy40[4];                             /*                  */
    volatile uint32_t  OIR_SCL0_OVR1;                          /*  OIR_SCL0_OVR1   */
    volatile uint8_t   dummy41[16];                            /*                  */
    volatile uint32_t  OIR_SCL1_UPDATE;                        /*  OIR_SCL1_UPDATE */
    volatile uint8_t   dummy42[4];                             /*                  */

    volatile uint32_t  OIR_SCL1_WR1;                           /*  OIR_SCL1_WR1    */
    volatile uint32_t  OIR_SCL1_WR2;                           /*  OIR_SCL1_WR2    */
    volatile uint32_t  OIR_SCL1_WR3;                           /*  OIR_SCL1_WR3    */
    volatile uint32_t  OIR_SCL1_WR4;                           /*  OIR_SCL1_WR4    */
    volatile uint8_t   dummy43[4];                             /*                  */
    volatile uint32_t  OIR_SCL1_WR5;                           /*  OIR_SCL1_WR5    */
    volatile uint32_t  OIR_SCL1_WR6;                           /*  OIR_SCL1_WR6    */
    volatile uint32_t  OIR_SCL1_WR7;                           /*  OIR_SCL1_WR7    */
    volatile uint8_t   dummy44[88];                            /*                  */
    volatile uint32_t  GR_OIR_UPDATE;                          /*  GR_OIR_UPDATE   */
    volatile uint32_t  GR_OIR_FLM_RD;                          /*  GR_OIR_FLM_RD   */

    volatile uint32_t  GR_OIR_FLM1;                            /*  GR_OIR_FLM1     */
    volatile uint32_t  GR_OIR_FLM2;                            /*  GR_OIR_FLM2     */
    volatile uint32_t  GR_OIR_FLM3;                            /*  GR_OIR_FLM3     */
    volatile uint32_t  GR_OIR_FLM4;                            /*  GR_OIR_FLM4     */
    volatile uint32_t  GR_OIR_FLM5;                            /*  GR_OIR_FLM5     */
    volatile uint32_t  GR_OIR_FLM6;                            /*  GR_OIR_FLM6     */

    volatile uint32_t  GR_OIR_AB1;                             /*  GR_OIR_AB1      */
    volatile uint32_t  GR_OIR_AB2;                             /*  GR_OIR_AB2      */
    volatile uint32_t  GR_OIR_AB3;                             /*  GR_OIR_AB3      */
    volatile uint8_t   dummy45[12];                            /*                  */
    volatile uint32_t  GR_OIR_AB7;                             /*  GR_OIR_AB7      */
    volatile uint32_t  GR_OIR_AB8;                             /*  GR_OIR_AB8      */
    volatile uint32_t  GR_OIR_AB9;                             /*  GR_OIR_AB9      */
    volatile uint32_t  GR_OIR_AB10;                            /*  GR_OIR_AB10     */
    volatile uint32_t  GR_OIR_AB11;                            /*  GR_OIR_AB11     */
    volatile uint32_t  GR_OIR_BASE;                            /*  GR_OIR_BASE     */
    volatile uint32_t  GR_OIR_CLUT;                            /*  GR_OIR_CLUT     */
    volatile uint32_t  GR_OIR_MON;                             /*  GR_OIR_MON      */
};


struct st_vdc5_from_gr0_update
{
    volatile uint32_t  GR0_UPDATE;                             /*  GR0_UPDATE      */
    volatile uint32_t  GR0_FLM_RD;                             /*  GR0_FLM_RD      */
    volatile uint32_t  GR0_FLM1;                               /*  GR0_FLM1        */
    volatile uint32_t  GR0_FLM2;                               /*  GR0_FLM2        */
    volatile uint32_t  GR0_FLM3;                               /*  GR0_FLM3        */
    volatile uint32_t  GR0_FLM4;                               /*  GR0_FLM4        */
    volatile uint32_t  GR0_FLM5;                               /*  GR0_FLM5        */
    volatile uint32_t  GR0_FLM6;                               /*  GR0_FLM6        */
    volatile uint32_t  GR0_AB1;                                /*  GR0_AB1         */
    volatile uint32_t  GR0_AB2;                                /*  GR0_AB2         */
    volatile uint32_t  GR0_AB3;                                /*  GR0_AB3         */
};


struct st_vdc5_from_gr0_ab7
{
    volatile uint32_t  GR0_AB7;                                /*  GR0_AB7         */
    volatile uint32_t  GR0_AB8;                                /*  GR0_AB8         */
    volatile uint32_t  GR0_AB9;                                /*  GR0_AB9         */
    volatile uint32_t  GR0_AB10;                               /*  GR0_AB10        */
    volatile uint32_t  GR0_AB11;                               /*  GR0_AB11        */
    volatile uint32_t  GR0_BASE;                               /*  GR0_BASE        */
};


struct st_vdc5_from_adj0_update
{
    volatile uint32_t  ADJ0_UPDATE;                            /*  ADJ0_UPDATE     */
    volatile uint32_t  ADJ0_BKSTR_SET;                         /*  ADJ0_BKSTR_SET  */
    volatile uint32_t  ADJ0_ENH_TIM1;                          /*  ADJ0_ENH_TIM1   */
    volatile uint32_t  ADJ0_ENH_TIM2;                          /*  ADJ0_ENH_TIM2   */
    volatile uint32_t  ADJ0_ENH_TIM3;                          /*  ADJ0_ENH_TIM3   */
    volatile uint32_t  ADJ0_ENH_SHP1;                          /*  ADJ0_ENH_SHP1   */
    volatile uint32_t  ADJ0_ENH_SHP2;                          /*  ADJ0_ENH_SHP2   */
    volatile uint32_t  ADJ0_ENH_SHP3;                          /*  ADJ0_ENH_SHP3   */
    volatile uint32_t  ADJ0_ENH_SHP4;                          /*  ADJ0_ENH_SHP4   */
    volatile uint32_t  ADJ0_ENH_SHP5;                          /*  ADJ0_ENH_SHP5   */
    volatile uint32_t  ADJ0_ENH_SHP6;                          /*  ADJ0_ENH_SHP6   */
    volatile uint32_t  ADJ0_ENH_LTI1;                          /*  ADJ0_ENH_LTI1   */
    volatile uint32_t  ADJ0_ENH_LTI2;                          /*  ADJ0_ENH_LTI2   */
    volatile uint32_t  ADJ0_MTX_MODE;                          /*  ADJ0_MTX_MODE   */
    volatile uint32_t  ADJ0_MTX_YG_ADJ0;                       /*  ADJ0_MTX_YG_ADJ0 */
    volatile uint32_t  ADJ0_MTX_YG_ADJ1;                       /*  ADJ0_MTX_YG_ADJ1 */
    volatile uint32_t  ADJ0_MTX_CBB_ADJ0;                      /*  ADJ0_MTX_CBB_ADJ0 */
    volatile uint32_t  ADJ0_MTX_CBB_ADJ1;                      /*  ADJ0_MTX_CBB_ADJ1 */
    volatile uint32_t  ADJ0_MTX_CRR_ADJ0;                      /*  ADJ0_MTX_CRR_ADJ0 */
    volatile uint32_t  ADJ0_MTX_CRR_ADJ1;                      /*  ADJ0_MTX_CRR_ADJ1 */
};


struct st_vdc5_from_sc0_scl0_update
{
    volatile uint32_t  SC0_SCL0_UPDATE;                        /*  SC0_SCL0_UPDATE */
    volatile uint32_t  SC0_SCL0_FRC1;                          /*  SC0_SCL0_FRC1   */
    volatile uint32_t  SC0_SCL0_FRC2;                          /*  SC0_SCL0_FRC2   */
    volatile uint32_t  SC0_SCL0_FRC3;                          /*  SC0_SCL0_FRC3   */
    volatile uint32_t  SC0_SCL0_FRC4;                          /*  SC0_SCL0_FRC4   */
    volatile uint32_t  SC0_SCL0_FRC5;                          /*  SC0_SCL0_FRC5   */
    volatile uint32_t  SC0_SCL0_FRC6;                          /*  SC0_SCL0_FRC6   */
    volatile uint32_t  SC0_SCL0_FRC7;                          /*  SC0_SCL0_FRC7   */
    volatile uint8_t   dummy5[4];                              /*                  */
    volatile uint32_t  SC0_SCL0_FRC9;                          /*  SC0_SCL0_FRC9   */
    volatile uint16_t SC0_SCL0_MON0;                          /*  SC0_SCL0_MON0   */
    volatile uint16_t SC0_SCL0_INT;                           /*  SC0_SCL0_INT    */
    volatile uint32_t  SC0_SCL0_DS1;                           /*  SC0_SCL0_DS1    */
    volatile uint32_t  SC0_SCL0_DS2;                           /*  SC0_SCL0_DS2    */
    volatile uint32_t  SC0_SCL0_DS3;                           /*  SC0_SCL0_DS3    */
    volatile uint32_t  SC0_SCL0_DS4;                           /*  SC0_SCL0_DS4    */
    volatile uint32_t  SC0_SCL0_DS5;                           /*  SC0_SCL0_DS5    */
    volatile uint32_t  SC0_SCL0_DS6;                           /*  SC0_SCL0_DS6    */
    volatile uint32_t  SC0_SCL0_DS7;                           /*  SC0_SCL0_DS7    */
    volatile uint32_t  SC0_SCL0_US1;                           /*  SC0_SCL0_US1    */
    volatile uint32_t  SC0_SCL0_US2;                           /*  SC0_SCL0_US2    */
    volatile uint32_t  SC0_SCL0_US3;                           /*  SC0_SCL0_US3    */
    volatile uint32_t  SC0_SCL0_US4;                           /*  SC0_SCL0_US4    */
    volatile uint32_t  SC0_SCL0_US5;                           /*  SC0_SCL0_US5    */
    volatile uint32_t  SC0_SCL0_US6;                           /*  SC0_SCL0_US6    */
    volatile uint32_t  SC0_SCL0_US7;                           /*  SC0_SCL0_US7    */
    volatile uint32_t  SC0_SCL0_US8;                           /*  SC0_SCL0_US8    */
    volatile uint8_t   dummy6[4];                              /*                  */
    volatile uint32_t  SC0_SCL0_OVR1;                          /*  SC0_SCL0_OVR1   */
    volatile uint8_t   dummy7[16];                             /*                  */
    volatile uint32_t  SC0_SCL1_UPDATE;                        /*  SC0_SCL1_UPDATE */
    volatile uint8_t   dummy8[4];                              /*                  */
    volatile uint32_t  SC0_SCL1_WR1;                           /*  SC0_SCL1_WR1    */
    volatile uint32_t  SC0_SCL1_WR2;                           /*  SC0_SCL1_WR2    */
    volatile uint32_t  SC0_SCL1_WR3;                           /*  SC0_SCL1_WR3    */
    volatile uint32_t  SC0_SCL1_WR4;                           /*  SC0_SCL1_WR4    */
    volatile uint8_t   dummy9[4];                              /*                  */
    volatile uint32_t  SC0_SCL1_WR5;                           /*  SC0_SCL1_WR5    */
    volatile uint32_t  SC0_SCL1_WR6;                           /*  SC0_SCL1_WR6    */
    volatile uint32_t  SC0_SCL1_WR7;                           /*  SC0_SCL1_WR7    */
    volatile uint32_t  SC0_SCL1_WR8;                           /*  SC0_SCL1_WR8    */
    volatile uint32_t  SC0_SCL1_WR9;                           /*  SC0_SCL1_WR9    */
    volatile uint32_t  SC0_SCL1_WR10;                          /*  SC0_SCL1_WR10   */
};


struct st_vdc5_from_sc0_scl1_pbuf0
{
    volatile uint32_t  SC0_SCL1_PBUF0;                         /*  SC0_SCL1_PBUF0  */
    volatile uint32_t  SC0_SCL1_PBUF1;                         /*  SC0_SCL1_PBUF1  */
    volatile uint32_t  SC0_SCL1_PBUF2;                         /*  SC0_SCL1_PBUF2  */
    volatile uint32_t  SC0_SCL1_PBUF3;                         /*  SC0_SCL1_PBUF3  */
    volatile uint32_t  SC0_SCL1_PBUF_FLD;                      /*  SC0_SCL1_PBUF_FLD */
    volatile uint32_t  SC0_SCL1_PBUF_CNT;                      /*  SC0_SCL1_PBUF_CNT */
};






/* Start of channnel array defines of VDC5 */

/* Channnel array defines of VDC5 */
/*(Sample) value = VDC5[ channel ]->INP_UPDATE; */








/* Channnel array defines of VDC5n_FROM_GR2_AB7_ARRAY */
/*(Sample) value = VDC5n_FROM_GR2_AB7_ARRAY[ channel ][ index ]->GR0_AB7; */
#line 693 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/vdc5_iodefine.h"




/* Channnel array defines of VDC5n_FROM_GR2_UPDATE_ARRAY */
/*(Sample) value = VDC5n_FROM_GR2_UPDATE_ARRAY[ channel ][ index ]->GR0_UPDATE; */
#line 711 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/vdc5_iodefine.h"




/* Channnel array defines of VDC5n_FROM_SC0_SCL1_PBUF0_ARRAY */
/*(Sample) value = VDC5n_FROM_SC0_SCL1_PBUF0_ARRAY[ channel ][ index ]->SC0_SCL1_PBUF0; */
#line 729 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/vdc5_iodefine.h"




/* Channnel array defines of VDC5n_FROM_SC0_SCL0_UPDATE_ARRAY */
/*(Sample) value = VDC5n_FROM_SC0_SCL0_UPDATE_ARRAY[ channel ][ index ]->SC0_SCL0_UPDATE; */
#line 747 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/vdc5_iodefine.h"




/* Channnel array defines of VDC5n_FROM_ADJ0_UPDATE_ARRAY */
/*(Sample) value = VDC5n_FROM_ADJ0_UPDATE_ARRAY[ channel ][ index ]->ADJ0_UPDATE; */
#line 765 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/vdc5_iodefine.h"




/* Channnel array defines of VDC5n_FROM_GR0_AB7_ARRAY */
/*(Sample) value = VDC5n_FROM_GR0_AB7_ARRAY[ channel ][ index ]->GR0_AB7; */
#line 783 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/vdc5_iodefine.h"




/* Channnel array defines of VDC5n_FROM_GR0_UPDATE_ARRAY */
/*(Sample) value = VDC5n_FROM_GR0_UPDATE_ARRAY[ channel ][ index ]->GR0_UPDATE; */
#line 801 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/vdc5_iodefine.h"


/* End of channnel array defines of VDC5 */


#line 1594 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/vdc5_iodefine.h"
/* <-SEC M1.10.1 */
/* <-QAC 0639 */
#line 136 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 1 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefines/wdt_iodefine.h"
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
* http://www.renesas.com/disclaimer*
* Copyright (C) 2013-2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : wdt_iodefine.h
* $Rev: 819 $
* $Date:: 2014-04-18 17:03:54 +0900#$
* Description : Definition of I/O Register (V1.00a)
******************************************************************************/



struct st_wdt
{                                                          /* WDT              */
    volatile uint16_t WTCSR;                                  /*  WTCSR           */
    volatile uint16_t WTCNT;                                  /*  WTCNT           */
    volatile uint16_t WRCSR;                                  /*  WRCSR           */
};





#line 137 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\inc\\iodefine.h"
#line 49 "C:\\work\\projects\\mysoftware\\RZ\\RZ_A1H_DMAC\\src\\intc_handler.c"
/* INTC system header */
//#include "intc_handler.h"

/*******************************************************************************
* Function Name: INTC_Handler_Interrupt
* Description  : This function is the INTC interrupt handler processing called 
*              : by the irq_handler. Executes the handler processing which 
*              : corresponds to the INTC interrupt source ID specified by the
*              : icciar by calling the Userdef_INTC_HandlerExe function. The
*              : IRQ multiple interrupts are enabled. The processing for
*              : unsupported interrupt ID is executed by calling
*              : Userdef_INTC_UndefId function.
*              : In the interrupt handler processing, when the int_sense shows 
*              : "INTC_LEVEL_SENSITIVE", clear the interrupt source because it
*              : means a level sense interrupt. 
*              : Stacks are restored by ASM with the top level to correspond
*              : to multiple interrupts
* Arguments    : uint32_t icciar : Interrupt ID (value of ICCIAR register)
* Return Value : none
*******************************************************************************/
void INTC_Handler_Interrupt(uint32_t icciar)
{
    uint32_t mask;
    uint32_t int_sense;
    uint16_t int_id;
    uint32_t volatile * addr;

    int_id = (uint16_t)(icciar & 0x000003FFuL); /* Obtain interrupt ID */

    if (int_id >= (587))    /* In case of unsupported interrupt ID */
    {
        Userdef_INTC_UndefId(int_id);
    }

    /* ==== Interrupt handler call ==== */
    __enable_irq();         /* IRQ interrupt enabled */

    /* ICDICFRn has 16 sources in the 32 bits                                  */
    /* The n can be calculated by int_id / 16                                  */
    /* The upper 1 bit out of 2 bits for the bit field width is the target bit */
    /* The target bit can be calculated by ((int_id % 16) * 2) + 1             */
    addr = (volatile uint32_t *)&(*(struct st_intc *)0xE8201000uL).ICDICFR0;
    mask = (uint32_t)(1 << (((int_id % 16) * 2) + 1));
    if (0 == (*(addr + (int_id / 16)) & mask))  /* In the case of level sense */
    {
        int_sense = (0);
    }
    else                                        /* In the case of edge trigger */
    {
        int_sense = (1);
    }

    Userdef_INTC_HandlerExe(int_id, int_sense);     /* Call interrupt handler */

    __disable_irq();        /* IRQ interrupt disabled */
}

/*******************************************************************************
* Function Name: FiqHandler_Interrupt
* Description  : This function is the INTC interrupt handler processing called
*              : by the fiq_handler.
* Arguments    : none
* Return Value : none
*******************************************************************************/
void FiqHandler_Interrupt(void)
{
    Userdef_FIQ_HandlerExe();
}


/* END of File */

