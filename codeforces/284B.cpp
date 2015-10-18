#include <iostream>
#include <string>
#include <map>
using namespace std;

int N;
string str;
map<char, int> cnt;

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> str;
	for (int i = 0; i < N; i ++)
		cnt[str[i]] ++;

	int ans = 0;
	for (int i = 0; i < N; i ++)
		if (str[i] != 'F' && cnt['I'] - (str[i] == 'I') == 0)
			ans ++;

	cout << ans << endl;

	return 0;
}
