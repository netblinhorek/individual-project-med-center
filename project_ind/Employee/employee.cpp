#include "employee.h"
#include <sstream>

Employee::Employee() : position(""), salary(0.0) {}

Employee::Employee(const FIO& fio, const std::string& position, double salary)
    : fio(fio), position(position), salary(salary) {}

FIO Employee::getFIO() const {
    return fio;
}

std::string Employee::getPosition() const {
    return position;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::setFIO(const FIO& fio) {
    this->fio = fio;
}

void Employee::setPosition(const std::string& position) {
    this->position = position;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}

std::string Employee::getInfo() const {
    std::stringstream ss;
    ss << "Сотрудник: " << fio.get_full_name() << "\n"
        << "Должность: " << position << "\n"
        << "Зарплата: " << salary;
    return ss.str();
}