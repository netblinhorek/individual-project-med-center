#include "cabinet.h"
#include <sstream>

Cabinet::Cabinet() : number("") {}

Cabinet::Cabinet(const std::string& number) : number(number) {}

Cabinet::~Cabinet() {
    // ќчищаем оборудование, но не удал€ем его, так как оно может использоватьс€ в других местах
    clearEquipment();
}

std::string Cabinet::getNumber() const {
    return number;
}

const TVector<Equipment*>& Cabinet::getEquipment() const {
    return equipment;
}

void Cabinet::setNumber(const std::string& number) {
    this->number = number;
}

void Cabinet::addEquipment(Equipment* equipment) {
    if (equipment && !hasEquipment(equipment)) {
        this->equipment.push_back(equipment);
    }
}

void Cabinet::removeEquipment(Equipment* equipment) {
    if (!equipment) return;

    for (size_t i = 0; i < this->equipment.get_size(); ++i) {
        if (this->equipment[i] == equipment) {
            TVector<Equipment*> newEquipment;
            for (size_t j = 0; j < this->equipment.get_size(); ++j) {
                if (j != i) {
                    newEquipment.push_back(this->equipment[j]);
                }
            }
            this->equipment = newEquipment;
            break;
        }
    }
}

bool Cabinet::hasEquipment(Equipment* equipment) const {
    if (!equipment) return false;

    for (size_t i = 0; i < this->equipment.get_size(); ++i) {
        if (this->equipment[i] == equipment) {
            return true;
        }
    }
    return false;
}

void Cabinet::clearEquipment() {
    equipment.clear();
}

std::string Cabinet::getInfo() const {
    std::stringstream ss;
    ss << " абинет: " << number << "\n";
    ss << "ќборудование: ";

    if (equipment.get_size() == 0) {
        ss << "нет";
    }
    else {
        for (size_t i = 0; i < equipment.get_size(); ++i) {
            ss << equipment[i]->getName();
            if (i < equipment.get_size() - 1) {
                ss << ", ";
            }
        }
    }

    return ss.str();
}