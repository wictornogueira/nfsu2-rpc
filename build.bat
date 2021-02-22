@echo off
setlocal enableextensions

if not exist build (
  mkdir build\scripts
)
  
i686-w64-mingw32-g++.exe -I include\ -L lib\ -shared -o build\scripts\discord-rpc.asi src\discord_rpc.cpp -l discord-rpc

if "%errorlevel%"=="0" (
  copy /B/V/Y lib\discord-rpc.dll build\discord-rpc.dll > NUL
  
  if "%errorlevel%"=="0" (
    echo Built successfully.
    exit /B
  )
)

echo Failed to build.
