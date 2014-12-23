//
// Forces J-Link to program, even if flash contents already match data to be programmed
//
log writeData.txt
r
//
exec SetSkipProgOnCRCMatch=0
//
// Download application into QSPI flash
//
loadbin .\RZ_A1H_DMAC.SINGLE.bin, 0x18040000
verifybin .\RZ_A1H_DMAC.SINGLE.bin, 0x18040000
exit