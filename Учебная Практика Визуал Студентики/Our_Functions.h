#pragma once
#include <iostream>
#include "List.h"
#include "STree.h"
#include "SBTree.h"
#include <fstream>
#include <string>

using namespace std;
const int grades_count = 5;

struct student_type
{
	string name, surname;
	int grade[grades_count];
	void read_from(fstream& file);
	string to_string();
	friend istream& operator>>(istream& in, student_type& obj);
	friend ostream& operator<<(ostream& out, student_type obj);
	bool operator<(student_type obj);
	bool operator>(student_type obj);
};

float average(int a[grades_count])
{
	int sum = 0;
	for (int i = 0; i < grades_count; ++i)
		sum += a[i];
	return (float)sum / grades_count;
}

istream& operator>>(istream& in, student_type& obj)
{
	in >> obj.name >> obj.surname;
	for (int i = 0; i < grades_count; ++i)
		in >> obj.grade[i];
	return in;
}

ostream& operator<<(ostream& out, student_type obj)
{
	out << obj.to_string();
	return out;
}

string array_to_string(int a[grades_count], const int grades_count)
{
	string result;
	for (int i = 0; i < grades_count; ++i)
		result += to_string(a[i]) + ' ';
	return result;
}

string student_type::to_string()
{
	return "Surname: " + surname + "Name: " + name + ", Grades: " + array_to_string(grade, grades_count);
}

void student_type::read_from(fstream& file)
{
	file >> name >> surname;
	for (int i = 0; i < grades_count; ++i)
		file >> grade[i];
}

bool is_less_than(student_type student1, student_type student2)
{
	bool result = false;
	if (student1.surname < student2.surname || student1.surname == student2.surname && (student1.name < student2.name))
		result = true;
	return result;
}

bool student_type::operator<(student_type obj)
{
	return is_less_than(*this, obj);
}

bool is_more_than(student_type student1, student_type student2)
{
	bool result = false;
	if (student1.surname > student2.surname || student1.surname == student2.surname && (student1.name > student2.name))
		result = true;
	return result;
}

bool student_type::operator>(student_type obj)
{
	return is_more_than(*this, obj);
}

struct task_type
{
	string surname;
	float average_grade = 0;
	string to_string();
	bool operator<(task_type obj);
	bool operator>(task_type obj);
	friend ostream& operator<<(ostream& out, task_type obj);
	friend istream& operator>>(istream& in, task_type& obj);
};

string task_type::to_string()
{
	return "Surname: " + surname + ", Average grade: " + ::to_string(average_grade);
}

ostream& operator<<(ostream& out, task_type obj)
{
	out << obj.to_string();
	return out;
}

istream& operator>>(istream& in, task_type& obj)
{
	student_type tmp;
	in >> tmp.name >> tmp.surname;
	for (int i = 0; i < grades_count; ++i)
		in >> tmp.grade[i];
	obj.surname = tmp.surname;
	obj.average_grade = average(tmp.grade);
	return in;
}

bool task_type::operator<(task_type obj)
{
	return surname < obj.surname;
}

bool task_type::operator>(task_type obj)
{
	return surname > obj.surname;
}

bool there_is_3(student_type student)
{
	bool result = false;
	for (int i = 0; i < grades_count && !result; ++i)
		if (student.grade[i] == 3)
			result = true;
	return result;
}