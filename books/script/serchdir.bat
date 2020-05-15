@echo off

set runpath=%cd%

for /D %%s in (*) do ( 
cd %%s
echo %%s
cd %runpath%
)

pause