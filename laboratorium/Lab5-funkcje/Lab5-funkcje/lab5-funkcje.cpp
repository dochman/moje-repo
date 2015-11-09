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
double potega(double podstawa, unsigned int wykladnik)
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
	lostablica(tab, 100);
	wyswtablica(tab, 100);

	cout << "4. Podniesienie double do podanej potegi: " << potega(4, 2) << endl;
	cout << "5. Odleglosc miedzy dwoma punktami w przestrzeni euklidesowej: " << odleglosc(0, 0, 1, 1) << endl;
	return 0;
}