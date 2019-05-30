#pragma once

class TPoint
{
protected:
	double x;
	double y;
public:
	TPoint(double _x, double _y);
	TPoint();
	TPoint(TPoint& A);

	double GetX();
	double GetY();
	void SetX(double _x);
	void SetY(double _y);
	bool operator==(TPoint& P);
	virtual void Show();
};
