rmdir /s/q ..\build
mkdir ..\build

cmake -G "Visual Studio 16 2019" -S . -B ..\build

cd ../build

SET MSBUILD=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe
IF NOT EXIST "%MSBUILD%" GOTO NOMSB

"%MSBUILD%" BrightnessAdjustment.sln /t:rebuild /p:configuration=Debug /m
GOTO :EOF

:NOMSB
echo. 
echo MSBUILD not found 
echo. 
GOTO :EOF 
