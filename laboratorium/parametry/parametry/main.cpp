#include <iostream>
#include <string>
#include <fstream>
using namespace std;

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

bool copy(const string& input_file_name, const  string& output_file_name)
{
	ifstream input(input_file_name);
	if (!input)
	{
		cout << "Nie mozna otworzyc pliku: " << input_file_name << "\n";
		return false;
	}

	ofstream output(output_file_name);
	if (!output)
	{
		cout << "Nie mozna otworzyc pliku: " << output_file_name << "\n";
		return false;
	}

	string line;
	while (getline(input, line))
		output << line << "\n";

	input.close();
	output.close();
	return true;
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


	if (!copy(input_file_name, output_file_name))
	{
		
	}


}