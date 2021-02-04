IF NOT EXIST build (
mkdir build 
)

cmake -G "Visual Studio 15 2017" -A x64 -S . -B build

cd build

SET MSBUILD=C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\MSBuild\15.0\Bin\MSBuild.exe
IF NOT EXIST "%MSBUILD%" GOTO NOMSB

"%MSBUILD%" OpenCVTrainings.sln /t:rebuild /p:Configuration=Debug /p:Platform="x64" /m
GOTO :EOF

:NOMSB
echo. 
echo MSBUILD not found 
echo. 
GOTO :EOF 
