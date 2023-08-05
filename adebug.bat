@echo off
if not exist "dist" mkdir dist 
if not exist "dist\Debug" mkdir dist\Debug 
cls
if not exist "resource/recurso.o" windres resource/recurso.rc "resource/recurso.o"
gcc  -std=c17 src/*.c resource/recurso.o -o dist/Debug/i2t.exe
echo Finalizado..
pause
cd dist/Debug
cls
i2t.exe windows.ico
notepad windows.ico_formateado.txt