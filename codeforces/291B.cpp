#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string str;
vector<string> ans;

int main() {
	ios::sync_with_stdio(0);

	getline(cin, str);

	stringstream ss(str);
	string s;
	while (getline(ss, s, '\"'))
		ans.push_back(s);

	for (int i = 0; i < (int) ans.size(); i ++)
		if (i % 2 == 1)
			cout << "<" << ans[i] << ">" << endl;
		else {
			stringstream ss(ans[i]);
			string s;
			while (getline(ss, s, ' '))
				if (s.size() > 0)
					cout << "<" << s << ">" << endl;
		}

	return 0;
}
