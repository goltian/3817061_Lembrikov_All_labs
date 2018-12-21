#include "Matrix.h" 
#include <cstdlib> 
#include <ctime> 

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(static_cast<unsigned int>(time(0)));
	double ra, nd, om;

	cout << "�������: \n";
	TMatrix<double> M1(5), M2(5), Res(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5 - i; j++)
		{
			ra = rand();
			nd = ra / RAND_MAX;
			om = nd * 49 + 1;

			M1[i][j] = om;

			ra = rand();
			nd = ra / RAND_MAX;
			om = nd * 49 + 1;

			M2[i][j] = om;
		}
	cout << "\n������� 1:" << endl << M1 << endl;
	cout << "\n������� 2:" << endl << M2 << endl;

	cout << "\n�������������� ��������: \n\n";
	try {
		Res = M1 + M2;
		cout << "������� 1 + ������� 2:" << endl << Res << endl;
	}
	catch (MyException exp)
	{
		exp.Print();
	}

	try {
		Res = M1 - M2;
		cout << "������� 1 - ������� 2:" << endl << Res << endl;
	}
	catch (MyException exp)
	{
		exp.Print();
	}

	try {
		Res = M1 * M2;
		cout << "������� 1 * ������� 2:" << endl << Res << endl;
	}
	catch (MyException exp)
	{
		exp.Print();
	}

	try {
		Res = M1 / M2;
		cout << "������� 1 / ������� 2:" << endl << Res << endl;
	}
	catch (MyException exp)
	{
		exp.Print();
	}

	cout << "\n\n������� ������� ����������� 3:\n";
	TMatrix <int> MT(3);
	cin >> MT;
	cout << "\n��������� ���� �������:" << endl << MT;

	/*//������������ �������� 
	TMatrix <int> MTest1(10000);
	TMatrix <int> MTest2(10000);
	TMatrix <int> MTest3(10000);

	for (int i = 0; i < 10000; i++)
	{
		for (int j = 0; j < 10000 - i; j++)
	{
	MTest1[i][j] = (int)rand();
	MTest2[i][j] = (int)rand();
	}
	}
	int start = clock();
	MTest3 = MTest1 + MTest2;
	int end = clock();

	cout << "�����: " << (end - start) << " ����������" << endl;*/

	return 0;
}