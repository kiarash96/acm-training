#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int> > segments;
pair<int, int> big(1000000000, 1);

int main() {
	cin >> N;
	segments.resize(N);
	for (int i = 0; i < N; i ++) {
		cin >> segments[i].first >> segments[i].second;
		big.first = min(segments[i].first, big.first);
		big.second = max(segments[i].second, big.second);
	}

	int res = -1;

	for (int i = 0; i < (int) segments.size(); i ++)
		if (segments[i].first == big.first && segments[i].second == big.second)
			res = i + 1;

	cout << res << endl;

	return 0;
}
