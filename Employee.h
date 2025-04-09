#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    std::string name;
    std::string position;
    std::string hireDate;

public:
    Employee();

    // Перегруженные методы установки параметров
    void setData();
    void setData(const std::string& name, const std::string& position, const std::string& hireDate);

    // Геттеры
    std::string getName() const;
    std::string getPosition() const;
    std::string getHireDate() const;
};

#endif // EMPLOYEE_H
