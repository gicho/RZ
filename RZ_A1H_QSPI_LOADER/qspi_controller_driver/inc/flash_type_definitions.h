/*
* Copyright 2015 Giancarlo Parodi
* 
* flash_type_definitions.h
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

#ifndef QSPI_CONTROLLER_DRIVER_INC_FLASH_TYPE_DEFINITIONS_H_
#define QSPI_CONTROLLER_DRIVER_INC_FLASH_TYPE_DEFINITIONS_H_

typedef enum FLASH_TYPE_T {

	SPANSION_S25FL512S = 1,
	OTHER_FLASH = 2

} FLASH_TYPE;

extern const FLASH_TYPE flashModel;

typedef enum wip_t {

	DEVICE_READY = 0u,
	DEVICE_BUSY = 1u

} wip_t;

typedef enum wel_t {

	IGNORE_WRITES = 0u,
	ACCEPT_WRITES = 1u

} wel_t;

typedef enum eraseErr_t {

	NO_ERASE_ERROR = 0u,
	ERASE_ERROR = 1u

} eraseErr_t;

typedef enum programErr_t {

	NO_PROGRAM_ERROR = 0u,
	PROGRAM_ERROR = 1u

} programErr_t;

typedef enum stRegWriteDisable_t {

	SREG_NO_PROTECTION = 0u,
	SREG_LOCK_BY_WP = 1u

} stRegWriteDisable_t;

// be aware of the standard ordering for GCC
// B0 is defined first in the list, B7 last
typedef union statusReg1_t {

	uint8_t stReg1;
	struct {
		wip_t WIP:1;
		wel_t WEL:1;
		uint8_t BP0:1;
		uint8_t BP1:1;
		uint8_t BP2:1;
		eraseErr_t E_ERR:1;
		programErr_t P_ERR:1;
		stRegWriteDisable_t SRWD:1;
	};

} flashStatusRegister1;

typedef enum programSuspend_t {

	NO_PROGRAM_SUSPEND_STATE = 0u,
	PROGRAM_SUSPEND_STATE = 1u

} programSuspend_t;

typedef enum eraseSuspend_t {

	NO_ERASE_SUSPEND_STATE = 0u,
	ERASE_SUSPEND_STATE = 1u

} eraseSuspend_t;


typedef union statusReg2_t {

	uint8_t stReg2;
	struct {
		uint8_t PS:1;
		uint8_t ES:1;
		uint8_t const RFU:1;
		uint8_t const RFU1:1;
		uint8_t const RFU2:1;
		uint8_t const RFU3:1;
		uint8_t const RFU4:1;
		uint8_t const RFU5:1;
	};

} flashStatusRegister2;



typedef enum freeze_t {

	BLOCK_OTP_UNLOCKED = 0u,
	BLOCK_OTP_LOCKED = 1u

} freeze_t;

typedef enum quad_t {

	SERIAL_DUAL_MODE = 0u,
	QUAD_MODE = 1u

} quad_t;

typedef enum blockProtect_t {

	BLOCK_PROTECT_NON_VOLATILE = 0u,
	BLOCK_PROTECT_VOLATILE = 1u

} blockProtect_t;

typedef enum tbProt_t {

	BLOCK_PROTECT_TOP = 0u,
	BLOCK_PROTECT_BOTTOM = 1u

} tbProt_t;

typedef union configReg1_t {

	uint8_t cfgReg1;
	struct {
		freeze_t FREEZE:1;
		quad_t QUAD:1;
		uint8_t const RFU2:1;
		blockProtect_t BPNV:1;
		uint8_t const RFU:1;
		tbProt_t TBPROT:1;
		uint8_t LC0:1;
		uint8_t LC1:1;
	};

} flashConfigRegister1;

//#define QUAD_MODE	        1u
//#define SERIAL_DUAL_MODE        0u
//#define CFREG_QUAD_BIT          0x02          /* Quad mode bit(Configuration Register) */
//#define PROGRAM_ERASE_ERROR     0x60

typedef enum manufacturerId_t {

	SPANSION_ID = 0x1,

} manufacturerId_t;

typedef enum deviceId_t {

	S25FL512S = 0x19,

} deviceId_t;


typedef struct deviceSignature_t {

	manufacturerId_t manufacturerId;
	deviceId_t	deviceId;

} deviceSignature;


typedef struct identification_t {

	manufacturerId_t manId;
	uint8_t memInterfaceType;
	uint8_t density;
	uint8_t idCfiLenght;
	uint8_t sectorArchitecture;
	uint8_t familyId;
	uint16_t asciiCharactersForModel;
	uint8_t reserved[8];
	uint8_t queryUniqueAscii[3];
	uint8_t primaryOemCommandSet;
	uint8_t flpCommandSetId;
	uint16_t addressForPrimaryExtendedTable;
	uint8_t alternateOemCommandSet;
	uint8_t asciiForSpiInterfaceStechnology;
	uint16_t addressForAlternateOemExtendedTable;
	uint8_t vccMin;
	uint8_t vcccMAx;
	uint8_t vppMIn;
	uint8_t vppMAx;
	uint8_t typicalTimeOutForSingleByteProgram;
	uint8_t typicalTimeOutForMinSizePageProgram;
	uint8_t typicalTimeoutForSectorErase;
	uint8_t typicalTimeoutForChipErase;
	uint8_t maxTimeoutForSingleByteProgram;
	uint8_t maxTimeoutForPageSizeProgram;
	uint8_t maxTimeoutForSectorErase;
	uint8_t maxTimeoOutForChipErase;
	uint8_t deviceSize;
	uint16_t flashDeviceInterfaceDescription;
	uint16_t maxNumberOfBytesInMultiByteWrite;
	uint8_t numberOfEraseBlockRegions;
	uint32_t eraseBlockInformation;	// 30h
	uint8_t reserved1[15];

} identification_t;





#endif /* QSPI_CONTROLLER_DRIVER_INC_FLASH_TYPE_DEFINITIONS_H_ */

