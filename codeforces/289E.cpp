#include <iostream>
using namespace std;

typedef long long ll;

const int MaxN = 1e6;
int N;
int ans[MaxN + 1] = {0};

int complement(const int x) {
	int p = 1;
	while (p <= x)
		p *= 2;
	return (p - 1) ^ x;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = N; i >= 0; i --)
		if (ans[i] == 0) {
			int x = complement(i);
			ans[i] = x;
			ans[x] = i;
		}

	ll b = 0LL;
	for (int i = 0; i <= N; i ++)
		b += i ^ ans[i];

	cout << b << endl;
	for (int i = 0; i <= N; i ++)
		cout << (i == 0 ? "" : " ") << ans[i];
	cout << endl;

	return 0;
}
