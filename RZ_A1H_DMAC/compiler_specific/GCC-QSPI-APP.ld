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
ENTRY(APP_reset_handler)

/* Base Address RAM Memory Table 10-Mbyte on-chip RAM */  
/* Total RAM available 10112K */
MEMORY 
{
	/* Internal RAM address range H'2000_0000 to H'2001_FFFF is configured as data retention RAM */
	/* Write access to this address range has to be enabled first by writing to registers SYSCR1 and SYSCR2 */
	RETRAM0 (rwx)   : ORIGIN = 0x20000000, LENGTH = 0x00004000  /* Retention ram page 0 ( 16KB) H'20000000 to H'20003FFF */
	RETRAM1 (rwx)   : ORIGIN = 0x20004000, LENGTH = 0x00004000  /* Retention ram page 1 ( 16KB) H'20004000 to H'20007FFF */
	RETRAM2 (rwx)   : ORIGIN = 0x20008000, LENGTH = 0x00008000  /* Retention ram page 2 ( 32KB) H'20008000 to H'2000FFFF */
	RETRAM3 (rwx)   : ORIGIN = 0x20010000, LENGTH = 0x00010000  /* Retention ram page 3 ( 64KB) H'20010000 to H'201FFFFF */
	
	RETRAM (rwx)	: ORIGIN = 0x20000000, LENGTH = 0x00020000	/* Complete range of retention RAM */
	
	/* Internal RAM memory map */
	RAM0L (rwx)   : ORIGIN = 0x20020000, LENGTH = 0x000E0000  /* Page 0 Lower bank ( 896KB) H'20020000 to H'200FFFFF */
	RAM1L (rwx)   : ORIGIN = 0x20100000, LENGTH = 0x00100000  /* Page 1 Upper bank (1024KB) H'20100000 to H'201FFFFF */
	RAM2L (rwx)   : ORIGIN = 0x20200000, LENGTH = 0x00100000  /* Page 2 Upper bank (1024KB) H'20200000 to H'202FFFFF */
	RAM3L (rwx)   : ORIGIN = 0x20300000, LENGTH = 0x00100000  /* Page 3 Upper bank (1024KB) H'20300000 to H'203FFFFF */
	RAM4L (rwx)   : ORIGIN = 0x20400000, LENGTH = 0x00100000  /* Page 4 Upper bank (1024KB) H'20400000 to H'204FFFFF */
	RAM0U (rwx)   : ORIGIN = 0x20500000, LENGTH = 0x00100000  /* Page 0 Upper bank (1024KB) H'20500000 to H'205FFFFF */
	RAM1U (rwx)   : ORIGIN = 0x20600000, LENGTH = 0x00100000  /* Page 1 Upper bank (1024KB) H'20600000 to H'206FFFFF */
	RAM2U (rwx)   : ORIGIN = 0x20700000, LENGTH = 0x00100000  /* Page 2 Upper bank (1024KB) H'20700000 to H'207FFFFF */
	RAM3U (rwx)   : ORIGIN = 0x20800000, LENGTH = 0x00100000  /* Page 3 Upper bank (1024KB) H'20800000 to H'208FFFFF */
	RAM4U (rwx)   : ORIGIN = 0x20900000, LENGTH = 0x00100000  /* Page 4 Upper bank (1024KB) H'20900000 to H'209FFFFF */

	RAM0L_MIRROR (rwx)   : ORIGIN = 0x60020000, LENGTH = 0x000E0000  /* Page 0 Lower bank ( 896KB) H'60020000 to H'600FFFFF */
	RAM0U_MIRROR (rwx)   : ORIGIN = 0x60100000, LENGTH = 0x00100000  /* Page 0 Upper bank (1024KB) H'60100000 to H'601FFFFF */
	RAM1U_MIRROR (rwx)   : ORIGIN = 0x60200000, LENGTH = 0x00100000  /* Page 1 Upper bank (1024KB) H'60200000 to H'602FFFFF */
	RAM1L_MIRROR (rwx)   : ORIGIN = 0x60300000, LENGTH = 0x00100000  /* Page 1 Upper bank (1024KB) H'60300000 to H'603FFFFF */
	RAM2L_MIRROR (rwx)   : ORIGIN = 0x60400000, LENGTH = 0x00100000  /* Page 2 Upper bank (1024KB) H'60400000 to H'604FFFFF */
	RAM2U_MIRROR (rwx)   : ORIGIN = 0x60500000, LENGTH = 0x00100000  /* Page 2 Upper bank (1024KB) H'60500000 to H'6050FFFF */
	RAM3U_MIRROR (rwx)   : ORIGIN = 0x60600000, LENGTH = 0x00100000  /* Page 3 Upper bank (1024KB) H'60600000 to H'606FFFFF */
	RAM3L_MIRROR (rwx)   : ORIGIN = 0x60700000, LENGTH = 0x00100000  /* Page 3 Upper bank (1024KB) H'60700000 to H'6070FFFF */
	RAM4L_MIRROR (rwx)   : ORIGIN = 0x60800000, LENGTH = 0x00100000  /* Page 4 Upper bank (1024KB) H'60800000 to H'6080FFFF */
	RAM4U_MIRROR (rwx)   : ORIGIN = 0x60900000, LENGTH = 0x00100000  /* Page 4 Upper bank (1024KB) H'60900000 to H'609FFFFF */
	
	SDRAM (rwx)   		: ORIGIN = 0x08000000, LENGTH = 0x02000000  /* SDRAM 32MB attached to CS2 H'08000000 to H'09FFFFFF */
	SDRAM_MIRROR (rwx)  : ORIGIN = 0x48000000, LENGTH = 0x02000000  /* SDRAM 32MB attached to CS2 H'48000000 to H'49FFFFFF */

	RAM (rwx)		: ORIGIN = 0x20020000, LENGTH = 0x009E0000	/* Complete range of always-on RAM */
	RAM_MIRROR (rwx): ORIGIN = 0x60020000, LENGTH = 0x009E0000	/* Complete range of always-on RAM mirror area */
	
	/* QSPI ROM attached to H'18000000, 2 chips of 0x4000000 size each (64 Mb) */ 
	/* Total addressable space from the QSPI internal address map is 0x18000000 to H'1BFFFFFF (64Mb page) */
	/* Size of block is 0x40000, first block is reserved to the BL */
	/* Defined length accounts for the split between the BL and the application located @ 18040000 */
	/* Check the bootloader project for consistency */	
	/* GP changed to 0x18000000 for testing without bootloader */
	
	QSPI_FLASH (rw) 		: ORIGIN = 0x18000000, LENGTH = 0x03FC0000  
	QSPI_FLASH_MIRROR (rw) 	: ORIGIN = 0x58000000, LENGTH = 0x03FC0000  			
}

PROGRAM_STACK_SIZE    = 0x8000;      /* Application stack                  */
IRQ_STACK_SIZE	      = 0x2000;      /* IRQ mode stack                     */
FIQ_STACK_SIZE	      = 0x2000;      /* Fast IRQ mode stack                */
SVC_STACK_SIZE	      = 0x2000;      /* SVC mode stack                     */
ABT_STACK_SIZE	      = 0x2000;      /* Abort mode stack                   */
TTB_SIZE              = 0x8000;      /* Level-1 Translation Table for MMU  */

/* GP changed to 0x18000000 for testing without bootloader */
APP_VECTOR_TABLE	= 0x18000000; 	/* Vector table in QSPI is located here */

SECTIONS
{
    /* Vector table located in QSPI @ location APP_VECTOR_TABLE, first item */
    /* the vector table must be aligned to 32-bytes, see Vector Base Address Register (VBAR) */
    /* within the arm v7 architecture manual */
    .vector_table APP_VECTOR_TABLE : ALIGN(0x20)
    {
        /* The start.S object file defines the vector table, and so gets located here. */
		__vector_table_rom_start__ = LOADADDR (.vector_table);
		PROVIDE(__vector_table_rom_start__ = LOADADDR (.vector_table));
 
        *start.o(.text)                        
		
		/* the application signature follows directly the vector table in the example */
		
		*application_signature.o(.rodata)
		
		. = ALIGN(0x4);  
		      
	} > QSPI_FLASH 
	
    /* startup code is executed in place from QSPI since not needed afterwards */
    .reset_section  :
    {
		. = ALIGN(0x4);  
		
        __reset_code_rom_start__ = .;
        PROVIDE(__reset_code_rom_start__ = .);
        
        *reset_handler.o (.text)
		*reset_handler.o (.rodata)
		
		*resetprg.o (.text)  
		*resetprg.o (.rodata)

/*
		*rza_io_regrw.o(.text)
		*rza_io_regrw.o(.rodata)		
*/
				      
		*copy_section_to_ram.o (.text)
		*copy_section_to_ram.o (.rodata) 
		
		*init_ttb.o (.text)
		*init_ttb.o (.rodata)
		
		*access.o(.text)
		*access.o(.rodata)
				
		*peripheral_early_init.o(.text)
		*peripheral_early_init.o(.rodata)
		*port_init.o(.text)
		*port_init.o(.rodata)
		*stb_init.o(.text)
		*stb_init.o(.rodata)		
		*bsc_init.o(.text)
		*bsc_init.o(.rodata)
		*bsc_userdef.o(.text)
		*bsc_userdef.o(.rodata)			
							
		__reset_code_rom_end__ = .;
        PROVIDE(__reset_code_rom_end__ = .);                               

		. = ALIGN(0x4);  
		      
	} > QSPI_FLASH
	
	.hardware_init :
	{
		. = ALIGN(0x4);  
	        
	    __hardware_init_code_rom_start__ = .;
        PROVIDE(__hardware_init_code_rom_start__ = .);
	
		__hardware_init_code_rom_end__ = __hardware_init_code_rom_start__ + SIZEOF(.hardware_init);
        PROVIDE(__hardware_init_code_rom_end__ = __hardware_init_code_rom_start__ + SIZEOF(.hardware_init));

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


    /* Executes from RAM */	
	.ram_vector_table : {
        
        /* this is the location in ram where the vector table for the application gets relocated */
		/* the vector table must be aligned to 32-bytes */
        . = ALIGN(0x20);
        
        __vector_table_ram_start__ = .;
        PROVIDE(__vector_table_ram_start__ = .);  
        
        /* reserve space for the vector table (0x20) and the following related literal constants (0x20) */
        . += 0x40;
        
		__vector_table_ram_end__ = .;
        PROVIDE(__vector_table_ram_end__ = .);          
        
        /* Any following code must be aligned to a 4 byte boundary. */
		/* Important since the code copy routine works on 4 bytes size for efficiency */
        . = ALIGN(0x4);

	}  > RAM0L  

	.fast_code_section : 
	{
        
        /* Any following code must be aligned to a 4 byte boundary. */
		/* Important since the code copy routine works on 4 bytes size for efficiency */
        . = ALIGN(0x4);

		__fast_code_rom_start__ = LOADADDR (.fast_code_section);
		PROVIDE(__fast_code_rom_start__ = LOADADDR (.fast_code_section));
		
        __fast_code_start__ = .;
        PROVIDE(__fast_code_start__ = .);

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
		
        __fast_code_end__ = .;
		PROVIDE(__fast_code_end__ = .);       
		
	}  > RAM0L AT>QSPI_FLASH         
	
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
        
	} > RAM0L AT>QSPI_FLASH

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
        end = .;
        PROVIDE(end = .); 
        
    } > RAM0L
 
	/* stacks need to be aligned to 8 bytes */
	.irq_stack_section (NOLOAD) : ALIGN(0x8)
	{	
		__irq_stack_start__ = .;
		PROVIDE(__irq_stack_start__ = .);         
				
		.  += IRQ_STACK_SIZE;
		
		. = ALIGN(0x4);
		
		__irq_stack_end__ = .;
		PROVIDE(__irq_stack_end__ = .);
		
	} > RAM0U
		
	/* stacks need to be aligned to 8 bytes */
	.fiq_stack_section (NOLOAD) : ALIGN(0x8)
	{
		__fiq_stack_start__ = .;
		PROVIDE(__fiq_stack_start__ = .);		
		
		.  += FIQ_STACK_SIZE;
		
		. = ALIGN(0x4);
		
		__fiq_stack_end__ = .;
		PROVIDE(__fiq_stack_end__ = .);
		
	} > RAM0U
		
	/* stacks need to be aligned to 8 bytes */
	.svc_stack_section (NOLOAD) : ALIGN(0x8)
	{
		__svc_stack_start__ = .;
		PROVIDE(__svc_stack_start__ = .);		
		
		.  += SVC_STACK_SIZE;
		
		. = ALIGN(0x4);
		
		__svc_stack_end__ = .;
		PROVIDE(__svc_stack_end__ = .);
		
	} > RAM0U
		
	/* stacks need to be aligned to 8 bytes */
	.abt_stack_section (NOLOAD) : ALIGN(0x8)
	{
		__abt_stack_start__ = .;
		PROVIDE(__abt_stack_start__ = .);
		
		.  += ABT_STACK_SIZE;
		
		. = ALIGN(0x4);
		
		__abt_stack_end__ = .;
		PROVIDE(__abt_stack_end__ = .);
		
	} > RAM0U
      
	/* stacks need to be aligned to 8 bytes */
	.program_stack_section (NOLOAD) : ALIGN(0x8)
	{
		__program_stack_start__ = .;
		PROVIDE(__program_stack_start__ = .);
		
		.  += PROGRAM_STACK_SIZE;
		
		. = ALIGN(0x4);		
		
		__program_stack_end__ = .;
		PROVIDE(__program_stack_end__ = .); 
		
	} > RAM0U	
     
	/* L1 translation table must be aligned to 16KB Boundary!           */
	/* Please refer to Cortex-A Series Version: 4.0 Programmer�s Guide, */
	/* section 9.4 First level address translation                      */
	.ttb_mmu1 : ALIGN(0x4000)
	{
		__ttb_mmu_base__ = .;
		PROVIDE(__ttb_mmu_base__ = .);
		
		.  += TTB_SIZE;
		.	= ALIGN(0x4);
		
		__ttb_mmu_end__ = .;
		PROVIDE(__ttb_mmu_end__ = .);
				
	} >RAM0U   
	    
	.DMA_BUFFER_IRAM (NOLOAD): ALIGN(0x40)
	{
		__dma_iram_buf_start__ = LOADADDR(.DMA_BUFFER_IRAM);
		PROVIDE(__dma_iram_buf_start__ = LOADADDR(.DMA_BUFFER_IRAM));
				
	} > RAM1L_MIRROR   
	
	__dma_iram_buf_size__ = SIZEOF(.DMA_BUFFER_IRAM);
	PROVIDE(__dma_iram_buf_size__ = SIZEOF(.DMA_BUFFER_IRAM));

	/* align section to 32 bytes because of cache line size */
	/* buffers must be multiple of 32 bytes (eventually padded) and 32-bytes aligned */
	/* to avoid cache coherency issues */
	.DMA_BUFFER_CACHED_IRAM (NOLOAD): ALIGN(0x40)
	{
		__dma_iram_cache_buf_start__ = LOADADDR(.DMA_BUFFER_CACHED_IRAM);
		PROVIDE(__dma_iram_cache_buf_start__ = LOADADDR(.DMA_BUFFER_CACHED_IRAM));		
				
	} > RAM1U  
	
	__dma_iram_cache_buf_size__ = SIZEOF(.DMA_BUFFER_CACHED_IRAM);
	PROVIDE(__dma_iram_cache_buf_size__ = SIZEOF(.DMA_BUFFER_CACHED_IRAM));
	    
	.stab 0 (NOLOAD) : { 
            *(.stab) 
    } 
 
    .stabstr 0 (NOLOAD) : { 
            *(.stabstr) 
    } 
}
