#pragma once
#include "calendar_of_dates.h"
#include "doctors.h"
#include "visiting.h"
#include "tvector.h"
#include "date.h"

class Schedule {
private:
    CalendarOfDates calendar;
    TVector<Doctor*> doctors;
    TVector<Visiting*> visitings;

public:
    // Конструкторы
    Schedule();

    // Методы для работы с врачами
    void addDoctor(Doctor* doctor);
    void removeDoctor(Doctor* doctor);
    Doctor* findDoctor(const std::string& specialization) const;
    const TVector<Doctor*>& getDoctors() const;

    // Методы для работы с посещениями
    void addVisiting(Visiting* visiting);
    void removeVisiting(int visitingId);
    Visiting* findVisiting(int visitingId) const;
    const TVector<Visiting*>& getVisitings() const;

    // Методы для работы с календарем
    void addDate(const Date& date);
    void removeDate(const Date& date);
    bool hasDate(const Date& date) const;
    const CalendarOfDates& getCalendar() const;

    // Вспомогательные методы
    void clear();
};

