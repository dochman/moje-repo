#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	//ZAD1, wypelnienie tablicy wartosciami losowymi, wypisanie tablicy
	srand(time(NULL));
	int tab[20];

	cout << "Tablica jednowymiarowa z losowymi wartosciami (0-100): " << endl;
	for (int i = 0; i < 20; i++)
	{
		tab[i] = rand() % 101;
		cout << tab[i] << endl;
	}
	


	//ZAD2, znajdz minimalny element, zamiana elementu minimalnego z pierwszym, sortowanie
	int min = INT_MAX;
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

	/*cout << "Tablica po zamianie elementu minimalnego z pierwszym" << endl;
	rez = tab[pozycja];
	tab[pozycja] = tab[0];
	tab[0] = rez;
	
	for (int i = 0; i < 20; i++)
	{
		cout << tab[i] << endl;
	}*/

	for (int i = 0;i < 20;i++)
		for (int j = 0;)




	return 0;
}