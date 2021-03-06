//#pragma once
#include <string>

#ifndef _PARAMETRY_H
#define	_PARAMETRY_H

/*
Funkcja, która sczytuje parametry z konsoli i odpowiednio przypisuje do zmiennych nazwy podanych plików
Publikacja_file - nazwa pliku zawierającego publikacje
Opisy_bibliograficzne_file - nazwa pliku zawierającego opisy bibliograficzne
Wyjsciowy_file - nazwa pliku wyjsciowego
argc - liczba parametrów wywołania
argv = tablica parametrów
*/
bool Parsuj_parametry(int argc, char**argv, std::string& Publikacja_file, std::string& Opisy_bibliograficzne_file, std::string& Wyjsciowy_file);

#endif