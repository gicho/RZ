RZ
==

Simple code which runs from QSPI

- configures PLL for max speed

- reconfigures the system for low vectors, so that VBAR is used as vector table location
	(high exception vectors ignore VBAR)

- turns off MMU and caches

- reconfigures the QSPI interface for maximum speed, quad mode

- copies reconfiguration code into internal ram 

- re-configures the QSPI IP to run in "external address mode", for one or two QSPI channels.

This is setup in the qspi_setup.h file, by using 
	#define QSPI_HARDWARE	QSPI_SINGLE_CHIP
or
	#define QSPI_HARDWARE	QSPI_DUAL_CHIP	
	
If two chips are being used, the application needs to be flashed in dual spi mode accordingly
	
- checks if a valid application image is available, at address DEF_USER_PROGRAM_SRC (0x18040000) with 0x40 offset

Verifies the string '.BootLoad_ValidProgramTest' is present, if yes, jumps to the application, if no, blinks LED0 forever

no other changes are made to the system.

Relocation of code into ram is left to the application itself

