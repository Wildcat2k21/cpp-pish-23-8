#include "../lib/Sandpile.h"
#include <iostream>
#include <filesystem>
#include <optional>
#include <string_view>

int main(int argc, char* argv[]) {
    try {
        // Парсим параметры командной строки
        std::optional<int> length, width, maxIter, freq;
        std::string input, output;

        for (int i = 1; i < argc; ++i) {
            std::string_view arg = argv[i];
            if (arg == "--length") {
                if (++i < argc) {
                    length = std::stoi(argv[i]);
                }
            } else if (arg == "--width") {
                if (++i < argc) {
                    width = std::stoi(argv[i]);
                }
            } else if (arg == "--input") {
                if (++i < argc) {
                    input = argv[i];
                }
            } else if (arg == "--output") {
                if (++i < argc) {
                    output = argv[i];
                }
            } else if (arg == "--max-iter") {
                if (++i < argc) {
                    maxIter = std::stoi(argv[i]);
                }
            } else if (arg == "--freq") {
                if (++i < argc) {
                    freq = std::stoi(argv[i]);
                }
            }
        }

        // Проверяем, что все параметры были переданы
        if (!length || !width || !maxIter || !freq || input.empty() || output.empty()) {
            std::cerr << "Не хватает параметров. Используйте: "
                      << argv[0] << " --length <int> --width <int> "
                      << "--input <file> --output <dir> --max-iter <int> --freq <int>\n";
            return 1;
        }

        // Создаём модель песчаной кучи
        Sandpile pile(*length, *width);

        // Загружаем точки из файла
        pile.loadFromFile(input);

        // Запускаем симуляцию
        pile.run(*maxIter, *freq, output);

        // Выводим сообщение об успешном завершении
        std::cout << "Симуляция завершена. Результат сохранён в " << output << "\n";
    } catch (const std::exception& e) {
        // В случае ошибки выводим её описание
        std::cerr << "Ошибка: " << e.what() << "\n";
        return 1;
    }

    return 0;
}

