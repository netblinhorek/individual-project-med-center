#pragma once
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // ������������
    Date();
    Date(int day, int month, int year);

    // �������
    int get_Day() const;
    int get_Month() const;
    int get_Year() const;
    std::string get_Date_String() const;

    // �������
    void set_Day(int day);
    void set_Month(int month);
    void set_Year(int year);

    // ������
    bool is_Valid() const;
    bool is_Leap_Year() const;
    int days_In_Month() const;
};
