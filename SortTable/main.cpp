#include "../SortTableLib/SortTable.h"
#include "../PolishLib/Stroka.h"
#include <iostream>
using namespace std;
#define fortravis

#ifndef fortravis
int main()
{
	try
	{
		int size;
		TString key;
		int data;
		cout << "Enter size of table" << endl;
		cin >> size;
		TSortTable<int> ST(10);
		while (1)
		{
			cout << "What you want to do?" << endl;
			cout << "1) Add" << endl;
			cout << "2) Delete" << endl;
			cout << "3) Search" << endl;
			cout << "4) Get number of elements" << endl;
			cout << "5) Print" << endl;
			cout << "6) Exit" << endl;
			int n;
			cin >> n;
			switch (n)
			{
			case 1:
				cout << "Enter key" << endl;
				cin >> key;
				cout << "Enter data" << endl;
				cin >> data;
				ST.Put(key, data);
				break;
			case 2:
				cout << "Enter key" << endl;
				cin >> key;
				ST.Del(key);
				break;
			case 3:
				cout << "Enter key" << endl;
				cin >> key;
				cout << ST.Search(key) << endl;
				break;
			case 4:
				cout << "Count = " << ST.GetCount() << endl;
				break;
			case 5:
				cout << ST << endl;
				break;
			case 6:
				return 0;
			default:
				cout << "Incorrect value" << endl;
			}
		}
		return 0;
	}
	catch (MyException E)
	{
		E.Print();
	}
}
#endif




#ifdef fortravis
int main()
{
	cout << "The example of using" << endl;
	cout << "For Travis" << endl;
	TSortTable<int> A;
	TString one("one");
	TString two("two");
	TString three("three");
	TString four("four");
	TString five("five");
	TString six("six");
	TString seven("seven");
	TString eight("eight");
	A.Put(one, 1);
	A.Put(two, 2);
	A.Put(three, 3);
	cout << A;
	cout << "Searching ""three""" << endl;
	cout << A.Search(three) << endl;

	cout << endl << "New Table" << endl;
	cout << "keys: one, two, three, four, five, six, seven, eight" << endl;
	cout << "data: 1, 2, 3, 4, 5, 6, 7, 8" << endl;
	cout << "with Quick Sort" << endl;
	TString key[] = { one, two, three, four, five, six, seven, eight };
	int data[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	TSortTable<int> B(key, data, 8, 3);
	cout << B << endl << endl;


	cout << "Delete four" << endl;
	B.Del(four);
	cout << B << endl;
	return 0;
}
#endif