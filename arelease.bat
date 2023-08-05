@echo off
if not exist "dist" mkdir dist 
if not exist "dist\Release" mkdir dist\Release 
cls
if not exist "resource/recurso.o" windres resource/recurso.rc "resource/recurso.o"
gcc  -O2 -s  -std=c17 src/*.c resource/recurso.o -o dist/Release/i2t.exe
echo Finalizado..
pause