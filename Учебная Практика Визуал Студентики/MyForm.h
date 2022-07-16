#pragma once

namespace GroupWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ set_file_name;
	private: System::Windows::Forms::Button^ del_file_name;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ dynamic_chain_1;
	private: System::Windows::Forms::Button^ dynamic_chain_2;
	private: System::Windows::Forms::Button^ search_tree_1;
	private: System::Windows::Forms::Button^ search_tree_2;
	private: System::Windows::Forms::Button^ task;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ del_num_of_students;
	private: System::Windows::Forms::Button^ set_num_of_students;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Button^ del_info;
	private: System::Windows::Forms::Button^ set_info;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ counter_label;
	private: System::Windows::Forms::Label^ label9;

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->set_file_name = (gcnew System::Windows::Forms::Button());
			this->del_file_name = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dynamic_chain_1 = (gcnew System::Windows::Forms::Button());
			this->dynamic_chain_2 = (gcnew System::Windows::Forms::Button());
			this->search_tree_1 = (gcnew System::Windows::Forms::Button());
			this->search_tree_2 = (gcnew System::Windows::Forms::Button());
			this->task = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->del_num_of_students = (gcnew System::Windows::Forms::Button());
			this->set_num_of_students = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->del_info = (gcnew System::Windows::Forms::Button());
			this->set_info = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->counter_label = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(26, 9);
			this->label1->Name = L"label1";
			this->label1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label1->Size = System::Drawing::Size(674, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Большаков П. А., Виноградов С. Д., Юхно А. М. 2 курс ПММ 61 группа";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 19);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Создание файла:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(49, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 19);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Имя файла:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(139, 69);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(337, 26);
			this->textBox1->TabIndex = 3;
			// 
			// set_file_name
			// 
			this->set_file_name->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->set_file_name->Location = System::Drawing::Point(503, 69);
			this->set_file_name->Name = L"set_file_name";
			this->set_file_name->Size = System::Drawing::Size(96, 26);
			this->set_file_name->TabIndex = 4;
			this->set_file_name->Text = L"Отправить";
			this->set_file_name->UseVisualStyleBackColor = true;
			this->set_file_name->Click += gcnew System::EventHandler(this, &MyForm::set_file_name_Click);
			// 
			// del_file_name
			// 
			this->del_file_name->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->del_file_name->Location = System::Drawing::Point(605, 69);
			this->del_file_name->Name = L"del_file_name";
			this->del_file_name->Size = System::Drawing::Size(95, 26);
			this->del_file_name->TabIndex = 5;
			this->del_file_name->Text = L"Очистить";
			this->del_file_name->UseVisualStyleBackColor = true;
			this->del_file_name->Click += gcnew System::EventHandler(this, &MyForm::del_file_name_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(32, 113);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(101, 19);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Ввод данных:";
			// 
			// dynamic_chain_1
			// 
			this->dynamic_chain_1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dynamic_chain_1->Location = System::Drawing::Point(6, 30);
			this->dynamic_chain_1->Name = L"dynamic_chain_1";
			this->dynamic_chain_1->Size = System::Drawing::Size(222, 34);
			this->dynamic_chain_1->TabIndex = 26;
			this->dynamic_chain_1->Text = L"Динамическая цепочка №1:";
			this->dynamic_chain_1->UseVisualStyleBackColor = true;
			this->dynamic_chain_1->Click += gcnew System::EventHandler(this, &MyForm::dynamic_chain_1_Click);
			// 
			// dynamic_chain_2
			// 
			this->dynamic_chain_2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dynamic_chain_2->Location = System::Drawing::Point(235, 30);
			this->dynamic_chain_2->Name = L"dynamic_chain_2";
			this->dynamic_chain_2->Size = System::Drawing::Size(223, 34);
			this->dynamic_chain_2->TabIndex = 27;
			this->dynamic_chain_2->Text = L"Динамическая цепочка №2:";
			this->dynamic_chain_2->UseVisualStyleBackColor = true;
			this->dynamic_chain_2->Click += gcnew System::EventHandler(this, &MyForm::dynamic_chain_2_Click);
			// 
			// search_tree_1
			// 
			this->search_tree_1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->search_tree_1->Location = System::Drawing::Point(5, 70);
			this->search_tree_1->Name = L"search_tree_1";
			this->search_tree_1->Size = System::Drawing::Size(223, 36);
			this->search_tree_1->TabIndex = 28;
			this->search_tree_1->Text = L"Дерево поиска:";
			this->search_tree_1->UseVisualStyleBackColor = true;
			this->search_tree_1->Click += gcnew System::EventHandler(this, &MyForm::search_tree_1_Click);
			// 
			// search_tree_2
			// 
			this->search_tree_2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->search_tree_2->Location = System::Drawing::Point(234, 70);
			this->search_tree_2->Name = L"search_tree_2";
			this->search_tree_2->Size = System::Drawing::Size(222, 36);
			this->search_tree_2->TabIndex = 29;
			this->search_tree_2->Text = L"АВЛ-дерево поиска:";
			this->search_tree_2->UseVisualStyleBackColor = true;
			this->search_tree_2->Click += gcnew System::EventHandler(this, &MyForm::search_tree_2_Click);
			// 
			// task
			// 
			this->task->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->task->Location = System::Drawing::Point(464, 30);
			this->task->Name = L"task";
			this->task->Size = System::Drawing::Size(227, 34);
			this->task->TabIndex = 30;
			this->task->Text = L"Студенты по заданию:";
			this->task->UseVisualStyleBackColor = true;
			this->task->Click += gcnew System::EventHandler(this, &MyForm::task_Click);
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox8->Location = System::Drawing::Point(139, 139);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(337, 26);
			this->textBox8->TabIndex = 31;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(2, 142);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(131, 19);
			this->label7->TabIndex = 32;
			this->label7->Text = L"Кол-во студентов:";
			// 
			// del_num_of_students
			// 
			this->del_num_of_students->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->del_num_of_students->Location = System::Drawing::Point(605, 138);
			this->del_num_of_students->Name = L"del_num_of_students";
			this->del_num_of_students->Size = System::Drawing::Size(95, 26);
			this->del_num_of_students->TabIndex = 34;
			this->del_num_of_students->Text = L"Очистить";
			this->del_num_of_students->UseVisualStyleBackColor = true;
			this->del_num_of_students->Click += gcnew System::EventHandler(this, &MyForm::del_num_of_students_Click);
			// 
			// set_num_of_students
			// 
			this->set_num_of_students->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->set_num_of_students->Location = System::Drawing::Point(503, 139);
			this->set_num_of_students->Name = L"set_num_of_students";
			this->set_num_of_students->Size = System::Drawing::Size(96, 26);
			this->set_num_of_students->TabIndex = 33;
			this->set_num_of_students->Text = L"Отправить";
			this->set_num_of_students->UseVisualStyleBackColor = true;
			this->set_num_of_students->Click += gcnew System::EventHandler(this, &MyForm::set_num_of_students_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->task);
			this->groupBox1->Controls->Add(this->search_tree_2);
			this->groupBox1->Controls->Add(this->dynamic_chain_1);
			this->groupBox1->Controls->Add(this->search_tree_1);
			this->groupBox1->Controls->Add(this->dynamic_chain_2);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(18, 308);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(699, 115);
			this->groupBox1->TabIndex = 35;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Функции:";
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(393, 82);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(63, 26);
			this->textBox7->TabIndex = 16;
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox6->Location = System::Drawing::Point(324, 82);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(63, 26);
			this->textBox6->TabIndex = 15;
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(255, 82);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(63, 26);
			this->textBox5->TabIndex = 14;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(187, 82);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(62, 26);
			this->textBox4->TabIndex = 13;
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(119, 82);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(62, 26);
			this->textBox3->TabIndex = 12;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(38, 54);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(75, 19);
			this->label8->TabIndex = 36;
			this->label8->Text = L"Фамилия:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(48, 85);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(65, 19);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Оценки:";
			// 
			// textBox9
			// 
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox9->Location = System::Drawing::Point(119, 50);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(337, 26);
			this->textBox9->TabIndex = 37;
			// 
			// del_info
			// 
			this->del_info->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->del_info->Location = System::Drawing::Point(587, 81);
			this->del_info->Name = L"del_info";
			this->del_info->Size = System::Drawing::Size(95, 26);
			this->del_info->TabIndex = 10;
			this->del_info->Text = L"Очистить";
			this->del_info->UseVisualStyleBackColor = true;
			this->del_info->Click += gcnew System::EventHandler(this, &MyForm::del_info_Click);
			// 
			// set_info
			// 
			this->set_info->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->set_info->Location = System::Drawing::Point(485, 82);
			this->set_info->Name = L"set_info";
			this->set_info->Size = System::Drawing::Size(96, 26);
			this->set_info->TabIndex = 9;
			this->set_info->Text = L"Отправить";
			this->set_info->UseVisualStyleBackColor = true;
			this->set_info->Click += gcnew System::EventHandler(this, &MyForm::set_info_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(73, 22);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 19);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Имя:";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(119, 19);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(337, 26);
			this->textBox2->TabIndex = 8;
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->counter_label);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->set_info);
			this->groupBox2->Controls->Add(this->del_info);
			this->groupBox2->Controls->Add(this->textBox9);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->textBox5);
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Controls->Add(this->textBox7);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->groupBox2->Location = System::Drawing::Point(18, 171);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(699, 131);
			this->groupBox2->TabIndex = 42;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Студент:";
			// 
			// counter_label
			// 
			this->counter_label->AutoSize = true;
			this->counter_label->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->counter_label->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->counter_label->ForeColor = System::Drawing::SystemColors::ControlText;
			this->counter_label->Location = System::Drawing::Point(589, 19);
			this->counter_label->Name = L"counter_label";
			this->counter_label->Size = System::Drawing::Size(93, 19);
			this->counter_label->TabIndex = 38;
			this->counter_label->Text = L"                     ";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(481, 19);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(81, 19);
			this->label9->TabIndex = 39;
			this->label9->Text = L"Осталось:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(729, 429);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->del_num_of_students);
			this->Controls->Add(this->set_num_of_students);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->del_file_name);
			this->Controls->Add(this->set_file_name);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox2);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void set_file_name_Click(System::Object^ sender, System::EventArgs^ e); //отправить имя файла
	private: System::Void del_file_name_Click(System::Object^ sender, System::EventArgs^ e); //очистить имя файла
	private: System::Void set_num_of_students_Click(System::Object^ sender, System::EventArgs^ e); //отправить количество студентов
	private: System::Void del_num_of_students_Click(System::Object^ sender, System::EventArgs^ e); //очистить количество студентов
	private: System::Void set_info_Click(System::Object^ sender, System::EventArgs^ e); //отправить фио и оценки
	private: System::Void del_info_Click(System::Object^ sender, System::EventArgs^ e); //очистить фио и оценки
	private: System::Void dynamic_chain_1_Click(System::Object^ sender, System::EventArgs^ e); //динамическая цепочка 1
	private: System::Void dynamic_chain_2_Click(System::Object^ sender, System::EventArgs^ e); //динамическая цепочка 2
	private: System::Void search_tree_1_Click(System::Object^ sender, System::EventArgs^ e); //дерево поиска
	private: System::Void search_tree_2_Click(System::Object^ sender, System::EventArgs^ e); //авл-дерево поиска
	private: System::Void task_Click(System::Object^ sender, System::EventArgs^ e); //студентики по заданию
};
}