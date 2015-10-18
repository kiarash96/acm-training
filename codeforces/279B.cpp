#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MaxN = 1e5;
int N;
ll T;
int arr[MaxN], sum[MaxN] = {0};

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> T;
	for (int i = 0; i < N; i ++) {
		cin >> arr[i];
		sum[i] = (i == 0 ? 0 : sum[i - 1]) + arr[i];
	}

	int ans = 0;
	for (int i = 0; i < N; i ++) {
		int ind = lower_bound(sum, sum + N, T) - sum;
		ans = max(ans, ind - i + (ind < N && sum[ind] == T));
		T += arr[i];
	}

	cout << ans << endl;

	return 0;
}
