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
Funkcja, kt�ra wypisuje informacje potrzebne w bibliografii na ko�cu pliku wyj�ciowego
subroot - korze� pomocniczego drzewa
Wyjsciowy_file - nazwa pliku wyjsciowego
*/
void WypiszPoddrzewo(SubNode* subroot, const std::string & Wyjsciowy_file);
/*
Funkcja czytaj�ca z pliku o zadanej nazwie opisy bibliograficzne ksi��ek i tworz�ca z nimi drzewo g��wne
Opisy_bibligoraficzne_file - nazwa pliku wejsciowego zawierajacego te opisy
root - korze� drzewa g��wnego
*/
void CzytajOpisy(const std::string& Opisy_bibliograficzne_file, MainNode*& root);
/*
Funkcja sczytuj�ca tekst publikacji linia po linii z pliku
Publikacja_file - nazwa pliku wej�ciowego z tekstem
root - korze� drzewa
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