#include "doctors.h"
#include <sstream>

Doctor::Doctor() : specialization(""), cabinet(nullptr) {}

Doctor::Doctor(const FIO& fio, const std::string& specialization, double salary)
    : Employee(fio, "Врач", salary), specialization(specialization), cabinet(nullptr) {}

std::string Doctor::getSpecialization() const {
    return specialization;
}

Cabinet* Doctor::getCabinet() const {
    return cabinet;
}

const TVector<int>& Doctor::getVisitingIds() const {
    return visitingIds;
}

void Doctor::setSpecialization(const std::string& specialization) {
    this->specialization = specialization;
}

void Doctor::setCabinet(Cabinet* cabinet) {
    this->cabinet = cabinet;
}

void Doctor::addVisiting(int visitingId) {
    visitingIds.push_back(visitingId);
}

void Doctor::removeVisiting(int visitingId) {
    for (size_t i = 0; i < visitingIds.get_size(); ++i) {
        if (visitingIds[i] == visitingId) {
            TVector<int> newVisitingIds;
            for (size_t j = 0; j < visitingIds.get_size(); ++j) {
                if (j != i) {
                    newVisitingIds.push_back(visitingIds[j]);
                }
            }
            visitingIds = newVisitingIds;
            break;
        }
    }
}

bool Doctor::hasVisiting(int visitingId) const {
    for (size_t i = 0; i < visitingIds.get_size(); ++i) {
        if (visitingIds[i] == visitingId) {
            return true;
        }
    }
    return false;
}

std::string Doctor::getInfo() const {
    std::stringstream ss;
    ss << Employee::getInfo() << "\n"
        << "Специализация: " << specialization << "\n"
        << "Кабинет: " << (cabinet ? cabinet->getNumber() : "Не назначен");
    return ss.str();
}