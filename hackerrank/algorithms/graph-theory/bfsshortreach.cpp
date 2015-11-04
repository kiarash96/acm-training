#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MaxN = 1000;
int N, M;
int S;
vector<int> list[MaxN];
int depth[MaxN];
queue<int> Q;

inline void BFS(int start) {
	fill(depth, depth + N, -1);

	depth[start] = 0;
	Q.push(start);

	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();

		for (int i = 0; i < (int) list[v].size(); i ++) {
			int u = list[v][i];
			if (depth[u] == -1) {
				depth[u] = depth[v] + 1;
				Q.push(u);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; t ++) {
		for (int i = 0; i < MaxN; i ++)
			list[i].clear();
		cin >> N >> M;
		for (int i = 0; i < M; i ++) {
			int u, v;
			cin >> u >> v;
			u --; v --;
			list[u].push_back(v);
			list[v].push_back(u);
		}

		cin >> S;
		S --;

		BFS(S);

		for (int i = 0; i < N; i ++)
			if (i != S)
				cout << (depth[i] == -1 ? -1 : depth[i] * 6) << " ";
		cout << endl;
	}

	return 0;
}

