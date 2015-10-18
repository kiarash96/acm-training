#include <iostream>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;
int N, M, K;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;
	long long ans = 0;

	if (K < N) {
		if (K % 2 == 0)
			ans = M;
		else
			ans = M*M;
	}

	if (K >= N || K == 1) {
		int end = 0;
		if (K == N)
			end = ceil((double) N / 2.0);
		else
			end = N;

		ans = 1;
		for (int i = 0; i < end; i ++)
			ans = (ans * M) % MOD;
	}
	
	cout << ans << endl;

	return 0;
}
