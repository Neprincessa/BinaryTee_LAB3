#ifndef _LAB3__TPL__
#define _LAB3__TPL__

#include <string>
using namespace std; 

//--------------------------------------------------Типы данных------------------------------------------------------//

class Student
{
	string Name;
	string SecondName;
	string Surname;
	int scores;
public:
	Student();
	void BuildStudent();
	void PrintStudent();
	void PrintName();
	void PrintSecondName();
	void PrintSurname();
	void PrintScores();
	int GetCurScores();
	int ChangeScores();
	void InputName(string);
	void InputSurname(string);
	void InputSecondName(string);
	void InputScores(int);
	bool CheckDataStudent(char*);
};

class Lecturer
{
	string Name;
	string Surname;
	string SecondName;
	int experience;
public:
	Lecturer();
	void BuildLecturer();
	void PrintName();
	int ChangeExperience();
	void PrintSecondName();
	void PrintSurname();
	void PrintExperience();
	int GetCurExperience();
	void PrintLecturer();
	void InputName(string);
	void InputSurname(string);
	void InputSecond(string);
	void InputExperience(int);
	bool CheckDataLecturer(char*);
};

int TypeOfFunction();
bool CheckTypeOfData(char*);

#endif // !_LAB3__TPL__
