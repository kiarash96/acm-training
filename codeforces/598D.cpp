#include <iostream>
#include <vector>
using namespace std;

inline bool bet(int a, int b, int c) {
	return a <= b && b < c;
}

const int ACTS = 4;
const int actions[ACTS][2] = {{0, +1}, {0, -1}, {+1, 0}, {-1, 0}};

const int MaxNM = 1000;
int N, M, K;
int map[MaxNM][MaxNM]; // 0 = wall		1 = passable		other = component number
vector<int> ans(2, 0);

inline void DFS(int x, int y, int cmp) {
	map[x][y] = cmp;
	for (int i = 0; i < ACTS; i ++) {
		int xx = x + actions[i][0], yy = y + actions[i][1];
		if (bet(0, xx, N) && bet(0, yy, M))
			if (map[xx][yy] == 0) // wall
				ans.back() ++;
			else if (map[xx][yy] == 1)
				DFS(xx, yy, cmp);
	}
}

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < M; j ++) {
			char ch;
			cin >> ch;
			map[i][j] = (ch == '.' ? 1 : 0);
		}

	int cmp = 2;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < M; j ++)
			if (map[i][j] == 1) {
				ans.push_back(0);
				DFS(i, j, cmp ++);
			}

	for (int i = 0; i < K; i ++) {
		int x, y;
		cin >> x >> y;
		x --; y --;
		cout << ans[map[x][y]] << endl;
	}
	return 0;
}

