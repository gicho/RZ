RZ
==

Simple configuration code which runs from QSPI boot

in reset_handler.s:

- turns off MMU and caches
- invalidates L1 cache contents, TLB and branch prediction array
- enable instruction cache and branch prediction array
- setup domain control register to "all clients"
- configures PLL for max speed
- reconfigures the system for low vectors, so that VBAR is used as vector table location
	(high exception vectors as configured after QSPI boot ignore VBAR)
- set standby mode enable in the power control register (inside L2CC) and configure for maximum speed
	(400 MHz CPU clock, 266.67 MHZ graphics clock - using a 13.33 MHz crystal on the RZ RSK)
- enable data retention ram
- setup stack areas
- jump to PowerON_Reset

in low_level_init_gcc.c:

- copy the QSPI reconfiguration code in internal RAM
- setup .bss and .data sections
- jump to main

in main.c:

- reconfigures the QSPI interface for maximum speed, quad mode (quad I/O read with 4 byte address), burst lenght 4 (4x8 Bytes per access) 
- jump at a fixed address of 0x18080000 which for the spansion flash mounted on the RSK corresponds to the second logical sector of the flash
	(sector size on the spansion flash ix 0x40000)


Note: the number of QSPI channels (chips) used is defined in the qspi_setup.h file, by using:
 
	#define QSPI_HARDWARE	QSPI_SINGLE_CHIP
	
or
	
	#define QSPI_HARDWARE	QSPI_DUAL_CHIP	
	
and the QSPI_SINGLE_CHIP or QSPI_DUAL_CHIP is specified via the project build rule. 
	

No other configuration changes are made to the application/system.

The MMU is NOT enabled but I cache is turned on - it must be invalidated before enabling the MMU in the application

Relocation of application code into ram is done by the application itself.

Any internal ram location can be reused for the application since the loader and the application projects are independent.

The only constraints are:
- not to use the first two sectors of QSPI flash inside the application linker script
- to use a consistent configuration for application and loader (single or dual mode)
 

 

