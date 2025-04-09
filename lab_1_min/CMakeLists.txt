cmake_minimum_required(VERSION 3.10)

# Название проекта
project(OOP_Lab1)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаем исполняемый файл с нужным названием
add_executable(
    Program
    src/main.cpp
    src/Department.cpp
    src/Employee.cpp
)

# Подключаем директорию с заголовками
target_include_directories(Program PRIVATE src)

# Указываем, что exe-файл должен собираться в корень проекта
set_target_properties(Program PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)
