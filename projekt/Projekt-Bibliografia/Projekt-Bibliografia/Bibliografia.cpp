#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//#include Operacje_na_plikach.h
//#include Operacje_na_drzewach.h
//#include Parametry.h
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


bool Parsuj_parametry(int argc, char**argv, string& Publikacja_file, string& Opisy_bibliograficzne_file, string& Wyjsciowy_file)
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


void Pomoc()
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


MainNode* SzukajWDrzewie(MainNode*& wsk, string tmp)
{
	bool znaleziony=false;

	while (wsk && !znaleziony)
	{
		if (wsk->Etykieta == tmp) znaleziony = true;
		else if (wsk->Etykieta > tmp) wsk = wsk->left;
		else wsk = wsk->right;
	}
	return wsk;
}


SubNode* SzukajWPoddrzewie(SubNode*& wsk, string tmp)
{
	bool znaleziony = false;
	auto temp = wsk;

	while (temp && !znaleziony)
	{
		if (temp->Nazwisko == tmp) znaleziony = true;
		else if (temp->Nazwisko > tmp) temp = temp->left;
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
	string tmp,wyraz,linia;
	int pos=0;
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


void ZastapNumerami(const string& Publikacja_file, const string& Wyjsciowy_file,SubNode*& subroot, MainNode*& root)
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
	string tmp,wyraz,linia;
	MainNode* wsk=nullptr;
	MainNode* wsk_dodatkowy = nullptr;
	SubNode* wskaznik = nullptr;

	while (getline(Publikacja, linia))
	{
		while (linia.find("\\cite") != string::npos)
		{
			pos = linia.find_first_of("{");
			pos = pos + 1;
			pos2 = linia.find_first_of("}");
			tmp = linia.substr(pos, pos2-pos);
			wsk = root;
			wskaznik = subroot;
			wsk_dodatkowy=SzukajWDrzewie(wsk, tmp);
			tmp = wsk_dodatkowy->Nazwisko;
			wskaznik=SzukajWPoddrzewie(wskaznik, tmp);
			linia.replace(linia.begin() + linia.find_first_of("\\"), linia.begin() + linia.find_first_of("}")+1, "[" + to_string(wskaznik->Numer) + "]");
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

int main(int argc, char**argv)
{
	string Publikacja_file, Opisy_bibliograficzne_file, Wyjsciowy_file;
	if (!Parsuj_parametry(argc, argv, Publikacja_file, Opisy_bibliograficzne_file, Wyjsciowy_file))
	{
		cout << "Podane zostaly bledne parametry, zastosuj sie do pomocy wyswietlonej ponizej:\n";
		Pomoc();
		return 1;
	}

	MainNode* root = nullptr;
	SubNode* subroot = nullptr;

	CzytajOpisy(Opisy_bibliograficzne_file, root);
	CzytajPublikacje(Publikacja_file, subroot, root);

	int licznik = 0;
	NadajNumery(subroot,licznik);


	ZastapNumerami(Publikacja_file, Wyjsciowy_file, subroot, root);
	WypiszBibliografie(Wyjsciowy_file, subroot);

	UsunGlowneDrzewo(root);
	UsunPoddrzewo(subroot);
}