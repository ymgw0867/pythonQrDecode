ECHO OFF
CLS

ECHO HASP aksfridge.sys �𖳌������܂�.
ECHO.                       
PAUSE

IF NOT EXIST %SystemRoot%\system32\drivers\aksfridge.sys goto NOTHING

MOVE /Y %SystemRoot%\system32\drivers\aksfridge.sys old-aksfridge.old
IF NOT EXIST %SystemRoot%\system32\drivers\aksfridge.sys goto DONE

ECHO.
ECHO �G���[�F%SystemRoot%\system32\drivers\aksfridge.sys �̖������Ɏ��s.
                       
GOTO END


:DONE
                       
ECHO.
ECHO HASP aksfridge.sys �𖳌������܂���.
                       
GOTO END


:NOTHING
                       
ECHO.
ECHO HASP aksfridge.sys ���V�X�e�����Ɍ�����܂���ł���.
                       
GOTO END


:END

ECHO.
PAUSE
