#include <iostream>
using namespace std;

int N, M;

int main() {
	ios::sync_with_stdio(0);

	int ans = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < M; j ++) {
			int x, y;
			cin >> x >> y;
			if (x + y > 0)
				ans ++;
		}

	cout << ans << endl;

	return 0;
}

