#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2*1e4, MaxLen = 100;
int N;
string mails[MaxN];
map<string, vector<int> > S;

inline string strip(string str) {
	bool bmail = false;
	if (str.size() >= 9) {
		for (int i = 0; i < 9; i ++)
			str[str.size() - i - 1] = tolower(str[str.size() - i - 1]);
		bmail = (str.substr(str.find_last_of('@')) == "@bmail.com");
	}

	string ret;
	bool domain = false, plus = false;
	for (int i = 0; i < (int) str.size(); i ++) {
		if (domain == false) {
			if (str[i] == '@')
				domain = true;
			else if (bmail && str[i] == '+')
				plus = true;
			
			if ((bmail && str[i] == '.') || (bmail && plus && str[i] != '@'))
				continue;
		}
		ret.push_back(tolower(str[i]));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i ++) {
		cin >> mails[i];
		
		S[strip(mails[i])].push_back(i);
	}

	cout << S.size() << endl;

	for (auto iter = S.begin(); iter != S.end(); ++ iter) {
		cout << iter->second.size();
		for (int i = 0; i < iter->second.size(); i ++)
			cout << " " << mails[iter->second[i]];
		cout << endl;
	}

	return 0;
}

