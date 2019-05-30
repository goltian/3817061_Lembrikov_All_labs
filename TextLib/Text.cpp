#include "../TextLib/Text.h"
using namespace std;


TText::TText()
{
	root = new TNode(0);
}

TText::TText(TNode* r)
{
	root = r;
}

TText::TText(TText& T)
{
	root = T.root->Clone();
}

TNode* TText::GetRoot()
{
	return root;
}

char* TText::Copy(int start, int n)
{
	char* res = new char[n];
	bool f = false;
	int pos = 0;
	TNodeIter t(root);
	while (pos != start)
	{
		if (t.IsEnd())
			throw MyException("incorrect values");
		if (t()->GetLevel() == 3)
			pos++;
		t++;
	}
	pos = 0;
	while (pos < n)
	{
		if (t.IsEnd())
			throw MyException("incorrect values");
		if (t()->GetLevel() == 3)
		{
			res[pos] = t()->GetData();
			pos++;
		}
		t++;
	}
	return res;
}

void TText::Del(TNode* start, int n)
{

	TNodeIter iter(root);
	int i = n;
	int count = 0;
	bool flag = false;
	bool nextflag = false;
	bool sameflag = false;
	TNode* temp1;
	TNode* temp2;
	TNode* temp3;

	while (iter.IsEnd() != true)
	{
		iter++;
		TNode* tmp = iter();
		if (tmp->GetSosed() == start)
		{
			temp1 = tmp;
			sameflag = true;
		}
		if (tmp->GetNextLevel() == start)
		{
			temp3 = tmp;
			nextflag = true;
		}
		if (tmp == start)
		{
			delete tmp;
			i--;
			flag = true;
		}
		else if (flag == true && tmp->GetLevel() == 3)
		{
			if (i == 1)
				temp2 = tmp->GetSosed();
			delete tmp;
			i--;
		}
		if (i == 0)
			break;
	}
	if (nextflag == true)
		temp3->SetNextLevel(temp2);
	if (sameflag == true)
		temp1->SetNextLevel(temp2);
		
}

int TText::GetCount()
{
	TNodeIter i(root);
	int count = 0;
	for (; !(i.IsEnd()); i++)
		if (i()->GetLevel() == 3)
			count++;
	return count;
}

void TText::Ins(TNode* start, TNode* d)
{ 
	if (start->GetLevel() != d->GetLevel())
		throw MyException("different level");
	d->SetSosed(start->GetSosed());
	start->SetSosed(d);
}

void TText::Ins(TNode* start, TMyString S)
{
	if (start->GetLevel() == 3)
		throw MyException("different level");
	TNode* N = new TNode(S);
	if (start->GetLevel() == 0)
	{
		if (start->GetNextLevel() == 0)
			start->SetNextLevel(new TNode(1));
		start = start->GetNextLevel();
	}
	if (start->GetLevel() == 1)
	{
		if (start->GetNextLevel() == 0)
		{
			start->SetNextLevel(N);
			return;
		}
		start = start->GetNextLevel();
	}
	N->SetSosed(start->GetSosed());
	start->SetSosed(N);
}

void TText::Ins(TNode* start, char c)
{
	if (start->GetLevel() != 3)
		throw MyException("different level");
	TNode* N = new TNode(c);
	if (start->GetLevel() == 0)
	{
		if (start->GetNextLevel() == 0)
			start->SetNextLevel(new TNode(1));
		start = start->GetNextLevel();
	}
	if (start->GetLevel() == 1)
	{
		if (start->GetNextLevel() == 0)
			start->SetNextLevel(new TNode(1));
		start = start->GetNextLevel();
	}
	if (start->GetLevel() == 2)
	{
		if (start->GetNextLevel() == 0)
		{
			start->SetNextLevel(N);
			return;
		}
		start = start->GetNextLevel();

	}
	N->SetSosed(start->GetSosed());
	start->SetSosed(N);
}

TNode* TText::Find(char* a)
{
	TNodeIter i(root);
	for (; !(i.IsEnd()); i++)
	{
		if (i()->GetData() == a[0])
		{
			bool f = true;
			TNodeIter j = i;
			int t = 1;
			while ((!(j.IsEnd())) && (a[t]!='\0'))
			{
				if (j()->GetData() != a[t])
				{
					f = false;
					break;
				}
				t++;
			}
			if (f = true)
				return i();
		}
	}
	return NULL;
}

int TText::FindIndex(char * a)
{
	int k = -1;
	TNodeIter i(root);
	for (; !(i.IsEnd()); i++)
	{
		if (i()->GetLevel() == 3)
			k++;
		if (i()->GetData() == a[0])
		{
			bool f = true;
			TNodeIter j = i;
			int t = 1;
			while ((!(j.IsEnd())) && (a[t] != '\0'))
			{
				if (j()->GetData() != a[t])
				{
					f = false;
					break;
				}
				t++;
			}
			if (f = true)
				return k;
		}
	}
	return -1;
}

ostream& operator<<(ostream& ostr, const TText &T)
{
	TNodeIter i(T.root);
	for (int k = 0; k < 3; k++)
	{
		if (i()->GetNextLevel() == 0)
			return ostr;
		i++;
	}
	for (; !(i.IsEnd()); i++)
	{
		if ((i()->GetLevel() == 3) && (i()->GetData() != -1))
			ostr << i()->GetData();
		else if ((i()->GetLevel() == 2) && (i()->GetSosed() != 0) && (i()->GetLevel()!= 0))
			ostr << " ";
		else if (i()->GetLevel() == 1)
			ostr << endl;
	}
	return ostr;
}
