#pragma once
#include "date.h"
#include "../Time_for_registration/time_for_registration.h"
#include "../Service/service.h"
#include "../Cabinet/cabinet.h"
#include "tvector.h"
#include <string>

class Client;
class Doctor;

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
    TVector<Service*> services; // ������ �����, ��������������� �� ����� ���������

public:
    // ������������
    Visiting();
    Visiting(int id, const Date& date, const Time& time, Client* client, Doctor* doctor, Cabinet* cabinet);

    // �������
    int getId() const;
    Date getDate() const;
    Time getTime() const;
    Client* getClient() const;
    Doctor* getDoctor() const;
    Cabinet* getCabinet() const;
    std::string getDiagnosis() const;
    std::string getTreatment() const;
    const TVector<Service*>& getServices() const;

    // �������
    void setId(int id);
    void setDate(const Date& date);
    void setTime(const Time& time);
    void setClient(Client* client);
    void setDoctor(Doctor* doctor);
    void setCabinet(Cabinet* cabinet);
    void setDiagnosis(const std::string& diagnosis);
    void setTreatment(const std::string& treatment);

    // ������ ��� ������ � ��������
    void addService(Service* service);
    void removeService(int serviceId);
    Service* findService(int serviceId) const;
    double getTotalCost() const;

    // ������
    std::string getInfo() const;
};