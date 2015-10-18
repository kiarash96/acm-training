#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int N;
vector<pii> points;
vector<bool> mark;

void DFS(const int v) {
	mark[v] = true;
	for (int i = 0; i < N; i ++)
		if ((points[v].first == points[i].first || points[v].second == points[i].second) && !mark[i])
			DFS(i);
}

int main() {
	cin >> N;
	points.resize(N);
	mark.resize(N, false);
	for (int i = 0; i < N; i ++)
		cin >> points[i].first >> points[i].second;

	int ans = 0;
	for (int i = 0; i < N; i ++)
		if (!mark[i]) {
			ans ++;
			DFS(i);
		}

	cout << ans - 1 << endl;

	return 0;
}
