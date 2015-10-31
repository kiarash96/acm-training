#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int N, X, M;
	string str, program;
	cin >> N >> X
		>> str
		>> M
		>> program;

	X --;
	string ans(1, str[X]);
	for (int i = 0; i < M; i ++) {
		X += (program[i] == 'L' ? -1 : +1);
		ans.push_back(str[X]);
	}

	cout << ans << endl;

	return 0;
}

