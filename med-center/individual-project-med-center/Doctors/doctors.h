#pragma once

class Doctor {
	char _profession;
	int _work_experience;
	char _clinic;
	char _category;
	char _specialization;
	int _cost;
public:

	Doctor() {
	}
	Doctor(char* name, char* series, char* number_pasport, char* policy) {
	}
	Doctor(const Doctor& original) {
	}
	// деструктор
	~Doctor() {
	}


	//сеттеры
	void set_profession(char* professional);
	void set_work_experience(int* work_experience);
	void set_clinic(char* clinic);
	void set_category(char* category);
	void set_specialization(char* specialization);
	void set_cost(int* cost);
	//геттеры
	const char* get_profession() const;
	const int* get_work_experience() const;
	const char* get_clinic() const;
	const char* get_category() const;
	const char* get_specialization() const;
	const int* get_cost() const;



};