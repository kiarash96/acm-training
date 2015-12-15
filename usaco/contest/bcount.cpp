#include <bits/stdc++.h>
using namespace std;

#define cin fin
#define cout fout

const int MaxN = 1e5;

int N, M;
int cnt[MaxN][3];

int main() {
	ios::sync_with_stdio(0);
	ifstream fin("bcount.in");
	ofstream fout("bcount.out");

	cin >> N >> M;
	for (int i = 0; i < N; i ++) {
		int x;
		cin >> x;
		x --;

		if (i == 0) {
			cnt[0][0] = 0;
			cnt[0][1] = 0;
			cnt[0][2] = 0;
			
			cnt[0][x] ++;
		} else {
			cnt[i][0] = cnt[i - 1][0];
			cnt[i][1] = cnt[i - 1][1];
			cnt[i][2] = cnt[i - 1][2];

			cnt[i][x] ++;
		}
	}

	for (int i = 0; i < M; i ++) {
		int a, b;
		cin >> a >> b;
		a --; b --;

		for (int t = 0; t < 3; t ++)
			cout << (t == 0 ? "" : " ") << cnt[b][t] - (a > 0 ? cnt[a - 1][t] : 0);
		cout << endl;
	}

	return 0;
}

