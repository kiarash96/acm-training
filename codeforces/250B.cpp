#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;

string get_block(const string &str) {
	string res;

//	cerr << str << endl;

	if (str.length() < 4)
		res.append(4 - str.length(), '0');

	res.append(str);

	return res;
}

string process(const string &addr) {
	string res;

	int all = count(addr.begin(), addr.end(), ':');
	
	int i = 0, j = 0;
	int num = 0;
	while (j = addr.find(':', i + 1), j != (int) string::npos) {
		if (addr[i] == ':' && addr[j] == ':') {
			for (int k = 0; k < 8 - all + 1; k ++)
				res.append("0000:");
			i ++;
		}

		res.append(get_block(addr.substr(i, j - i)) + ':');
		num ++;

		i = j + 1;
	}

	return string(res.begin(), res.end() - 1);

}

int main() {
	cin >> N;

	for (int t = 0; t < N; t ++) {
		string addr;
		cin >> addr;
		if (addr == "::")
			addr = "0000::0000";

		addr.push_back(':');

		cout << process(addr) << endl;
	}

	return 0;
}
