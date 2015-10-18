#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 5000;
int N, M;
int arr[MaxN];
int dp[MaxN];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i ++) {
		double tmp;
		cin >> arr[i] >> tmp;
	}

	dp[0] = 1;
	for (int i = 1; i < N; i ++) {
		dp[i] = 1;
		for (int j = 0; j < i; j ++)
			if (arr[j] <= arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
	}

	cout << N - *max_element(dp, dp + N) << endl;

	return 0;
}
