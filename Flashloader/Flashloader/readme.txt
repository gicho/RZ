
DESCRIPTION
===========

Serial Flash loader for the RSK RZA1H board.

Supported devices:
 - S25FL512S

CONFIGURATION
=============

The project contains configuration:

- Debug
Builds a flash loader for RSK RZA1H
Output file: FlashRTKRZA1H_SerialFlash.out
Macro file: FlashRTKRZA1H_SerialFlash.mac

USAGE
=====
The flash loader expects program code to be linked 
at address 0x18000000.

If [--dualmem] argument is used, the flashloader
will switch to 2 memories mode.

You can set custom write flash page (lower or upper 64MBytes) with
[--page] argument. It has one parameter - 0 or 1, respectively for 
lower or upper flash page. If no page is specified, default page is 0
 - lower 64MB.
