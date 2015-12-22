/*
 * Minimum spanning tree using Kruskal's algorithm
 * Running time: O(ElogE)
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
	int u, v, w;
	inline bool operator< (const Edge &e) const {
		return w < e.w;
	}
};

const int MaxN = 100, MaxE = 5000;

int N, E;
Edge edges[MaxE];
bool belong[MaxE] = {0};
int dsu[MaxN], size[MaxN];

inline int find(int x) { return (x == dsu[x] ? dsu[x] : dsu[x] = find(dsu[x])); }

inline void join(int x, int y) {
	x = find(x), y = find(y);
	if (x == y)
		return;
	if (size[x] > size[y])
		swap(x, y);
	dsu[x] = y;
	size[y] += size[x];
}

inline void kruskal() {
	for (int i = 0; i < N; i ++) {
		dsu[i] = i;
		size[i] = 1;
	}

	sort(edges, edges + E);

	for (int i = 0; i < E; i ++) {
		int u = edges[i].u, v = edges[i].v;
		if (find(u) != find(v)) {
			belong[i] = true;
			join(u, v);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> E;
	for (int i = 0; i < E; i ++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
		edges[i].u --; edges[i].v --;
	}

	kruskal();

	for (int i = 0; i < E; i ++)
		if (belong[i])
			cout << edges[i].u + 1 << " " << edges[i].v + 1 << endl;

	return 0;
}

