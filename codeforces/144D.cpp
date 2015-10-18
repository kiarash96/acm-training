#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int, int> pii;

const int MaxN = 1e5, MaxSP = 1e9;
int N, M, S, L;
vector<pii> list[MaxN];
int sp[MaxN];

bool cmp(const int u, const int v) {
	if (sp[u] != sp[v])
		return sp[u] < sp[v];
	return u < v;
}

set<int, bool(*)(const int, const int)> pq(cmp);

void dijkstra() {
	fill(sp, sp + N, MaxSP);
	
	sp[S] = 0;
	pq.insert(S);

	while (!pq.empty()) {
		int v = *pq.begin();
		pq.erase(v);

		for (int i = 0; i < (int) list[v].size(); i ++) {
			int u = list[v][i].first;
			int new_sp = sp[v] + list[v][i].second;
			if (new_sp < sp[u]) {
				pq.erase(u);
				sp[u] = new_sp;
				pq.insert(u);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> S; S--;

	for (int i = 0; i < M; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --; v --;
		list[u].push_back(pii(v, w));
		list[v].push_back(pii(u, w));
	}
	cin >> L;

	dijkstra();

	int ans = 0, dup = 0;
	for (int v = 0; v < N; v ++) {
		if (sp[v] < L) {
			for (int i = 0; i < (int) list[v].size(); i ++)
				if (sp[v] + list[v][i].second > L && L <= sp[list[v][i].first] + list[v][i].second - L + sp[v]) {
					ans ++;
					if (L == sp[list[v][i].first] + list[v][i].second - L + sp[v])
						dup ++;
				}
		} else if (sp[v] == L)
			ans ++;
	}

	cout << ans - dup/2 << endl;

	return 0;
}
