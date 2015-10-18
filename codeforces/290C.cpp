#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int tux;
	cin >> tux;

	int foo = 0, bar = 0, baz = 0, quz = 1;

	while (tux -- > 0) {
		int pur;
		cin >> pur;

		foo += pur;
		bar ++;
	
		if (max(foo * quz, bar * baz) == foo * quz) {
			baz = foo;
			quz = bar;
		}
	}

	cout << fixed << setprecision(6) << 1.0 * baz / quz << endl;

	return 0;
}
