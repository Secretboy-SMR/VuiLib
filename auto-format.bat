echo off
cls
setlocal enabledelayedexpansion

set DIR="%cd%"
SET CLANG_FORMAT="C:\Program Files\JetBrains\Rider\r2r\2023.2.3R\C290FEFCC6A89DF7C1940996A4BEEE4\windows-x86\clang-format"

SET /a index=0
for /R %DIR% %%f in (*.h, *.c, *.hpp, *.cpp, *.cc) do (
    %CLANG_FORMAT% -style=File -i %%f
    set /a index+=1
    Set "NUM=0000!index!"&Set "NUM=!NUM:~-4!"
    echo [!NUM!]Format file: %%f
)
echo.