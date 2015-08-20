/*
* Copyright 2015 Giancarlo Parodi
* 
* copy_arm_code_to_ram.c
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

#include "iodefine.h"
#include "rza_io_regrw.h"

void copyArmCodeToRam(uint32_t* rom_start, uint32_t* ram_start, uint32_t* ram_end)
{

	/* Variables for program copy */
    uint32_t i;
    uint32_t region_size;

    /* load and execution region are the same, nothing to do */
    if(rom_start == ram_start) return;

    /* Calculate the length of the copied section */
    region_size = (uint32_t)ram_end - (uint32_t)ram_start;

    /* Copy the next load module. */
    for(i = 0; i < (region_size/4); i++)
    {
        *ram_start++ = *rom_start++;
    }

}

/* End of File */
