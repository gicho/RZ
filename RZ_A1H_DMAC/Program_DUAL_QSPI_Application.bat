@echo off
rem  This batch file will load the code into dual quad mode QSPI devices.
rem  Please change the JLINK.EXE path below if it is different in your system. 
echo LOAD CODE INTO QSPI FLASH DUAL MODE (IC26)
echo .

rem <> Manually set path to JLink install directory here if you do not
rem    want to use the auto detect method
set BASE=C:\work\dev\SEGGER\JLink_V488b
if exist "%BASE%\JLink.exe" goto PATH_SET

rem <> Try to automatically detect JLink install directory
set KEYNAME=HKCU\Software\SEGGER\J-Link
set VALNAME=InstallPath
rem Check if JLink is installed first
reg query %KEYNAME% /v %VALNAME%
if not "%ERRORLEVEL%" == "0" (goto NO_PATH)
rem Query the value and then pipe it through findstr in order to find the matching line that has the value.
rem Only grab token 3 and the remainder of the line. %%b is what we are interested in here.
for /f "tokens=2,*" %%a in ('reg query %KEYNAME% /v %VALNAME% ^| findstr %VALNAME%') do (
    set BASE=%%b
)
if exist "%BASE%\JLink.exe" goto PATH_SET

:NO_PATH
chgclr 0C
echo ===================================================================
echo ERROR: You need to set the path for JLink.exe 
echo ===================================================================
pause
chgclr 07
exit

:PATH_SET

:PROGRAM
if not exist .\RZ_A1H_DMAC.DUAL.bin goto ERROR 

echo ===================================================================
"%BASE%\JLink.exe" -speed 15000 -if JTAG -device R7S721001_DUALSPI -CommanderScript Program_DUAL_QSPI_Application.Command
echo ===================================================================

goto END


:ERROR
chgclr 0C
echo ===================================================================
echo Error:
echo File "RZ_A1H_DMAC.DUAL.bin" not found
echo ===================================================================
pause
chgclr 07
exit

:END

echo .
pause
exit

