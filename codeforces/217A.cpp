#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int N;
vector<vector<int> > list;
vector<int> dist;

void DFS(const int node, const int d) {
	dist[node] = d;
	for (int i = 0; i < (int) list[node].size(); i ++)
		DFS(list[node][i], d + 1);
}

int main() {
	cin >> N;
	list.resize(N);
	dist.resize(N, -1);
	for (int i = 0; i < N; i ++) {
		int par;
		cin >> par;
		if (par == -1)
			dist[i] = 0;
		else {
			par --;
			list[par].push_back(i);
		}
	}

	for (int i = 0; i < N; i ++)
		if (dist[i] == 0)
			DFS(i, 0);

	int ans = numeric_limits<int>::min();
	for (int i = 0; i < N; i ++)
		ans = max(ans, dist[i]);

	cout << ans + 1<< endl;

	return 0;
}
