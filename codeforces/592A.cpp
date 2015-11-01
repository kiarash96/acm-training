#include <iostream>
using namespace std;

const int W = 8;
const int H = 8;
char table[H][W];

int main() {
	ios::sync_with_stdio(0);

	for (int i = 0; i < H; i ++)
		for (int j = 0; j < W; j ++)
			cin >> table[i][j];

	int A = 8, B = 8;
	for (int i = 0; i < W; i ++) {
		for (int j = 0; j < H; j ++) {
			if (table[j][i] == 'B')
				break;
			if (table[j][i] == 'W')
				A = min(A, j);
		}
		
		for (int j = H - 1; j >= 0; j --) {
			if (table[j][i] == 'W')
				break;
			if (table[j][i] == 'B')
				B = min(B, 8 - j - 1);
		}
	}

	cout << (A <= B ? "A" : "B") << endl;

	return 0;
}

