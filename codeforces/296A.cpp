#include <iostream>
#include <cmath>
using namespace std;

const int MaxX = 1000;
int N;
int cnt[MaxX + 1] = {0};

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++) {
		int x;
		cin >> x;
		cnt[x] ++;
	}

	bool ok = true;
	for (int i = 1; i <= MaxX; i ++)
		ok &= (cnt[i] <= ceil(N / 2.0));

	cout << (ok ? "YES" : "NO") << endl;

	return 0;
}
