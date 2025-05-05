#pragma once
#include "../Employee/employee.h"
#include "../Cabinet/cabinet.h"
#include "tvector.h"
#include "../FIO/FIO.h"
#include <string>

class Doctor : public Employee {
private:
    std::string specialization;
    Cabinet* cabinet;
    TVector<int> visitingIds; // ID ���������

public:
    // ������������
    Doctor();
    Doctor(const FIO& fio, const std::string& specialization, double salary);

    // �������
    std::string getSpecialization() const;
    Cabinet* getCabinet() const;
    const TVector<int>& getVisitingIds() const;

    // �������
    void setSpecialization(const std::string& specialization);
    void setCabinet(Cabinet* cabinet);

    // ������
    void addVisiting(int visitingId);
    void removeVisiting(int visitingId);
    bool hasVisiting(int visitingId) const;
    std::string getInfo() const override;
};
