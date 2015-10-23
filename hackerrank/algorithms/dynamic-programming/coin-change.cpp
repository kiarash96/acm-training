#include <iostream>
using namespace std;

typedef long long ll;

const int MaxN = 250;
const int MaxK = 50;
int N, K;
int coins[MaxK + 1];
ll dp[MaxN + 1];

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> K;
	for (int i = 1; i <= K; i ++)
		cin >> coins[i];

	for (int i = 0; i <= N; i ++)
		dp[i] = 0;
	dp[0] = 1;

	for (int k = 1; k <= K; k ++)
		for (int n = 1; n <= N; n ++)
			dp[n] = dp[n] + (n - coins[k] >= 0 ? dp[n - coins[k]] : 0);

	cout << dp[N] << endl;

	return 0;
}

