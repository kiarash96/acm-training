#include <iostream>
using namespace std;

const int MaxN = 1000;
int N;
int A[MaxN];
bool mark[MaxN];

int main() {
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i ++) {
		cin >> A[i];
		mark[i] = false;
	}

	int ans = 0;
	int pos = 0, got = 0, dir = +1;
	while (got < N) {
		if (mark[pos] == false && A[pos] <= got) {
			got ++;
			mark[pos] = true;
		}

		bool found = false;
		for (int i = pos; 0 <= i && i < N; i += dir)
			if (!mark[i] && A[i] <= got) {
				found = true;
				break;
			}

		if (!found) {
			dir *= -1;
			ans ++;
		}

		pos += dir;
	}

	cout << ans - 1 << endl;

	return 0;
}

