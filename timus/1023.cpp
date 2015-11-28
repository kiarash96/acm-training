#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int K;
	cin >> K;

	int ans = 0;
	for (int i = 2; i < K; i ++)
		if (K % (i + 1) == 0) {
			ans = i;
			break;
		}

	cout << ans << endl;

	return 0;
}

