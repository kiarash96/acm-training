#include <iostream>
#include <limits>
using namespace std;

int N, K;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	ll ans = numeric_limits<ll>::min();
	for (int i = 0; i < N; i ++) {
		ll f, t;
		cin >> f >> t;

		ans = max(ans, (t <= K ? f : f - t + K));
	}

	cout << ans << endl;

	return 0;
}
