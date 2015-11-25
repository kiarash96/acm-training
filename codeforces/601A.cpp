#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MaxN = 400;
int N, M;
int matrix[MaxN][MaxN] = {{0}};
int depth[MaxN];

inline void BFS(const int road) {
	queue<int> Q;
	fill(depth, depth + N, -1);

	Q.push(0);
	depth[0] = 0;

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();

		for (int v = 0; v < N; v ++)
			if (matrix[u][v] == road && depth[v] == -1) {
				Q.push(v);
				depth[v] = depth[u] + 1;
			}
	}
}

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i ++) {
		int u, v;
		cin >> u >> v;
		u --; v --;

		matrix[u][v] = 1;
		matrix[v][u] = 1;
	}

	BFS((matrix[0][N - 1] + 1) % 2);

	cout << depth[N - 1] << endl;

	return 0;
}

