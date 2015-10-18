#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> segments;
vector<vector<int> > ans;

int main() {
	cin >> N >> K;
	segments.resize(N*K, -1);
	ans.resize(K);
	for (int i = 0; i < K; i ++) {
		int x;
		cin >> x;
		x --;
		ans[i].push_back(x);
		segments[x] = i;
	}

	int begin = 0;
	for (int child = 0; child < K; child ++)
		for (int i = 1; i < N; i ++)
			for (int j = begin; j < (int) segments.size(); j ++)
				if (segments[j] == -1) {
					segments[j] = child;
					ans[child].push_back(j);
					break;
				}

	for (int i = 0; i < K; i ++) {
		for (int j = 0; j < N; j ++)
			cout << (j == 0 ? "" : " ") << ans[i][j] + 1;
		cout << endl;
	}

	return 0;
}
