#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int main(int argc, char**argv)
{
	//ZAD1, wyswietlenie n-liczb po kolei
	/*int n,i;
	cout << "Podaj n (tyle liczb wyswietli sie rosnaco)" << endl;
	cin >> n;
	cout << "To sa te liczby" << endl;

	for (i = 1; i < n + 1; i++)
	{
		cout << i << "\n";
	}*/



	// ZAD2, wyswietlenie n-liczb po kolei ale od n
	/*int n, i;
	cout << "Podaj n (tyle liczb wyswietli sie malejaco)" << endl;
	cin >> n;
	cout << "To sa te liczby:" << endl;
	for (i=n; i>0 ; i--)
	{
		cout << i << "\n";
	}*/



	//ZAD3, wyswietlenie liczb z podanego przedzialu i podzielnych przez dzielnik
	/*int start, stop, dzielnik;
	cout << "wypisz poczatek przedzialu" << endl;
	cin >> start;
	cout << "wypisz koniec przedzialu" << endl;
	cin >> stop;
	cout << "wypisz dzielnik" << endl;
	cin >> dzielnik;

	for (int i = start; i < stop;i++)
	{
		if (i % dzielnik == 0)
		{
			cout << i << endl;
		}
	}
	*/



	//ZAD4, podniesienie do potegi
	/*int  wykladnik;
	double podstawa, wynik = 1;
	cout << "podaj podstawe" << endl;
	cin >> podstawa;
	cout << "podaj wykladnik" << endl;
	cin >> wykladnik;

	for (int i = 1; i < wykladnik + 1;i++)
	{
	 wynik = wynik*podstawa;
	}
	cout << wynik << endl;
	*/



	//ZAD5, czy liczba jest lb pierwsza
	/*int liczba;
	bool czy=true;
	cout << "podaj liczbe" << endl;
	cin >> liczba;

	if (liczba < 2)
	{
		cout << "Liczba nie jest liczba pierwsza" << endl;
	}
	else
	{
		for (int i = 2;i < liczba;i++)
		{
			if (liczba % i == 0) czy = false;
		}
		if (czy==true)
		{
			cout << "Liczba jest lb pierwsza" << endl;
		}
		if (czy == false)
		{
			cout << "lb nie jest lb pierwsza" << endl;
		}
	}
	*/



	//ZAD6a, zgadywanka w petli bez ograniczen, for
	/*int liczba, proba;
	srand(time(NULL));
	liczba = rand() % 21;

	cout << "Zgadnij jaka wylosowalem liczbe (0-20)" << endl;
	for (int i = 1;i < 21; i++)
	{
		cin >> proba;
		if (proba == liczba)
		{
			cout << "Gratulacje, zgadles!" << endl;
			break;
		}
		else if (proba > liczba)
		{
			cout << "Podana liczba jest wieksza od wylosowanej" << endl;
		}
		else
		{
			cout << "Podana liczba jest mniejsza od wylosowanej" << endl;
		}
	}*/



	//ZAD6b, zgadywanka w petli bez ograniczen, while
	/*int liczba, proba;
	srand(time(NULL));
	liczba = rand() % 21;
	cout << "Zgadnij jaka wylosowalem liczbe (0-20)" << endl;
	cin >> proba;
	while (proba != liczba)
	{
		if (proba > liczba)
		{
			cout << "Podana liczba jest wieksza od wylosowanej" << endl;
		}
		else if (proba < liczba)
		{
			cout << "Podana liczba jest mniejsza od wylosowanej" << endl;
		}
		cin >> proba;
	}
	cout << "Gratulacje, zgadles!" << endl;
	*/



	//ZAD6c, zgadywanka w petli bez ograniczen, do-while
	/*int liczba, proba;
	srand(time(NULL));
	liczba = rand() % 21;

	cout << "Zgadnij jaka wylosowalem liczbe (0-20)" << endl;
	do
	{
		cin >> proba;
		if (proba > liczba)
		{
			cout << "Podana liczba jest wieksza od wylosowanej" << endl;
		}
		else if (proba < liczba)
		{
			cout << "Podana liczba jest mniejsza od wylosowanej" << endl;
		}
	} while (proba != liczba);
	cout << "Gratulacje, zgadles!" << endl;
	*/



	//ZAD7a, zgadywanka z ograniczeniem, while
	/*int liczba, proba,liczbaprob=0;
	srand(time(NULL));
	liczba = rand() % 21;

	cout << "Zgadnij jaka wylosowalem liczbe (0-20)" << endl;
	while (liczbaprob!=6)
	{
		cin >> proba;
		liczbaprob = liczbaprob + 1;
		if (proba == liczba)
		{
			cout << "Gratulacje, zgadles!" << endl;
			break;
		}
		else if (proba > liczba)
		{
			cout << "Podana liczba jest wieksza od wylosowanej" << endl;
		}
		else
		{
			cout << "Podana liczba jest mniejsza od wylosowanej" << endl;
		}
	}
	cout << "Przekroczyles liczbe prob" << endl;
	*/


	//ZAD7b, zgadywanka z ograniczeniem, do-while
	/*int liczba, proba, liczbaprob = 0;
	srand(time(NULL));
	liczba = rand() % 21;

	cout << "Zgadnij jaka wylosowalem liczbe (0-20)" << endl;
	do
	{
		cin >> proba;
		liczbaprob = liczbaprob + 1;
		if (proba == liczba)
		{
			cout << "Gratulacje, zgadles!" << endl;
			break;
		}
		else if (proba > liczba)
		{
			cout << "Podana liczba jest wieksza od wylosowanej" << endl;
		}
		else
		{
			cout << "Podana liczba jest mniejsza od wylosowanej" << endl;
		}
	} while (liczbaprob != 6);
	*/



	//ZAD7c, zgadywanka z ograniczeniem, for
	/*int liczba, proba;
	srand(time(NULL));
	liczba = rand() % 21;

	cout << "Zgadnij jaka wylosowalem liczbe (0-20)- masz 6 prob" << endl;
	for (int i = 1;i < 7; i++)
	{
		cin >> proba;
		if (proba == liczba)
		{
			cout << "Gratulacje, zgadles!" << endl;
			break;
		}
		else if (proba > liczba)
		{
			cout << "Podana liczba jest wieksza od wylosowanej" << endl;
		}
		else
		{
			cout << "Podana liczba jest mniejsza od wylosowanej" << endl;
		}
	}*/

	//ZAD8, wprowadzenie liczb, wyswietlenie ich ilosci oraz liczenie sredniej, maks, min, odchylenia standardowego
	/*double liczba,max,min,odchylenie,srednia;
	double suma = 0;
	double suma2 = 0;
	int czy;
	int licznik = 0;
	max = -32000;
	min = 32000;
	odchylenie=0;
		do
		{
			cout << "Podaj liczbe " << endl;
			cin >> liczba;
			licznik++;

			suma2 = suma2 + pow(liczba, 2);

			if (liczba > max)
			{
				max = liczba;
			}

			if (liczba < min)
			{
				min = liczba;
			}

			suma = suma + liczba;
			cout << "Czy chcesz zakonczyc wpisywanie? (1-Tak, 0-Nie)" << endl;
			cin >> czy;
			system("cls");

		} while (czy!=1);

		srednia = suma / licznik;
		odchylenie= sqrt(suma2 / licznik - pow(srednia, 2));

		cout << "Ile wpisales liczb: " << licznik << endl;
		cout << "Srednia wpisanych liczb wynosi: " << srednia << endl;
		cout << "Minimalna z wprowadzonych liczb jest: " << min << endl;
		cout << "Maksymalna z wprowadzonych liczb jest: " << max << endl;
		cout << "Odchylenie standardowe wprowadzonych liczb wynosi: " << odchylenie << endl;
		*/

	return 0;
}