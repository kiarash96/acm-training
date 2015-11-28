#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

const int MaxN = 4 * 1e5;

int N, K;
int arr[MaxN];

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> K;
	for (int i = 0; i < N; i ++)
		cin >> arr[i];

	ll dp[MaxN] = {0};
	map<int, int> cnt;
	int i = 0, j;
	for (j = 0; j < N; j ++) {
		dp[j] = (j == 0 ? 0 : dp[j - 1]);
		cnt[arr[j]] ++;
		while (cnt[arr[j]] >= K) {
			cnt[arr[i]] --;
			i ++;
			dp[j] ++;
		}
	}

	ll ans = 0;
	for (int i = 0; i < N; i ++)
		ans += dp[i];

	cout << ans << endl;

	return 0;
}

