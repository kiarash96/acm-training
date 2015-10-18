#include <iostream>
#include <vector>
using namespace std;

int N, E;
vector<vector<int> > list;
vector<int> color;

void DFS(const int vertex, const int c) {
	color[vertex] = c;

	for (int i = 0; i < (int) list[vertex].size(); i ++)
		if (color[list[vertex][i]] == -1)
			DFS(list[vertex][i], (c + 1) % 2);
}

int main() {
	cin >> N >> E;
	list.resize(N);
	color.resize(N, -1);
	for (int i = 0; i < E; i ++) {
		int u, v;
		cin >> u >> v;
		u --; v --;
		list[u].push_back(v);
		list[v].push_back(u);
	}

	for (int i = 0; i < N; i ++)
		if (color[i] == -1)
			DFS(i, 0);

	int ans = 0;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < (int) list[i].size(); j ++)
			if (color[i] == color[list[i][j]])
				ans ++;

	ans /= 2;
	cout << ((N - ans) % 2 == 0 ? ans : ans + 1) << endl;

	return 0;
}
