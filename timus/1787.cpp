#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int K, N, cars = 0;
	cin >> K >> N;
	
	for (int i = 0; i < N; i ++) {
		int x;
		cin >> x;
		cars = max(0, cars - K);
		cars += x;
	}

	cout << max(0, cars - K) << endl;

	return 0;
}

