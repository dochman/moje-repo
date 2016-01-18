#include<iostream>
#include "Algorytmiczne.h"
using namespace std;

void Print(char tab[N][M])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			cout << tab[i][j];
		cout << "\n";
	}
}

/*
 Proszę napisać funkcję o nagłówku:
 void Move(char in[N][M], char out[N][M], int x, int y);
 Celem funkcji jest "przesunięcie" obrazu ASCII-art o x pozycji w poziomie i y pozycji w pionie. Pierwszy parametr funkcji to dwuwymiarowa tablica 
 reprezentująca obraz wejściowy. Drugim parametrem jest tablica reprezentująca obraz wyjściowy (po przesunięciu). Dopuszczalne są przesunięcia ujemne.
 
 Dla x przesunięcie dodatnie reprezentuje przesunięcie w prawo.
 Dla y przesunięcie dodatnie reprezentuje przesunięcie w dół.

 W sytuacji gdy element "wypada" poza tablicę powinno nastąpić jego "zawinięcie".
 Przykładowo dla obrazu

 /**\
 |  |
 \__/

 wywołanie funkcji z parametrami x=1, y=-1 powinno dać w wyniku:
 ||
 /\__
 \/**

*/

void Move(char in[N][M], char out[N][M], int x, int y)
{
}