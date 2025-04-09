cmake_minimum_required(VERSION 3.10)
project(word_counter)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаем исполняемый файл с нужным названием
add_executable(
    WordCount
    src/main.cpp
    src/word_count.cpp
)

# Подключаем директорию с заголовками
target_include_directories(WordCount PRIVATE src)

# Указываем, что exe-файл должен собираться в корень проекта
set_target_properties(WordCount PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)
