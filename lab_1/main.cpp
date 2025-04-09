#include <iostream>
#include <string>
#include "Department.h"

int main() {
    Department dept;
    std::string input;

    std::cout << "Введите название отдела: ";
    std::getline(std::cin, input);
    dept.setName(input);

    std::cout << "Введите телефон отдела: ";
    std::getline(std::cin, input);
    dept.setPhone(input);

    std::cout << "\n--- Ввод данных сотрудников ---\n";

    // Первые 5 — через ввод с консоли
    for (int i = 0; i < 5; ++i) {
        std::cout << "\nСотрудник " << i + 1 << ":\n";
        Employee emp;
        emp.setData();
        dept.addEmployee(emp, i);
    }

    // Последние 5 — через параметры
    for (int i = 5; i < 10; ++i) {
        std::string name, position, date;
        std::cout << "\nСотрудник " << i + 1 << ":\n";

        std::cout << "Имя: ";
        std::getline(std::cin, name);

        std::cout << "Должность: ";
        std::getline(std::cin, position);

        std::cout << "Дата приема (дд.мм.гггг): ";
        std::getline(std::cin, date);

        Employee emp;
        emp.setData(name, position, date);
        dept.addEmployee(emp, i);
    }

    // Вывод всей информации
    std::cout << "\n=== Отдел: " << dept.getName() << " | Телефон: " << dept.getPhone() << " ===\n";

    for (int i = 0; i < 10; ++i) {
        Employee emp = dept.getEmployee(i);
        std::cout << "Сотрудник " << i + 1 << ": " << emp.getName()
                  << " | " << emp.getPosition()
                  << " | Дата приема: " << emp.getHireDate() << "\n";
    }

    return 0;
}
