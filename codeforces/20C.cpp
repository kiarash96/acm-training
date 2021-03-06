#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int MaxN = 100 * 1000;
const ll INF = 1000 * 1000 * 1000 * 1000ll;

int N, E;
vector<pii> list[MaxN];
ll dist[MaxN];
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

	dijkstra(0);

	if (par[N - 1] == -2)
		cout << -1 << endl;
	else {
		vector<int> path;
		for (int v = N - 1; v != -1; v = par[v])
			path.pb(v);
		for (int i = (int) path.size() - 1; i >= 0; i --)
			cout << path[i] + 1 << " ";
		cout << endl;
	}

	return 0;
}

