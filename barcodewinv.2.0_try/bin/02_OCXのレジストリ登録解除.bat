@echo off

echo �o�[�R�[�h�F�����C�u�����yOCX�Łz�̃��W�X�g���o�^���������܂�.

pause

set REGISTER=%SystemRoot%\system32\regsvr32.exe
set FILEPATH1=%~dp0MdBcDecode.ocx
set FILEPATH2=%~dp0MdQrDecode.ocx

"%REGISTER%" "%FILEPATH1%" /u
"%REGISTER%" "%FILEPATH2%" /u

pause
