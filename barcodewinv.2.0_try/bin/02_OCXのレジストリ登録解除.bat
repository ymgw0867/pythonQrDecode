@echo off

echo バーコード認識ライブラリ【OCX版】のレジストリ登録を解除します.

pause

set REGISTER=%SystemRoot%\system32\regsvr32.exe
set FILEPATH1=%~dp0MdBcDecode.ocx
set FILEPATH2=%~dp0MdQrDecode.ocx

"%REGISTER%" "%FILEPATH1%" /u
"%REGISTER%" "%FILEPATH2%" /u

pause
