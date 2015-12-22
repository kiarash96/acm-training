/*
 * Topological sort with Tarjan's algorithm (Reverse post-order)
 * Running time: O(|V| + |E|)
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;

int N, E;
vvi list;

vector<bool> mark;
stack<int> order;

inline void DFS(int v) {
	mark[v] = true;
	for (int u : list[v])
		if (!mark[u])
			DFS(u);
	order.push(v);
}

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> E;
	list.resize(N);
	for (int i = 0; i < E; i ++) {
		int u, v;
		cin >> u >> v;
		u --; v --;

		list[u].pb(v);
	}

	mark.resize(N, false);
	for (int i = 0; i < N; i ++)
		if (!mark[i])
			DFS(i);

	for (int i = 0; i < N; i ++) {
		cout << order.top() + 1 << " ";
		order.pop();
	}
	cout << endl;

	return 0;
}

