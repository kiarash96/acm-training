#include <bits/stdc++.h>
using namespace std;

const int MaxN = 500;
int N;
multiset<int> S;
int arr[MaxN];

int main() {
	ios::sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N*N; i ++) {
		int x;
		cin >> x;
		S.insert(x);
	}

	for (int i = 0; i < N; i ++) {
		arr[i] = *S.rbegin();
		S.erase(--S.end());

		for (int j = 0; j < i; j ++)
			for (int k = 0; k < 2; k ++)
				S.erase(S.find(__gcd(arr[i], arr[j])));
	}

	for (int i = 0; i < N; i ++)
		cout << (i == 0 ? "" : " ") << arr[i];
	cout << endl;

	return 0;
}

