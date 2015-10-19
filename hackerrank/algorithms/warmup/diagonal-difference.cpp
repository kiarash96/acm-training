#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++) {
			int x;
			cin >> x;

			if (i == j)
				sum1 += x;
			if (i == N - j - 1)
				sum2 += x;
		}

	cout << abs(sum2 - sum1) << endl;

	return 0;
}

