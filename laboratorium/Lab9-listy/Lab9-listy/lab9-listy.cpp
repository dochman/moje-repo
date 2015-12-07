#include <iostream>


using namespace std;


struct ListElem
{
	int val;
	ListElem* next;
};

struct List        //w wielu miejscach nie trzeba gwiazdki
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


/*

NA WSKAZNIKACH

//AddFront(head, 5); <- funkcja dodawania na poczatek listy
void AddFront(ListElem* &glowa, int wartosc)
{
	glowa = new ListElem{ wartosc, glowa};
}

void wyswietl(ListElem* &glowa)
{
	ListElem* nast;
	nast = glowa;
	//przegladanie listy
	while (nast != nullptr)
	{
		cout << nast->val << endl;
		nast = nast->next;
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
*/

int main()
{
	//ListElem* head = nullptr;
	List lista{ nullptr };

	//head = new ListElem{ 5,nullptr };  //dodawanie pokolei
	//head->next = new ListElem{ 6,nullptr };
	//head->next->next = new ListElem{ 7,nullptr };

	/*
	na wskaznikach

	AddFront(head, 5);
	AddFront(head, 6);
	AddFront(head, 7);

	wyswietl(head);
	usun(head);
	*/

	AddFront(lista, 5);
	AddFront(lista, 6);
	AddFront(lista, 7);

	wyswietl(lista);
	usun(lista);


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