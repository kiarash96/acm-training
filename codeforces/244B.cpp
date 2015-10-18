#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N;

vector<bool> lucky;
vector<int> tmp;

//vector<bool> touch;

int res = 0;

void add(const int n) {
//	touch[n] = true;
	if (n > 0 && n <= N && !lucky[n]) {
		res ++;
		lucky[n] = true;
	}
}

void find_lucky(const int x, const int y) {
	tmp.clear();

	tmp.push_back(x);
	tmp.push_back(y);
	add(x);
	add(y);

	for (int len = 2; len <= 9; len ++) {
		int n = tmp.size();
		for (int i = 0; i < n; i ++) {
			tmp.push_back(tmp[i]);
			
			tmp[i] = tmp[i] * 10 + x;
			add(tmp[i]);

			tmp.back() = tmp.back() * 10 + y;
			add(tmp.back());
		}
	}
}

int main() {
	cin >> N;
	lucky.resize(N + 1, false);

	//touch.resize(1000000000, false);

	for (int x = 0; x <= 9; x ++)
		for (int y = x + 1; y <= 9; y ++)
			find_lucky(x, y);

/*	for (int i = 0; i <= N; i ++)
		if (!touch[i])
			cerr << i << endl;
	cerr << endl;*/

	if (N == 1000000000)
		res ++;

	cout << res << endl;

	return 0;
}
