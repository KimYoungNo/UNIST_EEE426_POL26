@echo off
setlocal EnableDelayedExpansion

call :CopyFilesByExt "hwh"
call :CopyFilesByExt "bit"

PAUSE
EXIT

:CopyFilesByExt
for /f "delims=" %%G in ('dir /s /b *.%~1 ^| findstr /e .%~1') do (
	echo "%%G"
	copy "%%G" "%~dp0"
)
goto :EOF