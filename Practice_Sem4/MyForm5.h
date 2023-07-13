#pragma once
#include <msclr\marshal_cppstd.h>
#include <sstream>
#include "Student.h"
#include "AVLTree.h"

namespace PracticeSem4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для MyForm5
	/// </summary>
	public ref class MyForm5 : public System::Windows::Forms::Form
	{
	public:
		MyForm5(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm5()
		{
			if (components)
			{
				delete components;
			}
			root->Destroy_tree();
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(500, 490);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 70);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Закрыть";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm5::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(10, 10);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Padding = System::Windows::Forms::Padding(10, 10, 10, 0);
			this->pictureBox1->Size = System::Drawing::Size(1180, 475);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm5::pictureBox1_Paint);
			// 
			// MyForm5
			// 
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 600);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm5";
			this->Text = L"АВЛ дерево";
			this->Load += gcnew System::EventHandler(this, &MyForm5::MyForm5_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	public:
		AVLTree* root = new AVLTree();
	private:
		Graphics^ formGraph1;
		Pen^ pen;
		Pen^ pen1;
		Color color;
		Color color1;
		System::Drawing::Font^ font1;
		System::Drawing::StringFormat^ format1;

	private: System::Void MyForm5_Load(System::Object^ sender, System::EventArgs^ e)
	{
		color = Color::MediumPurple;
		color1 = Color::Black;
		pen = gcnew Pen(color, 5);
		pen1 = gcnew Pen(color1, 2.5);

		font1 = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 17.0F, FontStyle::Regular);
		format1 = gcnew System::Drawing::StringFormat();
		format1->LineAlignment = StringAlignment::Center;
		format1->Alignment = StringAlignment::Center;

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
			root->insert(stud);
		}
		sr->Close();
		delete sr;
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}

	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		formGraph1 = e->Graphics;
		formGraph1->DrawRectangle(pen, 465, 10, 250, 100);
		formGraph1->DrawRectangle(pen, 155, 180, 250, 100);
		formGraph1->DrawRectangle(pen, 775, 180, 250, 100);
		formGraph1->DrawRectangle(pen, 10, 340, 250, 100);
		formGraph1->DrawRectangle(pen, 300, 340, 250, 100);
		formGraph1->DrawRectangle(pen, 630, 340, 250, 100);
		formGraph1->DrawRectangle(pen, 920, 340, 250, 100);

		if (root->root)
		{
			String^ lastname = gcnew String(root->root->student.Get_lastname().c_str());
			String^ avg = gcnew String(root->root->student.Get_str_avarage().c_str());
			formGraph1->DrawString(lastname, font1, Brushes::Black, 590, 45, format1);
			formGraph1->DrawString(avg, font1, Brushes::Black, 590, 75, format1);

			if (root->root->left)
			{
				String^ lastname = gcnew String(root->root->left->student.Get_lastname().c_str());
				String^ avg = gcnew String(root->root->left->student.Get_str_avarage().c_str());
				formGraph1->DrawString(lastname, font1, Brushes::Black, 280, 215, format1);
				formGraph1->DrawString(avg, font1, Brushes::Black, 280, 245, format1);

				if (root->root->left->left)
				{
					String^ lastname = gcnew String(root->root->left->left->student.Get_lastname().c_str());
					String^ avg = gcnew String(root->root->left->left->student.Get_str_avarage().c_str());
					formGraph1->DrawString(lastname, font1, Brushes::Black, 135, 375, format1);
					formGraph1->DrawString(avg, font1, Brushes::Black, 135, 405, format1);
				}

				if (root->root->left->right)
				{
					String^ lastname = gcnew String(root->root->left->right->student.Get_lastname().c_str());
					String^ avg = gcnew String(root->root->left->right->student.Get_str_avarage().c_str());
					formGraph1->DrawString(lastname, font1, Brushes::Black, 425, 375, format1);
					formGraph1->DrawString(avg, font1, Brushes::Black, 425, 405, format1);
				}
			}

			if (root->root->right)
			{
				String^ lastname = gcnew String(root->root->right->student.Get_lastname().c_str());
				String^ avg = gcnew String(root->root->right->student.Get_str_avarage().c_str());
				formGraph1->DrawString(lastname, font1, Brushes::Black, 900, 215, format1);
				formGraph1->DrawString(avg, font1, Brushes::Black, 900, 245, format1);

				if (root->root->right->left)
				{
					String^ lastname = gcnew String(root->root->right->left->student.Get_lastname().c_str());
					String^ avg = gcnew String(root->root->right->left->student.Get_str_avarage().c_str());
					formGraph1->DrawString(lastname, font1, Brushes::Black, 755, 375, format1);
					formGraph1->DrawString(avg, font1, Brushes::Black, 755, 405, format1);
				}

				if (root->root->right->right)
				{
					String^ lastname = gcnew String(root->root->right->right->student.Get_lastname().c_str());
					String^ avg = gcnew String(root->root->right->right->student.Get_str_avarage().c_str());
					formGraph1->DrawString(lastname, font1, Brushes::Black, 1045, 375, format1);
					formGraph1->DrawString(avg, font1, Brushes::Black, 1045, 405, format1);
				}

			}
		}

	}
		
	};
}
