#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int, int> pii;

const int MaxN = 1000, INF = 1e6 + 10;
int N, E;
vector<pii> list[MaxN];
vector<pii> edges;
int dist[MaxN], par[MaxN];
bool mark[MaxN] = {0};
int ans = 0;

inline bool cmp(const int u, const int v) {
	if (dist[u] != dist[v])
		return dist[u] < dist[v];
	return u < v;
}

set<int, bool(*)(const int, const int)> S(cmp);

inline void relax(const int u, const int v, const int w) {
	if (!mark[v] && w < dist[v]) {
		S.erase(v);
		dist[v] = w;
		par[v] = u;
		S.insert(v);
	}
}

inline void prim() {
	fill(dist, dist + N, INF);
	fill(par, par + N, -1);

	dist[0] = 0;
	mark[0] = true;
	S.insert(0);

	while (!S.empty()) {
		int v = *S.begin();
		mark[v] = true;
		S.erase(S.begin());

		ans = max(ans, dist[v]);

		for (int i = 0; i < (int) list[v].size(); i ++)
			relax(v, list[v][i].first, list[v][i].second);
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

	prim();

	cout << ans << endl << N - 1 << endl;
	for (int i = 1; i < N; i ++)
		cout << par[i] + 1 << " " << i + 1 << endl;

	return 0;
}

