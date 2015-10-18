#include <iostream>
using namespace std;

const int MaxN = 1e5;
int N, M;
int d[MaxN] = {0};

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i ++) {
		int u, v;
		cin >> u >> v;
		u --; v --;
		d[u] ++; d[v] ++;
	}

	int cnt[3] = {0}; // 1, 2, n - 1
	for (int i = 0; i < N; i ++)
		if (d[i] == 1)
			cnt[0] ++;
		else if (d[i] == 2)
			cnt[1] ++;
		else if (d[i] == N - 1)
			cnt[2] ++;

	if (cnt[0] == 2 && cnt[1] == N - 2)
		cout << "bus";
	else if (cnt[1] == N)
		cout << "ring";
	else if (cnt[2] == 1 && cnt[0] == N - 1)
		cout << "star";
	else
		cout << "unknown";
	cout << " topology" << endl;

	return 0;
}
