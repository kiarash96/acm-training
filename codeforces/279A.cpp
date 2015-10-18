#include <iostream>
using namespace std;

const int ACTS = 4;
const int actions[ACTS][2] = {{+1, 0}, {0, +1}, {-1, 0}, {0, -1}};
int X, Y;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> X >> Y;

	if (X == 0 && Y == 0) {
		cout << 0 << endl;
		return 0;
	}

	bool end = false;
	int x = 0, y = 0, size = 1;
	int ans = 0;

	while (true) {
		for (int i = 0; i < size; i ++) {
			x += actions[ans % ACTS][0];
			y += actions[ans % ACTS][1];
			if (x == X && y == Y)
				end = true;
		}

		if (end)
			break;

		if ((ans ++) % 2 == 1)
			size ++;
	}

	cout << ans << endl;

	return 0;
}
