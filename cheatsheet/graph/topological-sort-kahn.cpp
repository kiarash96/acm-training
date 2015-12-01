/*
 * Topological sort with Kahn's algorithm
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define pb push_back

const int MaxN = 100;

int N, E;
vector<int> list[MaxN];
int indegree[MaxN];

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> E;
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

	vector<int> ans;
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		ans.pb(v);

		for (int i = 0; i < (int) list[v].size(); i ++) {
			int u = list[v][i];
			indegree[u] --;
			if (indegree[u] == 0)
				Q.push(u);
		}
	}

	for (int i = 0; i < N; i ++)
		cout << (i == 0 ? "" : " ") << ans[i] + 1;
	cout << endl;

	return 0;
}

