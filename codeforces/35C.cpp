#include <iostream>
#include <queue>
#include <utility>
#include <cstdio>
using namespace std;

typedef pair<int, int> pii;

const int ACTS = 4;
const int actions[ACTS][2] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
const int MaxNM = 2000;
int N, M, K;
bool mark[MaxNM][MaxNM] = {{0}};
queue<pii> Q;
pii last;

inline bool bet(const int value, const int begin, const int end) {
	return begin <= value && value < end;
}

inline void add(const pii &p) {
	mark[p.first][p.second] = true;
	Q.push(p);
	last = p;
}

inline void BFS() {
	while (!Q.empty()) {
		pii p = Q.front();
		Q.pop();

		for (int i = 0; i < ACTS; i ++) {
			pii child(p.first + actions[i][0], p.second + actions[i][1]);
			if (bet(child.first, 0, N) && bet(child.second, 0, M) && !mark[child.first][child.second])
				add(child);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i ++) {
		int x, y;
		cin >> x >> y;
		x --; y --;
		add(pii(x, y));
	}

	BFS();

	cout << last.first + 1 << " " << last.second + 1 << endl;

	return 0;
}
