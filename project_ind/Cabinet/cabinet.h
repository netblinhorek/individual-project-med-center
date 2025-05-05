#ifndef CABINET_H
#define CABINET_H

#include <string>
#include "tvector.h"
#include "../Equipment/equipment.h"

class Cabinet {
private:
    std::string number;
    TVector<Equipment*> equipment;

public:
    // 
    Cabinet();
    Cabinet(const std::string& number);

    // 
    ~Cabinet();

    // 
    std::string getNumber() const;
    const TVector<Equipment*>& getEquipment() const;

    // 
    void setNumber(const std::string& number);

    //    
    void addEquipment(Equipment* equipment);
    void removeEquipment(Equipment* equipment);
    bool hasEquipment(Equipment* equipment) const;
    void clearEquipment();

    //  
    std::string getInfo() const;
};

#endif // CABINET_H