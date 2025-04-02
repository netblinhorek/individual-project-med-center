#pragma once
#include "./Client/client.h"

class Visit {
	char doctor_recommendations;
private:
	Visit() {
	}
	Visit(char* doctor_recommendations) {
	}
	Visit(const Visit& original) {
	}
	// деструктор
	~Visit() {
	}
	//сеттеры
	void set_number(char doctor_recommendations);

	//геттеры
	const char get_doctor_recommendations() const;

};