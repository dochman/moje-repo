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


//ZAD2, struktura zwiazana z kolami samochodowymi

enum class type { letnia, zimowa };

struct Wheel
{
	type Kolo;
};

struct Car
{
	Wheel Kola[4];
};


bool CheckCar(Car bryka)
{
	type sprawdz = bryka.Kola[0].Kolo;
	for (int i = 1; i < 4; i++)
	{
		if (bryka.Kola[i].Kolo != sprawdz)
		{
			return false;
		}

		else if (bryka.Kola[i].Kolo == sprawdz)
		{
			return true;
		}
	}
}

void SetType(Car &bryka, type rodzaj_ogumienia)
{
	for (int i = 0; i < 4; i++)
	{
		bryka.Kola[i].Kolo = rodzaj_ogumienia;
	}
}


//ZAD3, struktura zwiazana z datami

struct Date
{
	int dzien;
	int miesiac;
	int rok;
};

bool przestepny(Date data)
{
	if (((data.rok % 4 == 0) && (data.rok % 100 != 0)) || (data.rok % 400 == 0)) return true;
	else return false;
}

bool dataprawidlowa(Date data)
{
	int dnimiesiac[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (przestepny(data)) dnimiesiac[1] += 1;

	if (data.miesiac <= 0 || data.miesiac > 12) return false;
	else if (data.dzien >= 31 || data.dzien <= 0) return false;
	else if (data.dzien > dnimiesiac[data.miesiac - 1]) return false;
	else if (data.rok == 0) return false;
	else return true;
}

bool porownaniedat(Date data1, Date data2)
{
	if (data1.rok == data2.rok && data1.miesiac == data2.miesiac && data1.dzien == data2.dzien) return 0;
	else if (data1.rok > data2.rok) return true;
	else if (data2.rok > data1.rok) return false;
	else if (data1.miesiac > data2.miesiac) return true;
	else if (data2.miesiac > data1.miesiac) return false;
	else if (data1.dzien > data2.dzien) return true;
	else if (data2.dzien > data2.dzien) return false;
}

int main()
{
	cout << "////////// ZAD1 //////////" << endl;
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

	/////////////////////////////////////////////////////////////////////
	cout << endl;
	cout << "////////// ZAD2 //////////" << endl;
	cout << "Czas na sprawdzenie jakie kola masz w samochodzie!" << endl;
	Car bryka;
	bryka.Kola[0].Kolo = type::letnia;
	bryka.Kola[1].Kolo = type::letnia;
	bryka.Kola[2].Kolo = type::letnia;
	bryka.Kola[3].Kolo = type::letnia;
	if (CheckCar(bryka)) cout << "Wszystkie kola sa tego samego typu" << endl;
	else cout << "Ktores z kol jest innego typu" << endl;
	
	cout << "Chcesz zmienic opony? Podaj typ a zrobie to za ciebie! (0 - zimowe, 1 - letnie)" << endl;
	char wybor;
	cin >> wybor;
	
	switch (wybor)
	{
	case '0': { 
				SetType(bryka, type::zimowa);
				break;
              }
	case '1': {
				SetType(bryka, type::letnia);
				break;
			  }
	default: cout << "No cos nie wyszlo" << endl;;
	}

	bool czy;

	for (int i = 0; i < 4; i++)
	{
		if (bryka.Kola[i].Kolo == type::letnia) czy = true;
		else if (bryka.Kola[i].Kolo == type::zimowa) czy = false;
	}

	if (czy) cout << "Wszystkie kola zostaly zmienione na letnie" << endl;
	if (!czy) cout << "Wszystkie kola zostaly zmienione na zimowe" << endl;

	///////////////////////////////////////////////////////////////////////////////
	cout << endl;
	cout << "////////// ZAD2 //////////" << endl;
	Date data1;
	data1.dzien = 28;
	data1.miesiac = 2;
	data1.rok = 2100;

	Date data2;
	data2.dzien = 20;
	data2.miesiac = 2;
	data2.rok = 2100;

	cout << "Data1: " << data1.dzien << "." << data1.miesiac << "." << data1.rok << endl;
	cout << "Data2: " << data2.dzien << "." << data2.miesiac << "." << data2.rok << endl;
	if (przestepny(data1)) cout << "Rok daty1 jest przestepny" << endl;
	else cout << "Rok daty1 nie jest przestepny" << endl;
	if (dataprawidlowa(data1)) cout << "Data1 jest prawidlowa" << endl;
	else cout << "Data1 jest nieprawidlowa" << endl;

	if (porownaniedat(data1, data2) == 0) cout << "Daty sa identyczne" << endl;
	else if (porownaniedat(data1, data2)) cout << "Data pierwsza jest wczesniejsza niz druga" << endl;
	else if (!porownaniedat(data1, data2)) cout << "Data pierwsza jest pozniejsza niz druga" << endl;



	return 0;
}