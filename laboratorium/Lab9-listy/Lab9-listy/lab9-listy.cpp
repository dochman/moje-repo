#include <iostream>


using namespace std;


struct ListElem
{
	int val;
	ListElem* next;
};

/*struct List        //w wielu miejscach nie trzeba gwiazdki
{
	ListElem* head;
	//int liczba_elementow;
};

//NA STRUKTURZE LIST

void AddFront(List &glowa, int wartosc)
{
	glowa.head = new ListElem{ wartosc, glowa.head};
}

void wyswietl(List &glowa)
{
	ListElem* nast;
	nast = glowa.head;
	//przegladanie listy
	while (nast != nullptr)
	{
		cout << nast->val << endl;
		nast = nast->next;
	}
}

void usun(List &glowa)
{
	//zwalnianie pamieci
	ListElem* tmp;
	while (glowa.head != nullptr)
	{
		tmp = glowa.head;
		glowa.head = tmp->next;
		delete tmp;
	}
}
*/



//NA WSKAZNIKACH

//AddFront(head, 5); <- funkcja dodawania na poczatek listy
void AddFront(ListElem* &glowa, int wartosc)
{
	glowa = new ListElem{ wartosc, glowa};
}

void AddBack(ListElem* &glowa, int wartosc)
{
	ListElem* nast;
	ListElem* ogon;

	if (glowa == nullptr)
	{
		glowa = new ListElem{ wartosc, nullptr };
	}


	ListElem* tmp = glowa;
	while (tmp -> next)  //dopoki istnieje nastepny element to idz dalej
	{
		tmp = tmp->next; 
	}
	tmp->next = new ListElem{ wartosc, nullptr }; //stworz nowy element na ktory wskazuje tmp, i ten nastepny bedzie wskazywal na null
}

void wyswietl(ListElem* &glowa)
{
	ListElem* nast;
	nast = glowa;
	//przegladanie listy
	while (nast != nullptr)
	{
		cout << nast->val << " ";
		nast = nast->next;
	}
	cout << endl;
}

void wyswietlodtylu(ListElem* &glowa)
{
	if (glowa!=nullptr)
	{
		wyswietlodtylu(glowa->next); //sprawdzam czy head jest nullem, jesli nie to ide do nastepnego elementu i zawezam obszar, potem znowu sprawdzam i tworze kolejny mniejszy obszar i jak juz jest nullem to wypisuje wartosc
		cout << glowa->val << " ";		//do head wpisuje nastepne pole i jak dochodze do null to wyswietlam
	}
	
}

void usun(ListElem* &glowa)
{
	//zwalnianie pamieci
	ListElem* tmp;
	while (glowa != nullptr)
	{
		tmp = glowa;
		glowa = tmp->next;
		delete tmp;
	}
}

bool szukaj(ListElem* &glowa, int szukana)
{
	ListElem* nast;
	nast = glowa;
	while (nast != nullptr)
	{
		if (nast->val == szukana) return true;
			nast = nast->next;
	}
	return false;
}

int usunowartosci(ListElem* &glowa, int wartosc)
{
	ListElem* nast;
	ListElem* tmp;
	nast = glowa;
	tmp = glowa->next;

	int licznik = 0;

	while (nast != nullptr)
	{
		if (nast->val == wartosc)
		{
			nast = tmp;
			tmp = tmp->next;


		}
	}
	return licznik;
}

//nastepne zadanie, napisac funkcje ktora dodaje do listy elementy w ten sposob ze sa one posortowane, na poczatku lista jest pusta, wiec tylko ta funkcja jest uzywana do dodawania

int main()
{
	ListElem* head = nullptr;
	//List lista{ nullptr };

	//head = new ListElem{ 5,nullptr };  //dodawanie pokolei
	//head->next = new ListElem{ 6,nullptr };
	//head->next->next = new ListElem{ 7,nullptr };

	
	//na wskaznikach

	//for (int i = 0; i < 500;i++)    //bedzie przepelnienie stosu przy wyswietlaniu bo coraz wiecej elementow odkladamy na stos i wkoncu sie zapelni
	//{
	//	AddFront(head, i);
	//}

	AddFront(head, 1);
	AddFront(head, 2);
	AddFront(head, 3);
	AddBack(head, 1);

	wyswietl(head);
	wyswietlodtylu(head);

	cout << endl;
	if (szukaj(head, 2)) cout << "Jest szukany element" << endl;
	else cout << "Nie ma szukanego elementu" << endl;

	usunowartosci(head,2);
	usun(head);
	
	//na strukturze Lists
	/*AddFront(lista, 5);
	AddFront(lista, 6);
	AddFront(lista, 7);

	wyswietl(lista);
	usun(lista);*/


	/* notatki
	/////////////zadziala ale stracimy glowe
	while (head)
	{
		cout<<head->val<<" ";
		head=head=head->next;
	}

	////////////tak lepiej bo nie tracimy glowy, wyswietlanie
	auto tmp=head;
	while(tmp)
	{
		cout<<tmp->val<<" ";
		tmp=tmp->next;
	}

	////////////zwalnianie pamieci
	auto do_usuniecia=head;
	while(head)
	{
		do_usuniecia=head;
		head=head->next;
		delete do_usuniecia;
	}
	*/
	return 0;
}