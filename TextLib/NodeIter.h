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
	TNodeIter(TNode*r); // ����������� �� ���������
	TNodeIter& GoNext(); // ������� �� ��������� �������
	void Reset(); // �������� ������� ������� � ���������� ��������� �� ������
	bool IsEnd(); // ���� �� ���������, �� ���������� ������
	TNode* operator() ();
	TNodeIter& operator++ (int);
};