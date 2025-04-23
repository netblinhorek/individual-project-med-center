#pragma once
#include <string>

class Time {
private:
    int hours;
    int minutes;

public:
    // Конструкторы
    Time();
    Time(int hours, int minutes);

    // Геттеры
    int getHours() const;
    int getMinutes() const;
    std::string getTimeString() const;

    // Сеттеры
    void setHours(int hours);
    void setMinutes(int minutes);

    // Методы
    bool isValid() const;
    void addMinutes(int minutes);
    int getTotalMinutes() const;
};