#include <iostream>
#include <string>
using namespace std;

int N;
string str;

int main() {
	cin >> N;
	for (int i = 0; i < N; i ++) {
		cin >> str;
		
		if (str.length() <= 10)
			cout << str;
		else
			cout << str[0] << str.length() - 2 << str[str.size() - 1];

		cout << endl;
	}
	return 0;
}
