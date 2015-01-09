/*
 * assembler_macros.h
 *
 *  Created on: 23.09.2014
 *      Author: ParodiG
 */

#ifndef ASSEMBLER_MACROS_H_
#define ASSEMBLER_MACROS_H_

#ifdef __ASSEMBLY__

	.equiv DMA_FROM_DEVICE,1
	.equiv DMA_TO_DEVICE,2

#else

	#define DMA_FROM_DEVICE 1
	#define DMA_TO_DEVICE 	2

#endif


#endif /* ASSEMBLER_MACROS_H_ */
