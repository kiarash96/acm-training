#include <iostream>
#include <algorithm>
using namespace std;

int median(int a, int b, int c) {
	if (a > b)
		swap(a, b);
	if (a > c)
		swap(a, c);
	if (b > c)
		swap(b, c);

	return b;
}

int main() {
	ios::sync_with_stdio(0);

	int a, b, c,
		d, e, f,
		g, h, i;

	cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;

	int x = median(a, b, c), y = median(d, e, f), z = median(g, h, i);

	cout << median(x, y, z) << endl;

	return 0;
}

