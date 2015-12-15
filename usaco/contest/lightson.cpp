#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define cin fin
#define cout fout

#define pb push_back
#define X first
#define Y second

typedef pair<int, int> pii;

const int ACTS = 4;
int actions[ACTS][2] = {{0, +1}, {0, -1}, {+1, 0}, {-1, 0}};

const int MaxN = 100;

int N, M;
pii dsu[MaxN][MaxN];
int size[MaxN][MaxN];
bool mark[MaxN][MaxN] = {0};
bool lit[MaxN][MaxN] = {0};
vector<pii> list[MaxN][MaxN];

inline bool bet(int a, int b, int c) { return a <= b && b < c; }

inline pii find(pii pos) {
	int x = pos.X, y = pos.Y;
	if (dsu[x][y] != pii(x, y))
		dsu[x][y] = find(dsu[x][y]);
	return dsu[x][y];
}

inline bool isLit(pii pos) {
	pii par = find(pos);
	return lit[par.X][par.Y];
}

inline void join(pii a, pii b) {
	a = find(a);
	b = find(b);

	if (a == b)
		return;

	if (size[a.X][a.Y] > size[b.X][b.Y])
		swap(a, b);

	dsu[a.X][a.Y] = b;
	size[b.X][b.Y] += size[a.X][a.Y];
}

inline void DFS(pii pos) {
	mark[pos.X][pos.Y] = true;
	
	for (pii &child : list[pos.X][pos.Y]) {
		lit[child.X][child.Y] = true;
		for (int i = 0; i < ACTS; i ++) {
			pii neigh(child.X + actions[i][0], child.Y + actions[i][1]);
			if (bet(0, neigh.X, N) && bet(0, neigh.Y, N) && isLit(neigh))
				join(child, neigh);
		}

		if (find(child) == find(pos) && !mark[child.X][child.Y])
			DFS(child);
	}

	for (int i = 0; i < ACTS; i ++) {
		pii neigh(pos.X + actions[i][0], pos.Y + actions[i][1]);
		if (bet(0, neigh.X, N) && bet(0, neigh.Y, N) && isLit(neigh) && !mark[neigh.X][neigh.Y])
			DFS(neigh);
	}
}

int main() {
	ios::sync_with_stdio(0);
	ifstream fin("lightson.in");
	ofstream fout("lightson.out");

	cin >> N >> M;

	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++) {
			dsu[i][j] = pii(i, j);
			size[i][j] = 1;
		}

	for (int i = 0; i < M; i ++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		x --; y --;		a --; b --;
		list[x][y].pb(pii(a, b));
	}

	lit[0][0] = true;
	DFS(pii(0, 0));

	int ans = 0;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++)
			if (isLit(pii(i, j)))
				ans ++;

	cout << ans << endl;

	return 0;
}

