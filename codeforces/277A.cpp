#include <iostream>
#include <vector>
using namespace std;

const int MaxNM = 100;
int N, M;
bool mark[2 * MaxNM] = {0};
vector<int> list[2 * MaxNM];

void DFS(const int v) {
	mark[v] = true;
	for (int i = 0; i < (int) list[v].size(); i ++)
		if (!mark[list[v][i]])
			DFS(list[v][i]);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int u = 0; u < N; u ++) {
		int s;
		cin >> s;
		for (int i = 0; i < s; i ++) {
			int v;
			cin >> v;
			v = v + N - 1;
			list[u].push_back(v);
			list[v].push_back(u);
		}
	}

	int cmp = 0;
	for (int v = 0; v < N + M; v ++)
		if (!mark[v]) {
			DFS(v);
			cmp ++;
		}

	bool has = false;
	for (int i = N; i < N + M; i ++)
		if (list[i].size() == 0)
			cmp --;
		else
			has = true;

	cout << (has ? cmp - 1 : cmp) << endl;

	return 0;
}
