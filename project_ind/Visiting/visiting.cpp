#include "visiting.h"
#include "client.h"
#include "doctors.h"
#include "cabinet.h"
#include <sstream>

Visiting::Visiting() : id(-1), client(nullptr), doctor(nullptr), cabinet(nullptr) {}

Visiting::Visiting(int id, const Date& date, const Time& time, Client* client, Doctor* doctor, Cabinet* cabinet)
    : id(id), date(date), time(time), client(client), doctor(doctor), cabinet(cabinet) {}

int Visiting::getId() const {
    return id;
}

Date Visiting::getDate() const {
    return date;
}

Time Visiting::getTime() const {
    return time;
}

Client* Visiting::getClient() const {
    return client;
}

Doctor* Visiting::getDoctor() const {
    return doctor;
}

Cabinet* Visiting::getCabinet() const {
    return cabinet;
}

std::string Visiting::getDiagnosis() const {
    return diagnosis;
}

std::string Visiting::getTreatment() const {
    return treatment;
}

const TVector<Service*>& Visiting::getServices() const {
    return services;
}

void Visiting::setId(int id) {
    this->id = id;
}

void Visiting::setDate(const Date& date) {
    this->date = date;
}

void Visiting::setTime(const Time& time) {
    this->time = time;
}

void Visiting::setClient(Client* client) {
    this->client = client;
}

void Visiting::setDoctor(Doctor* doctor) {
    this->doctor = doctor;
}

void Visiting::setCabinet(Cabinet* cabinet) {
    this->cabinet = cabinet;
}

void Visiting::setDiagnosis(const std::string& diagnosis) {
    this->diagnosis = diagnosis;
}

void Visiting::setTreatment(const std::string& treatment) {
    this->treatment = treatment;
}

void Visiting::addService(Service* service) {
    if (service) {
        services.push_back(service);
    }
}

void Visiting::removeService(int serviceId) {
    for (size_t i = 0; i < services.get_size(); ++i) {
        if (services[i]->getId() == serviceId) {
            TVector<Service*> newServices;
            for (size_t j = 0; j < services.get_size(); ++j) {
                if (j != i) {
                    newServices.push_back(services[j]);
                }
            }
            services = newServices;
            break;
        }
    }
}

Service* Visiting::findService(int serviceId) const {
    for (size_t i = 0; i < services.get_size(); ++i) {
        if (services[i]->getId() == serviceId) {
            return services[i];
        }
    }
    return nullptr;
}

double Visiting::getTotalCost() const {
    double total = 0.0;
    for (size_t i = 0; i < services.get_size(); ++i) {
        total += services[i]->getPrice();
    }
    return total;
}

std::string Visiting::getInfo() const {
    std::stringstream ss;
    ss << "Посещение #" << id << "\n"
        << "Дата: " << date.get_Date_String() << "\n"
        << "Время: " << time.getTimeString() << "\n"
        << "Клиент: " << (client ? client->getFIO().get_full_name() : "Не указан") << "\n"
        << "Врач: " << (doctor ? doctor->getFIO().get_full_name() : "Не указан") << "\n"
        << "Кабинет: " << (cabinet ? cabinet->getNumber() : "Не указан") << "\n"
        << "Диагноз: " << diagnosis << "\n"
        << "Лечение: " << treatment << "\n"
        << "Услуги: ";

    if (services.get_size() > 0) {
        ss << "\n";
        for (size_t i = 0; i < services.get_size(); ++i) {
            ss << "  - " << services[i]->getName() << " (" << services[i]->getPrice() << " руб.)\n";
        }
        ss << "Общая стоимость: " << getTotalCost() << " руб.";
    }
    else {
        ss << "Нет";
    }

    return ss.str();
}