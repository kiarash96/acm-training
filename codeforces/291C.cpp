#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>
using namespace std;

typedef long long ll;

const int MaxN = 1e5;
const int cand[8] = {128, 192, 224, 240, 248, 252, 254, 255};
int N, K;
int ip[MaxN][4];

int main() {
	ios::sync_with_stdio(0);

	cin >> N >> K;
	for (int i = 0; i < N; i ++) {
		char tmp;
		for (int j = 0; j < 4; j ++) {
			if (j > 0)
				cin >> tmp;
			cin >> ip[i][j];
		}
	}

	bool found = false;
	int mask[4] = {0};
	for (int i = 0; i < 4 && !found; i ++)
		for (int j = 0; j < 8 && !found; j ++) {
			mask[i] = cand[j];

			set<ll> S;
			for (int k = 0; k < N; k ++) {
				ll x = 0LL;
				for (int q = 0; q < 4; q ++)
					x |= ((mask[q] & ip[k][q]) << (q * 8));
				S.insert(x);
			}				

			found |= ((int) S.size() == K);
		}

	if (found && mask[3] != 255)
		for (int i = 0; i < 4; i ++)
			cout << (i == 0 ? "" : ".") << mask[i];
	else
		cout << -1;
	cout << endl;

	return 0;
}
