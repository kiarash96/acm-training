#include <iostream>
#include <queue>
using namespace std;

const int MAX_FIGHTS = 39916800;
queue<int> A, B;

int main() {
	ios::sync_with_stdio(false);

	int n, k1, k2;
	cin >> n;

	cin >> k1;
	for (int i = 0; i < k1; i ++) {
		int x;
		cin >> x;
		A.push(x);
	}

	cin >> k2;
	for (int i = 0; i < k2; i ++) {
		int x;
		cin >> x;
		B.push(x);
	}

	int fights = 0;
	while (++ fights) {
		int x = A.front(), y = B.front();
		A.pop();
		B.pop();

		if (x > y) {
			A.push(y);
			A.push(x);
		} else { // y > x
			B.push(x);
			B.push(y);
		}

		if (A.size() == 0) {
			cout << fights << " " << "2" << endl;
			break;
		} else if (B.size() == 0) {
			cout << fights << " " << "1" << endl;
			break;
		}

		if (fights > MAX_FIGHTS) {
			cout << -1 << endl;
			break;
		}
	}

	return 0;
}

