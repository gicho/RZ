/*
* Copyright 2015 Giancarlo Parodi
* 
* dma_tests.h
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

void dmac_uncached_uncached_extrequest(void);
void dmac_uncached_uncached(void);
void dmac_cached_uncached(void);
void dmac_uncached_cached(void);
void dmac_cached_cached(void);

void dmac_ram_uncached_sdram_uncached(void);
void dmac_ram_cached_sdram_uncached(void);
void dmac_ram_uncached_sdram_cached(void);
void dmac_ram_cached_sdram_cached(void);
void dmac_sdram_uncached_ram_uncached(void);
void dmac_sdram_cached_ram_uncached(void);
void dmac_sdram_uncached_ram_cached(void);
void dmac_sdram_cached_ram_cached(void);
void dmac_sdram_cached_sdram_cached(void);


