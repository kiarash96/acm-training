#include <iostream>
#include <iomanip>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i ++) {
		ll l, r;
		cin >> l >> r;
		cout << fixed << setprecision(10) << (long double)r/(r+1) - (long double)(l-1)/l << endl;
	}

	return 0;
}

