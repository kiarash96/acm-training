#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int N;
vector<ll> ans;

int main() {
	cin >> N;
	ans.resize(N);

	ans[0] = 2;
	ans[1] = 2;

	for (int i = 2; i < N; i ++)
		ans[i] = ans[i - 1] + ans[i - 2];

	cout << ans[N - 1] << endl;

	return 0;
}

