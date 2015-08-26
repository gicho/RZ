/**************************************************
 *
 * This module contains the function `__low_level_init', a function
 * that is called before the `main' function of the program.  Normally
 * low-level initializations - such as setting the prefered interrupt
 * level or setting the watchdog - can be performed here.
 *
 * Note that this function is called before the data segments are
 * initialized, this means that this function cannot rely on the
 * values of global or static variables.
 *
 * When this function returns zero, the startup code will inhibit the
 * initialization of the data segments. The result is faster startup,
 * the drawback is that neither global nor static data will be
 * initialized.
 *
 * Copyright 1999-2004 IAR Systems. All rights reserved.
 *
 * $Revision: 21623 $
 *
 **************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "compiler_settings.h"
#include "r_typedefs.h"
#include "devdrv_common.h"
#include "devdrv_intc.h"
#include "stb_init.h"
#include "bsc_userdef.h"
#include "sio_char.h"
#include "compiler_settings.h"

#include "peripheral_early_init.h"
#include "intc_handler.h"
#include "cp15_access.h"  
  
#pragma section = "RAM_IRQ_VECTOR_TABLE"
#pragma section = "RAM_IRQ_VECTOR_TABLE_init"
  

extern void APP_reset_handler(void);
extern void APP_undefined_handler(void);
extern void APP_abort_handler(void);
extern void APP_svc_handler(void);
extern void APP_prefetch_handler(void);
extern void APP_reserved_handler(void);
extern void APP_irq_handler(void);
extern void APP_fiq_handler(void);

int __low_level_init(void)
{
    
    uint32_t volatile * VectorTableEntry, * VectorTableRomEntry;
    uint8_t i;
    
    /* copy vector table to ram */
    VectorTableEntry = (uint32_t volatile *) __section_begin("RAM_IRQ_VECTOR_TABLE");
    VectorTableRomEntry = (uint32_t volatile *) __section_begin("RAM_IRQ_VECTOR_TABLE_init");

    // Size is 0x40
    for(i=0;i<0x10;i++)
      *(VectorTableEntry++) = *(VectorTableRomEntry++);

    /* Get the vector table entry again */
    VectorTableEntry = (uint32_t volatile *) __section_begin("RAM_IRQ_VECTOR_TABLE");
    VbarSet((uint32_t)VectorTableEntry);  
    
    /* Set to low vectors after QSPI boot */
    SetLowVectors();
    
//    /* setup the primary vector table in RAM */
//    *(VectorTableEntry++) = (LDR_PC_PC | 0x18);
//    *(VectorTableEntry++) = (LDR_PC_PC | 0x18);
//    *(VectorTableEntry++) = (LDR_PC_PC | 0x18);
//    *(VectorTableEntry++) = (LDR_PC_PC | 0x18);
//    *(VectorTableEntry++) = (LDR_PC_PC | 0x18);
//    *(VectorTableEntry++) = (LDR_PC_PC | 0x18);
//    *(VectorTableEntry++) = (LDR_PC_PC | 0x18);
//    *(VectorTableEntry++) = (LDR_PC_PC | 0x18);
//
//    /* setup the literal entries for the vector table in RAM */
//    *(VectorTableEntry++) = (uint32_t) &APP_reset_handler; 	/* this is in QSPI */
//    *(VectorTableEntry++) = (uint32_t) &APP_undefined_handler;  /* self loop could be coded as 0x04U */
//    *(VectorTableEntry++) = (uint32_t) &APP_svc_handler;	/* self loop could be coded as 0x08U */
//    *(VectorTableEntry++) = (uint32_t) &APP_prefetch_handler; 	/* self loop could be coded as 0x0CU */
//    *(VectorTableEntry++) = (uint32_t) &APP_abort_handler;	/* self loop could be coded as 0x10U */
//    *(VectorTableEntry++) = (uint32_t) &APP_reserved_handler;	/* self loop could be coded as 0x14U */
//    *(VectorTableEntry++) = (uint32_t) &APP_irq_handler;	/* IRQ and FIQ handler are located in RAM */
//    *(VectorTableEntry++) = (uint32_t) &APP_fiq_handler;
//
//    // set VBAR to the vector table in RAM
//    VectorTableEntry = (uint32_t volatile *) __section_begin("RAM_IRQ_VECTOR_TABLE");
//    VbarSet(VectorTableEntry);

    /* Now start initializing the hardware */
    /* enable all module clocks */
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

  /*==================================*/
  /* Choose if segment initialization */
  /* should be done or not.           */
  /* Return: 0 to omit seg_init       */
  /*         1 to run seg_init        */
  /*==================================*/
  return 1;
}

#pragma language=default

#ifdef __cplusplus
}
#endif
