/*
* Copyright 2015 Giancarlo Parodi
* 
* qspi_controller.c
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


#include "iodefine.h"
#include "spibsc_iobitmask.h"
#include "rza_io_regrw.h"

#include "qspi_controller.h"

const FLASH_TYPE flashModel =  SPANSION_S25FL512S;


EXEC_RAM void qspiControllerConfigure(spiConfig_t* spiConfig) {


	/* set mode SPI or external address space */
	RZA_IO_RegWrite_32(&SPIBSC0.CMNCR, spiConfig->operatingMode, SPIBSC_CMNCR_MD_SHIFT, SPIBSC_CMNCR_MD);

	/* set to single or dual memory */
	RZA_IO_RegWrite_32(&SPIBSC0.CMNCR, spiConfig->dataBusSize, SPIBSC_CMNCR_BSZ_SHIFT, SPIBSC_CMNCR_BSZ);

	/* write edge */
	RZA_IO_RegWrite_32(&SPIBSC0.CMNCR, spiConfig->outputShift, SPIBSC_CMNCR_CPHAT_SHIFT, SPIBSC_CMNCR_CPHAT);
	/* read edge */
	RZA_IO_RegWrite_32(&SPIBSC0.CMNCR, spiConfig->inputLatch, SPIBSC_CMNCR_CPHAR_SHIFT, SPIBSC_CMNCR_CPHAR);
	/* SSL  */
	RZA_IO_RegWrite_32(&SPIBSC0.CMNCR, spiConfig->slaveSelectPolarity, SPIBSC_CMNCR_SSLP_SHIFT, SPIBSC_CMNCR_SSLP);
	/* CLK */
	RZA_IO_RegWrite_32(&SPIBSC0.CMNCR, spiConfig->clockPolarity, SPIBSC_CMNCR_CPOL_SHIFT, SPIBSC_CMNCR_CPOL);

	/* swap by 8-bit unit - related to endianess of data) */
	RZA_IO_RegWrite_32(&SPIBSC0.CMNCR, spiConfig->dataSwap, SPIBSC_CMNCR_SFDE_SHIFT, SPIBSC_CMNCR_SFDE);

	/* idle state of lines */
	RZA_IO_RegWrite_32(&SPIBSC0.CMNCR, spiConfig->idleValue_30_31, SPIBSC_CMNCR_MOIIO3_SHIFT, SPIBSC_CMNCR_MOIIO3);
	RZA_IO_RegWrite_32(&SPIBSC0.CMNCR, spiConfig->idleValue_20_21, SPIBSC_CMNCR_MOIIO2_SHIFT, SPIBSC_CMNCR_MOIIO2);
	RZA_IO_RegWrite_32(&SPIBSC0.CMNCR, spiConfig->idleValue_10_11, SPIBSC_CMNCR_MOIIO1_SHIFT, SPIBSC_CMNCR_MOIIO1);
	RZA_IO_RegWrite_32(&SPIBSC0.CMNCR, spiConfig->idleValue_00_01, SPIBSC_CMNCR_MOIIO0_SHIFT, SPIBSC_CMNCR_MOIIO0);

	RZA_IO_RegWrite_32(&SPIBSC0.CMNCR, spiConfig->idleValue_30_31_2bitMode, SPIBSC_CMNCR_IO3FV_SHIFT, SPIBSC_CMNCR_IO3FV);
	RZA_IO_RegWrite_32(&SPIBSC0.CMNCR, spiConfig->idleValue_20_21_2bitMode, SPIBSC_CMNCR_IO2FV_SHIFT, SPIBSC_CMNCR_IO2FV);
	RZA_IO_RegWrite_32(&SPIBSC0.CMNCR, spiConfig->idleValue_00_01_1bitInput, SPIBSC_CMNCR_IO0FV_SHIFT, SPIBSC_CMNCR_IO0FV);

	/* next access delay */
	RZA_IO_RegWrite_32(&SPIBSC0.SSLDR, spiConfig->nextAccessDelay, SPIBSC_SSLDR_SPNDL_SHIFT, SPIBSC_SSLDR_SPNDL);
	/* SPBSSL negate delay */
	RZA_IO_RegWrite_32(&SPIBSC0.SSLDR, spiConfig->ssNegateDelay, SPIBSC_SSLDR_SLNDL_SHIFT, SPIBSC_SSLDR_SLNDL);
	/* clock delay */
	RZA_IO_RegWrite_32(&SPIBSC0.SSLDR, spiConfig->clockDelay, SPIBSC_SSLDR_SCKDL_SHIFT, SPIBSC_SSLDR_SCKDL);



	/* ---- Bit rate Setting ---- */
	RZA_IO_RegWrite_32(&SPIBSC0.SPBCR, (((spiConfig->divisionRatio) >> 8) & 0xFF), SPIBSC_SPBCR_SPBR_SHIFT, SPIBSC_SPBCR_SPBR);
	RZA_IO_RegWrite_32(&SPIBSC0.SPBCR, ((spiConfig->divisionRatio) & 0x3), SPIBSC_SPBCR_BRDV_SHIFT, SPIBSC_SPBCR_BRDV);



}

EXEC_RAM void qspiControllerWaitForIdle(void) {

    /* Wait for the final transfers to end (TEND=1) */
    while(!(SPIBSC0.CMNSR & TRANSFER_END));
};




