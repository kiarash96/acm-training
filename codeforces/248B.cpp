#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int ans[10] = {0, 0, 0, 210, 50, 80, 170, 20, 200, 110};
int len[10] = {0, 0, 0, 3,   2,  2,  3,  2,   3,   3};

int main() {
	cin >> N;
	
	if (N < 3)
		cout << -1;
	else if (N == 3)
		cout << 210;
	else {
		int x = N % 6;

		if (N == 6 || N == 7 || N == 8 || N == 9)
			x = N;
		else if (x < 4)
			x += 6;

		int z = N - len[x] - 1;

		cout << 1;
		for (int i = 0; i < z; i ++)
			cout << 0;
		cout << ans[x];
	}

	cout << endl;

	return 0;
}
