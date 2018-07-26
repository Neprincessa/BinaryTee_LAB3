#ifndef _USER__U__
#define _USER__U__
#include "Header.h"
#include "Templ.h"
#include "Test.h"

void start(int mode)
{
	char s[256];
	char *p = s;
	int obh;
	int number;

	if (mode != 1)
	{
		cout << "������� ����� ���������" << endl;
		cin >> s;
		while (!CheckTypeOfData(p))
			cin >> s;
		number = atoi(s);
		while (number < 0)
		{
			cout << "������� ��������������� �����" << endl;
			cin >> s;
			while (!CheckTypeOfData(p))
				cin >> s;
			number = atoi(s);
		}

		cout << "�������� �����: 1 - ���, 2 - ���" << endl;

		cin >> s;
		while (!CheckTypeOfData(p))
			cin >> s;
		obh = atoi(s);

		while (obh < 0 || obh > 2)
		{
			cout << "������� ����� 1 ��� 2" << endl;
			cin >> s;
			while (!CheckTypeOfData(p))
				cin >> s;
			obh = atoi(s);
		}
	}

	if (mode == 1)
	{
		Tree<Student> TestTree;
		TestTree.GetObhod(1);
		TestTree.GetAm(5);
		TestTree.Test_GetTree();

		Tree<Student> TestTreeDoubler;
		TestTreeDoubler.GetAm(5);
		TestTreeDoubler.GetObhod(1);
		TestTree.MakeDoubler(&TestTreeDoubler);

		//map
		Tree<Student> Test_TreeForMap;
		Test_TreeForMap.GetObhod(1);
		Test_TreeForMap.GetAm(5);
		TestTree.map(&Test_TreeForMap,ChangeInt);
		TestTree.Test_Map(&Test_TreeForMap);

		//where
		Tree<Student> New_Tree_Where;
		New_Tree_Where.GetObhod(obh);
		TestTree.where(&New_Tree_Where);
		New_Tree_Where.Test_Where();

		//����� �������� �� ���������
		TestTreeDoubler.Test_Search();

		//����� ��������� �� ���������
		Tree<Student> LittleTree;
		LittleTree.GetAm(2);
		LittleTree.GetObhod(1);
		LittleTree.Test_MakeLittleTree();
		TestTreeDoubler.Test_FindLittleTree(&LittleTree);

		//��������� ���������
		TestTreeDoubler.Test_FindNewRoot();

		//�������
		TestTreeDoubler.Test_Merge();
	}

	if (mode == 2)
	{
		Tree<Student> tree;

		tree.GetAm(number);
		tree.GetObhod(obh);

		tree.GetTree();
		tree.ShowTree();
		cout << "\n";
		cout << "\n";

		int whatFunction = TypeOfFunction(); //check++

		while (whatFunction != NULL)
		{
			if (whatFunction == 0)
				break;

			if (whatFunction == 1)
			{
				//map
				cout << "MAP" << endl;
				Tree<Student> New_Tree;
				New_Tree.GetObhod(obh);
				tree.map(&New_Tree, ChangeInt);
				New_Tree.ShowTree();
				cout << "\n";
			}

			if (whatFunction == 2)
			{
				//where
				cout << "WHERE" << endl;
				Tree<Student> New_Tree_Where;
				New_Tree_Where.GetObhod(obh);
				tree.where(&New_Tree_Where);

				if (New_Tree_Where.ifNullRoot() == true)
					New_Tree_Where.ShowTree();
				else
					cout << "���������� �������� ����� ���������" << endl;
				cout << "\n";
			}

			if (whatFunction == 3)
			{
				//����� �������� �� ���������
				cout << "������� ������� ����, ������� �� ������ �����" << endl;
				int exp;
				char s[256];
				char *p = s;
				cin >> s;
				while (!CheckTypeOfData(p))
					cin >> s;
				exp = atoi(s);

				int res = tree.Search(exp);
				if (res == 1)
					cout << "������� � ����� ������� ������ ������" << endl;
				if (res == 0)
					cout << "������� � ����� ������� ������ �� ������" << endl;
				cout << "\n";
			}

			if (whatFunction == 4)
			{
				//���������� ���������
				int CurExp;
				cout << "������� ������� ���� ��������. ���� ����� ������ ������� � ����� ������, �� ����� �������� ���������" << endl;
				cin >> CurExp;
				int f = 0;
				Tree<Student> *New_Tree_Select = new Tree<Student>;
				New_Tree_Select->GetObhod(obh);

				int ifThereIs = tree.FindNewRoot(New_Tree_Select, CurExp);
				if (ifThereIs == 1)
					New_Tree_Select->ShowTree();
				if (ifThereIs == 0)
					cout << "��� ������ ��������, ������� � �������� ����� �������� ������" << endl;
			}

			if (whatFunction == 5)
			{
				//����� ���������
				cout << "������� ��������� ��� ������" << endl;
				Tree<Student> LittleTree;
				cout << "������� ���������� ���������" << endl;
				cin >> s;
				while (!CheckTypeOfData(p))
					cin >> s;
				number = atoi(s);
				while (number <= 0 || number > tree.GetAmount())
				{
					cout << "������� ��������������� ����� �� 1 �� ";
					cout << tree.GetAmount() << endl;
					cin >> s;
					while (!CheckTypeOfData(p))
						cin >> s;
					number = atoi(s);
				}
				LittleTree.GetObhod(obh);
				LittleTree.GetAm(number);
				LittleTree.GetTree();
				cout << "Little" << endl;
				LittleTree.ShowTree();

				int ifFoundLittleTree = tree.FindLittleTreeRoot(&LittleTree);
				if (ifFoundLittleTree == 1)
					cout << "��������� �������" << endl;
				else
					cout << "��������� �� �������" << endl;
			}

			if (whatFunction == 6)
			{
				//�������
				cout << "������� ������ ��� ������� ������� ������ ��� �������" << endl;
				Tree<Student> TreeForMerge;
				TreeForMerge.GetObhod(obh);
				cout << "������� ����� ��������� � ����� ������" << endl;
				int amount1;
				cin >> s;
				while (!CheckTypeOfData(p))
					cin >> s;
				amount1 = atoi(s);
				while (amount1 < 0)
				{
					cout << "������� ��������������� �����" << endl;
					cin >> s;
					while (!CheckTypeOfData(p))
						cin >> s;
					amount1 = atoi(s);
				}

				TreeForMerge.GetAm(amount1);
				TreeForMerge.GetTree();

				tree.MergeTrees(&TreeForMerge);
				cout << "				" << "Merged" << endl;
				TreeForMerge.ShowTree();
			}
			whatFunction = TypeOfFunction();
		}
	}


	if (mode == 3)
	{
		Tree<Lecturer> tree;
		tree.GetAm(number);

		//checks!!!
		tree.GetObhod(obh);

		tree.GetTree();
		tree.ShowTree();
		cout << "\n";
		cout << "\n";

		int whatFunction = TypeOfFunction(); //check++
		while (whatFunction != 0)
		{
			if (whatFunction == 0)
				break;

			if (whatFunction == 1)
			{
				//map
				cout << "MAP" << endl;
				Tree<Lecturer> New_Tree;
				New_Tree.GetObhod(obh);
				tree.map(&New_Tree, ChangeInt);
				New_Tree.ShowTree();
				cout << "\n";
			}

			if (whatFunction == 2)
			{
				//where
				cout << "WHERE" << endl;
				Tree<Lecturer> New_Tree_Where;
				New_Tree_Where.GetObhod(obh);
				tree.where(&New_Tree_Where);

				if (New_Tree_Where.ifNullRoot() == true)
					New_Tree_Where.ShowTree();
				else
					cout << "���������� �������� ����� ���������" << endl;
			}

			if (whatFunction == 3)
			{

				//����� �������� �� ���������
				cout << "������� ����, ������� �� ������ �����" << endl;
				int exp;
				char s[256];
				char *p = s;
				cin >> s;
				while (!CheckTypeOfData(p))
					cin >> s;
				exp = atoi(s);

				int res = tree.Search(exp);
				if (res == 1)
					cout << "������������� � ����� ������ ������" << endl;
				if (res == 0)
					cout << "������������� � ����� ������ �� ������" << endl;
				cout << "\n";
			}

			if (whatFunction == 4)
			{

				//���������� ���������
				int CurExp;
				cout << "������� ���� �������������. ���� ����� ������ ������������� � ����� ������, �� ����� �������� ���������" << endl;
				cin >> CurExp;
				int f = 0;
				Tree<Lecturer> *New_Tree_Select = new Tree<Lecturer>;
				New_Tree_Select->GetObhod(obh);

				int ifThereIs = tree.FindNewRoot(New_Tree_Select, CurExp);
				if (ifThereIs == 1)
					New_Tree_Select->ShowTree();
				if (ifThereIs == 0)
					cout << "��� ������ ��������, ������� � �������� ����� �������� ������" << endl;
				//�������� ���������
			}

			if (whatFunction == 5)
			{
				//����� ���������� �� ���������
				cout << "������� ��������� ��� ������" << endl;
				Tree<Lecturer> LittleTree;
				cout << "������� ���������� ���������" << endl;
				cin >> s;
				while (!CheckTypeOfData(p))
					cin >> s;
				number = atoi(s);
				while (number <= 0 || number > tree.GetAmount())
				{
					cout << "������� ��������������� ����� �� 1 �� ";
					cout << tree.GetAmount() << endl;
					cin >> s;
					while (!CheckTypeOfData(p))
						cin >> s;
					number = atoi(s);
				}
				LittleTree.GetObhod(obh);
				LittleTree.GetAm(number);
				LittleTree.GetTree();
				cout << "Little" << endl;
				LittleTree.ShowTree();

				int ifFoundLittleTree = tree.FindLittleTreeRoot(&LittleTree);
				if (ifFoundLittleTree == 1)
					cout << "��������� �������" << endl;
				else
					cout << "��������� �� �������" << endl;
			}

			if (whatFunction == 6)
			{
				//�������
				cout << "������� ������ ��� ������� ������� ������ ��� �������" << endl;
				Tree<Lecturer> TreeForMerge;
				TreeForMerge.GetObhod(obh);
				cout << "������� ����� ��������� � ����� ������" << endl;
				int amount1;
				cin >> s;
				while (!CheckTypeOfData(p))
					cin >> s;
				amount1 = atoi(s);
				while (amount1 < 0)
				{
					cout << "������� ��������������� �����" << endl;
					cin >> s;
					while (!CheckTypeOfData(p))
						cin >> s;
					amount1 = atoi(s);
				}
				TreeForMerge.GetAm(amount1);
				TreeForMerge.GetTree();

				tree.MergeTrees(&TreeForMerge);
				cout << "				" << "Merged" << endl;
				TreeForMerge.ShowTree();
			}
			whatFunction = TypeOfFunction();
		}
	}
}

#endif // !_USER__U__
