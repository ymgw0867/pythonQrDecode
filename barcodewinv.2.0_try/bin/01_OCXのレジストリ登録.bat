@echo off

echo �o�[�R�[�h�F�����C�u�����yOCX�Łz�̃Z�b�g�A�b�v���J�n���܂�.

pause

set REGISTER=%SystemRoot%\system32\regsvr32.exe
set FILEPATH1=%~dp0MdBcDecode.ocx
set FILEPATH2=%~dp0MdQrDecode.ocx

"%REGISTER%" "%FILEPATH1%"
"%REGISTER%" "%FILEPATH2%"

pause
