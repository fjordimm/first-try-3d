@echo off

echo Building...
call build.bat
echo Done building
echo Running...
echo:
cd bin
threedtest.exe
echo:
pause