/*
* Copyright 2015 Giancarlo Parodi
* 
* low_level_init_iar.c
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

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "compiler_settings.h"
#include "iodefine.h"
#include "devdrv_common.h"
#include "devdrv_intc.h"

#include "sio_char.h"

#include "rza_io_regrw.h"

#include "intc_handler.h"
#include "cp15_access.h"  
  
#pragma section = "RAM_IRQ_VECTOR_TABLE"
#pragma section = "RAM_IRQ_VECTOR_TABLE_init"
#pragma section = ".textrw"
#pragma section = ".textrw_init"  

extern void APP_reset_handler(void);
extern void APP_undefined_handler(void);
extern void APP_abort_handler(void);
extern void APP_svc_handler(void);
extern void APP_prefetch_handler(void);
extern void APP_reserved_handler(void);
extern void APP_irq_handler(void);
extern void APP_fiq_handler(void);

void module_clocks_enable();
void cs0_port_init(void);
void cs2_port_init(void);
void cs0_init(void);
void cs2_init(void);

void address_data_lines_init(void);

int __low_level_init(void)
{
    
    uint32_t volatile * VectorTableEntry, * VectorTableRomEntry;
    uint32_t volatile *end, *dst, *rom_src;
    uint8_t i;
    
    /* copy vector table to ram */
    VectorTableEntry = (uint32_t volatile *) __section_begin("RAM_IRQ_VECTOR_TABLE");
    VectorTableRomEntry = (uint32_t volatile *) __section_begin("RAM_IRQ_VECTOR_TABLE_init");

    /* Size is 0x40 i.e. 16 entries @ 4 Bytes each */
    for(i=0;i<0x10;i++)
      *(VectorTableEntry++) = *(VectorTableRomEntry++);

    /* Get the vector table entry again */
    VectorTableEntry = (uint32_t volatile *) __section_begin("RAM_IRQ_VECTOR_TABLE");
    
    /* Set the base address register */ 
    VbarSet((uint32_t)VectorTableEntry);  
    
    /* Set to low vectors after QSPI boot */
    SetLowVectors();
    
    /* Copy the code executed in ram so that it is available also to the init functions */
    /* Note: these functions cannot use data variables as these are not yet initialized */
    /* These functions are marked as "EXEC_RAM" */
    rom_src = (uint32_t volatile*) __section_begin(".textrw_init");
    dst = (uint32_t volatile*) __section_begin(".textrw");
    end = (uint32_t volatile*) __section_end(".textrw");

    /* if not debugging directly from RAM */
    if(rom_src != dst) {
      /* ROM has data at end of text; copy it. */
      while (dst < end) {
        *dst++ = *rom_src++;
      }
    };    
    
    /* Now start initializing the system-level hardware */
    /* enable all module clocks */
    module_clocks_enable();

    // initialize the hardware ports
#if (USE_NOR_FLASH)

    /* ==== Port setting ==== */
    cs0_port_init();

#endif

#if (USE_SDRAM)

    /* ==== Port setting ==== */
    cs2_port_init();

#endif

    // initialize the bus state controllers
#if (USE_NOR_FLASH)

    /* ==== BSC setting ==== */
    cs0_init();

#endif

#if (USE_SDRAM)

    /* ==== BSC setting ==== */
    // warning: in this case also CS3 is configured due to hw behavior
    // see Userdef_BSC_CS2Init in bsc_userdef.c
    cs2_init();

#endif

#if (USE_NOR_FLASH | USE_SDRAM)

    address_data_lines_init();

#endif

    /* INTC setting */
    R_INTC_Init();

  /*==================================*/
  /* Choose if segment initialization */
  /* should be done or not.           */
  /* Return: 0 to omit seg_init       */
  /*         1 to run seg_init        */
  /*==================================*/
  return 1;
}




void cs0_init(void) {
  
    /* ---- CS0BCR settings ---- */
    BSC.CS0BCR = 0x10000C00uL;
                                    /* Idle Cycles between Write-read Cycles    */
                                    /*  and Write-write Cycles : 1 idle cycle   */
                                    /* Data Bus Size: 16-bit                    */

    /* ---- CS0WCR settings ----  */
    BSC.CS0WCR = 0x00000B40uL;
                                    /* Number of Delay Cycles from Address,     */
                                    /*  CS0# Assertion to RD#,WEn Assertion     */
                                    /*  : 1.5 cycles                            */
                                    /* Number of Access Wait Cycles: 6 cycles   */
                                    /* Delay Cycles from RD,WEn# negation to    */
                                    /*  Address,CSn# negation: 0.5 cycles       */  
}

#define SDRAM_MODE_CS2    (*(volatile uint16_t *)(0x3FFFD040))
#define SDRAM_MODE_CS3    (*(volatile uint16_t *)(0x3FFFE040))

void cs2_init(void) {
  
/*
*         Note : This configuration is invalid for a single SDRAM and is a 
*              : known limitation of the RSK+ board. The port pin used by 
*              : CS3 is configured for LED0. To allow SDRAM operation CS2 
*              : and CS3 must be configured to SDRAM. Option link R164 must
*              : NOT be fitted to avoid a Data Bus conflict on the SDRAM 
*              : and expansion buffers. In a new application with one SDRAM 
*              : always connect the SDRAM to CS3. On this RSK+ CS3 can not 
*              : be used in another configuration including the expansion 
*              : headers unless the SDRAM is completely disabled. For other 
*              : external memory mapped devices CS1 is available for use 
*              : with the expansion headers.
*              : See the hardware manual Bus State Controller 
*              : section 8.4.3 CS2WCR(SDRAM)
*/
  
    /* ==== CS2BCR settings ==== */
    /* Idle Cycles between Write-read Cycles  */
    /* and Write-write Cycles : 0 idle cycles */
    /* Memory type :SDRAM                     */
    /* Data Bus Size : 16-bit                 */
    BSC.CS2BCR = 0x00004C00ul;

    /* ==== CS3BCR settings ==== */
    /* SDRAM WORKAROUND - see Note */
    /* Idle Cycles between Write-read Cycles  */
    /* and Write-write Cycles : 0 idle cycles */
    /* Memory type :SDRAM                     */
    /* Data Bus Size : 16-bit                 */
    BSC.CS3BCR = 0x00004C00ul;

    /* ==== CS2/3WCR settings ==== */
    /* Precharge completion wait cycles: 1 cycle     */
    /* Wait cycles between ACTV command              */
    /* and READ(A)/WRITE(A) command : 1 cycles       */
    /* CAS latency for Area 3 : 2 cycles             */
    /* Auto-precharge startup wait cycles : 2 cycles */
    /* Idle cycles from REF command/self-refresh     */
    /* Release to ACTV/REF/MRS command : 5 cycles    */
    BSC.CS3WCR = 0x00004492ul;

    /* SDRAM WORKAROUND - see Note */
    BSC.CS2WCR = 0x00000480ul;

    /* ==== SDCR settings ==== */
    /* SDRAM WORKAROUND - see Note*/
    /* Row address for Area 2 : 13-bit    */
    /* Column Address for Area 2 : 9-bit  */
    /* Refresh Control :Refresh           */
    /* RMODE :Auto-refresh is performed   */
    /* BACTV :Auto-precharge mode         */
    /* Row address for Area 3 : 13-bit    */
    /* Column Address for Area 3 : 9-bit  */
    BSC.SDCR = 0x00110811ul;

    /* ==== RTCOR settings ==== */
    /* 7.64usec / 240nsec              */
    /*   = 128(0x80)cycles per refresh */
    BSC.RTCOR = 0xA55A0080ul;

    /* ==== RTCSR settings ==== */
    /* initialisation sequence start */
    /* Clock select B-phy/4          */
    /* Refresh count :Once           */
    BSC.RTCSR = 0xA55A0008ul;

    /* ==== SDRAM Mode Register ==== */
    /* Burst read (burst length 1)./Burst write */
    SDRAM_MODE_CS2 = 0;

    /* SDRAM WORKAROUND - see Note */
    SDRAM_MODE_CS3 = 0;  
}

void address_data_lines_init(void) {


	// configure the common data lines used from both memories
	#if (USE_SDRAM | USE_NOR_FLASH)

	/* ---- P6_0 : D0 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE6, 0, GPIO_PFCAE6_PFCAE60_SHIFT, GPIO_PFCAE6_PFCAE60);
    RZA_IO_RegWrite_16(&GPIO.PFCE6,  0, GPIO_PFCE6_PFCE60_SHIFT,   GPIO_PFCE6_PFCE60);
    RZA_IO_RegWrite_16(&GPIO.PFC6,   0, GPIO_PFC6_PFC60_SHIFT,     GPIO_PFC6_PFC60);
    RZA_IO_RegWrite_16(&GPIO.PMC6,   1, GPIO_PMC6_PMC60_SHIFT,     GPIO_PMC6_PMC60);
    RZA_IO_RegWrite_16(&GPIO.PIPC6,  1, GPIO_PIPC6_PIPC60_SHIFT,   GPIO_PIPC6_PIPC60);

    /* ---- P6_1 : D1 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE6, 0, GPIO_PFCAE6_PFCAE61_SHIFT, GPIO_PFCAE6_PFCAE61);
    RZA_IO_RegWrite_16(&GPIO.PFCE6,  0, GPIO_PFCE6_PFCE61_SHIFT,   GPIO_PFCE6_PFCE61);
    RZA_IO_RegWrite_16(&GPIO.PFC6,   0, GPIO_PFC6_PFC61_SHIFT,     GPIO_PFC6_PFC61);
    RZA_IO_RegWrite_16(&GPIO.PMC6,   1, GPIO_PMC6_PMC61_SHIFT,     GPIO_PMC6_PMC61);
    RZA_IO_RegWrite_16(&GPIO.PIPC6,  1, GPIO_PIPC6_PIPC61_SHIFT,   GPIO_PIPC6_PIPC61);

    /* ---- P6_2 : D2 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE6, 0, GPIO_PFCAE6_PFCAE62_SHIFT, GPIO_PFCAE6_PFCAE62);
    RZA_IO_RegWrite_16(&GPIO.PFCE6,  0, GPIO_PFCE6_PFCE62_SHIFT,   GPIO_PFCE6_PFCE62);
    RZA_IO_RegWrite_16(&GPIO.PFC6,   0, GPIO_PFC6_PFC62_SHIFT,     GPIO_PFC6_PFC62);
    RZA_IO_RegWrite_16(&GPIO.PMC6,   1, GPIO_PMC6_PMC62_SHIFT,     GPIO_PMC6_PMC62);
    RZA_IO_RegWrite_16(&GPIO.PIPC6,  1, GPIO_PIPC6_PIPC62_SHIFT,   GPIO_PIPC6_PIPC62);

    /* ---- P6_3 : D3 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE6, 0, GPIO_PFCAE6_PFCAE63_SHIFT, GPIO_PFCAE6_PFCAE63);
    RZA_IO_RegWrite_16(&GPIO.PFCE6,  0, GPIO_PFCE6_PFCE63_SHIFT,   GPIO_PFCE6_PFCE63);
    RZA_IO_RegWrite_16(&GPIO.PFC6,   0, GPIO_PFC6_PFC63_SHIFT,     GPIO_PFC6_PFC63);
    RZA_IO_RegWrite_16(&GPIO.PMC6,   1, GPIO_PMC6_PMC63_SHIFT,     GPIO_PMC6_PMC63);
    RZA_IO_RegWrite_16(&GPIO.PIPC6,  1, GPIO_PIPC6_PIPC63_SHIFT,   GPIO_PIPC6_PIPC63);

    /* ---- P6_4 : D4 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE6, 0, GPIO_PFCAE6_PFCAE64_SHIFT, GPIO_PFCAE6_PFCAE64);
    RZA_IO_RegWrite_16(&GPIO.PFCE6,  0, GPIO_PFCE6_PFCE64_SHIFT,   GPIO_PFCE6_PFCE64);
    RZA_IO_RegWrite_16(&GPIO.PFC6,   0, GPIO_PFC6_PFC64_SHIFT,     GPIO_PFC6_PFC64);
    RZA_IO_RegWrite_16(&GPIO.PMC6,   1, GPIO_PMC6_PMC64_SHIFT,     GPIO_PMC6_PMC64);
    RZA_IO_RegWrite_16(&GPIO.PIPC6,  1, GPIO_PIPC6_PIPC64_SHIFT,   GPIO_PIPC6_PIPC64);

    /* ---- P6_5 : D5 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE6, 0, GPIO_PFCAE6_PFCAE65_SHIFT, GPIO_PFCAE6_PFCAE65);
    RZA_IO_RegWrite_16(&GPIO.PFCE6,  0, GPIO_PFCE6_PFCE65_SHIFT,   GPIO_PFCE6_PFCE65);
    RZA_IO_RegWrite_16(&GPIO.PFC6,   0, GPIO_PFC6_PFC65_SHIFT,     GPIO_PFC6_PFC65);
    RZA_IO_RegWrite_16(&GPIO.PMC6,   1, GPIO_PMC6_PMC65_SHIFT,     GPIO_PMC6_PMC65);
    RZA_IO_RegWrite_16(&GPIO.PIPC6,  1, GPIO_PIPC6_PIPC65_SHIFT,   GPIO_PIPC6_PIPC65);

    /* ---- P6_6 : D6 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE6, 0, GPIO_PFCAE6_PFCAE66_SHIFT, GPIO_PFCAE6_PFCAE66);
    RZA_IO_RegWrite_16(&GPIO.PFCE6,  0, GPIO_PFCE6_PFCE66_SHIFT,   GPIO_PFCE6_PFCE66);
    RZA_IO_RegWrite_16(&GPIO.PFC6,   0, GPIO_PFC6_PFC66_SHIFT,     GPIO_PFC6_PFC66);
    RZA_IO_RegWrite_16(&GPIO.PMC6,   1, GPIO_PMC6_PMC66_SHIFT,     GPIO_PMC6_PMC66);
    RZA_IO_RegWrite_16(&GPIO.PIPC6,  1, GPIO_PIPC6_PIPC66_SHIFT,   GPIO_PIPC6_PIPC66);

    /* ---- P6_7 : D7 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE6, 0, GPIO_PFCAE6_PFCAE67_SHIFT, GPIO_PFCAE6_PFCAE67);
    RZA_IO_RegWrite_16(&GPIO.PFCE6,  0, GPIO_PFCE6_PFCE67_SHIFT,   GPIO_PFCE6_PFCE67);
    RZA_IO_RegWrite_16(&GPIO.PFC6,   0, GPIO_PFC6_PFC67_SHIFT,     GPIO_PFC6_PFC67);
    RZA_IO_RegWrite_16(&GPIO.PMC6,   1, GPIO_PMC6_PMC67_SHIFT,     GPIO_PMC6_PMC67);
    RZA_IO_RegWrite_16(&GPIO.PIPC6,  1, GPIO_PIPC6_PIPC67_SHIFT,   GPIO_PIPC6_PIPC67);

    /* ---- P6_8 : D8 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE6, 0, GPIO_PFCAE6_PFCAE68_SHIFT, GPIO_PFCAE6_PFCAE68);
    RZA_IO_RegWrite_16(&GPIO.PFCE6,  0, GPIO_PFCE6_PFCE68_SHIFT,   GPIO_PFCE6_PFCE68);
    RZA_IO_RegWrite_16(&GPIO.PFC6,   0, GPIO_PFC6_PFC68_SHIFT,     GPIO_PFC6_PFC68);
    RZA_IO_RegWrite_16(&GPIO.PMC6,   1, GPIO_PMC6_PMC68_SHIFT,     GPIO_PMC6_PMC68);
    RZA_IO_RegWrite_16(&GPIO.PIPC6,  1, GPIO_PIPC6_PIPC68_SHIFT,   GPIO_PIPC6_PIPC68);

    /* ---- P6_9 : D9 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE6, 0, GPIO_PFCAE6_PFCAE69_SHIFT, GPIO_PFCAE6_PFCAE69);
    RZA_IO_RegWrite_16(&GPIO.PFCE6,  0, GPIO_PFCE6_PFCE69_SHIFT,   GPIO_PFCE6_PFCE69);
    RZA_IO_RegWrite_16(&GPIO.PFC6,   0, GPIO_PFC6_PFC69_SHIFT,     GPIO_PFC6_PFC69);
    RZA_IO_RegWrite_16(&GPIO.PMC6,   1, GPIO_PMC6_PMC69_SHIFT,     GPIO_PMC6_PMC69);
    RZA_IO_RegWrite_16(&GPIO.PIPC6,  1, GPIO_PIPC6_PIPC69_SHIFT,   GPIO_PIPC6_PIPC69);

    /* ---- P6_10 : D10 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE6, 0, GPIO_PFCAE6_PFCAE610_SHIFT, GPIO_PFCAE6_PFCAE610);
    RZA_IO_RegWrite_16(&GPIO.PFCE6,  0, GPIO_PFCE6_PFCE610_SHIFT,   GPIO_PFCE6_PFCE610);
    RZA_IO_RegWrite_16(&GPIO.PFC6,   0, GPIO_PFC6_PFC610_SHIFT,     GPIO_PFC6_PFC610);
    RZA_IO_RegWrite_16(&GPIO.PMC6,   1, GPIO_PMC6_PMC610_SHIFT,     GPIO_PMC6_PMC610);
    RZA_IO_RegWrite_16(&GPIO.PIPC6,  1, GPIO_PIPC6_PIPC610_SHIFT,   GPIO_PIPC6_PIPC610);

    /* ---- P6_11 : D11 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE6, 0, GPIO_PFCAE6_PFCAE611_SHIFT, GPIO_PFCAE6_PFCAE611);
    RZA_IO_RegWrite_16(&GPIO.PFCE6,  0, GPIO_PFCE6_PFCE611_SHIFT,   GPIO_PFCE6_PFCE611);
    RZA_IO_RegWrite_16(&GPIO.PFC6,   0, GPIO_PFC6_PFC611_SHIFT,     GPIO_PFC6_PFC611);
    RZA_IO_RegWrite_16(&GPIO.PMC6,   1, GPIO_PMC6_PMC611_SHIFT,     GPIO_PMC6_PMC611);
    RZA_IO_RegWrite_16(&GPIO.PIPC6,  1, GPIO_PIPC6_PIPC611_SHIFT,   GPIO_PIPC6_PIPC611);

    /* ---- P6_12 : D12 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE6, 0, GPIO_PFCAE6_PFCAE612_SHIFT, GPIO_PFCAE6_PFCAE612);
    RZA_IO_RegWrite_16(&GPIO.PFCE6,  0, GPIO_PFCE6_PFCE612_SHIFT,   GPIO_PFCE6_PFCE612);
    RZA_IO_RegWrite_16(&GPIO.PFC6,   0, GPIO_PFC6_PFC612_SHIFT,     GPIO_PFC6_PFC612);
    RZA_IO_RegWrite_16(&GPIO.PMC6,   1, GPIO_PMC6_PMC612_SHIFT,     GPIO_PMC6_PMC612);
    RZA_IO_RegWrite_16(&GPIO.PIPC6,  1, GPIO_PIPC6_PIPC612_SHIFT,   GPIO_PIPC6_PIPC612);

    /* ---- P6_13 : D13 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE6, 0, GPIO_PFCAE6_PFCAE613_SHIFT, GPIO_PFCAE6_PFCAE613);
    RZA_IO_RegWrite_16(&GPIO.PFCE6,  0, GPIO_PFCE6_PFCE613_SHIFT,   GPIO_PFCE6_PFCE613);
    RZA_IO_RegWrite_16(&GPIO.PFC6,   0, GPIO_PFC6_PFC613_SHIFT,     GPIO_PFC6_PFC613);
    RZA_IO_RegWrite_16(&GPIO.PMC6,   1, GPIO_PMC6_PMC613_SHIFT,     GPIO_PMC6_PMC613);
    RZA_IO_RegWrite_16(&GPIO.PIPC6,  1, GPIO_PIPC6_PIPC613_SHIFT,   GPIO_PIPC6_PIPC613);

    /* ---- P6_14 : D14 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE6, 0, GPIO_PFCAE6_PFCAE614_SHIFT, GPIO_PFCAE6_PFCAE614);
    RZA_IO_RegWrite_16(&GPIO.PFCE6,  0, GPIO_PFCE6_PFCE614_SHIFT,   GPIO_PFCE6_PFCE614);
    RZA_IO_RegWrite_16(&GPIO.PFC6,   0, GPIO_PFC6_PFC614_SHIFT,     GPIO_PFC6_PFC614);
    RZA_IO_RegWrite_16(&GPIO.PMC6,   1, GPIO_PMC6_PMC614_SHIFT,     GPIO_PMC6_PMC614);
    RZA_IO_RegWrite_16(&GPIO.PIPC6,  1, GPIO_PIPC6_PIPC614_SHIFT,   GPIO_PIPC6_PIPC614);

    /* ---- P6_15 : D15 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE6, 0, GPIO_PFCAE6_PFCAE615_SHIFT, GPIO_PFCAE6_PFCAE615);
    RZA_IO_RegWrite_16(&GPIO.PFCE6,  0, GPIO_PFCE6_PFCE615_SHIFT,   GPIO_PFCE6_PFCE615);
    RZA_IO_RegWrite_16(&GPIO.PFC6,   0, GPIO_PFC6_PFC615_SHIFT,     GPIO_PFC6_PFC615);
    RZA_IO_RegWrite_16(&GPIO.PMC6,   1, GPIO_PMC6_PMC615_SHIFT,     GPIO_PMC6_PMC615);
    RZA_IO_RegWrite_16(&GPIO.PIPC6,  1, GPIO_PIPC6_PIPC615_SHIFT,   GPIO_PIPC6_PIPC615);

    #endif

    // configure the common address lines used for both memories
    #if (USE_SDRAM | USE_NOR_FLASH)

    /* ---- P7_9 : A1 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE79_SHIFT, GPIO_PFCAE7_PFCAE79);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE79_SHIFT,   GPIO_PFCE7_PFCE79);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC79_SHIFT,     GPIO_PFC7_PFC79);
    RZA_IO_RegWrite_16(&GPIO.PM7,    0, GPIO_PM7_PM79_SHIFT,       GPIO_PM7_PM79);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC79_SHIFT,     GPIO_PMC7_PMC79);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC79_SHIFT,   GPIO_PIPC7_PIPC79);

    /* ---- P7_10 : A2 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE710_SHIFT, GPIO_PFCAE7_PFCAE710);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE710_SHIFT,   GPIO_PFCE7_PFCE710);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC710_SHIFT,     GPIO_PFC7_PFC710);
    RZA_IO_RegWrite_16(&GPIO.PM7,    0, GPIO_PM7_PM710_SHIFT,       GPIO_PM7_PM710);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC710_SHIFT,     GPIO_PMC7_PMC710);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC710_SHIFT,   GPIO_PIPC7_PIPC710);

    /* ---- P7_11 : A3 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE711_SHIFT, GPIO_PFCAE7_PFCAE711);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE711_SHIFT,   GPIO_PFCE7_PFCE711);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC711_SHIFT,     GPIO_PFC7_PFC711);
    RZA_IO_RegWrite_16(&GPIO.PM7,    0, GPIO_PM7_PM711_SHIFT,       GPIO_PM7_PM711);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC711_SHIFT,     GPIO_PMC7_PMC711);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC711_SHIFT,   GPIO_PIPC7_PIPC711);

    /* ---- P7_12 : A4 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE712_SHIFT, GPIO_PFCAE7_PFCAE712);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE712_SHIFT,   GPIO_PFCE7_PFCE712);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC712_SHIFT,     GPIO_PFC7_PFC712);
    RZA_IO_RegWrite_16(&GPIO.PM7,    0, GPIO_PM7_PM712_SHIFT,       GPIO_PM7_PM712);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC712_SHIFT,     GPIO_PMC7_PMC712);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC712_SHIFT,   GPIO_PIPC7_PIPC712);

    /* ---- P7_13 : A5 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE713_SHIFT, GPIO_PFCAE7_PFCAE713);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE713_SHIFT,   GPIO_PFCE7_PFCE713);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC713_SHIFT,     GPIO_PFC7_PFC713);
    RZA_IO_RegWrite_16(&GPIO.PM7,    0, GPIO_PM7_PM713_SHIFT,       GPIO_PM7_PM713);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC713_SHIFT,     GPIO_PMC7_PMC713);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC713_SHIFT,   GPIO_PIPC7_PIPC713);

    /* ---- P7_14 : A6 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE714_SHIFT, GPIO_PFCAE7_PFCAE714);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE714_SHIFT,   GPIO_PFCE7_PFCE714);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC714_SHIFT,     GPIO_PFC7_PFC714);
    RZA_IO_RegWrite_16(&GPIO.PM7,    0, GPIO_PM7_PM714_SHIFT,       GPIO_PM7_PM714);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC714_SHIFT,     GPIO_PMC7_PMC714);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC714_SHIFT,   GPIO_PIPC7_PIPC714);

    /* ---- P7_15 : A7 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE715_SHIFT, GPIO_PFCAE7_PFCAE715);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE715_SHIFT,   GPIO_PFCE7_PFCE715);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC715_SHIFT,     GPIO_PFC7_PFC715);
    RZA_IO_RegWrite_16(&GPIO.PM7,    0, GPIO_PM7_PM715_SHIFT,       GPIO_PM7_PM715);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC715_SHIFT,     GPIO_PMC7_PMC715);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC715_SHIFT,   GPIO_PIPC7_PIPC715);

    /* ---- P8_0 : A8 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE8, 0, GPIO_PFCAE8_PFCAE80_SHIFT, GPIO_PFCAE8_PFCAE80);
    RZA_IO_RegWrite_16(&GPIO.PFCE8,  0, GPIO_PFCE8_PFCE80_SHIFT,   GPIO_PFCE8_PFCE80);
    RZA_IO_RegWrite_16(&GPIO.PFC8,   0, GPIO_PFC8_PFC80_SHIFT,     GPIO_PFC8_PFC80);
    RZA_IO_RegWrite_16(&GPIO.PMC8,   1, GPIO_PMC8_PMC80_SHIFT,     GPIO_PMC8_PMC80);
    RZA_IO_RegWrite_16(&GPIO.PIPC8,  1, GPIO_PIPC8_PIPC80_SHIFT,   GPIO_PIPC8_PIPC80);

    /* ---- P8_1 : A9 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE8, 0, GPIO_PFCAE8_PFCAE81_SHIFT, GPIO_PFCAE8_PFCAE81);
    RZA_IO_RegWrite_16(&GPIO.PFCE8,  0, GPIO_PFCE8_PFCE81_SHIFT,   GPIO_PFCE8_PFCE81);
    RZA_IO_RegWrite_16(&GPIO.PFC8,   0, GPIO_PFC8_PFC81_SHIFT,     GPIO_PFC8_PFC81);
    RZA_IO_RegWrite_16(&GPIO.PM8,    0, GPIO_PM8_PM81_SHIFT,       GPIO_PM8_PM81);
    RZA_IO_RegWrite_16(&GPIO.PMC8,   1, GPIO_PMC8_PMC81_SHIFT,     GPIO_PMC8_PMC81);
    RZA_IO_RegWrite_16(&GPIO.PIPC8,  1, GPIO_PIPC8_PIPC81_SHIFT,   GPIO_PIPC8_PIPC81);

    /* ---- P8_2 : A10 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE8, 0, GPIO_PFCAE8_PFCAE82_SHIFT, GPIO_PFCAE8_PFCAE82);
    RZA_IO_RegWrite_16(&GPIO.PFCE8,  0, GPIO_PFCE8_PFCE82_SHIFT,   GPIO_PFCE8_PFCE82);
    RZA_IO_RegWrite_16(&GPIO.PFC8,   0, GPIO_PFC8_PFC82_SHIFT,     GPIO_PFC8_PFC82);
    RZA_IO_RegWrite_16(&GPIO.PM8,    0, GPIO_PM8_PM82_SHIFT,       GPIO_PM8_PM82);
    RZA_IO_RegWrite_16(&GPIO.PMC8,   1, GPIO_PMC8_PMC82_SHIFT,     GPIO_PMC8_PMC82);
    RZA_IO_RegWrite_16(&GPIO.PIPC8,  1, GPIO_PIPC8_PIPC82_SHIFT,   GPIO_PIPC8_PIPC82);

    /* ---- P8_3 : A11 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE8, 0, GPIO_PFCAE8_PFCAE83_SHIFT, GPIO_PFCAE8_PFCAE83);
    RZA_IO_RegWrite_16(&GPIO.PFCE8,  0, GPIO_PFCE8_PFCE83_SHIFT,   GPIO_PFCE8_PFCE83);
    RZA_IO_RegWrite_16(&GPIO.PFC8,   0, GPIO_PFC8_PFC83_SHIFT,     GPIO_PFC8_PFC83);
    RZA_IO_RegWrite_16(&GPIO.PM8,    0, GPIO_PM8_PM83_SHIFT,       GPIO_PM8_PM83);
    RZA_IO_RegWrite_16(&GPIO.PMC8,   1, GPIO_PMC8_PMC83_SHIFT,     GPIO_PMC8_PMC83);
    RZA_IO_RegWrite_16(&GPIO.PIPC8,  1, GPIO_PIPC8_PIPC83_SHIFT,   GPIO_PIPC8_PIPC83);

    /* ---- P8_4 : A12 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE8, 0, GPIO_PFCAE8_PFCAE84_SHIFT, GPIO_PFCAE8_PFCAE84);
    RZA_IO_RegWrite_16(&GPIO.PFCE8,  0, GPIO_PFCE8_PFCE84_SHIFT,   GPIO_PFCE8_PFCE84);
    RZA_IO_RegWrite_16(&GPIO.PFC8,   0, GPIO_PFC8_PFC84_SHIFT,     GPIO_PFC8_PFC84);
    RZA_IO_RegWrite_16(&GPIO.PM8,    0, GPIO_PM8_PM84_SHIFT,       GPIO_PM8_PM84);
    RZA_IO_RegWrite_16(&GPIO.PMC8,   1, GPIO_PMC8_PMC84_SHIFT,     GPIO_PMC8_PMC84);
    RZA_IO_RegWrite_16(&GPIO.PIPC8,  1, GPIO_PIPC8_PIPC84_SHIFT,   GPIO_PIPC8_PIPC84);

    /* ---- P8_5 : A13 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE8, 0, GPIO_PFCAE8_PFCAE85_SHIFT, GPIO_PFCAE8_PFCAE85);
    RZA_IO_RegWrite_16(&GPIO.PFCE8,  0, GPIO_PFCE8_PFCE85_SHIFT,   GPIO_PFCE8_PFCE85);
    RZA_IO_RegWrite_16(&GPIO.PFC8,   0, GPIO_PFC8_PFC85_SHIFT,     GPIO_PFC8_PFC85);
    RZA_IO_RegWrite_16(&GPIO.PM8,    0, GPIO_PM8_PM85_SHIFT,       GPIO_PM8_PM85);
    RZA_IO_RegWrite_16(&GPIO.PMC8,   1, GPIO_PMC8_PMC85_SHIFT,     GPIO_PMC8_PMC85);
    RZA_IO_RegWrite_16(&GPIO.PIPC8,  1, GPIO_PIPC8_PIPC85_SHIFT,   GPIO_PIPC8_PIPC85);

    /* ---- P8_6 : A14 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE8, 0, GPIO_PFCAE8_PFCAE86_SHIFT, GPIO_PFCAE8_PFCAE86);
    RZA_IO_RegWrite_16(&GPIO.PFCE8,  0, GPIO_PFCE8_PFCE86_SHIFT,   GPIO_PFCE8_PFCE86);
    RZA_IO_RegWrite_16(&GPIO.PFC8,   0, GPIO_PFC8_PFC86_SHIFT,     GPIO_PFC8_PFC86);
    RZA_IO_RegWrite_16(&GPIO.PM8,    0, GPIO_PM8_PM86_SHIFT,       GPIO_PM8_PM86);
    RZA_IO_RegWrite_16(&GPIO.PMC8,   1, GPIO_PMC8_PMC86_SHIFT,     GPIO_PMC8_PMC86);
    RZA_IO_RegWrite_16(&GPIO.PIPC8,  1, GPIO_PIPC8_PIPC86_SHIFT,   GPIO_PIPC8_PIPC86);

#endif

    // configure the additional address lines for the NOR flash
	#if (USE_NOR_FLASH)

    /* ---- P8_7 : A15 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE8, 0, GPIO_PFCAE8_PFCAE87_SHIFT, GPIO_PFCAE8_PFCAE87);
    RZA_IO_RegWrite_16(&GPIO.PFCE8,  0, GPIO_PFCE8_PFCE87_SHIFT,   GPIO_PFCE8_PFCE87);
    RZA_IO_RegWrite_16(&GPIO.PFC8,   0, GPIO_PFC8_PFC87_SHIFT,     GPIO_PFC8_PFC87);
    RZA_IO_RegWrite_16(&GPIO.PM8,    0, GPIO_PM8_PM87_SHIFT,       GPIO_PM8_PM87);
    RZA_IO_RegWrite_16(&GPIO.PMC8,   1, GPIO_PMC8_PMC87_SHIFT,     GPIO_PMC8_PMC87);
    RZA_IO_RegWrite_16(&GPIO.PIPC8,  1, GPIO_PIPC8_PIPC87_SHIFT,   GPIO_PIPC8_PIPC87);

    /* ---- P8_8 : A16 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE8, 0, GPIO_PFCAE8_PFCAE88_SHIFT, GPIO_PFCAE8_PFCAE88);
    RZA_IO_RegWrite_16(&GPIO.PFCE8,  0, GPIO_PFCE8_PFCE88_SHIFT,   GPIO_PFCE8_PFCE88);
    RZA_IO_RegWrite_16(&GPIO.PFC8,   0, GPIO_PFC8_PFC88_SHIFT,     GPIO_PFC8_PFC88);
    RZA_IO_RegWrite_16(&GPIO.PM8,    0, GPIO_PM8_PM88_SHIFT,       GPIO_PM8_PM88);
    RZA_IO_RegWrite_16(&GPIO.PMC8,   1, GPIO_PMC8_PMC88_SHIFT,     GPIO_PMC8_PMC88);
    RZA_IO_RegWrite_16(&GPIO.PIPC8,  1, GPIO_PIPC8_PIPC88_SHIFT,   GPIO_PIPC8_PIPC88);

    /* ---- P8_9 : A17 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE8, 0, GPIO_PFCAE8_PFCAE89_SHIFT, GPIO_PFCAE8_PFCAE89);
    RZA_IO_RegWrite_16(&GPIO.PFCE8,  0, GPIO_PFCE8_PFCE89_SHIFT,   GPIO_PFCE8_PFCE89);
    RZA_IO_RegWrite_16(&GPIO.PFC8,   0, GPIO_PFC8_PFC89_SHIFT,     GPIO_PFC8_PFC89);
    RZA_IO_RegWrite_16(&GPIO.PM8,    0, GPIO_PM8_PM89_SHIFT,       GPIO_PM8_PM89);
    RZA_IO_RegWrite_16(&GPIO.PMC8,   1, GPIO_PMC8_PMC89_SHIFT,     GPIO_PMC8_PMC89);
    RZA_IO_RegWrite_16(&GPIO.PIPC8,  1, GPIO_PIPC8_PIPC89_SHIFT,   GPIO_PIPC8_PIPC89);

    /* ---- P8_10 : A18 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE8, 0, GPIO_PFCAE8_PFCAE810_SHIFT, GPIO_PFCAE8_PFCAE810);
    RZA_IO_RegWrite_16(&GPIO.PFCE8,  0, GPIO_PFCE8_PFCE810_SHIFT,   GPIO_PFCE8_PFCE810);
    RZA_IO_RegWrite_16(&GPIO.PFC8,   0, GPIO_PFC8_PFC810_SHIFT,     GPIO_PFC8_PFC810);
    RZA_IO_RegWrite_16(&GPIO.PM8,    0, GPIO_PM8_PM810_SHIFT,       GPIO_PM8_PM810);
    RZA_IO_RegWrite_16(&GPIO.PMC8,   1, GPIO_PMC8_PMC810_SHIFT,     GPIO_PMC8_PMC810);
    RZA_IO_RegWrite_16(&GPIO.PIPC8,  1, GPIO_PIPC8_PIPC810_SHIFT,   GPIO_PIPC8_PIPC810);

    /* ---- P8_11 : A19 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE8, 0, GPIO_PFCAE8_PFCAE811_SHIFT, GPIO_PFCAE8_PFCAE811);
    RZA_IO_RegWrite_16(&GPIO.PFCE8,  0, GPIO_PFCE8_PFCE811_SHIFT,   GPIO_PFCE8_PFCE811);
    RZA_IO_RegWrite_16(&GPIO.PFC8,   0, GPIO_PFC8_PFC811_SHIFT,     GPIO_PFC8_PFC811);
    RZA_IO_RegWrite_16(&GPIO.PM8,    0, GPIO_PM8_PM811_SHIFT,       GPIO_PM8_PM811);
    RZA_IO_RegWrite_16(&GPIO.PMC8,   1, GPIO_PMC8_PMC811_SHIFT,     GPIO_PMC8_PMC811);
    RZA_IO_RegWrite_16(&GPIO.PIPC8,  1, GPIO_PIPC8_PIPC811_SHIFT,   GPIO_PIPC8_PIPC811);

    /* ---- P8_12 : A20 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE8, 0, GPIO_PFCAE8_PFCAE812_SHIFT, GPIO_PFCAE8_PFCAE812);
    RZA_IO_RegWrite_16(&GPIO.PFCE8,  0, GPIO_PFCE8_PFCE812_SHIFT,   GPIO_PFCE8_PFCE812);
    RZA_IO_RegWrite_16(&GPIO.PFC8,   0, GPIO_PFC8_PFC812_SHIFT,     GPIO_PFC8_PFC812);
    RZA_IO_RegWrite_16(&GPIO.PMC8,   1, GPIO_PMC8_PMC812_SHIFT,     GPIO_PMC8_PMC812);
    RZA_IO_RegWrite_16(&GPIO.PIPC8,  1, GPIO_PIPC8_PIPC812_SHIFT,   GPIO_PIPC8_PIPC812);

    /* ---- P8_13 : A21 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE8, 0, GPIO_PFCAE8_PFCAE813_SHIFT, GPIO_PFCAE8_PFCAE813);
    RZA_IO_RegWrite_16(&GPIO.PFCE8,  0, GPIO_PFCE8_PFCE813_SHIFT,   GPIO_PFCE8_PFCE813);
    RZA_IO_RegWrite_16(&GPIO.PFC8,   0, GPIO_PFC8_PFC813_SHIFT,     GPIO_PFC8_PFC813);
    RZA_IO_RegWrite_16(&GPIO.PM8,    0, GPIO_PM8_PM813_SHIFT,       GPIO_PM8_PM813);
    RZA_IO_RegWrite_16(&GPIO.PMC8,   1, GPIO_PMC8_PMC813_SHIFT,     GPIO_PMC8_PMC813);
    RZA_IO_RegWrite_16(&GPIO.PIPC8,  1, GPIO_PIPC8_PIPC813_SHIFT,   GPIO_PIPC8_PIPC813);

    /* ---- P8_14 : A22 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE8, 0, GPIO_PFCAE8_PFCAE814_SHIFT, GPIO_PFCAE8_PFCAE814);
    RZA_IO_RegWrite_16(&GPIO.PFCE8,  0, GPIO_PFCE8_PFCE814_SHIFT,   GPIO_PFCE8_PFCE814);
    RZA_IO_RegWrite_16(&GPIO.PFC8,   0, GPIO_PFC8_PFC814_SHIFT,     GPIO_PFC8_PFC814);
    RZA_IO_RegWrite_16(&GPIO.PM8,    0, GPIO_PM8_PM814_SHIFT,       GPIO_PM8_PM814);
    RZA_IO_RegWrite_16(&GPIO.PMC8,   1, GPIO_PMC8_PMC814_SHIFT,     GPIO_PMC8_PMC814);
    RZA_IO_RegWrite_16(&GPIO.PIPC8,  1, GPIO_PIPC8_PIPC814_SHIFT,   GPIO_PIPC8_PIPC814);

    /* ---- P8_15 : A23 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE8, 0, GPIO_PFCAE8_PFCAE815_SHIFT, GPIO_PFCAE8_PFCAE815);
    RZA_IO_RegWrite_16(&GPIO.PFCE8,  0, GPIO_PFCE8_PFCE815_SHIFT,   GPIO_PFCE8_PFCE815);
    RZA_IO_RegWrite_16(&GPIO.PFC8,   0, GPIO_PFC8_PFC815_SHIFT,     GPIO_PFC8_PFC815);
    RZA_IO_RegWrite_16(&GPIO.PM8,    0, GPIO_PM8_PM815_SHIFT,       GPIO_PM8_PM815);
    RZA_IO_RegWrite_16(&GPIO.PMC8,   1, GPIO_PMC8_PMC815_SHIFT,     GPIO_PMC8_PMC815);
    RZA_IO_RegWrite_16(&GPIO.PIPC8,  1, GPIO_PIPC8_PIPC815_SHIFT,   GPIO_PIPC8_PIPC815);

    /* ---- P9_0 : A24 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */

    RZA_IO_RegWrite_16(&GPIO.PFCAE9, 0, GPIO_PFCAE9_PFCAE90_SHIFT, GPIO_PFCAE9_PFCAE90);
    RZA_IO_RegWrite_16(&GPIO.PFCE9,  0, GPIO_PFCE9_PFCE90_SHIFT,   GPIO_PFCE9_PFCE90);
    RZA_IO_RegWrite_16(&GPIO.PFC9,   0, GPIO_PFC9_PFC90_SHIFT,     GPIO_PFC9_PFC90);
    RZA_IO_RegWrite_16(&GPIO.PM9,    0, GPIO_PM9_PM90_SHIFT,       GPIO_PM9_PM90);
    RZA_IO_RegWrite_16(&GPIO.PMC9,   1, GPIO_PMC9_PMC90_SHIFT,     GPIO_PMC9_PMC90);
    RZA_IO_RegWrite_16(&GPIO.PIPC9,  1, GPIO_PIPC9_PIPC90_SHIFT,   GPIO_PIPC9_PIPC90);

    /* ---- P9_1 : A25 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE9, 0, GPIO_PFCAE9_PFCAE91_SHIFT, GPIO_PFCAE9_PFCAE91);
    RZA_IO_RegWrite_16(&GPIO.PFCE9,  0, GPIO_PFCE9_PFCE91_SHIFT,   GPIO_PFCE9_PFCE91);
    RZA_IO_RegWrite_16(&GPIO.PFC9,   0, GPIO_PFC9_PFC91_SHIFT,     GPIO_PFC9_PFC91);
    RZA_IO_RegWrite_16(&GPIO.PM9,    0, GPIO_PM9_PM91_SHIFT,       GPIO_PM9_PM91);
    RZA_IO_RegWrite_16(&GPIO.PMC9,   1, GPIO_PMC9_PMC91_SHIFT,     GPIO_PMC9_PMC91);
    RZA_IO_RegWrite_16(&GPIO.PIPC9,  1, GPIO_PIPC9_PIPC91_SHIFT,   GPIO_PIPC9_PIPC91);

	#endif

}


void CS0_PORTInit(void)
{
    /* ---- P7_0 : CS0 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE70_SHIFT, GPIO_PFCAE7_PFCAE70);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE70_SHIFT,   GPIO_PFCE7_PFCE70);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC70_SHIFT,     GPIO_PFC7_PFC70);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC70_SHIFT,     GPIO_PMC7_PMC70);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC70_SHIFT,   GPIO_PIPC7_PIPC70);

    /* ---- P7_6 : WE0# / DQMLL# ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE76_SHIFT, GPIO_PFCAE7_PFCAE76);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE76_SHIFT,   GPIO_PFCE7_PFCE76);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC76_SHIFT,     GPIO_PFC7_PFC76);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC76_SHIFT,     GPIO_PMC7_PMC76);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC76_SHIFT,   GPIO_PIPC7_PIPC76);

    /* ---- P7_8 : RD ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE78_SHIFT, GPIO_PFCAE7_PFCAE78);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE78_SHIFT,   GPIO_PFCE7_PFCE78);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC78_SHIFT,     GPIO_PFC7_PFC78);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC78_SHIFT,     GPIO_PMC7_PMC78);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC78_SHIFT,   GPIO_PIPC7_PIPC78);
}

void CS2_PORTInit(void)
{

    /* ---- P5_8 : CS2 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 6th multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE5, 1, GPIO_PFCAE5_PFCAE58_SHIFT, GPIO_PFCAE5_PFCAE58);
    RZA_IO_RegWrite_16(&GPIO.PFCE5,  0, GPIO_PFCE5_PFCE58_SHIFT,   GPIO_PFCE5_PFCE58);
    RZA_IO_RegWrite_16(&GPIO.PFC5,   1, GPIO_PFC5_PFC58_SHIFT,     GPIO_PFC5_PFC58);
    RZA_IO_RegWrite_16(&GPIO.PMC5,   1, GPIO_PMC5_PMC58_SHIFT,     GPIO_PMC5_PMC58);
    RZA_IO_RegWrite_16(&GPIO.PIPC5,  1, GPIO_PIPC5_PIPC58_SHIFT,   GPIO_PIPC5_PIPC58);

    /* ---- P7_1 : CS3 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE71_SHIFT, GPIO_PFCAE7_PFCAE71);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE71_SHIFT,   GPIO_PFCE7_PFCE71);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC71_SHIFT,     GPIO_PFC7_PFC71);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC71_SHIFT,     GPIO_PMC7_PMC71);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC71_SHIFT,   GPIO_PIPC7_PIPC71);

    /* ---- P7_2 : RAS# ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE72_SHIFT, GPIO_PFCAE7_PFCAE72);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE72_SHIFT,   GPIO_PFCE7_PFCE72);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC72_SHIFT,     GPIO_PFC7_PFC72);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC72_SHIFT,     GPIO_PMC7_PMC72);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC72_SHIFT,   GPIO_PIPC7_PIPC72);

    /* ---- P7_3 : CAS# ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE73_SHIFT, GPIO_PFCAE7_PFCAE73);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE73_SHIFT,   GPIO_PFCE7_PFCE73);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC73_SHIFT,     GPIO_PFC7_PFC73);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC73_SHIFT,     GPIO_PMC7_PMC73);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC73_SHIFT,   GPIO_PIPC7_PIPC73);

    /* ---- P7_4 : CKE ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE74_SHIFT, GPIO_PFCAE7_PFCAE74);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE74_SHIFT,   GPIO_PFCE7_PFCE74);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC74_SHIFT,     GPIO_PFC7_PFC74);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC74_SHIFT,     GPIO_PMC7_PMC74);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC74_SHIFT,   GPIO_PIPC7_PIPC74);

    /* ---- P7_5 : RD/WR# ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE75_SHIFT, GPIO_PFCAE7_PFCAE75);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE75_SHIFT,   GPIO_PFCE7_PFCE75);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC75_SHIFT,     GPIO_PFC7_PFC75);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC75_SHIFT,     GPIO_PMC7_PMC75);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC75_SHIFT,   GPIO_PIPC7_PIPC75);

    /* ---- P7_6 : DQMLL# ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE76_SHIFT, GPIO_PFCAE7_PFCAE76);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE76_SHIFT,   GPIO_PFCE7_PFCE76);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC76_SHIFT,     GPIO_PFC7_PFC76);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC76_SHIFT,     GPIO_PMC7_PMC76);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC76_SHIFT,   GPIO_PIPC7_PIPC76);

    /* ---- P7_7 : DQMLU# ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 1st multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE7, 0, GPIO_PFCAE7_PFCAE77_SHIFT, GPIO_PFCAE7_PFCAE77);
    RZA_IO_RegWrite_16(&GPIO.PFCE7,  0, GPIO_PFCE7_PFCE77_SHIFT,   GPIO_PFCE7_PFCE77);
    RZA_IO_RegWrite_16(&GPIO.PFC7,   0, GPIO_PFC7_PFC77_SHIFT,     GPIO_PFC7_PFC77);
    RZA_IO_RegWrite_16(&GPIO.PMC7,   1, GPIO_PMC7_PMC77_SHIFT,     GPIO_PMC7_PMC77);
    RZA_IO_RegWrite_16(&GPIO.PIPC7,  1, GPIO_PIPC7_PIPC77_SHIFT,   GPIO_PIPC7_PIPC77);
}


void module_clocks_enable(void) {
  
    /* Port level is keep in standby mode, [1], [1], [0],           */
    /* [1], [0], [1], CoreSight                                     */
    /* Keep io levels in standby mode */
    /* Coresight enabled */
    CPG.STBCR2  = ((0u << 7)|(0x6A)|(0u));

    /* IEBus, IrDA, LIN0, LIN1, MTU2, RSCAN2, [0], PWM              */
    CPG.STBCR3  = ((1u << 7)|(1u << 6)|(1u << 5)|(1u << 4)|(0u << 3)|(1u << 2)|(1u <<1)|(1u));

    /* SCIF0, SCIF1, SCIF2, SCIF3, SCIF4, SCIF5, SCIF6, SCIF7       */
    CPG.STBCR4  = 0x00u;

    /* SCIM0, SCIM1, SDG0, SDG1, SDG2, SDG3, OSTM0, OSTM1           */
    CPG.STBCR5  = 0x00u;

    /* A/D, CEU, DISCOM0, DISCOM1, DRC0, DRC1, JCU, RTClock         */
    CPG.STBCR6  = 0x00u;

    /* DVDEC0, DVDEC1, [1], ETHER, FLCTL, [1], USB0, USB1           */
    CPG.STBCR7  = 0x24u;

    /* IMR-LS20, IMR-LS21, IMR-LSD, MMCIF, MOST50, [1], SCUX, [1]   */
    CPG.STBCR8  = 0x05u;

    /* I2C0, I2C1, I2C2, I2C3, SPIBSC0, SPIBSC1, VDC50, VDC51       */
    CPG.STBCR9  = 0x00u;

    /* RSPI0, RSPI1, RSPI2, RSPI3, RSPI4, CD-ROMDEC, RSPDIF, RGPVG  */
    CPG.STBCR10 = 0x00u;

    /* [1], [1], SSIF0, SSIF1, SSIF2, SSIF3, SSIF4, SSIF5           */
    CPG.STBCR11 = 0xC0u;

    /* [1], [1], [1], [1], SDHI00, SDHI01, SDHI10, SDHI11           */
    CPG.STBCR12 = 0xF0u;

    DSB();
}



#pragma language=default

#ifdef __cplusplus
}
#endif
