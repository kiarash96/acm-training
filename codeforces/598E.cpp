#include <iostream>
#include <cmath>
using namespace std;

const int INF = 1e9;
const int MaxNM = 30;
const int MaxK = 50;

int N, M, K;
int cost[MaxNM + 1][MaxNM + 1][MaxK + 1];

int main() {
	ios::sync_with_stdio(0);

	for (int n = 0; n <= MaxNM; n ++)
		for (int m = 0; m <= MaxNM; m ++)
			cost[n][m][0] = 0;

	for (int k = 1; k <= MaxK; k ++)
		for (int n = 0; n <= MaxNM; n ++)
			for (int m = 0; m <= MaxNM; m ++)
				if (k > n*m)
					cost[n][m][k] = -1;
				else if (k == n*m)
					cost[n][m][k] = 0;
				else if (k <= n*m) {
					for (int i = 1; i < m; i ++)
						cost[n][m][k] = min(cost[n][m][k], n*n + cost[n][i][min(k, n*i)] + cost[n][m - i][max(0, k - n*i)]);

					for (int i = 1; i < n; i ++)
						cost[n][m][k] = min(cost[n][m][k], m*m + cost[i][m][min(k, i*m)] + cost[n - i][m][max(0, k - i*m)]);
				}

	int T;
	cin >> T;
	while (T --) {
		cin >> N >> M >> K;
		cout << cost[N][M][K] << endl;
	}

	return 0;
}

