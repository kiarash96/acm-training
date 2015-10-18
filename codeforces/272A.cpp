#include <iostream>
using namespace std;

int N, sum = 0;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++) {
		int x;
		cin >> x;
		sum += x;
	}

	int ans = 0;
	for (int i = 1; i <= 5; i ++)
		if ((sum + i) % (N + 1) != 1)
			ans ++;

	cout << ans << endl;

	return 0;
}
