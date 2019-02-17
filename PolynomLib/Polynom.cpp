#include "Polynom.h"

TPolynom::TPolynom(int _n)
{
	if (_n <= 0)
	{
		MyException exp("Incorrect number of variables, Polynom.cpp, TPolynom, 1");
		throw exp;
	}
	n = _n;
	start = 0;
}

TPolynom::~TPolynom()
{
	TMonom* a=start;
	TMonom* b;
	while (a != 0)
	{
		b = a;
		a = a->GetNext();
		delete b;
	}
	n = 0;
	start = 0;
}

TPolynom TPolynom::operator+ (TPolynom &p) 
{
	if (this->n != p.n)
	{
		MyException exp("Different number of variables, Polynom.cpp, Operator = , 3");
		throw exp;
	}
	TPolynom temp(n);
	TMonom *i1 = start, *i2 = p.start, *i = 0; 
	while ((i1 != 0) && (i2 != 0))
	{
		TMonom *t1;
		if ((*i1) == (*i2))//если мономы в обоих полиномах совпадают
		{
			t1 = new TMonom((*i1) + (*i2));
			i1 = i1->GetNext();
			i2 = i2->GetNext();
		}
		else
			//для понимания стоит рисовать картинку для: (x0^2 + x1 + x2^2) + (x0^2 + x0 + x2^2 + x2)
		{
			if ((*i1) < (*i2)) // добавляем в результат моном из второго полинома
			{
				t1 = new TMonom((*i2));
				i2 = i2->GetNext();
			}
			else // если моном из первого полинома больше
			{
				t1 = new TMonom((*i1));
				i1 = i1->GetNext();
			}
		}
		if (temp.start == 0)
		{
			temp.start = t1; //если полином пустой, то туда впихиваем t1
			i = t1; //переходим к t1
		}
		else
		{
			i->SetNext(t1); //добавляем t1 к полиному, если он не пустой
			i = t1; //переходим к t1
		}
	}
	if (i1 == 0)
		i1 = i2; //если дошли до конца первого полинома, то перекидываем итератор второго на первый
	while (i1 != 0) //докидываем остаток
	{
		i->SetNext(new TMonom(*i1));
		i1 = i1->GetNext();
	}
	return temp;
}

TPolynom::TPolynom(TPolynom &p) {
	n = p.n;
	if (p.start == 0)
	{
		start = 0;
	}
	else
	{
		start = new TMonom(*p.start);
		TMonom *mt = start;
		TMonom *mp = p.start->GetNext();
		while (mp != 0)
		{
			mt->SetNext(new TMonom(*mp));
			mp = mp->GetNext();
			mt = mt->GetNext();
		}
		mt->SetNext(0);
	}
}

TPolynom& TPolynom::operator=(const TPolynom &p)
{
	if (*this == p)
		return *this;
	TMonom *m1 = start;
	TMonom *m2 = start;
	while (m1 != 0)
	{
		m1 = m1->GetNext();
		delete m2;
		m2 = m1;
	}
	//память очищена
	m1 = p.start->GetNext();
	m2 = new TMonom(*p.start);
	start = m2;
	while (m1 != 0)
	{
		m2->SetNext(new TMonom(*m1));
		m1 = m1->GetNext();
		m2 = m2->GetNext();
	}
	return *this;
}

TPolynom& TPolynom::operator+=(TMonom &m)
{
	if (this->n != m.GetN())
	{
		MyException exp("Different number of variables, Polynom.cpp, Operator+=, 3");
		throw exp;
	}
	if (m.GetC() == 0)
		return *this;
	if (start == 0) //Если полином пустой
		start = new TMonom(m);
	else //Если полином не пустой
	{
		TMonom *_start, *_end;
		_start = start;
		_end = start->GetNext();
		
		if (*start < m) // если моном больше, чем первый член полинома
		{
			TMonom* tmp = new TMonom(m);
			tmp->SetNext(start);
			start = tmp;
		}
		else if (*start == m)
		{
			*start += m;
			if (start->GetC() == 0)
			{
				TMonom *temp = start->GetNext();
				delete start;
				start = temp;
			}
		}
		
		else//если меньше первого
		{
			while (_end != 0)// пробегаемся по всему полиному
			{
				if (*_end == m)// моном равен второму значению пары
				{
					*_end += m;
					if (_end->GetC() == 0)
					{
						_start->SetNext(_end->GetNext());
						delete _end;
					}
					return *this;
				}
				if (*_end < m) //моном между парой
				{
					TMonom* tmp = new TMonom(m);
					_start->SetNext(tmp);
					tmp->SetNext(_end);
					return *this;
				}
				_start = _end;
				_end = _end->GetNext();
			}
				if (_end == 0)
					_start->SetNext(new TMonom(m));
		
		}
	}
	return *this;
}

TMonom* TPolynom::GetStart()
{
	return start;
}

bool TPolynom::operator ==(const TPolynom& p)
{
	TMonom* a = start;
	TMonom* b = p.start;
	while ((a != 0) && (b != 0))
	{
		if (!(*a == *b))
			return false;
		a = a->GetNext();
		b = b->GetNext();
	}
	if (a != b)
		return false;
	return true;
}

ostream& operator << (ostream& ostr, TPolynom& p)
{
	TMonom* a=p.start;
	while (a->GetNext() != 0)
	{
		ostr << *a << " + ";
		a = a->GetNext();
	}
	ostr << *a;
	return ostr;
}