#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	ll a, b;
	cin >> a >> b;

	ll count = 0;
	while (a != 0 && b != 0) {
		if (a < b)
			swap(a, b);
		
		ll n = a / b;

		count += n;
		a -= b*n;
	}

	cout << count << endl;

	return 0;
}
