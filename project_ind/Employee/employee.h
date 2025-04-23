#pragma once
#include "FIO.h"
#include <string>

class Employee {
protected:
    FIO fio;
    std::string position;
    double salary;

public:
    // ������������
    Employee();
    Employee(const FIO& fio, const std::string& position, double salary);

    // �������
    FIO getFIO() const;
    std::string getPosition() const;
    double getSalary() const;

    // �������
    void setFIO(const FIO& fio);
    void setPosition(const std::string& position);
    void setSalary(double salary);

    // ����������� ������
    virtual std::string getInfo() const;
};