#include <iostream>

using namespace std;
using uint32 = unsigned int;



char get_bit(uint32 liczba, char pos)  //zwraca wartosc bitu na pozycji pos w liczba
{
	return liczba >> pos & 1;
}

void binary(uint32 liczba)
{
	for (int i = 31; i >= 0; --i)
		cout << (int)get_bit(liczba, i);
	cout << endl;
}


uint32 set_bit(uint32 liczba, char pos)
{
	return liczba | 1<<pos;
}

uint32 reset_bit(uint32 liczba, char pos)
{
	return liczba & ~1<<pos;
}

/* //1000 sie wyswietli bo najmniej znaczacy bajt jest na poczatku zawsze (myslalem ze 0001)
a & 255   wyciagnie najmniej znaczacy bit ale tak jak sie spodziewamy czyli 0001

uint32 a=1;
char* ptr = (char*)&a;
for (int i=0; i<4; ++i)
cout<<(int)ptr[i];
*/



int main()
{
	int a = 3;
	cout << (int)get_bit(a, 0) << endl;
	binary(a);
	binary(set_bit(a, 5));
	binary(reset_bit(a, 0));
}