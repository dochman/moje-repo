#include <iostream>
#include <ctime>

using namespace std;


int main(int argc, char**argv)
{
	srand(time(NULL));
	int liczba = rand() % 21;
	int proba1, proba2, proba3, proba4;
	
	//cout << liczba<<endl;
	cout << "Wylosowano liczbe z przedzialu 0-20, sprobuj ja odgadnac, masz 4 proby!" << endl;
	cout << "Podaj pierwszy typ: " << endl;
	cin >> proba1;

	if (proba1 == liczba)
	{
		cout << "Gratulacje, zgadles!" << endl;
	}
	else if (proba1 > liczba)
	{
		cout << "Niestety, wytypowana przez ciebie liczba jest wieksza od wylosowanej." << endl;

	}
	else if (proba1 < liczba)
	{
		cout<< "Niestety, wytypowana przez ciebie liczba jest mniejsza od wylosowanej." << endl;
	}

	if (proba1 != liczba)
	{
		cout << "Podaj drugi typ: " << endl;
		cin >> proba2;

		if (proba2 == liczba)
		{
			cout << "Gratulacje, zgadles!" << endl;
		}
		else if (proba2 > liczba)
		{
			cout << "Niestety, wytypowana przez ciebie liczba jest wieksza od wylosowanej." << endl;

		}
		else if (proba2 < liczba)
		{
			cout << "Niestety, wytypowana przez ciebie liczba jest mniejsza od wylosowanej." << endl;
		}

		if (proba2 != liczba)
		{
			cout << "Podaj trzeci typ: " << endl;
			cin >> proba3;

			if (proba3 == liczba)
			{
				cout << "Gratulacje, zgadles!" << endl;
			}
			else if (proba3 > liczba)
			{
				cout << "Niestety, wytypowana przez ciebie liczba jest wieksza od wylosowanej." << endl;

			}
			else if (proba3 < liczba)
			{
				cout << "Niestety, wytypowana przez ciebie liczba jest mniejsza od wylosowanej." << endl;
			}

			if (proba3 != liczba)
			{
				cout << "Podaj czwarty typ: " << endl;
				cin >> proba4;

				if (proba4 == liczba)
				{
					cout << "Gratulacje, zgadles!" << endl;
				}
				else if (proba4 > liczba)
				{
					cout << "Niestety, wytypowana przez ciebie liczba jest wieksza od wylosowanej." << endl;
					cout << "Wykorzystales swoje szanse, koniec gry!" << endl;
				}
				else if (proba4 < liczba)
				{
					cout << "Niestety, wytypowana przez ciebie liczba jest mniejsza od wylosowanej." << endl;
					cout << "Wykorzystales swoje szanse! Wylosowana liczba byla: " <<liczba<<". Koniec gry!"<< endl;
				}
			}
		}
	}
	return 0;
}