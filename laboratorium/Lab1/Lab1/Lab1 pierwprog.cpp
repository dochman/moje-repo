#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char**argv)

{
	double a, b, c, delta,x1,x2,x1i,x2i;
	cout << "Funkcja kwadratowa" << endl;
	cout << "1 wspolczynnik" << endl;
	cin >> a;
	cout << "2 wspolczynnik" << endl;
	cin >> b;
	cout << "3 wspolczynnik" << endl;
	cin >> c;

	if (a != 0)
	{
		delta = (b*b) - (4 * a*c);

		if (delta < 0)
		{
			cout << "wyroznik ujemny, pierwiastki urojone" << endl;
			x1 = (-b / (2 * a));
			x1i =(sqrt(-delta) / (2 * a));
			x2 = (-b / (2 * a));
			x2i =(sqrt(-delta) / (2 * a));

			cout << "1 pierwiastek: " << x1 <<"+"<<x1i <<"i" << endl;
			cout << "2 pierwiastek: " << x2 <<"-"<<x2i << "i" << endl;
		}
		
		if (delta==0)
		{
			x1 = -b / (2*a);
			cout << "jedno rozwiazanie: " << x1 << endl;
		}
		
		if (delta>0)
		{
			x1 = (-b - sqrt(delta)) / (2 * a);
			x2 = (-b + sqrt(delta)) / (2 * a);
			cout << "1 pierwiastek: " << x1<<endl;
			cout << "2 pierwiastek: " << x2 << endl;
		}

	}
	else
	{
		cout << "Rownanie liniowe"<<endl;
	}

	return 0;


	/*
	typy plus prosty program:

	double a=4.0 / 3 * 3;
	double b=4;
	double suma;
	string str = "napis";
	bool b = true;
	b = false;
	unsigned int aa = 5;
	unsigned long long aaa = 5;
	char c = 't';

    cout << "Wpisz pierwsza lb." << endl;
	cin >> a;
	cout << "wpisz druga lb." << endl;
	cin >> b; 
	suma = a + b;
	cout << "Suma liczb: " << suma << endl;
	cout << a;
	cout << endl; 
	
	warunki:
	int wiek;
	cin>>wiek;
	if (wiek<18 && wiek>-1 )
	{
	cout<<"niepelnoletni\n";
    }

	operatory: ==,!=, <, >, <=, >=, && - and (i), || - or(lub)

	co gdy bledy?:
	jak debbugowac?
	klikamy obok zeby czerwona kropka byla (break point), f5 zeby skompilowac i sprawdzic blad
	f10 przejscie do nastepnej liczby
	przydatne do krokowego sprawdzania 
	
	*/
}