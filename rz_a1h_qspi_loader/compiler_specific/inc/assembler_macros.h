/*
* Copyright 2015 Giancarlo Parodi
*
* assembler_macros.h
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

#ifndef ASSEMBLER_MACROS_H_
#define ASSEMBLER_MACROS_H_

#ifdef __GNUC__

#ifdef __ASSEMBLY__

	.equiv DMA_FROM_DEVICE,1
	.equiv DMA_TO_DEVICE,2

#else

    #define DMA_FROM_DEVICE (1)
	#define DMA_TO_DEVICE 	(2)

#endif

#define isb() __asm__ __volatile__ ("isb" : : : "memory")
#define dsb() __asm__ __volatile__ ("dsb" : : : "memory")
#define dmb() __asm__ __volatile__ ("dmb" : : : "memory")

#endif
      
#ifdef __ICCARM__

        #define DMA_FROM_DEVICE 1
	#define DMA_TO_DEVICE 	2

#endif
          
#endif /* ASSEMBLER_MACROS_H_ */
