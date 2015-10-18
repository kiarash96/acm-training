#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

int N;
vector<vector<int> > list;
vector<int> parent, dist;
queue<int> q;

inline vector<int> find_path(const int node) {
	vector<int> res;
	for (int v = node; v != -1; v = parent[v])
		res.push_back(v);
	return res;
}

inline void add(const int node, const int par, const int d) {
	q.push(node);
	parent[node] = par;
	dist[node] = d;
}

int BFS(const int root) {
	q = queue<int>();
	add(root, -1, 0);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < (int) list[node].size(); i ++)
			if (parent[list[node][i]] == -2)
				add(list[node][i], node, dist[node] + 1);
			else if (parent[node] != list[node][i]) {
				vector<int> p1 = find_path(node), p2 = find_path(list[node][i]);
				int start = p1.back();
				while (p1.back() == p2.back()) {
					start = p1.back();
					p1.pop_back(), p2.pop_back();
				}

				int res = numeric_limits<int>::max();
				for (int j = 0; j < (int) p1.size(); j ++)
					res = min(res, dist[p1[j]]);
				for (int j = 0; j < (int) p2.size(); j ++)
					res = min(res, dist[p2[j]]);

				return min(res, dist[start]);
			}
	}

	return 0;
}

int main() {
	cin >> N;
	list.resize(N);
	parent.resize(N);
	dist.resize(N);
	for (int i = 0; i < N; i ++) {
		int u, v;
		cin >> u >> v;
		u --; v --;
		list[u].push_back(v);
		list[v].push_back(u);
	}

	for (int i = 0; i < N; i ++) {
		fill(dist.begin(), dist.end(), 0);
		fill(parent.begin(), parent.end(), -2);
		cout << (i == 0 ? "" : " ") << BFS(i);
	}
	cout << endl;

	return 0;
}
