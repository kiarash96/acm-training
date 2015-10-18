#include <iostream>
#include <utility>
#include <string>
using namespace std;

typedef pair<int, int> pii;

const int ACTS = 9;
const int actions[ACTS][2] = {{0, 0},
	{0, +1}, {0, -1}, {+1, 0}, {-1, 0},
	{-1, -1}, {+1, +1}, {-1, +1}, {+1, -1}};

const int N = 8;
string map[N];

inline bool bet(const int value, const int begin, const int end) {
	return begin <= value && value < end;
}

bool DFS(const pii &pos, const int t) {
	if (pos == pii(0, N - 1) || t > 7)
		return true;

	if (bet(pos.first - t, 0, N) && map[pos.first - t][pos.second] == 'S')
		return false;

	bool res = false;
	for (int i = 0; i < ACTS; i ++) {
		pii child(pos.first + actions[i][0], pos.second + actions[i][1]);
		if (bet(child.first, 0, N) && bet(child.second, 0, N)) {
			if (bet(child.first - t, 0, N) && map[child.first - t][child.second] == 'S')
				continue;

			res |= DFS(child, t + 1);
		}
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < N; i ++)
		cin >> map[i];

	cout << (DFS(pii(N - 1, 0), 0) ? "WIN" : "LOSE") << endl;

	return 0;
}
