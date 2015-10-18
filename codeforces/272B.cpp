#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

int N;
map<int, int> cnt;

int f(int x) {
	int res = 0;
	while (x > 0) {
		if (x % 2 == 1)
			res ++;
		x /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++) {
		int x;
		cin >> x;
		cnt[f(x)] ++;
	}

	ll ans = 0;
	for (map<int, int>::iterator iter = cnt.begin(); iter != cnt.end(); iter ++)
		ans += ((ll) iter->second * (iter->second - 1)) / 2;

	cout << ans << endl;

	return 0;
}
