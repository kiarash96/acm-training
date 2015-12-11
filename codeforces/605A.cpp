#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 1e5;

int N;
int arr[MaxN];
int pos[MaxN + 1];

int main() {
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i ++) {
		cin >> arr[i];
		pos[arr[i]] = i;
	}

	int ans[MaxN];
	ans[0] = 1;
	for (int i = 1; i < N; i ++) {
		ans[i] = 1;
		if (arr[i] > 1 && pos[arr[i] - 1] < i)
			ans[i] = 1 + ans[pos[arr[i] - 1]];
	}

	cout << N - *max_element(ans, ans + N) << endl;

	return 0;
}

