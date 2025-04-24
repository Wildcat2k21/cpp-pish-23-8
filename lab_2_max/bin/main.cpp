#include <lib/number.h>
#include <iostream>
#include <iomanip>

int main() {
    // проверка вывода большого числа
    uint2022_t value = from_string("111222333444555666");
    std::cout << value << std::endl;

    // объявление переменных
    uint2022_t a = from_uint(33412);
    std::cout << "a = " << a << std::endl;

    // создание числа из строки
    uint2022_t b = from_string("3413241234");
    std::cout << "b = " << b << std::endl;

    // сложение
    uint2022_t sum = a + b;
    std::cout << "a + b = " << sum << std::endl;

    // вычитание
    uint2022_t diff = b - a;
    std::cout << "b - a = " << diff << std::endl;

    // умножение
    uint2022_t prod = a * b;
    std::cout << "a * b = " << prod << std::endl;

    // деление
    uint2022_t div = b / a;
    std::cout << "b / a = " << div << std::endl;

    // сравнение
    std::cout << "a == b? " << (a == b ? "Yes" : "No") << std::endl;
    std::cout << "a != b? " << (a != b ? "Yes" : "No") << std::endl;
    std::cout << "a < b? "  << (a < b  ? "Yes" : "No") << std::endl;
    std::cout << "a > b? "  << (a > b  ? "Yes" : "No") << std::endl;

    // Кейс с переполнением
    uint2022_t max_value;
    for (int i = 0; i < uint2022_t::CAPACITY; ++i) {
        max_value.data[i] = 0xFFFFFFFF;
    }

    std::cout << "\n=== ТЕСТ НА ПЕРЕПОЛНЕНИЕ ===" << std::endl;

    std::cout << "\nЗначение max: " << max_value << std::endl;

    uint2022_t two  = from_uint(4);
    std::cout << "\nзначение max + 2: " << max_value + two << std::endl;

    return 0;
}
