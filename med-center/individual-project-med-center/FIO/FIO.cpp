#include <iostream>
#include <stdexcept>
#include "FIO.h"
#include <string>
#include <regex>

#define CHOICE 3
#define EXIT 0 

void copy_string(char* name_1, const char* name_2) {
	int i = 0;
	int j = 0;
	while (name_2[j] != '\0') {
		if (name_2[j] != ' ') { // Проверяем, не является ли символ пробелом
			name_1[i++] = name_2[j];
		}
		j++;
	}
	name_1[i] = '\0'; // Завершаем строку
}
int FIO::check_corrections() {
	std::cout << "Возникли ошибка(и)." << std::endl;
	for (int i = 0; i < 20; i++) {
		if (iswdigit(first_name[i])) {
			std::wcout << "| Ошибка: В имени не должно быть цифр.\n";
			return 1; // Ошибка
		}
	}

	for (int i = 0; i < 20; i++) {
		if (iswdigit(second_name[i])) {
			std::wcout << "| Ошибка: В фамилии не должно быть цифр.\n";
			return 1; // Ошибка
		}
	}

	for (int i = 0; i < 20; i++) {
		if (iswdigit(last_name[i])) {
			std::wcout << "| Ошибка: В отчестве не должно быть цифр.\n";
			return 1; // Ошибка
		}
	}

	std::wcout << L"Все данные введены корректно.\n"; // Сообщение об успешной проверке
	return 0; // Успех
}


void FIO::capitalize_names() {

	// Приводим первый символ к верхнему регистру
	if (first_name[0] >= 'a' && first_name[0] <= 'z' || first_name[0] >= 'а' && first_name[0] <= 'я') {
		first_name[0] -= 32; // Приводим к верхнему регистру
	}
	if (second_name[0] >= 'a' && second_name[0] <= 'z' || second_name[0] >= 'а' && second_name[0] <= 'я') {
		second_name[0] -= 32;
	}
	if (last_name[0] >= 'a' && last_name[0] <= 'z' || last_name[0] >= 'а' && last_name[0] <= 'я') {
		last_name[0] -= 32;
	}

	// Приводим остальные буквы к нижнему регистру
	for (int j = 1; j < strlen(first_name); j++) {
		if (first_name[j] >= 'A' && first_name[j] <= 'Z' || first_name[j] >= 'А' && first_name[j] <= 'Я') {
			first_name[j] += 32; // Приводим к нижнему регистру
		}
	}

	for (int j = 1; j < strlen(second_name); j++) {
		if (second_name[j] >= 'A' && second_name[j] <= 'Z' || second_name[j] >= 'А' && second_name[j] <= 'Я') {
			second_name[j] += 32; // Приводим к нижнему регистру
		}
	}

	for (int j = 1; j < strlen(last_name); j++) {
		if (last_name[j] >= 'A' && last_name[j] <= 'Z' || last_name[j] >= 'А' && last_name[j] <= 'Я') {
			last_name[j] += 32; // Приводим к нижнему регистру
		}
	}
}
void change_to_fio_message() {
	std::cout << "| 1) фамилию," << std::endl;
	std::cout << "| 2) имя, " << std::endl;
	std::cout << "| 3) отчество? " << std::endl;
	std::cout << "| 0. Выход\n";
	std::cout << "+-----------------------------------------------------------+" << std::endl;
}

void get_selected_menu_item_1(int* menu_item, int item_count) {
	printf("Ваш выбор: ");
	while (1) {
		std::cin >> *menu_item;
		if (*menu_item >= 0 && *menu_item <= item_count) {
			break;
		}
		printf("Некорректный ввод, попробуйте снова: ");
	}
}

void display_anketa(FIO& person) {

	std::cout << "+-----------------------------------------------------------+" << std::endl;
	std::cout << "| *************** Личные данные пользователя ************** |" << std::endl;
	std::cout << "  Введите фамилию: " << person.get_second_name() << std::endl;
	std::cout << "  Введите имя: " << person.get_first_name() << std::endl;
	std::cout << "  Введите отчество: " << person.get_last_name() << std::endl;
	std::cout << "+-----------------------------------------------------------+" << std::endl;
	std::cout << "  Ваши данные: " << person.get_second_name() << " "
		<< person.get_first_name()[0] << "." << person.get_last_name()[0] << "." << std::endl;
	std::cout << "+-----------------------------------------------------------+" << std::endl;
}

void display_edit_menu_red() {
	std::cout << "| *********** Редактирование данных пользователя ********** |" << std::endl;
	std::cout << "| Что вы хотите поменять:                                   |" << std::endl;
	change_to_fio_message();
}

void change_data(FIO& person) {
	int value;
	bool isExit = false;

	while (!isExit) {
		display_edit_menu_red();
		get_selected_menu_item_1(&value, 3);
		if (value == EXIT) {
			isExit = true;
			break;
		}
		do {
			switch (value) {
			case 1:
				std::cout << "  Введите фамилию: ";
				{
					char buffer[20];
					std::cin.getline(buffer, 20);
					person.set_second_name(buffer);
				}
				std::cout << "| Фамилия изменена.                  |\n";
				break;
			case 2:
				std::cout << "  Введите новое имя: ";
				{
					char buffer[50];
					std::cin.getline(buffer, 20);
					person.set_first_name(buffer);
				}
				std::cout << "| Имя изменено.                      |\n";
				break;
			case 3:
				std::cout << "  Введите новое отчество: ";
				{
					char buffer[50];
					std::cin.getline(buffer, 50);
					person.set_last_name(buffer);
				}
				std::cout << "| Отчество изменено.                 |\n";
				break;
			default:
				std::cout << "| Неверный выбор, попробуйте снова.  |\n";
				break;
			}
		} while (person.check_corrections() == 1);

		std::cout << "| Еще что-то? (y/n):  ";
		char choosing_to_change_the_data;
		std::cin >> choosing_to_change_the_data;
		if (choosing_to_change_the_data == 'n') {
			isExit = true;
		}
	}
}

void exit_program(const FIO& person) {
	std::cout << "+-----------------------------------------------------------+" << std::endl;
	std::cout << "До свидания, " << person.get_first_name() << " " << person.get_last_name() << std::endl;
	std::cout << "+-----------------------------------------------------------+" << std::endl;
}

FIO::FIO() {

}
FIO::FIO(char* fn, char* sn, char* ln) {

}
FIO::FIO(const FIO& original) {

}
void FIO::set_first_name(char* fn) {
	std::cin.getline(fn, 20);
	copy_string(first_name, fn);
}
void FIO::set_second_name(char* sn) {
	std::cin.getline(sn, 20);
	copy_string(second_name, sn);
}

void FIO::set_last_name(char* ln) {
	std::cin.getline(ln, 20);
	copy_string(last_name, ln);
}
//геттеры
const char* FIO::get_first_name()  const {
	char* copy = new char[20];
	copy_string(copy, first_name);
	return first_name;
}
const char* FIO::get_second_name() const {
	char* copy = new char[20];
	copy_string(copy, first_name);
	return second_name;
}
const char* FIO::get_last_name() const {
	char* copy = new char[20];
	copy_string(copy, first_name);
	return last_name;
}

void start_writing_the_form(FIO& person) {
	char buffer[20];
	char first_name[20];
	char second_name[20];
	char last_name[20];
	int choosing_to_change_the_data;
	int y, n;
	int value;
	int isExit = 0;
	do {
		std::cout << " Введите фамилию: ";
		person.set_second_name(second_name);
		std::cout << " Введите имя: ";
		person.set_first_name(first_name);
		std::cout << " Введите отчество: ";
		person.set_last_name(last_name);
	} while (person.check_corrections() == 1);
	person.capitalize_names();
	display_anketa(person);
	change_data(person);
	exit_program(person);
}