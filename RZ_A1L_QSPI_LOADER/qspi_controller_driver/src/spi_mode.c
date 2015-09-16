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
#include <stdint.h>
#include "iodefine.h"
#include "spibsc_iobitmask.h"


#include "rza_io_regrw.h"


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



EXEC_RAM void qspiStartTransfer(void) {

    /* execute after setting SPNDL bit */
    RZA_IO_RegWrite_32(&SPIBSC0.SMCR, 1u, SPIBSC_SMCR_SPIE_SHIFT, SPIBSC_SMCR_SPIE);

}

// this assumes the SFDE bit is set to '1' (byte swap)
EXEC_RAM void qspiConfigureSpiTransfer(spiTransfer_t* transferConfig, dataBusSize_t busSize) {

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
	RZA_IO_RegWrite_32(&SPIBSC0.SMOPR, transferConfig->optionalData.UINT8[3], SPIBSC_SMOPR_OPD3_SHIFT, SPIBSC_SMOPR_OPD3);
	RZA_IO_RegWrite_32(&SPIBSC0.SMOPR, transferConfig->optionalData.UINT8[2], SPIBSC_SMOPR_OPD2_SHIFT, SPIBSC_SMOPR_OPD2);
	RZA_IO_RegWrite_32(&SPIBSC0.SMOPR, transferConfig->optionalData.UINT8[1], SPIBSC_SMOPR_OPD1_SHIFT, SPIBSC_SMOPR_OPD1);
	RZA_IO_RegWrite_32(&SPIBSC0.SMOPR, transferConfig->optionalData.UINT8[0], SPIBSC_SMOPR_OPD0_SHIFT, SPIBSC_SMOPR_OPD0);

    /* ---- Dummy ---- */
    RZA_IO_RegWrite_32(&SPIBSC0.SMENR, transferConfig->dummyCycleEnable, SPIBSC_SMENR_DME_SHIFT, SPIBSC_SMENR_DME);
    RZA_IO_RegWrite_32(&SPIBSC0.SMDMCR, transferConfig->dummyCycles, SPIBSC_SMDMCR_DMCYC_SHIFT, SPIBSC_SMDMCR_DMCYC);
    RZA_IO_RegWrite_32(&SPIBSC0.SMDMCR, transferConfig->dummyCycleBitSize, SPIBSC_SMDMCR_DMDB_SHIFT, SPIBSC_SMDMCR_DMDB);

    /* ---- Data ---- */
    RZA_IO_RegWrite_32(&SPIBSC0.SMENR, transferConfig->transferDataEnable, SPIBSC_SMENR_SPIDE_SHIFT, SPIBSC_SMENR_SPIDE);
    RZA_IO_RegWrite_32(&SPIBSC0.SMENR, transferConfig->transferDataBitSize, SPIBSC_SMENR_SPIDB_SHIFT, SPIBSC_SMENR_SPIDB);

    /* SDR Transmission */
    RZA_IO_RegWrite_32(&SPIBSC0.SMDRENR, transferConfig->addressRateMode, SPIBSC_SMDRENR_ADDRE_SHIFT, SPIBSC_SMDRENR_ADDRE);
    RZA_IO_RegWrite_32(&SPIBSC0.SMDRENR, transferConfig->optionalDataRateMode, SPIBSC_SMDRENR_OPDRE_SHIFT, SPIBSC_SMDRENR_OPDRE);
    RZA_IO_RegWrite_32(&SPIBSC0.SMDRENR, transferConfig->transferDataRateMode, SPIBSC_SMDRENR_SPIDRE_SHIFT, SPIBSC_SMDRENR_SPIDRE);

    /* SSL negate after transfer */
    RZA_IO_RegWrite_32(&SPIBSC0.SMCR, transferConfig->sslNegateAfterTransfer, SPIBSC_SMCR_SSLKP_SHIFT, SPIBSC_SMCR_SSLKP);

    /* data read enable and data write enable bits */
    RZA_IO_RegWrite_32(&SPIBSC0.SMCR, transferConfig->dataReadEnable, SPIBSC_SMCR_SPIRE_SHIFT, SPIBSC_SMCR_SPIRE);
    RZA_IO_RegWrite_32(&SPIBSC0.SMCR, transferConfig->dataWriteEnable, SPIBSC_SMCR_SPIWE_SHIFT, SPIBSC_SMCR_SPIWE);

    /* output zeros during register read */
    switch(transferConfig->transferDataEnable) {

    case TRANSFER_DATA_SINGLE8_DUAL16:

    	if (DUAL_MEMORY == busSize) {

    		SPIBSC0.SMWDR0.UINT16[0] = (uint16_t) ((transferConfig->writeData1.UINT8[0] << 8) | transferConfig->writeData0.UINT8[0]);

        } else if (SINGLE_MEMORY == busSize) {

        	SPIBSC0.SMWDR0.UINT8[0] = transferConfig->writeData0.UINT8[0];
        };

    	break;

    case TRANSFER_DATA_SINGLE16_DUAL32:

		if (DUAL_MEMORY == busSize) {

			SPIBSC0.SMWDR0.UINT32 = (uint32_t) (

					(transferConfig->writeData1.UINT8[1] << 24)	|
					(transferConfig->writeData0.UINT8[1] << 16) |
					(transferConfig->writeData1.UINT8[0] << 8)	|
					 transferConfig->writeData0.UINT8[0]);

		} else if (SINGLE_MEMORY == busSize) {

			SPIBSC0.SMWDR0.UINT16[0] = transferConfig->writeData0.UINT16[0];
		};

    	break;

    case TRANSFER_DATA_SINGLE32_DUAL64:

    	if (DUAL_MEMORY == busSize) {

    	    SPIBSC0.SMWDR1.UINT32 = (uint32_t) (

    	    		(transferConfig->writeData1.UINT8[1] << 24) |
					(transferConfig->writeData0.UINT8[1] << 16) |
					(transferConfig->writeData1.UINT8[0] << 8 ) |
					 transferConfig->writeData0.UINT8[0]);

	   	    SPIBSC0.SMWDR0.UINT32 = (uint32_t) (
	   	    		(transferConfig->writeData1.UINT8[3] << 24) |
					(transferConfig->writeData0.UINT8[3] << 16) |
					(transferConfig->writeData1.UINT8[2] << 8)  |
					 transferConfig->writeData0.UINT8[2]);

    	} else if (SINGLE_MEMORY == busSize) {

    	    SPIBSC0.SMWDR0.UINT32 = transferConfig->writeData0.UINT32;
    	};

    	break;

    case TRANSFER_DATA_DISABLED:

    	break;

    default:
    	while(1);
    	break;
    };

}

EXEC_RAM void qspiReadByte(uint8_t* dataDevice0, uint8_t* dataDevice1, dataBusSize_t busSize) {

	uint16_t regValue;

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();

	if(DUAL_MEMORY == busSize) {

		regValue = SPIBSC0.SMRDR0.UINT16[0];
		*dataDevice0 = (uint8_t)(regValue & 0x00FF);
		*dataDevice1 = (uint8_t)((regValue & 0xFF00) >> 8);

	} else if (SINGLE_MEMORY == busSize) {

		*dataDevice0 = (uint8_t)(SPIBSC0.SMRDR0.UINT8[0]);
		*dataDevice1 = (uint8_t) 0x0;
	};

}

// this assumes the SFDE bit is set to '1' (byte swap)
EXEC_RAM void qspiRead2Byte(uint16_t* dataDevice0, uint16_t* dataDevice1, dataBusSize_t busSize) {

	uint32_t regValue;

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();

	if(DUAL_MEMORY == busSize) {

		regValue = SPIBSC0.SMRDR0.UINT32;
		*dataDevice0 = (uint16_t)(((regValue & 0x00FF0000) >> 8)  | (regValue & 0x000000FF));
		*dataDevice1 = (uint16_t)(((regValue & 0xFF000000) >> 16) | (regValue & 0x0000FF00) >> 8);

	} else if (SINGLE_MEMORY == busSize) {

		*dataDevice0 = (uint16_t) SPIBSC0.SMRDR0.UINT16[0];
		*dataDevice1 = (uint16_t) 0x0;
	};
}

// this assumes the SFDE bit is set to '1' (byte swap)
EXEC_RAM void qspiRead4Byte(uint32_t* dataDevice0, uint32_t* dataDevice1, dataBusSize_t busSize) {

	uint32_t regValueH;
	uint32_t regValueL;

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();

	if(DUAL_MEMORY == busSize) {

		regValueH = (uint32_t) SPIBSC0.SMRDR0.UINT32;
		regValueL = (uint32_t) SPIBSC0.SMRDR1.UINT32;

		*dataDevice0 = (uint32_t)(
				((regValueH & 0x00FF0000) << 8)	|
				((regValueH & 0x000000FF) << 16)|
				((regValueL & 0x00FF0000) >> 8) |
				 (regValueL & 0x000000FF));

		*dataDevice1 = (uint32_t)(
				(regValueH 	& 0xFF000000) 		|
				((regValueH & 0x0000FF00) << 8) |
				((regValueL & 0xFF000000) >> 16)|
				((regValueL & 0x0000FF00) >> 8));

	} else if (SINGLE_MEMORY == busSize) {

		*dataDevice0 = (uint32_t)(SPIBSC0.SMRDR0.UINT32);
		*dataDevice1 = (uint32_t) 0x0;
	};
}

EXEC_RAM void qspiSoftwareReset(dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = SPI_ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = SPI_ADDRESS_SDR_TYPE;

	/* command on one bit */
	spiConfigRegTransfer.command = SOFTWARE_RESET;
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
	spiConfigRegTransfer.optionalCommand = DUMMY_OPTIONAL_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = SPI_OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_DISABLED;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* de-assert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();

}



EXEC_RAM void qspiWriteEnable(dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = SPI_ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = SPI_ADDRESS_SDR_TYPE;

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
	spiConfigRegTransfer.optionalCommand = DUMMY_OPTIONAL_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = SPI_OPTIONAL_DATA_SDR_TYPE;

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

EXEC_RAM void qspiWriteDisable(dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = SPI_ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = SPI_ADDRESS_SDR_TYPE;

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
	spiConfigRegTransfer.optionalCommand = DUMMY_OPTIONAL_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = SPI_OPTIONAL_DATA_SDR_TYPE;

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


EXEC_RAM void qspiClearStatusRegister(dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = SPI_ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = SPI_ADDRESS_SDR_TYPE;

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
	spiConfigRegTransfer.optionalCommand = DUMMY_OPTIONAL_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = SPI_OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_DISABLED;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	// dummy data
	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();
}


EXEC_RAM void qspiWriteStatusRegister(flashStatusRegister1 statusDevice0, flashStatusRegister1 statusDevice1, dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = SPI_ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = SPI_ADDRESS_SDR_TYPE;

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
	spiConfigRegTransfer.optionalCommand = DUMMY_OPTIONAL_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = SPI_OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE8_DUAL16;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;


	if(DUAL_MEMORY == busSize) {

		spiConfigRegTransfer.writeData0.UINT8[0] = statusDevice0.stReg1;
		spiConfigRegTransfer.writeData1.UINT8[0] = statusDevice1.stReg1;


	} else if (SINGLE_MEMORY == busSize) {

		spiConfigRegTransfer.writeData0.UINT8[0] = statusDevice0.stReg1;
		spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;
	};


	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();
}

EXEC_RAM void qspiWriteStatusConfigRegister(flashStatusRegister1 statusDevice0, flashConfigRegister1 configDevice0, flashStatusRegister1 statusDevice1, flashConfigRegister1 configDevice1, dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = SPI_ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = SPI_ADDRESS_SDR_TYPE;

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
	spiConfigRegTransfer.optionalCommand = DUMMY_OPTIONAL_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = SPI_OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE16_DUAL32;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	if(DUAL_MEMORY == busSize) {

		spiConfigRegTransfer.writeData0.UINT16[0] = (uint16_t) ((configDevice0.cfgReg1 << 8) | statusDevice0.stReg1);
		spiConfigRegTransfer.writeData1.UINT16[0] = (uint16_t) ((configDevice1.cfgReg1 << 8)  | (statusDevice1.stReg1));

	} else if (SINGLE_MEMORY == busSize) {

		spiConfigRegTransfer.writeData0.UINT16[0] = (uint16_t) ((configDevice0.cfgReg1 << 8) | statusDevice0.stReg1);
	};


	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();

}


EXEC_RAM void qspiReadStatusRegister1(flashStatusRegister1* dataDevice0, flashStatusRegister1* dataDevice1, dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = SPI_ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = SPI_ADDRESS_SDR_TYPE;

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
	spiConfigRegTransfer.optionalCommand = DUMMY_OPTIONAL_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = SPI_OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE8_DUAL16;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiReadByte((uint8_t*)dataDevice0, (uint8_t*)dataDevice1, busSize);


}

EXEC_RAM void qspiReadStatusRegister2(flashStatusRegister2* dataDevice0, flashStatusRegister2* dataDevice1, dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = SPI_ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = SPI_ADDRESS_SDR_TYPE;

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
	spiConfigRegTransfer.optionalCommand = DUMMY_OPTIONAL_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = SPI_OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE8_DUAL16;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiReadByte((uint8_t*)dataDevice0, (uint8_t*)dataDevice1, busSize);


}

EXEC_RAM void qspiReadElectronicManufacturerSignature(deviceSignature* signature0, deviceSignature* signature1, dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = SPI_ADDRESS_24_BITS;
	spiConfigRegTransfer.addressRateMode = SPI_ADDRESS_SDR_TYPE;

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
	spiConfigRegTransfer.optionalCommand = DUMMY_OPTIONAL_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = SPI_OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE16_DUAL32;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* de-assert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiRead2Byte((uint16_t*)signature0, (uint16_t*)signature1, busSize);


}

EXEC_RAM void qspiReadConfigRegister(flashConfigRegister1* dataDevice0, flashConfigRegister1* dataDevice1, dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address not sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = SPI_ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = SPI_ADDRESS_SDR_TYPE;

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
	spiConfigRegTransfer.optionalCommand = DUMMY_OPTIONAL_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = SPI_OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE8_DUAL16;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiReadByte((uint8_t*)dataDevice0, (uint8_t*)dataDevice1, busSize);

}


EXEC_RAM void qspiReadBankRegister(uint8_t* dataDevice0, uint8_t* dataDevice1, dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = SPI_ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = SPI_ADDRESS_SDR_TYPE;

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
	spiConfigRegTransfer.optionalCommand = DUMMY_OPTIONAL_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = SPI_OPTIONAL_DATA_SDR_TYPE;

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

EXEC_RAM void qspiWriteBankRegister(uint8_t bankDevice0, uint8_t bankDevice1, dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = SPI_ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = SPI_ADDRESS_SDR_TYPE;

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
	spiConfigRegTransfer.optionalCommand = DUMMY_OPTIONAL_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = SPI_OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE8_DUAL16;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	if(DUAL_MEMORY == busSize) {

		spiConfigRegTransfer.writeData0.UINT8[0] = bankDevice0;
		// SPIBSC0.SMWDR0.UINT8[0] = (uint8_t) bankDevice0;

		spiConfigRegTransfer.writeData1.UINT8[0] = bankDevice1;
		// SPIBSC0.SMWDR0.UINT8[1] = (uint8_t) bankDevice1;

	} else if (SINGLE_MEMORY == busSize) {

		spiConfigRegTransfer.writeData0.UINT8[0] = bankDevice0;
		// SPIBSC0.SMWDR0.UINT8[0] = (uint8_t) bankDevice0;

		spiConfigRegTransfer.writeData1.UINT8[0] = 0;
		// SPIBSC0.SMWDR0.UINT8[1] = (uint8_t) 0x0;
	};

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	qspiStartTransfer();

    /* wait for transfer-end */
    qspiControllerWaitForIdle();

}

EXEC_RAM void qspiReadIdentification(identification_t deviceId0, identification_t deviceId1, dataBusSize_t busSize) {

	uint16_t tableLenght;
	int8_t i;
	uint8_t *table0, *table1;
	spiTransfer_t spiConfigRegTransfer;

	/* address not sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = SPI_ADDRESS_DISABLED;
	spiConfigRegTransfer.addressRateMode = SPI_ADDRESS_SDR_TYPE;

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
	spiConfigRegTransfer.optionalCommand = DUMMY_OPTIONAL_COMMAND;
	spiConfigRegTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
	spiConfigRegTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

	/* optional data disabled */
	spiConfigRegTransfer.optionalData.UINT32 = 0x0;
	spiConfigRegTransfer.optionalDataBitSize = OPTIONAL_DATA_1BIT;
	spiConfigRegTransfer.optionalDataEnable = OPTIONAL_DATA_DISABLED;
	spiConfigRegTransfer.optionalDataRateMode = SPI_OPTIONAL_DATA_SDR_TYPE;

	/* transfer data size */
	spiConfigRegTransfer.transferDataBitSize = TRANSFER_DATA_1BIT;
	spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE8_DUAL16;
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SLL_KEEP;

	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);
	table0 = (uint8_t*) &deviceId0;
	table1 = (uint8_t*) &deviceId1;
	qspiRead4Byte((uint32_t*)table0, (uint32_t*)table1, busSize);

	tableLenght = deviceId0.idCfiLenght;
	if(tableLenght == 0) tableLenght = 512;

	spiConfigRegTransfer.commandEnable = COMMAND_DISABLED;
	qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);

	table0+=4;
	table1+=4;

	// read in stept of 4 bytes
	for(i=0;i<(tableLenght<<2);i++) {

		qspiRead4Byte((uint32_t*)table0, (uint32_t*)table1, busSize);
		table0+=4;
		table1+=4;
	};

	// compute the reminder
	i = (int8_t) (tableLenght - (tableLenght<<2));

	// read the reminder
	for(;i>0;i--) {

		qspiReadByte(table0, table1, busSize);
		table0+=1;
		table1+=1;
	};

}




/* End of File */
