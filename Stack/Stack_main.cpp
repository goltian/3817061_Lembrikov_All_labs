#include "../StackLib/Stack.h"
#include <cstdlib> 

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Пример использования стэка" << endl << "\nВведите размер стэка: ";
	int n;
	cin >> n;
	try
	{
		TStack<int> stack(n);
		for (int i = 0; i < n; i++)
			stack.Put(i);

		cout << "\стэк: \n";
		stack.PrintStack();

		TStack<int> copyStack(stack);
		cout << "\n\nКопирование стэка :\n";
		copyStack.PrintStack();

		if (copyStack == stack)
			cout << "\n\nИсходный и скопированный стэки равны";

		cout << "\n\nВынуть элемент из стэка: " << stack.Get();

		cout << "\n\nПолучившийся стэк:\n";
		stack.PrintStack();

		if (copyStack != stack)
			cout << "\n\nПолучившийся и исходный стэки разные\n";
	}

	catch (MyException exp)
	{
		exp.Print();
	}
	return 0;
}