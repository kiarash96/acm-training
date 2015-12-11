#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 2 * 1e5;

int N, M;
int arr[MaxN];

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i ++)
		cin >> arr[i];

	sort(arr, arr + N);

	for (int i = 0; i < M; i ++) {
		int x;
		cin >> x;

		cout << (i == 0 ? "" : " ") << upper_bound(arr, arr + N, x) - arr;
	}
	cout << endl;

	return 0;
}

