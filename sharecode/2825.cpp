#include <iostream>
using namespace std;

const int MaxN = 1e4;

int sumphi[MaxN + 1];

inline int phi(int x) {
	double ans = x;
	for (int p = 2; p <= x; p ++) {
		if (x % p == 0)
			ans *= (p - 1.0)/p;
		while (x % p == 0) 
			x /= p;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);

	sumphi[1] = phi(1);
	for (int x = 2; x <= MaxN; x ++)
		sumphi[x] = sumphi[x - 1] + phi(x);

	int T;
	cin >> T;
	while (T --) {
		int n;
		cin >> n;
		cout << sumphi[n] + 1 << endl;
	}

	return 0;
}

