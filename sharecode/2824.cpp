#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

const int MOD = 1e9;

map<ll, int> memo;

int fib(ll n) {
	if (memo.find(n) == memo.end())
		memo[n] = ((1LL * fib((n+1)/2) * fib(n/2)) % MOD + (1LL * fib((n-1)/2) * fib((n-2)/2)) % MOD) % MOD;
	return memo[n];
}

int main() {
	ios::sync_with_stdio(0);

	memo[0] = 1;
	memo[1] = 1;

	int T;
	cin >> T;
	
	while (T --) {
		ll n;
		cin >> n;
		cout << fib(n - 1) << endl;
	}

	return 0;
}

