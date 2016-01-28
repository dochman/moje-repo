//#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Operacjedrzewa.h"

#ifndef _OPERACJEPLIKI_H
#define	_OPERACJEPLIK_H

struct MainNode;
struct SubNode;

/*
Funkcja, która wypisuje informacje potrzebne w bibliografii na koñcu pliku wyjœciowego
subroot - korzeñ pomocniczego drzewa
Wyjsciowy_file - nazwa pliku wyjsciowego
*/
void WypiszPoddrzewo(SubNode* subroot, const std::string & Wyjsciowy_file);
/*
Funkcja czytaj¹ca z pliku o zadanej nazwie opisy bibliograficzne ksi¹¿ek i tworz¹ca z nimi drzewo g³ówne
Opisy_bibligoraficzne_file - nazwa pliku wejsciowego zawierajacego te opisy
root - korzeñ drzewa g³ównego
*/
void CzytajOpisy(const std::string& Opisy_bibliograficzne_file, MainNode*& root);
/*
Funkcja sczytuj¹ca tekst publikacji linia po linii z pliku
Publikacja_file - nazwa pliku wejœciowego z tekstem
root - korzeñ drzewa
*/
void CzytajPublikacje(const std::string& Publikacja_file, SubNode*& subroot, MainNode*& root);
/*
Funkcja zastepujaca numerami fragmenty tekstu publikacji /cite{etykieta}
Wyjsciowy_file - nazwa pliku wyjsciowego
Publikacja_file - nazwa pliku z ktorego szczytywane sa informacje
subroot, root - korzenie drzew (pomocniczego i glownego)
*/
void ZastapNumerami(const std::string& Publikacja_file, const std::string& Wyjsciowy_file, SubNode*& subroot, MainNode*& root);
/*
Funkcja wpisujaca do pliku wyjsciowego bibliografie
Wyjsciowy_file - nazwa pliku wyjsciowego
subroot - korzen drzewa pomocniczego
*/
void WypiszBibliografie(const std::string& Wyjsciowy_file, SubNode*& subroot);

#endif