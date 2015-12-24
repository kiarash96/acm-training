/*
 * Dijkstra single source shortest path algorithm.
 * Running time: O(nlogn)
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair

typedef pair<int, int> pii;

const int MaxN = 1000;
const int INF = 1000 * 1000 * 1000;

int N, E;
vector<pii> list[MaxN];
int dist[MaxN];
int par[MaxN];

set<pii> S;

inline bool relax(int u, int w, int v) {
	if (dist[u] + w < dist[v]) {
		S.erase(mp(dist[v], v));
		dist[v] = dist[u] + w;
		par[v] = u;
		S.insert(mp(dist[v], v));
		return true;
	}
	return false;
}

inline void dijkstra(int src) {
	fill(dist, dist + N, INF);
	fill(par, par + N, -2);

	dist[src] = 0;
	par[src] = -1;
	S.insert(mp(0, src));

	while (!S.empty()) {
		int v = S.begin()->second;
		S.erase(S.begin());

		for (pii edge : list[v])
			relax(v, edge.second, edge.first);
	}
}

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> E;
	for (int i = 0; i < E; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --; v --;

		list[u].eb(v, w);
		list[v].eb(u, w);
	}

	int src;
	cin >> src;
	src --;

	dijkstra(src);

	return 0;
}

