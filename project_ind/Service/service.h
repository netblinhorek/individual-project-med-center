#pragma once
#include <string>

// Перечисление для типов услуг
enum class ServiceType {
    PRIMARY_VISIT,    // Первичный прием
    REPEAT_VISIT,     // Повторный прием
    ONE_TIME_SERVICE  // Единоразовая услуга
};

class Service {
private:
    int id;
    std::string name;
    std::string description;
    double price;
    ServiceType type;
    int durationMinutes; // Длительность услуги в минутах

public:
    // Конструкторы
    Service();
    Service(int id, const std::string& name, const std::string& description,
        double price, ServiceType type, int durationMinutes);

    // Геттеры
    int getId() const;
    std::string getName() const;
    std::string getDescription() const;
    double getPrice() const;
    ServiceType getType() const;
    int getDurationMinutes() const;
    std::string getTypeString() const;

    // Сеттеры
    void setId(int id);
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setPrice(double price);
    void setType(ServiceType type);
    void setDurationMinutes(int durationMinutes);

    // Методы
    std::string getInfo() const;
};
