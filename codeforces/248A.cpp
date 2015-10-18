#include <iostream>
#include <algorithm>
using namespace std;

int N;
int c[2] = {0};

int main() {
	cin >> N;
	for (int i = 0; i < N; i ++) {
		int left, right;
		cin >> left >> right;
		c[0] += left;
		c[1] += right;
	}

	cout << min(c[0], N - c[0]) + min(c[1], N - c[1]) << endl;

	return 0;
}
