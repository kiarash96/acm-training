/*
 * Floyd-Warshall all-pairs shortest path algorithm
 * Running time: O(|V|^3)
 */

#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

typedef pair<int, int> pii;

const int MaxN = 100;
const int INF = 1e9;

int N, E;
vector<pii> list[MaxN];
int sp[MaxN][MaxN];

inline void floyd_warshall() {
	for (int v = 0; v < N; v ++)
		for (int u = 0; u < N; u ++)
			sp[v][u] = INF;
	for (int v = 0; v < N; v ++) {
		sp[v][v] = 0;
		for (int i = 0; i < (int) list[v].size(); i ++)
			sp[v][list[v][i].first] = list[v][i].second;
	}

	for (int k = 0; k < N; k ++)
		for (int i = 0; i < N; i ++)
			for (int j = 0; j < N; j ++)
				sp[i][j] = min(sp[i][j], sp[i][k] + sp[k][j]);
}

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> E;
	for (int i = 0; i < E; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --; v --;

		list[u].pb(pii(v, w));
		list[v].pb(pii(u, w));
	}

	floyd_warshall();

	int u, v;
	while (cin >> u >> v)
		cout << sp[u - 1][v -1] << endl;

	return 0;
}

