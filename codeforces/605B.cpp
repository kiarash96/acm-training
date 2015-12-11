#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int id;
	bool belong;
	int u, v, w;
	bool operator< (Edge &e) {
		if (w != e.w)
			return w < e.w;
//		return belong;
		return (belong && !e.belong);
	}
};

bool byid(Edge &e1, Edge &e2) {
	return e1.id < e2.id;
}

const int MaxN = 1e5, MaxE = 1e5;

int N, E;
Edge edges[MaxE];

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> E;
	for (int i = 0; i < E; i ++) {
		int b;
		edges[i].id = i;
		cin >> edges[i].w >> b;
		edges[i].belong = (b == 0 ? false : true);
	}

	sort(edges, edges + E);

	int end = 0;
	int u = 0, v = 2; // available
	for (int i = 0; i < E; i ++)
		if (edges[i].belong) {
			edges[i].u = end;	edges[i].v = ++ end;
		} else {
			if (v > end) {
				cout << -1 << endl;
				return 0;
			} else {
				edges[i].u = u; edges[i].v = v;
				if (u + 2 == v) {
					u = 0; v ++;
				} else
					u ++;
			}
		}

	sort(edges, edges + E, byid);
	for (int i = 0; i < E; i ++)
		cout << edges[i].u + 1 << " " << edges[i].v + 1 << endl;

	return 0;
}

