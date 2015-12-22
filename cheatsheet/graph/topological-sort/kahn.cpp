/*
 * Topological sort with Kahn's algorithm (Queue)
 * Running time: O(|V| + |E|)
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;

int N, E;
vvi list;
vi indegree;

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> E;
	list.resize(N);	indegree.resize(N);
	for (int i = 0; i < E; i ++) {
		int u, v;
		cin >> u >> v;
		u --; v --;

		list[u].pb(v);
		indegree[v] ++;
	}

	queue<int> Q;
	for (int i = 0; i < N; i ++)
		if (indegree[i] == 0)
			Q.push(i);

	vi ans(N);
	int k = 0;
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		ans[k ++] = v;

		for (int u : list[v]) {
			indegree[u] --;
			if (indegree[u] == 0)
				Q.push(u);
		}
	}

	for (int v : ans)
		cout << v << " ";
	cout << endl;

	return 0;
}

