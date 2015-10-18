#include <iostream>
#include <set>
#include <cmath>
using namespace std;

typedef long long ll;

const int MaxN = 1e5;
int N;
ll K;
set<ll> S;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < N; i ++) {
		ll x;
		cin >> x;
		S.insert(x);
	}

	int ans = N;
	while (!S.empty()) {
		ll x = *S.begin();
		int len = 0;

		while (S.count(x) > 0) {
			S.erase(x);
			len ++;
			x *= K;
		}

		ans -= len / 2;
	}

	cout << ans << endl;

	return 0;
}
