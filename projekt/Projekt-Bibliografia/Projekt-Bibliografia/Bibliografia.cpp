#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Parametry.h"
#include "Pomoc.h"
#include "Operacjepliki.h"
#include "Operacjedrzewa.h"

using namespace std;

int main(int argc, char**argv)
{
	string Publikacja_file, Opisy_bibliograficzne_file, Wyjsciowy_file;
	if (!Parsuj_parametry(argc, argv, Publikacja_file, Opisy_bibliograficzne_file, Wyjsciowy_file))
	{
		cout << "Podane zostaly bledne parametry, zastosuj sie do pomocy wyswietlonej ponizej:\n";
		Pomoc();
		return 1;
	}

	MainNode* root = nullptr;
	SubNode* subroot = nullptr;

	CzytajOpisy(Opisy_bibliograficzne_file, root);
	CzytajPublikacje(Publikacja_file, subroot, root);

	int licznik = 0;
	NadajNumery(subroot,licznik);


	ZastapNumerami(Publikacja_file, Wyjsciowy_file, subroot, root);
	WypiszBibliografie(Wyjsciowy_file, subroot);

	UsunGlowneDrzewo(root);
	UsunPoddrzewo(subroot);
}