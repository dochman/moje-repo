#include <iostream>
#include "catch.hpp"

#include "Dynamiczne.h"
#include "Algorytmiczne.h"
#include <set>

using namespace std;
//helper 
bool is_sorted_and_non_empty(ListNode* head)
{
	if (!head)
		return false;
	int prev = head->val;
	head = head->next;
	while (head)
	{
		if (head->val < prev)
			return false;
		prev = head->val;
		head = head->next;
	}
	return true;
}


//Test cases
TEST_CASE("Testy dla zadania dynamicznego")
{
	auto head = Build("dyn1.txt");
	{ INFO("Lista nie jest posortowana lub jest pusta"); CHECK(is_sorted_and_non_empty(head)); }
	{ INFO("Bledny wynik znajdywania nawyzszego drzewa");	CHECK(FindDeepestTree(head) == 7); }
	FreeMem(head);
	{ INFO("Wycieki pamieci"); CHECK(MemHelper::GetAllocCount() == 0); }
	CHECK(head == nullptr);
	

	head = Build("dyn2.txt");
	{ INFO("Lista nie jest posortowana lub jest pusta"); CHECK(is_sorted_and_non_empty(head)); }
	{ INFO("Bledny wynik znajdywania nawyzszego drzewa"); CHECK(FindDeepestTree(head) == 34); }
	FreeMem(head);
	{ INFO("Wycieki pamieci"); CHECK(MemHelper::GetAllocCount() == 0); }
	CHECK(head == nullptr);
}


bool arr_comp(char t1[N][M], char t2[N][M])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			if (t1[i][j] != t2[i][j])
				return false;
	}
	return true;
}

TEST_CASE("Testy dla zadania algorytmicznego")
{
	char in[N][M] = { { '+', '-', '-', '+' }, { '|', 'a', 'b', '|' }, { '+', '-', '-', '+' } };
	char out[N][M];
	Move(in, out, N*12, M*15);
	{INFO("Bledny wynik dla x = " << N * 12 << " y = " << M * 12); CHECK(arr_comp(in, out)); }
	
	Move(in, out, 0, -1);
	char pattern[N][M] = { { '|', 'a', 'b', '|' }, { '+', '-', '-', '+' }, { '+', '-', '-', '+' } };
	{ INFO("Bledny wynik dla x = 0 y = -1"); CHECK(arr_comp(pattern, out)); }


	Move(in, out, 0, 1);
	char pattern2[N][M] = {{ '+', '-', '-', '+' },{ '+', '-', '-', '+' },{ '|', 'a', 'b', '|' } };
	{ INFO("Bledny wynik dla x = 0 y = 1"); CHECK(arr_comp(pattern2, out)); }

	Move(in, out, 1, 0);
	Move(in, pattern, -127, 0);
	{ INFO("przesuniecie (1,0) powinno dac ten sam wynik co (-127,0)"); CHECK(arr_comp(pattern, out)); }

	Move(in, out, -3, 2);
	Move(in, pattern, -127, -12454);
	{ INFO("przesuniecie (-3,2) powinno dac ten sam wynik co (-127,12454)"); CHECK(arr_comp(pattern, out)); }
}


//TEST_CASE("tmp")
//{
//	char tab[N][M] = {  {'/','*','*','\\'},
//						{'|',' ',' ','|'},
//						{'\\','_','_','/'} };
//	char o[N][M];
//	Print(tab);
//	Move(tab, o, 1, 0);
//	Print(o);
//	Move(tab, o, 0, -1);
//	Print(o);
//	Move(tab, o, 1, -1);
//	Print(o);
//}
