#include <iostream>
#include <string>
using namespace std;

int N, K;

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> K;

	if (K > N || (N > 1 && K < 2))
		cout << -1;
	else {
		string ans(N, '0');
		for (int i = 0; i < N; i ++)
			ans[i] = (i % 2 ? 'b' : 'a');
		for (int i = N - 1, k = K - 1; i >= 0 && k >= 2; i --, k --)
			ans[i] = 'a' + k;
		cout << ans;
	}
	cout << endl;

	return 0;
}
