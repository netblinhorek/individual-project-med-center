#pragma once
class Documentation {
private:
	char name_of_the_document[8];
	char series_of_the_pasport[5];
	char number_of_the_pasport[7];
	char number_of_the_policy[17];
public:
	// конструкторы
	Documentation();
	Documentation(char*, char*, char*, char*);
	Documentation(const Documentation&);
	// деструктор
	~Documentation();
	//сеттеры
	void set_name_of_the_document(char* name);
	void set_series_of_the_pasport(char* series);
	void set_number_of_the_pasport(char* number_pasport);
	void set_number_of_the_policy(char* policy);
	//геттеры
	const char* get_name_of_the_document() const;
	const char* get_series_of_the_pasport() const;
	const char* get_number_of_the_pasport() const;
	const char* get_number_of_the_policy() const;

	void capitalize_names();
	int check_corrections();
	void copy_string(char* name_1, const char* name_2);
	void change_data();
	bool hasDigits(const std::string& str);
private:
	//std::wstring series_of_the_pasport_check;
	//std::wstring number_of_the_pasport_check;
	//std::wstring number_of_the_policy_check;
};
void start_writing_the_documents(Documentation& document);
