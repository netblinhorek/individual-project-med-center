#pragma once

#define YEAR 2026
class Date {
private:
	char reception_year[YEAR];
	char reception_month[13];
	char reception_day[32];
public:
	// конструкторы
	Date();
	Date(char*, char*, char*, char*);
	Date(const Date&);
	// деструктор
	~Date();
	//сеттеры
	void set_reception_year(char* year);
	void set_reception_month(char* month);
	void set_reception_day(char* day);
	//геттеры
	const char* get_reception_year() const;
	const char* get_reception_month() const;
	const char* get_reception_day() const;


	int check_corrections();
	void copy_string(char* name_1, const char* name_2);
	void change_data();
	bool hasDigits(const std::string& str);
private:
	//std::wstring series_of_the_pasport_check;
	//std::wstring number_of_the_pasport_check;
	//std::wstring number_of_the_policy_check;
};
void start_writing_the_data(Date& Date);
