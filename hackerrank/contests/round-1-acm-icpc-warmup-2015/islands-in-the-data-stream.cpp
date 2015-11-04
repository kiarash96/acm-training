#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int P;
	cin >> P;
	
	for (int p = 0; p < P; p ++) {
		int K;
		cin >> K;

		const int N = 12;
		int arr[N];
		for (int i = 0; i < N; i ++)
			cin >> arr[i];

		int ans = 0;
		for (int i = 1; i < N - 1; i ++)
			for (int j = i; j < N - 1; j ++) {
				bool island = true;
				for (int k = i; k <= j; k ++)
					island &= arr[i - 1] < arr[k] && arr[k] > arr[j + 1];
				ans += island;
			}
		cout << K << " " << ans << endl;
	}

	return 0;
}

