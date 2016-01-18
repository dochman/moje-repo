#include <iostream>
#include <fstream>
#include <string>

using namespace std;

	
	//NOTATKI

	//operator bitowy |
	//ofstream(test.txt);// odpalic program ponownie to wtedy wyswietli sie to samo, zeby dopisac to ofstream(test.txt, ios::app | ios::out)
						//zeby byl na dysku D to sciezka bezwzgledna "D:\\text.txt" \\ bo \ jest stosowany do specjalnych znakow np \t (tabulator)
	/*if (!a.is_open())
	{
		cout << "nie mozna otworzyc pliku" << endl;
		exit(1);
	}
	a << "siema swiecie\n";*/

	/*ofstream a;
	a.open("test.txt", ios::app);*/

	/*const string file_name = "test.txt";
	ofstream a(file_name);
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (!b)
	{
		cout << "Cannot open" << file_name;
		exit(1);
	}


		for (auto e : tab)
		{
			a << e<<" ";
		}
	a.close();



	ifstream b(file_name);

	if (!b)
	{
		cout << "Cannot open" << file_name;
		exit(1);
	}

	int tab2[5];
	fot(int i = 0; i < 5;++i)
		b >> tab2[i]; //trzeba przy zapisie rozdzielic jakos liczby bo inaczej strumien dziala do bialego znaku i moze wypisac syf

	int aa = 5;
	*/

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*int main()
	{
		ifstream f("test.txt");
		
		if (!f)
		{
			cout << "Cannot open" << file_name;
			exit(1);
		}

		string slowo;
		while (f >> slowo)        //gdy damy (getline(f,slowo)) to odczyta cala linie
		{
			cout << slowo << " ";  //wyswietli wszystko z pliku
		}
	}*/

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//plik binarny nie jest plikiem tekstowym, przechowuje sie w nich mniej wiecej to co jest w pamieci, pracuje sie z nimi inaczej
	/*int main()
	{
	ifstream f("test.txt", ios::binary);

	if (!f)
	{
		cout << "Cannot open" << file_name;
		exit(1);
	}

	char tab[100]; 
	f.read(tab, 100); //odczytane 100 bajtow z tego pliku, odczytanie pliku binarnego
	f.write(tab, 100); //wpisanie 100 bajtow do pliku binarnego
	*/

	//mozna skakac po pliku, wskaznik, int pos=f.tellg();   <- w ktorym miejscu jestem czyli ile bajtow od poczatku
	//f.seekg(pos, ios::cur);    cur-current- aktualna pozycja, od aktualnej przesun sie o tyle  g-odczyt z pliku, p- zapis do pliku
	//dla ofstream pos=f.tellp() f.seekp()    

	//KONIEC NOTATEK


//ZAD1, przyjecie nazwy pliku i wyswietlenie rozmiaru w bajtach
unsigned long long GetFileSize(const string& file_name)
{
	ifstream plik(file_name, ios::binary);
	if (!plik)
	{
		cout << "Nie mozna otworzyc";
		exit(1);
	}

	plik.seekg(0, ios::end);    //przesuwam sie o 0 wzgledem konca, cur to ta pozycja aktualna
	int pos = plik.tellg();     //znajduje pozycje konca pliku i czytam ja do zmiennej pos
	plik.close();

	return pos;
}


//ZAD2, odczytanie liczb rzeczywistych z pliku input i wpisanie do pliku output ich sredniej
void calculate_statistics(const string& input_file_name, const string& output_file_name)
{
	ifstream odczyt(input_file_name);
	if (!odczyt)
	{
		cout << "Nie mozna otworzyc "<<input_file_name;
		exit(1);
	}

	double liczba;
	double suma = 0;
	double srednia = 0;
	int licznik = 0;

	while (odczyt >> liczba)
	{
		cout << liczba << " ";
		licznik += 1;
		suma += liczba;
		srednia = suma / licznik;
	}
	cout << endl;
	odczyt.close();

	ofstream zapis(output_file_name, ios::app);
	if (!zapis)
	{
		cout << "Nie mozna otworzyc "<<output_file_name;
		exit(1);
	}

	zapis << srednia<<" ";
	zapis.close();

	return;
}



//ZAD3a, kopiowanie zawartosci input_file do output_file w trybie tekstowym
void copy_text(const string& input_file_name1, const string& output_file_name1)
{
	ifstream odc1(input_file_name1);
	if (!odc1)
	{
		cout << "Nie mozna otworzyc " << input_file_name1;
		exit(1);
	}

	ofstream zap1(output_file_name1, ios::out);
	if (!zap1)
	{
		cout << "Nie mozna otworzyc " << output_file_name1;
		exit(1);
	}

	string linia;

	while (getline(odc1,linia))
	{
		zap1 << linia << endl;
	}

	odc1.close();
	zap1.close();
}

//ZAD3b, kopiowanie zawartosci input_file do output_file w trybie binarnym
void copy_binary(const string& input_file_name1, const string& output_file_name2)
{
	ifstream odc2(input_file_name1, ios::in | ios::binary);
	if (!odc2)
	{
		cout << "Nie mozna otworzyc " << input_file_name1;
		exit(1);
	}

	ofstream zap2(output_file_name2, ios::out | ios::binary);
	if (!zap2)
	{
		cout << "Nie mozna otworzyc " << output_file_name2;
		exit(1);
	}

	
	const int i = 150;
	
	char tab[i];
	odc2.read(tab, i);
	zap2.write(tab, i);

	odc2.close();
	zap2.close();
}


int main()
{
	const string file_name = "D:\\rozmiar.txt"; //sciezka do pliku na dysku D
	const string input_file_name = "D:\\lbrzeczywiste.txt";
	const string output_file_name = "D:\\srednia.txt";
	cout << "Plik rozmiar.txt ma rozmiar = " << GetFileSize(file_name) << endl;
	calculate_statistics(input_file_name, output_file_name);
	const string input_file_name1 = "D:\\zrodlo.txt";
	const string output_file_name1 = "D:\\kopiatekst.txt";
	copy_text(input_file_name1, output_file_name1);
	const string output_file_name2 = "D:\\kopiabinarna.txt";
	copy_binary(input_file_name1, output_file_name2);
}
