#include "service.h"
#include <sstream>
#include <iomanip>

Service::Service()
    : id(-1), name(""), description(""), price(0.0),
    type(ServiceType::ONE_TIME_SERVICE), durationMinutes(30) {}

Service::Service(int id, const std::string& name, const std::string& description,
    double price, ServiceType type, int durationMinutes)
    : id(id), name(name), description(description), price(price),
    type(type), durationMinutes(durationMinutes) {}

int Service::getId() const {
    return id;
}

std::string Service::getName() const {
    return name;
}

std::string Service::getDescription() const {
    return description;
}

double Service::getPrice() const {
    return price;
}

ServiceType Service::getType() const {
    return type;
}

int Service::getDurationMinutes() const {
    return durationMinutes;
}

std::string Service::getTypeString() const {
    switch (type) {
    case ServiceType::PRIMARY_VISIT:
        return "��������� �����";
    case ServiceType::REPEAT_VISIT:
        return "��������� �����";
    case ServiceType::ONE_TIME_SERVICE:
        return "������������ ������";
    default:
        return "����������� ���";
    }
}

void Service::setId(int id) {
    this->id = id;
}

void Service::setName(const std::string& name) {
    this->name = name;
}

void Service::setDescription(const std::string& description) {
    this->description = description;
}

void Service::setPrice(double price) {
    this->price = price;
}

void Service::setType(ServiceType type) {
    this->type = type;
}

void Service::setDurationMinutes(int durationMinutes) {
    this->durationMinutes = durationMinutes;
}

std::string Service::getInfo() const {
    std::stringstream ss;
    ss << "������ #" << id << "\n"
        << "��������: " << name << "\n"
        << "��������: " << description << "\n"
        << "����: " << std::fixed << std::setprecision(2) << price << " ���.\n"
        << "���: " << getTypeString() << "\n"
        << "������������: " << durationMinutes << " ���.";
    return ss.str();
}