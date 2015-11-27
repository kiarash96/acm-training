#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while (T --) {
		int N;
		cin >> N;

		int S1 = N*(N + 1)/2;
		int S3 = N*(N + 1);
		int S2 = N*(N - 1) + N;

		cout << S1 << " " << S2 << " " << S3 << endl;
	}

	return 0;
}

