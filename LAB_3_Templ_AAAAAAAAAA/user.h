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
		cout << "Введите число элементов" << endl;
		cin >> s;
		while (!CheckTypeOfData(p))
			cin >> s;
		number = atoi(s);
		while (number < 0)
		{
			cout << "Введите неотрицательное число" << endl;
			cin >> s;
			while (!CheckTypeOfData(p))
				cin >> s;
			number = atoi(s);
		}

		cout << "Выберите обход: 1 - ПКЛ, 2 - ЛКП" << endl;

		cin >> s;
		while (!CheckTypeOfData(p))
			cin >> s;
		obh = atoi(s);

		while (obh < 0 || obh > 2)
		{
			cout << "Введите число 1 или 2" << endl;
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

		//поиск элемента на вхождение
		TestTreeDoubler.Test_Search();

		//поиск поддерева на вхождение
		Tree<Student> LittleTree;
		LittleTree.GetAm(2);
		LittleTree.GetObhod(1);
		LittleTree.Test_MakeLittleTree();
		TestTreeDoubler.Test_FindLittleTree(&LittleTree);

		//выделение поддерева
		TestTreeDoubler.Test_FindNewRoot();

		//слияние
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
					cout << "Невозможно выделить такое поддерево" << endl;
				cout << "\n";
			}

			if (whatFunction == 3)
			{
				//поиск элемента на вхождение
				cout << "Введите средний балл, который вы хотите найти" << endl;
				int exp;
				char s[256];
				char *p = s;
				cin >> s;
				while (!CheckTypeOfData(p))
					cin >> s;
				exp = atoi(s);

				int res = tree.Search(exp);
				if (res == 1)
					cout << "Студент с таким средним баллом найден" << endl;
				if (res == 0)
					cout << "Студент с таким средним баллом не найден" << endl;
				cout << "\n";
			}

			if (whatFunction == 4)
			{
				//извлечение поддерева
				int CurExp;
				cout << "Введите средний балл студента. Если будет найден студент с таким стажем, то будет выделено поддерево" << endl;
				cin >> CurExp;
				int f = 0;
				Tree<Student> *New_Tree_Select = new Tree<Student>;
				New_Tree_Select->GetObhod(obh);

				int ifThereIs = tree.FindNewRoot(New_Tree_Select, CurExp);
				if (ifThereIs == 1)
					New_Tree_Select->ShowTree();
				if (ifThereIs == 0)
					cout << "Нет такого элемента, начиная с которого можно выделить дерево" << endl;
			}

			if (whatFunction == 5)
			{
				//поиск поддерева
				cout << "Введите поддерево для поиска" << endl;
				Tree<Student> LittleTree;
				cout << "Введите количество элементов" << endl;
				cin >> s;
				while (!CheckTypeOfData(p))
					cin >> s;
				number = atoi(s);
				while (number <= 0 || number > tree.GetAmount())
				{
					cout << "Введите неотрицательное число от 1 до ";
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
					cout << "Поддерево найдено" << endl;
				else
					cout << "Поддерево не найдено" << endl;
			}

			if (whatFunction == 6)
			{
				//слияние
				cout << "Введите данные для созания второго дерева для слияния" << endl;
				Tree<Student> TreeForMerge;
				TreeForMerge.GetObhod(obh);
				cout << "Введите число элементов в новом дереве" << endl;
				int amount1;
				cin >> s;
				while (!CheckTypeOfData(p))
					cin >> s;
				amount1 = atoi(s);
				while (amount1 < 0)
				{
					cout << "Введите неотрицательное число" << endl;
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
					cout << "Невозможно выделить такое поддерево" << endl;
			}

			if (whatFunction == 3)
			{

				//поиск элемента на вхождение
				cout << "Введите стаж, который вы хотите найти" << endl;
				int exp;
				char s[256];
				char *p = s;
				cin >> s;
				while (!CheckTypeOfData(p))
					cin >> s;
				exp = atoi(s);

				int res = tree.Search(exp);
				if (res == 1)
					cout << "Преподаватель с таким стажем найден" << endl;
				if (res == 0)
					cout << "Преподаватель с таким стажем не найден" << endl;
				cout << "\n";
			}

			if (whatFunction == 4)
			{

				//извлечение поддерева
				int CurExp;
				cout << "Введите стаж преподавателя. Если будет найден преподаватель с таким стажем, то будет выделено поддерево" << endl;
				cin >> CurExp;
				int f = 0;
				Tree<Lecturer> *New_Tree_Select = new Tree<Lecturer>;
				New_Tree_Select->GetObhod(obh);

				int ifThereIs = tree.FindNewRoot(New_Tree_Select, CurExp);
				if (ifThereIs == 1)
					New_Tree_Select->ShowTree();
				if (ifThereIs == 0)
					cout << "Нет такого элемента, начиная с которого можно выделить дерево" << endl;
				//очищение указателя
			}

			if (whatFunction == 5)
			{
				//поиск поддеревоа на вхождение
				cout << "Введите поддерево для поиска" << endl;
				Tree<Lecturer> LittleTree;
				cout << "Введите количество элементов" << endl;
				cin >> s;
				while (!CheckTypeOfData(p))
					cin >> s;
				number = atoi(s);
				while (number <= 0 || number > tree.GetAmount())
				{
					cout << "Введите неотрицательное число от 1 до ";
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
					cout << "Поддерево найдено" << endl;
				else
					cout << "Поддерево не найдено" << endl;
			}

			if (whatFunction == 6)
			{
				//слияние
				cout << "Введите данные для созания второго дерева для слияния" << endl;
				Tree<Lecturer> TreeForMerge;
				TreeForMerge.GetObhod(obh);
				cout << "Введите число элементов в новом дереве" << endl;
				int amount1;
				cin >> s;
				while (!CheckTypeOfData(p))
					cin >> s;
				amount1 = atoi(s);
				while (amount1 < 0)
				{
					cout << "Введите неотрицательное число" << endl;
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
