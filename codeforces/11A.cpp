#include <iostream>
using namespace std;

typedef long long ll;

const int MaxN = 2000;
int N, D;
ll arr[MaxN];

int main() {
	cin >> N >> D;
	for (int i = 0; i < N; i ++)
		cin >> arr[i];

	int ans = 0;
	for (int i = 1; i < N; i ++)
		if (arr[i] <= arr[i - 1]) {
			int cnt = (arr[i - 1] - arr[i]) / D + 1;
			arr[i] += cnt * D;
			ans += cnt;
		}

	cout << ans << endl;

	return 0;
}
