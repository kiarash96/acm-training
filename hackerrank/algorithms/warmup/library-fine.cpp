#include <iostream>
using namespace std;

int main() {
	int d, m, y;
	int D, M, Y;

	cin >> D >> M >> Y;
	cin >> d >> m >> y;

	if (Y - y > 0)
		cout << 10000;
	else if (Y - y == 0 && M - m > 0)
		cout << (M - m)*500;
	else if (Y - y == 0 && M - m == 0 && D - d > 0)
		cout << (D - d)*15;
	else
		cout << 0;
	cout << endl;

	return 0;
}

