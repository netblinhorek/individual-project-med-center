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
			std::cout << "| ������: � ������������ ��������� �� ������ ���� ����.\n";
			return 1; // ������
		}
	}
	return 0; // ��� � �������, ���� ���

	for (int i = 0; series_of_the_pasport[i] != '0'; i++) {
		if (std::isdigit(static_cast<unsigned char>(series_of_the_pasport[i]))) {
			std::cout << "| ������: � ����� ��������� �� ������ ���� ����.\n";
			return 1; // ������
		}
	}
	return 0; // ��� � �������

	for (int i = 0; number_of_the_pasport[i] != '0'; i++) {
		if (!std::isdigit(static_cast<unsigned char>(number_of_the_pasport[i]))) {
			std::cout << "| ������: � ������ ��������� ������ ���� ������ �����.\n";
			return 1; // ������
		}
	}
	return 0; // ��� � �������


	for (int i = 0; number_of_the_policy[i] != '0'; i++) {
		if (!std::isdigit(static_cast<unsigned char>(number_of_the_policy[i]))) {
			std::cout << "| ������: � ������ ������ ���� ������ �����.\n";
			return 1; // ������
		}


		return 0; // ��� � �������
	}
	std::cout << "| ��� ������ ������� ���������.\n";
}

void Documentation::capitalize_names() {
	for (int j = 0; name_of_the_document[j] != '\0'; j++) {
		if (name_of_the_document[j] >= '�' && name_of_the_document[j] <= '�') {
			name_of_the_document[j] += ('�' - '�'); // �������� � ������� ��������
		}
		// ��� ��������� ����� �������� ����������� ��������
	}
}
void Documentation::copy_string(char* name_1, const char* name_2) {
	int i = 0;
	int j = 0;
	while (name_2[j] != '\0') {
		if (name_2[j] != ' ') { // ���������, �� �������� �� ������ ��������
			name_1[i++] = name_2[j];
		}
		j++;
	}
	name_1[i] = '\0'; // ��������� ������
}


// ������������
Documentation::Documentation() {
}
Documentation::Documentation(char* name, char* series, char* number_pasport, char* policy) {
}
Documentation::Documentation(const Documentation& original) {
}
// ����������
Documentation::~Documentation() {
}
//�������
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
//�������
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
	std::cout << "| *************** ������ ������ ������������ ************** |" << std::endl;
	std::cout << "  ������������ ���������: " << document.get_name_of_the_document() << std::endl;
	std::cout << "  ����� ��������: " << document.get_series_of_the_pasport() << std::endl;
	std::cout << "  ����� ��������: " << document.get_number_of_the_pasport() << std::endl;
	std::cout << "  ����� ������: " << document.get_number_of_the_policy() << std::endl;
	std::cout << "+-----------------------------------------------------------+" << std::endl;
}
void change_to_choice_message() {
	std::cout << "| 1) ������������ ���������," << std::endl;
	std::cout << "| 2) ����� ��������, " << std::endl;
	std::cout << "| 3) ����� ��������? " << std::endl;
	std::cout << "| 4) ����� ��������? " << std::endl;
	std::cout << "| 0. �����\n";
	std::cout << "+------------------------------------+\n";
}
void get_selected_menu_item(int* menu_item, int item_count) {
	printf("��� �����: ");
	while (1) {
		std::cin >> *menu_item;
		if (*menu_item >= 0 && *menu_item <= item_count) {
			break;
		}
		printf("������������ ����, ���������� �����: ");
	}
}

void display_edit_menu() {
	std::cout << "| *********** �������������� ������ ������������ ********** |" << std::endl;
	std::cout << "| ��� �� ������ ��������:                                   |" << std::endl;
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
				std::cout << "   ������� ������������ ���������: ";
				{
					char buffer[8];
					std::cin.getline(buffer, 8);
					document.set_name_of_the_document(buffer);
				}
				std::cout << "| ������������ ��������� ��������.                  |\n";
				break;
			case 2:
				std::cout << "  ������� ����� ����� ��������: ";
				{
					char buffer[5];
					std::cin.getline(buffer, 5);
					document.set_series_of_the_pasport(buffer);
				}
				std::cout << "| ����� �������� ��������.                      |\n";
				break;
			case 3:
				std::cout << "  ������� ����� ����� ��������: ";
				{
					char buffer[7];
					std::cin.getline(buffer, 7);
					document.set_number_of_the_pasport(buffer);
				}
				std::cout << "| ����� �������� ��������.                 |\n";
				break;
			case 4:
				std::cout << "  ������� ����� ����� ������: ";
				{
					char buffer[17];
					std::cin.getline(buffer, 17);
					document.set_number_of_the_policy(buffer);
				}
				std::cout << "| ����� �������� ��������.                 |\n";
				break;

			default:
				std::cout << "| �������� �����, ���������� �����.  |\n";
				break;
			}
		} while (document.check_corrections() == 1);

		std::cout << "| ��� ���-��? (y/n):  ";
		char choosing_to_change_the_data;
		std::cin >> choosing_to_change_the_data;
		if (choosing_to_change_the_data == 'n') {
			isExit = true;
		}
	}
}

void exit_program(const Documentation& document) {
	std::cout << "+------------------------------------+" << std::endl;
	std::cout << "�� ��������" << std::endl;
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
		std::cout << "  ������� ������������ ���������: ";
		document.set_name_of_the_document(name_of_the_document); //�������
		std::cout << "  ������� ����� ��������: ";
		document.set_series_of_the_pasport(series_of_the_pasport);
		std::cout << "  ������� ����� ��������: ";
		document.set_number_of_the_pasport(number_of_the_pasport);
		std::cout << "  ������� ����� ������: ";
		document.set_number_of_the_policy(number_of_the_policy);
		document.capitalize_names(); // �������
		display_anketa(document);
	} while (document.check_corrections() == 1);
	change_data(document);
	exit_program(document);
}