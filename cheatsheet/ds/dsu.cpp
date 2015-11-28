/*
 * Disjoint-Sets union with path compression and ranking.
 */

#include <iostream>
using namespace std;

const int MaxN = 100;

int par[MaxN];
int size[MaxN];

inline int find(int x) {
	if (x != par[x])
		par[x] = find(par[x]);
	return par[x];
}

inline void join(int x, int y) {
	x = find(x), y = find(y);
	if (size[x] > size[y])
		swap(x, y);
	par[x] = y;
	size[y] += size[x];
}

int N;

int main() {
	ios::sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; i ++) {
		par[i] = i;
		size[i] = 1;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i ++) {
		string cmd;
		cin >> cmd;
		
		if (cmd == "find") {
			int x;
			cin >> x;
			x --;
			cout << find(x) + 1 << endl;
		} else if (cmd == "join") {
			int x, y;
			cin >> x >> y;
			x --; y --;
			join(x, y);
		}
	}

	return 0;
}

