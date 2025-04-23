#pragma once
#include "FIO.h"
#include "client's_documents.h"
#include "tvector.h"
#include <string>

class Client {
private:
    FIO fio;
    ClientsDocuments documents;
    TVector<int> visitingIds; // ID ���������

public:
    // ������������
    Client();
    Client(const FIO& fio, const ClientsDocuments& documents);

    // �������
    FIO getFIO() const;
    ClientsDocuments getDocuments() const;
    const TVector<int>& getVisitingIds() const;

    // �������
    void setFIO(const FIO& fio);
    void setDocuments(const ClientsDocuments& documents);

    // ������
    void addVisiting(int visitingId);
    void removeVisiting(int visitingId);
    bool hasVisiting(int visitingId) const;
    std::string getInfo() const;
};
