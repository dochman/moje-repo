#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Operacjepliki.h"
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

void WypiszPoddrzewo(SubNode* subroot, const string & Wyjsciowy_file)
{
	ofstream Wyjsciowy(Wyjsciowy_file, ios::app);

	if (!subroot) return;
	WypiszPoddrzewo(subroot->left, Wyjsciowy_file);
	Wyjsciowy << "[" << subroot->Numer << "] " << subroot->Imie << " " << subroot->Nazwisko << " " << subroot->Tytul << endl;
	WypiszPoddrzewo(subroot->right, Wyjsciowy_file);

	Wyjsciowy.close();
}


void CzytajOpisy(const string& Opisy_bibliograficzne_file, MainNode*& root)
{
	string Etykieta;
	string Imie;
	string Nazwisko;
	string Tytul;
	string zbedna_linia;
	string wyraz;

	ifstream OpisyBibliograficzne(Opisy_bibliograficzne_file);
	if (!OpisyBibliograficzne)
	{
		cout << "Nie mozna otworzyc pliku: " << Opisy_bibliograficzne_file << "\n";
		return;
	}

	while (!OpisyBibliograficzne.eof())
	{
		getline(OpisyBibliograficzne, Etykieta);
		OpisyBibliograficzne >> Imie;
		OpisyBibliograficzne >> Nazwisko;
		getline(OpisyBibliograficzne, zbedna_linia);
		getline(OpisyBibliograficzne, Tytul);
		getline(OpisyBibliograficzne, zbedna_linia);

		DodajGlowneDrzewo(root, Etykieta, Imie, Nazwisko, Tytul);
	}

	OpisyBibliograficzne.close();
	return;
}


void CzytajPublikacje(const string& Publikacja_file, SubNode*& subroot, MainNode*& root)
{
	string tmp, wyraz, linia;
	int pos = 0;
	int pos2 = 0;
	MainNode* wsk = nullptr;


	ifstream Publikacja(Publikacja_file);
	if (!Publikacja)
	{
		cout << "Nie mozna otworzyc pliku: " << Publikacja_file << "\n";
		return;
	}

	while (getline(Publikacja, linia))
	{
		while (linia.find("\\cite") != string::npos)
		{
			pos = linia.find_first_of("{");
			pos = pos + 1;
			pos2 = linia.find_first_of("}");
			tmp = linia.substr(pos, pos2 - pos);
			wsk = root;
			SzukajWDrzewie(wsk, tmp);
			linia.replace(linia.begin() + linia.find_first_of("\\"), linia.begin() + linia.find_first_of("}") + 1, "[]");
			DodajPoddrzewo(subroot, wsk->Etykieta, wsk->Imie, wsk->Nazwisko, wsk->Tytul, 0);
			continue;
		}
	}

	Publikacja.close();
}


void ZastapNumerami(const string& Publikacja_file, const string& Wyjsciowy_file, SubNode*& subroot, MainNode*& root)
{
	ifstream Publikacja(Publikacja_file);
	if (!Publikacja)
	{
		cout << "Nie mozna otworzyc pliku: " << Publikacja_file << "\n";
		return;
	}

	ofstream Wyjsciowy(Wyjsciowy_file);
	if (!Wyjsciowy)
	{
		cout << "Nie mozna otworzyc pliku: " << Wyjsciowy_file << "\n";
		return;
	}

	int pos = 0;
	int pos2 = 0;
	string tmp, wyraz, linia;
	MainNode* wsk = nullptr;
	MainNode* wsk_dodatkowy = nullptr;
	SubNode* wskaznik = nullptr;

	while (getline(Publikacja, linia))
	{
		while (linia.find("\\cite") != string::npos)
		{
			pos = linia.find_first_of("{");
			pos = pos + 1;
			pos2 = linia.find_first_of("}");
			tmp = linia.substr(pos, pos2 - pos);
			wsk = root;
			wskaznik = subroot;
			wsk_dodatkowy = SzukajWDrzewie(wsk, tmp);
			tmp = wsk_dodatkowy->Nazwisko;
			wskaznik = SzukajWPoddrzewie(wskaznik, tmp);
			linia.replace(linia.begin() + linia.find_first_of("\\"), linia.begin() + linia.find_first_of("}") + 1, "[" + to_string(wskaznik->Numer) + "]");
		}
		Wyjsciowy << linia << endl;
	}

	Publikacja.close();
	Wyjsciowy.close();
}


void WypiszBibliografie(const string& Wyjsciowy_file, SubNode*& subroot)
{
	ofstream Wyjsciowy(Wyjsciowy_file, ios::app);
	if (!Wyjsciowy)
	{
		cout << "Nie mozna otworzyc pliku: " << Wyjsciowy_file << "\n";
		return;
	}

	Wyjsciowy << endl << endl << endl;
	Wyjsciowy << "--------------------------------------------------------------------------------------" << endl;
	Wyjsciowy << "Bibliografia" << endl;
	WypiszPoddrzewo(subroot, Wyjsciowy_file);

	Wyjsciowy.close();
}