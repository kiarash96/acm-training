#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int P, M, C,
		K, R, V;

	cin >> P >> M >> C >> K >> R >> V;

	cout << min(P/K, min(M/R, C/V)) << endl;

	return 0;
}

