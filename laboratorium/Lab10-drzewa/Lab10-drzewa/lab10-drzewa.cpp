#include <iostream>



using namespace std;

struct Node
{
	int val;
	Node *left, *right;
	//Node* parent;
};

/*struct ListElem         drzewo ktore ma w sobie listy
{
	string Imie;
	ListElem* next;
};

struct NodeWiek
{
	int wiek;
	NodeWiek *left, *right;
	ListElem* head;
};*/

void AddRecursive(Node*&root, int val)   //rekurencyjne dodawanie elementow do drzewa
{
	/*
	nast = new Node{ val, nullptr,nullptr };
	if (val > root->val) AddRecursive(root->right,val);
	else if (val < root->val) AddRecursive(root->left, val);*/

	if (!root)
		root = new Node{ val,nullptr,nullptr };
	else if (val < root->val) AddRecursive(root->left, val);
	else AddRecursive(root->right, val);
}

void Print(Node* root)  //wyswietlenie drzewa
{
	if (!root) return;
	/*else if (root->right != nullptr) cout << root->val;
	else if (root->left != nullptr)cout << root->val;*/
	cout << root->val << " ";
	Print(root->left);
	Print(root->right);
}

void Printsort(Node* root)  //wyswietlanie drzewa posortowanego, rosnaco
{
	if (!root) return;
	Printsort(root->left);   //wyswietl lewe poddrzewo
	cout << root->val << " ";  //wyswietl siebie
	Printsort(root->right);   //wyswietl prawe poddrzewo
}

void usun(Node*&root)  //korzen musi byc przekazany przez referencje nie przez wartosc
{
	if (!root) return;
	usun(root->left);  //usun lewe poddrzewo
	usun(root->right);  //usun prawe poddrzewo
	delete root;         //usun siebie
	root = nullptr;       //wskaznik musi na koncu wskazywac null
}

void dodajiter(Node* &root, int val)
{
	Node* pom=root;
	if (!root)
	{
		root = new Node{ val,nullptr,nullptr };
		return;
	}
	else

	while (true)
	{
		if (val < pom->val)
		{
				if (pom->left) pom = pom->left;
					else
					{
						pom->left = new Node{ val,nullptr,nullptr };
						return;
					}
		}

		else
		{
			if (val > pom->val)
			{
				if (pom->right) pom = pom->right;
				else
				{
					pom->right = new Node{ val,nullptr,nullptr };
					return;
				}
			}
		}

	}
}


void usundanyelement()
{


}



int main()
{
	Node* root = nullptr;
	AddRecursive(root, 10);
	AddRecursive(root, 5);
	AddRecursive(root, 15);
	Print(root);

	cout << endl;

	Printsort(root);
	usun(root);
	return 0;
}