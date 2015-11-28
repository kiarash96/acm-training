#include <iostream>
#include <string>
using namespace std;

int N, K;
string dp[3];

inline void fix(string &num, int n) {
	while (n > 0) {
		num.push_back(n % 10);
		n /= 10;
	}
}

inline string tostring(const int n) {
	string res;
	fix(res, n);
	return res;
}

string sum(const string &first, const string &second) {
	if (first.size() < second.size())
		return sum(second, first);

	string res = first;

	int carry = 0;
	for (int i = 0; i < (int) res.size(); i ++) {
		int x = first[i] + (i < (int) second.size() ? second[i] : 0) + carry;
		res[i] = x % 10;
		carry = x / 10;
	}

	fix(res, carry);
	return res;
}

string mult(const int n, const string &bignum) {
	string res = bignum;
	
	int carry = 0;
	for (int i = 0; i < (int) bignum.size(); i ++) {
		int x = bignum[i] * n + carry;
		res[i] = x % 10;
		carry = x / 10;
	}

	fix(res, carry);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	dp[1] = tostring(K - 1); dp[2] = tostring((K - 1) * K);
	for (int i = 3; i <= N; i ++)
		dp[i % 3] = mult(K - 1, sum(dp[(i - 1) % 3], dp[(i - 2) % 3]));

	for (int i = dp[N % 3].size() - 1; i >= 0; i --)
		cout << (char) (dp[N % 3][i] + '0');
	cout << endl;

	return 0;
}

