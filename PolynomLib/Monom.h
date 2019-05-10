#pragma once
#include <iostream>
#include "../ExceptionLib/ExceptionLib.h"
class TMonom {
protected:
	TMonom* next;//Указатель на следующий
	unsigned* power;//Степени
	double c;// Коэффициент
	const int n;//Кол-во переменных
public:
	TMonom(int _n, unsigned* _power, double c);
	virtual ~TMonom();
	TMonom(const TMonom& monom);
	TMonom* GetNext();//Указатель на следующий
	unsigned* GetPower();//Степени
	double GetC();// Коэффициент
	const int GetN();//Кол-во переменных

	void SetNext(TMonom* _next);//Указатель на следующий
	void SetPower(unsigned* _power);//Степени
	void SetC(double _c);// Коэффициент

	TMonom& operator =(const TMonom& monom);
	TMonom operator +(TMonom& monom);
	TMonom& operator+=(TMonom& monom);
	TMonom operator -(TMonom& monom);
	TMonom operator*(TMonom& monom)const;
	TMonom operator*(int a);
	TMonom& operator *=(TMonom& monom);
	bool operator ==(TMonom& monom);
	bool operator >(TMonom& monom);
	bool operator <(TMonom& monom);

	friend std::istream& operator >> (std::istream& _s, TMonom& Tm);
	friend std::ostream& operator << (std::ostream& _s, TMonom& Tm);

};
