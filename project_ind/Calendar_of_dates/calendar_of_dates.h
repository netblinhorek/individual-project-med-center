#pragma once
#include "date.h"
#include "tvector.h"

class CalendarOfDates {
private:
    TVector<Date> dates;

public:
    // Конструкторы
    CalendarOfDates();

    // Методы
    void addDate(const Date& date);
    void removeDate(const Date& date);
    bool hasDate(const Date& date) const;
    const TVector<Date>& getDates() const;
    void clear();
};