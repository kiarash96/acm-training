#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	string A, B;
	cin >> A >> B;

	int len = 0;
	for (int i = 0; i < (int) A.size(); i ++) {
		char digit = abs(A[i] - B[i]) + '0';
		if (len > 0 || digit != '0') {
			cout << digit;
			len ++;
		}
	}

	if (len == 0)
		cout << 0;

	cout << endl;

	return 0;
}

