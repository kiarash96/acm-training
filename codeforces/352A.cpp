#include <iostream>
using namespace std;

int N;
int fives = 0, zeros = 0;

int main() {
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i ++) {
		int x;
		cin >> x;
		(x == 5 ? fives ++ : zeros ++);
	}

	if (zeros == 0)
		cout << -1;
	else if (fives < 9)
		cout << 0;
	else {
		for (int i = 0; i < fives/9; i ++)
			cout << 555555555;
		for (int i = 0; i < zeros; i ++)
			cout << 0;
	}

	cout << endl;

	return 0;
}

