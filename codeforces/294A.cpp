#include <iostream>
using namespace std;

const int MaxN = 100;
int N, M;
int cnt[MaxN];

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++)
		cin >> cnt[i];

	cin >> M;
	for (int i = 0; i < M; i ++) {
		int x, y; // yth from the xth wire
		cin >> x >> y;
		x --;

		if (x - 1 >= 0)
			cnt[x - 1] += y - 1;
		if (x + 1 < N)
			cnt[x + 1] += cnt[x] - y;
		cnt[x] = 0;
	}

	for (int i = 0; i < N; i ++)
		cout << cnt[i] << endl;

	return 0;
}
