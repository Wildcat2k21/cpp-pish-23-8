#include "Employee.h"
#include <iostream>

Employee::Employee() {}

void Employee::setData() {
    std::cout << "Введите имя: ";
    std::getline(std::cin, name);

    std::cout << "Введите должность: ";
    std::getline(std::cin, position);

    std::cout << "Введите дату приема (дд.мм.гггг): ";
    std::getline(std::cin, hireDate);
}

void Employee::setData(const std::string& name, const std::string& position, const std::string& hireDate) {
    this->name = name;
    this->position = position;
    this->hireDate = hireDate;
}

std::string Employee::getName() const {
    return name;
}

std::string Employee::getPosition() const {
    return position;
}

std::string Employee::getHireDate() const {
    return hireDate;
}
