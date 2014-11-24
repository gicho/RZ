/*
 * cache-v7.h
 *
 *  Created on: 24.11.2014
 *      Author: ParodiG
 */

#ifndef CACHE_V7_H_
#define CACHE_V7_H_

#include "assembler_macros.h"


/*
 *	dma_map_area(start, size, dir)
 *	- start	- kernel virtual start address
 *	- size	- size of region
 *	- dir	- DMA direction
 */
extern void v7_dma_map_area(uint32_t start, uint32_t size, uint32_t dir);


/*
 *	dma_unmap_area(start, size, dir)
 *	- start	- kernel virtual start address
 *	- size	- size of region
 *	- dir	- DMA direction
 */
extern void v7_dma_unmap_area(uint32_t start, uint32_t size, uint32_t dir);

#endif /* CACHE_V7_H_ */
