#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	int negs = 0, zeros = 0, poss = 0;
	for (int i = 0; i < N; i ++) {
		int x;
		cin >> x;

		if (x < 0)
			negs ++;
		else if (x == 0)
			zeros ++;
		else
			poss ++;
	}

	cout << fixed << setprecision(4) << (double) poss / N << endl
									 << (double) negs / N << endl
									 << (double) zeros / N << endl;;

	return 0;
}

