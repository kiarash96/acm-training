#include <iostream>
#include <map>
using namespace std;

int N;
map<int, int> cnt;

int main() {
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i ++) {
		int x;
		cin >> x;
		if (x != 0)
			cnt[x] ++;
	}

	bool ok = true;
	int ans = 0;
	for (map<int, int>::iterator iter = cnt.begin(); iter != cnt.end(); iter ++)
		if (iter->second > 2)
			ok = false;
		else
			ans += iter->second / 2;

	cout << (ok ? ans : -1) << endl;

	return 0;
}
