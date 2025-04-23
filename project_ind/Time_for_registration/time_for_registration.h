#pragma once
#include <string>

class Time {
private:
    int hours;
    int minutes;

public:
    // ������������
    Time();
    Time(int hours, int minutes);

    // �������
    int getHours() const;
    int getMinutes() const;
    std::string getTimeString() const;

    // �������
    void setHours(int hours);
    void setMinutes(int minutes);

    // ������
    bool isValid() const;
    void addMinutes(int minutes);
    int getTotalMinutes() const;
};