#include <iostream>
#include <string>
#include <cstddef> 
using namespace std;

int main(int argc, char**argv)
{
	//ZAD1, wyswietlanie parametrow wywolania programu, prawym na solucje, debugging i tam wpisac parametry
	/*cout << argc;
	for (int i = 0;i < argc;++i)
		cout << argv[i] << "\n";
		*/

	//ZAD2, dwa napisy od uzytkownika, ktory jest krotszy i ktory jest mniejszy leksykograficznie
	/*string napis1, napis2;
	int dl1, dl2;

	cout << "Podaj pierwszy napis: " << endl;
	getline(cin, napis1);
	cout << "Podaj drugi napis: " << endl;
	getline(cin, napis2);

	dl1=napis1.length();
	dl2 =napis2.length();

	if (dl1 > dl2)
	{
		cout << "Pierwszy napis jest dluzszy od drugiego" << endl;
	}
	else if (dl1 < dl2) cout << "Drugi napis jest dluzszy od pierwszego" << endl;
	else cout << "Napisy sa takiej samej dlugosci" << endl;

	if (napis1.compare(napis2) == 0)
	{
		cout << "Napisy sa identyczne leksykograficznie" << endl;
	}
	else if (napis1.compare(napis2) < 0)
	{
		cout << "Napis pierwszy jest mniejszy leksykograficznie od drugiego" << endl;
	}
	else cout << "Napis pierwszy jest wiekszy leksykograficznie od drugiego" << endl;
	*/


	//ZAD3, wczytac napis i kazdy znak 'A' zamienic na 'Z'
	/*string napis;
	int dl;

	cout << "Wpisz cos" << endl;
	getline(cin, napis);
	dl = napis.length();
	
	for (int i = 0;i < dl;i++)
	{
		if (napis[i] == 'A') napis[i] = 'Z';
		else if (napis[i] == 'a') napis[i] = 'z';
	}
	cout << napis << endl;
	*/


	//ZAD4, wczytac imie i nazwisko oraz wyswietlic jeden string skladajacy sie z trzech liter imienia i nazwiska
	/*string imie, nazwisko, kimie,razem;

	cout << "Podaj imie" << endl;
	cin >> imie;
	cout << "Podaj nazwisko" << endl;
	cin >> nazwisko;

	kimie = imie.substr(0, 3);
	razem = kimie.append(nazwisko, 0, 3);
	cout << razem << endl;
	*/

	//ZAD5, zamiana liczby na string, system dziesietny
	/*int liczba;
	string napis,napispzm,rez;
	
	cout << "Podaj liczbe do zamiany na string: " << endl;
	cin >> liczba;

	do
	{

	if (liczba < 0)
	{
		napispzm = "-";
		liczba = -liczba;
	}

		rez += liczba % 10 + 48;
		liczba -= liczba % 10;
	} while (liczba /= 10);

	for (int i = rez.size() - 1; i >= 0; i--) napispzm += rez[i];

	cout <<"Liczba jako string: "<< napispzm << endl;
	*/



	//ZAD6, zamiana string na liczbe, system dziesietny
	/*int liczba,pozmianie=0;
	int i = 0;
	bool czy=true;
	string napis;
	cout << "Jaki lancuch zamienic na liczbe?" << endl;
	cin >> napis;

	if (napis[0] == '-')
	{
		i++;
		czy = false;
	}

	while (i < napis.size())
	{
		pozmianie = 10 * pozmianie + napis[i] - 48;
		i++;
	}
	if (czy) cout <<"Napis jako liczba: "<< pozmianie << endl;
	else cout << "Napis jako liczba: " << -pozmianie << endl;
	*/


	//ZAD7, zamiana liczby na string, rozne systemy
	/*int liczba,system,rez2;
	string napis, napispzm, rez;

	cout << "Podaj liczbe do zamiany na string: " << endl;
	cin >> liczba;
	cout << "Podaj system liczbowy: " << endl;
	cin >> system;

	do
	{
		if (liczba < 0)
		{
			napispzm = "-";
			liczba = -liczba;
		}

		rez2 = liczba % system;
		rez += liczba % system + 48;
		liczba -= liczba % system;

		switch (rez2)
		{
		case 10: napispzm = napispzm + 'A'; break;
		case 11: napispzm = napispzm + 'B'; break;
		case 12: napispzm = napispzm + 'C'; break;
		case 13: napispzm = napispzm + 'D'; break;
		case 14: napispzm = napispzm + 'E'; break;
		case 15: napispzm = napispzm + 'F'; break;
		}

	} while (liczba /= system);

	for (int i = rez.size() - 1; i >=0; i--) napispzm = napispzm + rez[i];

	cout << napispzm<< endl;
	*/

	//ZAD8, zamiana stringa na liczbe, rozne systemy
	/*int system, rez2;
	int pozmianie = 0;
	int liczba;
	int i = 0;
	string napis;

	cout << "Podaj lancuch do zamiany na liczbe: " << endl;
	cin >> napis;
	cout << "Podaj system liczbowy: " << endl;
	cin >> system;

	if (napis[0] == '-')
	{
		i++;
		czy = false;
	}


	while (i < napis.size())
	{
		pozmianie = system * pozmianie + napis[i] - 48;
		i++;
	}

	rez2 = pozmianie % system;
	switch (rez2)
	{
	case 10: pozmianie = pozmianie + 'A'; break;
	case 11: pozmianie = pozmianie + 'B'; break;
	case 12: pozmianie = pozmianie + 'C'; break;
	case 13: pozmianie = pozmianie + 'D'; break;
	case 14: pozmianie = pozmianie + 'E'; break;
	case 15: pozmianie = pozmianie + 'F'; break;
	}

	if (czy) cout <<"Napis jako liczba: "<< pozmianie << endl;
	else cout << "Napis jako liczba: " << -pozmianie << endl;
	*/

	//ZAD9a, kalkulator, liczba plus operacja plus druga liczba
	/*double liczba1, liczba2, wynik;
	char operacja;

	cout << "Podaj pierwsza liczbe" << endl;
	cin >> liczba1;
	cout << "Podaj jaka operacje chcesz wykonac" << endl;
	cin >> operacja;
	cout << "Podaj druga liczbe" << endl;
	cin >> liczba2;

	switch (operacja)
	{
		case '+':
		{
			wynik = liczba1 + liczba2;
			break;
		}
		case '-':
		{
			wynik = liczba1 - liczba2;
			break;
		}
		case '*':
		{
			wynik = liczba1 * liczba2;
			break;
		}
		case '/':
		{
			wynik = liczba1 / liczba2;
			break;
		}
		case '^':
		{
			wynik = pow(liczba1, liczba2);
			break;
		}
		default:
		{
			cout << "Bledna operacja" << endl;
			break;
		}
	}
	cout << wynik << endl;
	*/

	
	//ZAD9b, kalkulator, ulepszona wersja
	/*string napis;
	int czlon1, czlon2,dl;
	char operacja;
	string napis1, napis2;
	double wynik;


	cout << "Podaj rownanie do obliczenia" << endl;
	getline(cin,napis);


	int i = 0;
	int j = 0;
	napis1 = "                                                                                                          ";
	napis2 = "                                                                                                          ";


	while (napis.find(" ") != string::npos)
		napis.erase(napis.find(" "), 1);

	dl = napis.length();
	for (i = 0;i <dl;i++)
	{
		if ((napis[i] == '+') || (napis[i] == '-') || (napis[i] == '*')  || (napis[i] == '/')  || (napis[i] == '^'))
		{
			j = i;
			break;
		}
		napis1[i] = napis[i];
	}

	for (j=j+1;j < dl;j++)
	{
		operacja = napis[j - 2];
		napis2[j] = napis[j];
	}


	czlon1 = stoi(napis1);
	czlon2 = stoi(napis2);

	//cout << czlon1 << endl;
	//cout << czlon2 << endl;
	//cout << operacja << endl;
	

	//cout << czlon1 << " " << operacja << " " << czlon2 << endl;

	switch (operacja)
	{
	case '+':
	{
		wynik = czlon1 + czlon2;
		break;
	}
	case '-':
	{
		wynik = czlon1 - czlon2;
		break;
	}
	case '*':
	{
		wynik = czlon1 * czlon2;
		break;
	}
	case '/':
	{
		wynik = (czlon1) / (czlon2);
		break;
	}
	case '^':
	{
		wynik = pow(czlon1, czlon2);
		break;
	}
	default:
	{
		cout << "Bledna operacja" << endl;
		break;
	}
	}

	cout << wynik << endl;
	*/

	//ZAD10, czy slowo jest palindromem
	/*string slowo;
	int dl;

	cout << "podaj slowo: " << endl;
	cin >> slowo;

	dl = slowo.length();
	int i = dl / 2;
	bool czy = true;
	
	while (i > 0)
	{
		i = i - 1;
		if (slowo[i] != slowo[dl - i - 1]) czy = false;
	}
	if (czy) cout << "Slowo jest palindromem" << endl;
	else cout << "Slowo nie jest palindromem" << endl;
	*/

		return 0;

}