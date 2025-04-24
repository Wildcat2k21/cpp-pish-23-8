@echo off
chcp 65001 >nul
setlocal enabledelayedexpansion

echo === Пример 1: Суммирование чисел 1 2 3 ===
build\bin\labwork5.exe --sum 1 2 3
echo.

echo === Пример 2: Умножение чисел 4 5 6 ===
build\bin\labwork5.exe --mult 4 5 6
echo.

pause
