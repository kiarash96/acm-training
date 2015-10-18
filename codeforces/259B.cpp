#include <iostream>
using namespace std;

int main() {
	int table[3][3];
	for (int i = 0; i < 3; i ++)
		for (int j = 0; j < 3; j ++)
			cin >> table[i][j];

	table[0][0] = (table[0][2] + table[2][0] + table[1][2] - table[0][1]) / 2;
	table[2][2] = table[0][2] + table[2][0] - table[0][0];
	table[1][1] = table[0][1] + table[0][2] - table[2][2];

	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j ++)
			cout << (j == 0 ? "" : " ") << table[i][j];
		cout << endl;
	}

	return 0;
}
