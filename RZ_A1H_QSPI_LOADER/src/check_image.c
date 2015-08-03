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
* Copyright (C) 2013 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name   : check_image.c
* Description : verifies the signature to check if there is a valid application
*******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_typedefs.h"
#include "iodefine.h"
// #include "spibsc.h"
#include "rza_io_regrw.h"

/******************************************************************************
Typedef definitions
******************************************************************************/


/******************************************************************************
Macro definitions
******************************************************************************/
void error_image(void);

char signature[] = "0123456789ABCDEF";

int check_image(uint32_t location)
{
    uint8_t p    = 0;
    uint16_t len = sizeof(signature);
    uint8_t sourceData;
    uint8_t* sourceDataPtr;

    sourceDataPtr = (uint8_t*) location;
    while(len > 0)
    {
    	sourceData = *sourceDataPtr;

    	if(sourceData != signature[p])
        {
            break;
        }

    	sourceDataPtr++;
    	len--;
    	p++;

    }

    return(len);

}


/******************************************************************************
* Function Name: error_image
* Description  : This function is only called if the final boot loader stage
*                cannot recognize that a valid users application is available.
*                It will not exit and configures the LED0 as an output and
*                flashes the LED
* Arguments    : none
* Return Value : none
******************************************************************************/
void error_image(void)
{
	uint32_t delay = 0x30000;
	uint8_t state = 0;

    /* The port pin for LED0 is configured as an output */
    RZA_IO_RegWrite_16(&GPIO.PMC7,  0, GPIO_PMC7_PMC71_SHIFT,  GPIO_PMC7_PMC71);
    RZA_IO_RegWrite_16(&GPIO.P7,  1, GPIO_P7_P71_SHIFT,  GPIO_P7_P71);
    RZA_IO_RegWrite_16(&GPIO.PM7,  0, GPIO_PM7_PM71_SHIFT,  GPIO_PM7_PM71);
    RZA_IO_RegWrite_16(&GPIO.PIPC7, 0, GPIO_PIPC7_PIPC71_SHIFT, GPIO_PIPC7_PIPC71);

    /* This function will never exit - the system has failed to boot. */
    while(1)
    {
    	RZA_IO_RegWrite_16(&GPIO.P7,  state, GPIO_P7_P71_SHIFT,  GPIO_P7_P71);
		while (--delay) {
				__asm__("nop");
		}

		delay = 0x30000;
		state = state?0:1;
    };
}
