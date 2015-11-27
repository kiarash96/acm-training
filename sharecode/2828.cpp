#include <iostream>
using namespace std;

typedef long long ll;

const int MaxN = 30;

int main() {
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while (T --) {
		int N, M, K;
		cin >> N >> M >> K;

		ll ans[MaxN + 1] = {0};
		bool mark[MaxN + 1] = {0};

		for (int i = 0; M + i*K <= N; i ++)
			mark[M + i*K] = true;

		for (int i = 1; i <= N; i ++) {
			if (!mark[i])
				ans[i] ++;
			for (int j = 1; j < i; j ++)
				if (!mark[j])
					ans[i] += ans[i - j];
		}

		cout << ans[N] << endl;
	}

	return 0;
}

