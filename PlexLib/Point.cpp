#include "../PlexLib/Point.h"
#include <iostream>
using namespace std;

TPoint::TPoint(double _x, double _y)
{
	x = _x;
	y = _y;
}

TPoint::TPoint()
{
	x = 0;
	y = 0;
}

TPoint::TPoint(TPoint& A)
{
	x = A.x;
	y = A.y;
}

double TPoint::GetX()
{
	return x;
}

double TPoint::GetY()
{
	return y;
}

void TPoint::SetX(double _x)
{
	x = _x;
}

void TPoint::SetY(double _y)
{
	y = _y;
}

bool TPoint::operator==(TPoint& P)
{
	return (x == P.x) && (y == P.y);
}

void TPoint::Show()
{
	cout << "(" << x << " , " << y << ")";
}