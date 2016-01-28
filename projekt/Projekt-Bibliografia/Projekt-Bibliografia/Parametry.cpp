#include <string>
#include "Parametry.h"

using namespace std;

bool Parsuj_parametry(int argc, char**argv, string& Publikacja_file, string& Opisy_bibliograficzne_file, string& Wyjsciowy_file)
{
	Publikacja_file = "";
	Opisy_bibliograficzne_file = "";
	Wyjsciowy_file = "";
	const string Publikacja_switch = "-t";
	const string Opisy_switch = "-b";
	const string Wyjsciowy_switch = "-o";

	for (int i = 1; i < argc - 1; ++i)
	{
		if (argv[i] == Publikacja_switch)
		{
			Publikacja_file = argv[++i];
		}
		else if (argv[i] == Opisy_switch)
		{
			Opisy_bibliograficzne_file = argv[++i];
		}
		else if (argv[i] == Wyjsciowy_switch)
		{
			Wyjsciowy_file = argv[++i];
		}
	}

	if (Publikacja_file == "" || Opisy_bibliograficzne_file == "" || Wyjsciowy_file == "")
	{
		return false;
	}
	return true;
}