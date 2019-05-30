#pragma once
#include "../PolishLib/Stroka.h"
#include <iostream>
using namespace std;

template <class T>
class TSortElem
{
protected:
	TString key;
	T data;
public:
	TSortElem();
	TSortElem(TString k, T d);
	TSortElem(TSortElem<T>& A);
	TSortElem<T>& operator=(TSortElem<T>& A);

	TString GetKey();
	T GetData();
	void SetKey(TString k);
	void SetData(T d);
	T& operator()();

	bool operator==(TSortElem<T>& A);
	bool operator>(TSortElem<T>& A);
	bool operator< (TSortElem<T>& A);

	template <class T1>
	friend ostream& operator<<(ostream& ostr, const TSortElem<T1> SE);
};

template<class T>
TSortElem<T>::TSortElem()
{
	TString noname("noname");
	key = noname;
	data = 0;
}

template <class T>
TSortElem<T>::TSortElem(TString k, T d)
{
	key = k;
	data = d;
}

template <class T>
TSortElem<T>::TSortElem(TSortElem& A)
{
	key = A.key;
	data = A.data;
}

template <class T>
TSortElem<T>& TSortElem<T>::operator=(TSortElem<T>& A)
{
	key = A.key;
	data = A.data;
	return *this;
}

template <class T>
TString TSortElem<T>::GetKey()
{
	return key;
}

template <class T>
T TSortElem<T>::GetData()
{
	return data;
}

template <class T>
void TSortElem<T>::SetKey(TString k)
{
	key = k;
}

template <class T>
void TSortElem<T>::SetData(T d)
{
	data = d;
}

template<class T>
T& TSortElem<T>::operator()()
{
	return data;
}


template <class T>
bool TSortElem<T>::operator==(TSortElem<T>& A)
{
	return key == A.key;
}

template <class T>
bool TSortElem<T>::operator>(TSortElem<T>& A)
{
	return key > A.key;
}

template <class T>
bool TSortElem<T>::operator<(TSortElem<T>& A)
{
	return key < A.key;
}

template <class T1>
ostream& operator<<(ostream& ostr, const TSortElem<T1> SE)
{
	ostr << SE.key << "\t|" << SE.data;
	return ostr;
}

