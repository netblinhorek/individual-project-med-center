#pragma once

enum Position {
	Doctor,
	Registration, 
	SupportStaff
};

class Employee {
	//Date _employment_date;
	Position _position;
	//Date* _working_days;
	float _salary;
private:
	Employee() {
	}
	Employee(Date* employment_date, Position* position, Date* working_days, float* salary) {
	}
	Employee(const Employee& original) {
	}
	// деструктор
	~Employee() {
	}
	//сеттеры
	//void set_employment_date(Date employment_date);
	void set_position(Position position);
	//void set_working_days(Date* working_days);
	void set_salary(float salary);
	//геттеры
	//const Date get_employment_date() const;
	const Position get_position() const;
	//const Date* get_working_days() const;
	const float* get_salary() const;
};
