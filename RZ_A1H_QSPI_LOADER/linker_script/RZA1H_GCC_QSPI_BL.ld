/*
* Copyright 2015 Giancarlo Parodi
*
* RZA1H_GCC_QSPI_BL.ld
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
	RAM0L (rwx)   : ORIGIN = 0x20020000, LENGTH = 0x000E0000  /* Page 0 Lower bank ( 896KB) H'20020000 to H'200FFFFF */
	RAM1L (rwx)   : ORIGIN = 0x20100000, LENGTH = 0x00100000  /* Page 1 Lower bank (1024KB) H'20100000 to H'201FFFFF */
	RAM2L (rwx)   : ORIGIN = 0x20200000, LENGTH = 0x00100000  /* Page 2 Lower bank (1024KB) H'20200000 to H'202FFFFF */
	RAM3L (rwx)   : ORIGIN = 0x20300000, LENGTH = 0x00100000  /* Page 3 Lower bank (1024KB) H'20300000 to H'203FFFFF */
	RAM4L (rwx)   : ORIGIN = 0x20400000, LENGTH = 0x00100000  /* Page 4 Lower bank (1024KB) H'20400000 to H'204FFFFF */
	RAM0U (rwx)   : ORIGIN = 0x20500000, LENGTH = 0x00100000  /* Page 0 Upper bank (1024KB) H'20500000 to H'205FFFFF */
	RAM1U (rwx)   : ORIGIN = 0x20600000, LENGTH = 0x00100000  /* Page 1 Upper bank (1024KB) H'20600000 to H'206FFFFF */
	RAM2U (rwx)   : ORIGIN = 0x20700000, LENGTH = 0x00100000  /* Page 2 Upper bank (1024KB) H'20700000 to H'207FFFFF */
	RAM3U (rwx)   : ORIGIN = 0x20800000, LENGTH = 0x00100000  /* Page 3 Upper bank (1024KB) H'20800000 to H'208FFFFF */
	RAM4U (rwx)   : ORIGIN = 0x20900000, LENGTH = 0x00100000  /* Page 4 Upper bank (1024KB) H'20900000 to H'209FFFFF */

	RAM0L_MIRROR (rwx)   : ORIGIN = 0x60020000, LENGTH = 0x000E0000  /* Page 0 Lower bank ( 896KB) H'60020000 to H'600FFFFF */
	RAM0U_MIRROR (rwx)   : ORIGIN = 0x60100000, LENGTH = 0x00100000  /* Page 0 Upper bank (1024KB) H'60100000 to H'601FFFFF */
	RAM1U_MIRROR (rwx)   : ORIGIN = 0x60200000, LENGTH = 0x00100000  /* Page 1 Upper bank (1024KB) H'60200000 to H'602FFFFF */
	RAM1L_MIRROR (rwx)   : ORIGIN = 0x60300000, LENGTH = 0x00100000  /* Page 1 Lower bank (1024KB) H'60300000 to H'603FFFFF */
	RAM2L_MIRROR (rwx)   : ORIGIN = 0x60400000, LENGTH = 0x00100000  /* Page 2 Lower bank (1024KB) H'60400000 to H'604FFFFF */
	RAM2U_MIRROR (rwx)   : ORIGIN = 0x60500000, LENGTH = 0x00100000  /* Page 2 Upper bank (1024KB) H'60500000 to H'605FFFFF */
	RAM3U_MIRROR (rwx)   : ORIGIN = 0x60600000, LENGTH = 0x00100000  /* Page 3 Upper bank (1024KB) H'60600000 to H'606FFFFF */
	RAM3L_MIRROR (rwx)   : ORIGIN = 0x60700000, LENGTH = 0x00100000  /* Page 3 Lower bank (1024KB) H'60700000 to H'607FFFFF */
	RAM4L_MIRROR (rwx)   : ORIGIN = 0x60800000, LENGTH = 0x00100000  /* Page 4 Lower bank (1024KB) H'60800000 to H'608FFFFF */
	RAM4U_MIRROR (rwx)   : ORIGIN = 0x60900000, LENGTH = 0x00100000  /* Page 4 Upper bank (1024KB) H'60900000 to H'609FFFFF */
	
	SDRAM (rwx)   		: ORIGIN = 0x08000000, LENGTH = 0x02000000  /* SDRAM 32MB attached to CS2 H'08000000 to H'09FFFFFF */
	SDRAM_MIRROR (rwx)  : ORIGIN = 0x48000000, LENGTH = 0x02000000  /* SDRAM 32MB attached to CS2 H'48000000 to H'49FFFFFF */

	RAM (rwx)		: ORIGIN = 0x20020000, LENGTH = 0x009E0000	/* Complete range of always-on RAM */
	RAM_MIRROR (rwx): ORIGIN = 0x60020000, LENGTH = 0x009E0000	/* Complete range of always-on RAM mirror area */
	
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
ABT_STACK_SIZE	      = 0x2000;      /* Abort mode stack                   */
UND_STACK_SIZE	      = 0x2000;      /* Undefined mode stack               */
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
        /* eventually must be modified when malloc / heap is used */
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
	.und_stack_section (NOLOAD) : ALIGN(0x8)
	{
		__und_stack_start__ = .;
		PROVIDE(__und_stack_start__ = .);
		
		.  += UND_STACK_SIZE;
		
		. = ALIGN(0x4);
		
		__und_stack_end__ = .;
		PROVIDE(__und_stack_end__ = .);
		
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
    
	.stab 0 (NOLOAD) : { 
            *(.stab) 
    } 
 
    .stabstr 0 (NOLOAD) : { 
            *(.stabstr) 
    } 
}
