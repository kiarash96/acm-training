#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MaxN = 1e5;
int N, M, K;
vector<int> list[MaxN];
bool mark[MaxN] = {0};
bool edge[MaxN] = {0};
vector<int> path;

void DFS(const int v) {
	mark[v] = true;
	path.push_back(v);

	for (int i = 0; i < (int) list[v].size(); i ++)
		if (!mark[list[v][i]]) {
			DFS(list[v][i]);
			break;
		}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i ++) {
		int u, v;
		cin >> u >> v;
		u --; v --;
		list[u].push_back(v);
		list[v].push_back(u);
	}

	DFS(0);

	for (int i = 0; i < (int) list[path.back()].size(); i ++)
		edge[list[path.back()][i]] = true;

	int end = 0;
	while (!edge[path[end]])
		end ++;

	cout << path.size() - end << endl;
	for (int i = path.size() - 1; i >= end; i --)
		cout << (i == (int) path.size() - 1 ? "" : " ") << path[i] + 1;
	cout << endl;

	return 0;
}
