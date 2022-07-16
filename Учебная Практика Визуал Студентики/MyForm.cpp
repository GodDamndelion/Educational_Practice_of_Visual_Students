#include "MyForm.h"
#include <Windows.h>
#include <fstream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "Our_Functions.h"
#include "Dynamic_chain_1.h"
#include "Dynamic_chain_2.h"
#include "Search_tree_1.h"
#include "Search_tree_2.h"
#include "OurTask.h"
#include <iterator>

using namespace GroupWork;
using namespace std;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

fstream file;
string file_name;
int N = -1;
int COUNT = -1;

System::Void GroupWork::MyForm::set_file_name_Click(System::Object^ sender, System::EventArgs^ e) //отправить имя файла
{
	String^ FileName = textBox1->Text;
	if (FileName != "")
	{
		string filename = msclr::interop::marshal_as<string>(FileName);
		file_name = filename + ".txt";
		file.close();
		file.open(file_name, ios_base::out);
		MessageBox::Show("Файл успешно создан!", "Оповещение");
	}
	else
	{
		MessageBox::Show("Пустая строка в имени файла!", "Ошибка");
	}
}

System::Void GroupWork::MyForm::del_file_name_Click(System::Object^ sender, System::EventArgs^ e) //очистить имя файла
{
	if (textBox1) textBox1->Clear();
}

System::Void GroupWork::MyForm::set_num_of_students_Click(System::Object^ sender, System::EventArgs^ e) //отправить количество студентов
{
	if (file_name != "")
	{
		int n = Convert::ToSingle(textBox8->Text);
		if (n > 0)
		{
			N = n;
			COUNT = n;
			MessageBox::Show("Количество студентов задано!", "Оповещение");
			string counter = to_string(N);
			counter_label->Text = msclr::interop::marshal_as<String^>(counter);
		}
		else
		{
			MessageBox::Show("Недопустимое количество студентов!", "Ошибка");
		}
	}
	else
	{
		MessageBox::Show("Введите и отправьте имя файла!", "Ошибка");
	}
}

System::Void GroupWork::MyForm::del_num_of_students_Click(System::Object^ sender, System::EventArgs^ e) //очистить количество студентов
{
	if (textBox8) textBox8->Clear();
}

System::Void GroupWork::MyForm::set_info_Click(System::Object^ sender, System::EventArgs^ e) //отправить фио и оценки
{
	if (N != -1)
	{
		String^ name_ = textBox2->Text;
		string name = msclr::interop::marshal_as<string>(name_);
		String^ surname_ = textBox9->Text;
		string surname = msclr::interop::marshal_as<string>(surname_);
		if (textBox3->Text != "" && textBox4->Text != "" && textBox5->Text != "" && textBox6->Text != "" && textBox7->Text != "")
		{
			int mark1 = Convert::ToSingle(textBox3->Text);
			int mark2 = Convert::ToSingle(textBox4->Text);
			int mark3 = Convert::ToSingle(textBox5->Text);
			int mark4 = Convert::ToSingle(textBox6->Text);
			int mark5 = Convert::ToSingle(textBox7->Text);
			if (N > 0 && file && name != "" && surname != "" && name.length() <= 20 && surname.length() <= 20 && mark1 >= 2 && mark1 <= 5 && mark2 >= 2 && mark2 <= 5 && mark3 >= 2 && mark3 <= 5 && mark4 >= 2 && mark4 <= 5 && mark5 >= 2 && mark5 <= 5)
			{
				file << name << '\n' << surname << '\n' << mark1 << ' ' << mark2 << ' ' << mark3 << ' ' << mark4 << ' ' << mark5 << '\n';
				N--;
				string counter = to_string(N);
				counter_label->Text = msclr::interop::marshal_as<String^>(counter);
				MessageBox::Show("Студент добавлен!", "Оповещение");
			}
			else
			{
				MessageBox::Show("Студент не был добавлен!", "Ошибка");
			}
			if (N == 0)
			{
				file.close();
			}
		}
		else
		{
			MessageBox::Show("Недостаток данных!", "Ошибка");
		}
	}
	else
	{
		MessageBox::Show("Введите и отправьте количество студентов!", "Ошибка");
	}
}

System::Void GroupWork::MyForm::del_info_Click(System::Object^ sender, System::EventArgs^ e) //очистить фио и оценки
{
	for (int i = 0; i < groupBox2->Controls->Count; i++)
	{
		TextBox^ TextB = dynamic_cast<TextBox^>(groupBox2->Controls[i]);
		if (TextB)
			TextB->Clear();
	}
}

System::Void GroupWork::MyForm::dynamic_chain_1_Click(System::Object^ sender, System::EventArgs^ e) //динамическая цепочка 1
{
	if (file_name != "" && COUNT != -1 && N <= 0)
	{
		Dynamic_chain_1^ DC1 = gcnew Dynamic_chain_1();
		DC1->Show();
		file.open(file_name, ios_base::in);
		DoublyLinkedList<task_type> list1, list2;
		student_type tmp;
		for (int i = 0; i < COUNT; ++i)
		{
			tmp.read_from(file);
			task_type tmp2;
			tmp2.surname = tmp.surname;
			tmp2.average_grade = average(tmp.grade);
			if (there_is_3(tmp))
				list1.Add_before_node(list1.begin, tmp2);
			else
				list2.Add_before_node(list2.begin, tmp2);
		}
		list1.Splice(list1.end, list2);
		file.close();
		int j;
		NODE_L<task_type>* x = list1.begin;
		for (j = 10; x != list1.end->next; j += 45)
		{
			if (x != list1.end)
			{
				Label^ tmp = gcnew Label();
				tmp->AutoSize = true;
				tmp->BackColor = System::Drawing::SystemColors::AppWorkspace;
				tmp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				tmp->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
				tmp->ForeColor = System::Drawing::SystemColors::ControlText;
				tmp->Name = L"label";
				tmp->Size = System::Drawing::Size(65, 19);
				tmp->TabIndex = 11;
				tmp->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				string str = "Surname: " + x->info.surname + ", Average grade: " + to_string(x->info.average_grade);
				tmp->Text = msclr::interop::marshal_as<String^>(str);
				tmp->Location = System::Drawing::Point(20, j);
				DC1->Controls->Add(tmp);
				Label^ strelka = gcnew Label();
				strelka->AutoSize = true;
				strelka->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
				strelka->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
				strelka->Name = L"label1";
				strelka->Size = System::Drawing::Size(28, 31);
				strelka->TabIndex = 0;
				strelka->Text = L"↓";
				strelka->Location = System::Drawing::Point(20 + tmp->Size.Width / 2, j + 10);
				DC1->Controls->Add(strelka);
				x = x->next;
			}
			else
				if (x == list1.end)
				{
					Label^ tmp = gcnew Label();
					tmp->AutoSize = true;
					tmp->BackColor = System::Drawing::SystemColors::AppWorkspace;
					tmp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
					tmp->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
					tmp->ForeColor = System::Drawing::SystemColors::ControlText;
					tmp->Name = L"label";
					tmp->Size = System::Drawing::Size(65, 19);
					tmp->TabIndex = 11;
					tmp->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					string str = "Surname: " + x->info.surname + ", Average grade: " + to_string(x->info.average_grade);
					tmp->Text = msclr::interop::marshal_as<String^>(str);
					tmp->Location = System::Drawing::Point(20, j);
					DC1->Controls->Add(tmp);
					x = x->next;
				}
		}
	}
	else
	{
		MessageBox::Show("Недостаток данных!", "Ошибка");
	}
}

System::Void GroupWork::MyForm::dynamic_chain_2_Click(System::Object^ sender, System::EventArgs^ e) //динамическая цепочка 2
{
	if (file_name != "" && COUNT != -1 && N <= 0)
	{
		Dynamic_chain_2^ DC2 = gcnew Dynamic_chain_2();
		DC2->Show();
		file.open(file_name, ios_base::in);
		DoublyLinkedList<task_type> List;
		student_type tmp;
		for (int i = 0; i < COUNT; ++i)
		{
			tmp.read_from(file);
			task_type tmp2;
			tmp2.surname = tmp.surname;
			tmp2.average_grade = average(tmp.grade);
			List.Add_into(tmp2);
		}
		file.close();
		int j;
		NODE_L<task_type>* x = List.begin;
		for (j = 10; x != List.end->next; j += 45)
		{
			if (x != List.end)
			{
				Label^ tmp = gcnew Label();
				tmp->AutoSize = true;
				tmp->BackColor = System::Drawing::SystemColors::AppWorkspace;
				tmp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				tmp->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
				tmp->ForeColor = System::Drawing::SystemColors::ControlText;
				tmp->Name = L"label";
				tmp->Size = System::Drawing::Size(65, 19);
				tmp->TabIndex = 11;
				tmp->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				string str = "Surname: " + x->info.surname + ", Average grade: " + to_string(x->info.average_grade);
				tmp->Text = msclr::interop::marshal_as<String^>(str);
				tmp->Location = System::Drawing::Point(20, j);
				DC2->Controls->Add(tmp);
				Label^ strelka = gcnew Label();
				strelka->AutoSize = true;
				strelka->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
				strelka->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
				strelka->Name = L"label1";
				strelka->Size = System::Drawing::Size(28, 31);
				strelka->TabIndex = 0;
				strelka->Text = L"↓";
				strelka->Location = System::Drawing::Point(20 + tmp->Size.Width / 2, j + 10);
				DC2->Controls->Add(strelka);
				x = x->next;
			}
			else
				if (x == List.end)
				{
					Label^ tmp = gcnew Label();
					tmp->AutoSize = true;
					tmp->BackColor = System::Drawing::SystemColors::AppWorkspace;
					tmp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
					tmp->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
					tmp->ForeColor = System::Drawing::SystemColors::ControlText;
					tmp->Name = L"label";
					tmp->Size = System::Drawing::Size(65, 19);
					tmp->TabIndex = 11;
					tmp->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					string str = "Surname: " + x->info.surname + ", Average grade: " + to_string(x->info.average_grade);
					tmp->Text = msclr::interop::marshal_as<String^>(str);
					tmp->Location = System::Drawing::Point(20, j);
					DC2->Controls->Add(tmp);
					x = x->next;
				}
		}
	}
	else
	{
		MessageBox::Show("Недостаток данных!", "Ошибка");
	}
}

System::Void GroupWork::MyForm::search_tree_1_Click(System::Object^ sender, System::EventArgs^ e) //дерево поиска
{
	if (file_name != "" && COUNT != -1 && N <= 0)
	{
		Search_tree_1^ ST1 = gcnew Search_tree_1();
		ST1->Show();
		Search_binary_tree<task_type> sbt(file_name);
		Search_Tree<task_type> p = sbt.get_tree();
		ST1->label1->Text = msclr::interop::marshal_as<String^>(p->info.to_string());
		if (p->left)
		{
			Search_Tree<task_type> pl = p->left;
			ST1->label2->Text = msclr::interop::marshal_as<String^>(pl->info.to_string());
			if (pl->left)
			{
				Search_Tree<task_type> pll = pl->left;
				ST1->label4->Text = msclr::interop::marshal_as<String^>(pll->info.to_string());
			}
			if (pl->right)
			{
				Search_Tree<task_type> plr = pl->right;
				ST1->label5->Text = msclr::interop::marshal_as<String^>(plr->info.to_string());
			}
		}
		if (p->right)
		{
			Search_Tree<task_type> pr = p->right;
			ST1->label3->Text = msclr::interop::marshal_as<String^>(pr->info.to_string());
			if (pr->left)
			{
				Search_Tree<task_type> prl = pr->left;
				ST1->label6->Text = msclr::interop::marshal_as<String^>(prl->info.to_string());
			}
			if (pr->right)
			{
				Search_Tree<task_type> prr = pr->right;
				ST1->label7->Text = msclr::interop::marshal_as<String^>(prr->info.to_string());
			}
		}
	}
	else
	{
		MessageBox::Show("Недостаток данных!", "Ошибка");
	}
}

System::Void GroupWork::MyForm::search_tree_2_Click(System::Object^ sender, System::EventArgs^ e) //авл-дерево поиска
{
	if (file_name != "" && COUNT != -1 && N <= 0)
	{
		Search_tree_2^ ST2 = gcnew Search_tree_2();
		ST2->Show();
		Search_balansed_binary_tree<task_type> sbbt(file_name);
		Search_Balansed_Tree<task_type> p = sbbt.get_tree();
		ST2->label1->Text = msclr::interop::marshal_as<String^>(p->info.to_string());
		if (p->left)
		{
			Search_Balansed_Tree<task_type> pl = p->left;
			ST2->label2->Text = msclr::interop::marshal_as<String^>(pl->info.to_string());
			if (pl->left)
			{
				Search_Balansed_Tree<task_type> pll = pl->left;
				ST2->label4->Text = msclr::interop::marshal_as<String^>(pll->info.to_string());
			}
			if (pl->right)
			{
				Search_Balansed_Tree<task_type> plr = pl->right;
				ST2->label5->Text = msclr::interop::marshal_as<String^>(plr->info.to_string());
			}
		}
		if (p->right)
		{
			Search_Balansed_Tree<task_type> pr = p->right;
			ST2->label3->Text = msclr::interop::marshal_as<String^>(pr->info.to_string());
			if (pr->left)
			{
				Search_Balansed_Tree<task_type> prl = pr->left;
				ST2->label6->Text = msclr::interop::marshal_as<String^>(prl->info.to_string());
			}
			if (pr->right)
			{
				Search_Balansed_Tree<task_type> prr = pr->right;
				ST2->label7->Text = msclr::interop::marshal_as<String^>(prr->info.to_string());
			}
		}
	}
	else
	{
		MessageBox::Show("Недостаток данных!", "Ошибка");
	}
}

System::Void GroupWork::MyForm::task_Click(System::Object^ sender, System::EventArgs^ e) //студентики по заданию
{
	if (file_name != "" && COUNT != -1 && N <= 0)
	{
		OurTask^ OT = gcnew OurTask();
		OT->Show();
		file.open(file_name, ios_base::in);
		int max_good_count = 0;
		DoublyLinkedList<student_type> List;
		student_type tmp;
		for (int i = 0; i < COUNT; ++i)
		{
			int good_count = 0;
			file >> tmp.name >> tmp.surname;
			for (int j = 0; j < grades_count; ++j)
			{
				file >> tmp.grade[j];
				if (tmp.grade[j] == 4 || tmp.grade[j] == 5)
					++good_count;
			}
			if (good_count > max_good_count)
				max_good_count = good_count;
			List.Add_into(tmp);
		}
		file.close();
		int j;
		ptrNODE_L<student_type> x = List.begin;
		for (j = 10; x != List.end->next; )
		{
			int count = 0;
			for (int i = 0; i < grades_count; ++i)
			{
				if (x->info.grade[i] == 4 || x->info.grade[i] == 5)
					++count;
			}
			if (count == max_good_count && max_good_count != 0)
			{
				if (x != List.end)
				{
					Label^ tmp = gcnew Label();
					tmp->AutoSize = true;
					tmp->BackColor = System::Drawing::SystemColors::AppWorkspace;
					tmp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
					tmp->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
					tmp->ForeColor = System::Drawing::SystemColors::ControlText;
					tmp->Name = L"label";
					tmp->Size = System::Drawing::Size(65, 19);
					tmp->TabIndex = 11;
					tmp->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					string gr;
					for (int i = 0; i < grades_count; ++i)
					{
						gr += to_string(x->info.grade[i]) + ' ';
					}
					string str = "Surname: " + x->info.surname + ", Grades: " + gr;
					tmp->Text = msclr::interop::marshal_as<String^>(str);
					tmp->Location = System::Drawing::Point(20, j);
					OT->Controls->Add(tmp);
					Label^ strelka = gcnew Label();
					strelka->AutoSize = true;
					strelka->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
					strelka->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
					strelka->Name = L"label1";
					strelka->Size = System::Drawing::Size(28, 31);
					strelka->TabIndex = 0;
					strelka->Text = L"↓";
					strelka->Location = System::Drawing::Point(20 + tmp->Size.Width / 2, j + 10);
					OT->Controls->Add(strelka);
				}
				else
					if (x == List.end)
					{
						Label^ tmp = gcnew Label();
						tmp->AutoSize = true;
						tmp->BackColor = System::Drawing::SystemColors::AppWorkspace;
						tmp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
						tmp->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
						tmp->ForeColor = System::Drawing::SystemColors::ControlText;
						tmp->Name = L"label";
						tmp->Size = System::Drawing::Size(65, 19);
						tmp->TabIndex = 11;
						tmp->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
						string gr;
						for (int i = 0; i < grades_count; ++i)
						{
							gr += to_string(x->info.grade[i]) + ' ';
						}
						string str = "Surname: " + x->info.surname + ", Grades: " + gr;
						tmp->Text = msclr::interop::marshal_as<String^>(str);
						tmp->Location = System::Drawing::Point(20, j);
						OT->Controls->Add(tmp);
					}
				j += 45;
			}
			x = x->next;
		}
	}
	else
	{
		MessageBox::Show("Недостаток данных!", "Ошибка");
	}
}