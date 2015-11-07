#include <iostream>
using namespace std;

const int MaxI = 7 + 1;
int cnt[MaxI];

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		cnt[x] ++;

	}

	if (cnt[7] > 0 || cnt[5] > 0 || cnt[1] != cnt[4] + cnt[6] || cnt[2] < cnt[4] || cnt[6] != cnt[2] - cnt[4] + cnt[3])
		cout << -1 << endl;
	else {
		for (int i = 0; i < cnt[4]; i ++)
			cout << "1 2 4" << endl;
		for (int i = 0; i < cnt[2] - cnt[4]; i ++)
			cout << "1 2 6" << endl;
		for (int i = 0; i < cnt[3]; i ++)
			cout << "1 3 6" << endl;
	}

	return 0;
}

