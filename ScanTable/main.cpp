#include "../ScanTableLib/ScanTable.h"
#include "../ExceptionLib/ExceptionLib.h"
#include "../PolishLib/Stroka.h"
#include <iostream>
using namespace std;
#define fortravis

#ifdef fortravis
int main()
{
	try
	{
		int size;
		TString key;
		int data;
		cout << "Enter size of table" << endl;
		cin >> size;
		TScanTable<int> ST(10);
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

#ifndef fortravis
int main()
{
	cout << "Creating table" << endl;
	TScanTable<int> ST(10);
	cout << "Add key i, data 1" << endl;
	TString key1("i");
	ST.Put(key1, 1);
	cout << "Add key like, data 2" << endl;
	TString key2("like");
	ST.Put(key2, 2);
	cout << "Add key write, data 3" << endl;
	TString key3("write");
	ST.Put(key3, 3);
	cout << "Add key code, data 4" << endl;
	TString key4("code");
	ST.Put(key4, 4);
	cout << "Print table" << endl;
	cout << ST << endl;
	cout << "Delete i" << endl;
	ST.Del(key1);
	cout << "Delete write" << endl;
	ST.Del(key3);
	cout << endl << "Searcing ""code""" << endl;
	cout << ST.Search(key4) << endl;
	cout << "Searcing ""like""" << endl;
	cout << ST.Search(key2) << endl;
	cout << "Table size = " << ST.GetCount() << endl;
	cout << "Print table" << endl;
	cout << ST << endl;
	return 0;
}
#endif