#include "FIO.h"

FIO::FIO() : last_name(""), first_name(""), middle_name("") {}

FIO::FIO(const std::string& lastName, const std::string& firstName, const std::string& middleName)
    : last_name(lastName), first_name(firstName), middle_name(middleName) {}

std::string FIO::get_last_name() const {
    return last_name;
}

std::string FIO::get_first_name() const {
    return first_name;
}

std::string FIO::get_middle_name() const {
    return middle_name;
}

std::string FIO::get_full_name() const {
    return last_name + " " + first_name + " " + middle_name;
}

void FIO::set_last_name(const std::string& lastName) {
    this->last_name = lastName;
}

void FIO::set_first_name(const std::string& firstName) {
    this->first_name = firstName;
}

void FIO::set_middle_name(const std::string& middleName) {
    this->middle_name = middleName;
}