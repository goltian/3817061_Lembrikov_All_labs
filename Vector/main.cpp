#include <iostream>
#include "Vector.h"

int main()
{
	float a[3] = { 1.1,2.4,3.4 };
	float b[3] = { 0.55, 1.2, 1.7 };
	int c[3] = { 1,2,3 };
	int d[3] = { 3,2,1 };

	TVector<float> A(a, 3);
	TVector<float> B(b, 3);
	TVector<int> C(c, 3);
	TVector<int> D(d, 3);
	TVector<float> Sum;
	TVector<float> Razn;
	TVector<float> Umn;
	TVector<float> Del;
	std::cout << A << "\n" << B << "\n" << C << "\n" << D << "\n";

	return 0;
}