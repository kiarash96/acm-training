#include <iostream>
#include <vector>
using namespace std;

int N, E;
vector<vector<int> > list;
vector<int> indegree;

int main() {
	cin >> N >> E;
	list.resize(N);
	indegree.resize(N, 0);
	for (int i = 0; i < E; i ++) {
		int u, v;
		cin >> u >> v;
		u --; v --;
		list[u].push_back(v);
		indegree[v] ++;
	}

	bool ok = true;
	for (int i = 0; i < N; i ++) {
		int v;
		cin >> v;
		v --;

		if (indegree[v] == 0)
			for (int j = 0; j < (int) list[v].size(); j ++)
				indegree[list[v][j]] --;
		else
			ok = false;
	}

	cout << (ok ? "YES" : "NO") << endl;

	return 0;
}

