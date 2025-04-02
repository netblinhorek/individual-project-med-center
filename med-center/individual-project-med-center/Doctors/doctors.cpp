#include <iostream>
#include <stdexcept>
#include "doctors.h"
#include <cstring>
#include <cctype>
#include <string>
#include <regex>
#include <set>



Doctor::Doctor() {
}
Doctor::Doctor(char* name, char* series, char* number_pasport, char* policy) {
}
Doctor::Doctor(const Doctor& original) {
}
// деструктор
Doctor::~Doctor() {
}


void Doctor::set_profession(char* professional) {}
void Doctor::set_work_experience(int* work_experience) {}
void Doctor::set_clinic(char* clinic) {}
void Doctor::set_category(char* category) {}
void Doctor::set_specialization(char* specialization) {}
void Doctor::set_cost(int* cost) {}
//геттеры
const char* Doctor::get_profession() const {}
const int* Doctor::get_work_experience() const {}
const char* Doctor::get_clinic() const {}
const char* Doctor::get_category() const {}
const char* Doctor::get_specialization() const {}
const int* Doctor::get_cost() const {}


