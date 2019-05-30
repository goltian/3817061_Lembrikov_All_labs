#include "NodeIter.h"

TNodeIter::TNodeIter(TNode *r)
{
	root = cur = r;
	St.Put(root);
}

TNodeIter& TNodeIter::GoNext()
{
	cur = St.Get();
	if (cur->GetSosed() != 0)
	{
		St.Put(cur->GetSosed());
	}
	if (cur->GetNextLevel() != 0)
		St.Put(cur->GetNextLevel());
	return *this;
}

void TNodeIter::Reset()
{
	cur = root;
	while (!(St.IsEmpty()))
		St.Get();
	St.Put(cur);
}

bool TNodeIter::IsEnd()
{
	return St.IsEmpty();
}

TNode* TNodeIter::operator()()
{
	return cur;
}

TNodeIter& TNodeIter::operator++(int)
{
	return (*this)=this->GoNext();
}
