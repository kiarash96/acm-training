#include <iostream>
using namespace std;

int N, K;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	if (3 * K > N)
		cout << -1;
	else {
		int seg = 0;
		for (int i = 0; i < N; i ++) {
			if (i % K == 0)
				seg ++;
			cout << (i == 0 ? "" : " ") << (seg == 1 ? (i + 1) % K : i % K) + 1;
		}
	}
	cout << endl;

	return 0;
}
