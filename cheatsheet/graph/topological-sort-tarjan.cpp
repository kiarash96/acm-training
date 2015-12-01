/*
 * Topological sort with Tarjan's algorithm
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define pb push_back

const int MaxN = 100;

int N, E;
vector<int> list[MaxN];

bool mark[MaxN] = {0};
stack<int> order;

inline void DFS(int v) {
	mark[v] = true;
	for (int i = 0; i < (int) list[v].size(); i ++) {
		int u = list[v][i];
		if (!mark[u])
			DFS(u);
	}
	order.push(v);
}

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> E;
	for (int i = 0; i < E; i ++) {
		int u, v;
		cin >> u >> v;
		u --; v --;

		list[u].pb(v);
	}

	for (int i = 0; i < N; i ++)
		if (!mark[i])
			DFS(i);

	for (int i = 0; i < N; i ++) {
		cout << (i == 0 ? "" : " ") << order.top() + 1;
		order.pop();
	}
	cout << endl;

	return 0;
}

