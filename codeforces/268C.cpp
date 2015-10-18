#include <iostream>
using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	cout << min(N, M) + 1 << endl;
	
	int x = 0, y = M;
	while (x <= N && y >= 0)
		cout << x ++ << " " << y -- << endl;

	return 0;
}
