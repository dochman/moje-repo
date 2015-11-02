#include <iostream>
#include <string>
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

	//ZAD5, zamiana liczby na string
	int liczba;





	return 0;

}