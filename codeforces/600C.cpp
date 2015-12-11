#include <iostream>
#include <string>
using namespace std;

const int MaxChar = 'z';
int cnt[MaxChar + 1] = {0};

int main() {
	ios::sync_with_stdio(0);

	string str;
	cin >> str;

	for (int i = 0; i < (int) str.size(); i ++)
		cnt[str[i]] ++;

	for (char i = 'a', j = 'z'; i <= 'z'; i ++)
		if (cnt[i] % 2 == 1) {
			while (cnt[j] % 2 != 1)
				j --;
			cnt[i] ++;
			cnt[j] --;
		}

	char middle = 0;

	for (char ch = 'a'; ch <= 'z'; ch ++) {
		if (cnt[ch] % 2 == 1)
			middle = ch;
		for (int i = 0; i < cnt[ch]/2; i ++)
			cout << ch;
	}

	if (middle != 0)
		cout << middle;

	for (char ch = 'z'; ch >= 'a'; ch --)
		for (int i = 0; i < cnt[ch]/2; i ++)
			cout << ch;

	cout << endl;

	return 0;
}

