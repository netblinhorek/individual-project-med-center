#pragma once
#include <string>

// ������������ ��� ����� �����
enum class ServiceType {
    PRIMARY_VISIT,    // ��������� �����
    REPEAT_VISIT,     // ��������� �����
    ONE_TIME_SERVICE  // ������������ ������
};

class Service {
private:
    int id;
    std::string name;
    std::string description;
    double price;
    ServiceType type;
    int durationMinutes; // ������������ ������ � �������

public:
    // ������������
    Service();
    Service(int id, const std::string& name, const std::string& description,
        double price, ServiceType type, int durationMinutes);

    // �������
    int getId() const;
    std::string getName() const;
    std::string getDescription() const;
    double getPrice() const;
    ServiceType getType() const;
    int getDurationMinutes() const;
    std::string getTypeString() const;

    // �������
    void setId(int id);
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setPrice(double price);
    void setType(ServiceType type);
    void setDurationMinutes(int durationMinutes);

    // ������
    std::string getInfo() const;
};
