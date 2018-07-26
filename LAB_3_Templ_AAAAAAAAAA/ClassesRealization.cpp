#include "Header.h"
#include <iostream>
#include <string>
using namespace std;


Student::Student()
{
	this->Name = Name;
	this->Surname = Surname;
	this->SecondName = SecondName;
	this->scores = scores;	
}

void Student::BuildStudent()
{
	char s[256];
	char *p = s;
	cout << "Введите фамилию" << endl;
	cin >> s;
	this->Surname = s;
	cout << "Введите имя" << endl;
	cin >> s;
	this->Name = s;
	cout << "Введите отчество" << endl;
	cin >> s;
	this->SecondName = s;
	cout << "Введите средний балл студента" << endl;
	cin >> s;
	
	while (!CheckDataStudent(p))
		cin >> s;
	this->scores = atoi(s);

	while (scores < 0)
	{
		cin >> s;
		while (!CheckDataStudent(p))
			cin >> s;
		this->scores = atoi(s);
	}
	cout << "\n";
}
void Student::PrintStudent()
{
	char s[256];
	char *p = s;

	cout << "Фамилия:" << " ";
	cout << this->Surname << endl;

	cout << "Имя:" << " ";
	cout << this->Name << endl;

	cout << "Отчество:" << " ";
	cout << this->SecondName << endl;

	cout << "Средний балл" << " ";
	cout << this->scores << endl;
	
}


void Student::PrintName()
{
	cout << "Имя:" << " ";
	cout << Name << endl;
}
void Student::PrintSecondName()
{
	cout << "Отчество:" << " ";
	cout << SecondName << endl;
}
void Student::PrintSurname()
{
	cout << "Фамилия:" << " ";
	cout << Surname << endl;
}
void Student::PrintScores()
{
	cout << "Средний балл:" << " ";
	cout << scores << endl;
}
int Student::GetCurScores()
{
	return this->scores;
}

int Student::ChangeScores()
{
	this->scores = 5;
	return this->scores;
}

void Student::InputName(string s)
{
	this->Name = s;
}

void Student::InputSurname(string s)
{
	this->Surname = s;
}

void Student::InputSecondName(string s)
{
	this->SecondName = s;
}

void Student::InputScores(int x)
{
	this->scores = x;
}

bool Student::CheckDataStudent(char *ptr)
{
	bool isd = true;
	while (*ptr)
		if (!isdigit(*ptr++))
		{
			isd = false;
			break;
		}
	if (!isd)
		cout << "Введите целое положительное число, а не строку или дробное число" << endl;

	return isd;
}
//------------------------------------------------------------------------------------------//
Lecturer::Lecturer()
{
	this->Name = Name;
	this->SecondName = SecondName;
	this->Surname = Surname;
	this->experience = experience;
}

void Lecturer::BuildLecturer()
{
	char s[256];
	char *p = s;
	cout << "Введите фамилию" << endl;
	cin >> s;
	this->Surname = s;
	cout << "Введите имя" << endl;
	cin >> s;
	this->Name = s;
	cout << "Введите отчество" << endl;
	cin >> s;
	this->SecondName = s;
	cout << "Введите стаж преподавателя" << endl;
//	cin >> this->experience;
	cin >> s;
	/*
	while (!CheckType(p))
		cin >> s;
	int Mode = atoi(s);*/
	while (!CheckDataLecturer(p))
		cin >> s;
	this->experience = atoi(s);

	while (experience < 0)
	{
		cin >> s;
		while (!CheckDataLecturer(p))
			cin >> s;
		this->experience = atoi(s);

	}
}

bool Lecturer::CheckDataLecturer(char *ptr)
{
	bool isd = true;
	while (*ptr)
		if (!isdigit(*ptr++))
		{
			isd = false;
			break;
		}
	if (!isd)
		cout << "Введите целое положительное число, а не строку или дробное число" << endl;

	return isd;
}

void Lecturer::PrintLecturer()
{
	cout << "Фамилия:" << " ";
	cout << this->Surname << endl;
	cout << "Имя:" << " ";
	cout << this->Name << endl;
	cout << "Отчество:" << " ";
	cout << this->SecondName << endl;
	cout << "Стаж преподавателя:" << " ";
	cout << this->experience << endl;
}

int Lecturer::GetCurExperience()
{
	return this->experience;
}

void Lecturer::PrintName()
{
	cout << "Имя:" << " ";
	cout << Name << endl;
}

int Lecturer::ChangeExperience()
{
	this->experience = 5;
	return experience;
}

void Lecturer::PrintSecondName()
{
	cout << "Отество:" << " ";
	cout << SecondName << endl;
}

void Lecturer::PrintSurname()
{
	cout << "Фамилия:" << " ";
	cout << Surname << endl;
}

void Lecturer::PrintExperience()
{
	cout << "Стаж:" << " ";
	cout << experience << endl;
}

void Lecturer::InputName(string s)
{
	this->Name = s;
}

void Lecturer::InputSurname(string s)
{
	this->Surname = s;
}

void Lecturer::InputSecond(string s)
{
	this->SecondName = s;
}

void Lecturer::InputExperience(int x)
{
	this->experience = x;
}

int TypeOfFunction()
{
	cout << "Выберите, какое действие вы хотите произвести с деревом:" << endl;
	cout << "0 - если хотите завершить программу" << endl;
	cout << "1 - если хотите осуществить функцию map" << endl;
	cout << "2 - если хотите осуществить функцию where" << endl;
	cout << "3 - если хотите осуществить поиск элемента на вхождение" << endl;
	cout << "4 - если хотите выделить поддерево по элементу" << endl;
	cout << "5 - если хотите найти поддерево на вхождение" << endl;
	cout << "6 - если хотите осуществить слияние двух деревьев" << endl;

	int curType;
	char s[256];
	char *p = s;
	cin >> s;

	while (!CheckTypeOfData(p))
		cin >> s;
	curType = atoi(s);

	while (curType < 0 || curType > 6)
	{
		cout << "Введите число от 0 до 6" << endl;
		cin >> s;
		while (!CheckTypeOfData(p))
			cin >> s;
		curType = atoi(s);
	}

	return curType;
}

bool CheckTypeOfData(char *ptr)
{
	bool isd = true;
	while (*ptr)
		if (!isdigit(*ptr++))
		{
			isd = false;
			break;
		}
	if (!isd)
		cout << "Введите целое положительное число, а не строку или дробное число" << endl;

	return isd;
}