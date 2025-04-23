#pragma once
#include "employee.h"
#include "cabinet.h"
#include "tvector.h"
#include "FIO.h"
#include <string>

class Doctor : public Employee {
private:
    std::string specialization;
    Cabinet* cabinet;
    TVector<int> visitingIds; // ID посещений

public:
    // Конструкторы
    Doctor();
    Doctor(const FIO& fio, const std::string& specialization, double salary);

    // Геттеры
    std::string getSpecialization() const;
    Cabinet* getCabinet() const;
    const TVector<int>& getVisitingIds() const;

    // Сеттеры
    void setSpecialization(const std::string& specialization);
    void setCabinet(Cabinet* cabinet);

    // Методы
    void addVisiting(int visitingId);
    void removeVisiting(int visitingId);
    bool hasVisiting(int visitingId) const;
    std::string getInfo() const override;
};
