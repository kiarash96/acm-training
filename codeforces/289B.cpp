#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 100 * 100;
int arr[MaxN];
int N, M, D;

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> M >> D;
	N *= M;
	for (int i = 0; i < N; i ++)
		cin >> arr[i];

	int mod = arr[0] % D;
	bool ok = true;
	for (int i = 0; i < N; i ++)
		ok &= (arr[i] % D == mod);

	sort(arr, arr + N);
	int mid = N / 2;

	int ans = 0;
	for (int i = 0; i < N; i ++)
		ans += 1.0 * abs(arr[i] - arr[mid]) / D;

	cout << (ok ? ans : -1) << endl;

	return 0;
}
