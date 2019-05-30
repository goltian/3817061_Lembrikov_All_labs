#include "../PlexLib/Plex.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Creating plex" << endl;
	TPlex Pl;
	TPoint P1(1, 2);
	TPoint P2(3, 5);
	TPoint P3(6, 5);
	TPoint P4(9, 3);
	TPoint P5(2, 7);

	cout << "Add (1, 2)-(3, 5) to plex" << endl;
	Pl.Add(&P1, &P2);
	cout << "Add (3, 5)-(6, 5) to plex" << endl;
	Pl.Add(&P2, &P3);
	cout << "Add (9, 3)-(3, 5) to plex" << endl;
	Pl.Add(&P4, &P2);
	cout << "Add (1, 2)-(3, 5) to plex" << endl;
	Pl.Add(&P4, &P2);
	cout << "Add (2, 7)-(9, 3) to plex" << endl;
	Pl.Add(&P5, &P4);

	cout << "Show plex" << endl;
	Pl.Show();

	return 0;
}