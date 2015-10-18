#include <iostream>
using namespace std;

const int MaxN = 300;
int N, K;
int dist[MaxN][MaxN];
long long sum = 0;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++) {
			cin >> dist[i][j];
			sum += dist[i][j];
		}
	sum /= 2;

	cin >> K;
	for (int t = 0; t < K; t ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --; v --;

		for (int i = 0; i < N; i ++)
			for (int j = 0; j < N; j ++) {
				sum -= max(dist[i][j] - (dist[i][u] + w + dist[v][j]), 0);
				dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][u] + w + dist[v][j]);
			}

		cout << (t == 0 ? "" : " ") << sum;
	}
	cout << endl;

	return 0;
}
