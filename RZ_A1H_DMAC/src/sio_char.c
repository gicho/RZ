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
/*******************************************************************************
* File Name     : sample_sw.c
* Device(s)     : RZ/A1H (R7S721001)
* Tool-Chain    : GNUARM-RZv13.01-EABI
* H/W Platform  : RSK+RZA1H CPU Board
* Description   : Serial I/O character R/W (SCIF 2-ch process)
*******************************************************************************/
/*******************************************************************************
* History       : DD.MM.YYYY Version Description
*               : 18.06.2013 1.00
*               : 21.03.2014 2.00
*******************************************************************************/

/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_typedefs.h"
#include "dev_drv.h"
/* INTC Driver Header */
#include "devdrv_intc.h"
/* Device Driver common header */
/* UART Driver header */
#include "devdrv_scif_uart.h"
#include "sio_char.h"
#include "iodefine.h"
#include "rza_io_regrw.h"


/******************************************************************************
* Function Name: IntRXI2
* Description  : This function handles SCIF2 receive interrupts.
* Arguments    : none
* Return Value : none
******************************************************************************/
void IntRXI2 (uint32_t sense)
{
	/* Disable SCIF2 receive interrupts */
	R_INTC_Disable(INTC_ID_RXI2);

    /* Add code here */

	/* Enable SCIF2 receive interrupts */
	R_INTC_Enable(INTC_ID_RXI2);
}


/******************************************************************************
* Function Name: IoInitScif2
* Description  : This function initialises SCIF channel 2 as UART mode.
*              : The transmit and the receive of SCIF channel 2 are enabled.
* Arguments    : none
* Return Value : none
******************************************************************************/
void IoInitScif2(void)
{
    /* === Initialisation of SCIF2 ==== */
    /* P1 clock=66.67MHz CKS=0 SCBRR=17 Bit rate error=0.46% => Baud rate=115200bps */
    R_SCIF_UART_Init(DEVDRV_CH_2, SCIF_UART_MODE_RW, SCIF_CKS_DIVISION_1, 17);

    R_INTC_Disable(INTC_ID_RXI2);

    /* === initialisation of PORT function ==== */
    /* ---- P3_0 : TxD2 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 6th multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE3, 1, GPIO_PFCAE3_PFCAE30_SHIFT, GPIO_PFCAE3_PFCAE30);
    RZA_IO_RegWrite_16(&GPIO.PFCE3,  0, GPIO_PFCE3_PFCE30_SHIFT,   GPIO_PFCE3_PFCE30);
    RZA_IO_RegWrite_16(&GPIO.PFC3,   1, GPIO_PFC3_PFC30_SHIFT,     GPIO_PFC3_PFC30);
    RZA_IO_RegWrite_16(&GPIO.PMC3,   1, GPIO_PMC3_PMC30_SHIFT,     GPIO_PMC3_PMC30);
    RZA_IO_RegWrite_16(&GPIO.PIPC3,  1, GPIO_PIPC3_PIPC30_SHIFT,   GPIO_PIPC3_PIPC30);

    /* ---- P3_2 : RxD2 ---- */
    /* Port mode : Multiplex mode                     */
    /* Port function setting : 4th multiplex function */
    /* I/O control mode : Peripheral function         */
    RZA_IO_RegWrite_16(&GPIO.PFCAE3, 0, GPIO_PFCAE3_PFCAE32_SHIFT, GPIO_PFCAE3_PFCAE32);
    RZA_IO_RegWrite_16(&GPIO.PFCE3,  1, GPIO_PFCE3_PFCE32_SHIFT,   GPIO_PFCE3_PFCE32);
    RZA_IO_RegWrite_16(&GPIO.PFC3,   1, GPIO_PFC3_PFC32_SHIFT,     GPIO_PFC3_PFC32);
    RZA_IO_RegWrite_16(&GPIO.PMC3,   1, GPIO_PMC3_PMC32_SHIFT,     GPIO_PMC3_PMC32);
    RZA_IO_RegWrite_16(&GPIO.PIPC3,  1, GPIO_PIPC3_PIPC32_SHIFT,   GPIO_PIPC3_PIPC32);

    R_INTC_RegistIntFunc(INTC_ID_RXI2, &IntRXI2);
    R_INTC_SetPriority(INTC_ID_RXI2, 12uL);
    R_INTC_Enable(INTC_ID_RXI2);

    /* === Enable SCIF2 transmission/reception ==== */
    /* ---- Serial control register (SCSCRi) setting ---- */
    SCIF2.SCSCR = 0x0070u;
}

/******************************************************************************
* Function Name: IoGetchar
* Description  : One character is received from SCIF2, and it's data is returned.
*              : This function keeps waiting until it can obtain the receiving data.
* Arguments    : none
* Return Value : Character to receive (Byte).
******************************************************************************/
char_t IoGetchar(void)
{
    char_t data;

    /* Confirming receive error(ER,BRK,FER,PER) */
    if (SCIF2.SCFSR & 0x09Cu)
    {
        /* ---- Detect receive error ---- */
        /* Disable reception             */
        /* Reset receiving FIFO          */
        /* Clearing FIFO reception reset */
        /* Error bit clear               */
        /* Enable reception              */
        RZA_IO_RegWrite_16(&SCIF2.SCSCR, 0, SCIF2_SCSCR_RE_SHIFT,    SCIF2_SCSCR_RE);
        RZA_IO_RegWrite_16(&SCIF2.SCFCR, 1, SCIF2_SCFCR_RFRST_SHIFT, SCIF2_SCFCR_RFRST);
        RZA_IO_RegWrite_16(&SCIF2.SCFCR, 0, SCIF2_SCFCR_RFRST_SHIFT, SCIF2_SCFCR_RFRST);
        SCIF2.SCFSR &= (uint16_t)~0x9Cu;
        RZA_IO_RegWrite_16(&SCIF2.SCSCR, 1, SCIF2_SCSCR_RE_SHIFT,    SCIF2_SCSCR_RE);

        return 0;
    }

    /* Is there receive FIFO data? */
    while (0 == RZA_IO_RegRead_16(&SCIF2.SCFSR, SCIF2_SCFSR_RDF_SHIFT, SCIF2_SCFSR_RDF))
    {
        /* WAIT */
    }

    /* Read receive data */
    data = SCIF2.SCFRDR;
    /* Clear RDF */
    RZA_IO_RegWrite_16(&SCIF2.SCFSR, 0, SCIF2_SCFSR_RDF_SHIFT, SCIF2_SCFSR_RDF);

    /* Is it overflowed? */
    if (1 == RZA_IO_RegRead_16(&SCIF2.SCLSR, SCIF2_SCLSR_ORER_SHIFT, SCIF2_SCLSR_ORER))
    {
        /* ORER clear */
        RZA_IO_RegWrite_16(&SCIF2.SCLSR, 0, SCIF2_SCLSR_ORER_SHIFT, SCIF2_SCLSR_ORER);
    }

    return data;
}

/******************************************************************************
* Function Name: IoPutchar
* Description  : Character "buffer" is output to SCIF2.
*              : This function keeps waiting until it becomes the transmission
*              : enabled state.
* Arguments    : char_t buffer : character to output
* Return Value : None
******************************************************************************/
void IoPutchar(char_t buffer)
{
    /* Check if it is possible to transmit (TDFE flag) */
    while (0 == RZA_IO_RegRead_16(&SCIF2.SCFSR, SCIF2_SCFSR_TDFE_SHIFT, SCIF2_SCFSR_TDFE))
    {
        /* Wait */
    }

    /* Write the receiving data in TDR */
    SCIF2.SCFTDR = buffer;

    /* Clear TDRE and TEND flag */
    SCIF2.SCFSR &= (uint16_t)~0x0060u;
}


/* End of File */

