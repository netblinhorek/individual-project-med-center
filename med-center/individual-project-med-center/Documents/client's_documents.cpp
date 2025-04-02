#include <iostream>
#include <stdexcept>
#include "client.h"
#include <cstring>
#include <cctype>
#include <string>
#include <regex>
#define EXIT 0 
#define CHOICE 4


int Documentation::check_corrections() {
	for (int i = 0; name_of_the_document[i] != '0'; i++) {
		if (iswdigit(name_of_the_document[i])) {
			std::cout << "| Ошибка: В наименовании документа не должно быть цифр.\n";
			return 1; // Ошибка
		}
	}
	return 0; // Все в порядке, цифр нет

	for (int i = 0; series_of_the_pasport[i] != '0'; i++) {
		if (std::isdigit(static_cast<unsigned char>(series_of_the_pasport[i]))) {
			std::cout << "| Ошибка: В серии документа не должно быть букв.\n";
			return 1; // Ошибка
		}
	}
	return 0; // Все в порядке

	for (int i = 0; number_of_the_pasport[i] != '0'; i++) {
		if (!std::isdigit(static_cast<unsigned char>(number_of_the_pasport[i]))) {
			std::cout << "| Ошибка: В номере документа должны быть только цифры.\n";
			return 1; // Ошибка
		}
	}
	return 0; // Все в порядке


	for (int i = 0; number_of_the_policy[i] != '0'; i++) {
		if (!std::isdigit(static_cast<unsigned char>(number_of_the_policy[i]))) {
			std::cout << "| Ошибка: В полисе должны быть только цифры.\n";
			return 1; // Ошибка
		}


		return 0; // Все в порядке
	}
	std::cout << "| Все данные введены корректно.\n";
}

void Documentation::capitalize_names() {
	for (int j = 0; name_of_the_document[j] != '\0'; j++) {
		if (name_of_the_document[j] >= 'А' && name_of_the_document[j] <= 'Я') {
			name_of_the_document[j] += ('а' - 'А'); // Приводим к нижнему регистру
		}
		// Для кириллицы можно добавить аналогичную проверку
	}
}
void Documentation::copy_string(char* name_1, const char* name_2) {
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
Documentation::Documentation() {
}
Documentation::Documentation(char* name, char* series, char* number_pasport, char* policy) {
}
Documentation::Documentation(const Documentation& original) {
}
// деструктор
Documentation::~Documentation() {
}
//сеттеры
void Documentation::set_name_of_the_document(char* name) {
	std::cin.getline(name, 8);
	copy_string(name_of_the_document, name);
}
void Documentation::set_series_of_the_pasport(char* series) {
	std::cin.getline(series, 5);
	copy_string(series_of_the_pasport, series);
}
void Documentation::set_number_of_the_pasport(char* number_pasport) {
	std::cin.getline(number_pasport, 7);
	copy_string(number_of_the_pasport, number_pasport);
}
void Documentation::set_number_of_the_policy(char* policy) {
	std::cin.getline(policy, 17);
	copy_string(number_of_the_policy, policy);
}
//геттеры
const char* Documentation::get_name_of_the_document() const {
	char* copy = new char[8];
	return name_of_the_document;
}
const char* Documentation::get_series_of_the_pasport() const {
	char* copy = new char[5];
	//copy_string(copy, series_of_the_pasport);
	return series_of_the_pasport;
}
const char* Documentation::get_number_of_the_pasport() const {
	char* copy = new char[7];
	//copy_string(copy, number_of_the_pasport);
	return number_of_the_pasport;
}
const char* Documentation::get_number_of_the_policy() const {
	char* copy = new char[17];
	//copy_string(copy, number_of_the_policy);
	return number_of_the_policy;
}

void display_anketa(Documentation& document) {

	std::cout << "+-----------------------------------------------------------+" << std::endl;
	std::cout << "| *************** Личные данные пользователя ************** |" << std::endl;
	std::cout << "  Наименование документа: " << document.get_name_of_the_document() << std::endl;
	std::cout << "  Серия паспорта: " << document.get_series_of_the_pasport() << std::endl;
	std::cout << "  Номер паспорта: " << document.get_number_of_the_pasport() << std::endl;
	std::cout << "  Номер полиса: " << document.get_number_of_the_policy() << std::endl;
	std::cout << "+-----------------------------------------------------------+" << std::endl;
}
void change_to_choice_message() {
	std::cout << "| 1) наименование документа," << std::endl;
	std::cout << "| 2) серию паспорта, " << std::endl;
	std::cout << "| 3) номер паспорта? " << std::endl;
	std::cout << "| 4) номер паспорта? " << std::endl;
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
	std::cout << "| *********** Редактирование данных пользователя ********** |" << std::endl;
	std::cout << "| Что вы хотите поменять:                                   |" << std::endl;
	change_to_choice_message();
}

void change_data(Documentation& document) {
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
				std::cout << "   Введите наименование документа: ";
				{
					char buffer[8];
					std::cin.getline(buffer, 8);
					document.set_name_of_the_document(buffer);
				}
				std::cout << "| Наименование документа изменено.                  |\n";
				break;
			case 2:
				std::cout << "  Введите новую серию паспорта: ";
				{
					char buffer[5];
					std::cin.getline(buffer, 5);
					document.set_series_of_the_pasport(buffer);
				}
				std::cout << "| Серия паспорта изменена.                      |\n";
				break;
			case 3:
				std::cout << "  Введите новый номер паспорта: ";
				{
					char buffer[7];
					std::cin.getline(buffer, 7);
					document.set_number_of_the_pasport(buffer);
				}
				std::cout << "| Номер паспорта изменено.                 |\n";
				break;
			case 4:
				std::cout << "  Введите новый номер полиса: ";
				{
					char buffer[17];
					std::cin.getline(buffer, 17);
					document.set_number_of_the_policy(buffer);
				}
				std::cout << "| Номер паспорта изменено.                 |\n";
				break;

			default:
				std::cout << "| Неверный выбор, попробуйте снова.  |\n";
				break;
			}
		} while (document.check_corrections() == 1);

		std::cout << "| Еще что-то? (y/n):  ";
		char choosing_to_change_the_data;
		std::cin >> choosing_to_change_the_data;
		if (choosing_to_change_the_data == 'n') {
			isExit = true;
		}
	}
}

void exit_program(const Documentation& document) {
	std::cout << "+------------------------------------+" << std::endl;
	std::cout << "До свидания" << std::endl;
	std::cout << "+------------------------------------+" << std::endl;
}

void start_writing_the_documents(Documentation& document) {
	char name_of_the_document[8];
	char series_of_the_pasport[5];
	char number_of_the_pasport[7];
	char number_of_the_policy[17];
	int choosing_to_change_the_data;
	int y, n;
	int value;
	int isExit = 0;
	do {
		std::cout << "  Введите наименование документа: ";
		document.set_name_of_the_document(name_of_the_document); //паспорт
		std::cout << "  Введите серию паспорта: ";
		document.set_series_of_the_pasport(series_of_the_pasport);
		std::cout << "  Введите номер паспорта: ";
		document.set_number_of_the_pasport(number_of_the_pasport);
		std::cout << "  Введите номер полиса: ";
		document.set_number_of_the_policy(number_of_the_policy);
		document.capitalize_names(); // регистр
		display_anketa(document);
	} while (document.check_corrections() == 1);
	change_data(document);
	exit_program(document);
}