#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MaxN = 1e5;
int N;
string names[MaxN][2];

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++) {
		cin >> names[i][0] >> names[i][1];
		if (names[i][0] > names[i][1])
			swap(names[i][0], names[i][1]);
	}

	bool ans = true;
	int index;
	cin >> index;

	string last = names[index - 1][0];
	for (int i = 1; i < N; i ++) {
		cin >> index;
		index --;

		if (last <= names[index][0])
			last = names[index][0];
		else if (last <= names[index][1])
			last = names[index][1];
		else
			ans = false;
	}

	cout << (ans == false ? "NO" : "YES") << endl;

	return 0;
}

