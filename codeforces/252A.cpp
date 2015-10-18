#include <iostream>
using namespace std;

const int MaxN = 100;
int N;
int arr[MaxN];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++)
		cin >> arr[i];

	int ans = 0;
	for (int i = 0; i < N; i ++) {
		int v = 0;
		for (int j = i; j < N; j ++) {
			v ^= arr[j];
			ans = max(ans, v);
		}
	}

	cout << ans << endl;

	return 0;
}
