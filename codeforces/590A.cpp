#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

const int MaxN = 5 * 1e5;
int N;
int arr[MaxN], ans[MaxN];

inline vector<pii> findSegments() {
	vector<pii> v;
	for (int i = 1; i < N - 1; i ++)
		if (arr[i - 1] == arr[i] || arr[i] == arr[i + 1])
			continue;
		else {
			pii seg = make_pair(i, 0);
			while (i < N - 1 && arr[i] != arr[i + 1])
				i ++;
			seg.second = i - 1;
			v.push_back(seg);
		}
	return v;
}

int main() {
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i ++)
		cin >> arr[i];

	vector<pii> v = findSegments();
	/*for (int i = 0; i < (int) v.size(); i ++)
		cerr << v[i].first << " " << v[i].second << endl;*/

	int maxDepth = 0;
	ans[0] = arr[0];
	vector<pii>::iterator iter = v.begin();
	for (int i = 1; i < N - 1; i ++) {
		if (iter != v.end() && i == iter->first) {
			int x = iter->first, y = iter->second;
			int res1 = arr[x - 1], res2 = arr[y + 1];
			for (; i <= y; i ++)
				ans[i] = (i <= (x + y)/2 ? res1 : res2);
			i --;

			maxDepth = max(maxDepth, (y - x + 1)/2 + (res1 == res2 ? 1 : 0));
			iter ++;
		}
		else
			ans[i] = arr[i];
	}
	ans[N - 1] = arr[N - 1];

	cout << maxDepth << endl;
	for (int i = 0; i < N; i ++)
		cout << (i == 0 ? "" : " ") << ans[i];
	cout << endl;

	return 0;
}

