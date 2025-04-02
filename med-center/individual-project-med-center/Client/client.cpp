#include <iostream>
#include <stdexcept>
#include "client.h"
#include <cstring>
#include <cctype>
#include <string>
#include <regex>
#include <set>



Client::Client() {
}
Client::Client(char* name, char* series, char* number_pasport, char* policy) {
}
Client::Client(const Client& original) {
}
// деструктор
Client::~Client() {
}
//сеттеры
void Client::set_address(char* address) {
}
void Client::set_mail(char* mail) {

}
void Client::set_services(char* services) {
}
void Client::set_visiting(char* visiting) {
}
//геттеры
const char* Client::get_address() const {
}
const char* Client::get_mail() const {
}
const char* Client::get_services() const {
}
const char* Client::get_visiting() const {

}
