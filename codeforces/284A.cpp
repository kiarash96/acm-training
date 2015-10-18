#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int phi(const int n) {
	int res = 0;
	for (int i = 1; i <= n; i ++)
		if (__gcd(i, n) == 1)
			res ++;
	return res;
}

int main() {
	ios::sync_with_stdio(false);

	int p;
	cin >> p;
	cout << phi(phi(p)) << endl;

	return 0;
}
