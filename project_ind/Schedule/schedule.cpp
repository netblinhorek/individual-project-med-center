#include "schedule.h"

Schedule::Schedule() {}

void Schedule::addDoctor(Doctor* doctor) {
    if (doctor) {
        doctors.push_back(doctor);
    }
}

void Schedule::removeDoctor(Doctor* doctor) {
    for (size_t i = 0; i < doctors.get_size(); ++i) {
        if (doctors[i] == doctor) {
            TVector<Doctor*> newDoctors;
            for (size_t j = 0; j < doctors.get_size(); ++j) {
                if (j != i) {
                    newDoctors.push_back(doctors[j]);
                }
            }
            doctors = newDoctors;
            break;
        }
    }
}

Doctor* Schedule::findDoctor(const std::string& specialization) const {
    for (size_t i = 0; i < doctors.get_size(); ++i) {
        if (doctors[i]->getSpecialization() == specialization) {
            return doctors[i];
        }
    }
    return nullptr;
}

const TVector<Doctor*>& Schedule::getDoctors() const {
    return doctors;
}

void Schedule::addVisiting(Visiting* visiting) {
    if (visiting) {
        visitings.push_back(visiting);
    }
}

void Schedule::removeVisiting(int visitingId) {
    for (size_t i = 0; i < visitings.get_size(); ++i) {
        if (visitings[i]->getId() == visitingId) {
            TVector<Visiting*> newVisitings;
            for (size_t j = 0; j < visitings.get_size(); ++j) {
                if (j != i) {
                    newVisitings.push_back(visitings[j]);
                }
            }
            visitings = newVisitings;
            break;
        }
    }
}

Visiting* Schedule::findVisiting(int visitingId) const {
    for (size_t i = 0; i < visitings.get_size(); ++i) {
        if (visitings[i]->getId() == visitingId) {
            return visitings[i];
        }
    }
    return nullptr;
}

const TVector<Visiting*>& Schedule::getVisitings() const {
    return visitings;
}

void Schedule::addDate(const Date& date) {
    calendar.addDate(date);
}

void Schedule::removeDate(const Date& date) {
    calendar.removeDate(date);
}

bool Schedule::hasDate(const Date& date) const {
    return calendar.hasDate(date);
}

const CalendarOfDates& Schedule::getCalendar() const {
    return calendar;
}

void Schedule::clear() {
    calendar.clear();
    doctors.clear();
    visitings.clear();
}