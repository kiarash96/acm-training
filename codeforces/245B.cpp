#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
	cin >> str;
	
	int i;
	if (str.substr(0, 4) == "http") {
		i = 4;
		cout << "http://";
	} else {
		i = 3;
		cout << "ftp://";
	}

	int ru = str.find("ru");
	if (ru - i <= 0)
		ru = str.find("ru", ru + 2);

	cout << str.substr(i, ru - i) << ".ru";

	if (ru + 2 < (int) str.size())
		cout << "/" << str.substr(ru + 2);

	cout << endl;

	return 0;
}
