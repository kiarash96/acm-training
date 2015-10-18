#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MaxN = 1e5;
int N, MOD;
pii arr[2 * MaxN];
int mem[MaxN] = {0};

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < 2 * N; i ++) {
		cin >> arr[i].first;
		arr[i].second = i % N;
	}
	cin >> MOD;

	sort(arr, arr + 2 * N);

	vector<int> facts;
	int div2 = 0;

	for (int i = 0; i < 2 * N; i ++) {
		int x = arr[i].first;
		int cnt = 1, dup = 0;
		mem[arr[i].second] = x;

		while (i + 1 < 2 * N && arr[i + 1].first == x) {
			i ++; cnt ++;
			if (mem[arr[i].second] == x)
				dup ++;
			mem[arr[i].second] = x;
		}

		facts.push_back(cnt);
		div2 += dup;
	}

	sort(facts.begin(), facts.end());

	int ind = 0, ans = 1;
	for (int i = 2; i <= facts.back(); i ++) {
		while (i > facts[ind])
			ind ++;
		int p = facts.size() - ind;

		ll x = 1;
		for (int j = 0; j < p; j ++) {
			x *= i;

			while (x % 2 == 0 && div2 > 0) {
				x /= 2;
				div2 --;
			}

			x %= MOD;
		}
		
		ans = ((ll) ans * x) % MOD;
	}

	cout << ans << endl;

	return 0;
}
