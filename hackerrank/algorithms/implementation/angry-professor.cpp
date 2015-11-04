#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t ++) {
		int N, K;
		cin >> N >> K;

		int present = 0;
		for (int i = 0; i < N; i ++) {
			int x;
			cin >> x;

			if (x <= 0)
				present ++;
		}

		cout << (present >= K ? "NO" : "YES") << endl;
	}

	return 0;
}

