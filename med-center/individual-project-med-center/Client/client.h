#pragma once
#include "./Visiting/visiting.cpp"
#include "./Visiting/visiting.h"
class Client {
	char _address;
	char _mail;
	char _services;
	;
public:

	Client() {
	}
	Client(char* name, char* series, char* number_pasport, char* policy) {
	}
	Client(const Client& original) {
	}
	// ����������
	~Client() {
	}
	//�������
	void set_address(char* address);
	void set_mail(char* mail);
	void set_services(char* services);
	void set_visiting(char* visiting);
	//�������
	const char* get_address() const;
	const char* get_mail() const;
	const char* get_services() const;
	const char* get_visiting() const;
};