#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);

	ll X[2] = {0, 0};
	for (int k = 0; k < 2; k ++) {
		int N, B;
		cin >> N >> B;
		for (int i = 0; i < N; i ++) {
			int d;
			cin >> d;
			X[k] = X[k] * B + d;
		}
	}

	if (X[0] < X[1])
		cout << "<";
	else if (X[0] == X[1])
		cout << "=";
	else
		cout << ">";
	cout << endl;

	return 0;
}

