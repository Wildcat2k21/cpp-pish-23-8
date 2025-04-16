#include "number.h"
#include <string>
#include <algorithm>

// создаёт число из uint32_t
uint2022_t from_uint(uint32_t index) {
    uint2022_t result;
    result.data[0] = index;
    return result;
}

// создаёт число из строки
uint2022_t from_string(const char* character) {
    uint2022_t result;
    uint2022_t origin = from_uint(10);

    // умножает предыдущее значение на 10 и добавляет текущую цифру
    for (const char* point = character; *point; ++point) {
        result = result * origin + from_uint(*point - '0');
    }
    return result;
}

// оператор сложения двух чисел
uint2022_t operator+(const uint2022_t& lhs, const uint2022_t& rhs) {
    uint2022_t result;
    uint64_t carry = 0;

    for (int i = 0; i < uint2022_t::CAPACITY; ++i) {
        uint64_t addition = (uint64_t)lhs.data[i] + rhs.data[i] + carry;
        result.data[i] = addition & 0xFFFFFFFF;
        carry = addition >> 32;
    }

    return result;
}

// оператор вычитания одного числа из другого
uint2022_t operator-(const uint2022_t& lhs, const uint2022_t& rhs) {
    uint2022_t result;
    int64_t borrow = 0;

    for (int i = 0; i < uint2022_t::CAPACITY; ++i) {
        int64_t difference = (int64_t)lhs.data[i] - rhs.data[i] - borrow;
        if (difference < 0) {
            difference += ((int64_t)1 << 32);
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.data[i] = (uint32_t)difference;
    }

    return result;
}

// оператор умножения двух чисел
uint2022_t operator*(const uint2022_t& lhs, const uint2022_t& rhs) {
    uint2022_t result;

    for (int i = 0; i < uint2022_t::CAPACITY; ++i) {
        uint64_t carry = 0;

        for (int j = 0; j + i < uint2022_t::CAPACITY; ++j) {
            uint64_t product = (uint64_t)lhs.data[i] * rhs.data[j] + result.data[i + j] + carry;
            result.data[i + j] = product & 0xFFFFFFFF;
            carry = product >> 32;
        }
    }

    return result;
}

// оператор деления одного числа на другое
uint2022_t operator/(const uint2022_t& lhs, const uint2022_t& rhs) {
    if (rhs == from_uint(0)) return from_uint(0); // защита от деления на 0

    uint2022_t result, remainder;

    for (int i = uint2022_t::CAPACITY * 32 - 1; i >= 0; --i) {
        remainder = remainder * from_uint(2);
        remainder.data[0] |= (lhs.data[i / 32] >> (i % 32)) & 1;

        if (!(remainder < rhs)) {
            remainder = remainder - rhs;
            result.data[i / 32] |= (1U << (i % 32));
        }
    }

    return result;
}

// возвращает остаток от деления одного числа на другое
uint2022_t operator%(const uint2022_t& lhs, const uint2022_t& rhs) {
    if (rhs == from_uint(0)) return from_uint(0); // защита от деления на 0

    uint2022_t remainder;

    for (int i = uint2022_t::CAPACITY * 32 - 1; i >= 0; --i) {
        remainder = remainder * from_uint(2);
        remainder.data[0] |= (lhs.data[i / 32] >> (i % 32)) & 1;

        if (!(remainder < rhs)) {
            remainder = remainder - rhs;
        }
    }

    return remainder;
}

// оператор "меньше", сравнивает два числа побитно
bool operator<(const uint2022_t& x, const uint2022_t& y) {
    for (int i = uint2022_t::CAPACITY - 1; i >= 0; --i) {
        if (x.data[i] < y.data[i]) return true;
        if (x.data[i] > y.data[i]) return false;
    }
    return false;
}

// оператор "больше", сравнивает два числа побитно
bool operator>(const uint2022_t& x, const uint2022_t& y) {
    for (int i = uint2022_t::CAPACITY - 1; i >= 0; --i) {
        if (x.data[i] > y.data[i]) return true;
        if (x.data[i] < y.data[i]) return false;
    }
    return false;
}

// проверяет равенство двух чисел
bool operator==(const uint2022_t& lhs, const uint2022_t& rhs) {
    for (int i = 0; i < uint2022_t::CAPACITY; ++i) {
        if (lhs.data[i] != rhs.data[i]) return false;
    }
    return true;
}

// проверяет неравенство двух чисел
bool operator!=(const uint2022_t& lhs, const uint2022_t& rhs) {
    return !(lhs == rhs);
}

// выводит число в поток в виде строки
std::ostream& operator<<(std::ostream& stream, const uint2022_t& value) {
    uint2022_t num = value;
    std::string result;
    uint2022_t numZero = from_uint(0);
    uint2022_t numTen = from_uint(10);

    // преобразует число в строку путём деления и накопления цифр
    while (num != numZero) {
        uint2022_t digit = num % numTen;
        result.push_back('0' + digit.data[0]);
        num = num / numTen;
    }

    if (result.empty()) result = "0";

    std::reverse(result.begin(), result.end());
    stream << result;
    return stream;
}
