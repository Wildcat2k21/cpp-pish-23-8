#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include "Employee.h"

class Department {
private:
    std::string name;
    std::string phone;
    Employee employees[10]; // фиксированный массив работников

public:
    Department();

    void setName(const std::string& name);
    void setPhone(const std::string& phone);
    std::string getName() const;
    std::string getPhone() const;

    void addEmployee(const Employee& emp, int index);
    Employee getEmployee(int index) const;
};

#endif // DEPARTMENT_H
