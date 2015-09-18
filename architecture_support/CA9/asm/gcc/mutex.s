/*
* Copyright 2015 Giancarlo Parodi
* 
* mutex_iar.s
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
    
    .global mutex_lock
    .global mutex_unlock

.equ LOCKED, 	0
.equ UNLOCKED,	1

.equ yield,     1
.equ released,  2

/*
* R0 holds the mutex object address
*/ 
mutex_lock:

  MOV   r1, #LOCKED     /* Prepare the lock value */

spin_lock:
  LDREX   r2, [r0]          /* load exclusive - goto into exclusive access */
  CMP     r2, r1            /* is already locked? */
  BEQ     wait_for_release  /* if locked, wait for release */      
  STREXNE r2, r1, [r0]      /* try to claim */
  CMPNE   r2, #1            /* check for claim success */
  BEQ     spin_lock         /* if claiming semaphore failed retry */
  DMB                       /* lock acquired, sync and return */
  BX lr

wait_for_release:
//  PUSH {r0-r3,r7,r12}   /* Push AAPCS corruptible registers, plus r7 */
//  LDR r7, =yield        /* Parameter to SVC call passed in r7 */
//  SVC #0
//  POP {r0-r3,r7,r12}                    
  B spin_lock
  
/*
* R0 holds the mutex object address
*/  
mutex_unlock:

  MOV r1, #UNLOCKED     /* prepare the unlock value */    
  DMB                   /* make sure no outstanding memory transactions */
  STR   r1, [r0]        /* store it back and unlock mutex */
  
//  PUSH {r0-r3,r7,r12}   /* Push AAPCS corruptible registers, plus r7 */
//  LDR r7, =released     /* Parameter to SVC call passed in r7 */
//  SVC #0
//  POP {r0-r3,r7,r12}
  
  BX    lr
  
  .end
  
