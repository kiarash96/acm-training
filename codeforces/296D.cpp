#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int MaxN = 500;
const ll INF = 1e12;
int N;
int list[MaxN];
bool mark[MaxN] = {0};
ll dist[MaxN][MaxN];

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++)
			cin >> dist[i][j];
	for (int i = 0; i < N; i ++) {
		cin >> list[i];
		list[i] --;
	}

	vector<ll> ans;
	for (int t = N - 1; t >= 0; t --) {
		int k = list[t];
		mark[k] = true;
		for (int u = 0; u < N; u ++)
			for (int v = 0; v < N; v ++)
				dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);

		ll sum = 0;
		for (int i = 0; i < N; i ++)
			for (int j = 0; j < N; j ++)
				if (mark[i] && mark[j])
					sum += dist[i][j];
		ans.push_back(sum);
	}

	for (int i = N - 1; i >= 0; i --)
		cout << (i == N - 1 ? "" : " ") << ans[i];
	cout << endl;

	return 0;
}
