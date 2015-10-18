#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll L, R;

const ll f(const ll x) {
	ll res = 1;
	while (2 * res <= x)
		res *= 2;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> L >> R;

	while (f(L) == f(R) && R > 1)
		L -= f(L), R -= f(R);
	
	ll m = f(R);
	cout << (m - 1 < L ? (ll) 0 : (m ^ (m - 1))) << endl;

	return 0;
}
