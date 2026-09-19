@echo off
rem scripts/build_port.bat — Automated Native Port Build Script (Windows 11 MSVC/MinGW)
setlocal enabledelayedexpansion

set SCRIPT_DIR=%~dp0
set ROOT_DIR=%SCRIPT_DIR%..
set BUILD_DIR=%ROOT_DIR%\build

echo ====================================================================
echo  Building Companions of Xanth Native Port (Windows 11 MSVC/MinGW)
echo  Workspace : "%ROOT_DIR%"
echo  Build Dir : "%BUILD_DIR%"
echo ====================================================================

where cmake >nul 2>&1
if errorlevel 1 (
    echo [ERROR] CMake not found in PATH. Please install CMake 3.16+.
    exit /b 1
)

if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

echo [1/2] Configuring CMake build...
cmake -S "%ROOT_DIR%\port" -B "%BUILD_DIR%" -DCMAKE_BUILD_TYPE=Release
if errorlevel 1 (
    echo [ERROR] CMake configuration failed.
    exit /b %errorlevel%
)

echo [2/2] Compiling xanth_port executable...
cmake --build "%BUILD_DIR%" --config Release
if errorlevel 1 (
    echo [ERROR] Build failed.
    exit /b %errorlevel%
)

if exist "%BUILD_DIR%\Release\xanth_port.exe" (
    echo ====================================================================
    echo  BUILD SUCCESS: "%BUILD_DIR%\Release\xanth_port.exe"
    echo ====================================================================
    exit /b 0
) else if exist "%BUILD_DIR%\xanth_port.exe" (
    echo ====================================================================
    echo  BUILD SUCCESS: "%BUILD_DIR%\xanth_port.exe"
    echo ====================================================================
    exit /b 0
) else (
    echo [ERROR] Build target xanth_port.exe was not created.
    exit /b 1
)
