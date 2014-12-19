@echo off
rem  This batch file will load the Tutorial code into dual quad mode QSPI devices.
rem  Please change the JLINK.EXE path below if it is different in your system. 
echo LOAD BOOT LOADER INTO QSPI FLASH (IC26)
echo ===================================================================
echo ***    Remember to update the JLink.exe path specified          ***
echo ***    in this batch file if using a different version than     ***
echo ***    that installed by the RSK+RZA1H_V2 installer.            ***
echo ***    This batch file was tested and works with Ver 4.84b      ***
echo ***    of the JLink.exe                                         ***
echo ***                                                             ***
echo ***    Please refer to the RSK+RZA1H Tutorial Manual            *** 
echo ***    for more information on generating the binary files.     ***
echo ===================================================================
echo ------------------------------------------------------------------------
echo .
:PROGRAM
if not exist .\RZ_A1H_DMAC.bin goto ERROR 
echo ------------------------------------------------------------------------


"C:\work\dev\SEGGER\JLink_V494i\JLink.exe" -speed 15000 -if JTAG -device R7S721001_DualSPI -CommanderScript Program_QSPI_Application.Command


echo ------------------------------------------------------------------------
echo Done.
goto END
:ERROR
echo ------------------------------------------------------------------------
echo Error:
echo File "RZ_A1H_DMAC.bin" not found
echo ------------------------------------------------------------------------
:END