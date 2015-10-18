#include <iostream>
#include <cmath>
using namespace std;

const int MaxN = 100, MOD = (1 << 30);
int d[MaxN * MaxN * MaxN + 1];
int A, B, C;

inline int calc(const int n) {
	if (d[n] != 0)
		return d[n];

	int res = 0, root = sqrt(n);
	for (int i = 1; i <= root; i ++)
		if (n % i == 0)
			res += 2;

	if (root * root == n)
		res --;

	d[n] = res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> A >> B >> C;

	int ans = 0;
	for (int i = 1; i <= A; i ++)
		for (int j = 1; j <= B; j ++)
			for (int k = 1; k <= C; k ++)
				ans = (ans + calc(i * j * k)) % MOD;

	cout << ans << endl;

	return 0;
}
