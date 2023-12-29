echo off
rem ******************
rem Runs L2Sol.dll test scripts
rem L2Sol.dll is the solution to L2 lab
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
rem Now run L2Sol.dll generated from both Release and Debug configurations
rem ******************
"C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" L2Sol-Release.dll > solutionOutput-Release.txt
"C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" L2Sol-Debug.dll > solutionOutput-Debug.txt

