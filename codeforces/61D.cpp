#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MaxN = 1e5;
int N;
vector<pii> list[MaxN];
ll total = 0, best = 0;

void DFS(const int v, const int p, const ll cost) {
	bool leaf = true;
	for (int i = 0; i < (int) list[v].size(); i ++)
		if (list[v][i].first != p) {
			leaf = false;
			DFS(list[v][i].first, v, cost + list[v][i].second);
		}

	if (leaf)
		best = max(best, cost);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --; v --;
		list[u].push_back(pii(v, w));
		list[v].push_back(pii(u, w));
		total += w;
	}

	DFS(0, -1, 0);

	cout << 2 * total - best << endl;

	return 0;
}
