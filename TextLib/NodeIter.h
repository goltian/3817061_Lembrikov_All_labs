#pragma once
#include "../StackListLib/StackList.h"
#include "Node.h"
using namespace std;

class TNodeIter
{
protected:
	TNode* root;
	TNode* cur;
	TStackList <TNode*> St;
public:
	TNodeIter(TNode*r); // конструктор по умолчанию
	TNodeIter& GoNext(); // перейти на следующий элемент
	void Reset(); // сбросить текущую позицию и установить указатель на начало
	bool IsEnd(); // если мы закончили, то возвращает правду
	TNode* operator() ();
	TNodeIter& operator++ (int);
};