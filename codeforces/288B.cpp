#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MaxK = 8, MOD = 1e9 + 7;
int N, K;
ll number[MaxK + 1] = {0, 1, 2, 9, 64, 625, 7776, 117649, 2097152};

	mark[i] = true;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> K;

	int ans = number[K] % MOD;
	for (int i = 0; i < N - K; i ++)
		ans = 1LL * ans * (N - K) % MOD;

	cout << ans << endl;

	return 0;
}
