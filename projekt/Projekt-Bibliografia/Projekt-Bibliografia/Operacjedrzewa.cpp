#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Operacjedrzewa.h"

using namespace std;

struct MainNode
{
	string Etykieta;
	string Imie;
	string Nazwisko;
	string Tytul;

	MainNode *left, *right;
};

struct SubNode
{
	string Etykieta;
	string Imie;
	string Nazwisko;
	string Tytul;
	int Numer;

	SubNode *left, *right;
};

void DodajGlowneDrzewo(MainNode*&root, string Etykieta, string Imie, string Nazwisko, string Tytul)
{
	if (!root)
		root = new MainNode{ Etykieta, Imie, Nazwisko, Tytul,nullptr,nullptr };
	else if (Etykieta < root->Etykieta) DodajGlowneDrzewo(root->left, Etykieta, Imie, Nazwisko, Tytul);
	else DodajGlowneDrzewo(root->right, Etykieta, Imie, Nazwisko, Tytul);
}


void DodajPoddrzewo(SubNode*&subroot, string Etykieta, string Imie, string Nazwisko, string Tytul, int Numer)
{
	if (!subroot)
		subroot = new SubNode{ Etykieta, Imie, Nazwisko, Tytul, 0, nullptr, nullptr };
	else if (Nazwisko < subroot->Nazwisko) DodajPoddrzewo(subroot->left, Etykieta, Imie, Nazwisko, Tytul, Numer);
	else DodajPoddrzewo(subroot->right, Etykieta, Imie, Nazwisko, Tytul, Numer);
}


MainNode* SzukajWDrzewie(MainNode*& wsk, string szukana)
{
	bool znaleziony = false;

	while (wsk && !znaleziony)
	{
		if (wsk->Etykieta == szukana) znaleziony = true;
		else if (wsk->Etykieta > szukana) wsk = wsk->left;
		else wsk = wsk->right;
	}
	return wsk;
}


SubNode* SzukajWPoddrzewie(SubNode*& wsk, string szukana)
{
	bool znaleziony = false;
	auto temp = wsk;

	while (temp && !znaleziony)
	{
		if (temp->Nazwisko == szukana) znaleziony = true;
		else if (temp->Nazwisko > szukana) temp = temp->left;
		else temp = temp->right;
	}
	return temp;
}


void UsunGlowneDrzewo(MainNode*&root)
{
	if (!root) return;
	UsunGlowneDrzewo(root->left);
	UsunGlowneDrzewo(root->right);
	delete root;
	root = nullptr;
}


void UsunPoddrzewo(SubNode*&subroot)
{
	if (!subroot) return;
	UsunPoddrzewo(subroot->left);
	UsunPoddrzewo(subroot->right);
	delete subroot;
	subroot = nullptr;
}


void NadajNumery(SubNode*&subroot, int& licznik)
{
	if (!subroot) return;
	else
	{
		NadajNumery(subroot->left, licznik);
		licznik = licznik + 1;
		subroot->Numer = licznik;
		NadajNumery(subroot->right, licznik);
		return;
	}
}