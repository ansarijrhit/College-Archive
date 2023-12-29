echo off
rem **************
rem Uses FC to compare test script outputs
rem Compares outputs generated in Release configuration
rem **************
FC solutionOutput-Release.txt yourOutput-Release.txt > FCdiffs-Release.txt

echo -
echo FC just generated the file FCdiffs-Release.txt
echo -
echo Inspect it to see if there are differences between
echo   the output from your L2.dll and L2Sol.dll 
echo   when in Release configuration
echo -
echo Note: differences only in time taken to run tests are of no concern
pause

