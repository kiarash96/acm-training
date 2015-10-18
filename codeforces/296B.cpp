#include <iostream>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

int N;
long long ans = 1LL;
string s[2];

inline int toint(const char ch) { return ch - '0'; }

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> s[0] >> s[1];

	int less = 0, great = 0, question = 0;
	for (int i = 0; i < N; i ++)
		if (s[0][i] != '?' && s[1][i] != '?') {
			less += s[0][i] < s[1][i];
			great += s[0][i] > s[1][i];
		} else
			question += (s[0][i] == '?') + (s[1][i] == '?');

	for (int i = 0; i < question; i ++)
		ans = (ans * 10LL) % MOD;

	long long first = (less == 0), second = (great == 0), third = (less == 0 && great == 0);
	for (int i = 0; i < N; i ++)
		if (s[0][i] == '?' && s[1][i] == '?') {
			first = (first * 55LL) % MOD;
			second = (second * 55LL) % MOD;
			third = (third * 10LL) % MOD;
		} else if (s[0][i] == '?') {
			first = (first * (10 - toint(s[1][i]))) % MOD;
			second = (second * (toint(s[1][i]) + 1)) % MOD;
		} else if (s[1][i] == '?') {
			first = (first * (toint(s[0][i]) + 1)) % MOD;
			second = (second * (10 - toint(s[0][i]))) % MOD;
		}

	int mod = (0LL + ans - first - second + third) % MOD;
	while (mod < 0)
		mod += MOD;
	cout << mod << endl;

	return 0;
}
