echo off
rem **************
rem Uses FC to compare test script outputs
rem Compares outputs generated in Debug configuration
rem **************
FC solutionOutput-Debug.txt yourOutput-Debug.txt > FCdiffs-Debug.txt

echo -
echo FC just generated the file FCdiffs-Debug.txt
echo -
echo Inspect it to see if there are differences between
echo   the output from your L2.dll and L2Sol.dll 
echo   when in Debug configuration
echo -
echo Note: differences only in time taken to run tests are of no concern
pause