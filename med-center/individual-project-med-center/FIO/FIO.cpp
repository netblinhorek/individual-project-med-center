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
		if (name_2[j] != ' ') { // ���������, �� �������� �� ������ ��������
			name_1[i++] = name_2[j];
		}
		j++;
	}
	name_1[i] = '\0'; // ��������� ������
}
int FIO::check_corrections() {
	std::cout << "�������� ������(�)." << std::endl;
	for (int i = 0; i < 20; i++) {
		if (iswdigit(first_name[i])) {
			std::wcout << "| ������: � ����� �� ������ ���� ����.\n";
			return 1; // ������
		}
	}

	for (int i = 0; i < 20; i++) {
		if (iswdigit(second_name[i])) {
			std::wcout << "| ������: � ������� �� ������ ���� ����.\n";
			return 1; // ������
		}
	}

	for (int i = 0; i < 20; i++) {
		if (iswdigit(last_name[i])) {
			std::wcout << "| ������: � �������� �� ������ ���� ����.\n";
			return 1; // ������
		}
	}

	std::wcout << L"��� ������ ������� ���������.\n"; // ��������� �� �������� ��������
	return 0; // �����
}


void FIO::capitalize_names() {

	// �������� ������ ������ � �������� ��������
	if (first_name[0] >= 'a' && first_name[0] <= 'z' || first_name[0] >= '�' && first_name[0] <= '�') {
		first_name[0] -= 32; // �������� � �������� ��������
	}
	if (second_name[0] >= 'a' && second_name[0] <= 'z' || second_name[0] >= '�' && second_name[0] <= '�') {
		second_name[0] -= 32;
	}
	if (last_name[0] >= 'a' && last_name[0] <= 'z' || last_name[0] >= '�' && last_name[0] <= '�') {
		last_name[0] -= 32;
	}

	// �������� ��������� ����� � ������� ��������
	for (int j = 1; j < strlen(first_name); j++) {
		if (first_name[j] >= 'A' && first_name[j] <= 'Z' || first_name[j] >= '�' && first_name[j] <= '�') {
			first_name[j] += 32; // �������� � ������� ��������
		}
	}

	for (int j = 1; j < strlen(second_name); j++) {
		if (second_name[j] >= 'A' && second_name[j] <= 'Z' || second_name[j] >= '�' && second_name[j] <= '�') {
			second_name[j] += 32; // �������� � ������� ��������
		}
	}

	for (int j = 1; j < strlen(last_name); j++) {
		if (last_name[j] >= 'A' && last_name[j] <= 'Z' || last_name[j] >= '�' && last_name[j] <= '�') {
			last_name[j] += 32; // �������� � ������� ��������
		}
	}
}
void change_to_fio_message() {
	std::cout << "| 1) �������," << std::endl;
	std::cout << "| 2) ���, " << std::endl;
	std::cout << "| 3) ��������? " << std::endl;
	std::cout << "| 0. �����\n";
	std::cout << "+-----------------------------------------------------------+" << std::endl;
}

void get_selected_menu_item_1(int* menu_item, int item_count) {
	printf("��� �����: ");
	while (1) {
		std::cin >> *menu_item;
		if (*menu_item >= 0 && *menu_item <= item_count) {
			break;
		}
		printf("������������ ����, ���������� �����: ");
	}
}

void display_anketa(FIO& person) {

	std::cout << "+-----------------------------------------------------------+" << std::endl;
	std::cout << "| *************** ������ ������ ������������ ************** |" << std::endl;
	std::cout << "  ������� �������: " << person.get_second_name() << std::endl;
	std::cout << "  ������� ���: " << person.get_first_name() << std::endl;
	std::cout << "  ������� ��������: " << person.get_last_name() << std::endl;
	std::cout << "+-----------------------------------------------------------+" << std::endl;
	std::cout << "  ���� ������: " << person.get_second_name() << " "
		<< person.get_first_name()[0] << "." << person.get_last_name()[0] << "." << std::endl;
	std::cout << "+-----------------------------------------------------------+" << std::endl;
}

void display_edit_menu_red() {
	std::cout << "| *********** �������������� ������ ������������ ********** |" << std::endl;
	std::cout << "| ��� �� ������ ��������:                                   |" << std::endl;
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
				std::cout << "  ������� �������: ";
				{
					char buffer[20];
					std::cin.getline(buffer, 20);
					person.set_second_name(buffer);
				}
				std::cout << "| ������� ��������.                  |\n";
				break;
			case 2:
				std::cout << "  ������� ����� ���: ";
				{
					char buffer[50];
					std::cin.getline(buffer, 20);
					person.set_first_name(buffer);
				}
				std::cout << "| ��� ��������.                      |\n";
				break;
			case 3:
				std::cout << "  ������� ����� ��������: ";
				{
					char buffer[50];
					std::cin.getline(buffer, 50);
					person.set_last_name(buffer);
				}
				std::cout << "| �������� ��������.                 |\n";
				break;
			default:
				std::cout << "| �������� �����, ���������� �����.  |\n";
				break;
			}
		} while (person.check_corrections() == 1);

		std::cout << "| ��� ���-��? (y/n):  ";
		char choosing_to_change_the_data;
		std::cin >> choosing_to_change_the_data;
		if (choosing_to_change_the_data == 'n') {
			isExit = true;
		}
	}
}

void exit_program(const FIO& person) {
	std::cout << "+-----------------------------------------------------------+" << std::endl;
	std::cout << "�� ��������, " << person.get_first_name() << " " << person.get_last_name() << std::endl;
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
//�������
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
		std::cout << " ������� �������: ";
		person.set_second_name(second_name);
		std::cout << " ������� ���: ";
		person.set_first_name(first_name);
		std::cout << " ������� ��������: ";
		person.set_last_name(last_name);
	} while (person.check_corrections() == 1);
	person.capitalize_names();
	display_anketa(person);
	change_data(person);
	exit_program(person);
}