DMA example
== Summary

Shows several DMA transfer types between cached / uncached internal ram and sdram
Demonstrates usage of invalidate and clean functions for L1 and L2 cache

== Detailed description

The example tests combinations of source and destination buffers (IRAM, SDRAM) for cached and non-cached addresses, and shows the results on the PMOD1 display of the RSK
You need to press one of the switches in between to proceed.

The DMA transfer is a memory-to-memory, triggered in software, for simplicity. 

The functions where the buffer is ‘given’ and ‘taken’ between CPU and DMA are called map/unmap (comes from the Linux sources).
In the L1 cache functions, for a source buffer we need to specify DMA_TO_DEVICE (like if we would be writing to a peripheral, although it is memory)

For a destination buffer, we need to specify DMA_FROM_DEVICE (like if we would be receiving from a peripheral, although it is memory). 

Example:
v7_dma_map_area((uint32_t) dmac_src_data_cachedram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_TO_DEVICE);
v7_dma_unmap_area((uint32_t) dmac_dst_data_cachedsdram, (uint32_t) DMAC_BUFF_SIZE, (uint32_t) DMA_FROM_DEVICE);

There is no ‘unmap’ using DMA_TO_DEVICE called since the function would not do anything
(invalidating a source buffer after the DMA transfer is not required, only invalidating a DMA destination buffer is meaningful from the CPU perspective)

The code can be flashed and run from QSPI @ 0x18040000 (Debug configuration) but for easy debug/test there is a build rule for loading and running it directly from ram ('Debug from RAM’)

Some important points:

-	L2 cache and L1 cache line is 32 Bytes size. The buffers are aligned to 32-Bytes and multiple of 32-Bytes. 
	This is required to avoid cache coherency issues, if a cache line is only partly occupied by a DMA buffer and this same line gets modified by the CPU during the transfer.

-	L2 cache needs physical addresses for operations, since this is a PIPT (physically indexed, physically tagged) cache. 
	There is a virtual to physical address translation stub, which basically returns back the same address since MMU does do a 1-to-1 mapping on 1MB pages 
	(does not really use virtual memory mapping)

-	The DMA controller requires also physical addresses, which are provided by the stub function too

-	L2 controller is *not* configured as ‘exclusive cache’, which means copies of data / instructions could be kept both in L1 and L2 cache at any point in time. 
	Which also means, for invalidating lines we must act ‘outer first’ (first L2, then L1) and for cleaning lines (writing back) we must do ‘inner first’ (first L1, then L2)

-	When the DMA transfer goes to or from an SDRAM cached area, the DMA auxiliary control register needs to be setup in order to place on the internal AXI bus
	the proper signals as defined by ARM, coherent with the MMU setup.
	This is shown in the dedicated DMA setup routine initialise_dma8bit_L2Cached in the example. 
	The value placed there is 0xf (b1111) since the configuration of the MMU is in/out cacheable write back, write allocate (read/write allocate, actually). 
	This is configured in the init_ttb.s module for the MMU on both cached internal ram and cached external sdram. 
	If you change the cache allocation policy (for instance, to read allocate), then you would need to modify both the MMU TTB and the DMA configuration accordingly. 

-	During the DMA transfers, I implemented some “touch-loop” functions whose purpose is to access memory which will land in cache at the same index as one of the 
	transfer buffer 32-Bytes slices (the first one, actually), so I try to occupy all the available L1 or L2 ways (4/8). 
	This simulates some concurrent cache-activity which should (if fast enough) even make sure that at least this first line of the current source or destination transfer
	buffer is evicted or written back in the background, before the DMA transfer ends. 
	
	
	
