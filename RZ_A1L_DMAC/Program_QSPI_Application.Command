//
// Forces J-Link to program, even if flash contents already match data to be programmed
//
r
//
exec SetSkipProgOnCRCMatch=0
//
// Download application into QSPI flash
//
// when dual mode is used, the offset in the image would be double the size of single mode
// 2*256KBytes for each sector is the minimum granularity which can be erased
// starting at sector 1 -> 2*0x40000 = 0x80000
loadbin .\RZ_A1H_DMAC.bin, 0x18080000
verifybin .\RZ_A1H_DMAC.bin, 0x18080000
exit