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
// #include "spibsc.h"
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
extern uint32_t check_image(uint32_t location);
extern void error_image(void);

/******************************************************************************
Exported global variables and functions (to be accessed by other files)
******************************************************************************/


/******************************************************************************
Private global variables and functions
******************************************************************************/
#if 0
static void test_readBytes(dataBusSize_t busSize);
#endif

#if 1
static void test_readSignature(dataBusSize_t busSize);
#endif

static externalAddressTransfer_t quadIoRead4b = {

	.addressBitSize = ADDRESS_4BIT,
	.addressEnable = ADDRESS_32_BITS,
	.command = QUAD_IO_READ_4B,
	.commandBitSize = COMMAND_1BIT,
	.commandEnable = COMMAND_ENABLED,

	.dummyCycleBitSize = DUMMY_4BIT,
	.dummyCycleEnable = DUMMY_CYCLE_ENABLED,
	.dummyCycles = DUMMY_4CYCLE,
	.extValidRange  = BITS_24,
	.extendedUpperAddress = 0x0,

	.optionalCommand = DUMMY_COMMAND,
	.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT,
	.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED,

	.optionalData.UINT32 = 0x0,
	.optionalDataBitSize = OPTIONAL_DATA_4BIT,
	.optionalDataEnable = OPTIONAL_DATA_3,

	.readBurstLenght = BURST_LEN_1,
	.burstMode = READ_BURST_ON,
	.readDataBitSize = READ_DATA_4BIT,
	.sslNegateAfterBurst = SSL_NEGATE_AFTER_BURST,

	.addressRateMode = ADDRESS_SDR_TYPE,
	.dataReadRateMode = DATA_READ_SDR_TYPE,
	.optionalDataRateMode = OPTIONAL_DATA_SDR_TYPE
};

static externalAddressTransfer_t quadRead4b = {

	.addressBitSize = ADDRESS_1BIT,
	.addressEnable = ADDRESS_32_BITS,
	.command = QUAD_READ_4B,
	.commandBitSize = COMMAND_1BIT,
	.commandEnable = COMMAND_ENABLED,

	.dummyCycleBitSize = DUMMY_4BIT,
	.dummyCycleEnable = DUMMY_CYCLE_ENABLED,
	.dummyCycles = DUMMY_8CYCLE,
	.extValidRange  = BITS_24,
	.extendedUpperAddress = 0x0,

	.optionalCommand = DUMMY_COMMAND,
	.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT,
	.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED,

	.optionalData.UINT32 = 0x0,
	.optionalDataBitSize = OPTIONAL_DATA_4BIT,
	.optionalDataEnable = OPTIONAL_DATA_DISABLED,

	.readBurstLenght = BURST_LEN_1,
	.burstMode = READ_BURST_ON,
	.readDataBitSize = READ_DATA_4BIT,
	.sslNegateAfterBurst = SSL_NEGATE_AFTER_BURST,

	.addressRateMode = ADDRESS_SDR_TYPE,
	.dataReadRateMode = DATA_READ_SDR_TYPE,
	.optionalDataRateMode = OPTIONAL_DATA_SDR_TYPE
};

static externalAddressTransfer_t fastRead4b = {

	.addressBitSize = ADDRESS_1BIT,
	.addressEnable = ADDRESS_32_BITS,
	.command = FAST_READ_4B,
	.commandBitSize = COMMAND_1BIT,
	.commandEnable = COMMAND_ENABLED,

	.dummyCycleBitSize = DUMMY_4BIT,
	.dummyCycleEnable = DUMMY_CYCLE_ENABLED,
	.dummyCycles = DUMMY_8CYCLE,
	.extValidRange  = BITS_24,
	.extendedUpperAddress = 0x0,

	.optionalCommand = DUMMY_COMMAND,
	.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT,
	.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED,

	.optionalData.UINT32 = 0x0,
	.optionalDataBitSize = OPTIONAL_DATA_4BIT,
	.optionalDataEnable = OPTIONAL_DATA_DISABLED,

	.readBurstLenght = BURST_LEN_1,
	.burstMode = READ_BURST_ON,
	.readDataBitSize = READ_DATA_1BIT,
	.sslNegateAfterBurst = SSL_NEGATE_AFTER_BURST,

	.addressRateMode = ADDRESS_SDR_TYPE,
	.dataReadRateMode = DATA_READ_SDR_TYPE,
	.optionalDataRateMode = OPTIONAL_DATA_SDR_TYPE
};

static spiConfig_t spiMode_33Mhz = {

	    // QSPI HARDWARE defines if single or dual chip
	    .dataBusSize = QSPI_HARDWARE,

		// configure the SPI mode controller registers
		.operatingMode = SPI,
		.slaveSelectPolarity = ACTIVE_LOW,
		.clockPolarity = IDLE_LOW,

		.nextAccessDelay =  NA_DELAY_1,
		.ssNegateDelay = SS_NEGATE_DELAY_1DOT5,
		.clockDelay = CLOCK_DELAY_1,

		.dataSwap = BYTE_SWAP,

		.idleValue_30_31_2bitMode = IDLE_HI_Z,
		.idleValue_20_21_2bitMode = IDLE_HI_Z,
		.idleValue_00_01_1bitInput = IDLE_HI_Z,
		.idleValue_00_01 = IDLE_HI_Z,
		.idleValue_10_11 = IDLE_HI_Z,
		.idleValue_20_21 = IDLE_HI_Z,
		.idleValue_30_31 = IDLE_HI_Z,

		// TODO: need to confirm why the odd setting works
		// should be shift on even, latch on odd (working at 33 MHz, div.ratio 4)
		.divisionRatio = DIV_RATIO_4,
		.outputShift = SHIFT_ON_EVEN_EDGE,
		.inputLatch = LATCH_ON_ODD_EDGE

};

static spiConfig_t spiMode_66Mhz = {

	    // QSPI HARDWARE defines if single or dual chip
	    .dataBusSize = QSPI_HARDWARE,

		// configure the SPI mode controller registers
		.operatingMode = SPI,
		.slaveSelectPolarity = ACTIVE_LOW,
		.clockPolarity = IDLE_LOW,

		.nextAccessDelay =  NA_DELAY_1,
		.ssNegateDelay = SS_NEGATE_DELAY_1DOT5,
		.clockDelay = CLOCK_DELAY_1,

		.dataSwap = BYTE_SWAP,

		.idleValue_30_31_2bitMode = IDLE_HI_Z,
		.idleValue_20_21_2bitMode = IDLE_HI_Z,
		.idleValue_00_01_1bitInput = IDLE_HI_Z,
		.idleValue_00_01 = IDLE_HI_Z,
		.idleValue_10_11 = IDLE_HI_Z,
		.idleValue_20_21 = IDLE_HI_Z,
		.idleValue_30_31 = IDLE_HI_Z,

		// TODO: need to confirm why the odd setting works
		// should be shift on even, latch on odd (working at 33 MHz, div.ratio 4)
		.divisionRatio = DIV_RATIO_2,
		.outputShift = SHIFT_ON_EVEN_EDGE,
		.inputLatch = LATCH_ON_EVEN_EDGE

};

typedef void (*fPtr)(void);
static spiConfig_t* spiConfiguration;
static externalAddressTransfer_t* extAddressTransfer;

void qspi_change_config_and_start_application(void)
{
	flashStatusRegister1 statusReg1_device0, statusReg1_device1;
	flashConfigRegister1 configReg1_device0, configReg1_device1;
	flashStatusRegister2 statusReg2_device0, statusReg2_device1;

    uint8_t bf_device0, bf_device1;
    deviceSignature signature0, signature1;
    uint32_t len;

    fPtr applicationEntry = (fPtr) DEF_USER_PROGRAM_SRC;

    spiConfiguration = &spiMode_33Mhz;

    qspiExternalAddressForceIdleAndWait();

    /* configure additional pins for quad mode - port 0 needed in all configurations */
	/* ==== P9_6 : SPBIO20_0 ==== */
	/* port function : SPBIO20_0    */
	RZA_IO_RegWrite_16(&GPIO.PFCAE9, 0, GPIO_PFCAE9_PFCAE96_SHIFT, GPIO_PFCAE9_PFCAE96);
	RZA_IO_RegWrite_16(&GPIO.PFCE9,  0, GPIO_PFCE9_PFCE96_SHIFT,   GPIO_PFCE9_PFCE96);
	RZA_IO_RegWrite_16(&GPIO.PFC9,   1, GPIO_PFC9_PFC96_SHIFT,     GPIO_PFC9_PFC96);
	/* port mode : Both use mode(The 2nd both use) */
	RZA_IO_RegWrite_16(&GPIO.PMC9,   1, GPIO_PMC9_PMC96_SHIFT,     GPIO_PMC9_PMC96);
	/* Input/output control mode : peripheral function */
	RZA_IO_RegWrite_16(&GPIO.PIPC9,  1, GPIO_PIPC9_PIPC96_SHIFT,   GPIO_PIPC9_PIPC96);

	/* ==== P9_7 : SPBIO30_0 ==== */
	/* port function : SPBIO30_0    */
	RZA_IO_RegWrite_16(&GPIO.PFCAE9, 0, GPIO_PFCAE9_PFCAE97_SHIFT, GPIO_PFCAE9_PFCAE97);
	RZA_IO_RegWrite_16(&GPIO.PFCE9,  0, GPIO_PFCE9_PFCE97_SHIFT,   GPIO_PFCE9_PFCE97);
	RZA_IO_RegWrite_16(&GPIO.PFC9,   1, GPIO_PFC9_PFC97_SHIFT,     GPIO_PFC9_PFC97);
	/* port mode : Both use mode(The 2nd both use) */
	RZA_IO_RegWrite_16(&GPIO.PMC9,   1, GPIO_PMC9_PMC97_SHIFT,     GPIO_PMC9_PMC97);
	/* Input/output control mode : peripheral function */
	RZA_IO_RegWrite_16(&GPIO.PIPC9,  1, GPIO_PIPC9_PIPC97_SHIFT,   GPIO_PIPC9_PIPC97);

    if (QSPI_HARDWARE == DUAL_MEMORY) {

    	// configure two additional I/O lanes for the two chip configuration
    	/* ==== P2_12 : SPBIO01_0 ==== */
    	/* port function : SPBIO01_0    */
    	RZA_IO_RegWrite_16(&GPIO.PFCAE2, 0, GPIO_PFCAE2_PFCAE212_SHIFT, GPIO_PFCAE2_PFCAE212);
    	RZA_IO_RegWrite_16(&GPIO.PFCE2,  1, GPIO_PFCE2_PFCE212_SHIFT,   GPIO_PFCE2_PFCE212);
    	RZA_IO_RegWrite_16(&GPIO.PFC2,   1, GPIO_PFC2_PFC212_SHIFT,     GPIO_PFC2_PFC212);
    	/* port mode : Both use mode(The 4th both use) */
    	RZA_IO_RegWrite_16(&GPIO.PMC2,   1, GPIO_PMC2_PMC212_SHIFT,     GPIO_PMC2_PMC212);
    	/* Input/output control mode : peripheral function */
    	RZA_IO_RegWrite_16(&GPIO.PIPC2,  1, GPIO_PIPC2_PIPC212_SHIFT,   GPIO_PIPC2_PIPC212);

    	/* ==== P2_13 : SPBIO11_0 ==== */
    	/* port function : SPBIO11_0    */
    	RZA_IO_RegWrite_16(&GPIO.PFCAE2, 0, GPIO_PFCAE2_PFCAE213_SHIFT, GPIO_PFCAE2_PFCAE213);
    	RZA_IO_RegWrite_16(&GPIO.PFCE2,  1, GPIO_PFCE2_PFCE213_SHIFT,   GPIO_PFCE2_PFCE213);
    	RZA_IO_RegWrite_16(&GPIO.PFC2,   1, GPIO_PFC2_PFC213_SHIFT,     GPIO_PFC2_PFC213);
    	/* port mode : Both use mode(The 4th both use) */
    	RZA_IO_RegWrite_16(&GPIO.PMC2,   1, GPIO_PMC2_PMC213_SHIFT,     GPIO_PMC2_PMC213);
    	/* Input/output control mode : peripheral function */
    	RZA_IO_RegWrite_16(&GPIO.PIPC2,  1, GPIO_PIPC2_PIPC213_SHIFT,   GPIO_PIPC2_PIPC213);

    	/* configure additional pins for quad mode */
    	/* ==== P2_14 : SPBIO21_0 ==== */
    	/* port function : SPBIO21_0    */
    	RZA_IO_RegWrite_16(&GPIO.PFCAE2, 0, GPIO_PFCAE2_PFCAE214_SHIFT, GPIO_PFCAE2_PFCAE214);
    	RZA_IO_RegWrite_16(&GPIO.PFCE2,  1, GPIO_PFCE2_PFCE214_SHIFT,   GPIO_PFCE2_PFCE214);
    	RZA_IO_RegWrite_16(&GPIO.PFC2,   1, GPIO_PFC2_PFC214_SHIFT,     GPIO_PFC2_PFC214);
    	/* port mode : Both use mode(The 4th both use) */
    	RZA_IO_RegWrite_16(&GPIO.PMC2,   1, GPIO_PMC2_PMC214_SHIFT,     GPIO_PMC2_PMC214);
    	/* Input/output control mode : peripheral function */
    	RZA_IO_RegWrite_16(&GPIO.PIPC2,  1, GPIO_PIPC2_PIPC214_SHIFT,   GPIO_PIPC2_PIPC214);

    	/* ==== P2_15 : SPBIO31_0 ==== */
    	/* port function : SPBIO31_0    */
    	RZA_IO_RegWrite_16(&GPIO.PFCAE2, 0, GPIO_PFCAE2_PFCAE215_SHIFT, GPIO_PFCAE2_PFCAE215);
    	RZA_IO_RegWrite_16(&GPIO.PFCE2,  1, GPIO_PFCE2_PFCE215_SHIFT,   GPIO_PFCE2_PFCE215);
    	RZA_IO_RegWrite_16(&GPIO.PFCE2,  1, GPIO_PFCE2_PFCE215_SHIFT,   GPIO_PFCE2_PFCE215);
    	RZA_IO_RegWrite_16(&GPIO.PFC2,   1, GPIO_PFC2_PFC215_SHIFT,     GPIO_PFC2_PFC215);
    	/* port mode : Both use mode(The 4th both use) */
    	RZA_IO_RegWrite_16(&GPIO.PMC2,   1, GPIO_PMC2_PMC215_SHIFT,     GPIO_PMC2_PMC215);
    	/* Input/output control mode : peripheral function */
    	RZA_IO_RegWrite_16(&GPIO.PIPC2,  1, GPIO_PIPC2_PIPC215_SHIFT,   GPIO_PIPC2_PIPC215);

    }

    // now put the controller in SPI mode, single or dual chip
    // since we need to check and configure some SPI config registers
    qspiControllerConfigure(spiConfiguration);

    qspiSoftwareReset(spiConfiguration->dataBusSize);

    statusReg1_device0.stReg1 = statusReg1_device1.stReg1 = 0;
    statusReg2_device0.stReg2 = statusReg2_device1.stReg2 = 0;

    qspiReadElectronicManufacturerSignature(&signature0, &signature1, spiConfiguration->dataBusSize);

    // check the EMS read was successful
    if(	(signature0.deviceId != S25FL512S) ||
    	(signature0.manufacturerId != SPANSION_ID))
    {
       	while(1);
    };

    if(QSPI_HARDWARE == DUAL_MEMORY) {

        if(	(signature1.deviceId != S25FL512S) ||
        	(signature1.manufacturerId != SPANSION_ID))
        {
        	while(1);
        };

    };

    qspiReadConfigRegister(&configReg1_device0, &configReg1_device1, spiConfiguration->dataBusSize);

    qspiReadStatusRegister1(&statusReg1_device0, &statusReg1_device1, spiConfiguration->dataBusSize);

    qspiReadStatusRegister2(&statusReg2_device0, &statusReg2_device1, spiConfiguration->dataBusSize);

    qspiReadBankRegister(&bf_device0, &bf_device1, spiConfiguration->dataBusSize);

    /* ---- set quad mode ---- */
	configReg1_device0.QUAD = QUAD_MODE;

	/* always clear latency code to b'00 */
	/* on RSK spansion device it means support up to 80 MHz frequency */
	configReg1_device0.LC0 = 0;
	configReg1_device0.LC1 = 0;

	if (QSPI_HARDWARE == DUAL_MEMORY) {

		configReg1_device1.QUAD = QUAD_MODE;

		configReg1_device1.LC0 = 0;
		configReg1_device1.LC1 = 0;
	}

	// enable writes to the status register
	qspiWriteEnable(spiConfiguration->dataBusSize);

	// check read enable latch is set
	qspiReadStatusRegister1(&statusReg1_device0, &statusReg1_device1, spiConfiguration->dataBusSize);

	// configure the memory for quad mode
	qspiWriteStatusConfigRegister(statusReg1_device0, configReg1_device0, statusReg1_device1, configReg1_device1, spiConfiguration->dataBusSize);

	// disable writes to the status register
	qspiWriteDisable(spiConfiguration->dataBusSize);

	// read back config and status register
	qspiReadConfigRegister(&configReg1_device0, &configReg1_device1, spiConfiguration->dataBusSize);
	qspiReadStatusRegister1(&statusReg1_device0, &statusReg1_device1, spiConfiguration->dataBusSize);

#if 0
    test_readBytes(spiConfiguration.dataBusSize);
#endif

#if 0
    test_readSignature(spiConfiguration->dataBusSize);
#endif

    // now prepare scenario for external address mode

    // configure the specific registers for external address mode
    // does not yet switch the mode
    extAddressTransfer = &quadIoRead4b;
    extAddressTransfer->optionalData.UINT8[3] = 0x00;
    qspiConfigureExternalAddressTransfer(extAddressTransfer);

    spiConfiguration = &spiMode_66Mhz;
    // change the controller configuration before reading the signature
	// has to be done here since the application is programmed in single or dual mode
    // and the signature is also stored in the same mode
    // QSPI HARDWARE defines if single or dual chip
    spiConfiguration->operatingMode = EXTERNAL_ADDRESS_SPACE;

    // switch to external address mode
    // if the application space is configured in dual mode, the "single spi" mode
    // loader flash space cannot be accessed anymore after this point
    // (without reconfiguring again)
    qspiControllerConfigure(spiConfiguration);

    // now flush the read cache
    qspiExternalAddressFlushReadCache();

    // check if there is a valid image, can read bytes in external address mode
    len = check_image(DEF_USER_SIGNATURE);

    /* If the length remaining is not zero then the signature validation failed. */
    if(0 != len)
    {
        /* This function will never return. */
    	error_image();
    }

	// jump to the program application entry point
	// does not return
    (*applicationEntry)();

    // UserProgJmp(DEF_USER_PROGRAM_SRC);

	while(1); // just in case
}


#if 1

#define SIGLENGHT 16
// limited to 50 MHz on READ+4byte address
static void test_readSignature(dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	uint8_t data0[SIGLENGHT];
	uint8_t data1[SIGLENGHT];

	uint8_t i;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = ADDRESS_32_BITS;
	spiConfigRegTransfer.addressRateMode = ADDRESS_SDR_TYPE;

	/* command on one bit */
	spiConfigRegTransfer.command = READ_4B;
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
	spiConfigRegTransfer.transferDataRateMode = TRANSFER_DATA_SDR_TYPE;

	spiConfigRegTransfer.writeData0.UINT8[0] = 0x0;
	spiConfigRegTransfer.writeData1.UINT8[0] = 0x0;

	/* deassert SSL after transfer */
	spiConfigRegTransfer.sslNegateAfterTransfer = SSL_NEGATE;

	if(SINGLE_MEMORY == busSize) {

		spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE8_DUAL16;

		for(i=0; i<(SIGLENGHT); i++) {

			spiConfigRegTransfer.address.UINT32 = (uint32_t) (0x80040 + i);
			qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);
			qspiReadByte((uint8_t*)&data0[i], (uint8_t*)&data1[i], busSize);
		}

		spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE16_DUAL32;

		for(i=0; i<(SIGLENGHT/2); i++) {

			spiConfigRegTransfer.address.UINT32 = (uint32_t) (0x80040 + (i*2));
			qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);
			qspiRead2Byte((uint16_t*)&data0[i*2], (uint16_t*)&data1[i*2], busSize);
		}

		spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE32_DUAL64;

		for(i=0; i<(SIGLENGHT/4); i++) {

			spiConfigRegTransfer.address.UINT32 = (uint32_t) (0x80040 + (i*4));
			qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);
			qspiRead4Byte((uint32_t*)&data0[i*4], (uint32_t*)&data1[i*4], busSize);
		}

	}
	else if (DUAL_MEMORY == busSize) {

		spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE8_DUAL16;

		// attention: in SPI mode with two memories I have to compute the offset for the single memory
		// any address must be divided by two to get the proper "offset" for addressing the flash
		for(i=0; i<(SIGLENGHT/2); i++) {

			spiConfigRegTransfer.address.UINT32 = (uint32_t) ((0x80040/2) + i);
			qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);
			qspiReadByte((uint8_t*)&data0[i], (uint8_t*)&data1[i], busSize);
		}

		spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE16_DUAL32;

		for(i=0; i<(SIGLENGHT/4); i++) {

			spiConfigRegTransfer.address.UINT32 = (uint32_t) ((0x80040/2) + (i*2));
			qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);
			qspiRead2Byte((uint16_t*)&data0[i*2], (uint16_t*)&data1[i*2], busSize);
		}

		spiConfigRegTransfer.transferDataEnable = TRANSFER_DATA_SINGLE32_DUAL64;

		for(i=0; i<(SIGLENGHT/8); i++) {

			spiConfigRegTransfer.address.UINT32 = (uint32_t) ((0x80040/2) + (i*4));
			qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);
			qspiRead4Byte((uint32_t*)&data0[i*4], (uint32_t*)&data1[i*4], busSize);
		}

	}

}

#endif


#if 0

#define NUM_BYTES 10
static void test_readBytes(dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	uint8_t data0[NUM_BYTES];
	uint8_t data1[NUM_BYTES];

	uint8_t i;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = ADDRESS_32_BITS;
	spiConfigRegTransfer.addressRateMode = ADDRESS_SDR_TYPE;

	/* command on one bit */
	spiConfigRegTransfer.command = READ_4B;
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

	for(i=0; i<NUM_BYTES; i++) {

		spiConfigRegTransfer.address.UINT32 = (uint32_t) (0x0 + i);
		qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);
		qspiReadByte(&data0[i], &data1[i], busSize);

	}

	for(i=0; i<NUM_BYTES; i++) {

		spiConfigRegTransfer.address.UINT32 = (uint32_t) (0x80000 + i);
		qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);
		qspiReadByte(&data0[i], &data1[i], busSize);

	}

	for(i=0; i<NUM_BYTES; i++) {

		spiConfigRegTransfer.address.UINT32 = (uint32_t) (0x80020 + i);
		qspiConfigureSpiTransfer(&spiConfigRegTransfer, busSize);
		qspiReadByte(&data0[i], &data1[i], busSize);

	}

}

#endif


/* End of File */
