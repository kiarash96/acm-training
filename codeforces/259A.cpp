#include <iostream>
#include <string>
using namespace std;

const int N = 8;

int main() {
	bool ans = true;
	for (int i = 0; i < N; i ++) {
		string row;
		getline(cin, row);
		char last = 0;
		for (int j = 0; j < N; j ++) {
			if (last == row[j])
				ans = false;
			last = row[j];
		}
	}

	cout << (ans ? "YES" : "NO") << endl;

	return 0;
}
