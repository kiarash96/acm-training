/*
 * Calculate nth fibonacci number in O(logn)
 */

#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

map<ll, ll> memo;

ll fib(ll n) {
	if (memo.find(n) == memo.end())
		memo[n] = fib((n+1)/2) * fib(n/2) + fib((n-1)/2) * fib((n-2)/2);
	return memo[n];
}

int main() {
	ios::sync_with_stdio(0);

	memo[0] = 1;
	memo[1] = 1;

	ll n;
	cin >> n;

	cout << fib(n - 1) << endl;

	return 0;
}

