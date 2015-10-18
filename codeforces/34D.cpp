#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MaxN = 5 * 1e4;
int N, R1, R2;
vector<int> list[MaxN];
int par[MaxN];

void DFS(const int v, const int p) {
	par[v] = p;
	for (int i = 0; i < (int) list[v].size(); i ++)
		if (par[list[v][i]] == -2)
			DFS(list[v][i], v);
}

int main() {
	cin >> N >> R1 >> R2;
	R1 --; R2 --;
	for (int i = 0; i < N; i ++) {
		if (i == R1)
			continue;
		int u;
		cin >> u;
		u --;
		list[i].push_back(u);
		list[u].push_back(i);
	}

	fill(par, par + N, -2);
	DFS(R2, -1);

	int k = 0;
	for (int i = 0; i < N; i ++)
		if (i != R2)
			cout << (k ++ == 0 ? "" : " ") << par[i] + 1;
	cout << endl;

	return 0;
}
