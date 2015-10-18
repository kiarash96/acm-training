#include <iostream>
using namespace std;

const int ACTS = 5;
const int actions[ACTS][2] = {{0, 0}, {0, -1}, {0, +1}, {-1, 0}, {+1, 0}};

inline bool bet(const int value, const int begin, const int end) {
	return begin <= value && value < end;
}

const int N = 3;
int table[N][N] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++) {
			int x;
			cin >> x;
			if (x % 2 == 1)
				for (int k = 0; k < ACTS; k ++) {
					int xp = i + actions[k][0], yp = j + actions[k][1];
					if (bet(xp, 0, N) && bet(yp, 0, N))
						table[xp][yp] ++;
				}
		}

	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++)
			cout << (table[i][j] % 2 == 0 ? 1 : 0);
		cout << endl;
	}

	return 0;
}
