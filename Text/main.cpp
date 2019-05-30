#include "../TextLib/Text.h"
#include "../TextLib/MyString.h"
#include <iostream>
using namespace std;

int main()
{
	TMyString S;
	S = "This is string";
	cout<<"Create TNode by string ""This is string"""<<endl;
	TNode A(S);
	char* C = A.ToStr();
	TMyString S2(C);
	cout << S2 << endl;
	cout << endl << "Creating Text" << endl;
	TText Text;
	cout << "Add string ""This is string""" << endl << endl;
	Text.Ins(Text.GetRoot(), S);
	cout << "Printing Text" << endl;
	cout << Text << endl;
	cout << "Add char 'c'" << endl << endl;
	Text.Ins(Text.GetRoot(), "c");
	cout << "Printing Text" << endl;
	cout << Text << endl;
	cout << "find index for ""str""" << endl << endl;
	int p = Text.FindIndex("str");
	cout << "index = " << p << endl;
}