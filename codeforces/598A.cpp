#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t ++) {
		int N;
		cin >> N;

		ll ans = (ll)N*(N + 1)/2;
		for (int i = 1; i <= N; i *= 2)
			ans -= 2*i;

		cout << ans << endl;
	}

	return 0;
}

