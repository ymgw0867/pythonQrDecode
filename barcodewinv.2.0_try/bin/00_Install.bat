@echo off

set exe_path=%~dp0MspCmd.exe
set exe_args=-i
set log_path=%~dpn0.log

"%exe_path%" "%exe_args%" > "%log_path%"
echo �I���R�[�h�F%errorlevel% > "%log_path%"
type "%log_path%"

pause
