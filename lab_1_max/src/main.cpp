#include <iostream>
#include <vector>
#include <string>
#include "word_count.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: WordCount.exe [OPTION] filename [filename,...]\n";
        return 1;
    }

    std::vector<std::string> filenames;
    bool count_lines = false, count_words = false, count_bytes = false, count_chars = false;

    // Обработка флагов
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        // Комбинированные короткие флаги, например -lwc
        if (arg[0] == '-' && arg.size() > 1 && arg[1] != '-') {
            for (size_t j = 1; j < arg.size(); ++j) {
                switch (arg[j]) {
                    case 'l': count_lines = true; break;
                    case 'w': count_words = true; break;
                    case 'c': count_bytes = true; break;
                    case 'm': count_chars = true; break;
                    default:
                        std::cerr << "Unknown flag: -" << arg[j] << "\n";
                        return 1;
                }
            }
        }
        // Длинные флаги
        else if (arg == "--lines") {
            count_lines = true;
        } else if (arg == "--words") {
            count_words = true;
        } else if (arg == "--bytes") {
            count_bytes = true;
        } else if (arg == "--chars") {
            count_chars = true;
        }
        // Имена файлов
        else {
            filenames.push_back(arg);
        }
    }

    if (filenames.empty()) {
        std::cerr << "Error: No input files provided.\n";
        return 1;
    }

    // Обработка файлов
    for (const auto& filename : filenames) {
        std::cout << filename << ": ";

        if (count_lines) {
            std::cout << "lines=" << count_lines_in_file(filename) << " ";
        }
        if (count_words) {
            std::cout << "words=" << count_words_in_file(filename) << " ";
        }
        if (count_bytes) {
            std::cout << "bytes=" << count_bytes_in_file(filename) << " ";
        }
        if (count_chars) {
            std::cout << "chars=" << count_chars_in_file(filename) << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}
