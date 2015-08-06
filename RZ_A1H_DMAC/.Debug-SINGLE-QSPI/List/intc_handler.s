///////////////////////////////////////////////////////////////////////////////
//
// IAR ANSI C/C++ Compiler V7.40.3.8902/W32 for ARM       06/Aug/2015  16:43:11
// Copyright 1999-2015 IAR Systems AB.
//
//    Cpu mode     =  arm
//    Endian       =  little
//    Source file  =  
//        C:\work\projects\mysoftware\RZ\RZ_A1H_DMAC\src\intc_handler.c
//    Command line =  
//        C:\work\projects\mysoftware\RZ\RZ_A1H_DMAC\src\intc_handler.c -D
//        DEBUG --preprocess=cl
//        C:\work\projects\mysoftware\RZ\RZ_A1H_DMAC\.Debug-SINGLE-QSPI\List\
//        -lC
//        C:\work\projects\mysoftware\RZ\RZ_A1H_DMAC\.Debug-SINGLE-QSPI\List\
//        -lA
//        C:\work\projects\mysoftware\RZ\RZ_A1H_DMAC\.Debug-SINGLE-QSPI\List\
//        -o C:\work\projects\mysoftware\RZ\RZ_A1H_DMAC\.Debug-SINGLE-QSPI\Obj\
//        --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa
//        --no_clustering --no_scheduling --debug --endian=little
//        --cpu=Cortex-A9 -e --fpu=VFPv3 --dlib_config
//        C:\work\dev\iar_arm7.2\arm\INC\c\DLib_Config_Normal.h -I
//        C:\work\projects\mysoftware\RZ\RZ_A1H_DMAC\inc\ -I
//        C:\work\projects\mysoftware\RZ\RZ_A1H_DMAC\inc\iodefines\ -I
//        C:\work\projects\mysoftware\RZ\RZ_A1H_DMAC\inc\iobitmasks\ -I
//        C:\work\projects\mysoftware\RZ\RZ_A1H_DMAC\qspi_controller_driver\inc\
//        -I C:\work\projects\mysoftware\RZ\RZ_A1H_DMAC\compiler_specific\inc\
//        --cpu_mode arm -On
//    List file    =  
//        C:\work\projects\mysoftware\RZ\RZ_A1H_DMAC\.Debug-SINGLE-QSPI\List\intc_handler.s
//
///////////////////////////////////////////////////////////////////////////////

        RTMODEL "__SystemLibrary", "DLib"
        AAPCS BASE,INTERWORK,VFP
        PRESERVE8
        REQUIRE8

        #define SHT_PROGBITS 0x1

        EXTERN Userdef_FIQ_HandlerExe
        EXTERN Userdef_INTC_HandlerExe
        EXTERN Userdef_INTC_UndefId
        EXTERN __aeabi_idiv
        EXTERN __aeabi_idivmod

        PUBLIC FiqHandler_Interrupt
        PUBLIC INTC_Handler_Interrupt
        
          CFI Names cfiNames0
          CFI StackFrame CFA R13 DATA
          CFI Resource R0:32, R1:32, R2:32, R3:32, R4:32, R5:32, R6:32, R7:32
          CFI Resource R8:32, R9:32, R10:32, R11:32, R12:32, R13:32, R14:32
          CFI Resource D0:64, D1:64, D2:64, D3:64, D4:64, D5:64, D6:64, D7:64
          CFI Resource D8:64, D9:64, D10:64, D11:64, D12:64, D13:64, D14:64
          CFI Resource D15:64, D16:64, D17:64, D18:64, D19:64, D20:64, D21:64
          CFI Resource D22:64, D23:64, D24:64, D25:64, D26:64, D27:64, D28:64
          CFI Resource D29:64, D30:64, D31:64
          CFI EndNames cfiNames0
        
          CFI Common cfiCommon0 Using cfiNames0
          CFI CodeAlign 4
          CFI DataAlign 4
          CFI ReturnAddress R14 CODE
          CFI CFA R13+0
          CFI R0 Undefined
          CFI R1 Undefined
          CFI R2 Undefined
          CFI R3 Undefined
          CFI R4 SameValue
          CFI R5 SameValue
          CFI R6 SameValue
          CFI R7 SameValue
          CFI R8 SameValue
          CFI R9 SameValue
          CFI R10 SameValue
          CFI R11 SameValue
          CFI R12 Undefined
          CFI R14 SameValue
          CFI D0 Undefined
          CFI D1 Undefined
          CFI D2 Undefined
          CFI D3 Undefined
          CFI D4 Undefined
          CFI D5 Undefined
          CFI D6 Undefined
          CFI D7 Undefined
          CFI D8 SameValue
          CFI D9 SameValue
          CFI D10 SameValue
          CFI D11 SameValue
          CFI D12 SameValue
          CFI D13 SameValue
          CFI D14 SameValue
          CFI D15 SameValue
          CFI D16 Undefined
          CFI D17 Undefined
          CFI D18 Undefined
          CFI D19 Undefined
          CFI D20 Undefined
          CFI D21 Undefined
          CFI D22 Undefined
          CFI D23 Undefined
          CFI D24 Undefined
          CFI D25 Undefined
          CFI D26 Undefined
          CFI D27 Undefined
          CFI D28 Undefined
          CFI D29 Undefined
          CFI D30 Undefined
          CFI D31 Undefined
          CFI EndCommon cfiCommon0
        
// C:\work\projects\mysoftware\RZ\RZ_A1H_DMAC\src\intc_handler.c
//    1 /*******************************************************************************
//    2 * DISCLAIMER
//    3 * This software is supplied by Renesas Electronics Corporation and is only
//    4 * intended for use with Renesas products. No other uses are authorized. This
//    5 * software is owned by Renesas Electronics Corporation and is protected under
//    6 * all applicable laws, including copyright laws.
//    7 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
//    8 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
//    9 * LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
//   10 * AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
//   11 * TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
//   12 * ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
//   13 * FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
//   14 * ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
//   15 * BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
//   16 * Renesas reserves the right, without notice, to make changes to this software
//   17 * and to discontinue the availability of this software. By using this software,
//   18 * you agree to the additional terms and conditions found by accessing the
//   19 * following link:
//   20 * http://www.renesas.com/disclaimer
//   21 *
//   22 * Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.
//   23 *******************************************************************************/
//   24 /*******************************************************************************
//   25 * File Name     : intc_handler.c
//   26 * Device(s)     : RZ/A1H (R7S721001)
//   27 * Tool-Chain    : GNUARM-RZv13.01-EABI
//   28 * H/W Platform  : RSK+RZA1H CPU Board
//   29 * Description   : Sample Program - Handler process
//   30 *******************************************************************************/
//   31 /*******************************************************************************
//   32 * History       : DD.MM.YYYY Version Description
//   33 *               : 18.06.2013 1.00
//   34 *               : 21.03.2014 2.00
//   35 *******************************************************************************/
//   36 
//   37 /*******************************************************************************
//   38 Includes   <System Includes> , "Project Includes"
//   39 *******************************************************************************/
//   40 /* Interchangeable compiler specific header */
//   41 #include "compiler_settings.h"
//   42 
//   43 /* Default  type definition header */
//   44 #include "r_typedefs.h"
//   45 /* INTC Driver Header */
//   46 #include "devdrv_intc.h"
//   47 /* I/O Register root header */
//   48 #include "iodefine.h"
//   49 /* INTC system header */
//   50 //#include "intc_handler.h"
//   51 
//   52 /*******************************************************************************
//   53 * Function Name: INTC_Handler_Interrupt
//   54 * Description  : This function is the INTC interrupt handler processing called 
//   55 *              : by the irq_handler. Executes the handler processing which 
//   56 *              : corresponds to the INTC interrupt source ID specified by the
//   57 *              : icciar by calling the Userdef_INTC_HandlerExe function. The
//   58 *              : IRQ multiple interrupts are enabled. The processing for
//   59 *              : unsupported interrupt ID is executed by calling
//   60 *              : Userdef_INTC_UndefId function.
//   61 *              : In the interrupt handler processing, when the int_sense shows 
//   62 *              : "INTC_LEVEL_SENSITIVE", clear the interrupt source because it
//   63 *              : means a level sense interrupt. 
//   64 *              : Stacks are restored by ASM with the top level to correspond
//   65 *              : to multiple interrupts
//   66 * Arguments    : uint32_t icciar : Interrupt ID (value of ICCIAR register)
//   67 * Return Value : none
//   68 *******************************************************************************/

        SECTION `.text`:CODE:NOROOT(2)
          CFI Block cfiBlock0 Using cfiCommon0
          CFI Function INTC_Handler_Interrupt
        ARM
//   69 void INTC_Handler_Interrupt(uint32_t icciar)
//   70 {
INTC_Handler_Interrupt:
        PUSH     {R3-R9,LR}
          CFI R14 Frame(CFA, -4)
          CFI R9 Frame(CFA, -8)
          CFI R8 Frame(CFA, -12)
          CFI R7 Frame(CFA, -16)
          CFI R6 Frame(CFA, -20)
          CFI R5 Frame(CFA, -24)
          CFI R4 Frame(CFA, -28)
          CFI CFA R13+32
        MOVS     R4,R0
//   71     uint32_t mask;
//   72     uint32_t int_sense;
//   73     uint16_t int_id;
//   74     uint32_t volatile * addr;
//   75 
//   76     int_id = (uint16_t)(icciar & 0x000003FFuL); /* Obtain interrupt ID */
        MOVS     R0,R4
        LSLS     R0,R0,#+22
        LSRS     R0,R0,#+22
        MOVS     R7,R0
//   77 
//   78     if (int_id >= INTC_ID_TOTAL)    /* In case of unsupported interrupt ID */
        MOVS     R0,R7
        UXTH     R0,R0
        MOVW     R1,#+587
        CMP      R0,R1
        BLT      ??INTC_Handler_Interrupt_0
//   79     {
//   80         Userdef_INTC_UndefId(int_id);
        MOVS     R0,R7
        UXTH     R0,R0
        BL       Userdef_INTC_UndefId
//   81     }
//   82 
//   83     /* ==== Interrupt handler call ==== */
//   84     __enable_irq();         /* IRQ interrupt enabled */
??INTC_Handler_Interrupt_0:
          CFI FunCall Userdef_INTC_UndefId
        CPSIE    I
//   85 
//   86     /* ICDICFRn has 16 sources in the 32 bits                                  */
//   87     /* The n can be calculated by int_id / 16                                  */
//   88     /* The upper 1 bit out of 2 bits for the bit field width is the target bit */
//   89     /* The target bit can be calculated by ((int_id % 16) * 2) + 1             */
//   90     addr = (volatile uint32_t *)&INTC.ICDICFR0;
        LDR      R0,??DataTable0  ;; 0xe8201c00
        MOVS     R8,R0
//   91     mask = (uint32_t)(1 << (((int_id % 16) * 2) + 1));
        MOV      R9,#+1
        MOVS     R0,R7
        UXTH     R0,R0
        MOV      R1,#+16
        BL       __aeabi_idivmod
          CFI FunCall __aeabi_idivmod
        MOV      R0,#+2
        MULS     R1,R0,R1
        ADDS     R0,R1,#+1
        LSLS     R0,R9,R0
        MOVS     R5,R0
//   92     if (0 == (*(addr + (int_id / 16)) & mask))  /* In the case of level sense */
        MOVS     R0,R7
        UXTH     R0,R0
        MOV      R1,#+16
        BL       __aeabi_idiv
          CFI FunCall __aeabi_idiv
        LSLS     R0,R0,#+2
        LDR      R0,[R0, +R8]
        TST      R5,R0
        BNE      ??INTC_Handler_Interrupt_1
//   93     {
//   94         int_sense = INTC_LEVEL_SENSITIVE;
        MOV      R0,#+0
        MOVS     R6,R0
        B        ??INTC_Handler_Interrupt_2
//   95     }
//   96     else                                        /* In the case of edge trigger */
//   97     {
//   98         int_sense = INTC_EDGE_TRIGGER;
??INTC_Handler_Interrupt_1:
        MOV      R0,#+1
        MOVS     R6,R0
//   99     }
//  100 
//  101     Userdef_INTC_HandlerExe(int_id, int_sense);     /* Call interrupt handler */
??INTC_Handler_Interrupt_2:
        MOVS     R1,R6
        MOVS     R0,R7
        UXTH     R0,R0
        BL       Userdef_INTC_HandlerExe
//  102 
//  103     __disable_irq();        /* IRQ interrupt disabled */
          CFI FunCall Userdef_INTC_HandlerExe
        CPSID    I
//  104 }
        POP      {R0,R4-R9,PC}    ;; return
          CFI R4 SameValue
          CFI R5 SameValue
          CFI R6 SameValue
          CFI R7 SameValue
          CFI R8 SameValue
          CFI R9 SameValue
          CFI CFA R13+0
          CFI EndBlock cfiBlock0

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable0:
        DC32     0xe8201c00
//  105 
//  106 /*******************************************************************************
//  107 * Function Name: FiqHandler_Interrupt
//  108 * Description  : This function is the INTC interrupt handler processing called
//  109 *              : by the fiq_handler.
//  110 * Arguments    : none
//  111 * Return Value : none
//  112 *******************************************************************************/

        SECTION `.text`:CODE:NOROOT(2)
          CFI Block cfiBlock1 Using cfiCommon0
          CFI Function FiqHandler_Interrupt
        ARM
//  113 void FiqHandler_Interrupt(void)
//  114 {
FiqHandler_Interrupt:
        PUSH     {R12,LR}
          CFI R14 Frame(CFA, -4)
          CFI CFA R13+8
//  115     Userdef_FIQ_HandlerExe();
        BL       Userdef_FIQ_HandlerExe
//  116 }
          CFI FunCall Userdef_FIQ_HandlerExe
        POP      {R0,PC}          ;; return
          CFI CFA R13+0
          CFI EndBlock cfiBlock1

        SECTION `.iar_vfe_header`:DATA:NOALLOC:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
        DC32 0

        SECTION __DLIB_PERTHREAD:DATA:REORDER:NOROOT(0)
        SECTION_TYPE SHT_PROGBITS, 0

        SECTION __DLIB_PERTHREAD_init:DATA:REORDER:NOROOT(0)
        SECTION_TYPE SHT_PROGBITS, 0

        END
//  117 
//  118 
//  119 /* END of File */
//  120 
// 
// 200 bytes in section .text
// 
// 200 bytes of CODE memory
//
//Errors: none
//Warnings: none
