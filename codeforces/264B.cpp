#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const ll MaxN = 1e5;
int N;
vector<int> v[MaxN + 1];
int dp[MaxN + 1] = {0};
bool prime[MaxN + 1];

int main() {
	ios_base::sync_with_stdio(false);

	fill(prime, prime + MaxN + 1, true);
	for (int i = 2; i <= MaxN; i ++)
		if (prime[i])
			for (int j = 2; i*j <= MaxN; j ++) {
				prime[i * j] = false;
				v[i * j].push_back(i);
			}

	cin >> N;
	for (int i = 0; i < N; i ++) {
		int x;
		cin >> x;

		dp[x] = 1;
		for (int j = 0; j < (int) v[x].size(); j ++)
			dp[x] = max(dp[x], dp[v[x][j]] + 1);

		for (int j = 0; j < (int) v[x].size(); j ++)
			dp[v[x][j]] = max(dp[v[x][j]], dp[x]);
	}

	cout << *max_element(dp, dp + MaxN + 1) << endl;

	return 0;
}
