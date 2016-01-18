#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct lista
{
	int wiek;
	string imie;
	lista *next;
};

void AddFront(lista* &glowa, int wiek, const string &imie)
{
	glowa = new lista{ wiek, imie, glowa};
}

void wyswietl(lista* &glowa)
{
	lista* nast;
	nast = glowa;
	while (nast != nullptr)
	{
		cout << nast->wiek << " "<< nast->imie<< " | ";
		nast = nast->next;
	}
	cout << endl;
}

int zlicz(lista* &glowa)
{
	int licznik = 0;
	lista* nast;
	nast = glowa;
	while (nast != nullptr)
	{
		licznik++;
		nast = nast->next;
	}
	return licznik;
}


// string -> c.str()
//.resize(...)
void save(const string &file_name, lista* glowa)
{
	fstream plik(file_name, ios::out | ios::binary);

	if (!plik)
	{
		cout << "Nie mozna otworzyc pliku: " << file_name << "\n";
		return;
	}

	for (int i = 0; i < zlicz(glowa); i++)
	{
		plik.write((char*)&glowa->wiek, sizeof(int));
	}

	plik.close();
}

void load(const string &file_name, lista* &glowa)
{
	ifstream plik2(file_name, ios::binary);
	if (!plik2)
	{
		cout << "Nie mozna otworzyc pliku: " << file_name << "\n";
		return;
	}

	int wiek;
	while (true)
	{
		

		plik2.read((char*)&wiek, sizeof(int));
		if (plik2)
			AddFront(glowa, wiek, "aaa");
		else
			break;
	}

	plik2.close();
}


int main()
{
	lista* head = nullptr;

	AddFront(head, 21, "Daniel");
	AddFront(head, 43, "Troll");
	AddFront(head, 10, "Olaf");
	AddFront(head, 67, "Krzysztof");
	AddFront(head, 20, "Patryk");
	
	wyswietl(head);


	const string file_name = "binarny.txt";
	save(file_name, head);
	load(file_name, head);
	wyswietl(head);
	
	return 0;
}
