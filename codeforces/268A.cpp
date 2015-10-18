#include <iostream>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

const int MaxN = 30;
int N;
pii color[MaxN];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++)
		cin >> color[i].first >> color[i].second;

	int ans = 0;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++)
			if (i != j && color[i].first == color[j].second)
				ans ++;

	cout << ans << endl;

	return 0;
}
