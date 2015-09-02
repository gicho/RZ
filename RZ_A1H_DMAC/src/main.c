/*
* Copyright 2015 Giancarlo Parodi
* 
* main.c
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

/* System header */
#include <stdio.h>
#include <stdint.h>

/* Renesas data types header */
#include "r_typedefs.h"
/* Low level register read/write header */
#include "rza_io_regrw.h"            
/* Interchangeable compiler specific header */
#include "compiler_settings.h"   


/* Device Driver common header */
#include "dev_drv.h"
/* INTC driver header */
#include "devdrv_intc.h"
/* rspi module header */
#include "rspi.h"
/* I2C RSK+RZA1H Eval-board header */
#include "sample_riic_rza1h_rsk.h"
/* RIIC Driver Header */
#include "devdrv_riic.h"                               
/* Sample ADC interface header */
#include "sample_adc.h"
/* Sample Switch interface header */
#include "switches.h"
/* Sample on-board LED interface header */
#include "sample_led.h"              
/* PMOD LCD controlling function prototypes & macros */
#include "lcd_pmod.h"
/* Renesas logo (used with colour PMod display */
#include "logo.h"
/* Main sample module header */

#include "l1_cache.h"
#include "l2_cache.h"
#include "cp15_access.h"

#define PMOD_ROW_LENGTH		21u

#include "dma_tests.h"

#include "rsk.h"

uint32_t volatile init_test = 0xCAFECAFE;
#ifdef __ICCARM__

#pragma section="RAM_IRQ_VECTOR_TABLE"

#endif

#include "mutex.h"

MUTEX(testMutex);
MUTEX(testMutex2);

/*
* Function Name: main
* Description  : Main function, configures IIC channels 0 and 3, initialises
*                the user switches, LEDs and Pmod display. Displays information
*                on the Pmod before calling the dmac transfer function.
* Arguments    : none
* Return Value : 0
*/
int main(void)
{
#ifdef __ICCARM__  
  
    // int i;
    
    /* Initial setting of the level 1 cache */
    L1I_CacheInvalidate();
    L1D_CacheInvalidate();
    L2CacheInit();
    L1_CachesEnable();
    enable_mmu();

    /* Enable interrupts */
    __enable_irq();
    __enable_fiq();  

#endif

    /* Initialise user switches */
    rsk_init_switches();

    /* Initialise LED */
    rsk_init_led0();
    R_LED_On(LED0);    
    
    /* Initialise ri2c for rsk board */
    // r_riic_init_ch0();
    rsk_init_riic_ch3();
    
    R_LED_Off(LED1);
    R_LED_Off(LED2);
    R_LED_Off(LED3);
    R_LED_On(LED1);
    mutex_lock(&testMutex2);
    R_LED_On(LED2);
    mutex_unlock(&testMutex2);
    
    mutex_lock(&testMutex);
    R_LED_On(LED3);
    mutex_unlock(&testMutex);
    
    
    /* Initialise SPI */
    Init_SPI();

    /* Initialise the PMod Colour LCD display */
    R_LCD_Init();

#if 0

    /* test for dma via external request signal DREQ0
    * uses switch2 of the RSK to generate the request signal for one block transfer
    * uncached memory, ext request signal
	* Set SW2 (IRQ2) as DREQ0 pin (P1_8)
	*/
    /* ---- P1_8 : DREQ0 ---- */
    /* reinitialize to basic IO setting */
    RZA_IO_RegWrite_16(&GPIO.PIBC1,  0, GPIO_PIBC1_PIBC18_SHIFT, GPIO_PIBC1_PIBC18);
    RZA_IO_RegWrite_16(&GPIO.PBDC1,  0, GPIO_PBDC1_PBDC18_SHIFT, GPIO_PBDC1_PBDC18);
    RZA_IO_RegWrite_16(&GPIO.PM1,    1, GPIO_PM1_PM18_SHIFT, GPIO_PM1_PM18);
    RZA_IO_RegWrite_16(&GPIO.PMC1,   0, GPIO_PMC1_PMC18_SHIFT, GPIO_PMC1_PMC18);
    RZA_IO_RegWrite_16(&GPIO.PIPC1,  0, GPIO_PIPC1_PIPC18_SHIFT, GPIO_PIPC1_PIPC18);

    /* Port mode : Multiplex mode                     */
    /* Port function setting : 4th multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFC1,   1, GPIO_PFC1_PFC18_SHIFT,     GPIO_PFC1_PFC18);
    RZA_IO_RegWrite_16(&GPIO.PFCE1,  1, GPIO_PFCE1_PFCE18_SHIFT,   GPIO_PFCE1_PFCE18);
    RZA_IO_RegWrite_16(&GPIO.PFCAE1, 0, GPIO_PFCAE1_PFCAE18_SHIFT, GPIO_PFCAE1_PFCAE18);
    RZA_IO_RegWrite_16(&GPIO.PIPC1,  1, GPIO_PIPC1_PIPC18_SHIFT,   GPIO_PIPC1_PIPC18);
    RZA_IO_RegWrite_16(&GPIO.PMC1,   1, GPIO_PMC1_PMC18_SHIFT,     GPIO_PMC1_PMC18);
    // PM setting shall have no effect since PIPC is 1

    /* ---- P3_3 : DACK0 ---- */
    /* reinitialize to basic IO setting */
    RZA_IO_RegWrite_16(&GPIO.PIBC3,  0, GPIO_PIBC3_PIBC33_SHIFT, GPIO_PIBC3_PIBC33);
    RZA_IO_RegWrite_16(&GPIO.PBDC3,  0, GPIO_PBDC3_PBDC33_SHIFT, GPIO_PBDC3_PBDC33);
    RZA_IO_RegWrite_16(&GPIO.PM3,    1, GPIO_PM3_PM33_SHIFT, GPIO_PM3_PM33);
    RZA_IO_RegWrite_16(&GPIO.PMC3,   0, GPIO_PMC3_PMC33_SHIFT, GPIO_PMC3_PMC33);
    RZA_IO_RegWrite_16(&GPIO.PIPC3,  0, GPIO_PIPC3_PIPC33_SHIFT, GPIO_PIPC3_PIPC33);

    /* Port mode : Multiplex mode                     */
    /* Port function setting : 6th multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PBDC3,  0, GPIO_PBDC3_PBDC33_SHIFT, GPIO_PBDC3_PBDC33);
    RZA_IO_RegWrite_16(&GPIO.PFC3,   1, GPIO_PFC3_PFC33_SHIFT,     GPIO_PFC3_PFC33);
    RZA_IO_RegWrite_16(&GPIO.PFCE3,  0, GPIO_PFCE3_PFCE33_SHIFT,   GPIO_PFCE3_PFCE33);
    RZA_IO_RegWrite_16(&GPIO.PFCAE3, 1, GPIO_PFCAE3_PFCAE33_SHIFT, GPIO_PFCAE3_PFCAE33);
    RZA_IO_RegWrite_16(&GPIO.PIPC3,  1, GPIO_PIPC3_PIPC33_SHIFT,   GPIO_PIPC3_PIPC33);
    RZA_IO_RegWrite_16(&GPIO.PMC3,   1, GPIO_PMC3_PMC33_SHIFT,     GPIO_PMC3_PMC33);
    // PM setting shall have no effect since PIPC is 1

    /* ---- P3_2 : TEND0 ---- */
    /* on RSK is hardwired to G1C usb to serial so cannot be observed easily */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 6th multiplex function */
    /* I/O control mode : Peripheral function         */
//    RZA_IO_RegWrite_16(&GPIO.PIBC3,  0, GPIO_PIBC3_PIBC32_SHIFT, GPIO_PIBC3_PIBC32);
//    RZA_IO_RegWrite_16(&GPIO.PBDC3,  0, GPIO_PBDC3_PBDC32_SHIFT, GPIO_PBDC3_PBDC32);
//    RZA_IO_RegWrite_16(&GPIO.PM3,    1, GPIO_PM3_PM32_SHIFT, GPIO_PM3_PM32);
//    RZA_IO_RegWrite_16(&GPIO.PMC3,   0, GPIO_PMC3_PMC32_SHIFT, GPIO_PMC3_PMC32);
//    RZA_IO_RegWrite_16(&GPIO.PIPC3,  0, GPIO_PIPC3_PIPC32_SHIFT, GPIO_PIPC3_PIPC32);
    
//    RZA_IO_RegWrite_16(&GPIO.PFCAE3, 1, GPIO_PFCAE3_PFCAE32_SHIFT, GPIO_PFCAE3_PFCAE32);
//    RZA_IO_RegWrite_16(&GPIO.PFCE3,  0, GPIO_PFCE3_PFCE32_SHIFT,   GPIO_PFCE3_PFCE32);
//    RZA_IO_RegWrite_16(&GPIO.PFC3,   1, GPIO_PFC3_PFC32_SHIFT,     GPIO_PFC3_PFC32);
//    RZA_IO_RegWrite_16(&GPIO.PMC3,   1, GPIO_PMC3_PMC32_SHIFT,     GPIO_PMC3_PMC32);
//    RZA_IO_RegWrite_16(&GPIO.PIPC3,  1, GPIO_PIPC3_PIPC32_SHIFT,   GPIO_PIPC3_PIPC32);
    // PM setting shall have no effect since PIPC is 1

    dmac_uncached_uncached_extrequest();

	/* Set SW2 (IRQ2) back as normal IO input pin (P1_8) */
	RZA_IO_RegWrite_16(&GPIO.PBDC1,   1, GPIO_PBDC1_PBDC18_SHIFT,   GPIO_PBDC1_PBDC18);
	RZA_IO_RegWrite_16(&GPIO.PM1,     1, GPIO_PM1_PM18_SHIFT,       GPIO_PM1_PM18);
	RZA_IO_RegWrite_16(&GPIO.PMC1,    1, GPIO_PMC1_PMC18_SHIFT,     GPIO_PMC1_PMC18);
    RZA_IO_RegWrite_16(&GPIO.PFCAE1,  0, GPIO_PFCAE1_PFCAE18_SHIFT, GPIO_PFCAE1_PFCAE18);
    RZA_IO_RegWrite_16(&GPIO.PFCE1,   1, GPIO_PFCE1_PFCE18_SHIFT,   GPIO_PFCE1_PFCE18);
    RZA_IO_RegWrite_16(&GPIO.PFC1,    0, GPIO_PFC1_PFC18_SHIFT,     GPIO_PFC1_PFC18);
    RZA_IO_RegWrite_16(&GPIO.PIPC1,   1, GPIO_PIPC1_PIPC18_SHIFT,   GPIO_PIPC1_PIPC18);

#endif

    // tests for internal ram only
#if 1

    Display_On();
    Clear_Display(COL_WHITE);
    Display_Image (&RGB888_LOGO[0], 128, 24, 0, 104);
    Display_LCD(0, (uint8_t *)" RSK+RZA1H");
    Display_LCD(1, (uint8_t *)" DMAC L1 cache test");

    /* uncached memory */
    dmac_uncached_uncached();

    Display_LCD(12, (uint8_t *)" Press SW1,SW2,or SW3");
    g_switch_press_flg = 0u;
    /* wait for switch (1, 2, 3)press */
    while(0u == (g_switch_press_flg & SW_ALL_ON))
    {
        SOFT_DELAY();
        WAIT_FOR_INTERRUPT();
    }


    /* source cached -> dest uncached */
    Clear_Display(COL_WHITE);
    Display_Image (&RGB888_LOGO[0], 128, 24, 0, 104);
    Display_LCD(0, (uint8_t *)" RSK+RZA1H");
    Display_LCD(1, (uint8_t *)" DMAC L1 cache test");

    dmac_cached_uncached();

    Display_LCD(12, (uint8_t *)" Press SW1,SW2,or SW3");
    g_switch_press_flg = 0u;
    /* wait for switch (1, 2, 3)press */
    while(0u == (g_switch_press_flg & SW_ALL_ON))
    {
        SOFT_DELAY();
        WAIT_FOR_INTERRUPT();
    }


    /* source uncached -> dest cached */
    Clear_Display(COL_WHITE);
    Display_Image (&RGB888_LOGO[0], 128, 24, 0, 104);
    Display_LCD(0, (uint8_t *)" RSK+RZA1H");
    Display_LCD(1, (uint8_t *)" DMAC L1 cache test");

    dmac_uncached_cached();

    Display_LCD(12, (uint8_t *)" Press SW1,SW2,or SW3");
    g_switch_press_flg = 0u;
    /* wait for switch (1, 2, 3)press */
    while(0u == (g_switch_press_flg & SW_ALL_ON))
    {
        SOFT_DELAY();
        WAIT_FOR_INTERRUPT();
    }


    /* source cached -> dest cached */
	Clear_Display(COL_WHITE);
	Display_Image (&RGB888_LOGO[0], 128, 24, 0, 104);
	Display_LCD(0, (uint8_t *)" RSK+RZA1H");
	Display_LCD(1, (uint8_t *)" DMAC L1 cache test");

	dmac_cached_cached();

	Display_LCD(12, (uint8_t *)" Press SW1,SW2,or SW3");
	g_switch_press_flg = 0u;
	/* wait for switch (1, 2, 3)press */
	while(0u == (g_switch_press_flg & SW_ALL_ON))
	{
        SOFT_DELAY();
        WAIT_FOR_INTERRUPT();
	}


    Clear_Display(COL_WHITE);
    Display_Image (&RGB888_LOGO[0], 128, 24, 0, 104);
    Display_LCD(0, (uint8_t *)" RSK+RZA1H");
    Display_LCD(1, (uint8_t *)" DMAC L1 cache test");
    Display_LCD(3, (uint8_t *)" ALL PASSED");

	Display_LCD(12, (uint8_t *)" Press SW1,SW2,or SW3");
	g_switch_press_flg = 0u;
	/* wait for switch (1, 2, 3)press */
	while(0u == (g_switch_press_flg & SW_ALL_ON))
	{
        SOFT_DELAY();
        WAIT_FOR_INTERRUPT();
	}

#endif


	// tests for internal ram and sdram
#if 1

    /* source iram uncached -> dest sdram uncached */
	Clear_Display(COL_WHITE);
	Display_Image (&RGB888_LOGO[0], 128, 24, 0, 104);
	Display_LCD(0, (uint8_t *)" RSK+RZA1H");
	Display_LCD(1, (uint8_t *)" DMAC L1 - SDRAM");

	dmac_ram_uncached_sdram_uncached();

	Display_LCD(12, (uint8_t *)" Press SW1,SW2,or SW3");
	g_switch_press_flg = 0u;
	/* wait for switch (1, 2, 3)press */
	while(0u == (g_switch_press_flg & SW_ALL_ON))
	{
        SOFT_DELAY();
        WAIT_FOR_INTERRUPT();
	}

    /* source iram cached -> dest sdram uncached */
	Clear_Display(COL_WHITE);
	Display_Image (&RGB888_LOGO[0], 128, 24, 0, 104);
	Display_LCD(0, (uint8_t *)" RSK+RZA1H");
	Display_LCD(1, (uint8_t *)" DMAC L1 - SDRAM");

	dmac_ram_cached_sdram_uncached();

	Display_LCD(12, (uint8_t *)" Press SW1,SW2,or SW3");
	g_switch_press_flg = 0u;
	/* wait for switch (1, 2, 3)press */
	while(0u == (g_switch_press_flg & SW_ALL_ON))
	{
        SOFT_DELAY();
        WAIT_FOR_INTERRUPT();
	}

    /* source iram uncached -> dest sdram cached */
	Clear_Display(COL_WHITE);
	Display_Image (&RGB888_LOGO[0], 128, 24, 0, 104);
	Display_LCD(0, (uint8_t *)" RSK+RZA1H");
	Display_LCD(1, (uint8_t *)" DMAC L1 - SDRAM");

	dmac_ram_uncached_sdram_cached();

	Display_LCD(12, (uint8_t *)" Press SW1,SW2,or SW3");
	g_switch_press_flg = 0u;
	/* wait for switch (1, 2, 3)press */
	while(0u == (g_switch_press_flg & SW_ALL_ON))
	{
        SOFT_DELAY();
        WAIT_FOR_INTERRUPT();
	}

    /* source iram cached -> dest sdram cached */
	Clear_Display(COL_WHITE);
	Display_Image (&RGB888_LOGO[0], 128, 24, 0, 104);
	Display_LCD(0, (uint8_t *)" RSK+RZA1H");
	Display_LCD(1, (uint8_t *)" DMAC L1 - SDRAM");

	dmac_ram_cached_sdram_cached();

	Display_LCD(12, (uint8_t *)" Press SW1,SW2,or SW3");
	g_switch_press_flg = 0u;
	/* wait for switch (1, 2, 3)press */
	while(0u == (g_switch_press_flg & SW_ALL_ON))
	{
        SOFT_DELAY();
        WAIT_FOR_INTERRUPT();
	}


    /* source sdram uncached -> dest iram uncached */
	Clear_Display(COL_WHITE);
	Display_Image (&RGB888_LOGO[0], 128, 24, 0, 104);
	Display_LCD(0, (uint8_t *)" RSK+RZA1H");
	Display_LCD(1, (uint8_t *)" DMAC SDRAM - L1");

	dmac_sdram_uncached_ram_uncached();

	Display_LCD(12, (uint8_t *)" Press SW1,SW2,or SW3");
	g_switch_press_flg = 0u;
	/* wait for switch (1, 2, 3)press */
	while(0u == (g_switch_press_flg & SW_ALL_ON))
	{
        SOFT_DELAY();
        WAIT_FOR_INTERRUPT();
	}

    /* source sdram uncached -> dest iram cached */
	Clear_Display(COL_WHITE);
	Display_Image (&RGB888_LOGO[0], 128, 24, 0, 104);
	Display_LCD(0, (uint8_t *)" RSK+RZA1H");
	Display_LCD(1, (uint8_t *)" DMAC SDRAM - L1");

	dmac_sdram_uncached_ram_cached();

	Display_LCD(12, (uint8_t *)" Press SW1,SW2,or SW3");
	g_switch_press_flg = 0u;
	/* wait for switch (1, 2, 3)press */
	while(0u == (g_switch_press_flg & SW_ALL_ON))
	{
        SOFT_DELAY();
        WAIT_FOR_INTERRUPT();
	}

    /* source sdram cached -> dest ram uncached */
	Clear_Display(COL_WHITE);
	Display_Image (&RGB888_LOGO[0], 128, 24, 0, 104);
	Display_LCD(0, (uint8_t *)" RSK+RZA1H");
	Display_LCD(1, (uint8_t *)" DMAC SDRAM - L1");

	dmac_sdram_cached_ram_uncached();

	Display_LCD(12, (uint8_t *)" Press SW1,SW2,or SW3");
	g_switch_press_flg = 0u;
	/* wait for switch (1, 2, 3)press */
	while(0u == (g_switch_press_flg & SW_ALL_ON))
	{
        SOFT_DELAY();
        WAIT_FOR_INTERRUPT();
	}

    /* source sdram cached -> dest ram cached */
	Clear_Display(COL_WHITE);
	Display_Image (&RGB888_LOGO[0], 128, 24, 0, 104);
	Display_LCD(0, (uint8_t *)" RSK+RZA1H");
	Display_LCD(1, (uint8_t *)" DMAC SDRAM - L1");

	dmac_sdram_cached_ram_cached();

	Display_LCD(12, (uint8_t *)" Press SW1,SW2,or SW3");
	g_switch_press_flg = 0u;
	/* wait for switch (1, 2, 3)press */
	while(0u == (g_switch_press_flg & SW_ALL_ON))
	{
        SOFT_DELAY();
        WAIT_FOR_INTERRUPT();
	}


    /* source sdram cached -> dest sdram cached */
	Clear_Display(COL_WHITE);
	Display_Image (&RGB888_LOGO[0], 128, 24, 0, 104);
	Display_LCD(0, (uint8_t *)" RSK+RZA1H");
	Display_LCD(1, (uint8_t *)" DMAC SDRAM - SDRAM");

	dmac_sdram_cached_sdram_cached();

	Display_LCD(12, (uint8_t *)" Press SW1,SW2,or SW3");
	g_switch_press_flg = 0u;
	/* wait for switch (1, 2, 3)press */
	while(0u == (g_switch_press_flg & SW_ALL_ON))
	{
        SOFT_DELAY();
        WAIT_FOR_INTERRUPT();
	}

#endif

    Clear_Display(COL_WHITE);
    Display_Image (&RGB888_LOGO[0], 128, 24, 0, 104);
    Display_LCD(0, (uint8_t *)" RSK+RZA1H");
    Display_LCD(1, (uint8_t *)" DMAC L1 - SDRAM test");
    Display_LCD(3, (uint8_t *)" ALL PASSED");

    while(1)
    {
    	/* Program should not exit */
        SOFT_DELAY();        
    }

    return 0;
}


/* End of File */
