#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char**argv)
{
	double a1, b1, c1, a2, b2, c2;
	double x, y, w, wx, wy;

	cout << "Program rozwiazujacy uklad rownan z dwoma niewiadomymi x i y\n";
	cout << "Wprowadz wspolczynniki a1,b1,c1 pierwszego rownania\n";
	cin >> a1;
	cin >> b1;
	cin >> c1;
	cout << "Wprowadz wspolczynniki a2,b2,c2 drugiego rownania\n";
	cin >> a2;
	cin >> b2;
	cin >> c2;

	w = a1*b2 - b1*a2;
	wx = c1*b2 - b1*c2;
	wy = a1*c2 - c1*a2;

	if (w != 0)
	{
		cout << "Uklad ma jedno rozwiazanie: \n";
		x = wx / w;
		y = wy / w;
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
	}

	if ((w == 0) && (wx == 0) && (wy == 0))
	{
		cout << "Uklad rownan ma nieskonczenie wiele rozwiazan" << endl;
	}

	if ((w == 0) && ((wx != 0) || (wy != 0)))
	{
		cout << "Sprzecznosc" << endl;
	}

	return 0;
}