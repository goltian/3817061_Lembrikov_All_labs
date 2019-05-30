#include "../PlexLib/Circle.h"
#include "../ExceptionLib/ExceptionLib.h"
#include <iostream>
using namespace std;

TCircle::TCircle()
{
	center = NULL;
	r = 0;
}

TCircle::TCircle(TPoint* c, double _r)
{
	if (_r < 0)
		throw MyException("negative radius");
	center = c;
	r = _r;
}

TCircle::TCircle(TCircle& C)
{
	center = new TPoint(*C.center);
	r = C.r;
}

TCircle::~TCircle()
{
	center = NULL;
	r = 0;
}

void TCircle::SetCenter(TPoint* P)
{
	center = P;
}

void TCircle::SetR(double _r)
{
	r = _r;
}

TPoint* TCircle::GetCenter()
{
	return center;
}

double TCircle::GetR()
{
	return r;
}
void TCircle::Show()
{
	cout << "Circle: " << "Center = ";
	center->Show();
	cout << ", radius = " << r << endl;
}
