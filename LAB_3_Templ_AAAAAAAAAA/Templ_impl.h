#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//строчка 44


template <class T>
void Tree<T>::DeleteTree(Node *node)
{
	//пустой узел или нет ? пустой , если последний элемент в дереве
	//если не пусто, удаление родителей и детей
	if (node && node != NULL)
	{
		DeleteTree(node->branch[0]);
		DeleteTree(node->branch[1]);
		delete node;
	}
}

template <class T>
int Tree<T>::GetHeight(Node *node)
{
	/*if (node == NULL)
		return 0;
	int max = 0;
	for (Node *current = node->branch[0]; current; current = current->branch[1])
	{
		int CurHeight = GetHeight(current);
		if (CurHeight > max)
			max = CurHeight;
	}
	return max + 1;*/
	Node *temp = node;
	int mx = 0;
	int h1 = 0, h2 = 0;
	if (node == NULL)
		return 0;
	if (node->branch[0])
		h1 = GetHeight(node->branch[0]);
	
	if (node->branch[1])
		h2 = GetHeight(node->branch[1]);
	mx = h1 > h2 ? h1 : h2;
	mx = mx + 1;
	//mx = max(h1, h2) + 1;
	return mx;
}

template <class T>
int Tree<T>::GetNodesOnLevel(Node *node, int level)
{
	if (node == NULL)
		return 0;
	if (level <= 0)
		return 0;
	NodeCount(node);
	return GetNodesOnLevel(node->branch[0], level - 1) + (level == 1) + GetNodesOnLevel(node->branch[1], level - 1);
}


int pow1(int val, unsigned int n)
{
	int r = 1; //для степени 0, результат = 1
	if (val != 0) //основания = 0 цикл не запускается
		for (int j = n; j >0; j--)
			r *= val;
	else
		r = 0;
	return r;
}

void Tree<Student>::GetTree()
{
	for (int i = 0; i < amount; i++)
	{
		cout << "				" << i + 1 << "." << endl;
		Student x;
		x.BuildStudent();
		Add(x);
	}
}

template <class T>
void Tree<T>::GetMode(int mode)
{
	this->CurrentMode = mode;
}

void Tree<Lecturer>::GetTree()
{
	for (int i = 0; i < amount; i++)
	{
		cout <<"				"<< i + 1 <<"."<<endl;
		Lecturer x;
		x.BuildLecturer();
		Add(x);
	}
}

template <class T>
void Tree<T>::GetObhod(int obhod) 
{
	this->CurrentObhod = obhod;
}

template <class T>
int Tree<T>::GetAmount()
{
	return amount;
}

template <class T>
int Tree<T>::NodeCount(Node *node)
{
	if (node && node->branch[0] == NULL && node->branch[1] == NULL)
		return 1;
	int left, right;
	if (node && node->branch[0] != NULL)
		left = NodeCount(node->branch[0]);
	else
		left = 0;
	if (node && node->branch[1] != NULL)
		right = NodeCount(node->branch[1]);
	else
		right = 0;

	return left + right + 1;
}

template <class T>
void Tree<T>::Add(Node *&node, const T &data)
{
	if (CurrentObhod == 1)
	{
		if (node == NULL)
		{
			node = new Node(data);
		}

		else
		{
			int n = 2;

			int k = GetHeight(node); // количество уровней
			//cout << "levels: " << k << endl;
			int MaxAmount = pow1(n, k - 1); //максимальное количество на уровне //p

			int CurAmount = GetNodesOnLevel(node, k); //количество элементов на уровне //ss
			//cout << "nodes on level: " << CurAmount <<endl;

			if (CurAmount <= MaxAmount)
			{
				//добавление на тот же уровень
				if (CurAmount < (MaxAmount / n))
					Add(node->branch[1], data);
				else
						Add(node->branch[0], data);
			}
			else
				Add(node->branch[1], data);
		}
	}
	
	if (CurrentObhod == 2)
	{
		if (node == NULL)
		{
			node = new Node(data);
		}

		else
		{
			int n = 2;

			int k = GetHeight(node); // количество уровней

			int MaxAmount = pow1(n, k - 1); //максимальное количество на уровне //p

			int CurAmount = GetNodesOnLevel(node, k); //количество элементов на уровне //ss

			if (CurAmount <= MaxAmount)
			{
				//добавление на тот же уровень
				if (CurAmount < (MaxAmount / n))
					Add(node->branch[0], data);
				else
						Add(node->branch[1], data);
			}
			else
				Add(node->branch[0], data);
		}
	}
}


template <class T>
void Tree<T>::GetAm(int am)
{
	this->amount = am;
}


int Tree<Student>::Search(Node *node, int find, int &flag)
{
	if (node)
	{
		if (node->data.GetCurScores() == find)
			flag = 1;
		Search(node->branch[0], find, flag);
		Search(node->branch[1], find,flag);
	}
	return flag;
}

int Tree<Lecturer>::Search(Node *node, int find,int &flag)
{
	if (node)
	{
		if (node->data.GetCurExperience() == find)
			flag = 1;

		Search(node->branch[0], find, flag);
		Search(node->branch[1], find, flag);
	}
	return flag;
}

void Tree<Student>::PrintNode(Node *node)
{
		node->data.PrintStudent();
	cout << "\n";
}

void Tree<Lecturer>::PrintNode(Node *node)
{
	node->data.PrintLecturer();
	cout << "\n";
}

template <class T>
void Tree<T>::ShowTree(Node *node)
{
	//LKP
	if (CurrentObhod == 2)
	{
		if (node)
		{
			if (node->branch[0]) 
			{
				cout << "{ " << endl;;
				PrintNode(node->branch[0]);
				cout << " }" << endl;
				ShowTree(node->branch[0]);
			}
				

			if (node == root)
				PrintNode(node);

			if (node->branch[1])
			{
				cout << "|| ";
				PrintNode(node->branch[1]);
				cout << " ||" << endl;
				ShowTree(node->branch[1]);
			}
		}
	}

	//PKL
	if (CurrentObhod == 1)
	{
		if (node)
		{	

			if (node->branch[1])
			{
				cout << "|| " << endl;
				PrintNode(node->branch[1]);
				cout << " ||" << endl;
				ShowTree(node->branch[1]);
			}
			
			if (node == root)
				PrintNode(node);

			
			if (node->branch[0])
			{
				cout << "{ ";
				PrintNode(node->branch[0]);
				cout << " }" << endl;
				ShowTree(node->branch[0]);
			}
				
		}
	}
}

//для map 
Student ChangeInt(Student x)
{
	x.ChangeScores();
	return x;
}

Lecturer ChangeInt(Lecturer x)
{
	x.ChangeExperience();
	return x;

}

template <class T>
void Tree<T>::map(Node *node, T (*f)(T), Tree<T> *NewTree)
{
	if (node != NULL)
	{
		T x = node->data;
		x = ChangeInt(x);
		NewTree->Add(x); // добавление в новое дерево
	}

	if (node->branch[0] != NULL)
		map(node->branch[0], f, NewTree);
	if (node->branch[1] != NULL)
		map(node->branch[1], f, NewTree);
}

template <class T>
void Tree<T>::where(Node* node, Tree<T> *NewTree)
{
	if (node != NULL)
	{
		if (checkData(node->data))
		{
			T ins = node->data;
			NewTree->Add(ins);
		}
		
		if (node->branch[0] != NULL)
			where(node->branch[0], NewTree);
		if (node->branch[1]!=NULL)
			where(node->branch[1], NewTree);
	}
}

bool checkData(Student x)
{
	if (x.GetCurScores() > 25)
		return true;
	else
		return false;
}

bool checkData(Lecturer x)
{
	if (x.GetCurExperience() > 25)
		return true;
	else
		return false;
}

template <class T>
void Tree<T>::MakeNewTree(Node *node, Tree<T> *t)
{
	if (node!= NULL)
	{
		T ins = node->data;
		t->Add(ins);
		
		if (node->branch[0] != NULL)
			MakeNewTree(node->branch[0], t);
		if (node->branch[1]!=NULL)
			MakeNewTree(node->branch[1], t);
	}
}


template <class T>
void Tree<T>::MakeDoubler(Node *&node, Tree<T> *&NewTree)
{
	int end = 0;
	if (node != NULL && end<amount)
	{
		T ins = node->data;
		NewTree->Add(ins);
		end++;
		if (node->branch[0] != NULL)
			MakeDoubler(node->branch[0], NewTree);
		if (node->branch[1] != NULL)
			MakeDoubler(node->branch[1], NewTree);
	}
}

int Tree<Lecturer>::FindNewRoot(Node *node, Tree<Lecturer> * &tree, int key, int &flag)
{
	if (node != NULL  && tree->root == NULL)
	{
		if (node->data.GetCurExperience() == key && flag == 0 )
		{
			tree->root = node;
			flag = 1;
		}
		if (node->branch[0] != NULL) 
			FindNewRoot(node->branch[0], tree, key, flag);
		if (node->branch[1] != NULL) 
			FindNewRoot(node->branch[1], tree, key, flag);
	}
	return flag;
}

int Tree<Student>::FindNewRoot(Node *node, Tree<Student> *&tree, int key, int &flag)
{
	if (node != NULL)
	{
		if (node->data.GetCurScores() == key)
		{
			tree->root = node;
			flag = 1;
		}

		if (node->branch[0] != NULL)
			FindNewRoot(node->branch[0], tree, key, flag);
		if (node->branch[1] != NULL) 
			FindNewRoot(node->branch[1], tree, key, flag);
		
	}
	return flag;
}

template <class T>
void Tree<T>::MergeTrees(Node *&nodeFirst, Tree<T> *secondTree)
{
	if (nodeFirst != NULL)
	{
		secondTree->Add(nodeFirst->data);
		MergeTrees(nodeFirst->branch[0], secondTree);
		MergeTrees(nodeFirst->branch[1], secondTree);
	}
}

bool Tree<Lecturer>::FindLittleTreeRoot(Node *&node, Tree<Lecturer> *t, int &flag)
{
	if (node)
	{
		if (node->data.GetCurExperience() == t->GetRoot()->data.GetCurExperience())
		{
			Node *tmp = t->GetRoot();
			int found = 0;
			int count = 0;
			found = FindLittleTreeBranches(node, tmp, count);
			
			if (found == t->GetAmount())
			{
				flag = 1;
				return flag;
			}
		}
		else 
			if (flag != 1 || node->data.GetCurExperience() != t->GetRoot()->data.GetCurExperience())
			{
				FindLittleTreeRoot(node->branch[0], t, flag);
				FindLittleTreeRoot(node->branch[1], t, flag);
			}
	}
	return flag;
}

//для веточек
template <>
int Tree<Lecturer>::FindLittleTreeBranches(Node *&nodeFirst, Node *&nodeSecond, int &IfEqual)
{
	if (nodeFirst && nodeSecond)
	{
		if (nodeFirst->data.GetCurExperience() == nodeSecond->data.GetCurExperience())
			IfEqual++;
	
		FindLittleTreeBranches(nodeFirst->branch[0], nodeSecond->branch[0], IfEqual);
		FindLittleTreeBranches(nodeFirst->branch[1], nodeSecond->branch[1], IfEqual);
	}
	return IfEqual;
}

bool Tree<Student>::FindLittleTreeRoot(Node *&node, Tree<Student> *t,int &flag)
{
	if (node)
	{
		if (node->data.GetCurScores() == t->GetRoot()->data.GetCurScores())
		{
			Node *tmp = t->GetRoot();
			int found = 0;
			int count = 0;
			found = FindLittleTreeBranches(node, tmp, count);

			if (found == t->GetAmount())
			{
				flag = true;
				return flag;
			}
		}
		else
			if (flag != 1 || node->data.GetCurScores() != t->GetRoot()->data.GetCurScores())
			{
				FindLittleTreeRoot(node->branch[0], t, flag);
				FindLittleTreeRoot(node->branch[1], t, flag);
			}

	}
	return flag;
}

//для веточек
template <>
int Tree<Student>::FindLittleTreeBranches(Node *&nodeFirst, Node *&nodeSecond, int &IfEqual)
{
	if (nodeFirst && nodeSecond)
	{
		if (nodeFirst->data.GetCurScores() == nodeSecond->data.GetCurScores())
			IfEqual++;
		FindLittleTreeBranches(nodeFirst->branch[0], nodeSecond->branch[0], IfEqual);
		FindLittleTreeBranches(nodeFirst->branch[1], nodeSecond->branch[1], IfEqual);
	}
	return IfEqual;
}

//-----------------------------------------------------------------------------------------------------------------------------//
template <class T>
bool Tree<T>::ifNullRoot(Node *node)
{
	if (node != NULL)
		return true;
	else
		return false;
}