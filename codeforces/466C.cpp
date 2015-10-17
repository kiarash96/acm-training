#include <iostream>
using namespace std;

typedef long long ll;

const int MaxN = 5 * 1e5;
int N;
ll arr[MaxN];
ll sum[MaxN] = {0};

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++) {
		cin >> arr[i];
		sum[i] = arr[i] + (i > 0 ? sum[i - 1] : 0);
	}

	ll S = sum[N - 1];
	if (S % 3 != 0) {
		cout << 0 << endl;
		return 0;
	}

	ll first = 0LL, ans = 0LL;
	for (int i = 0; i < N - 1; i ++) {
		if (sum[i] - S/3 == S/3)
			ans += first;
		if (sum[i] == S/3)
			first ++;
	}

	cout << ans << endl;

	return 0;
}

