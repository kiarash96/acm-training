#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	if (N == 3)
		cout << 1;
	else if (N == 4)
		cout << 4;
	else
		cout << 3LL*(N - 3) + (N - 3LL)*(N - 4) + 1;
	cout << endl;

	return 0;
}

