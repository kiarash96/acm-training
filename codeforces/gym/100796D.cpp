#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

#define x first
#define y second

inline bool bet(int a, int b, int c) {
	return a <= b && b < c;
}

const int ACTS = 4;
const int actions[ACTS][2] = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};
queue<pii> Q;

const int MaxNM = 500;
int N, M;
char map[MaxNM][MaxNM];
int type[MaxNM][MaxNM] = {{0}};
int cost[MaxNM][MaxNM] = {{0}};
int C[2];

inline int BFS() {
	type[0][0] = 1; // town
	cost[0][0] = 0;
	Q.push(pii(0, 0));

	while (!Q.empty()) {
		pii p = Q.front();
		Q.pop();

		if (p == pii(M - 1, N - 1))
			return cost[p.x][p.y];

		for (int i = 0; i < ACTS; i ++) {
			pii child(p.x + actions[i][0], p.y + actions[i][1]);
			if (bet(0, child.x, M) && bet(0, child.y, N) && map[child.x][child.y] == '.' && type[child.x][child.y] == 0) {
				type[child.x][child.y] = (type[p.x][p.y])%2 + 1;
				cost[child.x][child.y] = cost[p.x][p.y] + (C[type[p.x][p.y] % 2]);
				Q.push(child);
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> M;
	cin >> C[0] >> C[1];
	for (int i = 0; i < M; i ++)
		for (int j = 0; j < N; j ++)
			cin >> map[i][j];

	int ans = BFS();
	if (ans == -1)
		cout << "IMPOSSIBLE";
	else
		cout << ans;
	cout << endl;

	return 0;
}

