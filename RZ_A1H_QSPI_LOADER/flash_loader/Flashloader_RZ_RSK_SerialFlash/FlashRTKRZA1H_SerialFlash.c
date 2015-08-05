/*************************************************************************
 *
 *   Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2014
 *
 *    File name   : FlashRTKRZA1H_SerialFlash.c
 *    Description : FlashLoader for RTKRZA1H Serial Flash
 *
 *                  The Serial Flash is Spansion S25FL512S. Capacity is 64MB
 *                  (131072 pages x 512 bytes. Number of blocks/sectors is 256,
 *                  each with 512 pages.
 *
 *    History :
 *    1. Date        : October 08, 2014
 *       Author      : Stanimir Bonev
 *       Description : flash loader for RTKRZA1H SerialFlash
 *
 *    $Revision: 32 $
 **************************************************************************/

/** include files **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <intrinsics.h>

#include <Renesas/ior7s721001.h>

#include "flash_loader.h" // The flash loader framework API declarations.
#include "flash_loader_extra.h"

/** local definitions **/

// These encompass all the commands and status checks the program makes.
#define FLASH_CMD_WREN      0x06
#define FLASH_CMD_WRDI      0x04
#define FLASH_CMD_RDID      0x9F
#define FLASH_CMD_RDSR      0x05
#define FLASH_CMD_RDCR      0x35
#define FLASH_CMD_WRR       0x01
#define FLASH_CMD_READ      0x03
#define FLASH_CMD_FTRD      0x0B
#define FLASH_CMD_PP        0x02
#define FLASH_CMD_4PP       0x12
#define FLASH_CMD_4QPP      0x34
#define FLASH_CMD_SE        0xD8
#define FLASH_CMD_4SE       0xDC
#define FLASH_CMD_BE        0xC7
#define FLASH_CMD_RESET     0xF0

// interface size used in SPI requests
#define ISIZE_1B            0x0
#define ISIZE_2B            0x1
#define ISIZE_4B            0x2

// address length used in SPI requests
#define ADDR_LEN_24         0x7
#define ADDR_LEN_32         0xF

// data length used in SPI requests
#define DATA_LEN_WORD       0xF
#define DATA_LEN_HWORD      0xC
#define DATA_LEN_BYTE       0x8

// flash functions return value
#define FLASH_OK            (0)
#define FLASH_ERROR         (1)
#define FLASH_TO_ERR        (2)

/** default settings **/
#define RST_DLY   35        /* 35 us */
#define ERASE_TO  2600000   /* 2600 ms */
#define PGM_TO    1300000   /* 1300 ms */
#define WRR_TO    2000000   /* 2000 ms */

#define OST_TPS   33ul
#define OST_DLY(x) ((x)*OST_TPS)

// parameters used in SPI interface functions
typedef uint32_t flashunit;

#define FIELD_GET(data,fb,lb) ((data>>fb) &  ((1UL<<(lb-fb+1)))-1)
#define ARRAY_SIZE(t)         (sizeof(t)/sizeof(t[0]))
#define OVERRIDE_BUFFER_PTR   (char*)theFlashParams.buffer

typedef struct def_flash_type_t
{
  uint32_t  id;
  uint8_t   block_size_exp;
  uint8_t   page_size_exp;
  uint8_t   device_size_exp;
} flash_type_t, * p_flash_type_t;

/** default settings **/

/** external functions **/

/** external data **/
extern void __iar_data_init3();

/** internal functions **/
static inline void     SPI_SetDataInterfaceSize(uint8_t isize);
static inline void     SPI_SetCommandInterfaceSize(uint8_t dsize);
static inline int8_t   SPI_Prepare();
static inline void     SPI_SetCommand(uint8_t command);
static inline void     SPI_SetAddress(uint32_t address, uint8_t len);
static inline void     SPI_SetData(uint32_t data, uint8_t len);
static inline void     SPI_EnableDataRead(uint8_t len);
static inline void     SPI_KeepSSL();
static inline void     SPI_ReleaseSSL();
static        uint32_t SPI_DoTransfer();
static        uint32_t SPI_GetDataRegister1();
static inline void     SPI_Init();
static        void     WENCmd(void);
static        void     RESETCmd(void);
static        uint8_t  WaitBusy(uint32_t timeout);
static        uint32_t GetCR1(void);
static        void     SetSR1CR1(uint32_t data);

#if USE_ARGC_ARGV
static const char* findOption(char* option, int with_value, int argc, char const* argv[]);
#endif /*USE_ARGC_ARGV*/

/** public data **/

/** private data **/
const flash_type_t flashType[] =
{
  {0x200201, 18, 9, 26},  /* S25FL512S */
  {0x20BA20, 16, 8, 22},  /* S25FL032P */
  {0x150201, 16, 8, 22},  /* FL032P1F24599012 */
};

__no_init uint32_t PageSize;
__no_init uint8_t  DualMemory;
__no_init uint32_t FlashPage;

/** public functions **/

/*************************************************************************
 * Function Name: FlashInit
 * Parameters: Flash Base Address, Image Size, Link Address, flags
 *
 * Return:  RESULT_OK (0)    - Init Successful
 *          RESULT_ERROR (1) - Init Fail
 * Description: Init flash and build layout.
 *
 *************************************************************************/
#if USE_ARGC_ARGV
uint32_t FlashInit(void *base_of_flash, uint32_t image_size,
                   uint32_t link_address, uint32_t flags,
                   int argc, char const *argv[])
#else
uint32_t FlashInit(void *base_of_flash, uint32_t image_size,
                   uint32_t link_address, uint32_t flags)
#endif
{
uint32_t i;
uint32_t reg0, reg1, id1, id2;
const char * arg;
const flash_type_t * flash_dev;

  DualMemory = 0;
  FlashPage = 0;
#if 1
#if USE_ARGC_ARGV
  __iar_data_init3();
  /* Pass external parameters to flashloader */
  arg = findOption("--page", 1, argc, argv);
  if(arg)
  {
    FlashPage = strtoul(arg,0,0);
    if(1 < FlashPage)
    {
      FlashPage = 0;
    }
  }
  if(findOption("--dualmem", 0, argc, argv))
  {
    DualMemory = 1;
  }
#endif /*USE_ARGC_ARGV*/
#endif
  /* SPI Init */
  SPI_Init();
  /* Initial flash prepare/check */
  if (SPI_Prepare()) return (RESULT_ERROR);

  /* Init OS Timer 0 */
  /* Clock enable */
  CPG_STBCR5_bit.MSTP51 = 0;
  /* stop timer */
  OSTM0TT = 1;
  /* disbale interrupts */
  OSTM0CTL_bit.OSTMMD0 = 0;
  /* Free runnung mode */
  OSTM0CTL_bit.OSTMMD1 = 1;

  SPIBSC_SMENR_0 = 0;

  /* Resets the flash memory */
  RESETCmd();

  /* Read FLASH memory signature */
  SPI_Prepare();
  SPI_SetCommand(FLASH_CMD_RDID);
  SPI_EnableDataRead(DATA_LEN_WORD);
  reg0 = SPI_DoTransfer();
  /* Check signature of flash 1 */
  if(DualMemory)
  {
    reg1 = SPI_GetDataRegister1();
    id1 = (reg1 & 0x000000FF)    | (reg1 & 0x00FF0000)>>8  | (reg0 & 0x000000FF)<<16;
    id2 = (reg1 & 0x0000FF00)>>8 | (reg1 & 0xFF000000)>>16 | (reg0 & 0x0000FF00)<<8;
  }
  else
    id1 = reg0 & 0x00FFFFFF;

  for(i = 0, flash_dev = flashType; i < ARRAY_SIZE(flashType); i++)
  {
    if(flash_dev->id == id1)
    {
      break;
    }
    ++flash_dev;
  }

  if(ARRAY_SIZE(flashType) == i)
  {
    /* Can't find compatible device*/
    return(RESULT_ERROR);
  }

  if(DualMemory)
  {
    /* check signature of flash 0, if 2 memories are used */
    for(i = 0, flash_dev = flashType; i < ARRAY_SIZE(flashType); i++)
    {
      if(flash_dev->id == id2)
      {
        break;
      }
      ++flash_dev;
    }

    if(ARRAY_SIZE(flashType) == i)
    {
      /* Can't find compatible device*/
      return(RESULT_ERROR);
    }
  }

  /* Set flash memory to QUAD mode */
  uint32_t cr1 = GetCR1();
  if(DualMemory) {
    cr1 |=  (1 << 1) | (1 << (1+8));
    cr1 &=~((3 << 6) | (3 << (6+8)));
    cr1 <<= 16;
  } else {
    cr1 |= (1 << 1);
    cr1 &=~(3 << 6);
    cr1 <<= 24;
  }
  // Clear SR1 and update CR1
  SetSR1CR1(cr1);
  WaitBusy(WRR_TO);

  sprintf(LAYOUT_OVERRIDE_BUFFER,"%d 0x%X",
          (1UL << (flash_dev->device_size_exp - flash_dev->block_size_exp)),
          (1UL << flash_dev->block_size_exp) << DualMemory);
  PageSize = (1UL << flash_dev->page_size_exp) << DualMemory;
  SET_PAGESIZE_OVERRIDE(PageSize);

  return (RESULT_OK | OVERRIDE_LAYOUT | OVERRIDE_PAGESIZE);
}

/*************************************************************************
 * Function Name: FlashWrite
 * Parameters: block base address, offset in block, data size, ram buffer
 *             pointer
 * Return: RESULT_OK (0)    - Write Successful
 *         RESULT_ERROR (1) - Write Fail
 * Description. Writes data in to serial flash
 *************************************************************************/
uint32_t FlashWrite(void *block_start,
                    uint32_t offset_into_block,
                    uint32_t count,
                    char const *buffer)
{
uint32_t size = 0;
/* Set destination address */
uint32_t Dest = ((uint32_t)block_start + offset_into_block) | (FlashPage << 26);
/* Set source address */
const uint32_t * Src = (const uint32_t *)(buffer);

  while(size < count)
  {
    WENCmd();

    SPI_SetDataInterfaceSize(ISIZE_4B);
    SPI_Prepare();
    SPI_SetCommand(FLASH_CMD_4QPP);
    SPI_SetAddress(Dest, ADDR_LEN_32);
    SPI_KeepSSL();
    SPI_DoTransfer();

    for(uint32_t cntr = 0 ; PageSize/4 > cntr; ++cntr)
    {
      /* Write one page */
      SPI_Prepare();
      if(DualMemory)
        SPI_SetData(*Src++, DATA_LEN_HWORD);
      else
        SPI_SetData(*Src++, DATA_LEN_WORD);
      /* if this is the last transfer - release ssl */
      if ((PageSize/4) - 1 == cntr) SPI_ReleaseSSL();
      SPI_DoTransfer();
    }
    size += PageSize;
    Dest += PageSize;

    /* Wait Page Program end */
    /* Wait WIP flag */
    if (WaitBusy(PGM_TO)) return(RESULT_ERROR);
  }

  return RESULT_OK;
}

/*************************************************************************
 * Function Name: FlashErase
 * Parameters:  Block Address, Block Size
 *
 * Return: 0
 *
 * Description: Erase block
 *************************************************************************/
uint32_t FlashErase(void *block_start,
                    uint32_t block_size)
{
uint32_t addr = (uint32_t)block_start | (FlashPage << 26);

  /* Write Enable Command */
  WENCmd();
  /* Sector Erase Command */
  SPI_Prepare();
  SPI_SetCommand(FLASH_CMD_4SE);
  SPI_SetAddress(addr, ADDR_LEN_32);
  SPI_DoTransfer();

  /* Wait Erase End */
  /* Wait WIP flag */
  if (WaitBusy(ERASE_TO)) return(RESULT_ERROR);

  return RESULT_OK;
}

/** private functions **/
#if USE_ARGC_ARGV
static const char* findOption(char* option, int with_value, int argc, char const* argv[])
{
  int i;

  for (i = 0; i < argc; i++)
  {
    if (strcmp(option, argv[i]) == 0)
    {
      if (with_value)
      {
        if (i + 1 < argc)
          return argv[i + 1]; // The next argument is the value.
        else
          return 0; // The option was found but there is no value to return.
      }
      else
      {
        return argv[i]; // Return the flag argument itself just to get a non-zero pointer.
      }
    }
  }
  return 0;
}
#endif // USE_ARGC_ARGV

/*************************************************************************
 * Function Name: SPI_SetDataInterfaceSize
 * Parameters:  isize - size of the interface used for the data
 *
 * Return: none
 *
 * Description: Configures the SPI data interface size.
 *************************************************************************/
static inline void SPI_SetDataInterfaceSize(uint8_t isize)
{
  SPIBSC_SMENR_0_bit.SPIDB = isize;
}

/*************************************************************************
 * Function Name: SPI_SetCommandInterfaceSize
 * Parameters:  isize - size of the interface used for the command
 *
 * Return: none
 *
 * Description: Configures the SPI command interface size.
 *************************************************************************/
static inline void SPI_SetCommandInterfaceSize(uint8_t isize)
{
  SPIBSC_SMENR_0_bit.CDB = isize;
}

/*************************************************************************
 * Function Name: SPI_Prepare
 * Parameters:  none
 *
 * Return: none
 *
 * Description: Prepare most of initial values for the SPI transfer.
 *************************************************************************/
static inline int8_t SPI_Prepare()
{
  if(!SPIBSC_CMNSR_0_bit.TEND) return -1;
  SPIBSC_SMCR_0_bit.SPIRE = 0;
  SPIBSC_SMCR_0_bit.SPIWE = 0;
  SPIBSC_SMENR_0_bit.ADE = 0;
  SPIBSC_SMENR_0_bit.CDE = 0;
  SPIBSC_SMENR_0_bit.SPIDE = 0;
  return 0;
}

/*************************************************************************
 * Function Name: SPI_SetCommand
 * Parameters:  command - command byte
 *
 * Return: none
 *
 * Description: Sets the command to be used in the next SPI transfer
 *************************************************************************/
static inline void SPI_SetCommand(uint8_t command)
{
  SPIBSC_SMCMR_0_bit.CMD = command;
  SPIBSC_SMENR_0_bit.CDE = 1;
}

/*************************************************************************
 * Function Name: SPI_SetAddress
 * Parameters:  address - 32-bit data address
 *                  len - address length (24/32bit)
 *
 * Return: none
 *
 * Description: Sets address to be used in the next SPI transfer
 *************************************************************************/
static inline void SPI_SetAddress(uint32_t address, uint8_t len)
{
  if(DualMemory) address >>= 1;
  SPIBSC_SMADR_0 = address;
  SPIBSC_SMENR_0_bit.ADE = len;
}

/*************************************************************************
 * Function Name: SPI_EnableDataRead
 * Parameters:  none
 *
 * Return: none
 *
 * Description: Configures the SPI module for data receiving
 *************************************************************************/
static inline void SPI_EnableDataRead(uint8_t len)
{
  SPIBSC_SMCR_0_bit.SPIRE = 1;
  SPIBSC_SMENR_0_bit.SPIDE = len;
}

/*************************************************************************
 * Function Name: SPI_SetData
 * Parameters:  data: data to be transmited
 *               len: data length (word/hword/byte)
 * Return: none
 *
 * Description: Sets "data" with size "len" to be transmitted in the
 *              next SPI transfer
 *************************************************************************/
static inline void SPI_SetData(uint32_t data, uint8_t len)
{
  SPIBSC_SMWDR0_0 = data;
  SPIBSC_SMCR_0_bit.SPIWE = 1;
  SPIBSC_SMENR_0_bit.SPIDE = len;
}

/*************************************************************************
 * Function Name: SPI_DoTransfer
 * Parameters:  Starts the SPI transfer
 *
 * Return: 32bit incoming data
 *
 * Description: Starts the configured transfer via SPI
 *************************************************************************/
static uint32_t SPI_DoTransfer()
{
  SPIBSC_SMCR_0_bit.SPIE = 1;
  while(!SPIBSC_CMNSR_0_bit.TEND);
  return SPIBSC_SMRDR0_0;
}

/*************************************************************************
 * Function Name: SPI_GetDataRegister1
 * Parameters:  none
 *
 * Return: 32bit incoming data
 *
 * Description: Gets value of SMRDR1 (in case 2 memories are used)
 *************************************************************************/
static uint32_t SPI_GetDataRegister1()
{
  return SPIBSC_SMRDR1_0;
}

/*************************************************************************
 * Function Name: SPI_KeepSSL
 * Parameters:  none
 *
 * Return: none
 *
 * Description: Keeps the SSL asserted after the next transfer
 *************************************************************************/
static inline void SPI_KeepSSL()
{
  SPIBSC_SMCR_0_bit.SSLKP = 1;
}

/*************************************************************************
 * Function Name: SPI_ReleaseSSL
 * Parameters:  none
 *
 * Return: none
 *
 * Description: Negates(releases) the SSL after the next transfer
 *************************************************************************/
static inline void SPI_ReleaseSSL()
{
  SPIBSC_SMCR_0_bit.SSLKP = 0;
}

/*************************************************************************
 * Function Name: SPI_Init
 * Parameters:  none
 *
 * Return: none
 *
 * Description: Some initializations to SPI module
 *************************************************************************/
static inline void SPI_Init()
{
  SPI_SetCommandInterfaceSize(ISIZE_1B);
  if(DualMemory)
    SPIBSC_CMNCR_0_bit.BSZ = 1;
  else
    SPIBSC_CMNCR_0_bit.BSZ = 0;
}

/*************************************************************************
 * Function Name: WENCmd
 * Parameters:  none
 *
 * Return: none
 *
 * Description: Enables writing to serial flash
 *************************************************************************/
static void WENCmd(void)
{
  SPI_Prepare();
  SPI_SetCommand(FLASH_CMD_WREN);
  SPI_DoTransfer();
}

/*************************************************************************
 * Function Name: RESETCmd
 * Parameters:  none
 *
 * Return: none
 *
 * Description: Resets the connected serial flash memories
 *************************************************************************/
static void RESETCmd(void)
{
  uint32_t hold;
  SPI_Prepare();
  SPI_SetCommand(FLASH_CMD_RESET);
  SPI_DoTransfer();
  /* start timer; */
  OSTM0TS = 1;
  hold = OSTM0CNT;
  while(OST_DLY(RST_DLY) > (OSTM0CNT - hold));
}

/*************************************************************************
 * Function Name: WaitBusy
 * Parameters:  none
 *
 * Return: none
 *
 * Description: Wait WIP flag in SR1 register to clear.
 *************************************************************************/
static uint8_t WaitBusy(uint32_t timeout)
{
uint32_t st;
uint32_t bb;
uint32_t err;
uint32_t hold;

  if(DualMemory)
  {
    bb  = (1UL << 0) | (1UL <<    8 );
    err = (3UL << 5) | (3UL << (5+8));
  }
  else
  {
    bb  = (1UL << 0);
    err = (3UL << 5);
  }

  /* start timer; */
  OSTM0TS = 1;
  hold = OSTM0CNT;
  timeout = OST_DLY(timeout);
  do
  {
    SPI_SetDataInterfaceSize(ISIZE_1B);
    SPI_Prepare();
    SPI_SetCommand(FLASH_CMD_RDSR);
    SPI_EnableDataRead(DATA_LEN_BYTE);
    st = SPI_DoTransfer();
    if(err & st)
    {
      return(RESULT_ERROR);
    }
    if(timeout < (OSTM0CNT - hold))
    {
      /* exit by timeout */
      return(RESULT_ERROR);
    }
  } while(bb & st);
  return 0;
}

/*************************************************************************
 * Function Name: GetCR1
 * Parameters:  none
 *
 * Return: uint32_t
 *
 * Description: Read CR1 of the flash memory.
 *************************************************************************/
static uint32_t GetCR1(void)
{
  SPI_Prepare();
  SPI_SetCommand(FLASH_CMD_RDCR);
  SPI_EnableDataRead(DATA_LEN_BYTE);
  return (SPI_DoTransfer() & 0xFFFF);
}

/*************************************************************************
 * Function Name: SetCR1SR1
 * Parameters:  none
 *
 * Return: none
 *
 * Description: Sets SR1 and CR1 of the flash memory.
 *************************************************************************/
static void SetSR1CR1(uint32_t data)
{
  WENCmd();
  SPI_Prepare();
  SPI_SetCommand(FLASH_CMD_WRR);
  SPI_SetData(data, DATA_LEN_HWORD);
  SPI_DoTransfer();
}

