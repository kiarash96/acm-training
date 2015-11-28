#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
	int u, v, w;
	inline bool operator< (const Edge &edge) const {
		return w < edge.w;
	}
};

const int MaxN = 1000, MaxE = 15000;
int N, E;
Edge edges[MaxE];
bool belong[MaxE] = {0};
int dsu[MaxN], size[MaxN];
int ans = 0;

inline int find(int x) {
	while (x != dsu[x])
		x = dsu[x];
	return x;
}

inline void join(const int x, const int y) {
	int a = find(x), b = find(y);
	if (a == b)
		return;
	if (size[a] > size[b])
		swap(a, b);
	dsu[a] = b;
	size[b] += size[a];
}

inline void kruskal() {
	sort(edges, edges + E);

	for (int i = 0; i < N; i ++) {
		dsu[i] = i;
		size[i] = 1;
	}

	for (int i = 0; i < E; i ++)
		if (find(edges[i].u) != find(edges[i].v)) {
			belong[i] = true;
			ans = max(ans, edges[i].w);
			join(edges[i].u, edges[i].v);
		}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> E;
	for (int i = 0; i < E; i ++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
		edges[i].u --; edges[i].v --;
	}

	kruskal();

	cout << ans << endl << N - 1 << endl;
	for (int i = 0; i < E; i ++)
		if (belong[i])
			cout << edges[i].u + 1 << " " << edges[i].v + 1 << endl;

	return 0;
}

