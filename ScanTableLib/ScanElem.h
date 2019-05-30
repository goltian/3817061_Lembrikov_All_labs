#pragma once
#include "../PolishLib/Stroka.h"
#include <iostream>
using namespace std;

template <class T>
class TScanElem
{
protected:
	TString key;
	T data;
public:
	TScanElem();
	TScanElem(TString k, T d);
	TScanElem(TScanElem<T>& A);
	TScanElem<T>& operator=(TScanElem<T>& A);

	TString GetKey();
	T GetData();
	void SetKey(TString k);
	void SetData(T d);
	T& operator()();

	bool operator==(TScanElem<T>& A);
	bool operator>(TScanElem<T>& A);
	bool operator< (TScanElem<T>& A);

	template <class T1>
	friend ostream& operator<<(ostream& ostr, const TScanElem<T1> SE);
};

template<class T>
TScanElem<T>::TScanElem()
{
	TString noname("noname");
	key = noname;
	data = (T)0;
}

template <class T>
TScanElem<T>::TScanElem(TString k, T d)
{
	key = k;
	data = d;
}

template <class T>
TScanElem<T>::TScanElem(TScanElem& A)
{
	key = A.key;
	data = A.data;
}

template <class T>
TScanElem<T>& TScanElem<T>::operator=(TScanElem<T>& A)
{
	key = A.key;
	data = A.data;
	return *this;
}

template <class T>
TString TScanElem<T>::GetKey()
{
	return key;
}

template <class T>
T TScanElem<T>::GetData()
{
	return data;
}

template <class T>
void TScanElem<T>::SetKey(TString k)
{
	key = k;
}

template <class T>
void TScanElem<T>::SetData(T d)
{
	data = d;
}

template<class T>
T& TScanElem<T>::operator()()
{
	return data;
}


template <class T>
bool TScanElem<T>::operator==(TScanElem<T>& A)
{
	return key == A.key;
}

template <class T>
bool TScanElem<T>::operator>(TScanElem<T>& A)
{
	return key > A.key;
}

template <class T>
bool TScanElem<T>::operator<(TScanElem<T>& A)
{
	return key < A.key;
}

template <class T1>
ostream& operator<<(ostream& ostr, const TScanElem<T1> SE)
{
	ostr << SE.key << "\t|" << SE.data;
	return ostr;
}