#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MaxN = 1000, MaxD = 1e6;
int N, P;
vector<pii> list[MaxN];
int degree[MaxN] = {0};
bool mark[MaxN] = {0};
vector<pii> ans;

void DFS(const int v) {
	mark[v] = true;
	ans.back().first = v;

	for (int i = 0; i < (int) list[v].size(); i ++)
		if (!mark[list[v][i].first]) {
			ans.back().second = min(ans.back().second, list[v][i].second);
			DFS(list[v][i].first);
		}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> P;
	for (int i = 0; i < P; i ++) {
		int u, v, d;
		cin >> u >> v >> d;
		u --; v --;
		list[u].push_back(pii(v, d));
		degree[u] ++;
		degree[v] ++;
	}
	
	vector<int> start;
	for (int i = 0; i < N; i ++)
		if (list[i].size() == 1 && degree[i] == 1)
			start.push_back(i);

	for (int i = 0; i < (int) start.size(); i ++)
		if (!mark[start[i]]) {
			ans.push_back(pii(start[i], MaxD));
			DFS(start[i]);
		}

	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i ++)
		cout << start[i] + 1 << " " << ans[i].first + 1 << " " << ans[i].second << endl;

	return 0;
}
