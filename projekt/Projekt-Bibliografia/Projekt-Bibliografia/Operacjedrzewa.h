//#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
//#include "Operacjepliki.h"

#ifndef _OPERACJEDRZEWA_H
#define	_OPERACJEDRZEWA_H

struct MainNode;
struct SubNode;

/*
Funkcja tworz¹ca elementy drzewa g³ownego
root - korzeñ
Etykieta, Imie, Nazwisko, Tytul - pola danych ka¿dego elementu drzewa
*/
void DodajGlowneDrzewo(MainNode*&root, std::string Etykieta, std::string Imie, std::string Nazwisko, std::string Tytul);
/*
Funkcja tworz¹ca elementy drzewa pomocniczego
subroot - korzeñ
Etykieta, Imie, Nazwisko, Tytul, Numer - pola danych ka¿dego elementu drzewa
*/
void DodajPoddrzewo(SubNode*&subroot, std::string Etykieta, std::string Imie, std::string Nazwisko, std::string Tytul, int Numer);
/*
Funkcja wyszukuj¹ca w drzewie g³ównym znalezionej w pliku etykiety
wsk - wskaznik na wezly drzewa (przesuwany po to zeby byc zwroconym jako ten element)
szukana - szukana etykieta
*/
MainNode* SzukajWDrzewie(MainNode*& wsk, std::string szukana);
/*
Funkcja wyszukuj¹ca w drzewie pomocniczym odpowiedniego nazwiska powi¹zanego z etykiet¹ pierwszego drzewa
wsk - wskaznik na wezly drzewa (przesuwany po to zeby byc zwroconym jako ten element)
szukana - szukane nazwisko
*/
SubNode* SzukajWPoddrzewie(SubNode*& wsk, std::string szukana);
/*
Funkcja rekurencyjnie usuwaj¹ca g³ówne drzewo
root - wskaŸnik na korzeñ
*/
void UsunGlowneDrzewo(MainNode*&root);
/*
Funkcja rekurencyjnie usuwaj¹ca pomocnicze drzewo
subroot - wskaŸnik na korzeñ
*/
void UsunPoddrzewo(SubNode*&subroot);
/*
Funkcja nadaj¹ca numery inorder wêz³om drzewa pomocniczego
licznik - kolejno inkrementowany licznik wpisywany w pola numer struktury
subroot - wskaŸnik na korzeñ
*/
void NadajNumery(SubNode*&subroot, int& licznik);


#endif