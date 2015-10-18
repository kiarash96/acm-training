#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MaxN = 2 * 1e5;
int N, Q;
int arr[MaxN], cnt[MaxN] = {0};

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> Q;
	for (int i = 0; i < N; i ++)
		cin >> arr[i];
	for (int i = 0; i < Q; i ++) {
		int l, r;
		cin >> l >> r;
		l --; r --;
		cnt[l] ++;
		if (r + 1 < N)
			cnt[r + 1] --;
	}
	
	for (int i = 0; i < N; i ++)
		cnt[i] += (i == 0 ? 0 : cnt[i - 1]);

	sort(arr, arr + N);
	sort(cnt, cnt + N);

	ll sum = 0;
	for (int i = 0; i < N; i ++)
		sum += (ll) cnt[i] * arr[i];

	cout << sum << endl;

	return 0;
}
