#include <iostream>
#include <cmath>
using namespace std;

const int MaxK = 100;
int N, K;
int count[MaxK] = {0};

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> K;
	for (int i = 0; i < N; i ++) {
		int x;
		cin >> x;
		count[x - 1] ++;
	}

	int ans = 0;
	for (int i = 0; i < K; i ++)
		ans += abs(count[i] - N/K);

	cout << ans/2 << endl;

	return 0;
}

