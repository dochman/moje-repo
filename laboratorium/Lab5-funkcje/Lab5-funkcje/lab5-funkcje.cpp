#include <iostream>
#include <ctime>
//#include "dodawanie.h"

using namespace std;

/*void sayhello()                           //funkcja nic nie zwraca(zadnej wartosci)
{
	cout << "Hello world" << endl;
	return;                             //cos wpisane po return sie nie wykona/nie wyswietli
	cout << "bye";
										//w przypadku void nalezy dac return; <bez 0 bo nie zwaraca wartosci
}*/

/*int Add(int& a, int b)                         //a,b parametry formalne
{
	a += b;
	return a;   //return a gdy a+=b to wynik ten sam / return a+b;
}*/


/*
przekazanie tablicy
void f(int* tab, int size)  lub tab[] bez *
{
}
*/



//ZAD1, funkcja zwracajaca sume dwoch liczb typu double
double dodaj(double a, double b)
{
	return a + b;
}

//ZAD2, funkcja do zamiany wartosci zmiennych
void zamien(int& a, int& b)
{
	int rez;
	rez = a;
	a = b;
	b = rez;
}

//ZAD3, funkcje uzupelniajace tablice i wyswietlajaca
void lostablica(int* tablica, int rozmiar)
{
	srand(time(NULL));
	for (int i = 0;i < rozmiar;i++)
	{
		tablica[i] = rand() % 100;
	}
}

void wyswtablica(int* tablica, int rozmiar)
{
	for (int i = 0;i < rozmiar;i++)
	{
		cout << tablica[i] << " ";
	}
	cout << endl;

}

//ZAD4, funkcja podnoszaca liczbe double do potegi naturalnej
double potega(double podstawa, int wykladnik)
{
	double wynik=1;
	for (int i = 0;i < wykladnik;i++)
	{
		wynik = wynik*podstawa;
	}
	return wynik;
}

//ZAD5, liczenie odleglosci dwoch punktow od siebie
double odleglosc(double x1, double y1, double x2, double y2)
{
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}



//ZAD6, rozwiazanie ukladu rownan z dwoma niewiadomymi
void ukladrownan(double a1, double b1, double c1, double a2, double b2, double c2)
{
	double x, y, W, Wx, Wy;
	W = a1*b2 - b1*a2;
	Wx = c1*b2 - b1*c2;
	Wy = a1*c2 - c1*a2;

	if (W != 0)
	{
		x = Wx / W;
		y = Wy / W;
		cout << "Rownanie ma dwa jedno rozwiazanie: x= " << x << " i y= " << y << endl;
	}
	
	if ((W == 0) && (Wx == 0) && (Wy == 0))
	{
		cout << "Uklad nieoznaczony" << endl;
	}
	else if ((W == 0) && (Wx != 0 || Wy != 0))
	{
		cout << "Uklad sprzeczny" << endl;
	}
}

//ZAD7, ciag fibonacciego rekurencyjnie i iteracyjnie
int fibrek(int n)
{
	if (n<=2) return 1;
	return fibrek(n - 1) + fibrek(n - 2);
}

int fibint(int n)
{
	int F1 = 0;
	int F2 = 1;

	for (int i = 0;i < n-1;i++)
	{
		F2 = F2 + F1;
		F1 = F2-F1;
	}
	return F2;
}


//ZAD8, wyswietlenie tablicy od tylu bez uzycia petli
void wyswtablica2(int* tablica, int rozmiar)
{
	if (rozmiar > 0)
	{
		cout << tablica[rozmiar-1] << " ";
		wyswtablica2(tablica, rozmiar -1);
	}
}



int main()
{
	//cout << endl<<sayhello();
	/*int x = 4;								  //przekazywanie przez wartosc
	int y = 5;
	cout << Add(x, y) << endl;                //2,6 parametry aktualne
	cout << "x= " << x << endl;       */       //x bedzie rowny 4 bo pracuje na kopii zmiennej x a nie zmienia jej wartosci
	
	cout <<"1. Suma dwoch liczb typu double: "<< dodaj(5.0, 3.0) << endl;

	int x = 2;
	int y = 3;
	zamien(x, y);
	cout <<"2. Liczby po zamianie: "<< x << " " << y << endl;

	
	cout << "3. Wypelnienie tablicy losowymi wartosciami i jej wyswietlenie: " << endl;
	int tab[100];
	lostablica(tab, 10);
	wyswtablica(tab, 10);

	cout << "4. Podniesienie double do podanej potegi: " << potega(4, 2) << endl;
	cout << "5. Odleglosc miedzy dwoma punktami w przestrzeni euklidesowej: " << odleglosc(0, 0, 1, 1) << endl;
	cout << "6. Rozwiazanie ukladu rownan z dwoma niewiadomymi: "<< endl;
	ukladrownan(5,-4,8,4,2,22);
	cout << "7a. Ciag fibonacciego rekurencyjnie (wyraz jedenasty): " << fibrek(11) << endl;
	cout << "7b. Ciag fibonacciego iteracyjnie (wyraz jedenasty): " << fibint(11) << endl;
	cout << "8. Wyswietlenie zawartosci tablicy od tylu: " << endl;
	wyswtablica2(tab, 10);
	cout << endl;

	return 0;
}