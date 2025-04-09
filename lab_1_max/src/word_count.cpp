#include "word_count.h"
#include <fstream>
#include <cctype>

int count_lines_in_file(const std::string& filename) {
    std::ifstream file(filename);
    int line_count = 0;
    std::string line;
    while (std::getline(file, line)) {
        ++line_count;
    }
    return line_count;
}

int count_words_in_file(const std::string& filename) {
    std::ifstream file(filename);
    int word_count = 0;
    std::string word;
    while (file >> word) {
        ++word_count;
    }
    return word_count;
}

int count_bytes_in_file(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    return file.tellg();
}

int count_chars_in_file(const std::string& filename) {
    std::ifstream file(filename);
    int char_count = 0;
    char ch;
    while (file.get(ch)) {
        if (std::isalpha(ch)) {
            ++char_count;
        }
    }
    return char_count;
}
