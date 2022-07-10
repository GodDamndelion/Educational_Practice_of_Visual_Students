#include "MyForm.h"
#include <Windows.h>
#include <fstream>
#include <string>
#include <msclr\marshal_cppstd.h>

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

System::Void GroupWork::MyForm::set_file_name_Click(System::Object^ sender, System::EventArgs^ e) //��������� ��� �����
{
	String^ FileName = textBox1->Text;
	if (FileName != "")
	{
		string filename = msclr::interop::marshal_as<string>(FileName);
		file_name = filename + ".txt";
		file.close();
		file.open(file_name, ios_base::out);
		MessageBox::Show("���� ������� ������!", "����������");
	}
	else
	{
		MessageBox::Show("������ ������ � ����� �����!", "������");
	}
}

System::Void GroupWork::MyForm::del_file_name_Click(System::Object^ sender, System::EventArgs^ e) //�������� ��� �����
{
	if (textBox1) textBox1->Clear();
}

System::Void GroupWork::MyForm::set_num_of_students_Click(System::Object^ sender, System::EventArgs^ e) //��������� ���������� ���������
{
	if (file_name != "")
	{
		int n = Convert::ToSingle(textBox8->Text);
		if (n > 0)
		{
			N = n;
			MessageBox::Show("���������� ��������� ������!", "����������");
		}
		else
		{
			MessageBox::Show("������������ ���������� ���������!", "������");
		}
	}
	else
	{
		MessageBox::Show("������� � ��������� ��� �����!", "������");
	}
}

System::Void GroupWork::MyForm::del_num_of_students_Click(System::Object^ sender, System::EventArgs^ e) //�������� ���������� ���������
{
	if (textBox8) textBox8->Clear();
}

System::Void GroupWork::MyForm::set_info_Click(System::Object^ sender, System::EventArgs^ e) //��������� ��� � ������
{
	if (N != -1)
	{
		String^ name_ = textBox2->Text;
		string name = msclr::interop::marshal_as<string>(name_);
		String^ surname_ = textBox9->Text;
		string surname = msclr::interop::marshal_as<string>(surname_);
		int mark1 = Convert::ToSingle(textBox3->Text);
		int mark2 = Convert::ToSingle(textBox4->Text);
		int mark3 = Convert::ToSingle(textBox5->Text);
		int mark4 = Convert::ToSingle(textBox6->Text);
		int mark5 = Convert::ToSingle(textBox7->Text);
		if (N > 0 && file && name != "" && surname != "" && name.length() <= 20 && surname.length() <= 20 && mark1 >= 2 && mark1 <= 5 && mark2 >= 2 && mark2 <= 5 && mark3 >= 2 && mark3 <= 5 && mark4 >= 2 && mark4 <= 5 && mark5 >= 2 && mark5 <= 5)
		{
			file << name << '\n' << surname << '\n' << mark1 << ' ' << mark2 << ' ' << mark3 << ' ' << mark4 << ' ' << mark5 << '\n';
			N--;
			MessageBox::Show("������� ��������!", "����������");
		}
		else
		{
			MessageBox::Show("������� �� ��� ��������!", "������");
		}
		if (N == 0)
		{
			file.close();
		}
	}
	else
	{
		MessageBox::Show("������� � ��������� ���������� ���������!", "������");
	}
}

System::Void GroupWork::MyForm::del_info_Click(System::Object^ sender, System::EventArgs^ e) //�������� ��� � ������
{
	for (int i = 0; i < groupBox2->Controls->Count; i++)
	{
		TextBox^ TextB = dynamic_cast<TextBox^>(groupBox2->Controls[i]);
		if (TextB)
			TextB->Clear();
	}
}

System::Void GroupWork::MyForm::dynamic_chain_1_Click(System::Object^ sender, System::EventArgs^ e) //������������ ������� 1
{
	return System::Void();
}

System::Void GroupWork::MyForm::dynamic_chain_2_Click(System::Object^ sender, System::EventArgs^ e) //������������ ������� 2
{
	return System::Void();
}

System::Void GroupWork::MyForm::search_tree_1_Click(System::Object^ sender, System::EventArgs^ e) //������ ������
{
	return System::Void();
}

System::Void GroupWork::MyForm::search_tree_2_Click(System::Object^ sender, System::EventArgs^ e) //���-������ ������
{
	return System::Void();
}

System::Void GroupWork::MyForm::task_Click(System::Object^ sender, System::EventArgs^ e) //���������� �� �������
{
	return System::Void();
}
