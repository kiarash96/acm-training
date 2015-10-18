#include <iostream>
using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;

	long long ans = 0;
	for (int i = 1; i <= N; i ++)
		ans += (N - i + 1) * (i - 1) + 1;

	cout << ans << endl;

	return 0;
}
