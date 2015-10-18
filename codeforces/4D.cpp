#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

istream& operator>> (istream &input, pii &p) {
	return input >> p.first >> p.second;
}

struct Envelope {
	pii size;
	int index;
	bool operator< (const Envelope &second) const {
		return size < second.size;
	}
};

const int MaxN = 5000;
int N;
Envelope arr[MaxN + 1];
int dp[MaxN + 1];
int par[MaxN + 1];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> arr[0].size;
	int ind = 1;
	for (int i = 1; i <= N; i ++) {
		cin >> arr[ind].size;
		arr[ind].index = i;
		if (arr[ind].size.first > arr[0].size.first && arr[ind].size.second > arr[0].size.second)
			ind ++;
	}
	N = ind - 1;

	sort(arr, arr + N + 1);

	dp[0] = 0;
	par[0] = -1;

	int end = 0;
	for (int i = 1; i <= N; i ++) {
		dp[i] = 0;
		for (int j = 0; j < i; j ++)
			if (arr[j].size.first < arr[i].size.first && arr[j].size.second < arr[i].size.second) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
					par[i] = j;
				}
			}

		if (dp[i] > dp[end])
			end = i;
	}

	vector<int> ans;
	for (int i = end; i != 0; i = par[i])
		ans.push_back(arr[i].index);
	
	cout << ans.size() << endl;
	for (int i = ans.size() - 1; i >= 0; i --)
		cout << (i == (int) ans.size() - 1 ? "" : " ") << ans[i];
	cout << endl;

	return 0;
}
