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
extern void UserProgJmp(uint32_t addr);
extern void check_image(uint32_t location);

/******************************************************************************
Exported global variables and functions (to be accessed by other files)
******************************************************************************/


/******************************************************************************
Private global variables and functions
******************************************************************************/
#if 0
static void test_readBytes(dataBusSize_t busSize);
#endif

#define QUAD_MODE			1u
#define SERIAL_DUAL_MODE	0u
#define CFREG_QUAD_BIT      0x02          /* Quad mode bit(Configuration Register) */
#define PROGRAM_ERASE_ERROR 0x60



void qspi_change_config_and_start_application(void)
{
    uint8_t st_reg1_device0, st_reg1_device1;
    uint8_t st_reg2_device0, st_reg2_device1;
    uint8_t cf_device0, cf_device1;
    uint8_t bf_device0, bf_device1;
    uint16_t signature0, signature1;

    externalAddressTransfer_t 	externalAddressTransfer;
    spiConfig_t					spiConfiguration;

    /* Release pin function for memory control without changing pin state. */
    while(CPG.DSFR.BIT.IOKEEP == 1) {
    	CPG.DSFR.BIT.IOKEEP = 0;
    };

    qspiExternalAddressForceIdleAndWait();

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

	/* for quad mode */
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


    // configure the SPI controller for single mode SPI
    spiConfiguration.dataBusSize = SINGLE_MEMORY;
    spiConfiguration.operatingMode = SPI;
    spiConfiguration.slaveSelectPolarity = ACTIVE_LOW;
    spiConfiguration.clockPolarity = IDLE_LOW;
    spiConfiguration.nextAccessDelay =  NA_DELAY_1;
    spiConfiguration.ssNegateDelay = SS_NEGATE_DELAY_1DOT5;
    spiConfiguration.clockDelay = CLOCK_DELAY_1;
    spiConfiguration.outputShift = SHIFT_ON_EVEN_EDGE;
    spiConfiguration.inputLatch = LATCH_ON_ODD_EDGE;
    spiConfiguration.dataSwap = BYTE_SWAP;
    spiConfiguration.divisionRatio = DIV_RATIO_4; // 33.33 MHz @ 133.33 Bclk
    spiConfiguration.idleValue_30_31_2bitMode = IDLE_HI_Z;
    spiConfiguration.idleValue_20_21_2bitMode = IDLE_HI_Z;
    spiConfiguration.idleValue_00_01_1bitInput = IDLE_HI_Z;
    spiConfiguration.idleValue_00_01 = IDLE_HI_Z;
    spiConfiguration.idleValue_10_11 = IDLE_HI_Z;
    spiConfiguration.idleValue_20_21 = IDLE_HI_Z;
    spiConfiguration.idleValue_30_31 = IDLE_HI_Z;

    qspiControllerConfigure(&spiConfiguration);

    signature0 = signature1 = 0;
    st_reg1_device0 = st_reg1_device1 = 0;
    st_reg2_device0 = st_reg2_device1 = 0;

    qspiReadElectronicManufacturerSignature(&signature0, &signature1, spiConfiguration.dataBusSize);
    qspiReadConfigRegister(&cf_device0, &cf_device1, spiConfiguration.dataBusSize);
    qspiReadStatusRegister1(&st_reg1_device0, &st_reg1_device1, spiConfiguration.dataBusSize);
    qspiReadStatusRegister2(&st_reg2_device0, &st_reg2_device1, spiConfiguration.dataBusSize);
    qspiReadBankRegister(&bf_device0, &bf_device1, spiConfiguration.dataBusSize);

    /* ---- set quad mode ---- */
    if(	((cf_device0 & CFREG_QUAD_BIT) >> 1u) != QUAD_MODE)
		cf_device0 = (cf_device0 | (uint8_t) CFREG_QUAD_BIT);

    /* always clear latency code to b'00 */
	if((cf_device0 & 0xC0) != 0x0)
		cf_device0 = (cf_device0 & ((uint8_t)~0xC0));

	if (((cf_device1 & CFREG_QUAD_BIT) >> 1u) != QUAD_MODE)
		cf_device1 = (cf_device1 | (uint8_t) CFREG_QUAD_BIT);

	if((cf_device1 & 0xC0) != 0x0)
		cf_device1 = (cf_device1 & ((uint8_t)~0xC0));

	// enable writes to the status register
	qspiWriteEnable(spiConfiguration.dataBusSize);

	// check read enable latch is set
	qspiReadStatusRegister1(&st_reg1_device0, &st_reg1_device1, spiConfiguration.dataBusSize);

	qspiWriteStatusConfigRegister(st_reg1_device0, cf_device0, st_reg1_device1, cf_device1, spiConfiguration.dataBusSize);

	qspiReadConfigRegister(&cf_device0, &cf_device1, spiConfiguration.dataBusSize);
	qspiReadStatusRegister1(&st_reg1_device0, &st_reg1_device1, spiConfiguration.dataBusSize);

#if 0
    test_readBytes(spiConfiguration.dataBusSize);
#endif

    externalAddressTransfer.addressBitSize = ADDRESS_4BIT;
    externalAddressTransfer.addressEnable = ADDRESS_32_BITS;

    externalAddressTransfer.command = QUAD_IO_READ_4B;
    externalAddressTransfer.commandBitSize = COMMAND_1BIT;
    externalAddressTransfer.commandEnable = COMMAND_ENABLED;

    externalAddressTransfer.dummyCycleBitSize = DUMMY_4BIT;
    externalAddressTransfer.dummyCycleEnable = DUMMY_CYCLE_ENABLED;
    externalAddressTransfer.dummyCycles = DUMMY_4CYCLE;

    externalAddressTransfer.extValidRange  = BITS_25;
    externalAddressTransfer.extendedUpperAddress = 0x0;

    externalAddressTransfer.optionalCommand = DUMMY_COMMAND;
    externalAddressTransfer.optionalCommandBitSize = OPTIONAL_COMMAND_1BIT;
    externalAddressTransfer.optionalCommandEnable = OPTIONAL_COMMAND_DISABLED;

    externalAddressTransfer.optionalData.UINT32 = 0x0;
    externalAddressTransfer.optionalData.UINT8[3] = 0x20;
    externalAddressTransfer.optionalDataBitSize = OPTIONAL_DATA_4BIT;
    externalAddressTransfer.optionalDataEnable = OPTIONAL_DATA_3;

    externalAddressTransfer.readBurstLenght = BURST_LEN_2;
    externalAddressTransfer.burstMode = READ_BURST_ON;
    externalAddressTransfer.readDataBitSize = READ_DATA_4BIT;
    externalAddressTransfer.sslNegateAfterBurst = SSL_NEGATE_AFTER_BURST;

    externalAddressTransfer.addressRateMode = ADDRESS_SDR_TYPE;
    externalAddressTransfer.dataReadRateMode = DATA_READ_SDR_TYPE;
    externalAddressTransfer.optionalDataRateMode = OPTIONAL_DATA_SDR_TYPE;

    // configure the specific registers for external address mode
    qspiConfigureExternalAddressTransfer(&externalAddressTransfer);

    // change the controller configuration before reading the signature
	// has to be done here since the application is programmed in single or dual mode
    // and the signature is also stored in the same mode
    // QSPI HARDWARE defines if single or dual chip
    spiConfiguration.operatingMode = EXTERNAL_ADDRESS_SPACE;
    spiConfiguration.dataBusSize = QSPI_HARDWARE;

    // switch to external address mode
    // if the application space is configured in dual mode, the single mode
    // loader flash space cannot be accessed anymore after this point
    // (without reconfiguring again)
    qspiControllerConfigure(&spiConfiguration);

    // now flush the read cache
    qspiExternalAddressFlushReadCache();

    // check if there is a valid image
    // does not return in case of failure, and keeps blinking LED0
	check_image(DEF_USER_SIGNATURE);

	// jump to the program application entry point
	// does not return
	UserProgJmp(DEF_USER_PROGRAM_SRC);

	while(1); // just in case
}


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
