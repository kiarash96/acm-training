#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int T;
	cin >> T;

	string tmp;
	getline(cin, tmp);

	while (T --) {
		string line;
		getline(cin, line);

		stringstream in(line);
		bool first = true;
		string word;
		while (in >> word) {
			string ans = word;
			if (word.substr(0, 2) == "be" && word.size() > 2)
				ans = word.substr(2);
			else if (word.substr(0, 2) == "ab")
				ans = "O" + word.substr(2);
			else {
				int ind = ans.find("a");
				while (ind != string::npos) {
					ans[ind] = 'e';
					ind = ans.find("a", ind);
				}
			}

			cout << (first ? "" : " ") << ans;
			first = false;
		}
		cout << endl;
	}

	return 0;
}

