#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include <string>

int count_lines_in_file(const std::string& filename);
int count_words_in_file(const std::string& filename);
int count_bytes_in_file(const std::string& filename);
int count_chars_in_file(const std::string& filename);

#endif // WORD_COUNT_H
