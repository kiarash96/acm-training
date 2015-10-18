#include <iostream>
#include <string>
using namespace std;

const int S = 'z' - 'a' + 1;
int cnt[S] = {0};
string str;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> str;

	for (int i = 0; i < (int) str.size(); i ++)
		cnt[str[i] - 'a'] ++;

	int len = str.size(), odd = 0;
	for (int i = 0; i < S; i ++)
		if (cnt[i] % 2 == 1)
			odd ++;
	
	int ans = 0;
	while (true) {
		if ((len % 2 == 0 && odd == 0) || (len % 2 == 1 && odd == 1))
			break;
		len --; odd --;
		ans ++;
	}

	cout << (ans % 2 == 0 ? "First" : "Second") << endl;

	return 0;
}
