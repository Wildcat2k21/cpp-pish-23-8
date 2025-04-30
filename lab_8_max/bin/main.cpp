#include <iostream>
#include <vector>
#include <map>
#include "lib/lazy_adapters.h"

int main() {
    std::vector<int> v = {1,2,3,4,5,6};
    
    // Фильтрация + трансформация (квадраты нечётных чисел)
    auto pipeline = v 
        | filter([](int x) { return x % 2; }) // Оставляем только нечётные числа
        | transform([](int x) { return x * x; }); // Возводим каждое число в квадрат
    std::cout << "Filter + Transform: ";
    for(int x : pipeline) {
        std::cout << x << " "; // Вывод: 1 9 25 (квадраты нечётных чисел)
    }

    // Take — взять первые 4 элемента из исходного вектора
    std::cout << "\nTake 4: ";
    for(auto x : v | take(4)) {
        std::cout << x << " "; // Вывод: 1 2 3 4 (первые 4 элемента)
    }

    // Drop — пропустить первые 2 элемента
    std::cout << "\nDrop 2: ";
    for(auto x : v | drop(2)) {
        std::cout << x << " "; // Вывод: 3 4 5 6 (пропустили первые два элемента)
    }

    // Reverse — реверсируем порядок элементов
    std::cout << "\nReverse: ";
    for(auto x : v | reverse()) {
        std::cout << x << " "; // Вывод: 6 5 4 3 2 1 (элементы в обратном порядке)
    }

    // Комбинация: реверс + take (реверсируем и берём первые 3 элемента)
    std::cout << "\nReverse + Take 3: ";
    for(auto x : v | reverse() | take(3)) {
        std::cout << x << " "; // Вывод: 6 5 4 (реверс + первые 3 элемента)
    }

    // Словарь: ключи и значения
    std::map<int, std::string> m = {{1, "one"}, {2, "two"}, {3, "three"}};

    // Извлечение ключей из словаря
    std::cout << "\nKeys: ";
    for(auto k : m | keys()) {
        std::cout << k << " "; // Вывод: 1 2 3 (ключи словаря)
    }

    // Извлечение значений из словаря
    std::cout << "\nValues: ";
    for(auto val : m | values()) {
        std::cout << val << " "; // Вывод: one two three (значения словаря)
    }

    std::cout << "\n";

    return 0;
}
