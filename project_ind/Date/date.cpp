#include "date.h"
#include <sstream>
#include <iomanip>

Date::Date() : day(1), month(1), year(2000) {}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

int Date::get_Day() const {
    return day;
}

int Date::get_Month() const {
    return month;
}

int Date::get_Year() const {
    return year;
}

std::string Date::get_Date_String() const {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << day << "."
        << std::setfill('0') << std::setw(2) << month << "."
        << year;
    return ss.str();
}

void Date::set_Day(int day) {
    this->day = day;
}

void Date::set_Month(int month) {
    this->month = month;
}

void Date::set_Year(int year) {
    this->year = year;
}

bool Date::is_Leap_Year() const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::days_In_Month() const {
    static const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && is_Leap_Year()) {
        return 29;
    }
    return days[month - 1];
}

bool Date::is_Valid() const {
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > days_In_Month()) return false;
    if (year < 1900 || year > 2100) return false;
    return true;
}