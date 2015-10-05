/*
* Copyright 2015 Giancarlo Parodi
* 
* qspi_change_config.c
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

#include "compiler_settings.h"
#include "iodefine.h"
#include "rza_io_regrw.h"

#include "qspi_controller.h"

#define BYTEREAD_TEST 0

#if BYTEREAD_TEST
EXEC_RAM static void test_readBytes(dataBusSize_t busSize);
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
  
  .optionalCommand = DUMMY_OPT_COMMAND,
  .optionalCommandBitSize = OPTIONAL_COMMAND_1BIT,
  .optionalCommandEnable = OPTIONAL_COMMAND_DISABLED,
  
  .optionalData.UINT32 = 0x0,
  .optionalDataBitSize = OPTIONAL_DATA_4BIT,
  .optionalDataEnable = OPTIONAL_DATA_3,
  
  .readBurstLenght = BURST_LEN_4,
  .burstMode = READ_BURST_ON,
  .readDataBitSize = READ_DATA_4BIT,
  .sslNegateAfterBurst = SSL_NEGATE_AFTER_BURST,
  
  .addressRateMode = ADDRESS_SDR_TYPE,
  .dataReadRateMode = DATA_READ_SDR_TYPE,
  .optionalDataRateMode = OPTIONAL_DATA_SDR_TYPE
};

/*
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
  
  .optionalCommand = DUMMY_OPT_COMMAND,
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
*/

/*
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
  
  .optionalCommand = DUMMY_OPT_COMMAND,
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
*/

static spiConfig_t spiMode_33Mhz = {

  .dataBusSize = QSPI_HARDWARE,
  
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
  
  .divisionRatio = DIV_RATIO_4,
  .outputShift = SHIFT_ON_EVEN_EDGE,
  .inputLatch = LATCH_ON_EVEN_EDGE

};

static spiConfig_t spiMode_66Mhz = {

  .dataBusSize = QSPI_HARDWARE,
  
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
  
  /*
   * With division ratio 2, the latching is done on the even edge
   * instead of the odd edge, to keep the setup time of the QSPI controller.
   * In theory should have been shift on even, latch on odd
  */
  .divisionRatio = DIV_RATIO_2,
  .outputShift = SHIFT_ON_EVEN_EDGE,
  .inputLatch = LATCH_ON_EVEN_EDGE

};


static spiConfig_t* spiConfiguration;
static externalAddressTransfer_t* extAddressTransfer;

typedef void (*fPtr)(void);

EXEC_RAM void qspiReconfigure(void)
{
  flashStatusRegister1 statusReg1_device0, statusReg1_device1;
  flashConfigRegister1 configReg1_device0, configReg1_device1;
  flashStatusRegister2 statusReg2_device0, statusReg2_device1;
  
  deviceSignature signature0, signature1;
  
  fPtr applicationEntry = (fPtr) DEF_USER_PROGRAM_SRC;  
  
  qspiExternalAddressForceIdleAndWait();
    
  /* 
  * The default SPI pins are configured by the ROM bootloader when 
  * booting from QSPI
  *
  * On RZ/A1-L these are configured by the bootloader :
  * P4.4 SPBCLK0
  * P4.5 SPBSSL0
  * P4.6 SPBIO00 / SPBM00
  * P4.7 SPBIO10 / SPBMI0  
  *
  * To support QUAD mode the following are required:
  * P4.2 SPBIO20
  * P4.3 SPBIO30
  */
  
  /* 
  * Configure additional pins for quad mode 
  * Port 0 is needed in all configurations since it must be attached for 
  * QSPI boot
  */

    
  /* P4_2: SPBIO20_0 */
  RZA_IO_RegWrite_16(&GPIO.PFCAE4, 0, GPIO_PFCAE4_PFCAE42_SHIFT, GPIO_PFCAE4_PFCAE42);
  RZA_IO_RegWrite_16(&GPIO.PFCE4,  0, GPIO_PFCE4_PFCE42_SHIFT,   GPIO_PFCE4_PFCE42);
  RZA_IO_RegWrite_16(&GPIO.PFC4,   1, GPIO_PFC4_PFC42_SHIFT,     GPIO_PFC4_PFC42);
  RZA_IO_RegWrite_16(&GPIO.PMC4,   1, GPIO_PMC4_PMC42_SHIFT,     GPIO_PMC4_PMC42);
  RZA_IO_RegWrite_16(&GPIO.PIPC4,  1, GPIO_PIPC4_PIPC42_SHIFT,   GPIO_PIPC4_PIPC42);    
  
  /* P4_3: SPBIO30_0 */
  RZA_IO_RegWrite_16(&GPIO.PFCAE4, 0, GPIO_PFCAE4_PFCAE43_SHIFT, GPIO_PFCAE4_PFCAE43);
  RZA_IO_RegWrite_16(&GPIO.PFCE4,  0, GPIO_PFCE4_PFCE43_SHIFT,   GPIO_PFCE4_PFCE43);
  RZA_IO_RegWrite_16(&GPIO.PFC4,   1, GPIO_PFC4_PFC43_SHIFT,     GPIO_PFC4_PFC43);
  RZA_IO_RegWrite_16(&GPIO.PMC4,   1, GPIO_PMC4_PMC43_SHIFT,     GPIO_PMC4_PMC43);
  RZA_IO_RegWrite_16(&GPIO.PIPC4,  1, GPIO_PIPC4_PIPC43_SHIFT,   GPIO_PIPC4_PIPC43);  

  /* 
  * When dual mode is used, we need 4 additional lines for channel 1 
  *
  * On RZ/A1-H these need to be added for channel 2:
  * P2.12 SPBIO01_0
  * P2.13 SPBIO11_0
  * P2.14 SPBIO21_0
  * P2.15 SPBIO31_0    
  */
  
  if (QSPI_HARDWARE == DUAL_MEMORY) {
    
    /* 
    * Clock and slave select must be connected to the same ports used in channel 0
    * for the first QSPI Flash chip (P4.4 and P4.5)
    * 
    * Now we add the additional data lanes for the second chip 
    *   
    */
    /* P3_10: SPBIO01_0 */
    RZA_IO_RegWrite_16(&GPIO.PFCAE3, 0, GPIO_PFCAE3_PFCAE310_SHIFT, GPIO_PFCAE3_PFCAE310);
    RZA_IO_RegWrite_16(&GPIO.PFCE3,  0, GPIO_PFCE3_PFCE310_SHIFT,   GPIO_PFCE3_PFCE310);
    RZA_IO_RegWrite_16(&GPIO.PFC3,   1, GPIO_PFC3_PFC310_SHIFT,     GPIO_PFC3_PFC310);
    RZA_IO_RegWrite_16(&GPIO.PMC3,   1, GPIO_PMC3_PMC310_SHIFT,     GPIO_PMC3_PMC310);
    RZA_IO_RegWrite_16(&GPIO.PIPC3,  1, GPIO_PIPC3_PIPC310_SHIFT,   GPIO_PIPC3_PIPC310);    
    
    
    /* P3_11: SPBIO11_0 */
    RZA_IO_RegWrite_16(&GPIO.PFCAE3, 0, GPIO_PFCAE3_PFCAE311_SHIFT, GPIO_PFCAE3_PFCAE311);
    RZA_IO_RegWrite_16(&GPIO.PFCE3,  0, GPIO_PFCE3_PFCE311_SHIFT,   GPIO_PFCE3_PFCE311);
    RZA_IO_RegWrite_16(&GPIO.PFC3,   1, GPIO_PFC3_PFC311_SHIFT,     GPIO_PFC3_PFC311);
    RZA_IO_RegWrite_16(&GPIO.PMC3,   1, GPIO_PMC3_PMC311_SHIFT,     GPIO_PMC3_PMC311);
    RZA_IO_RegWrite_16(&GPIO.PIPC3,  1, GPIO_PIPC3_PIPC311_SHIFT,   GPIO_PIPC3_PIPC311);      
    
    
    /* P3_12: SPBIO21_0 */
    RZA_IO_RegWrite_16(&GPIO.PFCAE3, 0, GPIO_PFCAE3_PFCAE312_SHIFT, GPIO_PFCAE3_PFCAE312);
    RZA_IO_RegWrite_16(&GPIO.PFCE3,  0, GPIO_PFCE3_PFCE312_SHIFT,   GPIO_PFCE3_PFCE312);
    RZA_IO_RegWrite_16(&GPIO.PFC3,   1, GPIO_PFC3_PFC312_SHIFT,     GPIO_PFC3_PFC312);
    RZA_IO_RegWrite_16(&GPIO.PMC3,   1, GPIO_PMC3_PMC312_SHIFT,     GPIO_PMC3_PMC312);
    RZA_IO_RegWrite_16(&GPIO.PIPC3,  1, GPIO_PIPC3_PIPC312_SHIFT,   GPIO_PIPC3_PIPC312);   
    
    /* P3_13: SPBIO31_0 */
    RZA_IO_RegWrite_16(&GPIO.PFCAE3, 0, GPIO_PFCAE3_PFCAE313_SHIFT, GPIO_PFCAE3_PFCAE313);
    RZA_IO_RegWrite_16(&GPIO.PFCE3,  0, GPIO_PFCE3_PFCE313_SHIFT,   GPIO_PFCE3_PFCE313);
    RZA_IO_RegWrite_16(&GPIO.PFC3,   1, GPIO_PFC3_PFC313_SHIFT,     GPIO_PFC3_PFC313);
    RZA_IO_RegWrite_16(&GPIO.PMC3,   1, GPIO_PMC3_PMC313_SHIFT,     GPIO_PMC3_PMC313);
    RZA_IO_RegWrite_16(&GPIO.PIPC3,  1, GPIO_PIPC3_PIPC313_SHIFT,   GPIO_PIPC3_PIPC313);
    
  }
  
  /* After boot the controller is in external address mode
   * To change the configuration we need to put the controller back in SPI mode
   * Note:
   * Some commands might not use the fastest frequencies.
   * Choose 33 MHz
   */
  spiConfiguration = &spiMode_33Mhz;
  qspiControllerConfigure(spiConfiguration);
  
  /* Send a software reset to the Flash devices */
  qspiSoftwareReset(spiConfiguration->dataBusSize);
  
  statusReg1_device0.stReg1 = statusReg1_device1.stReg1 = 0;
  statusReg2_device0.stReg2 = statusReg2_device1.stReg2 = 0;
  
  /* Read out the manufacturer signature */
  /* TODO: may change to use "new" CFI information instead of the legacy READ_EMS command */
  qspiReadElectronicManufacturerSignature(&signature0, &signature1, spiConfiguration->dataBusSize);
  
  /* check the EMS read was successful */
  /* Stop booting if the flash is not recognized */
  if((signature0.deviceId != S25FL512S) || (signature0.manufacturerId != SPANSION_ID))
  {
    while(1);
  };
  
  if(QSPI_HARDWARE == DUAL_MEMORY) {
    
    if(	(signature1.deviceId != S25FL512S) || (signature1.manufacturerId != SPANSION_ID))
    {
      while(1);
    };
    
  };
  
  /* Read out the configuration and status registers */
  qspiReadConfigRegister(&configReg1_device0, &configReg1_device1, spiConfiguration->dataBusSize);
  qspiReadStatusRegister1(&statusReg1_device0, &statusReg1_device1, spiConfiguration->dataBusSize);
  qspiReadStatusRegister2(&statusReg2_device0, &statusReg2_device1, spiConfiguration->dataBusSize);
    
  /* Now configure for quad mode */
  configReg1_device0.QUAD = QUAD_MODE;
  
  /* always clear latency code to b'00 */
  /* on RSK Spansion Flash device it means supporting up to 80 MHz clock frequency */
  /* Slower frequencies can use the same latency code for faster frequency */
  configReg1_device0.LC0 = 0;
  configReg1_device0.LC1 = 0;
  
  if (QSPI_HARDWARE == DUAL_MEMORY) {
    
    configReg1_device1.QUAD = QUAD_MODE;
    
    configReg1_device1.LC0 = 0;
    configReg1_device1.LC1 = 0;
  }
  
  /* enable writing to the status register */
  qspiWriteEnable(spiConfiguration->dataBusSize);
  
  /* verify the read enable latch in the register is set */
  qspiReadStatusRegister1(&statusReg1_device0, &statusReg1_device1, spiConfiguration->dataBusSize);
  
  /* write back and configure the memory for quad mode */
  qspiWriteStatusConfigRegister(statusReg1_device0, configReg1_device0, statusReg1_device1, configReg1_device1, spiConfiguration->dataBusSize);
  
  /* now disable writes to the status register */
  qspiWriteDisable(spiConfiguration->dataBusSize);
   
#if BYTEREAD_TEST
  test_readBytes(spiConfiguration->dataBusSize);
#endif
  
  /* now prepare scenario for external address mode */
  /*
  * Switch to external address mode
  * Note: if the application space is configured in dual mode, the
  * "single spi" mode loader flash address space cannot be accessed anymore
  * after this point without reconfiguring again the controller
  */
  extAddressTransfer = &quadIoRead4b;
  extAddressTransfer->optionalData.UINT8[3] = 0x00;
  qspiConfigureExternalAddressTransfer(extAddressTransfer);
  
  spiConfiguration = &spiMode_66Mhz;
  spiConfiguration->operatingMode = EXTERNAL_ADDRESS_SPACE;

  qspiControllerConfigure(spiConfiguration);

  /* flush the read cache */
  qspiExternalAddressFlushReadCache();  
  
  /* now jump to the program application entry point */
  (*applicationEntry)();
  
  while(1);
}




#if BYTEREAD_TEST

#define NUM_BYTES 10
EXEC_RAM static void test_readBytes(dataBusSize_t busSize) {

	spiTransfer_t spiConfigRegTransfer;

	uint8_t data0[NUM_BYTES];
	uint8_t data1[NUM_BYTES];

	uint8_t i;

	/* address  sent */
	spiConfigRegTransfer.address.UINT32 = 0x0;
	spiConfigRegTransfer.addressBitSize = ADDRESS_1BIT;
	spiConfigRegTransfer.addressEnable = SPI_ADDRESS_32_BITS;
	spiConfigRegTransfer.addressRateMode = SPI_ADDRESS_SDR_TYPE;

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


