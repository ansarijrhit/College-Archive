echo off
rem ***************************************
rem This Windows batch script will run 
rem L1.exe on each of the test scripts found
rem in ..\TestScripts\ folder, sending the output
rem to the file outputFileL1.txt
rem ***************************************
echo Running Test Scripts > outputFileL1.txt
for /r %%i in (..\TestScripts\*.txt) do (
        echo run script: %%i
	echo ### >> outputFileL1.txt
	echo run script: %%i >> outputFileL1.txt
	echo *** >> outputFileL1.txt
	L1.exe < %%i >> outputFileL1.txt
)



