#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 20;
int N;
int w[MaxN];
int sum = 0, best = 20 * 1e5;

void check(const int ind, const int res) {
	if (ind == N) {
		best = min(best, abs(sum - 2 * res));
		return;
	}

	check(ind + 1, res);
	check(ind + 1, res + w[ind]);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++) {
		cin >> w[i];
		sum += w[i];
	}

	check(0, 0);

	cout << best << endl;

	return 0;
}

