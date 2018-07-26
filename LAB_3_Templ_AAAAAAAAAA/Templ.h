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
	int CurrentMode; //�������� �� �����

public:
	Tree() { root = NULL; }
	~Tree()
	{
		DeleteTree(root);
	}
	void GetAm(int); //��������� ����������

	//������ ������
	int GetHeight() //�������� ������
	{
		return GetHeight(root);
	}

	//���-�� ��-� �� ������
	int GetNodesOnLevel() //���������� ����� �� ������
	{
		return GetNodesOnLevel(root, level);
	}

	//void BuildTree(int, int);//obhod, amount
	void Add(const T &elem) //���������� ��������
	{
		Add(root, elem);
	}

	void ShowTree() //�������� ������
	{
		ShowTree(root);
	}
	
	int Search(int x) //����� �������� �� ���������
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

	int FindNewRoot(Tree<T> *t, int key) //���������� ���������
	{
		int flag = 0;
		FindNewRoot(root, t, key, flag);
		return flag;
	}

	void GetTree();
	void GetMode(int); //�������� ����� ������ � ������
	void GetObhod(int); //�������� ��� ������ 
	int Search(Node*,int, int &el); //����� �������� �� ���������
	int GetAmount();//�������� ����������
	Node* GetRoot()//����������� �����
	{
		return root;
	}
	
	void MergeTrees(Tree<T> *t) //������� ��������
	{
		MergeTrees(root, t);
	}
	bool FindLittleTreeRoot(Tree<T> *t) //����� ������
	{
		int flag = 0;
		flag = FindLittleTreeRoot(root, t, flag);
		return flag;
	}

	//--------------------TEST------------------------------------//
	void Test_GetTree();//�������� ������������� ������������ ������
	void Test_Map(Tree<T>* t)
	{
		Test_Map(root, t);
	}
	void TestChange() //������ � ������ ���� ������� ������ �� 5
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
	bool ifNullRoot() //������� ������ ��� ���. ��� where
	{
		return ifNullRoot(root);
	}
	void Test_MakeLittleTree(); //�������� ���������� ������ ���  ������� � ������
	void Test_FindNewRoot(); //��������� ���������
	void Test_MakeEtalonTreeForMerge(); //�������� ��������� ����������� ����� ����� ���������� �������
	//-----------------------------------------------------------//
private:
	void MergeTrees(Node *&node, Tree<T> *second); //�������
	void map(Node*, T(*f)(T), Tree<T>*); //map
	int NodeCount(Node*); //������� ���������� �������� � ����
	void MakeNewTree(Node*, Tree<T>*); //�������� ������ ������
	void MakeDoubler(Node *&n, Tree<T> *&t); //������� ����������� ������
	void where(Node*, Tree<T>*); //where
	int FindNewRoot(Node *node, Tree<T> *&t, int k, int &f); //��������� ��������� �� ��������
	void Add(Node *&node, const T &elem); //���������� ��������
	void ShowTree(Node*); //����� ������ �� �����
	void DeleteTree(Node *); //�������� ������
	int GetHeight(Node*); //��������� ������ ������
	int GetNodesOnLevel(Node *node, int level); //��������� ���������� ����� �� ������
	void PrintNode(Node*); //������ ����
	bool FindLittleTreeRoot(Node *&node, Tree<T> *t, int &flag); //��� ������ ������ �� ���������, ����� ��������� ����
	int FindLittleTreeBranches(Node *&nodeFirst, Node *&nodeSecond, int &IfEqual); //�������� ���������� ������� ������ ��� ������ � ��������� ������
	bool ifNullRoot(Node *node); //�������� ���� ������ �������, ��� where
	//-------------------------------TEST--------------------------------------------//
	void Test_Map(Node*, Tree<T>*);
	void TestChange(Node*);
	void Test_Where(Node *node);
};


#include "Templ_impl.h"
#endif // ! _TEMPL__T__
