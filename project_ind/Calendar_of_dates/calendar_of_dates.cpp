#include "calendar_of_dates.h"

CalendarOfDates::CalendarOfDates() {}

void CalendarOfDates::addDate(const Date& date) {
    if (!hasDate(date)) {
        dates.push_back(date);
    }
}

void CalendarOfDates::removeDate(const Date& date) {
    for (size_t i = 0; i < dates.get_size(); ++i) {
        if (dates[i].get_Day() == date.get_Day() &&
            dates[i].get_Month() == date.get_Month() &&
            dates[i].get_Year() == date.get_Year()) {
            TVector<Date> newDates;
            for (size_t j = 0; j < dates.get_size(); ++j) {
                if (j != i) {
                    newDates.push_back(dates[j]);
                }
            }
            dates = newDates;
            break;
        }
    }
}

bool CalendarOfDates::hasDate(const Date& date) const {
    for (size_t i = 0; i < dates.get_size(); ++i) {
        if (dates[i].get_Day() == date.get_Day() &&
            dates[i].get_Month() == date.get_Month() &&
            dates[i].get_Year() == date.get_Year()) {
            return true;
        }
    }
    return false;
}

const TVector<Date>& CalendarOfDates::getDates() const {
    return dates;
}

void CalendarOfDates::clear() {
    dates.clear();
}