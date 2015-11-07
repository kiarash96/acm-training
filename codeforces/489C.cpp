#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string maxn;

void nextdigit(int m, int s) {
	if (m == 0)
		return;
	int digit = 9;
	while (s - digit < 0)
		digit --;
	maxn.push_back(digit + '0');
	nextdigit(m - 1, s - digit);
}

int main() {
	ios::sync_with_stdio(false);

	int m, s;
	cin >> m >> s;

	if (s > 9*m || (m > 1 && s == 0))
		cout << -1 << " " << -1 << endl;
	else if (m == 1 && s == 0)
		cout << 0 << " " << 0 << endl;
	else {
		nextdigit(m, s);
		
		string minn = maxn;
		reverse(minn.begin(), minn.end());
		if (minn[0] == '0') {
			minn[0] = '1';
			for (int i = 1; i < (int)minn.size(); i ++)
				if (minn[i] != '0') {
					minn[i] --;
					break;
				}
		}

		cout << minn << " " << maxn << endl;
	}

	return 0;
}

