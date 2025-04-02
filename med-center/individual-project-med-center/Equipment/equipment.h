#pragma once

enum Status {
	Working,
	Requires_repair,
	Requires_replacement,
	On_service

};

class Equipment {
	char _name;
	Status status;

private:
	Equipment() {
	}
	Equipment(char* nume, Status* name) {
	}
	Equipment(const Equipment& original) {
	}
	// деструктор
	~Equipment() {
	}
	//сеттеры
	void set_number(char* name);
	void set_name(Status* status);

	//геттеры
	const int get_name() const;
	const Status* get_status() const;


};