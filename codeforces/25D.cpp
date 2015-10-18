#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MaxN = 1000;
int N;
vector<int> list[MaxN];
int depth[MaxN] = {0};

int cmp_count = 0;
vector<pii> edges;
int cand[MaxN];

void DFS(const int v, const int par, const int d) {
	depth[v] = d;
	cand[cmp_count] = v;

	for (int i = 0; i < (int) list[v].size(); i ++)
		if (depth[list[v][i]] == -1)
			DFS(list[v][i], v, d + 1);
		else if (list[v][i] != par && depth[v] > depth[list[v][i]])
			edges.push_back(pii(v, list[v][i]));
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --; v --;
		list[u].push_back(v);
		list[v].push_back(u);
	}

	fill(depth, depth + N, -1);

	for (int i = 0; i < N; i ++)
		if (depth[i] == -1) {
			DFS(i, -1, 0);
			cmp_count ++;
		}

	cout << cmp_count - 1 << endl;
	for (int i = 1; i < cmp_count; i ++)
		cout << edges[i - 1].first + 1 << " " << edges[i - 1].second + 1 << " " << cand[0] + 1 << " " << cand[i] + 1 << endl;

	return 0;
}
