#pragma once
#include <string>

class ClientsDocuments {
private:
    std::string _series;
    std::string passport_Number;
    std::string _snils;
    std::string medical_Policy;

public:
    // ������������
    ClientsDocuments();
    ClientsDocuments(const std::string& series, const std::string& passportNumber, const std::string& snils, const std::string& medicalPolicy);

    // �������
    std::string get_Passport_Series() const;
    std::string get_Passport_Number() const;
    std::string get_Snils() const;
    std::string get_Medical_Policy() const;

    // �������
    void set_Passport_Series(const std::string& passportNumber);
    void set_Passport_Number(const std::string& passportNumber);
    void set_Snils(const std::string& snils);
    void set_Medical_Policy(const std::string& medicalPolicy);

    // ������
    bool is_Valid() const;
};
