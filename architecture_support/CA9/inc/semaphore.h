/*
* Copyright 2015 Giancarlo Parodi
* 
* semaphore.h
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
#ifndef SEMAPHORE_H
#define SEMAPHORE_H

typedef uint32_t semaphore_t;

#define LOCKED   0
#define UNLOCKED 1

/*
*	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*	         WARNING WARNING WARNING
*	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*	RZ does NOT support load/store exclusive (atomic access) on
*   strongly ordered, device, normal-shareable, or normal non-shareable uncached memory
*   Exclusive access *might* be used on normal non-shareable cached memory
*   Check the TTB setup to make sure the MMU setting is consistent
*/
void semaphore_get(semaphore_t* mutex);
void semaphore_put(semaphore_t* mutex);


#endif
