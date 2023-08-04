@echo off
if not exist "dist" mkdir dist 
if not exist "dist\Release" mkdir dist\Release 
cls
if not exist "resource/recurso.o" windres resource/recurso.rc "resource/recurso.o"
gcc -DRELEASE -O3 -s -static -std=c11 src/*.c resource/recurso.o -o dist/Release/Mi_app.exe
echo Finalizado..
pause