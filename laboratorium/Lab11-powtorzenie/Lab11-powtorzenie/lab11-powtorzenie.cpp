#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct drzewo
{
	int val;
	int licznik;
	drzewo *left, *right;
};

bool parse_parameters(int argc, char**argv, string& input_file_name, string& output_file_name)
{
	input_file_name = "";
	output_file_name = "";
	const string input_switch = "-i";
	const string output_switch = "-o";

	for (int i = 1; i < argc - 1; ++i)
	{
		if (argv[i] == input_switch)
		{
			input_file_name = argv[++i];
		}
		else if (argv[i] == output_switch)
		{
			output_file_name = argv[++i];
		}
	}

	if (input_file_name == "" || output_file_name == "")
	{
		return false;
	}
	return true;
}
void help()
{
	//tutaj tylko wyswietlenie jak uzywac programu
}


void AddRecursive(drzewo*&root, int val)   //rekurencyjne dodawanie elementow do drzewa
{
	if (!root)
		root = new drzewo{ val,1,nullptr,nullptr };
	else if (val < root->val) AddRecursive(root->left, val);
	else if (val > root->val) AddRecursive(root->right, val);
	else if (val == root->val) root->licznik++;
}


int ilerazy(drzewo* root, int& max);
void szukajmax(const string& input_file_name, const string& output_file_name)
{
	int dane;
	int max = 0;

	ifstream plikwe(input_file_name);
	if (!plikwe)
	{
		cout << "Nie mozna otworzyc pliku: " << input_file_name << "\n";
		return;
	}

	ofstream plikwy(output_file_name);
	if (!plikwy)
	{
		cout << "Nie mozna otworzyc pliku: " << output_file_name << "\n";
		return;
	}


	drzewo* root = nullptr;

	while (plikwe >> dane)
	{
		AddRecursive(root, dane);
	}

	max = ilerazy(root,max);
	plikwy <<max;


	plikwe.close();
	plikwy.close();

	return;
}

int ilerazy(drzewo* root, int& max) 
{
	//int max = -32000;
	if (!root) return 0;
	
	if (root->licznik > max) max = root->licznik;
	
	ilerazy(root->left, max);
	ilerazy(root->right, max);

	return max;
}

int main(int argc, char**argv)
{
	string input_file_name, output_file_name;
	if (!parse_parameters(argc, argv, input_file_name, output_file_name))
	{
		cout << "Bledne parametry:\n";
		help();
		return 1;
	}
	szukajmax(input_file_name, output_file_name);

	


}