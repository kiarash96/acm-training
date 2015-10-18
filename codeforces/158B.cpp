#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int c[5] = {0};

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++) {
		int s;
		cin >> s;
		c[s] ++;
	}

	int m = min(c[1], c[3]);
	
	int ans = c[2] / 2 + m;
	c[1] -= m;
	c[3] -= m;
	c[2] %= 2;
	ans += c[1] / 4; c[1] %= 4;

	m = min(c[1], c[2]);
	if (m > 0 && c[1] > 1) {
		ans += (c[1] + 2 * c[2]) / 4.0;
		c[1] -= 2;
		c[2] --;
	}
	m = min(c[1], c[2]);
	ans += m;
	c[1] -= m; c[2] -= m;

	cout << ans + (c[1] > 0 ? 1 : 0) + c[2] + c[3] + c[4] << endl;

	return 0;
}
