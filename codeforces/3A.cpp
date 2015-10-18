#include <iostream>
#include <utility>
#include <string>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;

inline bool bet(const int value, const int begin, const int end) {
	return begin <= value && value < end;
}

const int ACTS = 8;
const int actions[ACTS][2] = {
	{0, -1}, {0, +1}, {-1, 0}, {+1, 0},
	{+1, +1}, {-1, -1}, {+1, -1}, {-1, +1},
};
const string names[ACTS] = {"D", "U", "L", "R", "RU", "LD", "RD", "LU"};

pii pos, goal;

int main() {
	ios_base::sync_with_stdio(false);

	string s1, s2;
	cin >> s1 >> s2;
	pos = pii(s1[0] - 'a', s1[1] - '0' - 1);
	goal = pii(s2[0] - 'a', s2[1] - '0' - 1);

	cout << max(abs(pos.first - goal.first), abs(pos.second - goal.second)) << endl;

	while (pos != goal) {
		int best = 16, act = 0;
		for (int i = 0; i < ACTS; i ++) {
			pii res(pos.first + actions[i][0], pos.second + actions[i][1]);
			int diff = abs(res.first - goal.first) + abs(res.second - goal.second);
			if (bet(res.first, 0, 8) && bet(res.second, 0, 8) && diff < best) {
				best = diff;
				act = i;
			}
		}

		cout << names[act] << endl;
		pos.first += actions[act][0]; pos.second += actions[act][1];
	}

	return 0;
}
