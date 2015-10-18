#include <iostream>
using namespace std;

int n, k;

int main() {
	int ak;
	int res = 0;

	cin >> n >> k;

	for(int i = 1; i < n + 1; i ++) {
		int a;
		cin >> a;
		
		if(a <= 0)
			continue;

		if(i <= k) {
			res ++;
			if(i == k)
				ak = a;
		} else if(i > k && a >= ak)
			res ++;
	}

	cout << res << endl;

	return 0;
}
