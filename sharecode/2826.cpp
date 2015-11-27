#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef long long ll;

inline ll toint(string str) {
	stringstream ss;
	ss << str;
	ll res;
	ss >> res;
	return res;
}

inline int number(ll p, ll q) {
	if (p == 1 && q == 1)
		return 1;

	if (p < q)
		return 2*number(p, q - p);
	else
		return 2*number(p - q, q) + 1;
}

int main() {
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while (T --) {
		string str;
		cin >> str;

		string P, Q;
		stringstream ss(str);
		getline(ss, P, '/');
		getline(ss, Q);

		ll p = toint(P), q = toint(Q);

		cout << number(p, q) << endl;
	}

	return 0;
}

