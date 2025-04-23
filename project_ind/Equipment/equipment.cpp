#include "equipment.h"
#include <sstream>

Equipment::Equipment() : id(-1), name(""), description(""), isAvailable(true) {}

Equipment::Equipment(int id, const std::string& name, const std::string& description)
    : id(id), name(name), description(description), isAvailable(true) {}

int Equipment::getId() const {
    return id;
}

std::string Equipment::getName() const {
    return name;
}

std::string Equipment::getDescription() const {
    return description;
}

bool Equipment::getIsAvailable() const {
    return isAvailable;
}

void Equipment::setId(int id) {
    this->id = id;
}

void Equipment::setName(const std::string& name) {
    this->name = name;
}

void Equipment::setDescription(const std::string& description) {
    this->description = description;
}

void Equipment::setIsAvailable(bool isAvailable) {
    this->isAvailable = isAvailable;
}

std::string Equipment::getInfo() const {
    std::stringstream ss;
    ss << "Оборудование #" << id << "\n"
        << "Название: " << name << "\n"
        << "Описание: " << description << "\n"
        << "Доступно: " << (isAvailable ? "Да" : "Нет");
    return ss.str();
}