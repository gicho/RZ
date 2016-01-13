/*
* Copyright 2015 Giancarlo Parodi
*
* RZA1H_GCC_RAM_APP.ld
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
ENTRY(APP_reset_handler)

/* Base Address RAM Memory Table 10-Mbyte on-chip RAM */  
/* Total RAM available 10112K */
MEMORY 
{
	/* Internal RAM address range H'2000_0000 to H'2001_FFFF is configured as data retention RAM */
	/* Write access to this address range has to be enabled first by writing to register SYSCR3 */
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
			
}

PROGRAM_STACK_SIZE    = 0x8000;      /* Application stack                  */
IRQ_STACK_SIZE	      = 0x2000;      /* IRQ mode stack                     */
FIQ_STACK_SIZE	      = 0x2000;      /* Fast IRQ mode stack                */
SVC_STACK_SIZE	      = 0x2000;      /* SVC mode stack                     */
ABT_STACK_SIZE	      = 0x2000;      /* Abort mode stack                   */
UND_STACK_SIZE	      = 0x2000;      /* Undefined mode stack               */
TTB_SIZE              = 0x8000;      /* Level-1 Translation Table for MMU  */

APP_VECTOR_TABLE	= 0x20020000; 	/* Vector table in RAM is located here */

/************************************************************************************************/
/* NOTE: MIRRORED ADDRESSES ARE CONFIGURED AS NON-CACHEABLE AREAS */
/************************************************************************************************/
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
 
 		/* Vector table is not relocated but is already in RAM in this case */
 		/* the copy process gets skipped since load address and run address match */
         __vector_table_ram_start__ = .;
        PROVIDE(__vector_table_ram_start__ = .);  
        
        *start.o(.text)                        

		__vector_table_ram_end__ = .;
        PROVIDE(__vector_table_ram_end__ = .); 
        			
		. = ALIGN(0x4);  
		      
	} > RAM0L 
	
    /* startup code */
    .reset_section  :
    {
		. = ALIGN(0x4);  
		
        __reset_code_rom_start__ = .;
        PROVIDE(__reset_code_rom_start__ = .);
        
		*low_level_init_gcc.o (.text)  
		*low_level_init_gcc.o (.rodata)

        *reset_handler.o (.text)
		*reset_handler.o (.rodata)	
			      
		*copy_section_to_ram.o (.text)
		*copy_section_to_ram.o (.rodata) 
		
		*init_ttb_RZA1H.o (.text)
		*init_ttb_RZA1H.o (.rodata)
		
		*cp15_access.o(.text)
		*cp15_access.o(.rodata)			
							
		__reset_code_rom_end__ = .;
        PROVIDE(__reset_code_rom_end__ = .);                               

		. = ALIGN(0x4);  
		      
	} > RAM0L
	
	/* hardware init code is executed in place from QSPI since not needed afterwards */
	.hardware_init :
	{
		. = ALIGN(0x4);  
	        
	    __hardware_init_code_rom_start__ = .;
        PROVIDE(__hardware_init_code_rom_start__ = .);

		*peripheral_early_init.o(.text)
		*peripheral_early_init.o(.rodata)
		
		*stb_init.o(.text)
		*stb_init.o(.rodata)		
		
		*bsc.o(.text)
		*bsc.o(.rodata)
		*bsc_userdef.o(.text)
		*bsc_userdef.o(.rodata)	
			
		__hardware_init_code_rom_end__ = __hardware_init_code_rom_start__ + SIZEOF(.hardware_init);
        PROVIDE(__hardware_init_code_rom_end__ = __hardware_init_code_rom_start__ + SIZEOF(.hardware_init));

		. = ALIGN(0x4);  
		        
	} > RAM0L
	
    /* .ARM.exidx is sorted, so has to go in its own output section.  */ 
    .ARM.exidx : { 
    
		. = ALIGN(0x4);
            
        __exidx_start = .; 
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
             
        . = ALIGN(0x4);
        __exidx_end = .;
             
    } >RAM0L 

	/* when debugging from ram there is no "slow code" section however for consistency with the QSPI build this is kept the same */
	/* but goes into RAM */
	.fast_code_section : 
	{
        
        /* Any following code must be aligned to a 4 byte boundary. */
		/* Important since the code copy routine works on 4 bytes size for efficiency */
        . = ALIGN(0x4);

		/* the copy process gets skipped since load address and run address match */
		__fast_code_rom_start__ = LOADADDR (.fast_code_section);
		PROVIDE(__fast_code_rom_start__ = LOADADDR (.fast_code_section));
		
        __fast_code_start__ = .;
        PROVIDE(__fast_code_start__ = .);

		*irqfiq_handler.o(.text)
		*irqfiq_handler.o(.rodata)

		*intc_handler.o(.text)
		*intc_handler.o(.rodata)

		*l1_cache.o(.text)
		*l1_cache.o(.rodata)

		*l2_cache_pl310.o(.text)
		*l2_cache_pl310.o(.rodata)
		*l2_cache.o(.text)
		*l2_cache.o(.rodata)		
		
		*mutex.o(.text)
		*mutex.o(.rodata)
		*semaphore.o(.text)
		*semaphore.o(.rodata)

        /* Any following code is aligned to a 4 byte boundary. */
		/* Important since the copy routine works on 4 bytes size */
		. = ALIGN(0x4);
		
        __fast_code_end__ = .;
		PROVIDE(__fast_code_end__ = .);       
		
	}  > RAM0L          


	/* this is the placeholder section for code which is not time critical and gets executed in place from QSPI */
	/* only kept the same for consistency, it will go into RAM with this linker configuration */
	.slow_code_section : 
	{
        
        /* Any following code must be aligned to a 4 byte boundary. */
        . = ALIGN(0x4);

		__slow_code_rom_start__ = LOADADDR (.slow_code_section);
		PROVIDE(__slow_code_rom_start__ = LOADADDR (.slow_code_section));
		
        __slow_code_start__ = .;
        PROVIDE(__slow_code_start__ = .);

		/* These are for static constructors and destructors under ELF */ 
        KEEP (*crtbegin.o(.ctors)) 
        KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors)) 
        KEEP (*(SORT(.ctors.*))) 
        KEEP (*crtend.o(.ctors)) 
        KEEP (*crtbegin.o(.dtors)) 
        KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors)) 
        KEEP (*(SORT(.dtors.*))) 
        KEEP (*crtend.o(.dtors))
        
 		*(.init) 
        *(.fini)

        *(.plt) 
        *(.gnu.warning)
		
		/* veneers */
		*(.glue_7t) *(.glue_7) 				 		
 		
 		/* all remaining program code */
 		*(.text .text.* .gnu.linkonce.t.*) 
          		 		 	
        __slow_code_end__ = .;
		PROVIDE(__slow_code_end__ = .);       
		
	}  > RAM0L 

	
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
        
	} > RAM0L 

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
	    
	    
	/* These buffers for the dma are located in internal ram */
	.DMA_BUFFER_IRAM (NOLOAD): ALIGN(0x40)
	{
		__dma_iram_buf_start__ = LOADADDR(.DMA_BUFFER_IRAM);
		PROVIDE(__dma_iram_buf_start__ = LOADADDR(.DMA_BUFFER_IRAM));
				
	} > RAM1L_MIRROR   
	
	__dma_iram_buf_size__ = SIZEOF(.DMA_BUFFER_IRAM);
	PROVIDE(__dma_iram_buf_size__ = SIZEOF(.DMA_BUFFER_IRAM));

	/* These buffers for the dma are located in internal CACHED ram */
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


	/* These buffers for the dma are located in external sdram */
	.DMA_BUFFER_SDRAM (NOLOAD): ALIGN(0x40)
	{
		__dma_sdram_buf_start__ = LOADADDR(.DMA_BUFFER_SDRAM);
		PROVIDE(__dma_sdram_buf_start__ = LOADADDR(.DMA_BUFFER_SDRAM));
				
	} > SDRAM_MIRROR   
	
	__dma_sdram_buf_size__ = SIZEOF(.DMA_BUFFER_SDRAM);
	PROVIDE(__dma_sdram_buf_size__ = SIZEOF(.DMA_BUFFER_SDRAM));

	/* These buffers for the dma are located in external CACHED sdram */
	/* align section to 32 bytes because of cache line size */
	/* buffers must be multiple of 32 bytes (eventually padded) and 32-bytes aligned */
	/* to avoid cache coherency issues */
	.DMA_BUFFER_CACHED_SDRAM (NOLOAD): ALIGN(0x40)
	{
		__dma_sdram_cache_buf_start__ = LOADADDR(.DMA_BUFFER_CACHED_SDRAM);
		PROVIDE(__dma_sdram_cache_buf_start__ = LOADADDR(.DMA_BUFFER_CACHED_SDRAM));		
				
	} > SDRAM  
	
	__dma_sdram_cache_buf_size__ = SIZEOF(.DMA_BUFFER_CACHED_SDRAM);
	PROVIDE(__dma_sdram_cache_buf_size__ = SIZEOF(.DMA_BUFFER_CACHED_SDRAM));

	    
	.stab 0 (NOLOAD) : { 
            *(.stab) 
    } 
 
    .stabstr 0 (NOLOAD) : { 
            *(.stabstr) 
    } 
}
