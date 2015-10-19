#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	ll sum = 0ll;
	for (int i = 0; i < N; i ++) {
		ll x;
		cin >> x;
		sum += x;
	}

	cout << sum << endl;

	return 0;
}

