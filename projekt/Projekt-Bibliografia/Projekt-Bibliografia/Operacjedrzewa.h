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
Funkcja tworz�ca elementy drzewa g�ownego
root - korze�
Etykieta, Imie, Nazwisko, Tytul - pola danych ka�dego elementu drzewa
*/
void DodajGlowneDrzewo(MainNode*&root, std::string Etykieta, std::string Imie, std::string Nazwisko, std::string Tytul);
/*
Funkcja tworz�ca elementy drzewa pomocniczego
subroot - korze�
Etykieta, Imie, Nazwisko, Tytul, Numer - pola danych ka�dego elementu drzewa
*/
void DodajPoddrzewo(SubNode*&subroot, std::string Etykieta, std::string Imie, std::string Nazwisko, std::string Tytul, int Numer);
/*
Funkcja wyszukuj�ca w drzewie g��wnym znalezionej w pliku etykiety
wsk - wskaznik na wezly drzewa (przesuwany po to zeby byc zwroconym jako ten element)
szukana - szukana etykieta
*/
MainNode* SzukajWDrzewie(MainNode*& wsk, std::string szukana);
/*
Funkcja wyszukuj�ca w drzewie pomocniczym odpowiedniego nazwiska powi�zanego z etykiet� pierwszego drzewa
wsk - wskaznik na wezly drzewa (przesuwany po to zeby byc zwroconym jako ten element)
szukana - szukane nazwisko
*/
SubNode* SzukajWPoddrzewie(SubNode*& wsk, std::string szukana);
/*
Funkcja rekurencyjnie usuwaj�ca g��wne drzewo
root - wska�nik na korze�
*/
void UsunGlowneDrzewo(MainNode*&root);
/*
Funkcja rekurencyjnie usuwaj�ca pomocnicze drzewo
subroot - wska�nik na korze�
*/
void UsunPoddrzewo(SubNode*&subroot);
/*
Funkcja nadaj�ca numery inorder w�z�om drzewa pomocniczego
licznik - kolejno inkrementowany licznik wpisywany w pola numer struktury
subroot - wska�nik na korze�
*/
void NadajNumery(SubNode*&subroot, int& licznik);


#endif