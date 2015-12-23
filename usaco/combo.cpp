/*
ID: kia.cel1
PROG: combo
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#define cin fin
#define cout fout

int N;
int n1, n2, n3;
int m1, m2, m3;

inline bool checkdigit(int a, int b) {
	return abs(a - b) <= 2 || abs(a - b) >= N - 2;
}

inline bool match(int a, int b, int c, int x, int y, int z) {
	return checkdigit(a, x) && checkdigit(b, y) && checkdigit(c, z);
}

int main() {
	ios::sync_with_stdio(0);

	ifstream fin("combo.in");
	ofstream fout("combo.out");

	cin >> N;
	cin >> n1 >> n2 >> n3;
	cin >> m1 >> m2 >> m3;

	int ans = 0;
	for (int x = 1; x <= N; x ++)
		for (int y = 1; y <= N; y ++)
			for (int z = 1; z <= N; z ++)
				if (match(n1, n2, n3, x, y, z) || match(m1, m2, m3, x, y, z))
					ans ++;

	cout << ans << endl;

	return 0;
}

