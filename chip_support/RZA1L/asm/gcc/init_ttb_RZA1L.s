/*
* Copyright 2015 Giancarlo Parodi
*
* init_ttb_RZA1L.s
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

/* settings of the table entry format
*  31           20|19 18|17|16| 15|14 12|11 10|9|8    5|4 |3 2|1 0|
* |base address   | 0  0|nG| S|AP2|TEX  |AP   |P|Domain|XN|CB |1 0|
*/
	.equ ONE_MB	, 0x2
	.equ INOUT_WB_RWALLOC 		, ((0x1 << 12)|(0x3 << 2))
	.equ INOUT_NON_CACHABLE 	, ((0x1 << 12)|(0x0 << 2))
	.equ SHARABLE_DEVICE		, ((0x0 << 12)|(0x1 << 2))
	.equ NON_SHARABLE_DEVICE	, ((0x2 << 12)|(0x0 << 2))
	.equ STRONG_ORDER 			, ((0x0 << 12)|(0x0 << 2))

	.equ NON_SHARABLE 	, (0x0 << 16)
	.equ SHARABLE 		, (0x1 << 16)

	.equ DOMAIN , (0xF << 5)

	.equ EXEC_NEVER , (1 << 4)

	.equ FULL_ACCESS , ((0x0 << 15)|(0x3 << 10))

	.equ NORMAL_NON_SHARABLE_IONOUT_WB_RWALLOC , (INOUT_WB_RWALLOC | NON_SHARABLE | DOMAIN | FULL_ACCESS | ONE_MB)
	.equ NORMAL_NON_SHARABLE_IONOUT_NON_CACHABLE , (INOUT_NON_CACHABLE | NON_SHARABLE | DOMAIN | FULL_ACCESS | ONE_MB)
	.equ STRONGLY_ORDERED , (STRONG_ORDER | DOMAIN | FULL_ACCESS | ONE_MB)

/* ---- Parameter setting to level1 descriptor (bits 19:0) ---- */
/* setting for Strongly-ordered memory     
   B-00000000000000000000110111100010 */
    .equ TTB_PARA_STRGLY , 0x0DE2

/* setting for Outer and inner not cache normal memory 
   B-00000000000000000001110111100010 */
    .equ TTB_PARA_NORMAL_NOT_CACHE , 0x1DE2

/* setting for Outer and inner write back, write allocate normal memory 
   (Cacheable) 
   B-00000000000000000001110111101110 */
    .equ TTB_PARA_NORMAL_CACHE , 0x1DEE

/* ---- Memory area size (MB) ---- */
    .equ M_SIZE_NOR    , 128   /* [Area00] CS0, CS1 area (for NOR flash) */
    .equ M_SIZE_SDRAM , 128    /* [Area01] CS2, CS3 area (for SDRAM) */
    .equ M_SIZE_CS45 , 128     /* [Area02] CS4, CS5 area */
    .equ M_SIZE_SPI , 128      /* [Area03] SPI, SP2 area (for Serial flash) */
    .equ M_SIZE_RAM , 10       /* [Area04] Internal RAM */
    .equ M_SIZE_IO_1 , 502     /* [Area05] I/O area 1 */
    .equ M_SIZE_NOR_M , 128    /* [Area06] CS0, CS1 area (for NOR flash) (mirror) */
    .equ M_SIZE_SDRAM_M , 128  /* [Area07] CS2, CS3 area (for SDRAM) (mirror) */
    .equ M_SIZE_CS45_M , 128   /* [Area08] CS4, CS5 area (mirror) */
    .equ M_SIZE_SPI_M , 128    /* [Area09] SPI, SP2 area (for Serial flash) (mirror) */
    .equ M_SIZE_RAM_M , 10     /* [Area10] Internal RAM (mirror) */
    .equ M_SIZE_IO_2 , 2550    /* [Area11] I/O area 2 */

/*******************************************************************************
* This code provides basic global enable for Cortex-A9 cache. 
* It also enables branch prediction 
* This code must be run from a privileged mode 
/******************************************************************************/
    .global    init_TTB
    .func init_TTB

init_TTB:
/*******************************************************************************
* Cortex-A9 MMU Configuration
* Set translation table base
* see B3.12.24 CP15 c2, Translation table support registers
*******************************************************************************/
    /* Cortex-A9 supports two translation tables */
    /* Configure translation table base (TTB) control register cp15,c2 */
    /* to a value of all zeros, indicates we are using TTB register 0. */
    MOV  r0,#0x0
    MCR  p15, 0, r0, c2, c0, 2        /* TTBCR */

    /* write the address of our page table base to TTB register 0 */
    /* start of table from .ld file  */
    LDR  r0,=__ttb_mmu_base__
    
    /* RGN=b01  (outer cacheable write-back cached, write allocate) */
    MOV  r1, #0x08                    
    
    /* S=0      (translation table walk to non-shared memory) */
    /* IRGN=b01 (inner cacheability for the translation table walk is 
       Write-back Write-allocate) */
    ORR  r1,r1,#0x40               
    ORR  r0,r0,r1
    
    /* TTBR0 */
    MCR  p15, 0, r0, c2, c0, 0       

/*******************************************************************************
* PAGE TABLE generation 
* Generate the page tables 
* Build a flat translation table for the whole address space. 
* ie: Create 4096 1MB sections from 0x000xxxxx to 0xFFFxxxxx 
*  31           20|19 18|17|16| 15|14 12|11 10|9|8    5|4 |3 2|1 0|
* |base address   | 0  0|nG| S|AP2|TEX  |AP   |P|Domain|XN|CB |1 0|
*
* Bits[31:20]   - Top 12 bits of VA is pointer into table 
* nG[17]=0      - Non global, enables matching against ASID in the TLB when set.
* S[16]=0       - Indicates normal memory is shared when set.
* AP2[15]=0  
* TEX[14:12]=000
* AP[11:10]=11  - Configure for full read/write access in all modes 
* IMPP[9]=0     - Ignored
* Domain[5:8]=1111   - Set all pages to use domain 15
* XN[4]=0       - Execute never disabled
* CB[3:2]= 00   - Set attributes to Strongly-ordered memory. 
*                 (except for the descriptor where code segment is based, 
*                  see below) 
* Bits[1:0]=10  - Indicate entry is a 1MB section 
*******************************************************************************/
    LDR  r0,=__ttb_mmu_base__          /* start of table from .ld file */
    LDR  r1,=0xFFF
    LDR  r2,=11
    LDR  r3,=0
    LDR     r4,=0
    LDR  r5,=0

    /* r0 contains the address of the translation table base */
    /* r1 is loop counter */
    /* r2 is target area counter (Initialize value = Last area No.) */
    /* r3 is loop counter by area */

    /* use loop counter to create 4096 individual table entries. */
    /* this writes from address 'Image$$TTB$$ZI$$Base' +  */
    /* offset 0x3FFC down to offset 0x0 in word steps (4 bytes) */

set_mem_accsess:
    CMP  r2, #11
    BEQ  setting_area11
    CMP  r2, #10
    BEQ  setting_area10
    CMP  r2, #9
    BEQ  setting_area9
    CMP  r2, #8
    BEQ  setting_area8
    CMP  r2, #7
    BEQ  setting_area7
    CMP  r2, #6
    BEQ  setting_area6
    CMP  r2, #5
    BEQ  setting_area5
    CMP  r2, #4
    BEQ  setting_area4
    CMP  r2, #3
    BEQ  setting_area3
    CMP  r2, #2
    BEQ  setting_area2
    CMP  r2, #1
    BEQ  setting_area1
    CMP  r2, #0
    BEQ  setting_area0
setting_area11:                        
    LDR  r3, =M_SIZE_IO_2
    LDR  r4, =STRONGLY_ORDERED
    BAL  init_counter
setting_area10:                     
    LDR  r3, =M_SIZE_RAM_M
    LDR  r4, =NORMAL_NON_SHARABLE_IONOUT_NON_CACHABLE
    BAL  init_counter
setting_area9:                       
    LDR  r3, =M_SIZE_SPI_M
    LDR  r4, =NORMAL_NON_SHARABLE_IONOUT_NON_CACHABLE
    BAL  init_counter
setting_area8:                       
    LDR  r3, =M_SIZE_CS45_M
    LDR  r4, =STRONGLY_ORDERED
    BAL  init_counter    
setting_area7:                       
    LDR  r3, =M_SIZE_SDRAM_M
    LDR  r4, =NORMAL_NON_SHARABLE_IONOUT_NON_CACHABLE
    BAL  init_counter
setting_area6:      
    LDR  r3, =M_SIZE_NOR_M
    LDR  r4, =NORMAL_NON_SHARABLE_IONOUT_NON_CACHABLE
    BAL  init_counter
setting_area5:     
    LDR  r3, =M_SIZE_IO_1
    LDR  r4, =STRONGLY_ORDERED
    BAL  init_counter
setting_area4:                 
    LDR  r3, =M_SIZE_RAM
    LDR  r4, =NORMAL_NON_SHARABLE_IONOUT_WB_RWALLOC
    BAL  init_counter
setting_area3:                      
    LDR  r3, =M_SIZE_SPI
    LDR  r4, =NORMAL_NON_SHARABLE_IONOUT_WB_RWALLOC
    BAL  init_counter
setting_area2:                      
    LDR  r3, =M_SIZE_CS45
    LDR  r4, =STRONGLY_ORDERED
    BAL  init_counter
setting_area1:                      
    LDR  r3, =M_SIZE_SDRAM
    LDR  r4, =NORMAL_NON_SHARABLE_IONOUT_WB_RWALLOC
    BAL  init_counter    
setting_area0:                      
    LDR  r3, =M_SIZE_NOR
    LDR  r4, =NORMAL_NON_SHARABLE_IONOUT_WB_RWALLOC
    BAL  init_counter
init_counter:
    SUBS r3, r3, #1                 
write_ttb:
    
    /* R5 now contains full level1 descriptor to write */
    ORR  r5, r4, r1, LSL#20        
    
    /* Str table entry at TTB base + loopcount*4 */    
    STR  r5, [r0, r1, LSL#2]

    /* Decrement loop counter */
    SUB  r1, r1, #1                 
    
    /* Decrement loop counter by area */
    SUBS r3, r3, #1                 
    
    BPL  write_ttb
    
    /* target area counter */   
    SUBS r2, r2, #1                 
    
    /* To the next area */
    BPL  set_mem_accsess            

    BX   lr
    .endfunc
    .end
    .align 4
