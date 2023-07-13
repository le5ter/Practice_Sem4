#pragma once
#include <sstream>
#include <msclr\marshal_cppstd.h>
#include <list>
#include "Student.h"
#include <functional>
#include <iostream>

namespace PracticeSem4 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>

	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		
		MyForm1(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(250, 490);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 70);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Закрыть";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(65, 65);
			this->listBox1->Margin = System::Windows::Forms::Padding(0);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(570, 400);
			this->listBox1->TabIndex = 1;
			// 
			// MyForm1
			// 
			this->ClientSize = System::Drawing::Size(700, 600);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"MyForm1";
			this->Text = L"Динамический список";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		System::Drawing::Font^ font;
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		font = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 25.0F, FontStyle::Regular);
		listBox1->Font = font;

		std::list<Student> students;
		StreamReader^ sr = gcnew StreamReader("Data.txt");
		String^ line;
		std::string newline, name, lastname;
		int marks[5];
		while ((line = sr->ReadLine()) != nullptr)
		{
			newline = msclr::interop::marshal_as<std::string>(line);
			std::stringstream ss(newline);
			ss >> name >> lastname >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4];
			Student stud = Student(name, lastname, marks);
			students.push_front(stud);
		}
		students.sort(Student::f1);

		this->listBox1->Items->Clear();
		for (auto it = students.begin(); it != students.end(); it++)
		{
			std::string str = it->Get_lastname() + " " + it->Get_str_avarage();
			String^ str1 = gcnew String(str.c_str());
			listBox1->Items->Add(str1);
		}
		sr->Close();
		delete sr;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
};
}
