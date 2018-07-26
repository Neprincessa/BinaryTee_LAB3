#include "Header.h"
#include "Templ.h"
#include "user.h"
//#include "ClasseRealization.cpp"

#include <iostream>
#include <string>

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");

	cout << "Если вы хотите работать в тестовом режиме, нажмите 1" << endl;
	cout << "Если вы хотите работать со студентами, нажмите 2" << endl;
	cout << "Если вы хотите работать с преподавателями, нажмите 3" << endl;
	int mode;
	char s[256];
	char *p = s;

	cin >> s;
	while (!CheckTypeOfData(p))
		cin >> s;
	mode = atoi(s);

	while (mode < 1 || mode > 3)
	{
		cout << "Введите число от 1 до 3" << endl;
		cin >> s;
		while (!CheckTypeOfData(p))
			cin >> s;
		mode = atoi(s);
	}

	start(mode);
	
	system("pause");
	return 0;
}