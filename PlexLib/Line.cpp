#include "../PlexLib/Line.h"
#include <iostream>
using namespace std;

TLine::TLine()
{
	A = TPoint(0, 0);
	B = TPoint(0, 0);
}

TLine::TLine(TPoint _A, TPoint _B)
{
	A = _A;
	B = _B;
}

TLine::TLine(double x1, double y1, double x2, double y2)
{
	A = TPoint(x1, y1);
	B = TPoint(x2, y2);
}

TLine::TLine(TLine& Other)
{
	A = Other.A;
	B = Other.B;
}

TPoint TLine::GetA()
{
	return A;
}

TPoint TLine::GetB()
{
	return B;
}

void TLine::SetA(TPoint _A)
{
	A = _A;
}

void TLine::SetB(TPoint _B)
{
	B = _B;
}

void TLine::Show()
{
	cout << "(" << A.GetX() << " , " << A.GetY() << ")" << "-" << "(" << B.GetX() << " , " << B.GetY() << ")";
}