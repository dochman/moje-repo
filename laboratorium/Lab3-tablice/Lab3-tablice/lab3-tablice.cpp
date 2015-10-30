#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	//ZAD1, wypelnienie tablicy wartosciami losowymi, wypisanie tablicy
	/*srand(time(NULL));
	int tab[20];

	cout << "Tablica jednowymiarowa z losowymi wartosciami (0-100): " << endl;
	for (int i = 0; i < 20; i++)
	{
		tab[i] = rand() % 101;
		cout << tab[i] << endl;
	}
	*/


	//ZAD2, znajdz minimalny element, zamiana elementu minimalnego z pierwszym, sortowanie
	/*int min = INT_MAX;
	int rez,pozycja;

	for (int i = 0; i < 20; i++)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			pozycja = i;
		}
	}
	cout << "Minimalny element w tej tablicy to: " << min << endl;
	cout << endl;
	*/

	/*cout << "Tablica po zamianie elementu minimalnego z pierwszym" << endl;              //Zamiana tylko pierwszego elementu z minimalnym (zakomentowane)
	rez = tab[pozycja];
	tab[pozycja] = tab[0];
	tab[0] = rez;
	
	for (int i = 0; i < 20; i++)
	{
		cout << tab[i] << endl;
	}*/

	/*for (int i = 0; i < 20;i++)                                                             //sortowanie calej tablicy
		for (int j = 0; j<19 ;j++)
		{
			if (tab[j] > tab[j+1])
			{
				rez = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = rez;
			}
		}

	cout << "Tablica po przesortowaniu: " << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << tab[i] << endl;
	}
	*/

	//ZAD3, tabliczka mnozenia (przy wyswietlaniu system hex)
	int tab2[17][18] = {};
	int i, j;

	for (i = 1;i < 17;i++)                                 //wypelnienie granicznej kolumny
	{
		tab2[i][0] = i;
	}

	for (j = 1;j < 17;j++)									//wypelnienie granicznego wiersza
	{
		tab2[0][j] = j;
	}

	for (i = 1;i < 17;i++)
		for (j = 1;j < 17;j++)
		{
			tab2[i][j] = tab2[i][0] * tab2[0][j];
		}

	for (i = 0;i < 17;i++)                                   //wyswietlanie tabliczki mnozenia w hex
		for (j = 0;j < 17;j++)
		{
			if (j == 1) cout << "|";
			cout <<setw(4)<< hex << tab2[i][j];

			if (i == 0 && j == 16)
			{
				cout << endl;
				cout << "    |----------------------------------------------------------------" << endl;;
			}
			else if (j == 16)
			{
				cout << endl;
			}
		}



	return 0;
}