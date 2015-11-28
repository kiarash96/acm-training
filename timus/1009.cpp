#include <iostream>
using namespace std;

const int MaxN = 16;
int N, K;
int dp[MaxN + 1];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	dp[1] = K - 1; dp[2] = (K - 1) * K;
	for (int i = 3; i <= N; i ++)
		dp[i] = (K - 1) * (dp[i - 1] + dp[i - 2]);
	
	cout << dp[N] << endl;

	return 0;
}

