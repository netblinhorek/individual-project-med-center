#include <string>
#include "tvector.h"
#include "equipment.h"

class Cabinet {
private:
    std::string number;
    TVector<Equipment*> equipment;

public:
    // Конструкторы
    Cabinet();
    Cabinet(const std::string& number);

    // Деструктор
    ~Cabinet();

    // Геттеры
    std::string getNumber() const;
    const TVector<Equipment*>& getEquipment() const;

    // Сеттеры
    void setNumber(const std::string& number);

    // Методы для работы с оборудованием
    void addEquipment(Equipment* equipment);
    void removeEquipment(Equipment* equipment);
    bool hasEquipment(Equipment* equipment) const;
    void clearEquipment();

    // Вспомогательные методы
    std::string getInfo() const;
};