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

	cout << "���� �� ������ �������� � �������� ������, ������� 1" << endl;
	cout << "���� �� ������ �������� �� ����������, ������� 2" << endl;
	cout << "���� �� ������ �������� � ���������������, ������� 3" << endl;
	int mode;
	char s[256];
	char *p = s;

	cin >> s;
	while (!CheckTypeOfData(p))
		cin >> s;
	mode = atoi(s);

	while (mode < 1 || mode > 3)
	{
		cout << "������� ����� �� 1 �� 3" << endl;
		cin >> s;
		while (!CheckTypeOfData(p))
			cin >> s;
		mode = atoi(s);
	}

	start(mode);
	
	system("pause");
	return 0;
}