#include <iostream>
#include "Pomoc.h"
using namespace std;

void Pomoc()
{
	cout << "Program Bibliografia" << endl;
	cout << "Aby poprawnie uzywac programu nalezy przy wywolywaniu podac nazwe programu oraz trzy glowne parametry:" << endl;
	cout << "-t <nazwa pliku wejsciowego bedacego publikacja z odnosnikami do literatury>" << endl;
	cout << "-b <nazwa pliku wejsciowego zawierajacego opisy bibliograficzne utworow>" << endl;
	cout << "-o <nazwa pliku wyjsciowego>" << endl;
	cout << "W pliku wyjsciowym pojawi sie przerobiona publikacja, gdzie etykiety zastapione zostana odpowiednimi numerami z bibliografii a nizej bedzie wyswietlona bibliografia" << endl;
}