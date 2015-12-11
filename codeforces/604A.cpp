#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int N = 5;
int x[N] = {500, 1000, 1500, 2000, 2500};
int m[N], w[N];
int hs, hu;

int main() {
	ios::sync_with_stdio(0);

	for (int i = 0; i < N; i ++)
		cin >> m[i];
	for (int i = 0; i < N; i ++)
		cin >> w[i];
	cin >> hs >> hu;

	long double ans = 0.0;
	for (int i = 0; i < N; i ++)
		ans += round(max(0.3*x[i], (1.0 - m[i]/250.0)*x[i] - 50.0 * w[i]));

	cout << ans + 100*hs - 50*hu << endl;

	return 0;
}

