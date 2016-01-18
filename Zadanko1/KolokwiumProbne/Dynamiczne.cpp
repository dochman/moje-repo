#include <fstream>
#include <sstream>
#include "Dynamiczne.h"
using namespace std;

/*
Proszę zaimplementować funkcje:

ListNode* Build(const std::string& file_name);
int FindDeepestTree(ListNode* head);
void FreeMem(ListNode*&head);

Celem funkcji Build jest odczytanie danych zawartych w pliku o nazwie file_name do dynamicznej struktury danych 
(listy jednokierunkowej, zawierającej drzewa binarne - patrz ListNode, TreeNode w pliku Dynamiczne.h). 
Każda linia w pliku reprezentuje pojedyńczy element listy (jego numer oraz zawarte tam drzewo) i ma następujący format
<numer węzła listy> <element drzewa> [<element drzewa>...]
Dodawanie elementów do listy powinno zapewnić zachowanie rosnącego porządku elementów względem numerów węzła.
W każdym węźle drzewa elementy mniejsze powinny zostać umieszczone po lewej stronie, a większe - po prawej.
Przykładowo dla pliku o zawartości:

5 10 5 15 23
1 5
7 10 11 12 13

Powinna zostać utworzona następująca struktura:

         +---+       +---+      +---+
         | 1 |-----> | 5 |----->| 7 |
         +---+       +---+      +---+
           |            |         |
           |            |         |
           V            V         V
         +---+        +----+   +----+
         | 5 |        | 10 |   | 10 |
         +---+        +----+   +----+
                      /    \        \
                     /      \        \
                   +---+   +----+    +----+
                   | 5 |   | 15 |    | 11 |
                   +---+   +----+    +----+
                                \        \
                                 \        \
                               +----+    +----+
                               | 23 |    | 12 |
                               +----+    +----+
                                              \
                                               \
                                              +----+
                                              | 13 |
                                              +----+

Celem funkcji FindDeepestTree jest znalezienie węzeła listy, który zawiera najwyższe drzewo (wysokość drzewa to długość najdłuższej ścieżki od 
korzenia do liścia wyrażona w liczbie krawędzi, wysokość drzewa pustego to -1) i zwrócenie numeru tego węzła.
Dla powyższego przykładu byłoby to 7


Celem funkcji FreeMem jest zwolnienie zaalokowanej pamięci (po wykonaniu tej funkcji wskaźnik na głowę powinien wskazywać nullptr)

UWAGI: 
 * Kod należy podzielić na pomocnicze funkcje
 * Funkcja dodająca element do drzewa nie powinna być rekurencyjna - rekurencji można użyć jedynie do ustalenia wysokości drzewa i zwolnienia zaalokowanej pamięci
 * Można założyć że dane w pliku sa prawidłowe
 * Mozna założyć że numery węzłów listy są unikalne
 * dla każdego drzewa można założyć że numery węzłów są unikalne

Podpowiedź:
 Aby ze zmiennej typu string uzyskać wszystkie liczby oddzielone białymi znakami można użyć następującej konstrukcji:
 #include <sstream>
 ...
 //gdzieś w bloku kodu
 string liczby = "5 123  3  32     2";
 istringstream str(liczby);
 int liczba;
 while(str>>liczba)
	cout << liczba << " ";
*/

//tą funkcję należy napisać
ListNode* Build(const std::string& file_name)
{
	return nullptr;
}

//tą funkcję należy napisać
int FindDeepestTree(ListNode* head)
{
	return 0;
}

//tą funkcję należy napisać
void FreeMem(ListNode*&head)
{

}