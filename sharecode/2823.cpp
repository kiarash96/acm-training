#include <iostream>
using namespace std;

typedef long long ll;

const int MaxN = 100;

ll C[MaxN + 1][MaxN + 1];

int main() {
	ios::sync_with_stdio(0);

	for (int i = 0; i <= MaxN; i ++)
		C[i][0] = 0LL;
	for (int i = 0; i <= MaxN; i ++)
		C[0][i] = 1LL;

	for (int i = 1; i <= MaxN; i ++)
		for (int j = 1; j <= MaxN; j ++)
			C[i][j] = C[i][j - 1] + C[i - 1][j - 1];

	int T;
	cin >> T;

	while (T --) {
		int n;
		cin >> n;

		ll ans = 0LL;
		for (int c = 0; c <= n/4; c ++) {
			if ((n - 4*c)% 2 == 1) 
				continue;

			int a = (n - 4*c) / 2;
			int b = a;
			int d = c;

			if (c + d < a + b)
				continue;

			ans += C[a][a + c] * C[b][b + d];
		}

		cout << ans << endl;
	}

	return 0;
}

