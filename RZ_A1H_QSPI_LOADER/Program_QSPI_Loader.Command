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
loadbin .\RZ_A1H_QSPI_LOADER.bin, 0x18000000
verifybin .\RZ_A1H_QSPI_LOADER.bin, 0x18000000
exit