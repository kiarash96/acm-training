#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

const int MaxN = 1e5;
int N, K;
int a[MaxN], b[MaxN];

// numbers leq than n that are divisible by x
inline int numdiv(const int n, const int x, const int mod) {
	return max((int) ceil((double)(n - mod + 1)/x), 0) % MOD;
}

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> K;
	for (int i = 0; i < N/K; i ++)
		cin >> a[i];
	for (int i = 0; i < N/K; i ++)
		cin >> b[i];

	int maxk = 0;
	for (int i = 0; i < K; i ++)
		maxk = maxk * 10 + 9;

	int ans = 1;
	for (int i = 0; i < N/K; i ++) { // ith block
		int x = (numdiv(maxk, a[i], 0)
				- numdiv(maxk/10, a[i], (a[i] - ((b[i] * (int)pow(10.0, K - 1)) % a[i])) % a[i])) % MOD;
		ans = ((ll) ans * x) % MOD;
	}

	cout << ans << endl;

	return 0;
}
