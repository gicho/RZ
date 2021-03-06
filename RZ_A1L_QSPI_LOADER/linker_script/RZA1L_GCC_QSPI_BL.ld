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
* Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/******************************************************************************
* File Name     : GCC-QSPI-BL.ld
* Device(s)     : RZ/A1H RSK2+RZA1H
* H/W Platform  : RSK2+RZA1H CPU Board
* Description   : Linker file for simple QSPI bootloader which reconfigures the
*				  QSPi flash interface for higher performance and 4-Bit mode 
*				  using the code relocated in ram (qspi_reconfigure_code_section)
******************************************************************************/
/******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 17.09.2014 1.00
******************************************************************************/
OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(QSPI_BL_reset_handler)

/* Base Address RAM Memory Table 10-Mbyte on-chip RAM */  
/* Total RAM available 10112K */
MEMORY 
{
	/* Internal RAM address range H'2000_0000 to H'2001_FFFF is configured as data retention RAM */
	/* Write access to this address range has to be enabled first by writing to registers SYSCR1 and SYSCR2 */
	RETRAM0 (rwx)   : ORIGIN = 0x20000000, LENGTH = 0x00004000  /* Retention ram page 0 ( 16KB) H'20000000 to H'20003FFF */
	RETRAM1 (rwx)   : ORIGIN = 0x20004000, LENGTH = 0x00004000  /* Retention ram page 1 ( 16KB) H'20004000 to H'20007FFF */
	RETRAM2 (rwx)   : ORIGIN = 0x20008000, LENGTH = 0x00008000  /* Retention ram page 2 ( 32KB) H'20008000 to H'2000FFFF */
	RETRAM3 (rwx)   : ORIGIN = 0x20010000, LENGTH = 0x00010000  /* Retention ram page 3 ( 64KB) H'20010000 to H'2001FFFF */
	
	RETRAM (rwx)	: ORIGIN = 0x20000000, LENGTH = 0x00020000	/* Complete range of retention RAM */


	/* Internal RAM memory map */
	RAM0 (rwx)   : ORIGIN = 0x20020000, LENGTH = 0x00060000  /* Page 0 bank (384KB) H'20020000 to H'2007FFFF */
	RAM1 (rwx)   : ORIGIN = 0x20080000, LENGTH = 0x00080000  /* Page 1 bank (512KB) H'20080000 to H'200FFFFF */
	RAM2 (rwx)   : ORIGIN = 0x20100000, LENGTH = 0x00080000  /* Page 2 bank (512KB) H'20100000 to H'2017FFFF */
	RAM3 (rwx)   : ORIGIN = 0x20180000, LENGTH = 0x00080000  /* Page 3 bank (512KB) H'20180000 to H'201FFFFF */
	RAM4 (rwx)   : ORIGIN = 0x20200000, LENGTH = 0x00100000  /* Page 4 bank (  1MB) H'20200000 to H'202FFFFF */

	RAM0_MIRROR (rwx)   : ORIGIN = 0x60020000, LENGTH = 0x00060000  /* Page 0 bank (384KB) H'60020000 to H'6007FFFF */
	RAM1_MIRROR (rwx)   : ORIGIN = 0x60080000, LENGTH = 0x00080000  /* Page 1 bank (512KB) H'60080000 to H'600FFFFF */
	RAM2_MIRROR (rwx)   : ORIGIN = 0x60100000, LENGTH = 0x00080000  /* Page 2 bank (512KB) H'60100000 to H'6017FFFF */
	RAM3_MIRROR (rwx)   : ORIGIN = 0x60180000, LENGTH = 0x00080000  /* Page 3 bank (512KB) H'60180000 to H'601FFFFF */
	RAM4_MIRROR (rwx)   : ORIGIN = 0x60200000, LENGTH = 0x00100000  /* Page 4 bank (  1MB) H'60200000 to H'602FFFFF */
	
	SDRAM (rwx)   		: ORIGIN = 0x08000000, LENGTH = 0x02000000  /* SDRAM 32MB attached to CS2 H'08000000 to H'09FFFFFF */
	SDRAM_MIRROR (rwx)  : ORIGIN = 0x48000000, LENGTH = 0x02000000  /* SDRAM 32MB attached to CS2 H'48000000 to H'49FFFFFF */

	RAM (rwx)		: ORIGIN = 0x20020000, LENGTH = 0x002E0000	/* Complete range of always-on RAM */
	RAM_MIRROR (rwx): ORIGIN = 0x60020000, LENGTH = 0x002E0000	/* Complete range of always-on RAM mirror area */
	
	/* QSPI ROM attached to H'18000000, 2 chips of 0x4000000 size each (64 Mb) */ 
	/* Total addressable space from the QSPI internal address map is 0x18000000 to H'1BFFFFFF (64Mb page) */
	/* Size of block is 0x40000, first two blocks are reserved to the BL */
	/* Defined length accounts for the split between the BL and the application located @ 18040000 */
	QSPI_FLASH (rw) 		: ORIGIN = 0x18000000, LENGTH = 0x80000  
	QSPI_FLASH_MIRROR (rw) 	: ORIGIN = 0x58000000, LENGTH = 0x80000 
	/* Needs to match #define DEF_USER_PROGRAM_SRC 0x18080000 in qspi_setup.h, set at (ORIGIN + LENGTH) */																
}

PROGRAM_STACK_SIZE    = 0x8000;      /* Application stack                  */
IRQ_STACK_SIZE	      = 0x2000;      /* IRQ mode stack                     */
FIQ_STACK_SIZE	      = 0x2000;      /* Fast IRQ mode stack                */
SVC_STACK_SIZE	      = 0x2000;      /* SVC mode stack                     */
ABT_STACK_SIZE	      = 0x100;      /* Abort mode stack                   */
UND_STACK_SIZE	      = 0x100;      /* Undefined mode stack               */
TTB_SIZE              = 0x8000;      /* Level-1 Translation Table for MMU  */

SECTIONS
{
    /* Initial code section executing from QSPI @ 0x18000000 */
    /* Vector table located in QSPI @ location QSPI_VECTOR_TABLE, first item */
    /* the vector table must be aligned to 32-bytes, see Vector Base Address Register (VBAR) */
    /* within the arm v7 architecture manual */
    .reset_section : ALIGN(0x20)
    {
        /* The start object file begins with the vector table, and so must be located here. */
        __reset_code_rom_start__ = .;
        PROVIDE(__reset_code_rom_start__ = .);
        
        *start.o (.text)
        *reset_handler.o (.text)
		*low_level_init_gcc.o (.text)        

		*start.o (.rodata)
		*reset_handler.o (.rodata)
		*low_level_init_gcc.o (.rodata)
	
		__reset_code_rom_end__ = .;
        PROVIDE(__reset_code_rom_end__ = .);                               

		. = ALIGN(0x4);  
		      
	} > QSPI_FLASH

    /* .ARM.exidx is sorted, so has to go in its own output section.  */ 
    .ARM.exidx : { 
    
		. = ALIGN(0x4);
            
        __exidx_start = .; 
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
             
        . = ALIGN(0x4);
        __exidx_end = .;
             
    } >QSPI_FLASH 

    /* Modules for QSPI reconfiguration */
    /* Executes from RAM */
	
	.qspi_reconfigure_code_section : 
	{
        /* Any following code must be aligned to a 4 byte boundary. */
		/* Important since the copy routine works on 4 bytes size */
        . = ALIGN(0x4);

		__qspi_reconfigure_code_rom_start__ = LOADADDR (.qspi_reconfigure_code_section);
		PROVIDE(__qspi_reconfigure_code_rom_start__ = LOADADDR (.qspi_reconfigure_code_section));
		
        __qspi_reconfigure_code_start__ = .;
        PROVIDE(__qspi_reconfigure_code_start__ = .);

        /* The QSPI re-configuration needs to be copied to RAM by this code */
		*qspi_change_config.o (.text)
		*rza_io_regrw.o (.text)

		*qspi_controller.o (.text)		
		*spi_mode.o (.text)
		*external_address_mode.o (.text)

		/* These are for static constructors and destructors under ELF */ 
        . = ALIGN(0x4); 
        KEEP (*crtbegin.o(.ctors)) 
        KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors)) 
        KEEP (*(SORT(.ctors.*))) 
        KEEP (*crtend.o(.ctors)) 
        KEEP (*crtbegin.o(.dtors)) 
        KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors)) 
        KEEP (*(SORT(.dtors.*))) 
        KEEP (*crtend.o(.dtors))
		
		/* catch-all for remaining sections */
		*(.glue_7t) *(.glue_7) 				/* veneers */ 		
 		*(.text .text.* .gnu.linkonce.t.*) 
        *(.plt) 
        *(.gnu.warning)
          		 		 
 		*(.init) 
        *(.fini)

        /* Any following code is aligned to a 4 byte boundary. */
		/* Important since the copy routine works on 4 bytes size */
		. = ALIGN(0x4);
		
        __qspi_reconfigure_code_end__ = .;
		PROVIDE(__qspi_reconfigure_code_end__ = .);       
		
	}  > RAM0 AT>QSPI_FLASH         
	
    /* initialized data section */
	.data_section : 
    {
        . = ALIGN(0x4);
		
		__data_rom_start__ = LOADADDR (.data_section);
		PROVIDE(__data_rom_start__ = LOADADDR (.data_section));

        __data_start__ = .;
        PROVIDE(__data_start__ = .);  

        KEEP(*(.jcr)) 
        *(.got.plt) *(.got) 
        *(.shdata) 
        *(.data .data.* .gnu.linkonce.d.*) 

        *(.data)        
        *(.data.*)
        *(.got.plt) *(.got)
         
        *(.rodata .rodata.* .gnu.linkonce.r.*)
                
		. = ALIGN(0x4);
		
		__data_end__ = .;
        PROVIDE(__data_end__ = .);
        
	} > RAM0 AT>QSPI_FLASH

    /* zero initialised data section */
    .bss_section (NOLOAD) :
    {
		. = ALIGN(0x4);

        __bss_start__ = .;
        PROVIDE(__bss_start__ = .);         
				
		*(.shbss) 
        *(.bss .bss.* .gnu.linkonce.b.*)
        *(COMMON)
		
		. = ALIGN(0x4);
		
        __bss_end__ = .;
        PROVIDE(__bss_end__ = .);

        /* required by sbrk (syscalls.c) for heap management */
        /* eventually must be modified when malloc / heap is used */
        end = .;
        PROVIDE(end = .); 
                
        
    } > RAM0
 
	/* stacks need to be aligned to 8 bytes */
	.irq_stack_section (NOLOAD) : ALIGN(0x8)
	{	
		__irq_stack_start__ = .;
		PROVIDE(__irq_stack_start__ = .);         
				
		.  += IRQ_STACK_SIZE;
		
		. = ALIGN(0x4);
		
		__irq_stack_end__ = .;
		PROVIDE(__irq_stack_end__ = .);   		
		
	} > RAM1
		
	/* stacks need to be aligned to 8 bytes */
	.fiq_stack_section (NOLOAD) : ALIGN(0x8)
	{
		__fiq_stack_start__ = .;
		PROVIDE(__fiq_stack_start__ = .);		
		
		.  += FIQ_STACK_SIZE;
		
		. = ALIGN(0x4);
		
		__fiq_stack_end__ = .;
		PROVIDE(__fiq_stack_end__ = .);
		
	} > RAM1
		
	/* stacks need to be aligned to 8 bytes */
	.svc_stack_section (NOLOAD) : ALIGN(0x8)
	{
		__svc_stack_start__ = .;
		PROVIDE(__svc_stack_start__ = .);		
		
		.  += SVC_STACK_SIZE;
		
		. = ALIGN(0x4);
		
		__svc_stack_end__ = .;
		PROVIDE(__svc_stack_end__ = .);
		
	} > RAM1
		
	/* stacks need to be aligned to 8 bytes */
	.abt_stack_section (NOLOAD) : ALIGN(0x8)
	{
		__abt_stack_start__ = .;
		PROVIDE(__abt_stack_start__ = .);
		
		.  += ABT_STACK_SIZE;
		
		. = ALIGN(0x4);
		
		__abt_stack_end__ = .;
		PROVIDE(__abt_stack_end__ = .);
		
	} > RAM1

	/* stacks need to be aligned to 8 bytes */
	.und_stack_section (NOLOAD) : ALIGN(0x8)
	{
		__und_stack_start__ = .;
		PROVIDE(__und_stack_start__ = .);
		
		.  += UND_STACK_SIZE;
		
		. = ALIGN(0x4);
		
		__und_stack_end__ = .;
		PROVIDE(__und_stack_end__ = .);
		
	} > RAM1
	
	/* stacks need to be aligned to 8 bytes */
	.program_stack_section (NOLOAD) : ALIGN(0x8)
	{
		__program_stack_start__ = .;
		PROVIDE(__program_stack_start__ = .);
		
		.  += PROGRAM_STACK_SIZE;
		
		. = ALIGN(0x4);		
		
		__program_stack_end__ = .;
		PROVIDE(__program_stack_end__ = .); 
		
	} > RAM1	
    
	.stab 0 (NOLOAD) : { 
            *(.stab) 
    } 
 
    .stabstr 0 (NOLOAD) : { 
            *(.stabstr) 
    } 
}
