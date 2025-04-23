#include "client's_documents.h"

ClientsDocuments::ClientsDocuments() : _series(""), passport_Number(""), _snils(""), medical_Policy("") {}

ClientsDocuments::ClientsDocuments(const std::string& series, const std::string& passportNumber, const std::string& snils, const std::string& medicalPolicy)
    : _series(series), passport_Number(passportNumber), _snils(snils), medical_Policy(medicalPolicy) {}

std::string ClientsDocuments::get_Passport_Series() const {
    return _series;
}
std::string ClientsDocuments::get_Passport_Number() const {
    return passport_Number;
}

std::string ClientsDocuments::get_Snils() const {
    return _snils;
}

std::string ClientsDocuments::get_Medical_Policy() const {
    return medical_Policy;
}

void ClientsDocuments::set_Passport_Series(const std::string& series) {
    this->_series = series;
}

void ClientsDocuments::set_Passport_Number(const std::string& passportNumber) {
    this->passport_Number = passportNumber;
}

void ClientsDocuments::set_Snils(const std::string& snils) {
    this->_snils = snils;
}

void ClientsDocuments::set_Medical_Policy(const std::string& medicalPolicy) {
    this->medical_Policy = medicalPolicy;
}

bool ClientsDocuments::is_Valid() const {
    return !_series.empty() && !passport_Number.empty() && !_snils.empty() && !medical_Policy.empty();
}