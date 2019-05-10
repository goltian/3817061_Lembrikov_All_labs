#include <iostream>
#include "../PolynomLib/Polynom.h"
using namespace std;

#define fortravis

#ifndef fortravis

int main()
{
	try
	{
		cout << "Lets create Polynom" << endl;
		cout << "Enter the number of variables" << endl;
		int n;
		cin >> n;
		TPolynom P(n);
		unsigned* p = new unsigned[n];
		for (int j = 0; j < n; j++)
			p[j] = 0;

		TMonom M(n, p, 0);
		int i = 1;
		while (i != 2) {
			cout << "Enter Monom" << endl;
			cin >> M;
			cout <<"M = "<< M << endl;
			P += M;
			cout << "P = " << P << endl;
			cout << "Again?" << endl << "1)yes" << endl << "2)exit" << endl;
			cin >> i;
		}
		return 0;
	}

	catch (MyException exp)
	{
		exp.Print();
	}
}
#endif

#ifdef fortravis
int main()
{
	TPolynom P1(5);
	TPolynom P2(5);
	unsigned* p1 = new unsigned[5];
	unsigned* p2 = new unsigned[5];
	unsigned* p3 = new unsigned[5];
	unsigned* p4 = new unsigned[5];
	for (int i = 0; i < 5; i++)
	{
		p1[i] = i;
		p2[i] = 5 - i;
		p3[i] = i + 1;
		p4[i] = 10 - i;
	}
	cout << "TMonom M1 (5, [0, 1, 2, 3, 4], 3" << endl;
	TMonom M1(5, p1, 3);
	cout << "TMonom M2 (5, [5, 4, 3, 2, 1], 6" << endl;
	TMonom M2(5, p2, 6);
	cout << "TMonom M3 (5, [1, 2, 3, 4, 5], 1" << endl;
	TMonom M3(5, p3, 1);
	cout << "TMonom M4 (5, [10, 9, 8, 7, 6], 7" << endl;
	TMonom M4(5, p4, 7);
	cout << "TMonom M5 (5, [0, 1, 2, 3, 4], 5" << endl;
	TMonom M5(5, p2, 5);
	cout << "TMonom M6 (5, [1, 2, 3, 4, 5], -12" << endl << endl;
	TMonom M6(5, p3, -12);
	cout << "P1 += M1" << endl;
	P1 += M1;
	cout << "P1 += M2" << endl;
	P1 += M2;
	cout << "P1 += M3" << endl;
	P1 += M3;
	cout << "P2 += M4" << endl;
	P2 += M4;
	cout << "P2 += M5" << endl;
	P2 += M5;
	cout << "P2 += M6" << endl << endl;
	P2 += M6;
	cout << "TPolynom P3 = P1 + P2" << endl << endl;
	TPolynom P3(5);
	P3 = P1 + P2;
	cout << "P1 = " << P1 << endl;
	cout << "P2 = " << P2 << endl;
	cout << "P3 = " << P3 << endl;

	return 0;
}

#endif