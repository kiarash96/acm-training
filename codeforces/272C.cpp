#include <iostream>
using namespace std;

typedef long long ll;

const int MaxN = 1e5;
int N, M;
int arr[MaxN];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++)
		cin >> arr[i];

	cin >> M;

	ll c = 0;
	for (int i = 0; i < M; i ++) {
		int w, h;
		cin >> w >> h;

		ll ans = max(c, (ll) arr[w - 1]);
		c = ans + h;

		cout << ans << endl;
	}

	return 0;
}
