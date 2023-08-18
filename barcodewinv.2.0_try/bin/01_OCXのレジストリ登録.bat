@echo off

echo バーコード認識ライブラリ【OCX版】のセットアップを開始します.

pause

set REGISTER=%SystemRoot%\system32\regsvr32.exe
set FILEPATH1=%~dp0MdBcDecode.ocx
set FILEPATH2=%~dp0MdQrDecode.ocx

"%REGISTER%" "%FILEPATH1%"
"%REGISTER%" "%FILEPATH2%"

pause
