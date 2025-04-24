@echo off
chcp 65001 >nul
setlocal enabledelayedexpansion

cd /d %~dp0

echo === Запуск приложения ===

build\bin\sandpile_app.exe ^
  --length 100 --width 100 ^
  --input input\main_input.tsv ^
  --output output ^
  --max-iter 100000 ^
  --freq 0

pause
