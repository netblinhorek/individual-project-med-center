#include <iostream>
#include "./Time/time_for_registration.h"
#include "./Time/time_for_registration.cpp"
#include "./FIO/FIO.h"
#include "./FIO/FIO.cpp"
#include "./Calendar/calendar_of_dates.h"
#include "./Calendar/calendar_of_dates.cpp"
#include "./Documents/client's_documents.h"
#include "./Documents/client's_documents.cpp"
#include "./Doctors/doctors.h"
#include "./Doctors/doctors.cpp"
#include "./Client/client.h"
#include "./Client/client.cpp"
#include "./Employee/employee.h"
#include "./Employee/employee.cpp"
#include "./Visiting/visiting.cpp"
#include "./Visiting/visiting.h"
#include "./Date/date.h"
#include "./Date/date.cpp"
#include "./Cabinet/cabinet.cpp"
#include "./Cabinet/cabinet.h"
#include "./Equipment/equipment.cpp"
#include "./Equipment/equipment.h"
#include "./Schedule/schedule.cpp"
#include "./Schedule/schedule.h"


#include <cstdio>
#include <Windows.h>


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Time time;
	FIO person;
	Date date;
	//Doctors doctor;
	
	start_writing_the_form(person);
	start_writing_the_data(time);
	start_writing_the_data(date);
}