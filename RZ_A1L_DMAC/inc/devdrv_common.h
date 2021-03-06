/******************************************************************************
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
******************************************************************************/
/******************************************************************************
* File Name     : devdrv_common.h
* Device(s)     : RZ/A1H (R7S721001)
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : Sample Program - Common driver header
******************************************************************************/
/*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*               : 21.03.2014 2.00
*******************************************************************************/

/* Multiple inclusion prevention macro */
#ifndef DEVDRV_COMMON_H
#define DEVDRV_COMMON_H

/******************************************************************************
Macro definitions
******************************************************************************/
/* CS0 */
#define BSC_AREA_CS0    (0x01)
/* CS1 */
#define BSC_AREA_CS1    (0x02)
/* CS2 */
#define BSC_AREA_CS2    (0x04)
/* CS3 */
#define BSC_AREA_CS3    (0x08)
/* CS4 */
#define BSC_AREA_CS4    (0x10)
/* CS5 */
#define BSC_AREA_CS5    (0x20)

/******************************************************************************
Functions Prototypes
******************************************************************************/
void R_BSC_Init(uint8_t area);
void Userdef_BSC_CS0Init(void);
void Userdef_BSC_CS1Init(void);
void Userdef_BSC_CS2Init(void);
void Userdef_BSC_CS3Init(void);
void Userdef_BSC_CS4Init(void);
void Userdef_BSC_CS5Init(void);

/* DEVDRV_COMMON_H */
#endif

/* End of File */
