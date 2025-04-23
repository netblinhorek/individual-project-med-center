#pragma once
#include "date.h"
#include "time_for_registration.h"
#include <string>

class Client;
class Doctor;
class Cabinet;

class Visiting {
private:
    int id;
    Date date;
    Time time;
    Client* client;
    Doctor* doctor;
    Cabinet* cabinet;
    std::string diagnosis;
    std::string treatment;

public:
    // Конструкторы
    Visiting();
    Visiting(int id, const Date& date, const Time& time, Client* client, Doctor* doctor, Cabinet* cabinet);

    // Геттеры
    int getId() const;
    Date getDate() const;
    Time getTime() const;
    Client* getClient() const;
    Doctor* getDoctor() const;
    Cabinet* getCabinet() const;
    std::string getDiagnosis() const;
    std::string getTreatment() const;

    // Сеттеры
    void setId(int id);
    void setDate(const Date& date);
    void setTime(const Time& time);
    void setClient(Client* client);
    void setDoctor(Doctor* doctor);
    void setCabinet(Cabinet* cabinet);
    void setDiagnosis(const std::string& diagnosis);
    void setTreatment(const std::string& treatment);

    // Методы
    std::string getInfo() const;
};