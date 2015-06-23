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
* Copyright (C) 2013 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name   : spibsc_init2.c
* Description : Flash boot setting
*******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_typedefs.h"
#include "iodefine.h"
//#include "spibsc.h"
// #include "r_spibsc_ioset_api.h"
#include "rza_io_regrw.h"

//#include "sflash.h"
#include "qspi_setup.h"

#include "qspi_controller.h"

/******************************************************************************
Typedef definitions
******************************************************************************/


/******************************************************************************
Macro definitions
******************************************************************************/


/******************************************************************************
Imported global variables and functions (from other files)
******************************************************************************/

/******************************************************************************
Exported global variables and functions (to be accessed by other files)
******************************************************************************/


/******************************************************************************
Private global variables and functions
******************************************************************************/

void qspiExternalAddressForceIdleAndWait(void) {

    /* SPIBSC stop accessing the SPI in bus mode, set SSLN to negate access */
    SPIBSC0.DRCR |= EXTADDRESS_MODE_FORCE_IDLE;

    /* Wait for the SS pin to be negated */
    while((SPIBSC0.CMNSR & SLAVESELECT_PIN_MONITOR));

    qspiControllerWaitForIdle();
}

void qspiConfigureExternalAddressTransfer(externalAddressTransfer_t* externalAddressTransferConfig) {


    RZA_IO_RegWrite_32(&SPIBSC0.DRENR, externalAddressTransferConfig->commandBitSize, SPIBSC_DRENR_CDB_SHIFT, SPIBSC_DRENR_CDB);
    RZA_IO_RegWrite_32(&SPIBSC0.DRENR, externalAddressTransferConfig->optionalCommandBitSize, SPIBSC_DRENR_OCDB_SHIFT, SPIBSC_DRENR_OCDB);
    RZA_IO_RegWrite_32(&SPIBSC0.DRENR, externalAddressTransferConfig->addressBitSize, SPIBSC_DRENR_ADB_SHIFT, SPIBSC_DRENR_ADB);
    RZA_IO_RegWrite_32(&SPIBSC0.DRENR, externalAddressTransferConfig->optionalDataBitSize, SPIBSC_DRENR_OPDB_SHIFT, SPIBSC_DRENR_OPDB);
    RZA_IO_RegWrite_32(&SPIBSC0.DRENR, externalAddressTransferConfig->readDataBitSize, SPIBSC_DRENR_DRDB_SHIFT, SPIBSC_DRENR_DRDB);
    RZA_IO_RegWrite_32(&SPIBSC0.DRENR, externalAddressTransferConfig->dummyCycleEnable, SPIBSC_DRENR_DME_SHIFT, SPIBSC_DRENR_DME);
    RZA_IO_RegWrite_32(&SPIBSC0.DRENR, externalAddressTransferConfig->commandEnable, SPIBSC_DRENR_CDE_SHIFT, SPIBSC_DRENR_CDE);
    RZA_IO_RegWrite_32(&SPIBSC0.DRENR, externalAddressTransferConfig->optionalCommandEnable, SPIBSC_DRENR_OCDE_SHIFT, SPIBSC_DRENR_OCDE);
    RZA_IO_RegWrite_32(&SPIBSC0.DRENR, externalAddressTransferConfig->addressEnable, SPIBSC_DRENR_ADE_SHIFT, SPIBSC_DRENR_ADE);
    RZA_IO_RegWrite_32(&SPIBSC0.DRENR, externalAddressTransferConfig->optionalDataEnable, SPIBSC_DRENR_OPDE_SHIFT, SPIBSC_DRENR_OPDE);


    RZA_IO_RegWrite_32(&SPIBSC0.DRCMR, externalAddressTransferConfig->command, SPIBSC_DRCMR_CMD_SHIFT, SPIBSC_DRCMR_CMD);
    RZA_IO_RegWrite_32(&SPIBSC0.DRCMR, externalAddressTransferConfig->optionalCommand, SPIBSC_DRCMR_OCMD_SHIFT, SPIBSC_DRCMR_OCMD);

    RZA_IO_RegWrite_32(&SPIBSC0.DRCR, externalAddressTransferConfig->sslNegateAfterBurst, SPIBSC_DRCR_SSLE_SHIFT, SPIBSC_DRCR_SSLE);
    RZA_IO_RegWrite_32(&SPIBSC0.DRCR, externalAddressTransferConfig->readBurstLenght, SPIBSC_DRCR_RBURST_SHIFT, SPIBSC_DRCR_RBURST);
    RZA_IO_RegWrite_32(&SPIBSC0.DRCR, externalAddressTransferConfig->burstMode, SPIBSC_DRCR_RBE_SHIFT, SPIBSC_DRCR_RBE);


    RZA_IO_RegWrite_32(&SPIBSC0.DRDMCR, externalAddressTransferConfig->dummyCycleBitSize, SPIBSC_DRDMCR_DMDB_SHIFT, SPIBSC_DRDMCR_DMDB);
    RZA_IO_RegWrite_32(&SPIBSC0.DRDMCR, externalAddressTransferConfig->dummyCycles, SPIBSC_DRDMCR_DMCYC_SHIFT, SPIBSC_DRDMCR_DMCYC);



    RZA_IO_RegWrite_32(&SPIBSC0.DREAR, externalAddressTransferConfig->extendedUpperAddress, SPIBSC_DREAR_EAV_SHIFT, SPIBSC_DREAR_EAV);
    RZA_IO_RegWrite_32(&SPIBSC0.DREAR, externalAddressTransferConfig->extValidRange, SPIBSC_DREAR_EAC_SHIFT, SPIBSC_DREAR_EAC);

    SPIBSC0.DROPR = externalAddressTransferConfig->optionalData.UINT32;

    RZA_IO_RegWrite_32(&SPIBSC0.DRDRENR, externalAddressTransferConfig->addressRateMode, SPIBSC_DRDRENR_ADDRE_SHIFT, SPIBSC_DRDRENR_ADDRE);
    RZA_IO_RegWrite_32(&SPIBSC0.DRDRENR, externalAddressTransferConfig->dataReadRateMode, SPIBSC_DRDRENR_DRDRE_SHIFT, SPIBSC_DRDRENR_DRDRE);
    RZA_IO_RegWrite_32(&SPIBSC0.DRDRENR, externalAddressTransferConfig->optionalDataRateMode, SPIBSC_DRDRENR_OPDRE_SHIFT, SPIBSC_DRDRENR_OPDRE);

}


void qspiExternalAddressFlushReadCache(void) {

    uint32_t dummyRead;

    UNUSED_VARIABLE(dummyRead);

    /* flush cache */
    SPIBSC0.DRCR |= (1u << 9);

    dummyRead = SPIBSC0.DRCR;
}





/* End of File */
