#include "dodawanie.h"

int Add(int& a, int b)                         //a,b parametry formalne
{
	a += b;
	return a;   //return a gdy a+=b to wynik ten sam / return a+b;
}