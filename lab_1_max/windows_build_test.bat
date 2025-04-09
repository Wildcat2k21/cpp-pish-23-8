@echo off
chcp 65001 >nul
setlocal enabledelayedexpansion

:: Установка шрифта, чтобы консоль отображала UTF-8 корректно:
:: Это на твой страх и риск — в GUI меняется шрифт cmd. Альтернатива — вручную в свойствах консоли.
:: REG ADD "HKCU\Console" /v "FaceName" /t REG_SZ /d "Consolas" /f

echo === Тест 1: Подсчет слов ===
WordCount.exe "RandomText.txt" --words

echo.
echo === Тест 2: Подсчет строк ===
WordCount.exe "RandomText.txt" --lines

echo.
echo === Тест 3: Подсчет символов ===
WordCount.exe "RandomText.txt" --chars

echo.
echo === Тест 4: Комбинированный вызов: слова, строки, символы ===
WordCount.exe "RandomText.txt" --words --lines --chars

echo.
echo === Тест 5: Смешанный порядок аргументов ===
WordCount.exe --lines "RandomText.txt" --chars --words

echo.
echo === Тест 6: Некорректный путь к файлу ===
WordCount.exe "nonexistent.txt" --words

echo.
echo === Тест 7: Пустой вызов ===
WordCount.exe

echo.
echo === Тест 8: Только имя файла, без параметров ===
WordCount.exe "RandomText.txt"

echo.
echo === Тест 9: Только параметры, без файла ===
WordCount.exe --words --lines

echo.
echo === Тест 10: Все три параметра без кавычек ===
WordCount.exe RandomText.txt --words --lines --chars

echo.
pause
