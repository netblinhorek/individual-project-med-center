#include "equipment.h"
#include <iostream>


Equipment::Equipment() {
}
Equipment::Equipment(char* , Status* ) {
}
Equipment::Equipment(const Equipment& original) {
}
// деструктор
Equipment::~Equipment() {
}
//сеттеры
void Equipment::set_number(char* name) {
}
void Equipment::set_name(Status* status) {
}

//геттеры
const int Equipment::get_name() const {
}
const Status* Equipment::get_status() const {
}



