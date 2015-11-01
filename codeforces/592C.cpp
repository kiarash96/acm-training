#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll t, a, b;

inline ll lcm(ll a, ll b) {
	ll ans = a*(b/__gcd(a, b));
	return (ans/a == b/__gcd(a, b) ? ans : t + 1);
}

int main() {
	ios::sync_with_stdio(0);

	cin >> t >> a >> b;

	if (a > b)
		swap(a, b);

	ll l = lcm(a, b);

	ll p = (t/l)*a + max(0LL, min(a - 1, t%l));
	ll g = __gcd(p, t);

	cout << p / g << "/" << t / g << endl;

	return 0;
}

