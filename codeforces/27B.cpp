#include <iostream>
using namespace std;

const int MaxN = 50;
int N;
bool matrix[MaxN][MaxN] = {{0}};
bool mark[MaxN] = {0};
int degree[MaxN] = {0};

void DFS(const int v) {
	mark[v] = true;
	for (int i = 0; i < N; i ++)
		if (matrix[v][i] && !mark[i])
			DFS(i);
}

int main() {
	cin >> N;
	for (int i = 1; i < N * (N - 1) / 2; i ++) {
		int u, v;
		cin >> u >> v;
		u --; v --;
		matrix[u][v] = true;
		degree[u] ++; degree[v] ++;
	}

	int cand[2] = {0};
	int found = 0;
	for (int i = 0; i < N; i ++)
		if (degree[i] == N - 2) {
			cand[found] = i;
			found ++;
		}

	DFS(cand[0]);

	if (mark[cand[1]])
		cout << cand[0] + 1 << " " << cand[1] + 1;
	else
		cout << cand[1] + 1 << " " << cand[0] + 1;
	cout << endl;

	return 0;
}
