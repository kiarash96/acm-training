#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int N;
	int s;
	cin >> N >> s;

	int ans = -1;
	for (int i = 0; i < N; i ++) {
		int x, y;
		cin >> x >> y;
		
		int money = s, cent = 0;

		if (money > x || (money == x && cent >= y)) {
			money -= x;
			if (y <= cent)
				cent -= y;
			else {
				money --;
				cent += 100 - y;
			}

			while (cent >= 100) {
				cent -= 100;
				money ++;
			}

			ans = max(ans, cent);
		}
	}

	cout << ans << endl;

	return 0;
}

