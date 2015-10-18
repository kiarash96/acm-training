#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
	cin >> str;
	for (int i = 0; i < (int) str.size(); i ++) {
		char ch = tolower(str[i]);
		if (ch != 'a' & ch != 'o' && ch != 'y' && ch != 'e' && ch != 'u' && ch != 'i')
			cout << "." << ch;
	}
	cout << endl;
	return 0;
}
