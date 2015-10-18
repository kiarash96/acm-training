#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t ++) {
		int a, b;
		cin >> a >> b;
		if (a < b)
			swap(a, b);

		int ans = 0;
		while (a > 0 && b > 0) {
			ans += a/b;
			a -= (a/b) * b;
			swap(a, b);
		}

		cout << ans << endl;
	}
	return 0;
}
