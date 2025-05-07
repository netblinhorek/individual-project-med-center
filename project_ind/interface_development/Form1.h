#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			serviceToDoctors = gcnew Dictionary<String^, List<String^>^>();
			allServices = gcnew List<String^>();

			LoadTimeSlots();
			LoadDoctors();
			LoadServices();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ name_med_center;
	private: System::Windows::Forms::Label^ doctor;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ date;
	private: System::Windows::Forms::Label^ cost;
	private: System::Windows::Forms::Label^ long_service;
	private: System::Windows::Forms::Label^ sename;
	private: System::Windows::Forms::Label^ name;
	private: System::Windows::Forms::Label^ last_name;
	private: System::Windows::Forms::Label^ document;
	private: System::Windows::Forms::Label^ seria;
	private: System::Windows::Forms::Label^ number;
	private: System::Windows::Forms::Label^ snils;
	public: System::Windows::Forms::MonthCalendar^ calendar;
	private:

	private:











	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ med_polis;
	private: System::Windows::Forms::Label^ data_entry;
	private: System::Windows::Forms::TextBox^ text_sename;
	private: System::Windows::Forms::TextBox^ text_name;
	private: System::Windows::Forms::TextBox^ text_last_name;
	private: System::Windows::Forms::TextBox^ text_document;
	private: System::Windows::Forms::TextBox^ text_seria;
	private: System::Windows::Forms::TextBox^ text_number;
	private: System::Windows::Forms::TextBox^ text_snils;
	private: System::Windows::Forms::TextBox^ text_med_polis;








	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Button^ record;



	private: System::Windows::Forms::DomainUpDown^ cost_of_reception;
	private: System::Windows::Forms::ComboBox^ choose_a_service;
	private: System::Windows::Forms::ComboBox^ choose_a_doctor;
	private: System::Collections::Generic::List<String^>^ allServices;
	private: System::Collections::Generic::Dictionary<String^, System::Collections::Generic::List<String^>^>^ serviceToDoctors;
	private: System::Windows::Forms::ComboBox^ time_of_reception;











	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->name_med_center = (gcnew System::Windows::Forms::Label());
			this->doctor = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->date = (gcnew System::Windows::Forms::Label());
			this->cost = (gcnew System::Windows::Forms::Label());
			this->long_service = (gcnew System::Windows::Forms::Label());
			this->sename = (gcnew System::Windows::Forms::Label());
			this->name = (gcnew System::Windows::Forms::Label());
			this->last_name = (gcnew System::Windows::Forms::Label());
			this->document = (gcnew System::Windows::Forms::Label());
			this->seria = (gcnew System::Windows::Forms::Label());
			this->number = (gcnew System::Windows::Forms::Label());
			this->snils = (gcnew System::Windows::Forms::Label());
			this->calendar = (gcnew System::Windows::Forms::MonthCalendar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->med_polis = (gcnew System::Windows::Forms::Label());
			this->data_entry = (gcnew System::Windows::Forms::Label());
			this->text_sename = (gcnew System::Windows::Forms::TextBox());
			this->text_name = (gcnew System::Windows::Forms::TextBox());
			this->text_last_name = (gcnew System::Windows::Forms::TextBox());
			this->text_document = (gcnew System::Windows::Forms::TextBox());
			this->text_seria = (gcnew System::Windows::Forms::TextBox());
			this->text_number = (gcnew System::Windows::Forms::TextBox());
			this->text_snils = (gcnew System::Windows::Forms::TextBox());
			this->text_med_polis = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->record = (gcnew System::Windows::Forms::Button());
			this->cost_of_reception = (gcnew System::Windows::Forms::DomainUpDown());
			this->choose_a_service = (gcnew System::Windows::Forms::ComboBox());
			this->choose_a_doctor = (gcnew System::Windows::Forms::ComboBox());
			this->time_of_reception = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// name_med_center
			// 
			this->name_med_center->AutoSize = true;
			this->name_med_center->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->name_med_center->Location = System::Drawing::Point(233, 32);
			this->name_med_center->Name = L"name_med_center";
			this->name_med_center->Size = System::Drawing::Size(580, 67);
			this->name_med_center->TabIndex = 0;
			this->name_med_center->Text = L"Медицинский центр";
			// 
			// doctor
			// 
			this->doctor->AutoSize = true;
			this->doctor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->doctor->Location = System::Drawing::Point(12, 245);
			this->doctor->Name = L"doctor";
			this->doctor->Size = System::Drawing::Size(81, 33);
			this->doctor->TabIndex = 1;
			this->doctor->Text = L"Врач";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 183);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 33);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Услуги";
			// 
			// date
			// 
			this->date->AutoSize = true;
			this->date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->date->Location = System::Drawing::Point(12, 301);
			this->date->Name = L"date";
			this->date->Size = System::Drawing::Size(191, 33);
			this->date->TabIndex = 3;
			this->date->Text = L"Дата приёма";
			// 
			// cost
			// 
			this->cost->AutoSize = true;
			this->cost->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cost->Location = System::Drawing::Point(4, 732);
			this->cost->Name = L"cost";
			this->cost->Size = System::Drawing::Size(161, 33);
			this->cost->TabIndex = 4;
			this->cost->Text = L"Стоимость";
			// 
			// long_service
			// 
			this->long_service->AutoSize = true;
			this->long_service->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->long_service->Location = System::Drawing::Point(4, 687);
			this->long_service->Name = L"long_service";
			this->long_service->Size = System::Drawing::Size(103, 33);
			this->long_service->TabIndex = 5;
			this->long_service->Text = L"Время";
			// 
			// sename
			// 
			this->sename->AllowDrop = true;
			this->sename->AutoSize = true;
			this->sename->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sename->ForeColor = System::Drawing::SystemColors::ControlText;
			this->sename->Location = System::Drawing::Point(562, 219);
			this->sename->Name = L"sename";
			this->sename->Size = System::Drawing::Size(142, 33);
			this->sename->TabIndex = 6;
			this->sename->Text = L"Фамилия";
			// 
			// name
			// 
			this->name->AllowDrop = true;
			this->name->AutoSize = true;
			this->name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->name->ForeColor = System::Drawing::SystemColors::ControlText;
			this->name->Location = System::Drawing::Point(562, 272);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(73, 33);
			this->name->TabIndex = 7;
			this->name->Text = L"Имя";
			// 
			// last_name
			// 
			this->last_name->AllowDrop = true;
			this->last_name->AutoSize = true;
			this->last_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->last_name->ForeColor = System::Drawing::SystemColors::ControlText;
			this->last_name->Location = System::Drawing::Point(563, 325);
			this->last_name->Name = L"last_name";
			this->last_name->Size = System::Drawing::Size(141, 33);
			this->last_name->TabIndex = 8;
			this->last_name->Text = L"Отчество";
			// 
			// document
			// 
			this->document->AllowDrop = true;
			this->document->AutoSize = true;
			this->document->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->document->ForeColor = System::Drawing::SystemColors::ControlText;
			this->document->Location = System::Drawing::Point(562, 383);
			this->document->Name = L"document";
			this->document->Size = System::Drawing::Size(149, 33);
			this->document->TabIndex = 9;
			this->document->Text = L"Документ";
			// 
			// seria
			// 
			this->seria->AllowDrop = true;
			this->seria->AutoSize = true;
			this->seria->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->seria->ForeColor = System::Drawing::SystemColors::ControlText;
			this->seria->Location = System::Drawing::Point(562, 441);
			this->seria->Name = L"seria";
			this->seria->Size = System::Drawing::Size(100, 33);
			this->seria->TabIndex = 10;
			this->seria->Text = L"Серия";
			// 
			// number
			// 
			this->number->AllowDrop = true;
			this->number->AutoSize = true;
			this->number->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->number->ForeColor = System::Drawing::SystemColors::ControlText;
			this->number->Location = System::Drawing::Point(562, 499);
			this->number->Name = L"number";
			this->number->Size = System::Drawing::Size(105, 33);
			this->number->TabIndex = 11;
			this->number->Text = L"Номер";
			// 
			// snils
			// 
			this->snils->AllowDrop = true;
			this->snils->AutoSize = true;
			this->snils->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->snils->ForeColor = System::Drawing::SystemColors::ControlText;
			this->snils->Location = System::Drawing::Point(562, 551);
			this->snils->Name = L"snils";
			this->snils->Size = System::Drawing::Size(119, 33);
			this->snils->TabIndex = 12;
			this->snils->Text = L"СНИЛС";
			// 
			// calendar
			// 
			this->calendar->Location = System::Drawing::Point(45, 347);
			this->calendar->MaxDate = System::DateTime(2025, 12, 31, 0, 0, 0, 0);
			this->calendar->MinDate = System::DateTime(2025, 1, 1, 0, 0, 0, 0);
			this->calendar->Name = L"calendar";
			this->calendar->TabIndex = 13;
			this->calendar->TodayDate = System::DateTime(2025, 5, 6, 0, 0, 0, 0);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(1, 99);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(1072, 51);
			this->label2->TabIndex = 14;
			this->label2->Text = L"---------------------------------------------------------------------------";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(338, 183);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 51);
			this->label3->TabIndex = 15;
			// 
			// med_polis
			// 
			this->med_polis->AllowDrop = true;
			this->med_polis->AutoSize = true;
			this->med_polis->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->med_polis->ForeColor = System::Drawing::SystemColors::ControlText;
			this->med_polis->Location = System::Drawing::Point(563, 602);
			this->med_polis->Name = L"med_polis";
			this->med_polis->Size = System::Drawing::Size(168, 33);
			this->med_polis->TabIndex = 16;
			this->med_polis->Text = L"Мед. полис";
			// 
			// data_entry
			// 
			this->data_entry->AllowDrop = true;
			this->data_entry->AutoSize = true;
			this->data_entry->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->data_entry->ForeColor = System::Drawing::SystemColors::ControlText;
			this->data_entry->Location = System::Drawing::Point(608, 150);
			this->data_entry->Name = L"data_entry";
			this->data_entry->Size = System::Drawing::Size(410, 42);
			this->data_entry->TabIndex = 17;
			this->data_entry->Text = L"Введите ваши данные";
			// 
			// text_sename
			// 
			this->text_sename->AllowDrop = true;
			this->text_sename->Location = System::Drawing::Point(749, 219);
			this->text_sename->Name = L"text_sename";
			this->text_sename->Size = System::Drawing::Size(293, 31);
			this->text_sename->TabIndex = 18;
			// 
			// text_name
			// 
			this->text_name->AllowDrop = true;
			this->text_name->Location = System::Drawing::Point(749, 276);
			this->text_name->Name = L"text_name";
			this->text_name->Size = System::Drawing::Size(293, 31);
			this->text_name->TabIndex = 19;
			// 
			// text_last_name
			// 
			this->text_last_name->AllowDrop = true;
			this->text_last_name->Location = System::Drawing::Point(749, 329);
			this->text_last_name->Name = L"text_last_name";
			this->text_last_name->Size = System::Drawing::Size(293, 31);
			this->text_last_name->TabIndex = 20;
			// 
			// text_document
			// 
			this->text_document->AllowDrop = true;
			this->text_document->Location = System::Drawing::Point(749, 387);
			this->text_document->Name = L"text_document";
			this->text_document->Size = System::Drawing::Size(293, 31);
			this->text_document->TabIndex = 21;
			// 
			// text_seria
			// 
			this->text_seria->AllowDrop = true;
			this->text_seria->Location = System::Drawing::Point(749, 445);
			this->text_seria->Name = L"text_seria";
			this->text_seria->Size = System::Drawing::Size(293, 31);
			this->text_seria->TabIndex = 22;
			// 
			// text_number
			// 
			this->text_number->AllowDrop = true;
			this->text_number->Location = System::Drawing::Point(749, 503);
			this->text_number->Name = L"text_number";
			this->text_number->Size = System::Drawing::Size(293, 31);
			this->text_number->TabIndex = 23;
			// 
			// text_snils
			// 
			this->text_snils->AllowDrop = true;
			this->text_snils->Location = System::Drawing::Point(749, 555);
			this->text_snils->Name = L"text_snils";
			this->text_snils->Size = System::Drawing::Size(293, 31);
			this->text_snils->TabIndex = 24;
			// 
			// text_med_polis
			// 
			this->text_med_polis->AllowDrop = true;
			this->text_med_polis->Location = System::Drawing::Point(749, 606);
			this->text_med_polis->Name = L"text_med_polis";
			this->text_med_polis->Size = System::Drawing::Size(293, 31);
			this->text_med_polis->TabIndex = 25;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(458, 137);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(17, 25);
			this->label4->TabIndex = 26;
			this->label4->Text = L"|";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(458, 417);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(17, 25);
			this->label5->TabIndex = 27;
			this->label5->Text = L"|";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(458, 451);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(17, 25);
			this->label6->TabIndex = 28;
			this->label6->Text = L"|";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(458, 490);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(17, 25);
			this->label7->TabIndex = 29;
			this->label7->Text = L"|";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(458, 530);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(17, 25);
			this->label8->TabIndex = 30;
			this->label8->Text = L"|";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(458, 571);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(17, 25);
			this->label9->TabIndex = 31;
			this->label9->Text = L"|";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(458, 610);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(17, 25);
			this->label10->TabIndex = 32;
			this->label10->Text = L"|";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(458, 652);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(17, 25);
			this->label11->TabIndex = 33;
			this->label11->Text = L"|";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(458, 687);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(17, 25);
			this->label12->TabIndex = 34;
			this->label12->Text = L"|";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(458, 722);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(17, 25);
			this->label13->TabIndex = 35;
			this->label13->Text = L"|";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(458, 758);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(17, 25);
			this->label14->TabIndex = 36;
			this->label14->Text = L"|";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(458, 245);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(17, 25);
			this->label15->TabIndex = 37;
			this->label15->Text = L"|";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(458, 204);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(17, 25);
			this->label16->TabIndex = 38;
			this->label16->Text = L"|";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(458, 167);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(17, 25);
			this->label17->TabIndex = 39;
			this->label17->Text = L"|";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(458, 279);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(17, 25);
			this->label18->TabIndex = 40;
			this->label18->Text = L"|";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(458, 309);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(17, 25);
			this->label19->TabIndex = 41;
			this->label19->Text = L"|";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(458, 347);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(17, 25);
			this->label20->TabIndex = 42;
			this->label20->Text = L"|";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(458, 383);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(17, 25);
			this->label21->TabIndex = 43;
			this->label21->Text = L"|";
			// 
			// record
			// 
			this->record->AllowDrop = true;
			this->record->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->record->Location = System::Drawing::Point(568, 687);
			this->record->Name = L"record";
			this->record->Size = System::Drawing::Size(444, 78);
			this->record->TabIndex = 44;
			this->record->Text = L"Записаться на приём";
			this->record->UseVisualStyleBackColor = true;
			this->record->Click += gcnew System::EventHandler(this, &Form1::record_Click);
			// 
			// cost_of_reception
			// 
			this->cost_of_reception->Location = System::Drawing::Point(176, 737);
			this->cost_of_reception->Name = L"cost_of_reception";
			this->cost_of_reception->Size = System::Drawing::Size(257, 31);
			this->cost_of_reception->TabIndex = 48;
			// 
			// choose_a_service
			// 
			this->choose_a_service->FormattingEnabled = true;
			this->choose_a_service->Location = System::Drawing::Point(126, 183);
			this->choose_a_service->Name = L"choose_a_service";
			this->choose_a_service->Size = System::Drawing::Size(316, 33);
			this->choose_a_service->TabIndex = 49;
			// 
			// choose_a_doctor
			// 
			this->choose_a_doctor->FormattingEnabled = true;
			this->choose_a_doctor->Location = System::Drawing::Point(99, 249);
			this->choose_a_doctor->Name = L"choose_a_doctor";
			this->choose_a_doctor->Size = System::Drawing::Size(334, 33);
			this->choose_a_doctor->TabIndex = 50;
			// 
			// time_of_reception
			// 
			this->time_of_reception->FormattingEnabled = true;
			this->time_of_reception->Location = System::Drawing::Point(126, 687);
			this->time_of_reception->Name = L"time_of_reception";
			this->time_of_reception->Size = System::Drawing::Size(316, 33);
			this->time_of_reception->TabIndex = 51;
			this->time_of_reception->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::time_of_reception_SelectedIndexChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1081, 792);
			this->Controls->Add(this->time_of_reception);
			this->Controls->Add(this->choose_a_doctor);
			this->Controls->Add(this->choose_a_service);
			this->Controls->Add(this->cost_of_reception);
			this->Controls->Add(this->record);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->text_med_polis);
			this->Controls->Add(this->text_snils);
			this->Controls->Add(this->text_number);
			this->Controls->Add(this->text_seria);
			this->Controls->Add(this->text_document);
			this->Controls->Add(this->text_last_name);
			this->Controls->Add(this->text_name);
			this->Controls->Add(this->text_sename);
			this->Controls->Add(this->data_entry);
			this->Controls->Add(this->med_polis);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->calendar);
			this->Controls->Add(this->snils);
			this->Controls->Add(this->number);
			this->Controls->Add(this->seria);
			this->Controls->Add(this->document);
			this->Controls->Add(this->last_name);
			this->Controls->Add(this->name);
			this->Controls->Add(this->sename);
			this->Controls->Add(this->long_service);
			this->Controls->Add(this->cost);
			this->Controls->Add(this->date);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->doctor);
			this->Controls->Add(this->name_med_center);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void choose_a_service_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (choose_a_service->SelectedItem != nullptr) {
			String^ selectedService = choose_a_service->SelectedItem->ToString();
			choose_a_doctor->Items->Clear();


		}
	}
	private: System::Void choose_a_doctor_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (choose_a_doctor->SelectedItem != nullptr) {
			String^ selectedDoctor = choose_a_doctor->SelectedItem->ToString();
			choose_a_doctor->Items->Clear();


		}
	}
	private: void LoadDoctors() {
		try {
			String^ filePath = System::IO::Path::Combine(
				Environment::GetFolderPath(Environment::SpecialFolder::Desktop),
				"individual-project-med-center",
				"individual-project-med-center",
				"project_ind",
				"data",
				"doctors.txt");

			// Проверка существования файла
			if (!System::IO::File::Exists(filePath)) {
				MessageBox::Show("Файл с врачами не найден:\n" + filePath,
					"Ошибка",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
				return;
			}

			// Чтение файла
			array<String^>^ lines = System::IO::File::ReadAllLines(filePath);
			choose_a_doctor->Items->Clear();

			// Обработка каждой строки
			for each (String ^ line in lines) {
				if (!String::IsNullOrWhiteSpace(line)) {
					String^ doctorName = line->Trim();

					// Удаляем номер, если он есть в начале строки
					if (doctorName->Length > 0 && Char::IsDigit(doctorName[0])) {
						int spaceIndex = doctorName->IndexOf(' ');
						if (spaceIndex > 0) {
							doctorName = doctorName->Substring(spaceIndex + 1)->Trim();
						}
					}

					// Добавляем врача в список
					if (!String::IsNullOrWhiteSpace(doctorName)) {
						choose_a_doctor->Items->Add(doctorName);
					}
				}
			}

			// Сортировка списка врачей
			choose_a_doctor->Sorted = true;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка при загрузке списка врачей:\n" + ex->Message,
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
		}
	}
	
private: void LoadServices() {
	String^ filePath = System::IO::Path::Combine(
		Environment::GetFolderPath(Environment::SpecialFolder::Desktop),
		"individual-project-med-center",
		"individual-project-med-center",
		"project_ind",
		"data",
		"services.txt");

	array<String^>^ lines = System::IO::File::ReadAllLines(filePath);
	allServices->Clear();
	choose_a_service->Items->Clear();

	for each (String ^ line in lines) {
		if (!String::IsNullOrWhiteSpace(line)) {
			String^ cleanService = line->Trim();
			// Удаляем номер, если он есть
			if (cleanService->Length > 0 && Char::IsDigit(cleanService[0])) {
				int spaceIndex = cleanService->IndexOf(' ');
				if (spaceIndex > 0) {
					cleanService = cleanService->Substring(spaceIndex + 1)->Trim();
				}
			}
			allServices->Add(cleanService);
			choose_a_service->Items->Add(cleanService);
		}
	}
	choose_a_service->Sorted = true;
}
	   private: void LoadTimeSlots() {
		   try {
			   String^ filePath = System::IO::Path::Combine(
				   Environment::GetFolderPath(Environment::SpecialFolder::Desktop),
				   "individual-project-med-center",
				   "individual-project-med-center",
				   "project_ind",
				   "data",
				   "time_slots.txt");

			   if (!System::IO::File::Exists(filePath)) {
				   MessageBox::Show(L"???? ? ?????????? ??????? ?? ??????:\n" + filePath,
					   L"??????",
					   MessageBoxButtons::OK,
					   MessageBoxIcon::Error);
				   return;
			   }

			   array<String^>^ timeSlots = System::IO::File::ReadAllLines(filePath, System::Text::Encoding::UTF8);
			   time_of_reception->Items->Clear();

			   for each (String ^ timeSlot in timeSlots) {
				   if (!String::IsNullOrWhiteSpace(timeSlot)) {
					   String^ cleanTimeSlot = timeSlot->Trim();
					   if (!String::IsNullOrWhiteSpace(cleanTimeSlot)) {
						   time_of_reception->Items->Add(cleanTimeSlot);
					   }
				   }
			   }
		   }
		   catch (Exception^ ex) {
			   MessageBox::Show(L"?????? ??? ???????? ????????? ??????:\n" + ex->Message,
				   L"??????",
				   MessageBoxButtons::OK,
				   MessageBoxIcon::Error);
		   }
	   }

	private: System::Void time_of_reception_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		try {
				String^ filePath = System::IO::Path::Combine(
					Environment::GetFolderPath(Environment::SpecialFolder::Desktop),
					"individual-project-med-center",
					"individual-project-med-center",
					"project_ind",
					"data",
					"time_slots.txt");

				array<String^>^ lines = System::IO::File::ReadAllLines(filePath, System::Text::Encoding::UTF8);
				serviceToDoctors->Clear();
			if (!System::IO::File::Exists(filePath)) {
				MessageBox::Show(L"Файл с временными слотами не найден:\n" + filePath,
					L"Ошибка",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
				return;
			}

			// Читаем все строки из файла
			array<String^>^ timeSlots = System::IO::File::ReadAllLines(filePath, System::Text::Encoding::UTF8);
			time_of_reception->Items->Clear();

			// Добавляем каждый временной слот в ComboBox
			for each (String ^ timeSlot in timeSlots) {
				if (!String::IsNullOrWhiteSpace(timeSlot)) {
					String^ cleanTimeSlot = timeSlot->Trim();
					if (!String::IsNullOrWhiteSpace(cleanTimeSlot)) {
						time_of_reception->Items->Add(cleanTimeSlot);
					}
				}
			}

			// Если есть временные слоты, показываем выпадающий список
			if (time_of_reception->Items->Count > 0) {
				time_of_reception->DroppedDown = true;
			}
			else {
				MessageBox::Show(L"Нет доступных временных слотов",
					L"Информация",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(L"Ошибка при загрузке временных слотов:\n" + ex->Message,
				L"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
		}
	}
private: System::Void record_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Получаем данные из элементов управления
		String^ sename = text_sename->Text;
		String^ name = text_name->Text;
		String^ last_name = text_last_name->Text;
		String^ service = choose_a_service->SelectedItem->ToString();
		String^ doctor = choose_a_doctor->Text;
		String^ date = calendar->Text;
		//	String^ cabinet = cabinet->Text;
		String^ time = time_of_reception->Text;
		String^ cost = cost_of_reception->Text;
		// Формируем строку с информацией
		String^ info = L"=== Информация о записи ===\n";
		info += L"Фамилия: " + sename + L"\n";
		info += L"Имя: " + name + L"\n";
		info += L"Отчество: " + last_name + L"\n";
		info += L"Услуга: " + service + L"\n";
		info += L"Врач: " + doctor + L"\n";
		//	info += L"Кабинет: " + cabinet + L"\n";
		info += L"Дата: " + date + L"\n";
		info += L"Время: " + time + L"\n";
		info += L"Стоимость: " + cost + L"\n";


		info += L"===========================\n";

		// Выводим сообщение
		MessageBox::Show(info, L"Информация о записи", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (Exception^ ex) {
		// Обработка ошибки
		MessageBox::Show(L"Произошла ошибка: " + ex->Message, L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

	};
}
