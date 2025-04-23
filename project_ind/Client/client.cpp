#include "client.h"
#include <sstream>

Client::Client() {}

Client::Client(const FIO& fio, const ClientsDocuments& documents)
    : fio(fio), documents(documents) {}

FIO Client::getFIO() const {
    return fio;
}

ClientsDocuments Client::getDocuments() const {
    return documents;
}

const TVector<int>& Client::getVisitingIds() const {
    return visitingIds;
}

void Client::setFIO(const FIO& fio) {
    this->fio = fio;
}

void Client::setDocuments(const ClientsDocuments& documents) {
    this->documents = documents;
}

void Client::addVisiting(int visitingId) {
    visitingIds.push_back(visitingId);
}

void Client::removeVisiting(int visitingId) {
    for (size_t i = 0; i < visitingIds.get_size(); ++i) {
        if (visitingIds[i] == visitingId) {
            TVector<int> newVisitingIds;
            for (size_t j = 0; j < visitingIds.get_size(); ++j) {
                if (j != i) {
                    newVisitingIds.push_back(visitingIds[j]);
                }
            }
            visitingIds = newVisitingIds;
            break;
        }
    }
}

bool Client::hasVisiting(int visitingId) const {
    for (size_t i = 0; i < visitingIds.get_size(); ++i) {
        if (visitingIds[i] == visitingId) {
            return true;
        }
    }
    return false;
}

std::string Client::getInfo() const {
    std::stringstream ss;
    ss << "Клиент: " << fio.get_full_name() << "\n"
        << "Паспорт (номер): " << documents.get_Passport_Number() << "\n"
        << "Паспорт (серия): " << documents.get_Passport_Series() << "\n"
        << "СНИЛС: " << documents.get_Snils() << "\n"
        << "Полис: " << documents.get_Medical_Policy();
    return ss.str();
}