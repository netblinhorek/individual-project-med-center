#pragma once
#define HOUR 24
#define MINUTE 60
class Time {
private:
	char reception_hour[HOUR];
	char reception_minute[MINUTE];
public:
	// конструкторы
	Time();
	Time(char*, char*);
	Time(const Time&);
	// деструктор
	~Time();
	//сеттеры
	void set_reception_hour(char* hour);
	void set_reception_minute(char* minute);

	//геттеры
	const char* get_reception_hour() const;
	const char* get_reception_minute() const;



	int check_corrections();
	void copy_string(char* name_1, const char* name_2);
	void change_data();
	bool hasDigits(const std::string& str);
private:
	//std::wstring series_of_the_pasport_check;
	//std::wstring number_of_the_pasport_check;
	//std::wstring number_of_the_policy_check;
};
void start_writing_the_data(Time& time);
