#include "Department.h"

Department::Department() {}

void Department::setName(const std::string& name) {
    this->name = name;
}

void Department::setPhone(const std::string& phone) {
    this->phone = phone;
}

std::string Department::getName() const {
    return name;
}

std::string Department::getPhone() const {
    return phone;
}

void Department::addEmployee(const Employee& emp, int index) {
    if (index >= 0 && index < 10) {
        employees[index] = emp;
    }
    // В реальных условиях мы бы сделали исключение или лог
}

Employee Department::getEmployee(int index) const {
    return employees[index]; // В реальности проверка границ обязательна
}
