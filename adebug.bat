@echo off
if not exist "dist" mkdir dist 
if not exist "dist\Debug" mkdir dist\Debug 
cls
if not exist "resource/recurso.o" windres resource/recurso.rc "resource/recurso.o"
gcc -DDEBUG -static -std=c11 src/*.c resource/recurso.o -o dist/Debug/Mi_app.exe
echo Finalizado..
pause
cd dist/Debug
cls
Mi_app.exe