#include <iostream>
using namespace std;

typedef long long ll;

const int MaxN = 2 * 1e5 + 1;
int N;
int arr[MaxN], mark[2][MaxN] = {{0}};
ll ans[2][MaxN];
int step = 0;

void DFS(const int s, const int i) {
	mark[s][i] = step;

	int x = i, y = arr[x];
	x += (s == 0 ? 1 : -1) * arr[x];

	if (x <= 0 || x > N)
		ans[s][i] = y;
	else {
		int next = (s + 1) % 2;
		if (mark[next][x] == step)
			ans[s][i] = -1;
		else {
			if (ans[next][x] == -2)
				DFS(next, x);

			if (ans[next][x] == -1)
				ans[s][i] = -1;
			else
				ans[s][i] = y + ans[next][x];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 2; i <= N; i ++)
		cin >> arr[i];

	for (int s = 0; s < 2; s ++)
		for (int i = 1; i <= N; i ++)
			ans[s][i] = -2;
	ans[0][1] = ans[1][1] = -1;

	for (int s = 0; s < 2; s ++)
		for (int i = 2; i <= N; i ++)
			if (ans[s][i] == -2) {
				step ++;
				DFS(s, i);
			}

	for (int i = 1; i < N; i ++) {
		int x = 1 + i;
		if (x <= 0 || x > N)
			cout << i;
		else if (ans[1][x] == -1)
			cout << -1;
		else
			cout << i + ans[1][x];
		cout << endl;
	}

	return 0;
}
