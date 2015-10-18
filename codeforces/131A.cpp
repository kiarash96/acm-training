#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;

int main() {
	cin >> str;
	bool caps = true;

	for (int i = 1; i < (int) str.size(); i ++)
		if (islower(str[i]))
			caps = false;

	if (caps) {
		cout << (char) (isupper(str[0]) ? tolower(str[0]) : toupper(str[0]));
		for (int i = 1; i < (int) str.size(); i ++)
			cout << (char) tolower(str[i]);
	} else
		cout << str;

	cout << endl;
	return 0;
}
