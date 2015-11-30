#include <iostream>
#include <fstream>
#include <string>
using namespace std;


	/*
	int a = 5;
	int* a_p = &a; //  * - zmienna wskaznikowa, wskaznik wskazujacy na int musi byc typu int, moze tez byc uzyte auto (samodzielnie sam dobierze)


	cout << a_p << endl; //wyswietli adres zmiennej a
	cout << *a_p << endl; //wyswietli zawartosc zmiennej a, wiemy ze jest tym wskaznikiem wiec mowimy zeby dostal sie do tego na co wskazuje, dereferencja


	int ** a_p_p = &a_p;  //tworzenie wskaznika na wskaznik
	cout << **a_p_p <<endl; //wypisanie wskaznika wskazujacego na wskaznik wskazujacego na zmienna a


	int *p = nullptr; //NULL w nowym standardzie, null to jest 0 NULL <->0, pusty wskaznik
	p = new int;  //alokowanie pamieci
	int *x = new int;  //typ wskaznikowy inaczej niz wyzej
	*p = -10; // przypisanie do wskaznika pustego wartosci
	

	delete p; //zwalnianie pamieci na ktora wskazuje, mam odniesienie do pamieci ale stracilem dane i nie moge sie odwolywac
	p = nullptr; //po zwalnianiu dobrze jest zeby przypisac nulla, jesli nie zwolnie i nie dopisze to mzoe byc wyciek pamieci


	//tablice
	int tab[10] = { 1 }; //nazwa tablicy jest wskaznikiem na pierwszy element
	cout << tab[2] << endl; // zamienia na *(tab+2)
	cout << 2[tab] << endl; // zamieni na *(2+tab)
	cout << *(tab + 2) << endl;


	//tablica dynamiczna
	int c; //ilosc elementow
	cin >> c;
	int* dyn_tab = new int[c];  //new int(c) zalokowany int bedzie mial wartosc c
	
	delete[] dyn_tab;  //zwolnienie pamieci po tablicy


	//tablica dwuwymiarowa dynamiczna 10 na 20 deklaracja
	int** t2d = new int*[10];
	for (int i = 0; i < 10; ++i)
		t2d[i] = new int[20];

	for (for (int i = 0; i < 10; ++i)  //usuniecie najpierw tablic w srodku a potem calego wskaznika
		delete[] t2d[i];
	delete[] t2d;
	*/

	struct Person
	{
		string Imie;
		int Wiek;
	};



	
	


void odczytosob(const string &file_name)
	{


		Person* tab[5]; //zamieniam sobie typ przechowywanych danych na wskaznikowy
		ifstream plik(file_name, ios::in);
		int i = 0;
		int suma=0;
		double sredni;
		int licznik = 0;

		string imie; //deklaruje sobie dodatkowe zmienne
		int wiek;

		while (plik >> imie >> wiek)
		{
			tab[licznik] = new Person; //new Person{imie, wiek};
			tab[licznik]->Imie = imie;
			tab[licznik]->Wiek = wiek;
			suma += tab[licznik]->Wiek;

			licznik += 1;
		}
		sredni = suma / licznik;

		
		for (i = 0; i < licznik;i++)
		{
			if (tab[i]->Wiek < sredni)
			{
				cout << tab[i]->Imie << " " << tab[i]->Wiek << endl;
			}
		}
		
		//for (i = 0;) //w petli pousuwac poszczegolne persony

		plik.close();

	}

int main()
{
	string file_name = "D:\\osoby.txt";
	cout << "Osoby ponizej sredniego wieku: " << endl;
	odczytosob(file_name);

}