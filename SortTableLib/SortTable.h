#pragma once
#include "../SortTableLib/SortElem.h"
#include "../ExceptionLib/ExceptionLib.h"
#include <iostream>

template <class T>
class TSortTable
{
protected:
	TSortElem<T>* mas;
	int size;
	int count;

	void Bubble_Sort(TSortElem<T>* mas, int size);
	void Insert_Sort(TSortElem<T>* mas, int size);
	void Quick_Sort(TSortElem<T> *mas, int first, int last);

public:
	TSortElem<T> not_find;

	TSortTable(TString* k, T* d, int _size, int sort);
	TSortTable(int s = 10);
	TSortTable(TSortTable<T>& ST);
	~TSortTable();

	int Put(TString k, T d);
	void Del(TString k);
	TSortElem<T>& Search(TString k);
	void Resize(int s);

	int GetCount() { return count; }

	TSortElem<T>& operator[](TString k);
	TSortElem<T>& operator[](int i);
	template <class T1>

	friend ostream& operator<<(ostream& ostr, const TSortTable<T1> &A);
};

template <class T>
TSortTable<T>::TSortTable(TString* keys, T* dataes, int _size, int sort)
{
	if (_size <= 0)
		throw MyException("negative size");
	size = _size;
	mas = new TSortElem<T>[size];
	count = 0;
	TString notfind("not_find");
	not_find.SetKey(notfind);
	for (int i = 0; i < size; i++)
	{
		TSortElem<T> tmp(keys[i], dataes[i]);
		mas[i] = tmp;
		count++;
	}
	switch (sort)
	{
	case 1:
		Bubble_Sort(mas, size);
		break;
	case 2:
		Insert_Sort(mas, size);
		break;
	case 3:
		Quick_Sort(mas, 0, size - 1);
		break;
	default:
		throw MyException("incorect sort value");
	}
}

template <class T>
TSortTable<T>::TSortTable(int s)
{
	if (s <= 0)
		throw MyException("negative size");
	size = s;
	count = 0;
	mas = new TSortElem<T>[size];
	TString notfind("not_find");
	not_find.SetKey(notfind);
}

template <class T>
TSortTable<T>::TSortTable(TSortTable<T>& ST)
{
	size = ST.size;
	count = ST.count;
	mas = new TSortElem<T>[size];
	for (int i = 0; i < size; i++)
		mas[i] = ST.mas[i];
	TString notfind("not_find");
	not_find.SetKey(notfind);
}

template <class T>
TSortTable<T>::~TSortTable()
{
	if (size != 0)
	{
		delete[] mas;
		size = 0;
		count = 0;
	}
}

template <class T>
int TSortTable<T>::Put(TString k, T d)
{
	if (size <= count)
		Resize(count * 2);
	int right = count - 1;
	int left = 0;
	int cur = count / 2;
	while (right >= left)
	{
		if (mas[cur].GetKey() > k)
		{
			right = cur - 1;
			cur = (left + right) / 2;
		}
		else if (mas[cur].GetKey() < k)
		{
			left = cur + 1;
			cur = (left + right) / 2;
		}
		else
			throw MyException("Element already exist");
	}
	if ((mas[cur].GetKey() < k) && (count != 0))
		cur++;
	for (int i = count - 1; i >= cur; i--)
		mas[i + 1] = mas[i];
	TSortElem<T> temp(k, d);
	mas[cur] = temp;
	count++;
	return cur;

}


template <class T>
void TSortTable<T>::Del(TString k)
{
	int left = 0;
	int right = count - 1;
	int cur = count / 2;
	while (right >= left)
	{
		if (mas[cur].GetKey() > k)
		{
			right = cur - 1;
			cur = (left + right) / 2;
		}
		else if (mas[cur].GetKey() < k)
		{
			left = cur + 1;
			cur = (left + right) / 2;
		}
		else
		{
			for (int i = cur; i < count - 1; i++)
				mas[i] = mas[i + 1];
			TString noname("noname");
			mas[count - 1].SetKey(noname);
			count--;
			if (count < size / 2)
				Resize(size / 2);
			return;
		}
	}
	throw MyException("Element isn't find");
}

template <class T>
TSortElem<T>& TSortTable<T>::Search(TString k)
{
	int left = 0;
	int right = count - 1;
	int cur = count / 2;
	while (right >= left)
	{
		if (mas[cur].GetKey() > k)
		{
			right = cur - 1;
			cur = (left + right) / 2;
		}
		else if (mas[cur].GetKey() < k)
		{
			left = cur + 1;
			cur = (left + right) / 2;
		}
		else
			return mas[cur];
	}
	return not_find;
}

template <class T>
void TSortTable<T>::Resize(int s)
{
	if (s < this->count)
		throw MyException("New size is less then number of elements");
	if (s == this->size)
		return;
	TSortElem<T>* new_mas = new TSortElem<T>[s];
	for (int i = 0; i < this->count; i++)
		new_mas[i] = this->mas[i];
	delete[] this->mas;
	mas = new_mas;
	size = s;
}

template <class T>
TSortElem<T>& TSortTable<T>::operator[](TString k)
{
	TSortElem<T>& A = Search(k);
	if (A == not_find)
		throw MyException("Element isn't find");
	return A;
}

template<class T>
TSortElem<T>& TSortTable<T>::operator[](int i)
{
	if ((i >= count) || (i < 0))
		throw MyException("Value isn't correct");
	return mas[i];
}

template <class T1>
ostream& operator<<(ostream& ostr, const TSortTable<T1> &A)
{
	ostr << "key\t\tdata" << endl;
	for (int i = 0; i < A.count; i++)
		ostr << "| " << A.mas[i] << "\t\t |" << endl;
	ostr << endl;
	return ostr;
}

template <class T>
void TSortTable<T>::Bubble_Sort(TSortElem<T>* mas, int size)
{
	int i, j;
	TSortElem<T> tmp;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size - i - 1; j++)
			if (mas[j + 1] < mas[j]) {
				tmp = mas[j + 1];
				mas[j + 1] = mas[j];
				mas[j] = tmp;
			}
	}
}

template <class T>
void TSortTable<T>::Insert_Sort(TSortElem<T>* mas, int size)
{
	int i, j;
	TSortElem<T> tmp;
	for (i = 1; i < size; i++) {
		j = i - 1;
		while ((mas[j] > mas[j + 1]) && (j >= 0)) {
			tmp = mas[j + 1];
			mas[j + 1] = mas[j];
			mas[j] = tmp;
			j--;
		}
	}
}



template <class T>
void TSortTable<T>::Quick_Sort(TSortElem<T> *mas, int first, int last)
{
	TSortElem<T> mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; //вычисление опорного элемента
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l) //перестановка элементов
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) Quick_Sort(mas, first, l);
	if (f < last) Quick_Sort(mas, f, last);
}
