/*
* Copyright 2015 Giancarlo Parodi
* 
* semaphore_iar.s
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

    .text
    .arm
    .align 4
    
    .global semaphore_put
    .global semaphore_get

.equ yield,     1
.equ released,  2

/*
*	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*	         WARNING WARNING WARNING
*	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*	RZ does NOT support load/store exclusive (atomic access) on
*   strongly ordered, device, normal-shareable, or normal non-shareable uncached memory
*   Exclusive access might be used on normal non-shareable cached memory
*/
/* Declare for use from C as extern void semaphore_get(void * semaphore); */
semaphore_get:

  LDREX r1, [r0]        /* load exclusive - goto into exclusive access */
  CMP r1, #0            /* is semaphore empty? */
  BEQ semaphore_wait    /* If empty, block before retrying */
  SUB r1, r1, #1        /* If not empty, decrement temporary copy */
  STREX r2, r1, [r0]    /* Attempt Store-Exclusive */
  CMP r2, #0            /* Check if Store-Exclusive succeeded */
  BNE semaphore_get     /* If Store-Exclusive failed, retry from start */
  DMB                   /* Got hold of one instance of the semaphore */
  BX lr
  
/* this could trigger a context switch */
semaphore_wait:
//  PUSH {r0-r3,r7,r12}   /* Push AAPCS corruptible registers, plus r7 */
//  LDR r7, =yield        /* Parameter to SVC call passed in r7 */
//  SVC #0
//  POP {r0-r3,r7,r12} 
  B semaphore_get
  

/*
*	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*	         WARNING WARNING WARNING
*	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*	RZ does NOT support load/store exclusive (atomic access) on
*   strongly ordered, device, normal-shareable, or normal non-shareable uncached memory
*   Exclusive access might be used on normal non-shareable cached memory
*/
/* Declare for use from C as extern void semaphore_put(void * semaphore); */
semaphore_put:
  LDREX r1, [r0]        /* load the value from memory */
  ADD r1, r1, #1        /* Increment temporary copy */
  STREX r2, r1, [r0]    /* Attempt Store-Exclusive */
  CMP r2, #0            /* Check if Store-Exclusive succeeded */
  BNE semaphore_put     /* Store failed - retry */
  CMP r0, #1            /* Store successful - test if incremented from zero */
  DMB                   /* sync - Required before releasing protected resource */
  BGE signal_semaphore  /* If initial value was 0, signal update */
  BX lr

/* this could trigger a context switch */
signal_semaphore:
							/* Signal waiting processors or processes */
//  PUSH {r0-r3,r7,r12}   /* Push AAPCS corruptible registers, plus r7 */
//  LDR r7, =released     /* Parameter to SVC call passed in r7 */
//  SVC #0
//  POP {r0-r3,r7,r12}
  BX lr

  .end
    
    
    
    
