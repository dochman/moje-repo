//#pragma once
#include <string>

#ifndef _PARAMETRY_H
#define	_PARAMETRY_H

/*
Funkcja, kt�ra sczytuje parametry z konsoli i odpowiednio przypisuje do zmiennych nazwy podanych plik�w
Publikacja_file - nazwa pliku zawieraj�cego publikacje
Opisy_bibliograficzne_file - nazwa pliku zawieraj�cego opisy bibliograficzne
Wyjsciowy_file - nazwa pliku wyjsciowego
argc - liczba parametr�w wywo�ania
argv = tablica parametr�w
*/
bool Parsuj_parametry(int argc, char**argv, std::string& Publikacja_file, std::string& Opisy_bibliograficzne_file, std::string& Wyjsciowy_file);

#endif