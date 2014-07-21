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
#include "spibsc.h"
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



void qspiStartTransfer(void) {

    /* execute after setting SPNDL bit */
    RZA_IO_RegWrite_32(&SPIBSC0.SMCR, SPIBSC_SPI_ENABLE, SPIBSC_SMCR_SPIE_SHIFT, SPIBSC_SMCR_SPIE);

}


void qspiConfigureSpiTransfer(spiTransfer_t* transferConfig, dataBusSize_t busSize) {

    /* ---- Command ---- */
    RZA_IO_RegWrite_32(&SPIBSC0.SMENR, transferConfig->commandEnable, SPIBSC_SMENR_CDE_SHIFT, SPIBSC_SMENR_CDE);
    RZA_IO_RegWrite_32(&SPIBSC0.SMCMR, transferConfig->command, SPIBSC_SMCMR_CMD_SHIFT, SPIBSC_SMCMR_CMD);
    RZA_IO_RegWrite_32(&SPIBSC0.SMENR, transferConfig->commandBitSize, SPIBSC_SMENR_CDB_SHIFT, SPIBSC_SMENR_CDB);

    /* ---- Optional Command ---- */
    RZA_IO_RegWrite_32(&SPIBSC0.SMENR, transferConfig->optionalCommandEnable, SPIBSC_SMENR_OCDE_SHIFT, SPIBSC_SMENR_OCDE);
    RZA_IO_RegWrite_32(&SPIBSC0.SMCMR, transferConfig->optionalCommand, SPIBSC_SMCMR_OCMD_SHIFT, SPIBSC_SMCMR_OCMD);
    RZA_IO_RegWrite_32(&SPIBSC0.SMENR, transferConfig->optionalCommandBitSize, SPIBSC_SMENR_OCDB_SHIFT, SPIBSC_SMENR_OCDB);

    /* ---- Address ---- */
    RZA_IO_RegWrite_32(&SPIBSC0.SMENR, transferConfig->addressEnable, SPIBSC_SMENR_ADE_SHIFT, SPIBSC_SMENR_ADE);
    RZA_IO_RegWrite_32(&SPIBSC0.SMADR, transferConfig->address.UINT32, SPIBSC_SMADR_ADR_SHIFT, SPIBSC_SMADR_ADR);
    RZA_IO_RegWrite_32(&SPIBSC0.SMENR, transferConfig->addressBitSize, SPIBSC_SMENR_ADB_SHIFT, SPIBSC_SMENR_ADB);

    /* ---- Option Data ---- */
    RZA_IO_RegWrite_32(&SPIBSC0.SMENR, transferConfig->optionalDataEnable, SPIBSC_SMENR_OPDE_SHIFT, SPIBSC_SMENR_OPDE);
    RZA_IO_RegWrite_32(&SPIBSC0.SMENR, transferConfig->optionalDataBitSize, SPIBSC_SMENR_OPDB_SHIFT, SPIBSC_SMENR_OPDB);
	RZA_IO_RegWrite_32(&SPIBSC0.DROPR, transferConfig->optionalData.UINT8[3], SPIBSC_DROPR_OPD3_SHIFT, SPIBSC_DROPR_OPD3);
	RZA_IO_RegWrite_32(&SPIBSC0.DROPR, transferConfig->optionalData.UINT8[2], SPIBSC_DROPR_OPD2_SHIFT, SPIBSC_DROPR_OPD2);
	RZA_IO_RegWrite_32(&SPIBSC0.DROPR, transferConfig->optionalData.UINT8[1], SPIBSC_DROPR_OPD1_SHIFT, SPIBSC_DROPR_OPD1);
	RZA_IO_RegWrite_32(&SPIBSC0.DROPR, transferConfig->optionalData.UINT8[0], SPIBSC_DROPR_OPD0_SHIFT, SPIBSC_DROPR_OPD0);

    /* ---- Dummy ---- */
    RZA_IO_RegWrite_32(&SPIBSC0.SMENR, transferConfig->dummyCycleEnable, SPIBSC_SMENR_DME_SHIFT, SPIBSC_SMENR_DME);
    RZA_IO_RegWrite_32(&SPIBSC0.DRDMCR, transferConfig->dummyCycles, SPIBSC_DRDMCR_DMCYC_SHIFT, SPIBSC_DRDMCR_DMCYC);
    RZA_IO_RegWrite_32(&SPIBSC0.DRDMCR, transferConfig->dummyCycleBitSize, SPIBSC_DRDMCR_DMDB_SHIFT, SPIBSC_DRDMCR_DMDB);

    /* ---- Data ---- */
    RZA_IO_RegWrite_32(&SPIBSC0.SMENR, transferConfig->transferDataEnable, SPIBSC_SMENR_SPIDE_SHIFT, SPIBSC_SMENR_SPIDE);
    RZA_IO_RegWrite_32(&SPIBSC0.SMENR, transferConfig->transferDataBitSize, SPIBSC_SMENR_SPIDB_SHIFT, SPIBSC_SMENR_SPIDB);

    /* SDR Transmission */
    RZA_IO_RegWrite_32(&SPIBSC0.SMDRENR, transferConfig->addressRateMode, SPIBSC_SMDRENR_ADDRE_SHIFT, SPIBSC_SMDRENR_ADDRE);
    RZA_IO_RegWrite_32(&SPIBSC0.SMDRENR, transferConfig->optionalDataRateMode, SPIBSC_SMDRENR_OPDRE_SHIFT, SPIBSC_SMDRENR_OPDRE);
    RZA_IO_RegWrite_32(&SPIBSC0.SMDRENR, transferConfig->transferDataRateMode, SPIBSC_SMDRENR_SPIDRE_SHIFT, SPIBSC_SMDRENR_SPIDRE);

    /* SSL negate after transfer */
    RZA_IO_RegWrite_32(&SPIBSC0.SMCR, transferConfig->sslNegateAfterTransfer, SPIBSC_SMCR_SSLKP_SHIFT, SPIBSC_SMCR_SSLKP);

    /* output zeros during register read */
    if(TRANSFER_DATA_SINGLE8_DUAL16 == transferConfig->transferDataEnable) {

        	SPIBSC0.SMWDR0.UINT8[0] = transferConfig->writeData0.UINT8[0];
        	SPIBSC0.SMWDR0.UINT8[1] = transferConfig->writeData0.UINT8[1];
        	SPIBSC0.SMWDR0.UINT8[2] = transferConfig->writeData0.UINT8[2];
        	SPIBSC0.SMWDR0.UINT8[3] = transferConfig->writeData0.UINT8[3];

        } else if (TRANSFER_DATA_SINGLE16_DUAL32 == transferConfig->transferDataEnable) {

        	SPIBSC0.SMWDR0.UINT16[0] = transferConfig->writeData0.UINT16[0];
        	SPIBSC0.SMWDR0.UINT16[1] = transferConfig->writeData0.UINT16[1];

        } else if (TRANSFER_DATA_SINGLE32_DUAL64 == transferConfig->transferDataEnable) {

        	SPIBSC0.SMWDR0.UINT32 = transferConfig->writeData0.UINT32;
        	SPIBSC0.SMWDR1.UINT32 = transferConfig->writeData0.UINT32;
   };

   if (DUAL_MEMORY == busSize) {

        if(TRANSFER_DATA_SINGLE8_DUAL16 == transferConfig->transferDataEnable) {

        	SPIBSC0.SMWDR1.UINT8[0] = transferConfig->writeData1.UINT8[0];
        	SPIBSC0.SMWDR1.UINT8[1] = transferConfig->writeData1.UINT8[1];
        	SPIBSC0.SMWDR1.UINT8[2] = transferConfig->writeData1.UINT8[2];
        	SPIBSC0.SMWDR1.UINT8[3] = transferConfig->writeData1.UINT8[3];

        } else if (TRANSFER_DATA_SINGLE16_DUAL32 == transferConfig->transferDataEnable) {

        	SPIBSC0.SMWDR1.UINT16[0] = transferConfig->writeData1.UINT16[0];
        	SPIBSC0.SMWDR1.UINT16[1] = transferConfig->writeData1.UINT16[1];

        } else if (TRANSFER_DATA_SINGLE32_DUAL64 == transferConfig->transferDataEnable) {

        	SPIBSC0.SMWDR1.UINT32 = transferConfig->writeData1.UINT32;
        };
    };

   // data read enable and data write enable bits
    RZA_IO_RegWrite_32(&SPIBSC0.SMCR, transferConfig->dataReadEnable, SPIBSC_SMCR_SPIRE_SHIFT, SPIBSC_SMCR_SPIRE);
    RZA_IO_RegWrite_32(&SPIBSC0.SMCR, transferConfig->dataReadEnable, SPIBSC_SMCR_SPIWE_SHIFT, SPIBSC_SMCR_SPIWE);

}

void qspiReadByte(uint8_t* dataDevice0, uint8_t* dataDevice1, dataBusSize_t busSize) {

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();

	if(DUAL_MEMORY == busSize) {

		*dataDevice0 = (uint8_t)(SPIBSC0.SMRDR0.UINT8[0]);
		*dataDevice1 = (uint8_t)(SPIBSC0.SMRDR0.UINT8[1]);

	} else if (SINGLE_MEMORY == busSize) {

		*dataDevice0 = (uint8_t)(SPIBSC0.SMRDR0.UINT8[0]);
		*dataDevice1 = (uint8_t) 0x0;
	};

}

void qspiRead2Byte(uint16_t* dataDevice0, uint16_t* dataDevice1, dataBusSize_t busSize) {

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();

	if(DUAL_MEMORY == busSize) {

		*dataDevice0 = (uint16_t)(SPIBSC0.SMRDR0.UINT16[0]);
		*dataDevice1 = (uint16_t)(SPIBSC0.SMRDR0.UINT16[1]);

	} else if (SINGLE_MEMORY == busSize) {

		*dataDevice0 = (uint16_t)(SPIBSC0.SMRDR0.UINT16[0]);
		*dataDevice1 = (uint16_t) 0x0;
	};
}

void qspiRead4Byte(uint32_t* dataDevice0, uint16_t* dataDevice1, dataBusSize_t busSize) {

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();

	if(DUAL_MEMORY == busSize) {

		*dataDevice0 = (uint32_t)(SPIBSC0.SMRDR0.UINT32);
		*dataDevice1 = (uint16_t)(SPIBSC0.SMRDR1.UINT32);

	} else if (SINGLE_MEMORY == busSize) {

		*dataDevice0 = (uint16_t)(SPIBSC0.SMRDR0.UINT32);
		*dataDevice1 = (uint16_t) 0x0;
	};
}

void qspiWriteEnable(dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = ADDRESS_SDR_TYPE;

	/* command on one bit */
	spiConfigRegTransfer.command = WRITE_ENABLE;
	spiConfigRegTransfer.commandBitSize = COMMAND_1BIT;
	spiConfigRegTransfer.commandEnable = COMMAND_ENABLED;

	/* enable data read, disable data write */
	spiConfigRegTransfer.dataReadEnable = DATA_READ_DISABLE;
	spiConfigRegTransfer.dataWriteEnable = DATA_WRITE_DISABLE;

	/* dummy cycles disabled */
	spiConfigRegTransfer.dummyCycleBitSize = DUMMY_1BIT;
	spiConfigRegTransfer.dummyCycleEnable = DUMMY_CYCLE_DISABLED;
	spiConfigRegTransfer.dummyCycles = DUMMY_1CYCLE;

	/* optional command disabled */
	spiConfigRegTransfer.optionalCommand = DUMMY_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_DISABLED;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();
}

void qspiWriteDisable(dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = ADDRESS_SDR_TYPE;

	/* command on one bit */
	spiConfigRegTransfer.command = WRITE_DISABLE;
	spiConfigRegTransfer.commandBitSize = COMMAND_1BIT;
	spiConfigRegTransfer.commandEnable = COMMAND_ENABLED;

	/* enable data read, disable data write */
	spiConfigRegTransfer.dataReadEnable = DATA_READ_DISABLE;
	spiConfigRegTransfer.dataWriteEnable = DATA_WRITE_DISABLE;

	/* dummy cycles disabled */
	spiConfigRegTransfer.dummyCycleBitSize = DUMMY_1BIT;
	spiConfigRegTransfer.dummyCycleEnable = DUMMY_CYCLE_DISABLED;
	spiConfigRegTransfer.dummyCycles = DUMMY_1CYCLE;

	/* optional command disabled */
	spiConfigRegTransfer.optionalCommand = DUMMY_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_DISABLED;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();
}


void qspiClearStatusRegister(dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = ADDRESS_SDR_TYPE;

	/* command on one bit */
	spiConfigRegTransfer.command = CLEAR_STATUS;
	spiConfigRegTransfer.commandBitSize = COMMAND_1BIT;
	spiConfigRegTransfer.commandEnable = COMMAND_ENABLED;

	/* enable data read, disable data write */
	spiConfigRegTransfer.dataReadEnable = DATA_READ_DISABLE;
	spiConfigRegTransfer.dataWriteEnable = DATA_WRITE_DISABLE;

	/* dummy cycles disabled */
	spiConfigRegTransfer.dummyCycleBitSize = DUMMY_1BIT;
	spiConfigRegTransfer.dummyCycleEnable = DUMMY_CYCLE_DISABLED;
	spiConfigRegTransfer.dummyCycles = DUMMY_1CYCLE;

	/* optional command disabled */
	spiConfigRegTransfer.optionalCommand = DUMMY_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_DISABLED;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();
}


void qspiWriteStatusRegister(uint8_t statusDevice0, uint8_t statusDevice1, dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = ADDRESS_SDR_TYPE;

	/* command on one bit */
	spiConfigRegTransfer.command = WRITE_REGISTERS;
	spiConfigRegTransfer.commandBitSize = COMMAND_1BIT;
	spiConfigRegTransfer.commandEnable = COMMAND_ENABLED;

	/* enable data read, disable data write */
	spiConfigRegTransfer.dataReadEnable = DATA_READ_DISABLE;
	spiConfigRegTransfer.dataWriteEnable = DATA_WRITE_ENABLE;

	/* dummy cycles disabled */
	spiConfigRegTransfer.dummyCycleBitSize = DUMMY_1BIT;
	spiConfigRegTransfer.dummyCycleEnable = DUMMY_CYCLE_DISABLED;
	spiConfigRegTransfer.dummyCycles = DUMMY_1CYCLE;

	/* optional command disabled */
	spiConfigRegTransfer.optionalCommand = DUMMY_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE8_DUAL16;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	if(DUAL_MEMORY == busSize) {

		SPIBSC0.SMWDR0.UINT8[0] = statusDevice0;
		SPIBSC0.SMWDR0.UINT8[1] = statusDevice1;

	} else if (SINGLE_MEMORY == busSize) {

		SPIBSC0.SMWDR0.UINT8[0] = statusDevice0;
		SPIBSC0.SMWDR0.UINT8[1] = (uint8_t) 0x0;
	};


	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();
}

void qspiWriteStatusConfigRegister(uint8_t statusDevice0, uint8_t configDevice0, uint8_t statusDevice1, uint8_t configDevice1, dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = ADDRESS_SDR_TYPE;

	/* command on one bit */
	spiConfigRegTransfer.command = WRITE_REGISTERS;
	spiConfigRegTransfer.commandBitSize = COMMAND_1BIT;
	spiConfigRegTransfer.commandEnable = COMMAND_ENABLED;

	/* enable data read, disable data write */
	spiConfigRegTransfer.dataReadEnable = DATA_READ_DISABLE;
	spiConfigRegTransfer.dataWriteEnable = DATA_WRITE_ENABLE;

	/* dummy cycles disabled */
	spiConfigRegTransfer.dummyCycleBitSize = DUMMY_1BIT;
	spiConfigRegTransfer.dummyCycleEnable = DUMMY_CYCLE_DISABLED;
	spiConfigRegTransfer.dummyCycles = DUMMY_1CYCLE;

	/* optional command disabled */
	spiConfigRegTransfer.optionalCommand = DUMMY_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE16_DUAL32;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	if(DUAL_MEMORY == busSize) {

		SPIBSC0.SMWDR0.UINT16[0] = (uint16_t) ((statusDevice0 << 8)  | (configDevice0));
		SPIBSC0.SMWDR0.UINT16[1] = (uint16_t) ((statusDevice1 << 8)  | (configDevice1));

	} else if (SINGLE_MEMORY == busSize) {

		SPIBSC0.SMWDR0.UINT16[0] = (uint16_t) ((statusDevice0 << 8)  | (configDevice0));
		SPIBSC0.SMWDR0.UINT16[1] = (uint16_t) 0x0;
	};


	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();

}


void qspiReadStatusRegister1(uint8_t* dataDevice0, uint8_t* dataDevice1, dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = ADDRESS_SDR_TYPE;

	/* command on one bit */
	spiConfigRegTransfer.command = READ_STATUS_1;
	spiConfigRegTransfer.commandBitSize = COMMAND_1BIT;
	spiConfigRegTransfer.commandEnable = COMMAND_ENABLED;

	/* enable data read, disable data write */
	spiConfigRegTransfer.dataReadEnable = DATA_READ_ENABLE;
	spiConfigRegTransfer.dataWriteEnable = DATA_WRITE_DISABLE;

	/* dummy cycles disabled */
	spiConfigRegTransfer.dummyCycleBitSize = DUMMY_1BIT;
	spiConfigRegTransfer.dummyCycleEnable = DUMMY_CYCLE_DISABLED;
	spiConfigRegTransfer.dummyCycles = DUMMY_1CYCLE;

	/* optional command disabled */
	spiConfigRegTransfer.optionalCommand = DUMMY_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE8_DUAL16;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();

	qspiReadByte(dataDevice0, dataDevice1, busSize);


}

void qspiReadStatusRegister2(uint8_t* dataDevice0, uint8_t* dataDevice1, dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = ADDRESS_SDR_TYPE;

	/* command on one bit */
	spiConfigRegTransfer.command = READ_STATUS_2;
	spiConfigRegTransfer.commandBitSize = COMMAND_1BIT;
	spiConfigRegTransfer.commandEnable = COMMAND_ENABLED;

	/* enable data read, disable data write */
	spiConfigRegTransfer.dataReadEnable = DATA_READ_ENABLE;
	spiConfigRegTransfer.dataWriteEnable = DATA_WRITE_DISABLE;

	/* dummy cycles disabled */
	spiConfigRegTransfer.dummyCycleBitSize = DUMMY_1BIT;
	spiConfigRegTransfer.dummyCycleEnable = DUMMY_CYCLE_DISABLED;
	spiConfigRegTransfer.dummyCycles = DUMMY_1CYCLE;

	/* optional command disabled */
	spiConfigRegTransfer.optionalCommand = DUMMY_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE8_DUAL16;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();

	qspiReadByte(dataDevice0, dataDevice1, busSize);


}

void qspiReadElectronicManufacturerSignature(uint16_t* signature0, uint16_t* signature1, dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = ADDRESS_24_BITS;
	spiConfigRegTransfer.addressRateMode = ADDRESS_SDR_TYPE;

	/* command on one bit */
	spiConfigRegTransfer.command = READ_EMS;
	spiConfigRegTransfer.commandBitSize = COMMAND_1BIT;
	spiConfigRegTransfer.commandEnable = COMMAND_ENABLED;

	/* enable data read, disable data write */
	spiConfigRegTransfer.dataReadEnable = DATA_READ_ENABLE;
	spiConfigRegTransfer.dataWriteEnable = DATA_WRITE_DISABLE;

	/* dummy cycles disabled */
	spiConfigRegTransfer.dummyCycleBitSize = DUMMY_1BIT;
	spiConfigRegTransfer.dummyCycleEnable = DUMMY_CYCLE_DISABLED;
	spiConfigRegTransfer.dummyCycles = DUMMY_1CYCLE;

	/* optional command disabled */
	spiConfigRegTransfer.optionalCommand = DUMMY_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE16_DUAL32;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* de-assert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiRead2Byte(signature0, signature1, busSize);


}

void qspiReadConfigRegister(uint8_t* dataDevice0, uint8_t* dataDevice1, dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address not sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = ADDRESS_SDR_TYPE;

	/* command on one bit */
	spiConfigRegTransfer.command = READ_CONFIG;
	spiConfigRegTransfer.commandBitSize = COMMAND_1BIT;
	spiConfigRegTransfer.commandEnable = COMMAND_ENABLED;

	/* enable data read, disable data write */
	spiConfigRegTransfer.dataReadEnable = DATA_READ_ENABLE;
	spiConfigRegTransfer.dataWriteEnable = DATA_WRITE_DISABLE;

	/* dummy cycles disabled */
	spiConfigRegTransfer.dummyCycleBitSize = DUMMY_1BIT;
	spiConfigRegTransfer.dummyCycleEnable = DUMMY_CYCLE_DISABLED;
	spiConfigRegTransfer.dummyCycles = DUMMY_1CYCLE;

	/* optional command disabled */
	spiConfigRegTransfer.optionalCommand = DUMMY_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE8_DUAL16;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiReadByte(dataDevice0, dataDevice1, busSize);

}


void qspiReadBankRegister(uint8_t* dataDevice0, uint8_t* dataDevice1, dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = ADDRESS_SDR_TYPE;

	/* command on one bit */
	spiConfigRegTransfer.command = READ_BANK;
	spiConfigRegTransfer.commandBitSize = COMMAND_1BIT;
	spiConfigRegTransfer.commandEnable = COMMAND_ENABLED;

	/* enable data read, disable data write */
	spiConfigRegTransfer.dataReadEnable = DATA_READ_ENABLE;
	spiConfigRegTransfer.dataWriteEnable = DATA_WRITE_DISABLE;

	/* dummy cycles disabled */
	spiConfigRegTransfer.dummyCycleBitSize = DUMMY_1BIT;
	spiConfigRegTransfer.dummyCycleEnable = DUMMY_CYCLE_DISABLED;
	spiConfigRegTransfer.dummyCycles = DUMMY_1CYCLE;

	/* optional command disabled */
	spiConfigRegTransfer.optionalCommand = DUMMY_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE8_DUAL16;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiReadByte(dataDevice0, dataDevice1, busSize);
}

void qspiWriteBankRegister(uint8_t bankDevice0, uint8_t bankDevice1, dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = ADDRESS_SDR_TYPE;

	/* command on one bit */
	spiConfigRegTransfer.command = WRITE_BANK;
	spiConfigRegTransfer.commandBitSize = COMMAND_1BIT;
	spiConfigRegTransfer.commandEnable = COMMAND_ENABLED;

	/* enable data read, disable data write */
	spiConfigRegTransfer.dataReadEnable = DATA_READ_DISABLE;
	spiConfigRegTransfer.dataWriteEnable = DATA_WRITE_ENABLE;

	/* dummy cycles disabled */
	spiConfigRegTransfer.dummyCycleBitSize = DUMMY_1BIT;
	spiConfigRegTransfer.dummyCycleEnable = DUMMY_CYCLE_DISABLED;
	spiConfigRegTransfer.dummyCycles = DUMMY_1CYCLE;

	/* optional command disabled */
	spiConfigRegTransfer.optionalCommand = DUMMY_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE8_DUAL16;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	if(DUAL_MEMORY == busSize) {

		SPIBSC0.SMWDR0.UINT8[0] = (uint8_t) bankDevice0;
		SPIBSC0.SMWDR0.UINT8[1] = (uint8_t) bankDevice1;

	} else if (SINGLE_MEMORY == busSize) {

		SPIBSC0.SMWDR0.UINT8[0] = (uint8_t) bankDevice0;
		SPIBSC0.SMWDR0.UINT8[1] = (uint8_t) 0x0;
	};

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();

}




/* End of File */
