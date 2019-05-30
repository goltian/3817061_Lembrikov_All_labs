#pragma once
#include "Node.h"
#include "NodeIter.h"
class TText
{
protected:
	TNode *root;
public:
	TText();
	TText(TNode* r);
	TText(TText& T);
	TNode* GetRoot();
	char* Copy(int start, int n);
	void Del(TNode* start, int n);
	void Ins(TNode* start, TNode* d); // вставка
	void Ins(TNode* start, TMyString S);
	void Ins(TNode* start, char c);
	TNode* Find(char* a); // поиск с возратом узла
	int FindIndex(char* a); // поиск с возвратом номера буквы
	int GetCount();
	friend ostream& operator<<(ostream& ostr, const TText &T);

};