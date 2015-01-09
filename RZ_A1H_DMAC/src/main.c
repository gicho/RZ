/******************************************************************************
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
******************************************************************************/
/******************************************************************************
* File Name     : main.c
* Device(s)     : RZ/A1H (R7S721001)
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : This is the RZ/A1H DMA sample main code
* Operation     : Please see the Description.txt file in the doc folder.
* Limitations   : Please see the Description.txt file in the doc folder.
******************************************************************************/
/******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*               : 21.03.2014 2.00
******************************************************************************/

/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
/* System header */
#include <stdio.h>
/* Renesas data types header */
#include "r_typedefs.h"
/* Low level register read/write header */
#include "rza_io_regrw.h"            
/* Interchangeable compiler specific header */
#include "compiler_settings.h"   
/* Hardware interface header */
#include "iodefine.h"
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
#include "main.h"

#include "l1_cache.h"
#include "l2_cache.h"

/******************************************************************************
Macro definitions
******************************************************************************/
/* Transfer buffer size: 4096 bytes */
/* must be multiple of 32 bytes */
#define DMAC_BUFF_SIZE  (512)
/* Initial byte value in src */
#define BUFF_INIT_BYTE  (0xA5)


/*****************************************************************************
Private global variables and functions
******************************************************************************/
/* Source Buffer : Place in On-Chip RAM (cache invalid area) */
static uint8_t DMA_RAM_BUFFER dmac_src_data_ram[DMAC_BUFF_SIZE];

/* Destination Buffer : Place in On-Chip RAM (cache invalid area)*/
static uint8_t DMA_RAM_BUFFER dmac_dst_data_ram[DMAC_BUFF_SIZE];

/* Source Buffer : Place in On-Chip CACHED RAM */
static uint8_t DMA_RAM_CACHED_BUFFER dmac_src_data_cachedram[DMAC_BUFF_SIZE];

/* Destination Buffer : Place in On-Chip CACHED RAM */
static uint8_t DMA_RAM_CACHED_BUFFER dmac_dst_data_cachedram[DMAC_BUFF_SIZE];

/* Source Buffer : Place in SDRAM (cache invalid area) */
static uint8_t DMA_SDRAM_BUFFER dmac_src_data_sdram[DMAC_BUFF_SIZE];

/* Destination Buffer : Place in SDRAM (cache invalid area)*/
static uint8_t DMA_SDRAM_BUFFER dmac_dst_data_sdram[DMAC_BUFF_SIZE];

/* Source Buffer : Place in CACHED SDRAM */
static uint8_t DMA_SDRAM_CACHED_BUFFER dmac_src_data_cachedsdram[DMAC_BUFF_SIZE];

/* Destination Buffer : Place in CACHED SDRAM */
static uint8_t DMA_SDRAM_CACHED_BUFFER dmac_dst_data_cachedsdram[DMAC_BUFF_SIZE];


bool_t dmac_ch3_trans_flg = false;

#define L2_CACHED_SRC (0x1)
#define L2_CACHED_DST (0x2)


bool_t verify_data_set(uint8_t* buffer, uint8_t reference)
{
    uint32_t index = 0;
    bool_t   ret = true;

    for(index = 0; index < DMAC_BUFF_SIZE; index++)
    {
        if(buffer[index] != reference)
        {
            ret = false;
            break;
        }
    }

    return ret;
}

/* convert between physical and virtual address */
uint32_t getPaFromVa(uint32_t address) {

	/* 1-to-1 mapping via MMU between VA and PA */
	/* would be different in case of different MMU setup */
	return(address);
}

/******************************************************************************
* Function Name: Sample_DMAC3_Interrupt
* Description  : DMAC3 Interrupt handler
* Arguments    : uint32_t int_sense : Interrupt detection setting
*              :                    :   INTC_LEVEL_SENSITIVE : Level Sense
*              :                    :   INTC_EDGE_TRIGGER    : Edge Trigger
* Return Value : None
******************************************************************************/
void Sample_DMAC3_Interrupt(uint32_t int_sense)
{
    dmac_ch3_trans_flg = true;
}


/******************************************************************************
* Function Name: initialise_data
* Description  : Initialise memory block with specified data,
*              : memory block must be allocated prior to calling this function
*              : size should not specify more bytes than allocated
* Arguments    : uint8_t  *src : pointer to start of data to initialise
*              : uint8_t  data : byte value to initialise data block
*              : uint32_t size : number of bytes to initialise
* Return Value : None
******************************************************************************/
void initialise_data(uint8_t *src, uint8_t data, uint32_t size)
{
    while(size--)
    {
        *src++ = data;
    }
}

/******************************************************************************
* Function Name: initialise_dma8bit
* Description  : Initialise data transfer on channel 3 of the dma controller
*              : memory block must be allocated prior to calling this function
*              : size should not specify more bytes than allocated
* Arguments    : uint8_t  *src : pointer to start of data to transfer
*              : uint8_t  *dst : pointer to start of data transfer destination
*              : uint32_t size : number of bytes to transfer
* Return Value : None
******************************************************************************/
void initialise_dma8bit(uint8_t *src, uint8_t *dst, uint32_t size)
{
    volatile uint32_t dummy = 0u;

    UNUSED_VARIABLE(dummy);

    /* Clear interrupt flag */
    dmac_ch3_trans_flg = false;

    /* Set Source Start Address */
    DMAC3.N0SA.LONG = (uint32_t)src;

    /* Set Destination Start Address */
    DMAC3.N0DA.LONG = (uint32_t)dst;

    /* Set Transfer Size */
    DMAC3.N0TB.LONG = size;

    /* Set Count direction of the source address Auto increment */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0x00, DMAC3_CHCFG_n_DAD_SHIFT, DMAC3_CHCFG_n_DAD);

    /* Set Count direction of the destination address Auto increment */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0x00, DMAC3_CHCFG_n_SAD_SHIFT, DMAC3_CHCFG_n_SAD);

    /* Set Source Transfer Size 8 bits */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0x00, DMAC3_CHCFG_n_DDS_SHIFT, DMAC3_CHCFG_n_DDS);

    /* Set Destination Transfer Size 8 bits */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0x00, DMAC3_CHCFG_n_SDS_SHIFT, DMAC3_CHCFG_n_SDS);

    /* Set Channel Status Register DMA Mode to 0 (Register Mode) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_DMS_SHIFT,  DMAC3_CHCFG_n_DMS);

    /* Set Channel Status Register Set to 0 (Select Executes the Next0 Register Set) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_RSEL_SHIFT, DMAC3_CHCFG_n_RSEL);

    /* Set Channel Status Register Sweep Buffer Enable to 0 (Stops the DMA transfer without sweeping the buffer) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_SBE_SHIFT,  DMAC3_CHCFG_n_SBE);

    /* Set Channel Status Register DMA Interrupt Mask to 0 (Does not mask the DMA interrupt) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_DEM_SHIFT,  DMAC3_CHCFG_n_DEM);

    /* Set Enabled Register Set Enable to 0 (Does not continue DMA transfers) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_REN_SHIFT, DMAC3_CHCFG_n_REN);

    /* Set Register Select Switch to 0 (Does not invert RSEL automatically after a DMA transaction) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_RSW_SHIFT, DMAC3_CHCFG_n_RSW);

    /* TM  : Set Enabled Transfer Mode */
    /* AM  : Set ACK Mode DMAACK not to be output */
    /* SEL : Set SEL setting */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 1, DMAC3_CHCFG_n_TM_SHIFT,  DMAC3_CHCFG_n_TM);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 4, DMAC3_CHCFG_n_AM_SHIFT,  DMAC3_CHCFG_n_AM);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 3, DMAC3_CHCFG_n_SEL_SHIFT, DMAC3_CHCFG_n_SEL);

    /* LVL, HIEN, LOWN, REQD : Initial Value */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_LVL_SHIFT,  DMAC3_CHCFG_n_LVL);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_HIEN_SHIFT, DMAC3_CHCFG_n_HIEN);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_LOEN_SHIFT, DMAC3_CHCFG_n_LOEN);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_REQD_SHIFT, DMAC3_CHCFG_n_REQD);

    /* MID, RID : Initial Value */
    RZA_IO_RegWrite_32(&DMAC23.DMARS.LONG, 0, DMAC23_DMARS_CH3_MID_SHIFT, DMAC23_DMARS_CH3_MID);
    RZA_IO_RegWrite_32(&DMAC23.DMARS.LONG, 0, DMAC23_DMARS_CH3_RID_SHIFT, DMAC23_DMARS_CH3_RID);

    /* PR : Set Round Robin mode */
    RZA_IO_RegWrite_32(&DMAC07.DCTRL.LONG, 1, DMAC07_DCTRL_0_7_PR_SHIFT, DMAC07_DCTRL_0_7_PR);

    /* ==== Set DMAC channel 3 function ==== */
    R_INTC_RegistIntFunc(INTC_ID_DMAINT3, Sample_DMAC3_Interrupt);

    /* ==== Set DMAC channel 3 interrupt priority ==== */
    R_INTC_SetPriority(INTC_ID_DMAINT3, 1);

    /* ==== Enable DMAC channel 3 interrupt ==== */
    R_INTC_Enable(INTC_ID_DMAINT3);

    if ((0 == RZA_IO_RegRead_32(&DMAC3.CHSTAT.LONG, DMAC3_CHSTAT_n_EN_SHIFT,   DMAC3_CHSTAT_n_EN)) &&
        (0 == RZA_IO_RegRead_32(&DMAC3.CHSTAT.LONG, DMAC3_CHSTAT_n_TACT_SHIFT, DMAC3_CHSTAT_n_TACT)))
    {
        /* Channel Status Register */
        RZA_IO_RegWrite_32(&DMAC3.CHCTRL.LONG, 1, DMAC3_CHCTRL_n_SWRST_SHIFT, DMAC3_CHCTRL_n_SWRST);
        dummy = RZA_IO_RegRead_32(&DMAC3.CHCTRL.LONG, DMAC3_CHCTRL_n_SWRST_SHIFT, DMAC3_CHCTRL_n_SWRST);


        RZA_IO_RegWrite_32(&DMAC3.CHCTRL.LONG, 1, DMAC3_CHCTRL_n_SETEN_SHIFT, DMAC3_CHCTRL_n_SETEN);

        /* Software */
        RZA_IO_RegWrite_32(&DMAC3.CHCTRL.LONG, 1, DMAC3_CHCTRL_n_STG_SHIFT, DMAC3_CHCTRL_n_STG);
    }

}

// this setup configures also the auxiliary register with the CACHE attributes for the AXI bus
void initialise_dma8bit_L2Cached(uint8_t *src, uint8_t *dst, uint32_t size, const uint8_t direction)
{
    volatile uint32_t dummy = 0u;

    UNUSED_VARIABLE(dummy);

    /* Clear interrupt flag */
    dmac_ch3_trans_flg = false;

    /* Set Source Start Address */
    DMAC3.N0SA.LONG = (uint32_t)src;

    /* Set Destination Start Address */
    DMAC3.N0DA.LONG = (uint32_t)dst;

    /* Set Transfer Size */
    DMAC3.N0TB.LONG = size;

    /* Set Count direction of the source address Auto increment */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0x00, DMAC3_CHCFG_n_DAD_SHIFT, DMAC3_CHCFG_n_DAD);

    /* Set Count direction of the destination address Auto increment */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0x00, DMAC3_CHCFG_n_SAD_SHIFT, DMAC3_CHCFG_n_SAD);

    /* Set Source Transfer Size 8 bits */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0x00, DMAC3_CHCFG_n_DDS_SHIFT, DMAC3_CHCFG_n_DDS);

    /* Set Destination Transfer Size 8 bits */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0x00, DMAC3_CHCFG_n_SDS_SHIFT, DMAC3_CHCFG_n_SDS);

    /* Set Channel Status Register DMA Mode to 0 (Register Mode) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_DMS_SHIFT,  DMAC3_CHCFG_n_DMS);

    /* Set Channel Status Register Set to 0 (Select Executes the Next0 Register Set) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_RSEL_SHIFT, DMAC3_CHCFG_n_RSEL);

    /* Set Channel Status Register Sweep Buffer Enable to 0 (Stops the DMA transfer without sweeping the buffer) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_SBE_SHIFT,  DMAC3_CHCFG_n_SBE);

    /* Set Channel Status Register DMA Interrupt Mask to 0 (Does not mask the DMA interrupt) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_DEM_SHIFT,  DMAC3_CHCFG_n_DEM);

    /* Set Enabled Register Set Enable to 0 (Does not continue DMA transfers) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_REN_SHIFT, DMAC3_CHCFG_n_REN);

    /* Set Register Select Switch to 0 (Does not invert RSEL automatically after a DMA transaction) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_RSW_SHIFT, DMAC3_CHCFG_n_RSW);

    /* TM  : Set Enabled Transfer Mode */
    /* AM  : Set ACK Mode DMAACK not to be output */
    /* SEL : Set SEL setting */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 1, DMAC3_CHCFG_n_TM_SHIFT,  DMAC3_CHCFG_n_TM);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 4, DMAC3_CHCFG_n_AM_SHIFT,  DMAC3_CHCFG_n_AM);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 3, DMAC3_CHCFG_n_SEL_SHIFT, DMAC3_CHCFG_n_SEL);

    /* LVL, HIEN, LOWN, REQD : Initial Value */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_LVL_SHIFT,  DMAC3_CHCFG_n_LVL);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_HIEN_SHIFT, DMAC3_CHCFG_n_HIEN);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_LOEN_SHIFT, DMAC3_CHCFG_n_LOEN);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG.LONG, 0, DMAC3_CHCFG_n_REQD_SHIFT, DMAC3_CHCFG_n_REQD);

    /* MID, RID : Initial Value */
    RZA_IO_RegWrite_32(&DMAC23.DMARS.LONG, 0, DMAC23_DMARS_CH3_MID_SHIFT, DMAC23_DMARS_CH3_MID);
    RZA_IO_RegWrite_32(&DMAC23.DMARS.LONG, 0, DMAC23_DMARS_CH3_RID_SHIFT, DMAC23_DMARS_CH3_RID);

    /* PR : Set Round Robin mode */
    RZA_IO_RegWrite_32(&DMAC07.DCTRL.LONG, 1, DMAC07_DCTRL_0_7_PR_SHIFT, DMAC07_DCTRL_0_7_PR);

    /* ==== Set DMAC channel 3 function ==== */
    R_INTC_RegistIntFunc(INTC_ID_DMAINT3, Sample_DMAC3_Interrupt);

    /* ==== Set DMAC channel 3 interrupt priority ==== */
    R_INTC_SetPriority(INTC_ID_DMAINT3, 1);

    /* ==== Enable DMAC channel 3 interrupt ==== */
    R_INTC_Enable(INTC_ID_DMAINT3);

    /* Set channel extension register 3 to the CACHE attributes for source and destination */
    /* NOTE: this must be consistent with the TTB settings for the memory domain */
    /* now set at inner and outer write back, write allocate: 1111b, Table2-14 AWCACHE and ARCACHE definitions in L2C-310 trm */
    if(direction & L2_CACHED_SRC) RZA_IO_RegWrite_32(&DMAC3.CHEXT.LONG, WRITE_ALLOCATE_WRITE_BACK, DMAC3_CHEXT_n_SCA_SHIFT, DMAC7_CHEXT_n_SCA);
    if(direction & L2_CACHED_DST) RZA_IO_RegWrite_32(&DMAC3.CHEXT.LONG, WRITE_ALLOCATE_WRITE_BACK, DMAC3_CHEXT_n_DCA_SHIFT, DMAC7_CHEXT_n_DCA);



    if ((0 == RZA_IO_RegRead_32(&DMAC3.CHSTAT.LONG, DMAC3_CHSTAT_n_EN_SHIFT,   DMAC3_CHSTAT_n_EN)) &&
        (0 == RZA_IO_RegRead_32(&DMAC3.CHSTAT.LONG, DMAC3_CHSTAT_n_TACT_SHIFT, DMAC3_CHSTAT_n_TACT)))
    {
        /* Channel Status Register */
        RZA_IO_RegWrite_32(&DMAC3.CHCTRL.LONG, 1, DMAC3_CHCTRL_n_SWRST_SHIFT, DMAC3_CHCTRL_n_SWRST);
        dummy = RZA_IO_RegRead_32(&DMAC3.CHCTRL.LONG, DMAC3_CHCTRL_n_SWRST_SHIFT, DMAC3_CHCTRL_n_SWRST);


        RZA_IO_RegWrite_32(&DMAC3.CHCTRL.LONG, 1, DMAC3_CHCTRL_n_SETEN_SHIFT, DMAC3_CHCTRL_n_SETEN);

        /* Software */
        RZA_IO_RegWrite_32(&DMAC3.CHCTRL.LONG, 1, DMAC3_CHCTRL_n_STG_SHIFT, DMAC3_CHCTRL_n_STG);
    }

}

#define L1_WAY_OFFSET_INDEX  0x2000
void touchLoop_L1(uint32_t vaddress) {

	volatile uint8_t dummyByte;
	volatile uint8_t * dummyAddress;
	uint8_t i;

	// L1 is a 4 way cache
	for (i=0;i<5;i++) {

		dummyAddress = (uint8_t*) (vaddress + L1_WAY_OFFSET_INDEX);
		dummyByte = *dummyAddress; // at this point the cache line is fetched
	}

	// at this point the cache line @ vaddress must be already evicted

}

#define L2_WAY_OFFSET_INDEX  0x4000
void touchLoop_L2(uint32_t paddress) {

	volatile uint8_t dummyByte;
	volatile uint8_t * dummyAddress;
	uint8_t i;

	// L2 is a 8 way cache
	for (i=0;i<9;i++) {

		dummyAddress = (uint8_t*) (paddress + L2_WAY_OFFSET_INDEX);
		dummyByte = *dummyAddress; // at this point the cache line is fetched
	}

	// at this point the cache line @ vaddress must be already evicted
}

void dmac_uncached_uncached(void)
{
    char str[16];
    uint8_t *addressSrc, *addressDst;

    Display_LCD(3, (uint8_t *)" From uncached RAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_src_data_ram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To uncached RAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_dst_data_ram);
    Display_LCD(7, (uint8_t *)str);

    initialise_data(dmac_src_data_ram, BUFF_INIT_BYTE, DMAC_BUFF_SIZE);
    initialise_data(dmac_dst_data_ram, 0x00, DMAC_BUFF_SIZE);

    Display_LCD(9, (uint8_t *)" Press SW1,SW2,or SW3");

    g_switch_press_flg = 0u;

    /* wait for switch (1, 2, 3)press */
    while(0u == (g_switch_press_flg & SW_ALL_ON))
    {
        __asm("nop");
    }

    addressSrc = (uint8_t*) getPaFromVa((uint32_t)dmac_src_data_ram);
    addressDst = (uint8_t*) getPaFromVa((uint32_t)dmac_dst_data_ram);

    initialise_dma8bit(addressSrc, addressDst, DMAC_BUFF_SIZE);

    while(dmac_ch3_trans_flg == false)
    {
	    touchLoop_L1((uint32_t) dmac_src_data_ram);
	    touchLoop_L1((uint32_t) dmac_dst_data_ram);
	    __asm("nop");
    }

    if(verify_data_set(dmac_dst_data_ram, BUFF_INIT_BYTE) == true)
    {
        Display_LCD(10, (uint8_t *)" Complete - OK");
    }
    else
    {
        Display_LCD(10, (uint8_t *)" Complete - Failed");
        while(1);
    }
}

void dmac_cached_uncached(void)
{
    char str[16];
    uint8_t *addressSrc, *addressDst;

    Display_LCD(3, (uint8_t *)" From cached RAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_src_data_cachedram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To uncached RAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_dst_data_ram);
    Display_LCD(7, (uint8_t *)str);

    initialise_data(dmac_src_data_cachedram, BUFF_INIT_BYTE, DMAC_BUFF_SIZE);
    initialise_data(dmac_dst_data_ram, 0x00, DMAC_BUFF_SIZE);

    Display_LCD(9, (uint8_t *)" Press SW1,SW2,or SW3");

    g_switch_press_flg = 0u;

    /* wait for switch (1, 2, 3)press */
    while(0u == (g_switch_press_flg & SW_ALL_ON))
    {
        __asm("nop");
    }

    /* write back the cached data source before transfer */
    dma_buffer_issue((uint32_t) dmac_src_data_cachedram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_TO_DEVICE);

    addressSrc = (uint8_t*) getPaFromVa((uint32_t)dmac_src_data_cachedram);
    addressDst = (uint8_t*) getPaFromVa((uint32_t)dmac_dst_data_ram);

    initialise_dma8bit(addressSrc, addressDst, DMAC_BUFF_SIZE);

    while(dmac_ch3_trans_flg == false)
    {
	    touchLoop_L1((uint32_t) dmac_src_data_cachedram);
	    touchLoop_L1((uint32_t) dmac_dst_data_ram);
	    __asm("nop");
    }

    /* nothing to do for the source side, but make the procedure symmetric (map/unmap) */
    dma_buffer_reclaim((uint32_t) dmac_src_data_cachedram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_TO_DEVICE);

    if(verify_data_set(dmac_dst_data_ram, BUFF_INIT_BYTE) == true)
    {
        Display_LCD(10, (uint8_t *)" Complete - OK");
    }
    else
    {
        Display_LCD(10, (uint8_t *)" Complete - Failed");
        while(1);
    }
}

void dmac_uncached_cached(void)
{
    char str[16];
    uint8_t *addressSrc, *addressDst;

    Display_LCD(3, (uint8_t *)" From uncached RAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_src_data_ram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To cached RAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_dst_data_cachedram);
    Display_LCD(7, (uint8_t *)str);

    initialise_data(dmac_src_data_ram, BUFF_INIT_BYTE, DMAC_BUFF_SIZE);
    initialise_data(dmac_dst_data_cachedram, 0x00, DMAC_BUFF_SIZE);

    Display_LCD(9, (uint8_t *)" Press SW1,SW2,or SW3");

    g_switch_press_flg = 0u;

    /* wait for switch (1, 2, 3)press */
    while(0u == (g_switch_press_flg & SW_ALL_ON))
    {
        __asm("nop");
    }

    dma_buffer_issue((uint32_t) dmac_dst_data_cachedram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_FROM_DEVICE);

    addressSrc = (uint8_t*) getPaFromVa((uint32_t)dmac_src_data_ram);
    addressDst = (uint8_t*) getPaFromVa((uint32_t)dmac_dst_data_cachedram);
    initialise_dma8bit(addressSrc, addressDst, DMAC_BUFF_SIZE);

    while(dmac_ch3_trans_flg == false)
    {
	    touchLoop_L1((uint32_t) dmac_dst_data_cachedram);
	    touchLoop_L1((uint32_t) dmac_src_data_ram);
	    __asm("nop");
    }

    /* invalidate the cached data before reading */
    dma_buffer_reclaim((uint32_t) dmac_dst_data_cachedram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_FROM_DEVICE);

    if(verify_data_set(dmac_dst_data_cachedram, BUFF_INIT_BYTE) == true)
    {
        Display_LCD(10, (uint8_t *)" Complete - OK");
    }
    else
    {
        Display_LCD(10, (uint8_t *)" Complete - Failed");
        while(1);
    }
}

void dmac_cached_cached(void)
{
    char str[16];
    uint8_t *addressSrc, *addressDst;

    Display_LCD(3, (uint8_t *)" From cached RAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_src_data_cachedram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To cached RAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_dst_data_cachedram);
    Display_LCD(7, (uint8_t *)str);

    initialise_data(dmac_src_data_cachedram, BUFF_INIT_BYTE, DMAC_BUFF_SIZE);
    initialise_data(dmac_dst_data_cachedram, 0x00, DMAC_BUFF_SIZE);

    Display_LCD(9, (uint8_t *)" Press SW1,SW2,or SW3");

    g_switch_press_flg = 0u;

    /* wait for switch (1, 2, 3)press */
    while(0u == (g_switch_press_flg & SW_ALL_ON))
    {
        __asm("nop");
    }

    /* write back the cached data before reading */
    dma_buffer_issue((uint32_t) dmac_src_data_cachedram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_TO_DEVICE);
    dma_buffer_issue((uint32_t) dmac_dst_data_cachedram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_FROM_DEVICE); /* invalidate data for destination buffer */

    addressSrc = (uint8_t*) getPaFromVa((uint32_t) dmac_src_data_cachedram);
    addressDst = (uint8_t*) getPaFromVa((uint32_t) dmac_dst_data_cachedram);

    initialise_dma8bit(addressSrc, addressDst, DMAC_BUFF_SIZE);

    while(dmac_ch3_trans_flg == false)
    {
	    touchLoop_L1((uint32_t) dmac_src_data_cachedram);
	    touchLoop_L1((uint32_t) dmac_dst_data_cachedram);
	    __asm("nop");
    }

    /* invalidate the cached data before reading */
    dma_buffer_reclaim((uint32_t) dmac_src_data_cachedram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_TO_DEVICE);
    dma_buffer_reclaim((uint32_t) dmac_dst_data_cachedram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_FROM_DEVICE);

    if(verify_data_set(dmac_dst_data_cachedram, BUFF_INIT_BYTE) == true)
    {
        Display_LCD(10, (uint8_t *)" Complete - OK");
    }
    else
    {
        Display_LCD(10, (uint8_t *)" Complete - Failed");
        while(1);
    }
}



/* transfers using sdram */

/* map the VA (virtual) to PA (physical) address since L2 cache controller and DMA require PAs */
uint32_t getVaFromPa(uint32_t address) {

	/* 1-to-1 mapping via MMU between VA and PA */
	/* would be different in case of different MMU setup */
	return(address);
}


void dmac_ram_uncached_sdram_uncached(void)
{
    char str[16];
    uint8_t *addressSrc, *addressDst;

    Display_LCD(3, (uint8_t *)" From uncached RAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_src_data_ram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To uncached SDRAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_dst_data_sdram);
    Display_LCD(7, (uint8_t *)str);

    initialise_data(dmac_src_data_ram, BUFF_INIT_BYTE, DMAC_BUFF_SIZE);
    initialise_data(dmac_dst_data_sdram, 0x00, DMAC_BUFF_SIZE);

    Display_LCD(9, (uint8_t *)" Press SW1,SW2,or SW3");

    g_switch_press_flg = 0u;

    /* wait for switch (1, 2, 3)press */
    while(0u == (g_switch_press_flg & SW_ALL_ON))
    {
        __asm("nop");
    }

    addressSrc = (uint8_t*) getPaFromVa((uint32_t) dmac_src_data_ram);
    addressDst = (uint8_t*) getPaFromVa((uint32_t) dmac_dst_data_sdram);

    initialise_dma8bit(addressSrc, addressDst, DMAC_BUFF_SIZE);

    while(dmac_ch3_trans_flg == false)
    {
	    touchLoop_L1((uint32_t) dmac_src_data_ram);
	    touchLoop_L2((uint32_t) addressDst);
	    __asm("nop");
    }

    if(verify_data_set(dmac_dst_data_sdram, BUFF_INIT_BYTE) == true)
    {
        Display_LCD(10, (uint8_t *)" Complete - OK");
    }
    else
    {
        Display_LCD(10, (uint8_t *)" Complete - Failed");
        while(1);
    }
}



void dmac_ram_cached_sdram_uncached(void)
{
	    char str[16];
	    uint8_t *addressSrc, *addressDst;

	    Display_LCD(3, (uint8_t *)" From cached RAM");
	    sprintf(str, " ADDR 0x%08x",(uint)dmac_src_data_cachedram);
	    Display_LCD(4, (uint8_t *)str);

	    Display_LCD(6, (uint8_t *)" To uncached SDRAM");
	    sprintf(str, " ADDR 0x%08x",(uint)dmac_dst_data_sdram);
	    Display_LCD(7, (uint8_t *)str);

	    initialise_data(dmac_src_data_cachedram, BUFF_INIT_BYTE, DMAC_BUFF_SIZE);
	    initialise_data(dmac_dst_data_sdram, 0x00, DMAC_BUFF_SIZE);

	    Display_LCD(9, (uint8_t *)" Press SW1,SW2,or SW3");

	    g_switch_press_flg = 0u;

	    /* wait for switch (1, 2, 3)press */
	    while(0u == (g_switch_press_flg & SW_ALL_ON))
	    {
	        __asm("nop");
	    }

	    /* write back the cached data before transfer */
	    dma_buffer_issue((uint32_t) dmac_src_data_cachedram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_TO_DEVICE);

	    addressSrc = (uint8_t*) getPaFromVa((uint32_t)dmac_src_data_cachedram);
	    addressDst = (uint8_t*) getPaFromVa((uint32_t)dmac_dst_data_sdram);

	    initialise_dma8bit(addressSrc, addressDst, DMAC_BUFF_SIZE);

	    while(dmac_ch3_trans_flg == false)
	    {
		    touchLoop_L1((uint32_t) dmac_src_data_cachedram);
		    touchLoop_L2((uint32_t) addressDst);
		    __asm("nop");
	    }


	    if(verify_data_set(dmac_dst_data_sdram, BUFF_INIT_BYTE) == true)
	    {
	        Display_LCD(10, (uint8_t *)" Complete - OK");
	    }
	    else
	    {
	        Display_LCD(10, (uint8_t *)" Complete - Failed");
	        while(1);
	    }
}



void dmac_ram_uncached_sdram_cached(void)
{
    char str[16];
    uint8_t *addressSrc, *addressDst;

    Display_LCD(3, (uint8_t *)" From uncached RAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_src_data_ram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To cached SDRAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_dst_data_cachedsdram);
    Display_LCD(7, (uint8_t *)str);

    initialise_data(dmac_src_data_ram, BUFF_INIT_BYTE, DMAC_BUFF_SIZE);
    initialise_data(dmac_dst_data_cachedsdram, 0x00, DMAC_BUFF_SIZE);

    Display_LCD(9, (uint8_t *)" Press SW1,SW2,or SW3");

    g_switch_press_flg = 0u;

    /* wait for switch (1, 2, 3)press */
    while(0u == (g_switch_press_flg & SW_ALL_ON))
    {
        __asm("nop");
    }

    // do this here since PA are required for L2
    addressSrc = (uint8_t*) getPaFromVa((uint32_t) dmac_src_data_ram);
    addressDst = (uint8_t*) getPaFromVa((uint32_t) dmac_dst_data_cachedsdram);

    initialise_dma8bit_L2Cached(addressSrc, addressDst, DMAC_BUFF_SIZE, L2_CACHED_DST);

    while(dmac_ch3_trans_flg == false)
    {
	    touchLoop_L1((uint32_t) dmac_src_data_ram);
	    touchLoop_L2((uint32_t) addressDst);
	    __asm("nop");
    }

    /* invalidate the cached data before reading */
    // outer first
    l2x0_inv_range((uint32_t) addressDst, (uint32_t) (addressDst + DMAC_BUFF_SIZE));
    dma_buffer_reclaim((uint32_t) dmac_dst_data_cachedsdram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_FROM_DEVICE);

    if(verify_data_set(dmac_dst_data_cachedsdram, BUFF_INIT_BYTE) == true)
    {
        Display_LCD(10, (uint8_t *)" Complete - OK");
    }
    else
    {
        Display_LCD(10, (uint8_t *)" Complete - Failed");
        while(1);
    }
}


void dmac_ram_cached_sdram_cached(void)
{
    char str[16];
    uint8_t *addressSrc, *addressDst;

    Display_LCD(3, (uint8_t *)" From cached RAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_src_data_cachedram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To cached SDRAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_dst_data_cachedsdram);
    Display_LCD(7, (uint8_t *)str);

    initialise_data(dmac_src_data_cachedram, BUFF_INIT_BYTE, DMAC_BUFF_SIZE);
    initialise_data(dmac_dst_data_cachedsdram, 0x00, DMAC_BUFF_SIZE);

    Display_LCD(9, (uint8_t *)" Press SW1,SW2,or SW3");

    g_switch_press_flg = 0u;

    /* wait for switch (1, 2, 3)press */
    while(0u == (g_switch_press_flg & SW_ALL_ON))
    {
        __asm("nop");
    }

    // do this here since PA are required for L2
    addressSrc = (uint8_t*) getPaFromVa((uint32_t) dmac_src_data_cachedram);
    addressDst = (uint8_t*) getPaFromVa((uint32_t) dmac_dst_data_cachedsdram);

    // now map area to dma for L1, writes back source
    dma_buffer_issue((uint32_t) dmac_src_data_cachedram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_TO_DEVICE);

    initialise_dma8bit_L2Cached(addressSrc, addressDst, DMAC_BUFF_SIZE, L2_CACHED_DST);

    while(dmac_ch3_trans_flg == false)
    {
	    touchLoop_L1((uint32_t) dmac_src_data_cachedram);
	    touchLoop_L2((uint32_t) addressDst);
	    __asm("nop");
    }

    /* invalidate the cached data before reading */
    // outer first
    l2x0_inv_range((uint32_t) addressDst, (uint32_t) (addressDst + DMAC_BUFF_SIZE));
    dma_buffer_reclaim((uint32_t) dmac_dst_data_cachedsdram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_FROM_DEVICE);

    if(verify_data_set(dmac_dst_data_cachedsdram, BUFF_INIT_BYTE) == true)
    {
        Display_LCD(10, (uint8_t *)" Complete - OK");
    }
    else
    {
        Display_LCD(10, (uint8_t *)" Complete - Failed");
        while(1);
    }
}



void dmac_sdram_uncached_ram_uncached(void)
{
    char str[16];
    uint8_t *addressSrc, *addressDst;

    Display_LCD(3, (uint8_t *)" From uncached SDRAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_src_data_sdram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To uncached RAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_dst_data_ram);
    Display_LCD(7, (uint8_t *)str);

    initialise_data(dmac_src_data_sdram, BUFF_INIT_BYTE, DMAC_BUFF_SIZE);
    initialise_data(dmac_dst_data_ram, 0x00, DMAC_BUFF_SIZE);

    Display_LCD(9, (uint8_t *)" Press SW1,SW2,or SW3");

    g_switch_press_flg = 0u;

    /* wait for switch (1, 2, 3)press */
    while(0u == (g_switch_press_flg & SW_ALL_ON))
    {
        __asm("nop");
    }

    addressSrc = (uint8_t*) getPaFromVa((uint32_t) dmac_src_data_sdram);
    addressDst = (uint8_t*) getPaFromVa((uint32_t) dmac_dst_data_ram);
    initialise_dma8bit(addressSrc, addressDst, DMAC_BUFF_SIZE);

    while(dmac_ch3_trans_flg == false)
    {
	    touchLoop_L1((uint32_t) dmac_dst_data_ram);
	    touchLoop_L2((uint32_t) addressSrc);
	    __asm("nop");
    }

    if(verify_data_set(dmac_dst_data_ram, BUFF_INIT_BYTE) == true)
    {
        Display_LCD(10, (uint8_t *)" Complete - OK");
    }
    else
    {
        Display_LCD(10, (uint8_t *)" Complete - Failed");
        while(1);
    }
}


void dmac_sdram_cached_ram_uncached(void)
{
    char str[16];
    uint8_t *addressSrc, *addressDst;

    Display_LCD(3, (uint8_t *)" From cached SDRAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_src_data_cachedsdram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To uncached RAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_dst_data_ram);
    Display_LCD(7, (uint8_t *)str);

    initialise_data(dmac_src_data_cachedsdram, BUFF_INIT_BYTE, DMAC_BUFF_SIZE);
    initialise_data(dmac_dst_data_ram, 0x00, DMAC_BUFF_SIZE);

    Display_LCD(9, (uint8_t *)" Press SW1,SW2,or SW3");

    g_switch_press_flg = 0u;

    /* wait for switch (1, 2, 3)press */
    while(0u == (g_switch_press_flg & SW_ALL_ON))
    {
        __asm("nop");
    }

    // do this here since PA are required for L2
    addressSrc = (uint8_t*) getPaFromVa((uint32_t) dmac_src_data_cachedsdram);
    addressDst = (uint8_t*) getPaFromVa((uint32_t) dmac_dst_data_ram);

    // now map area to dma for L1, writes back (cleans), inner first!
    dma_buffer_issue((uint32_t) dmac_src_data_cachedsdram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_FROM_DEVICE);
    // clean L2 cache
    l2x0_clean_range((uint32_t) addressSrc, (uint32_t) (addressSrc + DMAC_BUFF_SIZE));

    initialise_dma8bit_L2Cached(addressSrc, addressDst, DMAC_BUFF_SIZE, L2_CACHED_SRC);

    while(dmac_ch3_trans_flg == false)
    {
	    touchLoop_L1((uint32_t) dmac_dst_data_ram);
	    touchLoop_L2((uint32_t) addressSrc);
	    __asm("nop");
    }


    if(verify_data_set(dmac_src_data_cachedsdram, BUFF_INIT_BYTE) == true)
    {
        Display_LCD(10, (uint8_t *)" Complete - OK");
    }
    else
    {
        Display_LCD(10, (uint8_t *)" Complete - Failed");
        while(1);
    }
}


void dmac_sdram_uncached_ram_cached(void)
{
    char str[16];
    uint8_t *addressSrc, *addressDst;

    Display_LCD(3, (uint8_t *)" From uncached SDRAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_src_data_sdram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To cached RAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_dst_data_cachedram);
    Display_LCD(7, (uint8_t *)str);

    initialise_data(dmac_src_data_sdram, BUFF_INIT_BYTE, DMAC_BUFF_SIZE);
    initialise_data(dmac_dst_data_cachedram, 0x00, DMAC_BUFF_SIZE);

    Display_LCD(9, (uint8_t *)" Press SW1,SW2,or SW3");

    g_switch_press_flg = 0u;

    /* wait for switch (1, 2, 3)press */
    while(0u == (g_switch_press_flg & SW_ALL_ON))
    {
	    touchLoop_L1((uint32_t) dmac_dst_data_ram);
	    touchLoop_L2((uint32_t) addressSrc);__asm("nop");
    }

    addressSrc = (uint8_t*) getPaFromVa((uint32_t) dmac_src_data_sdram);
    addressDst = (uint8_t*) getPaFromVa((uint32_t) dmac_dst_data_cachedram);

    initialise_dma8bit(addressSrc, addressDst, DMAC_BUFF_SIZE);

    while(dmac_ch3_trans_flg == false)
    {
	    touchLoop_L1((uint32_t) dmac_dst_data_cachedram);
	    touchLoop_L2((uint32_t) addressSrc);
	    __asm("nop");
    }

    /* invalidate the cached data before reading */
    dma_buffer_reclaim((uint32_t) dmac_dst_data_cachedram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_FROM_DEVICE);

    if(verify_data_set(dmac_dst_data_cachedram, BUFF_INIT_BYTE) == true)
    {
        Display_LCD(10, (uint8_t *)" Complete - OK");
    }
    else
    {
        Display_LCD(10, (uint8_t *)" Complete - Failed");
        while(1);
    }
}

void dmac_sdram_cached_ram_cached(void)
{
    char str[16];
    uint8_t *addressSrc, *addressDst;

    Display_LCD(3, (uint8_t *)" From cached SDRAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_src_data_cachedsdram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To cached RAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_dst_data_cachedram);
    Display_LCD(7, (uint8_t *)str);

    initialise_data(dmac_src_data_cachedsdram, BUFF_INIT_BYTE, DMAC_BUFF_SIZE);
    initialise_data(dmac_dst_data_cachedram, 0x00, DMAC_BUFF_SIZE);

    Display_LCD(9, (uint8_t *)" Press SW1,SW2,or SW3");

    g_switch_press_flg = 0u;

    /* wait for switch (1, 2, 3)press */
    while(0u == (g_switch_press_flg & SW_ALL_ON))
    {
        __asm("nop");
    }

    addressSrc = (uint8_t*) getPaFromVa((uint32_t) dmac_src_data_cachedsdram);
    addressDst = (uint8_t*) getPaFromVa((uint32_t) dmac_dst_data_cachedram);

    // now map area to dma for L1 src
    // clean, inner first
    dma_buffer_issue((uint32_t) dmac_src_data_cachedsdram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_TO_DEVICE);
    // clean L2 cache for src
    l2x0_clean_range((uint32_t) addressSrc, (uint32_t) (addressSrc + DMAC_BUFF_SIZE));

    initialise_dma8bit_L2Cached(addressSrc, addressDst, DMAC_BUFF_SIZE, L2_CACHED_SRC);

    while(dmac_ch3_trans_flg == false)
    {
	    touchLoop_L1((uint32_t) dmac_dst_data_cachedram);
	    touchLoop_L2((uint32_t) addressSrc);
	    __asm("nop");
    }

    /* invalidate the cached data before reading */
    dma_buffer_reclaim((uint32_t) dmac_dst_data_cachedram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_FROM_DEVICE);

    if(verify_data_set(dmac_dst_data_cachedsdram, BUFF_INIT_BYTE) == true)
    {
        Display_LCD(10, (uint8_t *)" Complete - OK");
    }
    else
    {
        Display_LCD(10, (uint8_t *)" Complete - Failed");
        while(1);
    }
}

void dmac_sdram_cached_sdram_cached(void)
{
    char str[16];
    uint8_t *addressSrc, *addressDst;

    Display_LCD(3, (uint8_t *)" From cached SDRAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_src_data_cachedsdram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To cached SDRAM");
    sprintf(str, " ADDR 0x%08x",(uint)dmac_dst_data_cachedsdram);
    Display_LCD(7, (uint8_t *)str);

    initialise_data(dmac_src_data_cachedsdram, BUFF_INIT_BYTE, DMAC_BUFF_SIZE);
    initialise_data(dmac_dst_data_cachedsdram, 0x00, DMAC_BUFF_SIZE);

    Display_LCD(9, (uint8_t *)" Press SW1,SW2,or SW3");

    g_switch_press_flg = 0u;

    /* wait for switch (1, 2, 3)press */
    while(0u == (g_switch_press_flg & SW_ALL_ON))
    {
        __asm("nop");
    }

    addressSrc = (uint8_t*) getPaFromVa((uint32_t) dmac_src_data_cachedsdram);
    addressDst = (uint8_t*) getPaFromVa((uint32_t) dmac_dst_data_cachedsdram);

    // now map area to dma for L1 src - clean, inner first!
    dma_buffer_issue((uint32_t) dmac_src_data_cachedsdram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_TO_DEVICE);
    // clean L2 cache for src
    l2x0_clean_range((uint32_t) addressSrc, (uint32_t) (addressSrc + DMAC_BUFF_SIZE));

    initialise_dma8bit_L2Cached(addressSrc, addressDst, DMAC_BUFF_SIZE, L2_CACHED_SRC | L2_CACHED_DST);

    while(dmac_ch3_trans_flg == false)
    {
	    touchLoop_L2((uint32_t) addressSrc);
	    touchLoop_L2((uint32_t) addressDst);
	    __asm("nop");
    }

    /* invalidate the cached data before reading */
    // outer first
    l2x0_inv_range((uint32_t) addressDst, (uint32_t) (addressDst + DMAC_BUFF_SIZE));
    dma_buffer_reclaim((uint32_t) dmac_dst_data_cachedsdram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_FROM_DEVICE);


    if(verify_data_set(dmac_dst_data_cachedsdram, BUFF_INIT_BYTE) == true)
    {
        Display_LCD(10, (uint8_t *)" Complete - OK");
    }
    else
    {
        Display_LCD(10, (uint8_t *)" Complete - Failed");
        while(1);
    }
}





/******************************************************************************
* Function Name: main
* Description  : Main function, configures IIC channels 0 and 3, initialises
*                the user switches, LEDs and Pmod display. Displays information
*                on the Pmod before calling the dmac transfer function.
* Arguments    : none
* Return Value : 0
******************************************************************************/
int_t main(void)
{
    /* Initialise ri2c for rsk board */
    R_RIIC_rza1h_rsk_init();

    /* Initialise user switches */
    Init_Switches();

    /* Initialise LED */
    R_LED_Init();

    /* Initialise SPI */
    Init_SPI();

    /* Initialise the PMod Colour LCD display */
    R_LCD_Init();

    // tests for internal ram only
#if 1

    Clear_Display(COL_WHITE);
    Display_Image (&RGB888_LOGO[0], 128, 24, 0, 104);
    Display_LCD(0, (uint8_t *)" RSK+RZA1H");
    Display_LCD(1, (uint8_t *)" DMAC L1 cache test");
    Display_On();

    /* uncached memory */
    dmac_uncached_uncached();

    Display_LCD(12, (uint8_t *)" Press SW1,SW2,or SW3");
    g_switch_press_flg = 0u;
    /* wait for switch (1, 2, 3)press */
    while(0u == (g_switch_press_flg & SW_ALL_ON))
    {
        __asm("nop");
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
        __asm("nop");
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
        __asm("nop");
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
		__asm("nop");
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
		__asm("nop");
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
		__asm("nop");
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
		__asm("nop");
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
		__asm("nop");
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
		__asm("nop");
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
		__asm("nop");
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
		__asm("nop");
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
		__asm("nop");
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
		__asm("nop");
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
		__asm("nop");
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
		__asm__("nop");
    }

    return 0;
}
/******************************************************************************
* End of Function main
******************************************************************************/

/* End of File */
