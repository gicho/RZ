/*
* Copyright 2015 Giancarlo Parodi
* 
* external_address_mode.c
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


#include "compiler_settings.h"
#include "iodefine.h"

#include "spibsc_iobitmask.h"
#include "rza_io_regrw.h"

#include "qspi_controller.h"

EXEC_RAM void qspiExternalAddressForceIdleAndWait(void) {

    /* SPIBSC stop accessing the SPI in bus mode, set SSLN to negate access */
    SPIBSC0.DRCR |= EXTADDRESS_MODE_FORCE_IDLE;

    /* Wait for the SS pin to be negated */
    while((SPIBSC0.CMNSR & SLAVESELECT_PIN_MONITOR));

    qspiControllerWaitForIdle();
}

EXEC_RAM void qspiConfigureExternalAddressTransfer(const externalAddressTransfer_t* externalAddressTransferConfig) {


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


EXEC_RAM void qspiExternalAddressFlushReadCache(void) {

    volatile uint32_t dummyRead, i;

    /* flush cache */
    SPIBSC0.DRCR |= (1u << 9);

    dummyRead = SPIBSC0.DRCR;
    for(i=0;i<100;i++) SOFT_DELAY();
}


