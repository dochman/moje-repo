#include <iostream>
#include <string>
#include <fstream>
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


bool parse_parameters(int argc, char**argv, string& Publikacja_file, string& Opisy_bibliograficzne_file, string& Wyjsciowy_file)
{
	Publikacja_file = "";
	Opisy_bibliograficzne_file = "";
	Wyjsciowy_file = "";
	const string Publikacja_switch = "-t";
	const string Opisy_switch = "-b";
	const string Wyjsciowy_switch = "-o";

	for (int i = 1; i < argc - 1; ++i)
	{
		if (argv[i] == Publikacja_switch)
		{
			Publikacja_file = argv[++i];
		}
		else if (argv[i] == Opisy_switch)
		{
			Opisy_bibliograficzne_file = argv[++i];
		}
		else if (argv[i] == Wyjsciowy_switch)
		{
			Wyjsciowy_file = argv[++i];
		}
	}

	if (Publikacja_file == "" || Opisy_bibliograficzne_file == "" || Wyjsciowy_file == "")
	{
		return false;
	}
	return true;
}


void help()
{
	cout << "Program Bibliografia" << endl;
	cout << "Aby poprawnie uzywac programu nalezy przy wywolywaniu podac nazwe programu oraz trzy glowne parametry:" << endl;
	cout << "-t <nazwa pliku wejsciowego bedacego publikacja z odnosnikami do literatury>" << endl;
	cout << "-b <nazwa pliku wejsciowego zawierajacego opisy bibliograficzne utworow>" << endl;
	cout << "-o <nazwa pliku wyjsciowego>" << endl;
	cout << "W pliku wejsciowym pojawi sie przerobiona publikacja, gdzie etykiety zastapione zostana odpowiednimi numerami z bibliografii a nizej bedzie wyswietlona bibliografia" << endl;
}


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


void SzukajWDrzewie(MainNode*& wsk, string tmp)
{
	bool znaleziony=false;

	while (wsk && !znaleziony)
	{
		if (wsk->Etykieta == tmp) znaleziony = true;
		else if (wsk->Etykieta > tmp) wsk = wsk->left;
		else wsk = wsk->right;
	}
	return;
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



void CzytajPublikacje(const string& Publikacja_file, SubNode*& subroot, MainNode*& root)
{
	string tmp,wyraz;
	int pos=0;
	

	ifstream Publikacja(Publikacja_file);
	if (!Publikacja)
	{
		cout << "Nie mozna otworzyc pliku: " << Publikacja_file << "\n";
		return;
	}

	while (Publikacja >> wyraz)
	{
		if (wyraz[0] == '\\')
		{
			if (pos != string::npos)
			{
				pos=wyraz.find_first_of("{");
				pos = pos + 1;
				tmp = wyraz.substr(pos, wyraz.length()-pos-1);
				SzukajWDrzewie(root, tmp);
				DodajPoddrzewo(subroot, root->Etykieta, root->Imie,  root->Nazwisko,root->Tytul, 0);
			}
		}
	}
	Publikacja.close();
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


int main(int argc, char**argv)
{
	string Publikacja_file, Opisy_bibliograficzne_file, Wyjsciowy_file;
	if (!parse_parameters(argc, argv, Publikacja_file, Opisy_bibliograficzne_file, Wyjsciowy_file))
	{
		cout << "Podane zostaly bledne parametry, zastosuj sie do pomocy wyswietlonej ponizej:\n";
		help();
		return 1;
	}

	MainNode* root = nullptr;
	SubNode* subroot = nullptr;

	CzytajOpisy(Opisy_bibliograficzne_file, root);
	CzytajPublikacje(Publikacja_file, subroot, root);

	int licznik = 0;
	NadajNumery(subroot,licznik);

	UsunGlowneDrzewo(root);
	UsunPoddrzewo(subroot);
}