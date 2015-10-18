#include <iostream>
#include <string>
#include <set>
using namespace std;

int N;
set<string> S;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++) {
		string str;
		cin >> str;
		for (int j = 0; j < (int) str.size(); j ++) {
			S.insert(string(1, str[j]));
			if (j + 1 < (int) str.size())
				S.insert(str.substr(j, 2));
		}
	}

	string ans;

	ans.resize(1);
	for (ans[0] = 'a'; ans[0] <= 'z'; ans[0] ++)
		if (S.count(ans) == 0) {
			cout << ans << endl;
			return 0;
		}

	ans.resize(2);
	for (ans[0] = 'a'; ans[0] <= 'z'; ans[0] ++)
		for (ans[1] = 'a'; ans[1] <= 'z'; ans[1] ++)
			if (S.count(ans) == 0) {
				cout << ans << endl;
				return 0;
			}

	return 0;
}
