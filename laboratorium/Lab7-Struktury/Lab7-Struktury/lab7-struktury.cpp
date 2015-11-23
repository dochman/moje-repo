#include <iostream>
#include <string>

using namespace std;

/*struct Inna
{
	int a, b;
};

struct Person
{
	string Name;
	int Age;
	int oceny[10];
	Inna a;            //mozna tak uzywac 
	//Person brat;     //nie mozna bo caly czas moznaby cos dopisywac w nieskonczonosc, nie skompiluje sie
};*/


	/*Person tab[10];
	Person Ala;
	Ala.Age = 24;      //mozna wpisywac osobno lub przy deklaracji // Person Ala={"Ala", 24}
	Ala.Name = "Ala";
	int tab[10];*/

	/*Person* person;   
	person->Name;*/			 //Przy wskaznikach jest strzalka zamiast kropki

	/*Person person1 = { "Ala", 24 };
	Person p2 = person1;*/			// przepisze wszystkie elementy do nowej zmiennej
	//if (p2 < person1) if (p2 == person1) if (p2 != person1)  //struktur nie mozna porownywac w zaden sposob!!!

/*enum class OpcjeGry { NowaGra = 2, Zapisz = 6};   //typy wyliczeniowe, class to dodatek w nowym c++
												  //w nim nie mozna odwolywac sie globalnie

	int main()
{
	OpcjeGry opcja=OpcjeGry::NowaGra;
	switch (opcja)
	{
	case OpcjeGry::NowaGra:
		//
		break;
	case OpcjeGry::Zapisz:
		//
		break;
	}
}*/


//ZAD1, struktura reprezentujaca liczbe zespolona
struct Complex
{
	double Re;
	double Im;
};

void wypiszzesp(Complex liczba)
{
	cout << "z= " << liczba.Re << "+" << liczba.Im << "i" << endl;
}

Complex stworzzesp(double x, double y)
{
	Complex liczba;
	liczba.Re = x;
	liczba.Im = y;
	return liczba;
}

Complex dodajzesp(Complex z1, Complex z2)
{
	Complex zdod;
	
	zdod.Re = z1.Re + z2.Re;
	zdod.Im = z1.Im + z2.Im;
	return zdod;
}

int porownajzesp(Complex z1, Complex z2)
{
	double mod1, mod2;

	
	mod1 = sqrt(pow(z1.Re, 2) + pow(z1.Im, 2));
	mod2 = sqrt(pow(z2.Re, 2) + pow(z2.Im, 2));

	if (mod1 < mod2) return -1;
	else if (mod1 == mod2) return 0;
	else if (mod1 > mod2) return 1;
	
}

int main()
{
	Complex liczba = { 4,8 };
	wypiszzesp(liczba);

	cout << "Liczba zespolona po parametrach: ";
	wypiszzesp(stworzzesp(6, 5));

	Complex liczba2 = {3,4};
	cout << "Po dodaniu ponizszych liczb: " << endl;
	wypiszzesp(dodajzesp(liczba, liczba2));
	
	if (porownajzesp(liczba, liczba2) == 0) cout << "Liczby sa sobie rowne" << endl;
	else if (porownajzesp(liczba, liczba2) == 1) cout << "Liczba 1 jest wieksza od 2" << endl;
	else if (porownajzesp(liczba, liczba2) == -1) cout << "Liczba 2 jest wieksza od 1" << endl;

	return 0;
}