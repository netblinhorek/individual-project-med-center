#include <iostream>
#include <stdexcept>
#include "time_for_registration.h"
#include <cstring>
#include <cctype>
#include <string>
#include <regex>
#include <set>
#define EXIT 0 
#define CHOICE 2
#define HOUR 24
#define MINUTE 60

void check(char hour, char minute) {
	if (hour < 7 || hour > 20) {
		throw std::logic_error("������ �����: ����� �� ����������� ����������� ���������!");
	}
	if (minute < 00 || minute > 60) {
		throw std::logic_error("������ �����: ����� �� ����������� ����������� ���������!");
	}
}

int Time::check_corrections() {
	for (int i = 0; reception_hour[i] != '\0'; i++) {
		if (std::isdigit(static_cast<unsigned char>(reception_hour[i]))) {
			std::cout << "| ������: � ������ ���� ��������� �� ������ ���� ����.\n";
			return 1; // ������
		}
	}

	for (int i = 0; reception_minute[i] != '\0'; i++) {
		if (!std::isdigit(static_cast<unsigned char>(reception_minute[i]))) {
			std::cout << "| ������: � ������ ������ ������ ���� ������ �����.\n";
			return 1; // ������
		}
	}
	std::cout << "| ��� ������ ������� ���������.\n";
	return 0; // ��� � �������
}

void Time::copy_string(char* name_1, const char* name_2) {
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
Time::Time() {
}
Time::Time(char* hour, char* minute) {
}
Time::Time(const Time& original) {
}
// ����������
Time::~Time() {
}
//�������
void Time::set_reception_hour(char* hour) {
	std::cin.getline(hour, HOUR);
	copy_string(reception_hour, hour);
}
void Time::set_reception_minute(char* minute) {
	std::cin.getline(minute, MINUTE);
	copy_string(reception_minute, minute);
}

//�������
const char* Time::get_reception_hour() const {
	char* copy = new char[HOUR];
	return reception_hour;
}
const char* Time::get_reception_minute() const {
	char* copy = new char[MINUTE];
	//copy_string(copy, series_of_the_pasport);
	return reception_minute;
}

void display_anketa(Time& time) {

	std::cout << "+-----------------------------------------------------------+" << std::endl;
	std::cout << "| *************** ������ ������ ������������ ************** |" << std::endl;
	std::cout << "  ��� ������: " << time.get_reception_hour() << std::endl;
	std::cout << "  ������ ������: " << time.get_reception_minute() << std::endl;
	std::cout << "+-----------------------------------------------------------+" << std::endl;
}
void change_to_choice_message() {
	std::cout << "| 1) ��� ������," << std::endl;
	std::cout << "| 2) ������ ������, " << std::endl;
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
	std::cout << "| ************* �������������� ������� ������ ************* |" << std::endl;
	std::cout << "| ��� �� ������ ��������:                                   |" << std::endl;
	change_to_choice_message();
}

void change_data(Time& time) {
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
				std::cout << "   ������� ��� ������: ";
				{

					char buffer[HOUR];
					std::cin.getline(buffer, HOUR);
					time.set_reception_hour(buffer);
				}
				std::cout << "|  ��� ��� ��������.                         |\n";
				break;
			case 2:
				std::cout << "  ������� ������ ������ ��������: ";
				{
					char buffer[MINUTE];
					std::cin.getline(buffer, MINUTE);
					time.set_reception_minute(buffer);
				}
				std::cout << "| ����� ������ �������.                      |\n";
				break;

			default:
				std::cout << "| �������� �����, ���������� �����.  |\n";
				break;
			}
		} while (time.check_corrections() == 1);

		std::cout << "| ��� ���-��? (y/n):  ";
		char choosing_to_change_the_data;
		std::cin >> choosing_to_change_the_data;
		if (choosing_to_change_the_data == 'n') {
			isExit = true;
		}
	}
}

void exit_program(const Time& time) {
	std::cout << "+------------------------------------+" << std::endl;
	std::cout << "�� ��������" << std::endl;
	std::cout << "+------------------------------------+" << std::endl;
}
bool input_data(Time& time, char& hour, char& minute) {
	char reception_hour[HOUR];
	char reception_minute[MINUTE];
	std::cout << "  ������� ��� ������: ";
	time.set_reception_hour(reception_hour); //�������
	std::cout << "  ������� ������ ������ (�����): ";
	time.set_reception_minute(reception_minute);

	try {
		check(*reception_hour, *reception_minute);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what();
		std::cout << " ���������� �����." << std::endl;
		return false;
	}
	return true;
}

void start_writing_the_data(Time& time) {
	char reception_hour[HOUR];
	char reception_minute[MINUTE];
	int choosing_to_change_the_data;
	int y, n;
	int value;
	int isExit = 0;
	do {
		input_data(time, *reception_hour, *reception_minute);
		display_anketa(time);
	} while (time.check_corrections() == 1);
	change_data(time);
	exit_program(time);
}