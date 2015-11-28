#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MaxN = 100;
int N;
vector<int> list[MaxN];
int color[MaxN];

void DFS(const int v, const int c) {
	color[v] = c;
	for (int i = 0; i < (int) list[v].size(); i ++)
		if (color[list[v][i]] == -1)
			DFS(list[v][i], (c + 1) % 2);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int u = 0; u < N; u ++) {
		int v;
		while (cin >> v && v != 0) {
			v --;
			list[u].push_back(v);
			list[v].push_back(u);
		}
	}

	fill(color, color + N, -1);
	for (int v = 0; v < N; v ++)
		if (color[v] == -1)
			DFS(v, 0);

	bool ok = true;
	vector<int> ans;

	for (int v = 0; v < N; v ++) {
		if (list[v].size() == 0)
			ok = false;

		if (color[v] == 0)
			ans.push_back(v);
	}

	if (ok) {
		cout << ans.size() << endl;
		for (int i = 0; i < (int) ans.size(); i ++)
			cout << (i == 0 ? "" : " ") << ans[i] + 1;
		cout << endl;
	} else
		cout << 0 << endl;

	return 0;
}

