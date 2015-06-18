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
/******************************************************************************
* File Name     : resetprg.c
* Device(s)     : RZ/A1H RSK+RZA1H
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : Sample Program - C library entry point
*               : Variants of this file must be created for each compiler
******************************************************************************/
/******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
******************************************************************************/

#include "r_typedefs.h"
#include "devdrv_common.h"
#include "devdrv_intc.h"
#include "resetprg.h"
#include "stb_init.h"
#include "bsc_userdef.h"
#include "sio_char.h"
#include "compiler_settings.h"

#include "peripheral_early_init.h"
#include "intc_handler.h"

#if defined(__thumb2__) || (defined(__thumb__) && defined(__ARM_ARCH_6M__))
# define THUMB_V7_V6M
#endif

/* Defined if this target supports the BLX Rm instruction.  */
# define HAVE_CALL_INDIRECT


#include "l1_cache.h"
#include "l2_cache.h"

/* These are related to the code which runs at startup */
/* Global variables are specified in the linker script (GCC-QSPI-BL.ld) */
extern uint32_t __fast_code_rom_start__;
extern uint32_t __fast_code_start__;
extern uint32_t __fast_code_end__;

extern uint32_t __vector_table_ram_start__;

/* These are related to the rest of the code */
extern uint32_t __data_rom_start__;
extern uint32_t __data_start__;
extern uint32_t __data_end__;

extern uint32_t __bss_start__;
extern uint32_t __bss_end__;


extern uint32_t APP_reset_handler;
extern uint32_t APP_undefined_handler;
extern uint32_t APP_svc_handler;
extern uint32_t APP_prefetch_handler;
extern uint32_t APP_abort_handler;
extern uint32_t APP_reserved_handler;
extern uint32_t APP_irq_handler;
extern uint32_t APP_fiq_handler;

extern void copy_arm_code_section_to_ram(uint32_t* rom_start, uint32_t* ram_start, uint32_t* ram_end);
extern void VbarSet(uint32_t address);

/*******************************************************************************
* Function Name: PowerON_Reset
* Description  :
* Arguments    : none
* Return Value : none
*******************************************************************************/
static uint32_t const LDR_PC_PC = 0xE59FF000U;

/* note: no global or initialized variables can be used since .data is not yet initialized */
void PowerON_Reset (void)
{
    uint32_t *ram_code_start,*ram_code_end;
	uint32_t *rom_code_start;
	uint32_t volatile * VectorTableEntry;
	uint8_t  *src, *dst, *end;

	/* data and bss are copied into initsct.S */
	/* relocate code and vector table to ram */
	/* these are the destination (run-time) locations of the code */
	ram_code_start = &__fast_code_start__;
	ram_code_end = &__fast_code_end__;

    /* this is where in rom the section is located */
	rom_code_start = &__fast_code_rom_start__;

	/* warning this is copying in multiple of 4 bytes so not suitable for 16-Bit thumb */
	copy_arm_code_section_to_ram(rom_code_start, ram_code_start, ram_code_end);

	/* setup any of the other .data, .const or .bss initialized sections */
	src = (uint8_t*) &__data_rom_start__;
	dst = (uint8_t*) &__data_start__;
	end = (uint8_t*) &__data_end__;

	/* if not debugging directly from RAM */
	if(src != dst) {
		/* ROM has data at end of text; copy it. */
		while (dst < end) {
			*dst++ = *src++;
		}
	};

	dst = (uint8_t*) &__bss_start__;
	end = (uint8_t*) &__bss_end__;

	/* Zero bss */
	for (; dst< end; dst++)
		*dst = 0;

	/* now C environment is properly configured */

	/* copy vector table to ram */
	VectorTableEntry = (uint32_t volatile *) &__vector_table_ram_start__;

    /* setup the primary vector table in RAM */
	*(VectorTableEntry++) = (LDR_PC_PC | 0x18);
    *(VectorTableEntry++) = (LDR_PC_PC | 0x18);
    *(VectorTableEntry++) = (LDR_PC_PC | 0x18);
    *(VectorTableEntry++) = (LDR_PC_PC | 0x18);
    *(VectorTableEntry++) = (LDR_PC_PC | 0x18);
    *(VectorTableEntry++) = (LDR_PC_PC | 0x18);
    *(VectorTableEntry++) = (LDR_PC_PC | 0x18);
    *(VectorTableEntry++) = (LDR_PC_PC | 0x18);

    /* setup the literal entries for the vector table in RAM */
    *(VectorTableEntry++) = (uint32_t) &APP_reset_handler; 		/* this is in QSPI */
    *(VectorTableEntry++) = (uint32_t) &APP_undefined_handler;  /* self loop could be coded as 0x04U */
    *(VectorTableEntry++) = (uint32_t) &APP_svc_handler;		/* self loop could be coded as 0x08U */
    *(VectorTableEntry++) = (uint32_t) &APP_prefetch_handler; 	/* self loop could be coded as 0x0CU */
    *(VectorTableEntry++) = (uint32_t) &APP_abort_handler;		/* self loop could be coded as 0x10U */
    *(VectorTableEntry++) = (uint32_t) &APP_reserved_handler;	/* self loop could be coded as 0x14U */
    *(VectorTableEntry++) = (uint32_t) &APP_irq_handler;		/* IRQ and FIQ handler are located in RAM */
    *(VectorTableEntry++) = (uint32_t) &APP_fiq_handler;

	// set VBAR to the vector table in RAM
	VbarSet((uint32_t) &__vector_table_ram_start__);

	/* Now start initializing the hardware */

    /* ==== CPG setting ====*/
    // configured in the reset handler
	// CPG_Init();

	// enable all module clocks
	STB_Init();

	// initialize the hardware ports
#if (USE_NOR_FLASH)

    /* ==== Port setting ==== */
    CS0_PORTInit();

#endif

#if (USE_SDRAM)

    /* ==== Port setting ==== */
    CS2_PORTInit();

#endif

    // initialize the bus state controllers
#if (USE_NOR_FLASH)

    /* ==== BSC setting ==== */
    R_BSC_Init((uint8_t)(BSC_AREA_CS0));

#endif

#if (USE_SDRAM)

    /* ==== BSC setting ==== */
    // warning: in this case also CS3 is configured due to hw behavior
    // see Userdef_BSC_CS2Init in bsc_userdef.c
    R_BSC_Init((uint8_t)(BSC_AREA_CS2));

#endif

#if (USE_NOR_FLASH | USE_SDRAM)

    ExternalBus_AddressDataLines_Init();

#endif


    /* INTC setting */
    R_INTC_Init();

    /* Initial setting of the level 1 cache */
    L1CachesEnable();

    L2CacheInit();

    __enable_irq();
    __enable_fiq();

//    /* ==== Initialise Terminal ==== */
//    /* SCIF 2ch */
//    /* P1=66.67MHz CKS=0 SCBRR=17 Bit rate error=0.46% => Baud rate=115200bps */
//    IoInitScif2();

    main();

	/* Stops program from running off */
    while(1)
    {
		__asm__("nop");
   	}
}

