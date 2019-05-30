#pragma once
#include "../TextLib/MyString.h"
// TNode.h
class TNode {

protected:
	TNode* nextLevel;// ��������� �� ��������� �������
	TNode* sosed;// ��������� �� ������
	int level; // ������� �������� 0 - �����, 1 - ������, 2 - �����, 3 - ������.
	char data; // ������ ��������
	
	static TNode* start; // ������
	static TNode* end; // �����
	static TNode* _free; // ������ �����
	static char* mas; // ����� ������
	static int sizeMas; // ������ �������, ��� ����� ��� ���� ������

public:
	TNode(char c);
	TNode(TMyString s);
	TNode(int _level);
	TNode(TNode& other);
	TNode& operator=(const TNode& a);
	TNode& operator+=(TNode& a);
	TNode& operator+=(char c);
	TNode& operator+=(char*c);

	char* ToStr();
	TNode* Clone();

	int GetLevel();
	void SetLevel(int lev);
	TNode* GetNextLevel();
	void SetNextLevel(TNode* NL);
	TNode* GetSosed();
	void SetSosed(TNode* S);
	char GetData();
	void SetData(char c);

	void Init(int size); // ������������� ����������� �����
	void* operator new (size_t n);
	void operator delete (void* a);
	static void GC(); // ������� ������
};

