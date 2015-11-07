#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int sum;
	cin >> sum;

	if (sum < 11)
		cout << 0;
	else if (sum == 11)
		cout << 4;
	else if (sum <= 19)
		cout << 4;
	else if (sum == 20)
		cout << 15;
	else if (sum == 21)
		cout << 4;
	else
		cout << 0;
	cout << endl;
	return 0;
}

