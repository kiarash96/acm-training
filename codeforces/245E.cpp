#include <iostream>
#include <string>
using namespace std;

string str;
int ans = 0;

int main() {
	cin >> str;
	int x = 0;
	for (int i = 0; i < (int) str.size(); i ++) {
		str[i] == '+' ? x ++ : x --;
		if (x < 0) {
			ans ++;
			x ++;
		}
		ans = max(ans, x);
	}
	cout << ans << endl;
	return 0;
}
