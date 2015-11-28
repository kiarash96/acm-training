#include <iostream>
using namespace std;

const int MaxN = 300 * 1000;

int N, M;
int arr[MaxN];

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i ++)
		cin >> arr[i];

	int ans = 0;
	int sum = 0, i = 0;
	for (int j = 0; j < N; j ++) {
		sum += arr[j];

		while (sum > M && i < j)
			sum -= arr[i ++];

		if (sum <= M)
			ans = max(ans, sum);
	}

	cout << ans << endl;

	return 0;
}

