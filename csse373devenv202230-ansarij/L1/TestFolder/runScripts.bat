echo off
rem ***************************************
rem This Windows batch script will run 
rem L1Sol.exe on each of the test scripts found
rem in ..\TestScripts\ folder, sending the output
rem to the file outputFile.txt
rem ***************************************
echo Running Test Scripts > outputFile.txt
for /r %%i in (..\TestScripts\*.txt) do (
        echo run script: %%i
	echo ### >> outputFile.txt
	echo run script: %%i >> outputFile.txt
	echo *** >> outputFile.txt
	L1Sol.exe < %%i >> outputFile.txt
)



