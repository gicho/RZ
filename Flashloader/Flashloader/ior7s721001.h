/*************************************************************************
 **
 **    This file defines the Special Function Register for
 **    Renesas R7S721001
 **
 **    Used with ICCARM and AARM.
 **
 **    (c) Copyright IAR Systems 2013
 **
 **    $Revision: 1521 $
 **
 ***************************************************************************/

#ifndef __IOR7S721001_H
#define __IOR7S721001_H

#if (((__TID__ >> 8) & 0x7F) != 0x4F)     /* 0x4F = 79 dec */
#error This file should only be compiled by ICCARM/AARM
#endif

#include "io_macros.h"

/***************************************************************************
 ***************************************************************************
 **
 **    R7S721001 SPECIAL FUNCTION REGISTERS
 **
 ***************************************************************************
 ***************************************************************************
 ***************************************************************************/

/* C specific declarations  ************************************************/

#ifdef __IAR_SYSTEMS_ICC__

#ifndef _SYSTEM_BUILD
#pragma system_include
#endif

#if __LITTLE_ENDIAN__ == 0
#error This file should only be compiled in little endian mode
#endif

/* Cache ID Register */
typedef struct {
  __REG32 RTL_release   : 6;
  __REG32 Part_number   : 4;
  __REG32 CACHE_ID   		: 6;
  __REG32               : 8;
  __REG32 Implementer   : 8;
} __l2cc_cache_id_bits;

/* Cache Type Register */
typedef struct {
  __REG32 CLLI			    : 2;
  __REG32               : 4;
  __REG32 AI						: 1;
  __REG32 Isize		   		: 5;
  __REG32 CLLD			    : 2;
  __REG32               : 4;
  __REG32 AD						: 1;
  __REG32 Dsize		   		: 5;
  __REG32 H					    : 1;
  __REG32 ctype			    : 4;
  __REG32               : 2;
  __REG32 DB				    : 1;
} __l2cc_cache_type_bits;

/* Control Register */
typedef struct {
  __REG32 ENA				    : 1;
  __REG32               :31;
} __l2cc_control_bits;

/* Auxiliary Control Register */
typedef struct {
  __REG32 FLZE			    : 1;
  __REG32               : 9;
  __REG32 HPSODRE		    : 1;
  __REG32 SBDLE			    : 1;
  __REG32 ECC				    : 1;
  __REG32 SAIE			    : 1;
  __REG32               : 2;
  __REG32 A16				    : 1;
  __REG32 WS				    : 3;
  __REG32 EMBE			    : 1;
  __REG32 PE				    : 1;
  __REG32 SAOE			    : 1;
  __REG32 FWA				    : 2;
  __REG32 CRP				    : 1;
  __REG32 NSLE			    : 1;
  __REG32 NSIAC			    : 1;
  __REG32 DPE				    : 1;
  __REG32 IPE				    : 1;
  __REG32 EBRESPE		    : 1;
  __REG32               : 1;
} __l2cc_aux_control_bits;

/* Tag and Data RAM Latency Control Registers */
typedef struct {
  __REG32 RAMSL			    : 3;
  __REG32               : 1;
  __REG32 RAMRAL		    : 3;
  __REG32 					    : 1;
  __REG32 RAMWAL		    : 3;
  __REG32               :21;
} __l2cc_tag_ram_control_bits;

/* Event Counter Control Register */
typedef struct {
  __REG32 ECE				    : 1;
  __REG32 CR				    : 2;
  __REG32               :29;
} __l2cc_ev_counter_ctrl_bits;

/* Event Counter Configuration Registers */
typedef struct {
  __REG32 ECIG			    : 2;
  __REG32 CES				    : 4;
  __REG32               :26;
} __l2cc_ev_counter_cfg_bits;

/* Interrupt Mask Register
	 Masked Interrupt Status Register
	 Raw Interrupt Status Register */
typedef struct {
  __REG32 ECNTR			    : 1;
  __REG32 PARRT			    : 1;
  __REG32 PARRD			    : 1;
  __REG32 ERRWT			    : 1;
  __REG32 ERRWD			    : 1;
  __REG32 ERRRT			    : 1;
  __REG32 ERRRD			    : 1;
  __REG32 SLVERR		    : 1;
  __REG32 DECERR		    : 1;
  __REG32               :23;
} __l2cc_int_mask_bits;

#define L2CC_INT_CLEAR_ECNTR 	(1UL << 0)
#define L2CC_INT_CLEAR_PARRT 	(1UL << 1)
#define L2CC_INT_CLEAR_PARRD 	(1UL << 2)
#define L2CC_INT_CLEAR_ERRWT 	(1UL << 3)
#define L2CC_INT_CLEAR_ERRWD 	(1UL << 4)
#define L2CC_INT_CLEAR_ERRRT 	(1UL << 5)
#define L2CC_INT_CLEAR_ERRRD 	(1UL << 6)
#define L2CC_INT_CLEAR_SLVERR	(1UL << 7)
#define L2CC_INT_CLEAR_DECERR (1UL << 8)

/* Lockdown by Line Enable */
typedef struct {
  __REG32 ENA				    : 1;
  __REG32               :31;
} __l2cc_lock_line_en_bits;

/* Unlock All Lines */
typedef struct {
  __REG32 UNLOCK0		    : 1;
  __REG32 UNLOCK1		    : 1;
  __REG32 UNLOCK2		    : 1;
  __REG32 UNLOCK3		    : 1;
  __REG32 UNLOCK4		    : 1;
  __REG32 UNLOCK5		    : 1;
  __REG32 UNLOCK6		    : 1;
  __REG32 UNLOCK7		    : 1;
  __REG32 UNLOCK8		    : 1;
  __REG32 UNLOCK9		    : 1;
  __REG32 UNLOCK10	    : 1;
  __REG32 UNLOCK11	    : 1;
  __REG32 UNLOCK12	    : 1;
  __REG32 UNLOCK13	    : 1;
  __REG32 UNLOCK14	    : 1;
  __REG32 UNLOCK15	    : 1;
  __REG32               :16;
} __l2cc_unlock_way_bits;

/* Address Filtering Start */
typedef struct {
  __REG32 ENA				    : 1;
  __REG32 					    :19;
  __REG32 START_ADDR    :12;
} __l2cc_addr_filtering_start_bits;

/* Debug */
typedef struct {
  __REG32 DCL				    : 1;
  __REG32 DWB				    : 1;
  __REG32 SPNIDEN		    : 1;
  __REG32 					    :29;
} __l2cc_debug_ctrl_bits;

/* Prefetch Control */
typedef struct {
  __REG32 POFFSET				: 5;
  __REG32 					    :16;
  __REG32 NSIDESE		    : 1;
  __REG32 					    : 1;
  __REG32 IDLE			    : 1;
  __REG32 PDE				    : 1;
  __REG32 					    : 2;
  __REG32 DLWRAPRD	    : 1;
  __REG32 DPE				    : 1;
  __REG32 IPE				    : 1;
  __REG32 DLE				    : 1;
  __REG32 					    : 1;
} __l2cc_prefetch_ctrl_bits;

/* Power Control */
typedef struct {
  __REG32 STBYE					: 1;
  __REG32 DCLKE					: 1;
  __REG32 					    :30;
} __l2cc_power_ctrl_bits;

/* Remap Register (RMPR) */
typedef struct {
  __REG32                : 1;
  __REG32  AXI128        : 1;
  __REG32                :30;
} __lsi_rmpr_bits;

/* AXI Bus Control Register 0 (AXIBUSCTL0) */
typedef struct {
  __REG32  ETHAWCACHE    : 4;
  __REG32                : 4;
  __REG32  ETHARCACHE    : 4;
  __REG32                : 4;
  __REG32  JCUAWCACHE    : 4;
  __REG32                : 4;
  __REG32  JCUARCACHE    : 4;
  __REG32                : 4;
} __lsi_axibusctl0_bits;

/* AXI Bus Control Register 1 (AXIBUSCTL1) */
typedef struct {
  __REG32  IMR21AWCACHE  : 4;
  __REG32                : 4;
  __REG32  IMR21ARCACHE  : 4;
  __REG32                : 4;
  __REG32  IMR20AWCACHE  : 4;
  __REG32                : 4;
  __REG32  IMR20ARCACHE  : 4;
  __REG32                : 4;
} __lsi_axibusctl1_bits;

/* AXI Bus Control Register 2 (AXIBUSCTL2) */
typedef struct {
  __REG32  CEUAWCACHE    : 4;
  __REG32                :12;
  __REG32  IMRDAWCACHE   : 4;
  __REG32                : 4;
  __REG32  IMRDARCACHE   : 4;
  __REG32                : 4;
} __lsi_axibusctl2_bits;

/* AXI Bus Control Register 3 (AXIBUSCTL3) */
typedef struct {
  __REG32  RGP641AWCACHE : 4;
  __REG32                : 4;
  __REG32  RGP641ARCACHE : 4;
  __REG32                :12;
  __REG32  RGP640ARCACHE : 4;
  __REG32                : 4;
} __lsi_axibusctl3_bits;

/* AXI Bus Control Register 4 (AXIBUSCTL4) */
typedef struct {
  __REG32                	: 8;
  __REG32  RGP1280ARCACHE : 4;
  __REG32                	: 4;
  __REG32  RGP642AWCACHE 	: 4;
  __REG32                	: 4;
  __REG32  RGP642ARCACHE 	: 4;
  __REG32                	: 4;
} __lsi_axibusctl4_bits;

/* AXI Bus Control Register 5 (AXIBUSCTL5) */
typedef struct {
  __REG32  MLBAXCACHE    	: 2;
  __REG32                	:14;
  __REG32  RGP1281AWCACHE	: 4;
  __REG32                	: 4;
  __REG32  RGP1281ARCACHE	: 4;
  __REG32                	: 4;
} __lsi_axibusctl5_bits;

/* AXI Bus Control Register 6 (AXIBUSCTL6) */
typedef struct {
  __REG32                : 8;
  __REG32  VDC502ARCACHE : 4;
  __REG32                : 4;
  __REG32  VDC501AWCACHE : 4;
  __REG32                : 4;
  __REG32  VDC501ARCACHE : 4;
  __REG32                : 4;
} __lsi_axibusctl6_bits;

/* AXI Bus Control Register 7 (AXIBUSCTL7) */
typedef struct {
  __REG32                : 8;
  __REG32  VDC504ARCACHE : 4;
  __REG32                : 4;
  __REG32  VDC503AWCACHE : 4;
  __REG32                : 4;
  __REG32  VDC503ARCACHE : 4;
  __REG32                : 4;
} __lsi_axibusctl7_bits;

/* AXI Bus Control Register 8 (AXIBUSCTL8) */
typedef struct {
  __REG32  VDC511AWCACHE : 4;
  __REG32                : 4;
  __REG32  VDC511ARCACHE : 4;
  __REG32                : 4;
  __REG32  VDC505AWCACHE : 4;
  __REG32                : 4;
  __REG32  VDC505ARCACHE : 4;
  __REG32                : 4;
} __lsi_axibusctl8_bits;

/* AXI Bus Control Register 9 (AXIBUSCTL9) */
typedef struct {
  __REG32  VDC513AWCACHE : 4;
  __REG32                : 4;
  __REG32  VDC513ARCACHE : 4;
  __REG32                :12;
  __REG32  VDC512ARCACHE : 4;
  __REG32                : 4;
} __lsi_axibusctl9_bits;

/* AXI Bus Control Register 10 (AXIBUSCTL10) */
typedef struct {
  __REG32  VDC515AWCACHE : 4;
  __REG32                : 4;
  __REG32  VDC515ARCACHE : 4;
  __REG32                :12;
  __REG32  VDC514ARCACHE : 4;
  __REG32                : 4;
} __lsi_axibusctl10_bits;

/* AXI Bus Response Error Interrupt Control Register0 (AXIRERRCTL0) */
typedef struct {
  __REG32                : 8;
  __REG32  CEURERREN 		 : 1;
  __REG32                : 3;
  __REG32  IMRDRERREN 	 : 1;
  __REG32                : 3;
  __REG32  IMR21RERREN 	 : 1;
  __REG32                : 3;
  __REG32  IMR20RERREN 	 : 1;
  __REG32                : 3;
  __REG32  ETHRERREN 	 	 : 1;
  __REG32                : 3;
  __REG32  JCURERREN 	 	 : 1;
  __REG32                : 3;
} __lsi_axirerrctl0_bits;

/* AXI Bus Response Error Interrupt Control Register 1 (AXIRERRCTL1) */
typedef struct {
  __REG32                	:12;
  __REG32  RGP1281RERREN	: 1;
  __REG32                	: 3;
  __REG32  RGP1280RERREN 	: 1;
  __REG32                	: 3;
  __REG32  RGP642RERREN 	: 1;
  __REG32                	: 3;
  __REG32  RGP641RERREN 	: 1;
  __REG32                	: 3;
  __REG32  RGP640RERREN 	: 1;
  __REG32                	: 3;
} __lsi_axirerrctl1_bits;

/* AXI Bus Response Error Interrupt Control Register2 (AXIRERRCTL2) */
typedef struct {
  __REG32                	:12;
  __REG32  VDC505RERREN 	: 1;
  __REG32                	: 3;
  __REG32  VDC504RERREN 	: 1;
  __REG32                	: 3;
  __REG32  VDC503RERREN 	: 1;
  __REG32                	: 3;
  __REG32  VDC502RERREN 	: 1;
  __REG32                	: 3;
  __REG32  VDC501RERREN 	: 1;
  __REG32                	: 3;
} __lsi_axirerrctl2_bits;

/* AXI Bus Response Error Interrupt Control Register3 (AXIRERRCTL3) */
typedef struct {
  __REG32                	:12;
  __REG32  VDC515RERREN 	: 1;
  __REG32                	: 3;
  __REG32  VDC514RERREN 	: 1;
  __REG32                	: 3;
  __REG32  VDC513RERREN 	: 1;
  __REG32                	: 3;
  __REG32  VDC512RERREN 	: 1;
  __REG32                	: 3;
  __REG32  VDC511RERREN 	: 1;
  __REG32                	: 3;
} __lsi_axirerrctl3_bits;

/* AXI Bus Response Error Status Register 0 (AXIRERRST0) */
typedef struct {
  __REG32                	: 8;
  __REG32  CEUBRESP			 	: 2;
  __REG32                	: 2;
  __REG32  IMRDBRESP		 	: 2;
  __REG32  IMRDRRESP		 	: 2;
  __REG32  IMR21BRESP		 	: 2;
  __REG32  IMR21RRESP		 	: 2;
  __REG32  IMR20BRESP		 	: 2;
  __REG32  IMR20RRESP		 	: 2;
  __REG32  ETHBRESP			 	: 2;
  __REG32  ETHRRESP			 	: 2;
  __REG32  JCUBRESP			 	: 2;
  __REG32  JCURRESP			 	: 2;
} __lsi_axirerrst0_bits;

/* AXI Bus Response Error Status Register 1 (AXIRERRST1) */
typedef struct {
  __REG32                	:12;
  __REG32  RGP1281BRESP 	: 2;
  __REG32  RGP1281RRESP 	: 2;
  __REG32                	: 2;
  __REG32  RGP1280RRESP	 	: 2;
  __REG32  RGP642BRESP	 	: 2;
  __REG32  RGP642RRESP	 	: 2;
  __REG32  RGP641BRESP		: 2;
  __REG32  RGP641RRESP	 	: 2;
  __REG32  							 	: 2;
  __REG32  RGP640RRESP	 	: 2;
} __lsi_axirerrst1_bits;

/* AXI Bus Response Error Status Register 2 (AXIRERRST2) */
typedef struct {
  __REG32                	:12;
  __REG32  VDC505BRESP	 	: 2;
  __REG32  VDC505RRESP	 	: 2;
  __REG32                	: 2;
  __REG32  VDC504RRESP	 	: 2;
  __REG32  VDC503BRESP	 	: 2;
  __REG32  VDC503RRESP	 	: 2;
  __REG32                	: 2;
  __REG32  VDC502RRESP	 	: 2;
  __REG32  VDC501BRESP	 	: 2;
  __REG32  VDC501RRESP	 	: 2;
} __lsi_axirerrst2_bits;

/* AXI Bus Response Error Status Register 3 (AXIRERRST3) */
typedef struct {
  __REG32                	:12;
  __REG32  VDC515BRESP	 	: 2;
  __REG32  VDC515RRESP	 	: 2;
  __REG32                	: 2;
  __REG32  VDC514RRESP	 	: 2;
  __REG32  VDC513BRESP	 	: 2;
  __REG32  VDC513RRESP	 	: 2;
  __REG32                	: 2;
  __REG32  VDC512RRESP	 	: 2;
  __REG32  VDC511BRESP	 	: 2;
  __REG32  VDC511RRESP	 	: 2;
} __lsi_axirerrst3_bits;

/* AXI Bus Response Error Clear Register 0 (AXIRERRCLR0) */
typedef struct {
  __REG32                	: 8;
  __REG32  CEUBRESPCLR	 	: 1;
  __REG32                	: 3;
  __REG32  IMRDBRESPCLR	 	: 1;
  __REG32  							 	: 1;
  __REG32  IMRDRRESPCLR	 	: 1;
  __REG32  							 	: 1;
  __REG32  IMR21BRESPCLR	: 1;
  __REG32  							 	: 1;
  __REG32  IMR21RRESPCLR	: 1;
  __REG32  							 	: 1;
  __REG32  IMR20BRESPCLR	: 1;
  __REG32  							 	: 1;
  __REG32  IMR20RRESPCLR	: 1;
  __REG32  							 	: 1;
  __REG32  ETHBRESPCLR	 	: 1;
  __REG32  							 	: 1;
  __REG32  ETHRRESPCLR	 	: 1;
  __REG32  							 	: 1;
  __REG32  JCUBRESPCLR	 	: 1;
  __REG32  							 	: 1;
  __REG32  JCURRESPCLR	 	: 1;
  __REG32  							 	: 1;
} __lsi_axirerrclr0_bits;

/* AXI Bus Response Error Clear Register 1 (AXIRERRCLR1) */
typedef struct {
  __REG32                		:12;
  __REG32  RGP1281BRESPCLR	: 1;
  __REG32                		: 1;
  __REG32  RGP1281RRESPCLR	: 1;
  __REG32  							 		: 3;
  __REG32  RGP1280RRESPCLR	: 1;
  __REG32  							 		: 1;
  __REG32  RGP642BRESPCLR		: 1;
  __REG32  							 		: 1;
  __REG32  RGP642RRESPCLR		: 1;
  __REG32  							 		: 1;
  __REG32  RGP641BRESPCLR		: 1;
  __REG32  							 		: 1;
  __REG32  RGP641RRESPCLR		: 1;
  __REG32  							 		: 3;
  __REG32  RGP640RRESPCLR		: 1;
  __REG32  							 		: 1;
} __lsi_axirerrclr1_bits;

/* AXI Bus Response Error Clear Register 2 (AXIRERRCLR2) */
typedef struct {
  __REG32                	:12;
  __REG32  VDC505BRESPCLR	: 1;
  __REG32                	: 1;
  __REG32  VDC505RRESPCLR	: 1;
  __REG32                	: 3;
  __REG32  VDC504RRESPCLR	: 1;
  __REG32                	: 1;
  __REG32  VDC503BRESPCLR	: 1;
  __REG32                	: 1;
  __REG32  VDC503RRESPCLR	: 1;
  __REG32  							 	: 3;
  __REG32  VDC502RRESPCLR	: 1;
  __REG32  							 	: 1;
  __REG32  VDC501BRESPCLR	: 1;
  __REG32  							 	: 1;
  __REG32  VDC501RRESPCLR	: 1;
  __REG32  							 	: 1;
} __lsi_axirerrclr2_bits;

/* AXI Bus Response Error Clear Register 3 (AXIRERRCLR3) */
typedef struct {
  __REG32                	:12;
  __REG32  VDC515BRESPCLR	: 1;
  __REG32                	: 1;
  __REG32  VDC515RRESPCLR	: 1;
  __REG32                	: 3;
  __REG32  VDC514RRESPCLR	: 1;
  __REG32                	: 1;
  __REG32  VDC513BRESPCLR	: 1;
  __REG32                	: 1;
  __REG32  VDC513RRESPCLR	: 1;
  __REG32  							 	: 3;
  __REG32  VDC512RRESPCLR	: 1;
  __REG32  							 	: 1;
  __REG32  VDC511BRESPCLR	: 1;
  __REG32  							 	: 1;
  __REG32  VDC511RRESPCLR	: 1;
  __REG32  							 	: 1;
} __lsi_axirerrclr3_bits;

/* Interrupt Control Register 0 (ICR0) */
typedef struct {
  __REG16               : 1;
  __REG16 NMIF          : 1;
  __REG16               : 6;
  __REG16 NMIE          : 1;
  __REG16               : 6;
  __REG16 NMIL          : 1;
} __intc_icr0_bits;

/* Interrupt Control Register 1 (ICR1) */
typedef struct {
  __REG16 IRQ00S        : 1;
  __REG16 IRQ01S        : 1;
  __REG16 IRQ10S        : 1;
  __REG16 IRQ11S        : 1;
  __REG16 IRQ20S        : 1;
  __REG16 IRQ21S        : 1;
  __REG16 IRQ30S        : 1;
  __REG16 IRQ31S        : 1;
  __REG16 IRQ40S        : 1;
  __REG16 IRQ41S        : 1;
  __REG16 IRQ50S        : 1;
  __REG16 IRQ51S        : 1;
  __REG16 IRQ60S        : 1;
  __REG16 IRQ61S        : 1;
  __REG16 IRQ70S        : 1;
  __REG16 IRQ71S        : 1;
} __intc_icr1_bits;

/* IRQ Interrupt Request Register (IRQRR) */
typedef struct {
  __REG16 IRQ0F         : 1;
  __REG16 IRQ1F         : 1;
  __REG16 IRQ2F         : 1;
  __REG16 IRQ3F         : 1;
  __REG16 IRQ4F         : 1;
  __REG16 IRQ5F         : 1;
  __REG16 IRQ6F         : 1;
  __REG16 IRQ7F         : 1;
  __REG16               : 8;
} __intc_irqrr_bits;

/* Common Control Register (CMNCR) */
typedef struct {
  __REG32 HIZCNT        : 1;
  __REG32 HIZMEM        : 1;
  __REG32               : 7;
  __REG32 DPRTY         : 2;
  __REG32               :13;
  __REG32 AL0           : 1;
  __REG32               : 3;
  __REG32 TL0           : 1;
  __REG32               : 3;
} __bsc_cmncr_bits;

/* CSn Space Bus Control Register (CSnBCR) */
typedef struct {
  __REG32               : 9;
  __REG32 BSZ           : 2;
  __REG32               : 1;
  __REG32 TYPE          : 3;
  __REG32               : 1;
  __REG32 IWRRS         : 3;
  __REG32 IWRRD         : 3;
  __REG32 IWRWS         : 3;
  __REG32 IWRWD         : 3;
  __REG32 IWW           : 3;
  __REG32               : 1;
} __bsc_csxbcr_bits;

/* CS0 Space Wait Control Register (CS0WCR) */
typedef union {
  /* BSC_CS0WCR */
  struct {
    __REG32 HW            : 2;
    __REG32               : 4;
    __REG32 WM            : 1;
    __REG32 WR            : 4;
    __REG32 SW            : 2;
    __REG32               : 7;
    __REG32 BAS           : 1;
    __REG32               :11;
  };
  /* BSC_CS0WCR_BURST_ROM_ASYNC */
  struct {
    __REG32               : 6;
    __REG32 WM            : 1;
    __REG32 W             : 4;
    __REG32               : 5;
    __REG32 BW            : 2;
    __REG32               : 2;
    __REG32 BST           : 2;
    __REG32               :10;
  } _burst_rom_async;
  /* BSC_CS0WCR_BURST_ROM_SYNC */
  struct {
    __REG32               : 6;
    __REG32 WM            : 1;
    __REG32 W             : 4;
    __REG32               : 5;
    __REG32 BW            : 2;
    __REG32               :14;
  } _burst_rom_sync;
} __bsc_cs0wcr_bits;

/* CS1 Space Wait Control Register (CS1WCR) */
typedef struct {
  __REG32 HM            : 2;
  __REG32               : 4;
  __REG32 WM            : 1;
  __REG32 WR            : 4;
  __REG32 SW            : 2;
  __REG32               : 3;
  __REG32 WW            : 3;
  __REG32               : 1;
  __REG32 BAS           : 1;
  __REG32               :11;
} __bsc_cs1wcr_bits;

/* CS2 Space Wait Control Register (CS2WCR) */
typedef union {
  /* BSC_CS2WCR */
  struct {
    __REG32               : 6;
    __REG32 WM            : 1;
    __REG32 WR            : 4;
    __REG32               : 9;
    __REG32 BAS           : 1;
    __REG32               :11;
  };
  /* BSC_CS2WCR_SDRAM */
  struct {
    __REG32               : 7;
    __REG32 A2CL          : 2;
    __REG32 WR            :23;
  } _sdram;
} __bsc_cs2wcr_bits;

/* CS3 Space Wait Control Register (CS3WCR) */
typedef union {
  /* BSC_CS3WCR */
  struct {
    __REG32               : 6;
    __REG32 WM            : 1;
    __REG32 WR            : 4;
    __REG32               : 9;
    __REG32 BAS           : 1;
    __REG32               :11;
  };
  /* BSC_CS3WCR_SDRAM */
  struct {
    __REG32 WTRC          : 2;
    __REG32               : 1;
    __REG32 TRWL          : 2;
    __REG32               : 2;
    __REG32 A3CL          : 2;
    __REG32               : 1;
    __REG32 WTRCD         : 2;
    __REG32               : 1;
    __REG32 WTRP          : 2;
    __REG32               :17;
  } _sdram;
} __bsc_cs3wcr_bits;

/* CS4 Space Wait Control Register (CS4WCR) */
typedef union {
  /* BSC_CS4WCR */
  struct {
    __REG32 HM            : 2;
    __REG32               : 4;
    __REG32 WM            : 1;
    __REG32 WR            : 4;
    __REG32 SW            : 2;
    __REG32               : 3;
    __REG32 WW            : 3;
    __REG32               : 1;
    __REG32 BAS           : 1;
    __REG32               :11;
  };
  /* BSC_CS4WCR_BURST_ROM_ASYNC */
  struct {
    __REG32 HM            : 2;
    __REG32               : 4;
    __REG32 WM            : 1;
    __REG32 WR            : 4;
    __REG32 SW            : 2;
    __REG32               : 3;
    __REG32 BW            : 2;
    __REG32               : 2;
    __REG32 BST           : 2;
    __REG32               :10;
  } _burst_rom_async;
} __bsc_cs4wcr_bits;

/* CS5 Space Wait Control Register (CS5WCR) */
typedef struct {
  __REG32 HW            : 2;
  __REG32               : 4;
  __REG32 WM            : 1;
  __REG32 WR            : 4;
  __REG32 SW            : 2;
  __REG32               : 3;
  __REG32 WW            : 3;
  __REG32               : 1;
  __REG32 MPXW_BAS      : 1;
  __REG32 SZSEL         : 1;
  __REG32               :10;
} __bsc_cs5wcr_bits;

/* SDRAM Control Register (SDCR) */
typedef struct {
  __REG32 A3COL         : 2;
  __REG32               : 1;
  __REG32 A3ROW         : 2;
  __REG32               : 3;
  __REG32 BACTV         : 1;
  __REG32 PDOWN         : 1;
  __REG32 RMODE         : 1;
  __REG32 RFSH          : 1;
  __REG32               : 1;
  __REG32 DEEP          : 1;
  __REG32               : 2;
  __REG32 A2COL         : 2;
  __REG32               : 1;
  __REG32 A2ROW         : 2;
  __REG32               :11;
} __bsc_sdcr_bits;

/* Refresh Timer Control/Status Register (RTCSR) */
typedef struct {
  __REG32 RRC           : 3;
  __REG32 CKS           : 3;
  __REG32 CMIE          : 1;
  __REG32 CMF           : 1;
  __REG32               :24;
} __bsc_rtcsr_bits;

/* Timeout Status Register (TOSTR) */
typedef struct {
  __REG32 CS0TOSTF      : 1;
  __REG32 CS1TOSTF      : 1;
  __REG32 CS2TOSTF      : 1;
  __REG32 CS3TOSTF      : 1;
  __REG32 CS4TOSTF      : 1;
  __REG32 CS5TOSTF      : 1;
  __REG32               :26;
} __bsc_tostr_bits;

/* Timeout Enable Register (TOENR) */
typedef struct {
  __REG32 CS0TOEN       : 1;
  __REG32 CS1TOEN       : 1;
  __REG32 CS2TOEN       : 1;
  __REG32 CS3TOEN       : 1;
  __REG32 CS4TOEN       : 1;
  __REG32 CS5TOEN       : 1;
  __REG32               :26;
} __bsc_toenr_bits;

/* Channel Status Register n (CHSTAT_n) */
typedef struct {
  __REG32 EN            : 1;
  __REG32 RQST          : 1;
  __REG32 TACT          : 1;
  __REG32 SUS           : 1;
  __REG32 ER            : 1;
  __REG32 END           : 1;
  __REG32 TC            : 1;
  __REG32 SR            : 1;
  __REG32 DL            : 1;
  __REG32 DW            : 1;
  __REG32 DER           : 1;
  __REG32 MODE          : 1;
  __REG32               : 4;
  __REG32 INTMSK        : 1;
  __REG32               : 15;
} __dmac_chstat_x_bits;

/* Channel Control Register n (CHCTRL_n) */
typedef struct {
  __REG32 SETEN         : 1;
  __REG32 CLREN         : 1;
  __REG32 STG           : 1;
  __REG32 SWRST         : 1;
  __REG32 CLRRQ         : 1;
  __REG32 CLREND        : 1;
  __REG32 CLRTC         : 1;
  __REG32               : 1;
  __REG32 SETSUS        : 1;
  __REG32 CLRSUS        : 1;
  __REG32               : 6;
  __REG32 SETINTMSK     : 1;
  __REG32 CLRINTMSK     : 1;
  __REG32               :14;
} __dmac_chctrl_x_bits;

/* Channel Configuration Register (CHCFG_n) */
typedef struct {
  __REG32 SEL           : 3;
  __REG32 REQD          : 1;
  __REG32 LOEN          : 1;
  __REG32 HIEN          : 1;
  __REG32 LVL           : 1;
  __REG32               : 1;
  __REG32 AM            : 3;
  __REG32               : 1;
  __REG32 SDS           : 4;
  __REG32 DDS           : 4;
  __REG32 SAD           : 1;
  __REG32 DAD           : 1;
  __REG32 TM            : 1;
  __REG32               : 1;
  __REG32 DEM           : 1;
  __REG32               : 2;
  __REG32 SBE           : 1;
  __REG32 RSEL          : 1;
  __REG32 RSE           : 1;
  __REG32 REN           : 1;
  __REG32 DMS           : 1;
} __dmac_chcfg_x_bits;

/* Channel Interval Register (CHITVL_n) */
typedef struct {
  __REG32 ITVL          :16;
  __REG32               :16;
} __dmac_chitvl_x_bits;

/* Channel Extension Register (CHEXT_n) */
typedef struct {
  __REG32               : 4;
  __REG32 SCA           : 4;
  __REG32               : 4;
  __REG32 DCA           : 4;
  __REG32               :16;
} __dmac_chext_x_bits;

/* DMA Control Register (DCTRL_0_7, DCTRL_8_15) */
typedef struct {
  __REG32 PR            : 1;
  __REG32 LVINT         : 1;
  __REG32               :18;
  __REG32 LDCA          : 4;
  __REG32               : 4;
  __REG32 LWCA          : 4;
} __dmac_dctrl_0_7_8_15_bits;

/* DMA Status EN Register (DSTAT_EN_0_7) */
typedef struct {
  __REG32 EN0           : 1;
  __REG32 EN1           : 1;
  __REG32 EN2           : 1;
  __REG32 EN3           : 1;
  __REG32 EN4           : 1;
  __REG32 EN5           : 1;
  __REG32 EN6           : 1;
  __REG32 EN7           : 1;
  __REG32               :24;
} __dmac_dstat_en_0_7_bits;

/* DMA Status EN Register (DSTAT_EN_8_15) */
typedef struct {
  __REG32 EN8           : 1;
  __REG32 EN9           : 1;
  __REG32 EN10          : 1;
  __REG32 EN11          : 1;
  __REG32 EN12          : 1;
  __REG32 EN13          : 1;
  __REG32 EN14          : 1;
  __REG32 EN15          : 1;
  __REG32               :24;
} __dmac_dstat_en_8_15_bits;

/* DMA Status ER Register (DSTAT_ER_0_7) */
typedef struct {
  __REG32 ER0           : 1;
  __REG32 ER1           : 1;
  __REG32 ER2           : 1;
  __REG32 ER3           : 1;
  __REG32 ER4           : 1;
  __REG32 ER5           : 1;
  __REG32 ER6           : 1;
  __REG32 ER7           : 1;
  __REG32               :24;
} __dmac_dstat_er_0_7_bits;

/* DMA Status ER Register (DSTAT_ER_8_15) */
typedef struct {
  __REG32 ER8           : 1;
  __REG32 ER9           : 1;
  __REG32 ER10          : 1;
  __REG32 ER11          : 1;
  __REG32 ER12          : 1;
  __REG32 ER13          : 1;
  __REG32 ER14          : 1;
  __REG32 ER15          : 1;
  __REG32               :24;
} __dmac_dstat_er_8_15_bits;

/* DMA Status END Register (DSTAT_END_0_7) */
typedef struct{
  __REG32 END0          : 1;
  __REG32 END1          : 1;
  __REG32 END2          : 1;
  __REG32 END3          : 1;
  __REG32 END4          : 1;
  __REG32 END5          : 1;
  __REG32 END6          : 1;
  __REG32 END7          : 1;
  __REG32               :24;
} __dmac_dstat_end_0_7_bits;

/* DMA Status END Register (DSTAT_END_8_15) */
typedef struct {
  __REG32 END8          : 1;
  __REG32 END9          : 1;
  __REG32 END10         : 1;
  __REG32 END11         : 1;
  __REG32 END12         : 1;
  __REG32 END13         : 1;
  __REG32 END14         : 1;
  __REG32 END15         : 1;
  __REG32               :24;
} __dmac_dstat_end_8_15_bits;

/* DMA Status TC Register (DSTAT_TC_0_7) */
typedef struct {
  __REG32 TC0           : 1;
  __REG32 TC1           : 1;
  __REG32 TC2           : 1;
  __REG32 TC3           : 1;
  __REG32 TC4           : 1;
  __REG32 TC5           : 1;
  __REG32 TC6           : 1;
  __REG32 TC7           : 1;
  __REG32               :24;
} __dmac_dstat_tc_0_7_bits;

/* DMA Status TC Register (DSTAT_TC_8_15) */
typedef struct {
  __REG32 TC8           : 1;
  __REG32 TC9           : 1;
  __REG32 TC10          : 1;
  __REG32 TC11          : 1;
  __REG32 TC12          : 1;
  __REG32 TC13          : 1;
  __REG32 TC14          : 1;
  __REG32 TC15          : 1;
  __REG32               :24;
} __dmac_dstat_tc_8_15_bits;

/* DMA Status SUS Register (DSTAT_SUS_0_7) */
typedef struct{
  __REG32 SUS0          : 1;
  __REG32 SUS1          : 1;
  __REG32 SUS2          : 1;
  __REG32 SUS3          : 1;
  __REG32 SUS4          : 1;
  __REG32 SUS5          : 1;
  __REG32 SUS6          : 1;
  __REG32 SUS7          : 1;
  __REG32               :24;
} __dmac_dstat_sus_0_7_bits;

/* DMA Status SUS Register (DSTAT_SUS_8_15) */
typedef struct {
  __REG32 SUS8          : 1;
  __REG32 SUS9          : 1;
  __REG32 SUS10         : 1;
  __REG32 SUS11         : 1;
  __REG32 SUS12         : 1;
  __REG32 SUS13         : 1;
  __REG32 SUS14         : 1;
  __REG32 SUS15         : 1;
  __REG32               :24;
} __dmac_dstat_sus_8_15_bits;

/* DMA Extension Resource Selector 0 (DMARS0) */
typedef struct {
  __REG32 CH0RID        : 2;
  __REG32 CH0MID        : 7;
  __REG32               : 7;
  __REG32 CH1RID        : 2;
  __REG32 CH1MID        : 7;
  __REG32               : 7;
} __dmac_dmars0_bits;

/* DMA Extension Resource Selector 1 (DMARS1) */
typedef struct {
  __REG32 CH2RID        : 2;
  __REG32 CH2MID        : 7;
  __REG32               : 7;
  __REG32 CH3RID        : 2;
  __REG32 CH3MID        : 7;
  __REG32               : 7;
} __dmac_dmars1_bits;

/* DMA Extension Resource Selector 2 (DMARS2) */
typedef struct {
  __REG32 CH4RID        : 2;
  __REG32 CH4MID        : 7;
  __REG32               : 7;
  __REG32 CH5RID        : 2;
  __REG32 CH5MID        : 7;
  __REG32               : 7;
} __dmac_dmars2_bits;

/* DMA Extension Resource Selector 3 (DMARS3) */
typedef struct {
  __REG32 CH6RID        : 2;
  __REG32 CH6MID        : 7;
  __REG32               : 7;
  __REG32 CH7RID        : 2;
  __REG32 CH7MID        : 7;
  __REG32               : 7;
} __dmac_dmars3_bits;

/* DMA Extension Resource Selector 4 (DMARS4) */
typedef struct {
  __REG32 CH8RID        : 2;
  __REG32 CH8MID        : 7;
  __REG32               : 7;
  __REG32 CH9RID        : 2;
  __REG32 CH9MID        : 7;
  __REG32               : 7;
} __dmac_dmars4_bits;

/* DMA Extension Resource Selector 5 (DMARS5) */
typedef struct {
  __REG32 CH10RID       : 2;
  __REG32 CH10MID       : 7;
  __REG32               : 7;
  __REG32 CH11RID       : 2;
  __REG32 CH11MID       : 7;
  __REG32               : 7;
} __dmac_dmars5_bits;

/* DMA Extension Resource Selector 6 (DMARS6) */
typedef struct {
  __REG32 CH12RID       : 2;
  __REG32 CH12MID       : 7;
  __REG32               : 7;
  __REG32 CH13RID       : 2;
  __REG32 CH13MID       : 7;
  __REG32               : 7;
} __dmac_dmars6_bits;

/* DMA Extension Resource Selector 7 (DMARS7) */
typedef struct {
  __REG32 CH14RID       : 2;
  __REG32 CH14MID       : 7;
  __REG32               : 7;
  __REG32 CH15RID       : 2;
  __REG32 CH15MID       : 7;
  __REG32               : 7;
} __dmac_dmars7_bits;

/* Timer Control Register (TCR) */
typedef struct {
  __REG8 TPS            : 3;
  __REG8 CKEG           : 2;
  __REG8 CCLR           : 3;
} __mtu2_tcr_bits;

/* Timer Mode Register (TMDR) */
typedef struct {
  __REG8 MD             : 4;
  __REG8 BFA            : 1;
  __REG8 BFB            : 1;
  __REG8 BFE            : 1;
  __REG8                : 1;
} __mtu2_tmdr_bits;

/* Timer I/O Control Register (TIOR) */
typedef struct {
  __REG8 IOA            : 4;
  __REG8 IOB            : 4;
} __mtu2_tior_bits;

/* Timer I/O Control Register Low (TIORL) */
typedef struct {
  __REG8 IOC            : 4;
  __REG8 IOD            : 4;
} __mtu2_tiorl_bits;

/* Timer Interrupt Enable Register (TIER) */
typedef struct {
  __REG8 TGIEA          : 1;
  __REG8 TGIEB          : 1;
  __REG8 TGIEC          : 1;
  __REG8 TGIED          : 1;
  __REG8 TCIEV          : 1;
  __REG8 TCIEU          : 1;
  __REG8 TTGE2          : 1;
  __REG8 TTGE           : 1;
} __mtu2_tier_bits;

/* Timer Interrupt Enable Register 2 (TIER2) */
typedef struct {
  __REG8 TGIEE          : 1;
  __REG8 TGIEF          : 1;
  __REG8                : 5;
  __REG8 TTGE2          : 1;
} __mtu2_tier2_bits;

/* Timer Status Register (TSR) */
typedef struct {
  __REG8 TGFA           : 1;
  __REG8 TGFB           : 1;
  __REG8 TGFC           : 1;
  __REG8 TGFD           : 1;
  __REG8 TCFV           : 1;
  __REG8 TCFU           : 1;
  __REG8                : 1;
  __REG8 TCFD           : 1;
} __mtu2_tsr_bits;

/* Timer Status Register 2 (TSR2) */
typedef struct {
  __REG8 TGFE           : 1;
  __REG8 TGFF           : 1;
  __REG8                : 6;
} __mtu2_tsr2_bits;

/* Timer Buffer Operation Transfer Mode Register (TBTM) */
typedef struct {
  __REG8 TTSA           : 1;
  __REG8 TTSB           : 1;
  __REG8 TTSE           : 1;
  __REG8                : 5;
} __mtu2_tbtm_bits;

/* Timer Input Capture Control Register (TICCR) */
typedef struct {
  __REG8 I1AE           : 1;
  __REG8 I1BE           : 1;
  __REG8 I2AE           : 1;
  __REG8 I2BE           : 1;
  __REG8                : 4;
} __mtu2_ticcr_bits;

/* Timer A/D Converter Start Request Control Register (TADCR) */
typedef struct {
  __REG16 ITB4VE        : 1;
  __REG16 ITB3AE        : 1;
  __REG16 ITA4VE        : 1;
  __REG16 ITA3AE        : 1;
  __REG16 DT4BE         : 1;
  __REG16 UT4BE         : 1;
  __REG16 DT4AE         : 1;
  __REG16 UT4AE         : 1;
  __REG16               : 6;
  __REG16 BF            : 2;
} __mtu2_tadcr_bits;

/* Timer Start Register (TSTR) */
typedef struct {
  __REG8 CST0           : 1;
  __REG8 CST1           : 1;
  __REG8 CST2           : 1;
  __REG8                : 3;
  __REG8 CST3           : 1;
  __REG8 CST4           : 1;
} __mtu2_tstr_bits;

/* Timer Synchronous Register (TSYR) */
typedef struct {
  __REG8 SYNC0          : 1;
  __REG8 SYNC1          : 1;
  __REG8 SYNC2          : 1;
  __REG8                : 3;
  __REG8 SYNC3          : 1;
  __REG8 SYNC4          : 1;
} __mtu2_tsyr_bits;

/* Timer Read/Write Enable Register (TRWER) */
typedef struct {
  __REG8 RWE            : 1;
  __REG8                : 7;
} __mtu2_trwer_bits;

/* Timer Output Master Enable Register (TOER) */
typedef struct {
  __REG8 OE3B           : 1;
  __REG8 OE4A           : 1;
  __REG8 OE4B           : 1;
  __REG8 OE3D           : 1;
  __REG8 OE4C           : 1;
  __REG8 OE4D           : 1;
  __REG8                : 2;
} __mtu2_toer_bits;

/* Timer Output Control Register 1 (TOCR1) */
typedef struct {
  __REG8 OLSP           : 1;
  __REG8 OLSN           : 1;
  __REG8 TOCS           : 1;
  __REG8 TOCL           : 1;
  __REG8                : 2;
  __REG8 PSYE           : 1;
  __REG8                : 1;
} __mtu2_tocr1_bits;

/* Timer Output Control Register 2 (TOCR2) */
typedef struct {
  __REG8 OLS1P          : 1;
  __REG8 OLS1N          : 1;
  __REG8 OLS2P          : 1;
  __REG8 OLS2N          : 1;
  __REG8 OLS3P          : 1;
  __REG8 OLS3N          : 1;
  __REG8 BF             : 2;
} __mtu2_tocr2_bits;

/* Timer Output Level Buffer Register (TOLBR) */
typedef struct {
  __REG8 OLS1P          : 1;
  __REG8 OLS1N          : 1;
  __REG8 OLS2P          : 1;
  __REG8 OLS2N          : 1;
  __REG8 OLS3P          : 1;
  __REG8 OLS3N          : 1;
  __REG8                : 2;
} __mtu2_tolbr_bits;

/* Timer Gate Control Register (TGCR) */
typedef struct {
  __REG8 UF             : 1;
  __REG8 VF             : 1;
  __REG8 WF             : 1;
  __REG8 FB             : 1;
  __REG8 P              : 1;
  __REG8 N              : 1;
  __REG8 BDC            : 1;
  __REG8                : 1;
} __mtu2_tgcr_bits;

/* Timer Interrupt Skipping Set Register (TITCR) */
typedef struct {
  __REG8 _4VCOR         : 3;
  __REG8 T4VEN          : 1;
  __REG8 _3ACOR         : 3;
  __REG8 T3AEN          : 1;
} __mtu2_titcr_bits;

/* Timer Interrupt Skipping Counter (TITCNT) */
typedef struct {
  __REG8 _4VCNT         : 3;
  __REG8                : 1;
  __REG8 _3ACNT         : 3;
  __REG8                : 1;
} __mtu2_titcnt_bits;

/* Timer Buffer Transfer Set Register (TBTER) */
typedef struct {
  __REG8 BTE            : 2;
  __REG8                : 6;
} __mtu2_tbter_bits;

/* Timer Dead Timer Enable Register (TDER) */
typedef struct {
  __REG8 TDER           : 1;
  __REG8                : 7;
} __mtu2_tder_bits;

/* Timer Waveform Control Register (TWCR) */
typedef struct {
  __REG8 WRE            : 1;
  __REG8                : 6;
  __REG8 CCE            : 1;
} __mtu2_twcr_bits;

/* OSTM Count Enable Status Register (OSTMxTE) */
typedef struct {
  __REG8 OSTMTE         : 1;
  __REG8                : 7;
} __ostm_te_bits;

/* OSTM Count Start Trigger Register (OSTM0TS) */
#define OSTM0TS_OSTMTS 0x01

/* OSTM Count Start Trigger Register (OSTM1TS) */
#define OSTM1TS_OSTMTS 0x01

/* OSTM Count Stop Trigger Register (OSTM0TT) */
#define OSTM0TT_OSTMTT 0x01

/* OSTM Count Stop Trigger Register (OSTM1TT) */
#define OSTM1TT_OSTMTT 0x01

/* OSTM Control Register (OSTMxCTL) */
typedef struct {
  __REG8 OSTMMD0        : 1;
  __REG8 OSTMMD1        : 1;
  __REG8                : 6;
} __ostm_ctl_bits;

/* Watchdog Reset Control/Status Register (WTCNT) */
typedef union {
  struct {
    __REG8 __byte0;
    __REG8 __byte1;
  };
  /* WDT_WTCNT */
  struct {
    __REG16             :16;
  };
} __wdt_wtcnt_bits;

/* Watchdog Timer Control/Status Register (WTCSR) */
typedef union {
  struct {
    union {
      struct {
        __REG8 CKS      : 3;
        __REG8          : 2;
        __REG8 TME      : 1;
        __REG8 WT_IT    : 1;
        __REG8 IOVF     : 1;
      } __byte0_bits;
      __REG8 __byte0;
    };
    __REG8 KEY;
  };
  /* WDT_WTCSR */
  struct {
    __REG16             :16;
  };
} __wdt_wtcsr_bits;

/* Watchdog Reset Control/Status Register (WRCSR) */
typedef union {
  struct {
    union {
      struct {
        __REG8          : 5;
        __REG8 RSTS     : 1;
        __REG8 RSTE     : 1;
        __REG8 WOVF     : 1;
      } __byte0_bits;
      __REG8 __byte0;
    };
    __REG8 KEY;
  };
  /* WDT_WRCSR */
  struct {
    __REG16             :16;
  };
} __wdt_wrcsr_bits;

/* 64-Hz Counter (R64CNT) */
typedef struct {
  __REG8 _64Hz          : 1;
  __REG8 _32Hz          : 1;
  __REG8 _16Hz          : 1;
  __REG8 _8Hz           : 1;
  __REG8 _4Hz           : 1;
  __REG8 _2Hz           : 1;
  __REG8 _1Hz           : 1;
  __REG8                : 1;
} __rtc_r64cnt_bits;

/* Second Counter (RSECCNT) */
typedef struct {
  __REG8 _1second       : 4;
  __REG8 _10seconds     : 3;
  __REG8                : 1;
} __rtc_rseccnt_bits;

/* Minute Counter (RMINCNT) */
typedef struct {
  __REG8 _1minute       : 4;
  __REG8 _10minutes     : 3;
  __REG8                : 1;
} __rtc_rmincnt_bits;

/* Hour Counter (RHRCNT) */
typedef struct {
  __REG8 _1hour         : 4;
  __REG8 _10hours       : 2;
  __REG8                : 2;
} __rtc_rhrcnt_bits;

/* Day of Week Counter (RWKCNT) */
typedef struct {
  __REG8 Day            : 3;
  __REG8                : 5;
} __rtc_rwkcnt_bits;

/* Day Counter (RDAYCNT) */
typedef struct {
  __REG8 _1day          : 4;
  __REG8 _10days        : 2;
  __REG8                : 2;
} __rtc_rdaycnt_bits;

/* Month Counter (RMONCNT) */
typedef struct {
  __REG8 _1month        : 4;
  __REG8 _10months      : 1;
  __REG8                : 3;
} __rtc_rmoncnt_bits;

/* Year Counter (RYRCNT) */
typedef struct {
  __REG16 _1year        : 4;
  __REG16 _10years      : 4;
  __REG16 _100year      : 4;
  __REG16 _1000year     : 4;
} __rtc_ryrcnt_bits;

/* Second Alarm Register (RSECAR) */
typedef struct {
  __REG8 _1second       : 4;
  __REG8 _10seconds     : 3;
  __REG8 ENB            : 1;
} __rtc_rsecar_bits;

/* Minute Alarm Register (RMINAR) */
typedef struct {
  __REG8 _1minute       : 4;
  __REG8 _10minutes     : 3;
  __REG8 ENB            : 1;
} __rtc_rminar_bits;

/* Hour Alarm Register (RHRAR) */
typedef struct {
  __REG8 _1hour         : 4;
  __REG8 _10hours       : 2;
  __REG8                : 1;
  __REG8 ENB            : 1;
} __rtc_rhrar_bits;

/* Day of Week Alarm Register (RWKAR) */
typedef struct {
  __REG8 Day            : 3;
  __REG8                : 4;
  __REG8 ENB            : 1;
} __rtc_rwkar_bits;

/* Day Alarm Register (RDAYAR) */
typedef struct {
  __REG8 _1day          : 4;
  __REG8 _10days        : 2;
  __REG8                : 1;
  __REG8 ENB            : 1;
} __rtc_rdayar_bits;

/* Month Alarm Register (RMONAR) */
typedef struct {
  __REG8 _1month        : 4;
  __REG8 _10months      : 1;
  __REG8                : 2;
  __REG8 ENB            : 1;
} __rtc_rmonar_bits;

/* Year Alarm Register (RYRAR) */
typedef struct {
  __REG16 _1year        : 4;
  __REG16 _10years      : 4;
  __REG16 _100year      : 4;
  __REG16 _1000year     : 4;
} __rtc_ryrar_bits;

/* Control Register 1 (RCR1) */
typedef struct {
  __REG8 AF             : 1;
  __REG8                : 2;
  __REG8 AIE            : 1;
  __REG8 CIE            : 1;
  __REG8                : 2;
  __REG8 CF             : 1;
} __rtc_rcr1_bits;

/* Control Register 2 (RCR2) */
typedef struct {
  __REG8 START          : 1;
  __REG8 RESET          : 1;
  __REG8 ADJ            : 1;
  __REG8 RTCEN          : 1;
  __REG8 PES            : 3;
  __REG8 PEF            : 1;
} __rtc_rcr2_bits;

/* Control Register 3 (RCR3) */
typedef struct {
  __REG8                : 7;
  __REG8 ENB            : 1;
} __rtc_rcr3_bits;

/* Control Register 5 (RCR5) */
typedef struct {
  __REG8 RCKSEL         : 2;
  __REG8                : 6;
} __rtc_rcr5_bits;

/* Frequency Register High (RFRH) */
typedef struct {
  __REG16 RFC           : 3;
  __REG16               :12;
  __REG16 SEL64         : 1;
} __rtc_rfrh_bits;

/* Serial Mode Register (SCSMR) */
typedef struct {
  __REG16 CKS           : 2;
  __REG16               : 1;
  __REG16 STOP          : 1;
  __REG16 O_E           : 1;
  __REG16 PE            : 1;
  __REG16 CHR           : 1;
  __REG16 C_A           : 1;
  __REG16               : 8;
} __scif_scsmr_bits;

/* Serial Control Register (SCSCR) */
typedef struct {
  __REG16 CKE           : 2;
  __REG16               : 1;
  __REG16 REI           : 1;
  __REG16 RE            : 1;
  __REG16 TE            : 1;
  __REG16 RIE           : 1;
  __REG16 TIE           : 1;
  __REG16               : 8;
} __scif_scscr_bits;

/* Serial Status Register (SCFSR) */
typedef struct {
  __REG16 DR            : 1;
  __REG16 RDF           : 1;
  __REG16 PER           : 1;
  __REG16 FER           : 1;
  __REG16 BRK           : 1;
  __REG16 TDFE          : 1;
  __REG16 TEND          : 1;
  __REG16 ER            : 1;
  __REG16 NFER          : 4;
  __REG16 NPER          : 4;
} __scif_scfsr_bits;

/* FIFO Control Register (SCFCR) */
typedef struct {
  __REG16 LOOP          : 1;
  __REG16 RFRST         : 1;
  __REG16 TFRST         : 1;
  __REG16 MCE           : 1;
  __REG16 TTRG          : 2;
  __REG16 RTRG          : 2;
  __REG16 RSTRG         : 3;
  __REG16               : 5;
} __scif_scfcr_bits;

/* FIFO Data Count Set Register (SCFDR) */
typedef struct {
  __REG16 R             : 5;
  __REG16               : 3;
  __REG16 T             : 5;
  __REG16               : 3;
} __scif_scfdr_bits;

/* Serial Port Register (SCSPTR) */
typedef struct {
  __REG16 SPB2DT        : 1;
  __REG16 SPB2IO        : 1;
  __REG16 SCKDT         : 1;
  __REG16 SCKIO         : 1;
  __REG16 CTSDT         : 1;
  __REG16 CTSIO         : 1;
  __REG16 RTSDT         : 1;
  __REG16 RTSIO         : 1;
  __REG16               : 8;
} __scif_scsptr_bits;

/* Line Status Register (SCLSR) */
typedef struct {
  __REG16 ORER          : 1;
  __REG16               :15;
} __scif_sclsr_bits;

/* Serial Extension Mode Register (SCEMR) */
typedef struct {
  __REG16 ABCS          : 1;
  __REG16               : 6;
  __REG16 BGDM          : 1;
  __REG16               : 8;
} __scif_scemr_bits;

/* Serial Mode Register (SMR) */
typedef struct {
  __REG8 CKS            : 2;
  __REG8 MP             : 1;
  __REG8 STOP           : 1;
  __REG8 PM             : 1;
  __REG8 PE             : 1;
  __REG8 CHR            : 1;
  __REG8 CM             : 1;
} __scim_smr_bits;

/* Serial Control Register (SCR) */
typedef struct {
  __REG8 CKE            : 2;
  __REG8 TEIE           : 1;
  __REG8 MPIE           : 1;
  __REG8 RE             : 1;
  __REG8 TE             : 1;
  __REG8 RIE            : 1;
  __REG8 TIE            : 1;
} __scim_scr_bits;

/* Serial Status Register (SSR) */
typedef struct {
  __REG8 MPBT           : 1;
  __REG8 MPB            : 1;
  __REG8 TEND           : 1;
  __REG8 PER            : 1;
  __REG8 FER            : 1;
  __REG8 ORER           : 1;
  __REG8                : 2;
} __scim_ssr_bits;

/* Smart Card Mode Register (SCMR) */
typedef struct {
  __REG8 SMIF           : 1;
  __REG8                : 1;
  __REG8 SINV           : 1;
  __REG8 SDIR           : 1;
  __REG8                : 3;
  __REG8 BCP2           : 1;
} __scim_scmr_bits;

/* Serial Extended Mode Register (SEMR) */
typedef struct {
  __REG8                : 4;
  __REG8 ABCS           : 1;
  __REG8 NFEN           : 1;
  __REG8                : 2;
} __scim_semr_bits;

/* Noise Filter Setting Register (SNFR) */
typedef struct {
  __REG8 NFCS           : 3;
  __REG8                : 5;
} __scim_snfr_bits;

/* Extended Function Control Register (SECR) */
typedef struct {
  __REG8                : 1;
  __REG8 CTSE           : 1;
  __REG8                : 6;
} __scim_secr_bits;

/* IrDA Control Register (IRCR) */
typedef struct {
  __REG8                : 2;
  __REG8 IRRXINV        : 1;
  __REG8 IRTXINV        : 1;
  __REG8 IRCKS	        : 3;
  __REG8 IRE		        : 1;
} __scim_ircr_bits;

/* Control Register (SPCR) */
typedef struct {
  __REG8                : 2;
  __REG8 MODFEN         : 1;
  __REG8 MSTR           : 1;
  __REG8 SPEIE          : 1;
  __REG8 SPTIE          : 1;
  __REG8 SPE            : 1;
  __REG8 SPRIE          : 1;
} __rspi_spcr_bits;

/* Slave Select Polarity Register (SSLP) */
typedef struct {
  __REG8 SSL0P          : 1;
  __REG8                : 7;
} __rspi_sslp_bits;

/* Pin Control Register (SPPCR) */
typedef struct {
  __REG8 SPLP           : 1;
  __REG8                : 3;
  __REG8 MOIFV          : 1;
  __REG8 MOIFE          : 1;
  __REG8                : 2;
} __rspi_sppcr_bits;

/* Status Register (SPSR) */
typedef struct {
  __REG8 OVRF           : 1;
  __REG8                : 1;
  __REG8 MODF           : 1;
  __REG8                : 2;
  __REG8 SPTEF          : 1;
  __REG8 TEND           : 1;
  __REG8 SPRF           : 1;
} __rspi_spsr_bits;

/* Data Register (SPDR) */
typedef union {
  /* RSPI_SPDR_0 */
  /* RSPI_SPDR_1 */
  /* RSPI_SPDR_2 */
  /* RSPI_SPDR_3 */
  /* RSPI_SPDR_4 */
  struct {
    __REG32 DATA        :32;
  };
  struct {
    __REG16 __halfword0;
    __REG16 __halfword1;
  };
  struct {
    __REG8 __byte0;
    __REG8 __byte1;
    __REG8 __byte2;
    __REG8 __byte3;
  };
} __rspi_spdr_bits;

/* Sequence Control Register (SPSCR) */
typedef struct {
  __REG8 SPSLN          : 2;
  __REG8                : 6;
} __rspi_spscr_bits;

/* Sequence Status Register (SPSSR) */
typedef struct {
  __REG8 SPCP           : 2;
  __REG8                : 6;
} __rspi_spssr_bits;

/* Data Control Register (SPDCR) */
typedef struct {
  __REG8                : 5;
  __REG8 SPLW           : 2;
  __REG8 TXDMY          : 1;
} __rspi_spdcr_bits;

/* Clock Delay Register (SPCKD) */
typedef struct {
  __REG8 SCKDL          : 3;
  __REG8                : 5;
} __rspi_spckd_bits;

/* Slave Select Negation Delay Register (SSLND) */
typedef struct {
  __REG8 SLNDL          : 3;
  __REG8                : 5;
} __rspi_sslnd_bits;

/* Next-Access Delay Register (SPND) */
typedef struct {
  __REG8 SPNDL          : 3;
  __REG8                : 5;
} __rspi_spnd_bits;

/* Command Register (SPCMD) */
typedef struct {
  __REG16 CPHA          : 1;
  __REG16 CPOL          : 1;
  __REG16 BRDV          : 2;
  __REG16               : 3;
  __REG16 SSLKP         : 1;
  __REG16 SPB           : 4;
  __REG16 LSBF          : 1;
  __REG16 SPNDEN        : 1;
  __REG16 SLNDEN        : 1;
  __REG16 SCKDEN        : 1;
} __rspi_spcmd_bits;

/* Buffer Control Register (SPBFCR) */
typedef struct {
  __REG8 RXTRG          : 3;
  __REG8                : 1;
  __REG8 TXTRG          : 2;
  __REG8 RXRST          : 1;
  __REG8 TXRST          : 1;
} __rspi_spbfcr_bits;

/* Buffer Data Count Setting Register (SPBFDR) */
typedef struct {
  __REG16 R             : 6;
  __REG16               : 2;
  __REG16 T             : 4;
  __REG16               : 4;
} __rspi_spbfdr_bits;

/* Common Control Register (CMNCR) */
typedef struct {
  __REG32 BSZ           : 2;
  __REG32               : 1;
  __REG32 CPOL          : 1;
  __REG32 SSLP          : 1;
  __REG32 CPHAR         : 1;
  __REG32 CPHAT         : 1;
  __REG32               : 1;
  __REG32 IO0VF         : 2;
  __REG32               : 2;
  __REG32 IO2VF         : 2;
  __REG32 IO3VF         : 2;
  __REG32 MOIIO0        : 2;
  __REG32 MOIIO1        : 2;
  __REG32 MOIIO2        : 2;
  __REG32 MOIIO3        : 2;
  __REG32 SFDE          : 1;
  __REG32               : 6;
  __REG32 MD            : 1;
} __spibsc_cmncr_bits;

/* SSL Delay Register (SSLDR) */
typedef struct {
  __REG32 SCKDL         : 3;
  __REG32               : 5;
  __REG32 SLNDL         : 3;
  __REG32               : 5;
  __REG32 SPNDL         : 3;
  __REG32               :13;
} __spibsc_ssldr_bits;

/* Bit Rate Register (SPBCR) */
typedef struct {
  __REG32 BRDV          : 2;
  __REG32               : 6;
  __REG32 SPBR          : 8;
  __REG32               :16;
} __spibsc_spbcr_bits;

/* Data Read Control Register (DRCR) */
typedef struct {
  __REG32 SSLE          : 1;
  __REG32               : 7;
  __REG32 RBE           : 1;
  __REG32 RCF           : 1;
  __REG32               : 6;
  __REG32 RBURST        : 4;
  __REG32               : 4;
  __REG32 SSLN          : 1;
  __REG32               : 7;
} __spibsc_drcr_bits;

/* Data Read Command Setting Register (DRCMR) */
/* SPI Mode Command Setting Register (SMCMR) */
typedef struct {
  __REG32 OCMD          : 8;
  __REG32               : 8;
  __REG32 CMD           : 8;
  __REG32               : 8;
} __spibsc_drcmr_smcmr_bits;

/* Data Read Extended Address Setting Register (DREAR) */
typedef struct {
  __REG32 EAC           : 3;
  __REG32               :13;
  __REG32 EAV           : 8;
  __REG32               : 8;
} __spibsc_drear_bits;

/* Data Read Option Setting Register (DROPR) */
/* SPI Mode Option Setting Register (SMOPR) */
typedef struct {
  __REG32 OPD0          : 8;
  __REG32 OPD1          : 8;
  __REG32 OPD2          : 8;
  __REG32 OPD3          : 8;
} __spibsc_dropr_smopr_bits;

/* Data Read Enable Setting Register (DRENR) */
typedef struct {
  __REG32               : 4;
  __REG32 OPDE          : 4;
  __REG32 ADE           : 4;
  __REG32 OCDE          : 1;
  __REG32               : 1;
  __REG32 CDE           : 1;
  __REG32 DME           : 1;
  __REG32 DRDB          : 2;
  __REG32               : 2;
  __REG32 OPDB          : 2;
  __REG32               : 2;
  __REG32 ADB           : 2;
  __REG32               : 2;
  __REG32 OCDB          : 2;
  __REG32 CDB           : 2;
} __spibsc_drenr_bits;

/* SPI Mode Control Register (SMCR) */
typedef struct {
  __REG32 SPIE          : 1;
  __REG32 SPIWE         : 1;
  __REG32 SPIRE         : 1;
  __REG32               : 5;
  __REG32 SSLKP         : 1;
  __REG32               :23;
} __spibsc_smcr_bits;

/* SPI Mode Address Setting Register (SMADR) */
typedef struct {
  __REG32 ADR0_23       :24;
  __REG32 ADR24_31      : 8;
} __spibsc_smadr_bits;

/* SPI Mode Enable Setting Register (SMENR) */
typedef struct {
  __REG32 SPIDE         : 4;
  __REG32 OPDE          : 4;
  __REG32 ADE           : 4;
  __REG32 OCDE          : 1;
  __REG32               : 1;
  __REG32 CDE           : 1;
  __REG32 DME           : 1;
  __REG32 SPIDB         : 2;
  __REG32               : 2;
  __REG32 OPDB          : 2;
  __REG32               : 2;
  __REG32 ADB           : 2;
  __REG32               : 2;
  __REG32 OCDB          : 2;
  __REG32 CDB           : 2;
} __spibsc_smenr_bits;

/* SPI Read Mode Data Register 0 (SMRDR0) */
typedef union {
  /* SPIBSC_SMRDR0_0 */
  /* SPIBSC_SMRDR0_1 */
  struct {
    __REG32             :32;
  };
  struct {
    __REG16 __halfword0;
    __REG16 __halfword1;
  };
  struct {
    __REG8 __byte0;
    __REG8 __byte1;
    __REG8 __byte2;
    __REG8 __byte3;
  };
} __spibsc_smrdr0_bits;

/* SPI Read Mode Data Register 1 (SMRDR1) */
typedef union {
  /* SPIBSC_SMRDR1_0 */
  /* SPIBSC_SMRDR1_1 */
  struct {
    __REG32             :32;
  };
  struct {
    __REG16 __halfword0;
    __REG16 __halfword1;
  };
  struct {
    __REG8 __byte0;
    __REG8 __byte1;
    __REG8 __byte2;
    __REG8 __byte3;
  };
} __spibsc_smrdr1_bits;

/* SPI Write Mode Data Register 0 (SMWDR0) */
typedef union {
  /* SPIBSC_SMWDR0_0 */
  /* SPIBSC_SMWDR0_1 */
  struct {
    __REG32             :32;
  };
  struct {
    __REG16 __halfword0;
    __REG16 __halfword1;
  };
  struct {
    __REG8 __byte0;
    __REG8 __byte1;
    __REG8 __byte2;
    __REG8 __byte3;
  };
} __spibsc_smwdr0_bits;

/* SPI Write Mode Data Register 1 (CMRDR1) */
typedef union {
  /* SPIBSC_SMWDR1_0 */
  /* SPIBSC_SMWDR1_1 */
  struct {
    __REG32             :32;
  };
  struct {
    __REG16 __halfword0;
    __REG16 __halfword1;
  };
  struct {
    __REG8 __byte0;
    __REG8 __byte1;
    __REG8 __byte2;
    __REG8 __byte3;
  };
} __spibsc_smwdr1_bits;

/* Common Status Register (CMNSR) */
typedef struct {
  __REG32 TEND          : 1;
  __REG32 SSLF          : 1;
  __REG32               :30;
} __spibsc_cmnsr_bits;

/* Data Mode Address Setting Register (DRDMCR) */
/* SPI Mode Dummy Cycle Setting Register (SMDMCR) */
typedef struct {
  __REG32 DMCYC         : 3;
  __REG32               :13;
  __REG32 DMDB          : 2;
  __REG32               :14;
} __spibsc_drdmcr_smdmcr_bits;

/* Data Read DDR Enable Register (DRDRENR) */
typedef struct {
  __REG32 DRDRE         : 1;
  __REG32               : 3;
  __REG32 OPDRE         : 1;
  __REG32               : 3;
  __REG32 ADDRE         : 1;
  __REG32               :23;
} __spibsc_drdrenr_bits;

/* SPI Mode DDR Enable Register (SMDRENR) */
typedef struct {
  __REG32 SPIDRE        : 1;
  __REG32               : 3;
  __REG32 OPDRE         : 1;
  __REG32               : 3;
  __REG32 ADDRE         : 1;
  __REG32               :23;
} __spibsc_smdrenr_bits;

/* I2C Bus Control Register 1 (RIIC0ICCR1) */
typedef struct {
  __REG32 SDAI          : 1;
  __REG32 SCLI          : 1;
  __REG32 SDAO          : 1;
  __REG32 SCLO          : 1;
  __REG32 SOWP          : 1;
  __REG32 CLO           : 1;
  __REG32 IICRST        : 1;
  __REG32 ICE           : 1;
  __REG32               :24;
} __riic_iccr1_bits;

/* I2C Bus Control Register 2 (RIIC0ICCR2) */
typedef struct {
  __REG32               : 1;
  __REG32 ST            : 1;
  __REG32 RS            : 1;
  __REG32 SP            : 1;
  __REG32               : 1;
  __REG32 TRS           : 1;
  __REG32 MST           : 1;
  __REG32 BBSY          : 1;
  __REG32               :24;
} __riic_iccr2_bits;

/* I2C Bus Mode Register 1 (RIIC0ICMR1) */
typedef struct {
  __REG32 BC            : 3;
  __REG32 BCWP          : 1;
  __REG32 CKS           : 3;
  __REG32 MTWP          : 1;
  __REG32               :24;
} __riic_icmr1_bits;

/* I2C Bus Mode Register 2 (RIIC0ICMR2) */
typedef struct {
  __REG32 TMOS          : 1;
  __REG32 TMOL          : 1;
  __REG32 TMOH          : 1;
  __REG32               : 1;
  __REG32 SDDL          : 3;
  __REG32 DLCS          : 1;
  __REG32               :24;
} __riic_icmr2_bits;

/* I2C Bus Mode Register 3 (RIIC0ICMR3) */
typedef struct {
  __REG32 NF            : 2;
  __REG32 ACKBR         : 1;
  __REG32 ACKBT         : 1;
  __REG32 ACKWP         : 1;
  __REG32 RDRFS         : 1;
  __REG32 WAIT          : 1;
  __REG32 SMBS          : 1;
  __REG32               :24;
} __riic_icmr3_bits;

/* I2C Bus Function Enable Register (RIIC0ICFER) */
typedef struct {
  __REG32 TMOE          : 1;
  __REG32 MALE          : 1;
  __REG32 NALE          : 1;
  __REG32 SALE          : 1;
  __REG32 NACKE         : 1;
  __REG32 NFE           : 1;
  __REG32 SCLE          : 1;
  __REG32 FMPE          : 1;
  __REG32               :24;
} __riic_icfer_bits;

/* I2C Bus Status Enable Register (RIIC0ICSER) */
typedef struct {
  __REG32 SAR0E         : 1;
  __REG32 SAR1E         : 1;
  __REG32 SAR2E         : 1;
  __REG32 GCAE          : 1;
  __REG32               : 1;
  __REG32 DIDE          : 1;
  __REG32               : 1;
  __REG32 HOAE          : 1;
  __REG32               :24;
} __riic_icser_bits;

/* I2C Bus Interrupt Enable Register (RIIC0ICIER) */
typedef struct {
  __REG32 TMOIE         : 1;
  __REG32 ALIE          : 1;
  __REG32 STIE          : 1;
  __REG32 SPIE          : 1;
  __REG32 NAKIE         : 1;
  __REG32 RIE           : 1;
  __REG32 TEIE          : 1;
  __REG32 TIE           : 1;
  __REG32               :24;
} __riic_icier_bits;

/* I2C Bus Status Register 1 (RIIC0ICSR1) */
typedef struct {
  __REG32 AAS0          : 1;
  __REG32 AAS1          : 1;
  __REG32 AAS2          : 1;
  __REG32 GCA           : 1;
  __REG32               : 1;
  __REG32 DID           : 1;
  __REG32               : 1;
  __REG32 HOA           : 1;
  __REG32               :24;
} __riic_icsr1_bits;

/* I2C Bus Status Register 2 (RIIC0ICSR2) */
typedef struct {
  __REG32 TMOF          : 1;
  __REG32 AL            : 1;
  __REG32 START         : 1;
  __REG32 STOP          : 1;
  __REG32 NACKF         : 1;
  __REG32 RDRF          : 1;
  __REG32 TEND          : 1;
  __REG32 TDRE          : 1;
  __REG32               :24;
} __riic_icsr2_bits;

/* I2C Slave Address Register y (RIIC0ICSARy) */
typedef struct {
  __REG32 SVA0          : 1;
  __REG32 SVA           : 9;
  __REG32               : 5;
  __REG32 FS            : 1;
  __REG32               :16;
} __riic_icsar_bits;

/* I2C Bus Bit Rate Low-Level Register (RIIC0ICBRL) */
typedef struct {
  __REG32 BRL           : 5;
  __REG32               :27;
} __riic_icbrl_bits;

/* I2C Bus Bit Rate High-Level Register (RIIC0ICBRH) */
typedef struct {
  __REG32 BRH           : 5;
  __REG32               :27;
} __riic_icbrh_bits;

/* Control Register (SSICR) */
typedef struct {
  __REG32 REN           : 1;
  __REG32 TEN           : 1;
  __REG32               : 1;
  __REG32 MUEN          : 1;
  __REG32 CKDV          : 4;
  __REG32 DEL           : 1;
  __REG32 PDTA          : 1;
  __REG32 SDTA          : 1;
  __REG32 SPDP          : 1;
  __REG32 SWSP          : 1;
  __REG32 SCKP          : 1;
  __REG32 SWSD          : 1;
  __REG32 SCKD          : 1;
  __REG32 SWL           : 3;
  __REG32 DWL           : 3;
  __REG32 CHNL          : 2;
  __REG32               : 1;
  __REG32 IIEN          : 1;
  __REG32 ROIEN         : 1;
  __REG32 RUIEN         : 1;
  __REG32 TOIEN         : 1;
  __REG32 TUIEN         : 1;
  __REG32 CKS           : 1;
  __REG32               : 1;
} __ssif_ssicr_bits;

/* Status Register (SSISR) */
typedef struct {
  __REG32 IDST          : 1;
  __REG32 RSWNO         : 1;
  __REG32 RCHNO         : 2;
  __REG32 TSWNO         : 1;
  __REG32 TCHNO         : 2;
  __REG32               :18;
  __REG32 IIRQ          : 1;
  __REG32 ROIRQ         : 1;
  __REG32 RUIRQ         : 1;
  __REG32 TOIRQ         : 1;
  __REG32 TUIRQ         : 1;
  __REG32               : 2;
} __ssif_ssisr_bits;

/* FIFO Control Register (SSIFCR) */
typedef struct {
  __REG32 RFRST         : 1;
  __REG32 TFRST         : 1;
  __REG32 RIE           : 1;
  __REG32 TIE           : 1;
  __REG32 RTRG          : 2;
  __REG32 TTRG          : 2;
  __REG32               :24;
} __ssif_ssifcr_bits;

/* FIFO Status Register (SSIFSR) */
typedef struct {
  __REG32 RDF           : 1;
  __REG32               : 7;
  __REG32 RDC           : 4;
  __REG32               : 4;
  __REG32 TDE           : 1;
  __REG32               : 7;
  __REG32 TDC           : 4;
  __REG32               : 4;
} __ssif_ssifsr_bits;

/* TDM Mode Register (SSITDMR) */
typedef struct {
  __REG32 TDM           : 1;
  __REG32               : 7;
  __REG32 CONT          : 1;
  __REG32               : 8;
  __REG32 RXDMUTE       : 1;
  __REG32               :14;
} __ssif_ssitdmr_bits;

/* FC Control Register (SSIFCCR) */
typedef struct {
  __REG32 FCEN          : 1;
  __REG32               :15;
  __REG32 FIEN          : 1;
  __REG32               :15;
} __ssif_ssifccr_bits;

/* FC Mode Register (SSIFCMR) */
typedef struct {
  __REG32 MINV          :14;
  __REG32               : 2;
  __REG32 MAXV          :14;
  __REG32               : 2;
} __ssif_ssifcmr_bits;

/* FC Status Register (SSIFCSR) */
typedef struct {
  __REG32 VALUE         :14;
  __REG32               :10;
  __REG32 FCIRQ         : 1;
  __REG32               : 7;
} __ssif_ssifcsr_bits;

/* Channel Configuration Registers (CxCFG) */
typedef struct {
  __REG32 BRP           :10;
  __REG32               : 6;
  __REG32 TSEG1         : 4;
  __REG32 TSEG2         : 3;
  __REG32               : 1;
  __REG32 SJW           : 2;
  __REG32               : 6;
} __rscan_cxcfg_bits;

/* Channel Control Registers (CxCTR) */
typedef struct {
  __REG32 CHMDC         : 2;
  __REG32 CSLPR         : 1;
  __REG32 RTBO          : 1;
  __REG32               : 4;
  __REG32 BEIE          : 1;
  __REG32 EWIE          : 1;
  __REG32 EPIE          : 1;
  __REG32 BOEIE         : 1;
  __REG32 BORIE         : 1;
  __REG32 OLIE          : 1;
  __REG32 BLIE          : 1;
  __REG32 ALIE          : 1;
  __REG32 TAIE          : 1;
  __REG32               : 4;
  __REG32 BOM           : 2;
  __REG32 ERRD          : 1;
  __REG32 CTME          : 1;
  __REG32 CTMS          : 2;
  __REG32 TRWE          : 1;
  __REG32 TRH           : 1;
  __REG32 TRR           : 1;
  __REG32               : 2;
} __rscan_cxctr_bits;

/* Channel Status Registers (CxSTS) */
typedef struct {
  __REG32 CRSTSTS       : 1;
  __REG32 CHLTSTS       : 1;
  __REG32 CSLPSTS       : 1;
  __REG32 EPSTS         : 1;
  __REG32 BOSTS         : 1;
  __REG32 TRMSTS        : 1;
  __REG32 RECSTS        : 1;
  __REG32 COMSTS        : 1;
  __REG32               : 8;
  __REG32 REC           : 8;
  __REG32 TEC           : 8;
} __rscan_cxsts_bits;

/* Channel Error Flag Registers (CxERFL) */
typedef struct {
  __REG32 BEF           : 1;
  __REG32 EWF           : 1;
  __REG32 EPF           : 1;
  __REG32 BOEF          : 1;
  __REG32 BORF          : 1;
  __REG32 OVLF          : 1;
  __REG32 BLF           : 1;
  __REG32 ALF           : 1;
  __REG32 SERR          : 1;
  __REG32 FERR          : 1;
  __REG32 AERR          : 1;
  __REG32 CERR          : 1;
  __REG32 B1ERR         : 1;
  __REG32 B0ERR         : 1;
  __REG32 ADERR         : 1;
  __REG32               : 1;
  __REG32 CRCREG        :15;
  __REG32               : 1;
} __rscan_cxerfl_bits;

/* Global Configuration Register (GCFG) */
typedef struct {
  __REG32 TPRI          : 1;
  __REG32 DCE           : 1;
  __REG32 DRE           : 1;
  __REG32 MME           : 1;
  __REG32 DCS           : 1;
  __REG32               : 3;
  __REG32 TSP           : 4;
  __REG32 TSSS          : 1;
  __REG32 TSBTCS        : 3;
  __REG32 ITRCP         :16;
} __rscan_gcfg_bits;

/* Global Control Register (GCTR) */
typedef struct {
  __REG32 GMDC          : 2;
  __REG32 GSLPR         : 1;
  __REG32               : 5;
  __REG32 DEIE          : 1;
  __REG32 MEIE          : 1;
  __REG32 THLEIE        : 1;
  __REG32               : 5;
  __REG32 TSRST         : 1;
  __REG32               :15;
} __rscan_gctr_bits;

/* Global Status Register (GSTS) */
typedef struct {
  __REG32 GRSTSTS       : 1;
  __REG32 GHLTSTS       : 1;
  __REG32 GSLPSTS       : 1;
  __REG32 GRAMINIT      : 1;
  __REG32               :28;
} __rscan_gsts_bits;

/* Global Error Flag Register (GERFL) */
typedef struct {
  __REG32 DEF           : 1;
  __REG32 MES           : 1;
  __REG32 THLES         : 1;
  __REG32               :29;
} __rscan_gerfl_bits;

/* Global TX Interrupt Status Register 0 (GTINTSTS0) */
typedef struct {
  __REG32 TSIF0         : 1;
  __REG32 TAIF0         : 1;
  __REG32 TQIF0         : 1;
  __REG32 CFTIF0        : 1;
  __REG32 THIF0         : 1;
  __REG32               : 3;
  __REG32 TSIF1         : 1;
  __REG32 TAIF1         : 1;
  __REG32 TQIF1         : 1;
  __REG32 CFTIF1        : 1;
  __REG32 THIF1         : 1;
  __REG32               : 3;
  __REG32 TSIF2         : 1;
  __REG32 TAIF2         : 1;
  __REG32 TQIF2         : 1;
  __REG32 CFTIF2        : 1;
  __REG32 THIF2         : 1;
  __REG32               : 3;
  __REG32 TSIF3         : 1;
  __REG32 TAIF3         : 1;
  __REG32 TQIF3         : 1;
  __REG32 CFTIF3        : 1;
  __REG32 THIF3         : 1;
  __REG32               : 3;
} __rscan_gtintsts0_bits;

/* Global TX Interrupt Status Register 1 (GTINTSTS1) */
typedef struct {
  __REG32 TSIF4         : 1;
  __REG32 TAIF4         : 1;
  __REG32 TQIF4         : 1;
  __REG32 CFTIF4        : 1;
  __REG32 THIF4         : 1;
  __REG32               :27;
} __rscan_gtintsts1_bits;

/* Global Timestamp Counter Register (GTSC) */
typedef struct {
  __REG32 TS            :16;
  __REG32               :16;
} __rscan_gtsc_bits;

/* Global Acceptance Filter List Entry Control Register (GAFLECTR) */
typedef struct {
  __REG32 AFLPN         : 5;
  __REG32               : 3;
  __REG32 AFLDAE        : 1;
  __REG32               :23;
} __rscan_gaflectr_bits;

/* Global Acceptance Filter List Configuration Register 0 (GAFLCFG0) */
typedef struct {
  __REG32 RNC3          : 8;
  __REG32 RNC2          : 8;
  __REG32 RNC1          : 8;
  __REG32 RNC0          : 8;
} __rscan_gaflcfg0_bits;

/* Global Acceptance Filter List Configuration Register 1 (GAFLCFG1) */
typedef struct {
  __REG32               :24;
  __REG32 RNC4          : 8;
} __rscan_gaflcfg1_bits;

/* Global Acceptance Filter List ID Registers (GAFLIDx) */
typedef struct {
  __REG32 GAFLID        :29;
  __REG32 GAFLLB        : 1;
  __REG32 GAFLRTR       : 1;
  __REG32 GAFLIDE       : 1;
} __rscan_gaflid_bits;

/* Global Acceptance Filter List Mask Registers (GAFLMx) */
typedef struct {
  __REG32 GAFLIDM       :29;
  __REG32               : 1;
  __REG32 GAFLRTRM      : 1;
  __REG32 GAFLIDEM      : 1;
} __rscan_gaflm_bits;

/* Global Acceptance Filter List Pointer 0 Registers (GAFLP0x) */
typedef struct {
  __REG32               : 8;
  __REG32 GAFLRMDP      : 7;
  __REG32 GAFLRMV       : 1;
  __REG32 GAFLRPTR      :12;
  __REG32 GAFLDLC       : 4;
} __rscan_gaflp0_bits;

/* Global Acceptance Filter List Pointer 1 Registers (GAFLP1x) */
typedef struct {
  __REG32 GAFLFDP       :23;
  __REG32               : 9;
} __rscan_gaflp1_bits;

/* RX Message Buffer New Data Register 2 (RMND2) */
//typedef struct {
//  __REG32 RMNS          :16;
//  __REG32               :16;
//} __rscan_rmnd2_bits;

/* RX Message Buffer ID Registers (RMID) */
typedef struct {
  __REG32 RMID          :29;
  __REG32               : 1;
  __REG32 RMRTR         : 1;
  __REG32 RMIDE         : 1;
} __rscan_rmid_bits;

/* RX Message Buffer Pointer Registers (RMPTRx) */
typedef struct {
  __REG32 RMTS          :16;
  __REG32 RMPTR         :12;
  __REG32 RMDLC         : 4;
} __rscan_rmptr_bits;

/* RX Message Buffer Data Field 0 Registers (RMDF0) */
typedef struct {
  __REG32 RMDB0         : 8;
  __REG32 RMDB1         : 8;
  __REG32 RMDB2         : 8;
  __REG32 RMDB3         : 8;
} __rscan_rmdf0_bits;

/* RX Message Buffer Data Field 1 Registers (RMDF1) */
typedef struct {
  __REG32 RMDB4         : 8;
  __REG32 RMDB5         : 8;
  __REG32 RMDB6         : 8;
  __REG32 RMDB7         : 8;
} __rscan_rmdf1_bits;

/* RX FIFO Configuration/Control Registers (RFCC) */
typedef struct {
  __REG32 RFE           : 1;
  __REG32 RFIE          : 1;
  __REG32               : 6;
  __REG32 RFDC          : 3;
  __REG32               : 1;
  __REG32 RFIM          : 1;
  __REG32 RFIGCV        : 3;
  __REG32               :16;
} __rscan_rfcc_bits;

/* RX FIFO Status Registers (RFSTS) */
typedef struct {
  __REG32 RFEMP         : 1;
  __REG32 RFFLL         : 1;
  __REG32 RFMLT         : 1;
  __REG32 RFIF          : 1;
  __REG32               : 4;
  __REG32 RFMC          : 8;
  __REG32               :16;
} __rscan_rfsts_bits;

/* RX FIFO Pointer Control Registers (RFPCTR) */
#define RFPCTR_RFPC     0x000000FFUL

/* RX FIFO Access ID Registers (RFID) */
typedef struct {
  __REG32 RFID          :29;
  __REG32               : 1;
  __REG32 RFRTR         : 1;
  __REG32 RFIDE         : 1;
} __rscan_rfid_bits;

/* RX FIFO Access Pointer Register (RFPTR) */
typedef struct {
  __REG32 RFTS          :16;
  __REG32 RFPTR         :12;
  __REG32 RFDLC         : 4;
} __rscan_rfptr_bits;

/* RX FIFO Access Data Field 0 Registers (RFDF0) */
typedef struct {
  __REG32 RFDB0         : 8;
  __REG32 RFDB1         : 8;
  __REG32 RFDB2         : 8;
  __REG32 RFDB3         : 8;
} __rscan_rfdf0_bits;

/* RX FIFO Access Data Field 1 Registers (RFDF1) */
typedef struct {
  __REG32 RFDB4         : 8;
  __REG32 RFDB5         : 8;
  __REG32 RFDB6         : 8;
  __REG32 RFDB7         : 8;
} __rscan_rfdf1_bits;

/* Common FIFO Configuration/Control Registers (CFCC) */
typedef struct {
  __REG32 CFE           : 1;
  __REG32 CFRXIE        : 1;
  __REG32 CFTXIE        : 1;
  __REG32               : 5;
  __REG32 CFDC          : 3;
  __REG32               : 1;
  __REG32 CFIM          : 1;
  __REG32 CFIGCV        : 3;
  __REG32 CFM           : 2;
  __REG32 CFITSS        : 1;
  __REG32 CFITR         : 1;
  __REG32 CFTML         : 4;
  __REG32 CFITT         : 8;
} __rscan_cfcc_bits;

/* Common FIFO Status Registers (CFSTS) */
typedef struct {
  __REG32 CFEMP         : 1;
  __REG32 CFFLL         : 1;
  __REG32 CFMLT         : 1;
  __REG32 CFRXIF        : 1;
  __REG32 CFTXIF        : 1;
  __REG32               : 3;
  __REG32 CFMC          : 8;
  __REG32               :16;
} __rscan_cfsts_bits;

/* Common FIFO Pointer Control Registers (CFPCTR) */
#define CFPCTR_CFPC     0x000000FFUL

/* Common FIFO Access ID Registers (CFID) */
typedef struct {
  __REG32 CFID          :29;
  __REG32 THLEN         : 1;
  __REG32 CFRTR         : 1;
  __REG32 CFIDE         : 1;
} __rscan_cfid_bits;

/* Common FIFO Access Pointer Registers (CFPTR) */
typedef struct {
  __REG32 CFTS          :16;
  __REG32 CFPTR         :12;
  __REG32 CFDLC         : 4;
} __rscan_cfptr_bits;

/* Common FIFO Access Data Field 0 Registers (CFDF0) */
typedef struct {
  __REG32 CFDB0         : 8;
  __REG32 CFDB1         : 8;
  __REG32 CFDB2         : 8;
  __REG32 CFDB3         : 8;
} __rscan_cfdf0_bits;

/* Common FIFO Access Data Field 1 Registers (CFDF1) */
typedef struct {
  __REG32 CFDB4         : 8;
  __REG32 CFDB5         : 8;
  __REG32 CFDB6         : 8;
  __REG32 CFDB7         : 8;
} __rscan_cfdf1_bits;

/* FIFO Empty Status Register (FESTS) */
typedef struct {
  __REG32 RF0EMP        : 1;
  __REG32 RF1EMP        : 1;
  __REG32 RF2EMP        : 1;
  __REG32 RF3EMP        : 1;
  __REG32 RF4EMP        : 1;
  __REG32 RF5EMP        : 1;
  __REG32 RF6EMP        : 1;
  __REG32 RF7EMP        : 1;
  __REG32 CF0EMP        : 1;
  __REG32 CF1EMP        : 1;
  __REG32 CF2EMP        : 1;
  __REG32 CF3EMP        : 1;
  __REG32 CF4EMP        : 1;
  __REG32 CF5EMP        : 1;
  __REG32 CF6EMP        : 1;
  __REG32 CF7EMP        : 1;
  __REG32 CF8EMP        : 1;
  __REG32 CF9EMP        : 1;
  __REG32 CF10EMP       : 1;
  __REG32 CF11EMP       : 1;
  __REG32 CF12EMP       : 1;
  __REG32 CF13EMP       : 1;
  __REG32 CF14EMP       : 1;
  __REG32               : 9;
} __rscan_fests_bits;

/* FIFO Full Status Register (FFSTS) */
typedef struct {
  __REG32 RF0FLL        : 1;
  __REG32 RF1FLL        : 1;
  __REG32 RF2FLL        : 1;
  __REG32 RF3FLL        : 1;
  __REG32 RF4FLL        : 1;
  __REG32 RF5FLL        : 1;
  __REG32 RF6FLL        : 1;
  __REG32 RF7FLL        : 1;
  __REG32 CF0FLL        : 1;
  __REG32 CF1FLL        : 1;
  __REG32 CF2FLL        : 1;
  __REG32 CF3FLL        : 1;
  __REG32 CF4FLL        : 1;
  __REG32 CF5FLL        : 1;
  __REG32 CF6FLL        : 1;
  __REG32 CF7FLL        : 1;
  __REG32 CF8FLL        : 1;
  __REG32 CF9FLL        : 1;
  __REG32 CF10FLL       : 1;
  __REG32 CF11FLL       : 1;
  __REG32 CF12FLL       : 1;
  __REG32 CF13FLL       : 1;
  __REG32 CF14FLL       : 1;
  __REG32               : 9;
} __rscan_ffsts_bits;

/* FIFO Message Lost Status Register (FMSTS) */
typedef struct {
  __REG32 RF0MLT        : 1;
  __REG32 RF1MLT        : 1;
  __REG32 RF2MLT        : 1;
  __REG32 RF3MLT        : 1;
  __REG32 RF4MLT        : 1;
  __REG32 RF5MLT        : 1;
  __REG32 RF6MLT        : 1;
  __REG32 RF7MLT        : 1;
  __REG32 CF0MLT        : 1;
  __REG32 CF1MLT        : 1;
  __REG32 CF2MLT        : 1;
  __REG32 CF3MLT        : 1;
  __REG32 CF4MLT        : 1;
  __REG32 CF5MLT        : 1;
  __REG32 CF6MLT        : 1;
  __REG32 CF7MLT        : 1;
  __REG32 CF8MLT        : 1;
  __REG32 CF9MLT        : 1;
  __REG32 CF10MLT       : 1;
  __REG32 CF11MLT       : 1;
  __REG32 CF12MLT       : 1;
  __REG32 CF13MLT       : 1;
  __REG32 CF14MLT       : 1;
  __REG32               : 9;
} __rscan_fmsts_bits;

/* FIFO Interrupt Flag Status Register (RFISTS) */
typedef struct {
  __REG32 RF0IF         : 1;
  __REG32 RF1IF         : 1;
  __REG32 RF2IF         : 1;
  __REG32 RF3IF         : 1;
  __REG32 RF4IF         : 1;
  __REG32 RF5IF         : 1;
  __REG32 RF6IF         : 1;
  __REG32 RF7IF         : 1;
  __REG32               :24;
} __rscan_rfists_bits;

/* Common FIFO RX Interrupt Flag Status Register (CFRISTS) */
typedef struct {
  __REG32 CF0RXIF       : 1;
  __REG32 CF1RXIF       : 1;
  __REG32 CF2RXIF       : 1;
  __REG32 CF3RXIF       : 1;
  __REG32 CF4RXIF       : 1;
  __REG32 CF5RXIF       : 1;
  __REG32 CF6RXIF       : 1;
  __REG32 CF7RXIF       : 1;
  __REG32 CF8RXIF       : 1;
  __REG32 CF9RXIF       : 1;
  __REG32 CF10RXIF      : 1;
  __REG32 CF11RXIF      : 1;
  __REG32 CF12RXIF      : 1;
  __REG32 CF13RXIF      : 1;
  __REG32 CF14RXIF      : 1;
  __REG32               :17;
} __rscan_cfrists_bits;

/* Common FIFO TX Interrupt Flag Status Register (CFTISTS) */
typedef struct {
  __REG32 CF0TXIF       : 1;
  __REG32 CF1TXIF       : 1;
  __REG32 CF2TXIF       : 1;
  __REG32 CF3TXIF       : 1;
  __REG32 CF4TXIF       : 1;
  __REG32 CF5TXIF       : 1;
  __REG32 CF6TXIF       : 1;
  __REG32 CF7TXIF       : 1;
  __REG32 CF8TXIF       : 1;
  __REG32 CF9TXIF       : 1;
  __REG32 CF10TXIF      : 1;
  __REG32 CF11TXIF      : 1;
  __REG32 CF12TXIF      : 1;
  __REG32 CF13TXIF      : 1;
  __REG32 CF14TXIF      : 1;
  __REG32               :17;
} __rscan_cftists_bits;

/* TX Message Buffer Control Registers (TMC) */
typedef struct {
  __REG8  TMTR          : 1;
  __REG8  TMTAR         : 1;
  __REG8  TMOM          : 1;
  __REG8                : 5;
} __rscan_tmc_bits;

/* TX Message Buffer Status Registers (TMSTS) */
typedef struct {
  __REG8  TMTSTS        : 1;
  __REG8  TMTRF         : 2;
  __REG8  TMTRM         : 1;
  __REG8  TMTARM        : 1;
  __REG8                : 3;
} __rscan_tmsts_bits;

/* TX Message Buffer Transmission Request Status Register 2 (TMTRSTS2) */
typedef struct {
  __REG32 TMTRSTS       :16;
  __REG32               :16;
} __rscan_tmtrsts2_bits;

/* TX Message Buffer Transmission Abortion Request Status Register 2 (TMTARSTS2) */
typedef struct {
  __REG32 TMTARSTS      :16;
  __REG32               :16;
} __rscan_tmtarsts2_bits;

/* TX Message Buffer Transmission Completion Status Register 2 (TMTCSTS2) */
typedef struct {
  __REG32 TMTCSTS       :16;
  __REG32               :16;
} __rscan_tmtcsts2_bits;

/* TX Message Buffer Transmission Abortion Status Register 2 (TMTASTS2) */
typedef struct {
  __REG32 TMTASTS       :16;
  __REG32               :16;
} __rscan_tmtasts2_bits;

/* TX Message Buffer Interrupt Enable Configuration Register 2 (TMIEC2) */
typedef struct {
  __REG32 TMIE          :16;
  __REG32               :16;
} __rscan_tmiec2_bits;

/* TX Message Buffer ID Registers (TMID) */
typedef struct {
  __REG32 TMID          :29;
  __REG32 THLEN         : 1;
  __REG32 TMRTR         : 1;
  __REG32 TMIDE         : 1;
} __rscan_tmid_bits;

/* TX Message Buffer Pointer (TMPTR) */
typedef struct {
  __REG32               :16;
  __REG32 TMPTR         : 8;
  __REG32               : 4;
  __REG32 TMDLC         : 4;
} __rscan_tmptr_bits;

/* TX Message Buffer Data Field 0 Registers (TMDF0) */
typedef struct {
  __REG32 TMDB0         : 8;
  __REG32 TMDB1         : 8;
  __REG32 TMDB2         : 8;
  __REG32 TMDB3         : 8;
} __rscan_tmdf0_bits;

/* TX Message Buffer Data Field 1 Registers (TMDF1) */
typedef struct {
  __REG32 TMDB4         : 8;
  __REG32 TMDB5         : 8;
  __REG32 TMDB6         : 8;
  __REG32 TMDB7         : 8;
} __rscan_tmdf1_bits;

/* TX Queue Configuration / Control Registers (TXQCC) */
typedef struct {
  __REG32 TXQE          : 1;
  __REG32               : 7;
  __REG32 TXQDC         : 4;
  __REG32 TXQIE         : 1;
  __REG32 TXQIM         : 1;
  __REG32               :18;
} __rscan_txqcc_bits;

/* TX Queue Status Registers (TXQSTS) */
typedef struct {
  __REG32 TXQEMP        : 1;
  __REG32 TXQFLL        : 1;
  __REG32 TXQIF         : 1;
  __REG32               :29;
} __rscan_txqsts_bits;

/* TX Queue Pointer Control Registers (TXQPCTR) */
typedef struct {
  __REG32 TXQPC         : 8;
  __REG32               :24;
} __rscan_txqpctr_bits;

/* TX History List Configuration / Control Register (THLCC) */
typedef struct {
  __REG32 THLE          : 1;
  __REG32               : 7;
  __REG32 THLIE         : 1;
  __REG32 THLIM         : 1;
  __REG32 THLDTE        : 1;
  __REG32               :21;
} __rscan_thlcc_bits;

/* TX History List Status Register (THLSTS) */
typedef struct {
  __REG32 THLEMP        : 1;
  __REG32 THLFLL        : 1;
  __REG32 THLELT        : 1;
  __REG32 THLIF         : 1;
  __REG32               : 4;
  __REG32 THLMC         : 5;
  __REG32               :19;
} __rscan_thlsts_bits;

/* TX History List Access Registers (THLACC) */
typedef struct {
  __REG32 BT            : 3;
  __REG32 BN            : 4;
  __REG32               : 1;
  __REG32 TID           : 8;
  __REG32               :16;
} __rscan_thlacc_bits;

/* TX History List Pointer Control Registers (THLPCTR) */
typedef struct {
  __REG32 THLPC         : 8;
  __REG32               :24;
} __rscan_thlpctr_bits;

/* Global Test Configuration Register (GTSTCFG) */
typedef struct {
  __REG32 C0ICBCE       : 1;
  __REG32 C1ICBCE       : 1;
  __REG32 C2ICBCE       : 1;
  __REG32 C3ICBCE       : 1;
  __REG32 C4ICBCE       : 1;
  __REG32               :27;
} __rscan_gtstcfg_bits;

/* Global Test Control Register (GTSTCTR) */
typedef struct {
  __REG32 ICBCTME       : 1;
  __REG32               :31;
} __rscan_gtstctr_bits;

/* IEBBn Bus Control Register (IEBBnBCR) */
typedef struct {
  __REG8                : 3;
  __REG8  IEBBnSRXE     : 1;
  __REG8  IEBBnSTXE     : 1;
  __REG8  IEBBnALRQ     : 1;
  __REG8  IEBBnMSRQ     : 1;
  __REG8  IEBBnPW       : 1;
} __iebb_bcr_bits;

/* IEBBn Power Save Register (IEBBnPSR) */
typedef struct {
  __REG8                : 6;
  __REG8  IEBBnCMD      : 1;
  __REG8  IEBBnCLKE     : 1;
} __iebb_psr_bits;

/* IEBBn Unit Address Register (IEBBnUAR) */
typedef struct {
  __REG16 IEBBnUAR      :12;
  __REG16               : 4;
} __iebb_uar_bits;

/* IEBBn Slave Address Register (IEBBnSAR) */
typedef struct {
  __REG16 IEBBnSAR      :12;
  __REG16               : 4;
} __iebb_sar_bits;

/* IEBBn Partner Address Register (IEBBnPAR) */
typedef struct {
  __REG16 IEBBnPAR      :12;
  __REG16               : 4;
} __iebb_par_bits;

/* IEBBn Reception Slave Address Register (IEBBnRSA) */
typedef struct {
  __REG16 IEBBnRSA      :12;
  __REG16               : 4;
} __iebb_rsa_bits;

/* IEBBn Control Data Register (IEBBnCDR) */
typedef struct {
  __REG8  IEBBnSLDC     : 4;
  __REG8                : 4;
} __iebb_cdr_bits;

/* IEBBn Transmission Control Data Register (IEBBnTCD) */
typedef struct {
  __REG8  IEBBnSLTD     : 4;
  __REG8                : 4;
} __iebb_tcd_bits;

/* IEBBn Reception Control Data Register (IEBBnRCD) */
typedef struct {
  __REG8  IEBBnSLRD     : 4;
  __REG8                : 4;
} __iebb_rcd_bits;

/* IEBBn Clock Selection Register (IEBBnCKS) */
typedef struct {
  __REG8  IEBBnBRS      : 3;
  __REG8                : 1;
  __REG8  IEBBnPRS      : 1;
  __REG8                : 3;
} __iebb_cks_bits;

/* IEBBn Transfer Mode Setting Register (IEBBnTMS) */
typedef struct {
  __REG8  IEBBnALC      : 3;
  __REG8  IEBBnSLTI     : 2;
  __REG8  IEBBnSLRI     : 2;
  __REG8  IEBBnFMDE     : 1;
} __iebb_tms_bits;

/* IEBBn Pointer Clear Register (IEBBnPCR) */
#define IEBB0PCR_IEBBnCTPT  0x40;
#define IEBB0PCR_IEBBnCRPT  0x80;

/* IEBBn Buffer Status Register (IEBBnBSR) */
typedef struct {
  __REG16 IEBBnSTFP     : 5;
  __REG16               : 1;
  __REG16 IEBBnFOVW     : 1;
  __REG16 TEBBnTFLF     : 1;
  __REG16 IEBBnSRFP     : 5;
  __REG16               : 1;
  __REG16 IEBBnFOVR     : 1;
  __REG16 TEBBnRFLF     : 1;
} __iebb_bsr_bits;

/* IEBBn Slave Status Register (IEBBnSSR) */
typedef struct {
  __REG8  IEBBnSTXF     : 1;
  __REG8  IEBBnSRXF     : 1;
  __REG8  IEBBnSTLF     : 1;
  __REG8                : 1;
  __REG8  IEBBnSSLF     : 1;
  __REG8                : 3;
} __iebb_ssr_bits;

/* IEBBn Unit Status Register (IEBBnUSR) */
typedef struct {
  __REG8                : 2;
  __REG8  IEBBnLCKF     : 1;
  __REG8  IEBBnACKF     : 1;
  __REG8  IEBBnALTF     : 1;
  __REG8  IEBBnARBF     : 1;
  __REG8  IEBBnSRQF     : 1;
  __REG8                : 1;
} __iebb_usr_bits;

/* IEBBn Interrupt Status Register (IEBBnISR) */
typedef struct {
  __REG8  IEBBnFOVE     : 1;
  __REG8                : 1;
  __REG8  IEBBnEFMF     : 1;
  __REG8  IEBBnETRF     : 1;
  __REG8  IEBBnSTSF     : 1;
  __REG8  IEBBnSTRF     : 1;
  __REG8  IEBBnIEBE     : 1;
  __REG8                : 1;
} __iebb_isr_bits;

/* IEBBn Error Status Register (IEBBnESR) */
typedef struct {
  __REG8  IEBBnTRDE     : 1;
  __REG8  IEBBnABTE     : 1;
  __REG8                : 1;
  __REG8  IEBBnOVRE     : 1;
  __REG8  IEBBnUNRE     : 1;
  __REG8  IEBBnNACE     : 1;
  __REG8  IEBBnPARE     : 1;
  __REG8  IEBBnTIME     : 1;
} __iebb_esr_bits;

/* IEBBn Field Status Register (IEBBnFSR) */
typedef struct {
  __REG8  IEBBnSSFS     : 2;
  __REG8                : 4;
  __REG8  IEBBnTTRF     : 1;
  __REG8  IEBBnRTRF     : 1;
} __iebb_fsr_bits;

/* IEBBn Status Clear Register 0 (IEBBnSTC0) */
#define IEBB0STC0_IEBBnCLTR  0x01
#define IEBB0STC0_IEBBnCLAB  0x02
#define IEBB0STC0_IEBBnCLOV  0x08
#define IEBB0STC0_IEBBnCLUR  0x10
#define IEBB0STC0_IEBBnCLNC  0x20
#define IEBB0STC0_IEBBnCLPA  0x40
#define IEBB0STC0_IEBBnCLTM  0x80

/* IEBBn Status Clear Register 1 (IEBBnSTC1) */
#define IEBB0STC1_IEBBnCLFF  0x01

/* RSPDIF Control Register (RSPDIF_CTRL) */
typedef struct {
  __REG32 TCBI          : 1;
  __REG32 TCSI          : 1;
  __REG32 RCBI          : 1;
  __REG32 RCSI          : 1;
  __REG32 TUII          : 1;
  __REG32 RUII          : 1;
  __REG32 ABUI          : 1;
  __REG32 ABOI          : 1;
  __REG32 CSEI          : 1;
  __REG32 PREI          : 1;
  __REG32 PAEI          : 1;
  __REG32 CREI          : 1;
  __REG32 UBUI          : 1;
  __REG32 UBOI          : 1;
  __REG32 TEIE          : 1;
  __REG32 REIE          : 1;
  __REG32 TME           : 1;
  __REG32 RME           : 1;
  __REG32 AOS           : 1;
  __REG32 NCSI          : 1;
  __REG32 TDE           : 1;
  __REG32 RDE           : 1;
  __REG32 TASS          : 2;
  __REG32 RASS          : 2;
  __REG32 PB            : 1;
  __REG32               : 1;
  __REG32 CKS           : 1;
  __REG32               : 3;
} __rspdif_ctrl_bits;

/* RSPDIF Status Register (RSPDIF_STAT) */
typedef struct {
  __REG32 CBTX          : 1;
  __REG32 CSTX          : 1;
  __REG32 CBRX          : 1;
  __REG32 CSRX          : 1;
  __REG32 TUIR          : 1;
  __REG32 RUIR          : 1;
  __REG32 ABU           : 1;
  __REG32 ABO           : 1;
  __REG32 CSE           : 1;
  __REG32 PREE          : 1;
  __REG32 PARE          : 1;
  __REG32 CE            : 1;
  __REG32 UBU           : 1;
  __REG32 UBO           : 1;
  __REG32 TIS           : 1;
  __REG32 RIS           : 1;
  __REG32 CMD           : 1;
  __REG32               :15;
} __rspdif_stat_bits;

/* RSPDIF Transmitter Channel 1 Audio Channel (RSPDIF_TLCA) */
#define RSPDIF_TLCA_Audio_PCM_Data 0x00FFFFFF

/* RSPDIF Transmitter Channel 2 Audio Channel (RSPDIF_TRCA) */
#define RSPDIF_TRCA_Audio_PCM_Data 0x00FFFFFF

/* RSPDIF Transmitter DMA Audio Data Register (RSPDIF_TDAD) */
#define RSPDIF_TDAD_Audio_PCM_Data 0x00FFFFFF

/* RSPDIF Transmitter User Data Register (RSPDIF_TUI) */
#define RSPDIF_TUI_User_Byte_1     0x000000FF
#define RSPDIF_TUI_User_Byte_2     0x0000FF00
#define RSPDIF_TUI_User_Byte_3     0x00FF0000
#define RSPDIF_TUI_User_Byte_4     0xFF000000

/* RSPDIF Transmitter Channel 1 Status Register (RSPDIF_TLCS) */
#define RSPDIF_TLCS_CTL            0x0000003E
#define RSPDIF_TLCS_CATCD          0x0000FF00
#define RSPDIF_TLCS_SRCNO          0x000F0000
#define RSPDIF_TLCS_CHNO           0x00F00000
#define RSPDIF_TLCS_FS             0x0F000000
#define RSPDIF_TLCS_CLAC           0x30000000

/* RSPDIF Transmitter Channel 2 Status Register (RSPDIF_TRCS) */
#define RSPDIF_TRCS_CTL            0x0000003E
#define RSPDIF_TRCS_CATCD          0x0000FF00
#define RSPDIF_TRCS_SRCNO          0x000F0000
#define RSPDIF_TRCS_CHNO           0x00F00000
#define RSPDIF_TRCS_FS             0x0F000000
#define RSPDIF_TRCS_CLAC           0x30000000

/* RSPDIF Receiver Channel 1 Audio Register (RSPDIF_RLCA) */
typedef struct {
  __REG32 Audio_PCM_Data:24;
  __REG32               : 8;
} __rspdif_rlca_bits;

/* RSPDIF Receiver Channel 2 Audio Register (RSPDIF_RRCA) */
typedef struct {
  __REG32 Audio_PCM_Data:24;
  __REG32               : 8;
} __rspdif_rrca_bits;

/* RSPDIF Receiver DMA Audio Data (RSPDIF_RDAD) */
typedef struct {
  __REG32 Audio_PCM_Data:24;
  __REG32               : 8;
} __rspdif_rdad_bits;

/* RSPDIF Receiver User Data Register (RSPDIF_RUI) */
typedef struct {
  __REG32 User_Byte_1   : 8;
  __REG32 User_Byte_2   : 8;
  __REG32 User_Byte_3   : 8;
  __REG32 User_Byte_4   : 8;
} __rspdif_rui_bits;

/* RSPDIF Receiver Channel 1 Status Register (RSPDIF_RLCS) */
/* RSPDIF Receiver Channel 2 Status Register (RSPDIF_RRCS) */
typedef struct {
  __REG32               : 1;
  __REG32 CTL           : 5;
  __REG32               : 2;
  __REG32 CATCD         : 8;
  __REG32 SRCNO         : 4;
  __REG32 CHNO          : 4;
  __REG32 FS            : 4;
  __REG32 CLAC          : 2;
  __REG32               : 2;
} __rspdif_rlcs_rrcs_bits;

/* Enable Control Register (CROMEN) */
typedef struct {
  __REG8                : 5;
  __REG8  CROM_STP      : 1;
  __REG8  CROM_EN       : 1;
  __REG8  SUBC_EN       : 1;
} __romdec_cromen_bits;

/* Sync Code-Based Synchronization Control Register (CROMSY0) */
typedef struct {
  __REG8                : 5;
  __REG8  SY_DEN        : 1;
  __REG8  SY_IEN        : 1;
  __REG8  SY_AUT        : 1;
} __romdec_cromsy0_bits;

/* Decoding Mode Control Register (CROMCTL0) */
typedef struct {
  __REG8  MD_SEC        : 3;
  __REG8  MD_AUTOS2     : 1;
  __REG8  MD_AUTOS1     : 1;
  __REG8  MD_AUTO       : 1;
  __REG8                : 1;
  __REG8  MD_DESC       : 1;
} __romdec_cromctl0_bits;

/* EDC/ECC Check Control Register (CROMCTL1) */
typedef struct {
  __REG8  MD_PQREP      : 2;
  __REG8                : 2;
  __REG8  MD_DEC        : 3;
  __REG8  M2F2EDC       : 1;
} __romdec_cromctl1_bits;

/* Automatic Decoding Stop Control Register (CROMCTL3) */
typedef struct {
  __REG8                : 3;
  __REG8  STP_MIN       : 1;
  __REG8  STP_MD        : 1;
  __REG8                : 1;
  __REG8  STP_EDC       : 1;
  __REG8  STP_ECC       : 1;
} __romdec_cromctl3_bits;

/* CDROMD Decoding Option Setting Control Register (CROMCTL4) */
typedef struct {
  __REG8                : 3;
  __REG8  NO_ECC        : 1;
  __REG8  ERR0SEL       : 1;
  __REG8                : 1;
  __REG8  LINK2         : 1;
  __REG8  LINKOFF       : 1;
} __romdec_cromctl4_bits;

/* CDROMD HEAD20 to HEAD22 Representation Control Register (CROMCTL5) */
typedef struct {
  __REG8  MSF_LBA_SEL   : 1;
  __REG8                : 7;
} __romdec_cromctl5_bits;

/* CDROMD Sync Code Status Register (CROMST0) */
typedef struct {
  __REG8  ST_SECL       : 1;
  __REG8  ST_SECS       : 1;
  __REG8  ST_BLKL       : 1;
  __REG8  ST_BLKS       : 1;
  __REG8  ST_SYNO       : 1;
  __REG8  ST_SYIL       : 1;
  __REG8                : 2;
} __romdec_cromst0_bits;

/* CDROMD CROMST1 Post-ECC Header Error Status Register (CROMST1) */
typedef struct {
  __REG8  ER2_HEAD3     : 1;
  __REG8  ER2_HEAD2     : 1;
  __REG8  ER2_HEAD1     : 1;
  __REG8  ER2_HEAD0     : 1;
  __REG8                : 4;
} __romdec_cromst1_bits;

/* CDROMD CROMST3 Post-ECC Subheader Error Status Register (CROMST3) */
typedef struct {
  __REG8  ER2_SHEAD7    : 1;
  __REG8  ER2_SHEAD6    : 1;
  __REG8  ER2_SHEAD5    : 1;
  __REG8  ER2_SHEAD4    : 1;
  __REG8  ER2_SHEAD3    : 1;
  __REG8  ER2_SHEAD2    : 1;
  __REG8  ER2_SHEAD1    : 1;
  __REG8  EG2_SHEAD0    : 1;
} __romdec_cromst3_bits;

/* CDROMD Header/Subheader Validity Check Status Register (CROMST4) */
typedef struct {
  __REG8  NG_MDTIM2     : 1;
  __REG8  NG_MDTIM1     : 1;
  __REG8  NG_MDDEF      : 1;
  __REG8  NG_MDCMP4     : 1;
  __REG8  NG_MDCMP3     : 1;
  __REG8  NG_MDCMP2     : 1;
  __REG8  NG_MDCMP1     : 1;
  __REG8  NG_MD         : 1;
} __romdec_cromst4_bits;

/* CDROMD Mode Determination and Link Sector Detection Status Register (CROMST5) */
typedef struct {
  __REG8  LINK_OUT1     : 1;
  __REG8  LINK_SDET     : 1;
  __REG8  LINK_DET      : 1;
  __REG8  LINK_ON       : 1;
  __REG8  ST_MDX        : 1;
  __REG8  ST_AMD        : 3;
} __romdec_cromst5_bits;

/* CDROMD ECC/EDC Error Status Register (CROMST6) */
typedef struct {
  __REG8  ST_EDC2       : 1;
  __REG8  ST_EDC1       : 1;
  __REG8  ST_ECCQ       : 1;
  __REG8  ST_ECCP       : 1;
  __REG8  ST_ECCNG      : 1;
  __REG8  ST_ECCABT     : 1;
  __REG8                : 1;
  __REG8  ST_ERR        : 1;
} __romdec_cromst6_bits;

/* CDROMD Buffer Status Register (CBUFST0) */
typedef struct {
  __REG8                : 6;
  __REG8  BUF_ACT       : 1;
  __REG8  BUF_REF       : 1;
} __romdec_cbufst0_bits;

/* CDROMD Decoding Stoppage Source Status Register (CBUFST1) */
typedef struct {
  __REG8                : 3;
  __REG8  BUF_MIN       : 1;
  __REG8  BUF_MD        : 1;
  __REG8                : 1;
  __REG8  BUF_EDC       : 1;
  __REG8  BUF_ECC       : 1;
} __romdec_cbufst1_bits;

/* CDROMD Buffer OVerflow Status Register (CBUFST2) */
typedef struct {
  __REG8                : 7;
  __REG8  BUF_NG        : 1;
} __romdec_cbufst2_bits;

/* CDROMD Automatic Buffering Setting Control Register (CBUFCTL0) */
typedef struct {
  __REG8                : 1;
  __REG8  CBUF_Q        : 1;
  __REG8  CBUF_TS       : 1;
  __REG8  CBUF_MD       : 2;
  __REG8  CBUF_LINK     : 1;
  __REG8  CBUF_EN       : 1;
  __REG8  CBUF_AUT      : 1;
} __romdec_cbufctl0_bits;

/* CDROMD ISY Interrupt Source Mask Control Register (CROMST0M) */
typedef struct {
  __REG8  ST_SECLM      : 1;
  __REG8  ST_SECSM      : 1;
  __REG8  ST_BLKLM      : 1;
  __REG8  ST_BLKSM      : 1;
  __REG8  ST_SYNOM      : 1;
  __REG8  ST_SYILM      : 1;
  __REG8                : 2;
} __romdec_cromst0m_bits;

/* CDROMD Reset Control Register (ROMDECRST) */
typedef struct {
  __REG8                : 6;
  __REG8  RAMRST        : 1;
  __REG8  LOGICRST      : 1;
} __romdec_romdecrst_bits;

/* CDROMD Reset Status Register (RSTSTAT) */
typedef struct {
  __REG8                : 7;
  __REG8  RAMCLRST      : 1;
} __romdec_rststat_bits;

/* CDROMD Serial Sound Interface (SSI) */
typedef struct {
  __REG8                : 2;
  __REG8  BUFEND1       : 2;
  __REG8  BUFEND0       : 2;
  __REG8  BITEND        : 1;
  __REG8  BYTEND        : 1;
} __romdec_ssi_bits;

/* CDROMD Interrupt Flag Register (INTHOLD) */
typedef struct {
  __REG8                : 2;
  __REG8  IREADY        : 1;
  __REG8  IBUF          : 1;
  __REG8  IERR          : 1;
  __REG8  ISY           : 1;
  __REG8  ITARG         : 1;
  __REG8  ISEC          : 1;
} __romdec_inthold_bits;

/* CDROMD Interrupt Source Mask Control Register (INHINT) */
typedef struct {
  __REG8  PREINH_IREADY : 1;
  __REG8  PREINH_REQDM  : 1;
  __REG8  INHIREADY     : 1;
  __REG8  INHIBUF       : 1;
  __REG8  INHIERR       : 1;
  __REG8  INHISY        : 1;
  __REG8  INHITARG      : 1;
  __REG8  INHISEC       : 1;
} __romdec_inhint_bits;

/* Software Reset Register (ARSTR)*/
typedef struct{
  __REG32 ARST          : 1;
  __REG32               :31;
} __ether_arstr_bits;

/* E-MAC Mode Register (ECMR) */
typedef struct {
  __REG32 PRM           : 1;
  __REG32 DM            : 1;
  __REG32               : 3;
  __REG32 TE            : 1;
  __REG32 RE            : 1;
  __REG32               : 2;
  __REG32               : 1;
  __REG32               : 3;
  __REG32 MCT           : 1;
  __REG32               : 2;
  __REG32 TXF           : 1;
  __REG32 RXF           : 1;
  __REG32 PFR           : 1;
  __REG32 ZPF           : 1;
  __REG32 RZPF          : 1;
  __REG32 DPAD          : 1;
  __REG32               : 1;
  __REG32 RCSC          : 1;
  __REG32               : 2;
  __REG32 TRCCM         : 1;
  __REG32               : 5;
} __ether_ecmr_bits;

/* E-MAC Status Register (ECSR) */
typedef struct {
  __REG32 ICD           : 1;
  __REG32               : 1;
  __REG32               : 1;
  __REG32               : 1;
  __REG32 PFROI         : 1;
  __REG32               :27;
} __ether_ecsr_bits;

/* E-MAC Interrupt Permission Register (ECSIPR) */
typedef struct {
  __REG32 ICDIP         : 1;
  __REG32               : 1;
  __REG32               : 1;
  __REG32               : 1;
  __REG32 PFROIP        : 1;
  __REG32               :27;
} __ether_ecsipr_bits;

/* PHY Interface Register (PIR) */
typedef struct {
  __REG32 MDC           : 1;
  __REG32 MMD           : 1;
  __REG32 MDO           : 1;
  __REG32 MDI           : 1;
  __REG32               :28;
} __ether_pir_bits;

/* MAC Address Low Register (MALR) */
typedef struct {
  __REG32 MA            :16;
  __REG32               :16;
} __ether_malr_bits;

/* Receive Frame Length Register (RFLR) */
typedef struct {
  __REG32 RFL           :18;
  __REG32               :14;
} __ether_rflr_bits;

/* Transmit Retry Over Counter Register (TROCR) */
typedef struct {
  __REG32 TROC          :16;
  __REG32               :16;
} __ether_trocr_bits;

/* Delayed Collision Detect Counter Register (CDCR) */
typedef struct {
  __REG32 COSDC         :16;
  __REG32               :16;
} __ether_cdcr_bits;

/* Lost Carrier Counter Register (LCCR) */
typedef struct {
  __REG32 LCCR          :16;
  __REG32               :16;
} __ether_lccr_bits;

/* CRC Error Frame Receive Counter Register (CEFCR) */
typedef struct {
  __REG32 CEFC          :16;
  __REG32               :16;
} __ether_cefcr_bits;

/* ETHER Frame Receive Error Counter Register (FRECR) */
typedef struct {
  __REG32 FREC          :16;
  __REG32               :16;
} __ether_frecr_bits;

/* Too-Short Frame Receive Counter Register (TSFRCR) */
typedef struct {
  __REG32 TSFC          :16;
  __REG32               :16;
} __ether_tsfrcr_bits;

/* ETHER Too-Long Frame Receive Counter Register (TLFRCR) */
typedef struct {
  __REG32 TLFC          :16;
  __REG32               :16;
} __ether_tlfrcr_bits;

/* Residual-Bit Frame Receive Counter Register (RFCR) */
typedef struct {
  __REG32 RFC           :16;
  __REG32               :16;
} __ether_rfcr_bits;

/* Carrier Extension Loss Counter Register (CERCR) */
typedef struct {
  __REG32 CERC          :16;
  __REG32               :16;
} __ether_cercr_bits;

/* Carrier Extension Counter Register (CEECR) */
typedef struct {
  __REG32 CEEC          :16;
  __REG32               :16;
} __ether_ceecr_bits;

/* Multicast Address Frame Receive Counter Register (MAFCR) */
typedef struct {
  __REG32 MAFC          :16;
  __REG32               :16;
} __ether_mafcr_bits;

/* Automatic PAUSE Frame Register (APR) */
typedef struct {
  __REG32 AP            :16;
  __REG32               :16;
} __ether_apr_bits;

/* Manual PAUSE Frame Register (MPR) */
typedef struct {
  __REG32 MP            :16;
  __REG32               :16;
} __ether_mpr_bits;

/* Automatic PAUSE Frame Retransmit Count Register (TPAUSER) */
typedef struct {
  __REG32 TPAUSE        :16;
  __REG32               :16;
} __ether_tpauser_bits;

/* PAUSE Frame Transmit Counter Register (PFTCR) */
typedef struct {
  __REG32 PFTXC         :16;
  __REG32               :16;
} __ether_pftcr_bits;

/* PAUSE Frame Receive Register (PFRCR) */
typedef struct {
  __REG32 PFRXC         :16;
  __REG32               :16;
} __ether_pfrcr_bits;

/* TSU Counter Reset Register (TSU_CTRST) */
typedef struct {
  __REG32               : 8;
  __REG32 CTRST         : 1;
  __REG32               :23;
} __ether_tsu_ctrst_bits;

/* VLANtag Set Register (TSU_VTAG0) */
typedef struct {
  __REG32 VID0          :12;
  __REG32               :19;
  __REG32 VTAG0         : 1;
} __ether_tsu_vtag0_bits;

/* CAM Entry Table Busy Register (TSU_ADSBSY) */
typedef struct {
  __REG32 ADSBSY        : 1;
  __REG32               :31;
} __ether_tsu_adsbsy_bits;

/* CAM Entry Table Enable Register (TSU_TEN) */
typedef struct {
  __REG32 TEN31         : 1;
  __REG32 TEN30         : 1;
  __REG32 TEN29         : 1;
  __REG32 TEN28         : 1;
  __REG32 TEN27         : 1;
  __REG32 TEN26         : 1;
  __REG32 TEN25         : 1;
  __REG32 TEN24         : 1;
  __REG32 TEN23         : 1;
  __REG32 TEN22         : 1;
  __REG32 TEN21         : 1;
  __REG32 TEN20         : 1;
  __REG32 TEN19         : 1;
  __REG32 TEN18         : 1;
  __REG32 TEN17         : 1;
  __REG32 TEN16         : 1;
  __REG32 TEN15         : 1;
  __REG32 TEN14         : 1;
  __REG32 TEN13         : 1;
  __REG32 TEN12         : 1;
  __REG32 TEN11         : 1;
  __REG32 TEN10         : 1;
  __REG32 TEN9          : 1;
  __REG32 TEN8          : 1;
  __REG32 TEN7          : 1;
  __REG32 TEN6          : 1;
  __REG32 TEN5          : 1;
  __REG32 TEN4          : 1;
  __REG32 TEN3          : 1;
  __REG32 TEN2          : 1;
  __REG32 TEN1          : 1;
  __REG32 TEN0          : 1;
} __ether_tsu_ten_bits;

/* CAM Entry Table 0L to 31L Registers (TSU_ADRL0 to TSU_ADRL31) */
typedef struct {
  __REG32 ADRL          :16;
  __REG32               :16;
} __ether_tsu_adrl_bits;

/* E-DMAC Start Register (EDSR) */
typedef struct {
  __REG32 ENR           : 1;
  __REG32 ENT           : 1;
  __REG32               :30;
} __ether_edsr_bits;

/* E-DMAC Mode Register (EDMR) */
typedef struct {
  __REG32 SWRR          : 1;
  __REG32 SWRT          : 1;
  __REG32               : 2;
  __REG32 DL            : 2;
  __REG32 DE            : 1;
  __REG32               :25;
} __ether_edmr_bits;

/* E-DMAC Transmit Request Register (EDTRR) */
typedef struct {
  __REG32 TR            : 2;
  __REG32               :30;
} __ether_edtrr_bits;

/* E-DMAC Receive Request Register (EDRRR) */
typedef struct {
  __REG32 RR            : 1;
  __REG32               :31;
} __ether_edrrr_bits;

/* E-MAC/E-DMAC Status Register (EESR) */
typedef struct {
  __REG32 CERF          : 1;
  __REG32 PRE           : 1;
  __REG32 RTSF          : 1;
  __REG32 RTLF          : 1;
  __REG32 RRF           : 1;
  __REG32 CELF          : 1;
  __REG32 CEEF          : 1;
  __REG32 RMAF          : 1;
  __REG32 TRO           : 1;
  __REG32 CD            : 1;
  __REG32 DLC           : 1;
  __REG32               : 5;
  __REG32 RFOF          : 1;
  __REG32 RDE           : 1;
  __REG32 FR            : 1;
  __REG32 TFUF          : 1;
  __REG32 TDE           : 1;
  __REG32 TC0           : 1;
  __REG32 ECI           : 1;
  __REG32               : 1;
  __REG32 RFCOF         : 1;
  __REG32 RABT          : 1;
  __REG32 TABT          : 1;
  __REG32 ROC           : 1;
  __REG32 TUC           : 1;
  __REG32 TC1           : 1;
  __REG32 TWB           : 2;
} __ether_eesr_bits;

/* E-MAC/E-DMAC Status Interrupt Permission Register (EESIPR) */
typedef struct {
  __REG32 CERFIP        : 1;
  __REG32 PREIP         : 1;
  __REG32 RTSFIP        : 1;
  __REG32 RTLFIP        : 1;
  __REG32 RRFIP         : 1;
  __REG32 CELFIP        : 1;
  __REG32 CEEFIP        : 1;
  __REG32 RMAFIP        : 1;
  __REG32 TROIP         : 1;
  __REG32 CDIP          : 1;
  __REG32 DLCIP         : 1;
  __REG32               : 5;
  __REG32 RFOFIP        : 1;
  __REG32 RDEIP         : 1;
  __REG32 FRIP          : 1;
  __REG32 TFUFIP        : 1;
  __REG32 TDEIP         : 1;
  __REG32 TC0IP         : 1;
  __REG32 ECIIP         : 1;
  __REG32               : 1;
  __REG32 RFCOFIP       : 1;
  __REG32 RABTIP        : 1;
  __REG32 TABTIP        : 1;
  __REG32 ROCIP         : 1;
  __REG32 TUCIP         : 1;
  __REG32 TC1IP         : 1;
  __REG32 TWB0IP        : 1;
  __REG32 TWB1IP        : 1;
} __ether_eesipr_bits;

/* Transmit/Receive Status Copy Enable Register (TRSCER) */
typedef struct {
  __REG32 CERFCE        : 1;
  __REG32 PRECE         : 1;
  __REG32 RTSFCE        : 1;
  __REG32 RTLFCE        : 1;
  __REG32 RRFCE         : 1;
  __REG32 CELFCE        : 1;
  __REG32 CEEFCE        : 1;
  __REG32 RMAFCE        : 1;
  __REG32 TROCE         : 1;
  __REG32 CDCE          : 1;
  __REG32 DLCCE         : 1;
  __REG32               : 5;
  __REG32 RABTCE        : 1;
  __REG32 TABTCE        : 1;
  __REG32               :14;
} __ether_trscer_bits;

/* Receive Missed-Frame Counter Register (RMFCR) */
typedef struct {
  __REG32 MCF           :16;
  __REG32               :16;
} __ether_rmfcr_bits;

/* Transmit FIFO Threshold Register (TFTR) */
typedef struct {
  __REG32 TFT           :11;
  __REG32               :21;
} __ether_tftr_bits;

/* FIFO Depth Register (FDR) */
typedef struct {
  __REG32 RFD           : 5;
  __REG32               : 3;
  __REG32 TFD           : 3;
  __REG32               :21;
} __ether_fdr_bits;

/* Receiving Method Control Register (RMCR) */
typedef struct {
  __REG32 RNC           : 1;
  __REG32               :31;
} __ether_rmcr_bits;

/* Receive Descriptor Final Flag Register (RDFFR) */
typedef struct {
  __REG32 RDLF          : 1;
  __REG32               :31;
} __ether_rdffr_bits;

/* Transmit Descriptor Final Flag Register (TDFFR) */
typedef struct {
  __REG32 TDLF          : 1;
  __REG32               :31;
} __ether_tdffr_bits;

/* Overflow Alert FIFO Threshold Register (FCFTR) */
typedef struct {
  __REG32 RFD           : 8;
  __REG32               : 8;
  __REG32 RFF           : 5;
  __REG32               :11;
} __ether_fcftr_bits;

/* Receive Data Padding Insert Register (RPADIR) */
typedef struct {
  __REG32 PADR          :16;
  __REG32 PADS          : 5;
  __REG32               :11;
} __ether_rpadir_bits;

/* Intelligent Checksum Mode Register (CSMR) */
typedef struct {
  __REG32 SB            : 6;
  __REG32               :24;
  __REG32 CSMD          : 1;
  __REG32 CSEBL         : 1;
} __ether_csmr_bits;

/* Intelligent Checksum Skipped Bytes Monitor Register (CSSBM) */
typedef struct {
  __REG32 SBM           : 6;
  __REG32               :26;
} __ether_cssbm_bits;

/* Intelligent Checksum Monitor Register (CSSMR) */
typedef struct {
  __REG32 CS            :16;
  __REG32               :16;
} __ether_cssmr_bits;

/* A/D Data Registers A to H (ADDRA to ADDRH) */
typedef struct {
  __REG16               : 4;
  __REG16 DATA          :12;
} __adc_addr_bits;

/* A/D Comparison Upper Limit Value Registers A to H (ADCMPHA to ADCMPHH) */
typedef struct {
  __REG16               : 4;
  __REG16 DATA          :12;
} __adc_adcmph_bits;

/* A/D Comparison Lower Limit Value Registers A to H (ADCMPLA to ADCMPLH) */
typedef struct {
  __REG16               : 4;
  __REG16 DATA          :12;
} __adc_adcmpl_bits;

/* A/D Control/Status Register (ADCSR) */
typedef struct {
  __REG16 CH            : 3;
  __REG16 MDS           : 3;
  __REG16 CKS           : 3;
  __REG16 TRGS          : 4;
  __REG16 ADST          : 1;
  __REG16 ADIE          : 1;
  __REG16 ADF           : 1;
} __adc_adcsr_bits;

/* A/D Comparison Interrupt Enable Register (ADCMPER) */
typedef struct {
  __REG16 LLMENA        : 1;
  __REG16 LLMENB        : 1;
  __REG16 LLMENC        : 1;
  __REG16 LLMEND        : 1;
  __REG16 LLMENE        : 1;
  __REG16 LLMENF        : 1;
  __REG16 LLMENG        : 1;
  __REG16 LLMENH        : 1;
  __REG16 HLMENA        : 1;
  __REG16 HLMENB        : 1;
  __REG16 HLMENC        : 1;
  __REG16 HLMEND        : 1;
  __REG16 HLMENE        : 1;
  __REG16 HLMENF        : 1;
  __REG16 HLMENG        : 1;
  __REG16 HLMENH        : 1;
} __adc_adcmper_bits;

/* A/D Comparison Status Register (ADCMPSR) */
typedef struct {
  __REG16 LUDRA         : 1;
  __REG16 LUDRB         : 1;
  __REG16 LUDRC         : 1;
  __REG16 LUDRD         : 1;
  __REG16 LUDRE         : 1;
  __REG16 LUDRF         : 1;
  __REG16 LUDRG         : 1;
  __REG16 LUDRH         : 1;
  __REG16 HOVRA         : 1;
  __REG16 HOVRB         : 1;
  __REG16 HOVRC         : 1;
  __REG16 HOVRD         : 1;
  __REG16 HOVRE         : 1;
  __REG16 HOVRF         : 1;
  __REG16 HOVRG         : 1;
  __REG16 HOVRH         : 1;
} __adc_adcmpsr_bits;

/* Common Control Register (FLCMNCR) */
typedef struct {
  __REG32               : 3;
  __REG32 CE            : 1;
  __REG32               : 5;
  __REG32 NANDWF        : 1;
  __REG32 ACM           : 2;
  __REG32               : 5;
  __REG32 QTSEL         : 1;
  __REG32 SNAND         : 1;
  __REG32               : 2;
  __REG32 BUSYON        : 1;
  __REG32               :10;
} __flctl_flcmncr_bits;

/* Command Control Register (FLCMDCR) */
typedef struct {
  __REG32 SCTCNT        :16;
  __REG32 DOCMD1        : 1;
  __REG32 DOCMD2        : 1;
  __REG32 ADRCNT        : 2;
  __REG32 DOADR         : 1;
  __REG32 SELRW         : 1;
  __REG32               : 2;
  __REG32 DOSR          : 1;
  __REG32 CDSRC         : 1;
  __REG32 ADRMD         : 1;
  __REG32 SCTCNT19_16   : 4;
  __REG32 ADRCNT2       : 1;
} __flctl_flcmdcr_bits;

/* Command Code Register (FLCMCDR) */
typedef struct {
  __REG32 CMD1          : 8;
  __REG32 CMD2          : 8;
  __REG32               :16;
} __flctl_flcmcdr_bits;

/* Address Register (FLADR) */
typedef union {
  struct {
    __REG32 ADR           :26;
    __REG32               : 6;
  };
  /* FLCTL_FLADR */
  struct {
    __REG32 ADR1          : 8;
    __REG32 ADR2          : 8;
    __REG32 ADR3          : 8;
    __REG32 ADR4          : 8;
  };
} __flctl_fladr_bits;

/* Address Register (FLADR2) */
typedef struct {
  __REG32 ADR5          : 8;
  __REG32               :24;
} __flctl_fladr2_bits;

/* Data Counter Register (FLDTCNTR) */
typedef struct {
  __REG32 DTCNT         :12;
  __REG32               : 4;
  __REG32 DTFLW         : 8;
  __REG32 ECFLW         : 8;
} __flctl_fldtcntr_bits;

/* Data Register (FLDATAR) */
typedef struct {
  __REG32 DT1           : 8;
  __REG32 DT2           : 8;
  __REG32 DT3           : 8;
  __REG32 DT4           : 8;
} __flctl_fldatar_bits;

/* Interrupt DMA Control Register (FLINTDMACR) */
typedef struct {
  __REG32 TRINTE0       : 1;
  __REG32 TRINTE1       : 1;
  __REG32 TEINTE        : 1;
  __REG32 RBERINTE      : 1;
  __REG32 STERINTE      : 1;
  __REG32 TRREQF0       : 1;
  __REG32 TRREQF1       : 1;
  __REG32 BTOERB        : 1;
  __REG32 STERB         : 1;
  __REG32               : 7;
  __REG32 DREQ0EN       : 1;
  __REG32 DREQ1EN       : 1;
  __REG32 AC0CLR        : 1;
  __REG32 AC1CLR        : 1;
  __REG32 FIFOTRG       : 2;
  __REG32               :10;
} __flctl_flintdmacr_bits;

/* Ready Busy Timeout Setting Register (FLBSYTMR) */
typedef struct {
  __REG32 RBTMOUT       :20;
  __REG32               :12;
} __flctl_flbsytmr_bits;

/* Ready Busy Timeout Counter (FLBSYCNT) */
typedef struct {
  __REG32 RBTIMCNT      :20;
  __REG32               : 4;
  __REG32 STAT          : 8;
} __flctl_flbsycnt_bits;

/* Transfer Control Register (FLTRCR) */
typedef struct {
  __REG8  TRSTRT        : 1;
  __REG8  TREND         : 1;
  __REG8  TRSTAT        : 1;
  __REG8                : 5;
} __flctl_fltrcr_bits;

/* USB System Configuration Control Register (SYSCFG0) */
typedef struct {
  __REG16 USBE          : 1;
  __REG16 UPLLE         : 1;
  __REG16 USCSEL        : 1;
  __REG16               : 1;
  __REG16 DPRUPU        : 1;
  __REG16 DRPD          : 1;
  __REG16 DCFM          : 1;
  __REG16 HSE           : 1;
  __REG16               : 8;
} __usb_syscfg0_bits;

/* USB CPU Bus Setting Register (BUSWAIT) */
typedef struct {
  __REG16 BWAIT         : 6;
  __REG16               :10;
} __usb_buswait_bits;

/* USB System Configuration Status Register (SYSSTS0) */
typedef struct {
  __REG16 LNST          : 2;
  __REG16               :14;
} __usb_syssts0_bits;

/* USB Device State Control Register 0 (DVSTCTR0) */
typedef struct {
  __REG16 RHST          : 3;
  __REG16               : 1;
  __REG16 UACT          : 1;
  __REG16 RESUME        : 1;
  __REG16 USBRST        : 1;
  __REG16 RWUPE         : 1;
  __REG16 WKUP          : 1;
  __REG16               : 7;
} __usb_dvstctr0_bits;

/* USB Test Mode Register (TESTMODE) */
typedef struct {
  __REG16 UTST          : 4;
  __REG16               :12;
} __usb_testmode_bits;

/* USB DMA-FIFO Bus Confguration Registers (D0FBCFG, D1FBCFG) */
typedef struct {
  __REG16               : 4;
  __REG16 TENDE         : 1;
  __REG16               :11;
} __usb_dxfbcfg_bits;

/* USB FIFO Port Registers (CFIFO, D0FIFO, D1FIFO) */
typedef union {
  /* USB_CFIFO_0 */
  /* USB_D0FIFO_0 */
  /* USB_D1FIFO_0 */
  /* USB_CFIFO_1 */
  /* USB_D0FIFO_1 */
  /* USB_D1FIFO_1 */
  struct {
    __REG32             :32;
  };
  struct {
    __REG16 __halfword0;
    __REG16 __halfword1;
  };
  struct {
    __REG8 __byte0;
    __REG8 __byte1;
    __REG8 __byte2;
    __REG8 __byte3;
  };
} __usb_cfifo_d0fifo_d1fifo_bits;

/* USB FIFO Port Select Registers (CFIFOSEL) */
typedef struct {
  __REG16 CURPIPE       : 4;
  __REG16               : 1;
  __REG16 ISEL          : 1;
  __REG16               : 2;
  __REG16 BIGEND        : 1;
  __REG16               : 1;
  __REG16 MBW           : 2;
  __REG16               : 2;
  __REG16 REW           : 1;
  __REG16 RCNT          : 1;
} __usb_cfifosel_bits;

/* USB FIFO Port Select Registers (D0FIFOSEL, D1FIFOSEL) */
typedef struct {
  __REG16 CURPIPE       : 4;
  __REG16               : 4;
  __REG16 BIGEND        : 1;
  __REG16               : 1;
  __REG16 MBW           : 2;
  __REG16 DREQE         : 1;
  __REG16 DCLRM         : 1;
  __REG16 REW           : 1;
  __REG16 RCNT          : 1;
} __usb_dxfifosel_bits;

/* USB FIFO Port Control Registers (CFIFOCTR, D0FIFOCTR, D1FIFOCTR) */
typedef struct {
  __REG16 DTLN          :12;
  __REG16               : 1;
  __REG16 FRDY          : 1;
  __REG16 BCLR          : 1;
  __REG16 BVAL          : 1;
} __usb_xfifoctr_bits;

/* USB Interrupt Enable Register 0 (INTENB0) */
typedef struct {
  __REG16               : 8;
  __REG16 BRDYE         : 1;
  __REG16 NRDYE         : 1;
  __REG16 BEMPE         : 1;
  __REG16 CTRE          : 1;
  __REG16 DVSE          : 1;
  __REG16 SOFE          : 1;
  __REG16 RSME          : 1;
  __REG16 VBSE          : 1;
} __usb_intenb0_bits;

/* USB Interrupt Enable Register 1 (INTENB1) */
typedef struct {
  __REG16               : 4;
  __REG16 SACKE         : 1;
  __REG16 SIGNE         : 1;
  __REG16 EOFERRE       : 1;
  __REG16               : 4;
  __REG16 ATTCHE        : 1;
  __REG16 DTCHE         : 1;
  __REG16               : 1;
  __REG16 BCHGE         : 1;
  __REG16               : 1;
} __usb_intenb1_bits;

/* USB SOF Output Configuration Register (SOFCFG) */
typedef struct {
  __REG16               : 6;
  __REG16 BRDYM         : 1;
  __REG16               : 1;
  __REG16 TRNENSEL      : 1;
  __REG16               : 7;
} __usb_sofcfg_bits;

/* USB Interrupt Status Register 0 (INTSTS0) */
typedef struct {
  __REG16 CTSQ          : 3;
  __REG16 VALID         : 1;
  __REG16 DVSQ          : 3;
  __REG16 VBSTS         : 1;
  __REG16 BRDY          : 1;
  __REG16 NRDY          : 1;
  __REG16 BEMP          : 1;
  __REG16 CTRT          : 1;
  __REG16 DVST          : 1;
  __REG16 SOFR          : 1;
  __REG16 RESM          : 1;
  __REG16 VBINT         : 1;
} __usb_intsts0_bits;

/* USB Interrupt Status Register 1 (INTSTS1) */
typedef struct {
  __REG16               : 4;
  __REG16 SACK          : 1;
  __REG16 SIGN          : 1;
  __REG16 EOFERR        : 1;
  __REG16               : 4;
  __REG16 ATTCH         : 1;
  __REG16 DTCH          : 1;
  __REG16               : 1;
  __REG16 BCHG          : 1;
  __REG16               : 1;
} __usb_intsts1_bits;

/* BRDY Interrupt Status Register (BRDYSTS) */
typedef struct {
  __REG16 PIPEBRDY0     : 1;
  __REG16 PIPEBRDY1     : 1;
  __REG16 PIPEBRDY2     : 1;
  __REG16 PIPEBRDY3     : 1;
  __REG16 PIPEBRDY4     : 1;
  __REG16 PIPEBRDY5     : 1;
  __REG16 PIPEBRDY6     : 1;
  __REG16 PIPEBRDY7     : 1;
  __REG16 PIPEBRDY8     : 1;
  __REG16 PIPEBRDY9     : 1;
  __REG16 PIPEBRDY10    : 1;
  __REG16 PIPEBRDY11    : 1;
  __REG16 PIPEBRDY12    : 1;
  __REG16 PIPEBRDY13    : 1;
  __REG16 PIPEBRDY14    : 1;
  __REG16 PIPEBRDY15    : 1;
} __usb_brdysts_bits;

/* NRDY Interrupt Status Register (NRDYSTS) */
typedef struct {
  __REG16 PIPENRDY0     : 1;
  __REG16 PIPENRDY1     : 1;
  __REG16 PIPENRDY2     : 1;
  __REG16 PIPENRDY3     : 1;
  __REG16 PIPENRDY4     : 1;
  __REG16 PIPENRDY5     : 1;
  __REG16 PIPENRDY6     : 1;
  __REG16 PIPENRDY7     : 1;
  __REG16 PIPENRDY8     : 1;
  __REG16 PIPENRDY9     : 1;
  __REG16 PIPENRDY10    : 1;
  __REG16 PIPENRDY11    : 1;
  __REG16 PIPENRDY12    : 1;
  __REG16 PIPENRDY13    : 1;
  __REG16 PIPENRDY14    : 1;
  __REG16 PIPENRDY15    : 1;
} __usb_nrdysts_bits;

/* BEMP Interrupt Status Register (BEMPSTS) */
typedef struct {
  __REG16 PIPEBEMP0     : 1;
  __REG16 PIPEBEMP1     : 1;
  __REG16 PIPEBEMP2     : 1;
  __REG16 PIPEBEMP3     : 1;
  __REG16 PIPEBEMP4     : 1;
  __REG16 PIPEBEMP5     : 1;
  __REG16 PIPEBEMP6     : 1;
  __REG16 PIPEBEMP7     : 1;
  __REG16 PIPEBEMP8     : 1;
  __REG16 PIPEBEMP9     : 1;
  __REG16 PIPEBEMP10    : 1;
  __REG16 PIPEBEMP11    : 1;
  __REG16 PIPEBEMP12    : 1;
  __REG16 PIPEBEMP13    : 1;
  __REG16 PIPEBEMP14    : 1;
  __REG16 PIPEBEMP15    : 1;
} __usb_bempsts_bits;

/* USB Frame Number Register (FRMNUM) */
typedef struct {
  __REG16 FRNM          :11;
  __REG16               : 3;
  __REG16 CRCE          : 1;
  __REG16 OVRN          : 1;
} __usb_frmnum_bits;

/* USB uFrame Nmber Register (UFRMNUM) */
typedef struct {
  __REG16 UFRNM         : 3;
  __REG16               :13;
} __usb_ufrmnum_bits;

/* USB Address Register (USBADDR) */
typedef struct {
  __REG16 USBADDR       : 7;
  __REG16               : 9;
} __usb_usbaddr_bits;

/* USB Request Type Register (USBREQ) */
typedef struct {
  __REG16 BMREQUESTTYPE : 8;
  __REG16 BREQUEST      : 8;
} __usb_usbreq_bits;

/* USB DCP Configuration Register (DCPCFG) */
typedef struct {
  __REG16               : 4;
  __REG16 DIR           : 1;
  __REG16               :11;
} __usb_dcpcfg_bits;

/* USB DCP Maximum Packet Size (DCPMAXP) */
typedef struct {
  __REG16 MXPS          : 7;
  __REG16               : 5;
  __REG16 DEVSEL        : 4;
} __usb_dcpmaxp_bits;

/* USB DCP Control Register (DCPCTR) */
typedef struct {
  __REG16 PID           : 2;
  __REG16 CCPL          : 1;
  __REG16               : 1;
  __REG16 PINGE         : 1;
  __REG16 PBUSY         : 1;
  __REG16 SQMON         : 1;
  __REG16 SQSET         : 1;
  __REG16 SQCLR         : 1;
  __REG16               : 2;
  __REG16 SUREQCLR      : 1;
  __REG16 CSSTS         : 1;
  __REG16 CSCLR         : 1;
  __REG16 SUREQ         : 1;
  __REG16 BSTS          : 1;
} __usb_dcpctr_bits;

/* USB Pipe Window Select Register (PIPESEL) */
typedef struct {
  __REG16 PIPESEL       : 4;
  __REG16               :12;
} __usb_pipesel_bits;

/* USB Pipe Configuration Register (PIPECFG) */
typedef struct {
  __REG16 EPNUM         : 4;
  __REG16 DIR           : 1;
  __REG16               : 2;
  __REG16 SHTNAK        : 1;
  __REG16 CNTMD         : 1;
  __REG16 DBLB          : 1;
  __REG16 BFRE          : 1;
  __REG16               : 3;
  __REG16 TYPE          : 2;
} __usb_pipecfg_bits;

/* USB Pipe Buffer Setting Register (PIPEBUF) */
typedef struct {
  __REG16 BUFNMB        : 8;
  __REG16               : 2;
  __REG16 BUFSIZE       : 5;
  __REG16               : 1;
} __usb_pipebuf_bits;

/* USB Pipe Maximum Packet Size Register (PIPEMAXP) */
typedef struct {
  __REG16 MXPS          :11;
  __REG16               : 1;
  __REG16 DEVSEL        : 4;
} __usb_pipemaxp_bits;

/* USB Pipe Timing Control Register (PIPEPERI) */
typedef struct {
  __REG16 IITV          : 3;
  __REG16               : 9;
  __REG16 IFIS          : 1;
  __REG16               : 3;
} __usb_pipeperi_bits;

/* USB PIPEn Control Registers (PIPEnCTR n=1 to 5, 9) */
typedef struct {
  __REG16 PID           : 2;
  __REG16               : 3;
  __REG16 PBUSY         : 1;
  __REG16 SQMON         : 1;
  __REG16 SQSET         : 1;
  __REG16 SQCLR         : 1;
  __REG16 ACLRM         : 1;
  __REG16 ATREPM        : 1;
  __REG16               : 1;
  __REG16 CSSTS         : 1;
  __REG16 CSCLR         : 1;
  __REG16 INBUFM        : 1;
  __REG16 BSTS          : 1;
} __usb_pipe15_9ctr_bits;

/* USB PIPEn Control Registers (PIPEnCTR n=6 to 8) */
typedef struct {
  __REG16 PID           : 2;
  __REG16               : 3;
  __REG16 PBUSY         : 1;
  __REG16 SQMON         : 1;
  __REG16 SQSET         : 1;
  __REG16 SQCLR         : 1;
  __REG16 ACLRM         : 1;
  __REG16               : 2;
  __REG16 CSSTS         : 1;
  __REG16 CSCLR         : 1;
  __REG16               : 1;
  __REG16 BSTS          : 1;
} __usb_pipe68ctr_bits;

/* USB PIPEn Control Registers (PIPEnCTR n=9) */
typedef struct {
  __REG16 PID           : 2;
  __REG16               : 3;
  __REG16 PBUSY         : 1;
  __REG16 SQMON         : 1;
  __REG16 SQSET         : 1;
  __REG16 SQCLR         : 1;
  __REG16 ACLRM         : 1;
  __REG16 ATREPM        : 1;
  __REG16               : 3;
  __REG16 INBUFM        : 1;
  __REG16 BSTS          : 1;
} __usb_pipeAFctr_bits;

/* USB PIPEn Transaction Counter Enable Register (PIPEnTRE n=1 to 5, 9, A to F) */
typedef struct {
  __REG16               : 8;
  __REG16 TRCLR         : 1;
  __REG16 TRENB         : 1;
  __REG16               : 6;
} __usb_pipe15_9_AFtre_bits;

/* USB Device Address n Configuration Registers (DEVADDn n=0 to 9, A) */
typedef struct {
  __REG16               : 6;
  __REG16 USBSPD        : 2;
  __REG16 HUBPORT       : 3;
  __REG16 UPPHUB        : 4;
  __REG16               : 1;
} __usb_devadd09_A_bits;

/* USB UTMI Suspend Mode Register (SUSPMODE) */
typedef struct {
  __REG16               :14;
  __REG16 SUSPM         : 1;
  __REG16               : 1;
} __usb_suspmode_bits;

/* ADC Control Register 1 (ADCCR1) */
typedef struct {
  __REG16               : 8;
  __REG16 AGCMODE       : 1;
  __REG16               : 7;
} __dvdec_adccr1_bits;

/* Timing Generation Register 1 (TGCR1) */
typedef struct {
  __REG16 SRCLEFT       : 8;
  __REG16               : 8;
} __dvdec_tgcr1_bits;

/* Timing Generation Control Register 2 (TGCR2) */
typedef struct {
  __REG16 SRCHEIGHT     :10;
  __REG16 SRCTOP        : 6;
} __dvdec_tgcr2_bits;

/* Timing Generation Control Register 3 (TGCR3) */
typedef struct {
  __REG16 SRCWIDTH      :11;
  __REG16               : 5;
} __dvdec_tgcr3_bits;

/* Sync Separation Control Register 1 (SYNSCR1) */
typedef struct {
  __REG16 SLICERMODE_V    : 2;
  __REG16 SLICERMODE_H    : 2;
  __REG16 VELOCITYSHIFT_H : 4;
  __REG16                 : 2;
  __REG16 LPFHSYNC        : 3;
  __REG16 LPFVSYNC        : 3;
} __dvdec_synscr1_bits;

/* Sync Separation Control Register 2 (SYNSCR2) */
typedef struct {
  __REG16 SYNCMINDUTY_H : 6;
  __REG16 SYNCMAXDUTY_H : 6;
  __REG16               : 4;
} __dvdec_synscr2_bits;

/* Sync Separation Control Register 3 (SYNSCR3) */
typedef struct {
  __REG16 CSYNCSLICE_H  :10;
  __REG16 SSCLIPSEL     : 4;
  __REG16               : 2;
} __dvdec_synscr3_bits;

/* Sync Separation Control Register 4 (SYNSCR4) */
typedef struct {
  __REG16 SYNCMINDUTY_V : 6;
  __REG16 SYNCMAXDUTY_V : 6;
  __REG16               : 4;
} __dvdec_synscr4_bits;

/* Sync Separation Control Register 5 (SYNSCR5) */
typedef struct {
  __REG16 CSYNCSLICE_V  :10;
  __REG16 VSYNCSLICE    : 5;
  __REG16 VSYNCDELAY    : 1;
} __dvdec_synscr5_bits;

/* Horizontal AFC Control Register 1 (HAFCCR1) */
typedef struct {
  __REG16 HAFCTYP       :10;
  __REG16 HAFCFREERUN   : 1;
  __REG16               : 1;
  __REG16 HAFCGAIN      : 4;
} __dvdec_hafccr1_bits;

/* Horizontal AFC Control Register 2 (HAFCCR2) */
typedef struct {
  __REG16 HAFCMAX       :10;
  __REG16 DOX2HOSC      : 1;
  __REG16 NOX2HOSC      : 1;
  __REG16 HAFCSTART     : 4;
} __dvdec_hafccr2_bits;

/* Horizontal AFC Control Register 3 (HAFCCR3) */
typedef struct {
  __REG16 HAFCMIN       :10;
  __REG16 HAFCMODE      : 2;
  __REG16 HAFCEND       : 4;
} __dvdec_hafccr3_bits;

/* Vertical Countdown Control Register 1 (VCDWCR1) */
typedef struct {
  __REG16 VCDOFFSET     : 5;
  __REG16 VCDWINDOW     : 6;
  __REG16 VCDDEFAULT    : 2;
  __REG16 NOVCD60       : 1;
  __REG16 NOVCD50       : 1;
  __REG16 VCDFREERUN    : 1;
} __dvdec_vcdwcr1_bits;

/* Digital Clamp Control Register 1 (DCPCR1) */
typedef struct {
  __REG16 BLANKLEVEL_Y  :10;
  __REG16               : 1;
  __REG16 DCPCHECK      : 1;
  __REG16               : 3;
  __REG16 DCPMODE       : 1;
} __dvdec_dcpcr1_bits;

/* Digital Clamp Control Register 2 (DCPCR2) */
typedef struct {
  __REG16 BLANKLEVEL_CR : 6;
  __REG16 BLANKLEVEL_CB : 6;
  __REG16               : 3;
  __REG16 DCPMODE_C     : 1;
} __dvdec_dcpcr2_bits;

/* Digital Clamp Control Register 3 (DCPCR3) */
typedef struct {
  __REG16               :12;
  __REG16 DCPRESPONSE   : 3;
  __REG16               : 1;
} __dvdec_dcpcr3_bits;

/* Digital Clamp Control Register 4 (DCPCR4) */
typedef struct {
  __REG16               :10;
  __REG16 DCPSTART      : 6;
} __dvdec_dcpcr4_bits;

/* Digital Clamp Control Register 5 (DCPCR5) */
typedef struct {
  __REG16               :10;
  __REG16 DCPEND        : 6;
} __dvdec_dcpcr5_bits;

/* Digital Clamp Control Register 6 (DCPCR6) */
typedef struct {
  __REG16               : 8;
  __REG16 DCPWIDTH      : 7;
  __REG16               : 1;
} __dvdec_dcpcr6_bits;

/* Digital Clamp Control Register 7 (DCPCR7) */
typedef struct {
  __REG16               : 8;
  __REG16 DCPPOS_Y      : 8;
} __dvdec_dcpcr7_bits;

/* Digital Clamp Control Register 8 (DCPCR8) */
typedef struct {
  __REG16               : 8;
  __REG16 DCPPOS_C      : 8;
} __dvdec_dcpcr8_bits;

/* Noise Detection Control Register (NSDCR) */
typedef struct {
  __REG16 ACFFILTER     : 2;
  __REG16               : 2;
  __REG16 ACFLAGTIME    : 5;
  __REG16               : 3;
  __REG16 ACFINPUT      : 2;
  __REG16               : 2;
} __dvdec_nsdcr_bits;

/* Burst Lock/Chroma Decoding Control Register (BTLCR) */
typedef struct {
  __REG16 NOSECAM       : 1;
  __REG16 NOPAL443      : 1;
  __REG16 NOPALN        : 1;
  __REG16 NOPALM        : 1;
  __REG16 NONTSC443     : 1;
  __REG16 NONTSC358     : 1;
  __REG16 DEFAULTSYS    : 2;
  __REG16               : 1;
  __REG16 BCOFREERUN    : 1;
  __REG16 LOCKLIMIT     : 2;
  __REG16 LOOPGAIN      : 2;
  __REG16 LOCKRANGE     : 2;
} __dvdec_btlcr_bits;

/* Burst Gate Pulse Control Register (BTGPCR) */
typedef struct {
  __REG16 BGPSTART      : 8;
  __REG16 BGPWIDTH      : 7;
  __REG16 BGPCHECK      : 1;
} __dvdec_btgpcr_bits;

/* ACC Control Register 1 (ACCCR1) */
typedef struct {
  __REG16 ACCLEVEL      : 9;
  __REG16 ACCMAXGAIN    : 2;
  __REG16 ACCMODE       : 1;
  __REG16 KILLEROFFSET  : 4;
} __dvdec_acccr1_bits;

/* ACC Control Register 2 (ACCCR2) */
typedef struct {
  __REG16 CHROMAMAINGAIN: 9;
  __REG16 CHROMASUBGAIN : 2;
  __REG16               : 5;
} __dvdec_acccr2_bits;

/* ACC Control Register 3 (ACCCR3) */
typedef struct {
  __REG16               : 1;
  __REG16 KILLERLEVEL   : 6;
  __REG16 KILLERMODE    : 1;
  __REG16 ACCPRECIS     : 6;
  __REG16 ACCRESPONSE   : 2;
} __dvdec_acccr3_bits;

/* TINT Control Register (TINTCR) */
typedef struct {
  __REG16 TINTMAIN      :10;
  __REG16 TINTSUB       : 6;
} __dvdec_tintcr_bits;

/* Y/C Delay/Chroma Decoding Control Register (YCDCR) */
typedef struct {
  __REG16 DEMOMODE      : 2;
  __REG16 CHROMALPF     : 1;
  __REG16               : 1;
  __REG16 LUMADELAY     : 5;
  __REG16               : 7;
} __dvdec_ycdcr_bits;

/* AGC Control Register 1 (AGCCR1) */
typedef struct {
  __REG16 AGCLEVEL      : 9;
  __REG16 AGCRESPONSE   : 3;
  __REG16 NOREDUCE      : 1;
  __REG16 DOREDUCE      : 1;
  __REG16               : 2;
} __dvdec_agccr1_bits;

/* AGC Control Register 2 (AGCCR2) */
typedef struct {
  __REG16               : 8;
  __REG16 AGCPRECIS     : 6;
  __REG16               : 2;
} __dvdec_agccr2_bits;

/* Peak Limiter Control Register (PKLIMITCR) */
typedef struct {
  __REG16 MAXPEAKSAMPLES: 8;
  __REG16 PEAKRATIO     : 2;
  __REG16 PEAKRELEASE   : 2;
  __REG16 PEAKATTACK    : 2;
  __REG16 PEAKLEVEL     : 2;
} __dvdec_pklimitcr_bits;

/* Over-Range Control Register 1 (RGORCR1) */
typedef struct {
  __REG16 RADJ_O_LEVEL0 :10;
  __REG16               : 6;
} __dvdec_rgorcr1_bits;

/* Over-Range Control Register 2 (RGORCR2) */
typedef struct {
  __REG16 RADJ_U_LEVEL0 :10;
  __REG16               : 6;
} __dvdec_rgorcr2_bits;

/* Over-Range Control Register 3 (RGORCR3) */
typedef struct {
  __REG16 RADJ_O_LEVEL1 :10;
  __REG16               : 6;
} __dvdec_rgorcr3_bits;

/* Over-Range Control Register 4 (RGORCR4) */
typedef struct {
  __REG16 RADJ_U_LEVEL1 :10;
  __REG16               : 6;
} __dvdec_rgorcr4_bits;

/* Over-Range Control Register 5 (RGORCR5) */
typedef struct {
  __REG16 RADJ_O_LEVEL2 :10;
  __REG16               : 6;
} __dvdec_rgorcr5_bits;

/* Over-Range Control Register 6 (RGORCR6) */
typedef struct {
  __REG16 RADJ_U_LEVEL2 :10;
  __REG16               : 6;
} __dvdec_rgorcr6_bits;

/* Over-Range Control Register 7 (RGORCR7) */
typedef struct {
  __REG16 HWIDE_SW      : 1;
  __REG16 DCMP_SW       : 1;
  __REG16 UCMP_SW       : 1;
  __REG16               : 6;
  __REG16 RADJ_MIX_K_FIX: 3;
  __REG16 TEST_MONI     : 3;
  __REG16               : 1;
} __dvdec_rgorcr7_bits;

/* Feedback Control Register for Horizontal AFC Phase Comparator (AFCPFCR) */
typedef struct {
  __REG16 PHDET_DIV     : 3;
  __REG16               : 1;
  __REG16 PHDET_FIX     : 1;
  __REG16               :11;
} __dvdec_afcpfcr_bits;

/* Register Update Enable Register (RUPDCR) */
typedef struct {
  __REG16               :15;
  __REG16 NEWSETTING    : 1;
} __dvdec_rupdcr_bits;

/* Sync Separation Status/Vertical Cycle Read Register (VSYNCSR) */
typedef struct {
  __REG16 FVCOUNT       : 8;
  __REG16 INTERLACED    : 1;
  __REG16 FVMODE        : 1;
  __REG16 FVLOCK        : 1;
  __REG16 NOSIGNAL      : 1;
  __REG16 FHMODE        : 1;
  __REG16 ISNOISY       : 1;
  __REG16 FHLOCK        : 1;
  __REG16 FHCOUNT       : 1;
} __dvdec_vsyncsr_bits;

/* Digital Clamp Read Register 1 (DCPSR1) */
typedef struct {
  __REG16 CLAMPLEVEL_Y  :10;
  __REG16 CLAMPLEVEL_CB : 6;
} __dvdec_dcpsr1_bits;

/* Digital Clamp Read Register 2 (DCPSR2) */
typedef struct {
  __REG16               :10;
  __REG16 CLAMPLEVEL_CR : 6;
} __dvdec_dcpsr2_bits;

/* Chroma Decoding Read Register 1 (CROMASR1) */
typedef struct {
  __REG16 ACCMAINGAIN   : 9;
  __REG16 ACCSUBGAIN    : 2;
  __REG16 NOBURST       : 1;
  __REG16 FSCLOCK       : 1;
  __REG16 FSCMODE       : 1;
  __REG16 COLORSYS      : 2;
} __dvdec_cromasr1_bits;

/* Chroma Decoding Read Register 2 (CROMASR2) */
typedef struct {
  __REG16 LOCKLEVEL     : 8;
  __REG16               : 2;
  __REG16 ISNTSC        : 1;
  __REG16 ISPAL         : 1;
  __REG16 ISSECAM       : 1;
  __REG16               : 3;
} __dvdec_cromasr2_bits;

/* Sync Separation Read Register (SYNCSSR) */
typedef struct {
  __REG16 SYNCDEPTH     :10;
  __REG16               : 2;
  __REG16 ISREDUCED     : 1;
  __REG16               : 3;
} __dvdec_syncssr_bits;

/* AGC Control Read Register 1 (AGCCSR1) */
typedef struct {
  __REG16 PEAKSAMPLES   : 8;
  __REG16 HIGHSAMPLES   : 8;
} __dvdec_agccsr1_bits;

/* AGC Control Read Register 2 (AGCCSR2) */
typedef struct {
  __REG16 AGCGAIN       : 8;
  __REG16 AGCCONVERGE   : 1;
  __REG16               : 7;
} __dvdec_agccsr2_bits;

/* Y/C Separation Control Register 3 (YCSCR3) */
typedef struct {
  __REG16 K11           : 6;
  __REG16 K13           : 6;
  __REG16 K15           : 4;
} __dvdec_ycscr3_bits;

/* Y/C Separation Control Register 4 (YCSCR4) */
typedef struct {
  __REG16 K12           : 6;
  __REG16 K14           : 6;
  __REG16 K16           : 4;
} __dvdec_ycscr4_bits;

/* Y/C Separation Control Register 5 (YCSCR4) */
typedef struct {
  __REG16 K21A          : 6;
  __REG16               : 2;
  __REG16 K22A          : 8;
} __dvdec_ycscr5_bits;

/* Y/C Separation Control Register 6 (YCSCR6) */
typedef struct {
  __REG16 K21B          : 6;
  __REG16               : 2;
  __REG16 K22B          : 8;
} __dvdec_ycscr6_bits;

/* Y/C Separation Control Register 7 (YCSCR7) */
typedef struct {
  __REG16 K24           : 5;
  __REG16               : 3;
  __REG16 K23A          : 4;
  __REG16 K23B          : 4;
} __dvdec_ycscr7_bits;

/* Y/C Separation Control Register 8 (YCSCR8) */
typedef struct {
  __REG16               :11;
  __REG16 HFIL_TAP_SEL  : 1;
  __REG16 HVBPF1_9TAP_ON: 1;
  __REG16 HBPF1_9TAP_ON : 1;
  __REG16 HVBPF1_NARROW : 1;
  __REG16 HBPF1_NARROW  : 1;
} __dvdec_ycscr8_bits;

/* Y/C Separation Control Register 9 (YCSCR9) */
typedef struct {
  __REG16 HVSEL_MIX_Y   : 4;
  __REG16 VSEL_MIX_Y    : 4;
  __REG16 HSEL_MIX_Y    : 4;
  __REG16               : 3;
  __REG16 DET2_ON       : 1;
} __dvdec_ycscr9_bits;

/* Y/C Separation Control Register 11 (YCSCR11) */
typedef struct {
  __REG16 V_Y_LEVEL     : 9;
  __REG16               : 7;
} __dvdec_ycscr11_bits;

/* Y/C Separation Control Register 12 (YCSCR12) */
typedef struct {
  __REG16 FIL2_NARROW_2D: 1;
  __REG16               : 1;
  __REG16 FIL2_MODE_2D  : 2;
  __REG16               : 4;
  __REG16 DET2_MIX_Y    : 4;
  __REG16 DET2_MIX_C    : 4;
} __dvdec_ycscr12_bits;

/* Digital Clamp Control Register 9 (DCPCR9) */
typedef struct {
  __REG16               :10;
  __REG16 CLP_HOLD_ON_CR: 1;
  __REG16 CLP_HOLD_ON_CB: 1;
  __REG16 CLP_HOLD_ON_Y : 1;
  __REG16               : 3;
} __dvdec_dcpcr9_bits;

/* Chroma Filter TAP Coefficient (WA_Fx) Registers for Y/C Separation (YCTWA_Fx) */
typedef struct {
  __REG16 FIL2_2D_WA_F  :13;
  __REG16               : 3;
} __dvdec_yctwa_fx_bits;

/* Chroma Filter TAP Coefficient (WB_Fx) Registers for Y/C Separation (YCTWB_Fx) */
typedef struct {
  __REG16 FIL2_2D_WB_F  :13;
  __REG16               : 3;
} __dvdec_yctwb_fx_bits;

/* Chroma Filter TAP Coefficient (NA_Fx) Registers for Y/C Separation (YCTNA_Fx) */
typedef struct {
  __REG16 FIL2_2D_NA_F  :13;
  __REG16               : 3;
} __dvdec_yctna_fx_bits;

/* Chroma Filter TAP Coefficient (NB_Fx) Registers for Y/C Separation (YCTNB_Fx) */
typedef struct {
  __REG16 FIL2_2D_NB_F  :13;
  __REG16               : 3;
} __dvdec_yctnb_fx_bits;

/* Luminance (Y) Signal Gain Control Register (YGAINCR) */
typedef struct {
  __REG16 Y_GAIN2       :10;
  __REG16               : 6;
} __dvdec_ygaincr_bits;

/* Color Difference (Cb) Signal Gain Control Register (CBGAINCR) */
typedef struct {
  __REG16 CB_GAIN2      :10;
  __REG16               : 6;
} __dvdec_cbgaincr_bits;

/* Color Difference (Cr) Signal Gain Control Register (CRGAINCR) */
typedef struct {
  __REG16 CR_GAIN2      :10;
  __REG16               : 6;
} __dvdec_crgaincr_bits;

/* PGA Register Update (PGA_UPDATE) */
typedef struct {
  __REG16 PGA_VEN       : 1;
  __REG16               :15;
} __dvdec_pga_update_bits;

/* PGA Control Register (PGACR) */
typedef struct {
  __REG16               : 8;
  __REG16 PGA_GAIN      : 6;
  __REG16 PGA_GAIN_SEL  : 1;
  __REG16               : 1;
} __dvdec_pgacr_bits;

/* ADC Control Register 2 (ADCCR2) */
typedef struct {
  __REG16 ADC_VINSEL    : 1;
  __REG16               :15;
} __dvdec_adccr2_bits;

/* External Input Block Register Update Control Register (INP_UPDATE) */
typedef struct {
  __REG32 INP_IMG_UPDATE         	: 1;
  __REG32               					: 3;
  __REG32 INP_EXT_UPDATE         	: 1;
  __REG32               					:27;
} __vdc_inp_update_bits;

/* Input Select Control Register (INP_SEL_CNT) */
typedef struct {
  __REG32 INP_HS_EDGE         		: 1;
  __REG32               					: 3;
  __REG32 INP_VS_EDGE         		: 1;
  __REG32               					: 3;
  __REG32 INP_PXD_EDGE         		: 1;
  __REG32               					: 3;
  __REG32 INP_FORMAT         			: 3;
  __REG32               					: 5;
  __REG32 INP_SEL		         			: 1;
  __REG32               					:11;
} __vdc_inp_sel_cnt_bits;

/* External Input Sync Signal Control Register (INP_EXT_SYNC_CNT) */
typedef struct {
  __REG32 INP_H_POS         			: 2;
  __REG32               					: 2;
  __REG32 INP_F525_625         		: 1;
  __REG32               					: 3;
  __REG32 INP_H_EDGE_SEL         	: 1;
  __REG32               					: 7;
  __REG32 INP_HS_INV         			: 1;
  __REG32               					: 3;
  __REG32 INP_VS_INV		         	: 1;
  __REG32               					: 3;
  __REG32 INP_SWAP_ON		         	: 1;
  __REG32               					: 3;
  __REG32 INP_ENDIAN_ON		        : 1;
  __REG32               					: 3;
} __vdc_inp_ext_sync_cnt_bits;

/* Vsync Signal Phase Adjustment Register (INP_VSYNC_PH_ADJ) */
typedef struct {
  __REG32 INP_FH25	         			:10;
  __REG32               					: 6;
  __REG32 INP_FH50		         		:10;
  __REG32               					: 6;
} __vdc_inp_vsync_ph_adj_bits;

/* Sync Signal Delay Adjustment Register (INP_DLY_ADJ) */
typedef struct {
  __REG32 INP_HS_DLY         			: 8;
  __REG32 INP_VS_DLY     					: 8;
  __REG32 INP_FLD_DLY	         		: 8;
  __REG32 INP_VS_DLY_L	       		: 3;
  __REG32               					: 5;
} __vdc_inp_dly_adj_bits;

/* Image Quality Adjustment Block Register Update Control Register (IMGCNT_UPDATE) */
typedef struct {
  __REG32 IMGCNT_VEN         			: 1;
  __REG32               					:31;
} __vdc_imgcnt_update_bits;

/* NR Control Register 0 (IMGCNT_NR_CNT0) */
typedef struct {
  __REG32 NR1D_Y_GAIN         		: 2;
  __REG32               					: 2;
  __REG32 NR1D_Y_TAP         			: 2;
  __REG32               					: 2;
  __REG32 NR1D_Y_TH		         		: 7;
  __REG32               					: 1;
  __REG32 NR1D_ON		         			: 1;
  __REG32               					: 3;
  __REG32 NR1D_MD		         			: 1;
  __REG32               					:11;
} __vdc_imgcnt_nr_cnt0_bits;

/* NR Control Register 1 (IMGCNT_NR_CNT1) */
typedef struct {
  __REG32 NR1D_CR_GAIN         		: 2;
  __REG32               					: 2;
  __REG32 NR1D_CR_TAP         		: 2;
  __REG32               					: 2;
  __REG32 NR1D_CR_TH		         	: 7;
  __REG32               					: 1;
  __REG32 NR1D_CB_GAIN		        : 2;
  __REG32               					: 2;
  __REG32 NR1D_CB_TAP		         	: 2;
  __REG32               					: 2;
  __REG32 NR1D_CB_TH		         	: 7;
  __REG32               					: 1;
} __vdc_imgcnt_nr_cnt1_bits;

/* Image Quality Adjustment Block Matrix YG Adjustment Register 1 (IMGCNT_MTX_YG_ADJ1) */
typedef struct {
  __REG32 IMGCNT_MTX_GR       		:11;
  __REG32               					: 5;
  __REG32 IMGCNT_MTX_GB        		:11;
  __REG32               					: 5;
} __vdc_imgcnt_mtx_yg_adj1_bits;

/* Image Quality Adjustment Block Matrix Mode Register (IMGCNT_MTX_MODE) */
typedef struct {
  __REG32 IMGCNT_MTX_MD       		: 2;
  __REG32               					:30;
} __vdc_imgcnt_mtx_mode_bits;

/* Image Quality Adjustment Block Matrix YG Adjustment Register 0 (IMGCNT_MTX_YG_ADJ0) */
typedef struct {
  __REG32 IMGCNT_MTX_GG       		:11;
  __REG32               					: 5;
  __REG32 IMGCNT_MTX_YG        		: 8;
  __REG32               					: 8;
} __vdc_imgcnt_mtx_yg_adj_bits;

/* Image Quality Adjustment Block Matrix CBB Adjustment Register 0 (IMGCNT_MTX_CBB_ADJ0) */
typedef struct {
  __REG32 IMGCNT_MTX_BG       		:11;
  __REG32               					: 5;
  __REG32 IMGCNT_MTX_B        		: 8;
  __REG32               					: 8;
} __vdc_imgcnt_mtx_cbb_adj_bits;

/* Image Quality Adjustment Block Matrix CBB Adjustment Register 1 (IMGCNT_MTX_CBB_ADJ1) */
typedef struct {
  __REG32 IMGCNT_MTX_BR       		:11;
  __REG32               					: 5;
  __REG32 IMGCNT_MTX_BB        		:11;
  __REG32               					: 5;
} __vdc_imgcnt_mtx_cbb_adj1_bits;

/* Image Quality Adjustment Block Matrix CRR Adjustment Register 0 (IMGCNT_MTX_CRR_ADJ0) */
typedef struct {
  __REG32 IMGCNT_MTX_RG       		:11;
  __REG32               					: 5;
  __REG32 IMGCNT_MTX_R        		: 8;
  __REG32               					: 8;
} __vdc_imgcnt_mtx_crr_adj_bits;

/* Image Quality Adjustment Block Matrix CRR Adjustment Register 1 (IMGCNT_MTX_CRR_ADJ1) */
typedef struct {
  __REG32 IMGCNT_MTX_RR       		:11;
  __REG32               					: 5;
  __REG32 IMGCNT_MTX_RB        		:11;
  __REG32               					: 5;
} __vdc_imgcnt_mtx_crr_adj1_bits;

/* Dynamic Range Compression Register (IMGCNT_DRC_REG) */
typedef struct {
  __REG32 DRCC_EN       					: 1;
  __REG32               					:31;
} __vdc_imgcnt_drc_reg_bits;

/* SCL0 Register Update Control Register (SCL0_UPDATE) */
typedef struct {
  __REG32 SCL0_VEN_A       				: 1;
  __REG32               					: 3;
  __REG32 SCL0_VEN_B        			: 1;
  __REG32               					: 3;
  __REG32 SCL0_UPDATE        			: 1;
  __REG32               					: 3;
  __REG32 SCL0_VEN_C        			: 1;
  __REG32 SCL0_VEN_D        			: 1;
  __REG32               					:18;
} __vdc_sc_scl_update_bits;

/* Mask Control Register (SCL0_FRC1) */
typedef struct {
  __REG32 RES_VMASK_ON       			: 1;
  __REG32               					:15;
  __REG32 RES_VMASK	        			:16;
} __vdc_sc_scl_frc1_bits;

/* Missing Vsync Compensation Control Register (SCL0_FRC2) */
typedef struct {
  __REG32 RES_VLACK_ON       			: 1;
  __REG32               					:15;
  __REG32 RES_VLACK	        			:16;
} __vdc_sc_scl_frc2_bits;

/* Output Sync Select Register (SCL0_FRC3) */
typedef struct {
  __REG32 RES_VS_SEL       				: 1;
  __REG32               					: 7;
  __REG32 RES_VS_IN_SEL       		: 1;
  __REG32               					:23;
} __vdc_sc_scl_frc3_bits;

/* Free-Running Period Control Register (SCL0_FRC4) */
typedef struct {
  __REG32 RES_FH		       				:11;
  __REG32               					: 5;
  __REG32 RES_FV		       				:11;
  __REG32               					: 5;
} __vdc_sc_scl_frc4_bits;

/* Output Delay Control Register (SCL0_FRC5) */
typedef struct {
  __REG32 RES_VSDLY	       				: 8;
  __REG32 RES_FLD_DLY_SEL     		: 1;
  __REG32               					:23;
} __vdc_sc_scl_frc5_bits;

/* Full-Screen Vertical Size Register (SCL0_FRC6) */
typedef struct {
  __REG32 RES_F_VW	       				:11;
  __REG32               					: 5;
  __REG32 RES_F_VS	       				:11;
  __REG32               					: 5;
} __vdc_sc_scl_frc6_bits;

/* Full-Screen Horizontal Size Register (SCL0_FRC7) */
typedef struct {
  __REG32 RES_F_HW	       				:11;
  __REG32               					: 5;
  __REG32 RES_F_HS	       				:11;
  __REG32               					: 5;
} __vdc_sc_scl_frc7_bits;

/* Vsync Detection Register (SCL0_FRC9) */
typedef struct {
  __REG32 RES_QVLACK	        		: 1;
  __REG32               					: 3;
  __REG32 RES_QVLOCK	       			: 1;
  __REG32               					:27;
} __vdc_sc_scl_frc9_bits;

/* Status Monitor 0 Register (SCL0_MON0) */
typedef struct {
  __REG16 RES_LIN_STAT        		:11;
  __REG16               					: 5;
} __vdc_sc_scl_mon0_bits;

/* Interrupt Control Register (SCL0_INT) */
typedef struct {
  __REG16 RES_LINE        				:11;
  __REG16               					: 5;
} __vdc_sc_scl_int_bits;

/* Scaling-Down Control Register (SCL0_DS1) */
typedef struct {
  __REG32 RES_DS_H_ON	        		: 1;
  __REG32               					: 3;
  __REG32 RES_DS_V_ON	       			: 1;
  __REG32               					:27;
} __vdc_sc_scl_ds1_bits;

/* Vertical Capture Size Register (SCL0_DS2) */
typedef struct {
  __REG32 RES_VW			        		:11;
  __REG32               					: 5;
  __REG32 RES_VS			       			:11;
  __REG32               					: 5;
} __vdc_sc_scl_ds2_bits;

/* Horizontal Capture Size Register (SCL0_DS3) */
typedef struct {
  __REG32 RES_HW			        		:11;
  __REG32               					: 5;
  __REG32 RES_HS			       			:11;
  __REG32               					: 5;
} __vdc_sc_scl_ds3_bits;

/* Horizontal Scale DownRegister (SCL0_DS4) */
typedef struct {
  __REG32 RES_DS_H_RATIO      		:16;
  __REG32               					:12;
  __REG32 RES_DS_H_INTERPOTYP			: 1;
  __REG32 RES_PFIL_SEL						: 1;
  __REG32               					: 2;
} __vdc_sc_scl_ds4_bits;

/* Initial Vertical Phase Register (SCL0_DS5) */
typedef struct {
  __REG32 RES_BTM_INIPHASE    		:12;
  __REG32               					: 4;
  __REG32 RES_TOP_INIPHASE				:12;
  __REG32 RES_V_INTERPOTYP				: 1;
  __REG32               					: 3;
} __vdc_sc_scl_ds5_bits;

/* Vertical Scaling Register (SCL0_DS6) */
typedef struct {
  __REG32 RES_V_RATIO			    		:16;
  __REG32               					:16;
} __vdc_sc_scl_ds6_bits;

/* Scaling-Down Control Block Output Size Register (SCL0_DS7) */
typedef struct {
  __REG32 RES_OUT_HW			    		:11;
  __REG32               					: 5;
  __REG32 RES_OUT_VW			    		:11;
  __REG32               					: 5;
} __vdc_sc_scl_ds7_bits;

/* Scaling-Up Control Register (SCL0_US1) */
typedef struct {
  __REG32 RES_US_H_ON			    		: 1;
  __REG32               					: 3;
  __REG32 RES_US_V_ON			    		: 1;
  __REG32               					:27;
} __vdc_sc_scl_us1_bits;

/* Output Image Vertical Size Register (SCL0_US2) */
typedef struct {
  __REG32 RES_P_VW				    		:11;
  __REG32               					: 5;
  __REG32 RES_P_VS				    		:11;
  __REG32               					: 5;
} __vdc_sc_scl_us2_bits;

/* Output Image Horizontal Size Register (SCL0_US3) */
typedef struct {
  __REG32 RES_P_HW				    		:11;
  __REG32               					: 5;
  __REG32 RES_P_HS				    		:11;
  __REG32               					: 5;
} __vdc_sc_scl_us3_bits;

/* Scaling-Up Control Block Input Size Register (SCL0_US4) */
typedef struct {
  __REG32 RES_IN_HW				    		:11;
  __REG32               					: 5;
  __REG32 RES_IN_VW				    		:11;
  __REG32               					: 5;
} __vdc_sc_scl_us4_bits;

/* Horizontal Scale UpRegister (SCL0_US5) */
typedef struct {
  __REG32 RES_US_H_RATIO	    		:16;
  __REG32               					:16;
} __vdc_sc_scl_us5_bits;

/* Horizontal Scale Up Initial Phase Register (SCL0_US6) */
typedef struct {
  __REG32 RES_US_HB_INIPHASE  		:12;
  __REG32               					: 4;
  __REG32 RES_US_HT_INIPHASE  		:12;
  __REG32 RES_US_H_INTERPOTYP 		: 1;
  __REG32               					: 3;
} __vdc_sc_scl_us6_bits;

/* Trimming Register (SCL0_US7) */
typedef struct {
  __REG32 RES_VCUT								: 8;
  __REG32 RES_HCUT					  		: 8;
  __REG32               					:16;
} __vdc_sc_scl_us7_bits;

/* Frame Buffer Read Select Register (SCL0_US8) */
typedef struct {
  __REG32 RES_DISP_ON							: 1;
  __REG32               					: 3;
  __REG32 RES_IBUS_SYNC_SEL				: 1;
  __REG32               					:27;
} __vdc_sc_scl_us8_bits;

/* Background Color Register (SCL0_OVR1) */
typedef struct {
  __REG32 RES_BK_COL_B						: 8;
  __REG32 RES_BK_COL_G						: 8;
  __REG32 RES_BK_COL_R						: 8;
  __REG32               					: 8;
} __vdc_sc_scl_ovr1_bits;

/* SCL1 Register Update Control Register (UPDATE) */
typedef struct {
  __REG32 VEN_A										: 1;
  __REG32               					: 3;
  __REG32 VEN_B										: 1;
  __REG32               					:11;
  __REG32 UPDATE_A								: 1;
  __REG32               					: 3;
  __REG32 UPDATE_B								: 1;
  __REG32               					:11;
} __vdc_sc_scl1_update_bits;

/* Writing Mode Register (WR1) */
typedef struct {
  __REG32 RES_BST_MD							: 1;
  __REG32 RES_LOOP								: 1;
  __REG32 RES_MD									: 2;
  __REG32 RES_DS_WR_MD						: 3;
  __REG32 RES_TB_ADD_MOD					: 1;
  __REG32               					: 8;
  __REG32 RES_WRSWA								: 3;
  __REG32               					:13;
} __vdc_sc_scl_wr1_bits;

/* Write Address Register 2T (WR3) */
typedef struct {
  __REG32 RES_FLM_NUM							:10;
  __REG32 												: 6;
  __REG32 RES_LN_OFF							:15;
  __REG32               					: 1;
} __vdc_sc_scl_wr3_bits;

/* Write Address Register 3T (WR4) */
typedef struct {
  __REG32 RES_FLM_OFF							:23;
  __REG32 												: 9;
} __vdc_sc_scl_wr4_bits;

/* Frame Sub-Sampling Register (WR5) */
typedef struct {
  __REG32 RES_WENB								: 1;
  __REG32 												: 3;
  __REG32 RES_FLD_SEL							: 1;
  __REG32 												: 3;
  __REG32 RES_FS_RATE							: 2;
  __REG32 												: 2;
  __REG32 RES_INTER								: 1;
  __REG32 												:19;
} __vdc_sc_scl_wr5_bits;

/* Bit Reduction Register (WR6) */
typedef struct {
  __REG32 RES_BITDEC_ON						: 1;
  __REG32 												: 3;
  __REG32 RES_DTH_ON							: 1;
  __REG32 												:27;
} __vdc_sc_scl_wr6_bits;

/* Write Detection Register (WR7) */
typedef struct {
  __REG32 RES_FLM_CNT							:10;
  __REG32 												: 6;
  __REG32 RES_OVERFLOW						: 1;
  __REG32 												:15;
} __vdc_sc_scl_wr7_bits;

/* Write Address Register 2B (WR9) */
typedef struct {
  __REG32 RES_FLM_NUM_B						:10;
  __REG32 												: 6;
  __REG32 RES_LN_OFF_B						:15;
  __REG32 												: 1;
} __vdc_sc_scl_wr9_bits;

/* Write Address Register 3B (WR10) */
typedef struct {
  __REG32 RES_FLM_OFF_B						:23;
  __REG32 												: 9;
} __vdc_sc_scl_wr10_bits;

/* Write Detection Register B (WR11) */
typedef struct {
  __REG32 RES_FLM_CNT_B						:10;
  __REG32 												:22;
} __vdc_sc_scl_wr11_bits;

/* Status Monitor 1 Register (MON1) */
typedef struct {
  __REG32 												: 8;
  __REG32 PBUF_NUM								: 2;
  __REG32 												:22;
} __vdc_sc_scl_mon1_bits;

/* Pointer Buffer and Field Information Register (PBUF_FLD) */
typedef struct {
  __REG32 FLD_INF0								: 1;
  __REG32 												: 7;
  __REG32 FLD_INF1								: 1;
  __REG32 												: 7;
  __REG32 FLD_INF2								: 1;
  __REG32 												: 7;
  __REG32 FLD_INF3								: 1;
  __REG32 												: 7;
} __vdc_sc_scl_pbuf_fld_bits;

/* Pointer Buffer Control Register (PBUF_CNT) */
typedef struct {
  __REG32 												:16;
  __REG32 PBUF_RST								: 1;
  __REG32 												:15;
} __vdc_sc_scl_pbuf_cnt_bits;

/* Graphics 0 Register Update Control Register (UPDATE) */
typedef struct {
  __REG32 IBUS_VEN								: 1;
  __REG32 												: 3;
  __REG32 P_VEN										: 1;
  __REG32 												: 3;
  __REG32 UPDATE									: 1;
  __REG32 												:23;
} __vdc_gr_update_bits;

/* Frame Buffer Read Control Register (Graphics 0) (FLM_RD) */
typedef struct {
  __REG32 R_ENB										: 1;
  __REG32 												:31;
} __vdc_gr_flm_rd_bits;

/* Frame Buffer Control Register 1 (Graphics 0) (FLM1) */
typedef struct {
  __REG32 BST_MD									: 1;
  __REG32 												: 3;
  __REG32 IMR_FLM_INV							: 1;
  __REG32 												: 3;
  __REG32 FLM_SEL									: 2;
  __REG32 												: 6;
  __REG32 LN_OFF_DIR							: 1;
  __REG32 												:14;
  __REG32 FLD_SEL	 								: 1;
} __vdc_gr_flm1_bits;

/* Frame Buffer Control Register 1 (Graphics 1) (FLM1) */
typedef struct {
  __REG32 BST_MD									: 1;
  __REG32 												: 7;
  __REG32 FLM_SEL									: 2;
  __REG32 												: 6;
  __REG32 LN_OFF_DIR							: 1;
  __REG32 												:14;
  __REG32 FLD_SEL	 								: 1;
} __vdc_gr1_flm1_bits;

/* Frame Buffer Control Register 3 (Graphics 0) (FLM3) */
typedef struct {
  __REG32 FLM_NUM									:10;
  __REG32 												: 6;
  __REG32 LN_OFF									:15;
  __REG32 FLD_NXT									: 1;
} __vdc_gr_flm3_bits;

/* Frame Buffer Control Register 4 (Graphics 0) (FLM4) */
typedef struct {
  __REG32 FLM_OFF									:23;
  __REG32 												: 9;
} __vdc_gr_flm4_bits;

/* Frame Buffer Control Register 5 (Graphics 0) (FLM5) */
typedef struct {
  __REG32 FLM_LOOP								:11;
  __REG32 												: 5;
  __REG32 FLM_LNUM								:11;
  __REG32 												: 5;
} __vdc_gr_flm5_bits;

/* Frame Buffer Control Register 6 (Graphics 0) (FLM6) */
typedef struct {
  __REG32 STA_POS									: 6;
  __REG32 												: 2;
  __REG32 CNV444_MD								: 1;
  __REG32 												: 1;
  __REG32 RDSWA										: 3;
  __REG32 YCC_SWAP								: 3;
  __REG32 HW											:11;
  __REG32 												: 1;
  __REG32 FORMAT									: 4;
} __vdc_gr_flm6_bits;

/* Alpha Blending Control Register 1 (Graphics 0) (AB1) */
typedef struct {
  __REG32 DISP_SEL								: 2;
  __REG32 												: 2;
  __REG32 GRC_DISP_ON							: 1;
  __REG32 												:27;
} __vdc_gr_ab1_bits;

/* Alpha Blending Control Register 1 (Graphics 1) (AB1) */
typedef struct {
  __REG32 DISP_SEL								: 2;
  __REG32 												: 2;
  __REG32 GRC_DISP_ON							: 1;
  __REG32 												: 3;
  __REG32 ARC_DISP_ON							: 1;
  __REG32 												: 3;
  __REG32 ARC_ON									: 1;
  __REG32 												: 1;
  __REG32 ACALC_MD								: 1;
  __REG32 ARC_MUL									: 1;
  __REG32 												:12;
  __REG32 CUS_CON_ON							: 1;
  __REG32 												: 3;
} __vdc_gr1_ab1_bits;

/* Alpha Blending Control Register 2 (Graphics 0) (AB2) */
typedef struct {
  __REG32 GRC_VW									:11;
  __REG32 												: 5;
  __REG32 GRC_VS									:11;
  __REG32 												: 5;
} __vdc_gr_ab2_bits;

/* Alpha Blending Control Register 3 (Graphics 0) (AB3) */
typedef struct {
  __REG32 GRC_HW									:11;
  __REG32 												: 5;
  __REG32 GRC_HS									:11;
  __REG32 												: 5;
} __vdc_gr_ab3_bits;

/* Alpha Blending Control Register 4 (Graphics 1) (AB4) */
typedef struct {
  __REG32 ARC_VW									:11;
  __REG32 												: 5;
  __REG32 ARC_VS									:11;
  __REG32 												: 5;
} __vdc_gr1_ab4_bits;

/* Alpha Blending Control Register 5 (Graphics 1) (AB5) */
typedef struct {
  __REG32 ARC_HW									:11;
  __REG32 												: 5;
  __REG32 ARC_HS									:11;
  __REG32 												: 5;
} __vdc_gr1_ab5_bits;

/* Alpha Blending Control Register 6 (Graphics 1) (AB6) */
typedef struct {
  __REG32 ARC_RATE								: 8;
  __REG32 												: 8;
  __REG32 ARC_HS									: 8;
  __REG32 ARC_MODE								: 1;
  __REG32 												: 7;
} __vdc_gr1_ab6_bits;

/* Alpha Blending Control Register 7 (Graphics 0) (AB7) */
typedef struct {
  __REG32 CK_ON										: 1;
  __REG32 												:31;
} __vdc_gr_ab7_bits;

/* Alpha Blending Control Register 7 (Graphics 1) (AB7) */
typedef struct {
  __REG32 CK_ON										: 1;
  __REG32 												:15;
  __REG32 ARC_DEF									: 8;
  __REG32 												: 8;
} __vdc_gr1_ab7_bits;

/* Alpha Blending Control Register 8 (Graphics 0) (AB8) */
typedef struct {
  __REG32 CK_KR										: 8;
  __REG32 CK_KB										: 8;
  __REG32 CK_KG										: 8;
  __REG32 CK_KCLUT								: 8;
} __vdc_gr_ab8_bits;

/* Alpha Blending Control Register 9 (Graphics 0) (AB9) */
typedef struct {
  __REG32 CK_R										: 8;
  __REG32 CK_B										: 8;
  __REG32 CK_G										: 8;
  __REG32 CK_A	  								: 8;
} __vdc_gr_ab9_bits;

/* Alpha Blending Control Register 10 (Graphics 0) (AB10) */
typedef struct {
  __REG32 R0											: 8;
  __REG32 B0											: 8;
  __REG32 G0											: 8;
  __REG32 A0		  								: 8;
} __vdc_gr_ab10_bits;

/* Alpha Blending Control Register 11 (Graphics 0) (AB11) */
typedef struct {
  __REG32 R1											: 8;
  __REG32 B1											: 8;
  __REG32 G1											: 8;
  __REG32 A1		  								: 8;
} __vdc_gr_ab11_bits;

/* Background Color Control Register (Graphics 0) (BASE) */
typedef struct {
  __REG32 BASE_R									: 8;
  __REG32 BASE_B									: 8;
  __REG32 BASE_G									: 8;
  __REG32 					  						: 8;
} __vdc_gr_base_bits;

/* CLUT Table Control Register (Graphics 0) (CLUT) */
typedef struct {
  __REG32 												:16;
  __REG32 CLT_SEL									: 1;
  __REG32 					  						:15;
} __vdc_gr_clut_bits;

/* Status Monitor Register (Graphics 1) (MON) */
typedef struct {
  __REG32 ARC_ST									: 1;
  __REG32 					  						:31;
} __vdc_gr1_mon_bits;

/* Register Update Control Register in Image Quality Improver (UPDATE) */
typedef struct {
  __REG32 VEN											: 1;
  __REG32 					  						:31;
} __vdc_adj_update_bits;

/* Black Stretch Register (BKSTR_SET) */
typedef struct {
  __REG32 BKSTR_T2								: 5;
  __REG32 					  						: 3;
  __REG32 BKSTR_T1								: 5;
  __REG32 					  						: 3;
  __REG32 BKSTR_D									: 4;
  __REG32 BKSTR_ST								: 4;
  __REG32 BKSTR_ON								: 1;
  __REG32 					  						: 7;
} __vdc_adj_bkstr_set_bits;

/* Enhancer Timing AdjustmentRegister 1 (ENH_TIM1) */
typedef struct {
  __REG32 ENH_DISP_ON							: 1;
  __REG32 					  						: 3;
  __REG32 ENH_MD									: 1;
  __REG32 					  						:27;
} __vdc_adj_enh_tim1_bits;

/* Enhancer Timing AdjustmentRegister 2 (ENH_TIM2) */
typedef struct {
  __REG32 ENH_VW									:11;
  __REG32 					  						: 5;
  __REG32 ENH_VS									:11;
  __REG32 					  						: 5;
} __vdc_adj_enh_tim2_bits;

/* Enhancer Timing AdjustmentRegister 3 (ENH_TIM3) */
typedef struct {
  __REG32 ENH_HW									:11;
  __REG32 					  						: 5;
  __REG32 ENH_HS									:11;
  __REG32 					  						: 5;
} __vdc_adj_enh_tim3_bits;

/* Enhancer Sharpness Register 1 (ENH_SHP1) */
typedef struct {
  __REG32 SHP_H1_CORE							: 7;
  __REG32 					  						: 9;
  __REG32 SHP_H_ON								: 1;
  __REG32 					  						:15;
} __vdc_adj_enh_shp1_bits;

/* Enhancer Sharpness Register 2 (ENH_SHP2) */
typedef struct {
  __REG32 SHP_H1_GAIN_U						: 8;
  __REG32 SHP_H1_GAIN_O						: 8;
  __REG32 SHP_H1_CLIP_U						: 8;
  __REG32 SHP_H1_CLIP_O						: 8;
} __vdc_adj_enh_shp2_bits;

/* Enhancer Sharpness Register 3 (ENH_SHP3) */
typedef struct {
  __REG32 SHP_H2_CORE							: 7;
  __REG32 					  						: 9;
  __REG32 SHP_H2_LPF_SEL					: 1;
  __REG32 												:15;
} __vdc_adj_enh_shp3_bits;

/* Enhancer Sharpness Register 4 (ENH_SHP4) */
typedef struct {
  __REG32 SHP_H2_GAIN_U						: 8;
  __REG32 SHP_H2_GAIN_O						: 8;
  __REG32 SHP_H2_CLIP_U						: 8;
  __REG32 SHP_H2_CLIP_O						: 8;
} __vdc_adj_enh_shp4_bits;

/* Enhancer Sharpness Register 5 (ENH_SHP5) */
typedef struct {
  __REG32 SHP_H3_CORE							: 7;
  __REG32 												:25;
} __vdc_adj_enh_shp5_bits;

/* Enhancer Sharpness Register 5 (ENH_SHP5) */
typedef struct {
  __REG32 SHP_H3_GAIN_U						: 8;
  __REG32 SHP_H3_GAIN_O						: 8;
  __REG32 SHP_H3_CLIP_U						: 8;
  __REG32 SHP_H3_CLIP_O						: 8;
} __vdc_adj_enh_shp6_bits;

/* Enhancer LTI Register 1 (ENH_LTI1) */
typedef struct {
  __REG32 LTI_H2_CORE							: 8;
  __REG32 LTI_H2_GAIN							: 8;
  __REG32 LTI_H2_INC_ZERO					: 8;
  __REG32 LTI_H2_LPF_SEL					: 1;
  __REG32 												: 6;
  __REG32 LTI_H_ON								: 1;
} __vdc_adj_enh_lti1_bits;

/* Enhancer LTI Register 2 (ENH_LTI2) */
typedef struct {
  __REG32 LTI_H4_CORE							: 8;
  __REG32 LTI_H4_GAIN							: 8;
  __REG32 LTI_H4_INC_ZERO					: 8;
  __REG32 LTI_H4_MEDIAN_TAP_SEL		: 1;
  __REG32 												: 7;
} __vdc_adj_enh_lti2_bits;

/* Matrix Mode Register in Image Quality Improver(MTX_MODE) */
typedef struct {
  __REG32 MTX_MD									: 2;
  __REG32 												:30;
} __vdc_adj_mtx_mode_bits;

/* Matrix YG Control Register0 in Image Quality Improver  (MTX_YG_ADJ0) */
typedef struct {
  __REG32 MTX_GG									:11;
  __REG32 												: 5;
  __REG32 MTX_YG									: 8;
  __REG32 												: 8;
} __vdc_adj_mtx_yg_adj_bits;

/* Matrix YG Control Register1 in Image Quality Improver  (MTX_YG_ADJ1) */
typedef struct {
  __REG32 MTX_GR									:11;
  __REG32 												: 5;
  __REG32 MTX_GB									:11;
  __REG32 												: 5;
} __vdc_adj_mtx_yg_adj1_bits;

/* Matrix CBB Control Register0 in Image Quality Improver  (MTX_CBB_ADJ0) */
typedef struct {
  __REG32 MTX_BG									:11;
  __REG32 												: 5;
  __REG32 MTX_B										: 8;
  __REG32 												: 8;
} __vdc_adj_mtx_cbb_adj_bits;

/* Matrix CBB Control Register1 in Image Quality Improver (MTX_CBB_ADJ1) */
typedef struct {
  __REG32 MTX_BR									:11;
  __REG32 												: 5;
  __REG32 MTX_BB									:11;
  __REG32 												: 5;
} __vdc_adj_mtx_cbb_adj1_bits;

/* Matrix CRR Control Register0 in Image Quality Improver  (MTX_CRR_ADJ0) */
typedef struct {
  __REG32 MTX_RG									:11;
  __REG32 												: 5;
  __REG32 MTX_R										: 8;
  __REG32 												: 8;
} __vdc_adj_mtx_crr_adj_bits;

/* Matrix CBB Control Register1 in Image Quality Improver (MTX_CBB_ADJ1) */
typedef struct {
  __REG32 MTX_RR									:11;
  __REG32 												: 5;
  __REG32 MTX_RB									:11;
  __REG32 												: 5;
} __vdc_adj_mtx_crr_adj1_bits;

/* Graphics 2 Register Update Control Register (GR2_UPDATE) */
typedef struct {
  __REG32 IBUS_VEN								: 1;
  __REG32 												: 3;
  __REG32 P_VEN										: 1;
  __REG32 												: 3;
  __REG32 UPDATE									: 1;
  __REG32 												:23;
} __vdc_gr2_update_bits;

/* Frame Buffer Read Control Register (Graphics 2) (GR2_FLM_RD) */
typedef struct {
  __REG32 R_ENB										: 1;
  __REG32 												:31;
} __vdc_gr2_flm_rd_bits;

/* Frame Buffer Control Register 1 (Graphics 2) (GR2_FLM1) */
typedef struct {
  __REG32 BST_MD									: 1;
  __REG32 												: 7;
  __REG32 FLM_SEL									: 2;
  __REG32 												: 6;
  __REG32 LN_OFF_DIR							: 1;
  __REG32 												:14;
  __REG32 FLD_SEL	 								: 1;
} __vdc_gr2_flm1_bits;

/* Frame Buffer Control Register 3 (Graphics 2) (GR2_FLM3) */
typedef struct {
  __REG32 FLM_NUM									:10;
  __REG32 												: 6;
  __REG32 LN_OFF									:15;
  __REG32 												: 1;
} __vdc_gr2_flm3_bits;

/* Frame Buffer Control Register 4 (Graphics 2) (GR2_FLM4) */
typedef struct {
  __REG32 FLM_OFF									:23;
  __REG32 												: 9;
} __vdc_gr2_flm4_bits;

/* Frame Buffer Control Register 5 (Graphics 2) (GR2_FLM5) */
typedef struct {
  __REG32 FLM_LOOP								:11;
  __REG32 												: 5;
  __REG32 FLM_LNUM								:11;
  __REG32 												: 5;
} __vdc_gr2_flm5_bits;

/* Frame Buffer Control Register 6 (Graphics 2) (GR2_FLM6) */
typedef struct {
  __REG32 STA_POS									: 6;
  __REG32 												: 4;
  __REG32 RDSWA										: 3;
  __REG32 												: 3;
  __REG32 HW											:11;
  __REG32 												: 1;
  __REG32 FORMAT									: 4;
} __vdc_gr2_flm6_bits;

/* Alpha Blending Control Register 1 (Graphics 2) (GR2_AB1) */
typedef struct {
  __REG32 DISP_SEL								: 2;
  __REG32 												: 2;
  __REG32 GRC_DISP_ON							: 1;
  __REG32 												: 3;
  __REG32 ARC_DISP_ON							: 1;
  __REG32 												: 3;
  __REG32 ARC_ON									: 1;
  __REG32 												: 1;
  __REG32 ACALC_MD								: 1;
  __REG32 ARC_MUL									: 1;
  __REG32 												:16;
} __vdc_gr2_ab1_bits;

/* Alpha Blending Control Register 2 (Graphics 2) (GR2_AB2) */
typedef struct {
  __REG32 GRC_VW									:11;
  __REG32 												: 5;
  __REG32 GRC_VS									:11;
  __REG32 												: 5;
} __vdc_gr2_ab2_bits;

/* Alpha Blending Control Register 3 (Graphics 2) (GR2_AB3) */
typedef struct {
  __REG32 GRC_HW									:11;
  __REG32 												: 5;
  __REG32 GRC_HS									:11;
  __REG32 												: 5;
} __vdc_gr2_ab3_bits;

/* Alpha Blending Control Register 4 (Graphics 2) (GR2_AB4) */
typedef struct {
  __REG32 ARC_VW									:11;
  __REG32 												: 5;
  __REG32 ARC_VS									:11;
  __REG32 												: 5;
} __vdc_gr2_ab4_bits;

/* Alpha Blending Control Register 5 (Graphics 2) (GR2_AB5) */
typedef struct {
  __REG32 ARC_HW									:11;
  __REG32 												: 5;
  __REG32 ARC_HS									:11;
  __REG32 												: 5;
} __vdc_gr2_ab5_bits;

/* Alpha Blending Control Register 6 (Graphics 2) (GR2_AB6) */
typedef struct {
  __REG32 ARC_RATE								: 8;
  __REG32 												: 8;
  __REG32 ARC_COEF								: 8;
  __REG32 ARC_MODE								: 1;
  __REG32 												: 7;
} __vdc_gr2_ab6_bits;

/* Alpha Blending Control Register 7 (Graphics 2) (GR2_AB7) */
typedef struct {
  __REG32 CK_ON										: 1;
  __REG32 												:15;
  __REG32 ARC_DEF									: 8;
  __REG32 												: 8;
} __vdc_gr2_ab7_bits;

/* Alpha Blending Control Register 8 (Graphics 2) (GR2_AB8) */
typedef struct {
  __REG32 CK_KR										: 8;
  __REG32 CK_KB										: 8;
  __REG32 CK_KG										: 8;
  __REG32 CK_KCLUT								: 8;
} __vdc_gr2_ab8_bits;

/* Alpha Blending Control Register 9 (Graphics 2) (GR2_AB9) */
typedef struct {
  __REG32 CK_R										: 8;
  __REG32 CK_B										: 8;
  __REG32 CK_G										: 8;
  __REG32 CK_A	  								: 8;
} __vdc_gr2_ab9_bits;

/* Alpha Blending Control Register 10 (Graphics 2) (GR2_AB10) */
typedef struct {
  __REG32 R0											: 8;
  __REG32 B0											: 8;
  __REG32 G0											: 8;
  __REG32 A0		  								: 8;
} __vdc_gr2_ab10_bits;

/* Alpha Blending Control Register 11 (Graphics 2) (GR2_AB11) */
typedef struct {
  __REG32 R1											: 8;
  __REG32 B1											: 8;
  __REG32 G1											: 8;
  __REG32 A1		  								: 8;
} __vdc_gr2_ab11_bits;

/* Background Color Control Register (Graphics 2) (GR2_BASE) */
typedef struct {
  __REG32 BASE_R									: 8;
  __REG32 BASE_B									: 8;
  __REG32 BASE_G									: 8;
  __REG32 					  						: 8;
} __vdc_gr2_base_bits;

/* CLUT Table Control Register (Graphics 2) (GR2_CLUT) */
typedef struct {
  __REG32 												:16;
  __REG32 CLT_SEL									: 1;
  __REG32 					  						:15;
} __vdc_gr2_clut_bits;

/* Status Monitor Register (Graphics 2) (MON) */
typedef struct {
  __REG32 ARC_ST									: 1;
  __REG32 					  						:31;
} __vdc_gr2_mon_bits;

/* Graphics 3 Register Update Control Register (GR3_UPDATE) */
typedef struct {
  __REG32 IBUS_VEN								: 1;
  __REG32 					  						: 3;
  __REG32 P_VEN										: 1;
  __REG32 					  						: 3;
  __REG32 UPDATE									: 1;
  __REG32 					  						:23;
} __vdc_gr3_update_bits;

/* Frame Buffer Read Control Register (Graphics 3) (GR3_FLM_RD) */
typedef struct {
  __REG32 R_ENB										: 1;
  __REG32 												:31;
} __vdc_gr3_flm_rd_bits;

/* Frame Buffer Control Register 1 (Graphics 3) (GR3_FLM1) */
typedef struct {
  __REG32 BST_MD									: 1;
  __REG32 												: 7;
  __REG32 FLM_SEL									: 2;
  __REG32 												: 6;
  __REG32 LN_OFF_DIR							: 1;
  __REG32 												:15;
} __vdc_gr3_flm1_bits;

/* Frame Buffer Control Register 3 (Graphics 3) (GR3_FLM3) */
typedef struct {
  __REG32 FLM_NUM									:10;
  __REG32 												: 6;
  __REG32 LN_OFF									:15;
  __REG32 												: 1;
} __vdc_gr3_flm3_bits;

/* Frame Buffer Control Register 4 (Graphics 3) (GR3_FLM4) */
typedef struct {
  __REG32 FLM_OFF									:23;
  __REG32 												: 9;
} __vdc_gr3_flm4_bits;

/* Frame Buffer Control Register 5 (Graphics 3) (GR3_FLM5) */
typedef struct {
  __REG32 FLM_LOOP								:11;
  __REG32 												: 5;
  __REG32 FLM_LNUM								:11;
  __REG32 												: 5;
} __vdc_gr3_flm5_bits;

/* Frame Buffer Control Register 6 (Graphics 3) (GR3_FLM6) */
typedef struct {
  __REG32 STA_POS									: 6;
  __REG32 												: 4;
  __REG32 RDSWA										: 3;
  __REG32 												: 3;
  __REG32 HW											:11;
  __REG32 												: 1;
  __REG32 FORMAT									: 4;
} __vdc_gr3_flm6_bits;

/* Alpha Blending Control Register 1 (Graphics 3) (GR3_AB1) */
typedef struct {
  __REG32 DISP_SEL								: 2;
  __REG32 												: 2;
  __REG32 GRC_DISP_ON							: 1;
  __REG32 												: 3;
  __REG32 ARC_DISP_ON							: 1;
  __REG32 												: 3;
  __REG32 ARC_ON									: 1;
  __REG32 												: 1;
  __REG32 ACALC_MD								: 1;
  __REG32 ARC_MUL									: 1;
  __REG32 												:16;
} __vdc_gr3_ab1_bits;

/* Alpha Blending Control Register 2 (Graphics 3) (GR3_AB2) */
typedef struct {
  __REG32 GRC_VW									:11;
  __REG32 												: 5;
  __REG32 GRC_VS									:11;
  __REG32 												: 5;
} __vdc_gr3_ab2_bits;

/* Alpha Blending Control Register 3 (Graphics 3) (GR3_AB3) */
typedef struct {
  __REG32 GRC_HW									:11;
  __REG32 												: 5;
  __REG32 GRC_HS									:11;
  __REG32 												: 5;
} __vdc_gr3_ab3_bits;

/* Alpha Blending Control Register 4 (Graphics 3) (GR3_AB4) */
typedef struct {
  __REG32 ARC_VW									:11;
  __REG32 												: 5;
  __REG32 ARC_VS									:11;
  __REG32 												: 5;
} __vdc_gr3_ab4_bits;

/* Alpha Blending Control Register 5 (Graphics 3) (GR3_AB5) */
typedef struct {
  __REG32 ARC_HW									:11;
  __REG32 												: 5;
  __REG32 ARC_HS									:11;
  __REG32 												: 5;
} __vdc_gr3_ab5_bits;

/* Alpha Blending Control Register 6 (Graphics 3) (GR3_AB6) */
typedef struct {
  __REG32 ARC_RATE								: 8;
  __REG32 												: 8;
  __REG32 ARC_COEF								: 8;
  __REG32 ARC_MODE								: 1;
  __REG32 												: 7;
} __vdc_gr3_ab6_bits;

/* Alpha Blending Control Register 7 (Graphics 3) (GR3_AB7) */
typedef struct {
  __REG32 CK_ON										: 1;
  __REG32 												:15;
  __REG32 ARC_DEF									: 8;
  __REG32 												: 8;
} __vdc_gr3_ab7_bits;

/* Alpha Blending Control Register 8 (Graphics 3) (GR3_AB8) */
typedef struct {
  __REG32 CK_KR										: 8;
  __REG32 CK_KB										: 8;
  __REG32 CK_KG										: 8;
  __REG32 CK_KCLUT								: 8;
} __vdc_gr3_ab8_bits;

/* Alpha Blending Control Register 9 (Graphics 3) (GR3_AB9) */
typedef struct {
  __REG32 CK_R										: 8;
  __REG32 CK_B										: 8;
  __REG32 CK_G										: 8;
  __REG32 CK_A	  								: 8;
} __vdc_gr3_ab9_bits;

/* Alpha Blending Control Register 10 (Graphics 3) (GR3_AB10) */
typedef struct {
  __REG32 R0											: 8;
  __REG32 B0											: 8;
  __REG32 G0											: 8;
  __REG32 A0		  								: 8;
} __vdc_gr3_ab10_bits;

/* Alpha Blending Control Register 11 (Graphics 3) (GR3_AB11) */
typedef struct {
  __REG32 R1											: 8;
  __REG32 B1											: 8;
  __REG32 G1											: 8;
  __REG32 A1		  								: 8;
} __vdc_gr3_ab11_bits;

/* Background Color Control Register (Graphics 3) (GR3_BASE) */
typedef struct {
  __REG32 BASE_R									: 8;
  __REG32 BASE_B									: 8;
  __REG32 BASE_G									: 8;
  __REG32 					  						: 8;
} __vdc_gr3_base_bits;

/* CLUT Table and Interrupt Control Register (Graphics 3) (GR3_CLUT_INT) */
typedef struct {
  __REG32 LINE										:11;
  __REG32 					  						: 5;
  __REG32 CLT_SEL									: 1;
  __REG32 					  						:15;
} __vdc_gr3_clut_int_bits;

/* Status Monitor Register (Graphics 3) (GR3_MON) */
typedef struct {
  __REG32 ARC_ST									: 1;
  __REG32 					  						:31;
} __vdc_gr3_mon_bits;

/* VIN Synthesizer Register Update Control Register (GR_VIN_UPDATE) */
typedef struct {
  __REG32 					  						: 4;
  __REG32 VIN_P_VEN								: 1;
  __REG32 					  						: 3;
  __REG32 VIN_UPDATE							: 1;
  __REG32 					  						:23;
} __vdc_gr_vin_update_bits;

/* Alpha Blending Control Register 1 (VIN Synthesizer) (GR_VIN_AB1) */
typedef struct {
  __REG32 VIN_DISP_SEL						: 2;
  __REG32 VIN_SCL_UND_SEL					: 1;
  __REG32 					  						: 1;
  __REG32 VIN_GRC_DISP_ON					: 1;
  __REG32 					  						: 3;
  __REG32 VIN_ARC_DISP_ON					: 1;
  __REG32 					  						: 3;
  __REG32 VIN_ARC_ON							: 1;
  __REG32 					  						:19;
} __vdc_gr_vin_ab1_bits;

/* Alpha Blending Control Register 2 (VIN Synthesizer) (GR_VIN_AB2) */
typedef struct {
  __REG32 VIN_GRC_VW							:11;
  __REG32 					  						: 5;
  __REG32 VIN_GRC_VS							:11;
  __REG32 					  						: 5;
} __vdc_gr_vin_ab2_bits;

/* Alpha Blending Control Register 3 (VIN Synthesizer) (GR_VIN_AB3) */
typedef struct {
  __REG32 VIN_GRC_HW							:11;
  __REG32 					  						: 5;
  __REG32 VIN_GRC_HS							:11;
  __REG32 					  						: 5;
} __vdc_gr_vin_ab3_bits;

/* Alpha Blending Control Register 4 (VIN Synthesizer) (GR_VIN_AB4) */
typedef struct {
  __REG32 VIN_ARC_VW							:11;
  __REG32 					  						: 5;
  __REG32 VIN_ARC_VS							:11;
  __REG32 					  						: 5;
} __vdc_gr_vin_ab4_bits;

/* Alpha Blending Control Register 5 (VIN Synthesizer) (GR_VIN_AB5) */
typedef struct {
  __REG32 VIN_ARC_HW							:11;
  __REG32 					  						: 5;
  __REG32 VIN_ARC_HS							:11;
  __REG32 					  						: 5;
} __vdc_gr_vin_ab5_bits;

/* Alpha Blending Control Register 6 (VIN Synthesizer) (GR_VIN_AB6) */
typedef struct {
  __REG32 VIN_ARC_RATE						: 8;
  __REG32 					  						: 8;
  __REG32 VIN_ARC_COEF						: 8;
  __REG32 VIN_ARC_MODE						: 1;
  __REG32 					  						: 7;
} __vdc_gr_vin_ab6_bits;

/* Alpha Blending Control Register 7 (VIN Synthesizer) (GR_VIN_AB7) */
typedef struct {
  __REG32 					  						:16;
  __REG32 VIN_ARC_DEF							: 8;
  __REG32 					  						: 8;
} __vdc_gr_vin_ab7_bits;

/* Background Color Control Register (VIN Synthesizer) (GR_IN_BASE) */
typedef struct {
  __REG32 VIN_BASE_R							: 8;
  __REG32 VIN_BASE_B							: 8;
  __REG32 VIN_BASE_G 							: 8;
  __REG32 					  						: 8;
} __vdc_gr_vin_base_bits;

/* Status Monitor Register (VIN Synthesizer) (GR_VIN_MON) */
typedef struct {
  __REG32 VIN_ARC_ST							: 1;
  __REG32 					  						:31;
} __vdc_gr_vin_mon_bits;

/* SCL0 Register Update Control Register (UPDATE) */
typedef struct {
  __REG32 VEN_A										: 1;
  __REG32 					  						: 3;
  __REG32 VEN_B										: 1;
  __REG32 					  						: 3;
  __REG32 UPDATE									: 1;
  __REG32 					  						: 3;
  __REG32 VEN_C										: 1;
  __REG32 VEN_D										: 1;
  __REG32 					  						:18;
} __vdc_oir_scl_update_bits;

/* Mask Control Register (FRC1) */
typedef struct {
  __REG32 VMASK_ON								: 1;
  __REG32 					  						:15;
  __REG32 VMASK										:16;
} __vdc_oir_scl_frc1_bits;

/* Missing Vsync Compensation Control Register (FRC2) */
typedef struct {
  __REG32 VLACK_ON								: 1;
  __REG32 					  						:15;
  __REG32 VLACK										:16;
} __vdc_oir_scl_frc2_bits;

/* Output Sync Select Register (FRC3) */
typedef struct {
  __REG32 VS_SEL									: 1;
  __REG32 					  						:15;
  __REG32 EN											: 1;
  __REG32 					  						:15;
} __vdc_oir_scl_frc3_bits;

/* Free-Running Period Control Register (FRC4) */
typedef struct {
  __REG32 FH											:11;
  __REG32 					  						: 5;
  __REG32 FV											:11;
  __REG32 					  						: 5;
} __vdc_oir_scl_frc4_bits;

/* Output Delay Control Register (FRC5) */
typedef struct {
  __REG32 VSDLY										: 8;
  __REG32 					  						:24;
} __vdc_oir_scl_frc5_bits;

/* Full-Screen Vertical Size Register (FRC6) */
typedef struct {
  __REG32 F_VW										:11;
  __REG32 					  						: 5;
  __REG32 F_VS										:11;
  __REG32 					  						: 5;
} __vdc_oir_scl_frc6_bits;

/* Full-Screen Horizontal Size Register (FRC7) */
typedef struct {
  __REG32 F_HW										:11;
  __REG32 					  						: 5;
  __REG32 F_HS										:11;
  __REG32 					  						: 5;
} __vdc_oir_scl_frc7_bits;

/* Scaling-Down Control Register (DS1) */
typedef struct {
  __REG32 DS_H_ON									: 1;
  __REG32 					  						: 3;
  __REG32 DS_V_ON									: 1;
  __REG32 					  						:27;
} __vdc_oir_scl_ds1_bits;

/* Vertical Capture Size Register (DS2) */
typedef struct {
  __REG32 VW											:11;
  __REG32 					  						: 5;
  __REG32 VS											:11;
  __REG32 					  						: 5;
} __vdc_oir_scl_ds2_bits;

/* Horizontal Capture Size Register (DS3) */
typedef struct {
  __REG32 HW											:11;
  __REG32 					  						: 5;
  __REG32 HS											:11;
  __REG32 					  						: 5;
} __vdc_oir_scl_ds3_bits;

/* Scaling-Down Control Block Output Size Register (DS7) */
typedef struct {
  __REG32 OUT_HW									:11;
  __REG32 					  						: 5;
  __REG32 OUT_VW									:11;
  __REG32 					  						: 5;
} __vdc_oir_scl_ds7_bits;

/* Scaling-Up Control Register (US1) */
typedef struct {
  __REG32 US_H_ON									: 1;
  __REG32 					  						: 3;
  __REG32 US_V_ON									: 1;
  __REG32 					  						:27;
} __vdc_oir_scl_us1_bits;

/* Output Image Vertical Size Register (US2) */
typedef struct {
  __REG32 P_VW										:11;
  __REG32 					  						: 5;
  __REG32 P_VS										:11;
  __REG32 					  						: 5;
} __vdc_oir_scl_us2_bits;

/* Output Image Horizontal Size Register (US3) */
typedef struct {
  __REG32 P_HW										:11;
  __REG32 					  						: 5;
  __REG32 P_HS										:11;
  __REG32 					  						: 5;
} __vdc_oir_scl_us3_bits;

/* Frame Buffer Read Select Register (US8) */
typedef struct {
  __REG32 					  						: 4;
  __REG32 IBUS_SYNC_SEL						: 1;
  __REG32 					  						:27;
} __vdc_oir_scl_us8_bits;

/* Background Color Register (OVR1) */
typedef struct {
  __REG32 BK_COL_B								: 8;
  __REG32 BK_COL_G								: 8;
  __REG32 BK_COL_R								: 8;
  __REG32 					  						: 8;
} __vdc_oir_scl_ovr1_bits;

/* Background Color Register (OVR1) */
typedef struct {
  __REG32 VEN_A										: 1;
  __REG32 					  						: 3;
  __REG32 VEN_B										: 1;
  __REG32 					  						:11;
  __REG32 UPDATE_A								: 1;
  __REG32 					  						:15;
} __vdc_oir_scl1_update_bits;

/* Writing Mode Register (WR1) */
typedef struct {
  __REG32 BST_MD									: 1;
  __REG32 LOOP										: 1;
  __REG32 MD											: 2;
  __REG32 					  						:12;
  __REG32 WRSWA										: 3;
  __REG32 					  						:13;
} __vdc_oir_scl_wr1_bits;

/* Write Address Register 2 (WR3) */
typedef struct {
  __REG32 FLM_NUM									:10;
  __REG32 					  						: 6;
  __REG32 LN_OFF									:15;
  __REG32 					  						: 1;
} __vdc_oir_scl_wr3_bits;

/* Write Address Register 3 (WR4) */
typedef struct {
  __REG32 FLM_OFF									:23;
  __REG32 					  						: 9;
} __vdc_oir_scl_wr4_bits;

/* Frame Sub-Sampling Register (WR5) */
typedef struct {
  __REG32 WENB										: 1;
  __REG32 					  						: 7;
  __REG32 FS_RATE									: 2;
  __REG32 					  						: 2;
  __REG32 INTER										: 1;
  __REG32 					  						:19;
} __vdc_oir_scl_wr5_bits;

/* Bit Reduction Register (WR6) */
typedef struct {
  __REG32 BITDEC_ON								: 1;
  __REG32 					  						: 3;
  __REG32 DTH_ON									: 1;
  __REG32 					  						:27;
} __vdc_oir_scl_wr6_bits;

/* Write Detection Register (WR7) */
typedef struct {
  __REG32 FLM_CNT									:10;
  __REG32 					  						: 6;
  __REG32 OVERFLOW								: 1;
  __REG32 					  						:15;
} __vdc_oir_scl_wr7_bits;

/* Graphics (OIR) Register Update Control Register (UPDATE) */
typedef struct {
  __REG32 IBUS_VEN								: 1;
  __REG32 					  						: 3;
  __REG32 P_VEN										: 1;
  __REG32 					  						: 3;
  __REG32 UPDATE									: 1;
  __REG32 					  						:23;
} __vdc_gr_oir_update_bits;

/* Frame Buffer Read Control Register (Graphics (OIR)) (FLM_RD) */
typedef struct {
  __REG32 R_ENB										: 1;
  __REG32 					  						:31;
} __vdc_gr_oir_flm_rd_bits;

/* Frame Buffer Control Register 1 (Graphics (OIR)) (FLM1) */
typedef struct {
  __REG32 BST_MD									: 1;
  __REG32 					  						: 3;
  __REG32 IMR_FLM_INV							: 1;
  __REG32 					  						: 3;
  __REG32 FLM_SEL									: 2;
  __REG32 					  						: 6;
  __REG32 LN_OFF_DIR							: 1;
  __REG32 					  						:15;
} __vdc_gr_oir_flm1_bits;

/* Frame Buffer Control Register 3 (Graphics (OIR)) (FLM3) */
typedef struct {
  __REG32 FLM_NUM									:10;
  __REG32 					  						: 6;
  __REG32 LN_OFF									:15;
  __REG32 					  						: 1;
} __vdc_gr_oir_flm3_bits;

/* Frame Buffer Control Register 4 (Graphics (OIR)) (FLM4) */
typedef struct {
  __REG32 FLM_OFF									:23;
  __REG32 					  						: 9;
} __vdc_gr_oir_flm4_bits;

/* Frame Buffer Control Register 5 (Graphics (OIR)) (FLM5) */
typedef struct {
  __REG32 FLM_LOOP								:11;
  __REG32 					  						: 5;
  __REG32 FLM_LNUM								:11;
  __REG32 					  						: 5;
} __vdc_gr_oir_flm5_bits;

/* Frame Buffer Control Register 6 (Graphics (OIR)) (FLM6) */
typedef struct {
  __REG32 STA_POS									: 6;
  __REG32 					  						: 4;
  __REG32 RDSWA										: 3;
  __REG32 HW											:13;
  __REG32 					  						: 2;
  __REG32 FORMAT									: 4;
} __vdc_gr_oir_flm6_bits;

/* Alpha Blending Control Register 1 (Graphics (OIR)) (AB1) */
typedef struct {
  __REG32 DISP_SEL								: 2;
  __REG32 					  						: 2;
  __REG32 GRC_DISP_ON							: 1;
  __REG32 HW											:27;
} __vdc_gr_oir_ab1_bits;

/* Alpha Blending Control Register 2 (Graphics (OIR)) (AB2) */
typedef struct {
  __REG32 GRC_VW									:11;
  __REG32 					  						: 5;
  __REG32 GRC_VS									:11;
  __REG32 					  						: 5;
} __vdc_gr_oir_ab2_bits;

/* Alpha Blending Control Register 3 (Graphics (OIR)) (AB3) */
typedef struct {
  __REG32 GRC_HW									:11;
  __REG32 					  						: 5;
  __REG32 GRC_HS									:11;
  __REG32 					  						: 5;
} __vdc_gr_oir_ab3_bits;

/* Alpha Blending Control Register 7 (Graphics (OIR)) (AB7) */
typedef struct {
  __REG32 CK_ON									: 1;
  __REG32 					  					:31;
} __vdc_gr_oir_ab7_bits;

/* Alpha Blending Control Register 8 (Graphics (OIR)) (AB8) */
typedef struct {
  __REG32 CK_KR									: 8;
  __REG32 CK_KB									: 8;
  __REG32 CK_KG									: 8;
  __REG32 CK_KCLUT							: 8;
} __vdc_gr_oir_ab8_bits;

/* Alpha Blending Control Register 9 (Graphics (OIR)) (AB9) */
typedef struct {
  __REG32 CK_R										: 8;
  __REG32 CK_B										: 8;
  __REG32 CK_G										: 8;
  __REG32 CK_A										: 8;
} __vdc_gr_oir_ab9_bits;

/* Alpha Blending Control Register 10 (Graphics (OIR)) (AB10) */
typedef struct {
  __REG32 R0											: 8;
  __REG32 B0											: 8;
  __REG32 G0											: 8;
  __REG32 A0											: 8;
} __vdc_gr_oir_ab10_bits;

/* Alpha Blending Control Register 11 (Graphics (OIR)) (AB11) */
typedef struct {
  __REG32 R1											: 8;
  __REG32 B1											: 8;
  __REG32 G1											: 8;
  __REG32 A1											: 8;
} __vdc_gr_oir_ab11_bits;

/* Background Color Control Register (Graphics (OIR)) (BASE) */
typedef struct {
  __REG32 BASE_R									: 8;
  __REG32 BASE_B									: 8;
  __REG32 BASE_G									: 8;
  __REG32 												: 8;
} __vdc_gr_oir_base_bits;

/* CLUT Table Control Register (Graphics (OIR)) (CLUT) */
typedef struct {
  __REG32 LINE										: 9;
  __REG32 												: 7;
  __REG32 CLT_SEL									: 1;
  __REG32 												:15;
} __vdc_gr_oir_clut_bits;

/* Status Monitor Register (MON) */
typedef struct {
  __REG32 												:16;
  __REG32 LIN_STAT								:11;
  __REG32 												: 5;
} __vdc_gr_oir_mon_bits;

/* Register Update Control Register in Gamma Correction Block  (UPDATE) */
typedef struct {
  __REG32 VEN											: 1;
  __REG32 					  						:31;
} __vdc_gam_update_bits;

/* Function Switch Register in Gamma Correction Block (SW) */
typedef struct {
  __REG32 ON											: 1;
  __REG32 					  						:31;
} __vdc_gam_sw_bits;

/* Table Setting Register in Gamma Correction Block (LUT1  to LUT16) */
typedef struct {
  __REG32 LUT_L										:11;
  __REG32 					  						: 5;
  __REG32 LUT_H										:11;
  __REG32 					  						: 5;
} __vdc_gam_lut_bits;

/* Area Setting Register in Gamma Correction Block (AREA1) */
typedef struct {
  __REG32 TH_03							: 8;
  __REG32 TH_02							: 8;
  __REG32 TH_01							: 8;
  __REG32 					  						: 8;
} __vdc_gam_area1_bits;

/* Area Setting Register in Gamma Correction Block (AREA2) */
typedef struct {
  __REG32 TH_07							: 8;
  __REG32 TH_06							: 8;
  __REG32 TH_05							: 8;
  __REG32 TH_04							: 8;
} __vdc_gam_area2_bits;

/* Area Setting Register in Gamma Correction Block (AREA3) */
typedef struct {
  __REG32 TH_11							: 8;
  __REG32 TH_10							: 8;
  __REG32 TH_07							: 8;
  __REG32 TH_08							: 8;
} __vdc_gam_area3_bits;

/* Area Setting Register in Gamma Correction Block (AREA4) */
typedef struct {
  __REG32 TH_15							: 8;
  __REG32 TH_14							: 8;
  __REG32 TH_13							: 8;
  __REG32 TH_12							: 8;
} __vdc_gam_area4_bits;

/* Area Setting Register in Gamma Correction Block (AREA5) */
typedef struct {
  __REG32 TH_19							: 8;
  __REG32 TH_18							: 8;
  __REG32 TH_17							: 8;
  __REG32 TH_16							: 8;
} __vdc_gam_area5_bits;

/* Area Setting Register in Gamma Correction Block (AREA6) */
typedef struct {
  __REG32 TH_23							: 8;
  __REG32 TH_22							: 8;
  __REG32 TH_21							: 8;
  __REG32 TH_20							: 8;
} __vdc_gam_area6_bits;

/* Area Setting Register in Gamma Correction Block (AREA7) */
typedef struct {
  __REG32 TH_27							: 8;
  __REG32 TH_26							: 8;
  __REG32 TH_25							: 8;
  __REG32 TH_24							: 8;
} __vdc_gam_area7_bits;

/* Area Setting Register in Gamma Correction Block (AREA8) */
typedef struct {
  __REG32 TH_31							: 8;
  __REG32 TH_30							: 8;
  __REG32 TH_29							: 8;
  __REG32 TH_28							: 8;
} __vdc_gam_area8_bits;

/* TCON Register Update Control Register (TCON_UPDATE) */
typedef struct {
  __REG32 TCON_VEN								: 1;
  __REG32 												:31;
} __vdc_tcon_update_bits;

/* TCON Reference Timing Setting Register (TCON_TIM) */
typedef struct {
  __REG32 TCON_OFFSET							:11;
  __REG32 												: 5;
  __REG32 TCON_HALF								:11;
  __REG32 												: 5;
} __vdc_tcon_tim_bits;

/* TCON Vertical Timing Setting Register A1 (TCON_TIM_STVA1) */
typedef struct {
  __REG32 TCON_STVA_VW						:11;
  __REG32 												: 5;
  __REG32 TCON_STVA_VS						:11;
  __REG32 												: 5;
} __vdc_tcon_tim_stva1_bits;

/* TCON Vertical Timing Setting Register A2 (TCON_TIM_STVA2) */
typedef struct {
  __REG32 TCON_STVA_SEL						: 3;
  __REG32 												: 1;
  __REG32 TCON_STVA_INV						: 1;
  __REG32 												:27;
} __vdc_tcon_tim_stva2_bits;

/* TCON Vertical Timing Setting Register B1 (TCON_TIM_STVB1) */
typedef struct {
  __REG32 TCON_STVB_VW						:11;
  __REG32 												: 5;
  __REG32 TCON_STVB_VS						:11;
  __REG32 												: 5;
} __vdc_tcon_tim_stvb1_bits;

/* TCON Vertical Timing Setting Register B2 (TCON_TIM_STVB2) */
typedef struct {
  __REG32 TCON_STVB_SEL						: 3;
  __REG32 												: 1;
  __REG32 TCON_STVB_INV						: 1;
  __REG32 												:27;
} __vdc_tcon_tim_stvb2_bits;

/* TCON Horizontal Timing Setting Register STH1 (TCON_TIM_STH1) */
typedef struct {
  __REG32 TCON_STH_HW							:11;
  __REG32 												: 5;
  __REG32 TCON_STH_HS							:11;
  __REG32 												: 5;
} __vdc_tcon_tim_sth1_bits;

/* TCON Horizontal Timing Setting Register STH2 (TCON_TIM_STH2) */
typedef struct {
  __REG32 TCON_STH_SEL						: 3;
  __REG32 												: 1;
  __REG32 TCON_STH_INV						: 1;
  __REG32 												: 3;
  __REG32 TCON_STH_HS_SEL					: 1;
  __REG32 												:23;
} __vdc_tcon_tim_sth2_bits;

/* TCON Horizontal Timing Setting Register STB1 (TCON_TIM_STB1) */
typedef struct {
  __REG32 TCON_STB_HW							:11;
  __REG32 												: 5;
  __REG32 TCON_STB_HS							:11;
  __REG32 												: 5;
} __vdc_tcon_tim_stb1_bits;

/* TCON Horizontal Timing Setting Register STB2 (TCON_TIM_STB2) */
typedef struct {
  __REG32 TCON_STB_SEL						: 3;
  __REG32 												: 1;
  __REG32 TCON_STB_INV						: 1;
  __REG32 												: 3;
  __REG32 TCON_STB_HS_SE					: 1;
  __REG32 												:23;
} __vdc_tcon_tim_stb2_bits;

/* TCON Horizontal Timing Setting Register CPV1 (TCON_TIM_CPV1) */
typedef struct {
  __REG32 TCON_CPV_HW							:11;
  __REG32 												: 5;
  __REG32 TCON_CPV_HS							:11;
  __REG32 												: 5;
} __vdc_tcon_tim_cpv1_bits;

/* TCON Horizontal Timing Setting Register CPV2 (TCON_TIM_CPV2) */
typedef struct {
  __REG32 TCON_CPV_SEL						: 3;
  __REG32 												: 1;
  __REG32 TCON_CPV_INV						: 1;
  __REG32 												: 3;
  __REG32 TCON_CPV_HS_SEL					: 1;
  __REG32 												:23;
} __vdc_tcon_tim_cpv2_bits;

/* TCON Horizontal Timing Setting Register POLA1 (TCON_TIM_POLA1) */
typedef struct {
  __REG32 TCON_POLA_HW						:11;
  __REG32 												: 5;
  __REG32 TCON_POLA_HS						:11;
  __REG32 												: 5;
} __vdc_tcon_tim_pola1_bits;

/* TCON Horizontal Timing Setting Register POLA2 (TCON_TIM_POLA2) */
typedef struct {
  __REG32 TCON_POLA_SEL						: 3;
  __REG32 												: 1;
  __REG32 TCON_POLA_INV						: 1;
  __REG32 												: 3;
  __REG32 TCON_POLA_HS_SEL				: 1;
  __REG32 												: 3;
  __REG32 TCON_POLA_MD						: 2;
  __REG32 												:18;
} __vdc_tcon_tim_pola2_bits;

/* TCON Horizontal Timing Setting Register POLB1 (TCON_TIM_POLB1) */
typedef struct {
  __REG32 TCON_POLB_HW						:11;
  __REG32 												: 5;
  __REG32 TCON_POLB_HS						:11;
  __REG32 												: 5;
} __vdc_tcon_tim_polb1_bits;

/* TCON Horizontal Timing Setting Register POLB2 (TCON_TIM_POLB2) */
typedef struct {
  __REG32 TCON_POLB_SEL						: 3;
  __REG32 												: 1;
  __REG32 TCON_POLB_INV						: 1;
  __REG32 												: 3;
  __REG32 TCON_POLB_HS_SEL				: 1;
  __REG32 												: 3;
  __REG32 TCON_POLB_MD						: 2;
  __REG32 												:18;
} __vdc_tcon_tim_polb2_bits;

/* TCON Data Enable Polarity Setting Register (TCON_TIM_DE) */
typedef struct {
  __REG32 TCON_DE_INV							: 1;
  __REG32 												:31;
} __vdc_tcon_tim_de_bits;

/* Register Update Control Register in OutputController (OUT_UPDATE) */
typedef struct {
  __REG32 OUTCNT_VEN							: 1;
  __REG32 												:31;
} __vdc_tcon_out_update_bits;

/* Output Interface Register (OUT_SET) */
typedef struct {
  __REG32 OUT_PHASE								: 2;
  __REG32 												: 2;
  __REG32 OUT_DIR_SEL							: 1;
  __REG32 												: 3;
  __REG32 OUT_FRQ_SEL							: 2;
  __REG32 												: 2;
  __REG32 OUT_FORMAT							: 2;
  __REG32 												:10;
  __REG32 OUT_SWAP_ON							: 1;
  __REG32 												: 3;
  __REG32 OUT_ENDIAN_ON						: 1;
  __REG32 												: 3;
} __vdc_tcon_out_set_bits;

/* Brightness (DC) Correction Register 1 (OUT_BRIGHT1) */
typedef struct {
  __REG32 PBRT_G									:10;
  __REG32 												:22;
} __vdc_tcon_out_bright1_bits;

/* Brightness (DC) Correction Register 2 (OUT_BRIGHT2) */
typedef struct {
  __REG32 PBRT_R									:10;
  __REG32 												: 6;
  __REG32 PBRT_B									:10;
  __REG32 												: 6;
} __vdc_tcon_out_bright2_bits;

/* Contrast (Gain) Correction Register (OUT_CONTRAST) */
typedef struct {
  __REG32 CONT_R									: 8;
  __REG32 CONT_B									: 8;
  __REG32 CONT_G									: 8;
  __REG32 												: 8;
} __vdc_tcon_out_contrast_bits;

/* Panel Dither Register (OUT_PDTHA) */
typedef struct {
  __REG32 PDTH_PD									: 2;
  __REG32 												: 2;
  __REG32 PDTH_PC									: 2;
  __REG32 												: 2;
  __REG32 PDTH_PB									: 2;
  __REG32 												: 2;
  __REG32 PDTH_PA									: 2;
  __REG32 												: 2;
  __REG32 PDTH_FORMAT							: 2;
  __REG32 												: 2;
  __REG32 PDTH_SEL								: 2;
  __REG32 												:10;
} __vdc_tcon_out_pdtha_bits;

/* Output Phase Control Register (OUT_CLK_PHASE) */
typedef struct {
  __REG32 OUTCNT_POLB_EDGE				: 1;
  __REG32 OUTCNT_POLA_EDGE				: 1;
  __REG32 OUTCNT_CPV_EDGE					: 1;
  __REG32 OUTCNT_STB_EDGE					: 1;
  __REG32 OUTCNT_STH_EDGE					: 1;
  __REG32 OUTCNT_STVB_EDGE				: 1;
  __REG32 OUTCNT_STVA_EDGE				: 1;
  __REG32 												: 1;
  __REG32 OUTCNT_LCD_EDGE					: 1;
  __REG32 												: 3;
  __REG32 OUTCNT_FRONT_GAM				: 1;
  __REG32 												:19;
} __vdc_tcon_out_clk_phase_bits;

/* Interrupt Control Register 1 (SYSCNT_INT1) */
typedef struct {
  __REG32 INT_STA0								: 1;
  __REG32 												: 3;
  __REG32 INT_STA1								: 1;
  __REG32 												: 3;
  __REG32 INT_STA2								: 1;
  __REG32 												: 3;
  __REG32 INT_STA3								: 1;
  __REG32 												: 3;
  __REG32 INT_STA4								: 1;
  __REG32 												: 3;
  __REG32 INT_STA5								: 1;
  __REG32 												: 3;
  __REG32 INT_STA6								: 1;
  __REG32 												: 3;
  __REG32 INT_STA7								: 1;
  __REG32 												: 3;
} __vdc_syscnt_int1_bits;

/* Interrupt Control Register 2 (SYSCNT_INT2) */
typedef struct {
  __REG32 INT_STA8								: 1;
  __REG32 												: 3;
  __REG32 INT_STA9								: 1;
  __REG32 												: 3;
  __REG32 INT_STA10								: 1;
  __REG32 												: 3;
  __REG32 INT_STA11								: 1;
  __REG32 												: 3;
  __REG32 INT_STA12								: 1;
  __REG32 												: 3;
  __REG32 INT_STA13								: 1;
  __REG32 												: 3;
  __REG32 INT_STA14								: 1;
  __REG32 												: 3;
  __REG32 INT_STA15								: 1;
  __REG32 												: 3;
} __vdc_syscnt_int2_bits;

/* Interrupt Control Register 3 (SYSCNT_INT3) */
typedef struct {
  __REG32 INT_STA16								: 1;
  __REG32 												: 3;
  __REG32 INT_STA17								: 1;
  __REG32 												: 3;
  __REG32 INT_STA18								: 1;
  __REG32 												: 3;
  __REG32 INT_STA19								: 1;
  __REG32 												: 3;
  __REG32 INT_STA20								: 1;
  __REG32 												: 3;
  __REG32 INT_STA21								: 1;
  __REG32 												: 3;
  __REG32 INT_STA2								: 1;
  __REG32 												: 7;
} __vdc_syscnt_int3_bits;

/* Interrupt Control Register 4 (SYSCNT_INT4) */
typedef struct {
  __REG32 INT_OUT0_ON							: 1;
  __REG32 												: 3;
  __REG32 INT_OUT1_ON							: 1;
  __REG32 												: 3;
  __REG32 INT_OUT2_ON							: 1;
  __REG32 			 									: 3;
  __REG32 INT_OUT3_ON							: 1;
  __REG32 												: 3;
  __REG32 INT_OUT4_ON							: 1;
  __REG32 												: 3;
  __REG32 INT_OUT5_ON							: 1;
  __REG32 												: 3;
  __REG32 INT_OUT6_ON							: 1;
  __REG32 												: 3;
  __REG32 INT_OUT7_ON							: 1;
  __REG32 												: 3;
} __vdc_syscnt_int4_bits;

/* Interrupt Control Register 5 (SYSCNT_INT5) */
typedef struct {
  __REG32 INT_OUT8_ON							: 1;
  __REG32 												: 3;
  __REG32 INT_OUT9_ON 						: 1;
  __REG32 												: 3;
  __REG32 INT_OUT10_ON 						: 1;
  __REG32 												: 3;
  __REG32 INT_OUT11_ON 						: 1;
  __REG32 												: 3;
  __REG32 INT_OUT12_ON 						: 1;
  __REG32 												: 3;
  __REG32 INT_OUT13_ON 						: 1;
  __REG32 												: 3;
  __REG32 INT_OUT14_ON 						: 1;
  __REG32 												: 3;
  __REG32 INT_OUT15_ON 						: 1;
  __REG32 												: 3;
} __vdc_syscnt_int5_bits;

/* Interrupt Control Register 6 (SYSCNT_INT6) */
typedef struct {
  __REG32 INT_OUT16_ON						: 1;
  __REG32 												: 3;
  __REG32 INT_OUT17_ON 						: 1;
  __REG32 												: 3;
  __REG32 INT_OUT18_ON 						: 1;
  __REG32 												: 3;
  __REG32 INT_OUT19_ON 						: 1;
  __REG32 												: 3;
  __REG32 INT_OUT20_ON 						: 1;
  __REG32 												: 3;
  __REG32 INT_OUT21_ON 						: 1;
  __REG32 												: 3;
  __REG32 INT_OUT22_ON 						: 1;
  __REG32 												: 7;
} __vdc_syscnt_int6_bits;

/* Panel Clock Control Register (SYSCNT_PANEL_CLK) */
typedef struct {
  __REG16 PANEL_DCDR							: 6;
  __REG16 												: 2;
  __REG16 PANEL_ICKE 							: 1;
  __REG16 												: 1;
  __REG16 PANEL_OCKSEL						: 2;
  __REG16 PANEL_ICKSEL						: 2;
  __REG16 												: 2;
} __vdc_syscnt_panel_clk_bits;

/* CLUT Table Read Select SignalStatus Register (SYSCNT_CLUT) */
typedef struct {
  __REG16 GR0_CLT_SEL_ST					: 1;
  __REG16 												: 3;
  __REG16 GR1_CLT_SEL_ST					: 1;
  __REG16 												: 3;
  __REG16 GR2_CLT_SEL_ST					: 1;
  __REG16 												: 3;
  __REG16 GR3_CLT_SEL_ST				  : 1;
  __REG16 												: 1;
  __REG16 GR_OIR_SEL_ST				  	: 1;
  __REG16 												: 1;
} __vdc_syscnt_clut_bits;

/* Capture Start Register (CAPSR) */
typedef struct {
  __REG32 CE											: 1;
  __REG32 												:15;
  __REG32 CPKIL										: 1;
  __REG32 												:15;
} __ceu_capsr_bits;

/* Capture Control Register (CAPCR) */
typedef struct {
  __REG32 												:16;
  __REG32 CTNCP										: 1;
  __REG32 												: 3;
  __REG32 MTCM										: 2;
  __REG32 												: 2;
  __REG32 FDRP										: 8;
} __ceu_capcr_bits;

/* Capture Interface Control Register (CAMCR) */
typedef struct {
  __REG32 HDPOL										: 1;
  __REG32 VDPOL										: 1;
  __REG32 												: 2;
  __REG32 JPG											: 2;
  __REG32 												: 2;
  __REG32 DTARY										: 2;
  __REG32 												: 2;
  __REG32 DTIF										: 1;
  __REG32 												: 3;
  __REG32 FLDPOL									: 1;
  __REG32 												:15;
} __ceu_camcr_bits;

/* Capture Interface Cycle Register (CMCYR) */
typedef struct {
  __REG32 HCYL										:14;
  __REG32 												: 2;
  __REG32 VCYL										:14;
  __REG32 												: 2;
} __ceu_cmcyr_bits;

/* Capture Interface Offset Register (CAMOR) */
typedef struct {
  __REG32 HOFST										:13;
  __REG32 												: 3;
  __REG32 VOFST										:12;
  __REG32 												: 4;
} __ceu_camor_bits;

/* Capture Interface Width Register (CAPWR) */
typedef struct {
  __REG32 HWDTH										:13;
  __REG32 												: 3;
  __REG32 VWDTH										:12;
  __REG32 												: 4;
} __ceu_capwr_bits;

/* Capture Interface Input Format Register (CAIFR) */
typedef struct {
  __REG32 FCI											: 2;
  __REG32 												: 2;
  __REG32 CIM											: 1;
  __REG32 												: 3;
  __REG32 IFS											: 1;
  __REG32 												:23;
} __ceu_caifr_bits;

/* CEU Register Control Register (CRCNTR) */
typedef struct {
  __REG32 RC											: 1;
  __REG32 RS											: 1;
  __REG32 												: 2;
  __REG32 RVS											: 1;
  __REG32 												:27;
} __ceu_crcntr_bits;

/* CEU Register ForcibleControl Register (CRCMPR) */
typedef struct {
  __REG32 RA											: 1;
  __REG32 												:31;
} __ceu_crcmpr_bits;

/* Capture Filter Control Register (CFLCR) */
typedef struct {
  __REG32 HFRAC										:12;
  __REG32 HMANT										: 4;
  __REG32 VFRAC										:12;
  __REG32 VMANT										: 4;
} __ceu_cflcr_bits;

/* Capture Filter SizeClip Register (CFSZR) */
typedef struct {
  __REG32 HFCLP										:12;
  __REG32 												: 4;
  __REG32 VFCLP										:12;
  __REG32 												: 4;
} __ceu_cfszr_bits;

/* Capture Destination Width Register (CDWDR) */
typedef struct {
  __REG32 CHDW										:13;
  __REG32 												:19;
} __ceu_cdwdr_bits;

/* Capture Bundle Destination Size Register (CBDSR) */
typedef struct {
  __REG32 CBVS										:23;
  __REG32 												: 9;
} __ceu_cbdsr_bits;

/* Capture Low-Pass FilterControl Register (CLFCR) */
typedef struct {
  __REG32 LPF											: 1;
  __REG32 												:31;
} __ceu_cfwcr_bits;

/* Firewall Operation Control Register (CFWCR) */
typedef struct {
  __REG32 FWE											: 1;
  __REG32 												: 4;
  __REG32 FWV											:27;
} __ceu_clfcr_bits;

/* Capture Data Output Control Register (CDOCR) */
typedef struct {
  __REG32 COBS										: 1;
  __REG32 COWS										: 1;
  __REG32 COLS										: 1;
  __REG32 												: 1;
  __REG32 CDS											: 1;
  __REG32 												:11;
  __REG32 CBE											: 1;
  __REG32 												:15;
} __ceu_cdocr_bits;

/* Capture Event Interrupt Enable Register (CEIER) */
typedef struct {
  __REG32 CPEIE										: 1;
  __REG32 CFEIE										: 1;
  __REG32 												: 2;
  __REG32 IGRWIE									: 1;
  __REG32 												: 3;
  __REG32 HDIE										: 1;
  __REG32 VDIE										: 1;
  __REG32 												: 2;
  __REG32 CPBE1IE									: 1;
  __REG32 CPBE2IE									: 1;
  __REG32 CPBE3IE									: 1;
  __REG32 CPBE4IE									: 1;
  __REG32 CDTOFIE									: 1;
  __REG32 IGHSIE									: 1;
  __REG32 IGVSIE									: 1;
  __REG32 												: 1;
  __REG32 VBPIE										: 1;
  __REG32 												: 2;
  __REG32 FWFIE										: 1;
  __REG32 NHDIE										: 1;
  __REG32 NVDIE										: 1;
  __REG32 												: 6;
} __ceu_ceier_bits;

/* Capture Event FlagClear Register (CETCR) */
typedef struct {
  __REG32 CPE											: 1;
  __REG32 CFE											: 1;
  __REG32 												: 2;
  __REG32 IGRW										: 1;
  __REG32 												: 3;
  __REG32 HD											: 1;
  __REG32 VD											: 1;
  __REG32 												: 2;
  __REG32 CPBE1										: 1;
  __REG32 CPBE2										: 1;
  __REG32 CPBE3										: 1;
  __REG32 CPBE4										: 1;
  __REG32 CDTOF										: 1;
  __REG32 IGHS										: 1;
  __REG32 IGVS										: 1;
  __REG32 												: 1;
  __REG32 VBP											: 1;
  __REG32 												: 2;
  __REG32 FWF											: 1;
  __REG32 NHD											: 1;
  __REG32 NVD											: 1;
  __REG32 												: 6;
} __ceu_cetcr_bits;

/* Capture Status Register (CSTSR) */
typedef struct {
  __REG32 CPTON										: 1;
  __REG32 												:15;
  __REG32 CPFLD										: 1;
  __REG32 												: 7;
  __REG32 CRST										: 1;
  __REG32 												: 7;
} __ceu_cstsr_bits;

/* Control Register (DOCMCR) */
typedef struct {
  __REG32 CMPR          : 1;
  __REG32               :15;
  __REG32 CMPRU         : 1;
  __REG32               :15;
} __discom_docmcr_bits;

/* Status Register (DOCMSTR) */
typedef struct {
  __REG32 CMPST         : 1;
  __REG32               :31;
} __discom_docmstr_bits;

/* Status Clear Register (DOCMCLSTR) */
typedef struct {
  __REG32 CMPCLST       : 1;
  __REG32               :31;
} __discom_docmclstr_bits;

/* Interrupt Enable Register (DOCMIENR) */
typedef struct {
  __REG32 CMPIEN        : 1;
  __REG32               :31;
} __discom_docmienr_bits;

/* Operation Parameter Setting Register (DOCMPMR) */
typedef struct {
  __REG32 CMPSELP       : 4;
  __REG32               : 3;
  __REG32 CMPDAUF       : 1;
  __REG32 CMPDFA        : 8;
  __REG32 CMPBT         : 1;
  __REG32               :15;
} __discom_docmpmr_bits;

/* Horizontal Start Position Setting Register (DOCMSPXR) */
typedef struct {
  __REG32 CMPSPX        :11;
  __REG32               :21;
} __discom_docmspxr_bits;

/* Vertical Start Position Setting Register (DOCMSPYR) */
typedef struct {
  __REG32 CMPSPY        :11;
  __REG32               :21;
} __discom_docmspyr_bits;

/* Horizontal Size Setting Register (DOCMSZXR) */
typedef struct {
  __REG32 CMPSZX        :11;
  __REG32               :21;
} __discom_docmszxr_bits;

/* Vertical Size Setting Register (DOCMSZYR) */
typedef struct {
  __REG32 CMPSZY        :11;
  __REG32               :21;
} __discom_docmszyr_bits;

/* JPEG Code Mode Register (JCMOD) */
typedef struct {
  __REG8  REDU          : 3;
  __REG8  DSP           : 1;
  __REG8                : 4;
} __jcu_jcmod_bits;

/* JPEG Code Command Register (JCCMD) */
typedef struct {
  __REG8  JSRT          : 1;
  __REG8  JRST          : 1;
  __REG8  JEND          : 1;
  __REG8                : 4;
  __REG8  BRST          : 1;
} __jcu_jccmd_bits;

/* JPEG Code Quantization Table Number Register (JCQTN) */
typedef struct {
  __REG8  QT1           : 2;
  __REG8  QT2           : 2;
  __REG8  QT3           : 2;
  __REG8                : 2;
} __jcu_jcqtn_bits;

/* JPEG Code Huffman Table Number Register (JCHTN) */
typedef struct {
  __REG8  HTD1          : 1;
  __REG8  HTA1          : 1;
  __REG8  HTD2          : 1;
  __REG8  HTA2          : 1;
  __REG8  HTD3          : 1;
  __REG8  HTA3          : 1;
  __REG8                : 2;
} __jcu_jchtn_bits;

/* JPEG Interrupt Enable Register 0 (JINTE0) */
typedef struct {
  __REG8                : 3;
  __REG8  INT3          : 1;
  __REG8                : 1;
  __REG8  INT5          : 1;
  __REG8  INT6          : 1;
  __REG8  INT7          : 1;
} __jcu_jinte0_bits;

/* JPEG Interrupt Status Register 0 (JINTS0) */
typedef struct {
  __REG8                : 3;
  __REG8  INS3          : 1;
  __REG8                : 1;
  __REG8  INS5          : 1;
  __REG8  INS6          : 1;
  __REG8                : 1;
} __jcu_jints0_bits;

/* JPEG Code Decode Error Register (JCDERR) */
typedef struct {
  __REG8  ERR           : 4;
  __REG8                : 4;
} __jcu_jcderr_bits;

/* JPEG Code Reset Register (JCRST) */
typedef struct {
  __REG8  RST           : 1;
  __REG8                : 7;
} __jcu_jcrst_bits;

/* JPEG Interface Compression Control Register (JIFECNT) */
typedef struct {
  __REG32 DINSWAP       : 3;
  __REG32               : 1;
  __REG32 DINLC         : 1;
  __REG32 DINRCMD       : 1;
  __REG32 DINRINI       : 1;
  __REG32               : 1;
  __REG32 JOUTSWAP      : 3;
  __REG32               : 1;
  __REG32 JOUTC         : 1;
  __REG32 JOUTRCMD      : 1;
  __REG32 JOUTRINI      : 1;
  __REG32               :17;
} __jcu_jifecnt_bits;

/* JPEG Interface Compression Line Offset Register (JIFESOFST) */
typedef struct {
  __REG32 ESMW          :15;
  __REG32               :17;
} __jcu_jifesofst_bits;

/* JPEG Inteface Compression Source Line Count Register (JIFESLC) */
/* JPEG Interface Decompression Destination Line Register (JIFDDLC) */
typedef struct {
  __REG32 LINES         :16;
  __REG32               :16;
} __jcu_jifeslc_jifddlc_bits;

/* JPEG Inteface Compression Destination Count Register (JIFEDDC) */
/* JPEG Interface Decompression Source Count Register (JIFDSDC) */
typedef struct {
  __REG32 JDATAS        :16;
  __REG32               :16;
} __jcu_jifeddc_jifdsdc_bits;

/* JPEG Inteface Decompression Control Register (JIFDCNT) */
typedef struct {
  __REG32 DOUTSWAP      : 3;
  __REG32               : 1;
  __REG32 DOUTLD        : 1;
  __REG32 DOUTRCMD      : 1;
  __REG32 DOUTRINI      : 1;
  __REG32               : 1;
  __REG32 JINSWAP       : 3;
  __REG32               : 1;
  __REG32 JINC          : 1;
  __REG32 JINRCMD       : 1;
  __REG32 JINRINI       : 1;
  __REG32               : 9;
  __REG32 OPF           : 2;
  __REG32 HINTER        : 2;
  __REG32 VINTER        : 2;
  __REG32               : 2;
} __jcu_jifdcnt_bits;

/* JPEG Interface Decompression Line Offset Register (JIFDDOFST) */
typedef struct {
  __REG32 DDMW          :15;
  __REG32               :17;
} __jcu_jifddofst_bits;

/* JPEG Interface Decompression alpha Set Register (JIFDADT) */
typedef struct {
  __REG32 ALPHA         : 8;
  __REG32               :24;
} __jcu_jifdadt_bits;

/* JPEG Interrupt Enable Register 1 (JINTE1) */
typedef struct {
  __REG32 DOUTLEN       : 1;
  __REG32 JINEN         : 1;
  __REG32 DBTEN         : 1;
  __REG32               : 1;
  __REG32 JOUTEN        : 1;
  __REG32 DINLEN        : 1;
  __REG32 CBTEN         : 1;
  __REG32               :25;
} __jcu_jinte1_bits;

/* JPEG Interrupt Status Register 1 (JINTS1) */
typedef struct {
  __REG32 DOUTLF        : 1;
  __REG32 JINF          : 1;
  __REG32 DBTF          : 1;
  __REG32               : 1;
  __REG32 JOUTF         : 1;
  __REG32 DINLF         : 1;
  __REG32 CBTF          : 1;
  __REG32               :25;
} __jcu_jints1_bits;

/* JPEG Input Image Data CbCr Range Setting Register (JIFESVSZ) */
typedef struct {
  __REG32               :15;
  __REG32 DINYCHG       : 1;
  __REG32               :16;
} __jcu_jifesvsz_bits;

/* JPEG Output Image Data CbCr Range Setting Register (JIFESHSZ) */
typedef struct {
  __REG32               :15;
  __REG32 DOUTCHG       : 1;
  __REG32               :16;
} __jcu_jifeshsz_bits;

/* PFV Control Register (PFVCR) */
typedef struct {
  __REG32 DOUTSWAP32    : 2;
  __REG32 DINSWAP32     : 2;
  __REG32 DOUTSWAP16    : 1;
  __REG32 DINSWAP16     : 1;
  __REG32               : 2;
  __REG32 OFMT          : 2;
  __REG32 IFMT          : 2;
  __REG32 DTH_ON        : 1;
  __REG32               : 3;
  __REG32 PFVE          : 1;
  __REG32               :15;
} __pfv_cr_bits;

/* PFV Interrupt Control Register (PFVICR) */
typedef struct {
  __REG32 ODTRG         : 2;
  __REG32 IDTRG         : 2;
  __REG32 OFEN          : 1;
  __REG32 IFEN          : 1;
  __REG32 PFVEEN        : 1;
  __REG32               :25;
} __pfv_icr_bits;

/* PFV Interrupt Status Register (PFVISR) */
typedef struct {
  __REG32 OFFUL         : 1;
  __REG32 IFEMP         : 1;
  __REG32 OFUDF         : 1;
  __REG32 IFOVF         : 1;
  __REG32               :28;
} __pfv_isr_bits;

/* PFV Input/Output Buffer Registers (PFVID, PFVOD) */
typedef union {
  /* PFV0_PFVID */
  /* PFV0_PFVOD */
  /* PFV1_PFVID */
  /* PFV1_PFVOD */
  struct {
    __REG32             :32;
  };
  struct {
    __REG16 __halfword0;
    __REG16 __halfword1;
  };
} __pfv_id_pfvod_bits;

/* PFV Input FIFO Status Register (PFVIFSR) */
typedef struct {
  __REG32 IFVD          : 6;
  __REG32               :26;
} __pfv_ifsr_bits;

/* PFV Output FIFO Status Register (PFVOFSR) */
typedef struct {
  __REG32 OFVD          : 6;
  __REG32               :26;
} __pfv_ofsr_bits;

/* PFV alpha Setting Register (PFVACR) */
typedef struct {
  __REG32 ALPHA         : 8;
  __REG32               :24;
} __pfv_acr_bits;

/* PFV Matrix Mode Register (PFV_MTX_MODE) */
typedef struct {
  __REG32 PFV_MTX_MD    : 2;
  __REG32               :30;
} __pfv_mtx_mode_bits;

/* PFV Matrix YG Adjustment Register 0 (PFV_MTX_YG_ADJ0) */
typedef struct {
  __REG32 PFV_MTX_GG    :11;
  __REG32               : 5;
  __REG32 PFV_MTX_YG    : 8;
  __REG32               : 8;
} __pfv_mtx_yg_adj_bits;

/* PFV Matrix YG Adjustment Register 1 (PFV_MTX_YG_ADJ1) */
typedef struct {
  __REG32 PFV_MTX_GR    :11;
  __REG32               : 5;
  __REG32 PFV_MTX_GB    :11;
  __REG32               : 5;
} __pfv_mtx_yg_adj1_bits;

/* PFV Matrix CBB Adjustment Register 0 (PFV_MTX_CBB_ADJ0) */
typedef struct {
  __REG32 PFV_MTX_BG    :11;
  __REG32               : 5;
  __REG32 PFV_MTX_B     : 8;
  __REG32               : 8;
} __pfv_mtx_cbb_adj_bits;

/* PFV Matrix CBB Adjustment Register 1 (PFV_MTX_CBB_ADJ1) */
typedef struct {
  __REG32 PFV_MTX_BR    :11;
  __REG32               : 5;
  __REG32 PFV_MTX_BB    :11;
  __REG32               : 5;
} __pfv_mtx_cbb_adj1_bits;

/* PFV Matrix CRR Adjustment Register 0 (PFV_MTX_CRR_ADJ0) */
typedef struct {
  __REG32 PFV_MTX_RG    :11;
  __REG32               : 5;
  __REG32 PFV_MTX_R     : 8;
  __REG32               : 8;
} __pfv_mtx_crr_adj_bits;

/* PFV Matrix CRR Adjustment Register 1 (PFV_MTX_CRR_ADJ1) */
typedef struct {
  __REG32 PFV_MTX_RB    :11;
  __REG32               : 5;
  __REG32 PFV_MTX_RR    :11;
  __REG32               : 5;
} __pfv_mtx_crr_adj1_bits;

/* PFV Image Size Setting Register (PFVSZR) */
typedef struct {
  __REG32 PFVSZY        :16;
  __REG32 PFVSZX        :16;
} __pfv_szr_bits;

/* IPC0_n Initialization Register (IPCIR_IPC0_n n=0,1,2,3) */
/* OPC0_n Initialization Register (OPCIR_OPC0_n n=0,1,2,3) */
/* FFD0_n FIFO Download Initialization Register (FFDIR_FFD0_n) (n = 0, 1, 2, 3) */
/* FFU0_n FIFO Upload Initialization Register (FFUIR_FFU0_n) (n = 0, 1, 2, 3) */
/* 2SRC0_m Initialization Register p (SRCIRp_2SRC0_m) (m = 0, 1; p = 0, 1) */
/* 2SRC0_m Initialization Register RIF (SRCIRR_2SRC0_m) (m = 0, 1) */
/* DVU0_n Initialization Register (DVUIR_DVU0_n) (n = 0, 1, 2, 3) */
/* MIX0_0 Initialization Register (MIXIR_MIX0_0) */
typedef struct {
  __REG32 INIT          : 1;
  __REG32               :31;
} __scux_initreg_bits;

/* IPC0_n Pass Select Register (IPCSLR_IPC0_n n=0,1,2,3) */
typedef struct {
  __REG32 IPC_PASS_SEL  : 3;
  __REG32               :29;
} __scux_ipslr_ipc0_bits;

/* OPC0_n Pass Select Register (OPCSLR_OPC0_n n=0,1,2,3) */
typedef struct {
  __REG32 OPC_PASS_SEL  : 3;
  __REG32               :29;
} __scux_opslr_opc0_bits;

/* FFD0_n FIFO Download Audio Information Register (FDAIR_FFD0_n) (n = 0, 1, 2, 3) */
/* FFU0_n FIFO Upload Audio Information Register (FUAIR_FFU0_n) (n = 0, 1, 2, 3)*/
/* MIX0_0 Audio Information Register (MADIR_MIX0_0) */
typedef struct {
  __REG32 CHNUM         : 4;
  __REG32               :28;
} __scux_chnumreg_bits;

/* FFD0_n FIFO Download Request Size Register (DRQSR_FFD0_n) (n = 0, 1, 2, 3) */
/* FFU0_n FIFO Upload Request Size Register (URQSR_FFU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32 SIZE          : 4;
  __REG32               :28;
} __scux_sizereg_bits;

/* FFD0_n FIFO Download Pass Register (FFDPR_FFD0_n) (n = 0, 1, 2, 3) */
/* FFU0_n FIFO Upload Pass Register (FFUPR_FFU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32 PASS          : 2;
  __REG32               :30;
} __scux_passreg_bits;

/* FFD0_n FIFO Download Boot Register (FFDBR_FFD0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32 BOOT          : 1;
  __REG32               :31;
} __scux_ffdbr_ffd0_bits;

/* FFD0_n FIFO Download Event Mask Register (DEVMR_FFD0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32               :15;
  __REG32 DEVMRQ        : 1;
  __REG32               :12;
  __REG32 DEVMIUF       : 1;
  __REG32 DEVMOL        : 1;
  __REG32 DEVMOF        : 1;
  __REG32 DEVMUF        : 1;
} __scux_devmr_ffd0_bits;

/* FFD0_n FIFO Download Event Clear Register (DEVCR_FFD0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32               :15;
  __REG32 DEVCRQ        : 1;
  __REG32               :12;
  __REG32 DEVCIUF       : 1;
  __REG32 DEVCOL        : 1;
  __REG32 DEVCOF        : 1;
  __REG32 DEVCUF        : 1;
} __scux_devcr_ffd0_bits;

/* FFU0_n FIFO Upload Event Mask Register (UEVMR_FFU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32               :15;
  __REG32 UEVMRQ        : 1;
  __REG32               :13;
  __REG32 UEVMOL        : 1;
  __REG32 UEVMOF        : 1;
  __REG32 UEVMUF        : 1;
} __scux_uevmr_ffu0_bits;

/* FFU0_n FIFO Upload Event Clear Register (UEVCR_FFU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32               :15;
  __REG32 UEVCRQ        : 1;
  __REG32               :13;
  __REG32 UEVCOL        : 1;
  __REG32 UEVCOF        : 1;
  __REG32 UEVCUF        : 1;
} __scux_uevcr_ffu0_bits;

/* 2SRC0_m Audio Information Register p (SADIRp_2SRC0_m) (m = 0, 1; p = 0, 1) */
/* DVU0_n Audio Information Register (VADIR_DVU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32 CHNUM         : 4;
  __REG32               :12;
  __REG32 OTBL          : 5;
  __REG32               :11;
} __scux_otblchnumreg_bits;

/* 2SRC0_m Bypass Register p (SRCBRp_2SRC0_m) (m = 0, 1; p = 0, 1) */
/* DVU0_n Bypass Register (DVUBR_DVU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32 BYPASS        : 1;
  __REG32               :31;
} __scux_bypassreg_bits;

/* 2SRC0_m IFS Control Register p (IFSCRp_2SRC0_m) (m = 0, 1; p = 0, 1) */
typedef struct {
  __REG32 INTIFSEN      : 1;
  __REG32               :31;
} __scux_ifscr_2src0_bits;

/* 2SRC0_m IFS Value Setting Register p (IFSVRp_2SRC0_m) (m = 0, 1; p = 0, 1) */
typedef struct {
  __REG32 INTIFS        :28;
  __REG32               : 4;
} __scux_ifsvr_2src0_bits;

/* 2SRC0_m Control Register p (SRCCRp_2SRC0_m) (m = 0, 1; p = 0, 1) */
typedef struct {
  __REG32 SRCMD         : 1;
  __REG32               :11;
  __REG32 BUFMD         : 1;
  __REG32               : 7;
  __REG32 WATMD         : 1;
  __REG32               :11;
} __scux_srccr_2src0_bits;

/* 2SRC0_m Minimum FS Setting Register p (MNFSRp_2SRC0_m) (m = 0, 1; p = 0, 1) */
typedef struct {
  __REG32 MINFS         :28;
  __REG32               : 4;
} __scux_mnfsr_2src0_bits;

/* 2SRC0_m Buffer Size Setting Register p (BFSSRp_2SRC0_m) (m = 0, 1; p = 0, 1) */
typedef struct {
  __REG32 BUFIJEC       : 4;
  __REG32               :12;
  __REG32 BUFDATA       :10;
  __REG32               : 6;
} __scux_bfssr_2src0_bits;

/* 2SRC0_m SCU2 Status Register p (SC2SRp_2SRC0_m) (m = 0, 1; p = 0, 1) */
typedef struct {
  __REG32 SC2FSI        :28;
  __REG32 SC2STS        : 2;
  __REG32 SC2MUTE       : 1;
  __REG32 SRCWSTS       : 1;
} __scux_sc2sr_2src0_bits;

/* 2SRC0_m Wait Time Setting Register p (WATSRp_2SRC0_m) (m = 0, 1; p = 0, 1) */
typedef struct {
  __REG32 WTIME         :24;
  __REG32               : 8;
} __scux_watsr_2src0_bits;

/* 2SRC0_m Event Mask Register p (SEVMRp_2SRC0_m) (m = 0, 1; p = 0, 1) */
typedef struct {
  __REG32               :14;
  __REG32 EVMWAIT       : 1;
  __REG32               :15;
  __REG32 EVMOF         : 1;
  __REG32 EVMUF         : 1;
} __scux_sevmr_2src0_bits;

/* 2SRC0_m Event Clear Register p (SEVCRp_2SRC0_m) (m = 0, 1; p = 0, 1) */
typedef struct {
  __REG32               :14;
  __REG32 EVCWAIT       : 1;
  __REG32               :15;
  __REG32 EVCOF         : 1;
  __REG32 EVCUF         : 1;
} __scux_sevcr_2src0_bits;

/* DVU0_n Control Register (DVUCR_DVU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32 ZCMD          : 1;
  __REG32               : 3;
  __REG32 VRMD          : 1;
  __REG32               : 3;
  __REG32 VVMD          : 1;
  __REG32               :23;
} __scux_dvucr_dvu0_bits;

/* DVU0_n Zero Cross Mute Control Register (ZCMCR_DVU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32 ZCEN0         : 1;
  __REG32 ZCEN1         : 1;
  __REG32 ZCEN2         : 1;
  __REG32 ZCEN3         : 1;
  __REG32 ZCEN4         : 1;
  __REG32 ZCEN5         : 1;
  __REG32 ZCEN6         : 1;
  __REG32 ZCEN7         : 1;
  __REG32               :24;
} __scux_zcmcr_dvu0_bits;

/* DVU0_n Volume Ramp Control Register (VRCTR_DVU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32 VREN0         : 1;
  __REG32 VREN1         : 1;
  __REG32 VREN2         : 1;
  __REG32 VREN3         : 1;
  __REG32 VREN4         : 1;
  __REG32 VREN5         : 1;
  __REG32 VREN6         : 1;
  __REG32 VREN7         : 1;
  __REG32               :24;
} __scux_vrctr_dvu0_bits;

/* DVU0_n Volume Ramp Period Register (VRPDR_DVU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32 VRPDDW        : 5;
  __REG32               : 3;
  __REG32 VRPDUP        : 5;
  __REG32               :19;
} __scux_vrpdr_dvu0_bits;

/* DVU0_n Volume Ramp Decibel Register (VRDBR_DVU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32 VRDB          :10;
  __REG32               :22;
} __scux_vrdbr_dvu0_bits;

/* DVU0_n Volume Ramp Wait Time Register (VRWTR_DVU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32 VRWT          :24;
  __REG32               : 8;
} __scux_vrwtr_dvu0_bits;

/* DVU0_n Volume Value Setting Register (VOLxR_DVU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32 VOLVAL        :24;
  __REG32               : 8;
} __scux_volxr_dvu0_bits;

/* DVU0_n Enable Register (DVUER_DVU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32 DVUEN         : 1;
  __REG32               :31;
} __scux_dvuer_dvu0_bits;

/* DVU0_n Status Register (DVUSR_DVU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32 VRSTS         : 3;
  __REG32               :13;
  __REG32 ZSTS0         : 1;
  __REG32 ZSTS1         : 1;
  __REG32 ZSTS2         : 1;
  __REG32 ZSTS3         : 1;
  __REG32 ZSTS4         : 1;
  __REG32 ZSTS5         : 1;
  __REG32 ZSTS6         : 1;
  __REG32 ZSTS7         : 1;
  __REG32               : 8;
} __scux_dvusr_dvu0_bits;

/* DVU0_n Event Mask Register (VEVMR_DVU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32               :15;
  __REG32 VEVMVR        : 1;
  __REG32               : 8;
  __REG32 VEVMZCM0      : 1;
  __REG32 VEVMZCM1      : 1;
  __REG32 VEVMZCM2      : 1;
  __REG32 VEVMZCM3      : 1;
  __REG32 VEVMZCM4      : 1;
  __REG32 VEVMZCM5      : 1;
  __REG32 VEVMZCM6      : 1;
  __REG32 VEVMZCM7      : 1;
} __scux_vevmr_dvu0_bits;

/* DVU0_n Event Clear Register (VEVCR_DVU0_n) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32               :15;
  __REG32 VEVCVR        : 1;
  __REG32               : 8;
  __REG32 VEVCZCM0      : 1;
  __REG32 VEVCZCM1      : 1;
  __REG32 VEVCZCM2      : 1;
  __REG32 VEVCZCM3      : 1;
  __REG32 VEVCZCM4      : 1;
  __REG32 VEVCZCM5      : 1;
  __REG32 VEVCZCM6      : 1;
  __REG32 VEVCZCM7      : 1;
} __scux_vevcr_dvu0_bits;

/* MIX0_0 Bypass Register (MIXBR_MIX0_0) */
typedef struct {
  __REG32 BYPASS        : 1;
  __REG32               :15;
  __REG32 BPSYS         : 2;
  __REG32               :14;
} __scux_mixbr_mix0_bits;

/* MIX0_0 Mode Register (MIXMR_MIX0_0) */
typedef struct {
  __REG32 MIXMODE       : 1;
  __REG32               :31;
} __scux_mixmr_mix0_bits;

/* MIX0_0 Volume Period Register (MVPDR_MIX0_0) */
typedef struct {
  __REG32 MXPDDW        : 4;
  __REG32               : 4;
  __REG32 MXPDUP        : 4;
  __REG32               :20;
} __scux_mvpdr_mix0_bits;

/* MIX0_0 Decibel A Register (MDBAR_MIX0_0) */
typedef struct {
  __REG32 MIXDBA        :10;
  __REG32               :22;
} __scux_mdbar_mix0_bits;

/* MIX0_0 Decibel B Register (MDBBR_MIX0_0) */
typedef struct {
  __REG32 MIXDBB        :10;
  __REG32               :22;
} __scux_mdbbr_mix0_bits;

/* MIX0_0 Decibel C Register (MDBCR_MIX0_0) */
typedef struct {
  __REG32 MIXDBC        :10;
  __REG32               :22;
} __scux_mdbcr_mix0_bits;

/* MIX0_0 Decibel D Register (MDBDR_MIX0_0) */
typedef struct {
  __REG32 MIXDBD        :10;
  __REG32               :22;
} __scux_mdbdr_mix0_bits;

/* MIX0_0 Decibel Enable Register (MDBER_MIX0_0) */
typedef struct {
  __REG32 MIXDBEN       : 1;
  __REG32               :31;
} __scux_mdber_mix0_bits;

/* MIX0_0 Status Register (MIXSR_MIX0_0) */
typedef struct {
  __REG32 MIXSTS        : 2;
  __REG32               :30;
} __scux_mixsr_mix0_bits;

/* Software Reset Register (SWRSR_CIM) */
typedef struct {
  __REG32 SWRST         : 1;
  __REG32               :31;
} __scux_swrsr_cim_bits;

/* DMA Control Register (DMACR_CIM) */
typedef struct {
  __REG32 DMAMDFFD0     : 1;
  __REG32 DMAMDFFD1     : 1;
  __REG32 DMAMDFFD0_2   : 1;
  __REG32 DMAMDFFD0_3   : 1;
  __REG32 DMAMDFFU0     : 1;
  __REG32 DMAMDFFU1     : 1;
  __REG32 DMAMDFFU2     : 1;
  __REG32 DMAMDFFU3     : 1;
  __REG32               :24;
} __scux_dmacr_cim_bits;

/* SSI Route Select Register (SSIRSEL_CIM) */
typedef struct {
  __REG32 SOSEL0        : 2;
  __REG32               : 2;
  __REG32 SOSEL1        : 2;
  __REG32               : 2;
  __REG32 SOSEL2        : 2;
  __REG32               : 2;
  __REG32 SOSEL3        : 2;
  __REG32               : 2;
  __REG32 SOSEL4        : 2;
  __REG32               : 2;
  __REG32 SOSEL5        : 2;
  __REG32               : 2;
  __REG32 SISEL0        : 2;
  __REG32 SISEL1        : 2;
  __REG32 SISEL2        : 2;
  __REG32 SISEL3        : 2;
} __scux_ssirsel_cim_bits;

/* FFD0_n Timing Select Register (FDTSELn_CIM) (n = 0, 1, 2, 3) */
/* FFU0_n Timing Select Register (FUTSELn_CIM) (n = 0, 1, 2, 3) */
typedef struct {
  __REG32 SCKSEL        : 4;
  __REG32 MTUSEL        : 1;
  __REG32               : 3;
  __REG32 DIVEN         : 1;
  __REG32               : 7;
  __REG32 SCKDIV        :11;
  __REG32               : 5;
} __scux_fxtsel_cim_bits;

/* SSI Pin Mode Register (SSIPMD_CIM) */
typedef struct {
  __REG32 SSI2PMD       : 2;
  __REG32 SSI1PMD       : 2;
  __REG32 SSI012EN      : 1;
  __REG32               : 3;
  __REG32 SSI5PMD       : 2;
  __REG32 SSI4PMD       : 2;
  __REG32 SSI345EN      : 1;
  __REG32               : 1;
  __REG32 SSI3PMD       : 2;
  __REG32 SSI0CKS       : 1;
  __REG32 SSI1CKS       : 1;
  __REG32 SSI2CKS       : 1;
  __REG32 SSI3CKS       : 1;
  __REG32 SSI4CKS       : 1;
  __REG32 SSI5CKS       : 1;
  __REG32               :10;
} __scux_ssipmd_cim_bits;

/* SSI Control Register (SSICTRL_CIM) */
typedef struct {
  __REG32 SSI012REN     : 1;
  __REG32 SSI012TEN     : 1;
  __REG32               : 6;
  __REG32 SSI2RX        : 1;
  __REG32 SSI1RX        : 1;
  __REG32 SSI0RX        : 1;
  __REG32               : 1;
  __REG32 SSI2TX        : 1;
  __REG32 SSI1TX        : 1;
  __REG32 SSI0TX        : 1;
  __REG32               : 1;
  __REG32 SSI345REN     : 1;
  __REG32 SSI345TEN     : 1;
  __REG32               : 6;
  __REG32 SSI5RX        : 1;
  __REG32 SSI4RX        : 1;
  __REG32 SSI3RX        : 1;
  __REG32               : 1;
  __REG32 SSI5TX        : 1;
  __REG32 SSI4TX        : 1;
  __REG32 SSI3TX        : 1;
  __REG32               : 1;
} __scux_ssictrl_cim_bits;

/* SRCn Route Select Register (SRCRSELn_CIM) (n = 0, 1, 2, 3) */
/* MIX Route Select Register (MIXRSEL_CIM) */
typedef struct {
  __REG32 PLACE0        : 3;
  __REG32               : 1;
  __REG32 PLACE1        : 3;
  __REG32               : 1;
  __REG32 PLACE2        : 3;
  __REG32               : 1;
  __REG32 PLACE3        : 3;
  __REG32               : 1;
  __REG32 PLACE4        : 3;
  __REG32               : 1;
  __REG32 PLACE5        : 3;
  __REG32               : 1;
  __REG32 PLACE6        : 3;
  __REG32               : 1;
  __REG32 PLACE7        : 3;
  __REG32               : 1;
} __scux_srcrsel_mixrsel_cim_bits;

/* Sound Generator Control Register 1 (SGCR1) */
typedef struct {
  __REG8  DPF           : 3;
  __REG8  SGCK          : 2;
  __REG8                : 1;
  __REG8  STPM          : 1;
  __REG8  SGST          : 1;
} __sdg_sgcr1_bits;

/* Sound Generator Control Status Register (SGCSR) */
typedef struct {
  __REG8                : 6;
  __REG8  SGDEF         : 1;
  __REG8  SGIE          : 1;
} __sdg_sgcsr_bits;

/* Sound Generator Control Register 2 (SGCR2) */
typedef struct {
  __REG8                : 6;
  __REG8  TCHG          : 1;
  __REG8  SGEND         : 1;
} __sdg_sgcr2_bits;

/* Sound Generator Tone Frequency Register (SGTFR) */
typedef struct {
  __REG8  TONE          : 7;
  __REG8                : 1;
} __sdg_sgtfr_bits;

/* Command Setting Register (CE_CMD_SET) */
typedef struct {
  __REG32 DATW          : 2;
  __REG32               : 1;
  __REG32 SBIT          : 1;
  __REG32               : 2;
  __REG32 OPDM          : 1;
  __REG32 TBIT          : 1;
  __REG32 CRCSTE        : 1;
  __REG32               : 1;
  __REG32 CRC16C        : 1;
  __REG32               : 1;
  __REG32 RCRC7C        : 2;
  __REG32 RIDXC         : 2;
  __REG32 CMD12EN       : 1;
  __REG32 CMLTE         : 1;
  __REG32 DWEN          : 1;
  __REG32 WDAT          : 1;
  __REG32               : 1;
  __REG32 RBSY          : 1;
  __REG32 RTYP          : 2;
  __REG32 CMD           : 6;
  __REG32               : 2;
} __mmc_ce_cmd_set_bits;

/* Command Control Register (CE_CMD_CTRL) */
typedef struct {
  __REG32 BREAK         : 1;
  __REG32               :31;
} __mmc_ce_cmd_ctrl_bits;

/* Transfer Block Setting Register (CE_BLOCK_SET) */
typedef struct {
  __REG32 BLKSIZ        :16;
  __REG32 BLKCNT        :16;
} __mmc_ce_block_set_bits;

/* Clock Control Register (CE_CLK_CTRL) */
typedef struct {
  __REG32               : 4;
  __REG32 SRWDTO        : 4;
  __REG32 SRBSYTO       : 4;
  __REG32 SRSPTO        : 2;
  __REG32               : 2;
  __REG32 CLKDIV        : 4;
  __REG32               : 4;
  __REG32 CLKEN         : 1;
  __REG32               : 7;
} __mmc_ce_clk_ctrl_bits;

/* Buffer Access Configuration Register (CE_BUF_ACC) */
typedef struct {
  __REG32               :16;
  __REG32 ATYP          : 1;
  __REG32               : 7;
  __REG32 DMAREN        : 1;
  __REG32 DMAWEN        : 1;
  __REG32               : 6;
} __mmc_ce_buf_acc_bits;

/* Interrupt Flag Register (CE_INT) */
typedef struct {
  __REG32 RSPTO         : 1;
  __REG32 RBSYTO        : 1;
  __REG32 RDATTO        : 1;
  __REG32 WDATTO        : 1;
  __REG32 CRCSTO        : 1;
  __REG32               : 3;
  __REG32 RSPERR        : 1;
  __REG32 RIDXERR       : 1;
  __REG32 RDATAERR      : 1;
  __REG32 WDATERR       : 1;
  __REG32               : 2;
  __REG32 BUFVIO        : 1;
  __REG32 CMDVIO        : 1;
  __REG32 CRSPE         : 1;
  __REG32 RBSYE         : 1;
  __REG32               : 2;
  __REG32 BUFREN        : 1;
  __REG32 BUFWEN        : 1;
  __REG32 BUFRE         : 1;
  __REG32 DTRANE        : 1;
  __REG32 CMD12CRE      : 1;
  __REG32 CMD12RBE      : 1;
  __REG32 CMD12DRE      : 1;
  __REG32               : 5;
} __mmc_ce_int_bits;

/* Interrupt Enable Register (CE_INT_EN) */
typedef struct {
  __REG32 MRSPTO        : 1;
  __REG32 MRBSYTO       : 1;
  __REG32 MRDATTO       : 1;
  __REG32 MWDATTO       : 1;
  __REG32 MCRCSTO       : 1;
  __REG32               : 3;
  __REG32 MRSPERR       : 1;
  __REG32 MRIDXERR      : 1;
  __REG32 MRDATAERR     : 1;
  __REG32 MWDATERR      : 1;
  __REG32               : 2;
  __REG32 MBUFVIO       : 1;
  __REG32 MCMDVIO       : 1;
  __REG32 MCRSPE        : 1;
  __REG32 MRBSYE        : 1;
  __REG32               : 2;
  __REG32 MBUFREN       : 1;
  __REG32 MBUFWEN       : 1;
  __REG32 MBUFRE        : 1;
  __REG32 MDTRANE       : 1;
  __REG32 MCMD12CRE     : 1;
  __REG32 MCMD12RBE     : 1;
  __REG32 MCMD12DRE     : 1;
  __REG32               : 5;
} __mmc_ce_int_en_bits;

/* Status Register 1 (CE_HOST_STS1) */
typedef struct {
  __REG32 RCVBLK        :16;
  __REG32 DATASIG       : 8;
  __REG32 RSPIDX        : 6;
  __REG32 CMDSIG        : 1;
  __REG32 CMDSEQ        : 1;
} __mmc_ce_host_sts1_bits;

/* Status Register 2 (CE_HOST _STS2) */
typedef struct {
  __REG32               : 8;
  __REG32 STRSPTO       : 1;
  __REG32 AC12RSPTO     : 1;
  __REG32 RSPBSYTO      : 1;
  __REG32 AC12BSYTO     : 1;
  __REG32 CRCSTTO       : 1;
  __REG32 DATBSYTO      : 1;
  __REG32 STRDATTO      : 1;
  __REG32               : 1;
  __REG32 CRCST         : 3;
  __REG32               : 3;
  __REG32 RSPIDXE       : 1;
  __REG32 AC12IDXE      : 1;
  __REG32 RSPEBE        : 1;
  __REG32 AC12REBE      : 1;
  __REG32 RDATEBE       : 1;
  __REG32 CRCSTEBE      : 1;
  __REG32 RSPCRC7E      : 1;
  __REG32 AC12CRCE      : 1;
  __REG32 CRC16E        : 1;
  __REG32 CRCSTE        : 1;
} __mmc_ce_host_sts2_bits;

/* DMA Mode Setting Register (CE_DMA_MODE) */
typedef struct {
  __REG32 DMASEL        : 1;
  __REG32               :31;
} __mmc_ce_dma_mode_bits;

/* Card Detection/Port Control Register (CE_DETECT) */
typedef struct {
  __REG32               : 4;
  __REG32 MCDFALL       : 1;
  __REG32 MCDRISE       : 1;
  __REG32               : 6;
  __REG32 CDFALL        : 1;
  __REG32 CDRISE        : 1;
  __REG32 CDSIG         : 1;
  __REG32               :17;
} __mmc_ce_detect_bits;

/* Special Mode Setting Register (CE_ADD_MODE) */
typedef struct {
  __REG32               :19;
  __REG32 CLKMAIN       : 1;
  __REG32               :12;
} __mmc_ce_add_mode_bits;

/* Version Register (CE_VERSION) */
typedef struct {
  __REG32 VERSION       :16;
  __REG32               :15;
  __REG32 SWRST         : 1;
} __mmc_ce_version_bits;

/* PWM Control Register_n (PWCR_n) (n=1, 2) */
typedef struct {
  __REG8  CKS           : 3;
  __REG8  CST           : 1;
  __REG8  CMF           : 1;
  __REG8  IE            : 1;
  __REG8                : 2;
} __pwm_pwcr_bits;

/* PWM Polarity Register_n (PWPR_n) (n=1, 2) */
typedef struct {
  __REG8  OPSA          : 1;
  __REG8  OPSB          : 1;
  __REG8  OPSC          : 1;
  __REG8  OPSD          : 1;
  __REG8  OPSE          : 1;
  __REG8  OPSF          : 1;
  __REG8  OPSG          : 1;
  __REG8  OPSH          : 1;
} __pwm_pwpr_bits;

/* PWM Buffer Registers_nA, nC, nE, nG (PWBFR_nA, PWBFR_nC, PWBFR_nE, PWBFR_nG) (n = 1, 2) */
typedef struct {
  __REG16 DT            :10;
  __REG16               : 2;
  __REG16 OTS           : 1;
  __REG16               : 3;
} __pwm_pwbfr_bits;

/* PWM Buffer Trnasfer Control Register (PWBTCR) */
typedef struct {
  __REG8  BTC1A         : 1;
  __REG8  BTC1C         : 1;
  __REG8  BTC1E         : 1;
  __REG8  BTC1G         : 1;
  __REG8  BTC2A         : 1;
  __REG8  BTC2C         : 1;
  __REG8  BTC2E         : 1;
  __REG8  BTC2G         : 1;
} __pwm_pwbtcr_bits;

/* Port Register (P) */
typedef struct {
  __REG16 P0            : 1;
  __REG16 P1            : 1;
  __REG16 P2            : 1;
  __REG16 P3            : 1;
  __REG16 P4            : 1;
  __REG16 P5            : 1;
  __REG16 P6            : 1;
  __REG16 P7            : 1;
  __REG16 P8            : 1;
  __REG16 P9            : 1;
  __REG16 P10           : 1;
  __REG16 P11           : 1;
  __REG16 P12           : 1;
  __REG16 P13           : 1;
  __REG16 P14           : 1;
  __REG16 P15           : 1;
} __gpio_p_bits;

/* Port Set and Reset Register (P) */
typedef struct {
  __REG32 PSR0          : 1;
  __REG32 PSR1          : 1;
  __REG32 PSR2          : 1;
  __REG32 PSR3          : 1;
  __REG32 PSR4          : 1;
  __REG32 PSR5          : 1;
  __REG32 PSR6          : 1;
  __REG32 PSR7          : 1;
  __REG32 PSR8          : 1;
  __REG32 PSR9          : 1;
  __REG32 PSR10         : 1;
  __REG32 PSR11         : 1;
  __REG32 PSR12         : 1;
  __REG32 PSR13         : 1;
  __REG32 PSR14         : 1;
  __REG32 PSR15         : 1;
  __REG32 PSR16         : 1;
  __REG32 PSR17         : 1;
  __REG32 PSR18         : 1;
  __REG32 PSR19         : 1;
  __REG32 PSR20         : 1;
  __REG32 PSR21         : 1;
  __REG32 PSR22         : 1;
  __REG32 PSR23         : 1;
  __REG32 PSR24         : 1;
  __REG32 PSR25         : 1;
  __REG32 PSR26         : 1;
  __REG32 PSR27         : 1;
  __REG32 PSR28         : 1;
  __REG32 PSR29         : 1;
  __REG32 PSR30         : 1;
  __REG32 PSR31         : 1;
} __gpio_psr_bits;

/* Port Pin Read Register (PPR) */
typedef struct {
  __REG16 PPR0          : 1;
  __REG16 PPR1          : 1;
  __REG16 PPR2          : 1;
  __REG16 PPR3          : 1;
  __REG16 PPR4          : 1;
  __REG16 PPR5          : 1;
  __REG16 PPR6          : 1;
  __REG16 PPR7          : 1;
  __REG16 PPR8          : 1;
  __REG16 PPR9          : 1;
  __REG16 PPR10         : 1;
  __REG16 PPR11         : 1;
  __REG16 PPR12         : 1;
  __REG16 PPR13         : 1;
  __REG16 PPR14         : 1;
  __REG16 PPR15         : 1;
} __gpio_ppr_bits;

/* Port Mode Register (PM) */
typedef struct {
  __REG16 PM0           : 1;
  __REG16 PM1           : 1;
  __REG16 PM2           : 1;
  __REG16 PM3           : 1;
  __REG16 PM4           : 1;
  __REG16 PM5           : 1;
  __REG16 PM6           : 1;
  __REG16 PM7           : 1;
  __REG16 PM8           : 1;
  __REG16 PM9           : 1;
  __REG16 PM10          : 1;
  __REG16 PM11          : 1;
  __REG16 PM12          : 1;
  __REG16 PM13          : 1;
  __REG16 PM14          : 1;
  __REG16 PM15          : 1;
} __gpio_pm_bits;

/* Port Mode Control Register (PMC) */
typedef struct {
  __REG16 PMC0          : 1;
  __REG16 PMC1          : 1;
  __REG16 PMC2          : 1;
  __REG16 PMC3          : 1;
  __REG16 PMC4          : 1;
  __REG16 PMC5          : 1;
  __REG16 PMC6          : 1;
  __REG16 PMC7          : 1;
  __REG16 PMC8          : 1;
  __REG16 PMC9          : 1;
  __REG16 PMC10         : 1;
  __REG16 PMC11         : 1;
  __REG16 PMC12         : 1;
  __REG16 PMC13         : 1;
  __REG16 PMC14         : 1;
  __REG16 PMC15         : 1;
} __gpio_pmc_bits;

/* Port Function Control Register (PFC) */
typedef struct {
  __REG16 PFC0          : 1;
  __REG16 PFC1          : 1;
  __REG16 PFC2          : 1;
  __REG16 PFC3          : 1;
  __REG16 PFC4          : 1;
  __REG16 PFC5          : 1;
  __REG16 PFC6          : 1;
  __REG16 PFC7          : 1;
  __REG16 PFC8          : 1;
  __REG16 PFC9          : 1;
  __REG16 PFC10         : 1;
  __REG16 PFC11         : 1;
  __REG16 PFC12         : 1;
  __REG16 PFC13         : 1;
  __REG16 PFC14         : 1;
  __REG16 PFC15         : 1;
} __gpio_pfc_bits;

/* Port Function Control Expansion Register (PFCE) */
typedef struct {
  __REG16 PFCE0         : 1;
  __REG16 PFCE1         : 1;
  __REG16 PFCE2         : 1;
  __REG16 PFCE3         : 1;
  __REG16 PFCE4         : 1;
  __REG16 PFCE5         : 1;
  __REG16 PFCE6         : 1;
  __REG16 PFCE7         : 1;
  __REG16 PFCE8         : 1;
  __REG16 PFCE9         : 1;
  __REG16 PFCE10        : 1;
  __REG16 PFCE11        : 1;
  __REG16 PFCE12        : 1;
  __REG16 PFCE13        : 1;
  __REG16 PFCE14        : 1;
  __REG16 PFCE15        : 1;
} __gpio_pfce_bits;

/* Port NOT Register (PNOT) */
typedef struct {
  __REG16 PNOT0         : 1;
  __REG16 PNOT1         : 1;
  __REG16 PNOT2         : 1;
  __REG16 PNOT3         : 1;
  __REG16 PNOT4         : 1;
  __REG16 PNOT5         : 1;
  __REG16 PNOT6         : 1;
  __REG16 PNOT7         : 1;
  __REG16 PNOT8         : 1;
  __REG16 PNOT9         : 1;
  __REG16 PNOT10        : 1;
  __REG16 PNOT11        : 1;
  __REG16 PNOT12        : 1;
  __REG16 PNOT13        : 1;
  __REG16 PNOT14        : 1;
  __REG16 PNOT15        : 1;
} __gpio_pnot_bits;

/* Port Mode Set and Reset Register (PMSR) */
typedef struct {
  __REG32 PMSR0         : 1;
  __REG32 PMSR1         : 1;
  __REG32 PMSR2         : 1;
  __REG32 PMSR3         : 1;
  __REG32 PMSR4         : 1;
  __REG32 PMSR5         : 1;
  __REG32 PMSR6         : 1;
  __REG32 PMSR7         : 1;
  __REG32 PMSR8         : 1;
  __REG32 PMSR9         : 1;
  __REG32 PMSR10        : 1;
  __REG32 PMSR11        : 1;
  __REG32 PMSR12        : 1;
  __REG32 PMSR13        : 1;
  __REG32 PMSR14        : 1;
  __REG32 PMSR15        : 1;
  __REG32 PMSR16        : 1;
  __REG32 PMSR17        : 1;
  __REG32 PMSR18        : 1;
  __REG32 PMSR19        : 1;
  __REG32 PMSR20        : 1;
  __REG32 PMSR21        : 1;
  __REG32 PMSR22        : 1;
  __REG32 PMSR23        : 1;
  __REG32 PMSR24        : 1;
  __REG32 PMSR25        : 1;
  __REG32 PMSR26        : 1;
  __REG32 PMSR27        : 1;
  __REG32 PMSR28        : 1;
  __REG32 PMSR29        : 1;
  __REG32 PMSR30        : 1;
  __REG32 PMSR31        : 1;
} __gpio_pmsr_bits;

/* Port Mode Control Set and Reset Register (PMCSR) */
typedef struct {
  __REG32 PMCSR0        : 1;
  __REG32 PMCSR1        : 1;
  __REG32 PMCSR2        : 1;
  __REG32 PMCSR3        : 1;
  __REG32 PMCSR4        : 1;
  __REG32 PMCSR5        : 1;
  __REG32 PMCSR6        : 1;
  __REG32 PMCSR7        : 1;
  __REG32 PMCSR8        : 1;
  __REG32 PMCSR9        : 1;
  __REG32 PMCSR10       : 1;
  __REG32 PMCSR11       : 1;
  __REG32 PMCSR12       : 1;
  __REG32 PMCSR13       : 1;
  __REG32 PMCSR14       : 1;
  __REG32 PMCSR15       : 1;
  __REG32 PMCSR16       : 1;
  __REG32 PMCSR17       : 1;
  __REG32 PMCSR18       : 1;
  __REG32 PMCSR19       : 1;
  __REG32 PMCSR20       : 1;
  __REG32 PMCSR21       : 1;
  __REG32 PMCSR22       : 1;
  __REG32 PMCSR23       : 1;
  __REG32 PMCSR24       : 1;
  __REG32 PMCSR25       : 1;
  __REG32 PMCSR26       : 1;
  __REG32 PMCSR27       : 1;
  __REG32 PMCSR28       : 1;
  __REG32 PMCSR29       : 1;
  __REG32 PMCSR30       : 1;
  __REG32 PMCSR31       : 1;
} __gpio_pmcsr_bits;

/* Port Function Control Additional Expansion Register (PFCAE) */
typedef struct {
  __REG16 PFCAE0        : 1;
  __REG16 PFCAE1        : 1;
  __REG16 PFCAE2        : 1;
  __REG16 PFCAE3        : 1;
  __REG16 PFCAE4        : 1;
  __REG16 PFCAE5        : 1;
  __REG16 PFCAE6        : 1;
  __REG16 PFCAE7        : 1;
  __REG16 PFCAE8        : 1;
  __REG16 PFCAE9        : 1;
  __REG16 PFCAE10       : 1;
  __REG16 PFCAE11       : 1;
  __REG16 PFCAE12       : 1;
  __REG16 PFCAE13       : 1;
  __REG16 PFCAE14       : 1;
  __REG16 PFCAE15       : 1;
} __gpio_pfcae_bits;

/* Port Input Buffer Control Register (PIBC) */
typedef struct {
  __REG16 PIBC0         : 1;
  __REG16 PIBC1         : 1;
  __REG16 PIBC2         : 1;
  __REG16 PIBC3         : 1;
  __REG16 PIBC4         : 1;
  __REG16 PIBC5         : 1;
  __REG16 PIBC6         : 1;
  __REG16 PIBC7         : 1;
  __REG16 PIBC8         : 1;
  __REG16 PIBC9         : 1;
  __REG16 PIBC10        : 1;
  __REG16 PIBC11        : 1;
  __REG16 PIBC12        : 1;
  __REG16 PIBC13        : 1;
  __REG16 PIBC14        : 1;
  __REG16 PIBC15        : 1;
} __gpio_pibc_bits;

/* Port Bidirection Control Register (PBDC) */
typedef struct {
  __REG16 PBDC0         : 1;
  __REG16 PBDC1         : 1;
  __REG16 PBDC2         : 1;
  __REG16 PBDC3         : 1;
  __REG16 PBDC4         : 1;
  __REG16 PBDC5         : 1;
  __REG16 PBDC6         : 1;
  __REG16 PBDC7         : 1;
  __REG16 PBDC8         : 1;
  __REG16 PBDC9         : 1;
  __REG16 PBDC10        : 1;
  __REG16 PBDC11        : 1;
  __REG16 PBDC12        : 1;
  __REG16 PBDC13        : 1;
  __REG16 PBDC14        : 1;
  __REG16 PBDC15        : 1;
} __gpio_pbdc_bits;

/* Port IP Control Register (PIPC) */
typedef struct {
  __REG16 PIPC0         : 1;
  __REG16 PIPC1         : 1;
  __REG16 PIPC2         : 1;
  __REG16 PIPC3         : 1;
  __REG16 PIPC4         : 1;
  __REG16 PIPC5         : 1;
  __REG16 PIPC6         : 1;
  __REG16 PIPC7         : 1;
  __REG16 PIPC8         : 1;
  __REG16 PIPC9         : 1;
  __REG16 PIPC10        : 1;
  __REG16 PIPC11        : 1;
  __REG16 PIPC12        : 1;
  __REG16 PIPC13        : 1;
  __REG16 PIPC14        : 1;
  __REG16 PIPC15        : 1;
} __gpio_pipc_bits;

/* Serial Sound Interface Noise Canceler Register (SNCR) */
typedef struct {
  __REG32 SSI0NCE       : 1;
  __REG32 SSI1NCE       : 1;
  __REG32 SSI2NCE       : 1;
  __REG32 SSI3NCE       : 1;
  __REG32 SSI4NCE       : 1;
  __REG32 SSI5NCE       : 1;
  __REG32               :26;
} __gpio_sncr_bits;

/* Frequency Control Register (FRQCR) */
typedef struct {
  __REG16               : 8;
  __REG16 IFC           : 2;
  __REG16               : 2;
  __REG16 CKOEN         : 2;
  __REG16 CKOEN2        : 1;
  __REG16               : 1;
} __cpg_frqcr_bits;

/* Frequency Control Register 2 (FRQCR2) */
typedef struct {
  __REG16 GFC           : 2;
  __REG16               :14;
} __cpg_frqcr2_bits;

/* Standby Control Register 1 (STBCR1) */
typedef struct {
  __REG8                : 6;
  __REG8  DEEP          : 1;
  __REG8  STBY          : 1;
} __cpg_stbcr1_bits;

/* Standby Control Register 2 (STBCR2) */
typedef struct {
  __REG8  MSTP20        : 1;
  __REG8                : 6;
  __REG8  HIZ           : 1;
} __cpg_stbcr2_bits;

/* Standby Control Register 3 (STBCR3) */
typedef struct {
  __REG8  MSTP30        : 1;
  __REG8                : 1;
  __REG8  MSTP32        : 1;
  __REG8  MSTP33        : 1;
  __REG8  MSTP34        : 1;
  __REG8  MSTP35        : 1;
  __REG8  MSTP36        : 1;
  __REG8  MSTP37        : 1;
} __cpg_stbcr3_bits;

/* Standby Control Register 4 (STBCR4) */
typedef struct {
  __REG8  MSTP40        : 1;
  __REG8  MSTP41        : 1;
  __REG8  MSTP42        : 1;
  __REG8  MSTP43        : 1;
  __REG8  MSTP44        : 1;
  __REG8  MSTP45        : 1;
  __REG8  MSTP46        : 1;
  __REG8  MSTP47        : 1;
} __cpg_stbcr4_bits;

/* Standby Control Register 5 (STBCR5) */
typedef struct {
  __REG8  MSTP50        : 1;
  __REG8  MSTP51        : 1;
  __REG8  MSTP52        : 1;
  __REG8  MSTP53        : 1;
  __REG8  MSTP54        : 1;
  __REG8  MSTP55        : 1;
  __REG8  MSTP56        : 1;
  __REG8  MSTP57        : 1;
} __cpg_stbcr5_bits;

/* Standby Control Register 6 (STBCR6) */
typedef struct {
  __REG8  MSTP60        : 1;
  __REG8  MSTP61        : 1;
  __REG8  MSTP62        : 1;
  __REG8  MSTP63        : 1;
  __REG8  MSTP64        : 1;
  __REG8  MSTP65        : 1;
  __REG8  MSTP66        : 1;
  __REG8  MSTP67        : 1;
} __cpg_stbcr6_bits;

/* Standby Control Register 7 (STBCR7) */
typedef struct {
  __REG8  MSTP70        : 1;
  __REG8  MSTP71        : 1;
  __REG8                : 1;
  __REG8  MSTP73        : 1;
  __REG8  MSTP74        : 1;
  __REG8                : 1;
  __REG8  MSTP76        : 1;
  __REG8  MSTP77        : 1;
} __cpg_stbcr7_bits;

/* Standby Control Register 8 (STBCR8) */
typedef struct {
  __REG8                : 1;
  __REG8  MSTP81        : 1;
  __REG8                : 1;
  __REG8  MSTP83        : 1;
  __REG8  MSTP84        : 1;
  __REG8  MSTP85        : 1;
  __REG8  MSTP86        : 1;
  __REG8  MSTP87        : 1;
} __cpg_stbcr8_bits;

/* Standby Control Register 9 (STBCR9) */
typedef struct {
  __REG8  MSTP90        : 1;
  __REG8  MSTP91        : 1;
  __REG8  MSTP92        : 1;
  __REG8  MSTP93        : 1;
  __REG8  MSTP94        : 1;
  __REG8  MSTP95        : 1;
  __REG8  MSTP96        : 1;
  __REG8  MSTP97        : 1;
} __cpg_stbcr9_bits;

/* Standby Control Register 10 (STBCR10) */
typedef struct {
  __REG8  MSTP100       : 1;
  __REG8  MSTP101       : 1;
  __REG8  MSTP102       : 1;
  __REG8  MSTP103       : 1;
  __REG8  MSTP104       : 1;
  __REG8  MSTP105       : 1;
  __REG8  MSTP106       : 1;
  __REG8  MSTP107       : 1;
} __cpg_stbcr10_bits;

/* Standby Control Register 11 (STBCR11) */
typedef struct {
  __REG8  MSTP110       : 1;
  __REG8  MSTP111       : 1;
  __REG8  MSTP112       : 1;
  __REG8  MSTP113       : 1;
  __REG8  MSTP114       : 1;
  __REG8  MSTP115       : 1;
  __REG8                : 2;
} __cpg_stbcr11_bits;

/* Standby Control Register 12 (STBCR12) */
typedef struct {
  __REG8  MSTP120       : 1;
  __REG8  MSTP121       : 1;
  __REG8  MSTP122       : 1;
  __REG8  MSTP123       : 1;
  __REG8                : 4;
} __cpg_stbcr12_bits;

/* Standby Control Register 13 (STBCR13) */
typedef struct {
  __REG8                : 1;
  __REG8  MSTP131       : 1;
  __REG8  MSTP132       : 1;
  __REG8                : 5;
} __cpg_stbcr13_bits;

/* Software Reset Control Register 1 (SWRSTCR1) */
typedef struct {
  __REG8                : 1;
  __REG8  SRST11        : 1;
  __REG8  SRST12        : 1;
  __REG8  SRST13        : 1;
  __REG8  SRST14        : 1;
  __REG8  SRST15        : 1;
  __REG8  SRST16        : 1;
  __REG8  AXTALE        : 1;
} __cpg_swrstcr1_bits;

/* Software Reset Control Register 2 (SWRSTCR2) */
typedef struct {
  __REG8                : 1;
  __REG8  SRST21        : 1;
  __REG8  SRST22        : 1;
  __REG8  SRST23        : 1;
  __REG8  SRST24        : 1;
  __REG8  SRST25        : 1;
  __REG8  SRST26        : 1;
  __REG8  SRST27        : 1;
} __cpg_swrstcr2_bits;

/* Software Reset Control Register 3 (SWRSTCR3) */
typedef struct {
  __REG8                : 1;
  __REG8  SRST31        : 1;
  __REG8  SRST32        : 1;
  __REG8  SRST33        : 1;
  __REG8  SRST34        : 1;
  __REG8  SRST35        : 1;
  __REG8  SRST36        : 1;
  __REG8                : 1;
} __cpg_swrstcr3_bits;

/* System Control Register 1 (SYSCR1) */
typedef struct {
  __REG8  VRAME0        : 1;
  __REG8  VRAME1        : 1;
  __REG8  VRAME2        : 1;
  __REG8  VRAME3        : 1;
  __REG8  VRAME4        : 1;
  __REG8                : 3;
} __cpg_syscr1_bits;

/* System Control Register 2 (SYSCR2) */
typedef struct {
  __REG8  VRAMWE0       : 1;
  __REG8  VRAMWE1       : 1;
  __REG8  VRAMWE2       : 1;
  __REG8  VRAMWE3       : 1;
  __REG8  VRAMWE4       : 1;
  __REG8                : 3;
} __cpg_syscr2_bits;

/* System Control Register 3 (SYSCR3) */
typedef struct {
  __REG8  RRAMWE0       : 1;
  __REG8  RRAMWE1       : 1;
  __REG8  RRAMWE2       : 1;
  __REG8  RRAMWE3       : 1;
  __REG8                : 4;
} __cpg_syscr3_bits;

/* CPU Status Register (CPUSTS) */
typedef struct {
  __REG8                : 4;
  __REG8  ISBUSY0       : 1;
  __REG8                : 3;
} __cpg_cpusts_bits;

/* Standby Request Register 1 (STBREQ1) */
typedef struct {
  __REG8  STBRQ10       : 1;
  __REG8                : 2;
  __REG8  STBRQ13       : 1;
  __REG8                : 1;
  __REG8  STBRQ15       : 1;
  __REG8                : 2;
} __cpg_stbreq1_bits;

/* Standby Request Register 2 (STBREQ2) */
typedef struct {
  __REG8  STBRQ20       : 1;
  __REG8  STBRQ21       : 1;
  __REG8  STBRQ22       : 1;
  __REG8  STBRQ23       : 1;
  __REG8  STBRQ24       : 1;
  __REG8  STBRQ25       : 1;
  __REG8  STBRQ26       : 1;
  __REG8  STBRQ27       : 1;
} __cpg_stbreq2_bits;

/* Standby Acknowledgment Register 1 (STBACK1) */
typedef struct {
  __REG8  STBAK10       : 1;
  __REG8                : 2;
  __REG8  STBAK13       : 1;
  __REG8                : 1;
  __REG8  STBAK15       : 1;
  __REG8                : 2;
} __cpg_stback1_bits;

/* Standby Acknowledgment Register 2 (STBACK2) */
typedef struct {
  __REG8  STBAK20       : 1;
  __REG8  STBAK21       : 1;
  __REG8  STBAK22       : 1;
  __REG8  STBAK23       : 1;
  __REG8  STBAK24       : 1;
  __REG8  STBAK25       : 1;
  __REG8  STBAK26       : 1;
  __REG8  STBAK27       : 1;
} __cpg_stback2_bits;

/* On-Chip Data-Retention RAM Area Setting Register (RRAMKP) */
typedef struct {
  __REG8  RRAMKP0       : 1;
  __REG8  RRAMKP1       : 1;
  __REG8  RRAMKP2       : 1;
  __REG8  RRAMKP3       : 1;
  __REG8                : 4;
} __cpg_rramkp_bits;

/* Deep Standby Control Register (DSCTR) */
typedef struct {
  __REG8                : 6;
  __REG8 RAMBOOT        : 1;
  __REG8 EBUSKEEPE      : 1;
} __cpg_dsctr_bits;

/* Deep Standby Cancel Source Select Register (DSSSR) */
typedef struct {
  __REG16 P8_2          : 1;
  __REG16 P9_1          : 1;
  __REG16 P2_15         : 1;
  __REG16 P7_8          : 1;
  __REG16 P5_9          : 1;
  __REG16 P6_4          : 1;
  __REG16 RTCAR         : 1;
  __REG16               : 1;
  __REG16 NMI           : 1;
  __REG16 P3_3          : 1;
  __REG16 P8_7          : 1;
  __REG16 P2_12         : 1;
  __REG16 P3_1          : 1;
  __REG16 P3_9          : 1;
  __REG16 P6_2          : 1;
  __REG16               : 1;
} __cpg_dsssr_bits;

/* Deep Standby Cancel Edge Select Register (DSESR) */
typedef struct {
  __REG16 P8_2E         : 1;
  __REG16 P9_1E         : 1;
  __REG16 P2_15E        : 1;
  __REG16 P7_8E         : 1;
  __REG16 P5_9E         : 1;
  __REG16 P6_4E         : 1;
  __REG16               : 2;
  __REG16 NMIE          : 1;
  __REG16 P3_3E         : 1;
  __REG16 P8_7E         : 1;
  __REG16 P2_12E        : 1;
  __REG16 P3_1E         : 1;
  __REG16 P3_9E         : 1;
  __REG16 P6_2E         : 1;
  __REG16               : 1;
} __cpg_dsesr_bits;

/* Deep Standby Cancel Source Flag Register (DSFR) */
typedef struct {
  __REG16 P8_2F         : 1;
  __REG16 P9_1F         : 1;
  __REG16 P2_15F        : 1;
  __REG16 P7_8F         : 1;
  __REG16 P5_9F         : 1;
  __REG16 P6_4F         : 1;
  __REG16 RTCARF        : 1;
  __REG16               : 1;
  __REG16 NMIF          : 1;
  __REG16 P3_3F         : 1;
  __REG16 P8_7F         : 1;
  __REG16 P2_12F        : 1;
  __REG16 P3_1F         : 1;
  __REG16 P3_9F         : 1;
  __REG16 P6_2F         : 1;
  __REG16 IOKEEP        : 1;
} __cpg_dsfr_bits;

/* XTAL Crystal Oscillator Gain Control Register (XTALCTR) */
typedef struct {
  __REG8  GAIN0         : 1;
  __REG8  GAIN1         : 1;
  __REG8                : 6;
} __cpg_xtalctr_bits;


#endif    /* __IAR_SYSTEMS_ICC__ */

/* Common declarations  ****************************************************/
/***************************************************************************
 **
 **  L2CC (Level 2 Cache Controller)
 **
 ***************************************************************************/
__IO_REG32_BIT(L2CC_CACHE_ID,              	0x3FFFF000,__READ				,__l2cc_cache_id_bits);
__IO_REG32_BIT(L2CC_CACHE_TYPE,             0x3FFFF004,__READ				,__l2cc_cache_type_bits);
__IO_REG32_BIT(L2CC_CONTROL,              	0x3FFFF100,__READ_WRITE	,__l2cc_control_bits);
__IO_REG32_BIT(L2CC_AUX_CONTROL,            0x3FFFF104,__READ_WRITE	,__l2cc_aux_control_bits);
__IO_REG32_BIT(L2CC_TAG_RAM_CONTROL,        0x3FFFF108,__READ_WRITE	,__l2cc_tag_ram_control_bits);
__IO_REG32_BIT(L2CC_DATA_RAM_CONTROL,       0x3FFFF10C,__READ_WRITE	,__l2cc_tag_ram_control_bits);
__IO_REG32_BIT(L2CC_EV_COUNTER_CTRL,        0x3FFFF200,__READ_WRITE	,__l2cc_ev_counter_ctrl_bits);
__IO_REG32_BIT(L2CC_EV_COUNTER1_CFG,        0x3FFFF204,__READ_WRITE	,__l2cc_ev_counter_cfg_bits);
__IO_REG32_BIT(L2CC_EV_COUNTER0_CFG,        0x3FFFF208,__READ_WRITE	,__l2cc_ev_counter_cfg_bits);
__IO_REG32(		 L2CC_EV_COUNTER1,            0x3FFFF20C,__READ_WRITE	);
__IO_REG32(		 L2CC_EV_COUNTER0,            0x3FFFF210,__READ_WRITE	);
__IO_REG32_BIT(L2CC_INT_MASK,              	0x3FFFF214,__READ_WRITE	,__l2cc_int_mask_bits);
__IO_REG32_BIT(L2CC_INT_MASK_STATUS,        0x3FFFF218,__READ				,__l2cc_int_mask_bits);
__IO_REG32_BIT(L2CC_INT_RAW_STATUS,        	0x3FFFF21C,__READ				,__l2cc_int_mask_bits);
__IO_REG32(		 L2CC_INT_CLEAR,              0x3FFFF220,__WRITE			);
__IO_REG32(		 L2CC_CACHE_SYNC,             0x3FFFF730,__READ_WRITE	);
__IO_REG32(		 L2CC_INV_PA,             		0x3FFFF770,__READ_WRITE	);
__IO_REG32(		 L2CC_INV_WAY,             		0x3FFFF77C,__READ_WRITE	);
__IO_REG32(		 L2CC_CLEAN_PA,             	0x3FFFF7B0,__READ_WRITE	);
__IO_REG32(		 L2CC_CLEAN_INDEX,            0x3FFFF7B8,__READ_WRITE	);
__IO_REG32(		 L2CC_CLEAN_WAY,            	0x3FFFF7BC,__READ_WRITE	);
__IO_REG32(		 L2CC_CLEAN_INV_PA,           0x3FFFF7F0,__READ_WRITE	);
__IO_REG32(		 L2CC_CLEAN_INV_INDEX,        0x3FFFF7F8,__READ_WRITE	);
__IO_REG32(		 L2CC_CLEAN_INV_WAY,          0x3FFFF7FC,__READ_WRITE	);
__IO_REG32(		 L2CC_D_LOCKDOWN0,            0x3FFFF900,__READ_WRITE	);
__IO_REG32(		 L2CC_I_LOCKDOWN0,            0x3FFFF904,__READ_WRITE	);
__IO_REG32(		 L2CC_D_LOCKDOWN1,            0x3FFFF908,__READ_WRITE	);
__IO_REG32(		 L2CC_I_LOCKDOWN1,            0x3FFFF90C,__READ_WRITE	);
__IO_REG32(		 L2CC_D_LOCKDOWN2,            0x3FFFF910,__READ_WRITE	);
__IO_REG32(		 L2CC_I_LOCKDOWN2,            0x3FFFF914,__READ_WRITE	);
__IO_REG32(		 L2CC_D_LOCKDOWN3,            0x3FFFF918,__READ_WRITE	);
__IO_REG32(		 L2CC_I_LOCKDOWN3,            0x3FFFF91C,__READ_WRITE	);
__IO_REG32(		 L2CC_D_LOCKDOWN4,            0x3FFFF920,__READ_WRITE	);
__IO_REG32(		 L2CC_I_LOCKDOWN4,            0x3FFFF924,__READ_WRITE	);
__IO_REG32(		 L2CC_D_LOCKDOWN5,            0x3FFFF928,__READ_WRITE	);
__IO_REG32(		 L2CC_I_LOCKDOWN5,            0x3FFFF92C,__READ_WRITE	);
__IO_REG32(		 L2CC_D_LOCKDOWN6,            0x3FFFF930,__READ_WRITE	);
__IO_REG32(		 L2CC_I_LOCKDOWN6,            0x3FFFF934,__READ_WRITE	);
__IO_REG32(		 L2CC_D_LOCKDOWN7,            0x3FFFF938,__READ_WRITE	);
__IO_REG32(		 L2CC_I_LOCKDOWN7,            0x3FFFF93C,__READ_WRITE	);
__IO_REG32_BIT(L2CC_LOCK_LINE_EN,           0x3FFFF950,__READ_WRITE	,__l2cc_lock_line_en_bits);
__IO_REG32_BIT(L2CC_UNLOCK_WAY,            	0x3FFFF954,__READ_WRITE	,__l2cc_unlock_way_bits);
__IO_REG32_BIT(L2CC_ADDR_FILTERING_START,   0x3FFFFC00,__READ_WRITE	,__l2cc_addr_filtering_start_bits);
__IO_REG32(		 L2CC_ADDR_FILTERING_END,     0x3FFFFC04,__READ_WRITE	);
__IO_REG32_BIT(L2CC_DEBUG_CTRL,           	0x3FFFFF40,__READ_WRITE	,__l2cc_debug_ctrl_bits);
__IO_REG32_BIT(L2CC_PREFETCH_CTRL,          0x3FFFFF60,__READ_WRITE	,__l2cc_prefetch_ctrl_bits);
__IO_REG32_BIT(L2CC_POWER_CTRL,           	0x3FFFFF80,__READ_WRITE	,__l2cc_power_ctrl_bits);

/***************************************************************************
 **
 **  LSI (Clock Pulse Generator)
 **
 ***************************************************************************/
__IO_REG32_BIT(LSI_RMPR,              			0xFCFE1A00,__READ_WRITE,__lsi_rmpr_bits);
__IO_REG32_BIT(LSI_AXIBUSCTL0,              0xFCFE1A04,__READ_WRITE,__lsi_axibusctl0_bits);
__IO_REG32_BIT(LSI_AXIBUSCTL1,              0xFCFE1A08,__READ_WRITE,__lsi_axibusctl1_bits);
__IO_REG32_BIT(LSI_AXIBUSCTL2,              0xFCFE1A0C,__READ_WRITE,__lsi_axibusctl2_bits);
__IO_REG32_BIT(LSI_AXIBUSCTL3,              0xFCFE1A10,__READ_WRITE,__lsi_axibusctl3_bits);
__IO_REG32_BIT(LSI_AXIBUSCTL4,              0xFCFE1A14,__READ_WRITE,__lsi_axibusctl4_bits);
__IO_REG32_BIT(LSI_AXIBUSCTL5,              0xFCFE1A18,__READ_WRITE,__lsi_axibusctl5_bits);
__IO_REG32_BIT(LSI_AXIBUSCTL6,              0xFCFE1A1C,__READ_WRITE,__lsi_axibusctl6_bits);
__IO_REG32_BIT(LSI_AXIBUSCTL7,              0xFCFE1A20,__READ_WRITE,__lsi_axibusctl7_bits);
__IO_REG32_BIT(LSI_AXIBUSCTL8,              0xFCFE1A24,__READ_WRITE,__lsi_axibusctl8_bits);
__IO_REG32_BIT(LSI_AXIBUSCTL9,              0xFCFE1A28,__READ_WRITE,__lsi_axibusctl9_bits);
__IO_REG32_BIT(LSI_AXIBUSCTL10,             0xFCFE1A2C,__READ_WRITE,__lsi_axibusctl10_bits);
__IO_REG32_BIT(LSI_AXIRERRCTL0,             0xFCFE1A30,__READ_WRITE,__lsi_axirerrctl0_bits);
__IO_REG32_BIT(LSI_AXIRERRCTL1,             0xFCFE1A34,__READ_WRITE,__lsi_axirerrctl1_bits);
__IO_REG32_BIT(LSI_AXIRERRCTL2,             0xFCFE1A38,__READ_WRITE,__lsi_axirerrctl2_bits);
__IO_REG32_BIT(LSI_AXIRERRCTL3,             0xFCFE1A3C,__READ_WRITE,__lsi_axirerrctl3_bits);
__IO_REG32_BIT(LSI_AXIRERRST0,              0xFCFE1A40,__READ_WRITE,__lsi_axirerrst0_bits);
__IO_REG32_BIT(LSI_AXIRERRST1,              0xFCFE1A44,__READ_WRITE,__lsi_axirerrst1_bits);
__IO_REG32_BIT(LSI_AXIRERRST2,              0xFCFE1A48,__READ_WRITE,__lsi_axirerrst2_bits);
__IO_REG32_BIT(LSI_AXIRERRST3,              0xFCFE1A4C,__READ_WRITE,__lsi_axirerrst3_bits);
__IO_REG32_BIT(LSI_AXIRERRCLR0,             0xFCFE1A50,__READ_WRITE,__lsi_axirerrclr0_bits);
__IO_REG32_BIT(LSI_AXIRERRCLR1,             0xFCFE1A54,__READ_WRITE,__lsi_axirerrclr1_bits);
__IO_REG32_BIT(LSI_AXIRERRCLR2,             0xFCFE1A58,__READ_WRITE,__lsi_axirerrclr2_bits);
__IO_REG32_BIT(LSI_AXIRERRCLR3,             0xFCFE1A5C,__READ_WRITE,__lsi_axirerrclr3_bits);

/***************************************************************************
 **
 **  CPG (Clock Pulse Generator)
 **
 ***************************************************************************/
__IO_REG16_BIT(CPG_FRQCR,                   0xFCFE0010,__READ_WRITE,__cpg_frqcr_bits);
__IO_REG16_BIT(CPG_FRQCR2,                  0xFCFE0014,__READ_WRITE,__cpg_frqcr2_bits);
__IO_REG8_BIT( CPG_STBCR1,                  0xFCFE0020,__READ_WRITE,__cpg_stbcr1_bits);
__IO_REG8_BIT( CPG_STBCR2,                  0xFCFE0024,__READ_WRITE,__cpg_stbcr2_bits);
__IO_REG8_BIT( CPG_STBCR3,                  0xFCFE0420,__READ_WRITE,__cpg_stbcr3_bits);
__IO_REG8_BIT( CPG_STBCR4,                  0xFCFE0424,__READ_WRITE,__cpg_stbcr4_bits);
__IO_REG8_BIT( CPG_STBCR5,                  0xFCFE0428,__READ_WRITE,__cpg_stbcr5_bits);
__IO_REG8_BIT( CPG_STBCR6,                  0xFCFE042C,__READ_WRITE,__cpg_stbcr6_bits);
__IO_REG8_BIT( CPG_STBCR7,                  0xFCFE0430,__READ_WRITE,__cpg_stbcr7_bits);
__IO_REG8_BIT( CPG_STBCR8,                  0xFCFE0434,__READ_WRITE,__cpg_stbcr8_bits);
__IO_REG8_BIT( CPG_STBCR9,                  0xFCFE0438,__READ_WRITE,__cpg_stbcr9_bits);
__IO_REG8_BIT( CPG_STBCR10,                 0xFCFE043C,__READ_WRITE,__cpg_stbcr10_bits);
__IO_REG8_BIT( CPG_STBCR11,                 0xFCFE0440,__READ_WRITE,__cpg_stbcr11_bits);
__IO_REG8_BIT( CPG_STBCR12,                 0xFCFE0444,__READ_WRITE,__cpg_stbcr12_bits);
__IO_REG8_BIT( CPG_STBCR13,                 0xFCFE0470,__READ_WRITE,__cpg_stbcr13_bits);
__IO_REG8_BIT( CPG_SWRSTCR1,                0xFCFE0460,__READ_WRITE,__cpg_swrstcr1_bits);
__IO_REG8_BIT( CPG_SWRSTCR2,                0xFCFE0464,__READ_WRITE,__cpg_swrstcr2_bits);
__IO_REG8_BIT( CPG_SWRSTCR3,                0xFCFE0468,__READ_WRITE,__cpg_swrstcr3_bits);
__IO_REG8_BIT( CPG_SYSCR1,                  0xFCFE0400,__READ_WRITE,__cpg_syscr1_bits);
__IO_REG8_BIT( CPG_SYSCR2,                  0xFCFE0404,__READ_WRITE,__cpg_syscr2_bits);
__IO_REG8_BIT( CPG_SYSCR3,                  0xFCFE0408,__READ_WRITE,__cpg_syscr3_bits);
__IO_REG8_BIT( CPG_CPUSTS,                  0xFCFE0018,__READ      ,__cpg_cpusts_bits);
__IO_REG8_BIT( CPG_STBREQ1,                 0xFCFE0030,__READ_WRITE,__cpg_stbreq1_bits);
__IO_REG8_BIT( CPG_STBREQ2,                 0xFCFE0034,__READ_WRITE,__cpg_stbreq2_bits);
__IO_REG8_BIT( CPG_STBACK1,                 0xFCFE0040,__READ      ,__cpg_stback1_bits);
__IO_REG8_BIT( CPG_STBACK2,                 0xFCFE0044,__READ      ,__cpg_stback2_bits);
__IO_REG8_BIT( CPG_RRAMKP,                  0xFCFE1800,__READ_WRITE,__cpg_rramkp_bits);
__IO_REG8_BIT( CPG_DSCTR,                   0xFCFE1802,__READ_WRITE,__cpg_dsctr_bits);
__IO_REG16_BIT(CPG_DSSSR,                   0xFCFE1804,__READ_WRITE,__cpg_dsssr_bits);
__IO_REG16_BIT(CPG_DSESR,                   0xFCFE1806,__READ_WRITE,__cpg_dsesr_bits);
__IO_REG16_BIT(CPG_DSFR,                    0xFCFE1808,__READ_WRITE,__cpg_dsfr_bits);
__IO_REG8_BIT( CPG_XTALCTR,                 0xFCFE1810,__READ_WRITE,__cpg_xtalctr_bits);


/***************************************************************************
 **
 **  INTC (Interrupt Controller)
 **
 ***************************************************************************/
__IO_REG16_BIT(INTC_ICR0,                   0xFCFEF800,__READ_WRITE,__intc_icr0_bits);
__IO_REG16_BIT(INTC_ICR1,                   0xFCFEF802,__READ_WRITE,__intc_icr1_bits);
__IO_REG16_BIT(INTC_IRQRR,                  0xFCFEF804,__READ_WRITE,__intc_irqrr_bits);
__IO_REG32(    INTC_ICDDCR,                 0xE8201000,__READ_WRITE);
__IO_REG32(    INTC_ICDICTR,                0xE8201004,__READ      );
__IO_REG32(    INTC_ICDIIDR,                0xE8201008,__READ      );
__IO_REG32(    INTC_ICDISR0,                0xE8201080,__READ_WRITE);
__IO_REG32(    INTC_ICDISR1,                0xE8201084,__READ_WRITE);
__IO_REG32(    INTC_ICDISR2,                0xE8201088,__READ_WRITE);
__IO_REG32(    INTC_ICDISR3,                0xE820108C,__READ_WRITE);
__IO_REG32(    INTC_ICDISR4,                0xE8201090,__READ_WRITE);
__IO_REG32(    INTC_ICDISR5,                0xE8201094,__READ_WRITE);
__IO_REG32(    INTC_ICDISR6,                0xE8201098,__READ_WRITE);
__IO_REG32(    INTC_ICDISR7,                0xE820109C,__READ_WRITE);
__IO_REG32(    INTC_ICDISR8,                0xE82010A0,__READ_WRITE);
__IO_REG32(    INTC_ICDISR9,                0xE82010A4,__READ_WRITE);
__IO_REG32(    INTC_ICDISR10,               0xE82010A8,__READ_WRITE);
__IO_REG32(    INTC_ICDISR11,               0xE82010AC,__READ_WRITE);
__IO_REG32(    INTC_ICDISR12,               0xE82010B0,__READ_WRITE);
__IO_REG32(    INTC_ICDISR13,               0xE82010B4,__READ_WRITE);
__IO_REG32(    INTC_ICDISR14,               0xE82010B8,__READ_WRITE);
__IO_REG32(    INTC_ICDISR15,               0xE82010BC,__READ_WRITE);
__IO_REG32(    INTC_ICDISR16,               0xE82010C0,__READ_WRITE);
__IO_REG32(    INTC_ICDISR17,               0xE82010C4,__READ_WRITE);
__IO_REG32(    INTC_ICDISR18,               0xE82010C8,__READ_WRITE);
__IO_REG32(    INTC_ICDISER0,               0xE8201100,__READ_WRITE);
__IO_REG32(    INTC_ICDISER1,               0xE8201104,__READ_WRITE);
__IO_REG32(    INTC_ICDISER2,               0xE8201108,__READ_WRITE);
__IO_REG32(    INTC_ICDISER3,               0xE820110C,__READ_WRITE);
__IO_REG32(    INTC_ICDISER4,               0xE8201110,__READ_WRITE);
__IO_REG32(    INTC_ICDISER5,               0xE8201114,__READ_WRITE);
__IO_REG32(    INTC_ICDISER6,               0xE8201118,__READ_WRITE);
__IO_REG32(    INTC_ICDISER7,               0xE820111C,__READ_WRITE);
__IO_REG32(    INTC_ICDISER8,               0xE8201120,__READ_WRITE);
__IO_REG32(    INTC_ICDISER9,               0xE8201124,__READ_WRITE);
__IO_REG32(    INTC_ICDISER10,              0xE8201128,__READ_WRITE);
__IO_REG32(    INTC_ICDISER11,              0xE820112C,__READ_WRITE);
__IO_REG32(    INTC_ICDISER12,              0xE8201130,__READ_WRITE);
__IO_REG32(    INTC_ICDISER13,              0xE8201134,__READ_WRITE);
__IO_REG32(    INTC_ICDISER14,              0xE8201138,__READ_WRITE);
__IO_REG32(    INTC_ICDISER15,              0xE820113C,__READ_WRITE);
__IO_REG32(    INTC_ICDISER16,              0xE8201140,__READ_WRITE);
__IO_REG32(    INTC_ICDISER17,              0xE8201144,__READ_WRITE);
__IO_REG32(    INTC_ICDISER18,              0xE8201148,__READ_WRITE);
__IO_REG32(    INTC_ICDICER0,               0xE8201180,__READ_WRITE);
__IO_REG32(    INTC_ICDICER1,               0xE8201184,__READ_WRITE);
__IO_REG32(    INTC_ICDICER2,               0xE8201188,__READ_WRITE);
__IO_REG32(    INTC_ICDICER3,               0xE820118C,__READ_WRITE);
__IO_REG32(    INTC_ICDICER4,               0xE8201190,__READ_WRITE);
__IO_REG32(    INTC_ICDICER5,               0xE8201194,__READ_WRITE);
__IO_REG32(    INTC_ICDICER6,               0xE8201198,__READ_WRITE);
__IO_REG32(    INTC_ICDICER7,               0xE820119C,__READ_WRITE);
__IO_REG32(    INTC_ICDICER8,               0xE82011A0,__READ_WRITE);
__IO_REG32(    INTC_ICDICER9,               0xE82011A4,__READ_WRITE);
__IO_REG32(    INTC_ICDICER10,              0xE82011A8,__READ_WRITE);
__IO_REG32(    INTC_ICDICER11,              0xE82011AC,__READ_WRITE);
__IO_REG32(    INTC_ICDICER12,              0xE82011B0,__READ_WRITE);
__IO_REG32(    INTC_ICDICER13,              0xE82011B4,__READ_WRITE);
__IO_REG32(    INTC_ICDICER14,              0xE82011B8,__READ_WRITE);
__IO_REG32(    INTC_ICDICER15,              0xE82011BC,__READ_WRITE);
__IO_REG32(    INTC_ICDICER16,              0xE82011C0,__READ_WRITE);
__IO_REG32(    INTC_ICDICER17,              0xE82011C4,__READ_WRITE);
__IO_REG32(    INTC_ICDICER18,              0xE82011C8,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR0,               0xE8201200,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR1,               0xE8201204,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR2,               0xE8201208,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR3,               0xE820120C,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR4,               0xE8201210,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR5,               0xE8201214,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR6,               0xE8201218,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR7,               0xE820121C,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR8,               0xE8201220,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR9,               0xE8201224,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR10,              0xE8201228,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR11,              0xE820122C,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR12,              0xE8201230,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR13,              0xE8201234,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR14,              0xE8201238,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR15,              0xE820123C,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR16,              0xE8201240,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR17,              0xE8201244,__READ_WRITE);
__IO_REG32(    INTC_ICDISPR18,              0xE8201248,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR0,               0xE8201280,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR1,               0xE8201284,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR2,               0xE8201288,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR3,               0xE820128C,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR4,               0xE8201290,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR5,               0xE8201294,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR6,               0xE8201298,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR7,               0xE820129C,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR8,               0xE82012A0,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR9,               0xE82012A4,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR10,              0xE82012A8,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR11,              0xE82012AC,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR12,              0xE82012B0,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR13,              0xE82012B4,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR14,              0xE82012B8,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR15,              0xE82012BC,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR16,              0xE82012C0,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR17,              0xE82012C4,__READ_WRITE);
__IO_REG32(    INTC_ICDICPR18,              0xE82012C8,__READ_WRITE);
__IO_REG32(    INTC_ICDABR0,                0xE8201300,__READ_WRITE);
__IO_REG32(    INTC_ICDABR1,                0xE8201304,__READ_WRITE);
__IO_REG32(    INTC_ICDABR2,                0xE8201308,__READ_WRITE);
__IO_REG32(    INTC_ICDABR3,                0xE820130C,__READ_WRITE);
__IO_REG32(    INTC_ICDABR4,                0xE8201310,__READ_WRITE);
__IO_REG32(    INTC_ICDABR5,                0xE8201314,__READ_WRITE);
__IO_REG32(    INTC_ICDABR6,                0xE8201318,__READ_WRITE);
__IO_REG32(    INTC_ICDABR7,                0xE820131C,__READ_WRITE);
__IO_REG32(    INTC_ICDABR8,                0xE8201320,__READ_WRITE);
__IO_REG32(    INTC_ICDABR9,                0xE8201324,__READ_WRITE);
__IO_REG32(    INTC_ICDABR10,               0xE8201328,__READ_WRITE);
__IO_REG32(    INTC_ICDABR11,               0xE820132C,__READ_WRITE);
__IO_REG32(    INTC_ICDABR12,               0xE8201330,__READ_WRITE);
__IO_REG32(    INTC_ICDABR13,               0xE8201334,__READ_WRITE);
__IO_REG32(    INTC_ICDABR14,               0xE8201338,__READ_WRITE);
__IO_REG32(    INTC_ICDABR15,               0xE820133C,__READ_WRITE);
__IO_REG32(    INTC_ICDABR16,               0xE8201340,__READ_WRITE);
__IO_REG32(    INTC_ICDABR17,               0xE8201344,__READ_WRITE);
__IO_REG32(    INTC_ICDABR18,               0xE8201348,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR0,                0xE8201400,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR1,                0xE8201404,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR2,                0xE8201408,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR3,                0xE820140C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR4,                0xE8201410,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR5,                0xE8201414,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR6,                0xE8201418,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR7,                0xE820141C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR8,                0xE8201420,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR9,                0xE8201424,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR10,               0xE8201428,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR11,               0xE820142C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR12,               0xE8201430,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR13,               0xE8201434,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR14,               0xE8201438,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR15,               0xE820143C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR16,               0xE8201440,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR17,               0xE8201444,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR18,               0xE8201448,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR19,               0xE820144C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR20,               0xE8201450,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR21,               0xE8201454,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR22,               0xE8201458,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR23,               0xE820145C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR24,               0xE8201460,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR25,               0xE8201464,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR26,               0xE8201468,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR27,               0xE820146C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR28,               0xE8201470,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR29,               0xE8201474,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR30,               0xE8201478,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR31,               0xE820147C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR32,               0xE8201480,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR33,               0xE8201484,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR34,               0xE8201488,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR35,               0xE820148C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR36,               0xE8201490,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR37,               0xE8201494,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR38,               0xE8201498,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR39,               0xE820149C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR40,               0xE82014A0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR41,               0xE82014A4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR42,               0xE82014A8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR43,               0xE82014AC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR44,               0xE82014B0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR45,               0xE82014B4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR46,               0xE82014B8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR47,               0xE82014BC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR48,               0xE82014C0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR49,               0xE82014C4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR50,               0xE82014C8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR51,               0xE82014CC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR52,               0xE82014D0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR53,               0xE82014D4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR54,               0xE82014D8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR55,               0xE82014DC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR56,               0xE82014E0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR57,               0xE82014E4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR58,               0xE82014E8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR59,               0xE82014EC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR60,               0xE82014F0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR61,               0xE82014F4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR62,               0xE82014F8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR63,               0xE82014FC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR64,               0xE8201500,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR65,               0xE8201504,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR66,               0xE8201508,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR67,               0xE820150C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR68,               0xE8201510,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR69,               0xE8201514,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR70,               0xE8201518,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR71,               0xE820151C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR72,               0xE8201520,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR73,               0xE8201524,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR74,               0xE8201528,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR75,               0xE820152C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR76,               0xE8201530,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR77,               0xE8201534,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR78,               0xE8201538,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR79,               0xE820153C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR80,               0xE8201540,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR81,               0xE8201544,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR82,               0xE8201548,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR83,               0xE820154C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR84,               0xE8201550,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR85,               0xE8201554,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR86,               0xE8201558,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR87,               0xE820155C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR88,               0xE8201560,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR89,               0xE8201564,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR90,               0xE8201568,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR91,               0xE820156C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR92,               0xE8201570,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR93,               0xE8201574,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR94,               0xE8201578,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR95,               0xE820157C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR96,               0xE8201580,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR97,               0xE8201584,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR98,               0xE8201588,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR99,               0xE820158C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR100,              0xE8201590,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR101,              0xE8201594,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR102,              0xE8201598,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR103,              0xE820159C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR104,              0xE82015A0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR105,              0xE82015A4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR106,              0xE82015A8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR107,              0xE82015AC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR108,              0xE82015B0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR109,              0xE82015B4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR110,              0xE82015B8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR111,              0xE82015BC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR112,              0xE82015C0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR113,              0xE82015C4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR114,              0xE82015C8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR115,              0xE82015CC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR116,              0xE82015D0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR117,              0xE82015D4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR118,              0xE82015D8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR119,              0xE82015DC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR120,              0xE82015E0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR121,              0xE82015E4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR122,              0xE82015E8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR123,              0xE82015EC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR124,              0xE82015F0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR125,              0xE82015F4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR126,              0xE82015F8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR127,              0xE82015FC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR128,              0xE8201600,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR129,              0xE8201604,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR130,              0xE8201608,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR131,              0xE820160C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR132,              0xE8201610,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR133,              0xE8201614,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR134,              0xE8201618,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR135,              0xE820161C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR136,              0xE8201620,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR137,              0xE8201624,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR138,              0xE8201628,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR139,              0xE820162C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR140,              0xE8201630,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR141,              0xE8201634,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR142,              0xE8201638,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR143,              0xE820163C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR144,              0xE8201640,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR145,              0xE8201644,__READ_WRITE);
__IO_REG32(    INTC_ICDIPR146,              0xE8201648,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR0,               0xE8201800,__READ      );
__IO_REG32(    INTC_ICDIPTR1,               0xE8201804,__READ      );
__IO_REG32(    INTC_ICDIPTR2,               0xE8201808,__READ      );
__IO_REG32(    INTC_ICDIPTR3,               0xE820180C,__READ      );
__IO_REG32(    INTC_ICDIPTR4,               0xE8201810,__READ      );
__IO_REG32(    INTC_ICDIPTR5,               0xE8201814,__READ      );
__IO_REG32(    INTC_ICDIPTR6,               0xE8201818,__READ      );
__IO_REG32(    INTC_ICDIPTR7,               0xE820181C,__READ      );
__IO_REG32(    INTC_ICDIPTR8,               0xE8201820,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR9,               0xE8201824,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR10,              0xE8201828,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR11,              0xE820182C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR12,              0xE8201830,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR13,              0xE8201834,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR14,              0xE8201838,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR15,              0xE820183C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR16,              0xE8201840,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR17,              0xE8201844,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR18,              0xE8201848,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR19,              0xE820184C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR20,              0xE8201850,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR21,              0xE8201854,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR22,              0xE8201858,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR23,              0xE820185C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR24,              0xE8201860,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR25,              0xE8201864,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR26,              0xE8201868,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR27,              0xE820186C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR28,              0xE8201870,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR29,              0xE8201874,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR30,              0xE8201878,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR31,              0xE820187C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR32,              0xE8201880,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR33,              0xE8201884,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR34,              0xE8201888,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR35,              0xE820188C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR36,              0xE8201890,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR37,              0xE8201894,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR38,              0xE8201898,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR39,              0xE820189C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR40,              0xE82018A0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR41,              0xE82018A4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR42,              0xE82018A8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR43,              0xE82018AC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR44,              0xE82018B0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR45,              0xE82018B4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR46,              0xE82018B8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR47,              0xE82018BC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR48,              0xE82018C0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR49,              0xE82018C4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR50,              0xE82018C8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR51,              0xE82018CC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR52,              0xE82018D0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR53,              0xE82018D4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR54,              0xE82018D8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR55,              0xE82018DC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR56,              0xE82018E0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR57,              0xE82018E4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR58,              0xE82018E8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR59,              0xE82018EC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR60,              0xE82018F0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR61,              0xE82018F4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR62,              0xE82018F8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR63,              0xE82018FC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR64,              0xE8201900,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR65,              0xE8201904,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR66,              0xE8201908,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR67,              0xE820190C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR68,              0xE8201910,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR69,              0xE8201914,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR70,              0xE8201918,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR71,              0xE820191C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR72,              0xE8201920,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR73,              0xE8201924,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR74,              0xE8201928,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR75,              0xE820192C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR76,              0xE8201930,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR77,              0xE8201934,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR78,              0xE8201938,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR79,              0xE820193C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR80,              0xE8201940,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR81,              0xE8201944,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR82,              0xE8201948,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR83,              0xE820194C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR84,              0xE8201950,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR85,              0xE8201954,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR86,              0xE8201958,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR87,              0xE820195C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR88,              0xE8201960,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR89,              0xE8201964,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR90,              0xE8201968,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR91,              0xE820196C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR92,              0xE8201970,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR93,              0xE8201974,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR94,              0xE8201978,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR95,              0xE820197C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR96,              0xE8201980,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR97,              0xE8201984,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR98,              0xE8201988,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR99,              0xE820198C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR100,             0xE8201990,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR101,             0xE8201994,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR102,             0xE8201998,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR103,             0xE820199C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR104,             0xE82019A0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR105,             0xE82019A4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR106,             0xE82019A8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR107,             0xE82019AC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR108,             0xE82019B0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR109,             0xE82019B4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR110,             0xE82019B8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR111,             0xE82019BC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR112,             0xE82019C0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR113,             0xE82019C4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR114,             0xE82019C8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR115,             0xE82019CC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR116,             0xE82019D0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR117,             0xE82019D4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR118,             0xE82019D8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR119,             0xE82019DC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR120,             0xE82019E0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR121,             0xE82019E4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR122,             0xE82019E8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR123,             0xE82019EC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR124,             0xE82019F0,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR125,             0xE82019F4,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR126,             0xE82019F8,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR127,             0xE82019FC,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR128,             0xE8201A00,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR129,             0xE8201A04,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR130,             0xE8201A08,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR131,             0xE8201A0C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR132,             0xE8201A10,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR133,             0xE8201A14,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR134,             0xE8201A18,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR135,             0xE8201A1C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR136,             0xE8201A20,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR137,             0xE8201A24,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR138,             0xE8201A28,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR139,             0xE8201A2C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR140,             0xE8201A30,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR141,             0xE8201A34,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR142,             0xE8201A38,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR143,             0xE8201A3C,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR144,             0xE8201A40,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR145,             0xE8201A44,__READ_WRITE);
__IO_REG32(    INTC_ICDIPTR146,             0xE8201A48,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR0,               0xE8201C00,__READ      );
__IO_REG32(    INTC_ICDICFR1,               0xE8201C04,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR2,               0xE8201C08,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR3,               0xE8201C0C,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR4,               0xE8201C10,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR5,               0xE8201C14,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR6,               0xE8201C18,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR7,               0xE8201C1C,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR8,               0xE8201C20,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR9,               0xE8201C24,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR10,              0xE8201C28,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR11,              0xE8201C2C,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR12,              0xE8201C30,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR13,              0xE8201C34,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR14,              0xE8201C38,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR15,              0xE8201C3C,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR16,              0xE8201C40,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR17,              0xE8201C44,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR18,              0xE8201C48,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR19,              0xE8201C4C,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR20,              0xE8201C50,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR21,              0xE8201C54,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR22,              0xE8201C58,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR23,              0xE8201C5C,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR24,              0xE8201C60,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR25,              0xE8201C64,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR26,              0xE8201C68,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR27,              0xE8201C6C,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR28,              0xE8201C70,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR29,              0xE8201C74,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR30,              0xE8201C78,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR31,              0xE8201C7C,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR32,              0xE8201C80,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR33,              0xE8201C84,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR34,              0xE8201C88,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR35,              0xE8201C8C,__READ_WRITE);
__IO_REG32(    INTC_ICDICFR36,              0xE8201C90,__READ_WRITE);
__IO_REG32(    INTC_ppi_status,             0xE8201D00,__READ      );
__IO_REG32(    INTC_spi_status0,            0xE8201D04,__READ      );
__IO_REG32(    INTC_spi_status1,            0xE8201D08,__READ      );
__IO_REG32(    INTC_spi_status2,            0xE8201D0C,__READ      );
__IO_REG32(    INTC_spi_status3,            0xE8201D10,__READ      );
__IO_REG32(    INTC_spi_status4,            0xE8201D14,__READ      );
__IO_REG32(    INTC_spi_status5,            0xE8201D18,__READ      );
__IO_REG32(    INTC_spi_status6,            0xE8201D1C,__READ      );
__IO_REG32(    INTC_spi_status7,            0xE8201D20,__READ      );
__IO_REG32(    INTC_spi_status8,            0xE8201D24,__READ      );
__IO_REG32(    INTC_spi_status9,            0xE8201D28,__READ      );
__IO_REG32(    INTC_spi_status10,           0xE8201D2C,__READ      );
__IO_REG32(    INTC_spi_status11,           0xE8201D30,__READ      );
__IO_REG32(    INTC_spi_status12,           0xE8201D34,__READ      );
__IO_REG32(    INTC_spi_status13,           0xE8201D38,__READ      );
__IO_REG32(    INTC_spi_status14,           0xE8201D3C,__READ      );
__IO_REG32(    INTC_spi_status15,           0xE8201D40,__READ      );
__IO_REG32(    INTC_spi_status16,           0xE8201D44,__READ      );
__IO_REG32(    INTC_ICDSGIR,                0xE8201F00,__WRITE     );
__IO_REG32(    INTC_ICCICR,                 0xE8202000,__READ_WRITE);
__IO_REG32(    INTC_ICCPMR,                 0xE8202004,__READ_WRITE);
__IO_REG32(    INTC_ICCBPR,                 0xE8202008,__READ_WRITE);
__IO_REG32(    INTC_ICCIAR,                 0xE820200C,__READ      );
__IO_REG32(    INTC_ICCEOIR,                0xE8202010,__WRITE     );
__IO_REG32(    INTC_ICCRPR,                 0xE8202014,__READ      );
__IO_REG32(    INTC_ICCHPIR,                0xE8202018,__READ      );
__IO_REG32(    INTC_ICCABPR,                0xE820201C,__READ_WRITE);
__IO_REG32(    INTC_ICCIIDR,                0xE82020FC,__READ      );

/***************************************************************************
 **
 **  BSC (Bus State Controller)
 **
 ***************************************************************************/
__IO_REG32_BIT(BSC_CMNCR,                   0x3FFFC000,__READ_WRITE,__bsc_cmncr_bits);
__IO_REG32_BIT(BSC_CS0BCR,                  0x3FFFC004,__READ_WRITE,__bsc_csxbcr_bits);
__IO_REG32_BIT(BSC_CS1BCR,                  0x3FFFC008,__READ_WRITE,__bsc_csxbcr_bits);
__IO_REG32_BIT(BSC_CS2BCR,                  0x3FFFC00C,__READ_WRITE,__bsc_csxbcr_bits);
__IO_REG32_BIT(BSC_CS3BCR,                  0x3FFFC010,__READ_WRITE,__bsc_csxbcr_bits);
__IO_REG32_BIT(BSC_CS4BCR,                  0x3FFFC014,__READ_WRITE,__bsc_csxbcr_bits);
__IO_REG32_BIT(BSC_CS5BCR,                  0x3FFFC018,__READ_WRITE,__bsc_csxbcr_bits);
__IO_REG32_BIT(BSC_CS0WCR,                  0x3FFFC028,__READ_WRITE,__bsc_cs0wcr_bits);

#define BSC_CS0WCR_BURST_ROM_ASYNC      BSC_CS0WCR
#define BSC_CS0WCR_BURST_ROM_ASYNC_bit  BSC_CS0WCR_bit._burst_rom_async

#define BSC_CS0WCR_BURST_ROM_SYNC       BSC_CS0WCR
#define BSC_CS0WCR_BURST_ROM_SYNC_bit   BSC_CS0WCR_bit._burst_rom_sync

__IO_REG32_BIT(BSC_CS1WCR,                  0x3FFFC02C,__READ_WRITE,__bsc_cs1wcr_bits);
__IO_REG32_BIT(BSC_CS2WCR,                  0x3FFFC030,__READ_WRITE,__bsc_cs2wcr_bits);

#define BSC_CS2WCR_SDRAM                BSC_CS2WCR
#define BSC_CS2WCR_SDRAM_bit            BSC_CS2WCR_bit._sdram

__IO_REG32_BIT(BSC_CS3WCR,                  0x3FFFC034,__READ_WRITE,__bsc_cs3wcr_bits);

#define BSC_CS3WCR_SDRAM                BSC_CS3WCR
#define BSC_CS3WCR_SDRAM_bit            BSC_CS3WCR_bit._sdram

__IO_REG32_BIT(BSC_CS4WCR,                  0x3FFFC038,__READ_WRITE,__bsc_cs4wcr_bits);

#define BSC_CS4WCR_BURST_ROM_ASYNC      BSC_CS4WCR
#define BSC_CS4WCR_BURST_ROM_ASYNC_bit  BSC_CS4WCR_bit._burst_rom_async

__IO_REG32_BIT(BSC_CS5WCR,                  0x3FFFC03C,__READ_WRITE,__bsc_cs5wcr_bits);
__IO_REG32_BIT(BSC_SDCR,                    0x3FFFC04C,__READ_WRITE,__bsc_sdcr_bits);
__IO_REG32_BIT(BSC_RTCSR,                   0x3FFFC050,__READ_WRITE,__bsc_rtcsr_bits);
__IO_REG32(    BSC_RTCNT,                   0x3FFFC054,__READ_WRITE);
__IO_REG32(    BSC_RTCOR,                   0x3FFFC058,__READ_WRITE);
__IO_REG32(    BSC_TOSCOR0,                 0x3FFFC060,__READ_WRITE);
__IO_REG32(    BSC_TOSCOR1,                 0x3FFFC064,__READ_WRITE);
__IO_REG32(    BSC_TOSCOR2,                 0x3FFFC068,__READ_WRITE);
__IO_REG32(    BSC_TOSCOR3,                 0x3FFFC06C,__READ_WRITE);
__IO_REG32(    BSC_TOSCOR4,                 0x3FFFC070,__READ_WRITE);
__IO_REG32(    BSC_TOSCOR5,                 0x3FFFC074,__READ_WRITE);
__IO_REG32_BIT(BSC_TOSTR,                   0x3FFFC080,__READ_WRITE,__bsc_tostr_bits);
__IO_REG32_BIT(BSC_TOENR,                   0x3FFFC084,__READ_WRITE,__bsc_toenr_bits);


/***************************************************************************
 **
 **  DMAC (Direct Memory Access Controller)
 **
 ***************************************************************************/
__IO_REG32(    DMAC_N0SA_0,                 0xE8200000,__READ_WRITE);
__IO_REG32(    DMAC_N0DA_0,                 0xE8200004,__READ_WRITE);
__IO_REG32(    DMAC_N0TB_0,                 0xE8200008,__READ_WRITE);
__IO_REG32(    DMAC_N1SA_0,                 0xE820000C,__READ_WRITE);
__IO_REG32(    DMAC_N1DA_0,                 0xE8200010,__READ_WRITE);
__IO_REG32(    DMAC_N1TB_0,                 0xE8200014,__READ_WRITE);
__IO_REG32(    DMAC_CRSA_0,                 0xE8200018,__READ      );
__IO_REG32(    DMAC_CRDA_0,                 0xE820001C,__READ      );
__IO_REG32(    DMAC_CRTB_0,                 0xE8200020,__READ      );
__IO_REG32_BIT(DMAC_CHSTAT_0,               0xE8200024,__READ      ,__dmac_chstat_x_bits);
__IO_REG32_BIT(DMAC_CHCTRL_0,               0xE8200028,__READ_WRITE,__dmac_chctrl_x_bits);
__IO_REG32_BIT(DMAC_CHCFG_0,                0xE820002C,__READ_WRITE,__dmac_chcfg_x_bits);
__IO_REG32_BIT(DMAC_CHITVL_0,               0xE8200030,__READ_WRITE,__dmac_chitvl_x_bits);
__IO_REG32_BIT(DMAC_CHEXT_0,                0xE8200034,__READ_WRITE,__dmac_chext_x_bits);
__IO_REG32(    DMAC_NXLA_0,                 0xE8200038,__READ_WRITE);
__IO_REG32(    DMAC_CRLA_0,                 0xE820003C,__READ      );

/***************************************************************************
 **
 **  DMAC ch.1 (Direct Memory Access Controller channel 1)
 **
 ***************************************************************************/
__IO_REG32(    DMAC_N0SA_1,                 0xE8200040,__READ_WRITE);
__IO_REG32(    DMAC_N0DA_1,                 0xE8200044,__READ_WRITE);
__IO_REG32(    DMAC_N0TB_1,                 0xE8200048,__READ_WRITE);
__IO_REG32(    DMAC_N1SA_1,                 0xE820004C,__READ_WRITE);
__IO_REG32(    DMAC_N1DA_1,                 0xE8200050,__READ_WRITE);
__IO_REG32(    DMAC_N1TB_1,                 0xE8200054,__READ_WRITE);
__IO_REG32(    DMAC_CRSA_1,                 0xE8200058,__READ      );
__IO_REG32(    DMAC_CRDA_1,                 0xE820005C,__READ      );
__IO_REG32(    DMAC_CRTB_1,                 0xE8200060,__READ      );
__IO_REG32_BIT(DMAC_CHSTAT_1,               0xE8200064,__READ      ,__dmac_chstat_x_bits);
__IO_REG32_BIT(DMAC_CHCTRL_1,               0xE8200068,__READ_WRITE,__dmac_chctrl_x_bits);
__IO_REG32_BIT(DMAC_CHCFG_1,                0xE820006C,__READ_WRITE,__dmac_chcfg_x_bits);
__IO_REG32_BIT(DMAC_CHITVL_1,               0xE8200070,__READ_WRITE,__dmac_chitvl_x_bits);
__IO_REG32_BIT(DMAC_CHEXT_1,                0xE8200074,__READ_WRITE,__dmac_chext_x_bits);
__IO_REG32(    DMAC_NXLA_1,                 0xE8200078,__READ_WRITE);
__IO_REG32(    DMAC_CRLA_1,                 0xE820007C,__READ      );

/***************************************************************************
 **
 **  DMAC ch.2 (Direct Memory Access Controller channel 2)
 **
 ***************************************************************************/
__IO_REG32(    DMAC_N0SA_2,                 0xE8200080,__READ_WRITE);
__IO_REG32(    DMAC_N0DA_2,                 0xE8200084,__READ_WRITE);
__IO_REG32(    DMAC_N0TB_2,                 0xE8200088,__READ_WRITE);
__IO_REG32(    DMAC_N1SA_2,                 0xE820008C,__READ_WRITE);
__IO_REG32(    DMAC_N1DA_2,                 0xE8200090,__READ_WRITE);
__IO_REG32(    DMAC_N1TB_2,                 0xE8200094,__READ_WRITE);
__IO_REG32(    DMAC_CRSA_2,                 0xE8200098,__READ      );
__IO_REG32(    DMAC_CRDA_2,                 0xE820009C,__READ      );
__IO_REG32(    DMAC_CRTB_2,                 0xE82000A0,__READ      );
__IO_REG32_BIT(DMAC_CHSTAT_2,               0xE82000A4,__READ      ,__dmac_chstat_x_bits);
__IO_REG32_BIT(DMAC_CHCTRL_2,               0xE82000A8,__READ_WRITE,__dmac_chctrl_x_bits);
__IO_REG32_BIT(DMAC_CHCFG_2,                0xE82000AC,__READ_WRITE,__dmac_chcfg_x_bits);
__IO_REG32_BIT(DMAC_CHITVL_2,               0xE82000B0,__READ_WRITE,__dmac_chitvl_x_bits);
__IO_REG32_BIT(DMAC_CHEXT_2,                0xE82000B4,__READ_WRITE,__dmac_chext_x_bits);
__IO_REG32(    DMAC_NXLA_2,                 0xE82000B8,__READ_WRITE);
__IO_REG32(    DMAC_CRLA_2,                 0xE82000BC,__READ      );

/***************************************************************************
 **
 **  DMAC ch.3 (Direct Memory Access Controller channel 3)
 **
 ***************************************************************************/
__IO_REG32(    DMAC_N0SA_3,                 0xE82000C0,__READ_WRITE);
__IO_REG32(    DMAC_N0DA_3,                 0xE82000C4,__READ_WRITE);
__IO_REG32(    DMAC_N0TB_3,                 0xE82000C8,__READ_WRITE);
__IO_REG32(    DMAC_N1SA_3,                 0xE82000CC,__READ_WRITE);
__IO_REG32(    DMAC_N1DA_3,                 0xE82000D0,__READ_WRITE);
__IO_REG32(    DMAC_N1TB_3,                 0xE82000D4,__READ_WRITE);
__IO_REG32(    DMAC_CRSA_3,                 0xE82000D8,__READ      );
__IO_REG32(    DMAC_CRDA_3,                 0xE82000DC,__READ      );
__IO_REG32(    DMAC_CRTB_3,                 0xE82000E0,__READ      );
__IO_REG32_BIT(DMAC_CHSTAT_3,               0xE82000E4,__READ      ,__dmac_chstat_x_bits);
__IO_REG32_BIT(DMAC_CHCTRL_3,               0xE82000E8,__READ_WRITE,__dmac_chctrl_x_bits);
__IO_REG32_BIT(DMAC_CHCFG_3,                0xE82000EC,__READ_WRITE,__dmac_chcfg_x_bits);
__IO_REG32_BIT(DMAC_CHITVL_3,               0xE82000F0,__READ_WRITE,__dmac_chitvl_x_bits);
__IO_REG32_BIT(DMAC_CHEXT_3,                0xE82000F4,__READ_WRITE,__dmac_chext_x_bits);
__IO_REG32(    DMAC_NXLA_3,                 0xE82000F8,__READ_WRITE);
__IO_REG32(    DMAC_CRLA_3,                 0xE82000FC,__READ      );

/***************************************************************************
 **
 **  DMAC ch.4 (Direct Memory Access Controller channel 4)
 **
 ***************************************************************************/
__IO_REG32(    DMAC_N0SA_4,                 0xE8200100,__READ_WRITE);
__IO_REG32(    DMAC_N0DA_4,                 0xE8200104,__READ_WRITE);
__IO_REG32(    DMAC_N0TB_4,                 0xE8200108,__READ_WRITE);
__IO_REG32(    DMAC_N1SA_4,                 0xE820010C,__READ_WRITE);
__IO_REG32(    DMAC_N1DA_4,                 0xE8200110,__READ_WRITE);
__IO_REG32(    DMAC_N1TB_4,                 0xE8200114,__READ_WRITE);
__IO_REG32(    DMAC_CRSA_4,                 0xE8200118,__READ      );
__IO_REG32(    DMAC_CRDA_4,                 0xE820011C,__READ      );
__IO_REG32(    DMAC_CRTB_4,                 0xE8200120,__READ      );
__IO_REG32_BIT(DMAC_CHSTAT_4,               0xE8200124,__READ      ,__dmac_chstat_x_bits);
__IO_REG32_BIT(DMAC_CHCTRL_4,               0xE8200128,__READ_WRITE,__dmac_chctrl_x_bits);
__IO_REG32_BIT(DMAC_CHCFG_4,                0xE820012C,__READ_WRITE,__dmac_chcfg_x_bits);
__IO_REG32_BIT(DMAC_CHITVL_4,               0xE8200130,__READ_WRITE,__dmac_chitvl_x_bits);
__IO_REG32_BIT(DMAC_CHEXT_4,                0xE8200134,__READ_WRITE,__dmac_chext_x_bits);
__IO_REG32(    DMAC_NXLA_4,                 0xE8200138,__READ_WRITE);
__IO_REG32(    DMAC_CRLA_4,                 0xE820013C,__READ      );

/***************************************************************************
 **
 **  DMAC ch.5 (Direct Memory Access Controller channel 5)
 **
 ***************************************************************************/
__IO_REG32(    DMAC_N0SA_5,                 0xE8200140,__READ_WRITE);
__IO_REG32(    DMAC_N0DA_5,                 0xE8200144,__READ_WRITE);
__IO_REG32(    DMAC_N0TB_5,                 0xE8200148,__READ_WRITE);
__IO_REG32(    DMAC_N1SA_5,                 0xE820014C,__READ_WRITE);
__IO_REG32(    DMAC_N1DA_5,                 0xE8200150,__READ_WRITE);
__IO_REG32(    DMAC_N1TB_5,                 0xE8200154,__READ_WRITE);
__IO_REG32(    DMAC_CRSA_5,                 0xE8200158,__READ      );
__IO_REG32(    DMAC_CRDA_5,                 0xE820015C,__READ      );
__IO_REG32(    DMAC_CRTB_5,                 0xE8200160,__READ      );
__IO_REG32_BIT(DMAC_CHSTAT_5,               0xE8200164,__READ      ,__dmac_chstat_x_bits);
__IO_REG32_BIT(DMAC_CHCTRL_5,               0xE8200168,__READ_WRITE,__dmac_chctrl_x_bits);
__IO_REG32_BIT(DMAC_CHCFG_5,                0xE820016C,__READ_WRITE,__dmac_chcfg_x_bits);
__IO_REG32_BIT(DMAC_CHITVL_5,               0xE8200170,__READ_WRITE,__dmac_chitvl_x_bits);
__IO_REG32_BIT(DMAC_CHEXT_5,                0xE8200174,__READ_WRITE,__dmac_chext_x_bits);
__IO_REG32(    DMAC_NXLA_5,                 0xE8200178,__READ_WRITE);
__IO_REG32(    DMAC_CRLA_5,                 0xE820017C,__READ      );

/***************************************************************************
 **
 **  DMAC ch.6 (Direct Memory Access Controller channel 6)
 **
 ***************************************************************************/
__IO_REG32(    DMAC_N0SA_6,                 0xE8200180,__READ_WRITE);
__IO_REG32(    DMAC_N0DA_6,                 0xE8200184,__READ_WRITE);
__IO_REG32(    DMAC_N0TB_6,                 0xE8200188,__READ_WRITE);
__IO_REG32(    DMAC_N1SA_6,                 0xE820018C,__READ_WRITE);
__IO_REG32(    DMAC_N1DA_6,                 0xE8200190,__READ_WRITE);
__IO_REG32(    DMAC_N1TB_6,                 0xE8200194,__READ_WRITE);
__IO_REG32(    DMAC_CRSA_6,                 0xE8200198,__READ      );
__IO_REG32(    DMAC_CRDA_6,                 0xE820019C,__READ      );
__IO_REG32(    DMAC_CRTB_6,                 0xE82001A0,__READ      );
__IO_REG32_BIT(DMAC_CHSTAT_6,               0xE82001A4,__READ      ,__dmac_chstat_x_bits);
__IO_REG32_BIT(DMAC_CHCTRL_6,               0xE82001A8,__READ_WRITE,__dmac_chctrl_x_bits);
__IO_REG32_BIT(DMAC_CHCFG_6,                0xE82001AC,__READ_WRITE,__dmac_chcfg_x_bits);
__IO_REG32_BIT(DMAC_CHITVL_6,               0xE82001B0,__READ_WRITE,__dmac_chitvl_x_bits);
__IO_REG32_BIT(DMAC_CHEXT_6,                0xE82001B4,__READ_WRITE,__dmac_chext_x_bits);
__IO_REG32(    DMAC_NXLA_6,                 0xE82001B8,__READ_WRITE);
__IO_REG32(    DMAC_CRLA_6,                 0xE82001BC,__READ      );

/***************************************************************************
 **
 **  DMAC ch.7 (Direct Memory Access Controller channel 7)
 **
 ***************************************************************************/
__IO_REG32(    DMAC_N0SA_7,                 0xE82001C0,__READ_WRITE);
__IO_REG32(    DMAC_N0DA_7,                 0xE82001C4,__READ_WRITE);
__IO_REG32(    DMAC_N0TB_7,                 0xE82001C8,__READ_WRITE);
__IO_REG32(    DMAC_N1SA_7,                 0xE82001CC,__READ_WRITE);
__IO_REG32(    DMAC_N1DA_7,                 0xE82001D0,__READ_WRITE);
__IO_REG32(    DMAC_N1TB_7,                 0xE82001D4,__READ_WRITE);
__IO_REG32(    DMAC_CRSA_7,                 0xE82001D8,__READ      );
__IO_REG32(    DMAC_CRDA_7,                 0xE82001DC,__READ      );
__IO_REG32(    DMAC_CRTB_7,                 0xE82001E0,__READ      );
__IO_REG32_BIT(DMAC_CHSTAT_7,               0xE82001E4,__READ      ,__dmac_chstat_x_bits);
__IO_REG32_BIT(DMAC_CHCTRL_7,               0xE82001E8,__READ_WRITE,__dmac_chctrl_x_bits);
__IO_REG32_BIT(DMAC_CHCFG_7,                0xE82001EC,__READ_WRITE,__dmac_chcfg_x_bits);
__IO_REG32_BIT(DMAC_CHITVL_7,               0xE82001F0,__READ_WRITE,__dmac_chitvl_x_bits);
__IO_REG32_BIT(DMAC_CHEXT_7,                0xE82001F4,__READ_WRITE,__dmac_chext_x_bits);
__IO_REG32(    DMAC_NXLA_7,                 0xE82001F8,__READ_WRITE);
__IO_REG32(    DMAC_CRLA_7,                 0xE82001FC,__READ      );

/***************************************************************************
 **
 **  DMAC common ch.0-7 (Direct Memory Access Controller common)
 **
 ***************************************************************************/
__IO_REG32_BIT(DMAC_DCTRL_0_7,              0xE8200300,__READ_WRITE,__dmac_dctrl_0_7_8_15_bits);
__IO_REG32_BIT(DMAC_DSTAT_EN_0_7,           0xE8200310,__READ      ,__dmac_dstat_en_0_7_bits);
__IO_REG32_BIT(DMAC_DSTAT_ER_0_7,           0xE8200314,__READ      ,__dmac_dstat_er_0_7_bits);
__IO_REG32_BIT(DMAC_DSTAT_END_0_7,          0xE8200318,__READ      ,__dmac_dstat_end_0_7_bits);
__IO_REG32_BIT(DMAC_DSTAT_TC_0_7,           0xE820031C,__READ      ,__dmac_dstat_tc_0_7_bits);
__IO_REG32_BIT(DMAC_DSTAT_SUS_0_7,          0xE8200320,__READ      ,__dmac_dstat_sus_0_7_bits);

__IO_REG32_BIT(DMAC_DMARS0,                 0xFCFE1000,__READ_WRITE,__dmac_dmars0_bits);
__IO_REG32_BIT(DMAC_DMARS1,                 0xFCFE1004,__READ_WRITE,__dmac_dmars1_bits);
__IO_REG32_BIT(DMAC_DMARS2,                 0xFCFE1008,__READ_WRITE,__dmac_dmars2_bits);
__IO_REG32_BIT(DMAC_DMARS3,                 0xFCFE100C,__READ_WRITE,__dmac_dmars3_bits);

/***************************************************************************
 **
 **  DMAC ch.8 (Direct Memory Access Controller channel 8)
 **
 ***************************************************************************/
__IO_REG32(    DMAC_N0SA_8,                 0xE8200400,__READ_WRITE);
__IO_REG32(    DMAC_N0DA_8,                 0xE8200404,__READ_WRITE);
__IO_REG32(    DMAC_N0TB_8,                 0xE8200408,__READ_WRITE);
__IO_REG32(    DMAC_N1SA_8,                 0xE820040C,__READ_WRITE);
__IO_REG32(    DMAC_N1DA_8,                 0xE8200410,__READ_WRITE);
__IO_REG32(    DMAC_N1TB_8,                 0xE8200414,__READ_WRITE);
__IO_REG32(    DMAC_CRSA_8,                 0xE8200418,__READ      );
__IO_REG32(    DMAC_CRDA_8,                 0xE820041C,__READ      );
__IO_REG32(    DMAC_CRTB_8,                 0xE8200420,__READ      );
__IO_REG32_BIT(DMAC_CHSTAT_8,               0xE8200424,__READ      ,__dmac_chstat_x_bits);
__IO_REG32_BIT(DMAC_CHCTRL_8,               0xE8200428,__READ_WRITE,__dmac_chctrl_x_bits);
__IO_REG32_BIT(DMAC_CHCFG_8,                0xE820042C,__READ_WRITE,__dmac_chcfg_x_bits);
__IO_REG32_BIT(DMAC_CHITVL_8,               0xE8200430,__READ_WRITE,__dmac_chitvl_x_bits);
__IO_REG32_BIT(DMAC_CHEXT_8,                0xE8200434,__READ_WRITE,__dmac_chext_x_bits);
__IO_REG32(    DMAC_NXLA_8,                 0xE8200438,__READ_WRITE);
__IO_REG32(    DMAC_CRLA_8,                 0xE820043C,__READ      );

/***************************************************************************
 **
 **  DMAC ch.9 (Direct Memory Access Controller channel 9)
 **
 ***************************************************************************/
__IO_REG32(    DMAC_N0SA_9,                 0xE8200440,__READ_WRITE);
__IO_REG32(    DMAC_N0DA_9,                 0xE8200444,__READ_WRITE);
__IO_REG32(    DMAC_N0TB_9,                 0xE8200448,__READ_WRITE);
__IO_REG32(    DMAC_N1SA_9,                 0xE820044C,__READ_WRITE);
__IO_REG32(    DMAC_N1DA_9,                 0xE8200450,__READ_WRITE);
__IO_REG32(    DMAC_N1TB_9,                 0xE8200454,__READ_WRITE);
__IO_REG32(    DMAC_CRSA_9,                 0xE8200458,__READ      );
__IO_REG32(    DMAC_CRDA_9,                 0xE820045C,__READ      );
__IO_REG32(    DMAC_CRTB_9,                 0xE8200460,__READ      );
__IO_REG32_BIT(DMAC_CHSTAT_9,               0xE8200464,__READ      ,__dmac_chstat_x_bits);
__IO_REG32_BIT(DMAC_CHCTRL_9,               0xE8200468,__READ_WRITE,__dmac_chctrl_x_bits);
__IO_REG32_BIT(DMAC_CHCFG_9,                0xE820046C,__READ_WRITE,__dmac_chcfg_x_bits);
__IO_REG32_BIT(DMAC_CHITVL_9,               0xE8200470,__READ_WRITE,__dmac_chitvl_x_bits);
__IO_REG32_BIT(DMAC_CHEXT_9,                0xE8200474,__READ_WRITE,__dmac_chext_x_bits);
__IO_REG32(    DMAC_NXLA_9,                 0xE8200478,__READ_WRITE);
__IO_REG32(    DMAC_CRLA_9,                 0xE820047C,__READ      );

/***************************************************************************
 **
 **  DMAC ch.10 (Direct Memory Access Controller channel 10)
 **
 ***************************************************************************/
__IO_REG32(    DMAC_N0SA_10,                0xE8200480,__READ_WRITE);
__IO_REG32(    DMAC_N0DA_10,                0xE8200484,__READ_WRITE);
__IO_REG32(    DMAC_N0TB_10,                0xE8200488,__READ_WRITE);
__IO_REG32(    DMAC_N1SA_10,                0xE820048C,__READ_WRITE);
__IO_REG32(    DMAC_N1DA_10,                0xE8200490,__READ_WRITE);
__IO_REG32(    DMAC_N1TB_10,                0xE8200494,__READ_WRITE);
__IO_REG32(    DMAC_CRSA_10,                0xE8200498,__READ      );
__IO_REG32(    DMAC_CRDA_10,                0xE820049C,__READ      );
__IO_REG32(    DMAC_CRTB_10,                0xE82004A0,__READ      );
__IO_REG32_BIT(DMAC_CHSTAT_10,              0xE82004A4,__READ      ,__dmac_chstat_x_bits);
__IO_REG32_BIT(DMAC_CHCTRL_10,              0xE82004A8,__READ_WRITE,__dmac_chctrl_x_bits);
__IO_REG32_BIT(DMAC_CHCFG_10,               0xE82004AC,__READ_WRITE,__dmac_chcfg_x_bits);
__IO_REG32_BIT(DMAC_CHITVL_10,              0xE82004B0,__READ_WRITE,__dmac_chitvl_x_bits);
__IO_REG32_BIT(DMAC_CHEXT_10,               0xE82004B4,__READ_WRITE,__dmac_chext_x_bits);
__IO_REG32(    DMAC_NXLA_10,                0xE82004B8,__READ_WRITE);
__IO_REG32(    DMAC_CRLA_10,                0xE82004BC,__READ      );

/***************************************************************************
 **
 **  DMAC ch.11 (Direct Memory Access Controller channel 11)
 **
 ***************************************************************************/
__IO_REG32(    DMAC_N0SA_11,                0xE82004C0,__READ_WRITE);
__IO_REG32(    DMAC_N0DA_11,                0xE82004C4,__READ_WRITE);
__IO_REG32(    DMAC_N0TB_11,                0xE82004C8,__READ_WRITE);
__IO_REG32(    DMAC_N1SA_11,                0xE82004CC,__READ_WRITE);
__IO_REG32(    DMAC_N1DA_11,                0xE82004D0,__READ_WRITE);
__IO_REG32(    DMAC_N1TB_11,                0xE82004D4,__READ_WRITE);
__IO_REG32(    DMAC_CRSA_11,                0xE82004D8,__READ      );
__IO_REG32(    DMAC_CRDA_11,                0xE82004DC,__READ      );
__IO_REG32(    DMAC_CRTB_11,                0xE82004E0,__READ      );
__IO_REG32_BIT(DMAC_CHSTAT_11,              0xE82004E4,__READ      ,__dmac_chstat_x_bits);
__IO_REG32_BIT(DMAC_CHCTRL_11,              0xE82004E8,__READ_WRITE,__dmac_chctrl_x_bits);
__IO_REG32_BIT(DMAC_CHCFG_11,               0xE82004EC,__READ_WRITE,__dmac_chcfg_x_bits);
__IO_REG32_BIT(DMAC_CHITVL_11,              0xE82004F0,__READ_WRITE,__dmac_chitvl_x_bits);
__IO_REG32_BIT(DMAC_CHEXT_11,               0xE82004F4,__READ_WRITE,__dmac_chext_x_bits);
__IO_REG32(    DMAC_NXLA_11,                0xE82004F8,__READ_WRITE);
__IO_REG32(    DMAC_CRLA_11,                0xE82004FC,__READ      );

/***************************************************************************
 **
 **  DMAC ch.12 (Direct Memory Access Controller channel 12)
 **
 ***************************************************************************/
__IO_REG32(    DMAC_N0SA_12,                0xE8200500,__READ_WRITE);
__IO_REG32(    DMAC_N0DA_12,                0xE8200504,__READ_WRITE);
__IO_REG32(    DMAC_N0TB_12,                0xE8200508,__READ_WRITE);
__IO_REG32(    DMAC_N1SA_12,                0xE820050C,__READ_WRITE);
__IO_REG32(    DMAC_N1DA_12,                0xE8200510,__READ_WRITE);
__IO_REG32(    DMAC_N1TB_12,                0xE8200514,__READ_WRITE);
__IO_REG32(    DMAC_CRSA_12,                0xE8200518,__READ      );
__IO_REG32(    DMAC_CRDA_12,                0xE820051C,__READ      );
__IO_REG32(    DMAC_CRTB_12,                0xE8200520,__READ      );
__IO_REG32_BIT(DMAC_CHSTAT_12,              0xE8200524,__READ      ,__dmac_chstat_x_bits);
__IO_REG32_BIT(DMAC_CHCTRL_12,              0xE8200528,__READ_WRITE,__dmac_chctrl_x_bits);
__IO_REG32_BIT(DMAC_CHCFG_12,               0xE820052C,__READ_WRITE,__dmac_chcfg_x_bits);
__IO_REG32_BIT(DMAC_CHITVL_12,              0xE8200530,__READ_WRITE,__dmac_chitvl_x_bits);
__IO_REG32_BIT(DMAC_CHEXT_12,               0xE8200534,__READ_WRITE,__dmac_chext_x_bits);
__IO_REG32(    DMAC_NXLA_12,                0xE8200538,__READ_WRITE);
__IO_REG32(    DMAC_CRLA_12,                0xE820053C,__READ      );

/***************************************************************************
 **
 **  DMAC ch.13 (Direct Memory Access Controller channel 13)
 **
 ***************************************************************************/
__IO_REG32(    DMAC_N0SA_13,                0xE8200540,__READ_WRITE);
__IO_REG32(    DMAC_N0DA_13,                0xE8200544,__READ_WRITE);
__IO_REG32(    DMAC_N0TB_13,                0xE8200548,__READ_WRITE);
__IO_REG32(    DMAC_N1SA_13,                0xE820054C,__READ_WRITE);
__IO_REG32(    DMAC_N1DA_13,                0xE8200550,__READ_WRITE);
__IO_REG32(    DMAC_N1TB_13,                0xE8200554,__READ_WRITE);
__IO_REG32(    DMAC_CRSA_13,                0xE8200558,__READ      );
__IO_REG32(    DMAC_CRDA_13,                0xE820055C,__READ      );
__IO_REG32(    DMAC_CRTB_13,                0xE8200560,__READ      );
__IO_REG32_BIT(DMAC_CHSTAT_13,              0xE8200564,__READ      ,__dmac_chstat_x_bits);
__IO_REG32_BIT(DMAC_CHCTRL_13,              0xE8200568,__READ_WRITE,__dmac_chctrl_x_bits);
__IO_REG32_BIT(DMAC_CHCFG_13,               0xE820056C,__READ_WRITE,__dmac_chcfg_x_bits);
__IO_REG32_BIT(DMAC_CHITVL_13,              0xE8200570,__READ_WRITE,__dmac_chitvl_x_bits);
__IO_REG32_BIT(DMAC_CHEXT_13,               0xE8200574,__READ_WRITE,__dmac_chext_x_bits);
__IO_REG32(    DMAC_NXLA_13,                0xE8200578,__READ_WRITE);
__IO_REG32(    DMAC_CRLA_13,                0xE820057C,__READ      );

/***************************************************************************
 **
 **  DMAC ch.14 (Direct Memory Access Controller channel 14)
 **
 ***************************************************************************/
__IO_REG32(    DMAC_N0SA_14,                0xE8200580,__READ_WRITE);
__IO_REG32(    DMAC_N0DA_14,                0xE8200584,__READ_WRITE);
__IO_REG32(    DMAC_N0TB_14,                0xE8200588,__READ_WRITE);
__IO_REG32(    DMAC_N1SA_14,                0xE820058C,__READ_WRITE);
__IO_REG32(    DMAC_N1DA_14,                0xE8200590,__READ_WRITE);
__IO_REG32(    DMAC_N1TB_14,                0xE8200594,__READ_WRITE);
__IO_REG32(    DMAC_CRSA_14,                0xE8200598,__READ      );
__IO_REG32(    DMAC_CRDA_14,                0xE820059C,__READ      );
__IO_REG32(    DMAC_CRTB_14,                0xE82005A0,__READ      );
__IO_REG32_BIT(DMAC_CHSTAT_14,              0xE82005A4,__READ      ,__dmac_chstat_x_bits);
__IO_REG32_BIT(DMAC_CHCTRL_14,              0xE82005A8,__READ_WRITE,__dmac_chctrl_x_bits);
__IO_REG32_BIT(DMAC_CHCFG_14,               0xE82005AC,__READ_WRITE,__dmac_chcfg_x_bits);
__IO_REG32_BIT(DMAC_CHITVL_14,              0xE82005B0,__READ_WRITE,__dmac_chitvl_x_bits);
__IO_REG32_BIT(DMAC_CHEXT_14,               0xE82005B4,__READ_WRITE,__dmac_chext_x_bits);
__IO_REG32(    DMAC_NXLA_14,                0xE82005B8,__READ_WRITE);
__IO_REG32(    DMAC_CRLA_14,                0xE82005BC,__READ      );

/***************************************************************************
 **
 **  DMAC commnch.15 (Direct Memory Access Controller channel 15)
 **
 ***************************************************************************/
__IO_REG32(    DMAC_N0SA_15,                0xE82005C0,__READ_WRITE);
__IO_REG32(    DMAC_N0DA_15,                0xE82005C4,__READ_WRITE);
__IO_REG32(    DMAC_N0TB_15,                0xE82005C8,__READ_WRITE);
__IO_REG32(    DMAC_N1SA_15,                0xE82005CC,__READ_WRITE);
__IO_REG32(    DMAC_N1DA_15,                0xE82005D0,__READ_WRITE);
__IO_REG32(    DMAC_N1TB_15,                0xE82005D4,__READ_WRITE);
__IO_REG32(    DMAC_CRSA_15,                0xE82005D8,__READ      );
__IO_REG32(    DMAC_CRDA_15,                0xE82005DC,__READ      );
__IO_REG32(    DMAC_CRTB_15,                0xE82005E0,__READ      );
__IO_REG32_BIT(DMAC_CHSTAT_15,              0xE82005E4,__READ      ,__dmac_chstat_x_bits);
__IO_REG32_BIT(DMAC_CHCTRL_15,              0xE82005E8,__READ_WRITE,__dmac_chctrl_x_bits);
__IO_REG32_BIT(DMAC_CHCFG_15,               0xE82005EC,__READ_WRITE,__dmac_chcfg_x_bits);
__IO_REG32_BIT(DMAC_CHITVL_15,              0xE82005F0,__READ_WRITE,__dmac_chitvl_x_bits);
__IO_REG32_BIT(DMAC_CHEXT_15,               0xE82005F4,__READ_WRITE,__dmac_chext_x_bits);
__IO_REG32(    DMAC_NXLA_15,                0xE82005F8,__READ_WRITE);
__IO_REG32(    DMAC_CRLA_15,                0xE82005FC,__READ      );

/***************************************************************************
 **
 **  DMAC common ch.8-15 (Direct Memory Access Controller common)
 **
 ***************************************************************************/
__IO_REG32_BIT(DMAC_DCTRL_8_15,             0xE8200700,__READ_WRITE,__dmac_dctrl_0_7_8_15_bits);
__IO_REG32_BIT(DMAC_DSTAT_EN_8_15,          0xE8200710,__READ      ,__dmac_dstat_en_8_15_bits);
__IO_REG32_BIT(DMAC_DSTAT_ER_8_15,          0xE8200714,__READ      ,__dmac_dstat_er_8_15_bits);
__IO_REG32_BIT(DMAC_DSTAT_END_8_15,         0xE8200718,__READ      ,__dmac_dstat_end_8_15_bits);
__IO_REG32_BIT(DMAC_DSTAT_TC_8_15,          0xE820071C,__READ      ,__dmac_dstat_tc_8_15_bits);
__IO_REG32_BIT(DMAC_DSTAT_SUS_8_15,         0xE8200720,__READ      ,__dmac_dstat_sus_8_15_bits);

__IO_REG32_BIT(DMAC_DMARS4,                 0xFCFE1010,__READ_WRITE,__dmac_dmars4_bits);
__IO_REG32_BIT(DMAC_DMARS5,                 0xFCFE1014,__READ_WRITE,__dmac_dmars5_bits);
__IO_REG32_BIT(DMAC_DMARS6,                 0xFCFE1018,__READ_WRITE,__dmac_dmars6_bits);
__IO_REG32_BIT(DMAC_DMARS7,                 0xFCFE101C,__READ_WRITE,__dmac_dmars7_bits);

/***************************************************************************
 **
 **  MTU2 ch.0 (Multi-Function Timer Pulse Unit 2 channel 0)
 **
 ***************************************************************************/
__IO_REG8_BIT( MTU2_TCR_0,                  0xFCFF0300,__READ_WRITE,__mtu2_tcr_bits);
__IO_REG8_BIT( MTU2_TMDR_0,                 0xFCFF0301,__READ_WRITE,__mtu2_tmdr_bits);
__IO_REG8_BIT( MTU2_TIORH_0,                0xFCFF0302,__READ_WRITE,__mtu2_tior_bits);
__IO_REG8_BIT( MTU2_TIORL_0,                0xFCFF0303,__READ_WRITE,__mtu2_tiorl_bits);
__IO_REG8_BIT( MTU2_TIER_0,                 0xFCFF0304,__READ_WRITE,__mtu2_tier_bits);
__IO_REG8_BIT( MTU2_TSR_0,                  0xFCFF0305,__READ_WRITE,__mtu2_tsr_bits);
__IO_REG16(    MTU2_TCNT_0,                 0xFCFF0306,__READ_WRITE);
__IO_REG16(    MTU2_TGRA_0,                 0xFCFF0308,__READ_WRITE);
__IO_REG16(    MTU2_TGRB_0,                 0xFCFF030A,__READ_WRITE);
__IO_REG16(    MTU2_TGRC_0,                 0xFCFF030C,__READ_WRITE);
__IO_REG16(    MTU2_TGRD_0,                 0xFCFF030E,__READ_WRITE);
__IO_REG16(    MTU2_TGRE_0,                 0xFCFF0320,__READ_WRITE);
__IO_REG16(    MTU2_TGRF_0,                 0xFCFF0322,__READ_WRITE);
__IO_REG8_BIT( MTU2_TIER2_0,                0xFCFF0324,__READ_WRITE,__mtu2_tier2_bits);
__IO_REG8_BIT( MTU2_TSR2_0,                 0xFCFF0325,__READ_WRITE,__mtu2_tsr2_bits);
__IO_REG8_BIT( MTU2_TBTM_0,                 0xFCFF0326,__READ_WRITE,__mtu2_tbtm_bits);

/***************************************************************************
 **
 **  MTU2 ch.1 (Multi-Function Timer Pulse Unit 2 channel 1)
 **
 ***************************************************************************/
__IO_REG8_BIT( MTU2_TCR_1,                  0xFCFF0380,__READ_WRITE,__mtu2_tcr_bits);
__IO_REG8_BIT( MTU2_TMDR_1,                 0xFCFF0381,__READ_WRITE,__mtu2_tmdr_bits);
__IO_REG8_BIT( MTU2_TIOR_1,                 0xFCFF0382,__READ_WRITE,__mtu2_tior_bits);
__IO_REG8_BIT( MTU2_TIER_1,                 0xFCFF0384,__READ_WRITE,__mtu2_tier_bits);
__IO_REG8_BIT( MTU2_TSR_1,                  0xFCFF0385,__READ_WRITE,__mtu2_tsr_bits);
__IO_REG16(    MTU2_TCNT_1,                 0xFCFF0386,__READ_WRITE);
__IO_REG16(    MTU2_TGRA_1,                 0xFCFF0388,__READ_WRITE);
__IO_REG16(    MTU2_TGRB_1,                 0xFCFF038A,__READ_WRITE);
__IO_REG8_BIT( MTU2_TICCR,                  0xFCFF0390,__READ_WRITE,__mtu2_ticcr_bits);

/***************************************************************************
 **
 **  MTU2 ch.2 (Multi-Function Timer Pulse Unit 2 channel 2)
 **
 ***************************************************************************/
__IO_REG8_BIT( MTU2_TCR_2,                  0xFCFF0000,__READ_WRITE,__mtu2_tcr_bits);
__IO_REG8_BIT( MTU2_TMDR_2,                 0xFCFF0001,__READ_WRITE,__mtu2_tmdr_bits);
__IO_REG8_BIT( MTU2_TIOR_2,                 0xFCFF0002,__READ_WRITE,__mtu2_tior_bits);
__IO_REG8_BIT( MTU2_TIER_2,                 0xFCFF0004,__READ_WRITE,__mtu2_tier_bits);
__IO_REG8_BIT( MTU2_TSR_2,                  0xFCFF0005,__READ_WRITE,__mtu2_tsr_bits);
__IO_REG16(    MTU2_TCNT_2,                 0xFCFF0006,__READ_WRITE);
__IO_REG16(    MTU2_TGRA_2,                 0xFCFF0008,__READ_WRITE);
__IO_REG16(    MTU2_TGRB_2,                 0xFCFF000A,__READ_WRITE);

/***************************************************************************
 **
 **  MTU2 ch.3 (Multi-Function Timer Pulse Unit 2 channel 3)
 **
 ***************************************************************************/
__IO_REG8_BIT( MTU2_TCR_3,                  0xFCFF0200,__READ_WRITE,__mtu2_tcr_bits);
__IO_REG8_BIT( MTU2_TMDR_3,                 0xFCFF0202,__READ_WRITE,__mtu2_tmdr_bits);
__IO_REG8_BIT( MTU2_TIORH_3,                0xFCFF0204,__READ_WRITE,__mtu2_tior_bits);
__IO_REG8_BIT( MTU2_TIORL_3,                0xFCFF0205,__READ_WRITE,__mtu2_tiorl_bits);
__IO_REG8_BIT( MTU2_TIER_3,                 0xFCFF0208,__READ_WRITE,__mtu2_tier_bits);
__IO_REG8_BIT( MTU2_TSR_3,                  0xFCFF022C,__READ_WRITE,__mtu2_tsr_bits);
__IO_REG16(    MTU2_TCNT_3,                 0xFCFF0210,__READ_WRITE);
__IO_REG16(    MTU2_TGRA_3,                 0xFCFF0218,__READ_WRITE);
__IO_REG16(    MTU2_TGRB_3,                 0xFCFF021A,__READ_WRITE);
__IO_REG16(    MTU2_TGRC_3,                 0xFCFF0224,__READ_WRITE);
__IO_REG16(    MTU2_TGRD_3,                 0xFCFF0226,__READ_WRITE);
__IO_REG8_BIT( MTU2_TBTM_3,                 0xFCFF0238,__READ_WRITE,__mtu2_tbtm_bits);

/***************************************************************************
 **
 **  MTU2 ch.4 (Multi-Function Timer Pulse Unit 2 channel 4)
 **
 ***************************************************************************/
__IO_REG8_BIT( MTU2_TCR_4,                  0xFCFF0201,__READ_WRITE,__mtu2_tcr_bits);
__IO_REG8_BIT( MTU2_TMDR_4,                 0xFCFF0203,__READ_WRITE,__mtu2_tmdr_bits);
__IO_REG8_BIT( MTU2_TIORH_4,                0xFCFF0206,__READ_WRITE,__mtu2_tior_bits);
__IO_REG8_BIT( MTU2_TIORL_4,                0xFCFF0207,__READ_WRITE,__mtu2_tiorl_bits);
__IO_REG8_BIT( MTU2_TIER_4,                 0xFCFF0209,__READ_WRITE,__mtu2_tier_bits);
__IO_REG8_BIT( MTU2_TSR_4,                  0xFCFF022D,__READ_WRITE,__mtu2_tsr_bits);
__IO_REG16(    MTU2_TCNT_4,                 0xFCFF0212,__READ_WRITE);
__IO_REG16(    MTU2_TGRA_4,                 0xFCFF021C,__READ_WRITE);
__IO_REG16(    MTU2_TGRB_4,                 0xFCFF021E,__READ_WRITE);
__IO_REG16(    MTU2_TGRC_4,                 0xFCFF0228,__READ_WRITE);
__IO_REG16(    MTU2_TGRD_4,                 0xFCFF022A,__READ_WRITE);
__IO_REG8_BIT( MTU2_TBTM_4,                 0xFCFF0239,__READ_WRITE,__mtu2_tbtm_bits);
__IO_REG16_BIT(MTU2_TADCR,                  0xFCFF0240,__READ_WRITE,__mtu2_tadcr_bits);
__IO_REG16(    MTU2_TADCORA_4,              0xFCFF0244,__READ_WRITE);
__IO_REG16(    MTU2_TADCORB_4,              0xFCFF0246,__READ_WRITE);
__IO_REG16(    MTU2_TADCOBRA_4,             0xFCFF0248,__READ_WRITE);
__IO_REG16(    MTU2_TADCOBRB_4,             0xFCFF024A,__READ_WRITE);

/***************************************************************************
 **
 **  MTU2 common (Multi-Function Timer Pulse Unit 2 common)
 **
 ***************************************************************************/
__IO_REG8_BIT( MTU2_TSTR,                   0xFCFF0280,__READ_WRITE,__mtu2_tstr_bits);
__IO_REG8_BIT( MTU2_TSYR,                   0xFCFF0281,__READ_WRITE,__mtu2_tsyr_bits);
__IO_REG8_BIT( MTU2_TRWER,                  0xFCFF0284,__READ_WRITE,__mtu2_trwer_bits);
__IO_REG8_BIT( MTU2_TOER,                   0xFCFF020A,__READ_WRITE,__mtu2_toer_bits);
__IO_REG8_BIT( MTU2_TOCR1,                  0xFCFF020E,__READ_WRITE,__mtu2_tocr1_bits);
__IO_REG8_BIT( MTU2_TOCR2,                  0xFCFF020F,__READ_WRITE,__mtu2_tocr2_bits);
__IO_REG8_BIT( MTU2_TGCR,                   0xFCFF020D,__READ_WRITE,__mtu2_tgcr_bits);
__IO_REG16(    MTU2_TCDR,                   0xFCFF0214,__READ_WRITE);
__IO_REG16(    MTU2_TDDR,                   0xFCFF0216,__READ_WRITE);
__IO_REG16(    MTU2_TCNTS,                  0xFCFF0220,__READ      );
__IO_REG16(    MTU2_TCBR,                   0xFCFF0222,__READ_WRITE);
__IO_REG8_BIT( MTU2_TITCR,                  0xFCFF0230,__READ_WRITE,__mtu2_titcr_bits);
__IO_REG8_BIT( MTU2_TITCNT,                 0xFCFF0231,__READ      ,__mtu2_titcnt_bits);
__IO_REG8_BIT( MTU2_TBTER,                  0xFCFF0232,__READ_WRITE,__mtu2_tbter_bits);
__IO_REG8_BIT( MTU2_TDER,                   0xFCFF0234,__READ_WRITE,__mtu2_tder_bits);
__IO_REG8_BIT( MTU2_TWCR,                   0xFCFF0260,__READ_WRITE,__mtu2_twcr_bits);
__IO_REG8_BIT( MTU2_TOLBR,                  0xFCFF0236,__READ_WRITE,__mtu2_tolbr_bits);

/***************************************************************************
 **
 **  OSTM0 (OS Timer 0)
 **
 ***************************************************************************/
__IO_REG32(    OSTM0CMP,                    0xFCFEC000,__READ_WRITE);
__IO_REG32(    OSTM0CNT,                    0xFCFEC004,__READ      );
__IO_REG8_BIT( OSTM0TE,                     0xFCFEC010,__READ      ,__ostm_te_bits);
__IO_REG8(     OSTM0TS,                     0xFCFEC014,__WRITE     );
__IO_REG8(     OSTM0TT,                     0xFCFEC018,__WRITE     );
__IO_REG8_BIT( OSTM0CTL,                    0xFCFEC020,__READ_WRITE,__ostm_ctl_bits);

/***************************************************************************
 **
 **  OSTM1 (OS Timer 1)
 **
 ***************************************************************************/
__IO_REG32(    OSTM1CMP,                    0xFCFEC400,__READ_WRITE);
__IO_REG32(    OSTM1CNT,                    0xFCFEC404,__READ      );
__IO_REG8_BIT( OSTM1TE,                     0xFCFEC410,__READ      ,__ostm_te_bits);
__IO_REG8(     OSTM1TS,                     0xFCFEC414,__WRITE     );
__IO_REG8(     OSTM1TT,                     0xFCFEC418,__WRITE     );
__IO_REG8_BIT( OSTM1CTL,                    0xFCFEC420,__READ_WRITE,__ostm_ctl_bits);

/***************************************************************************
 **
 **  WDT (Watchdog Timer)
 **
 ***************************************************************************/
__IO_REG16_BIT(WDT_WTCNT_H,                 0xFCFE0002,__READ_WRITE,__wdt_wtcnt_bits);
#define WDT_WTCNT                WDT_WTCNT_H_bit.__byte0
__IO_REG16_BIT(WDT_WTCSR_H,                 0xFCFE0000,__READ_WRITE,__wdt_wtcsr_bits);
#define WDT_WTCSR                WDT_WTCSR_H_bit.__byte0
#define WDT_WTCSR_bit            WDT_WTCSR_H_bit.__byte0_bits
__IO_REG16_BIT(WDT_WRCSR_H,                 0xFCFE0004,__READ_WRITE,__wdt_wrcsr_bits);
#define WDT_WRCSR                WDT_WRCSR_H_bit.__byte0
#define WDT_WRCSR_bit            WDT_WRCSR_H_bit.__byte0_bits

/***************************************************************************
 **
 **  RTC (Realtime Clock)
 **
 ***************************************************************************/
__IO_REG8_BIT( RTC_R64CNT,                  0xFCFF1000,__READ      ,__rtc_r64cnt_bits);
__IO_REG8_BIT( RTC_RSECCNT,                 0xFCFF1002,__READ_WRITE,__rtc_rseccnt_bits);
__IO_REG8_BIT( RTC_RMINCNT,                 0xFCFF1004,__READ_WRITE,__rtc_rmincnt_bits);
__IO_REG8_BIT( RTC_RHRCNT,                  0xFCFF1006,__READ_WRITE,__rtc_rhrcnt_bits);
__IO_REG8_BIT( RTC_RWKCNT,                  0xFCFF1008,__READ_WRITE,__rtc_rwkcnt_bits);
__IO_REG8_BIT( RTC_RDAYCNT,                 0xFCFF100A,__READ_WRITE,__rtc_rdaycnt_bits);
__IO_REG8_BIT( RTC_RMONCNT,                 0xFCFF100C,__READ_WRITE,__rtc_rmoncnt_bits);
__IO_REG16_BIT(RTC_RYRCNT,                  0xFCFF100E,__READ_WRITE,__rtc_ryrcnt_bits);
__IO_REG8_BIT( RTC_RSECAR,                  0xFCFF1010,__READ_WRITE,__rtc_rsecar_bits);
__IO_REG8_BIT( RTC_RMINAR,                  0xFCFF1012,__READ_WRITE,__rtc_rminar_bits);
__IO_REG8_BIT( RTC_RHRAR,                   0xFCFF1014,__READ_WRITE,__rtc_rhrar_bits);
__IO_REG8_BIT( RTC_RWKAR,                   0xFCFF1016,__READ_WRITE,__rtc_rwkar_bits);
__IO_REG8_BIT( RTC_RDAYAR,                  0xFCFF1018,__READ_WRITE,__rtc_rdayar_bits);
__IO_REG8_BIT( RTC_RMONAR,                  0xFCFF101A,__READ_WRITE,__rtc_rmonar_bits);
__IO_REG16_BIT(RTC_RYRAR,                   0xFCFF1020,__READ_WRITE,__rtc_ryrar_bits);
__IO_REG8_BIT( RTC_RCR1,                    0xFCFF101C,__READ_WRITE,__rtc_rcr1_bits);
__IO_REG8_BIT( RTC_RCR2,                    0xFCFF101E,__READ_WRITE,__rtc_rcr2_bits);
__IO_REG8_BIT( RTC_RCR3,                    0xFCFF1024,__READ_WRITE,__rtc_rcr3_bits);
__IO_REG8_BIT( RTC_RCR5,                    0xFCFF1026,__READ_WRITE,__rtc_rcr5_bits);
__IO_REG16_BIT(RTC_RFRH,                    0xFCFF102A,__READ_WRITE,__rtc_rfrh_bits);
__IO_REG16(    RTC_RFRL,                    0xFCFF102C,__READ_WRITE);

/***************************************************************************
 **
 **  SCIF ch.0 (Serial Communication Interface with FIFO channel 0)
 **
 ***************************************************************************/
__IO_REG16_BIT(SCIF_SCSMR_0,                0xE8007000,__READ_WRITE,__scif_scsmr_bits);
__IO_REG8(     SCIF_SCBRR_0,                0xE8007004,__READ_WRITE);
__IO_REG16_BIT(SCIF_SCSCR_0,                0xE8007008,__READ_WRITE,__scif_scscr_bits);
__IO_REG8(     SCIF_SCFTDR_0,               0xE800700C,__WRITE     );
__IO_REG16_BIT(SCIF_SCFSR_0,                0xE8007010,__READ_WRITE,__scif_scfsr_bits);
__IO_REG8(     SCIF_SCFRDR_0,               0xE8007014,__READ      );
__IO_REG16_BIT(SCIF_SCFCR_0,                0xE8007018,__READ_WRITE,__scif_scfcr_bits);
__IO_REG16_BIT(SCIF_SCFDR_0,                0xE800701C,__READ      ,__scif_scfdr_bits);
__IO_REG16_BIT(SCIF_SCSPTR_0,               0xE8007020,__READ_WRITE,__scif_scsptr_bits);
__IO_REG16_BIT(SCIF_SCLSR_0,                0xE8007024,__READ_WRITE,__scif_sclsr_bits);
__IO_REG16_BIT(SCIF_SCEMR_0,                0xE8007028,__READ_WRITE,__scif_scemr_bits);

/***************************************************************************
 **
 **  SCIF ch.1 (Serial Communication Interface with FIFO channel 1)
 **
 ***************************************************************************/
__IO_REG16_BIT(SCIF_SCSMR_1,                0xE8007800,__READ_WRITE,__scif_scsmr_bits);
__IO_REG8(     SCIF_SCBRR_1,                0xE8007804,__READ_WRITE);
__IO_REG16_BIT(SCIF_SCSCR_1,                0xE8007808,__READ_WRITE,__scif_scscr_bits);
__IO_REG8(     SCIF_SCFTDR_1,               0xE800780C,__WRITE     );
__IO_REG16_BIT(SCIF_SCFSR_1,                0xE8007810,__READ_WRITE,__scif_scfsr_bits);
__IO_REG8(     SCIF_SCFRDR_1,               0xE8007814,__READ      );
__IO_REG16_BIT(SCIF_SCFCR_1,                0xE8007818,__READ_WRITE,__scif_scfcr_bits);
__IO_REG16_BIT(SCIF_SCFDR_1,                0xE800781C,__READ      ,__scif_scfdr_bits);
__IO_REG16_BIT(SCIF_SCSPTR_1,               0xE8007820,__READ_WRITE,__scif_scsptr_bits);
__IO_REG16_BIT(SCIF_SCLSR_1,                0xE8007824,__READ_WRITE,__scif_sclsr_bits);
__IO_REG16_BIT(SCIF_SCEMR_1,                0xE8007828,__READ_WRITE,__scif_scemr_bits);

/***************************************************************************
 **
 **  SCIF ch.2 (Serial Communication Interface with FIFO channel 2)
 **
 ***************************************************************************/
__IO_REG16_BIT(SCIF_SCSMR_2,                0xE8008000,__READ_WRITE,__scif_scsmr_bits);
__IO_REG8(     SCIF_SCBRR_2,                0xE8008004,__READ_WRITE);
__IO_REG16_BIT(SCIF_SCSCR_2,                0xE8008008,__READ_WRITE,__scif_scscr_bits);
__IO_REG8(     SCIF_SCFTDR_2,               0xE800800C,__WRITE     );
__IO_REG16_BIT(SCIF_SCFSR_2,                0xE8008010,__READ_WRITE,__scif_scfsr_bits);
__IO_REG8(     SCIF_SCFRDR_2,               0xE8008014,__READ      );
__IO_REG16_BIT(SCIF_SCFCR_2,                0xE8008018,__READ_WRITE,__scif_scfcr_bits);
__IO_REG16_BIT(SCIF_SCFDR_2,                0xE800801C,__READ      ,__scif_scfdr_bits);
__IO_REG16_BIT(SCIF_SCSPTR_2,               0xE8008020,__READ_WRITE,__scif_scsptr_bits);
__IO_REG16_BIT(SCIF_SCLSR_2,                0xE8008024,__READ_WRITE,__scif_sclsr_bits);
__IO_REG16_BIT(SCIF_SCEMR_2,                0xE8008028,__READ_WRITE,__scif_scemr_bits);

/***************************************************************************
 **
 **  SCIF ch.3 (Serial Communication Interface with FIFO channel 3)
 **
 ***************************************************************************/
__IO_REG16_BIT(SCIF_SCSMR_3,                0xE8008800,__READ_WRITE,__scif_scsmr_bits);
__IO_REG8(     SCIF_SCBRR_3,                0xE8008804,__READ_WRITE);
__IO_REG16_BIT(SCIF_SCSCR_3,                0xE8008808,__READ_WRITE,__scif_scscr_bits);
__IO_REG8(     SCIF_SCFTDR_3,               0xE800880C,__WRITE     );
__IO_REG16_BIT(SCIF_SCFSR_3,                0xE8008810,__READ_WRITE,__scif_scfsr_bits);
__IO_REG8(     SCIF_SCFRDR_3,               0xE8008814,__READ      );
__IO_REG16_BIT(SCIF_SCFCR_3,                0xE8008818,__READ_WRITE,__scif_scfcr_bits);
__IO_REG16_BIT(SCIF_SCFDR_3,                0xE800881C,__READ      ,__scif_scfdr_bits);
__IO_REG16_BIT(SCIF_SCSPTR_3,               0xE8008820,__READ_WRITE,__scif_scsptr_bits);
__IO_REG16_BIT(SCIF_SCLSR_3,                0xE8008824,__READ_WRITE,__scif_sclsr_bits);
__IO_REG16_BIT(SCIF_SCEMR_3,                0xE8008828,__READ_WRITE,__scif_scemr_bits);

/***************************************************************************
 **
 **  SCIF ch.4 (Serial Communication Interface with FIFO channel 4)
 **
 ***************************************************************************/
__IO_REG16_BIT(SCIF_SCSMR_4,                0xE8009000,__READ_WRITE,__scif_scsmr_bits);
__IO_REG8(     SCIF_SCBRR_4,                0xE8009004,__READ_WRITE);
__IO_REG16_BIT(SCIF_SCSCR_4,                0xE8009008,__READ_WRITE,__scif_scscr_bits);
__IO_REG8(     SCIF_SCFTDR_4,               0xE800900C,__WRITE     );
__IO_REG16_BIT(SCIF_SCFSR_4,                0xE8009010,__READ_WRITE,__scif_scfsr_bits);
__IO_REG8(     SCIF_SCFRDR_4,               0xE8009014,__READ      );
__IO_REG16_BIT(SCIF_SCFCR_4,                0xE8009018,__READ_WRITE,__scif_scfcr_bits);
__IO_REG16_BIT(SCIF_SCFDR_4,                0xE800901C,__READ      ,__scif_scfdr_bits);
__IO_REG16_BIT(SCIF_SCSPTR_4,               0xE8009020,__READ_WRITE,__scif_scsptr_bits);
__IO_REG16_BIT(SCIF_SCLSR_4,                0xE8009024,__READ_WRITE,__scif_sclsr_bits);
__IO_REG16_BIT(SCIF_SCEMR_4,                0xE8009028,__READ_WRITE,__scif_scemr_bits);

/***************************************************************************
 **
 **  SCIF ch.5 (Serial Communication Interface with FIFO channel 5)
 **
 ***************************************************************************/
__IO_REG16_BIT(SCIF_SCSMR_5,                0xE8009800,__READ_WRITE,__scif_scsmr_bits);
__IO_REG8(     SCIF_SCBRR_5,                0xE8009804,__READ_WRITE);
__IO_REG16_BIT(SCIF_SCSCR_5,                0xE8009808,__READ_WRITE,__scif_scscr_bits);
__IO_REG8(     SCIF_SCFTDR_5,               0xE800980C,__WRITE     );
__IO_REG16_BIT(SCIF_SCFSR_5,                0xE8009810,__READ_WRITE,__scif_scfsr_bits);
__IO_REG8(     SCIF_SCFRDR_5,               0xE8009814,__READ      );
__IO_REG16_BIT(SCIF_SCFCR_5,                0xE8009818,__READ_WRITE,__scif_scfcr_bits);
__IO_REG16_BIT(SCIF_SCFDR_5,                0xE800981C,__READ      ,__scif_scfdr_bits);
__IO_REG16_BIT(SCIF_SCSPTR_5,               0xE8009820,__READ_WRITE,__scif_scsptr_bits);
__IO_REG16_BIT(SCIF_SCLSR_5,                0xE8009824,__READ_WRITE,__scif_sclsr_bits);
__IO_REG16_BIT(SCIF_SCEMR_5,                0xE8009828,__READ_WRITE,__scif_scemr_bits);

/***************************************************************************
 **
 **  SCIF ch.6 (Serial Communication Interface with FIFO channel 6)
 **
 ***************************************************************************/
__IO_REG16_BIT(SCIF_SCSMR_6,                0xE800A000,__READ_WRITE,__scif_scsmr_bits);
__IO_REG8(     SCIF_SCBRR_6,                0xE800A004,__READ_WRITE);
__IO_REG16_BIT(SCIF_SCSCR_6,                0xE800A008,__READ_WRITE,__scif_scscr_bits);
__IO_REG8(     SCIF_SCFTDR_6,               0xE800A00C,__WRITE     );
__IO_REG16_BIT(SCIF_SCFSR_6,                0xE800A010,__READ_WRITE,__scif_scfsr_bits);
__IO_REG8(     SCIF_SCFRDR_6,               0xE800A014,__READ      );
__IO_REG16_BIT(SCIF_SCFCR_6,                0xE800A018,__READ_WRITE,__scif_scfcr_bits);
__IO_REG16_BIT(SCIF_SCFDR_6,                0xE800A01C,__READ      ,__scif_scfdr_bits);
__IO_REG16_BIT(SCIF_SCSPTR_6,               0xE800A020,__READ_WRITE,__scif_scsptr_bits);
__IO_REG16_BIT(SCIF_SCLSR_6,                0xE800A024,__READ_WRITE,__scif_sclsr_bits);
__IO_REG16_BIT(SCIF_SCEMR_6,                0xE800A028,__READ_WRITE,__scif_scemr_bits);

/***************************************************************************
 **
 **  SCIF ch.7 (Serial Communication Interface with FIFO channel 7)
 **
 ***************************************************************************/
__IO_REG16_BIT(SCIF_SCSMR_7,                0xE800A800,__READ_WRITE,__scif_scsmr_bits);
__IO_REG8(     SCIF_SCBRR_7,                0xE800A804,__READ_WRITE);
__IO_REG16_BIT(SCIF_SCSCR_7,                0xE800A808,__READ_WRITE,__scif_scscr_bits);
__IO_REG8(     SCIF_SCFTDR_7,               0xE800A80C,__WRITE     );
__IO_REG16_BIT(SCIF_SCFSR_7,                0xE800A810,__READ_WRITE,__scif_scfsr_bits);
__IO_REG8(     SCIF_SCFRDR_7,               0xE800A814,__READ      );
__IO_REG16_BIT(SCIF_SCFCR_7,                0xE800A818,__READ_WRITE,__scif_scfcr_bits);
__IO_REG16_BIT(SCIF_SCFDR_7,                0xE800A81C,__READ      ,__scif_scfdr_bits);
__IO_REG16_BIT(SCIF_SCSPTR_7,               0xE800A820,__READ_WRITE,__scif_scsptr_bits);
__IO_REG16_BIT(SCIF_SCLSR_7,                0xE800A824,__READ_WRITE,__scif_sclsr_bits);
__IO_REG16_BIT(SCIF_SCEMR_7,                0xE800A828,__READ_WRITE,__scif_scemr_bits);

/***************************************************************************
 **
 **  SCIM ch.0 (Serial Communication Interface channel 0)
 **
 ***************************************************************************/
__IO_REG8_BIT( SCIM_SMR0,                   0xE800B000,__READ_WRITE,__scim_smr_bits);
__IO_REG8(     SCIM_BRR0,                   0xE800B001,__READ_WRITE);
__IO_REG8_BIT( SCIM_SCR0,                   0xE800B002,__READ_WRITE,__scim_scr_bits);
__IO_REG8(     SCIM_TDR0,                   0xE800B003,__READ_WRITE);
__IO_REG8_BIT( SCIM_SSR0,                   0xE800B004,__READ_WRITE,__scim_ssr_bits);
__IO_REG8(     SCIM_RDR0,                   0xE800B005,__READ      );
__IO_REG8_BIT( SCIM_SCMR0,                  0xE800B006,__READ_WRITE,__scim_scmr_bits);
__IO_REG8_BIT( SCIM_SEMR0,                  0xE800B007,__READ_WRITE,__scim_semr_bits);
__IO_REG8_BIT( SCIM_SNFR0,                  0xE800B008,__READ_WRITE,__scim_snfr_bits);
__IO_REG8_BIT( SCIM_SECR0,                  0xE800B00D,__READ_WRITE,__scim_secr_bits);

/***************************************************************************
 **
 **  SCIM ch.1 (Serial Communication Interface channel 1)
 **
 ***************************************************************************/
__IO_REG8_BIT( SCIM_SMR1,                   0xE800B800,__READ_WRITE,__scim_smr_bits);
__IO_REG8(     SCIM_BRR1,                   0xE800B801,__READ_WRITE);
__IO_REG8_BIT( SCIM_SCR1,                   0xE800B802,__READ_WRITE,__scim_scr_bits);
__IO_REG8(     SCIM_TDR1,                   0xE800B803,__READ_WRITE);
__IO_REG8_BIT( SCIM_SSR1,                   0xE800B804,__READ_WRITE,__scim_ssr_bits);
__IO_REG8(     SCIM_RDR1,                   0xE800B805,__READ      );
__IO_REG8_BIT( SCIM_SCMR1,                  0xE800B806,__READ_WRITE,__scim_scmr_bits);
__IO_REG8_BIT( SCIM_SEMR1,                  0xE800B807,__READ_WRITE,__scim_semr_bits);
__IO_REG8_BIT( SCIM_SNFR1,                  0xE800B808,__READ_WRITE,__scim_snfr_bits);
__IO_REG8_BIT( SCIM_SECR1,                  0xE800B80D,__READ_WRITE,__scim_secr_bits);

/***************************************************************************
 **
 **  SCIM IrDA
 **
 ***************************************************************************/
__IO_REG8_BIT( SCIM_IRCR,                  	0xE8014000,__READ_WRITE,__scim_ircr_bits);

/***************************************************************************
 **
 **  RSPI ch.0 (Renesas Serial Peripheral Interface channel 0)
 **
 ***************************************************************************/
__IO_REG8_BIT( RSPI_SPCR_0,                 0xE800C800,__READ_WRITE,__rspi_spcr_bits);
__IO_REG8_BIT( RSPI_SSLP_0,                 0xE800C801,__READ_WRITE,__rspi_sslp_bits);
__IO_REG8_BIT( RSPI_SPPCR_0,                0xE800C802,__READ_WRITE,__rspi_sppcr_bits);
__IO_REG8_BIT( RSPI_SPSR_0,                 0xE800C803,__READ_WRITE,__rspi_spsr_bits);
__IO_REG32_BIT(RSPI_SPDR_0,                 0xE800C804,__READ_WRITE,__rspi_spdr_bits);
#define RSPI_SPDR_0_B            RSPI_SPDR_0_bit.__byte0
#define RSPI_SPDR_0_H            RSPI_SPDR_0_bit.__halfword0
__IO_REG8_BIT( RSPI_SPSCR_0,                0xE800C808,__READ_WRITE,__rspi_spscr_bits);
__IO_REG8_BIT( RSPI_SPSSR_0,                0xE800C809,__READ      ,__rspi_spssr_bits);
__IO_REG8(     RSPI_SPBR_0,                 0xE800C80A,__READ_WRITE);
__IO_REG8_BIT( RSPI_SPDCR_0,                0xE800C80B,__READ_WRITE,__rspi_spdcr_bits);
__IO_REG8_BIT( RSPI_SPCKD_0,                0xE800C80C,__READ_WRITE,__rspi_spckd_bits);
__IO_REG8_BIT( RSPI_SSLND_0,                0xE800C80D,__READ_WRITE,__rspi_sslnd_bits);
__IO_REG8_BIT( RSPI_SPND_0,                 0xE800C80E,__READ_WRITE,__rspi_spnd_bits);
__IO_REG16_BIT(RSPI_SPCMD0_0,               0xE800C810,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG16_BIT(RSPI_SPCMD1_0,               0xE800C812,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG16_BIT(RSPI_SPCMD2_0,               0xE800C814,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG16_BIT(RSPI_SPCMD3_0,               0xE800C816,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG8_BIT( RSPI_SPBFCR_0,               0xE800C820,__READ_WRITE,__rspi_spbfcr_bits);
__IO_REG16_BIT(RSPI_SPBFDR_0,               0xE800C822,__READ      ,__rspi_spbfdr_bits);

/***************************************************************************
 **
 **  RSPI ch.1 (Renesas Serial Peripheral Interface channel 1)
 **
 ***************************************************************************/
__IO_REG8_BIT( RSPI_SPCR_1,                 0xE800D000,__READ_WRITE,__rspi_spcr_bits);
__IO_REG8_BIT( RSPI_SSLP_1,                 0xE800D001,__READ_WRITE,__rspi_sslp_bits);
__IO_REG8_BIT( RSPI_SPPCR_1,                0xE800D002,__READ_WRITE,__rspi_sppcr_bits);
__IO_REG8_BIT( RSPI_SPSR_1,                 0xE800D003,__READ_WRITE,__rspi_spsr_bits);
__IO_REG32_BIT(RSPI_SPDR_1,                 0xE800D004,__READ_WRITE,__rspi_spdr_bits);
#define RSPI_SPDR_1_B            RSPI_SPDR_1_bit.__byte0
#define RSPI_SPDR_1_H            RSPI_SPDR_1_bit.__halfword0
__IO_REG8_BIT( RSPI_SPSCR_1,                0xE800D008,__READ_WRITE,__rspi_spscr_bits);
__IO_REG8_BIT( RSPI_SPSSR_1,                0xE800D009,__READ      ,__rspi_spssr_bits);
__IO_REG8(     RSPI_SPBR_1,                 0xE800D00A,__READ_WRITE);
__IO_REG8_BIT( RSPI_SPDCR_1,                0xE800D00B,__READ_WRITE,__rspi_spdcr_bits);
__IO_REG8_BIT( RSPI_SPCKD_1,                0xE800D00C,__READ_WRITE,__rspi_spckd_bits);
__IO_REG8_BIT( RSPI_SSLND_1,                0xE800D00D,__READ_WRITE,__rspi_sslnd_bits);
__IO_REG8_BIT( RSPI_SPND_1,                 0xE800D00E,__READ_WRITE,__rspi_spnd_bits);
__IO_REG16_BIT(RSPI_SPCMD0_1,               0xE800D010,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG16_BIT(RSPI_SPCMD1_1,               0xE800D012,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG16_BIT(RSPI_SPCMD2_1,               0xE800D014,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG16_BIT(RSPI_SPCMD3_1,               0xE800D016,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG8_BIT( RSPI_SPBFCR_1,               0xE800D020,__READ_WRITE,__rspi_spbfcr_bits);
__IO_REG16_BIT(RSPI_SPBFDR_1,               0xE800D022,__READ      ,__rspi_spbfdr_bits);

/***************************************************************************
 **
 **  RSPI ch.2 (Renesas Serial Peripheral Interface channel 2)
 **
 ***************************************************************************/
__IO_REG8_BIT( RSPI_SPCR_2,                 0xE800D800,__READ_WRITE,__rspi_spcr_bits);
__IO_REG8_BIT( RSPI_SSLP_2,                 0xE800D801,__READ_WRITE,__rspi_sslp_bits);
__IO_REG8_BIT( RSPI_SPPCR_2,                0xE800D802,__READ_WRITE,__rspi_sppcr_bits);
__IO_REG8_BIT( RSPI_SPSR_2,                 0xE800D803,__READ_WRITE,__rspi_spsr_bits);
__IO_REG32_BIT(RSPI_SPDR_2,                 0xE800D804,__READ_WRITE,__rspi_spdr_bits);
#define RSPI_SPDR_2_B            RSPI_SPDR_2_bit.__byte0
#define RSPI_SPDR_2_H            RSPI_SPDR_2_bit.__halfword0
__IO_REG8_BIT( RSPI_SPSCR_2,                0xE800D808,__READ_WRITE,__rspi_spscr_bits);
__IO_REG8_BIT( RSPI_SPSSR_2,                0xE800D809,__READ      ,__rspi_spssr_bits);
__IO_REG8(     RSPI_SPBR_2,                 0xE800D80A,__READ_WRITE);
__IO_REG8_BIT( RSPI_SPDCR_2,                0xE800D80B,__READ_WRITE,__rspi_spdcr_bits);
__IO_REG8_BIT( RSPI_SPCKD_2,                0xE800D80C,__READ_WRITE,__rspi_spckd_bits);
__IO_REG8_BIT( RSPI_SSLND_2,                0xE800D80D,__READ_WRITE,__rspi_sslnd_bits);
__IO_REG8_BIT( RSPI_SPND_2,                 0xE800D80E,__READ_WRITE,__rspi_spnd_bits);
__IO_REG16_BIT(RSPI_SPCMD0_2,               0xE800D810,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG16_BIT(RSPI_SPCMD1_2,               0xE800D812,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG16_BIT(RSPI_SPCMD2_2,               0xE800D814,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG16_BIT(RSPI_SPCMD3_2,               0xE800D816,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG8_BIT( RSPI_SPBFCR_2,               0xE800D820,__READ_WRITE,__rspi_spbfcr_bits);
__IO_REG16_BIT(RSPI_SPBFDR_2,               0xE800D822,__READ      ,__rspi_spbfdr_bits);

/***************************************************************************
 **
 **  RSPI ch.3 (Renesas Serial Peripheral Interface channel 3)
 **
 ***************************************************************************/
__IO_REG8_BIT( RSPI_SPCR_3,                 0xE800E000,__READ_WRITE,__rspi_spcr_bits);
__IO_REG8_BIT( RSPI_SSLP_3,                 0xE800E001,__READ_WRITE,__rspi_sslp_bits);
__IO_REG8_BIT( RSPI_SPPCR_3,                0xE800E002,__READ_WRITE,__rspi_sppcr_bits);
__IO_REG8_BIT( RSPI_SPSR_3,                 0xE800E003,__READ_WRITE,__rspi_spsr_bits);
__IO_REG32_BIT(RSPI_SPDR_3,                 0xE800E004,__READ_WRITE,__rspi_spdr_bits);
#define RSPI_SPDR_3_B            RSPI_SPDR_3_bit.__byte0
#define RSPI_SPDR_3_H            RSPI_SPDR_3_bit.__halfword0
__IO_REG8_BIT( RSPI_SPSCR_3,                0xE800E008,__READ_WRITE,__rspi_spscr_bits);
__IO_REG8_BIT( RSPI_SPSSR_3,                0xE800E009,__READ      ,__rspi_spssr_bits);
__IO_REG8(     RSPI_SPBR_3,                 0xE800E00A,__READ_WRITE);
__IO_REG8_BIT( RSPI_SPDCR_3,                0xE800E00B,__READ_WRITE,__rspi_spdcr_bits);
__IO_REG8_BIT( RSPI_SPCKD_3,                0xE800E00C,__READ_WRITE,__rspi_spckd_bits);
__IO_REG8_BIT( RSPI_SSLND_3,                0xE800E00D,__READ_WRITE,__rspi_sslnd_bits);
__IO_REG8_BIT( RSPI_SPND_3,                 0xE800E00E,__READ_WRITE,__rspi_spnd_bits);
__IO_REG16_BIT(RSPI_SPCMD0_3,               0xE800E010,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG16_BIT(RSPI_SPCMD1_3,               0xE800E012,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG16_BIT(RSPI_SPCMD2_3,               0xE800E014,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG16_BIT(RSPI_SPCMD3_3,               0xE800E016,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG8_BIT( RSPI_SPBFCR_3,               0xE800E020,__READ_WRITE,__rspi_spbfcr_bits);
__IO_REG16_BIT(RSPI_SPBFDR_3,               0xE800E022,__READ      ,__rspi_spbfdr_bits);

/***************************************************************************
 **
 **  RSPI ch.4 (Renesas Serial Peripheral Interface channel 4)
 **
 ***************************************************************************/
__IO_REG8_BIT( RSPI_SPCR_4,                 0xE800E800,__READ_WRITE,__rspi_spcr_bits);
__IO_REG8_BIT( RSPI_SSLP_4,                 0xE800E801,__READ_WRITE,__rspi_sslp_bits);
__IO_REG8_BIT( RSPI_SPPCR_4,                0xE800E802,__READ_WRITE,__rspi_sppcr_bits);
__IO_REG8_BIT( RSPI_SPSR_4,                 0xE800E803,__READ_WRITE,__rspi_spsr_bits);
__IO_REG32_BIT(RSPI_SPDR_4,                 0xE800E804,__READ_WRITE,__rspi_spdr_bits);
#define RSPI_SPDR_4_B            RSPI_SPDR_4_bit.__byte0
#define RSPI_SPDR_4_H            RSPI_SPDR_4_bit.__halfword0
__IO_REG8_BIT( RSPI_SPSCR_4,                0xE800E808,__READ_WRITE,__rspi_spscr_bits);
__IO_REG8_BIT( RSPI_SPSSR_4,                0xE800E809,__READ      ,__rspi_spssr_bits);
__IO_REG8(     RSPI_SPBR_4,                 0xE800E80A,__READ_WRITE);
__IO_REG8_BIT( RSPI_SPDCR_4,                0xE800E80B,__READ_WRITE,__rspi_spdcr_bits);
__IO_REG8_BIT( RSPI_SPCKD_4,                0xE800E80C,__READ_WRITE,__rspi_spckd_bits);
__IO_REG8_BIT( RSPI_SSLND_4,                0xE800E80D,__READ_WRITE,__rspi_sslnd_bits);
__IO_REG8_BIT( RSPI_SPND_4,                 0xE800E80E,__READ_WRITE,__rspi_spnd_bits);
__IO_REG16_BIT(RSPI_SPCMD0_4,               0xE800E810,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG16_BIT(RSPI_SPCMD1_4,               0xE800E812,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG16_BIT(RSPI_SPCMD2_4,               0xE800E814,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG16_BIT(RSPI_SPCMD3_4,               0xE800E816,__READ_WRITE,__rspi_spcmd_bits);
__IO_REG8_BIT( RSPI_SPBFCR_4,               0xE800E820,__READ_WRITE,__rspi_spbfcr_bits);
__IO_REG16_BIT(RSPI_SPBFDR_4,               0xE800E822,__READ      ,__rspi_spbfdr_bits);

/***************************************************************************
 **
 **  SPIBSC ch.0 (SPI with I/O Bus Controller channel 0)
 **
 ***************************************************************************/
__IO_REG32_BIT(SPIBSC_CMNCR_0,             0x3FEFA000,__READ_WRITE,__spibsc_cmncr_bits);
__IO_REG32_BIT(SPIBSC_SSLDR_0,             0x3FEFA004,__READ_WRITE,__spibsc_ssldr_bits);
__IO_REG32_BIT(SPIBSC_SPBCR_0,             0x3FEFA008,__READ_WRITE,__spibsc_spbcr_bits);
__IO_REG32_BIT(SPIBSC_DRCR_0,              0x3FEFA00C,__READ_WRITE,__spibsc_drcr_bits);
__IO_REG32_BIT(SPIBSC_DRCMR_0,             0x3FEFA010,__READ_WRITE,__spibsc_drcmr_smcmr_bits);
__IO_REG32_BIT(SPIBSC_DREAR_0,             0x3FEFA014,__READ_WRITE,__spibsc_drear_bits);
__IO_REG32_BIT(SPIBSC_DROPR_0,             0x3FEFA018,__READ_WRITE,__spibsc_dropr_smopr_bits);
__IO_REG32_BIT(SPIBSC_DRENR_0,             0x3FEFA01C,__READ_WRITE,__spibsc_drenr_bits);
__IO_REG32_BIT(SPIBSC_SMCR_0,              0x3FEFA020,__READ_WRITE,__spibsc_smcr_bits);
__IO_REG32_BIT(SPIBSC_SMCMR_0,             0x3FEFA024,__READ_WRITE,__spibsc_drcmr_smcmr_bits);
__IO_REG32_BIT(SPIBSC_SMADR_0,             0x3FEFA028,__READ_WRITE,__spibsc_smadr_bits);
__IO_REG32_BIT(SPIBSC_SMOPR_0,             0x3FEFA02C,__READ_WRITE,__spibsc_dropr_smopr_bits);
__IO_REG32_BIT(SPIBSC_SMENR_0,             0x3FEFA030,__READ_WRITE,__spibsc_smenr_bits);
__IO_REG32_BIT(SPIBSC_SMRDR0_0,            0x3FEFA038,__READ      ,__spibsc_smrdr0_bits);
#define SPIBSC_SMRDR0_0_H        SPIBSC_SMRDR0_0_bit.__halfword0
#define SPIBSC_SMRDR0_0_B        SPIBSC_SMRDR0_0_bit.__byte0
__IO_REG32_BIT(SPIBSC_SMRDR1_0,            0x3FEFA03C,__READ      ,__spibsc_smrdr1_bits);
#define SPIBSC_SMRDR1_0_H        SPIBSC_SMRDR1_0_bit.__halfword0
#define SPIBSC_SMRDR1_0_B        SPIBSC_SMRDR1_0_bit.__byte0
__IO_REG32_BIT(SPIBSC_SMWDR0_0,            0x3FEFA040,__READ_WRITE,__spibsc_smwdr0_bits);
#define SPIBSC_SMWDR0_0_H        SPIBSC_SMWDR0_0_bit.__halfword0
#define SPIBSC_SMWDR0_0_B        SPIBSC_SMWDR0_0_bit.__byte0
__IO_REG32_BIT(SPIBSC_SMWDR1_0,            0x3FEFA044,__READ_WRITE,__spibsc_smwdr1_bits);
#define SPIBSC_SMWDR1_0_H        SPIBSC_SMWDR1_0_bit.__halfword0
#define SPIBSC_SMWDR1_0_B        SPIBSC_SMWDR1_0_bit.__byte0
__IO_REG32_BIT(SPIBSC_CMNSR_0,             0x3FEFA048,__READ      ,__spibsc_cmnsr_bits);
__IO_REG32_BIT(SPIBSC_DRDMCR_0,            0x3FEFA058,__READ_WRITE,__spibsc_drdmcr_smdmcr_bits);
__IO_REG32_BIT(SPIBSC_DRDRENR_0,           0x3FEFA05C,__READ_WRITE,__spibsc_drdrenr_bits);
__IO_REG32_BIT(SPIBSC_SMDMCR_0,            0x3FEFA060,__READ_WRITE,__spibsc_drdmcr_smdmcr_bits);
__IO_REG32_BIT(SPIBSC_SMDRENR_0,           0x3FEFA064,__READ_WRITE,__spibsc_smdrenr_bits);

/***************************************************************************
 **
 **  SPIBSC ch.1 (SPI with I/O Bus Controller channel 1)
 **
 ***************************************************************************/
__IO_REG32_BIT(SPIBSC_CMNCR_1,             0x3FEFB000,__READ_WRITE,__spibsc_cmncr_bits);
__IO_REG32_BIT(SPIBSC_SSLDR_1,             0x3FEFB004,__READ_WRITE,__spibsc_ssldr_bits);
__IO_REG32_BIT(SPIBSC_SPBCR_1,             0x3FEFB008,__READ_WRITE,__spibsc_spbcr_bits);
__IO_REG32_BIT(SPIBSC_DRCR_1,              0x3FEFB00C,__READ_WRITE,__spibsc_drcr_bits);
__IO_REG32_BIT(SPIBSC_DRCMR_1,             0x3FEFB010,__READ_WRITE,__spibsc_drcmr_smcmr_bits);
__IO_REG32_BIT(SPIBSC_DREAR_1,             0x3FEFB014,__READ_WRITE,__spibsc_drear_bits);
__IO_REG32_BIT(SPIBSC_DROPR_1,             0x3FEFB018,__READ_WRITE,__spibsc_dropr_smopr_bits);
__IO_REG32_BIT(SPIBSC_DRENR_1,             0x3FEFB01C,__READ_WRITE,__spibsc_drenr_bits);
__IO_REG32_BIT(SPIBSC_SMCR_1,              0x3FEFB020,__READ_WRITE,__spibsc_smcr_bits);
__IO_REG32_BIT(SPIBSC_SMCMR_1,             0x3FEFB024,__READ_WRITE,__spibsc_drcmr_smcmr_bits);
__IO_REG32_BIT(SPIBSC_SMADR_1,             0x3FEFB028,__READ_WRITE,__spibsc_smadr_bits);
__IO_REG32_BIT(SPIBSC_SMOPR_1,             0x3FEFB02C,__READ_WRITE,__spibsc_dropr_smopr_bits);
__IO_REG32_BIT(SPIBSC_SMENR_1,             0x3FEFB030,__READ_WRITE,__spibsc_smenr_bits);
__IO_REG32_BIT(SPIBSC_SMRDR0_1,            0x3FEFB038,__READ      ,__spibsc_smrdr0_bits);
#define SPIBSC_SMRDR0_1_H        SPIBSC_SMRDR0_1_bit.__halfword0
#define SPIBSC_SMRDR0_1_B        SPIBSC_SMRDR0_1_bit.__byte0
__IO_REG32_BIT(SPIBSC_SMRDR1_1,            0x3FEFB03C,__READ      ,__spibsc_smrdr1_bits);
#define SPIBSC_SMRDR1_1_H        SPIBSC_SMRDR1_1_bit.__halfword0
#define SPIBSC_SMRDR1_1_B        SPIBSC_SMRDR1_1_bit.__byte0
__IO_REG32_BIT(SPIBSC_SMWDR0_1,            0x3FEFB040,__READ_WRITE,__spibsc_smwdr0_bits);
#define SPIBSC_SMWDR0_1_H        SPIBSC_SMWDR0_1_bit.__halfword0
#define SPIBSC_SMWDR0_1_B        SPIBSC_SMWDR0_1_bit.__byte0
__IO_REG32_BIT(SPIBSC_SMWDR1_1,            0x3FEFB044,__READ_WRITE,__spibsc_smwdr1_bits);
#define SPIBSC_SMWDR1_1_H        SPIBSC_SMWDR1_1_bit.__halfword0
#define SPIBSC_SMWDR1_1_B        SPIBSC_SMWDR1_1_bit.__byte0
__IO_REG32_BIT(SPIBSC_CMNSR_1,             0x3FEFB048,__READ      ,__spibsc_cmnsr_bits);
__IO_REG32_BIT(SPIBSC_DRDMCR_1,            0x3FEFB058,__READ_WRITE,__spibsc_drdmcr_smdmcr_bits);
__IO_REG32_BIT(SPIBSC_DRDRENR_1,           0x3FEFB05C,__READ_WRITE,__spibsc_drdrenr_bits);
__IO_REG32_BIT(SPIBSC_SMDMCR_1,            0x3FEFB060,__READ_WRITE,__spibsc_drdmcr_smdmcr_bits);
__IO_REG32_BIT(SPIBSC_SMDRENR_1,           0x3FEFB064,__READ_WRITE,__spibsc_smdrenr_bits);

/***************************************************************************
 **
 **  RIIC ch.0 (Renesas I2C Bus Interface channel 0)
 **
 ***************************************************************************/
__IO_REG32_BIT(RIIC0CR1,                    0xFCFEE000,__READ_WRITE,__riic_iccr1_bits);
__IO_REG32_BIT(RIIC0CR2,                    0xFCFEE004,__READ_WRITE,__riic_iccr2_bits);
__IO_REG32_BIT(RIIC0MR1,                    0xFCFEE008,__READ_WRITE,__riic_icmr1_bits);
__IO_REG32_BIT(RIIC0MR2,                    0xFCFEE00C,__READ_WRITE,__riic_icmr2_bits);
__IO_REG32_BIT(RIIC0MR3,                    0xFCFEE010,__READ_WRITE,__riic_icmr3_bits);
__IO_REG32_BIT(RIIC0FER,                    0xFCFEE014,__READ_WRITE,__riic_icfer_bits);
__IO_REG32_BIT(RIIC0SER,                    0xFCFEE018,__READ_WRITE,__riic_icser_bits);
__IO_REG32_BIT(RIIC0IER,                    0xFCFEE01C,__READ_WRITE,__riic_icier_bits);
__IO_REG32_BIT(RIIC0SR1,                    0xFCFEE020,__READ_WRITE,__riic_icsr1_bits);
__IO_REG32_BIT(RIIC0SR2,                    0xFCFEE024,__READ_WRITE,__riic_icsr2_bits);
__IO_REG32_BIT(RIIC0SAR0,                   0xFCFEE028,__READ_WRITE,__riic_icsar_bits);
__IO_REG32_BIT(RIIC0SAR1,                   0xFCFEE02C,__READ_WRITE,__riic_icsar_bits);
__IO_REG32_BIT(RIIC0SAR2,                   0xFCFEE030,__READ_WRITE,__riic_icsar_bits);
__IO_REG32_BIT(RIIC0BRL,                    0xFCFEE034,__READ_WRITE,__riic_icbrl_bits);
__IO_REG32_BIT(RIIC0BRH,                    0xFCFEE038,__READ_WRITE,__riic_icbrh_bits);
__IO_REG32(    RIIC0DRT,                    0xFCFEE03C,__READ_WRITE);
__IO_REG32(    RIIC0DRR,                    0xFCFEE040,__READ      );

/***************************************************************************
 **
 **  RIIC ch.1 (Renesas I2C Bus Interface channel 1)
 **
 ***************************************************************************/
__IO_REG32_BIT(RIIC1CR1,                    0xFCFEE400,__READ_WRITE,__riic_iccr1_bits);
__IO_REG32_BIT(RIIC1CR2,                    0xFCFEE404,__READ_WRITE,__riic_iccr2_bits);
__IO_REG32_BIT(RIIC1MR1,                    0xFCFEE408,__READ_WRITE,__riic_icmr1_bits);
__IO_REG32_BIT(RIIC1MR2,                    0xFCFEE40C,__READ_WRITE,__riic_icmr2_bits);
__IO_REG32_BIT(RIIC1MR3,                    0xFCFEE410,__READ_WRITE,__riic_icmr3_bits);
__IO_REG32_BIT(RIIC1FER,                    0xFCFEE414,__READ_WRITE,__riic_icfer_bits);
__IO_REG32_BIT(RIIC1SER,                    0xFCFEE418,__READ_WRITE,__riic_icser_bits);
__IO_REG32_BIT(RIIC1IER,                    0xFCFEE41C,__READ_WRITE,__riic_icier_bits);
__IO_REG32_BIT(RIIC1SR1,                    0xFCFEE420,__READ_WRITE,__riic_icsr1_bits);
__IO_REG32_BIT(RIIC1SR2,                    0xFCFEE424,__READ_WRITE,__riic_icsr2_bits);
__IO_REG32_BIT(RIIC1SAR0,                   0xFCFEE428,__READ_WRITE,__riic_icsar_bits);
__IO_REG32_BIT(RIIC1SAR1,                   0xFCFEE42C,__READ_WRITE,__riic_icsar_bits);
__IO_REG32_BIT(RIIC1SAR2,                   0xFCFEE430,__READ_WRITE,__riic_icsar_bits);
__IO_REG32_BIT(RIIC1BRL,                    0xFCFEE434,__READ_WRITE,__riic_icbrl_bits);
__IO_REG32_BIT(RIIC1BRH,                    0xFCFEE438,__READ_WRITE,__riic_icbrh_bits);
__IO_REG32(    RIIC1DRT,                    0xFCFEE43C,__READ_WRITE);
__IO_REG32(    RIIC1DRR,                    0xFCFEE440,__READ      );

/***************************************************************************
 **
 **  RIIC ch.2 (Renesas I2C Bus Interface channel 2)
 **
 ***************************************************************************/
__IO_REG32_BIT(RIIC2CR1,                    0xFCFEE800,__READ_WRITE,__riic_iccr1_bits);
__IO_REG32_BIT(RIIC2CR2,                    0xFCFEE804,__READ_WRITE,__riic_iccr2_bits);
__IO_REG32_BIT(RIIC2MR1,                    0xFCFEE808,__READ_WRITE,__riic_icmr1_bits);
__IO_REG32_BIT(RIIC2MR2,                    0xFCFEE80C,__READ_WRITE,__riic_icmr2_bits);
__IO_REG32_BIT(RIIC2MR3,                    0xFCFEE810,__READ_WRITE,__riic_icmr3_bits);
__IO_REG32_BIT(RIIC2FER,                    0xFCFEE814,__READ_WRITE,__riic_icfer_bits);
__IO_REG32_BIT(RIIC2SER,                    0xFCFEE818,__READ_WRITE,__riic_icser_bits);
__IO_REG32_BIT(RIIC2IER,                    0xFCFEE81C,__READ_WRITE,__riic_icier_bits);
__IO_REG32_BIT(RIIC2SR1,                    0xFCFEE820,__READ_WRITE,__riic_icsr1_bits);
__IO_REG32_BIT(RIIC2SR2,                    0xFCFEE824,__READ_WRITE,__riic_icsr2_bits);
__IO_REG32_BIT(RIIC2SAR0,                   0xFCFEE828,__READ_WRITE,__riic_icsar_bits);
__IO_REG32_BIT(RIIC2SAR1,                   0xFCFEE82C,__READ_WRITE,__riic_icsar_bits);
__IO_REG32_BIT(RIIC2SAR2,                   0xFCFEE830,__READ_WRITE,__riic_icsar_bits);
__IO_REG32_BIT(RIIC2BRL,                    0xFCFEE834,__READ_WRITE,__riic_icbrl_bits);
__IO_REG32_BIT(RIIC2BRH,                    0xFCFEE838,__READ_WRITE,__riic_icbrh_bits);
__IO_REG32(    RIIC2DRT,                    0xFCFEE83C,__READ_WRITE);
__IO_REG32(    RIIC2DRR,                    0xFCFEE840,__READ      );

/***************************************************************************
 **
 **  RIIC ch.3 (Renesas I2C Bus Interface channel 3)
 **
 ***************************************************************************/
__IO_REG32_BIT(RIIC3CR1,                    0xFCFEEC00,__READ_WRITE,__riic_iccr1_bits);
__IO_REG32_BIT(RIIC3CR2,                    0xFCFEEC04,__READ_WRITE,__riic_iccr2_bits);
__IO_REG32_BIT(RIIC3MR1,                    0xFCFEEC08,__READ_WRITE,__riic_icmr1_bits);
__IO_REG32_BIT(RIIC3MR2,                    0xFCFEEC0C,__READ_WRITE,__riic_icmr2_bits);
__IO_REG32_BIT(RIIC3MR3,                    0xFCFEEC10,__READ_WRITE,__riic_icmr3_bits);
__IO_REG32_BIT(RIIC3FER,                    0xFCFEEC14,__READ_WRITE,__riic_icfer_bits);
__IO_REG32_BIT(RIIC3SER,                    0xFCFEEC18,__READ_WRITE,__riic_icser_bits);
__IO_REG32_BIT(RIIC3IER,                    0xFCFEEC1C,__READ_WRITE,__riic_icier_bits);
__IO_REG32_BIT(RIIC3SR1,                    0xFCFEEC20,__READ_WRITE,__riic_icsr1_bits);
__IO_REG32_BIT(RIIC3SR2,                    0xFCFEEC24,__READ_WRITE,__riic_icsr2_bits);
__IO_REG32_BIT(RIIC3SAR0,                   0xFCFEEC28,__READ_WRITE,__riic_icsar_bits);
__IO_REG32_BIT(RIIC3SAR1,                   0xFCFEEC2C,__READ_WRITE,__riic_icsar_bits);
__IO_REG32_BIT(RIIC3SAR2,                   0xFCFEEC30,__READ_WRITE,__riic_icsar_bits);
__IO_REG32_BIT(RIIC3BRL,                    0xFCFEEC34,__READ_WRITE,__riic_icbrl_bits);
__IO_REG32_BIT(RIIC3BRH,                    0xFCFEEC38,__READ_WRITE,__riic_icbrh_bits);
__IO_REG32(    RIIC3DRT,                    0xFCFEEC3C,__READ_WRITE);
__IO_REG32(    RIIC3DRR,                    0xFCFEEC40,__READ      );

/***************************************************************************
 **
 **  SSIF ch.0 (Serial Sound Interface channel 0)
 **
 ***************************************************************************/
__IO_REG32_BIT(SSIF_SSICR_0,                0xE820B000,__READ_WRITE,__ssif_ssicr_bits);
__IO_REG32_BIT(SSIF_SSISR_0,                0xE820B004,__READ_WRITE,__ssif_ssisr_bits);
__IO_REG32_BIT(SSIF_SSIFCR_0,               0xE820B010,__READ_WRITE,__ssif_ssifcr_bits);
__IO_REG32_BIT(SSIF_SSIFSR_0,               0xE820B014,__READ_WRITE,__ssif_ssifsr_bits);
__IO_REG32(    SSIF_SSIFTDR_0,              0xE820B018,__WRITE     );
__IO_REG32(    SSIF_SSIFRDR_0,              0xE820B01C,__READ      );
__IO_REG32_BIT(SSIF_SSITDMR_0,              0xE820B020,__READ_WRITE,__ssif_ssitdmr_bits);
__IO_REG32_BIT(SSIF_SSIFCCR_0,              0xE820B024,__READ_WRITE,__ssif_ssifccr_bits);
__IO_REG32_BIT(SSIF_SSIFCMR_0,              0xE820B028,__READ_WRITE,__ssif_ssifcmr_bits);
__IO_REG32_BIT(SSIF_SSIFCSR_0,              0xE820B02C,__READ_WRITE,__ssif_ssifcsr_bits);

/***************************************************************************
 **
 **  SSIF ch.1 (Serial Sound Interface channel 1)
 **
 ***************************************************************************/
__IO_REG32_BIT(SSIF_SSICR_1,                0xE820B800,__READ_WRITE,__ssif_ssicr_bits);
__IO_REG32_BIT(SSIF_SSISR_1,                0xE820B804,__READ_WRITE,__ssif_ssisr_bits);
__IO_REG32_BIT(SSIF_SSIFCR_1,               0xE820B810,__READ_WRITE,__ssif_ssifcr_bits);
__IO_REG32_BIT(SSIF_SSIFSR_1,               0xE820B814,__READ_WRITE,__ssif_ssifsr_bits);
__IO_REG32(    SSIF_SSIFTDR_1,              0xE820B818,__WRITE     );
__IO_REG32(    SSIF_SSIFRDR_1,              0xE820B81C,__READ      );
__IO_REG32_BIT(SSIF_SSITDMR_1,              0xE820B820,__READ_WRITE,__ssif_ssitdmr_bits);
__IO_REG32_BIT(SSIF_SSIFCCR_1,              0xE820B824,__READ_WRITE,__ssif_ssifccr_bits);
__IO_REG32_BIT(SSIF_SSIFCMR_1,              0xE820B828,__READ_WRITE,__ssif_ssifcmr_bits);
__IO_REG32_BIT(SSIF_SSIFCSR_1,              0xE820B82C,__READ_WRITE,__ssif_ssifcsr_bits);

/***************************************************************************
 **
 **  SSIF ch.2 (Serial Sound Interface channel 2)
 **
 ***************************************************************************/
__IO_REG32_BIT(SSIF_SSICR_2,                0xE820C000,__READ_WRITE,__ssif_ssicr_bits);
__IO_REG32_BIT(SSIF_SSISR_2,                0xE820C004,__READ_WRITE,__ssif_ssisr_bits);
__IO_REG32_BIT(SSIF_SSIFCR_2,               0xE820C010,__READ_WRITE,__ssif_ssifcr_bits);
__IO_REG32_BIT(SSIF_SSIFSR_2,               0xE820C014,__READ_WRITE,__ssif_ssifsr_bits);
__IO_REG32(    SSIF_SSIFTDR_2,              0xE820C018,__WRITE     );
__IO_REG32(    SSIF_SSIFRDR_2,              0xE820C01C,__READ      );
__IO_REG32_BIT(SSIF_SSITDMR_2,              0xE820C020,__READ_WRITE,__ssif_ssitdmr_bits);
__IO_REG32_BIT(SSIF_SSIFCCR_2,              0xE820C024,__READ_WRITE,__ssif_ssifccr_bits);
__IO_REG32_BIT(SSIF_SSIFCMR_2,              0xE820C028,__READ_WRITE,__ssif_ssifcmr_bits);
__IO_REG32_BIT(SSIF_SSIFCSR_2,              0xE820C02C,__READ_WRITE,__ssif_ssifcsr_bits);

/***************************************************************************
 **
 **  SSIF ch.3 (Serial Sound Interface channel 3)
 **
 ***************************************************************************/
__IO_REG32_BIT(SSIF_SSICR_3,                0xE820C800,__READ_WRITE,__ssif_ssicr_bits);
__IO_REG32_BIT(SSIF_SSISR_3,                0xE820C804,__READ_WRITE,__ssif_ssisr_bits);
__IO_REG32_BIT(SSIF_SSIFCR_3,               0xE820C810,__READ_WRITE,__ssif_ssifcr_bits);
__IO_REG32_BIT(SSIF_SSIFSR_3,               0xE820C814,__READ_WRITE,__ssif_ssifsr_bits);
__IO_REG32(    SSIF_SSIFTDR_3,              0xE820C818,__WRITE     );
__IO_REG32(    SSIF_SSIFRDR_3,              0xE820C81C,__READ      );
__IO_REG32_BIT(SSIF_SSITDMR_3,              0xE820C820,__READ_WRITE,__ssif_ssitdmr_bits);
__IO_REG32_BIT(SSIF_SSIFCCR_3,              0xE820C824,__READ_WRITE,__ssif_ssifccr_bits);
__IO_REG32_BIT(SSIF_SSIFCMR_3,              0xE820C828,__READ_WRITE,__ssif_ssifcmr_bits);
__IO_REG32_BIT(SSIF_SSIFCSR_3,              0xE820C82C,__READ_WRITE,__ssif_ssifcsr_bits);

/***************************************************************************
 **
 **  SSIF ch.4 (Serial Sound Interface channel 4)
 **
 ***************************************************************************/
__IO_REG32_BIT(SSIF_SSICR_4,                0xE820D000,__READ_WRITE,__ssif_ssicr_bits);
__IO_REG32_BIT(SSIF_SSISR_4,                0xE820D004,__READ_WRITE,__ssif_ssisr_bits);
__IO_REG32_BIT(SSIF_SSIFCR_4,               0xE820D010,__READ_WRITE,__ssif_ssifcr_bits);
__IO_REG32_BIT(SSIF_SSIFSR_4,               0xE820D014,__READ_WRITE,__ssif_ssifsr_bits);
__IO_REG32(    SSIF_SSIFTDR_4,              0xE820D018,__WRITE     );
__IO_REG32(    SSIF_SSIFRDR_4,              0xE820D01C,__READ      );
__IO_REG32_BIT(SSIF_SSITDMR_4,              0xE820D020,__READ_WRITE,__ssif_ssitdmr_bits);
__IO_REG32_BIT(SSIF_SSIFCCR_4,              0xE820D024,__READ_WRITE,__ssif_ssifccr_bits);
__IO_REG32_BIT(SSIF_SSIFCMR_4,              0xE820D028,__READ_WRITE,__ssif_ssifcmr_bits);
__IO_REG32_BIT(SSIF_SSIFCSR_4,              0xE820D02C,__READ_WRITE,__ssif_ssifcsr_bits);

/***************************************************************************
 **
 **  SSIF ch.5 (Serial Sound Interface channel 5)
 **
 ***************************************************************************/
__IO_REG32_BIT(SSIF_SSICR_5,                0xE820D800,__READ_WRITE,__ssif_ssicr_bits);
__IO_REG32_BIT(SSIF_SSISR_5,                0xE820D804,__READ_WRITE,__ssif_ssisr_bits);
__IO_REG32_BIT(SSIF_SSIFCR_5,               0xE820D810,__READ_WRITE,__ssif_ssifcr_bits);
__IO_REG32_BIT(SSIF_SSIFSR_5,               0xE820D814,__READ_WRITE,__ssif_ssifsr_bits);
__IO_REG32(    SSIF_SSIFTDR_5,              0xE820D818,__WRITE     );
__IO_REG32(    SSIF_SSIFRDR_5,              0xE820D81C,__READ      );
__IO_REG32_BIT(SSIF_SSITDMR_5,              0xE820D820,__READ_WRITE,__ssif_ssitdmr_bits);
__IO_REG32_BIT(SSIF_SSIFCCR_5,              0xE820D824,__READ_WRITE,__ssif_ssifccr_bits);
__IO_REG32_BIT(SSIF_SSIFCMR_5,              0xE820D828,__READ_WRITE,__ssif_ssifcmr_bits);
__IO_REG32_BIT(SSIF_SSIFCSR_5,              0xE820D82C,__READ_WRITE,__ssif_ssifcsr_bits);

/***************************************************************************
 **
 **  MLB (Media Local Bus)
 **
 ***************************************************************************/
__IO_REG32(    MLB_DCCR,                    0xE8034000,__READ_WRITE);
__IO_REG32(    MLB_SSCR,                    0xE8034004,__READ_WRITE);
__IO_REG32(    MLB_SDCR,                    0xE8034008,__READ_WRITE);
__IO_REG32(    MLB_SMCR,                    0xE803400C,__READ_WRITE);
__IO_REG32(    MLB_VCCR,                    0xE803401C,__READ_WRITE);
__IO_REG32(    MLB_SBCR,                    0xE8034020,__READ_WRITE);
__IO_REG32(    MLB_ABCR,                    0xE8034024,__READ_WRITE);
__IO_REG32(    MLB_CBCR,                    0xE8034028,__READ_WRITE);
__IO_REG32(    MLB_IBCR,                    0xE803402C,__READ_WRITE);
__IO_REG32(    MLB_CICR,                    0xE8034030,__READ_WRITE);
__IO_REG32(    MLB_CECR0,                   0xE8034040,__READ_WRITE);
__IO_REG32(    MLB_CSCR0,                   0xE8034044,__READ_WRITE);
__IO_REG32(    MLB_CCBCR0,                  0xE8034048,__READ_WRITE);
__IO_REG32(    MLB_CNBCR0,                  0xE803404C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR0,                  0xE8034280,__READ_WRITE);
__IO_REG32(    MLB_CECR1,                   0xE8034050,__READ_WRITE);
__IO_REG32(    MLB_CSCR1,                   0xE8034054,__READ_WRITE);
__IO_REG32(    MLB_CCBCR1,                  0xE8034058,__READ_WRITE);
__IO_REG32(    MLB_CNBCR1,                  0xE803405C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR1,                  0xE8034284,__READ_WRITE);
__IO_REG32(    MLB_CECR2,                   0xE8034060,__READ_WRITE);
__IO_REG32(    MLB_CSCR2,                   0xE8034064,__READ_WRITE);
__IO_REG32(    MLB_CCBCR2,                  0xE8034068,__READ_WRITE);
__IO_REG32(    MLB_CNBCR2,                  0xE803406C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR2,                  0xE8034288,__READ_WRITE);
__IO_REG32(    MLB_CECR3,                   0xE8034070,__READ_WRITE);
__IO_REG32(    MLB_CSCR3,                   0xE8034074,__READ_WRITE);
__IO_REG32(    MLB_CCBCR3,                  0xE8034078,__READ_WRITE);
__IO_REG32(    MLB_CNBCR3,                  0xE803407C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR3,                  0xE803428C,__READ_WRITE);
__IO_REG32(    MLB_CECR4,                   0xE8034080,__READ_WRITE);
__IO_REG32(    MLB_CSCR4,                   0xE8034084,__READ_WRITE);
__IO_REG32(    MLB_CCBCR4,                  0xE8034088,__READ_WRITE);
__IO_REG32(    MLB_CNBCR4,                  0xE803408C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR4,                  0xE8034290,__READ_WRITE);
__IO_REG32(    MLB_CECR5,                   0xE8034090,__READ_WRITE);
__IO_REG32(    MLB_CSCR5,                   0xE8034094,__READ_WRITE);
__IO_REG32(    MLB_CCBCR5,                  0xE8034098,__READ_WRITE);
__IO_REG32(    MLB_CNBCR5,                  0xE803409C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR5,                  0xE8034294,__READ_WRITE);
__IO_REG32(    MLB_CECR6,                   0xE80340A0,__READ_WRITE);
__IO_REG32(    MLB_CSCR6,                   0xE80340A4,__READ_WRITE);
__IO_REG32(    MLB_CCBCR6,                  0xE80340A8,__READ_WRITE);
__IO_REG32(    MLB_CNBCR6,                  0xE80340AC,__READ_WRITE);
__IO_REG32(    MLB_LCBCR6,                  0xE8034298,__READ_WRITE);
__IO_REG32(    MLB_CECR7,                   0xE80340B0,__READ_WRITE);
__IO_REG32(    MLB_CSCR7,                   0xE80340B4,__READ_WRITE);
__IO_REG32(    MLB_CCBCR7,                  0xE80340B8,__READ_WRITE);
__IO_REG32(    MLB_CNBCR7,                  0xE80340BC,__READ_WRITE);
__IO_REG32(    MLB_LCBCR7,                  0xE803429C,__READ_WRITE);
__IO_REG32(    MLB_CECR8,                   0xE80340C0,__READ_WRITE);
__IO_REG32(    MLB_CSCR8,                   0xE80340C4,__READ_WRITE);
__IO_REG32(    MLB_CCBCR8,                  0xE80340C8,__READ_WRITE);
__IO_REG32(    MLB_CNBCR8,                  0xE80340CC,__READ_WRITE);
__IO_REG32(    MLB_LCBCR8,                  0xE80342A0,__READ_WRITE);
__IO_REG32(    MLB_CECR9,                   0xE80340D0,__READ_WRITE);
__IO_REG32(    MLB_CSCR9,                   0xE80340D4,__READ_WRITE);
__IO_REG32(    MLB_CCBCR9,                  0xE80340D8,__READ_WRITE);
__IO_REG32(    MLB_CNBCR9,                  0xE80340DC,__READ_WRITE);
__IO_REG32(    MLB_LCBCR9,                  0xE80342A4,__READ_WRITE);
__IO_REG32(    MLB_CECR10,                  0xE80340E0,__READ_WRITE);
__IO_REG32(    MLB_CSCR10,                  0xE80340E4,__READ_WRITE);
__IO_REG32(    MLB_CCBCR10,                 0xE80340E8,__READ_WRITE);
__IO_REG32(    MLB_CNBCR10,                 0xE80340EC,__READ_WRITE);
__IO_REG32(    MLB_LCBCR10,                 0xE80342A8,__READ_WRITE);
__IO_REG32(    MLB_CECR11,                  0xE80340F0,__READ_WRITE);
__IO_REG32(    MLB_CSCR11,                  0xE80340F4,__READ_WRITE);
__IO_REG32(    MLB_CCBCR11,                 0xE80340F8,__READ_WRITE);
__IO_REG32(    MLB_CNBCR11,                 0xE80340FC,__READ_WRITE);
__IO_REG32(    MLB_LCBCR11,                 0xE80342AC,__READ_WRITE);
__IO_REG32(    MLB_CECR12,                  0xE8034100,__READ_WRITE);
__IO_REG32(    MLB_CSCR12,                  0xE8034104,__READ_WRITE);
__IO_REG32(    MLB_CCBCR12,                 0xE8034108,__READ_WRITE);
__IO_REG32(    MLB_CNBCR12,                 0xE803410C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR12,                 0xE80342B0,__READ_WRITE);
__IO_REG32(    MLB_CECR13,                  0xE8034110,__READ_WRITE);
__IO_REG32(    MLB_CSCR13,                  0xE8034114,__READ_WRITE);
__IO_REG32(    MLB_CCBCR13,                 0xE8034118,__READ_WRITE);
__IO_REG32(    MLB_CNBCR13,                 0xE803411C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR13,                 0xE80342B4,__READ_WRITE);
__IO_REG32(    MLB_CECR14,                  0xE8034120,__READ_WRITE);
__IO_REG32(    MLB_CSCR14,                  0xE8034124,__READ_WRITE);
__IO_REG32(    MLB_CCBCR14,                 0xE8034128,__READ_WRITE);
__IO_REG32(    MLB_CNBCR14,                 0xE803412C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR14,                 0xE80342B8,__READ_WRITE);
__IO_REG32(    MLB_CECR15,                  0xE8034130,__READ_WRITE);
__IO_REG32(    MLB_CSCR15,                  0xE8034134,__READ_WRITE);
__IO_REG32(    MLB_CCBCR15,                 0xE8034138,__READ_WRITE);
__IO_REG32(    MLB_CNBCR15,                 0xE803413C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR15,                 0xE80342BC,__READ_WRITE);
__IO_REG32(    MLB_CECR16,                  0xE8034140,__READ_WRITE);
__IO_REG32(    MLB_CSCR16,                  0xE8034144,__READ_WRITE);
__IO_REG32(    MLB_CCBCR16,                 0xE8034148,__READ_WRITE);
__IO_REG32(    MLB_CNBCR16,                 0xE803414C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR16,                 0xE80342C0,__READ_WRITE);
__IO_REG32(    MLB_CECR17,                  0xE8034150,__READ_WRITE);
__IO_REG32(    MLB_CSCR17,                  0xE8034154,__READ_WRITE);
__IO_REG32(    MLB_CCBCR17,                 0xE8034158,__READ_WRITE);
__IO_REG32(    MLB_CNBCR17,                 0xE803415C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR17,                 0xE80342C4,__READ_WRITE);
__IO_REG32(    MLB_CECR18,                  0xE8034160,__READ_WRITE);
__IO_REG32(    MLB_CSCR18,                  0xE8034164,__READ_WRITE);
__IO_REG32(    MLB_CCBCR18,                 0xE8034168,__READ_WRITE);
__IO_REG32(    MLB_CNBCR18,                 0xE803416C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR18,                 0xE80342C8,__READ_WRITE);
__IO_REG32(    MLB_CECR19,                  0xE8034170,__READ_WRITE);
__IO_REG32(    MLB_CSCR19,                  0xE8034174,__READ_WRITE);
__IO_REG32(    MLB_CCBCR19,                 0xE8034178,__READ_WRITE);
__IO_REG32(    MLB_CNBCR19,                 0xE803417C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR19,                 0xE80342CC,__READ_WRITE);
__IO_REG32(    MLB_CECR20,                  0xE8034180,__READ_WRITE);
__IO_REG32(    MLB_CSCR20,                  0xE8034184,__READ_WRITE);
__IO_REG32(    MLB_CCBCR20,                 0xE8034188,__READ_WRITE);
__IO_REG32(    MLB_CNBCR20,                 0xE803418C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR20,                 0xE80342D0,__READ_WRITE);
__IO_REG32(    MLB_CECR21,                  0xE8034190,__READ_WRITE);
__IO_REG32(    MLB_CSCR21,                  0xE8034194,__READ_WRITE);
__IO_REG32(    MLB_CCBCR21,                 0xE8034198,__READ_WRITE);
__IO_REG32(    MLB_CNBCR21,                 0xE803419C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR21,                 0xE80342D4,__READ_WRITE);
__IO_REG32(    MLB_CECR22,                  0xE80341A0,__READ_WRITE);
__IO_REG32(    MLB_CSCR22,                  0xE80341A4,__READ_WRITE);
__IO_REG32(    MLB_CCBCR22,                 0xE80341A8,__READ_WRITE);
__IO_REG32(    MLB_CNBCR22,                 0xE80341AC,__READ_WRITE);
__IO_REG32(    MLB_LCBCR22,                 0xE80342D8,__READ_WRITE);
__IO_REG32(    MLB_CECR23,                  0xE80341B0,__READ_WRITE);
__IO_REG32(    MLB_CSCR23,                  0xE80341B4,__READ_WRITE);
__IO_REG32(    MLB_CCBCR23,                 0xE80341B8,__READ_WRITE);
__IO_REG32(    MLB_CNBCR23,                 0xE80341BC,__READ_WRITE);
__IO_REG32(    MLB_LCBCR23,                 0xE80342DC,__READ_WRITE);
__IO_REG32(    MLB_CECR24,                  0xE80341C0,__READ_WRITE);
__IO_REG32(    MLB_CSCR24,                  0xE80341C4,__READ_WRITE);
__IO_REG32(    MLB_CCBCR24,                 0xE80341C8,__READ_WRITE);
__IO_REG32(    MLB_CNBCR24,                 0xE80341CC,__READ_WRITE);
__IO_REG32(    MLB_LCBCR24,                 0xE80342E0,__READ_WRITE);
__IO_REG32(    MLB_CECR25,                  0xE80341D0,__READ_WRITE);
__IO_REG32(    MLB_CSCR25,                  0xE80341D4,__READ_WRITE);
__IO_REG32(    MLB_CCBCR25,                 0xE80341D8,__READ_WRITE);
__IO_REG32(    MLB_CNBCR25,                 0xE80341DC,__READ_WRITE);
__IO_REG32(    MLB_LCBCR25,                 0xE80342E4,__READ_WRITE);
__IO_REG32(    MLB_CECR26,                  0xE80341E0,__READ_WRITE);
__IO_REG32(    MLB_CSCR26,                  0xE80341E4,__READ_WRITE);
__IO_REG32(    MLB_CCBCR26,                 0xE80341E8,__READ_WRITE);
__IO_REG32(    MLB_CNBCR26,                 0xE80341EC,__READ_WRITE);
__IO_REG32(    MLB_LCBCR26,                 0xE80342E8,__READ_WRITE);
__IO_REG32(    MLB_CECR27,                  0xE80341F0,__READ_WRITE);
__IO_REG32(    MLB_CSCR27,                  0xE80341F4,__READ_WRITE);
__IO_REG32(    MLB_CCBCR27,                 0xE80341F8,__READ_WRITE);
__IO_REG32(    MLB_CNBCR27,                 0xE80341FC,__READ_WRITE);
__IO_REG32(    MLB_LCBCR27,                 0xE80342EC,__READ_WRITE);
__IO_REG32(    MLB_CECR28,                  0xE8034200,__READ_WRITE);
__IO_REG32(    MLB_CSCR28,                  0xE8034204,__READ_WRITE);
__IO_REG32(    MLB_CCBCR28,                 0xE8034208,__READ_WRITE);
__IO_REG32(    MLB_CNBCR28,                 0xE803420C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR28,                 0xE80342F0,__READ_WRITE);
__IO_REG32(    MLB_CECR29,                  0xE8034210,__READ_WRITE);
__IO_REG32(    MLB_CSCR29,                  0xE8034214,__READ_WRITE);
__IO_REG32(    MLB_CCBCR29,                 0xE8034218,__READ_WRITE);
__IO_REG32(    MLB_CNBCR29,                 0xE803421C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR29,                 0xE80342F4,__READ_WRITE);
__IO_REG32(    MLB_CECR30,                  0xE8034220,__READ_WRITE);
__IO_REG32(    MLB_CSCR30,                  0xE8034224,__READ_WRITE);
__IO_REG32(    MLB_CCBCR30,                 0xE8034228,__READ_WRITE);
__IO_REG32(    MLB_CNBCR30,                 0xE803422C,__READ_WRITE);
__IO_REG32(    MLB_LCBCR30,                 0xE80342F8,__READ_WRITE);

/***************************************************************************
 **
 **  RSCAN (Channels and Global Registers)
 **
 ***************************************************************************/
__IO_REG32_BIT(RSCAN0C0CFG,                 0xE803A000,__READ_WRITE,__rscan_cxcfg_bits);
__IO_REG32_BIT(RSCAN0C0CTR,                 0xE803A004,__READ_WRITE,__rscan_cxctr_bits);
__IO_REG32_BIT(RSCAN0C0STS,                 0xE803A008,__READ_WRITE,__rscan_cxsts_bits);
__IO_REG32_BIT(RSCAN0C0ERFL,                0xE803A00C,__READ_WRITE,__rscan_cxerfl_bits);
__IO_REG32_BIT(RSCAN0C1CFG,                 0xE803A010,__READ_WRITE,__rscan_cxcfg_bits);
__IO_REG32_BIT(RSCAN0C1CTR,                 0xE803A014,__READ_WRITE,__rscan_cxctr_bits);
__IO_REG32_BIT(RSCAN0C1STS,                 0xE803A018,__READ_WRITE,__rscan_cxsts_bits);
__IO_REG32_BIT(RSCAN0C1ERFL,                0xE803A01C,__READ_WRITE,__rscan_cxerfl_bits);
__IO_REG32_BIT(RSCAN0C2CFG,                 0xE803A020,__READ_WRITE,__rscan_cxcfg_bits);
__IO_REG32_BIT(RSCAN0C2CTR,                 0xE803A024,__READ_WRITE,__rscan_cxctr_bits);
__IO_REG32_BIT(RSCAN0C2STS,                 0xE803A028,__READ_WRITE,__rscan_cxsts_bits);
__IO_REG32_BIT(RSCAN0C2ERFL,                0xE803A02C,__READ_WRITE,__rscan_cxerfl_bits);
__IO_REG32_BIT(RSCAN0C3CFG,                 0xE803A030,__READ_WRITE,__rscan_cxcfg_bits);
__IO_REG32_BIT(RSCAN0C3CTR,                 0xE803A034,__READ_WRITE,__rscan_cxctr_bits);
__IO_REG32_BIT(RSCAN0C3STS,                 0xE803A038,__READ_WRITE,__rscan_cxsts_bits);
__IO_REG32_BIT(RSCAN0C3ERFL,                0xE803A03C,__READ_WRITE,__rscan_cxerfl_bits);
__IO_REG32_BIT(RSCAN0C4CFG,                 0xE803A040,__READ_WRITE,__rscan_cxcfg_bits);
__IO_REG32_BIT(RSCAN0C4CTR,                 0xE803A044,__READ_WRITE,__rscan_cxctr_bits);
__IO_REG32_BIT(RSCAN0C4STS,                 0xE803A048,__READ_WRITE,__rscan_cxsts_bits);
__IO_REG32_BIT(RSCAN0C4ERFL,                0xE803A04C,__READ_WRITE,__rscan_cxerfl_bits);
__IO_REG32_BIT(RSCAN0GCFG,                  0xE803A084,__READ_WRITE,__rscan_gcfg_bits);
__IO_REG32_BIT(RSCAN0GCTR,                  0xE803A088,__READ_WRITE,__rscan_gctr_bits);
__IO_REG32_BIT(RSCAN0GSTS,                  0xE803A08C,__READ      ,__rscan_gsts_bits);
__IO_REG32_BIT(RSCAN0GERFL,                 0xE803A090,__READ_WRITE,__rscan_gerfl_bits);
__IO_REG16(    RSCAN0GTSC,                  0xE803A094,__READ_WRITE);
__IO_REG32_BIT(RSCAN0GAFLECTR,              0xE803A098,__READ_WRITE,__rscan_gaflectr_bits);
__IO_REG32_BIT(RSCAN0GAFLCFG0,              0xE803A09C,__READ_WRITE,__rscan_gaflcfg0_bits);
__IO_REG32_BIT(RSCAN0GAFLCFG1,              0xE803A0A0,__READ_WRITE,__rscan_gaflcfg1_bits);

/***************************************************************************
 **
 **  RSCAN (RX Message Buffer Configuration & Status Registers)
 **
 ***************************************************************************/
__IO_REG8(     RSCAN0RMNB,                  0xE803A0A4,__READ_WRITE);
__IO_REG32(    RSCAN0RMND0,                 0xE803A0A8,__READ_WRITE);
__IO_REG32(    RSCAN0RMND1,                 0xE803A0AC,__READ_WRITE);
__IO_REG16(    RSCAN0RMND2,                 0xE803A0B0,__READ_WRITE);

/***************************************************************************
 **
 **  RSCAN (RX FIFO Registers)
 **
 ***************************************************************************/
__IO_REG32_BIT(RSCAN0RFCC0,                 0xE803A0B8,__READ_WRITE,__rscan_rfcc_bits);
__IO_REG32_BIT(RSCAN0RFCC1,                 0xE803A0BC,__READ_WRITE,__rscan_rfcc_bits);
__IO_REG32_BIT(RSCAN0RFCC2,                 0xE803A0C0,__READ_WRITE,__rscan_rfcc_bits);
__IO_REG32_BIT(RSCAN0RFCC3,                 0xE803A0C4,__READ_WRITE,__rscan_rfcc_bits);
__IO_REG32_BIT(RSCAN0RFCC4,                 0xE803A0C8,__READ_WRITE,__rscan_rfcc_bits);
__IO_REG32_BIT(RSCAN0RFCC5,                 0xE803A0CC,__READ_WRITE,__rscan_rfcc_bits);
__IO_REG32_BIT(RSCAN0RFCC6,                 0xE803A0D0,__READ_WRITE,__rscan_rfcc_bits);
__IO_REG32_BIT(RSCAN0RFCC7,                 0xE803A0D4,__READ_WRITE,__rscan_rfcc_bits);
__IO_REG32_BIT(RSCAN0RFSTS0,                0xE803A0D8,__READ_WRITE,__rscan_rfsts_bits);
__IO_REG32_BIT(RSCAN0RFSTS1,                0xE803A0DC,__READ_WRITE,__rscan_rfsts_bits);
__IO_REG32_BIT(RSCAN0RFSTS2,                0xE803A0E0,__READ_WRITE,__rscan_rfsts_bits);
__IO_REG32_BIT(RSCAN0RFSTS3,                0xE803A0E4,__READ_WRITE,__rscan_rfsts_bits);
__IO_REG32_BIT(RSCAN0RFSTS4,                0xE803A0E8,__READ_WRITE,__rscan_rfsts_bits);
__IO_REG32_BIT(RSCAN0RFSTS5,                0xE803A0EC,__READ_WRITE,__rscan_rfsts_bits);
__IO_REG32_BIT(RSCAN0RFSTS6,                0xE803A0F0,__READ_WRITE,__rscan_rfsts_bits);
__IO_REG32_BIT(RSCAN0RFSTS7,                0xE803A0F4,__READ_WRITE,__rscan_rfsts_bits);
__IO_REG32(    RSCAN0RFPCTR0,               0xE803A0F8,__WRITE     );
__IO_REG32(    RSCAN0RFPCTR1,               0xE803A0FC,__WRITE     );
__IO_REG32(    RSCAN0RFPCTR2,               0xE803A100,__WRITE     );
__IO_REG32(    RSCAN0RFPCTR3,               0xE803A104,__WRITE     );
__IO_REG32(    RSCAN0RFPCTR4,               0xE803A108,__WRITE     );
__IO_REG32(    RSCAN0RFPCTR5,               0xE803A10C,__WRITE     );
__IO_REG32(    RSCAN0RFPCTR6,               0xE803A110,__WRITE     );
__IO_REG32(    RSCAN0RFPCTR7,               0xE803A114,__WRITE     );

/***************************************************************************
 **
 **  RSCAN (Common & Status Support FIFO Registers)
 **
 ***************************************************************************/
__IO_REG32_BIT(RSCAN0CFCC0,                 0xE803A118,__READ_WRITE,__rscan_cfcc_bits);
__IO_REG32_BIT(RSCAN0CFCC1,                 0xE803A11C,__READ_WRITE,__rscan_cfcc_bits);
__IO_REG32_BIT(RSCAN0CFCC2,                 0xE803A120,__READ_WRITE,__rscan_cfcc_bits);
__IO_REG32_BIT(RSCAN0CFCC3,                 0xE803A124,__READ_WRITE,__rscan_cfcc_bits);
__IO_REG32_BIT(RSCAN0CFCC4,                 0xE803A128,__READ_WRITE,__rscan_cfcc_bits);
__IO_REG32_BIT(RSCAN0CFCC5,                 0xE803A12C,__READ_WRITE,__rscan_cfcc_bits);
__IO_REG32_BIT(RSCAN0CFCC6,                 0xE803A130,__READ_WRITE,__rscan_cfcc_bits);
__IO_REG32_BIT(RSCAN0CFCC7,                 0xE803A134,__READ_WRITE,__rscan_cfcc_bits);
__IO_REG32_BIT(RSCAN0CFCC8,                 0xE803A138,__READ_WRITE,__rscan_cfcc_bits);
__IO_REG32_BIT(RSCAN0CFCC9,                 0xE803A13C,__READ_WRITE,__rscan_cfcc_bits);
__IO_REG32_BIT(RSCAN0CFCC10,                0xE803A140,__READ_WRITE,__rscan_cfcc_bits);
__IO_REG32_BIT(RSCAN0CFCC11,                0xE803A144,__READ_WRITE,__rscan_cfcc_bits);
__IO_REG32_BIT(RSCAN0CFCC12,                0xE803A148,__READ_WRITE,__rscan_cfcc_bits);
__IO_REG32_BIT(RSCAN0CFCC13,                0xE803A14C,__READ_WRITE,__rscan_cfcc_bits);
__IO_REG32_BIT(RSCAN0CFCC14,                0xE803A150,__READ_WRITE,__rscan_cfcc_bits);
__IO_REG32_BIT(RSCAN0CFSTS0,                0xE803A178,__READ_WRITE,__rscan_cfsts_bits);
__IO_REG32_BIT(RSCAN0CFSTS1,                0xE803A17C,__READ_WRITE,__rscan_cfsts_bits);
__IO_REG32_BIT(RSCAN0CFSTS2,                0xE803A180,__READ_WRITE,__rscan_cfsts_bits);
__IO_REG32_BIT(RSCAN0CFSTS3,                0xE803A184,__READ_WRITE,__rscan_cfsts_bits);
__IO_REG32_BIT(RSCAN0CFSTS4,                0xE803A188,__READ_WRITE,__rscan_cfsts_bits);
__IO_REG32_BIT(RSCAN0CFSTS5,                0xE803A18C,__READ_WRITE,__rscan_cfsts_bits);
__IO_REG32_BIT(RSCAN0CFSTS6,                0xE803A190,__READ_WRITE,__rscan_cfsts_bits);
__IO_REG32_BIT(RSCAN0CFSTS7,                0xE803A194,__READ_WRITE,__rscan_cfsts_bits);
__IO_REG32_BIT(RSCAN0CFSTS8,                0xE803A198,__READ_WRITE,__rscan_cfsts_bits);
__IO_REG32_BIT(RSCAN0CFSTS9,                0xE803A19C,__READ_WRITE,__rscan_cfsts_bits);
__IO_REG32_BIT(RSCAN0CFSTS10,               0xE803A1A0,__READ_WRITE,__rscan_cfsts_bits);
__IO_REG32_BIT(RSCAN0CFSTS11,               0xE803A1A4,__READ_WRITE,__rscan_cfsts_bits);
__IO_REG32_BIT(RSCAN0CFSTS12,               0xE803A1A8,__READ_WRITE,__rscan_cfsts_bits);
__IO_REG32_BIT(RSCAN0CFSTS13,               0xE803A1AC,__READ_WRITE,__rscan_cfsts_bits);
__IO_REG32_BIT(RSCAN0CFSTS14,               0xE803A1B0,__READ_WRITE,__rscan_cfsts_bits);
__IO_REG8(     RSCAN0CFPCTR0,               0xE803A1D8,__WRITE     );
__IO_REG8(     RSCAN0CFPCTR1,               0xE803A1DC,__WRITE     );
__IO_REG8(     RSCAN0CFPCTR2,               0xE803A1E0,__WRITE     );
__IO_REG8(     RSCAN0CFPCTR3,               0xE803A1E4,__WRITE     );
__IO_REG8(     RSCAN0CFPCTR4,               0xE803A1E8,__WRITE     );
__IO_REG8(     RSCAN0CFPCTR5,               0xE803A1EC,__WRITE     );
__IO_REG8(     RSCAN0CFPCTR6,               0xE803A1F0,__WRITE     );
__IO_REG8(     RSCAN0CFPCTR7,               0xE803A1F4,__WRITE     );
__IO_REG8(     RSCAN0CFPCTR8,               0xE803A1F8,__WRITE     );
__IO_REG8(     RSCAN0CFPCTR9,               0xE803A1FC,__WRITE     );
__IO_REG8(     RSCAN0CFPCTR10,              0xE803A200,__WRITE     );
__IO_REG8(     RSCAN0CFPCTR11,              0xE803A204,__WRITE     );
__IO_REG8(     RSCAN0CFPCTR12,              0xE803A208,__WRITE     );
__IO_REG8(     RSCAN0CFPCTR13,              0xE803A20C,__WRITE     );
__IO_REG8(     RSCAN0CFPCTR14,              0xE803A210,__WRITE     );
__IO_REG32_BIT(RSCAN0FESTS,                 0xE803A238,__READ      ,__rscan_fests_bits);
__IO_REG32_BIT(RSCAN0FFSTS,                 0xE803A23C,__READ      ,__rscan_ffsts_bits);
__IO_REG32_BIT(RSCAN0FMSTS,                 0xE803A240,__READ      ,__rscan_fmsts_bits);
__IO_REG32_BIT(RSCAN0RFISTS,                0xE803A244,__READ      ,__rscan_rfists_bits);
__IO_REG32_BIT(RSCAN0CFRISTS,               0xE803A248,__READ      ,__rscan_cfrists_bits);
__IO_REG32_BIT(RSCAN0CFTISTS,               0xE803A24C,__READ      ,__rscan_cftists_bits);

/***************************************************************************
 **
 **  RSCAN (TX Message Buffer Control Registers)
 **
 ***************************************************************************/
__IO_REG8_BIT( RSCAN0TMC0,                  0xE803A250,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC1,                  0xE803A251,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC2,                  0xE803A252,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC3,                  0xE803A253,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC4,                  0xE803A254,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC5,                  0xE803A255,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC6,                  0xE803A256,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC7,                  0xE803A257,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC8,                  0xE803A258,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC9,                  0xE803A259,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC10,                 0xE803A25A,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC11,                 0xE803A25B,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC12,                 0xE803A25C,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC13,                 0xE803A25D,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC14,                 0xE803A25E,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC15,                 0xE803A25F,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC16,                 0xE803A260,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC17,                 0xE803A261,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC18,                 0xE803A262,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC19,                 0xE803A263,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC20,                 0xE803A264,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC21,                 0xE803A265,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC22,                 0xE803A266,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC23,                 0xE803A267,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC24,                 0xE803A268,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC25,                 0xE803A269,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC26,                 0xE803A26A,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC27,                 0xE803A26B,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC28,                 0xE803A26C,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC29,                 0xE803A26D,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC30,                 0xE803A26E,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC31,                 0xE803A26F,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC32,                 0xE803A270,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC33,                 0xE803A271,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC34,                 0xE803A272,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC35,                 0xE803A273,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC36,                 0xE803A274,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC37,                 0xE803A275,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC38,                 0xE803A276,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC39,                 0xE803A277,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC40,                 0xE803A278,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC41,                 0xE803A279,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC42,                 0xE803A27A,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC43,                 0xE803A27B,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC44,                 0xE803A27C,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC45,                 0xE803A27D,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC46,                 0xE803A27E,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC47,                 0xE803A27F,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC48,                 0xE803A280,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC49,                 0xE803A281,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC50,                 0xE803A282,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC51,                 0xE803A283,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC52,                 0xE803A284,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC53,                 0xE803A285,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC54,                 0xE803A286,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC55,                 0xE803A287,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC56,                 0xE803A288,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC57,                 0xE803A289,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC58,                 0xE803A28A,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC59,                 0xE803A28B,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC60,                 0xE803A28C,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC61,                 0xE803A28D,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC62,                 0xE803A28E,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC63,                 0xE803A28F,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC64,                 0xE803A290,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC65,                 0xE803A291,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC66,                 0xE803A292,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC67,                 0xE803A293,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC68,                 0xE803A294,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC69,                 0xE803A295,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC70,                 0xE803A296,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC71,                 0xE803A297,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC72,                 0xE803A298,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC73,                 0xE803A299,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC74,                 0xE803A29A,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC75,                 0xE803A29B,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC76,                 0xE803A29C,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC77,                 0xE803A29D,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC78,                 0xE803A29E,__READ_WRITE,__rscan_tmc_bits);
__IO_REG8_BIT( RSCAN0TMC79,                 0xE803A29F,__READ_WRITE,__rscan_tmc_bits);

/***************************************************************************
 **
 **  RSCAN (TX Message Buffer Status Registers)
 **
 ***************************************************************************/
__IO_REG8_BIT( RSCAN0TMSTS0,                0xE803A2D0,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS1,                0xE803A2D1,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS2,                0xE803A2D2,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS3,                0xE803A2D3,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS4,                0xE803A2D4,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS5,                0xE803A2D5,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS6,                0xE803A2D6,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS7,                0xE803A2D7,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS8,                0xE803A2D8,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS9,                0xE803A2D9,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS10,               0xE803A2DA,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS11,               0xE803A2DB,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS12,               0xE803A2DC,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS13,               0xE803A2DD,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS14,               0xE803A2DE,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS15,               0xE803A2DF,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS16,               0xE803A2E0,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS17,               0xE803A2E1,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS18,               0xE803A2E2,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS19,               0xE803A2E3,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS20,               0xE803A2E4,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS21,               0xE803A2E5,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS23,               0xE803A2E6,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS24,               0xE803A2E7,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS25,               0xE803A2E8,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS26,               0xE803A2E9,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS27,               0xE803A2EA,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS28,               0xE803A2EB,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS29,               0xE803A2EC,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS30,               0xE803A2ED,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS31,               0xE803A2EE,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS32,               0xE803A2EF,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS33,               0xE803A2F0,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS34,               0xE803A2F1,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS35,               0xE803A2F2,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS36,               0xE803A2F3,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS37,               0xE803A2F4,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS38,               0xE803A2F5,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS39,               0xE803A2F6,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS40,               0xE803A2F7,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS41,               0xE803A2F8,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS42,               0xE803A2F9,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS43,               0xE803A2FA,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS44,               0xE803A2FB,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS45,               0xE803A2FC,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS46,               0xE803A2FD,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS47,               0xE803A2FE,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS48,               0xE803A2FF,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS49,               0xE803A300,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS50,               0xE803A301,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS51,               0xE803A302,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS52,               0xE803A303,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS53,               0xE803A304,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS54,               0xE803A305,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS55,               0xE803A306,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS56,               0xE803A307,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS57,               0xE803A308,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS58,               0xE803A309,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS59,               0xE803A30A,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS60,               0xE803A30B,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS61,               0xE803A30C,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS62,               0xE803A30D,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS63,               0xE803A30E,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS64,               0xE803A30F,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS65,               0xE803A310,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS66,               0xE803A311,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS67,               0xE803A312,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS68,               0xE803A313,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS69,               0xE803A314,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS70,               0xE803A315,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS71,               0xE803A316,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS72,               0xE803A317,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS73,               0xE803A318,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS74,               0xE803A319,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS75,               0xE803A31A,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS76,               0xE803A31B,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS77,               0xE803A31C,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS78,               0xE803A31E,__READ_WRITE,__rscan_tmsts_bits);
__IO_REG8_BIT( RSCAN0TMSTS79,               0xE803A31F,__READ_WRITE,__rscan_tmsts_bits);

/***************************************************************************
 **
 **  RSCAN (TX Message Buffer Transmission Status & Configuration Registers)
 **
 ***************************************************************************/
__IO_REG32(    RSCAN0TMTRSTS0,              0xE803A350,__READ      );
__IO_REG32(    RSCAN0TMTRSTS1,              0xE803A354,__READ      );
__IO_REG16(    RSCAN0TMTRSTS2,              0xE803A358,__READ      );
__IO_REG32(    RSCAN0TMTARSTS0,             0xE803A360,__READ      );
__IO_REG32(    RSCAN0TMTARSTS1,             0xE803A364,__READ      );
__IO_REG16(    RSCAN0TMTARSTS2,             0xE803A368,__READ      );
__IO_REG32(    RSCAN0TMTCSTS0,              0xE803A370,__READ      );
__IO_REG32(    RSCAN0TMTCSTS1,              0xE803A374,__READ      );
__IO_REG16(    RSCAN0TMTCSTS2,              0xE803A378,__READ      );
__IO_REG32(    RSCAN0TMTASTS0,              0xE803A380,__READ      );
__IO_REG32(    RSCAN0TMTASTS1,              0xE803A384,__READ      );
__IO_REG16(    RSCAN0TMTASTS2,              0xE803A388,__READ      );
__IO_REG32(    RSCAN0TMIEC0,                0xE803A390,__READ_WRITE);
__IO_REG32(    RSCAN0TMIEC1,                0xE803A394,__READ_WRITE);
__IO_REG16(    RSCAN0TMIEC2,                0xE803A398,__READ_WRITE);

/***************************************************************************
 **
 **  RSCAN (TX Queue Registers)
 **
 ***************************************************************************/
__IO_REG32_BIT(RSCAN0TXQCC0,                0xE803A3A0,__READ_WRITE,__rscan_txqcc_bits);
__IO_REG32_BIT(RSCAN0TXQCC1,                0xE803A3A4,__READ_WRITE,__rscan_txqcc_bits);
__IO_REG32_BIT(RSCAN0TXQCC2,                0xE803A3A8,__READ_WRITE,__rscan_txqcc_bits);
__IO_REG32_BIT(RSCAN0TXQCC3,                0xE803A3AC,__READ_WRITE,__rscan_txqcc_bits);
__IO_REG32_BIT(RSCAN0TXQCC4,                0xE803A3B0,__READ_WRITE,__rscan_txqcc_bits);
__IO_REG32_BIT(RSCAN0TXQSTS0,               0xE803A3C0,__READ_WRITE,__rscan_txqsts_bits);
__IO_REG32_BIT(RSCAN0TXQSTS1,               0xE803A3C4,__READ_WRITE,__rscan_txqsts_bits);
__IO_REG32_BIT(RSCAN0TXQSTS2,               0xE803A3C8,__READ_WRITE,__rscan_txqsts_bits);
__IO_REG32_BIT(RSCAN0TXQSTS3,               0xE803A3CC,__READ_WRITE,__rscan_txqsts_bits);
__IO_REG32_BIT(RSCAN0TXQSTS4,               0xE803A3D0,__READ_WRITE,__rscan_txqsts_bits);
__IO_REG8(     RSCAN0TXQPCTR0,              0xE803A3E0,__WRITE     );
__IO_REG8(     RSCAN0TXQPCTR1,              0xE803A3E4,__WRITE     );
__IO_REG8(     RSCAN0TXQPCTR2,              0xE803A3E8,__WRITE     );
__IO_REG8(     RSCAN0TXQPCTR3,              0xE803A3EC,__WRITE     );
__IO_REG8(     RSCAN0TXQPCTR4,              0xE803A3F0,__WRITE     );

/***************************************************************************
 **
 **  RSCAN (TX History List & Common TX & Test Registers)
 **
 ***************************************************************************/
__IO_REG32_BIT(RSCAN0THLCC0,                0xE803A400,__READ_WRITE,__rscan_thlcc_bits);
__IO_REG32_BIT(RSCAN0THLCC1,                0xE803A404,__READ_WRITE,__rscan_thlcc_bits);
__IO_REG32_BIT(RSCAN0THLCC2,                0xE803A408,__READ_WRITE,__rscan_thlcc_bits);
__IO_REG32_BIT(RSCAN0THLCC3,                0xE803A40C,__READ_WRITE,__rscan_thlcc_bits);
__IO_REG32_BIT(RSCAN0THLCC4,                0xE803A410,__READ_WRITE,__rscan_thlcc_bits);
__IO_REG32_BIT(RSCAN0THLSTS0,               0xE803A420,__READ_WRITE,__rscan_thlsts_bits);
__IO_REG32_BIT(RSCAN0THLSTS1,               0xE803A424,__READ_WRITE,__rscan_thlsts_bits);
__IO_REG32_BIT(RSCAN0THLSTS2,               0xE803A428,__READ_WRITE,__rscan_thlsts_bits);
__IO_REG32_BIT(RSCAN0THLSTS3,               0xE803A42C,__READ_WRITE,__rscan_thlsts_bits);
__IO_REG32_BIT(RSCAN0THLSTS4,               0xE803A430,__READ_WRITE,__rscan_thlsts_bits);
__IO_REG8(     RSCAN0THLPCTR0,              0xE803A440,__WRITE     );
__IO_REG8(     RSCAN0THLPCTR1,              0xE803A444,__WRITE     );
__IO_REG8(     RSCAN0THLPCTR2,              0xE803A448,__WRITE     );
__IO_REG8(     RSCAN0THLPCTR3,              0xE803A44C,__WRITE     );
__IO_REG8(     RSCAN0THLPCTR4,              0xE803A450,__WRITE     );
__IO_REG32_BIT(RSCAN0GTINTSTS0,             0xE803A460,__READ      ,__rscan_gtintsts0_bits);
__IO_REG32_BIT(RSCAN0GTINTSTS1,             0xE803A464,__READ      ,__rscan_gtintsts1_bits);
__IO_REG32_BIT(RSCAN0GTSTCFG,               0xE803A468,__READ_WRITE,__rscan_gtstcfg_bits);
__IO_REG32_BIT(RSCAN0GTSTCTR,               0xE803A46C,__READ_WRITE,__rscan_gtstctr_bits);
__IO_REG32(    RSCAN0GLOCKK,                0xE803A47C,__READ_WRITE);

/***************************************************************************
 **
 **  RSCAN (Global Acceptance Filter List Test Mode Access Registers)
 **
 ***************************************************************************/
__IO_REG32_BIT(RSCAN0GAFLID0,               0xE803A500,__READ_WRITE,__rscan_gaflid_bits);
__IO_REG32_BIT(RSCAN0GAFLM0,                0xE803A504,__READ_WRITE,__rscan_gaflm_bits);
__IO_REG32_BIT(RSCAN0GAFLP00,               0xE803A508,__READ_WRITE,__rscan_gaflp0_bits);
__IO_REG32_BIT(RSCAN0GAFLP10,               0xE803A50C,__READ_WRITE,__rscan_gaflp1_bits);
__IO_REG32_BIT(RSCAN0GAFLID1,               0xE803A510,__READ_WRITE,__rscan_gaflid_bits);
__IO_REG32_BIT(RSCAN0GAFLM1,                0xE803A514,__READ_WRITE,__rscan_gaflm_bits);
__IO_REG32_BIT(RSCAN0GAFLP01,               0xE803A518,__READ_WRITE,__rscan_gaflp0_bits);
__IO_REG32_BIT(RSCAN0GAFLP11,               0xE803A51C,__READ_WRITE,__rscan_gaflp1_bits);
__IO_REG32_BIT(RSCAN0GAFLID2,               0xE803A520,__READ_WRITE,__rscan_gaflid_bits);
__IO_REG32_BIT(RSCAN0GAFLM2,                0xE803A524,__READ_WRITE,__rscan_gaflm_bits);
__IO_REG32_BIT(RSCAN0GAFLP02,               0xE803A528,__READ_WRITE,__rscan_gaflp0_bits);
__IO_REG32_BIT(RSCAN0GAFLP12,               0xE803A52C,__READ_WRITE,__rscan_gaflp1_bits);
__IO_REG32_BIT(RSCAN0GAFLID3,               0xE803A530,__READ_WRITE,__rscan_gaflid_bits);
__IO_REG32_BIT(RSCAN0GAFLM3,                0xE803A534,__READ_WRITE,__rscan_gaflm_bits);
__IO_REG32_BIT(RSCAN0GAFLP03,               0xE803A538,__READ_WRITE,__rscan_gaflp0_bits);
__IO_REG32_BIT(RSCAN0GAFLP13,               0xE803A53C,__READ_WRITE,__rscan_gaflp1_bits);
__IO_REG32_BIT(RSCAN0GAFLID4,               0xE803A540,__READ_WRITE,__rscan_gaflid_bits);
__IO_REG32_BIT(RSCAN0GAFLM4,                0xE803A544,__READ_WRITE,__rscan_gaflm_bits);
__IO_REG32_BIT(RSCAN0GAFLP04,               0xE803A548,__READ_WRITE,__rscan_gaflp0_bits);
__IO_REG32_BIT(RSCAN0GAFLP14,               0xE803A54C,__READ_WRITE,__rscan_gaflp1_bits);
__IO_REG32_BIT(RSCAN0GAFLID5,               0xE803A550,__READ_WRITE,__rscan_gaflid_bits);
__IO_REG32_BIT(RSCAN0GAFLM5,                0xE803A554,__READ_WRITE,__rscan_gaflm_bits);
__IO_REG32_BIT(RSCAN0GAFLP05,               0xE803A558,__READ_WRITE,__rscan_gaflp0_bits);
__IO_REG32_BIT(RSCAN0GAFLP15,               0xE803A55C,__READ_WRITE,__rscan_gaflp1_bits);
__IO_REG32_BIT(RSCAN0GAFLID6,               0xE803A560,__READ_WRITE,__rscan_gaflid_bits);
__IO_REG32_BIT(RSCAN0GAFLM6,                0xE803A564,__READ_WRITE,__rscan_gaflm_bits);
__IO_REG32_BIT(RSCAN0GAFLP06,               0xE803A568,__READ_WRITE,__rscan_gaflp0_bits);
__IO_REG32_BIT(RSCAN0GAFLP16,               0xE803A56C,__READ_WRITE,__rscan_gaflp1_bits);
__IO_REG32_BIT(RSCAN0GAFLID7,               0xE803A570,__READ_WRITE,__rscan_gaflid_bits);
__IO_REG32_BIT(RSCAN0GAFLM7,                0xE803A574,__READ_WRITE,__rscan_gaflm_bits);
__IO_REG32_BIT(RSCAN0GAFLP07,               0xE803A578,__READ_WRITE,__rscan_gaflp0_bits);
__IO_REG32_BIT(RSCAN0GAFLP17,               0xE803A57C,__READ_WRITE,__rscan_gaflp1_bits);
__IO_REG32_BIT(RSCAN0GAFLID8,               0xE803A580,__READ_WRITE,__rscan_gaflid_bits);
__IO_REG32_BIT(RSCAN0GAFLM8,                0xE803A584,__READ_WRITE,__rscan_gaflm_bits);
__IO_REG32_BIT(RSCAN0GAFLP08,               0xE803A588,__READ_WRITE,__rscan_gaflp0_bits);
__IO_REG32_BIT(RSCAN0GAFLP18,               0xE803A58C,__READ_WRITE,__rscan_gaflp1_bits);
__IO_REG32_BIT(RSCAN0GAFLID9,               0xE803A590,__READ_WRITE,__rscan_gaflid_bits);
__IO_REG32_BIT(RSCAN0GAFLM9,                0xE803A594,__READ_WRITE,__rscan_gaflm_bits);
__IO_REG32_BIT(RSCAN0GAFLP09,               0xE803A598,__READ_WRITE,__rscan_gaflp0_bits);
__IO_REG32_BIT(RSCAN0GAFLP19,               0xE803A59C,__READ_WRITE,__rscan_gaflp1_bits);
__IO_REG32_BIT(RSCAN0GAFLID10,              0xE803A5A0,__READ_WRITE,__rscan_gaflid_bits);
__IO_REG32_BIT(RSCAN0GAFLM10,               0xE803A5A4,__READ_WRITE,__rscan_gaflm_bits);
__IO_REG32_BIT(RSCAN0GAFLP010,              0xE803A5A8,__READ_WRITE,__rscan_gaflp0_bits);
__IO_REG32_BIT(RSCAN0GAFLP110,              0xE803A5AC,__READ_WRITE,__rscan_gaflp1_bits);
__IO_REG32_BIT(RSCAN0GAFLID11,              0xE803A5B0,__READ_WRITE,__rscan_gaflid_bits);
__IO_REG32_BIT(RSCAN0GAFLM11,               0xE803A5B4,__READ_WRITE,__rscan_gaflm_bits);
__IO_REG32_BIT(RSCAN0GAFLP011,              0xE803A5B8,__READ_WRITE,__rscan_gaflp0_bits);
__IO_REG32_BIT(RSCAN0GAFLP111,              0xE803A5BC,__READ_WRITE,__rscan_gaflp1_bits);
__IO_REG32_BIT(RSCAN0GAFLID12,              0xE803A5C0,__READ_WRITE,__rscan_gaflid_bits);
__IO_REG32_BIT(RSCAN0GAFLM12,               0xE803A5C4,__READ_WRITE,__rscan_gaflm_bits);
__IO_REG32_BIT(RSCAN0GAFLP012,              0xE803A5C8,__READ_WRITE,__rscan_gaflp0_bits);
__IO_REG32_BIT(RSCAN0GAFLP112,              0xE803A5CC,__READ_WRITE,__rscan_gaflp1_bits);
__IO_REG32_BIT(RSCAN0GAFLID13,              0xE803A5D0,__READ_WRITE,__rscan_gaflid_bits);
__IO_REG32_BIT(RSCAN0GAFLM13,               0xE803A5D4,__READ_WRITE,__rscan_gaflm_bits);
__IO_REG32_BIT(RSCAN0GAFLP013,              0xE803A5D8,__READ_WRITE,__rscan_gaflp0_bits);
__IO_REG32_BIT(RSCAN0GAFLP113,              0xE803A5DC,__READ_WRITE,__rscan_gaflp1_bits);
__IO_REG32_BIT(RSCAN0GAFLID14,              0xE803A5E0,__READ_WRITE,__rscan_gaflid_bits);
__IO_REG32_BIT(RSCAN0GAFLM14,               0xE803A5E4,__READ_WRITE,__rscan_gaflm_bits);
__IO_REG32_BIT(RSCAN0GAFLP014,              0xE803A5E8,__READ_WRITE,__rscan_gaflp0_bits);
__IO_REG32_BIT(RSCAN0GAFLP114,              0xE803A5EC,__READ_WRITE,__rscan_gaflp1_bits);
__IO_REG32_BIT(RSCAN0GAFLID15,              0xE803A5F0,__READ_WRITE,__rscan_gaflid_bits);
__IO_REG32_BIT(RSCAN0GAFLM15,               0xE803A5F4,__READ_WRITE,__rscan_gaflm_bits);
__IO_REG32_BIT(RSCAN0GAFLP015,              0xE803A5F8,__READ_WRITE,__rscan_gaflp0_bits);
__IO_REG32_BIT(RSCAN0GAFLP115,              0xE803A5FC,__READ_WRITE,__rscan_gaflp1_bits);

/***************************************************************************
 **
 **  RSCAN (RX Message Buffer Registers)
 **
 ***************************************************************************/
__IO_REG32_BIT(RSCAN0RMID0,                 0xE803A600,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR0,                0xE803A604,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF00,                0xE803A608,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF10,                0xE803A60C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID1,                 0xE803A610,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR1,                0xE803A614,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF01,                0xE803A618,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF11,                0xE803A61C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID2,                 0xE803A620,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR2,                0xE803A624,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF02,                0xE803A628,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF12,                0xE803A62C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID3,                 0xE803A630,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR3,                0xE803A634,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF03,                0xE803A638,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF13,                0xE803A63C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID4,                 0xE803A640,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR4,                0xE803A644,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF04,                0xE803A648,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF14,                0xE803A64C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID5,                 0xE803A650,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR5,                0xE803A654,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF05,                0xE803A658,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF15,                0xE803A65C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID6,                 0xE803A660,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR6,                0xE803A664,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF06,                0xE803A668,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF16,                0xE803A66C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID7,                 0xE803A670,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR7,                0xE803A674,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF07,                0xE803A678,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF17,                0xE803A67C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID8,                 0xE803A680,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR8,                0xE803A684,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF08,                0xE803A688,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF18,                0xE803A68C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID9,                 0xE803A690,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR9,                0xE803A694,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF09,                0xE803A698,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF19,                0xE803A69C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID10,                0xE803A6A0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR10,               0xE803A6A4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF010,               0xE803A6A8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF110,               0xE803A6AC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID11,                0xE803A6B0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR11,               0xE803A6B4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF011,               0xE803A6B8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF111,               0xE803A6BC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID12,                0xE803A6C0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR12,               0xE803A6C4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF012,               0xE803A6C8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF112,               0xE803A6CC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID13,                0xE803A6D0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR13,               0xE803A6D4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF013,               0xE803A6D8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF113,               0xE803A6DC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID14,                0xE803A6E0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR14,               0xE803A6E4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF014,               0xE803A6E8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF114,               0xE803A6EC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID15,                0xE803A6F0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR15,               0xE803A6F4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF015,               0xE803A6F8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF115,               0xE803A6FC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID16,                0xE803A700,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR16,               0xE803A704,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF016,               0xE803A708,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF116,               0xE803A70C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID17,                0xE803A710,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR17,               0xE803A714,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF017,               0xE803A718,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF117,               0xE803A71C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID18,                0xE803A720,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR18,               0xE803A724,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF018,               0xE803A728,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF118,               0xE803A72C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID19,                0xE803A730,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR19,               0xE803A734,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF019,               0xE803A738,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF119,               0xE803A73C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID20,                0xE803A740,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR20,               0xE803A744,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF020,               0xE803A748,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF120,               0xE803A74C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID21,                0xE803A750,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR21,               0xE803A754,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF021,               0xE803A758,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF121,               0xE803A75C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID22,                0xE803A760,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR22,               0xE803A764,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF022,               0xE803A768,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF122,               0xE803A76C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID23,                0xE803A770,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR23,               0xE803A774,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF023,               0xE803A778,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF123,               0xE803A77C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID24,                0xE803A780,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR24,               0xE803A784,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF024,               0xE803A788,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF124,               0xE803A78C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID25,                0xE803A790,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR25,               0xE803A794,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF025,               0xE803A798,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF125,               0xE803A79C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID26,                0xE803A7A0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR26,               0xE803A7A4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF026,               0xE803A7A8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF126,               0xE803A7AC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID27,                0xE803A7B0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR27,               0xE803A7B4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF027,               0xE803A7B8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF127,               0xE803A7BC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID28,                0xE803A7C0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR28,               0xE803A7C4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF028,               0xE803A7C8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF128,               0xE803A7CC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID29,                0xE803A7D0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR29,               0xE803A7D4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF029,               0xE803A7D8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF129,               0xE803A7DC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID30,                0xE803A7E0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR30,               0xE803A7E4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF030,               0xE803A7E8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF130,               0xE803A7EC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID31,                0xE803A7F0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR31,               0xE803A7F4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF031,               0xE803A7F8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF131,               0xE803A7FC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID32,                0xE803A800,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR32,               0xE803A804,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF032,               0xE803A808,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF132,               0xE803A80C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID33,                0xE803A810,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR33,               0xE803A814,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF033,               0xE803A818,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF133,               0xE803A81C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID34,                0xE803A820,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR34,               0xE803A824,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF034,               0xE803A828,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF134,               0xE803A82C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID35,                0xE803A830,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR35,               0xE803A834,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF035,               0xE803A838,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF135,               0xE803A83C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID36,                0xE803A840,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR36,               0xE803A844,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF036,               0xE803A848,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF136,               0xE803A84C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID37,                0xE803A850,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR37,               0xE803A854,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF037,               0xE803A858,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF137,               0xE803A85C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID38,                0xE803A860,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR38,               0xE803A864,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF038,               0xE803A868,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF138,               0xE803A86C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID39,                0xE803A870,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR39,               0xE803A874,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF039,               0xE803A878,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF139,               0xE803A87C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID40,                0xE803A880,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR40,               0xE803A884,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF040,               0xE803A888,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF140,               0xE803A88C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID41,                0xE803A890,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR41,               0xE803A894,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF041,               0xE803A898,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF141,               0xE803A89C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID42,                0xE803A8A0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR42,               0xE803A8A4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF042,               0xE803A8A8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF142,               0xE803A8AC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID43,                0xE803A8B0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR43,               0xE803A8B4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF043,               0xE803A8B8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF143,               0xE803A8BC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID44,                0xE803A8C0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR44,               0xE803A8C4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF044,               0xE803A8C8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF144,               0xE803A8CC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID45,                0xE803A8D0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR45,               0xE803A8D4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF045,               0xE803A8D8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF145,               0xE803A8DC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID46,                0xE803A8E0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR46,               0xE803A8E4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF046,               0xE803A8E8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF146,               0xE803A8EC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID47,                0xE803A8F0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR47,               0xE803A8F4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF047,               0xE803A8F8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF147,               0xE803A8FC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID48,                0xE803A900,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR48,               0xE803A904,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF048,               0xE803A908,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF148,               0xE803A90C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID49,                0xE803A910,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR49,               0xE803A914,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF049,               0xE803A918,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF149,               0xE803A91C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID50,                0xE803A920,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR50,               0xE803A924,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF050,               0xE803A928,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF150,               0xE803A92C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID51,                0xE803A930,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR51,               0xE803A934,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF051,               0xE803A938,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF151,               0xE803A93C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID52,                0xE803A940,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR52,               0xE803A944,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF052,               0xE803A948,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF152,               0xE803A94C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID53,                0xE803A950,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR53,               0xE803A954,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF053,               0xE803A958,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF153,               0xE803A95C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID54,                0xE803A960,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR54,               0xE803A964,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF054,               0xE803A968,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF154,               0xE803A96C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID55,                0xE803A970,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR55,               0xE803A974,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF055,               0xE803A978,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF155,               0xE803A97C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID56,                0xE803A980,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR56,               0xE803A984,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF056,               0xE803A988,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF156,               0xE803A98C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID57,                0xE803A990,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR57,               0xE803A994,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF057,               0xE803A998,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF157,               0xE803A99C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID58,                0xE803A9A0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR58,               0xE803A9A4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF058,               0xE803A9A8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF158,               0xE803A9AC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID59,                0xE803A9B0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR59,               0xE803A9B4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF059,               0xE803A9B8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF159,               0xE803A9BC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID60,                0xE803A9C0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR60,               0xE803A9C4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF060,               0xE803A9C8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF160,               0xE803A9CC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID61,                0xE803A9D0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR61,               0xE803A9D4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF061,               0xE803A9D8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF161,               0xE803A9DC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID62,                0xE803A9E0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR62,               0xE803A9E4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF062,               0xE803A9E8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF162,               0xE803A9EC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID63,                0xE803A9F0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR63,               0xE803A9F4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF063,               0xE803A9F8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF163,               0xE803A9FC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID64,                0xE803AA00,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR64,               0xE803AA04,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF064,               0xE803AA08,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF164,               0xE803AA0C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID65,                0xE803AA10,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR65,               0xE803AA14,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF065,               0xE803AA18,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF165,               0xE803AA1C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID66,                0xE803AA20,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR66,               0xE803AA24,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF066,               0xE803AA28,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF166,               0xE803AA2C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID67,                0xE803AA30,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR67,               0xE803AA34,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF067,               0xE803AA38,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF167,               0xE803AA3C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID68,                0xE803AA40,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR68,               0xE803AA44,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF068,               0xE803AA48,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF168,               0xE803AA4C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID69,                0xE803AA50,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR69,               0xE803AA54,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF069,               0xE803AA58,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF169,               0xE803AA5C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID70,                0xE803AA60,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR70,               0xE803AA64,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF070,               0xE803AA68,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF170,               0xE803AA6C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID71,                0xE803AA70,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR71,               0xE803AA74,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF071,               0xE803AA78,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF171,               0xE803AA7C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID72,                0xE803AA80,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR72,               0xE803AA84,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF072,               0xE803AA88,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF172,               0xE803AA8C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID73,                0xE803AA90,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR73,               0xE803AA94,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF073,               0xE803AA98,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF173,               0xE803AA9C,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID74,                0xE803AAA0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR74,               0xE803AAA4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF074,               0xE803AAA8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF174,               0xE803AAAC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID75,                0xE803AAB0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR75,               0xE803AAB4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF075,               0xE803AAB8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF175,               0xE803AABC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID76,                0xE803AAC0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR76,               0xE803AAC4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF076,               0xE803AAC8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF176,               0xE803AACC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID77,                0xE803AAD0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR77,               0xE803AAD4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF077,               0xE803AAD8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF177,               0xE803AADC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID78,                0xE803AAE0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR78,               0xE803AAE4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF078,               0xE803AAE8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF178,               0xE803AAEC,__READ      ,__rscan_rmdf1_bits);
__IO_REG32_BIT(RSCAN0RMID79,                0xE803AAF0,__READ      ,__rscan_rmid_bits);
__IO_REG32_BIT(RSCAN0RMPTR79,               0xE803AAF4,__READ      ,__rscan_rmptr_bits);
__IO_REG32_BIT(RSCAN0RMDF079,               0xE803AAF8,__READ      ,__rscan_rmdf0_bits);
__IO_REG32_BIT(RSCAN0RMDF179,               0xE803AAFC,__READ      ,__rscan_rmdf1_bits);

/***************************************************************************
 **
 **  RSCAN (RX FIFO Access Registers)
 **
 ***************************************************************************/
__IO_REG32_BIT(RSCAN0RFID0,                 0xE803AE00,__READ      ,__rscan_rfid_bits);
__IO_REG32_BIT(RSCAN0RFPTR0,                0xE803AE04,__READ      ,__rscan_rfptr_bits);
__IO_REG32_BIT(RSCAN0RFDF00,                0xE803AE08,__READ      ,__rscan_rfdf0_bits);
__IO_REG32_BIT(RSCAN0RFDF10,                0xE803AE0C,__READ      ,__rscan_rfdf1_bits);
__IO_REG32_BIT(RSCAN0RFID1,                 0xE803AE10,__READ      ,__rscan_rfid_bits);
__IO_REG32_BIT(RSCAN0RFPTR1,                0xE803AE14,__READ      ,__rscan_rfptr_bits);
__IO_REG32_BIT(RSCAN0RFDF01,                0xE803AE18,__READ      ,__rscan_rfdf0_bits);
__IO_REG32_BIT(RSCAN0RFDF11,                0xE803AE1C,__READ      ,__rscan_rfdf1_bits);
__IO_REG32_BIT(RSCAN0RFID2,                 0xE803AE20,__READ      ,__rscan_rfid_bits);
__IO_REG32_BIT(RSCAN0RFPTR2,                0xE803AE24,__READ      ,__rscan_rfptr_bits);
__IO_REG32_BIT(RSCAN0RFDF02,                0xE803AE28,__READ      ,__rscan_rfdf0_bits);
__IO_REG32_BIT(RSCAN0RFDF12,                0xE803AE2C,__READ      ,__rscan_rfdf1_bits);
__IO_REG32_BIT(RSCAN0RFID3,                 0xE803AE30,__READ      ,__rscan_rfid_bits);
__IO_REG32_BIT(RSCAN0RFPTR3,                0xE803AE34,__READ      ,__rscan_rfptr_bits);
__IO_REG32_BIT(RSCAN0RFDF03,                0xE803AE38,__READ      ,__rscan_rfdf0_bits);
__IO_REG32_BIT(RSCAN0RFDF13,                0xE803AE3C,__READ      ,__rscan_rfdf1_bits);
__IO_REG32_BIT(RSCAN0RFID4,                 0xE803AE40,__READ      ,__rscan_rfid_bits);
__IO_REG32_BIT(RSCAN0RFPTR4,                0xE803AE44,__READ      ,__rscan_rfptr_bits);
__IO_REG32_BIT(RSCAN0RFDF04,                0xE803AE48,__READ      ,__rscan_rfdf0_bits);
__IO_REG32_BIT(RSCAN0RFDF14,                0xE803AE4C,__READ      ,__rscan_rfdf1_bits);
__IO_REG32_BIT(RSCAN0RFID5,                 0xE803AE50,__READ      ,__rscan_rfid_bits);
__IO_REG32_BIT(RSCAN0RFPTR5,                0xE803AE54,__READ      ,__rscan_rfptr_bits);
__IO_REG32_BIT(RSCAN0RFDF05,                0xE803AE58,__READ      ,__rscan_rfdf0_bits);
__IO_REG32_BIT(RSCAN0RFDF15,                0xE803AE5C,__READ      ,__rscan_rfdf1_bits);
__IO_REG32_BIT(RSCAN0RFID6,                 0xE803AE60,__READ      ,__rscan_rfid_bits);
__IO_REG32_BIT(RSCAN0RFPTR6,                0xE803AE64,__READ      ,__rscan_rfptr_bits);
__IO_REG32_BIT(RSCAN0RFDF06,                0xE803AE68,__READ      ,__rscan_rfdf0_bits);
__IO_REG32_BIT(RSCAN0RFDF16,                0xE803AE6C,__READ      ,__rscan_rfdf1_bits);
__IO_REG32_BIT(RSCAN0RFID7,                 0xE803AE70,__READ      ,__rscan_rfid_bits);
__IO_REG32_BIT(RSCAN0RFPTR7,                0xE803AE74,__READ      ,__rscan_rfptr_bits);
__IO_REG32_BIT(RSCAN0RFDF07,                0xE803AE78,__READ      ,__rscan_rfdf0_bits);
__IO_REG32_BIT(RSCAN0RFDF17,                0xE803AE7C,__READ      ,__rscan_rfdf1_bits);

/***************************************************************************
 **
 **  RSCAN (Common FIFO Access Registers)
 **
 ***************************************************************************/
__IO_REG32_BIT(RSCAN0CFID0,                 0xE803AE80,__READ_WRITE,__rscan_cfid_bits);
__IO_REG32_BIT(RSCAN0CFPTR0,                0xE803AE84,__READ_WRITE,__rscan_cfptr_bits);
__IO_REG32_BIT(RSCAN0CFDF00,                0xE803AE88,__READ_WRITE,__rscan_cfdf0_bits);
__IO_REG32_BIT(RSCAN0CFDF10,                0xE803AE8C,__READ_WRITE,__rscan_cfdf1_bits);
__IO_REG32_BIT(RSCAN0CFID1,                 0xE803AE90,__READ_WRITE,__rscan_cfid_bits);
__IO_REG32_BIT(RSCAN0CFPTR1,                0xE803AE94,__READ_WRITE,__rscan_cfptr_bits);
__IO_REG32_BIT(RSCAN0CFDF01,                0xE803AE98,__READ_WRITE,__rscan_cfdf0_bits);
__IO_REG32_BIT(RSCAN0CFDF11,                0xE803AE9C,__READ_WRITE,__rscan_cfdf1_bits);
__IO_REG32_BIT(RSCAN0CFID2,                 0xE803AEA0,__READ_WRITE,__rscan_cfid_bits);
__IO_REG32_BIT(RSCAN0CFPTR2,                0xE803AEA4,__READ_WRITE,__rscan_cfptr_bits);
__IO_REG32_BIT(RSCAN0CFDF02,                0xE803AEA8,__READ_WRITE,__rscan_cfdf0_bits);
__IO_REG32_BIT(RSCAN0CFDF12,                0xE803AEAC,__READ_WRITE,__rscan_cfdf1_bits);
__IO_REG32_BIT(RSCAN0CFID3,                 0xE803AEB0,__READ_WRITE,__rscan_cfid_bits);
__IO_REG32_BIT(RSCAN0CFPTR3,                0xE803AEB4,__READ_WRITE,__rscan_cfptr_bits);
__IO_REG32_BIT(RSCAN0CFDF03,                0xE803AEB8,__READ_WRITE,__rscan_cfdf0_bits);
__IO_REG32_BIT(RSCAN0CFDF13,                0xE803AEBC,__READ_WRITE,__rscan_cfdf1_bits);
__IO_REG32_BIT(RSCAN0CFID4,                 0xE803AEC0,__READ_WRITE,__rscan_cfid_bits);
__IO_REG32_BIT(RSCAN0CFPTR4,                0xE803AEC4,__READ_WRITE,__rscan_cfptr_bits);
__IO_REG32_BIT(RSCAN0CFDF04,                0xE803AEC8,__READ_WRITE,__rscan_cfdf0_bits);
__IO_REG32_BIT(RSCAN0CFDF14,                0xE803AECC,__READ_WRITE,__rscan_cfdf1_bits);
__IO_REG32_BIT(RSCAN0CFID5,                 0xE803AED0,__READ_WRITE,__rscan_cfid_bits);
__IO_REG32_BIT(RSCAN0CFPTR5,                0xE803AED4,__READ_WRITE,__rscan_cfptr_bits);
__IO_REG32_BIT(RSCAN0CFDF05,                0xE803AED8,__READ_WRITE,__rscan_cfdf0_bits);
__IO_REG32_BIT(RSCAN0CFDF15,                0xE803AEDC,__READ_WRITE,__rscan_cfdf1_bits);
__IO_REG32_BIT(RSCAN0CFID6,                 0xE803AEE0,__READ_WRITE,__rscan_cfid_bits);
__IO_REG32_BIT(RSCAN0CFPTR6,                0xE803AEE4,__READ_WRITE,__rscan_cfptr_bits);
__IO_REG32_BIT(RSCAN0CFDF06,                0xE803AEE8,__READ_WRITE,__rscan_cfdf0_bits);
__IO_REG32_BIT(RSCAN0CFDF16,                0xE803AEEC,__READ_WRITE,__rscan_cfdf1_bits);
__IO_REG32_BIT(RSCAN0CFID7,                 0xE803AEF0,__READ_WRITE,__rscan_cfid_bits);
__IO_REG32_BIT(RSCAN0CFPTR7,                0xE803AEF4,__READ_WRITE,__rscan_cfptr_bits);
__IO_REG32_BIT(RSCAN0CFDF07,                0xE803AEF8,__READ_WRITE,__rscan_cfdf0_bits);
__IO_REG32_BIT(RSCAN0CFDF17,                0xE803AEFC,__READ_WRITE,__rscan_cfdf1_bits);
__IO_REG32_BIT(RSCAN0CFID8,                 0xE803AF00,__READ_WRITE,__rscan_cfid_bits);
__IO_REG32_BIT(RSCAN0CFPTR8,                0xE803AF04,__READ_WRITE,__rscan_cfptr_bits);
__IO_REG32_BIT(RSCAN0CFDF08,                0xE803AF08,__READ_WRITE,__rscan_cfdf0_bits);
__IO_REG32_BIT(RSCAN0CFDF18,                0xE803AF0C,__READ_WRITE,__rscan_cfdf1_bits);
__IO_REG32_BIT(RSCAN0CFID9,                 0xE803AF10,__READ_WRITE,__rscan_cfid_bits);
__IO_REG32_BIT(RSCAN0CFPTR9,                0xE803AF14,__READ_WRITE,__rscan_cfptr_bits);
__IO_REG32_BIT(RSCAN0CFDF09,                0xE803AF18,__READ_WRITE,__rscan_cfdf0_bits);
__IO_REG32_BIT(RSCAN0CFDF19,                0xE803AF1C,__READ_WRITE,__rscan_cfdf1_bits);
__IO_REG32_BIT(RSCAN0CFID10,                0xE803AF20,__READ_WRITE,__rscan_cfid_bits);
__IO_REG32_BIT(RSCAN0CFPTR10,               0xE803AF24,__READ_WRITE,__rscan_cfptr_bits);
__IO_REG32_BIT(RSCAN0CFDF010,               0xE803AF28,__READ_WRITE,__rscan_cfdf0_bits);
__IO_REG32_BIT(RSCAN0CFDF110,               0xE803AF2C,__READ_WRITE,__rscan_cfdf1_bits);
__IO_REG32_BIT(RSCAN0CFID11,                0xE803AF30,__READ_WRITE,__rscan_cfid_bits);
__IO_REG32_BIT(RSCAN0CFPTR11,               0xE803AF34,__READ_WRITE,__rscan_cfptr_bits);
__IO_REG32_BIT(RSCAN0CFDF011,               0xE803AF38,__READ_WRITE,__rscan_cfdf0_bits);
__IO_REG32_BIT(RSCAN0CFDF111,               0xE803AF3C,__READ_WRITE,__rscan_cfdf1_bits);
__IO_REG32_BIT(RSCAN0CFID12,                0xE803AF40,__READ_WRITE,__rscan_cfid_bits);
__IO_REG32_BIT(RSCAN0CFPTR12,               0xE803AF44,__READ_WRITE,__rscan_cfptr_bits);
__IO_REG32_BIT(RSCAN0CFDF012,               0xE803AF48,__READ_WRITE,__rscan_cfdf0_bits);
__IO_REG32_BIT(RSCAN0CFDF112,               0xE803AF4C,__READ_WRITE,__rscan_cfdf1_bits);
__IO_REG32_BIT(RSCAN0CFID13,                0xE803AF50,__READ_WRITE,__rscan_cfid_bits);
__IO_REG32_BIT(RSCAN0CFPTR13,               0xE803AF54,__READ_WRITE,__rscan_cfptr_bits);
__IO_REG32_BIT(RSCAN0CFDF013,               0xE803AF58,__READ_WRITE,__rscan_cfdf0_bits);
__IO_REG32_BIT(RSCAN0CFDF113,               0xE803AF5C,__READ_WRITE,__rscan_cfdf1_bits);
__IO_REG32_BIT(RSCAN0CFID14,                0xE803AF60,__READ_WRITE,__rscan_cfid_bits);
__IO_REG32_BIT(RSCAN0CFPTR14,               0xE803AF64,__READ_WRITE,__rscan_cfptr_bits);
__IO_REG32_BIT(RSCAN0CFDF014,               0xE803AF68,__READ_WRITE,__rscan_cfdf0_bits);
__IO_REG32_BIT(RSCAN0CFDF114,               0xE803AF6C,__READ_WRITE,__rscan_cfdf1_bits);

/***************************************************************************
 **
 **  RSCAN (TX Message Buffer & History List Registers)
 **
 ***************************************************************************/
__IO_REG32_BIT(RSCAN0TMID0,                 0xE803B000,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR0,                0xE803B004,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF00,                0xE803B008,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF10,                0xE803B00C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID1,                 0xE803B010,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR1,                0xE803B014,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF01,                0xE803B018,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF11,                0xE803B01C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID2,                 0xE803B020,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR2,                0xE803B024,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF02,                0xE803B028,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF12,                0xE803B02C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID3,                 0xE803B030,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR3,                0xE803B034,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF03,                0xE803B038,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF13,                0xE803B03C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID4,                 0xE803B040,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR4,                0xE803B044,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF04,                0xE803B048,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF14,                0xE803B04C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID5,                 0xE803B050,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR5,                0xE803B054,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF05,                0xE803B058,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF15,                0xE803B05C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID6,                 0xE803B060,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR6,                0xE803B064,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF06,                0xE803B068,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF16,                0xE803B06C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID7,                 0xE803B070,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR7,                0xE803B074,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF07,                0xE803B078,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF17,                0xE803B07C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID8,                 0xE803B080,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR8,                0xE803B084,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF08,                0xE803B088,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF18,                0xE803B08C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID9,                 0xE803B090,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR9,                0xE803B094,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF09,                0xE803B098,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF19,                0xE803B09C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID10,                0xE803B0A0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR10,               0xE803B0A4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF010,               0xE803B0A8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF110,               0xE803B0AC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID11,                0xE803B0B0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR11,               0xE803B0B4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF011,               0xE803B0B8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF111,               0xE803B0BC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID12,                0xE803B0C0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR12,               0xE803B0C4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF012,               0xE803B0C8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF112,               0xE803B0CC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID13,                0xE803B0D0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR13,               0xE803B0D4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF013,               0xE803B0D8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF113,               0xE803B0DC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID14,                0xE803B0E0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR14,               0xE803B0E4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF014,               0xE803B0E8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF114,               0xE803B0EC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID15,                0xE803B0F0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR15,               0xE803B0F4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF015,               0xE803B0F8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF115,               0xE803B0FC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID16,                0xE803B100,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR16,               0xE803B104,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF016,               0xE803B108,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF116,               0xE803B10C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID17,                0xE803B110,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR17,               0xE803B114,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF017,               0xE803B118,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF117,               0xE803B11C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID18,                0xE803B120,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR18,               0xE803B124,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF018,               0xE803B128,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF118,               0xE803B12C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID19,                0xE803B130,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR19,               0xE803B134,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF019,               0xE803B138,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF119,               0xE803B13C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID20,                0xE803B140,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR20,               0xE803B144,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF020,               0xE803B148,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF120,               0xE803B14C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID21,                0xE803B150,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR21,               0xE803B154,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF021,               0xE803B158,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF121,               0xE803B15C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID22,                0xE803B160,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR22,               0xE803B164,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF022,               0xE803B168,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF122,               0xE803B16C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID23,                0xE803B170,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR23,               0xE803B174,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF023,               0xE803B178,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF123,               0xE803B17C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID24,                0xE803B180,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR24,               0xE803B184,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF024,               0xE803B188,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF124,               0xE803B18C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID25,                0xE803B190,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR25,               0xE803B194,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF025,               0xE803B198,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF125,               0xE803B19C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID26,                0xE803B1A0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR26,               0xE803B1A4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF026,               0xE803B1A8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF126,               0xE803B1AC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID27,                0xE803B1B0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR27,               0xE803B1B4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF027,               0xE803B1B8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF127,               0xE803B1BC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID28,                0xE803B1C0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR28,               0xE803B1C4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF028,               0xE803B1C8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF128,               0xE803B1CC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID29,                0xE803B1D0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR29,               0xE803B1D4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF029,               0xE803B1D8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF129,               0xE803B1DC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID30,                0xE803B1E0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR30,               0xE803B1E4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF030,               0xE803B1E8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF130,               0xE803B1EC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID31,                0xE803B1F0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR31,               0xE803B1F4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF031,               0xE803B1F8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF131,               0xE803B1FC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID32,                0xE803B200,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR32,               0xE803B204,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF032,               0xE803B208,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF132,               0xE803B20C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID33,                0xE803B210,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR33,               0xE803B214,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF033,               0xE803B218,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF133,               0xE803B21C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID34,                0xE803B220,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR34,               0xE803B224,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF034,               0xE803B228,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF134,               0xE803B22C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID35,                0xE803B230,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR35,               0xE803B234,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF035,               0xE803B238,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF135,               0xE803B23C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID36,                0xE803B240,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR36,               0xE803B244,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF036,               0xE803B248,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF136,               0xE803B24C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID37,                0xE803B250,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR37,               0xE803B254,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF037,               0xE803B258,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF137,               0xE803B25C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID38,                0xE803B260,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR38,               0xE803B264,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF038,               0xE803B268,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF138,               0xE803B26C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID39,                0xE803B270,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR39,               0xE803B274,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF039,               0xE803B278,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF139,               0xE803B27C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID40,                0xE803B280,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR40,               0xE803B284,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF040,               0xE803B288,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF140,               0xE803B28C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID41,                0xE803B290,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR41,               0xE803B294,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF041,               0xE803B298,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF141,               0xE803B29C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID42,                0xE803B2A0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR42,               0xE803B2A4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF042,               0xE803B2A8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF142,               0xE803B2AC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID43,                0xE803B2B0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR43,               0xE803B2B4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF043,               0xE803B2B8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF143,               0xE803B2BC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID44,                0xE803B2C0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR44,               0xE803B2C4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF044,               0xE803B2C8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF144,               0xE803B2CC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID45,                0xE803B2D0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR45,               0xE803B2D4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF045,               0xE803B2D8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF145,               0xE803B2DC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID46,                0xE803B2E0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR46,               0xE803B2E4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF046,               0xE803B2E8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF146,               0xE803B2EC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID47,                0xE803B2F0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR47,               0xE803B2F4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF047,               0xE803B2F8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF147,               0xE803B2FC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID48,                0xE803B300,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR48,               0xE803B304,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF048,               0xE803B308,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF148,               0xE803B30C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID49,                0xE803B310,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR49,               0xE803B314,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF049,               0xE803B318,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF149,               0xE803B31C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID50,                0xE803B320,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR50,               0xE803B324,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF050,               0xE803B328,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF150,               0xE803B32C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID51,                0xE803B330,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR51,               0xE803B334,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF051,               0xE803B338,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF151,               0xE803B33C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID52,                0xE803B340,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR52,               0xE803B344,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF052,               0xE803B348,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF152,               0xE803B34C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID53,                0xE803B350,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR53,               0xE803B354,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF053,               0xE803B358,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF153,               0xE803B35C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID54,                0xE803B360,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR54,               0xE803B364,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF054,               0xE803B368,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF154,               0xE803B36C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID55,                0xE803B370,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR55,               0xE803B374,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF055,               0xE803B378,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF155,               0xE803B37C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID56,                0xE803B380,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR56,               0xE803B384,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF056,               0xE803B388,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF156,               0xE803B38C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID57,                0xE803B390,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR57,               0xE803B394,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF057,               0xE803B398,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF157,               0xE803B39C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID58,                0xE803B3A0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR58,               0xE803B3A4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF058,               0xE803B3A8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF158,               0xE803B3AC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID59,                0xE803B3B0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR59,               0xE803B3B4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF059,               0xE803B3B8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF159,               0xE803B3BC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID60,                0xE803B3C0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR60,               0xE803B3C4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF060,               0xE803B3C8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF160,               0xE803B3CC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID61,                0xE803B3D0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR61,               0xE803B3D4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF061,               0xE803B3D8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF161,               0xE803B3DC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID62,                0xE803B3E0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR62,               0xE803B3E4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF062,               0xE803B3E8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF162,               0xE803B3EC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID63,                0xE803B3F0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR63,               0xE803B3F4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF063,               0xE803B3F8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF163,               0xE803B3FC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID64,                0xE803B400,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR64,               0xE803B404,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF064,               0xE803B408,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF164,               0xE803B40C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID65,                0xE803B410,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR65,               0xE803B414,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF065,               0xE803B418,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF165,               0xE803B41C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID66,                0xE803B420,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR66,               0xE803B424,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF066,               0xE803B428,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF166,               0xE803B42C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID67,                0xE803B430,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR67,               0xE803B434,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF067,               0xE803B438,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF167,               0xE803B43C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID68,                0xE803B440,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR68,               0xE803B444,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF068,               0xE803B448,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF168,               0xE803B44C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID69,                0xE803B450,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR69,               0xE803B454,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF069,               0xE803B458,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF169,               0xE803B45C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID70,                0xE803B460,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR70,               0xE803B464,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF070,               0xE803B468,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF170,               0xE803B46C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID71,                0xE803B470,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR71,               0xE803B474,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF071,               0xE803B478,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF171,               0xE803B47C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID72,                0xE803B480,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR72,               0xE803B484,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF072,               0xE803B488,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF172,               0xE803B48C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID73,                0xE803B490,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR73,               0xE803B494,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF073,               0xE803B498,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF173,               0xE803B49C,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID74,                0xE803B4A0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR74,               0xE803B4A4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF074,               0xE803B4A8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF174,               0xE803B4AC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID75,                0xE803B4B0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR75,               0xE803B4B4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF075,               0xE803B4B8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF175,               0xE803B4BC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID76,                0xE803B4C0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR76,               0xE803B4C4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF076,               0xE803B4C8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF176,               0xE803B4CC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID77,                0xE803B4D0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR77,               0xE803B4D4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF077,               0xE803B4D8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF177,               0xE803B4DC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID78,                0xE803B4E0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR78,               0xE803B4E4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF078,               0xE803B4E8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF178,               0xE803B4EC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0TMID79,                0xE803B4F0,__READ_WRITE,__rscan_tmid_bits);
__IO_REG32_BIT(RSCAN0TMPTR79,               0xE803B4F4,__READ_WRITE,__rscan_tmptr_bits);
__IO_REG32_BIT(RSCAN0TMDF079,               0xE803B4F8,__READ_WRITE,__rscan_tmdf0_bits);
__IO_REG32_BIT(RSCAN0TMDF179,               0xE803B4FC,__READ_WRITE,__rscan_tmdf1_bits);
__IO_REG32_BIT(RSCAN0THLACC0,               0xE803B800,__READ      ,__rscan_thlacc_bits);
__IO_REG32_BIT(RSCAN0THLACC1,               0xE803B804,__READ      ,__rscan_thlacc_bits);
__IO_REG32_BIT(RSCAN0THLACC2,               0xE803B808,__READ      ,__rscan_thlacc_bits);
__IO_REG32_BIT(RSCAN0THLACC3,               0xE803B80C,__READ      ,__rscan_thlacc_bits);
__IO_REG32_BIT(RSCAN0THLACC4,               0xE803B810,__READ      ,__rscan_thlacc_bits);

/***************************************************************************
 **
 **  IEBB (IEBus Controller)
 **
 ***************************************************************************/
__IO_REG8_BIT( IEBB0BCR,                    0xFCFEF000,__READ_WRITE,__iebb_bcr_bits);
__IO_REG8_BIT( IEBB0PSR,                    0xFCFEF004,__READ_WRITE,__iebb_psr_bits);
__IO_REG16(    IEBB0UAR,                    0xFCFEF008,__READ_WRITE);
__IO_REG16(    IEBB0SAR,                    0xFCFEF00C,__READ_WRITE);
__IO_REG16(    IEBB0PAR,                    0xFCFEF010,__READ      );
__IO_REG16(    IEBB0RSA,                    0xFCFEF014,__READ      );
__IO_REG8_BIT( IEBB0CDR,                    0xFCFEF018,__READ_WRITE,__iebb_cdr_bits);
__IO_REG8_BIT( IEBB0TCD,                    0xFCFEF01C,__READ_WRITE,__iebb_tcd_bits);
__IO_REG8_BIT( IEBB0RCD,                    0xFCFEF020,__READ      ,__iebb_rcd_bits);
__IO_REG8(     IEBB0DLR,                    0xFCFEF024,__READ_WRITE);
__IO_REG8(     IEBB0TDL,                    0xFCFEF028,__READ_WRITE);
__IO_REG8(     IEBB0RDL,                    0xFCFEF02C,__READ      );
__IO_REG8_BIT( IEBB0CKS,                    0xFCFEF030,__READ_WRITE,__iebb_cks_bits);
__IO_REG8_BIT( IEBB0TMS,                    0xFCFEF034,__READ_WRITE,__iebb_tms_bits);
__IO_REG8(     IEBB0PCR,                    0xFCFEF038,__WRITE     );
__IO_REG16_BIT(IEBB0BSR,                    0xFCFEF03C,__READ      ,__iebb_bsr_bits);
__IO_REG8_BIT( IEBB0SSR,                    0xFCFEF040,__READ      ,__iebb_ssr_bits);
__IO_REG8_BIT( IEBB0USR,                    0xFCFEF044,__READ      ,__iebb_usr_bits);
__IO_REG8_BIT( IEBB0ISR,                    0xFCFEF048,__READ_WRITE,__iebb_isr_bits);
__IO_REG8_BIT( IEBB0ESR,                    0xFCFEF04C,__READ      ,__iebb_esr_bits);
__IO_REG8_BIT( IEBB0FSR,                    0xFCFEF050,__READ      ,__iebb_fsr_bits);
__IO_REG8(     IEBB0SCR,                    0xFCFEF054,__READ      );
__IO_REG8(     IEBB0CCR,                    0xFCFEF058,__READ      );
__IO_REG8(     IEBB0STC0,                   0xFCFEF05C,__WRITE     );
__IO_REG8(     IEBB0STC1,                   0xFCFEF060,__WRITE     );
__IO_REG8(     IEBB0DR,                     0xFCFEF064,__READ_WRITE);

/***************************************************************************
 **
 **  RSPDIF (Renesas SPDIF Interface)
 **
 ***************************************************************************/
__IO_REG32(    RSPDIF_TLCA,                 0xFFFFD800,__WRITE     );
__IO_REG32(    RSPDIF_TRCA,                 0xFFFFD804,__WRITE     );
__IO_REG32(    RSPDIF_TLCS,                 0xFFFFD808,__WRITE     );
__IO_REG32(    RSPDIF_TRCS,                 0xFFFFD80C,__WRITE     );
__IO_REG32(    RSPDIF_TUI,                  0xFFFFD810,__WRITE     );
__IO_REG32_BIT(RSPDIF_RLCA,                 0xFFFFD814,__READ      ,__rspdif_rlca_bits);
__IO_REG32_BIT(RSPDIF_RRCA,                 0xFFFFD818,__READ      ,__rspdif_rrca_bits);
__IO_REG32_BIT(RSPDIF_RLCS,                 0xFFFFD81C,__READ      ,__rspdif_rlcs_rrcs_bits);
__IO_REG32_BIT(RSPDIF_RRCS,                 0xFFFFD820,__READ      ,__rspdif_rlcs_rrcs_bits);
__IO_REG32_BIT(RSPDIF_RUI,                  0xFFFFD824,__READ      ,__rspdif_rui_bits);
__IO_REG32_BIT(RSPDIF_CTRL,                 0xFFFFD828,__READ_WRITE,__rspdif_ctrl_bits);
__IO_REG32_BIT(RSPDIF_STAT,                 0xFFFFD82C,__READ_WRITE,__rspdif_stat_bits);
__IO_REG32(    RSPDIF_TDAD,                 0xFFFFD830,__WRITE     );
__IO_REG32_BIT(RSPDIF_RDAD,                 0xFFFFD834,__READ_WRITE,__rspdif_rdad_bits);

/***************************************************************************
 **
 **  ROMDEC (CD-ROM Decoder)
 **
 ***************************************************************************/
__IO_REG8_BIT( ROMDEC_CROMEN,               0xE8005000,__READ_WRITE,__romdec_cromen_bits);
__IO_REG8_BIT( ROMDEC_CROMSY0,              0xE8005001,__READ_WRITE,__romdec_cromsy0_bits);
__IO_REG8_BIT( ROMDEC_CROMCTL0,             0xE8005002,__READ_WRITE,__romdec_cromctl0_bits);
__IO_REG8_BIT( ROMDEC_CROMCTL1,             0xE8005003,__READ_WRITE,__romdec_cromctl1_bits);
__IO_REG8_BIT( ROMDEC_CROMCTL3,             0xE8005005,__READ_WRITE,__romdec_cromctl3_bits);
__IO_REG8_BIT( ROMDEC_CROMCTL4,             0xE8005006,__READ_WRITE,__romdec_cromctl4_bits);
__IO_REG8_BIT( ROMDEC_CROMCTL5,             0xE8005007,__READ_WRITE,__romdec_cromctl5_bits);
__IO_REG8_BIT( ROMDEC_CROMST0,              0xE8005008,__READ      ,__romdec_cromst0_bits);
__IO_REG8_BIT( ROMDEC_CROMST1,              0xE8005009,__READ      ,__romdec_cromst1_bits);
__IO_REG8_BIT( ROMDEC_CROMST3,              0xE800500B,__READ      ,__romdec_cromst3_bits);
__IO_REG8_BIT( ROMDEC_CROMST4,              0xE800500C,__READ      ,__romdec_cromst4_bits);
__IO_REG8_BIT( ROMDEC_CROMST5,              0xE800500D,__READ      ,__romdec_cromst5_bits);
__IO_REG8_BIT( ROMDEC_CROMST6,              0xE800500E,__READ      ,__romdec_cromst6_bits);
__IO_REG8_BIT( ROMDEC_CBUFST0,              0xE8005014,__READ      ,__romdec_cbufst0_bits);
__IO_REG8_BIT( ROMDEC_CBUFST1,              0xE8005015,__READ      ,__romdec_cbufst1_bits);
__IO_REG8_BIT( ROMDEC_CBUFST2,              0xE8005016,__READ      ,__romdec_cbufst2_bits);
__IO_REG8(     ROMDEC_HEAD00,               0xE8005018,__READ      );
__IO_REG8(     ROMDEC_HEAD01,               0xE8005019,__READ      );
__IO_REG8(     ROMDEC_HEAD02,               0xE800501A,__READ      );
__IO_REG8(     ROMDEC_HEAD03,               0xE800501B,__READ      );
__IO_REG8(     ROMDEC_SHEAD00,              0xE800501C,__READ      );
__IO_REG8(     ROMDEC_SHEAD01,              0xE800501D,__READ      );
__IO_REG8(     ROMDEC_SHEAD02,              0xE800501E,__READ      );
__IO_REG8(     ROMDEC_SHEAD03,              0xE800501F,__READ      );
__IO_REG8(     ROMDEC_SHEAD04,              0xE8005020,__READ      );
__IO_REG8(     ROMDEC_SHEAD05,              0xE8005021,__READ      );
__IO_REG8(     ROMDEC_SHEAD06,              0xE8005022,__READ      );
__IO_REG8(     ROMDEC_SHEAD07,              0xE8005023,__READ      );
__IO_REG8(     ROMDEC_HEAD20,               0xE8005024,__READ      );
__IO_REG8(     ROMDEC_HEAD21,               0xE8005025,__READ      );
__IO_REG8(     ROMDEC_HEAD22,               0xE8005026,__READ      );
__IO_REG8(     ROMDEC_HEAD23,               0xE8005027,__READ      );
__IO_REG8(     ROMDEC_SHEAD20,              0xE8005028,__READ      );
__IO_REG8(     ROMDEC_SHEAD21,              0xE8005029,__READ      );
__IO_REG8(     ROMDEC_SHEAD22,              0xE800502A,__READ      );
__IO_REG8(     ROMDEC_SHEAD23,              0xE800502B,__READ      );
__IO_REG8(     ROMDEC_SHEAD24,              0xE800502C,__READ      );
__IO_REG8(     ROMDEC_SHEAD25,              0xE800502D,__READ      );
__IO_REG8(     ROMDEC_SHEAD26,              0xE800502E,__READ      );
__IO_REG8(     ROMDEC_SHEAD27,              0xE800502F,__READ      );
__IO_REG8(     ROMDEC_CBUFCTL0,             0xE8005040,__READ_WRITE);
__IO_REG8(     ROMDEC_CBUFCTL1,             0xE8005041,__READ_WRITE);
__IO_REG8(     ROMDEC_CBUFCTL2,             0xE8005042,__READ_WRITE);
__IO_REG8(     ROMDEC_CBUFCTL3,             0xE8005043,__READ_WRITE);
__IO_REG8_BIT( ROMDEC_CROMST0M,             0xE8005045,__READ_WRITE,__romdec_cromst0m_bits);
__IO_REG8_BIT( ROMDEC_ROMDECRST,            0xE8005100,__READ_WRITE,__romdec_romdecrst_bits);
__IO_REG8_BIT( ROMDEC_RSTSTAT,              0xE8005101,__READ      ,__romdec_rststat_bits);
__IO_REG8_BIT( ROMDEC_SSI,                  0xE8005102,__READ_WRITE,__romdec_ssi_bits);
__IO_REG8_BIT( ROMDEC_INTHOLD,              0xE8005108,__READ_WRITE,__romdec_inthold_bits);
__IO_REG8_BIT( ROMDEC_INHINT,               0xE8005109,__READ_WRITE,__romdec_inhint_bits);
__IO_REG16(    ROMDEC_STRMDIN0,             0xE8005200,__READ_WRITE);
__IO_REG16(    ROMDEC_STRMDIN1,             0xE8005202,__READ_WRITE);
__IO_REG16(    ROMDEC_STRMDOUT0,            0xE8005204,__READ_WRITE);

/***************************************************************************
 **
 **  ETHER (Ethernet Controller)
 **
 ***************************************************************************/
__IO_REG32_BIT(ETHER_ARSTR,                 0xE8204800,__READ_WRITE,__ether_arstr_bits);
__IO_REG32_BIT(ETHER_ECMR0,                 0xE8203500,__READ_WRITE,__ether_ecmr_bits);
__IO_REG32_BIT(ETHER_ECSR0,                 0xE8203510,__READ_WRITE,__ether_ecsr_bits);
__IO_REG32_BIT(ETHER_ECSIPR0,               0xE8203518,__READ_WRITE,__ether_ecsipr_bits);
__IO_REG32_BIT(ETHER_PIR0,                  0xE8203520,__READ_WRITE,__ether_pir_bits);
__IO_REG32(    ETHER_MAHR0,                 0xE82035C0,__READ_WRITE);
__IO_REG32_BIT(ETHER_MALR0,                 0xE82035C8,__READ_WRITE,__ether_malr_bits);
__IO_REG32_BIT(ETHER_RFLR0,                 0xE8203508,__READ_WRITE,__ether_rflr_bits);
__IO_REG32_BIT(ETHER_TROCR0,                0xE8203700,__READ_WRITE,__ether_trocr_bits);
__IO_REG32_BIT(ETHER_CDCR0,                 0xE8203708,__READ_WRITE,__ether_cdcr_bits);
__IO_REG32_BIT(ETHER_LCCR0,                 0xE8203710,__READ_WRITE,__ether_lccr_bits);
__IO_REG32_BIT(ETHER_CEFCR0,                0xE8203740,__READ_WRITE,__ether_cefcr_bits);
__IO_REG32_BIT(ETHER_FRECR0,                0xE8203748,__READ_WRITE,__ether_frecr_bits);
__IO_REG32_BIT(ETHER_TSFRCR0,               0xE8203750,__READ_WRITE,__ether_tsfrcr_bits);
__IO_REG32_BIT(ETHER_TLFRCR0,               0xE8203758,__READ_WRITE,__ether_tlfrcr_bits);
__IO_REG32_BIT(ETHER_RFCR0,                 0xE8203760,__READ_WRITE,__ether_rfcr_bits);
__IO_REG32_BIT(ETHER_CERCR0,                0xE8203768,__READ_WRITE,__ether_cercr_bits);
__IO_REG32_BIT(ETHER_CEECR0,                0xE8203770,__READ_WRITE,__ether_ceecr_bits);
__IO_REG32_BIT(ETHER_MAFCR0,                0xE8203778,__READ_WRITE,__ether_mafcr_bits);
__IO_REG32_BIT(ETHER_APR0,                  0xE8203554,__READ_WRITE,__ether_apr_bits);
__IO_REG32_BIT(ETHER_MPR0,                  0xE8203558,__READ_WRITE,__ether_mpr_bits);
__IO_REG32_BIT(ETHER_TPAUSER0,              0xE8203564,__READ_WRITE,__ether_tpauser_bits);
__IO_REG32_BIT(ETHER_PFTCR0,                0xE820355C,__READ      ,__ether_pftcr_bits);
__IO_REG32_BIT(ETHER_PFRCR0,                0xE8203560,__READ      ,__ether_pfrcr_bits);
__IO_REG32_BIT(ETHER_TSU_CTRST,             0xE8204804,__READ_WRITE,__ether_tsu_ctrst_bits);
__IO_REG32_BIT(ETHER_TSU_VTAG0,             0xE8204858,__READ_WRITE,__ether_tsu_vtag0_bits);
__IO_REG32_BIT(ETHER_TSU_ADSBSY,            0xE8204860,__READ      ,__ether_tsu_adsbsy_bits);
__IO_REG32_BIT(ETHER_TSU_TEN,               0xE8204864,__READ_WRITE,__ether_tsu_ten_bits);
__IO_REG32(    ETHER_TSU_ADRH0,             0xE8204900,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH1,             0xE8204908,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH2,             0xE8204910,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH3,             0xE8204918,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH4,             0xE8204920,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH5,             0xE8204928,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH6,             0xE8204930,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH7,             0xE8204938,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH8,             0xE8204940,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH9,             0xE8204948,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH10,            0xE8204950,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH11,            0xE8204958,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH12,            0xE8204960,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH13,            0xE8204968,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH14,            0xE8204970,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH15,            0xE8204978,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH16,            0xE8204980,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH17,            0xE8204988,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH18,            0xE8204990,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH19,            0xE8204998,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH20,            0xE82049A0,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH21,            0xE82049A8,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH22,            0xE82049B0,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH23,            0xE82049B8,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH24,            0xE82049C0,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH25,            0xE82049C8,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH26,            0xE82049D0,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH27,            0xE82049D8,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH28,            0xE82049E0,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH29,            0xE82049E8,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH30,            0xE82049F0,__READ_WRITE);
__IO_REG32(    ETHER_TSU_ADRH31,            0xE82049F8,__READ_WRITE);
__IO_REG32_BIT(ETHER_TSU_ADRL0,             0xE8204904,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL1,             0xE820490C,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL2,             0xE8204914,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL3,             0xE820491C,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL4,             0xE8204924,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL5,             0xE820492C,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL6,             0xE8204934,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL7,             0xE820493C,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL8,             0xE8204944,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL9,             0xE820494C,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL10,            0xE8204954,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL11,            0xE820495C,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL12,            0xE8204964,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL13,            0xE820496C,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL14,            0xE8204974,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL15,            0xE820497C,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL16,            0xE8204984,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL17,            0xE820498C,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL18,            0xE8204994,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL19,            0xE820499C,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL20,            0xE82049A4,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL21,            0xE82049AC,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL22,            0xE82049B4,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL23,            0xE82049BC,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL24,            0xE82049C4,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL25,            0xE82049CC,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL26,            0xE82049D4,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL27,            0xE82049DC,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL28,            0xE82049E4,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL29,            0xE82049EC,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL30,            0xE82049F4,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32_BIT(ETHER_TSU_ADRL31,            0xE82049FC,__READ_WRITE,__ether_tsu_adrl_bits);
__IO_REG32(    ETHER_TXNLCR0,               0xE8204880,__READ      );
__IO_REG32(    ETHER_TXALCR0,               0xE8204884,__READ      );
__IO_REG32(    ETHER_RXNLCR0,               0xE8204888,__READ      );
__IO_REG32(    ETHER_RXALCR0,               0xE820488C,__READ      );
__IO_REG32(    ETHER_EDSR0,                 0xE8203000,__WRITE     );
__IO_REG32_BIT(ETHER_EDMR0,                 0xE8203400,__READ_WRITE,__ether_edmr_bits);
__IO_REG32_BIT(ETHER_EDTRR0,                0xE8203408,__READ_WRITE,__ether_edtrr_bits);
__IO_REG32_BIT(ETHER_EDRRR0,                0xE8203410,__READ_WRITE,__ether_edrrr_bits);
__IO_REG32_BIT(ETHER_EESR0,                 0xE8203428,__READ_WRITE,__ether_eesr_bits);
__IO_REG32_BIT(ETHER_EESIPR0,               0xE8203430,__READ_WRITE,__ether_eesipr_bits);
__IO_REG32(    ETHER_TDLAR0,                0xE8203010,__READ_WRITE);
__IO_REG32(    ETHER_TDFAR0,                0xE8203014,__READ_WRITE);
__IO_REG32(    ETHER_TDFXR0,                0xE8203018,__READ_WRITE);
__IO_REG32_BIT(ETHER_TDFFR0,                0xE820301C,__READ_WRITE,__ether_tdffr_bits);
__IO_REG32(    ETHER_RDLAR0,                0xE8203030,__READ_WRITE);
__IO_REG32(    ETHER_RDFAR0,                0xE8203034,__READ_WRITE);
__IO_REG32(    ETHER_RDFXR0,                0xE8203038,__READ_WRITE);
__IO_REG32_BIT(ETHER_RDFFR0,                0xE820303C,__READ_WRITE,__ether_rdffr_bits);
__IO_REG32_BIT(ETHER_TRSCER0,               0xE8203438,__READ_WRITE,__ether_trscer_bits);
__IO_REG32_BIT(ETHER_RMFCR0,                0xE8203440,__READ_WRITE,__ether_rmfcr_bits);
__IO_REG32_BIT(ETHER_TFTR0,                 0xE8203448,__READ_WRITE,__ether_tftr_bits);
__IO_REG32_BIT(ETHER_FDR0,                  0xE8203450,__READ_WRITE,__ether_fdr_bits);
__IO_REG32_BIT(ETHER_RMCR0,                 0xE8203458,__READ_WRITE,__ether_rmcr_bits);
__IO_REG32_BIT(ETHER_RPADIR0,               0xE8203460,__READ_WRITE,__ether_rpadir_bits);
__IO_REG32_BIT(ETHER_FCFTR0,                0xE8203468,__READ_WRITE,__ether_fcftr_bits);
__IO_REG32_BIT(ETHER_CSMR,                  0xE82034E4,__READ_WRITE,__ether_csmr_bits);
__IO_REG32_BIT(ETHER_CSSBM,                 0xE82034E8,__READ      ,__ether_cssbm_bits);
__IO_REG32_BIT(ETHER_CSSMR,                 0xE82034EC,__READ      ,__ether_cssmr_bits);

/***************************************************************************
 **
 **  ADC (A/D Converter)
 **
 ***************************************************************************/
__IO_REG16_BIT(ADC_ADDRA,                   0xE8005800,__READ      ,__adc_addr_bits);
__IO_REG16_BIT(ADC_ADDRB,                   0xE8005802,__READ      ,__adc_addr_bits);
__IO_REG16_BIT(ADC_ADDRC,                   0xE8005804,__READ      ,__adc_addr_bits);
__IO_REG16_BIT(ADC_ADDRD,                   0xE8005806,__READ      ,__adc_addr_bits);
__IO_REG16_BIT(ADC_ADDRE,                   0xE8005808,__READ      ,__adc_addr_bits);
__IO_REG16_BIT(ADC_ADDRF,                   0xE800580A,__READ      ,__adc_addr_bits);
__IO_REG16_BIT(ADC_ADDRG,                   0xE800580C,__READ      ,__adc_addr_bits);
__IO_REG16_BIT(ADC_ADDRH,                   0xE800580E,__READ      ,__adc_addr_bits);
__IO_REG16_BIT(ADC_ADCMPHA,                 0xE8005820,__READ_WRITE,__adc_adcmph_bits);
__IO_REG16_BIT(ADC_ADCMPLA,                 0xE8005822,__READ_WRITE,__adc_adcmpl_bits);
__IO_REG16_BIT(ADC_ADCMPHB,                 0xE8005824,__READ_WRITE,__adc_adcmph_bits);
__IO_REG16_BIT(ADC_ADCMPLB,                 0xE8005826,__READ_WRITE,__adc_adcmpl_bits);
__IO_REG16_BIT(ADC_ADCMPHC,                 0xE8005828,__READ_WRITE,__adc_adcmph_bits);
__IO_REG16_BIT(ADC_ADCMPLC,                 0xE800582A,__READ_WRITE,__adc_adcmpl_bits);
__IO_REG16_BIT(ADC_ADCMPHD,                 0xE800582C,__READ_WRITE,__adc_adcmph_bits);
__IO_REG16_BIT(ADC_ADCMPLD,                 0xE800582E,__READ_WRITE,__adc_adcmpl_bits);
__IO_REG16_BIT(ADC_ADCMPHE,                 0xE8005830,__READ_WRITE,__adc_adcmph_bits);
__IO_REG16_BIT(ADC_ADCMPLE,                 0xE8005832,__READ_WRITE,__adc_adcmpl_bits);
__IO_REG16_BIT(ADC_ADCMPHF,                 0xE8005834,__READ_WRITE,__adc_adcmph_bits);
__IO_REG16_BIT(ADC_ADCMPLF,                 0xE8005836,__READ_WRITE,__adc_adcmpl_bits);
__IO_REG16_BIT(ADC_ADCMPHG,                 0xE8005838,__READ_WRITE,__adc_adcmph_bits);
__IO_REG16_BIT(ADC_ADCMPLG,                 0xE800583A,__READ_WRITE,__adc_adcmpl_bits);
__IO_REG16_BIT(ADC_ADCMPHH,                 0xE800583C,__READ_WRITE,__adc_adcmph_bits);
__IO_REG16_BIT(ADC_ADCMPLH,                 0xE800583E,__READ_WRITE,__adc_adcmpl_bits);
__IO_REG16_BIT(ADC_ADCSR,                   0xE8005860,__READ_WRITE,__adc_adcsr_bits);
__IO_REG16_BIT(ADC_ADCMPER,                 0xE8005862,__READ_WRITE,__adc_adcmper_bits);
__IO_REG16_BIT(ADC_ADCMPSR,                 0xE8005864,__READ_WRITE,__adc_adcmpsr_bits);

/***************************************************************************
 **
 **  FLCTL (NAND Flash Memory Controller)
 **
 ***************************************************************************/
__IO_REG32_BIT(FLCTL_FLCMNCR,               0xFCFF4000,__READ_WRITE,__flctl_flcmncr_bits);
__IO_REG32_BIT(FLCTL_MLCMDCR,               0xFCFF4004,__READ_WRITE,__flctl_flcmdcr_bits);
__IO_REG32_BIT(FLCTL_FLCMCDR,               0xFCFF4008,__READ_WRITE,__flctl_flcmcdr_bits);
__IO_REG32_BIT(FLCTL_FLADR,                 0xFCFF400C,__READ_WRITE,__flctl_fladr_bits);
__IO_REG32_BIT(FLCTL_FLADR2,                0xFCFF403C,__READ_WRITE,__flctl_fladr2_bits);
__IO_REG32_BIT(FLCTL_FLDATAR,               0xFCFF4010,__READ_WRITE,__flctl_fldatar_bits);
__IO_REG32_BIT(FLCTL_FLDTCNTR,              0xFCFF4014,__READ_WRITE,__flctl_fldtcntr_bits);
__IO_REG32_BIT(FLCTL_FLINTDMACR,            0xFCFF4018,__READ_WRITE,__flctl_flintdmacr_bits);
__IO_REG32_BIT(FLCTL_FLBSYTMR,              0xFCFF401C,__READ_WRITE,__flctl_flbsytmr_bits);
__IO_REG32_BIT(FLCTL_FLBSYCNT,              0xFCFF4020,__READ_WRITE,__flctl_flbsycnt_bits);
__IO_REG32(    FLCTL_FLDTFIFO,              0xFCFF4050,__READ_WRITE);
__IO_REG32(    FLCTL_FLECFIFO,              0xFCFF4060,__READ_WRITE);
__IO_REG8_BIT( FLCTL_FLTRCR,                0xFCFF402C,__READ_WRITE,__flctl_fltrcr_bits);

/***************************************************************************
 **
 **  USB ch.0 (USB2.0 Host/Function Module channel 0)
 **
 ***************************************************************************/
__IO_REG16_BIT(USB_SYSCFG0_0,               0xE8010000,__READ_WRITE,__usb_syscfg0_bits);
__IO_REG16_BIT(USB_BUSWAIT_0,               0xE8010002,__READ_WRITE,__usb_buswait_bits);
__IO_REG16_BIT(USB_SYSSTS0_0,               0xE8010004,__READ      ,__usb_syssts0_bits);
__IO_REG16_BIT(USB_DVSTCTR0_0,              0xE8010008,__READ_WRITE,__usb_dvstctr0_bits);
__IO_REG16_BIT(USB_TESTMODE_0,              0xE801000C,__READ_WRITE,__usb_testmode_bits);
__IO_REG16_BIT(USB_D0FBCFG_0,               0xE8010010,__READ_WRITE,__usb_dxfbcfg_bits);
__IO_REG16_BIT(USB_D1FBCFG_0,               0xE8010012,__READ_WRITE,__usb_dxfbcfg_bits);
__IO_REG32_BIT(USB_CFIFO_0,                 0xE8010014,__READ_WRITE,__usb_cfifo_d0fifo_d1fifo_bits);
#define USB_CFIFO_0_H            USB_CFIFO_0_bit.__halfword0
#define USB_CFIFO_0_B            USB_CFIFO_0_bit.__byte0
__IO_REG32_BIT(USB_D0FIFO_0,                0xE8010018,__READ_WRITE,__usb_cfifo_d0fifo_d1fifo_bits);
#define USB_D0FIFO_0_H           USB_D0FIFO_0_bit.__halfword0
#define USB_D0FIFO_0_B           USB_D0FIFO_0_bit.__byte0
__IO_REG32_BIT(USB_D1FIFO_0,                0xE801001C,__READ_WRITE,__usb_cfifo_d0fifo_d1fifo_bits);
#define USB_D1FIFO_0_H           USB_D1FIFO_0_bit.__halfword0
#define USB_D1FIFO_0_B           USB_D1FIFO_0_bit.__byte0
__IO_REG16_BIT(USB_CFIFOSEL_0,              0xE8010020,__READ_WRITE,__usb_cfifosel_bits);
__IO_REG16_BIT(USB_CFIFOCTR_0,              0xE8010022,__READ_WRITE,__usb_xfifoctr_bits);
__IO_REG16_BIT(USB_D0FIFOSEL_0,             0xE8010028,__READ_WRITE,__usb_dxfifosel_bits);
__IO_REG16_BIT(USB_D0FIFOCTR_0,             0xE801002A,__READ_WRITE,__usb_xfifoctr_bits);
__IO_REG16_BIT(USB_D1FIFOSEL_0,             0xE801002C,__READ_WRITE,__usb_dxfifosel_bits);
__IO_REG16_BIT(USB_D1FIFOCTR_0,             0xE801002E,__READ_WRITE,__usb_xfifoctr_bits);
__IO_REG16_BIT(USB_INTENB0_0,               0xE8010030,__READ_WRITE,__usb_intenb0_bits);
__IO_REG16_BIT(USB_INTENB1_0,               0xE8010032,__READ_WRITE,__usb_intenb1_bits);
__IO_REG16(    USB_BRDYENB_0,               0xE8010036,__READ_WRITE);
__IO_REG16(    USB_NRDYENB_0,               0xE8010038,__READ_WRITE);
__IO_REG16(    USB_BEMPENB_0,               0xE801003A,__READ_WRITE);
__IO_REG16_BIT(USB_SOFCFG_0,                0xE801003C,__READ_WRITE,__usb_sofcfg_bits);
__IO_REG16_BIT(USB_INTSTS0_0,               0xE8010040,__READ_WRITE,__usb_intsts0_bits);
__IO_REG16_BIT(USB_INTSTS1_0,               0xE8010042,__READ_WRITE,__usb_intsts1_bits);
__IO_REG16_BIT(USB_BRDYSTS_0,               0xE8010046,__READ_WRITE,__usb_brdysts_bits);
__IO_REG16_BIT(USB_NRDYSTS_0,               0xE8010048,__READ_WRITE,__usb_nrdysts_bits);
__IO_REG16_BIT(USB_BEMPSTS_0,               0xE801004A,__READ_WRITE,__usb_bempsts_bits);
__IO_REG16_BIT(USB_FRMNUM_0,                0xE801004C,__READ_WRITE,__usb_frmnum_bits);
__IO_REG16_BIT(USB_UFRMNUM_0,               0xE801004E,__READ      ,__usb_ufrmnum_bits);
__IO_REG16_BIT(USB_USBADDR_0,               0xE8010050,__READ      ,__usb_usbaddr_bits);
__IO_REG16_BIT(USB_USBREQ_0,                0xE8010054,__READ_WRITE,__usb_usbreq_bits);
__IO_REG16(    USB_USBVAL_0,                0xE8010056,__READ_WRITE);
__IO_REG16(    USB_USBINDX_0,               0xE8010058,__READ_WRITE);
__IO_REG16(    USB_USBLENG_0,               0xE801005A,__READ_WRITE);
__IO_REG16_BIT(USB_DCPCFG_0,                0xE801005C,__READ_WRITE,__usb_dcpcfg_bits);
__IO_REG16_BIT(USB_DCPMAXP_0,               0xE801005E,__READ_WRITE,__usb_dcpmaxp_bits);
__IO_REG16_BIT(USB_DCPCTR_0,                0xE8010060,__READ_WRITE,__usb_dcpctr_bits);
__IO_REG16_BIT(USB_PIPESEL_0,               0xE8010064,__READ_WRITE,__usb_pipesel_bits);
__IO_REG16_BIT(USB_PIPECFG_0,               0xE8010068,__READ_WRITE,__usb_pipecfg_bits);
__IO_REG16_BIT(USB_PIPEBUF_0,               0xE801006A,__READ_WRITE,__usb_pipebuf_bits);
__IO_REG16_BIT(USB_PIPEMAXP_0,              0xE801006C,__READ_WRITE,__usb_pipemaxp_bits);
__IO_REG16_BIT(USB_PIPEPERI_0,              0xE801006E,__READ_WRITE,__usb_pipeperi_bits);
__IO_REG16_BIT(USB_PIPE1CTR_0,              0xE8010070,__READ_WRITE,__usb_pipe15_9ctr_bits);
__IO_REG16_BIT(USB_PIPE2CTR_0,              0xE8010072,__READ_WRITE,__usb_pipe15_9ctr_bits);
__IO_REG16_BIT(USB_PIPE3CTR_0,              0xE8010074,__READ_WRITE,__usb_pipe15_9ctr_bits);
__IO_REG16_BIT(USB_PIPE4CTR_0,              0xE8010076,__READ_WRITE,__usb_pipe15_9ctr_bits);
__IO_REG16_BIT(USB_PIPE5CTR_0,              0xE8010078,__READ_WRITE,__usb_pipe15_9ctr_bits);
__IO_REG16_BIT(USB_PIPE6CTR_0,              0xE801007A,__READ_WRITE,__usb_pipe68ctr_bits);
__IO_REG16_BIT(USB_PIPE7CTR_0,              0xE801007C,__READ_WRITE,__usb_pipe68ctr_bits);
__IO_REG16_BIT(USB_PIPE8CTR_0,              0xE801007E,__READ_WRITE,__usb_pipe68ctr_bits);
__IO_REG16_BIT(USB_PIPE9CTR_0,              0xE8010080,__READ_WRITE,__usb_pipe15_9ctr_bits);
__IO_REG16_BIT(USB_PIPEACTR_0,              0xE8010082,__READ_WRITE,__usb_pipeAFctr_bits);
__IO_REG16_BIT(USB_PIPEBCTR_0,              0xE8010084,__READ_WRITE,__usb_pipeAFctr_bits);
__IO_REG16_BIT(USB_PIPECCTR_0,              0xE8010086,__READ_WRITE,__usb_pipeAFctr_bits);
__IO_REG16_BIT(USB_PIPEDCTR_0,              0xE8010088,__READ_WRITE,__usb_pipeAFctr_bits);
__IO_REG16_BIT(USB_PIPEECTR_0,              0xE801008A,__READ_WRITE,__usb_pipeAFctr_bits);
__IO_REG16_BIT(USB_PIPEFCTR_0,              0xE801008C,__READ_WRITE,__usb_pipeAFctr_bits);
__IO_REG16_BIT(USB_PIPE1TRE_0,              0xE8010090,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPE1TRN_0,              0xE8010092,__READ_WRITE);
__IO_REG16_BIT(USB_PIPE2TRE_0,              0xE8010094,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPE2TRN_0,              0xE8010096,__READ_WRITE);
__IO_REG16_BIT(USB_PIPE3TRE_0,              0xE8010098,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPE3TRN_0,              0xE801009A,__READ_WRITE);
__IO_REG16_BIT(USB_PIPE4TRE_0,              0xE801009C,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPE4TRN_0,              0xE801009E,__READ_WRITE);
__IO_REG16_BIT(USB_PIPE5TRE_0,              0xE80100A0,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPE5TRN_0,              0xE80100A2,__READ_WRITE);
__IO_REG16_BIT(USB_PIPEBTRE_0,              0xE80100A4,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPEBTRN_0,              0xE80100A6,__READ_WRITE);
__IO_REG16_BIT(USB_PIPECTRE_0,              0xE80100A8,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPECTRN_0,              0xE80100AA,__READ_WRITE);
__IO_REG16_BIT(USB_PIPEDTRE_0,              0xE80100AC,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPEDTRN_0,              0xE80100AE,__READ_WRITE);
__IO_REG16_BIT(USB_PIPEETRE_0,              0xE80100B0,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPEETRN_0,              0xE80100B2,__READ_WRITE);
__IO_REG16_BIT(USB_PIPEFTRE_0,              0xE80100B4,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPEFTRN_0,              0xE80100B6,__READ_WRITE);
__IO_REG16_BIT(USB_PIPE9TRE_0,              0xE80100B8,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPE9TRN_0,              0xE80100BA,__READ_WRITE);
__IO_REG16_BIT(USB_PIPEATRE_0,              0xE80100BC,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPEATRN_0,              0xE80100BE,__READ_WRITE);
__IO_REG16_BIT(USB_DEVADD0_0,               0xE80100D0,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD1_0,               0xE80100D2,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD2_0,               0xE80100D4,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD3_0,               0xE80100D6,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD4_0,               0xE80100D8,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD5_0,               0xE80100DA,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD6_0,               0xE80100DC,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD7_0,               0xE80100DE,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD8_0,               0xE80100E0,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD9_0,               0xE80100E2,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADDA_0,               0xE80100E4,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_SUSPMODE_0,              0xE8010102,__READ_WRITE,__usb_suspmode_bits);

/***************************************************************************
 **
 **  USB ch.1 (USB2.0 Host/Function Module channel 1)
 **
 ***************************************************************************/
__IO_REG16_BIT(USB_SYSCFG0_1,               0xE8207000,__READ_WRITE,__usb_syscfg0_bits);
__IO_REG16_BIT(USB_BUSWAIT_1,               0xE8207002,__READ_WRITE,__usb_buswait_bits);
__IO_REG16_BIT(USB_SYSSTS0_1,               0xE8207004,__READ      ,__usb_syssts0_bits);
__IO_REG16_BIT(USB_DVSTCTR0_1,              0xE8207008,__READ_WRITE,__usb_dvstctr0_bits);
__IO_REG16_BIT(USB_TESTMODE_1,              0xE820700C,__READ_WRITE,__usb_testmode_bits);
__IO_REG16_BIT(USB_D0FBCFG_1,               0xE8207010,__READ_WRITE,__usb_dxfbcfg_bits);
__IO_REG16_BIT(USB_D1FBCFG_1,               0xE8207012,__READ_WRITE,__usb_dxfbcfg_bits);
__IO_REG32_BIT(USB_CFIFO_1,                 0xE8207014,__READ_WRITE,__usb_cfifo_d0fifo_d1fifo_bits);
#define USB_CFIFO_1_H            USB_CFIFO_1_bit.__halfword0
#define USB_CFIFO_1_B            USB_CFIFO_1_bit.__byte0
__IO_REG32_BIT(USB_D0FIFO_1,                0xE8207018,__READ_WRITE,__usb_cfifo_d0fifo_d1fifo_bits);
#define USB_D0FIFO_1_H           USB_D0FIFO_1_bit.__halfword0
#define USB_D0FIFO_1_B           USB_D0FIFO_1_bit.__byte0
__IO_REG32_BIT(USB_D1FIFO_1,                0xE820701C,__READ_WRITE,__usb_cfifo_d0fifo_d1fifo_bits);
#define USB_D1FIFO_1_H           USB_D1FIFO_1_bit.__halfword0
#define USB_D1FIFO_1_B           USB_D1FIFO_1_bit.__byte0
__IO_REG16_BIT(USB_CFIFOSEL_1,              0xE8207020,__READ_WRITE,__usb_cfifosel_bits);
__IO_REG16_BIT(USB_CFIFOCTR_1,              0xE8207022,__READ_WRITE,__usb_xfifoctr_bits);
__IO_REG16_BIT(USB_D0FIFOSEL_1,             0xE8207028,__READ_WRITE,__usb_dxfifosel_bits);
__IO_REG16_BIT(USB_D0FIFOCTR_1,             0xE820702A,__READ_WRITE,__usb_xfifoctr_bits);
__IO_REG16_BIT(USB_D1FIFOSEL_1,             0xE820702C,__READ_WRITE,__usb_dxfifosel_bits);
__IO_REG16_BIT(USB_D1FIFOCTR_1,             0xE820702E,__READ_WRITE,__usb_xfifoctr_bits);
__IO_REG16_BIT(USB_INTENB0_1,               0xE8207030,__READ_WRITE,__usb_intenb0_bits);
__IO_REG16_BIT(USB_INTENB1_1,               0xE8207032,__READ_WRITE,__usb_intenb1_bits);
__IO_REG16(    USB_BRDYENB_1,               0xE8207036,__READ_WRITE);
__IO_REG16(    USB_NRDYENB_1,               0xE8207038,__READ_WRITE);
__IO_REG16(    USB_BEMPENB_1,               0xE820703A,__READ_WRITE);
__IO_REG16_BIT(USB_SOFCFG_1,                0xE820703C,__READ_WRITE,__usb_sofcfg_bits);
__IO_REG16_BIT(USB_INTSTS0_1,               0xE8207040,__READ_WRITE,__usb_intsts0_bits);
__IO_REG16_BIT(USB_INTSTS1_1,               0xE8207042,__READ_WRITE,__usb_intsts1_bits);
__IO_REG16_BIT(USB_BRDYSTS_1,               0xE8207046,__READ_WRITE,__usb_brdysts_bits);
__IO_REG16_BIT(USB_NRDYSTS_1,               0xE8207048,__READ_WRITE,__usb_nrdysts_bits);
__IO_REG16_BIT(USB_BEMPSTS_1,               0xE820704A,__READ_WRITE,__usb_bempsts_bits);
__IO_REG16_BIT(USB_FRMNUM_1,                0xE820704C,__READ_WRITE,__usb_frmnum_bits);
__IO_REG16_BIT(USB_UFRMNUM_1,               0xE820704E,__READ      ,__usb_ufrmnum_bits);
__IO_REG16_BIT(USB_USBADDR_1,               0xE8207050,__READ      ,__usb_usbaddr_bits);
__IO_REG16_BIT(USB_USBREQ_1,                0xE8207054,__READ_WRITE,__usb_usbreq_bits);
__IO_REG16(    USB_USBVAL_1,                0xE8207056,__READ_WRITE);
__IO_REG16(    USB_USBINDX_1,               0xE8207058,__READ_WRITE);
__IO_REG16(    USB_USBLENG_1,               0xE820705A,__READ_WRITE);
__IO_REG16_BIT(USB_DCPCFG_1,                0xE820705C,__READ_WRITE,__usb_dcpcfg_bits);
__IO_REG16_BIT(USB_DCPMAXP_1,               0xE820705E,__READ_WRITE,__usb_dcpmaxp_bits);
__IO_REG16_BIT(USB_DCPCTR_1,                0xE8207060,__READ_WRITE,__usb_dcpctr_bits);
__IO_REG16_BIT(USB_PIPESEL_1,               0xE8207064,__READ_WRITE,__usb_pipesel_bits);
__IO_REG16_BIT(USB_PIPECFG_1,               0xE8207068,__READ_WRITE,__usb_pipecfg_bits);
__IO_REG16_BIT(USB_PIPEBUF_1,               0xE820706A,__READ_WRITE,__usb_pipebuf_bits);
__IO_REG16_BIT(USB_PIPEMAXP_1,              0xE820706C,__READ_WRITE,__usb_pipemaxp_bits);
__IO_REG16_BIT(USB_PIPEPERI_1,              0xE820706E,__READ_WRITE,__usb_pipeperi_bits);
__IO_REG16_BIT(USB_PIPE1CTR_1,              0xE8207070,__READ_WRITE,__usb_pipe15_9ctr_bits);
__IO_REG16_BIT(USB_PIPE2CTR_1,              0xE8207072,__READ_WRITE,__usb_pipe15_9ctr_bits);
__IO_REG16_BIT(USB_PIPE3CTR_1,              0xE8207074,__READ_WRITE,__usb_pipe15_9ctr_bits);
__IO_REG16_BIT(USB_PIPE4CTR_1,              0xE8207076,__READ_WRITE,__usb_pipe15_9ctr_bits);
__IO_REG16_BIT(USB_PIPE5CTR_1,              0xE8207078,__READ_WRITE,__usb_pipe15_9ctr_bits);
__IO_REG16_BIT(USB_PIPE6CTR_1,              0xE820707A,__READ_WRITE,__usb_pipe68ctr_bits);
__IO_REG16_BIT(USB_PIPE7CTR_1,              0xE820707C,__READ_WRITE,__usb_pipe68ctr_bits);
__IO_REG16_BIT(USB_PIPE8CTR_1,              0xE820707E,__READ_WRITE,__usb_pipe68ctr_bits);
__IO_REG16_BIT(USB_PIPE9CTR_1,              0xE8207080,__READ_WRITE,__usb_pipe15_9ctr_bits);
__IO_REG16_BIT(USB_PIPEACTR_1,              0xE8207082,__READ_WRITE,__usb_pipeAFctr_bits);
__IO_REG16_BIT(USB_PIPEBCTR_1,              0xE8207084,__READ_WRITE,__usb_pipeAFctr_bits);
__IO_REG16_BIT(USB_PIPECCTR_1,              0xE8207086,__READ_WRITE,__usb_pipeAFctr_bits);
__IO_REG16_BIT(USB_PIPEDCTR_1,              0xE8207088,__READ_WRITE,__usb_pipeAFctr_bits);
__IO_REG16_BIT(USB_PIPEECTR_1,              0xE820708A,__READ_WRITE,__usb_pipeAFctr_bits);
__IO_REG16_BIT(USB_PIPEFCTR_1,              0xE820708C,__READ_WRITE,__usb_pipeAFctr_bits);
__IO_REG16_BIT(USB_PIPE1TRE_1,              0xE8207090,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPE1TRN_1,              0xE8207092,__READ_WRITE);
__IO_REG16_BIT(USB_PIPE2TRE_1,              0xE8207094,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPE2TRN_1,              0xE8207096,__READ_WRITE);
__IO_REG16_BIT(USB_PIPE3TRE_1,              0xE8207098,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPE3TRN_1,              0xE820709A,__READ_WRITE);
__IO_REG16_BIT(USB_PIPE4TRE_1,              0xE820709C,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPE4TRN_1,              0xE820709E,__READ_WRITE);
__IO_REG16_BIT(USB_PIPE5TRE_1,              0xE82070A0,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPE5TRN_1,              0xE82070A2,__READ_WRITE);
__IO_REG16_BIT(USB_PIPEBTRE_1,              0xE82070A4,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPEBTRN_1,              0xE82070A6,__READ_WRITE);
__IO_REG16_BIT(USB_PIPECTRE_1,              0xE82070A8,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPECTRN_1,              0xE82070AA,__READ_WRITE);
__IO_REG16_BIT(USB_PIPEDTRE_1,              0xE82070AC,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPEDTRN_1,              0xE82070AE,__READ_WRITE);
__IO_REG16_BIT(USB_PIPEETRE_1,              0xE82070B0,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPEETRN_1,              0xE82070B2,__READ_WRITE);
__IO_REG16_BIT(USB_PIPEFTRE_1,              0xE82070B4,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPEFTRN_1,              0xE82070B6,__READ_WRITE);
__IO_REG16_BIT(USB_PIPE9TRE_1,              0xE82070B8,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPE9TRN_1,              0xE82070BA,__READ_WRITE);
__IO_REG16_BIT(USB_PIPEATRE_1,              0xE82070BC,__READ_WRITE,__usb_pipe15_9_AFtre_bits);
__IO_REG16(    USB_PIPEATRN_1,              0xE82070BE,__READ_WRITE);
__IO_REG16_BIT(USB_DEVADD0_1,               0xE82070D0,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD1_1,               0xE82070D2,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD2_1,               0xE82070D4,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD3_1,               0xE82070D6,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD4_1,               0xE82070D8,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD5_1,               0xE82070DA,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD6_1,               0xE82070DC,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD7_1,               0xE82070DE,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD8_1,               0xE82070E0,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADD9_1,               0xE82070E2,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_DEVADDA_1,               0xE82070E4,__READ_WRITE,__usb_devadd09_A_bits);
__IO_REG16_BIT(USB_SUSPMODE_1,              0xE8207102,__READ_WRITE,__usb_suspmode_bits);

/***************************************************************************
 **
 **  DVDEC ch.0 (Digital Video Decoder channel 0)
 **
 ***************************************************************************/
__IO_REG16_BIT(DVDEC_ADCCR1_0,              0xFCFFB808,__READ_WRITE,__dvdec_adccr1_bits);
__IO_REG16_BIT(DVDEC_TGCR1_0,               0xFCFFB80E,__READ_WRITE,__dvdec_tgcr1_bits);
__IO_REG16_BIT(DVDEC_TGCR2_0,               0xFCFFB810,__READ_WRITE,__dvdec_tgcr2_bits);
__IO_REG16_BIT(DVDEC_TGCR3_0,               0xFCFFB812,__READ_WRITE,__dvdec_tgcr1_bits);
__IO_REG16_BIT(DVDEC_SYNSCR1_0,             0xFCFFB81A,__READ_WRITE,__dvdec_synscr1_bits);
__IO_REG16_BIT(DVDEC_SYNSCR2_0,             0xFCFFB81C,__READ_WRITE,__dvdec_synscr2_bits);
__IO_REG16_BIT(DVDEC_SYNSCR3_0,             0xFCFFB81E,__READ_WRITE,__dvdec_synscr3_bits);
__IO_REG16_BIT(DVDEC_SYNSCR4_0,             0xFCFFB820,__READ_WRITE,__dvdec_synscr4_bits);
__IO_REG16_BIT(DVDEC_SYNSCR5_0,             0xFCFFB822,__READ_WRITE,__dvdec_synscr5_bits);
__IO_REG16_BIT(DVDEC_HAFCCR1_0,             0xFCFFB824,__READ_WRITE,__dvdec_hafccr1_bits);
__IO_REG16_BIT(DVDEC_HAFCCR2_0,             0xFCFFB826,__READ_WRITE,__dvdec_hafccr2_bits);
__IO_REG16_BIT(DVDEC_HAFCCR3_0,             0xFCFFB828,__READ_WRITE,__dvdec_hafccr3_bits);
__IO_REG16_BIT(DVDEC_VCDWCR1_0,             0xFCFFB82A,__READ_WRITE,__dvdec_vcdwcr1_bits);
__IO_REG16_BIT(DVDEC_DCPCR1_0,              0xFCFFB830,__READ_WRITE,__dvdec_dcpcr1_bits);
__IO_REG16_BIT(DVDEC_DCPCR2_0,              0xFCFFB832,__READ_WRITE,__dvdec_dcpcr2_bits);
__IO_REG16_BIT(DVDEC_DCPCR3_0,              0xFCFFB834,__READ_WRITE,__dvdec_dcpcr3_bits);
__IO_REG16_BIT(DVDEC_DCPCR4_0,              0xFCFFB836,__READ_WRITE,__dvdec_dcpcr4_bits);
__IO_REG16_BIT(DVDEC_DCPCR5_0,              0xFCFFB838,__READ_WRITE,__dvdec_dcpcr5_bits);
__IO_REG16_BIT(DVDEC_DCPCR6_0,              0xFCFFB83A,__READ_WRITE,__dvdec_dcpcr6_bits);
__IO_REG16_BIT(DVDEC_DCPCR7_0,              0xFCFFB83C,__READ_WRITE,__dvdec_dcpcr7_bits);
__IO_REG16_BIT(DVDEC_DCPCR8_0,              0xFCFFB83E,__READ_WRITE,__dvdec_dcpcr8_bits);
__IO_REG16_BIT(DVDEC_NSDCR_0,               0xFCFFB840,__READ_WRITE,__dvdec_nsdcr_bits);
__IO_REG16_BIT(DVDEC_BTLCR_0,               0xFCFFB842,__READ_WRITE,__dvdec_btlcr_bits);
__IO_REG16_BIT(DVDEC_BTGPCR_0,              0xFCFFB844,__READ_WRITE,__dvdec_btgpcr_bits);
__IO_REG16_BIT(DVDEC_ACCCR1_0,              0xFCFFB846,__READ_WRITE,__dvdec_acccr1_bits);
__IO_REG16_BIT(DVDEC_ACCCR2_0,              0xFCFFB848,__READ_WRITE,__dvdec_acccr2_bits);
__IO_REG16_BIT(DVDEC_ACCCR3_0,              0xFCFFB84A,__READ_WRITE,__dvdec_acccr3_bits);
__IO_REG16_BIT(DVDEC_TINTCR_0,              0xFCFFB84C,__READ_WRITE,__dvdec_tintcr_bits);
__IO_REG16_BIT(DVDEC_YCDCR_0,               0xFCFFB84E,__READ_WRITE,__dvdec_ycdcr_bits);
__IO_REG16_BIT(DVDEC_AGCCR1_0,              0xFCFFB850,__READ_WRITE,__dvdec_agccr1_bits);
__IO_REG16_BIT(DVDEC_AGCCR2_0,              0xFCFFB852,__READ_WRITE,__dvdec_agccr2_bits);
__IO_REG16_BIT(DVDEC_PKLIMITCR_0,           0xFCFFB854,__READ_WRITE,__dvdec_pklimitcr_bits);
__IO_REG16_BIT(DVDEC_RGORCR1_0,             0xFCFFB856,__READ_WRITE,__dvdec_rgorcr1_bits);
__IO_REG16_BIT(DVDEC_RGORCR2_0,             0xFCFFB858,__READ_WRITE,__dvdec_rgorcr2_bits);
__IO_REG16_BIT(DVDEC_RGORCR3_0,             0xFCFFB85A,__READ_WRITE,__dvdec_rgorcr3_bits);
__IO_REG16_BIT(DVDEC_RGORCR4_0,             0xFCFFB85C,__READ_WRITE,__dvdec_rgorcr4_bits);
__IO_REG16_BIT(DVDEC_RGORCR5_0,             0xFCFFB85E,__READ_WRITE,__dvdec_rgorcr5_bits);
__IO_REG16_BIT(DVDEC_RGORCR6_0,             0xFCFFB860,__READ_WRITE,__dvdec_rgorcr6_bits);
__IO_REG16_BIT(DVDEC_RGORCR7_0,             0xFCFFB862,__READ_WRITE,__dvdec_rgorcr7_bits);
__IO_REG16_BIT(DVDEC_AFCPFCR_0,             0xFCFFB87C,__READ_WRITE,__dvdec_afcpfcr_bits);
__IO_REG16_BIT(DVDEC_RUPDCR_0,              0xFCFFB87E,__READ_WRITE,__dvdec_rupdcr_bits);
__IO_REG16_BIT(DVDEC_VSYNCSR_0,             0xFCFFB880,__READ      ,__dvdec_vsyncsr_bits);
__IO_REG16(    DVDEC_HSYNCSR_0,             0xFCFFB882,__READ      );
__IO_REG16_BIT(DVDEC_DCPSR1_0,              0xFCFFB884,__READ      ,__dvdec_dcpsr1_bits);
__IO_REG16_BIT(DVDEC_DCPSR2_0,              0xFCFFB886,__READ      ,__dvdec_dcpsr2_bits);
__IO_REG16(    DVDEC_NSDSR_0,               0xFCFFB88C,__READ      );
__IO_REG16_BIT(DVDEC_CROMASR1_0,            0xFCFFB88E,__READ      ,__dvdec_cromasr1_bits);
__IO_REG16_BIT(DVDEC_CROMASR2_0,            0xFCFFB890,__READ      ,__dvdec_cromasr2_bits);
__IO_REG16_BIT(DVDEC_SYNCSSR_0,             0xFCFFB892,__READ      ,__dvdec_syncssr_bits);
__IO_REG16_BIT(DVDEC_AGCCSR1_0,             0xFCFFB894,__READ      ,__dvdec_agccsr1_bits);
__IO_REG16_BIT(DVDEC_AGCCSR2_0,             0xFCFFB896,__READ      ,__dvdec_agccsr2_bits);
__IO_REG16_BIT(DVDEC_YCSCR3_0,              0xFCFFB904,__READ_WRITE,__dvdec_ycscr3_bits);
__IO_REG16_BIT(DVDEC_YCSCR4_0,              0xFCFFB906,__READ_WRITE,__dvdec_ycscr4_bits);
__IO_REG16_BIT(DVDEC_YCSCR5_0,              0xFCFFB908,__READ_WRITE,__dvdec_ycscr5_bits);
__IO_REG16_BIT(DVDEC_YCSCR6_0,              0xFCFFB90A,__READ_WRITE,__dvdec_ycscr6_bits);
__IO_REG16_BIT(DVDEC_YCSCR7_0,              0xFCFFB90C,__READ_WRITE,__dvdec_ycscr7_bits);
__IO_REG16_BIT(DVDEC_YCSCR8_0,              0xFCFFB90E,__READ_WRITE,__dvdec_ycscr8_bits);
__IO_REG16_BIT(DVDEC_YCSCR9_0,              0xFCFFB910,__READ_WRITE,__dvdec_ycscr9_bits);
__IO_REG16_BIT(DVDEC_YCSCR11_0,             0xFCFFB914,__READ_WRITE,__dvdec_ycscr11_bits);
__IO_REG16_BIT(DVDEC_YCSCR12_0,             0xFCFFB916,__READ_WRITE,__dvdec_ycscr12_bits);
__IO_REG16_BIT(DVDEC_DCPCR9_0,              0xFCFFB980,__READ_WRITE,__dvdec_dcpcr9_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F0_0,            0xFCFFB992,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F1_0,            0xFCFFB994,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F2_0,            0xFCFFB996,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F3_0,            0xFCFFB998,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F4_0,            0xFCFFB99A,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F5_0,            0xFCFFB99c,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F6_0,            0xFCFFB99E,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F7_0,            0xFCFFB9A0,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F8_0,            0xFCFFB9A2,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F0_0,            0xFCFFB9A4,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F1_0,            0xFCFFB9A6,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F2_0,            0xFCFFB9A8,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F3_0,            0xFCFFB9AA,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F4_0,            0xFCFFB9AC,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F5_0,            0xFCFFB9AE,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F6_0,            0xFCFFB9B0,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F7_0,            0xFCFFB9B2,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F8_0,            0xFCFFB9B4,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F0_0,            0xFCFFB9B6,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F1_0,            0xFCFFB9B8,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F2_0,            0xFCFFB9BA,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F3_0,            0xFCFFB9BC,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F4_0,            0xFCFFB9BE,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F5_0,            0xFCFFB9C0,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F6_0,            0xFCFFB9C2,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F7_0,            0xFCFFB9C4,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F8_0,            0xFCFFB9C6,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F0_0,            0xFCFFB9C8,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F1_0,            0xFCFFB9CA,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F2_0,            0xFCFFB9CC,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F3_0,            0xFCFFB9CE,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F4_0,            0xFCFFB9D0,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F5_0,            0xFCFFB9D2,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F6_0,            0xFCFFB9D4,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F7_0,            0xFCFFB9D6,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F8_0,            0xFCFFB9D8,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YGAINCR_0,             0xFCFFBA00,__READ_WRITE,__dvdec_ygaincr_bits);
__IO_REG16_BIT(DVDEC_CBGAINCR_0,            0xFCFFBA02,__READ_WRITE,__dvdec_cbgaincr_bits);
__IO_REG16_BIT(DVDEC_CRGAINCR_0,            0xFCFFBA04,__READ_WRITE,__dvdec_crgaincr_bits);
__IO_REG16_BIT(DVDEC_PGA_UPDATE_0,          0xFCFFBA80,__READ_WRITE,__dvdec_pga_update_bits);
__IO_REG16_BIT(DVDEC_PGACR_0,               0xFCFFBA82,__READ_WRITE,__dvdec_pgacr_bits);
__IO_REG16_BIT(DVDEC_ADCCR2_0,              0xFCFFBA84,__READ_WRITE,__dvdec_adccr2_bits);

/***************************************************************************
 **
 **  DVD ch.1 (Digital Video Decoder channel 1)
 **
 ***************************************************************************/
__IO_REG16_BIT(DVDEC_ADCCR1_1,              0xFCFFA008,__READ_WRITE,__dvdec_adccr1_bits);
__IO_REG16_BIT(DVDEC_TGCR1_1,               0xFCFFA00E,__READ_WRITE,__dvdec_tgcr1_bits);
__IO_REG16_BIT(DVDEC_TGCR2_1,               0xFCFFA010,__READ_WRITE,__dvdec_tgcr2_bits);
__IO_REG16_BIT(DVDEC_TGCR3_1,               0xFCFFA012,__READ_WRITE,__dvdec_tgcr1_bits);
__IO_REG16_BIT(DVDEC_SYNSCR1_1,             0xFCFFA01A,__READ_WRITE,__dvdec_synscr1_bits);
__IO_REG16_BIT(DVDEC_SYNSCR2_1,             0xFCFFA01C,__READ_WRITE,__dvdec_synscr2_bits);
__IO_REG16_BIT(DVDEC_SYNSCR3_1,             0xFCFFA01E,__READ_WRITE,__dvdec_synscr3_bits);
__IO_REG16_BIT(DVDEC_SYNSCR4_1,             0xFCFFA020,__READ_WRITE,__dvdec_synscr4_bits);
__IO_REG16_BIT(DVDEC_SYNSCR5_1,             0xFCFFA022,__READ_WRITE,__dvdec_synscr5_bits);
__IO_REG16_BIT(DVDEC_HAFCCR1_1,             0xFCFFA024,__READ_WRITE,__dvdec_hafccr1_bits);
__IO_REG16_BIT(DVDEC_HAFCCR2_1,             0xFCFFA026,__READ_WRITE,__dvdec_hafccr2_bits);
__IO_REG16_BIT(DVDEC_HAFCCR3_1,             0xFCFFA028,__READ_WRITE,__dvdec_hafccr3_bits);
__IO_REG16_BIT(DVDEC_VCDWCR1_1,             0xFCFFA02A,__READ_WRITE,__dvdec_vcdwcr1_bits);
__IO_REG16_BIT(DVDEC_DCPCR1_1,              0xFCFFA030,__READ_WRITE,__dvdec_dcpcr1_bits);
__IO_REG16_BIT(DVDEC_DCPCR2_1,              0xFCFFA032,__READ_WRITE,__dvdec_dcpcr2_bits);
__IO_REG16_BIT(DVDEC_DCPCR3_1,              0xFCFFA034,__READ_WRITE,__dvdec_dcpcr3_bits);
__IO_REG16_BIT(DVDEC_DCPCR4_1,              0xFCFFA036,__READ_WRITE,__dvdec_dcpcr4_bits);
__IO_REG16_BIT(DVDEC_DCPCR5_1,              0xFCFFA038,__READ_WRITE,__dvdec_dcpcr5_bits);
__IO_REG16_BIT(DVDEC_DCPCR6_1,              0xFCFFA03A,__READ_WRITE,__dvdec_dcpcr6_bits);
__IO_REG16_BIT(DVDEC_DCPCR7_1,              0xFCFFA03C,__READ_WRITE,__dvdec_dcpcr7_bits);
__IO_REG16_BIT(DVDEC_DCPCR8_1,              0xFCFFA03E,__READ_WRITE,__dvdec_dcpcr8_bits);
__IO_REG16_BIT(DVDEC_NSDCR_1,               0xFCFFA040,__READ_WRITE,__dvdec_nsdcr_bits);
__IO_REG16_BIT(DVDEC_BTLCR_1,               0xFCFFA042,__READ_WRITE,__dvdec_btlcr_bits);
__IO_REG16_BIT(DVDEC_BTGPCR_1,              0xFCFFA044,__READ_WRITE,__dvdec_btgpcr_bits);
__IO_REG16_BIT(DVDEC_ACCCR1_1,              0xFCFFA046,__READ_WRITE,__dvdec_acccr1_bits);
__IO_REG16_BIT(DVDEC_ACCCR2_1,              0xFCFFA048,__READ_WRITE,__dvdec_acccr2_bits);
__IO_REG16_BIT(DVDEC_ACCCR3_1,              0xFCFFA04A,__READ_WRITE,__dvdec_acccr3_bits);
__IO_REG16_BIT(DVDEC_TINTCR_1,              0xFCFFA04C,__READ_WRITE,__dvdec_tintcr_bits);
__IO_REG16_BIT(DVDEC_YCDCR_1,               0xFCFFA04E,__READ_WRITE,__dvdec_ycdcr_bits);
__IO_REG16_BIT(DVDEC_AGCCR1_1,              0xFCFFA050,__READ_WRITE,__dvdec_agccr1_bits);
__IO_REG16_BIT(DVDEC_AGCCR2_1,              0xFCFFA052,__READ_WRITE,__dvdec_agccr2_bits);
__IO_REG16_BIT(DVDEC_PKLIMITCR_1,           0xFCFFA054,__READ_WRITE,__dvdec_pklimitcr_bits);
__IO_REG16_BIT(DVDEC_RGORCR1_1,             0xFCFFA056,__READ_WRITE,__dvdec_rgorcr1_bits);
__IO_REG16_BIT(DVDEC_RGORCR2_1,             0xFCFFA058,__READ_WRITE,__dvdec_rgorcr2_bits);
__IO_REG16_BIT(DVDEC_RGORCR3_1,             0xFCFFA05A,__READ_WRITE,__dvdec_rgorcr3_bits);
__IO_REG16_BIT(DVDEC_RGORCR4_1,             0xFCFFA05C,__READ_WRITE,__dvdec_rgorcr4_bits);
__IO_REG16_BIT(DVDEC_RGORCR5_1,             0xFCFFA05E,__READ_WRITE,__dvdec_rgorcr5_bits);
__IO_REG16_BIT(DVDEC_RGORCR6_1,             0xFCFFA060,__READ_WRITE,__dvdec_rgorcr6_bits);
__IO_REG16_BIT(DVDEC_RGORCR7_1,             0xFCFFA062,__READ_WRITE,__dvdec_rgorcr7_bits);
__IO_REG16_BIT(DVDEC_AFCPFCR_1,             0xFCFFA07C,__READ_WRITE,__dvdec_afcpfcr_bits);
__IO_REG16_BIT(DVDEC_RUPDCR_1,              0xFCFFA07E,__READ_WRITE,__dvdec_rupdcr_bits);
__IO_REG16_BIT(DVDEC_VSYNCSR_1,             0xFCFFA080,__READ      ,__dvdec_vsyncsr_bits);
__IO_REG16(    DVDEC_HSYNCSR_1,             0xFCFFA082,__READ      );
__IO_REG16_BIT(DVDEC_DCPSR1_1,              0xFCFFA084,__READ      ,__dvdec_dcpsr1_bits);
__IO_REG16_BIT(DVDEC_DCPSR2_1,              0xFCFFA086,__READ      ,__dvdec_dcpsr2_bits);
__IO_REG16(    DVDEC_NSDSR_1,               0xFCFFA08C,__READ      );
__IO_REG16_BIT(DVDEC_CROMASR1_1,            0xFCFFA08E,__READ      ,__dvdec_cromasr1_bits);
__IO_REG16_BIT(DVDEC_CROMASR2_1,            0xFCFFA090,__READ      ,__dvdec_cromasr2_bits);
__IO_REG16_BIT(DVDEC_SYNCSSR_1,             0xFCFFA092,__READ      ,__dvdec_syncssr_bits);
__IO_REG16_BIT(DVDEC_AGCCSR1_1,             0xFCFFA094,__READ      ,__dvdec_agccsr1_bits);
__IO_REG16_BIT(DVDEC_AGCCSR2_1,             0xFCFFA096,__READ      ,__dvdec_agccsr2_bits);
__IO_REG16_BIT(DVDEC_YCSCR3_1,              0xFCFFA104,__READ_WRITE,__dvdec_ycscr3_bits);
__IO_REG16_BIT(DVDEC_YCSCR4_1,              0xFCFFA106,__READ_WRITE,__dvdec_ycscr4_bits);
__IO_REG16_BIT(DVDEC_YCSCR5_1,              0xFCFFA108,__READ_WRITE,__dvdec_ycscr5_bits);
__IO_REG16_BIT(DVDEC_YCSCR6_1,              0xFCFFA10A,__READ_WRITE,__dvdec_ycscr6_bits);
__IO_REG16_BIT(DVDEC_YCSCR7_1,              0xFCFFA10C,__READ_WRITE,__dvdec_ycscr7_bits);
__IO_REG16_BIT(DVDEC_YCSCR8_1,              0xFCFFA10E,__READ_WRITE,__dvdec_ycscr8_bits);
__IO_REG16_BIT(DVDEC_YCSCR9_1,              0xFCFFA110,__READ_WRITE,__dvdec_ycscr9_bits);
__IO_REG16_BIT(DVDEC_YCSCR11_1,             0xFCFFA114,__READ_WRITE,__dvdec_ycscr11_bits);
__IO_REG16_BIT(DVDEC_YCSCR12_1,             0xFCFFA116,__READ_WRITE,__dvdec_ycscr12_bits);
__IO_REG16_BIT(DVDEC_DCPCR9_1,              0xFCFFA180,__READ_WRITE,__dvdec_dcpcr9_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F0_1,            0xFCFFA192,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F1_1,            0xFCFFA194,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F2_1,            0xFCFFA196,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F3_1,            0xFCFFA198,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F4_1,            0xFCFFA19A,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F5_1,            0xFCFFA19c,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F6_1,            0xFCFFA19E,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F7_1,            0xFCFFA1A0,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWA_F8_1,            0xFCFFA1A2,__READ_WRITE,__dvdec_yctwa_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F0_1,            0xFCFFA1A4,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F1_1,            0xFCFFA1A6,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F2_1,            0xFCFFA1A8,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F3_1,            0xFCFFA1AA,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F4_1,            0xFCFFA1AC,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F5_1,            0xFCFFA1AE,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F6_1,            0xFCFFA1B0,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F7_1,            0xFCFFA1B2,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTWB_F8_1,            0xFCFFA1B4,__READ_WRITE,__dvdec_yctwb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F0_1,            0xFCFFA1B6,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F1_1,            0xFCFFA1B8,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F2_1,            0xFCFFA1BA,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F3_1,            0xFCFFA1BC,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F4_1,            0xFCFFA1BE,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F5_1,            0xFCFFA1C0,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F6_1,            0xFCFFA1C2,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F7_1,            0xFCFFA1C4,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNA_F8_1,            0xFCFFA1C6,__READ_WRITE,__dvdec_yctna_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F0_1,            0xFCFFA1C8,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F1_1,            0xFCFFA1CA,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F2_1,            0xFCFFA1CC,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F3_1,            0xFCFFA1CE,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F4_1,            0xFCFFA1D0,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F5_1,            0xFCFFA1D2,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F6_1,            0xFCFFA1D4,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F7_1,            0xFCFFA1D6,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YCTNB_F8_1,            0xFCFFA1D8,__READ_WRITE,__dvdec_yctnb_fx_bits);
__IO_REG16_BIT(DVDEC_YGAINCR_1,             0xFCFFA200,__READ_WRITE,__dvdec_ygaincr_bits);
__IO_REG16_BIT(DVDEC_CBGAINCR_1,            0xFCFFA202,__READ_WRITE,__dvdec_cbgaincr_bits);
__IO_REG16_BIT(DVDEC_CRGAINCR_1,            0xFCFFA204,__READ_WRITE,__dvdec_crgaincr_bits);
__IO_REG16_BIT(DVDEC_PGA_UPDATE_1,          0xFCFFA280,__READ_WRITE,__dvdec_pga_update_bits);
__IO_REG16_BIT(DVDEC_PGACR_1,               0xFCFFA282,__READ_WRITE,__dvdec_pgacr_bits);
__IO_REG16_BIT(DVDEC_ADCCR2_1,              0xFCFFA284,__READ_WRITE,__dvdec_adccr2_bits);

/***************************************************************************
 **
 **  VDC INP (Video Display Controller 5 Input Controller)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_INP_UPDATE,              0xFCFF7400,__READ_WRITE,__vdc_inp_update_bits);
__IO_REG32_BIT(VDC_INP_SEL_CNT,             0xFCFF7404,__READ_WRITE,__vdc_inp_sel_cnt_bits);
__IO_REG32_BIT(VDC_INP_EXT_SYNC_CNT,        0xFCFF7408,__READ_WRITE,__vdc_inp_ext_sync_cnt_bits);
__IO_REG32_BIT(VDC_INP_VSYNC_PH_ADJ,        0xFCFF740C,__READ_WRITE,__vdc_inp_vsync_ph_adj_bits);
__IO_REG32_BIT(VDC_INP_DLY_ADJ,             0xFCFF7410,__READ_WRITE,__vdc_inp_dly_adj_bits);
__IO_REG32_BIT(VDC_IMGCNT_UPDATE,           0xFCFF7480,__READ_WRITE,__vdc_imgcnt_update_bits);
__IO_REG32_BIT(VDC_IMGCNT_NR_CNT0,          0xFCFF7484,__READ_WRITE,__vdc_imgcnt_nr_cnt0_bits);
__IO_REG32_BIT(VDC_IMGCNT_NR_CNT1,          0xFCFF7488,__READ_WRITE,__vdc_imgcnt_nr_cnt1_bits);
__IO_REG32_BIT(VDC_IMGCNT_MTX_MODE,         0xFCFF74A0,__READ_WRITE,__vdc_imgcnt_mtx_mode_bits);
__IO_REG32_BIT(VDC_IMGCNT_MTX_YG_ADJ0,      0xFCFF74A4,__READ_WRITE,__vdc_imgcnt_mtx_yg_adj_bits);
__IO_REG32_BIT(VDC_IMGCNT_MTX_YG_ADJ1,      0xFCFF74A8,__READ_WRITE,__vdc_imgcnt_mtx_yg_adj1_bits);
__IO_REG32_BIT(VDC_IMGCNT_MTX_CBB_ADJ0,     0xFCFF74AC,__READ_WRITE,__vdc_imgcnt_mtx_cbb_adj_bits);
__IO_REG32_BIT(VDC_IMGCNT_MTX_CBB_ADJ1,     0xFCFF74B0,__READ_WRITE,__vdc_imgcnt_mtx_cbb_adj1_bits);
__IO_REG32_BIT(VDC_IMGCNT_MTX_CRR_ADJ0,     0xFCFF74B4,__READ_WRITE,__vdc_imgcnt_mtx_crr_adj_bits);
__IO_REG32_BIT(VDC_IMGCNT_MTX_CRR_ADJ1,     0xFCFF74B8,__READ_WRITE,__vdc_imgcnt_mtx_crr_adj1_bits);
__IO_REG32_BIT(VDC_IMGCNT_DRC_REG,     			0xFCFF74C0,__READ_WRITE,__vdc_imgcnt_drc_reg_bits);

/***************************************************************************
 **
 **  VDC SC0 CH0 (Video Display Controller 5 Scaler0 channel 0)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_SC0_SCL0_UPDATE_0,         0xFCFF7500,__READ_WRITE,__vdc_sc_scl_update_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_FRC1_0,         	0xFCFF7504,__READ_WRITE,__vdc_sc_scl_frc1_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_FRC2_0,		        0xFCFF7508,__READ_WRITE,__vdc_sc_scl_frc2_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_FRC3_0,		        0xFCFF750C,__READ_WRITE,__vdc_sc_scl_frc3_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_FRC4_0,		        0xFCFF7510,__READ_WRITE,__vdc_sc_scl_frc4_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_FRC5_0,		        0xFCFF7514,__READ_WRITE,__vdc_sc_scl_frc5_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_FRC6_0,		        0xFCFF7518,__READ_WRITE,__vdc_sc_scl_frc6_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_FRC7_0,		        0xFCFF751C,__READ_WRITE,__vdc_sc_scl_frc7_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_FRC9_0,		        0xFCFF7524,__READ			 ,__vdc_sc_scl_frc9_bits);
__IO_REG16_BIT(VDC_SC0_SCL0_MON0_0,         	0xFCFF7528,__READ			 ,__vdc_sc_scl_mon0_bits);
__IO_REG16_BIT(VDC_SC0_SCL0_INT_0,         		0xFCFF752A,__READ_WRITE,__vdc_sc_scl_int_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_DS1_0,         		0xFCFF752C,__READ_WRITE,__vdc_sc_scl_ds1_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_DS2_0,         		0xFCFF7530,__READ_WRITE,__vdc_sc_scl_ds2_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_DS3_0,         		0xFCFF7534,__READ_WRITE,__vdc_sc_scl_ds3_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_DS4_0,         		0xFCFF7538,__READ_WRITE,__vdc_sc_scl_ds4_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_DS5_0,         		0xFCFF753C,__READ_WRITE,__vdc_sc_scl_ds5_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_DS6_0,         		0xFCFF7540,__READ_WRITE,__vdc_sc_scl_ds6_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_DS7_0,         		0xFCFF7544,__READ_WRITE,__vdc_sc_scl_ds7_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_US1_0,         		0xFCFF7548,__READ_WRITE,__vdc_sc_scl_us1_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_US2_0,         		0xFCFF754C,__READ_WRITE,__vdc_sc_scl_us2_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_US3_0,         		0xFCFF7550,__READ_WRITE,__vdc_sc_scl_us3_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_US4_0,         		0xFCFF7554,__READ_WRITE,__vdc_sc_scl_us4_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_US5_0,         		0xFCFF7558,__READ_WRITE,__vdc_sc_scl_us5_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_US6_0,         		0xFCFF755C,__READ_WRITE,__vdc_sc_scl_us6_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_US7_0,         		0xFCFF7560,__READ_WRITE,__vdc_sc_scl_us7_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_US8_0,         		0xFCFF7564,__READ_WRITE,__vdc_sc_scl_us8_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_OVR1_0,         	0xFCFF756C,__READ_WRITE,__vdc_sc_scl_ovr1_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_UPDATE_0,         0xFCFF7580,__READ_WRITE,__vdc_sc_scl1_update_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_WR1_0,         		0xFCFF7588,__READ_WRITE,__vdc_sc_scl_wr1_bits);
__IO_REG32(		 VDC_SC0_SCL1_WR2_0,         		0xFCFF758C,__READ_WRITE);
__IO_REG32_BIT(VDC_SC0_SCL1_WR3_0,         		0xFCFF7590,__READ_WRITE,__vdc_sc_scl_wr3_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_WR4_0,         		0xFCFF7594,__READ_WRITE,__vdc_sc_scl_wr4_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_WR5_0,         		0xFCFF759C,__READ_WRITE,__vdc_sc_scl_wr5_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_WR6_0,         		0xFCFF75A0,__READ_WRITE,__vdc_sc_scl_wr6_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_WR7_0,         		0xFCFF75A4,__READ			 ,__vdc_sc_scl_wr7_bits);
__IO_REG32(		 VDC_SC0_SCL1_WR8_0,         		0xFCFF75A8,__READ_WRITE);
__IO_REG32_BIT(VDC_SC0_SCL1_WR9_0,         		0xFCFF75AC,__READ_WRITE,__vdc_sc_scl_wr9_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_WR10_0,        		0xFCFF75B0,__READ_WRITE,__vdc_sc_scl_wr10_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_WR11_0,        		0xFCFF75B4,__READ			 ,__vdc_sc_scl_wr11_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_MON1_0,        		0xFCFF75B8,__READ			 ,__vdc_sc_scl_mon1_bits);
__IO_REG32(		 VDC_SC0_SCL1_PBUF0_0,        	0xFCFF75BC,__READ			 );
__IO_REG32(		 VDC_SC0_SCL1_PBUF1_0,       		0xFCFF75C0,__READ			 );
__IO_REG32(		 VDC_SC0_SCL1_PBUF2_0,       		0xFCFF75C4,__READ			 );
__IO_REG32(		 VDC_SC0_SCL1_PBUF3_0,        	0xFCFF75C8,__READ			 );
__IO_REG32_BIT(VDC_SC0_SCL1_PBUF_FLD_0,       0xFCFF75CC,__READ			 ,__vdc_sc_scl_pbuf_fld_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_PBUF_CNT_0,       0xFCFF75D0,__READ_WRITE,__vdc_sc_scl_pbuf_cnt_bits);
__IO_REG32_BIT(VDC_GR0_UPDATE_0,         			0xFCFF7600,__READ_WRITE,__vdc_gr_update_bits);
__IO_REG32_BIT(VDC_GR0_FLM_RD_0,         			0xFCFF7604,__READ_WRITE,__vdc_gr_flm_rd_bits);
__IO_REG32_BIT(VDC_GR0_FLM1_0,         				0xFCFF7608,__READ_WRITE,__vdc_gr_flm1_bits);
__IO_REG32(		 VDC_GR0_FLM2_0,         				0xFCFF760C,__READ_WRITE);
__IO_REG32_BIT(VDC_GR0_FLM3_0,         				0xFCFF7610,__READ_WRITE,__vdc_gr_flm3_bits);
__IO_REG32_BIT(VDC_GR0_FLM4_0,         				0xFCFF7614,__READ_WRITE,__vdc_gr_flm4_bits);
__IO_REG32_BIT(VDC_GR0_FLM5_0,         				0xFCFF7618,__READ_WRITE,__vdc_gr_flm5_bits);
__IO_REG32_BIT(VDC_GR0_FLM6_0,         				0xFCFF761C,__READ_WRITE,__vdc_gr_flm6_bits);
__IO_REG32_BIT(VDC_GR0_AB1_0,         				0xFCFF7620,__READ_WRITE,__vdc_gr_ab1_bits);
__IO_REG32_BIT(VDC_GR0_AB2_0,         				0xFCFF7624,__READ_WRITE,__vdc_gr_ab2_bits);
__IO_REG32_BIT(VDC_GR0_AB3_0,         				0xFCFF7628,__READ_WRITE,__vdc_gr_ab3_bits);
__IO_REG32_BIT(VDC_GR0_AB7_0,         				0xFCFF7638,__READ_WRITE,__vdc_gr_ab7_bits);
__IO_REG32_BIT(VDC_GR0_AB8_0,         				0xFCFF763C,__READ_WRITE,__vdc_gr_ab8_bits);
__IO_REG32_BIT(VDC_GR0_AB9_0,         				0xFCFF7640,__READ_WRITE,__vdc_gr_ab9_bits);
__IO_REG32_BIT(VDC_GR0_AB10_0,         				0xFCFF7644,__READ_WRITE,__vdc_gr_ab10_bits);
__IO_REG32_BIT(VDC_GR0_AB11_0,         				0xFCFF7648,__READ_WRITE,__vdc_gr_ab11_bits);
__IO_REG32_BIT(VDC_GR0_BASE_0,         				0xFCFF764C,__READ_WRITE,__vdc_gr_base_bits);
__IO_REG32_BIT(VDC_GR0_CLUT_0,         				0xFCFF7650,__READ_WRITE,__vdc_gr_clut_bits);

/***************************************************************************
 **
 **  VDC SC1 (Video Display Controller 5 Scaler1 Ch0)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_SC1_SCL0_UPDATE_0,         0xFCFF7C00,__READ_WRITE,__vdc_sc_scl_update_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_FRC1_0,         	0xFCFF7C04,__READ_WRITE,__vdc_sc_scl_frc1_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_FRC2_0,		        0xFCFF7C08,__READ_WRITE,__vdc_sc_scl_frc2_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_FRC3_0,		        0xFCFF7C0C,__READ_WRITE,__vdc_sc_scl_frc3_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_FRC4_0,		        0xFCFF7C10,__READ_WRITE,__vdc_sc_scl_frc4_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_FRC5_0,		        0xFCFF7C14,__READ_WRITE,__vdc_sc_scl_frc5_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_FRC6_0,		        0xFCFF7C18,__READ_WRITE,__vdc_sc_scl_frc6_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_FRC7_0,		        0xFCFF7C1C,__READ_WRITE,__vdc_sc_scl_frc7_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_FRC9_0,		        0xFCFF7C24,__READ			 ,__vdc_sc_scl_frc9_bits);
__IO_REG16_BIT(VDC_SC1_SCL0_MON0_0,         	0xFCFF7C28,__READ			 ,__vdc_sc_scl_mon0_bits);
__IO_REG16_BIT(VDC_SC1_SCL0_INT_0,         		0xFCFF7C2A,__READ_WRITE,__vdc_sc_scl_int_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_DS1_0,         		0xFCFF7C2C,__READ_WRITE,__vdc_sc_scl_ds1_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_DS2_0,         		0xFCFF7C30,__READ_WRITE,__vdc_sc_scl_ds2_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_DS3_0,         		0xFCFF7C34,__READ_WRITE,__vdc_sc_scl_ds3_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_DS4_0,         		0xFCFF7C38,__READ_WRITE,__vdc_sc_scl_ds4_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_DS5_0,         		0xFCFF7C3C,__READ_WRITE,__vdc_sc_scl_ds5_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_DS6_0,         		0xFCFF7C40,__READ_WRITE,__vdc_sc_scl_ds6_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_DS7_0,         		0xFCFF7C44,__READ_WRITE,__vdc_sc_scl_ds7_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_US1_0,         		0xFCFF7C48,__READ_WRITE,__vdc_sc_scl_us1_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_US2_0,         		0xFCFF7C4C,__READ_WRITE,__vdc_sc_scl_us2_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_US3_0,         		0xFCFF7C50,__READ_WRITE,__vdc_sc_scl_us3_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_US4_0,         		0xFCFF7C54,__READ_WRITE,__vdc_sc_scl_us4_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_US5_0,         		0xFCFF7C58,__READ_WRITE,__vdc_sc_scl_us5_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_US6_0,         		0xFCFF7C5C,__READ_WRITE,__vdc_sc_scl_us6_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_US7_0,         		0xFCFF7C60,__READ_WRITE,__vdc_sc_scl_us7_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_US8_0,         		0xFCFF7C64,__READ_WRITE,__vdc_sc_scl_us8_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_OVR1_0,         	0xFCFF7C6C,__READ_WRITE,__vdc_sc_scl_ovr1_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_UPDATE_0,         0xFCFF7C80,__READ_WRITE,__vdc_sc_scl1_update_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_WR1_0,         		0xFCFF7C88,__READ_WRITE,__vdc_sc_scl_wr1_bits);
__IO_REG32(		 VDC_SC1_SCL1_WR2_0,         		0xFCFF7C8C,__READ_WRITE);
__IO_REG32_BIT(VDC_SC1_SCL1_WR3_0,         		0xFCFF7C90,__READ_WRITE,__vdc_sc_scl_wr3_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_WR4_0,         		0xFCFF7C94,__READ_WRITE,__vdc_sc_scl_wr4_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_WR5_0,         		0xFCFF7C9C,__READ_WRITE,__vdc_sc_scl_wr5_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_WR6_0,         		0xFCFF7CA0,__READ_WRITE,__vdc_sc_scl_wr6_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_WR7_0,         		0xFCFF7CA4,__READ			 ,__vdc_sc_scl_wr7_bits);
__IO_REG32(		 VDC_SC1_SCL1_WR8_0,         		0xFCFF7CA8,__READ_WRITE);
__IO_REG32_BIT(VDC_SC1_SCL1_WR9_0,         		0xFCFF7CAC,__READ_WRITE,__vdc_sc_scl_wr9_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_WR10_0,        		0xFCFF7CB0,__READ_WRITE,__vdc_sc_scl_wr10_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_WR11_0,        		0xFCFF7CB4,__READ			 ,__vdc_sc_scl_wr11_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_MON1_0,        		0xFCFF7CB8,__READ			 ,__vdc_sc_scl_mon1_bits);
__IO_REG32(		 VDC_SC1_SCL1_PBUF0_0,        	0xFCFF7CBC,__READ			 );
__IO_REG32(		 VDC_SC1_SCL1_PBUF1_0,       		0xFCFF7CC0,__READ			 );
__IO_REG32(		 VDC_SC1_SCL1_PBUF2_0,       		0xFCFF7CC4,__READ			 );
__IO_REG32(		 VDC_SC1_SCL1_PBUF3_0,        	0xFCFF7CC8,__READ			 );
__IO_REG32_BIT(VDC_SC1_SCL1_PBUF_FLD_0,       0xFCFF7CCC,__READ			 ,__vdc_sc_scl_pbuf_fld_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_PBUF_CNT_0,       0xFCFF7CD0,__READ_WRITE,__vdc_sc_scl_pbuf_cnt_bits);
__IO_REG32_BIT(VDC_GR1_UPDATE_0,         			0xFCFF7D00,__READ_WRITE,__vdc_gr_update_bits);
__IO_REG32_BIT(VDC_GR1_FLM_RD_0,         			0xFCFF7D04,__READ_WRITE,__vdc_gr_flm_rd_bits);
__IO_REG32_BIT(VDC_GR1_FLM_0,         				0xFCFF7D08,__READ_WRITE,__vdc_gr1_flm1_bits);
__IO_REG32(		 VDC_GR1_FLM2_0,         				0xFCFF7D0C,__READ_WRITE);
__IO_REG32_BIT(VDC_GR1_FLM3_0,         				0xFCFF7D10,__READ_WRITE,__vdc_gr_flm3_bits);
__IO_REG32_BIT(VDC_GR1_FLM4_0,         				0xFCFF7D14,__READ_WRITE,__vdc_gr_flm4_bits);
__IO_REG32_BIT(VDC_GR1_FLM5_0,         				0xFCFF7D18,__READ_WRITE,__vdc_gr_flm5_bits);
__IO_REG32_BIT(VDC_GR1_FLM6_0,         				0xFCFF7D1C,__READ_WRITE,__vdc_gr_flm6_bits);
__IO_REG32_BIT(VDC_GR1_AB1_0,         				0xFCFF7D20,__READ_WRITE,__vdc_gr1_ab1_bits);
__IO_REG32_BIT(VDC_GR1_AB2_0,         				0xFCFF7D24,__READ_WRITE,__vdc_gr_ab2_bits);
__IO_REG32_BIT(VDC_GR1_AB3_0,         				0xFCFF7D28,__READ_WRITE,__vdc_gr_ab3_bits);
__IO_REG32_BIT(VDC_GR1_AB4_0,         				0xFCFF7D2C,__READ_WRITE,__vdc_gr1_ab4_bits);
__IO_REG32_BIT(VDC_GR1_AB5_0,         				0xFCFF7D30,__READ_WRITE,__vdc_gr1_ab5_bits);
__IO_REG32_BIT(VDC_GR1_AB6_0,         				0xFCFF7D34,__READ_WRITE,__vdc_gr1_ab6_bits);
__IO_REG32_BIT(VDC_GR1_AB7_0,         				0xFCFF7D38,__READ_WRITE,__vdc_gr1_ab7_bits);
__IO_REG32_BIT(VDC_GR1_AB8_0,         				0xFCFF7D3C,__READ_WRITE,__vdc_gr_ab8_bits);
__IO_REG32_BIT(VDC_GR1_AB9_0,         				0xFCFF7D40,__READ_WRITE,__vdc_gr_ab9_bits);
__IO_REG32_BIT(VDC_GR1_AB10_0,         				0xFCFF7D44,__READ_WRITE,__vdc_gr_ab10_bits);
__IO_REG32_BIT(VDC_GR1_AB11_0,         				0xFCFF7D48,__READ_WRITE,__vdc_gr_ab11_bits);
__IO_REG32_BIT(VDC_GR1_BASE_0,         				0xFCFF7D4C,__READ_WRITE,__vdc_gr_base_bits);
__IO_REG32_BIT(VDC_GR1_CLUT_0,         				0xFCFF7D50,__READ_WRITE,__vdc_gr_clut_bits);
__IO_REG32_BIT(VDC_GR1_MON_0,         				0xFCFF7D54,__READ_WRITE,__vdc_gr1_mon_bits);

/***************************************************************************
 **
 **  VDC SC0 CH1 (Video Display Controller 5 Scaler0 channel 1)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_SC0_SCL0_UPDATE_1,         0xFCFF9500,__READ_WRITE,__vdc_sc_scl_update_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_FRC1_1,         	0xFCFF9504,__READ_WRITE,__vdc_sc_scl_frc1_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_FRC2_1,		        0xFCFF9508,__READ_WRITE,__vdc_sc_scl_frc2_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_FRC3_1,		        0xFCFF950C,__READ_WRITE,__vdc_sc_scl_frc3_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_FRC4_1,		        0xFCFF9510,__READ_WRITE,__vdc_sc_scl_frc4_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_FRC5_1,		        0xFCFF9514,__READ_WRITE,__vdc_sc_scl_frc5_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_FRC6_1,		        0xFCFF9518,__READ_WRITE,__vdc_sc_scl_frc6_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_FRC7_1,		        0xFCFF951C,__READ_WRITE,__vdc_sc_scl_frc7_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_FRC9_1,		        0xFCFF9524,__READ			 ,__vdc_sc_scl_frc9_bits);
__IO_REG16_BIT(VDC_SC0_SCL0_MON0_1,         	0xFCFF9528,__READ			 ,__vdc_sc_scl_mon0_bits);
__IO_REG16_BIT(VDC_SC0_SCL0_INT_1,         		0xFCFF952A,__READ_WRITE,__vdc_sc_scl_int_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_DS1_1,         		0xFCFF952C,__READ_WRITE,__vdc_sc_scl_ds1_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_DS2_1,         		0xFCFF9530,__READ_WRITE,__vdc_sc_scl_ds2_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_DS3_1,         		0xFCFF9534,__READ_WRITE,__vdc_sc_scl_ds3_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_DS4_1,         		0xFCFF9538,__READ_WRITE,__vdc_sc_scl_ds4_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_DS5_1,         		0xFCFF953C,__READ_WRITE,__vdc_sc_scl_ds5_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_DS6_1,         		0xFCFF9540,__READ_WRITE,__vdc_sc_scl_ds6_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_DS7_1,         		0xFCFF9544,__READ_WRITE,__vdc_sc_scl_ds7_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_US1_1,         		0xFCFF9548,__READ_WRITE,__vdc_sc_scl_us1_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_US2_1,         		0xFCFF954C,__READ_WRITE,__vdc_sc_scl_us2_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_US3_1,         		0xFCFF9550,__READ_WRITE,__vdc_sc_scl_us3_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_US4_1,         		0xFCFF9554,__READ_WRITE,__vdc_sc_scl_us4_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_US5_1,         		0xFCFF9558,__READ_WRITE,__vdc_sc_scl_us5_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_US6_1,         		0xFCFF955C,__READ_WRITE,__vdc_sc_scl_us6_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_US7_1,         		0xFCFF9560,__READ_WRITE,__vdc_sc_scl_us7_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_US8_1,         		0xFCFF9564,__READ_WRITE,__vdc_sc_scl_us8_bits);
__IO_REG32_BIT(VDC_SC0_SCL0_OVR1_1,         	0xFCFF956C,__READ_WRITE,__vdc_sc_scl_ovr1_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_UPDATE_1,         0xFCFF9580,__READ_WRITE,__vdc_sc_scl1_update_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_WR1_1,         		0xFCFF9588,__READ_WRITE,__vdc_sc_scl_wr1_bits);
__IO_REG32(		 VDC_SC0_SCL1_WR2_1,         		0xFCFF958C,__READ_WRITE);
__IO_REG32_BIT(VDC_SC0_SCL1_WR3_1,         		0xFCFF9590,__READ_WRITE,__vdc_sc_scl_wr3_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_WR4_1,         		0xFCFF9594,__READ_WRITE,__vdc_sc_scl_wr4_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_WR5_1,         		0xFCFF959C,__READ_WRITE,__vdc_sc_scl_wr5_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_WR6_1,         		0xFCFF95A0,__READ_WRITE,__vdc_sc_scl_wr6_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_WR7_1,         		0xFCFF95A4,__READ			 ,__vdc_sc_scl_wr7_bits);
__IO_REG32(		 VDC_SC0_SCL1_WR8_1,         		0xFCFF95A8,__READ_WRITE);
__IO_REG32_BIT(VDC_SC0_SCL1_WR9_1,         		0xFCFF95AC,__READ_WRITE,__vdc_sc_scl_wr9_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_WR10_1,        		0xFCFF95B0,__READ_WRITE,__vdc_sc_scl_wr10_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_WR11_1,        		0xFCFF95B4,__READ			 ,__vdc_sc_scl_wr11_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_MON1_1,        		0xFCFF95B8,__READ			 ,__vdc_sc_scl_mon1_bits);
__IO_REG32(		 VDC_SC0_SCL1_PBUF0_1,        	0xFCFF95BC,__READ			 );
__IO_REG32(		 VDC_SC0_SCL1_PBUF1_1,       		0xFCFF95C0,__READ			 );
__IO_REG32(		 VDC_SC0_SCL1_PBUF2_1,       		0xFCFF95C4,__READ			 );
__IO_REG32(		 VDC_SC0_SCL1_PBUF3_1,        	0xFCFF95C8,__READ			 );
__IO_REG32_BIT(VDC_SC0_SCL1_PBUF_FLD_1,       0xFCFF95CC,__READ			 ,__vdc_sc_scl_pbuf_fld_bits);
__IO_REG32_BIT(VDC_SC0_SCL1_PBUF_CNT_1,       0xFCFF95D0,__READ_WRITE,__vdc_sc_scl_pbuf_cnt_bits);
__IO_REG32_BIT(VDC_GR0_UPDATE_1,         			0xFCFF9600,__READ_WRITE,__vdc_gr_update_bits);
__IO_REG32_BIT(VDC_GR0_FLM_RD_1,         			0xFCFF9604,__READ_WRITE,__vdc_gr_flm_rd_bits);
__IO_REG32_BIT(VDC_GR0_FLM1_1,         				0xFCFF9608,__READ_WRITE,__vdc_gr_flm1_bits);
__IO_REG32(		 VDC_GR0_FLM2_1,         				0xFCFF960C,__READ_WRITE);
__IO_REG32_BIT(VDC_GR0_FLM3_1,         				0xFCFF9610,__READ_WRITE,__vdc_gr_flm3_bits);
__IO_REG32_BIT(VDC_GR0_FLM4_1,         				0xFCFF9614,__READ_WRITE,__vdc_gr_flm4_bits);
__IO_REG32_BIT(VDC_GR0_FLM5_1,         				0xFCFF9618,__READ_WRITE,__vdc_gr_flm5_bits);
__IO_REG32_BIT(VDC_GR0_FLM6_1,         				0xFCFF961C,__READ_WRITE,__vdc_gr_flm6_bits);
__IO_REG32_BIT(VDC_GR0_AB1_1,         				0xFCFF9620,__READ_WRITE,__vdc_gr_ab1_bits);
__IO_REG32_BIT(VDC_GR0_AB2_1,         				0xFCFF9624,__READ_WRITE,__vdc_gr_ab2_bits);
__IO_REG32_BIT(VDC_GR0_AB3_1,         				0xFCFF9628,__READ_WRITE,__vdc_gr_ab3_bits);
__IO_REG32_BIT(VDC_GR0_AB7_1,         				0xFCFF9638,__READ_WRITE,__vdc_gr_ab7_bits);
__IO_REG32_BIT(VDC_GR0_AB8_1,         				0xFCFF963C,__READ_WRITE,__vdc_gr_ab8_bits);
__IO_REG32_BIT(VDC_GR0_AB9_1,         				0xFCFF9640,__READ_WRITE,__vdc_gr_ab9_bits);
__IO_REG32_BIT(VDC_GR0_AB10_1,         				0xFCFF9644,__READ_WRITE,__vdc_gr_ab10_bits);
__IO_REG32_BIT(VDC_GR0_AB11_1,         				0xFCFF9648,__READ_WRITE,__vdc_gr_ab11_bits);
__IO_REG32_BIT(VDC_GR0_BASE_1,         				0xFCFF964C,__READ_WRITE,__vdc_gr_base_bits);
__IO_REG32_BIT(VDC_GR0_CLUT_1,         				0xFCFF9650,__READ_WRITE,__vdc_gr_clut_bits);

/***************************************************************************
 **
 **  VDC SC1 CH1 (Video Display Controller 5 Scaler1 channel 1)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_SC1_SCL0_UPDATE_1,         0xFCFF9C00,__READ_WRITE,__vdc_sc_scl_update_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_FRC1_1,         	0xFCFF9C04,__READ_WRITE,__vdc_sc_scl_frc1_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_FRC2_1,		        0xFCFF9C08,__READ_WRITE,__vdc_sc_scl_frc2_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_FRC3_1,		        0xFCFF9C0C,__READ_WRITE,__vdc_sc_scl_frc3_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_FRC4_1,		        0xFCFF9C10,__READ_WRITE,__vdc_sc_scl_frc4_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_FRC5_1,		        0xFCFF9C14,__READ_WRITE,__vdc_sc_scl_frc5_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_FRC6_1,		        0xFCFF9C18,__READ_WRITE,__vdc_sc_scl_frc6_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_FRC7_1,		        0xFCFF9C1C,__READ_WRITE,__vdc_sc_scl_frc7_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_FRC9_1,		        0xFCFF9C24,__READ			 ,__vdc_sc_scl_frc9_bits);
__IO_REG16_BIT(VDC_SC1_SCL0_MON0_1,         	0xFCFF9C28,__READ			 ,__vdc_sc_scl_mon0_bits);
__IO_REG16_BIT(VDC_SC1_SCL0_INT_1,         		0xFCFF9C2A,__READ_WRITE,__vdc_sc_scl_int_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_DS1_1,         		0xFCFF9C2C,__READ_WRITE,__vdc_sc_scl_ds1_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_DS2_1,         		0xFCFF9C30,__READ_WRITE,__vdc_sc_scl_ds2_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_DS3_1,         		0xFCFF9C34,__READ_WRITE,__vdc_sc_scl_ds3_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_DS4_1,         		0xFCFF9C38,__READ_WRITE,__vdc_sc_scl_ds4_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_DS5_1,         		0xFCFF9C3C,__READ_WRITE,__vdc_sc_scl_ds5_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_DS6_1,         		0xFCFF9C40,__READ_WRITE,__vdc_sc_scl_ds6_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_DS7_1,         		0xFCFF9C44,__READ_WRITE,__vdc_sc_scl_ds7_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_US1_1,         		0xFCFF9C48,__READ_WRITE,__vdc_sc_scl_us1_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_US2_1,         		0xFCFF9C4C,__READ_WRITE,__vdc_sc_scl_us2_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_US3_1,         		0xFCFF9C50,__READ_WRITE,__vdc_sc_scl_us3_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_US4_1,         		0xFCFF9C54,__READ_WRITE,__vdc_sc_scl_us4_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_US5_1,         		0xFCFF9C58,__READ_WRITE,__vdc_sc_scl_us5_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_US6_1,         		0xFCFF9C5C,__READ_WRITE,__vdc_sc_scl_us6_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_US7_1,         		0xFCFF9C60,__READ_WRITE,__vdc_sc_scl_us7_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_US8_1,         		0xFCFF9C64,__READ_WRITE,__vdc_sc_scl_us8_bits);
__IO_REG32_BIT(VDC_SC1_SCL0_OVR1_1,         	0xFCFF9C6C,__READ_WRITE,__vdc_sc_scl_ovr1_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_UPDATE_1,         0xFCFF9C80,__READ_WRITE,__vdc_sc_scl1_update_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_WR1_1,         		0xFCFF9C88,__READ_WRITE,__vdc_sc_scl_wr1_bits);
__IO_REG32(		 VDC_SC1_SCL1_WR2_1,         		0xFCFF9C8C,__READ_WRITE);
__IO_REG32_BIT(VDC_SC1_SCL1_WR3_1,         		0xFCFF9C90,__READ_WRITE,__vdc_sc_scl_wr3_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_WR4_1,         		0xFCFF9C94,__READ_WRITE,__vdc_sc_scl_wr4_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_WR5_1,         		0xFCFF9C9C,__READ_WRITE,__vdc_sc_scl_wr5_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_WR6_1,         		0xFCFF9CA0,__READ_WRITE,__vdc_sc_scl_wr6_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_WR7_1,         		0xFCFF9CA4,__READ			 ,__vdc_sc_scl_wr7_bits);
__IO_REG32(		 VDC_SC1_SCL1_WR8_1,         		0xFCFF9CA8,__READ_WRITE);
__IO_REG32_BIT(VDC_SC1_SCL1_WR9_1,         		0xFCFF9CAC,__READ_WRITE,__vdc_sc_scl_wr9_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_WR10_1,        		0xFCFF9CB0,__READ_WRITE,__vdc_sc_scl_wr10_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_WR11_1,        		0xFCFF9CB4,__READ			 ,__vdc_sc_scl_wr11_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_MON1_1,        		0xFCFF9CB8,__READ			 ,__vdc_sc_scl_mon1_bits);
__IO_REG32(		 VDC_SC1_SCL1_PBUF0_1,        	0xFCFF9CBC,__READ			 );
__IO_REG32(		 VDC_SC1_SCL1_PBUF1_1,       		0xFCFF9CC0,__READ			 );
__IO_REG32(		 VDC_SC1_SCL1_PBUF2_1,       		0xFCFF9CC4,__READ			 );
__IO_REG32(		 VDC_SC1_SCL1_PBUF3_1,        	0xFCFF9CC8,__READ			 );
__IO_REG32_BIT(VDC_SC1_SCL1_PBUF_FLD_1,       0xFCFF9CCC,__READ			 ,__vdc_sc_scl_pbuf_fld_bits);
__IO_REG32_BIT(VDC_SC1_SCL1_PBUF_CNT_1,       0xFCFF9CD0,__READ_WRITE,__vdc_sc_scl_pbuf_cnt_bits);
__IO_REG32_BIT(VDC_GR1_UPDATE_1,         			0xFCFF9D00,__READ_WRITE,__vdc_gr_update_bits);
__IO_REG32_BIT(VDC_GR1_FLM_RD_1,         			0xFCFF9D04,__READ_WRITE,__vdc_gr_flm_rd_bits);
__IO_REG32_BIT(VDC_GR1_FLM_1,         				0xFCFF9D08,__READ_WRITE,__vdc_gr1_flm1_bits);
__IO_REG32(		 VDC_GR1_FLM2_1,         				0xFCFF9D0C,__READ_WRITE);
__IO_REG32_BIT(VDC_GR1_FLM3_1,         				0xFCFF9D10,__READ_WRITE,__vdc_gr_flm3_bits);
__IO_REG32_BIT(VDC_GR1_FLM4_1,         				0xFCFF9D14,__READ_WRITE,__vdc_gr_flm4_bits);
__IO_REG32_BIT(VDC_GR1_FLM5_1,         				0xFCFF9D18,__READ_WRITE,__vdc_gr_flm5_bits);
__IO_REG32_BIT(VDC_GR1_FLM6_1,         				0xFCFF9D1C,__READ_WRITE,__vdc_gr_flm6_bits);
__IO_REG32_BIT(VDC_GR1_AB1_1,         				0xFCFF9D20,__READ_WRITE,__vdc_gr1_ab1_bits);
__IO_REG32_BIT(VDC_GR1_AB2_1,         				0xFCFF9D24,__READ_WRITE,__vdc_gr_ab2_bits);
__IO_REG32_BIT(VDC_GR1_AB3_1,         				0xFCFF9D28,__READ_WRITE,__vdc_gr_ab3_bits);
__IO_REG32_BIT(VDC_GR1_AB4_1,         				0xFCFF9D2C,__READ_WRITE,__vdc_gr1_ab4_bits);
__IO_REG32_BIT(VDC_GR1_AB5_1,         				0xFCFF9D30,__READ_WRITE,__vdc_gr1_ab5_bits);
__IO_REG32_BIT(VDC_GR1_AB6_1,         				0xFCFF9D34,__READ_WRITE,__vdc_gr1_ab6_bits);
__IO_REG32_BIT(VDC_GR1_AB7_1,         				0xFCFF9D38,__READ_WRITE,__vdc_gr1_ab7_bits);
__IO_REG32_BIT(VDC_GR1_AB8_1,         				0xFCFF9D3C,__READ_WRITE,__vdc_gr_ab8_bits);
__IO_REG32_BIT(VDC_GR1_AB9_1,         				0xFCFF9D40,__READ_WRITE,__vdc_gr_ab9_bits);
__IO_REG32_BIT(VDC_GR1_AB10_1,         				0xFCFF9D44,__READ_WRITE,__vdc_gr_ab10_bits);
__IO_REG32_BIT(VDC_GR1_AB11_1,         				0xFCFF9D48,__READ_WRITE,__vdc_gr_ab11_bits);
__IO_REG32_BIT(VDC_GR1_BASE_1,         				0xFCFF9D4C,__READ_WRITE,__vdc_gr_base_bits);
__IO_REG32_BIT(VDC_GR1_CLUT_1,         				0xFCFF9D50,__READ_WRITE,__vdc_gr_clut_bits);
__IO_REG32_BIT(VDC_GR1_MON_1,         				0xFCFF9D54,__READ_WRITE,__vdc_gr1_mon_bits);

/***************************************************************************
 **
 **  VDC ADJ0 CH0 (Video Display Controller 5 Image Quality Improver 0, channel 0)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_ADJ0_UPDATE_0,        	 		0xFCFF7680,__READ_WRITE,__vdc_adj_update_bits);
__IO_REG32_BIT(VDC_ADJ0_BKSTR_SET_0,        	0xFCFF7684,__READ_WRITE,__vdc_adj_bkstr_set_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_TIM1_0,        	 	0xFCFF7688,__READ_WRITE,__vdc_adj_enh_tim1_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_TIM2_0,      	 		0xFCFF768C,__READ_WRITE,__vdc_adj_enh_tim2_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_TIM3_0,      	 		0xFCFF7690,__READ_WRITE,__vdc_adj_enh_tim3_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_SHP1_0,        	 	0xFCFF7694,__READ_WRITE,__vdc_adj_enh_shp1_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_SHP2_0,        	 	0xFCFF7698,__READ_WRITE,__vdc_adj_enh_shp2_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_SHP3_0,        	 	0xFCFF769C,__READ_WRITE,__vdc_adj_enh_shp3_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_SHP4_0,        	 	0xFCFF76A0,__READ_WRITE,__vdc_adj_enh_shp4_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_SHP5_0,        	 	0xFCFF76A4,__READ_WRITE,__vdc_adj_enh_shp5_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_SHP6_0,        	 	0xFCFF76A8,__READ_WRITE,__vdc_adj_enh_shp6_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_LTI1_0,        	 	0xFCFF76AC,__READ_WRITE,__vdc_adj_enh_lti1_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_LTI2_0,        	 	0xFCFF76B0,__READ_WRITE,__vdc_adj_enh_lti2_bits);
__IO_REG32_BIT(VDC_ADJ0_MTX_MODE_0,        	 	0xFCFF76B4,__READ_WRITE,__vdc_adj_mtx_mode_bits);
__IO_REG32_BIT(VDC_ADJ0_MTX_YG_ADJ0_0,        0xFCFF76B8,__READ_WRITE,__vdc_adj_mtx_yg_adj_bits);
__IO_REG32_BIT(VDC_ADJ0_MTX_YG_ADJ1_0,        0xFCFF76BC,__READ_WRITE,__vdc_adj_mtx_yg_adj1_bits);
__IO_REG32_BIT(VDC_ADJ0_MTX_CBB_ADJ0_0,       0xFCFF76C0,__READ_WRITE,__vdc_adj_mtx_cbb_adj_bits);
__IO_REG32_BIT(VDC_ADJ0_MTX_CBB_ADJ1_0,       0xFCFF76C4,__READ_WRITE,__vdc_adj_mtx_cbb_adj1_bits);
__IO_REG32_BIT(VDC_ADJ0_MTX_CRR_ADJ0_0,       0xFCFF76C8,__READ_WRITE,__vdc_adj_mtx_crr_adj_bits);
__IO_REG32_BIT(VDC_ADJ0_MTX_CRR_ADJ1_0,       0xFCFF76CC,__READ_WRITE,__vdc_adj_mtx_crr_adj1_bits);

/***************************************************************************
 **
 **  VDC ADJ1 CH0 (Video Display Controller 5 Image Quality Improver 1, channel 0)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_ADJ1_UPDATE_0,        	 		0xFCFF7D80,__READ_WRITE,__vdc_adj_update_bits);
__IO_REG32_BIT(VDC_ADJ1_BKSTR_SET_0,        	0xFCFF7D84,__READ_WRITE,__vdc_adj_bkstr_set_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_TIM1_0,        	 	0xFCFF7D88,__READ_WRITE,__vdc_adj_enh_tim1_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_TIM2_0,      	 		0xFCFF7D8C,__READ_WRITE,__vdc_adj_enh_tim2_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_TIM3_0,      	 		0xFCFF7D90,__READ_WRITE,__vdc_adj_enh_tim3_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_SHP1_0,        	 	0xFCFF7D94,__READ_WRITE,__vdc_adj_enh_shp1_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_SHP2_0,        	 	0xFCFF7D98,__READ_WRITE,__vdc_adj_enh_shp2_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_SHP3_0,        	 	0xFCFF7D9C,__READ_WRITE,__vdc_adj_enh_shp3_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_SHP4_0,        	 	0xFCFF7DA0,__READ_WRITE,__vdc_adj_enh_shp4_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_SHP5_0,        	 	0xFCFF7DA4,__READ_WRITE,__vdc_adj_enh_shp5_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_SHP6_0,        	 	0xFCFF7DA8,__READ_WRITE,__vdc_adj_enh_shp6_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_LTI1_0,        	 	0xFCFF7DAC,__READ_WRITE,__vdc_adj_enh_lti1_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_LTI2_0,        	 	0xFCFF7DB0,__READ_WRITE,__vdc_adj_enh_lti2_bits);
__IO_REG32_BIT(VDC_ADJ1_MTX_MODE_0,        	 	0xFCFF7DB4,__READ_WRITE,__vdc_adj_mtx_mode_bits);
__IO_REG32_BIT(VDC_ADJ1_MTX_YG_ADJ0_0,        0xFCFF7DB8,__READ_WRITE,__vdc_adj_mtx_yg_adj_bits);
__IO_REG32_BIT(VDC_ADJ1_MTX_YG_ADJ1_0,        0xFCFF7DBC,__READ_WRITE,__vdc_adj_mtx_yg_adj1_bits);
__IO_REG32_BIT(VDC_ADJ1_MTX_CBB_ADJ0_0,       0xFCFF7DC0,__READ_WRITE,__vdc_adj_mtx_cbb_adj_bits);
__IO_REG32_BIT(VDC_ADJ1_MTX_CBB_ADJ1_0,       0xFCFF7DC4,__READ_WRITE,__vdc_adj_mtx_cbb_adj1_bits);
__IO_REG32_BIT(VDC_ADJ1_MTX_CRR_ADJ0_0,       0xFCFF7DC8,__READ_WRITE,__vdc_adj_mtx_crr_adj_bits);
__IO_REG32_BIT(VDC_ADJ1_MTX_CRR_ADJ1_0,       0xFCFF7DCC,__READ_WRITE,__vdc_adj_mtx_crr_adj1_bits);

/***************************************************************************
 **
 **  VDC ADJ0 CH1 (Video Display Controller 5 Image Quality Improver 0, channel 1)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_ADJ0_UPDATE_1,        	 		0xFCFF9680,__READ_WRITE,__vdc_adj_update_bits);
__IO_REG32_BIT(VDC_ADJ0_BKSTR_SET_1,        	0xFCFF9684,__READ_WRITE,__vdc_adj_bkstr_set_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_TIM1_1,        	 	0xFCFF9688,__READ_WRITE,__vdc_adj_enh_tim1_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_TIM2_1,      	 		0xFCFF968C,__READ_WRITE,__vdc_adj_enh_tim2_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_TIM3_1,      	 		0xFCFF9690,__READ_WRITE,__vdc_adj_enh_tim3_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_SHP1_1,        	 	0xFCFF9694,__READ_WRITE,__vdc_adj_enh_shp1_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_SHP2_1,        	 	0xFCFF9698,__READ_WRITE,__vdc_adj_enh_shp2_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_SHP3_1,        	 	0xFCFF969C,__READ_WRITE,__vdc_adj_enh_shp3_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_SHP4_1,        	 	0xFCFF96A0,__READ_WRITE,__vdc_adj_enh_shp4_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_SHP5_1,        	 	0xFCFF96A4,__READ_WRITE,__vdc_adj_enh_shp5_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_SHP6_1,        	 	0xFCFF96A8,__READ_WRITE,__vdc_adj_enh_shp6_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_LTI1_1,        	 	0xFCFF96AC,__READ_WRITE,__vdc_adj_enh_lti1_bits);
__IO_REG32_BIT(VDC_ADJ0_ENH_LTI2_1,        	 	0xFCFF96B0,__READ_WRITE,__vdc_adj_enh_lti2_bits);
__IO_REG32_BIT(VDC_ADJ0_MTX_MODE_1,        	 	0xFCFF96B4,__READ_WRITE,__vdc_adj_mtx_mode_bits);
__IO_REG32_BIT(VDC_ADJ0_MTX_YG_ADJ0_1,        0xFCFF96B8,__READ_WRITE,__vdc_adj_mtx_yg_adj_bits);
__IO_REG32_BIT(VDC_ADJ0_MTX_YG_ADJ1_1,        0xFCFF96BC,__READ_WRITE,__vdc_adj_mtx_yg_adj1_bits);
__IO_REG32_BIT(VDC_ADJ0_MTX_CBB_ADJ0_1,       0xFCFF96C0,__READ_WRITE,__vdc_adj_mtx_cbb_adj_bits);
__IO_REG32_BIT(VDC_ADJ0_MTX_CBB_ADJ1_1,       0xFCFF96C4,__READ_WRITE,__vdc_adj_mtx_cbb_adj1_bits);
__IO_REG32_BIT(VDC_ADJ0_MTX_CRR_ADJ0_1,       0xFCFF96C8,__READ_WRITE,__vdc_adj_mtx_crr_adj_bits);
__IO_REG32_BIT(VDC_ADJ0_MTX_CRR_ADJ1_1,       0xFCFF96CC,__READ_WRITE,__vdc_adj_mtx_crr_adj1_bits);

/***************************************************************************
 **
 **  VDC ADJ1 CH1 (Video Display Controller 5 Image Quality Improver 1, channel 1)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_ADJ1_UPDATE_1,        	 		0xFCFF9D80,__READ_WRITE,__vdc_adj_update_bits);
__IO_REG32_BIT(VDC_ADJ1_BKSTR_SET_1,        	0xFCFF9D84,__READ_WRITE,__vdc_adj_bkstr_set_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_TIM1_1,        	 	0xFCFF9D88,__READ_WRITE,__vdc_adj_enh_tim1_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_TIM2_1,      	 		0xFCFF9D8C,__READ_WRITE,__vdc_adj_enh_tim2_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_TIM3_1,      	 		0xFCFF9D90,__READ_WRITE,__vdc_adj_enh_tim3_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_SHP1_1,        	 	0xFCFF9D94,__READ_WRITE,__vdc_adj_enh_shp1_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_SHP2_1,        	 	0xFCFF9D98,__READ_WRITE,__vdc_adj_enh_shp2_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_SHP3_1,        	 	0xFCFF9D9C,__READ_WRITE,__vdc_adj_enh_shp3_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_SHP4_1,        	 	0xFCFF9DA0,__READ_WRITE,__vdc_adj_enh_shp4_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_SHP5_1,        	 	0xFCFF9DA4,__READ_WRITE,__vdc_adj_enh_shp5_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_SHP6_1,        	 	0xFCFF9DA8,__READ_WRITE,__vdc_adj_enh_shp6_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_LTI1_1,        	 	0xFCFF9DAC,__READ_WRITE,__vdc_adj_enh_lti1_bits);
__IO_REG32_BIT(VDC_ADJ1_ENH_LTI2_1,        	 	0xFCFF9DB0,__READ_WRITE,__vdc_adj_enh_lti2_bits);
__IO_REG32_BIT(VDC_ADJ1_MTX_MODE_1,        	 	0xFCFF9DB4,__READ_WRITE,__vdc_adj_mtx_mode_bits);
__IO_REG32_BIT(VDC_ADJ1_MTX_YG_ADJ0_1,        0xFCFF9DB8,__READ_WRITE,__vdc_adj_mtx_yg_adj_bits);
__IO_REG32_BIT(VDC_ADJ1_MTX_YG_ADJ1_1,        0xFCFF9DBC,__READ_WRITE,__vdc_adj_mtx_yg_adj1_bits);
__IO_REG32_BIT(VDC_ADJ1_MTX_CBB_ADJ0_1,       0xFCFF9DC0,__READ_WRITE,__vdc_adj_mtx_cbb_adj_bits);
__IO_REG32_BIT(VDC_ADJ1_MTX_CBB_ADJ1_1,       0xFCFF9DC4,__READ_WRITE,__vdc_adj_mtx_cbb_adj1_bits);
__IO_REG32_BIT(VDC_ADJ1_MTX_CRR_ADJ0_1,       0xFCFF9DC8,__READ_WRITE,__vdc_adj_mtx_crr_adj_bits);
__IO_REG32_BIT(VDC_ADJ1_MTX_CRR_ADJ1_1,       0xFCFF9DCC,__READ_WRITE,__vdc_adj_mtx_crr_adj1_bits);

/***************************************************************************
 **
 **  VDC IS CH 0(Video Display Controller 5 Image Synthesizer, channel 0)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_GR2_UPDATE_0,        	 		0xFCFF7700,__READ_WRITE,__vdc_gr2_update_bits);
__IO_REG32_BIT(VDC_GR2_FLM_RD_0,        	 		0xFCFF7704,__READ_WRITE,__vdc_gr2_flm_rd_bits);
__IO_REG32_BIT(VDC_GR2_FLM1_0,        	 			0xFCFF7708,__READ_WRITE,__vdc_gr2_flm1_bits);
__IO_REG32(		 VDC_GR2_FLM2_0,        	 			0xFCFF770C,__READ_WRITE);
__IO_REG32_BIT(VDC_GR2_FLM3_0,        	 			0xFCFF7710,__READ_WRITE,__vdc_gr2_flm3_bits);
__IO_REG32_BIT(VDC_GR2_FLM4_0,        	 			0xFCFF7714,__READ_WRITE,__vdc_gr2_flm4_bits);
__IO_REG32_BIT(VDC_GR2_FLM5_0,        	 			0xFCFF7718,__READ_WRITE,__vdc_gr2_flm5_bits);
__IO_REG32_BIT(VDC_GR2_FLM6_0,        	 			0xFCFF771C,__READ_WRITE,__vdc_gr2_flm6_bits);
__IO_REG32_BIT(VDC_GR2_AB1_0,        	 				0xFCFF7720,__READ_WRITE,__vdc_gr2_ab1_bits);
__IO_REG32_BIT(VDC_GR2_AB2_0,        	 				0xFCFF7724,__READ_WRITE,__vdc_gr2_ab2_bits);
__IO_REG32_BIT(VDC_GR2_AB3_0,        	 				0xFCFF7728,__READ_WRITE,__vdc_gr2_ab3_bits);
__IO_REG32_BIT(VDC_GR2_AB4_0,        	 				0xFCFF772C,__READ_WRITE,__vdc_gr2_ab4_bits);
__IO_REG32_BIT(VDC_GR2_AB5_0,        	 				0xFCFF7730,__READ_WRITE,__vdc_gr2_ab5_bits);
__IO_REG32_BIT(VDC_GR2_AB6_0,        	 				0xFCFF7734,__READ_WRITE,__vdc_gr2_ab6_bits);
__IO_REG32_BIT(VDC_GR2_AB7_0,        	 				0xFCFF7738,__READ_WRITE,__vdc_gr2_ab7_bits);
__IO_REG32_BIT(VDC_GR2_AB8_0,        	 				0xFCFF773C,__READ_WRITE,__vdc_gr2_ab8_bits);
__IO_REG32_BIT(VDC_GR2_AB9_0,        	 				0xFCFF7740,__READ_WRITE,__vdc_gr2_ab9_bits);
__IO_REG32_BIT(VDC_GR2_AB10_0,       	 				0xFCFF7744,__READ_WRITE,__vdc_gr2_ab10_bits);
__IO_REG32_BIT(VDC_GR2_AB11_0,       	 				0xFCFF7748,__READ_WRITE,__vdc_gr2_ab11_bits);
__IO_REG32_BIT(VDC_GR2_BASE_0,        	 			0xFCFF774C,__READ_WRITE,__vdc_gr2_base_bits);
__IO_REG32_BIT(VDC_GR2_CLUT_0,        	 			0xFCFF7750,__READ_WRITE,__vdc_gr2_clut_bits);
__IO_REG32_BIT(VDC_GR2_MON_0,	        	 			0xFCFF7754,__READ			 ,__vdc_gr2_mon_bits);
__IO_REG32_BIT(VDC_GR3_UPDATE_0,        	 		0xFCFF7780,__READ_WRITE,__vdc_gr3_update_bits);
__IO_REG32_BIT(VDC_GR3_FLM_RD_0,        	 		0xFCFF7784,__READ_WRITE,__vdc_gr3_flm_rd_bits);
__IO_REG32_BIT(VDC_GR3_FLM1_0,        	 			0xFCFF7788,__READ_WRITE,__vdc_gr3_flm1_bits);
__IO_REG32(		 VDC_GR3_FLM2_0,        	 			0xFCFF778C,__READ_WRITE);
__IO_REG32_BIT(VDC_GR3_FLM3_0,        	 			0xFCFF7790,__READ_WRITE,__vdc_gr3_flm3_bits);
__IO_REG32_BIT(VDC_GR3_FLM4_0,        	 			0xFCFF7794,__READ_WRITE,__vdc_gr3_flm4_bits);
__IO_REG32_BIT(VDC_GR3_FLM5_0,        	 			0xFCFF7798,__READ_WRITE,__vdc_gr3_flm5_bits);
__IO_REG32_BIT(VDC_GR3_FLM6_0,        	 			0xFCFF779C,__READ_WRITE,__vdc_gr3_flm6_bits);
__IO_REG32_BIT(VDC_GR3_AB1_0,        	 				0xFCFF77A0,__READ_WRITE,__vdc_gr3_ab1_bits);
__IO_REG32_BIT(VDC_GR3_AB2_0,        	 				0xFCFF77A4,__READ_WRITE,__vdc_gr3_ab2_bits);
__IO_REG32_BIT(VDC_GR3_AB3_0,        	 				0xFCFF77A8,__READ_WRITE,__vdc_gr3_ab3_bits);
__IO_REG32_BIT(VDC_GR3_AB4_0,        	 				0xFCFF77AC,__READ_WRITE,__vdc_gr3_ab4_bits);
__IO_REG32_BIT(VDC_GR3_AB5_0,        	 				0xFCFF77B0,__READ_WRITE,__vdc_gr3_ab5_bits);
__IO_REG32_BIT(VDC_GR3_AB6_0,        	 				0xFCFF77B4,__READ_WRITE,__vdc_gr3_ab6_bits);
__IO_REG32_BIT(VDC_GR3_AB7_0,        	 				0xFCFF77B8,__READ_WRITE,__vdc_gr3_ab7_bits);
__IO_REG32_BIT(VDC_GR3_AB8_0,        	 				0xFCFF77BC,__READ_WRITE,__vdc_gr3_ab8_bits);
__IO_REG32_BIT(VDC_GR3_AB9_0,        	 				0xFCFF77C0,__READ_WRITE,__vdc_gr3_ab9_bits);
__IO_REG32_BIT(VDC_GR3_AB10_0,        	 			0xFCFF77C4,__READ_WRITE,__vdc_gr3_ab10_bits);
__IO_REG32_BIT(VDC_GR3_AB11_0,        	 			0xFCFF77C8,__READ_WRITE,__vdc_gr3_ab11_bits);
__IO_REG32_BIT(VDC_GR3_BASE_0,        	 			0xFCFF77CC,__READ_WRITE,__vdc_gr3_base_bits);
__IO_REG32_BIT(VDC_GR3_CLUT_INT_0,        	 	0xFCFF77D0,__READ_WRITE,__vdc_gr3_clut_int_bits);
__IO_REG32_BIT(VDC_GR3_MON_0,        	 				0xFCFF77D4,__READ			 ,__vdc_gr3_mon_bits);

/***************************************************************************
 **
 **  VDC GR VIN CH 0 (Video Display Controller 5 VIN Synthesizer, channel 0)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_GR_VIN_UPDATE_0,        	 	0xFCFF7E00,__READ_WRITE,__vdc_gr_vin_update_bits);
__IO_REG32_BIT(VDC_GR_VIN_AB1_0,        	 		0xFCFF7E20,__READ_WRITE,__vdc_gr_vin_ab1_bits);
__IO_REG32_BIT(VDC_GR_VIN_AB2_0,        	 		0xFCFF7E24,__READ_WRITE,__vdc_gr_vin_ab2_bits);
__IO_REG32_BIT(VDC_GR_VIN_AB3_0,        	 		0xFCFF7E28,__READ_WRITE,__vdc_gr_vin_ab3_bits);
__IO_REG32_BIT(VDC_GR_VIN_AB4_0,        	 		0xFCFF7E2C,__READ_WRITE,__vdc_gr_vin_ab4_bits);
__IO_REG32_BIT(VDC_GR_VIN_AB5_0,        	 		0xFCFF7E30,__READ_WRITE,__vdc_gr_vin_ab5_bits);
__IO_REG32_BIT(VDC_GR_VIN_AB6_0,        	 		0xFCFF7E34,__READ_WRITE,__vdc_gr_vin_ab6_bits);
__IO_REG32_BIT(VDC_GR_VIN_AB7_0,        	 		0xFCFF7E38,__READ_WRITE,__vdc_gr_vin_ab7_bits);
__IO_REG32_BIT(VDC_GR_VIN_BASE_0,        	 		0xFCFF7E4C,__READ_WRITE,__vdc_gr_vin_base_bits);
__IO_REG32_BIT(VDC_GR_VIN_MON_0,        	 		0xFCFF7E54,__READ_WRITE,__vdc_gr_vin_mon_bits);

/***************************************************************************
 **
 **  VDC IS CH 1(Video Display Controller 5 Image Synthesizer, channel 1)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_GR2_UPDATE_1,        	 		0xFCFF9700,__READ_WRITE,__vdc_gr2_update_bits);
__IO_REG32_BIT(VDC_GR2_FLM_RD_1,        	 		0xFCFF9704,__READ_WRITE,__vdc_gr2_flm_rd_bits);
__IO_REG32_BIT(VDC_GR2_FLM1_1,        	 			0xFCFF9708,__READ_WRITE,__vdc_gr2_flm1_bits);
__IO_REG32(		 VDC_GR2_FLM2_1,        	 			0xFCFF970C,__READ_WRITE);
__IO_REG32_BIT(VDC_GR2_FLM3_1,        	 			0xFCFF9710,__READ_WRITE,__vdc_gr2_flm3_bits);
__IO_REG32_BIT(VDC_GR2_FLM4_1,        	 			0xFCFF9714,__READ_WRITE,__vdc_gr2_flm4_bits);
__IO_REG32_BIT(VDC_GR2_FLM5_1,        	 			0xFCFF9718,__READ_WRITE,__vdc_gr2_flm5_bits);
__IO_REG32_BIT(VDC_GR2_FLM6_1,        	 			0xFCFF971C,__READ_WRITE,__vdc_gr2_flm6_bits);
__IO_REG32_BIT(VDC_GR2_AB1_1,        	 				0xFCFF9720,__READ_WRITE,__vdc_gr2_ab1_bits);
__IO_REG32_BIT(VDC_GR2_AB2_1,        	 				0xFCFF9724,__READ_WRITE,__vdc_gr2_ab2_bits);
__IO_REG32_BIT(VDC_GR2_AB3_1,        	 				0xFCFF9728,__READ_WRITE,__vdc_gr2_ab3_bits);
__IO_REG32_BIT(VDC_GR2_AB4_1,        	 				0xFCFF972C,__READ_WRITE,__vdc_gr2_ab4_bits);
__IO_REG32_BIT(VDC_GR2_AB5_1,        	 				0xFCFF9730,__READ_WRITE,__vdc_gr2_ab5_bits);
__IO_REG32_BIT(VDC_GR2_AB6_1,        	 				0xFCFF9734,__READ_WRITE,__vdc_gr2_ab6_bits);
__IO_REG32_BIT(VDC_GR2_AB7_1,        	 				0xFCFF9738,__READ_WRITE,__vdc_gr2_ab7_bits);
__IO_REG32_BIT(VDC_GR2_AB8_1,        	 				0xFCFF973C,__READ_WRITE,__vdc_gr2_ab8_bits);
__IO_REG32_BIT(VDC_GR2_AB9_1,        	 				0xFCFF9740,__READ_WRITE,__vdc_gr2_ab9_bits);
__IO_REG32_BIT(VDC_GR2_AB10_1,       	 				0xFCFF9744,__READ_WRITE,__vdc_gr2_ab10_bits);
__IO_REG32_BIT(VDC_GR2_AB11_1,       	 				0xFCFF9748,__READ_WRITE,__vdc_gr2_ab11_bits);
__IO_REG32_BIT(VDC_GR2_BASE_1,        	 			0xFCFF974C,__READ_WRITE,__vdc_gr2_base_bits);
__IO_REG32_BIT(VDC_GR2_CLUT_1,        	 			0xFCFF9750,__READ_WRITE,__vdc_gr2_clut_bits);
__IO_REG32_BIT(VDC_GR2_MON_1,	        	 			0xFCFF9754,__READ			 ,__vdc_gr2_mon_bits);
__IO_REG32_BIT(VDC_GR3_UPDATE_1,        	 		0xFCFF9780,__READ_WRITE,__vdc_gr3_update_bits);
__IO_REG32_BIT(VDC_GR3_FLM_RD_1,        	 		0xFCFF9784,__READ_WRITE,__vdc_gr3_flm_rd_bits);
__IO_REG32_BIT(VDC_GR3_FLM1_1,        	 			0xFCFF9788,__READ_WRITE,__vdc_gr3_flm1_bits);
__IO_REG32(		 VDC_GR3_FLM2_1,        	 			0xFCFF978C,__READ_WRITE);
__IO_REG32_BIT(VDC_GR3_FLM3_1,        	 			0xFCFF9790,__READ_WRITE,__vdc_gr3_flm3_bits);
__IO_REG32_BIT(VDC_GR3_FLM4_1,        	 			0xFCFF9794,__READ_WRITE,__vdc_gr3_flm4_bits);
__IO_REG32_BIT(VDC_GR3_FLM5_1,        	 			0xFCFF9798,__READ_WRITE,__vdc_gr3_flm5_bits);
__IO_REG32_BIT(VDC_GR3_FLM6_1,        	 			0xFCFF979C,__READ_WRITE,__vdc_gr3_flm6_bits);
__IO_REG32_BIT(VDC_GR3_AB1_1,        	 				0xFCFF97A0,__READ_WRITE,__vdc_gr3_ab1_bits);
__IO_REG32_BIT(VDC_GR3_AB2_1,        	 				0xFCFF97A4,__READ_WRITE,__vdc_gr3_ab2_bits);
__IO_REG32_BIT(VDC_GR3_AB3_1,        	 				0xFCFF97A8,__READ_WRITE,__vdc_gr3_ab3_bits);
__IO_REG32_BIT(VDC_GR3_AB4_1,        	 				0xFCFF97AC,__READ_WRITE,__vdc_gr3_ab4_bits);
__IO_REG32_BIT(VDC_GR3_AB5_1,        	 				0xFCFF97B0,__READ_WRITE,__vdc_gr3_ab5_bits);
__IO_REG32_BIT(VDC_GR3_AB6_1,        	 				0xFCFF97B4,__READ_WRITE,__vdc_gr3_ab6_bits);
__IO_REG32_BIT(VDC_GR3_AB7_1,        	 				0xFCFF97B8,__READ_WRITE,__vdc_gr3_ab7_bits);
__IO_REG32_BIT(VDC_GR3_AB8_1,        	 				0xFCFF97BC,__READ_WRITE,__vdc_gr3_ab8_bits);
__IO_REG32_BIT(VDC_GR3_AB9_1,        	 				0xFCFF97C0,__READ_WRITE,__vdc_gr3_ab9_bits);
__IO_REG32_BIT(VDC_GR3_AB10_1,        	 			0xFCFF97C4,__READ_WRITE,__vdc_gr3_ab10_bits);
__IO_REG32_BIT(VDC_GR3_AB11_1,        	 			0xFCFF97C8,__READ_WRITE,__vdc_gr3_ab11_bits);
__IO_REG32_BIT(VDC_GR3_BASE_1,        	 			0xFCFF97CC,__READ_WRITE,__vdc_gr3_base_bits);
__IO_REG32_BIT(VDC_GR3_CLUT_INT_1,        	 	0xFCFF97D0,__READ_WRITE,__vdc_gr3_clut_int_bits);
__IO_REG32_BIT(VDC_GR3_MON_1,        	 				0xFCFF97D4,__READ			 ,__vdc_gr3_mon_bits);

/***************************************************************************
 **
 **  VDC GR VIN CH 1 (Video Display Controller 5 VIN Synthesizer, channel 1)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_GR_VIN_UPDATE_1,        	 	0xFCFF9E00,__READ_WRITE,__vdc_gr_vin_update_bits);
__IO_REG32_BIT(VDC_GR_VIN_AB1_1,        	 		0xFCFF9E20,__READ_WRITE,__vdc_gr_vin_ab1_bits);
__IO_REG32_BIT(VDC_GR_VIN_AB2_1,        	 		0xFCFF9E24,__READ_WRITE,__vdc_gr_vin_ab2_bits);
__IO_REG32_BIT(VDC_GR_VIN_AB3_1,        	 		0xFCFF9E28,__READ_WRITE,__vdc_gr_vin_ab3_bits);
__IO_REG32_BIT(VDC_GR_VIN_AB4_1,        	 		0xFCFF9E2C,__READ_WRITE,__vdc_gr_vin_ab4_bits);
__IO_REG32_BIT(VDC_GR_VIN_AB5_1,        	 		0xFCFF9E30,__READ_WRITE,__vdc_gr_vin_ab5_bits);
__IO_REG32_BIT(VDC_GR_VIN_AB6_1,        	 		0xFCFF9E34,__READ_WRITE,__vdc_gr_vin_ab6_bits);
__IO_REG32_BIT(VDC_GR_VIN_AB7_1,        	 		0xFCFF9E38,__READ_WRITE,__vdc_gr_vin_ab7_bits);
__IO_REG32_BIT(VDC_GR_VIN_BASE_1,        	 		0xFCFF9E4C,__READ_WRITE,__vdc_gr_vin_base_bits);
__IO_REG32_BIT(VDC_GR_VIN_MON_1,        	 		0xFCFF9E54,__READ_WRITE,__vdc_gr_vin_mon_bits);

/***************************************************************************
 **
 **  VDC OIR CH0 (Video Display Controller 5 Output Image Generator channel 0)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_OIR_SCL0_UPDATE_0,        	0xFCFF7E80,__READ_WRITE,__vdc_oir_scl_update_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_FRC1_0,        		0xFCFF7E84,__READ_WRITE,__vdc_oir_scl_frc1_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_FRC2_0,        		0xFCFF7E88,__READ_WRITE,__vdc_oir_scl_frc2_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_FRC3_0,        		0xFCFF7E8C,__READ_WRITE,__vdc_oir_scl_frc3_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_FRC4_0,        		0xFCFF7E90,__READ_WRITE,__vdc_oir_scl_frc4_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_FRC5_0,        		0xFCFF7E94,__READ_WRITE,__vdc_oir_scl_frc5_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_FRC6_0,        		0xFCFF7E98,__READ_WRITE,__vdc_oir_scl_frc6_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_FRC7_0,        		0xFCFF7E9C,__READ_WRITE,__vdc_oir_scl_frc7_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_DS1_0,        		0xFCFF7EAC,__READ_WRITE,__vdc_oir_scl_ds1_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_DS2_0,        		0xFCFF7EB0,__READ_WRITE,__vdc_oir_scl_ds2_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_DS3_0,        		0xFCFF7EB4,__READ_WRITE,__vdc_oir_scl_ds3_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_DS7_0,        		0xFCFF7EC4,__READ_WRITE,__vdc_oir_scl_ds7_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_US1_0,        		0xFCFF7EC8,__READ_WRITE,__vdc_oir_scl_us1_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_US2_0,        		0xFCFF7ECC,__READ_WRITE,__vdc_oir_scl_us2_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_US3_0,        		0xFCFF7ED0,__READ_WRITE,__vdc_oir_scl_us3_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_US8_0,        		0xFCFF7EE4,__READ_WRITE,__vdc_oir_scl_us8_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_OVR1_0,        		0xFCFF7EEC,__READ_WRITE,__vdc_oir_scl_ovr1_bits);
__IO_REG32_BIT(VDC_OIR_SCL1_UPDATE_0,        	0xFCFF7F00,__READ_WRITE,__vdc_oir_scl1_update_bits);
__IO_REG32_BIT(VDC_OIR_SCL1_WR1_0,        		0xFCFF7F08,__READ_WRITE,__vdc_oir_scl_wr1_bits);
__IO_REG32(		 VDC_OIR_SCL1_WR2_0,        		0xFCFF7F0C,__READ_WRITE);
__IO_REG32_BIT(VDC_OIR_SCL1_WR3_0,        		0xFCFF7F10,__READ_WRITE,__vdc_oir_scl_wr3_bits);
__IO_REG32_BIT(VDC_OIR_SCL1_WR4_0,        		0xFCFF7F14,__READ_WRITE,__vdc_oir_scl_wr4_bits);
__IO_REG32_BIT(VDC_OIR_SCL1_WR5_0,        		0xFCFF7F1C,__READ_WRITE,__vdc_oir_scl_wr5_bits);
__IO_REG32_BIT(VDC_OIR_SCL1_WR6_0,        		0xFCFF7F20,__READ_WRITE,__vdc_oir_scl_wr6_bits);
__IO_REG32_BIT(VDC_OIR_SCL1_WR7_0,        		0xFCFF7F24,__READ			 ,__vdc_oir_scl_wr7_bits);
__IO_REG32_BIT(VDC_GR_OIR_UPDATE_0,        		0xFCFF7F80,__READ_WRITE,__vdc_gr_oir_update_bits);
__IO_REG32_BIT(VDC_GR_OIR_FLM_RD_0,        		0xFCFF7F84,__READ_WRITE,__vdc_gr_oir_flm_rd_bits);
__IO_REG32_BIT(VDC_GR_OIR_FLM1_0,        			0xFCFF7F88,__READ_WRITE,__vdc_gr_oir_flm1_bits);
__IO_REG32(		 VDC_GR_OIR_FLM2_0,        			0xFCFF7F8C,__READ_WRITE);
__IO_REG32_BIT(VDC_GR_OIR_FLM3_0,        			0xFCFF7F90,__READ_WRITE,__vdc_gr_oir_flm3_bits);
__IO_REG32_BIT(VDC_GR_OIR_FLM4_0,        			0xFCFF7F94,__READ_WRITE,__vdc_gr_oir_flm4_bits);
__IO_REG32_BIT(VDC_GR_OIR_FLM5_0,        			0xFCFF7F98,__READ_WRITE,__vdc_gr_oir_flm5_bits);
__IO_REG32_BIT(VDC_GR_OIR_FLM6_0,        			0xFCFF7F9C,__READ_WRITE,__vdc_gr_oir_flm6_bits);
__IO_REG32_BIT(VDC_GR_OIR_AB1_0,        			0xFCFF7FA0,__READ_WRITE,__vdc_gr_oir_ab1_bits);
__IO_REG32_BIT(VDC_GR_OIR_AB2_0,        			0xFCFF7FA4,__READ_WRITE,__vdc_gr_oir_ab2_bits);
__IO_REG32_BIT(VDC_GR_OIR_AB3_0,        			0xFCFF7FA8,__READ_WRITE,__vdc_gr_oir_ab3_bits);
__IO_REG32_BIT(VDC_GR_OIR_AB7_0,        			0xFCFF7FB8,__READ_WRITE,__vdc_gr_oir_ab7_bits);
__IO_REG32_BIT(VDC_GR_OIR_AB8_0,        			0xFCFF7FBC,__READ_WRITE,__vdc_gr_oir_ab8_bits);
__IO_REG32_BIT(VDC_GR_OIR_AB9_0,        			0xFCFF7FC0,__READ_WRITE,__vdc_gr_oir_ab9_bits);
__IO_REG32_BIT(VDC_GR_OIR_AB10_0,        			0xFCFF7FC4,__READ_WRITE,__vdc_gr_oir_ab10_bits);
__IO_REG32_BIT(VDC_GR_OIR_AB11_0,        			0xFCFF7FC8,__READ_WRITE,__vdc_gr_oir_ab11_bits);
__IO_REG32_BIT(VDC_GR_OIR_BASE_0,        			0xFCFF7FCC,__READ_WRITE,__vdc_gr_oir_base_bits);
__IO_REG32_BIT(VDC_GR_OIR_CLUT_0,        			0xFCFF7FD0,__READ_WRITE,__vdc_gr_oir_clut_bits);
__IO_REG32_BIT(VDC_GR_OIR_MON_0,        			0xFCFF7FD4,__READ			 ,__vdc_gr_oir_mon_bits);

/***************************************************************************
 **
 **  VDC OIR CH1 (Video Display Controller 5 Output Image Generator channel 1)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_OIR_SCL0_UPDATE_1,        	0xFCFF9E80,__READ_WRITE,__vdc_oir_scl_update_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_FRC1_1,        		0xFCFF9E84,__READ_WRITE,__vdc_oir_scl_frc1_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_FRC2_1,        		0xFCFF9E88,__READ_WRITE,__vdc_oir_scl_frc2_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_FRC3_1,        		0xFCFF9E8C,__READ_WRITE,__vdc_oir_scl_frc3_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_FRC4_1,        		0xFCFF9E90,__READ_WRITE,__vdc_oir_scl_frc4_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_FRC5_1,        		0xFCFF9E94,__READ_WRITE,__vdc_oir_scl_frc5_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_FRC6_1,        		0xFCFF9E98,__READ_WRITE,__vdc_oir_scl_frc6_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_FRC7_1,        		0xFCFF9E9C,__READ_WRITE,__vdc_oir_scl_frc7_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_DS1_1,        		0xFCFF9EAC,__READ_WRITE,__vdc_oir_scl_ds1_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_DS2_1,        		0xFCFF9EB0,__READ_WRITE,__vdc_oir_scl_ds2_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_DS3_1,        		0xFCFF9EB4,__READ_WRITE,__vdc_oir_scl_ds3_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_DS7_1,        		0xFCFF9EC4,__READ_WRITE,__vdc_oir_scl_ds7_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_US1_1,        		0xFCFF9EC8,__READ_WRITE,__vdc_oir_scl_us1_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_US2_1,        		0xFCFF9ECC,__READ_WRITE,__vdc_oir_scl_us2_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_US3_1,        		0xFCFF9ED0,__READ_WRITE,__vdc_oir_scl_us3_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_US8_1,        		0xFCFF9EE4,__READ_WRITE,__vdc_oir_scl_us8_bits);
__IO_REG32_BIT(VDC_OIR_SCL0_OVR1_1,        		0xFCFF9EEC,__READ_WRITE,__vdc_oir_scl_ovr1_bits);
__IO_REG32_BIT(VDC_OIR_SCL1_UPDATE_1,        	0xFCFF9F00,__READ_WRITE,__vdc_oir_scl1_update_bits);
__IO_REG32_BIT(VDC_OIR_SCL1_WR1_1,        		0xFCFF9F08,__READ_WRITE,__vdc_oir_scl_wr1_bits);
__IO_REG32(		 VDC_OIR_SCL1_WR2_1,        		0xFCFF9F0C,__READ_WRITE);
__IO_REG32_BIT(VDC_OIR_SCL1_WR3_1,        		0xFCFF9F10,__READ_WRITE,__vdc_oir_scl_wr3_bits);
__IO_REG32_BIT(VDC_OIR_SCL1_WR4_1,        		0xFCFF9F14,__READ_WRITE,__vdc_oir_scl_wr4_bits);
__IO_REG32_BIT(VDC_OIR_SCL1_WR5_1,        		0xFCFF9F1C,__READ_WRITE,__vdc_oir_scl_wr5_bits);
__IO_REG32_BIT(VDC_OIR_SCL1_WR6_1,        		0xFCFF9F20,__READ_WRITE,__vdc_oir_scl_wr6_bits);
__IO_REG32_BIT(VDC_OIR_SCL1_WR7_1,        		0xFCFF9F24,__READ			 ,__vdc_oir_scl_wr7_bits);
__IO_REG32_BIT(VDC_GR_OIR_UPDATE_1,        		0xFCFF9F80,__READ_WRITE,__vdc_gr_oir_update_bits);
__IO_REG32_BIT(VDC_GR_OIR_FLM_RD_1,        		0xFCFF9F84,__READ_WRITE,__vdc_gr_oir_flm_rd_bits);
__IO_REG32_BIT(VDC_GR_OIR_FLM1_1,        			0xFCFF9F88,__READ_WRITE,__vdc_gr_oir_flm1_bits);
__IO_REG32(		 VDC_GR_OIR_FLM2_1,        			0xFCFF9F8C,__READ_WRITE);
__IO_REG32_BIT(VDC_GR_OIR_FLM3_1,        			0xFCFF9F90,__READ_WRITE,__vdc_gr_oir_flm3_bits);
__IO_REG32_BIT(VDC_GR_OIR_FLM4_1,        			0xFCFF9F94,__READ_WRITE,__vdc_gr_oir_flm4_bits);
__IO_REG32_BIT(VDC_GR_OIR_FLM5_1,        			0xFCFF9F98,__READ_WRITE,__vdc_gr_oir_flm5_bits);
__IO_REG32_BIT(VDC_GR_OIR_FLM6_1,        			0xFCFF9F9C,__READ_WRITE,__vdc_gr_oir_flm6_bits);
__IO_REG32_BIT(VDC_GR_OIR_AB1_1,        			0xFCFF9FA0,__READ_WRITE,__vdc_gr_oir_ab1_bits);
__IO_REG32_BIT(VDC_GR_OIR_AB2_1,        			0xFCFF9FA4,__READ_WRITE,__vdc_gr_oir_ab2_bits);
__IO_REG32_BIT(VDC_GR_OIR_AB3_1,        			0xFCFF9FA8,__READ_WRITE,__vdc_gr_oir_ab3_bits);
__IO_REG32_BIT(VDC_GR_OIR_AB7_1,        			0xFCFF9FB8,__READ_WRITE,__vdc_gr_oir_ab7_bits);
__IO_REG32_BIT(VDC_GR_OIR_AB8_1,        			0xFCFF9FBC,__READ_WRITE,__vdc_gr_oir_ab8_bits);
__IO_REG32_BIT(VDC_GR_OIR_AB9_1,        			0xFCFF9FC0,__READ_WRITE,__vdc_gr_oir_ab9_bits);
__IO_REG32_BIT(VDC_GR_OIR_AB10_1,        			0xFCFF9FC4,__READ_WRITE,__vdc_gr_oir_ab10_bits);
__IO_REG32_BIT(VDC_GR_OIR_AB11_1,        			0xFCFF9FC8,__READ_WRITE,__vdc_gr_oir_ab11_bits);
__IO_REG32_BIT(VDC_GR_OIR_BASE_1,        			0xFCFF9FCC,__READ_WRITE,__vdc_gr_oir_base_bits);
__IO_REG32_BIT(VDC_GR_OIR_CLUT_1,        			0xFCFF9FD0,__READ_WRITE,__vdc_gr_oir_clut_bits);
__IO_REG32_BIT(VDC_GR_OIR_MON_1,        			0xFCFF9FD4,__READ			 ,__vdc_gr_oir_mon_bits);

/***************************************************************************
 **
 **  VDC GAM CH0 (Video Display Controller 5 Output Controller channel 0)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_GAM_G_UPDATE_0,        	 	0xFCFF7800,__READ_WRITE,__vdc_gam_update_bits);
__IO_REG32_BIT(VDC_GAM_G_SW_0,        	 			0xFCFF7804,__READ_WRITE,__vdc_gam_sw_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT1_0,        	 		0xFCFF7808,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT2_0,        	 		0xFCFF780C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT3_0,        	 		0xFCFF7810,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT4_0,        	 		0xFCFF7814,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT5_0,        	 		0xFCFF7818,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT6_0,        	 		0xFCFF781C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT7_0,        	 		0xFCFF7820,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT8_0,        	 		0xFCFF7824,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT9_0,        	 		0xFCFF7828,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT10_0,        	 		0xFCFF782C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT11_0,        	 		0xFCFF7830,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT12_0,        	 		0xFCFF7834,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT13_0,        	 		0xFCFF7838,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT14_0,        	 		0xFCFF783C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT15_0,        	 		0xFCFF7840,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT16_0,        	 		0xFCFF7844,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_AREA1_0,        	 		0xFCFF7848,__READ_WRITE,__vdc_gam_area1_bits);
__IO_REG32_BIT(VDC_GAM_G_AREA2_0,        	 		0xFCFF784C,__READ_WRITE,__vdc_gam_area2_bits);
__IO_REG32_BIT(VDC_GAM_G_AREA3_0,        	 		0xFCFF7850,__READ_WRITE,__vdc_gam_area3_bits);
__IO_REG32_BIT(VDC_GAM_G_AREA4_0,        	 		0xFCFF7854,__READ_WRITE,__vdc_gam_area4_bits);
__IO_REG32_BIT(VDC_GAM_G_AREA5_0,        	 		0xFCFF7858,__READ_WRITE,__vdc_gam_area5_bits);
__IO_REG32_BIT(VDC_GAM_G_AREA6_0,        	 		0xFCFF785C,__READ_WRITE,__vdc_gam_area6_bits);
__IO_REG32_BIT(VDC_GAM_G_AREA7_0,        	 		0xFCFF7860,__READ_WRITE,__vdc_gam_area7_bits);
__IO_REG32_BIT(VDC_GAM_G_AREA8_0,        	 		0xFCFF7864,__READ_WRITE,__vdc_gam_area8_bits);
__IO_REG32_BIT(VDC_GAM_B_UPDATE_0,        	 	0xFCFF7880,__READ_WRITE,__vdc_gam_update_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT1_0,        	 		0xFCFF7888,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT2_0,        	 		0xFCFF788C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT3_0,        	 		0xFCFF7890,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT4_0,        	 		0xFCFF7894,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT5_0,        	 		0xFCFF7898,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT6_0,        	 		0xFCFF789C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT7_0,        	 		0xFCFF78A0,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT8_0,        	 		0xFCFF78A4,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT9_0,        	 		0xFCFF78A8,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT10_0,        	 		0xFCFF78AC,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT11_0,        	 		0xFCFF78B0,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT12_0,        	 		0xFCFF78B4,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT13_0,        	 		0xFCFF78B8,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT14_0,        	 		0xFCFF78BC,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT15_0,        	 		0xFCFF78C0,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT16_0,        	 		0xFCFF78C4,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_AREA1_0,        	 		0xFCFF78C8,__READ_WRITE,__vdc_gam_area1_bits);
__IO_REG32_BIT(VDC_GAM_B_AREA2_0,        	 		0xFCFF78CC,__READ_WRITE,__vdc_gam_area2_bits);
__IO_REG32_BIT(VDC_GAM_B_AREA3_0,        	 		0xFCFF78D0,__READ_WRITE,__vdc_gam_area3_bits);
__IO_REG32_BIT(VDC_GAM_B_AREA4_0,        	 		0xFCFF78D4,__READ_WRITE,__vdc_gam_area4_bits);
__IO_REG32_BIT(VDC_GAM_B_AREA5_0,        	 		0xFCFF78D8,__READ_WRITE,__vdc_gam_area5_bits);
__IO_REG32_BIT(VDC_GAM_B_AREA6_0,        	 		0xFCFF78DC,__READ_WRITE,__vdc_gam_area6_bits);
__IO_REG32_BIT(VDC_GAM_B_AREA7_0,        	 		0xFCFF78E0,__READ_WRITE,__vdc_gam_area7_bits);
__IO_REG32_BIT(VDC_GAM_B_AREA8_0,        	 		0xFCFF78E4,__READ_WRITE,__vdc_gam_area8_bits);
__IO_REG32_BIT(VDC_GAM_R_UPDATE_0,        	 	0xFCFF7900,__READ_WRITE,__vdc_gam_update_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT1_0,        	 		0xFCFF7908,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT2_0,        	 		0xFCFF790C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT3_0,        	 		0xFCFF7910,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT4_0,        	 		0xFCFF7914,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT5_0,        	 		0xFCFF7918,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT6_0,        	 		0xFCFF791C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT7_0,        	 		0xFCFF7920,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT8_0,        	 		0xFCFF7924,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT9_0,        	 		0xFCFF7928,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT10_0,        	 		0xFCFF792C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT11_0,        	 		0xFCFF7930,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT12_0,        	 		0xFCFF7934,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT13_0,        	 		0xFCFF7938,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT14_0,        	 		0xFCFF793C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT15_0,        	 		0xFCFF7940,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT16_0,        	 		0xFCFF7944,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_AREA1_0,        	 		0xFCFF7948,__READ_WRITE,__vdc_gam_area1_bits);
__IO_REG32_BIT(VDC_GAM_R_AREA2_0,        	 		0xFCFF794C,__READ_WRITE,__vdc_gam_area2_bits);
__IO_REG32_BIT(VDC_GAM_R_AREA3_0,        	 		0xFCFF7950,__READ_WRITE,__vdc_gam_area3_bits);
__IO_REG32_BIT(VDC_GAM_R_AREA4_0,        	 		0xFCFF7954,__READ_WRITE,__vdc_gam_area4_bits);
__IO_REG32_BIT(VDC_GAM_R_AREA5_0,        	 		0xFCFF7958,__READ_WRITE,__vdc_gam_area5_bits);
__IO_REG32_BIT(VDC_GAM_R_AREA6_0,        	 		0xFCFF795C,__READ_WRITE,__vdc_gam_area6_bits);
__IO_REG32_BIT(VDC_GAM_R_AREA7_0,        	 		0xFCFF7960,__READ_WRITE,__vdc_gam_area7_bits);
__IO_REG32_BIT(VDC_GAM_R_AREA8_0,        	 		0xFCFF7964,__READ_WRITE,__vdc_gam_area8_bits);
__IO_REG32_BIT(VDC_TCON_UPDATE_0,        	 		0xFCFF7980,__READ_WRITE,__vdc_tcon_update_bits);
__IO_REG32_BIT(VDC_TCON_TIM_0,        	 			0xFCFF7984,__READ_WRITE,__vdc_tcon_tim_bits);
__IO_REG32_BIT(VDC_TCON_TIM_STVA1_0,        	0xFCFF7988,__READ_WRITE,__vdc_tcon_tim_stva1_bits);
__IO_REG32_BIT(VDC_TCON_TIM_STVA2_0,        	0xFCFF798C,__READ_WRITE,__vdc_tcon_tim_stva2_bits);
__IO_REG32_BIT(VDC_TCON_TIM_STVB1_0,        	0xFCFF7990,__READ_WRITE,__vdc_tcon_tim_stvb1_bits);
__IO_REG32_BIT(VDC_TCON_TIM_STVB2_0,        	0xFCFF7994,__READ_WRITE,__vdc_tcon_tim_stvb2_bits);
__IO_REG32_BIT(VDC_TCON_TIM_STH1_0,        	 	0xFCFF7998,__READ_WRITE,__vdc_tcon_tim_sth1_bits);
__IO_REG32_BIT(VDC_TCON_TIM_STH2_0,        	 	0xFCFF799C,__READ_WRITE,__vdc_tcon_tim_sth2_bits);
__IO_REG32_BIT(VDC_TCON_TIM_STB1_0,        	 	0xFCFF79A0,__READ_WRITE,__vdc_tcon_tim_stb1_bits);
__IO_REG32_BIT(VDC_TCON_TIM_STB2_0,        	 	0xFCFF79A4,__READ_WRITE,__vdc_tcon_tim_stb2_bits);
__IO_REG32_BIT(VDC_TCON_TIM_CPV1_0,        	 	0xFCFF79A8,__READ_WRITE,__vdc_tcon_tim_cpv1_bits);
__IO_REG32_BIT(VDC_TCON_TIM_CPV2_0,        	 	0xFCFF79AC,__READ_WRITE,__vdc_tcon_tim_cpv2_bits);
__IO_REG32_BIT(VDC_TCON_TIM_POLA1_0,        	0xFCFF79B0,__READ_WRITE,__vdc_tcon_tim_pola1_bits);
__IO_REG32_BIT(VDC_TCON_TIM_POLA2_0,        	0xFCFF79B4,__READ_WRITE,__vdc_tcon_tim_pola2_bits);
__IO_REG32_BIT(VDC_TCON_TIM_POLB1_0,        	0xFCFF79B8,__READ_WRITE,__vdc_tcon_tim_polb1_bits);
__IO_REG32_BIT(VDC_TCON_TIM_POLB2_0,        	0xFCFF79BC,__READ_WRITE,__vdc_tcon_tim_polb2_bits);
__IO_REG32_BIT(VDC_TCON_TIM_DE_0,        			0xFCFF79C0,__READ_WRITE,__vdc_tcon_tim_de_bits);
__IO_REG32_BIT(VDC_TCON_OUT_UPDATE_0,        	0xFCFF7A00,__READ_WRITE,__vdc_tcon_out_update_bits);
__IO_REG32_BIT(VDC_TCON_OUT_SET_0,        		0xFCFF7A04,__READ_WRITE,__vdc_tcon_out_set_bits);
__IO_REG32_BIT(VDC_TCON_OUT_BRIGHT1_0,        0xFCFF7A08,__READ_WRITE,__vdc_tcon_out_bright1_bits);
__IO_REG32_BIT(VDC_TCON_OUT_BRIGHT2_0,        0xFCFF7A0C,__READ_WRITE,__vdc_tcon_out_bright2_bits);
__IO_REG32_BIT(VDC_TCON_OUT_CONTRAST_0,       0xFCFF7A10,__READ_WRITE,__vdc_tcon_out_contrast_bits);
__IO_REG32_BIT(VDC_TCON_OUT_PDTHA_0,        	0xFCFF7A14,__READ_WRITE,__vdc_tcon_out_pdtha_bits);
__IO_REG32_BIT(VDC_TCON_OUT_CLK_PHASE_0,      0xFCFF7A24,__READ_WRITE,__vdc_tcon_out_clk_phase_bits);

/***************************************************************************
 **
 **  VDC GAM CH1 (Video Display Controller 5 Output Controller channel 1)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_GAM_G_UPDATE_1,        	 	0xFCFF9800,__READ_WRITE,__vdc_gam_update_bits);
__IO_REG32_BIT(VDC_GAM_G_SW_1,        	 			0xFCFF9804,__READ_WRITE,__vdc_gam_sw_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT1_1,        	 		0xFCFF9808,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT2_1,        	 		0xFCFF980C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT3_1,        	 		0xFCFF9810,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT4_1,        	 		0xFCFF9814,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT5_1,        	 		0xFCFF9818,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT6_1,        	 		0xFCFF981C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT7_1,        	 		0xFCFF9820,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT8_1,        	 		0xFCFF9824,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT9_1,        	 		0xFCFF9828,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT10_1,        	 		0xFCFF982C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT11_1,        	 		0xFCFF9830,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT12_1,        	 		0xFCFF9834,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT13_1,        	 		0xFCFF9838,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT14_1,        	 		0xFCFF983C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT15_1,        	 		0xFCFF9840,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_LUT16_1,        	 		0xFCFF9844,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_G_AREA1_1,        	 		0xFCFF9848,__READ_WRITE,__vdc_gam_area1_bits);
__IO_REG32_BIT(VDC_GAM_G_AREA2_1,        	 		0xFCFF984C,__READ_WRITE,__vdc_gam_area2_bits);
__IO_REG32_BIT(VDC_GAM_G_AREA3_1,        	 		0xFCFF9850,__READ_WRITE,__vdc_gam_area3_bits);
__IO_REG32_BIT(VDC_GAM_G_AREA4_1,        	 		0xFCFF9854,__READ_WRITE,__vdc_gam_area4_bits);
__IO_REG32_BIT(VDC_GAM_G_AREA5_1,        	 		0xFCFF9858,__READ_WRITE,__vdc_gam_area5_bits);
__IO_REG32_BIT(VDC_GAM_G_AREA6_1,        	 		0xFCFF985C,__READ_WRITE,__vdc_gam_area6_bits);
__IO_REG32_BIT(VDC_GAM_G_AREA7_1,        	 		0xFCFF9860,__READ_WRITE,__vdc_gam_area7_bits);
__IO_REG32_BIT(VDC_GAM_G_AREA8_1,        	 		0xFCFF9864,__READ_WRITE,__vdc_gam_area8_bits);
__IO_REG32_BIT(VDC_GAM_B_UPDATE_1,        	 	0xFCFF9880,__READ_WRITE,__vdc_gam_update_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT1_1,        	 		0xFCFF9888,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT2_1,        	 		0xFCFF988C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT3_1,        	 		0xFCFF9890,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT4_1,        	 		0xFCFF9894,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT5_1,        	 		0xFCFF9898,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT6_1,        	 		0xFCFF989C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT7_1,        	 		0xFCFF98A0,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT8_1,        	 		0xFCFF98A4,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT9_1,        	 		0xFCFF98A8,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT10_1,        	 		0xFCFF98AC,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT11_1,        	 		0xFCFF98B0,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT12_1,        	 		0xFCFF98B4,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT13_1,        	 		0xFCFF98B8,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT14_1,        	 		0xFCFF98BC,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT15_1,        	 		0xFCFF98C0,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_LUT16_1,        	 		0xFCFF98C4,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_B_AREA1_1,        	 		0xFCFF98C8,__READ_WRITE,__vdc_gam_area1_bits);
__IO_REG32_BIT(VDC_GAM_B_AREA2_1,        	 		0xFCFF98CC,__READ_WRITE,__vdc_gam_area2_bits);
__IO_REG32_BIT(VDC_GAM_B_AREA3_1,        	 		0xFCFF98D0,__READ_WRITE,__vdc_gam_area3_bits);
__IO_REG32_BIT(VDC_GAM_B_AREA4_1,        	 		0xFCFF98D4,__READ_WRITE,__vdc_gam_area4_bits);
__IO_REG32_BIT(VDC_GAM_B_AREA5_1,        	 		0xFCFF98D8,__READ_WRITE,__vdc_gam_area5_bits);
__IO_REG32_BIT(VDC_GAM_B_AREA6_1,        	 		0xFCFF98DC,__READ_WRITE,__vdc_gam_area6_bits);
__IO_REG32_BIT(VDC_GAM_B_AREA7_1,        	 		0xFCFF98E0,__READ_WRITE,__vdc_gam_area7_bits);
__IO_REG32_BIT(VDC_GAM_B_AREA8_1,        	 		0xFCFF98E4,__READ_WRITE,__vdc_gam_area8_bits);
__IO_REG32_BIT(VDC_GAM_R_UPDATE_1,        	 	0xFCFF9900,__READ_WRITE,__vdc_gam_update_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT1_1,        	 		0xFCFF9908,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT2_1,        	 		0xFCFF990C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT3_1,        	 		0xFCFF9910,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT4_1,        	 		0xFCFF9914,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT5_1,        	 		0xFCFF9918,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT6_1,        	 		0xFCFF991C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT7_1,        	 		0xFCFF9920,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT8_1,        	 		0xFCFF9924,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT9_1,        	 		0xFCFF9928,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT10_1,        	 		0xFCFF992C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT11_1,        	 		0xFCFF9930,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT12_1,        	 		0xFCFF9934,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT13_1,        	 		0xFCFF9938,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT14_1,        	 		0xFCFF993C,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT15_1,        	 		0xFCFF9940,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_LUT16_1,        	 		0xFCFF9944,__READ_WRITE,__vdc_gam_lut_bits);
__IO_REG32_BIT(VDC_GAM_R_AREA1_1,        	 		0xFCFF9948,__READ_WRITE,__vdc_gam_area1_bits);
__IO_REG32_BIT(VDC_GAM_R_AREA2_1,        	 		0xFCFF994C,__READ_WRITE,__vdc_gam_area2_bits);
__IO_REG32_BIT(VDC_GAM_R_AREA3_1,        	 		0xFCFF9950,__READ_WRITE,__vdc_gam_area3_bits);
__IO_REG32_BIT(VDC_GAM_R_AREA4_1,        	 		0xFCFF9954,__READ_WRITE,__vdc_gam_area4_bits);
__IO_REG32_BIT(VDC_GAM_R_AREA5_1,        	 		0xFCFF9958,__READ_WRITE,__vdc_gam_area5_bits);
__IO_REG32_BIT(VDC_GAM_R_AREA6_1,        	 		0xFCFF995C,__READ_WRITE,__vdc_gam_area6_bits);
__IO_REG32_BIT(VDC_GAM_R_AREA7_1,        	 		0xFCFF9960,__READ_WRITE,__vdc_gam_area7_bits);
__IO_REG32_BIT(VDC_GAM_R_AREA8_1,        	 		0xFCFF9964,__READ_WRITE,__vdc_gam_area8_bits);
__IO_REG32_BIT(VDC_TCON_UPDATE_1,        	 		0xFCFF9980,__READ_WRITE,__vdc_tcon_update_bits);
__IO_REG32_BIT(VDC_TCON_TIM_1,        	 			0xFCFF9984,__READ_WRITE,__vdc_tcon_tim_bits);
__IO_REG32_BIT(VDC_TCON_TIM_STVA1_1,        	0xFCFF9988,__READ_WRITE,__vdc_tcon_tim_stva1_bits);
__IO_REG32_BIT(VDC_TCON_TIM_STVA2_1,        	0xFCFF998C,__READ_WRITE,__vdc_tcon_tim_stva2_bits);
__IO_REG32_BIT(VDC_TCON_TIM_STVB1_1,        	0xFCFF9990,__READ_WRITE,__vdc_tcon_tim_stvb1_bits);
__IO_REG32_BIT(VDC_TCON_TIM_STVB2_1,        	0xFCFF9994,__READ_WRITE,__vdc_tcon_tim_stvb2_bits);
__IO_REG32_BIT(VDC_TCON_TIM_STH1_1,        	 	0xFCFF9998,__READ_WRITE,__vdc_tcon_tim_sth1_bits);
__IO_REG32_BIT(VDC_TCON_TIM_STH2_1,        	 	0xFCFF999C,__READ_WRITE,__vdc_tcon_tim_sth2_bits);
__IO_REG32_BIT(VDC_TCON_TIM_STB1_1,        	 	0xFCFF99A0,__READ_WRITE,__vdc_tcon_tim_stb1_bits);
__IO_REG32_BIT(VDC_TCON_TIM_STB2_1,        	 	0xFCFF99A4,__READ_WRITE,__vdc_tcon_tim_stb2_bits);
__IO_REG32_BIT(VDC_TCON_TIM_CPV1_1,        	 	0xFCFF99A8,__READ_WRITE,__vdc_tcon_tim_cpv1_bits);
__IO_REG32_BIT(VDC_TCON_TIM_CPV2_1,        	 	0xFCFF99AC,__READ_WRITE,__vdc_tcon_tim_cpv2_bits);
__IO_REG32_BIT(VDC_TCON_TIM_POLA1_1,        	0xFCFF99B0,__READ_WRITE,__vdc_tcon_tim_pola1_bits);
__IO_REG32_BIT(VDC_TCON_TIM_POLA2_1,        	0xFCFF99B4,__READ_WRITE,__vdc_tcon_tim_pola2_bits);
__IO_REG32_BIT(VDC_TCON_TIM_POLB1_1,        	0xFCFF99B8,__READ_WRITE,__vdc_tcon_tim_polb1_bits);
__IO_REG32_BIT(VDC_TCON_TIM_POLB2_1,        	0xFCFF99BC,__READ_WRITE,__vdc_tcon_tim_polb2_bits);
__IO_REG32_BIT(VDC_TCON_TIM_DE_1,        			0xFCFF99C0,__READ_WRITE,__vdc_tcon_tim_de_bits);
__IO_REG32_BIT(VDC_TCON_OUT_UPDATE_1,        	0xFCFF9A00,__READ_WRITE,__vdc_tcon_out_update_bits);
__IO_REG32_BIT(VDC_TCON_OUT_SET_1,        		0xFCFF9A04,__READ_WRITE,__vdc_tcon_out_set_bits);
__IO_REG32_BIT(VDC_TCON_OUT_BRIGHT1_1,        0xFCFF9A08,__READ_WRITE,__vdc_tcon_out_bright1_bits);
__IO_REG32_BIT(VDC_TCON_OUT_BRIGHT2_1,        0xFCFF9A0C,__READ_WRITE,__vdc_tcon_out_bright2_bits);
__IO_REG32_BIT(VDC_TCON_OUT_CONTRAST_1,       0xFCFF9A10,__READ_WRITE,__vdc_tcon_out_contrast_bits);
__IO_REG32_BIT(VDC_TCON_OUT_PDTHA_1,        	0xFCFF9A14,__READ_WRITE,__vdc_tcon_out_pdtha_bits);
__IO_REG32_BIT(VDC_TCON_OUT_CLK_PHASE_1,      0xFCFF9A24,__READ_WRITE,__vdc_tcon_out_clk_phase_bits);

/***************************************************************************
 **
 **  VDC SYSCNT CH0 (Video Display Controller 5 System controller, channel 0)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_SYSCNT_INT1_0,        	 		0xFCFF7A80,__READ_WRITE,__vdc_syscnt_int1_bits);
__IO_REG32_BIT(VDC_SYSCNT_INT2_0,        	 		0xFCFF7A84,__READ_WRITE,__vdc_syscnt_int2_bits);
__IO_REG32_BIT(VDC_SYSCNT_INT3_0,        	 		0xFCFF7A88,__READ_WRITE,__vdc_syscnt_int3_bits);
__IO_REG32_BIT(VDC_SYSCNT_INT4_0,        	 		0xFCFF7A8C,__READ_WRITE,__vdc_syscnt_int4_bits);
__IO_REG32_BIT(VDC_SYSCNT_INT5_0,        	 		0xFCFF7A90,__READ_WRITE,__vdc_syscnt_int5_bits);
__IO_REG32_BIT(VDC_SYSCNT_INT6_0,        	 		0xFCFF7A94,__READ_WRITE,__vdc_syscnt_int6_bits);
__IO_REG16_BIT(VDC_SYSCNT_PANEL_CLK_0,        0xFCFF7A98,__READ_WRITE,__vdc_syscnt_panel_clk_bits);
__IO_REG16_BIT(VDC_SYSCNT_CLUT_0,        	 		0xFCFF7A9A,__READ			 ,__vdc_syscnt_clut_bits);

/***************************************************************************
 **
 **  VDC SYSCNT CH1 (Video Display Controller 5 System controller, channel 1)
 **
 ***************************************************************************/
__IO_REG32_BIT(VDC_SYSCNT_INT1_1,        	 		0xFCFF9A80,__READ_WRITE,__vdc_syscnt_int1_bits);
__IO_REG32_BIT(VDC_SYSCNT_INT2_1,        	 		0xFCFF9A84,__READ_WRITE,__vdc_syscnt_int2_bits);
__IO_REG32_BIT(VDC_SYSCNT_INT3_1,        	 		0xFCFF9A88,__READ_WRITE,__vdc_syscnt_int3_bits);
__IO_REG32_BIT(VDC_SYSCNT_INT4_1,        	 		0xFCFF9A8C,__READ_WRITE,__vdc_syscnt_int4_bits);
__IO_REG32_BIT(VDC_SYSCNT_INT5_1,        	 		0xFCFF9A90,__READ_WRITE,__vdc_syscnt_int5_bits);
__IO_REG32_BIT(VDC_SYSCNT_INT6_1,        	 		0xFCFF9A94,__READ_WRITE,__vdc_syscnt_int6_bits);
__IO_REG16_BIT(VDC_SYSCNT_PANEL_CLK_1,        0xFCFF9A98,__READ_WRITE,__vdc_syscnt_panel_clk_bits);
__IO_REG16_BIT(VDC_SYSCNT_CLUT_1,        	 		0xFCFF9A9A,__READ			 ,__vdc_syscnt_clut_bits);

/***************************************************************************
 **
 **  CEU (Capture Engine Unit)
 **
 ***************************************************************************/
__IO_REG32_BIT(CEU_CAPSR,    			    	 		0xE8210000,__READ_WRITE,__ceu_capsr_bits);
__IO_REG32_BIT(CEU_CAPCR,        	 					0xE8210004,__READ_WRITE,__ceu_capcr_bits);
__IO_REG32_BIT(CEU_CAMCR,        	 					0xE8210008,__READ_WRITE,__ceu_camcr_bits);
__IO_REG32_BIT(CEU_CMCYR,        	 					0xE821000C,__READ_WRITE,__ceu_cmcyr_bits);
__IO_REG32_BIT(CEU_CAMOR,        	 					0xE8210010,__READ_WRITE,__ceu_camor_bits);
__IO_REG32_BIT(CEU_CAPWR,        	 					0xE8210014,__READ_WRITE,__ceu_capwr_bits);
__IO_REG32_BIT(CEU_CAIFR,        	 					0xE8210018,__READ_WRITE,__ceu_caifr_bits);
__IO_REG32_BIT(CEU_CRCNTR,        	 				0xE8210028,__READ_WRITE,__ceu_crcntr_bits);
__IO_REG32_BIT(CEU_CRCMPR,        	 				0xE821002C,__READ_WRITE,__ceu_crcmpr_bits);
__IO_REG32_BIT(CEU_CFLCR,        	 					0xE8210030,__READ_WRITE,__ceu_cflcr_bits);
__IO_REG32_BIT(CEU_CFSZR,        	 					0xE8210034,__READ_WRITE,__ceu_cfszr_bits);
__IO_REG32_BIT(CEU_CDWDR,        	 					0xE8210038,__READ_WRITE,__ceu_cdwdr_bits);
__IO_REG32(		 CEU_CDAYR,        	 					0xE821003C,__READ_WRITE);
__IO_REG32(		 CEU_CDACR,        	 					0xE8210040,__READ_WRITE);
__IO_REG32(		 CEU_CDBYR,        	 					0xE8210044,__READ_WRITE);
__IO_REG32(		 CEU_CDBCR,        	 					0xE8210048,__READ_WRITE);
__IO_REG32_BIT(CEU_CBDSR,        	 					0xE821004C,__READ_WRITE,__ceu_cbdsr_bits);
__IO_REG32_BIT(CEU_CFWCR,        	 					0xE821005C,__READ_WRITE,__ceu_cfwcr_bits);
__IO_REG32_BIT(CEU_CLFCR,        	 					0xE8210060,__READ_WRITE,__ceu_clfcr_bits);
__IO_REG32_BIT(CEU_CDOCR,        	 					0xE8210064,__READ_WRITE,__ceu_cdocr_bits);
__IO_REG32_BIT(CEU_CEIER,        	 					0xE8210070,__READ_WRITE,__ceu_ceier_bits);
__IO_REG32_BIT(CEU_CETCR,        	 					0xE8210074,__READ_WRITE,__ceu_cetcr_bits);
__IO_REG32_BIT(CEU_CSTSR,        	 					0xE821007C,__READ			 ,__ceu_cstsr_bits);
__IO_REG32(		 CEU_CDSSR,        	 					0xE8210084,__READ_WRITE);
__IO_REG32(		 CEU_CDAYR2,        	 				0xE8210090,__READ_WRITE);
__IO_REG32(		 CEU_CDACR2,        	 				0xE8210094,__READ_WRITE);
__IO_REG32(		 CEU_CDBYR2,        	 				0xE8210098,__READ_WRITE);
__IO_REG32(		 CEU_CDBCR2,        	 				0xE821009C,__READ_WRITE);

/***************************************************************************
 **
 **  DISCOM ch.0 (Display Out Comparison Unit)
 **
 ***************************************************************************/
__IO_REG32_BIT(DISCOM_DOCMCR_0,             0xFCFFA800,__READ_WRITE,__discom_docmcr_bits);
__IO_REG32_BIT(DISCOM_DOCMSTR_0,            0xFCFFA804,__READ      ,__discom_docmstr_bits);
__IO_REG32_BIT(DISCOM_DOCMCLSTR_0,          0xFCFFA808,__READ_WRITE,__discom_docmclstr_bits);
__IO_REG32_BIT(DISCOM_DOCMIENR_0,           0xFCFFA80C,__READ_WRITE,__discom_docmienr_bits);
__IO_REG32_BIT(DISCOM_DOCMPMR_0,            0xFCFFA814,__READ_WRITE,__discom_docmpmr_bits);
__IO_REG32(    DISCOM_DOCMECRCR_0,          0xFCFFA818,__READ_WRITE);
__IO_REG32(    DISCOM_DOCMCCRCR_0,          0xFCFFA81C,__READ      );
__IO_REG32_BIT(DISCOM_DOCMSPXR_0,           0xFCFFA820,__READ_WRITE,__discom_docmspxr_bits);
__IO_REG32_BIT(DISCOM_DOCMSPYR_0,           0xFCFFA824,__READ_WRITE,__discom_docmspyr_bits);
__IO_REG32_BIT(DISCOM_DOCMSZXR_0,           0xFCFFA828,__READ_WRITE,__discom_docmszxr_bits);
__IO_REG32_BIT(DISCOM_DOCMSZYR_0,           0xFCFFA82C,__READ_WRITE,__discom_docmszyr_bits);
__IO_REG32(    DISCOM_DOCMCRCIR_0,          0xFCFFA830,__READ_WRITE);

/***************************************************************************
 **
 **  DISCOM ch.1 (Display Out Comparison Unit)
 **
 ***************************************************************************/
__IO_REG32_BIT(DISCOM_DOCMCR_1,             0xFCFFB000,__READ_WRITE,__discom_docmcr_bits);
__IO_REG32_BIT(DISCOM_DOCMSTR_1,            0xFCFFB004,__READ      ,__discom_docmstr_bits);
__IO_REG32_BIT(DISCOM_DOCMCLSTR_1,          0xFCFFB008,__READ_WRITE,__discom_docmclstr_bits);
__IO_REG32_BIT(DISCOM_DOCMIENR_1,           0xFCFFB00C,__READ_WRITE,__discom_docmienr_bits);
__IO_REG32_BIT(DISCOM_DOCMPMR_1,            0xFCFFB014,__READ_WRITE,__discom_docmpmr_bits);
__IO_REG32(    DISCOM_DOCMECRCR_1,          0xFCFFB018,__READ_WRITE);
__IO_REG32(    DISCOM_DOCMCCRCR_1,          0xFCFFB01C,__READ      );
__IO_REG32_BIT(DISCOM_DOCMSPXR_1,           0xFCFFB020,__READ_WRITE,__discom_docmspxr_bits);
__IO_REG32_BIT(DISCOM_DOCMSPYR_1,           0xFCFFB024,__READ_WRITE,__discom_docmspyr_bits);
__IO_REG32_BIT(DISCOM_DOCMSZXR_1,           0xFCFFB028,__READ_WRITE,__discom_docmszxr_bits);
__IO_REG32_BIT(DISCOM_DOCMSZYR_1,           0xFCFFB02C,__READ_WRITE,__discom_docmszyr_bits);
__IO_REG32(    DISCOM_DOCMCRCIR_1,          0xFCFFB030,__READ_WRITE);

/***************************************************************************
 **
 **  JCU (JPEG Codec Unit)
 **
 ***************************************************************************/
__IO_REG8_BIT( JCU_JCMOD,                   0xE8017000,__READ_WRITE,__jcu_jcmod_bits);
__IO_REG8_BIT( JCU_JCCMD,                   0xE8017001,__READ_WRITE,__jcu_jccmd_bits);
__IO_REG8_BIT( JCU_JCQTN,                   0xE8017003,__READ_WRITE,__jcu_jcqtn_bits);
__IO_REG8_BIT( JCU_JCHTN,                   0xE8017004,__READ_WRITE,__jcu_jchtn_bits);
__IO_REG8(     JCU_JCDRIU,                  0xE8017005,__READ_WRITE);
__IO_REG8(     JCU_JCDRID,                  0xE8017006,__READ_WRITE);
__IO_REG8(     JCU_JCVSZU,                  0xE8017007,__READ_WRITE);
__IO_REG8(     JCU_JCVSZD,                  0xE8017008,__READ_WRITE);
__IO_REG8(     JCU_JCHSZU,                  0xE8017009,__READ_WRITE);
__IO_REG8(     JCU_JCHSZD,                  0xE801700A,__READ_WRITE);
__IO_REG8(     JCU_JCDTCU,                  0xE801700B,__READ      );
__IO_REG8(     JCU_JCDTCM,                  0xE801700C,__READ      );
__IO_REG8(     JCU_JCDTCD,                  0xE801700D,__READ      );
__IO_REG8_BIT( JCU_JINTE0,                  0xE801700E,__READ_WRITE,__jcu_jinte0_bits);
__IO_REG8_BIT( JCU_JINTS0,                  0xE801700F,__READ_WRITE,__jcu_jints0_bits);
__IO_REG8_BIT( JCU_JCDERR,                  0xE8017010,__READ_WRITE,__jcu_jcderr_bits);
__IO_REG8_BIT( JCU_JCRST,                   0xE8017011,__READ      ,__jcu_jcrst_bits);
__IO_REG32_BIT(JCU_JIFECNT,                 0xE8017040,__READ_WRITE,__jcu_jifecnt_bits);
__IO_REG32(    JCU_JIFESA,                  0xE8017044,__READ_WRITE);
__IO_REG32_BIT(JCU_JIFESOFST,               0xE8017048,__READ_WRITE,__jcu_jifesofst_bits);
__IO_REG32(    JCU_JIFEDA,                  0xE801704C,__READ_WRITE);
__IO_REG32_BIT(JCU_JIFESLC,                 0xE8017050,__READ_WRITE,__jcu_jifeslc_jifddlc_bits);
__IO_REG32_BIT(JCU_JIFEDDC,                 0xE8017054,__READ_WRITE,__jcu_jifeddc_jifdsdc_bits);
__IO_REG32_BIT(JCU_JIFDCNT,                 0xE8017058,__READ_WRITE,__jcu_jifdcnt_bits);
__IO_REG32(    JCU_JIFDSA,                  0xE801705C,__READ_WRITE);
__IO_REG32_BIT(JCU_JIFDDOFST,               0xE8017060,__READ_WRITE,__jcu_jifddofst_bits);
__IO_REG32(    JCU_JIFDDA,                  0xE8017064,__READ_WRITE);
__IO_REG32_BIT(JCU_JIFDSDC,                 0xE8017068,__READ_WRITE,__jcu_jifeddc_jifdsdc_bits);
__IO_REG32_BIT(JCU_JIFDDLC,                 0xE801706C,__READ_WRITE,__jcu_jifeslc_jifddlc_bits);
__IO_REG32_BIT(JCU_JIFDADT,                 0xE8017070,__READ_WRITE,__jcu_jifdadt_bits);
__IO_REG32_BIT(JCU_JINTE1,                  0xE801708C,__READ_WRITE,__jcu_jinte1_bits);
__IO_REG32_BIT(JCU_JINTS1,                  0xE8017090,__READ_WRITE,__jcu_jints1_bits);
__IO_REG32_BIT(JCU_JIFESVSZ,                0xE8017094,__READ_WRITE,__jcu_jifesvsz_bits);
__IO_REG32_BIT(JCU_JIFESHSZ,                0xE8017098,__READ_WRITE,__jcu_jifeshsz_bits);
__IO_REG8(     JCU_JCQTBL0,                 0xE8017100,__READ_WRITE);
__IO_REG8(     JCU_JCQTBL1,                 0xE8017140,__READ_WRITE);
__IO_REG8(     JCU_JCQTBL2,                 0xE8017180,__READ_WRITE);
__IO_REG8(     JCU_JCQTBL3,                 0xE80171C0,__READ_WRITE);
__IO_REG8(     JCU_JCHTBD0,                 0xE8017200,__WRITE     );
__IO_REG8(     JCU_JCHTBA0,                 0xE8017220,__WRITE     );
__IO_REG8(     JCU_JCHTBD1,                 0xE8017300,__WRITE     );
__IO_REG8(     JCU_JCHTBA1,                 0xE8017320,__WRITE     );

/***************************************************************************
 **
 **  PFV0 (Pixel Format Converter 0)
 **
 ***************************************************************************/
__IO_REG32_BIT(PFV0_PFVCR,                  0xE8205000,__READ_WRITE,__pfv_cr_bits);
__IO_REG32_BIT(PFV0_PFVICR,                 0xE8205004,__READ_WRITE,__pfv_icr_bits);
__IO_REG32_BIT(PFV0_PFVISR,                 0xE8205008,__READ      ,__pfv_isr_bits);
__IO_REG32_BIT(PFV0_PFVID,                  0xE8205020,__WRITE     ,__pfv_id_pfvod_bits);
#define PFV0_PFVID_H              PFV0_PFVID_bit.__halfword0
__IO_REG32_BIT(PFV0_PFVOD,                  0xE8205040,__READ_WRITE,__pfv_id_pfvod_bits);
#define PFV0_PFVOD_H              PFV0_PFVOD_bit.__halfword0
__IO_REG32_BIT(PFV0_PFVIFSR,                0xE8205064,__READ_WRITE,__pfv_ifsr_bits);
__IO_REG32_BIT(PFV0_PFVOFSR,                0xE8205068,__READ_WRITE,__pfv_ofsr_bits);
__IO_REG32_BIT(PFV0_PFVACR,                 0xE820506C,__READ_WRITE,__pfv_acr_bits);
__IO_REG32_BIT(PFV0_PFV_MTX_MODE,           0xE8205070,__READ_WRITE,__pfv_mtx_mode_bits);
__IO_REG32_BIT(PFV0_PFV_MTX_YG_ADJ0,        0xE8205074,__READ_WRITE,__pfv_mtx_yg_adj_bits);
__IO_REG32_BIT(PFV0_PFV_MTX_YG_ADJ1,        0xE8205078,__READ_WRITE,__pfv_mtx_yg_adj1_bits);
__IO_REG32_BIT(PFV0_PFV_MTX_CBB_ADJ0,       0xE820507C,__READ_WRITE,__pfv_mtx_cbb_adj_bits);
__IO_REG32_BIT(PFV0_PFV_MTX_CBB_ADJ1,       0xE8205080,__READ_WRITE,__pfv_mtx_cbb_adj1_bits);
__IO_REG32_BIT(PFV0_PFV_MTX_CRR_ADJ0,       0xE8205084,__READ_WRITE,__pfv_mtx_crr_adj_bits);
__IO_REG32_BIT(PFV0_PFV_MTX_CRR_ADJ1,       0xE8205088,__READ_WRITE,__pfv_mtx_crr_adj1_bits);
__IO_REG32_BIT(PFV0_PFVSZR,                 0xE820508C,__READ_WRITE,__pfv_szr_bits);

/***************************************************************************
 **
 **  PFV1 (Pixel Format Converter 1)
 **
 ***************************************************************************/
__IO_REG32_BIT(PFV1_PFVCR,                  0xE8205800,__READ_WRITE,__pfv_cr_bits);
__IO_REG32_BIT(PFV1_PFVICR,                 0xE8205804,__READ_WRITE,__pfv_icr_bits);
__IO_REG32_BIT(PFV1_PFVISR,                 0xE8205808,__READ      ,__pfv_isr_bits);
__IO_REG32_BIT(PFV1_PFVID,                  0xE8205820,__WRITE     ,__pfv_id_pfvod_bits);
#define PFV1_PFVID_H              PFV1_PFVID_bit.__halfword0
__IO_REG32_BIT(PFV1_PFVOD,                  0xE8205840,__READ_WRITE,__pfv_id_pfvod_bits);
#define PFV1_PFVOD_H              PFV1_PFVOD_bit.__halfword0
__IO_REG32_BIT(PFV1_PFVIFSR,                0xE8205864,__READ_WRITE,__pfv_ifsr_bits);
__IO_REG32_BIT(PFV1_PFVOFSR,                0xE8205868,__READ_WRITE,__pfv_ofsr_bits);
__IO_REG32_BIT(PFV1_PFVACR,                 0xE820586C,__READ_WRITE,__pfv_acr_bits);
__IO_REG32_BIT(PFV1_PFV_MTX_MODE,           0xE8205870,__READ_WRITE,__pfv_mtx_mode_bits);
__IO_REG32_BIT(PFV1_PFV_MTX_YG_ADJ0,        0xE8205874,__READ_WRITE,__pfv_mtx_yg_adj_bits);
__IO_REG32_BIT(PFV1_PFV_MTX_YG_ADJ1,        0xE8205878,__READ_WRITE,__pfv_mtx_yg_adj1_bits);
__IO_REG32_BIT(PFV1_PFV_MTX_CBB_ADJ0,       0xE820587C,__READ_WRITE,__pfv_mtx_cbb_adj_bits);
__IO_REG32_BIT(PFV1_PFV_MTX_CBB_ADJ1,       0xE8205880,__READ_WRITE,__pfv_mtx_cbb_adj1_bits);
__IO_REG32_BIT(PFV1_PFV_MTX_CRR_ADJ0,       0xE8205884,__READ_WRITE,__pfv_mtx_crr_adj_bits);
__IO_REG32_BIT(PFV1_PFV_MTX_CRR_ADJ1,       0xE8205888,__READ_WRITE,__pfv_mtx_crr_adj1_bits);
__IO_REG32_BIT(PFV1_PFVSZR,                 0xE820588C,__READ_WRITE,__pfv_szr_bits);

/***************************************************************************
 **
 **  SCUX (IPC0/OPC0)
 **
 ***************************************************************************/
__IO_REG32_BIT(SCUX_IPCIR_IPC0_0,           0xE8208000,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_IPSLR_IPC0_0,           0xE8208004,__READ_WRITE,__scux_ipslr_ipc0_bits);
__IO_REG32_BIT(SCUX_IPCIR_IPC0_1,           0xE8208100,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_IPSLR_IPC0_1,           0xE8208104,__READ_WRITE,__scux_ipslr_ipc0_bits);
__IO_REG32_BIT(SCUX_IPCIR_IPC0_2,           0xE8208200,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_IPSLR_IPC0_2,           0xE8208204,__READ_WRITE,__scux_ipslr_ipc0_bits);
__IO_REG32_BIT(SCUX_IPCIR_IPC0_3,           0xE8208300,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_IPSLR_IPC0_3,           0xE8208304,__READ_WRITE,__scux_ipslr_ipc0_bits);
__IO_REG32_BIT(SCUX_OPCIR_OPC0_0,           0xE8208400,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_OPSLR_OPC0_0,           0xE8208404,__READ_WRITE,__scux_opslr_opc0_bits);
__IO_REG32_BIT(SCUX_OPCIR_OPC0_1,           0xE8208500,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_OPSLR_OPC0_1,           0xE8208504,__READ_WRITE,__scux_opslr_opc0_bits);
__IO_REG32_BIT(SCUX_OPCIR_OPC0_2,           0xE8208600,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_OPSLR_OPC0_2,           0xE8208604,__READ_WRITE,__scux_opslr_opc0_bits);
__IO_REG32_BIT(SCUX_OPCIR_OPC0_3,           0xE8208700,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_OPSLR_OPC0_3,           0xE8208704,__READ_WRITE,__scux_opslr_opc0_bits);

/***************************************************************************
 **
 **  SCUX (FFD0)
 **
 ***************************************************************************/
__IO_REG32_BIT(SCUX_FFDIR_FFD0_0,           0xE8208800,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_FDAIR_FFD0_0,           0xE8208804,__READ_WRITE,__scux_chnumreg_bits);
__IO_REG32_BIT(SCUX_DRQSR_FFD0_0,           0xE8208808,__READ_WRITE,__scux_sizereg_bits);
__IO_REG32_BIT(SCUX_FFDPR_FFD0_0,           0xE820880C,__READ_WRITE,__scux_passreg_bits);
__IO_REG32_BIT(SCUX_FFDBR_FFD0_0,           0xE8208810,__READ_WRITE,__scux_ffdbr_ffd0_bits);
__IO_REG32_BIT(SCUX_DEVMR_FFD0_0,           0xE8208814,__READ_WRITE,__scux_devmr_ffd0_bits);
__IO_REG32_BIT(SCUX_DEVCR_FFD0_0,           0xE820881C,__READ_WRITE,__scux_devcr_ffd0_bits);
__IO_REG32_BIT(SCUX_FFDIR_FFD0_1,           0xE8208900,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_FDAIR_FFD0_1,           0xE8208904,__READ_WRITE,__scux_chnumreg_bits);
__IO_REG32_BIT(SCUX_DRQSR_FFD0_1,           0xE8208908,__READ_WRITE,__scux_sizereg_bits);
__IO_REG32_BIT(SCUX_FFDPR_FFD0_1,           0xE820890C,__READ_WRITE,__scux_passreg_bits);
__IO_REG32_BIT(SCUX_FFDBR_FFD0_1,           0xE8208910,__READ_WRITE,__scux_ffdbr_ffd0_bits);
__IO_REG32_BIT(SCUX_DEVMR_FFD0_1,           0xE8208914,__READ_WRITE,__scux_devmr_ffd0_bits);
__IO_REG32_BIT(SCUX_DEVCR_FFD0_1,           0xE820891C,__READ_WRITE,__scux_devcr_ffd0_bits);
__IO_REG32_BIT(SCUX_FFDIR_FFD0_2,           0xE8208A00,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_FDAIR_FFD0_2,           0xE8208A04,__READ_WRITE,__scux_chnumreg_bits);
__IO_REG32_BIT(SCUX_DRQSR_FFD0_2,           0xE8208A08,__READ_WRITE,__scux_sizereg_bits);
__IO_REG32_BIT(SCUX_FFDPR_FFD0_2,           0xE8208A0C,__READ_WRITE,__scux_passreg_bits);
__IO_REG32_BIT(SCUX_FFDBR_FFD0_2,           0xE8208A10,__READ_WRITE,__scux_ffdbr_ffd0_bits);
__IO_REG32_BIT(SCUX_DEVMR_FFD0_2,           0xE8208A14,__READ_WRITE,__scux_devmr_ffd0_bits);
__IO_REG32_BIT(SCUX_DEVCR_FFD0_2,           0xE8208A1C,__READ_WRITE,__scux_devcr_ffd0_bits);
__IO_REG32_BIT(SCUX_FFDIR_FFD0_3,           0xE8208B00,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_FDAIR_FFD0_3,           0xE8208B04,__READ_WRITE,__scux_chnumreg_bits);
__IO_REG32_BIT(SCUX_DRQSR_FFD0_3,           0xE8208B08,__READ_WRITE,__scux_sizereg_bits);
__IO_REG32_BIT(SCUX_FFDPR_FFD0_3,           0xE8208B0C,__READ_WRITE,__scux_passreg_bits);
__IO_REG32_BIT(SCUX_FFDBR_FFD0_3,           0xE8208B10,__READ_WRITE,__scux_ffdbr_ffd0_bits);
__IO_REG32_BIT(SCUX_DEVMR_FFD0_3,           0xE8208B14,__READ_WRITE,__scux_devmr_ffd0_bits);
__IO_REG32_BIT(SCUX_DEVCR_FFD0_3,           0xE8208B1C,__READ_WRITE,__scux_devcr_ffd0_bits);

/***************************************************************************
 **
 **  SCUX (FFU0)
 **
 ***************************************************************************/
__IO_REG32_BIT(SCUX_FFUIR_FFU0_0,           0xE8208C00,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_FUAIR_FFU0_0,           0xE8208C04,__READ_WRITE,__scux_chnumreg_bits);
__IO_REG32_BIT(SCUX_URQSR_FFU0_0,           0xE8208C08,__READ_WRITE,__scux_sizereg_bits);
__IO_REG32_BIT(SCUX_FFUPR_FFU0_0,           0xE8208C0C,__READ_WRITE,__scux_passreg_bits);
__IO_REG32_BIT(SCUX_UEVMR_FFU0_0,           0xE8208C10,__READ_WRITE,__scux_uevmr_ffu0_bits);
__IO_REG32_BIT(SCUX_UEVCR_FFU0_0,           0xE8208C18,__READ_WRITE,__scux_uevcr_ffu0_bits);
__IO_REG32_BIT(SCUX_FFUIR_FFU0_1,           0xE8208D00,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_FUAIR_FFU0_1,           0xE8208D04,__READ_WRITE,__scux_chnumreg_bits);
__IO_REG32_BIT(SCUX_URQSR_FFU0_1,           0xE8208D08,__READ_WRITE,__scux_sizereg_bits);
__IO_REG32_BIT(SCUX_FFUPR_FFU0_1,           0xE8208D0C,__READ_WRITE,__scux_passreg_bits);
__IO_REG32_BIT(SCUX_UEVMR_FFU0_1,           0xE8208D10,__READ_WRITE,__scux_uevmr_ffu0_bits);
__IO_REG32_BIT(SCUX_UEVCR_FFU0_1,           0xE8208D18,__READ_WRITE,__scux_uevcr_ffu0_bits);
__IO_REG32_BIT(SCUX_FFUIR_FFU0_2,           0xE8208E00,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_FUAIR_FFU0_2,           0xE8208E04,__READ_WRITE,__scux_chnumreg_bits);
__IO_REG32_BIT(SCUX_URQSR_FFU0_2,           0xE8208E08,__READ_WRITE,__scux_sizereg_bits);
__IO_REG32_BIT(SCUX_FFUPR_FFU0_2,           0xE8208E0C,__READ_WRITE,__scux_passreg_bits);
__IO_REG32_BIT(SCUX_UEVMR_FFU0_2,           0xE8208E10,__READ_WRITE,__scux_uevmr_ffu0_bits);
__IO_REG32_BIT(SCUX_UEVCR_FFU0_2,           0xE8208E18,__READ_WRITE,__scux_uevcr_ffu0_bits);
__IO_REG32_BIT(SCUX_FFUIR_FFU0_3,           0xE8208F00,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_FUAIR_FFU0_3,           0xE8208F04,__READ_WRITE,__scux_chnumreg_bits);
__IO_REG32_BIT(SCUX_URQSR_FFU0_3,           0xE8208F08,__READ_WRITE,__scux_sizereg_bits);
__IO_REG32_BIT(SCUX_FFUPR_FFU0_3,           0xE8208F0C,__READ_WRITE,__scux_passreg_bits);
__IO_REG32_BIT(SCUX_UEVMR_FFU0_3,           0xE8208F10,__READ_WRITE,__scux_uevmr_ffu0_bits);
__IO_REG32_BIT(SCUX_UEVCR_FFU0_3,           0xE8208F18,__READ_WRITE,__scux_uevcr_ffu0_bits);

/***************************************************************************
 **
 **  SCUX (SRC0/SRC1)
 **
 ***************************************************************************/
__IO_REG32_BIT(SCUX_SRCIR0_2SRC0_0,         0xE8209000,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_SADIR0_2SRC0_0,         0xE8209004,__READ_WRITE,__scux_otblchnumreg_bits);
__IO_REG32_BIT(SCUX_SRCBR0_2SRC0_0,         0xE8209008,__READ_WRITE,__scux_bypassreg_bits);
__IO_REG32_BIT(SCUX_IFSCR0_2SRC0_0,         0xE820900C,__READ_WRITE,__scux_ifscr_2src0_bits);
__IO_REG32_BIT(SCUX_IFSVR0_2SRC0_0,         0xE8209010,__READ_WRITE,__scux_ifsvr_2src0_bits);
__IO_REG32_BIT(SCUX_SRCCR0_2SRC0_0,         0xE8209014,__READ_WRITE,__scux_srccr_2src0_bits);
__IO_REG32_BIT(SCUX_MNFSR0_2SRC0_0,         0xE8209018,__READ_WRITE,__scux_mnfsr_2src0_bits);
__IO_REG32_BIT(SCUX_BFSSR0_2SRC0_0,         0xE820901C,__READ_WRITE,__scux_bfssr_2src0_bits);
__IO_REG32_BIT(SCUX_SC2SR0_2SRC0_0,         0xE8209020,__READ      ,__scux_sc2sr_2src0_bits);
__IO_REG32_BIT(SCUX_WATSR0_2SRC0_0,         0xE8209024,__READ_WRITE,__scux_watsr_2src0_bits);
__IO_REG32_BIT(SCUX_SEVMR0_2SRC0_0,         0xE8209028,__READ_WRITE,__scux_sevmr_2src0_bits);
__IO_REG32_BIT(SCUX_SEVCR0_2SRC0_0,         0xE8209030,__READ_WRITE,__scux_sevcr_2src0_bits);
__IO_REG32_BIT(SCUX_SRCIR1_2SRC0_0,         0xE8209034,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_SADIR1_2SRC0_0,         0xE8209038,__READ_WRITE,__scux_otblchnumreg_bits);
__IO_REG32_BIT(SCUX_SRCBR1_2SRC0_0,         0xE820903C,__READ_WRITE,__scux_bypassreg_bits);
__IO_REG32_BIT(SCUX_IFSCR1_2SRC0_0,         0xE8209040,__READ_WRITE,__scux_ifscr_2src0_bits);
__IO_REG32_BIT(SCUX_IFSVR1_2SRC0_0,         0xE8209044,__READ_WRITE,__scux_ifsvr_2src0_bits);
__IO_REG32_BIT(SCUX_SRCCR1_2SRC0_0,         0xE8209048,__READ_WRITE,__scux_srccr_2src0_bits);
__IO_REG32_BIT(SCUX_MNFSR1_2SRC0_0,         0xE820904C,__READ_WRITE,__scux_mnfsr_2src0_bits);
__IO_REG32_BIT(SCUX_BFSSR1_2SRC0_0,         0xE8209050,__READ_WRITE,__scux_bfssr_2src0_bits);
__IO_REG32_BIT(SCUX_SC2SR1_2SRC0_0,         0xE8209054,__READ      ,__scux_sc2sr_2src0_bits);
__IO_REG32_BIT(SCUX_WATSR1_2SRC0_0,         0xE8209058,__READ_WRITE,__scux_watsr_2src0_bits);
__IO_REG32_BIT(SCUX_SEVMR1_2SRC0_0,         0xE820905C,__READ_WRITE,__scux_sevmr_2src0_bits);
__IO_REG32_BIT(SCUX_SEVCR1_2SRC0_0,         0xE8209064,__READ_WRITE,__scux_sevcr_2src0_bits);
__IO_REG32_BIT(SCUX_SRCIRR_2SRC0_0,         0xE8209068,__READ_WRITE,__scux_initreg_bits);

/***************************************************************************
 **
 **  SCUX (SRC2/SRC3)
 **
 ***************************************************************************/
__IO_REG32_BIT(SCUX_SRCIR0_2SRC0_1,         0xE8209100,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_SADIR0_2SRC0_1,         0xE8209104,__READ_WRITE,__scux_otblchnumreg_bits);
__IO_REG32_BIT(SCUX_SRCBR0_2SRC0_1,         0xE8209108,__READ_WRITE,__scux_bypassreg_bits);
__IO_REG32_BIT(SCUX_IFSCR0_2SRC0_1,         0xE820910C,__READ_WRITE,__scux_ifscr_2src0_bits);
__IO_REG32_BIT(SCUX_IFSVR0_2SRC0_1,         0xE8209110,__READ_WRITE,__scux_ifsvr_2src0_bits);
__IO_REG32_BIT(SCUX_SRCCR0_2SRC0_1,         0xE8209114,__READ_WRITE,__scux_srccr_2src0_bits);
__IO_REG32_BIT(SCUX_MNFSR0_2SRC0_1,         0xE8209118,__READ_WRITE,__scux_mnfsr_2src0_bits);
__IO_REG32_BIT(SCUX_BFSSR0_2SRC0_1,         0xE820911C,__READ_WRITE,__scux_bfssr_2src0_bits);
__IO_REG32_BIT(SCUX_SC2SR0_2SRC0_1,         0xE8209120,__READ      ,__scux_sc2sr_2src0_bits);
__IO_REG32_BIT(SCUX_WATSR0_2SRC0_1,         0xE8209124,__READ_WRITE,__scux_watsr_2src0_bits);
__IO_REG32_BIT(SCUX_SEVMR0_2SRC0_1,         0xE8209128,__READ_WRITE,__scux_sevmr_2src0_bits);
__IO_REG32_BIT(SCUX_SEVCR0_2SRC0_1,         0xE8209130,__READ_WRITE,__scux_sevcr_2src0_bits);
__IO_REG32_BIT(SCUX_SRCIR1_2SRC0_1,         0xE8209134,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_SADIR1_2SRC0_1,         0xE8209138,__READ_WRITE,__scux_otblchnumreg_bits);
__IO_REG32_BIT(SCUX_SRCBR1_2SRC0_1,         0xE820913C,__READ_WRITE,__scux_bypassreg_bits);
__IO_REG32_BIT(SCUX_IFSCR1_2SRC0_1,         0xE8209140,__READ_WRITE,__scux_ifscr_2src0_bits);
__IO_REG32_BIT(SCUX_IFSVR1_2SRC0_1,         0xE8209144,__READ_WRITE,__scux_ifsvr_2src0_bits);
__IO_REG32_BIT(SCUX_SRCCR1_2SRC0_1,         0xE8209148,__READ_WRITE,__scux_srccr_2src0_bits);
__IO_REG32_BIT(SCUX_MNFSR1_2SRC0_1,         0xE820914C,__READ_WRITE,__scux_mnfsr_2src0_bits);
__IO_REG32_BIT(SCUX_BFSSR1_2SRC0_1,         0xE8209150,__READ_WRITE,__scux_bfssr_2src0_bits);
__IO_REG32_BIT(SCUX_SC2SR1_2SRC0_1,         0xE8209154,__READ      ,__scux_sc2sr_2src0_bits);
__IO_REG32_BIT(SCUX_WATSR1_2SRC0_1,         0xE8209158,__READ_WRITE,__scux_watsr_2src0_bits);
__IO_REG32_BIT(SCUX_SEVMR1_2SRC0_1,         0xE820915C,__READ_WRITE,__scux_sevmr_2src0_bits);
__IO_REG32_BIT(SCUX_SEVCR1_2SRC0_1,         0xE8209164,__READ_WRITE,__scux_sevcr_2src0_bits);
__IO_REG32_BIT(SCUX_SRCIRR_2SRC0_1,         0xE8209168,__READ_WRITE,__scux_initreg_bits);

/***************************************************************************
 **
 **  SCUX (DVU0_0)
 **
 ***************************************************************************/
__IO_REG32_BIT(SCUX_DVUIR_DVU0_0,           0xE8209200,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_VADIR_DVU0_0,           0xE8209204,__READ_WRITE,__scux_otblchnumreg_bits);
__IO_REG32_BIT(SCUX_DVUBR_DVU0_0,           0xE8209208,__READ_WRITE,__scux_bypassreg_bits);
__IO_REG32_BIT(SCUX_DVUCR_DVU0_0,           0xE820920C,__READ_WRITE,__scux_dvucr_dvu0_bits);
__IO_REG32_BIT(SCUX_ZCMCR_DVU0_0,           0xE8209210,__READ_WRITE,__scux_zcmcr_dvu0_bits);
__IO_REG32_BIT(SCUX_VRCTR_DVU0_0,           0xE8209214,__READ_WRITE,__scux_vrctr_dvu0_bits);
__IO_REG32_BIT(SCUX_VRPDR_DVU0_0,           0xE8209218,__READ_WRITE,__scux_vrpdr_dvu0_bits);
__IO_REG32_BIT(SCUX_VRDBR_DVU0_0,           0xE820921C,__READ_WRITE,__scux_vrdbr_dvu0_bits);
__IO_REG32_BIT(SCUX_VRWTR_DVU0_0,           0xE8209220,__READ_WRITE,__scux_vrwtr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL0R_DVU0_0,           0xE8209224,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL1R_DVU0_0,           0xE8209228,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL2R_DVU0_0,           0xE820922C,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL3R_DVU0_0,           0xE8209230,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL4R_DVU0_0,           0xE8209234,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL5R_DVU0_0,           0xE8209238,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL6R_DVU0_0,           0xE820923C,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL7R_DVU0_0,           0xE8209240,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_DVUER_DVU0_0,           0xE8209244,__READ_WRITE,__scux_dvuer_dvu0_bits);
__IO_REG32_BIT(SCUX_DVUSR_DVU0_0,           0xE8209248,__READ      ,__scux_dvusr_dvu0_bits);
__IO_REG32_BIT(SCUX_VEVMR_DVU0_0,           0xE820924C,__READ_WRITE,__scux_vevmr_dvu0_bits);
__IO_REG32_BIT(SCUX_VEVCR_DVU0_0,           0xE8209254,__READ_WRITE,__scux_vevcr_dvu0_bits);

/***************************************************************************
 **
 **  SCUX (DVU0_1)
 **
 ***************************************************************************/
__IO_REG32_BIT(SCUX_DVUIR_DVU0_1,           0xE8209300,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_VADIR_DVU0_1,           0xE8209304,__READ_WRITE,__scux_otblchnumreg_bits);
__IO_REG32_BIT(SCUX_DVUBR_DVU0_1,           0xE8209308,__READ_WRITE,__scux_bypassreg_bits);
__IO_REG32_BIT(SCUX_DVUCR_DVU0_1,           0xE820930C,__READ_WRITE,__scux_dvucr_dvu0_bits);
__IO_REG32_BIT(SCUX_ZCMCR_DVU0_1,           0xE8209310,__READ_WRITE,__scux_zcmcr_dvu0_bits);
__IO_REG32_BIT(SCUX_VRCTR_DVU0_1,           0xE8209314,__READ_WRITE,__scux_vrctr_dvu0_bits);
__IO_REG32_BIT(SCUX_VRPDR_DVU0_1,           0xE8209318,__READ_WRITE,__scux_vrpdr_dvu0_bits);
__IO_REG32_BIT(SCUX_VRDBR_DVU0_1,           0xE820931C,__READ_WRITE,__scux_vrdbr_dvu0_bits);
__IO_REG32_BIT(SCUX_VRWTR_DVU0_1,           0xE8209320,__READ_WRITE,__scux_vrwtr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL0R_DVU0_1,           0xE8209324,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL1R_DVU0_1,           0xE8209328,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL2R_DVU0_1,           0xE820932C,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL3R_DVU0_1,           0xE8209330,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL4R_DVU0_1,           0xE8209334,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL5R_DVU0_1,           0xE8209338,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL6R_DVU0_1,           0xE820933C,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL7R_DVU0_1,           0xE8209340,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_DVUER_DVU0_1,           0xE8209344,__READ_WRITE,__scux_dvuer_dvu0_bits);
__IO_REG32_BIT(SCUX_DVUSR_DVU0_1,           0xE8209348,__READ      ,__scux_dvusr_dvu0_bits);
__IO_REG32_BIT(SCUX_VEVMR_DVU0_1,           0xE820934C,__READ_WRITE,__scux_vevmr_dvu0_bits);
__IO_REG32_BIT(SCUX_VEVCR_DVU0_1,           0xE8209354,__READ_WRITE,__scux_vevcr_dvu0_bits);

/***************************************************************************
 **
 **  SCUX (DVU0_2)
 **
 ***************************************************************************/
__IO_REG32_BIT(SCUX_DVUIR_DVU0_2,           0xE8209400,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_VADIR_DVU0_2,           0xE8209404,__READ_WRITE,__scux_otblchnumreg_bits);
__IO_REG32_BIT(SCUX_DVUBR_DVU0_2,           0xE8209408,__READ_WRITE,__scux_bypassreg_bits);
__IO_REG32_BIT(SCUX_DVUCR_DVU0_2,           0xE820940C,__READ_WRITE,__scux_dvucr_dvu0_bits);
__IO_REG32_BIT(SCUX_ZCMCR_DVU0_2,           0xE8209410,__READ_WRITE,__scux_zcmcr_dvu0_bits);
__IO_REG32_BIT(SCUX_VRCTR_DVU0_2,           0xE8209414,__READ_WRITE,__scux_vrctr_dvu0_bits);
__IO_REG32_BIT(SCUX_VRPDR_DVU0_2,           0xE8209418,__READ_WRITE,__scux_vrpdr_dvu0_bits);
__IO_REG32_BIT(SCUX_VRDBR_DVU0_2,           0xE820941C,__READ_WRITE,__scux_vrdbr_dvu0_bits);
__IO_REG32_BIT(SCUX_VRWTR_DVU0_2,           0xE8209420,__READ_WRITE,__scux_vrwtr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL0R_DVU0_2,           0xE8209424,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL1R_DVU0_2,           0xE8209428,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL2R_DVU0_2,           0xE820942C,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL3R_DVU0_2,           0xE8209430,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL4R_DVU0_2,           0xE8209434,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL5R_DVU0_2,           0xE8209438,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL6R_DVU0_2,           0xE820943C,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL7R_DVU0_2,           0xE8209440,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_DVUER_DVU0_2,           0xE8209444,__READ_WRITE,__scux_dvuer_dvu0_bits);
__IO_REG32_BIT(SCUX_DVUSR_DVU0_2,           0xE8209448,__READ      ,__scux_dvusr_dvu0_bits);
__IO_REG32_BIT(SCUX_VEVMR_DVU0_2,           0xE820944C,__READ_WRITE,__scux_vevmr_dvu0_bits);
__IO_REG32_BIT(SCUX_VEVCR_DVU0_2,           0xE8209454,__READ_WRITE,__scux_vevcr_dvu0_bits);

/***************************************************************************
 **
 **  SCUX (DVU0_3)
 **
 ***************************************************************************/
__IO_REG32_BIT(SCUX_DVUIR_DVU0_3,           0xE8209500,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_VADIR_DVU0_3,           0xE8209504,__READ_WRITE,__scux_otblchnumreg_bits);
__IO_REG32_BIT(SCUX_DVUBR_DVU0_3,           0xE8209508,__READ_WRITE,__scux_bypassreg_bits);
__IO_REG32_BIT(SCUX_DVUCR_DVU0_3,           0xE820950C,__READ_WRITE,__scux_dvucr_dvu0_bits);
__IO_REG32_BIT(SCUX_ZCMCR_DVU0_3,           0xE8209510,__READ_WRITE,__scux_zcmcr_dvu0_bits);
__IO_REG32_BIT(SCUX_VRCTR_DVU0_3,           0xE8209514,__READ_WRITE,__scux_vrctr_dvu0_bits);
__IO_REG32_BIT(SCUX_VRPDR_DVU0_3,           0xE8209518,__READ_WRITE,__scux_vrpdr_dvu0_bits);
__IO_REG32_BIT(SCUX_VRDBR_DVU0_3,           0xE820951C,__READ_WRITE,__scux_vrdbr_dvu0_bits);
__IO_REG32_BIT(SCUX_VRWTR_DVU0_3,           0xE8209520,__READ_WRITE,__scux_vrwtr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL0R_DVU0_3,           0xE8209524,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL1R_DVU0_3,           0xE8209528,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL2R_DVU0_3,           0xE820952C,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL3R_DVU0_3,           0xE8209530,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL4R_DVU0_3,           0xE8209534,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL5R_DVU0_3,           0xE8209538,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL6R_DVU0_3,           0xE820953C,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_VOL7R_DVU0_3,           0xE8209540,__READ_WRITE,__scux_volxr_dvu0_bits);
__IO_REG32_BIT(SCUX_DVUER_DVU0_3,           0xE8209544,__READ_WRITE,__scux_dvuer_dvu0_bits);
__IO_REG32_BIT(SCUX_DVUSR_DVU0_3,           0xE8209548,__READ      ,__scux_dvusr_dvu0_bits);
__IO_REG32_BIT(SCUX_VEVMR_DVU0_3,           0xE820954C,__READ_WRITE,__scux_vevmr_dvu0_bits);
__IO_REG32_BIT(SCUX_VEVCR_DVU0_3,           0xE8209554,__READ_WRITE,__scux_vevcr_dvu0_bits);

/***************************************************************************
 **
 **  SCUX (MIX)
 **
 ***************************************************************************/
__IO_REG32_BIT(SCUX_MIXIR_MIX0_0,           0xE8209600,__READ_WRITE,__scux_initreg_bits);
__IO_REG32_BIT(SCUX_MADIR_MIX0_0,           0xE8209604,__READ_WRITE,__scux_chnumreg_bits);
__IO_REG32_BIT(SCUX_MIXBR_MIX0_0,           0xE8206608,__READ_WRITE,__scux_mixbr_mix0_bits);
__IO_REG32_BIT(SCUX_MIXMR_MIX0_0,           0xE820660C,__READ_WRITE,__scux_mixmr_mix0_bits);
__IO_REG32_BIT(SCUX_MVPDR_MIX0_0,           0xE8206610,__READ_WRITE,__scux_mvpdr_mix0_bits);
__IO_REG32_BIT(SCUX_MDBAR_MIX0_0,           0xE8206614,__READ_WRITE,__scux_mdbar_mix0_bits);
__IO_REG32_BIT(SCUX_MDBBR_MIX0_0,           0xE8206618,__READ_WRITE,__scux_mdbbr_mix0_bits);
__IO_REG32_BIT(SCUX_MDBCR_MIX0_0,           0xE820661C,__READ_WRITE,__scux_mdbcr_mix0_bits);
__IO_REG32_BIT(SCUX_MDBDR_MIX0_0,           0xE8206620,__READ_WRITE,__scux_mdbdr_mix0_bits);
__IO_REG32_BIT(SCUX_MDBER_MIX0_0,           0xE8206624,__READ_WRITE,__scux_mdber_mix0_bits);
__IO_REG32_BIT(SCUX_MIXSR_MIX0_0,           0xE8206628,__READ      ,__scux_mixsr_mix0_bits);

/***************************************************************************
 **
 **  SCUX (CIM)
 **
 ***************************************************************************/
__IO_REG32_BIT(SCUX_SWRSR_CIM,              0xE8206700,__READ_WRITE,__scux_swrsr_cim_bits);
__IO_REG32_BIT(SCUX_DMACR_CIM,              0xE8206704,__READ_WRITE,__scux_dmacr_cim_bits);
__IO_REG32(    SCUX_DMATD0_CIM,             0xE8206708,__WRITE     );
__IO_REG32(    SCUX_DMATD1_CIM,             0xE820670C,__WRITE     );
__IO_REG32(    SCUX_DMATD2_CIM,             0xE8206710,__WRITE     );
__IO_REG32(    SCUX_DMATD3_CIM,             0xE8206714,__WRITE     );
__IO_REG32(    SCUX_DMATU0_CIM,             0xE8206718,__READ      );
__IO_REG32(    SCUX_DMATU1_CIM,             0xE820671C,__READ      );
__IO_REG32(    SCUX_DMATU2_CIM,             0xE8206720,__READ      );
__IO_REG32(    SCUX_DMATU3_CIM,             0xE8206724,__READ      );
__IO_REG32_BIT(SCUX_SSIRSEL_CIM,            0xE8209738,__READ_WRITE,__scux_ssirsel_cim_bits);
__IO_REG32_BIT(SCUX_FDTSEL0_CIM,            0xE820973C,__READ_WRITE,__scux_fxtsel_cim_bits);
__IO_REG32_BIT(SCUX_FDTSEL1_CIM,            0xE8209740,__READ_WRITE,__scux_fxtsel_cim_bits);
__IO_REG32_BIT(SCUX_FDTSEL2_CIM,            0xE8209744,__READ_WRITE,__scux_fxtsel_cim_bits);
__IO_REG32_BIT(SCUX_FDTSEL3_CIM,            0xE8209748,__READ_WRITE,__scux_fxtsel_cim_bits);
__IO_REG32_BIT(SCUX_FUTSEL0_CIM,            0xE820974C,__READ_WRITE,__scux_fxtsel_cim_bits);
__IO_REG32_BIT(SCUX_FUTSEL1_CIM,            0xE8209750,__READ_WRITE,__scux_fxtsel_cim_bits);
__IO_REG32_BIT(SCUX_FUTSEL2_CIM,            0xE8209754,__READ_WRITE,__scux_fxtsel_cim_bits);
__IO_REG32_BIT(SCUX_FUTSEL3_CIM,            0xE8209758,__READ_WRITE,__scux_fxtsel_cim_bits);
__IO_REG32_BIT(SCUX_SSIPMD_CIM,             0xE820975C,__READ_WRITE,__scux_ssipmd_cim_bits);
__IO_REG32_BIT(SCUX_SSICTRL_CIM,            0xE8209760,__READ_WRITE,__scux_ssictrl_cim_bits);
__IO_REG32_BIT(SCUX_SRCRSEL0_CIM,           0xE8209764,__READ_WRITE,__scux_srcrsel_mixrsel_cim_bits);
__IO_REG32_BIT(SCUX_SRCRSEL1_CIM,           0xE8209768,__READ_WRITE,__scux_srcrsel_mixrsel_cim_bits);
__IO_REG32_BIT(SCUX_SRCRSEL2_CIM,           0xE820976C,__READ_WRITE,__scux_srcrsel_mixrsel_cim_bits);
__IO_REG32_BIT(SCUX_SRCRSEL3_CIM,           0xE8209770,__READ_WRITE,__scux_srcrsel_mixrsel_cim_bits);
__IO_REG32_BIT(SCUX_MIXRSEL_CIM,            0xE8209774,__READ_WRITE,__scux_srcrsel_mixrsel_cim_bits);

/***************************************************************************
 **
 **  SDG ch.0 (Sound Generator channel 0)
 **
 ***************************************************************************/
__IO_REG8_BIT( SDG_SGCR1_0,                 0xFCFF4800,__READ_WRITE,__sdg_sgcr1_bits);
__IO_REG8_BIT( SDG_SGCSR_0,                 0xFCFF4801,__READ_WRITE,__sdg_sgcsr_bits);
__IO_REG8_BIT( SDG_SGCR2_0,                 0xFCFF4802,__READ_WRITE,__sdg_sgcr2_bits);
__IO_REG8(     SDG_SGLR_0,                  0xFCFF4803,__READ_WRITE);
__IO_REG8_BIT( SDG_SGTFR_0,                 0xFCFF4804,__READ_WRITE,__sdg_sgtfr_bits);
__IO_REG8(     SDG_SGSFR_0,                 0xFCFF4805,__READ_WRITE);

/***************************************************************************
 **
 **  SDG ch.1 (Sound Generator channel 1)
 **
 ***************************************************************************/
__IO_REG8_BIT( SDG_SGCR1_1,                 0xFCFF4A00,__READ_WRITE,__sdg_sgcr1_bits);
__IO_REG8_BIT( SDG_SGCSR_1,                 0xFCFF4A01,__READ_WRITE,__sdg_sgcsr_bits);
__IO_REG8_BIT( SDG_SGCR2_1,                 0xFCFF4A02,__READ_WRITE,__sdg_sgcr2_bits);
__IO_REG8(     SDG_SGLR_1,                  0xFCFF4A03,__READ_WRITE);
__IO_REG8_BIT( SDG_SGTFR_1,                 0xFCFF4A04,__READ_WRITE,__sdg_sgtfr_bits);
__IO_REG8(     SDG_SGSFR_1,                 0xFCFF4A05,__READ_WRITE);

/***************************************************************************
 **
 **  SDG ch.2 (Sound Generator channel 2)
 **
 ***************************************************************************/
__IO_REG8_BIT( SDG_SGCR1_2,                 0xFCFF4C00,__READ_WRITE,__sdg_sgcr1_bits);
__IO_REG8_BIT( SDG_SGCSR_2,                 0xFCFF4C01,__READ_WRITE,__sdg_sgcsr_bits);
__IO_REG8_BIT( SDG_SGCR2_2,                 0xFCFF4C02,__READ_WRITE,__sdg_sgcr2_bits);
__IO_REG8(     SDG_SGLR_2,                  0xFCFF4C03,__READ_WRITE);
__IO_REG8_BIT( SDG_SGTFR_2,                 0xFCFF4C04,__READ_WRITE,__sdg_sgtfr_bits);
__IO_REG8(     SDG_SGSFR_2,                 0xFCFF4C05,__READ_WRITE);

/***************************************************************************
 **
 **  SDG ch.3 (Sound Generator channel 3)
 **
 ***************************************************************************/
__IO_REG8_BIT( SDG_SGCR1_3,                 0xFCFF4E00,__READ_WRITE,__sdg_sgcr1_bits);
__IO_REG8_BIT( SDG_SGCSR_3,                 0xFCFF4E01,__READ_WRITE,__sdg_sgcsr_bits);
__IO_REG8_BIT( SDG_SGCR2_3,                 0xFCFF4E02,__READ_WRITE,__sdg_sgcr2_bits);
__IO_REG8(     SDG_SGLR_3,                  0xFCFF4E03,__READ_WRITE);
__IO_REG8_BIT( SDG_SGTFR_3,                 0xFCFF4E04,__READ_WRITE,__sdg_sgtfr_bits);
__IO_REG8(     SDG_SGSFR_3,                 0xFCFF4E05,__READ_WRITE);

/***************************************************************************
 **
 **  MMC (MMC Host Interface)
 **
 ***************************************************************************/
__IO_REG32_BIT(MMC_CE_CMD_SET,              0xE804C800,__READ_WRITE,__mmc_ce_cmd_set_bits);
__IO_REG32(    MMC_CE_ARG,                  0xE804C808,__READ_WRITE);
__IO_REG32(    MMC_CE_ARG_CMD12,            0xE804C80C,__READ_WRITE);
__IO_REG32_BIT(MMC_CE_CMD_CTRL,             0xE804C810,__READ_WRITE,__mmc_ce_cmd_ctrl_bits);
__IO_REG32_BIT(MMC_CE_BLOCK_SET,            0xE804C814,__READ_WRITE,__mmc_ce_block_set_bits);
__IO_REG32_BIT(MMC_CE_CLK_CTRL,             0xE804C818,__READ_WRITE,__mmc_ce_clk_ctrl_bits);
__IO_REG32_BIT(MMC_CE_BUF_ACC,              0xE804C81C,__READ_WRITE,__mmc_ce_buf_acc_bits);
__IO_REG32(    MMC_CE_RESP3,                0xE804C820,__READ      );
__IO_REG32(    MMC_CE_RESP2,                0xE804C824,__READ      );
__IO_REG32(    MMC_CE_RESP1,                0xE804C828,__READ      );
__IO_REG32(    MMC_CE_RESP0,                0xE804C82C,__READ      );
__IO_REG32(    MMC_CE_RESP_CMD12,           0xE804C830,__READ      );
__IO_REG32(    MMC_CE_DATA,                 0xE804C834,__READ      );
__IO_REG32_BIT(MMC_CE_INT,                  0xE804C840,__READ_WRITE,__mmc_ce_int_bits);
__IO_REG32_BIT(MMC_CE_INT_EN,               0xE804C844,__READ_WRITE,__mmc_ce_int_en_bits);
__IO_REG32_BIT(MMC_CE_HOST_STS1,            0xE804C848,__READ      ,__mmc_ce_host_sts1_bits);
__IO_REG32_BIT(MMC_CE_HOST_STS2,            0xE804C84C,__READ      ,__mmc_ce_host_sts2_bits);
__IO_REG32_BIT(MMC_CE_DMA_MODE,             0xE804C85C,__READ_WRITE,__mmc_ce_dma_mode_bits);
__IO_REG32_BIT(MMC_CE_DETECT,               0xE804C870,__READ_WRITE,__mmc_ce_detect_bits);
__IO_REG32_BIT(MMC_CE_ADD_MODE,             0xE804C874,__READ_WRITE,__mmc_ce_add_mode_bits);
__IO_REG32_BIT(MMC_CE_VERSION,              0xE804C87C,__READ_WRITE,__mmc_ce_version_bits);

/***************************************************************************
 **
 **  PWM (Motor Control PWM Timer)
 **
 ***************************************************************************/
__IO_REG8_BIT( PWM_PWCR_1,                  0xFCFF50E0,__READ_WRITE,__pwm_pwcr_bits);
__IO_REG8_BIT( PWM_PWPR_1,                  0xFCFF50E4,__READ_WRITE,__pwm_pwpr_bits);
__IO_REG16(    PWM_PWCYR_1,                 0xFCFF50E6,__READ_WRITE);
__IO_REG16_BIT(PWM_PWBFR_1A,                0xFCFF50E8,__READ_WRITE,__pwm_pwbfr_bits);
__IO_REG16_BIT(PWM_PWBFR_1C,                0xFCFF50EA,__READ_WRITE,__pwm_pwbfr_bits);
__IO_REG16_BIT(PWM_PWBFR_1E,                0xFCFF50EC,__READ_WRITE,__pwm_pwbfr_bits);
__IO_REG16_BIT(PWM_PWBFR_1G,                0xFCFF50EE,__READ_WRITE,__pwm_pwbfr_bits);
__IO_REG8_BIT( PWM_PWCR_2,                  0xFCFF50F0,__READ_WRITE,__pwm_pwcr_bits);
__IO_REG8_BIT( PWM_PWPR_2,                  0xFCFF50F4,__READ_WRITE,__pwm_pwpr_bits);
__IO_REG16(    PWM_PWCYR_2,                 0xFCFF50F6,__READ_WRITE);
__IO_REG16_BIT(PWM_PWBFR_2A,                0xFCFF50F8,__READ_WRITE,__pwm_pwbfr_bits);
__IO_REG16_BIT(PWM_PWBFR_2C,                0xFCFF50FA,__READ_WRITE,__pwm_pwbfr_bits);
__IO_REG16_BIT(PWM_PWBFR_2E,                0xFCFF50FC,__READ_WRITE,__pwm_pwbfr_bits);
__IO_REG16_BIT(PWM_PWBFR_2G,                0xFCFF50FE,__READ_WRITE,__pwm_pwbfr_bits);
__IO_REG8_BIT( PWM_PWBTCR,                  0xFCFF5006,__READ_WRITE,__pwm_pwbtcr_bits);

/***************************************************************************
 **
 **  GPIO JTAG
 **
 ***************************************************************************/
__IO_REG16_BIT(GPIO_JPPR0,                  0xFCFE7B20,__READ      ,__gpio_ppr_bits);
__IO_REG16_BIT(GPIO_JPMC0,                  0xFCFE7B40,__READ_WRITE,__gpio_pmc_bits);
__IO_REG32_BIT(GPIO_JPMCSR0,                0xFCFE7B90,__READ_WRITE,__gpio_pmcsr_bits);
__IO_REG16_BIT(GPIO_JPIBC0,                 0xFCFE7F00,__READ_WRITE,__gpio_pibc_bits);

/***************************************************************************
 **
 **  GPIO SNCR
 **
 ***************************************************************************/
__IO_REG32_BIT(GPIO_SNCR,                   0xFCFE3C00,__READ_WRITE,__gpio_sncr_bits);

/***************************************************************************
 **
 **  GPIO P0
 **
 ***************************************************************************/
__IO_REG16_BIT(GPIO_PPR0,                   0xFCFE3200,__READ      ,__gpio_ppr_bits);
__IO_REG16_BIT(GPIO_PMC0,                   0xFCFE3400,__READ_WRITE,__gpio_pmc_bits);
__IO_REG32_BIT(GPIO_PMCSR0,                 0xFCFE3900,__READ_WRITE,__gpio_pmcsr_bits);
__IO_REG16_BIT(GPIO_PIBC0,                  0xFCFE7000,__READ_WRITE,__gpio_pibc_bits);

/***************************************************************************
 **
 **  GPIO P1
 **
 ***************************************************************************/
__IO_REG16_BIT(GPIO_P1,                     0xFCFE3004,__READ_WRITE,__gpio_p_bits);
__IO_REG32_BIT(GPIO_PSR1,                   0xFCFE3104,__READ_WRITE,__gpio_psr_bits);
__IO_REG16_BIT(GPIO_PPR1,                   0xFCFE3204,__READ      ,__gpio_ppr_bits);
__IO_REG16_BIT(GPIO_PM1,                    0xFCFE3304,__READ_WRITE,__gpio_pm_bits);
__IO_REG16_BIT(GPIO_PMC1,                   0xFCFE3404,__READ_WRITE,__gpio_pmc_bits);
__IO_REG16_BIT(GPIO_PFC1,                   0xFCFE3504,__READ_WRITE,__gpio_pfc_bits);
__IO_REG16_BIT(GPIO_PFCE1,                  0xFCFE3604,__READ_WRITE,__gpio_pfce_bits);
__IO_REG16(    GPIO_PNOT1,                  0xFCFE3704,__WRITE     );
__IO_REG32_BIT(GPIO_PMSR1,                  0xFCFE3804,__READ_WRITE,__gpio_pmsr_bits);
__IO_REG32_BIT(GPIO_PMCSR1,                 0xFCFE3904,__READ_WRITE,__gpio_pmcsr_bits);
__IO_REG16_BIT(GPIO_PFCAE1,                 0xFCFE3A04,__READ_WRITE,__gpio_pfcae_bits);
__IO_REG16_BIT(GPIO_PIBC1,                  0xFCFE7004,__READ_WRITE,__gpio_pibc_bits);
__IO_REG16_BIT(GPIO_PBDC1,                  0xFCFE7104,__READ_WRITE,__gpio_pbdc_bits);
__IO_REG16_BIT(GPIO_PIPC1,                  0xFCFE7204,__READ_WRITE,__gpio_pipc_bits);

/***************************************************************************
 **
 **  GPIO P2
 **
 ***************************************************************************/
__IO_REG16_BIT(GPIO_P2,                     0xFCFE3008,__READ_WRITE,__gpio_p_bits);
__IO_REG32_BIT(GPIO_PSR2,                   0xFCFE3108,__READ_WRITE,__gpio_psr_bits);
__IO_REG16_BIT(GPIO_PPR2,                   0xFCFE3208,__READ      ,__gpio_ppr_bits);
__IO_REG16_BIT(GPIO_PM2,                    0xFCFE3308,__READ_WRITE,__gpio_pm_bits);
__IO_REG16_BIT(GPIO_PMC2,                   0xFCFE3408,__READ_WRITE,__gpio_pmc_bits);
__IO_REG16_BIT(GPIO_PFC2,                   0xFCFE3508,__READ_WRITE,__gpio_pfc_bits);
__IO_REG16_BIT(GPIO_PFCE2,                  0xFCFE3608,__READ_WRITE,__gpio_pfce_bits);
__IO_REG16(    GPIO_PNOT2,                  0xFCFE3708,__WRITE     );
__IO_REG32_BIT(GPIO_PMSR2,                  0xFCFE3808,__READ_WRITE,__gpio_pmsr_bits);
__IO_REG32_BIT(GPIO_PMCRS2,                 0xFCFE3908,__READ_WRITE,__gpio_pmcsr_bits);
__IO_REG16_BIT(GPIO_PFCAE2,                 0xFCFE3A08,__READ_WRITE,__gpio_pfcae_bits);
__IO_REG16_BIT(GPIO_PIBC2,                  0xFCFE7008,__READ_WRITE,__gpio_pibc_bits);
__IO_REG16_BIT(GPIO_PBDC2,                  0xFCFE7108,__READ_WRITE,__gpio_pbdc_bits);
__IO_REG16_BIT(GPIO_PIPC2,                  0xFCFE7208,__READ_WRITE,__gpio_pipc_bits);

/***************************************************************************
 **
 **  GPIO P3
 **
 ***************************************************************************/
__IO_REG16_BIT(GPIO_P3,                     0xFCFE300C,__READ_WRITE,__gpio_p_bits);
__IO_REG32_BIT(GPIO_PSR3,                   0xFCFE310C,__READ_WRITE,__gpio_psr_bits);
__IO_REG16_BIT(GPIO_PPR3,                   0xFCFE320C,__READ      ,__gpio_ppr_bits);
__IO_REG16_BIT(GPIO_PM3,                    0xFCFE330C,__READ_WRITE,__gpio_pm_bits);
__IO_REG16_BIT(GPIO_PMC3,                   0xFCFE340C,__READ_WRITE,__gpio_pmc_bits);
__IO_REG16_BIT(GPIO_PFC3,                   0xFCFE350C,__READ_WRITE,__gpio_pfc_bits);
__IO_REG16_BIT(GPIO_PFCE3,                  0xFCFE360C,__READ_WRITE,__gpio_pfce_bits);
__IO_REG16(    GPIO_PNOT3,                  0xFCFE370C,__WRITE     );
__IO_REG32_BIT(GPIO_PMSR3,                  0xFCFE380C,__READ_WRITE,__gpio_pmsr_bits);
__IO_REG32_BIT(GPIO_PMCRS3,                 0xFCFE390C,__READ_WRITE,__gpio_pmcsr_bits);
__IO_REG16_BIT(GPIO_PFCAE3,                 0xFCFE3A0C,__READ_WRITE,__gpio_pfcae_bits);
__IO_REG16_BIT(GPIO_PIBC3,                  0xFCFE700C,__READ_WRITE,__gpio_pibc_bits);
__IO_REG16_BIT(GPIO_PBDC3,                  0xFCFE710C,__READ_WRITE,__gpio_pbdc_bits);
__IO_REG16_BIT(GPIO_PIPC3,                  0xFCFE720C,__READ_WRITE,__gpio_pipc_bits);

/***************************************************************************
 **
 **  GPIO P4
 **
 ***************************************************************************/
__IO_REG16_BIT(GPIO_P4,                     0xFCFE3010,__READ_WRITE,__gpio_p_bits);
__IO_REG32_BIT(GPIO_PSR4,                   0xFCFE3110,__READ_WRITE,__gpio_psr_bits);
__IO_REG16_BIT(GPIO_PPR4,                   0xFCFE3210,__READ      ,__gpio_ppr_bits);
__IO_REG16_BIT(GPIO_PM4,                    0xFCFE3310,__READ_WRITE,__gpio_pm_bits);
__IO_REG16_BIT(GPIO_PMC4,                   0xFCFE3410,__READ_WRITE,__gpio_pmc_bits);
__IO_REG16_BIT(GPIO_PFC4,                   0xFCFE3510,__READ_WRITE,__gpio_pfc_bits);
__IO_REG16_BIT(GPIO_PFCE4,                  0xFCFE3610,__READ_WRITE,__gpio_pfce_bits);
__IO_REG16(    GPIO_PNOT4,                  0xFCFE3710,__WRITE     );
__IO_REG32_BIT(GPIO_PMSR4,                  0xFCFE3810,__READ_WRITE,__gpio_pmsr_bits);
__IO_REG32_BIT(GPIO_PMCRS4,                 0xFCFE3910,__READ_WRITE,__gpio_pmcsr_bits);
__IO_REG16_BIT(GPIO_PFCAE4,                 0xFCFE3A10,__READ_WRITE,__gpio_pfcae_bits);
__IO_REG16_BIT(GPIO_PIBC4,                  0xFCFE7010,__READ_WRITE,__gpio_pibc_bits);
__IO_REG16_BIT(GPIO_PBDC4,                  0xFCFE7110,__READ_WRITE,__gpio_pbdc_bits);
__IO_REG16_BIT(GPIO_PIPC4,                  0xFCFE7210,__READ_WRITE,__gpio_pipc_bits);

/***************************************************************************
 **
 **  GPIO P5
 **
 ***************************************************************************/
__IO_REG16_BIT(GPIO_P5,                     0xFCFE3014,__READ_WRITE,__gpio_p_bits);
__IO_REG32_BIT(GPIO_PSR5,                   0xFCFE3114,__READ_WRITE,__gpio_psr_bits);
__IO_REG16_BIT(GPIO_PPR5,                   0xFCFE3214,__READ      ,__gpio_ppr_bits);
__IO_REG16_BIT(GPIO_PM5,                    0xFCFE3314,__READ_WRITE,__gpio_pm_bits);
__IO_REG16_BIT(GPIO_PMC5,                   0xFCFE3414,__READ_WRITE,__gpio_pmc_bits);
__IO_REG16_BIT(GPIO_PFC5,                   0xFCFE3514,__READ_WRITE,__gpio_pfc_bits);
__IO_REG16_BIT(GPIO_PFCE5,                  0xFCFE3614,__READ_WRITE,__gpio_pfce_bits);
__IO_REG16(    GPIO_PNOT5,                  0xFCFE3714,__WRITE     );
__IO_REG32_BIT(GPIO_PMSR5,                  0xFCFE3814,__READ_WRITE,__gpio_pmsr_bits);
__IO_REG32_BIT(GPIO_PMCRS5,                 0xFCFE3914,__READ_WRITE,__gpio_pmcsr_bits);
__IO_REG16_BIT(GPIO_PFCAE5,                 0xFCFE3A14,__READ_WRITE,__gpio_pfcae_bits);
__IO_REG16_BIT(GPIO_PIBC5,                  0xFCFE7014,__READ_WRITE,__gpio_pibc_bits);
__IO_REG16_BIT(GPIO_PBDC5,                  0xFCFE7114,__READ_WRITE,__gpio_pbdc_bits);
__IO_REG16_BIT(GPIO_PIPC5,                  0xFCFE7214,__READ_WRITE,__gpio_pipc_bits);

/***************************************************************************
 **
 **  GPIO P6
 **
 ***************************************************************************/
__IO_REG16_BIT(GPIO_P6,                     0xFCFE3018,__READ_WRITE,__gpio_p_bits);
__IO_REG32_BIT(GPIO_PSR6,                   0xFCFE3118,__READ_WRITE,__gpio_psr_bits);
__IO_REG16_BIT(GPIO_PPR6,                   0xFCFE3218,__READ      ,__gpio_ppr_bits);
__IO_REG16_BIT(GPIO_PM6,                    0xFCFE3318,__READ_WRITE,__gpio_pm_bits);
__IO_REG16_BIT(GPIO_PMC6,                   0xFCFE3418,__READ_WRITE,__gpio_pmc_bits);
__IO_REG16_BIT(GPIO_PFC6,                   0xFCFE3518,__READ_WRITE,__gpio_pfc_bits);
__IO_REG16_BIT(GPIO_PFCE6,                  0xFCFE3618,__READ_WRITE,__gpio_pfce_bits);
__IO_REG16(    GPIO_PNOT6,                  0xFCFE3718,__WRITE     );
__IO_REG32_BIT(GPIO_PMSR6,                  0xFCFE3818,__READ_WRITE,__gpio_pmsr_bits);
__IO_REG32_BIT(GPIO_PMCRS6,                 0xFCFE3918,__READ_WRITE,__gpio_pmcsr_bits);
__IO_REG16_BIT(GPIO_PFCAE6,                 0xFCFE3A18,__READ_WRITE,__gpio_pfcae_bits);
__IO_REG16_BIT(GPIO_PIBC6,                  0xFCFE7018,__READ_WRITE,__gpio_pibc_bits);
__IO_REG16_BIT(GPIO_PBDC6,                  0xFCFE7118,__READ_WRITE,__gpio_pbdc_bits);
__IO_REG16_BIT(GPIO_PIPC6,                  0xFCFE7218,__READ_WRITE,__gpio_pipc_bits);

/***************************************************************************
 **
 **  GPIO P7
 **
 ***************************************************************************/
__IO_REG16_BIT(GPIO_P7,                     0xFCFE301C,__READ_WRITE,__gpio_p_bits);
__IO_REG32_BIT(GPIO_PSR7,                   0xFCFE311C,__READ_WRITE,__gpio_psr_bits);
__IO_REG16_BIT(GPIO_PPR7,                   0xFCFE321C,__READ      ,__gpio_ppr_bits);
__IO_REG16_BIT(GPIO_PM7,                    0xFCFE331C,__READ_WRITE,__gpio_pm_bits);
__IO_REG16_BIT(GPIO_PMC7,                   0xFCFE341C,__READ_WRITE,__gpio_pmc_bits);
__IO_REG16_BIT(GPIO_PFC7,                   0xFCFE351C,__READ_WRITE,__gpio_pfc_bits);
__IO_REG16_BIT(GPIO_PFCE7,                  0xFCFE361C,__READ_WRITE,__gpio_pfce_bits);
__IO_REG16(    GPIO_PNOT7,                  0xFCFE371C,__WRITE     );
__IO_REG32_BIT(GPIO_PMSR7,                  0xFCFE381C,__READ_WRITE,__gpio_pmsr_bits);
__IO_REG32_BIT(GPIO_PMCRS7,                 0xFCFE391C,__READ_WRITE,__gpio_pmcsr_bits);
__IO_REG16_BIT(GPIO_PFCAE7,                 0xFCFE3A1C,__READ_WRITE,__gpio_pfcae_bits);
__IO_REG16_BIT(GPIO_PIBC7,                  0xFCFE701C,__READ_WRITE,__gpio_pibc_bits);
__IO_REG16_BIT(GPIO_PBDC7,                  0xFCFE711C,__READ_WRITE,__gpio_pbdc_bits);
__IO_REG16_BIT(GPIO_PIPC7,                  0xFCFE721C,__READ_WRITE,__gpio_pipc_bits);

/***************************************************************************
 **
 **  GPIO P8
 **
 ***************************************************************************/
__IO_REG16_BIT(GPIO_P8,                     0xFCFE3020,__READ_WRITE,__gpio_p_bits);
__IO_REG32_BIT(GPIO_PSR8,                   0xFCFE3120,__READ_WRITE,__gpio_psr_bits);
__IO_REG16_BIT(GPIO_PPR8,                   0xFCFE3220,__READ      ,__gpio_ppr_bits);
__IO_REG16_BIT(GPIO_PM8,                    0xFCFE3320,__READ_WRITE,__gpio_pm_bits);
__IO_REG16_BIT(GPIO_PMC8,                   0xFCFE3420,__READ_WRITE,__gpio_pmc_bits);
__IO_REG16_BIT(GPIO_PFC8,                   0xFCFE3520,__READ_WRITE,__gpio_pfc_bits);
__IO_REG16_BIT(GPIO_PFCE8,                  0xFCFE3620,__READ_WRITE,__gpio_pfce_bits);
__IO_REG16(    GPIO_PNOT8,                  0xFCFE3720,__WRITE     );
__IO_REG32_BIT(GPIO_PMSR8,                  0xFCFE3820,__READ_WRITE,__gpio_pmsr_bits);
__IO_REG32_BIT(GPIO_PMCRS8,                 0xFCFE3920,__READ_WRITE,__gpio_pmcsr_bits);
__IO_REG16_BIT(GPIO_PFCAE8,                 0xFCFE3A20,__READ_WRITE,__gpio_pfcae_bits);
__IO_REG16_BIT(GPIO_PIBC8,                  0xFCFE7020,__READ_WRITE,__gpio_pibc_bits);
__IO_REG16_BIT(GPIO_PBDC8,                  0xFCFE7120,__READ_WRITE,__gpio_pbdc_bits);
__IO_REG16_BIT(GPIO_PIPC8,                  0xFCFE7220,__READ_WRITE,__gpio_pipc_bits);

/***************************************************************************
 **
 **  GPIO P9
 **
 ***************************************************************************/
__IO_REG16_BIT(GPIO_P9,                     0xFCFE3024,__READ_WRITE,__gpio_p_bits);
__IO_REG32_BIT(GPIO_PSR9,                   0xFCFE3124,__READ_WRITE,__gpio_psr_bits);
__IO_REG16_BIT(GPIO_PPR9,                   0xFCFE3224,__READ      ,__gpio_ppr_bits);
__IO_REG16_BIT(GPIO_PM9,                    0xFCFE3324,__READ_WRITE,__gpio_pm_bits);
__IO_REG16_BIT(GPIO_PMC9,                   0xFCFE3424,__READ_WRITE,__gpio_pmc_bits);
__IO_REG16_BIT(GPIO_PFC9,                   0xFCFE3524,__READ_WRITE,__gpio_pfc_bits);
__IO_REG16_BIT(GPIO_PFCE9,                  0xFCFE3624,__READ_WRITE,__gpio_pfce_bits);
__IO_REG16(    GPIO_PNOT9,                  0xFCFE3724,__WRITE     );
__IO_REG32_BIT(GPIO_PMSR9,                  0xFCFE3824,__READ_WRITE,__gpio_pmsr_bits);
__IO_REG32_BIT(GPIO_PMCRS9,                 0xFCFE3924,__READ_WRITE,__gpio_pmcsr_bits);
__IO_REG16_BIT(GPIO_PFCAE9,                 0xFCFE3A24,__READ_WRITE,__gpio_pfcae_bits);
__IO_REG16_BIT(GPIO_PIBC9,                  0xFCFE7024,__READ_WRITE,__gpio_pibc_bits);
__IO_REG16_BIT(GPIO_PBDC9,                  0xFCFE7124,__READ_WRITE,__gpio_pbdc_bits);
__IO_REG16_BIT(GPIO_PIPC9,                  0xFCFE7224,__READ_WRITE,__gpio_pipc_bits);

/***************************************************************************
 **
 **  GPIO P10
 **
 ***************************************************************************/
__IO_REG16_BIT(GPIO_P10,                    0xFCFE3028,__READ_WRITE,__gpio_p_bits);
__IO_REG32_BIT(GPIO_PSR10,                  0xFCFE3128,__READ_WRITE,__gpio_psr_bits);
__IO_REG16_BIT(GPIO_PPR10,                  0xFCFE3228,__READ      ,__gpio_ppr_bits);
__IO_REG16_BIT(GPIO_PM10,                   0xFCFE3328,__READ_WRITE,__gpio_pm_bits);
__IO_REG16_BIT(GPIO_PMC10,                  0xFCFE3428,__READ_WRITE,__gpio_pmc_bits);
__IO_REG16_BIT(GPIO_PFC10,                  0xFCFE3528,__READ_WRITE,__gpio_pfc_bits);
__IO_REG16_BIT(GPIO_PFCE10,                 0xFCFE3628,__READ_WRITE,__gpio_pfce_bits);
__IO_REG16(    GPIO_PNOT10,                 0xFCFE3728,__WRITE     );
__IO_REG32_BIT(GPIO_PMSR10,                 0xFCFE3828,__READ_WRITE,__gpio_pmsr_bits);
__IO_REG32_BIT(GPIO_PMCRS10,                0xFCFE3928,__READ_WRITE,__gpio_pmcsr_bits);
__IO_REG16_BIT(GPIO_PFCAE10,                0xFCFE3A28,__READ_WRITE,__gpio_pfcae_bits);
__IO_REG16_BIT(GPIO_PIBC10,                 0xFCFE7028,__READ_WRITE,__gpio_pibc_bits);
__IO_REG16_BIT(GPIO_PBDC10,                 0xFCFE7128,__READ_WRITE,__gpio_pbdc_bits);
__IO_REG16_BIT(GPIO_PIPC10,                 0xFCFE7228,__READ_WRITE,__gpio_pipc_bits);

/***************************************************************************
 **
 **  GPIO P11
 **
 ***************************************************************************/
__IO_REG16_BIT(GPIO_P11,                    0xFCFE302C,__READ_WRITE,__gpio_p_bits);
__IO_REG32_BIT(GPIO_PSR11,                  0xFCFE312C,__READ_WRITE,__gpio_psr_bits);
__IO_REG16_BIT(GPIO_PPR11,                  0xFCFE322C,__READ      ,__gpio_ppr_bits);
__IO_REG16_BIT(GPIO_PM11,                   0xFCFE332C,__READ_WRITE,__gpio_pm_bits);
__IO_REG16_BIT(GPIO_PMC11,                  0xFCFE342C,__READ_WRITE,__gpio_pmc_bits);
__IO_REG16_BIT(GPIO_PFC11,                  0xFCFE352C,__READ_WRITE,__gpio_pfc_bits);
__IO_REG16_BIT(GPIO_PFCE11,                 0xFCFE362C,__READ_WRITE,__gpio_pfce_bits);
__IO_REG16(    GPIO_PNOT11,                 0xFCFE372C,__WRITE     );
__IO_REG32_BIT(GPIO_PMSR11,                 0xFCFE382C,__READ_WRITE,__gpio_pmsr_bits);
__IO_REG32_BIT(GPIO_PMCRS11,                0xFCFE392C,__READ_WRITE,__gpio_pmcsr_bits);
__IO_REG16_BIT(GPIO_PFCAE11,                0xFCFE3A2C,__READ_WRITE,__gpio_pfcae_bits);
__IO_REG16_BIT(GPIO_PIBC11,                 0xFCFE702C,__READ_WRITE,__gpio_pibc_bits);
__IO_REG16_BIT(GPIO_PBDC11,                 0xFCFE712C,__READ_WRITE,__gpio_pbdc_bits);
__IO_REG16_BIT(GPIO_PIPC11,                 0xFCFE722C,__READ_WRITE,__gpio_pipc_bits);


/* Assembler specific declarations  ****************************************/

#ifdef __IAR_SYSTEMS_ASM__

#endif    /* __IAR_SYSTEMS_ASM__ */

/***************************************************************************
 **
 **  Interrupt vector table
 **
 ***************************************************************************/
#define RESETV        0x00  /* Reset                                       */
#define UNDEFV        0x04  /* Undefined instruction                       */
#define SWIV          0x08  /* Software interrupt                          */
#define PABORTV       0x0c  /* Prefetch abort                              */
#define DABORTV       0x10  /* Data abort                                  */
#define IRQV          0x18  /* Normal interrupt                            */
#define FIQV          0x1c  /* Fast interrupt                              */

/***************************************************************************
 **
 **   Renesas R7S721001 interrupt sources
 **
 ***************************************************************************/
#define INT_SW0                 0              /* GIC Software Interrupt */
#define INT_SW1                 1
#define INT_SW2                 2
#define INT_SW3                 3
#define INT_SW4                 4
#define INT_SW5                 5
#define INT_SW6                 6
#define INT_SW7                 7
#define INT_SW8                 8
#define INT_SW9                 9
#define INT_SW10               10
#define INT_SW11               11
#define INT_SW12               12
#define INT_SW13               13
#define INT_SW14               14
#define INT_SW15               15
#define INT_PMUIRQ0            16             /* CPU */
#define INT_COMMRX0            17
#define INT_COMMTX0            18
#define INT_CTIIRQ0            19
#define INT_IRQ0               32             /* IRQ */
#define INT_IRQ1               33
#define INT_IRQ2               34
#define INT_IRQ3               35
#define INT_IRQ4               36
#define INT_IRQ5               37
#define INT_IRQ6               38
#define INT_IRQ7               39
#define INT_PL310ERR           40             /* Secondary cache */
#define INT_DMAINT0            41             /* Direct Memory Access controller channel 0 */
#define INT_DMAINT1            42             /* Direct Memory Access controller channel 1 */
#define INT_DMAINT2            43             /* Direct Memory Access controller channel 2 */
#define INT_DMAINT3            44             /* Direct Memory Access controller channel 3 */
#define INT_DMAINT4            45             /* Direct Memory Access controller channel 4 */
#define INT_DMAINT5            46             /* Direct Memory Access controller channel 5 */
#define INT_DMAINT6            47             /* Direct Memory Access controller channel 6 */
#define INT_DMAINT7            48             /* Direct Memory Access controller channel 7 */
#define INT_DMAINT8            49             /* Direct Memory Access controller channel 8 */
#define INT_DMAINT9            50             /* Direct Memory Access controller channel 9 */
#define INT_DMAINT10           51             /* Direct Memory Access controller channel 10 */
#define INT_DMAINT11           52             /* Direct Memory Access controller channel 11 */
#define INT_DMAINT12           53             /* Direct Memory Access controller channel 12 */
#define INT_DMAINT13           54             /* Direct Memory Access controller channel 13 */
#define INT_DMAINT14           55             /* Direct Memory Access controller channel 14 */
#define INT_DMAINT15           56             /* Direct Memory Access controller channel 15 */
#define INT_DMAERR             57
#define INT_USBI0              73             /* USB 2.0 Host/Function Module channel 0 */
#define INT_USBI1              74             /* USB 2.0 Host/Function Module channel 1 */
#define INT_S0_VI_VSYNC0       75             /* Video Display Controller 5 channel 0 */
#define INT_S0_LO_VSYNC0       76
#define INT_S0_VSYNCERR0       77
#define INT_GR3_VLINE0         78
#define INT_S0_VFIELD0         79
#define INT_IV1_VBUFERR0       80
#define INT_IV3_VBUFERR0       81
#define INT_IV5_VBUFERR0       82
#define INT_IV6_VBUFERR0       83
#define INT_S0_WLINE0          84
#define INT_S1_VI_VSYNC0       85
#define INT_S1_LO_VSYNC0       86
#define INT_S1_VSYNCERR0       87
#define INT_S1_VFIELD0         88
#define INT_IV2_VBUFERR0       89
#define INT_IV4_VBUFFER0       90
#define INT_S1_WLINE0          91
#define INT_OIR_VI_VSYNC0      92
#define INT_OIR_LO_VSYNC0      93
#define INT_OIR_VSYNCERR0      94
#define INT_OIR_VFIELD0        95
#define INT_IV7_VBUFFER0       96
#define INT_IV8_VBUFFER0       97
#define INT_OIR_WLINE0         98
#define INT_S0_VI_VSYNC1       99             /* Video Display Controller 5 channel 1 */
#define INT_S0_LO_VSYNC1      100
#define INT_S0_VSYNCERR1      101
#define INT_GR3_VLINE1        102
#define INT_S0_VFIELD1        103
#define INT_IV1_VBUFERR1      104
#define INT_IV3_VBUFERR1      105
#define INT_IV5_VBUFERR1      106
#define INT_IV6_VBUFERR1      107
#define INT_S0_WLINE1         108
#define INT_S1_VI_VSYNC1      109
#define INT_S1_LO_VSYNC1      110
#define INT_S1_VSYNCERR1      111
#define INT_S1_VFIELD1        112
#define INT_IV2_VBUFERR1      113
#define INT_IV4_VBUFERR1      114
#define INT_S1_WLINE1         115
#define INT_OIR_VI_VSYNC1     116
#define INT_OIR_LO_VSYNC1     117
#define INT_OIR_VLINE1        118
#define INT_OIR_VFIELD1       119
#define INT_IV7_VBUFERR1      120
#define INT_IV8_VBUFERR1      121
#define INT_OIR_WLINE1        122
#define INT_IMRDI             123             /* Image Renderer */
#define INT_IMR2I0            124             /* Image Renderer channel 0 */
#define INT_IMR2I1            125             /* Image Renderer channel 1 */
#define INT_JEDI              126             /* JPEG Codec Unit */
#define INT_JDTI              127
#define INT_CMP0              128             /* Display Out Comparison Unit channel 0 */
#define INT_CMP1              129             /* Display Out Comparison Unit channel 1 */
#define INT_INT0              130             /* OpenVG-compilant Renesas Graphics Processor */
#define INT_INT1              131
#define INT_INT2              132
#define INT_INT3              133
#define INT_OSTMI0            134             /* OS Timer channel 0 */
#define INT_OSTMI1            135             /* OS Timer channel 1 */
#define INT_CMI               136             /* Bus State Controller */
#define INT_WTOUT             137
#define INT_ITI               138             /* Watchdog Timer */
#define INT_TGI0A             139             /* Multi-function Timer Pulse Unit 2 channel 0 */
#define INT_TGI0B             140
#define INT_TGI0C             141
#define INT_TGI0D             142
#define INT_TGI0V             143
#define INT_TGI0E             144
#define INT_TGI0F             145
#define INT_TGI1A             146             /* Multi-function Timer Pulse Unit 2 channel 1 */
#define INT_TGI1B             147
#define INT_TGI1V             148
#define INT_TGI1U             149
#define INT_TGI2A             150             /* Multi-function Timer Pulse Unit 2 channel 2 */
#define INT_TGI2B             151
#define INT_TGI2V             152
#define INT_TGI2U             153
#define INT_TGI3A             154             /* Multi-function Timer Pulse Unit 2 channel 3 */
#define INT_TGI3B             155
#define INT_TGI3C             156
#define INT_TGI3D             157
#define INT_TGI3V             158
#define INT_TGI4A             159             /* Multi-function Timer Pulse Unit 2 channel 4 */
#define INT_TGI4B             160
#define INT_TGI4C             161
#define INT_TGI4D             162
#define INT_TGI4V             163
#define INT_CMI1              164             /* Motor Control PWM Timer */
#define INT_CMI2              165
#define INT_SGDEI0            166             /* Sound Generator channel 0 */
#define INT_SGDEI1            167             /* Sound Generator channel 1 */
#define INT_SGDEI2            168             /* Sound Generator channel 2 */
#define INT_SGDEI3            169             /* Sound Generator channel 3 */
#define INT_ADI               170             /* 12-bit A/D Converter */
#define INT_ADWAR             171
#define INT_SSII0             172             /* Serial Sound Interface channel 0 */
#define INT_SSIRXI0           173
#define INT_SSITXI0           174
#define INT_SSII1             175             /* Serial Sound Interface channel 1 */
#define INT_SSIRXI1           176
#define INT_SSITXI1           177
#define INT_SSII2             178             /* Serial Sound Interface channel 2 */
#define INT_SSIRTI2           179
#define INT_SSII3             180             /* Serial Sound Interface channel 3 */
#define INT_SSIRXI3           181
#define INT_SSITXI3           182
#define INT_SSII4             183             /* Serial Sound Interface channel 4 */
#define INT_SSIRTI4           184
#define INT_SSII5             185             /* Serial Sound Interface channel 5 */
#define INT_SSIRXI5           186
#define INT_SSITXI5           187
#define INT_SPDIFI            188             /* Renesas SPDIF Interface */
#define INT_TEI0              189             /* Renesas I2C Bus Interface channel 0 */
#define INT_RI0               190
#define INT_TI0               191
#define INT_SPI0              192
#define INT_STI0              193
#define INT_NAKI0             194
#define INT_ALI0              195
#define INT_TMOI0             196
#define INT_TEI1              197             /* Renesas I2C Bus Interface channel 1 */
#define INT_RI1               198
#define INT_TI1               199
#define INT_SPI1              200
#define INT_STI1              201
#define INT_NAKI1             202
#define INT_ALI1              203
#define INT_TMOI1             204
#define INT_TEI2              205             /* Renesas I2C Bus Interface channel 2 */
#define INT_RI2               206
#define INT_TI2               207
#define INT_SPI2              208
#define INT_STI2              209
#define INT_NAKI2             210
#define INT_ALI2              211
#define INT_TMOI2             212
#define INT_TEI3              213             /* Renesas I2C Bus Interface channel 3 */
#define INT_RI3               214
#define INT_TI3               215
#define INT_SPI3              216
#define INT_STI3              217
#define INT_NAKI3             218
#define INT_ALI3              219
#define INT_TMOI3             220
#define INT_BRI0              221             /* Serial Communication Interface with FIFO channel 0 */
#define INT_ERI0              222
#define INT_RXI0              223
#define INT_TXI0              224
#define INT_BRI1              225             /* Serial Communication Interface with FIFO channel 1 */
#define INT_ERI1              226
#define INT_RXI1              227
#define INT_TXI1              228
#define INT_BRI2              229             /* Serial Communication Interface with FIFO channel 2 */
#define INT_ERI2              230
#define INT_RXI2              231
#define INT_TXI2              232
#define INT_BRI3              233             /* Serial Communication Interface with FIFO channel 3 */
#define INT_ERI3              234
#define INT_RXI3              235
#define INT_TXI3              236
#define INT_BRI4              237             /* Serial Communication Interface with FIFO channel 4 */
#define INT_ERI4              238
#define INT_RXI4              239
#define INT_TXI4              240
#define INT_BRI5              241             /* Serial Communication Interface with FIFO channel 5 */
#define INT_ERI5              242
#define INT_RXI5              243
#define INT_TXI5              244
#define INT_BRI6              245             /* Serial Communication Interface with FIFO channel 6 */
#define INT_ERI6              246
#define INT_RXI6              247
#define INT_TXI6              248
#define INT_BRI7              249             /* Serial Communication Interface with FIFO channel 7 */
#define INT_ERI7              250
#define INT_RXI7              251
#define INT_TXI7              252
#define INT_GERI              253             /* Controller Area Network 2 - NEXT common */
#define INT_RFI               254
#define INT_CFRXI0            255             /* Controller Area Network 2 - NEXT channel 0 */
#define INT_CERI0             256
#define INT_CTXI0             257
#define INT_CFRXI1            258             /* Controller Area Network 2 - NEXT channel 1 */
#define INT_CERI1             259
#define INT_CTX1              260
#define INT_CFRXI2            261             /* Controller Area Network 2 - NEXT channel 2 */
#define INT_CERI2             262
#define INT_CTX2              263
#define INT_CFRXI3            264             /* Controller Area Network 2 - NEXT channel 3 */
#define INT_CERI3             265
#define INT_CTXI3             266
#define INT_CFRXI4            267             /* Controller Area Network 2 - NEXT channel 4 */
#define INT_CERI4             268
#define INT_CTXI4             269
#define INT_SPEI0             270             /* Renesas Serial Peripheral Interface channel 0 */
#define INT_SPRI0             271
#define INT_SPTI0             272
#define INT_SPEI1             273             /* Renesas Serial Peripheral Interface channel 1 */
#define INT_SPRI1             274
#define INT_SPTI1             275
#define INT_SPEI2             276             /* Renesas Serial Peripheral Interface channel 2 */
#define INT_SPRI2             277
#define INT_SPTI2             278
#define INT_SPEI3             279             /* Renesas Serial Peripheral Interface channel 3 */
#define INT_SPRI3             280
#define INT_SPTI3             281
#define INT_SPEI4             282             /* Renesas Serial Peripheral Interface channel 4 */
#define INT_SPRI4             283
#define INT_SPTI4             284
#define INT_IEBBTD            285             /* IEBus Controller */
#define INT_IEBBTERR          286
#define INT_IEBBTSTA          287
#define INT_IEBBTV            288
#define INT_ISY               289             /* CD-ROM Decoder */
#define INT_IERR              290
#define INT_ITARG             291
#define INT_ISEC              292
#define INT_IBUF              293
#define INT_IREADY            294
#define INT_STERB_BTOERB      295             /* NAND Flash Memory Controller */
#define INT_FLTENDI           296
#define INT_FLTREQ0I          297
#define INT_FLTREQ1I          298
#define INT_MMC0              299             /* MMC Host Controller */
#define INT_MMC1              300
#define INT_MMC2              301
#define INT_SDHI0_3           302             /* SD Host Interface channel 0 */
#define INT_SDHI0_0           303
#define INT_SDHI0_1           304
#define INT_SDHI1_3           305             /* SD Host Interface channel 1 */
#define INT_SDHI1_0           306
#define INT_SDHI1_1           307
#define INT_ARM               308             /* Relatime Clock */
#define INT_PRD               309
#define INT_CUP               310
#define INT_SCUAI0            311             /* SCUX  */
#define INT_SCUAI1            312
#define INT_SCUFDI0           313
#define INT_SCUFDI1           314
#define INT_SCUFDI2           315
#define INT_SCUFDI3           316
#define INT_SCUFUI0           317
#define INT_SCUFUI1           318
#define INT_SCUFUI2           319
#define INT_SCUFUI3           320
#define INT_SCUDVI0           321
#define INT_SCUDVI1           322
#define INT_SCUDVI2           323
#define INT_SCUDVI3           324
#define INT_MLBCI             325             /* Media Local Bus */
#define INT_MLBSI             326
#define INT_DRC0_1            327             /* Dynamic Range Converter channel 0 */
#define INT_DRC1_1            328             /* Dynamic Range Converter channel 1 */
#define INT_LINI0_INT_T       331             /* Renesas LIN3 channel 0 */
#define INT_LINI0_INT_R       332
#define INT_LINI0_INT_S       333
#define INT_LINI0_INT_M       334
#define INT_LINI1_INT_T       335             /* Renesas LIN3 channel 1 */
#define INT_LINI1_INT_R       336
#define INT_LINI1_INT_S       337
#define INT_LINI1_INT_M       338
#define INT_ERI0              347             /* Serial Communication Interface channel 0 */
#define INT_RXI0              348
#define INT_TXI0              349
#define INT_TEI0              350
#define INT_ERI1              351             /* Serial Communication Interface channel 1 */
#define INT_RXI1              352
#define INT_TXI1              353
#define INT_TEI1              354
#define INT_ETHERI            359             /* Ethernet Controller */
#define INT_CEUI              364             /* Capture Engine Unit */
#define INT_CSIH0TIR          365             /* ICN Communication */
#define INT_CSIH0TIRE         366
#define INT_CSIH1TIC          367
#define INT_CSIH1TIJC         368
#define INT_ECCE10            369             /* On-Chip RAM */
#define INT_ECCE20            370
#define INT_ECCOVF0           371
#define INT_ECCE11            372
#define INT_ECCE21            373
#define INT_ECCOVF1           374
#define INT_ECCE12            375
#define INT_ECCE22            376
#define INT_ECCOVF2           377
#define INT_ECCE13            378
#define INT_ECCE23            379
#define INT_ECCOVF3           380
#define INT_H2XMLB_ERRINT     381             /* Internal Bus */
#define INT_H2XIC1_ERRINT     382
#define INT_X2HPERI1_ERRINT   383
#define INT_X2HPERI2_ERRINT   384
#define INT_X2HPERI34_ERRINT  385
#define INT_X2HPERI5_ERRINT   386
#define INT_X2HPERI67_ERRINT  387
#define INT_X2DBGR_ERRINT     388
#define INT_PRRI              389
#define INT_IFEI0             390             /* Pixel Format Converter channel 0 */
#define INT_OFFI0             391
#define INT_PFVEI0            392
#define INT_IFEI1             393             /* Pixel Format Converter channel 1 */
#define INT_OFFI1             394
#define INT_PFVEI1            395
#define INT_TINT0             416             /* Pin Interrupts */
#define INT_TINT1             417
#define INT_TINT2             418
#define INT_TINT3             419
#define INT_TINT4             420
#define INT_TINT5             421
#define INT_TINT6             422
#define INT_TINT7             423
#define INT_TINT8             424
#define INT_TINT9             425
#define INT_TINT10            426
#define INT_TINT11            427
#define INT_TINT12            428
#define INT_TINT13            429
#define INT_TINT14            430
#define INT_TINT15            431
#define INT_TINT16            432
#define INT_TINT17            433
#define INT_TINT18            434
#define INT_TINT19            435
#define INT_TINT20            436
#define INT_TINT21            437
#define INT_TINT22            438
#define INT_TINT23            439
#define INT_TINT24            440
#define INT_TINT25            441
#define INT_TINT26            442
#define INT_TINT27            443
#define INT_TINT28            444
#define INT_TINT29            445
#define INT_TINT30            446
#define INT_TINT31            447
#define INT_TINT32            448
#define INT_TINT33            449
#define INT_TINT34            450
#define INT_TINT35            451
#define INT_TINT36            452
#define INT_TINT37            453
#define INT_TINT38            454
#define INT_TINT39            455
#define INT_TINT40            456
#define INT_TINT41            457
#define INT_TINT42            458
#define INT_TINT43            459
#define INT_TINT44            460
#define INT_TINT45            461
#define INT_TINT46            462
#define INT_TINT47            463
#define INT_TINT48            464
#define INT_TINT49            465
#define INT_TINT50            466
#define INT_TINT51            467
#define INT_TINT52            468
#define INT_TINT53            469
#define INT_TINT54            470
#define INT_TINT55            471
#define INT_TINT56            472
#define INT_TINT57            473
#define INT_TINT58            474
#define INT_TINT59            475
#define INT_TINT60            476
#define INT_TINT61            477
#define INT_TINT62            478
#define INT_TINT63            479
#define INT_TINT64            480
#define INT_TINT65            481
#define INT_TINT66            482
#define INT_TINT67            483
#define INT_TINT68            484
#define INT_TINT69            485
#define INT_TINT70            486
#define INT_TINT71            487
#define INT_TINT72            488
#define INT_TINT73            489
#define INT_TINT74            490
#define INT_TINT75            491
#define INT_TINT76            492
#define INT_TINT77            493
#define INT_TINT78            494
#define INT_TINT79            495
#define INT_TINT80            496
#define INT_TINT81            497
#define INT_TINT82            498
#define INT_TINT83            499
#define INT_TINT84            500
#define INT_TINT85            501
#define INT_TINT86            502
#define INT_TINT87            503
#define INT_TINT88            504
#define INT_TINT89            505
#define INT_TINT90            506
#define INT_TINT91            507
#define INT_TINT92            508
#define INT_TINT93            509
#define INT_TINT94            510
#define INT_TINT95            511
#define INT_TINT96            512
#define INT_TINT97            513
#define INT_TINT98            514
#define INT_TINT99            515
#define INT_TINT100           516
#define INT_TINT101           517
#define INT_TINT102           518
#define INT_TINT103           519
#define INT_TINT104           520
#define INT_TINT105           521
#define INT_TINT106           522
#define INT_TINT107           523
#define INT_TINT108           524
#define INT_TINT109           525
#define INT_TINT110           526
#define INT_TINT111           527
#define INT_TINT112           528
#define INT_TINT113           529
#define INT_TINT114           530
#define INT_TINT115           531
#define INT_TINT116           532
#define INT_TINT117           533
#define INT_TINT118           534
#define INT_TINT119           535
#define INT_TINT120           536
#define INT_TINT121           537
#define INT_TINT122           538
#define INT_TINT123           539
#define INT_TINT124           540
#define INT_TINT125           541
#define INT_TINT126           542
#define INT_TINT127           543
#define INT_TINT128           544
#define INT_TINT129           545
#define INT_TINT130           546
#define INT_TINT131           547
#define INT_TINT132           548
#define INT_TINT133           549
#define INT_TINT134           550
#define INT_TINT135           551
#define INT_TINT136           552
#define INT_TINT137           553
#define INT_TINT138           554
#define INT_TINT139           555
#define INT_TINT140           556
#define INT_TINT141           557
#define INT_TINT142           558
#define INT_TINT143           559
#define INT_TINT144           560
#define INT_TINT145           561
#define INT_TINT146           562
#define INT_TINT147           563
#define INT_TINT148           564
#define INT_TINT149           565
#define INT_TINT150           566
#define INT_TINT151           567
#define INT_TINT152           568
#define INT_TINT153           569
#define INT_TINT154           570
#define INT_TINT155           571
#define INT_TINT156           572
#define INT_TINT157           573
#define INT_TINT158           574
#define INT_TINT159           575
#define INT_TINT160           576
#define INT_TINT161           577
#define INT_TINT162           578

#endif    /* __IOR7S721001_H */
