#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	int sum = 0;
	for (int i = 0; i < N; i ++) {
		int x;
		cin >> x;
		sum += x;
	}

	cout << sum << endl;

	return 0;
}

