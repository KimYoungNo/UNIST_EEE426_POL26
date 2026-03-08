@echo off
setlocal

set version=2024.1
set "shortcutPath=%APPDATA%\Microsoft\Windows\Start Menu\Programs\Xilinx Design Tools\Vitis_HLS %version%\Vitis HLS %version%.lnk"

if not exist "%shortcutPath%" (
    echo Error: The shortcut file was not found at:
    echo %shortcutPath%
    echo.
    echo Please ensure Vitis HLS %version% is installed and you have run it once
    echo to create the start menu shortcut.
    pause
    exit /b
)

echo Updating Vitis HLS %version% shortcut...
echo Target: "%shortcutPath%"

powershell -command "& { $s=(New-Object -COM WScript.Shell).CreateShortcut('%shortcutPath%'); $s.Arguments='-classic'; $s.Save(); }"

if %errorlevel% equ 0 (
    echo.
    echo Success! The shortcut has been updated to launch with the "-classic" flag.
) else (
    echo.
    echo An error occurred while trying to update the shortcut.
)

pause