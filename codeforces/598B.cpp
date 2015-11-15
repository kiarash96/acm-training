#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	string str;
	cin >> str;

	int M;
	cin >> M;
	for (int i = 0; i < M; i ++) {
		int l, r, k;
		cin >> l >> r >> k;
		l --; r --;

		int n = r - l + 1;
		string copy = str.substr(l, n);
		for (int j = l; j <= r; j ++)
			str[j] = copy[(n + j - l - k%n)%n];
	}

	cout << str << endl;

	return 0;
}

