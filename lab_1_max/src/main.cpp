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
        if (arg == "--lines" || arg == "-l") {
            count_lines = true;
        } else if (arg == "--words" || arg == "-w") {
            count_words = true;
        } else if (arg == "--bytes" || arg == "-c") {
            count_bytes = true;
        } else if (arg == "--chars" || arg == "-m") {
            count_chars = true;
        } else {
            filenames.push_back(arg);
        }
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
