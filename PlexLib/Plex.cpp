#include "../PlexLib/Plex.h"
#include "../PlexLib/Line.h"
#include <iostream>
#include "../ExceptionLib/ExceptionLib.h"
#include "../StackListLib/StackList.h"
using namespace std;

TPlex::TPlex()
{
	right = NULL;
	left = NULL;
}

TPlex::TPlex(TPoint* l, TPoint* r)
{
	right = r;
	left = l;
}

TPlex::TPlex(TPlex& P)
{
	TPlex *pl, *pr;
	pl = dynamic_cast<TPlex*>(P.left);
	pr = dynamic_cast<TPlex*>(P.right);
	
	if (pl != 0)//Plex
		left = new TPlex(*pl);
	else
		left = new TPoint(*pl);

	if (pr != 0)//Plex
		right = new TPlex(*pr);
	else
		right = new TPoint(*pr);
}

TPoint* TPlex::GetRight()
{
	return right;
}

TPoint* TPlex::GetLeft()
{
	return left;
}

void TPlex::SetRight(TPoint* R)
{
	right = R;
}

void TPlex::SetLeft(TPoint* L)
{
	left = L;
}

void TPlex::Add(TPoint* A, TPoint* B)
{
	if (right == 0 && left == 0)
	{
		right = A;
		left = B;
	}
	else
	{
		TStackList<TPoint*> point;
		TStackList<TPlex*> plex;
		point.Put(right);
		point.Put(left);
		plex.Put(this);
		plex.Put(this);
		bool flag = true;
		while (flag && (!point.IsEmpty() || !plex.IsEmpty()))
		{
			TPoint* t = point.Get();
			TPlex* p = dynamic_cast<TPlex*>(t);
			TPlex* par = plex.Get();
			if (t->GetX() == A->GetX() && t->GetY() == A->GetY())
			{
				if (par->left == t)
					par->left = new TPlex(B, A);
				else
					par->right = new TPlex(B, A);
				flag = false;
			}
			else if (t->GetX() == B->GetX() && t->GetY() == B->GetY())
			{
				if (par->left == t)
					par->left = new TPlex(A, B);
				else
					par->right = new TPlex(A, B);
				flag = false;
			}
			else if (p != 0)
			{
				point.Put(p->left);
				point.Put(p->right);
				plex.Put(p);
				plex.Put(p);
			}
		}
		if (flag)
			throw MyException("Line is not connected with plex");
	}
}

void TPlex::Show()
{
	if (right == 0 && left == 0)
		throw MyException("Plex is empty");
	TStackList<TPlex*> stack;
	TStackList<TPoint*> point;
	TPlex *pl, *pr;
	TPlex *p = this;
	TPoint *tl = NULL, *tr = NULL;
	stack.Put(p);
	while (!stack.IsEmpty())
	{
		p = stack.Get();
		while (tr == NULL)
		{
			pr = dynamic_cast<TPlex*>(p->right);
			pl = dynamic_cast<TPlex*>(p->left);
			if (pr != 0 && pl != 0)
			{
				if (point.GetSize() % 2 == 0)
					p = stack.Get();
				else if (point.GetSize() == 1)
				{
					tr = point.Get();
					tl = point.Get();
				}
				else
				{
					stack.Put(p);
					stack.Put(pr);
					stack.Put(p);
					p = dynamic_cast<TPlex*>(pl);
				}
			}
			else if (pr != NULL)
			{
				stack.Put(p);
				p = dynamic_cast<TPlex*>(pr);
			}
			else
			{
				tr = p->right;
			}
		}
		if (tl == NULL)
		{
			pl = dynamic_cast<TPlex*>(p->left);
			if (pl != NULL)
			{
				stack.Put(p);
				p = dynamic_cast<TPlex*>(pl);
				tr = NULL;
				stack.Put(p);
			}
			else
			{
				tl = p->left;
			}
		}
		if (tr != NULL && tl != NULL)
		{

			TLine A(*tl, *tr);
			A.Show();
			cout << endl;
			if (!stack.IsEmpty())
			{
				p = stack.Get();
				pr = dynamic_cast<TPlex*>(p->right);
				pl = dynamic_cast<TPlex*>(p->left);
				TPoint *pp = tl;
				if (pr != 0 && pl != 0)
				{
					point.Put(pp);
					tl = NULL;
					tr = NULL;
				}
				else if (pr != 0)
				{
					tr = pp;
					tl = NULL;
				}
				else
				{
					tl = pp;
					tr = NULL;
				}
				stack.Put(p);
			}
		}
	}
}

TPoint* TPlex::Show(TPlex* P)
{
	TPlex *pl, *pr;
	TPoint *tl, *tr;

	pl = dynamic_cast<TPlex*>(P->left);
	pr = dynamic_cast<TPlex*>(P->right);

	if (pl != 0)
	{
		tl = Show(pl);
		cout << endl;
	}
	else
		tl = P->left;

	if (pr != 0)
	{
		tr = Show(pr);
		cout << endl;
	}
	else
		tr = P->right;
	TLine L(*tr, *tl);
	L.Show();
	cout << endl;
	return tr;
}