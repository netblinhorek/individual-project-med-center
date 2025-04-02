#include <iostream>
#include <stdexcept>
#include "date.h"
#include <cstring>
#include <cctype>
#include <string>
#include <regex>
#include <set>
#define EXIT 0 
#define CHOICE 3
#define YEAR 2026
void check(char year, char month, char day) {
	if (year < 2025 || year > 2027) {
		throw std::logic_error("Ошибка ввода: число не принадлежит правильному диапазону!");
	}
	if (month < 0 || month > 12) {
		throw std::logic_error("Ошибка ввода: число не принадлежит правильному диапазону!");
	}
	if (day < 0 || day > 32) {
		throw std::logic_error("Ошибка ввода: число не принадлежит правильному диапазону!");
	}

}

int Date::check_corrections() {
	for (int i = 0; reception_year[i] != '\0'; i++) {
		if (std::isdigit(static_cast<unsigned char>(reception_year[i]))) {
			std::cout << "| Ошибка: В выборе года документа не должно быть букв.\n";
			return 1; // Ошибка
		}
	}

	for (int i = 0; reception_month[i] != '\0'; i++) {
		if (!std::isdigit(static_cast<unsigned char>(reception_month[i]))) {
			std::cout << "| Ошибка: В выборе месяца должны быть только цифры.\n";
			return 1; // Ошибка
		}
	}
	for (int i = 0; reception_day[i] != '\0'; i++) {
		if (!std::isdigit(static_cast<unsigned char>(reception_day[i]))) {
			std::cout << "| Ошибка: В выборе дня должны быть только цифры.\n";
			return 1; // Ошибка
		}
	}
	std::cout << "| Все данные введены корректно.\n";
	return 0; // Все в порядке
}

void Date::copy_string(char* name_1, const char* name_2) {
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


// конструкторы
Date::Date() {
}
Date::Date(char* name, char* series, char* number_pasport, char* policy) {
}
Date::Date(const Date& original) {
}
// деструктор
Date::~Date() {
}
//сеттеры
void Date::set_reception_year(char* year) {
	std::cin.getline(year, YEAR);
	copy_string(reception_year, year);
}
void Date::set_reception_month(char* month) {
	std::cin.getline(month, 13);
	copy_string(reception_month, month);
}
void Date::set_reception_day(char* day) {
	std::cin.getline(day, 32);
	copy_string(reception_day, day);
}
//геттеры
const char* Date::get_reception_year() const {
	char* copy = new char[8];
	return reception_year;
}
const char* Date::get_reception_month() const {
	char* copy = new char[5];
	//copy_string(copy, series_of_the_pasport);
	return reception_month;
}
const char* Date::get_reception_day() const {
	char* copy = new char[7];
	//copy_string(copy, number_of_the_pasport);
	return reception_day;
}
void display_anketa(Date& Date) {

	std::cout << "+-----------------------------------------------------------+" << std::endl;
	std::cout << "| *************** Личные данные пользователя ************** |" << std::endl;
	std::cout << "  Год приема: " << Date.get_reception_year() << std::endl;
	std::cout << "  Месяц приема: " << Date.get_reception_month() << std::endl;
	std::cout << "  День приема: " << Date.get_reception_day() << std::endl;
	std::cout << "+-----------------------------------------------------------+" << std::endl;
}
void change_to_choice_message() {
	std::cout << "| 1) год приема," << std::endl;
	std::cout << "| 2) месяц приема, " << std::endl;
	std::cout << "| 3) день приема? " << std::endl;
	std::cout << "| 0. Выход\n";
	std::cout << "+------------------------------------+\n";
}
void get_selected_menu_item(int* menu_item, int item_count) {
	printf("Ваш выбор: ");
	while (1) {
		std::cin >> *menu_item;
		if (*menu_item >= 0 && *menu_item <= item_count) {
			break;
		}
		printf("Некорректный ввод, попробуйте снова: ");
	}
}

void display_edit_menu() {
	std::cout << "| *************** Редактирование даты приема ************** |" << std::endl;
	std::cout << "| Что вы хотите поменять:                                   |" << std::endl;
	change_to_choice_message();
}

void change_data(Date& Date) {
	int value;
	bool isExit = false;

	while (!isExit) {
		display_edit_menu();
		get_selected_menu_item(&value, 4);
		if (value == EXIT) {
			isExit = true;
			break;
		}
		do {
			switch (value) {
			case 1:
				std::cout << "   Введите год приема: ";
				{

					char buffer[YEAR];
					std::cin.getline(buffer, YEAR);
					Date.set_reception_year(buffer);
				}
				std::cout << "|  Год приема изменено.                         |\n";
				break;
			case 2:
				std::cout << "  Введите месяц приема паспорта: ";
				{
					char buffer[13];
					std::cin.getline(buffer, 13);
					Date.set_reception_month(buffer);
				}
				std::cout << "| Месяц приема изменен.                      |\n";
				break;
			case 3:
				std::cout << "  Введите новый день приема: ";
				{
					char buffer[32];
					std::cin.getline(buffer, 32);
					Date.set_reception_day(buffer);
				}
				std::cout << "| День приема изменен.                 |\n";
				break;
			default:
				std::cout << "| Неверный выбор, попробуйте снова.  |\n";
				break;
			}
		} while (Date.check_corrections() == 1);

		std::cout << "| Еще что-то? (y/n):  ";
		char choosing_to_change_the_data;
		std::cin >> choosing_to_change_the_data;
		if (choosing_to_change_the_data == 'n') {
			isExit = true;
		}
	}
}

void exit_program(const Date& Date) {
	std::cout << "+------------------------------------+" << std::endl;
	std::cout << "До свидания" << std::endl;
	std::cout << "+------------------------------------+" << std::endl;
}
bool input_data(Date& Date, char& year, char& month, char& day) {
	char reception_year[YEAR];
	char reception_month[13];
	char reception_day[32];
	std::cout << "  Введите год приема: ";
	Date.set_reception_year(reception_year); //паспорт
	std::cout << "  Введите месяц приема (цифры): ";
	Date.set_reception_month(reception_month);
	std::cout << "  Введите день приема: ";
	Date.set_reception_day(reception_day);

	try {
		check(*reception_year, *reception_month, *reception_day);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what();
		std::cout << " Попробуйте снова." << std::endl;
		return false;
	}
	return true;
}

void start_writing_the_data(Date& Date) {
	char reception_year[YEAR];
	char reception_month[13];
	char reception_day[32];
	int choosing_to_change_the_data;
	int y, n;
	int value;
	int isExit = 0;
	do {
		input_data(Date, *reception_year, *reception_month, *reception_day);
		display_anketa(Date);
	} while (Date.check_corrections() == 1);
	change_data(Date);
	exit_program(Date);
}