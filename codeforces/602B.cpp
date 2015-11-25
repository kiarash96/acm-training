#include <iostream>
#include <map>
using namespace std;

const int MaxN = 1e5;
int N;
int arr[MaxN];

int main() {
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i ++)
		cin >> arr[i];

	int ans = 2;

	map<int, int> cnt;
	cnt[arr[0]] ++;
	cnt[arr[1]] ++;

	int i = 0;
	for (int j = 2; j < N; j ++) {
		cnt[arr[j]] ++;

		while (cnt.rbegin()->first - cnt.begin()->first > 1) {
			cnt[arr[i]] --;
			if (cnt[arr[i]] == 0)
				cnt.erase(arr[i]);

			i ++;
		}

		ans = max(ans, j - i + 1);
	}

	cout << ans << endl;

	return 0;
}
