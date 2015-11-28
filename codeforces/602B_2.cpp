#include <iostream>
using namespace std;

const int MaxN = 1e5;

int N;
int arr1[MaxN], arr2[MaxN];

inline int max_consecutive(int arr[]) {
	int ans = 1;
	for (int i = 0, j = 0; j < N; j ++) {
		while (arr[i] != arr[j])
			i ++;
		ans = max(ans, j - i + 1);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i ++) {
		int x;
		cin >> x;

		arr1[i] = arr2[i] = x;
		if (x % 2 == 0)
			arr1[i] ++;
		else
			arr2[i] ++;
	}

	cout << max(max_consecutive(arr1), max_consecutive(arr2)) << endl;

	return 0;
}

