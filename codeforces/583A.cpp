#include <iostream>
using namespace std;

const int MaxN = 50;
int N;
bool h[MaxN], v[MaxN];

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N*N; i ++) {
		int x, y;
		cin >> x >> y;
		x --; y --;
		if (h[x] == false && v[y] == false) {
			h[x] = true;
			v[y] = true;
			cout << i + 1 << " ";
		}
	}

	cout << endl;
	return 0;
}

