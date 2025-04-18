#pragma once
#include <cinttypes>
#include <iostream>
#include <cstring>

// структура для представления большого целого числа
struct uint2022_t {
    static const int CAPACITY = 70; // 70 * 4 = 280 байт < 300 байт
    uint32_t data[CAPACITY] = {0};  // массив 32-битных слов, младший разряд — data[0]
};

static_assert(sizeof(uint2022_t) <= 300, "size of uint2022_t must be no higher than 300 bytes");

// преобразование из uint32_t
uint2022_t from_uint(uint32_t index);

// преобразование из строки (десятичное число)
uint2022_t from_string(const char* character);

// арифметические операторы
uint2022_t operator+(const uint2022_t& lhs, const uint2022_t& rhs);
uint2022_t operator-(const uint2022_t& lhs, const uint2022_t& rhs);
uint2022_t operator*(const uint2022_t& lhs, const uint2022_t& rhs);
uint2022_t operator/(const uint2022_t& lhs, const uint2022_t& rhs);
uint2022_t operator%(const uint2022_t& lhs, const uint2022_t& rhs);

// операторы сравнения
bool operator==(const uint2022_t& lhs, const uint2022_t& rhs);
bool operator!=(const uint2022_t& lhs, const uint2022_t& rhs);
bool operator<(const uint2022_t& lhs, const uint2022_t& rhs);
bool operator>(const uint2022_t& lhs, const uint2022_t& rhs);

// вывод значения
std::ostream& operator<<(std::ostream& stream, const uint2022_t& value);
