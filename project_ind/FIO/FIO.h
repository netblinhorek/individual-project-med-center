#pragma once
#include <string>

class FIO {
private:
    std::string last_name;
    std::string first_name;
    std::string middle_name;

public:
    // Конструкторы
    FIO();
    FIO(const std::string&, const std::string&, const std::string&);

    // Геттеры
    std::string get_last_name() const;
    std::string get_first_name() const;
    std::string get_middle_name() const;
    std::string get_full_name() const;

    // Сеттеры
    void set_last_name(const std::string& last_name);
    void set_first_name(const std::string& first_name);
    void set_middle_name(const std::string& middle_name);
};
