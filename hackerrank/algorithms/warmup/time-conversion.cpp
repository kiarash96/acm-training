#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	string str;
	cin >> str;

	int h = stoi(str.substr(0, 2));
	bool pm = (str.substr(8, 2) == "PM");

	cout << setfill('0') << setw(2)
		<< ((pm && h < 12) || (!pm && h == 12) ? (h + 12)%24 : h)
		<< ":" << str.substr(3, 5) << endl;

	return 0;
}

