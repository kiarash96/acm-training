#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	int n = string(s.begin(), unique(s.begin(), s.end())).length();
	(n % 2 == 0) ? cout << "CHAT WITH HER!" : cout << "IGNORE HIM!";
	cout << endl;
	return 0;
}
