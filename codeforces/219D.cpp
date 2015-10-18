#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MaxN = 2 * 1e5;
int N;
vector<pair<int, bool> > list[MaxN];
int par[MaxN];
int color[MaxN][2]; // Colors on path from root
int res[MaxN][2];
int tot[2] = {0};

void DFS(const int v, const int p, int edge) {
	par[v] = p;
	for (int i = 0; i < 2; i ++)
		color[v][i] = (p == -1 ? 0 : color[p][i]);
	if (edge != -1) {
		color[v][edge] ++;
		tot[edge] ++;
	}
	
	for (int i = 0; i < (int) list[v].size(); i ++)
		if (par[list[v][i].first] == -2)
			DFS(list[v][i].first, v, list[v][i].second);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --; v --;
		list[u].push_back(make_pair(v, 0));
		list[v].push_back(make_pair(u, 1));
	}

	fill(par, par + N, -2);
	DFS(0, -1, -1);

	int ans = MaxN;

	for (int i = 0; i < N; i ++) {
		res[i][0] = tot[0]; res[i][1] = tot[1];
		for (int j = 0; j < 2; j ++) {
			res[i][j] -= color[i][j];
			res[i][j] += color[i][!j];
		}

		ans = min(ans, res[i][1]);
	}

	cout << ans << endl;
	int k = 0;
	for (int i = 0; i < N; i ++)
		if (res[i][1] == ans)
			cout << (k ++ == 0 ? "" : " ") << i + 1;
	cout << endl;

	return 0;
}
