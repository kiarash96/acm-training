#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e11;
const int MaxN = 1e5;
int N, E;
vector<pii> list[MaxN];
int par[MaxN];
ll dist[MaxN];

inline bool cmp(const int u, const int v) {
	if (dist[u] != dist[v])
		return dist[u] < dist[v];
	return u < v;
}

set<int, bool(*)(const int, const int)> S(cmp);

inline bool relax(const int u, const int w, const int v) {
	if (dist[u] + w < dist[v]) {
		S.erase(v);
		dist[v] = dist[u] + w;
		par[v] = u;
		S.insert(v);
		return true;
	}
	return false;
}

inline void dijkstra(const int root) {
	fill(dist, dist + N, INF);
	fill(par, par + N, -2);

	dist[root] = 0;
	par[root] = -1;
	S.insert(root);

	while (!S.empty()) {
		int v = *S.begin();
		S.erase(S.begin());
		for (int i = 0; i < (int) list[v].size(); i ++)
			relax(v, list[v][i].second, list[v][i].first);
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> E;
	for (int i = 0; i < E; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --; v --;
		list[u].push_back(pii(v, w));
		list[v].push_back(pii(u, w));
	}

	dijkstra(0);

	N --;
	if (par[N] == -2)
		cout << -1;
	else {
		vector<int> path;
		for (int v = N; v != -1; v = par[v])
			path.push_back(v);
		for (int i = path.size() - 1; i >= 0; i --)
			cout << (i == (int) path.size() - 1 ? "" : " ") << path[i] + 1;
	}
	cout << endl;

	return 0;
}
