#pragma once
#include "./Equipment/equipment.h"
#include "./Equipment/equipment.cpp"


class Cabinet {
	int _number;
	//Equipment* _name;
	//Equipment* _status;

private:
	Cabinet() {
	}
	Cabinet(int* number/*, Equipment* name, Equipment* status*/) {
	}
	Cabinet(const Cabinet& original) {
	}
	// деструктор
	~Cabinet() {
	}
	//сеттеры
	void set_number(int number);
	//void set_name(Equipment* name);
	//void set_condition(Equipment* _status);
	
	//геттеры
	const int get_employment_date() const;
	//const Equipment* get_name() const;
	//const Equipment* get_status() const;
};