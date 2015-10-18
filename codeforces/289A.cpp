#include <iostream>
using namespace std;

typedef long long ll;

int N, K;
ll value = 0LL;

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < N; i ++) {
		int a, b;
		cin >> a >> b;
		value += b - a + 1;
	}

	cout << (value % K == 0 ? 0 : K - (value % K)) << endl;

	return 0;
}
