#ifndef _TEST__T__
#define _TEST__T__
#include "Header.h"
#include "Templ.h"

void Tree<Student>::Test_GetTree()
{
	Student *Array = new Student[5];
	Array[0].InputName("Alexandr");
	Array[0].InputSurname("Alexandrovich");
	Array[0].InputSecondName("Alexandrov");
	Array[0].InputScores(1);

	Array[1].InputName("Ivan");
	Array[1].InputSurname("Ivanovich");
	Array[1].InputSecondName("Ivanov");
	Array[1].InputScores(2);

	Array[2].InputName("Dmitriy");
	Array[2].InputSurname("Dmitrievich");
	Array[2].InputSecondName("Dmitrov");
	Array[2].InputScores(3);

	Array[3].InputName("Sergey");
	Array[3].InputSurname("Sergeevich");
	Array[3].InputSecondName("Sergeev");
	Array[3].InputScores(4);

	Array[4].InputName("Maxim");
	Array[4].InputSurname("Maximovich");
	Array[4].InputSecondName("Maximov");
	Array[4].InputScores(5);

	for (int i = 0; i < 5; i++)
	{
		Student x = Array[i];
		Add(x);
	}
}

void Tree<Student>::Test_Map(Node *node, Tree<Student> *resultTree)
{
	TestChange();
	int flag = FindLittleTreeRoot(resultTree);
	if (flag == 1)
		cout << "Функция map работает верно" << endl;
	else
		cout << "Функция map работает не верно" << endl;
}


void Tree<Student>::TestChange(Node *node)
{
	if (node)
	{
		node->data.InputScores(5);
		TestChange(node->branch[0]);
		TestChange(node->branch[1]);
	}
}


template <class T>
void Tree<T>::Test_Where(Node *node)
{
	if (node == NULL)
		cout << "Функция where работает верно" << endl;
	else
		cout << "Функция where работает не верно" << endl;
}

template <class T>
void Tree<T>::Test_Search()
{
	int res = Search(1);

	if (res == 1)
		cout << "Функция поиска элемента на вхождение работает верно" << endl;
	else
		cout <<"Функция поиска элемента на вхождение работает не верно" << endl;
}

void Tree<Student>::Test_MakeLittleTree()
{
	Student *Array = new Student[2];

	Array[0].InputName("Ivan");
	Array[0].InputSurname("Ivanovich");
	Array[0].InputSecondName("Ivanov");
	Array[0].InputScores(2);

	Array[1].InputName("Dmitriy");
	Array[1].InputSurname("Dmitrievich");
	Array[1].InputSecondName("Dmitrov");
	Array[1].InputScores(3);

	for (int i = 0; i < 2; i++)
	{
		Student x = Array[i];
		Add(x);
	}
}

void Tree<Student>::Test_FindLittleTree(Tree<Student> *tree)
{
	int res = FindLittleTreeRoot(tree);
	if (FindLittleTreeRoot(tree) == true)
		cout << "Функция поиска поддерева на вхождение работает верно" << endl;
	else
		cout << "Функция поиска поддерева на вхождение работает не верно" << endl;
}

void Tree<Student>::Test_FindNewRoot()
{
	Tree<Student> *New_Tree_Select = new Tree<Student>;
	New_Tree_Select->GetObhod(1);

	int ifThereIs = FindNewRoot(New_Tree_Select, 2);
	
	if (ifThereIs == 1)
		cout << "Функция выделения поддерева работает верно" << endl;
	else
		cout << "Функция выделения поддерева работает не верно" << endl;
}


void Tree<Student>::Test_MakeEtalonTreeForMerge()
{
	Student *Array = new Student[7];
	Array[0].InputName("Alexandr");
	Array[0].InputSurname("Alexandrovich");
	Array[0].InputSecondName("Alexandrov");
	Array[0].InputScores(1);

	Array[1].InputName("Ivan");
	Array[1].InputSurname("Ivanovich");
	Array[1].InputSecondName("Ivanov");
	Array[1].InputScores(2);

	Array[2].InputName("Dmitriy");
	Array[2].InputSurname("Dmitrievich");
	Array[2].InputSecondName("Dmitrov");
	Array[2].InputScores(3);

	Array[3].InputName("Sergey");
	Array[3].InputSurname("Sergeevich");
	Array[3].InputSecondName("Sergeev");
	Array[3].InputScores(4);

	Array[4].InputName("Maxim");
	Array[4].InputSurname("Maximovich");
	Array[4].InputSecondName("Maximov");
	Array[4].InputScores(5);

	Array[5].InputName("Ivan");
	Array[5].InputSurname("Ivanovich");
	Array[5].InputSecondName("Ivanov");
	Array[5].InputScores(2);

	Array[6].InputName("Dmitriy");
	Array[6].InputSurname("Dmitrievich");
	Array[6].InputSecondName("Dmitrov");
	Array[6].InputScores(3);

	for (int i = 0; i < 7; i++)
	{
		Student x = Array[i];
		Add(x);
	}
}

void Tree<Student>::Test_Merge()
{
	Tree<Student> TreeAfterMege_Etalon;
	TreeAfterMege_Etalon.GetAm(7);
	TreeAfterMege_Etalon.GetObhod(1);

	TreeAfterMege_Etalon.Test_MakeEtalonTreeForMerge();
	Tree<Student> TreeForMerge;
	TreeForMerge.GetAm(2);
	TreeForMerge.GetObhod(1);
	TreeForMerge.Test_MakeLittleTree();
	MergeTrees(&TreeForMerge);

	int res = TreeAfterMege_Etalon.FindLittleTreeRoot(&TreeForMerge);
	if (res == 1)
		cout << "Функция слияния деревьев работает верно" << endl;
	else
		cout << "Функция слияния деревьев работает не верно" << endl;
}
#endif // !_TEST__T__
