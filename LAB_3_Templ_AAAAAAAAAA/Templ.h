#ifndef  _TEMPL__T__
#define _TEMPL__T__
#include <string>
#include <iostream>
#include "Header.h"
using namespace std;

void start(int);


template <class T>
T ChangeInt(T x);

template <class T>
bool checkData(T x);

template <class T>
class Tree {
	
	struct  Node
	{
		T data;

		Node *branch[2];

		Node(T i, Node *s1 = NULL, Node *s2 = NULL, Node *s3 = NULL)
		{
			data = i;
			branch[0] = s1;
			branch[1] = s2;
		}

		int index;
	};

	Node *root;
	int amount;
	int CurrentObhod;
	int CurrentMode; //возможно не нужно

public:
	Tree() { root = NULL; }
	~Tree()
	{
		DeleteTree(root);
	}
	void GetAm(int); //заполнить количество

	//высота дерева
	int GetHeight() //получить высоту
	{
		return GetHeight(root);
	}

	//кол-во эл-в на уровне
	int GetNodesOnLevel() //количество узлов на уровне
	{
		return GetNodesOnLevel(root, level);
	}

	//void BuildTree(int, int);//obhod, amount
	void Add(const T &elem) //добавление элемента
	{
		Add(root, elem);
	}

	void ShowTree() //показать дерево
	{
		ShowTree(root);
	}
	
	int Search(int x) //поиск элемента на вхождение
	{
		int flag = 0;
		return Search(root, x, flag);
	}

	void where(Tree<T>*t) //where
	{
		where(root, t);
	}

	void map(Tree<T>* t, T (*f)(T)) //map
	{
		map(root, f, t);
	}
	
	void MakeDoubler(Tree<T> *t)
	{
		MakeDoubler(root, t);
	}

	int FindNewRoot(Tree<T> *t, int key) //извлечение поддерева
	{
		int flag = 0;
		FindNewRoot(root, t, key, flag);
		return flag;
	}

	void GetTree();
	void GetMode(int); //записать режим работы в дерево
	void GetObhod(int); //записать тип обхода 
	int Search(Node*,int, int &el); //поиск элемента на вхождение
	int GetAmount();//получить количество
	Node* GetRoot()//возвращение корня
	{
		return root;
	}
	
	void MergeTrees(Tree<T> *t) //слияние деревьев
	{
		MergeTrees(root, t);
	}
	bool FindLittleTreeRoot(Tree<T> *t) //поиск дерева
	{
		int flag = 0;
		flag = FindLittleTreeRoot(root, t, flag);
		return flag;
	}

	//--------------------TEST------------------------------------//
	void Test_GetTree();//создание автоматически заполненного дерева
	void Test_Map(Tree<T>* t)
	{
		Test_Map(root, t);
	}
	void TestChange() //замена в дереве всех средних баллов на 5
	{
		TestChange(root);
	}
	void Test_Where()
	{
		Test_Where(root);
	}
	void Test_Search();
	void Test_Merge();
	void Test_FindLittleTree(Tree<T>*);
	bool ifNullRoot() //нулевой корень или нет. для where
	{
		return ifNullRoot(root);
	}
	void Test_MakeLittleTree(); //создание маленького дерева для  слияния и поиска
	void Test_FindNewRoot(); //выделение поддерева
	void Test_MakeEtalonTreeForMerge(); //создание конечного корректного дереа после выполнения слияния
	//-----------------------------------------------------------//
private:
	void MergeTrees(Node *&node, Tree<T> *second); //слияние
	void map(Node*, T(*f)(T), Tree<T>*); //map
	int NodeCount(Node*); //подсчет количества потомков у узла
	void MakeNewTree(Node*, Tree<T>*); //создание нового дерева
	void MakeDoubler(Node *&n, Tree<T> *&t); //сделать аналогичное дерево
	void where(Node*, Tree<T>*); //where
	int FindNewRoot(Node *node, Tree<T> *&t, int k, int &f); //выделение поддерева по элементу
	void Add(Node *&node, const T &elem); //добавление элемента
	void ShowTree(Node*); //вывод дерева на экран
	void DeleteTree(Node *); //удаление деерва
	int GetHeight(Node*); //получение высоты дерева
	int GetNodesOnLevel(Node *node, int level); //получения количества узлов на уровне
	void PrintNode(Node*); //печать узла
	bool FindLittleTreeRoot(Node *&node, Tree<T> *t, int &flag); //для поиска дерева на вхождение, поисх вхождения узла
	int FindLittleTreeBranches(Node *&nodeFirst, Node *&nodeSecond, int &IfEqual); //проверка совпаления веточек дерева для поиска и основного дерева
	bool ifNullRoot(Node *node); //проверка если корень нулевой, для where
	//-------------------------------TEST--------------------------------------------//
	void Test_Map(Node*, Tree<T>*);
	void TestChange(Node*);
	void Test_Where(Node *node);
};


#include "Templ_impl.h"
#endif // ! _TEMPL__T__
