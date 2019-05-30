#pragma once
#include "../PlexLib/Point.h"

class TCircle
{
protected:
	TPoint* center;
	double r;
public:
	TCircle();
	TCircle(TPoint* c, double r);
	TCircle(TCircle& C);
	~TCircle();
	void SetCenter(TPoint* P);
	void SetR(double r);
	TPoint* GetCenter();
	double GetR();
	void Show();
};
