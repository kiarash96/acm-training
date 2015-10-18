#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);

	const int N = 5;
	pii pos;

	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++) {
			int x;
			cin >> x;
			if (x == 1)
				pos = pii(i, j);
		}

	cout << abs(pos.first - 2) + abs(pos.second - 2) << endl;

	return 0;
}
