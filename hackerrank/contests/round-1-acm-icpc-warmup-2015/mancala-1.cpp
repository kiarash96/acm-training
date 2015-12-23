#include <iostream>
#include <vector>
using namespace std;

const int MaxN = 2000;
vector<int> ans[MaxN + 1];

int main() {
	ios::sync_with_stdio(0);

	for (int n = 1; n <= MaxN; n ++) {
		ans[n] = ans[n - 1];

		int ind = ans[n].size(); // index of first zero
		for (int i = 0; i < (int) ans[n].size(); i ++) {
			if (ans[n][i] == 0) {
				ind = i;
				break;
			}
		}
		
		for (int i = 0; i < ind; i ++)
			ans[n][i] --;
		if (ind < ans[n].size())
			ans[n][ind] = ind + 1;
		else
			ans[n].push_back(ind + 1);
	}

	int T;
	cin >> T;
	for (int t = 0; t < T; t ++) {
		int K, N;
		cin >> K >> N;

		cout << K << " " << ans[N].size() << endl;
		for (int i = 0; i < (int) ans[N].size(); i ++)
			cout << (i % 10 == 0 ? "" : " ") << ans[N][i] << (i % 10 == 9 ? "\n" : "");
		if (ans[N].size() % 10 > 0)
			cout << endl;
	}

	return 0;
}

