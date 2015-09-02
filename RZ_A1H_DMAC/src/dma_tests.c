/*
* Copyright 2015 Giancarlo Parodi
* 
* dma_tests.c
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
#include <stdint.h>
#include <stdio.h>

#include "compiler_settings.h"
#include "assembler_macros.h"

/* Hardware interface header */
#include "iodefine.h"
#include "devdrv_intc.h"
#include "dmac_iobitmask.h"
#include "rza_io_regrw.h"

#include "l1_cache.h"
#include "l2_cache.h"
#include "cp15_access.h"

#include "switches.h"
#include "lcd_pmod.h"

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
DMA_RAM_BUFFER static uint8_t dmac_src_data_ram[DMAC_BUFF_SIZE];

/* Destination Buffer : Place in On-Chip RAM (cache invalid area)*/
DMA_RAM_BUFFER static uint8_t dmac_dst_data_ram[DMAC_BUFF_SIZE];

/* Source Buffer : Place in On-Chip CACHED RAM */
DMA_RAM_CACHED_BUFFER static uint8_t dmac_src_data_cachedram[DMAC_BUFF_SIZE];

/* Destination Buffer : Place in On-Chip CACHED RAM */
DMA_RAM_CACHED_BUFFER static uint8_t dmac_dst_data_cachedram[DMAC_BUFF_SIZE];

/* Source Buffer : Place in SDRAM (cache invalid area) */
DMA_SDRAM_BUFFER static uint8_t dmac_src_data_sdram[DMAC_BUFF_SIZE];

/* Destination Buffer : Place in SDRAM (cache invalid area)*/
DMA_SDRAM_BUFFER static uint8_t dmac_dst_data_sdram[DMAC_BUFF_SIZE];

/* Source Buffer : Place in CACHED SDRAM */
DMA_SDRAM_CACHED_BUFFER static uint8_t dmac_src_data_cachedsdram[DMAC_BUFF_SIZE];

/* Destination Buffer : Place in CACHED SDRAM */
DMA_SDRAM_CACHED_BUFFER static uint8_t dmac_dst_data_cachedsdram[DMAC_BUFF_SIZE];


bool dmac_ch3_trans_flg = false;
bool dmac_ch0_trans_flg = false;

#define L2_CACHED_SRC (0x1)
#define L2_CACHED_DST (0x2)


bool verify_data_set(uint8_t* buffer, uint8_t reference)
{
    uint32_t index = 0;
    bool   ret = true;

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

void Sample_DMAC3_Interrupt(uint32_t int_sense)
{
    dmac_ch3_trans_flg = true;
}

void Sample_DMAC0_Interrupt(uint32_t int_sense)
{
    dmac_ch0_trans_flg = true;
}


void initialise_data(uint8_t *src, uint8_t data, uint32_t size)
{
    while(size--)
    {
        *src++ = data;
    }
}

/*
* Function Name: initialise_dma8bit_extrequest
* Description  : Initialise data transfer on channel 0 of the dma controller
*              : memory block must be allocated prior to calling this function
*              : size should not specify more bytes than allocated
*              : transfer is done via external request signal DREQ based on level
*              : acknowledge is generated via DACK0
*              : transfer end signaled via TEND0
* Arguments    : uint8_t  *src : pointer to start of data to transfer
*              : uint8_t  *dst : pointer to start of data transfer destination
*              : uint32_t size : number of bytes to transfer
* Return Value : None
*/
void initialise_dma8bit_extrequest(uint8_t *src, uint8_t *dst, uint32_t size)
{
    volatile uint32_t dummy = 0u;

    UNUSED_VARIABLE(dummy);

    /* Clear interrupt flag */
    dmac_ch0_trans_flg = false;

    /* Set Source Start Address */
    DMAC0.N0SA_n = (uint32_t)src;

    /* Set Destination Start Address */
    DMAC0.N0DA_n = (uint32_t)dst;

    /* Set Transfer Size */
    DMAC0.N0TB_n = size;

    /* Set Count direction of the source address Auto increment */
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 0x0, DMAC0_CHCFG_n_DAD_SHIFT, DMAC0_CHCFG_n_DAD);

    /* Set Count direction of the destination address Auto increment */
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 0x0, DMAC0_CHCFG_n_SAD_SHIFT, DMAC0_CHCFG_n_SAD);

    /* Set Source Transfer Size 8 bits */
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 0x0, DMAC0_CHCFG_n_DDS_SHIFT, DMAC0_CHCFG_n_DDS);

    /* Set Destination Transfer Size 8 bits */
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 0x0, DMAC0_CHCFG_n_SDS_SHIFT, DMAC0_CHCFG_n_SDS);

    /* Set Channel Status Register DMA Mode to 0 (Register Mode) */
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 0, DMAC0_CHCFG_n_DMS_SHIFT,  DMAC0_CHCFG_n_DMS);

    /* Set Channel Status Register Set to 0 (Select Executes the Next0 Register Set) */
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 0, DMAC0_CHCFG_n_RSEL_SHIFT, DMAC0_CHCFG_n_RSEL);

    /* Set Channel Status Register Sweep Buffer Enable to 0 (Stops the DMA transfer without sweeping the buffer) */
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 0, DMAC0_CHCFG_n_SBE_SHIFT,  DMAC0_CHCFG_n_SBE);

    /* Set Channel Status Register DMA Interrupt Mask to 0 (Does not mask the DMA interrupt) */
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 0, DMAC0_CHCFG_n_DEM_SHIFT,  DMAC0_CHCFG_n_DEM);

    /* Set Enabled Register Set Enable to 0 (Does not continue DMA transfers) */
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 0, DMAC0_CHCFG_n_REN_SHIFT, DMAC0_CHCFG_n_REN);

    /* Set Register Select Switch to 0 (Does not invert RSEL automatically after a DMA transaction) */
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 0, DMAC0_CHCFG_n_RSW_SHIFT, DMAC0_CHCFG_n_RSW);

    /* TM  : Set Enabled single transfer Mode */
    /* AM  : Set ACK Mode DMAACK output until DREQ becomes inactive 0x1, bus cycle 0x2 */
    /* SEL : Set SEL setting, channel 0 */
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 0, DMAC0_CHCFG_n_TM_SHIFT,  DMAC0_CHCFG_n_TM);
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 1, DMAC0_CHCFG_n_AM_SHIFT,  DMAC0_CHCFG_n_AM);
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 0, DMAC0_CHCFG_n_SEL_SHIFT, DMAC0_CHCFG_n_SEL);

    /* LVL, HIEN, LOWN, REQD */
    /* select based on edge */
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 1, DMAC0_CHCFG_n_LVL_SHIFT,  DMAC0_CHCFG_n_LVL);
    /* ignore high level */
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 0, DMAC0_CHCFG_n_HIEN_SHIFT, DMAC0_CHCFG_n_HIEN);
    /* detect a request when signal has a falling edge */
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 1, DMAC0_CHCFG_n_LOEN_SHIFT, DMAC0_CHCFG_n_LOEN);

    /* ACK to get active when read */
    RZA_IO_RegWrite_32(&DMAC0.CHCFG_n, 1, DMAC0_CHCFG_n_REQD_SHIFT, DMAC0_CHCFG_n_REQD);

    /* MID = 0, RID = 3 for external request */
    RZA_IO_RegWrite_32(&DMAC01.DMARS, 0, DMAC01_DMARS_CH0_MID_SHIFT, DMAC01_DMARS_CH0_MID);
    RZA_IO_RegWrite_32(&DMAC01.DMARS, 3, DMAC01_DMARS_CH0_RID_SHIFT, DMAC01_DMARS_CH0_RID);

    /* PR : Set Round Robin mode */
    RZA_IO_RegWrite_32(&DMAC07.DCTRL_0_7, 1, DMAC07_DCTRL_0_7_PR_SHIFT, DMAC07_DCTRL_0_7_PR);

    /* ==== Set DMAC channel 0 function ==== */
    R_INTC_RegistIntFunc(INTC_ID_DMAINT0, Sample_DMAC0_Interrupt);

    /* ==== Set DMAC channel 3 interrupt priority ==== */
    R_INTC_SetPriority(INTC_ID_DMAINT0, 1);

    /* ==== Enable DMAC channel 0 interrupt ==== */
    R_INTC_Enable(INTC_ID_DMAINT0);

    if ((0 == RZA_IO_RegRead_32(&DMAC0.CHSTAT_n, DMAC0_CHSTAT_n_EN_SHIFT,   DMAC0_CHSTAT_n_EN)) &&
        (0 == RZA_IO_RegRead_32(&DMAC0.CHSTAT_n, DMAC0_CHSTAT_n_TACT_SHIFT, DMAC0_CHSTAT_n_TACT)))
    {
        /* Channel Status Register */
        RZA_IO_RegWrite_32(&DMAC0.CHCTRL_n, 1, DMAC0_CHCTRL_n_SWRST_SHIFT, DMAC0_CHCTRL_n_SWRST);
        dummy = RZA_IO_RegRead_32(&DMAC0.CHCTRL_n, DMAC0_CHCTRL_n_SWRST_SHIFT, DMAC0_CHCTRL_n_SWRST);


        RZA_IO_RegWrite_32(&DMAC0.CHCTRL_n, 1, DMAC0_CHCTRL_n_SETEN_SHIFT, DMAC0_CHCTRL_n_SETEN);

    }

}

/*
* Function Name: initialise_dma8bit
* Description  : Initialise data transfer on channel 3 of the dma controller
*              : memory block must be allocated prior to calling this function
*              : size should not specify more bytes than allocated
* Arguments    : uint8_t  *src : pointer to start of data to transfer
*              : uint8_t  *dst : pointer to start of data transfer destination
*              : uint32_t size : number of bytes to transfer
* Return Value : None
*/
void initialise_dma8bit(uint8_t *src, uint8_t *dst, uint32_t size)
{
    volatile uint32_t dummy = 0u;

    UNUSED_VARIABLE(dummy);

    /* Clear interrupt flag */
    dmac_ch3_trans_flg = false;

    /* Set Source Start Address */
    DMAC3.N0SA_n = (uint32_t)src;

    /* Set Destination Start Address */
    DMAC3.N0DA_n = (uint32_t)dst;

    /* Set Transfer Size */
    DMAC3.N0TB_n = size;

    /* Set Count direction of the source address Auto increment */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0x00, DMAC3_CHCFG_n_DAD_SHIFT, DMAC3_CHCFG_n_DAD);

    /* Set Count direction of the destination address Auto increment */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0x00, DMAC3_CHCFG_n_SAD_SHIFT, DMAC3_CHCFG_n_SAD);

    /* Set Source Transfer Size 8 bits */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0x00, DMAC3_CHCFG_n_DDS_SHIFT, DMAC3_CHCFG_n_DDS);

    /* Set Destination Transfer Size 8 bits */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0x00, DMAC3_CHCFG_n_SDS_SHIFT, DMAC3_CHCFG_n_SDS);

    /* Set Channel Status Register DMA Mode to 0 (Register Mode) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_DMS_SHIFT,  DMAC3_CHCFG_n_DMS);

    /* Set Channel Status Register Set to 0 (Select Executes the Next0 Register Set) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_RSEL_SHIFT, DMAC3_CHCFG_n_RSEL);

    /* Set Channel Status Register Sweep Buffer Enable to 0 (Stops the DMA transfer without sweeping the buffer) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_SBE_SHIFT,  DMAC3_CHCFG_n_SBE);

    /* Set Channel Status Register DMA Interrupt Mask to 0 (Does not mask the DMA interrupt) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_DEM_SHIFT,  DMAC3_CHCFG_n_DEM);

    /* Set Enabled Register Set Enable to 0 (Does not continue DMA transfers) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_REN_SHIFT, DMAC3_CHCFG_n_REN);

    /* Set Register Select Switch to 0 (Does not invert RSEL automatically after a DMA transaction) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_RSW_SHIFT, DMAC3_CHCFG_n_RSW);

    /* TM  : Set Enabled Transfer Mode */
    /* AM  : Set ACK Mode DMAACK not to be output */
    /* SEL : Set SEL setting */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 1, DMAC3_CHCFG_n_TM_SHIFT,  DMAC3_CHCFG_n_TM);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 4, DMAC3_CHCFG_n_AM_SHIFT,  DMAC3_CHCFG_n_AM);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 3, DMAC3_CHCFG_n_SEL_SHIFT, DMAC3_CHCFG_n_SEL);

    /* LVL, HIEN, LOWN, REQD : Initial Value */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_LVL_SHIFT,  DMAC3_CHCFG_n_LVL);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_HIEN_SHIFT, DMAC3_CHCFG_n_HIEN);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_LOEN_SHIFT, DMAC3_CHCFG_n_LOEN);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_REQD_SHIFT, DMAC3_CHCFG_n_REQD);

    /* MID, RID : Initial Value */
    RZA_IO_RegWrite_32(&DMAC23.DMARS, 0, DMAC23_DMARS_CH3_MID_SHIFT, DMAC23_DMARS_CH3_MID);
    RZA_IO_RegWrite_32(&DMAC23.DMARS, 0, DMAC23_DMARS_CH3_RID_SHIFT, DMAC23_DMARS_CH3_RID);

    /* PR : Set Round Robin mode */
    RZA_IO_RegWrite_32(&DMAC07.DCTRL_0_7, 1, DMAC07_DCTRL_0_7_PR_SHIFT, DMAC07_DCTRL_0_7_PR);

    /* ==== Set DMAC channel 3 function ==== */
    R_INTC_RegistIntFunc(INTC_ID_DMAINT3, Sample_DMAC3_Interrupt);

    /* ==== Set DMAC channel 3 interrupt priority ==== */
    R_INTC_SetPriority(INTC_ID_DMAINT3, 1);

    /* ==== Enable DMAC channel 3 interrupt ==== */
    R_INTC_Enable(INTC_ID_DMAINT3);

    if ((0 == RZA_IO_RegRead_32(&DMAC3.CHSTAT_n, DMAC3_CHSTAT_n_EN_SHIFT,   DMAC3_CHSTAT_n_EN)) &&
        (0 == RZA_IO_RegRead_32(&DMAC3.CHSTAT_n, DMAC3_CHSTAT_n_TACT_SHIFT, DMAC3_CHSTAT_n_TACT)))
    {
        /* Channel Status Register */
        RZA_IO_RegWrite_32(&DMAC3.CHCTRL_n, 1, DMAC3_CHCTRL_n_SWRST_SHIFT, DMAC3_CHCTRL_n_SWRST);
        dummy = RZA_IO_RegRead_32(&DMAC3.CHCTRL_n, DMAC3_CHCTRL_n_SWRST_SHIFT, DMAC3_CHCTRL_n_SWRST);


        RZA_IO_RegWrite_32(&DMAC3.CHCTRL_n, 1, DMAC3_CHCTRL_n_SETEN_SHIFT, DMAC3_CHCTRL_n_SETEN);

        /* Software */
        RZA_IO_RegWrite_32(&DMAC3.CHCTRL_n, 1, DMAC3_CHCTRL_n_STG_SHIFT, DMAC3_CHCTRL_n_STG);
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
    DMAC3.N0SA_n = (uint32_t)src;

    /* Set Destination Start Address */
    DMAC3.N0DA_n = (uint32_t)dst;

    /* Set Transfer Size */
    DMAC3.N0TB_n = size;

    /* Set Count direction of the source address Auto increment */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0x00, DMAC3_CHCFG_n_DAD_SHIFT, DMAC3_CHCFG_n_DAD);

    /* Set Count direction of the destination address Auto increment */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0x00, DMAC3_CHCFG_n_SAD_SHIFT, DMAC3_CHCFG_n_SAD);

    /* Set Source Transfer Size 8 bits */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0x00, DMAC3_CHCFG_n_DDS_SHIFT, DMAC3_CHCFG_n_DDS);

    /* Set Destination Transfer Size 8 bits */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0x00, DMAC3_CHCFG_n_SDS_SHIFT, DMAC3_CHCFG_n_SDS);

    /* Set Channel Status Register DMA Mode to 0 (Register Mode) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_DMS_SHIFT,  DMAC3_CHCFG_n_DMS);

    /* Set Channel Status Register Set to 0 (Select Executes the Next0 Register Set) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_RSEL_SHIFT, DMAC3_CHCFG_n_RSEL);

    /* Set Channel Status Register Sweep Buffer Enable to 0 (Stops the DMA transfer without sweeping the buffer) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_SBE_SHIFT,  DMAC3_CHCFG_n_SBE);

    /* Set Channel Status Register DMA Interrupt Mask to 0 (Does not mask the DMA interrupt) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_DEM_SHIFT,  DMAC3_CHCFG_n_DEM);

    /* Set Enabled Register Set Enable to 0 (Does not continue DMA transfers) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_REN_SHIFT, DMAC3_CHCFG_n_REN);

    /* Set Register Select Switch to 0 (Does not invert RSEL automatically after a DMA transaction) */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_RSW_SHIFT, DMAC3_CHCFG_n_RSW);

    /* TM  : Set Enabled Transfer Mode */
    /* AM  : Set ACK Mode DMAACK not to be output */
    /* SEL : Set SEL setting */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 1, DMAC3_CHCFG_n_TM_SHIFT,  DMAC3_CHCFG_n_TM);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 4, DMAC3_CHCFG_n_AM_SHIFT,  DMAC3_CHCFG_n_AM);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 3, DMAC3_CHCFG_n_SEL_SHIFT, DMAC3_CHCFG_n_SEL);

    /* LVL, HIEN, LOWN, REQD : Initial Value */
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_LVL_SHIFT,  DMAC3_CHCFG_n_LVL);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_HIEN_SHIFT, DMAC3_CHCFG_n_HIEN);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_LOEN_SHIFT, DMAC3_CHCFG_n_LOEN);
    RZA_IO_RegWrite_32(&DMAC3.CHCFG_n, 0, DMAC3_CHCFG_n_REQD_SHIFT, DMAC3_CHCFG_n_REQD);

    /* MID, RID : Initial Value */
    RZA_IO_RegWrite_32(&DMAC23.DMARS, 0, DMAC23_DMARS_CH3_MID_SHIFT, DMAC23_DMARS_CH3_MID);
    RZA_IO_RegWrite_32(&DMAC23.DMARS, 0, DMAC23_DMARS_CH3_RID_SHIFT, DMAC23_DMARS_CH3_RID);

    /* PR : Set Round Robin mode */
    RZA_IO_RegWrite_32(&DMAC07.DCTRL_0_7, 1, DMAC07_DCTRL_0_7_PR_SHIFT, DMAC07_DCTRL_0_7_PR);

    /* ==== Set DMAC channel 3 function ==== */
    R_INTC_RegistIntFunc(INTC_ID_DMAINT3, Sample_DMAC3_Interrupt);

    /* ==== Set DMAC channel 3 interrupt priority ==== */
    R_INTC_SetPriority(INTC_ID_DMAINT3, 1);

    /* ==== Enable DMAC channel 3 interrupt ==== */
    R_INTC_Enable(INTC_ID_DMAINT3);

    /* Set channel extension register 3 to the CACHE attributes for source and destination */
    /* NOTE: this must be consistent with the TTB settings for the memory domain */
    /* now set at inner and outer write back, write allocate: 1111b, Table2-14 AWCACHE and ARCACHE definitions in L2C-310 trm */
    if(direction & L2_CACHED_SRC) RZA_IO_RegWrite_32(&DMAC3.CHEXT_n, WRITE_ALLOCATE_WRITE_BACK, DMAC3_CHEXT_n_SCA_SHIFT, DMAC7_CHEXT_n_SCA);
    if(direction & L2_CACHED_DST) RZA_IO_RegWrite_32(&DMAC3.CHEXT_n, WRITE_ALLOCATE_WRITE_BACK, DMAC3_CHEXT_n_DCA_SHIFT, DMAC7_CHEXT_n_DCA);



    if ((0 == RZA_IO_RegRead_32(&DMAC3.CHSTAT_n, DMAC3_CHSTAT_n_EN_SHIFT,   DMAC3_CHSTAT_n_EN)) &&
        (0 == RZA_IO_RegRead_32(&DMAC3.CHSTAT_n, DMAC3_CHSTAT_n_TACT_SHIFT, DMAC3_CHSTAT_n_TACT)))
    {
        /* Channel Status Register */
        RZA_IO_RegWrite_32(&DMAC3.CHCTRL_n, 1, DMAC3_CHCTRL_n_SWRST_SHIFT, DMAC3_CHCTRL_n_SWRST);
        dummy = RZA_IO_RegRead_32(&DMAC3.CHCTRL_n, DMAC3_CHCTRL_n_SWRST_SHIFT, DMAC3_CHCTRL_n_SWRST);


        RZA_IO_RegWrite_32(&DMAC3.CHCTRL_n, 1, DMAC3_CHCTRL_n_SETEN_SHIFT, DMAC3_CHCTRL_n_SETEN);

        /* Software */
        RZA_IO_RegWrite_32(&DMAC3.CHCTRL_n, 1, DMAC3_CHCTRL_n_STG_SHIFT, DMAC3_CHCTRL_n_STG);
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

void dmac_uncached_uncached_extrequest(void)
{
    // char str[16];
    uint8_t *addressSrc, *addressDst;

    // dmac_src_data_sdram
    initialise_data(dmac_src_data_sdram, BUFF_INIT_BYTE, DMAC_BUFF_SIZE);
    initialise_data(dmac_dst_data_ram, 0x00, DMAC_BUFF_SIZE);

    addressSrc = (uint8_t*) getPaFromVa((uint32_t)dmac_dst_data_ram);
    addressDst = (uint8_t*) getPaFromVa((uint32_t)dmac_src_data_sdram);
/*
    addressSrc = (uint8_t*) getPaFromVa((uint32_t)dmac_src_data_sdram);
    addressDst = (uint8_t*) getPaFromVa((uint32_t)dmac_dst_data_ram);
*/

    initialise_dma8bit_extrequest(addressSrc, addressDst, DMAC_BUFF_SIZE);

    while(dmac_ch0_trans_flg == false)
    {
	    touchLoop_L1((uint32_t) dmac_src_data_sdram);
	    touchLoop_L1((uint32_t) dmac_dst_data_ram);
	    __asm("nop");
    }

    if(verify_data_set(dmac_dst_data_ram, BUFF_INIT_BYTE) == false)
    {
    	while(1);
    }
}

void dmac_uncached_uncached(void)
{
    char str[16];
    uint8_t *addressSrc, *addressDst;

    Display_LCD(3, (uint8_t *)" From uncached RAM");
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_src_data_ram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To uncached RAM");
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_dst_data_ram);
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
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_src_data_cachedram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To uncached RAM");
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_dst_data_ram);
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
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_src_data_ram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To cached RAM");
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_dst_data_cachedram);
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
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_src_data_cachedram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To cached RAM");
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_dst_data_cachedram);
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
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_src_data_ram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To uncached SDRAM");
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_dst_data_sdram);
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
	    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_src_data_cachedram);
	    Display_LCD(4, (uint8_t *)str);

	    Display_LCD(6, (uint8_t *)" To uncached SDRAM");
	    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_dst_data_sdram);
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
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_src_data_ram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To cached SDRAM");
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_dst_data_cachedsdram);
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
    L2CacheInvalidateRange((uint32_t) addressDst, (uint32_t) (addressDst + DMAC_BUFF_SIZE));
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
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_src_data_cachedram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To cached SDRAM");
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_dst_data_cachedsdram);
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
    L2CacheInvalidateRange((uint32_t) addressDst, (uint32_t) (addressDst + DMAC_BUFF_SIZE));
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
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_src_data_sdram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To uncached RAM");
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_dst_data_ram);
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
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_src_data_cachedsdram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To uncached RAM");
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_dst_data_ram);
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
    L2CacheCleanRange((uint32_t) addressSrc, (uint32_t) (addressSrc + DMAC_BUFF_SIZE));

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
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_src_data_sdram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To cached RAM");
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_dst_data_cachedram);
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
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_src_data_cachedsdram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To cached RAM");
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_dst_data_cachedram);
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
    L2CacheCleanRange((uint32_t) addressSrc, (uint32_t) (addressSrc + DMAC_BUFF_SIZE));

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
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_src_data_cachedsdram);
    Display_LCD(4, (uint8_t *)str);

    Display_LCD(6, (uint8_t *)" To cached SDRAM");
    sprintf(str, " ADDR 0x%08x",(uint32_t)dmac_dst_data_cachedsdram);
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
    L2CacheCleanRange((uint32_t) addressSrc, (uint32_t) (addressSrc + DMAC_BUFF_SIZE));

    initialise_dma8bit_L2Cached(addressSrc, addressDst, DMAC_BUFF_SIZE, L2_CACHED_SRC | L2_CACHED_DST);

    while(dmac_ch3_trans_flg == false)
    {
	    touchLoop_L2((uint32_t) addressSrc);
	    touchLoop_L2((uint32_t) addressDst);
	    __asm("nop");
    }

    /* invalidate the cached data before reading */
    // outer first
    L2CacheInvalidateRange((uint32_t) addressDst, (uint32_t) (addressDst + DMAC_BUFF_SIZE));
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


