#pragma once

class FIO {
private:
	char first_name[20];
	char second_name[20];
	char last_name[20];
public:
	// конструкторы
	FIO();
	FIO(char*, char*, char*);
	FIO(const FIO&);
	// деструктор
	~FIO() {}
	void set_first_name(char* fn);
	void set_second_name(char* sn);
	void set_last_name(char* ln);

	const char* get_first_name() const;
	const char* get_second_name() const;
	const char* get_last_name() const;

	void capitalize_names();
	int check_corrections();
};
void display_edit_menu();
void change_to_fio_message();
void display_anketa(FIO&);
void change_data(FIO&);
void exit_program(const FIO& person);