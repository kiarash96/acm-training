#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t ++) {
		int a;
		cin >> a;
		cout << (360 % (180 - a) == 0 ? "YES" : "NO") << endl;
	}

	return 0;
}
