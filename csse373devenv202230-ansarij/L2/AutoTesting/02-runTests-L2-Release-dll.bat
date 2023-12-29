echo off
rem ******************
rem Runs your L2.dll test scripts
rem ******************

rem ******************
rem First check to see if the MS executable vstest.console.exe can be found
rem   if not echo a message and exit
rem   if yes then proceed to run test scripts
rem ******************
IF NOT EXIST "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" (
   echo This batch file needs to run: vstest.console.exe
   echo Use Windows File Explorer to find it on your machine
   echo Once you find it, note down its pathname
   echo Then edit this batch file by fixing the pathname to vstest.console.exe
   pause
   exit
)

rem ******************
rem First check to see L2.dll exists in the L2\x64\Release folder 
rem   if not echo a message and exit
rem   if yes then proceed to run test scripts from L2\x64\Release\L2.dll
rem ******************
IF EXIST "..\x64\Release\L2.dll" (
"C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" ..\x64\Release\L2.dll > yourOutput-Release.txt
) else (
  echo Go back to VS2022 and build L2 in Release configuration
  echo This will cause VS2022 to create L2.dll in the L2\x64\Release folder
  echo L2.dll is required by this batch file
  pause
  exit
)



