
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct MainNode
{
	string Etykieta;
	string Imie;
	string Nazwisko;
	//string Autor;
	string Tytul;

	MainNode *left, *right;
};

struct SubNode
{
	string Etykieta;
	string Imie;
	string Nazwisko;
	string Tytul;
	int Numer;

	SubNode *left, *right;
};


bool parse_parameters(int argc, char**argv, string& input_file_name, string& input_file_name_2,string& output_file_name)
{
	input_file_name = "";
	input_file_name_2 = "";
	output_file_name = "";
	const string input_switch = "-t";
	const string input_switch_2 = "-b";
	const string output_switch = "-o";

	for (int i = 1; i < argc - 1; ++i)
	{
		if (argv[i] == input_switch)
		{
			input_file_name = argv[++i];
		}
		else if (argv[i] == input_switch_2)
		{
			input_file_name_2 = argv[++i];
		}
		else if (argv[i] == output_switch)
		{
			output_file_name = argv[++i];
		}
	}

	if (input_file_name == "" || input_file_name_2 == "" || output_file_name == "")
	{
		return false;
	}
	return true;
}


void help()
{
	cout << "Program Bibliografia" << endl;
	cout << "Aby poprawnie uzywac programu nalezy przy wywolywaniu podac nazwe programu oraz trzy glowne parametry:" << endl;
	cout << "-t <nazwa pliku wejsciowego bedacego publikacja z odnosnikami do literatury>" << endl;
	cout << "-b <nazwa pliku wejsciowego zawierajacego opisy bibliograficzne utworow>" << endl;
	cout << "-o <nazwa pliku wyjsciowego>" << endl;
	cout << "W pliku wejsciowym pojawi sie przerobiona publikacja, gdzie etykiety zastapione zostana odpowiednimi numerami z bibliografii a nizej bedzie wyswietlona bibliografia" << endl;
}


void MainAddRecursive(MainNode*&root, string Etykieta, string Imie, string Nazwisko,string Tytul)
{
	if (!root)
		root = new MainNode{ Etykieta, Imie, Nazwisko, Tytul,nullptr,nullptr };
	else if (Etykieta < root->Etykieta) MainAddRecursive(root->left, Etykieta, Imie, Nazwisko, Tytul);
	else MainAddRecursive(root->right, Etykieta, Imie, Nazwisko, Tytul);
}

void SubAddRecursive(SubNode*&subroot, string Etykieta, string Imie, string Nazwisko, string Tytul, int Numer)
{
	if (!subroot)
		subroot = new SubNode{ Etykieta, Imie, Nazwisko, Tytul, 0, nullptr, nullptr};
	else if (Nazwisko < subroot->Nazwisko) SubAddRecursive(subroot->left,Etykieta,Imie,Nazwisko,Tytul, Numer);
	else SubAddRecursive(subroot->right, Etykieta,Imie,Nazwisko,Tytul, Numer);
}

/*void DeleteMainTree(MainNode*&root) 
{
	if (!root) return;
	DeleteMainTree(root->left);  
	DeleteMainTree(root->right); 
	delete root;         
	root = nullptr;   
}*/


void NadajNumery(SubNode* subroot)
{
	if (!subroot) return;
	NadajNumery(subroot->left);
	subroot->Numer++;
	NadajNumery(subroot->right);
	return;
}

void Przejdz(MainNode* root)
{
	if (!root) return;
	Przejdz(root->left);
	Przejdz(root->right);

	return;
}

void CzytajPliki(const string& input_file_name, const string& input_file_name_2, const string& output_file_name)
{
	string Etykieta;
	string Imie;
	string Nazwisko;
	string Tytul;
	string Autor;
	string zbedna_linia;
	string wyraz;
	int dl;

	ifstream OpisyBibliograficzne(input_file_name_2);
	if (!OpisyBibliograficzne)
	{
		cout << "Nie mozna otworzyc pliku: " << input_file_name_2 << "\n";
		return;
	}

	ifstream Publikacja(input_file_name);
	if (!Publikacja)
	{
		cout << "Nie mozna otworzyc pliku: " << input_file_name << "\n";
		return;
	}


	MainNode* root = nullptr;
	SubNode* subroot = nullptr;

	while (!OpisyBibliograficzne.eof())
	{
		getline(OpisyBibliograficzne, Etykieta);
		getline(OpisyBibliograficzne, Autor);
		getline(OpisyBibliograficzne, Tytul);
		getline(OpisyBibliograficzne, zbedna_linia);

		dl = Autor.length();
		for (int i = 0; i < dl; i++)
		{
			if (Autor[i] == ' ')
			{
				Imie = Autor.substr(0, i);
				Nazwisko = Autor.substr(i+1, dl);
				break;
			}
		}
		MainAddRecursive(root, Etykieta, Imie, Nazwisko,Tytul);
	}

	while (Publikacja >> wyraz)
	{
		if (wyraz[0] == '\\' && wyraz == "\\cite{" + root->Etykieta + "}")
		{
				SubAddRecursive(subroot, root->Etykieta, root->Imie, root->Nazwisko, root->Tytul, 0);
		}
	}
	
	OpisyBibliograficzne.close();
	Publikacja.close();
	return;
}


int main(int argc, char**argv)
{
	string input_file_name, input_file_name_2, output_file_name;
	if (!parse_parameters(argc, argv, input_file_name, input_file_name_2, output_file_name))
	{
		cout << "Podane zostaly bledne parametry, zastosuj sie do pomocy wyswietlonej ponizej:\n";
		help();
		return 1;
	}

	CzytajPliki(input_file_name, input_file_name_2, output_file_name);

	//DeleteMainTree(root);

}