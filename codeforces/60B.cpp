#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M, K;
vector<vector<string> > plate;
int ans = 0;

const int ACT_SIZE = 6;
const int actions[ACT_SIZE][3] = {
	{+1, 0, 0},
	{-1, 0, 0},
	{0, +1, 0},
	{0, -1, 0},
	{0, 0, +1},
	{0, 0, -1},
};

inline bool bet(const int value, const int begin, const int end) {
	return begin <= value && value < end;
}

void DFS(const int h, const int x, const int y) {
	plate[h][x][y] = '#';
	ans ++;

	for (int i = 0; i < ACT_SIZE; i ++) {
		int hn = h + actions[i][0], xn = x + actions[i][1], yn = y + actions[i][2];
		if (bet(hn, 0, K) && bet(xn, 0, N) && bet(yn, 0, M) && plate[hn][xn][yn] == '.')
			DFS(hn, xn, yn);
	}
}

int main() {
	cin >> K >> N >> M;
	plate.resize(K, vector<string>(N));

	for (int k = 0; k < K; k ++)
		for (int i = 0; i < N; i ++)
			cin >> plate[k][i];

	int x, y;
	cin >> x >> y;
	x --;
	y --;

	if (plate[0][x][y] == '.')
		DFS(0, x, y);

	cout << ans << endl;

	return 0;
}
