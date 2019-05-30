#pragma once
#include "../PlexLib/Point.h"

class TLine
{
protected:
	TPoint A;
	TPoint B;
public:
	TLine();
	TLine(TPoint _A, TPoint _B);
	TLine(double x1, double y1, double x2, double y2);
	TLine(TLine& Other);

	TPoint GetA();
	TPoint GetB();
	void SetA(TPoint _A);
	void SetB(TPoint _B);

	void Show();
};
