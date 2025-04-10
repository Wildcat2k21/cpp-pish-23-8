@echo off
chcp 65001 >nul
setlocal enabledelayedexpansion

:: Установка шрифта, чтобы консоль отображала UTF-8 корректно:
:: REG ADD "HKCU\Console" /v "FaceName" /t REG_SZ /d "Consolas" /f

echo.
echo === Тест 1: Один файл без параметров ===
echo Команда: WordCount.exe "RandomText.txt"
WordCount.exe "RandomText.txt"

echo.
echo === Тест 2: Несколько файлов без параметров ===
echo Команда: WordCount.exe "RandomText.txt" "README.md"
WordCount.exe "RandomText.txt" "README.md"

echo.
echo === Тест 3: Подсчёт слов и строк ===
echo Команда: WordCount.exe --words --lines "RandomText.txt"
WordCount.exe --words --lines "RandomText.txt"

echo.
echo === Тест 4: Подсчёт строк и байт ===
echo Команда: WordCount.exe -l -c "RandomText.txt"
WordCount.exe -l -c "RandomText.txt"

echo.
echo === Тест 5: Подсчёт слов, строк и байт (объединённые флаги) ===
echo Команда: WordCount.exe -lwc "RandomText.txt" "README.md"
WordCount.exe -lwc "RandomText.txt" "README.md"

echo.
echo === Тест 6: Перемешанные аргументы (флаги и файлы) ===
echo Команда: WordCount.exe "RandomText.txt" "README.md" -lw --bytes
WordCount.exe "RandomText.txt" "README.md" -lw --bytes

echo.
pause
