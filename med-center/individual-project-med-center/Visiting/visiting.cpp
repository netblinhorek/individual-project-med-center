#include <iostream>
#include "visiting.h"



Visit::Visit() {
}
Visit::Visit(char* doctor_recommendations) {
}
Visit::Visit(const Visit& original) {
}
// деструктор
Visit::~Visit() {
}
//сеттеры
void Visit::set_number(char doctor_recommendations) {
}

//геттеры
const char Visit::get_doctor_recommendations() const {}