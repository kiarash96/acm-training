#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 100;
int N, M;
vector<int> list[MaxN];
bool mark[MaxN] = {0};

void DFS(const int v, const int par) {
	mark[v] = true;
	for (int i = 0; i < (int) list[v].size(); i ++)
		if (!mark[list[v][i]])
			DFS(list[v][i], v);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i ++) {
		int u, v;
		cin >> u >> v;
		u --; v --;
		list[u].push_back(v);
		list[v].push_back(u);
	}

	int cmp = 0;
	for (int i = 0; i < N; i ++)
		if (!mark[i]) {
			cmp ++;
			DFS(i, -1);
		}

	cout << (cmp == 1 && N == M ? "FHTAGN!" : "NO") << endl;

	return 0;
}
