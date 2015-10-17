#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0LL)
		return a;
	return gcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(false);

	ll l, r;
	cin >> l >> r;

	for (ll a = l; a <= r; a ++)
		for (ll b = a + 1; b <= r; b ++)
			for (ll c = b + 1; c <= r; c ++)
				if (gcd(a, b) == 1LL && gcd(b, c) == 1LL && gcd(a, c) != 1LL) {
					cout << a << " " << b << " " << c << endl;
					return 0;
				}

	cout << -1 << endl;

	return 0;
}

