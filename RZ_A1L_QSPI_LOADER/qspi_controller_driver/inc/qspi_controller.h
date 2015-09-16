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
*******************************************************************************/
/*******************************************************************************
* File Name     : ascii.h
* Device(s)     : RZ/A1H (R7S721001)
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description  : This Header file contains the Macro Definitions & prototypes
*                for the functions used in lcd.c
*******************************************************************************/
/*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*               : 21.03.2014 2.00
*******************************************************************************/

/* Multiple inclusion prevention macro */
#ifndef _QSPI_CONTROLLER_H
#define _QSPI_CONTROLLER_H


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include <stdint.h>
#include "compiler_settings.h"

#include "iodefine.h"

#include "rza_io_regrw.h"


#include "qspi_setup.h"

#include "flash_type_definitions.h"

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


/******************************************************************************
* Function Name: qspi_change_config
* Description  :
* Arguments    : none
* Return Value : none
******************************************************************************/
typedef union qspiDataRegister_t
{
    uint32_t  UINT32;                                  /*  32-bit Access   */
    uint16_t  UINT16[2];                               /*  16-bit Access   */
    uint8_t   UINT8[4];                                /*  8-bit Access    */

} qspiDataRegister_t;

typedef enum operatingMode_t {

	EXTERNAL_ADDRESS_SPACE = 0,
	SPI

} operatingMode_t;

typedef enum dataSwap_t {

	NO_SWAP = 0,
	BYTE_SWAP

} dataSwap_t;

typedef enum idleValueSignal_t {

	IDLE_ZERO = 0,
	IDLE_ONE,
	IDLE_KEEP,
	IDLE_HI_Z

} idleValueSignal_t;

typedef enum outputShift_t {

	SHIFT_ON_EVEN_EDGE = 0,
	SHIFT_ON_ODD_EDGE

} outputShift_t;

typedef enum inputLatch_t {

	LATCH_ON_ODD_EDGE = 0,
	LATCH_ON_EVEN_EDGE

} inputLatch_t;

typedef enum slaveSelectPolarity_t {

	ACTIVE_LOW = 0,
	ACTIVE_HIGH

} slaveSelectPolarity_t;

typedef enum clockPolarity_t {

	IDLE_LOW = 0,
	IDLE_HIGH

} clockPolarity_t;

typedef enum dataBusSize_t {

	SINGLE_MEMORY = 0,
	DUAL_MEMORY

} dataBusSize_t;

typedef enum nextAccessDelay_t {

	NA_DELAY_1 = 0,
	NA_DELAY_2,
	NA_DELAY_3,
	NA_DELAY_4,
	NA_DELAY_5,
	NA_DELAY_6,
	NA_DELAY_7,
	NA_DELAY_8,

} nextAccessDelay_t;

typedef enum ssNegateDelay_t {

	SS_NEGATE_DELAY_1DOT5 = 0,
	SS_NEGATE_DELAY_2DOT5,
	SS_NEGATE_DELAY_3DOT5,
	SS_NEGATE_DELAY_4DOT5,
	SS_NEGATE_DELAY_5DOT5,
	SS_NEGATE_DELAY_6DOT5,
	SS_NEGATE_DELAY_7DOT5,
	SS_NEGATE_DELAY_8DOT5

} ssNegateDelay_t;

typedef enum clockDelay_t {

	CLOCK_DELAY_1 = 0,
	CLOCK_DELAY_2,
	CLOCK_DELAY_3,
	CLOCK_DELAY_4,
	CLOCK_DELAY_5,
	CLOCK_DELAY_6,
	CLOCK_DELAY_7,
	CLOCK_DELAY_8

} clockDelay_t;

typedef enum divisionRatio_t {

	DIV_RATIO_2 = 	((1u << 8) | 0u),
	DIV_RATIO_4 = 	((2u << 8) | 0u),
	DIV_RATIO_6 = 	((3u << 8) | 0u),
	DIV_RATIO_8 = 	((4u << 8) | 0u),
	DIV_RATIO_10 = 	((5u << 8) | 0u),
	DIV_RATIO_12 = 	((6u << 8) | 0u),
	DIV_RATIO_24 = 	((6u << 8) | 1u),
	DIV_RATIO_48 = 	((6u << 8) | 2u),
	DIV_RATIO_96 = 	((6u << 8) | 3u)

} divisionRatio_t;





typedef struct spiConfig_t
{
	/* CMNCR register */
	operatingMode_t 		operatingMode; 				// Spi or external address space mode
	dataSwap_t 				dataSwap;					// swap bytes
	idleValueSignal_t 		idleValue_30_31;			// default line value when SS de-asserted
	idleValueSignal_t 		idleValue_20_21;			// default line value when SS de-asserted
	idleValueSignal_t 		idleValue_10_11;			// default line value when SS de-asserted
	idleValueSignal_t		idleValue_00_01;			// default line value when SS de-asserted

	idleValueSignal_t 		idleValue_30_31_2bitMode;	// default line value when two bit communication is used
	idleValueSignal_t 		idleValue_20_21_2bitMode;	// default line value when two bit communication is used
	idleValueSignal_t 		idleValue_00_01_1bitInput;	// default line value when one bit input is used

	outputShift_t 			outputShift;				// select the edge for data shift
	inputLatch_t 			inputLatch;					// select the edge for data latch
	slaveSelectPolarity_t 	slaveSelectPolarity;		// slave select polarity
	clockPolarity_t 		clockPolarity;				// clock polarity in idle periods (SS deasserted)
	dataBusSize_t 			dataBusSize;				// one or two memories supported

	/* SSLDR register */
	nextAccessDelay_t		nextAccessDelay;			// time between successive accesses (in SPCLK cycles)
	ssNegateDelay_t			ssNegateDelay;				// time between last clock edge and SS de-assertion (in SPCLK cycles)
	clockDelay_t			clockDelay;					// time between SS assertion and first clock edge (in SPCLK cycles)

	/* SPBCR register */
	divisionRatio_t			divisionRatio;				// division ratio for SPI clock from the base peripheral clock



} spiConfig_t;




typedef enum readBurstLenght_t {

	BURST_LEN_1 = 0,
	BURST_LEN_2,
	BURST_LEN_3,
	BURST_LEN_4,
	BURST_LEN_5,
	BURST_LEN_6,
	BURST_LEN_7,
	BURST_LEN_8,
	BURST_LEN_9,
	BURST_LEN_10,
	BURST_LEN_11,
	BURST_LEN_12,
	BURST_LEN_13,
	BURST_LEN_14,
	BURST_LEN_15,
	BURST_LEN_16,

} readBurstLenght_t;

typedef enum burstOnOff_t {

	READ_BURST_OFF = 0,
	READ_BURST_ON

} burstOnOff_t;

typedef enum sslNegateAfterBurst_t {

	SSL_NEGATE_AFTER_BURST = 0,
	SLL_KEEP_AFTER_BURST

} sslNegateAfterBurst_t;





typedef enum extAddrCommand_t {

	DUMMY_COMMAND 	= 0x0,

	/* read device identification */
	READ_EMS		= 0x90,
	READ_ID			= 0x9F,
	READ_SIGNATURE	= 0xAB,
	READ_PARAMS		= 0x5A,

	/* register access */
	READ_STATUS_1  	= 0x05,
	READ_STATUS_2  	= 0x07,
	READ_CONFIG   	= 0x35,
	WRITE_REGISTERS	= 0x01,
	WRITE_CONFIG 	= 0x01,
	WRITE_DISABLE	= 0x04,
	WRITE_ENABLE  	= 0x06,
	CLEAR_STATUS  	= 0x30,
	READ_AUTOBOOT 	= 0x14,
	WRITE_AUTOBOOT 	= 0x15,
	READ_BANK     	= 0x16,
	WRITE_BANK    	= 0x17,
	BRAC			= 0xB9,
	DLRP_READ		= 0x41,
	PROG_NV_DLR		= 0x43,
	WRITE_V_DLR		= 0x4A,

	/* read flash array */
	READ				= 0x03,	// single output, 3 + bank or 4 bytes address (extadd bit in Bank Address Register)
	READ_4B				= 0x13,	// single output, 4 byte address
	FAST_READ			= 0x0B, // single output, 3 + bank or 4 bytes address (extadd bit in Bank Address Register)
	FAST_READ_4B		= 0x0C, // single output, 4 byte address

	READ_DUAL			= 0x3B, // dual output, 3 + bank or 4 bytes address (extadd bit in Bank Address Register)
	READ_DUAL_4B		= 0x3C, // dual output, 4 bytes address
	QUAD_READ			= 0x6B, // quad output, 3 + bank or 4 bytes address (extadd bit in Bank Address Register)
	QUAD_READ_4B		= 0x6C, // quad output, 4 bytes address
	DUAL_IO_READ  		= 0xBB, // dual output, dual 3 + bank or 4 bytes address (extadd bit in Bank Address Register)
	DUAL_IO_READ_4B		= 0xBC, // dual output, dual 4 bytes address
	QUAD_IO_READ  		= 0xEB, // quad output, quad 3 + bank or 4 bytes address (extadd bit in Bank Address Register)
	QUAD_IO_READ_4B		= 0xEC, // quad output, quad 4 bytes address

	DDR_FAST_READ		= 0x0D,
	DDR_FAST_READ_4B	= 0x0E,
	DDR_DUAL_IO_READ	= 0xBD,
	DDR_DUAL_IO_READ_4B	= 0xBE,
	DDR_QUAD_IO_READ  	= 0xED,
	DDR_QUAD_IO_READ_4B	= 0xEE,

	/* program flash array */
	PAGE_PROGRAM 			= 0x02,		// single output, 3 + bank or 4 bytes address (extadd bit in Bank Address Register)
	PAGE_PROGRAM_4B			= 0x12,		// single output, 4 byte address
	QUAD_PAGE_PROGRAM  		= 0x32,		// quad output, 3 + bank or 4 bytes address (extadd bit in Bank Address Register)
	QUAD_PAGE_PROGRAM_4B	= 0x34,		// quad output, 4 bytes address
	PROGRAM_SUSPEND			= 0x85,
	PROGRAM_RESUME			= 0x8A,

	/* erase flash array */
	BULK_ERASE 		= 0xC7,
	SECTOR_ERASE 	= 0xD8,			// sector erase, quad 3 + bank or 4 bytes address (extadd bit in Bank Address Register)
	SECTOR_ERASE_4B	= 0xDC,			// sector erase, 4 bytes address
	ERASE_SUSPEND	= 0x75,
	ERASE_RESUME	= 0x7A,


	/* reset */
	SOFTWARE_RESET 	= 0xF0,
	MODE_BIT_RESET	= 0xFF

} extAddrCommand_t;

typedef enum extAddrOptionalCommand_t {

	DUMMY_OPT_COMMAND = 0,


} extAddrOptionalCommand_t;

typedef enum extAddrValidRange_t {

	BITS_24 = 0,
	BITS_25


} extAddrValidRange_t;

typedef enum commandBitSize_t {

	COMMAND_1BIT = 0,
	COMMAND_2BIT,
	COMMAND_4BIT

} commandBitSize_t;

typedef enum commandEnable_t {

	COMMAND_DISABLED = 0,
	COMMAND_ENABLED,

} commandEnable_t;

typedef enum optionalCommandBitSize_t {

	OPTIONAL_COMMAND_1BIT = 0,
	OPTIONAL_COMMAND_2BIT,
	OPTIONAL_COMMAND_4BIT

} optionalCommandBitSize_t;

typedef enum optionalCommandEnable_t {

	OPTIONAL_COMMAND_DISABLED = 0,
	OPTIONAL_COMMAND_ENABLED,

} optionalCommandEnable_t;

typedef enum addressBitSize_t {

	ADDRESS_1BIT = 0,
	ADDRESS_2BIT,
	ADDRESS_4BIT

} addressBitSize_t;

typedef enum addressEnable_t {

	ADDRESS_DISABLED = 0,
	ADDRESS_24_BITS = 0x7,	// bits 23:0 for one chip, 24:1 for two chips
	ADDRESS_32_BITS = 0xF 	// bits 31:0 for one chip, 32:1 for two chips

} addressEnable_t;

typedef enum optionalDataBitSize_t {

	OPTIONAL_DATA_1BIT = 0,
	OPTIONAL_DATA_2BIT,
	OPTIONAL_DATA_4BIT

} optionalDataBitSize_t;

typedef enum optionalDataEnable_t {

	OPTIONAL_DATA_DISABLED 	= 0,
	OPTIONAL_DATA_3 		= 0x8,
	OPTIONAL_DATA_32		= 0xC,
	OPTIONAL_DATA_321		= 0xE,
	OPTIONAL_DATA_3210		= 0xF

} optionalDataEnable_t;

typedef enum readDataBitSize_t {

	READ_DATA_1BIT = 0,
	READ_DATA_2BIT,
	READ_DATA_4BIT

} readDataBitSize_t;


typedef enum dummyCycleNumber_t {

	DUMMY_1CYCLE = 0,
	DUMMY_2CYCLE,
	DUMMY_3CYCLE,
	DUMMY_4CYCLE,
	DUMMY_5CYCLE,
	DUMMY_6CYCLE,
	DUMMY_7CYCLE,
	DUMMY_8CYCLE

} dummyCycleNumber_t;

typedef enum dummyCycleBitSize_t {

	DUMMY_1BIT = 0,
	DUMMY_2BIT,
	DUMMY_4BIT

} dummyCycleBitSize_t;

typedef enum dummyCycleEnable_t {

	DUMMY_CYCLE_DISABLED = 0,
	DUMMY_CYCLE_ENABLED,

} dummyCycleEnable_t;

typedef enum addressDdrEnable_t {

	ADDRESS_SDR_TYPE = 0,
	ADDRESS_DDR_TYPE,

} addressDdrEnable_t;

typedef enum optionalDataDdrEnable_tag {

	OPTIONAL_DATA_SDR_TYPE = 0,
	OPTIONAL_DATA_DDR_TYPE,

} optionalDataDdrEnable_t;

typedef enum dataReadDdrEnable_t {

	DATA_READ_SDR_TYPE = 0,
	DATA_READ_DDR_TYPE,

} dataReadDdrEnable_t;


typedef struct externalAddressSpaceMode_t {

	/* DRCR register */
	readBurstLenght_t			readBurstLenght;			// read burst length when in external address space mode
	burstOnOff_t				burstMode;					// activate or not burst mode
	sslNegateAfterBurst_t		sslNegateAfterBurst;		// negate ssl when finished or when address not contiguous

	/* DRCMR register */
	extAddrCommand_t			command;					// command for external address space mode
	extAddrOptionalCommand_t	optionalCommand;			// optional command for external address space mode

	/* DREAR register */
	uint8_t						extendedUpperAddress;
	extAddrValidRange_t			extValidRange;				// range of addresses when in 32-bit address mode

	/* DROPR register */
	qspiDataRegister_t			optionalData;

	/* DRENR register */
	commandBitSize_t			commandBitSize;
	optionalCommandBitSize_t	optionalCommandBitSize;
	addressBitSize_t			addressBitSize;
	optionalDataBitSize_t		optionalDataBitSize;
	readDataBitSize_t			readDataBitSize;

	commandEnable_t				commandEnable;
	optionalCommandEnable_t		optionalCommandEnable;
	addressEnable_t				addressEnable;
	optionalDataEnable_t		optionalDataEnable;
	dummyCycleEnable_t			dummyCycleEnable;

	/* DRDMCR register */
	dummyCycleBitSize_t			dummyCycleBitSize;
	dummyCycleNumber_t			dummyCycles;

	addressDdrEnable_t			addressRateMode;
	optionalDataDdrEnable_t		optionalDataRateMode;
	dataReadDdrEnable_t			dataReadRateMode;

} externalAddressTransfer_t;


typedef enum sslNegateAfterTransfer_t {

	SSL_NEGATE = 0,
	SLL_KEEP

} sslNegateAfterTransfer_t;

typedef enum dataReadEnable_t {

	DATA_READ_DISABLE = 0,
	DATA_READ_ENABLE


} dataReadEnable_t;

typedef enum dataWriteEnable_t {

	DATA_WRITE_DISABLE = 0,
	DATA_WRITE_ENABLE

} dataWriteEnable_t;

typedef extAddrCommand_t spiCommand_t;

typedef enum spiOptionalCommand_t {

	DUMMY_OPTIONAL_COMMAND = 0,

} spiOptionalCommand_t;

typedef union qspiAddress_t
{
    uint32_t  UINT32;                                  /*  32-bit Access   */
    struct {
    	uint8_t   upperByte;
    	uint8_t   UINT8[3];                                /*  8-bit Access    */
    };

} qspiAddress_t;

typedef enum transferDataBitSize_t {

	TRANSFER_DATA_1BIT = 0,
	TRANSFER_DATA_2BIT,
	TRANSFER_DATA_4BIT

} transferDataBitSize_t;


typedef enum spiAddressEnable_t {

	SPI_ADDRESS_DISABLED	= 0,
	SPI_ADDRESS_8_BITS		= 0x4,  // bits 23:16
	SPI_ADDRESS_16_BITS 	= 0x6,	// bits 23:8
	SPI_ADDRESS_24_BITS 	= 0x7,	// bits 23:0
	SPI_ADDRESS_32_BITS 	= 0xF 	// bits 31:0

} spiAddressEnable_t;

typedef enum transferDataEnable_t {

	TRANSFER_DATA_DISABLED			= 0,
	TRANSFER_DATA_SINGLE8_DUAL16	= 0x8,  // data to reg0[0] (single chip) reg0[0,1] (dual chip)
	TRANSFER_DATA_SINGLE16_DUAL32	= 0xC,  // data to reg0[0,1] (single chip) reg0[2,3] (dual chip)
	TRANSFER_DATA_SINGLE32_DUAL64	= 0xF,  // data to reg0[0,3] (single chip) reg1[0,3] (dual chip)

} transferDataEnable_t;


typedef enum spiAddressDdrEnable_t {

	SPI_ADDRESS_SDR_TYPE = 0,
	SPI_ADDRESS_DDR_TYPE,

} spiAddressDdrEnable_t;

typedef enum spiOptionalDataDdrEnable_t {

	SPI_OPTIONAL_DATA_SDR_TYPE = 0,
	SP_OPTIONAL_DATA_DDR_TYPE,

} spiOptionalDataDdrEnable_t;

typedef enum spiDataTransferDdrEnable_t {

	TRANSFER_DATA_SDR_TYPE = 0,
	TRANSFER_DATA_DDR_TYPE,

} spiDataTransferDdrEnable_t;

typedef struct
{

	/* SMCR register */
	sslNegateAfterTransfer_t	sslNegateAfterTransfer;		// negate ssl when finished
	dataWriteEnable_t			dataWriteEnable;
	dataReadEnable_t			dataReadEnable;

	/* SMCMR register */
	spiCommand_t				command;
	spiOptionalCommand_t		optionalCommand;

	/* SMADR */
	qspiAddress_t 				address;

	/* SMOPR register */
	qspiDataRegister_t			optionalData;

	/* SMENR register */
	commandBitSize_t			commandBitSize;
	optionalCommandBitSize_t	optionalCommandBitSize;
	addressBitSize_t			addressBitSize;
	optionalDataBitSize_t		optionalDataBitSize;
	transferDataBitSize_t		transferDataBitSize;

	commandEnable_t				commandEnable;
	optionalCommandEnable_t		optionalCommandEnable;
	spiAddressEnable_t			addressEnable;
	optionalDataEnable_t		optionalDataEnable;
	dummyCycleEnable_t			dummyCycleEnable;
	transferDataEnable_t		transferDataEnable;

	/* SMDMCR register */
	dummyCycleBitSize_t			dummyCycleBitSize;
	dummyCycleNumber_t			dummyCycles;

	/* SMDRENR register */
	spiAddressDdrEnable_t		addressRateMode;
	spiOptionalDataDdrEnable_t	optionalDataRateMode;
	spiDataTransferDdrEnable_t	transferDataRateMode;

	qspiDataRegister_t writeData0; // write data register for chip0
	qspiDataRegister_t writeData1; // write data register for chip1

} spiTransfer_t;

#define TRANSFER_END				(0x1)
#define EXTADDRESS_MODE_FORCE_IDLE	(1u <<24)
#define SLAVESELECT_PIN_MONITOR		(0x2)

// configuration functions for QSPI controller
EXEC_RAM void qspiControllerConfigure(spiConfig_t* spiConfig);
EXEC_RAM void qspiControllerWaitForIdle(void);
EXEC_RAM void qspiControllerSetPortMode(uint8_t singleDualMode);

// functions for SPI Mode
EXEC_RAM void qspiConfigureSpiTransfer(spiTransfer_t* transferConfig, dataBusSize_t busSize);
EXEC_RAM void qspiReadByte(uint8_t* dataDevice0, uint8_t* dataDevice1, dataBusSize_t busSize);
EXEC_RAM void qspiRead2Byte(uint16_t* dataDevice0, uint16_t* dataDevice1, dataBusSize_t busSize);
EXEC_RAM void qspiRead4Byte(uint32_t* dataDevice0, uint32_t* dataDevice1, dataBusSize_t busSize);
EXEC_RAM void qspiStartTransfer(void);

EXEC_RAM void qspiReadIdentification(identification_t deviceId0, identification_t deviceId1, dataBusSize_t busSize);
EXEC_RAM void qspiSoftwareReset(dataBusSize_t busSize);
EXEC_RAM void qspiReadStatusRegister1(flashStatusRegister1* dataDevice0, flashStatusRegister1* dataDevice1, dataBusSize_t busSize);
EXEC_RAM void qspiReadStatusRegister2(flashStatusRegister2* dataDevice0, flashStatusRegister2* dataDevice1, dataBusSize_t busSize);
EXEC_RAM void qspiReadConfigRegister(flashConfigRegister1* dataDevice0, flashConfigRegister1* dataDevice1, dataBusSize_t busSize);
EXEC_RAM void qspiReadBankRegister(uint8_t* dataDevice0, uint8_t* dataDevice1, dataBusSize_t busSize);
EXEC_RAM void qspiWriteBankRegister(uint8_t dataDevice0, uint8_t dataDevice1, dataBusSize_t busSize);
EXEC_RAM void qspiWriteEnable(dataBusSize_t busSize);
EXEC_RAM void qspiWriteDisable(dataBusSize_t busSize);
EXEC_RAM void qspiClearStatusRegister(dataBusSize_t busSize);
EXEC_RAM void qspiWriteStatusRegister(flashStatusRegister1 statusDevice0, flashStatusRegister1 statusDevice1, dataBusSize_t busSize);
EXEC_RAM void qspiWriteStatusConfigRegister(flashStatusRegister1 statusDevice0, flashConfigRegister1 configDevice0, flashStatusRegister1 statusDevice1, flashConfigRegister1 configDevice1, dataBusSize_t busSize);
EXEC_RAM void qspiReadElectronicManufacturerSignature(deviceSignature* signature0, deviceSignature* signature1, dataBusSize_t busSize);

// functions for External Address Mode
EXEC_RAM void qspiExternalAddressForceIdleAndWait(void);
EXEC_RAM void qspiConfigureExternalAddressTransfer(const externalAddressTransfer_t* externalAddressTransferConfig);
EXEC_RAM void qspiExternalAddressFlushReadCache(void);




#endif

/* End of File */


