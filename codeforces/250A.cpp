#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N;
vector<int> res(1, 0);

int main() {
	cin >> N;

	int neg = 0;
	for (int i = 0; i < N; i ++) {
		int x;
		cin >> x;

		if (x >= 0)
			res.back() ++;
		else if (neg < 2) {
			res.back() ++;
			neg ++;
		} else {
			res.push_back(1);
			neg = 1;
		}

	}

	cout << res.size() << endl;
	for (int i = 0; i < (int) res.size(); i ++)
		cout << (i == 0 ? "" : " ") << res[i];
	cout << endl;

	return 0;
}
