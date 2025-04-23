#pragma once
#include "FIO.h"
#include <string>

class Employee {
protected:
    FIO fio;
    std::string position;
    double salary;

public:
    // Конструкторы
    Employee();
    Employee(const FIO& fio, const std::string& position, double salary);

    // Геттеры
    FIO getFIO() const;
    std::string getPosition() const;
    double getSalary() const;

    // Сеттеры
    void setFIO(const FIO& fio);
    void setPosition(const std::string& position);
    void setSalary(double salary);

    // Виртуальные методы
    virtual std::string getInfo() const;
};