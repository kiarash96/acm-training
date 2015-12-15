#include <bits/stdc++.h>
using namespace std;

#define cin fin
#define cout fout

const int MaxN = 50 * 1000;

int N;
int num[MaxN];
set<int> myarr;

int main() {
	ios::sync_with_stdio(0);
	ifstream fin("highcard.in");
	ofstream fout("highcard.out");

	cin >> N;

	for (int i = 1; i <= 2*N; i ++)
		myarr.insert(i);

	for (int i = 0; i < N; i ++) {
		cin >> num[i];
		myarr.erase(num[i]);
	}

	int ans = 0;
	for (int i = 0; i < N; i ++) {
		auto iter = myarr.lower_bound(num[i]);
		if (iter != myarr.end()) {
			ans ++;
			myarr.erase(iter);
		}
	}

	cout << ans << endl;

	return 0;
}

