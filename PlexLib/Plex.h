#pragma once
#include "../PlexLib/Point.h"
#include "../PlexLib/Line.h"

class TPlex: public TPoint
{
protected:
	TPoint* left;
	TPoint* right;
public:
	TPlex();
	TPlex(TPoint* l, TPoint* r);
	TPlex(TPlex& P);

	TPoint* GetRight();
	TPoint* GetLeft();

	void SetRight(TPoint* R);
	void SetLeft(TPoint* L);

	void Add(TPoint* A, TPoint* B);
	virtual void Show();
	virtual TPoint* Show(TPlex* P);
};

