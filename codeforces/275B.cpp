#include <iostream>
#include <utility>
#include <string>
using namespace std;

#define x first
#define y second

typedef pair<int, int> pii;

const int MaxNM = 50, INF = 2;
int N, M;

const int ACTS = 4;
const int actions[ACTS][2] = {{0, -1}, {0, +1}, {-1, 0}, {+1, 0}};

string table[MaxNM];
int mark[MaxNM][MaxNM];

inline bool bet(const int value, const int begin, const int end) {
	return begin <= value && value < end;
}

inline void work(const pii &p, const int d, const int m) {
	for (int k = 1; ; k ++) {
		pii child(p.x + actions[d][0] * k, p.y + actions[d][1] * k);
		if (!bet(child.x, 0, N) || !bet(child.y, 0, M) || table[child.x][child.y] == 'W')
			break;
		mark[child.x][child.y] = min(mark[child.x][child.y], m);
	}
}

inline bool check(const pii &start) {
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < M; j ++)
			mark[i][j] = INF;

	mark[start.x][start.y] = 0;
	for (int i = 0; i < ACTS; i ++)
		work(start, i, 0);

	for (int x = 0; x < N; x ++)
		for (int y = 0; y < M; y ++) {
			if (mark[x][y] == 0)
				for (int i = 0; i < ACTS; i ++)
					work(pii(x, y), i, 1);
		}

	for (int i = 0; i < N; i ++)
		for (int j = 0; j < M; j ++)
			if (table[i][j] == 'B' && mark[i][j] > 1)
				return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i ++)
		cin >> table[i];

	bool ans = true;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < M; j ++)
			if (table[i][j] == 'B' && !check(pii(i, j)))
				ans = false;

	cout << (ans ? "YES" : "NO") << endl;

	return 0;
}
