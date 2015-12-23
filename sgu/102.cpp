#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	int ans = 0;
	for (int i = 1; i <= N; i ++)
		if (__gcd(i, N) == 1)
			ans ++;

	cout << ans << endl;

	return 0;
}

