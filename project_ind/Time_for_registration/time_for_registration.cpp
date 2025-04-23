#include "time_for_registration.h"
#include <sstream>
#include <iomanip>

Time::Time() : hours(0), minutes(0) {}

Time::Time(int hours, int minutes) : hours(hours), minutes(minutes) {}

int Time::getHours() const {
    return hours;
}

int Time::getMinutes() const {
    return minutes;
}

std::string Time::getTimeString() const {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << hours << ":"
        << std::setfill('0') << std::setw(2) << minutes;
    return ss.str();
}

void Time::setHours(int hours) {
    this->hours = hours;
}

void Time::setMinutes(int minutes) {
    this->minutes = minutes;
}

bool Time::isValid() const {
    return hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60;
}

void Time::addMinutes(int minutes) {
    int totalMinutes = getTotalMinutes() + minutes;
    hours = (totalMinutes / 60) % 24;
    this->minutes = totalMinutes % 60;
}

int Time::getTotalMinutes() const {
    return hours * 60 + minutes;
}