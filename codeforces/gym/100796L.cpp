#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int N;
	string str;
	
	cin >> N >> str;

	int ans = 0;
	for (int i = 0; i < N; i ++)
		if (str[i] == ':') {
			if (0 <= i - 1) {
				if (str[i - 1] == '(') // (:
					ans ++;
				else if (str[i - 1] == ')') // ):
					ans --;
			}
			if (i + 1 < N) {
				if (str[i + 1] == ')') // :)
					ans ++;
				else if (str[i + 1] == '(') // :(
					ans --;
			}
		}

	if (ans < 0)
		cout << "SAD";
	else if (ans == 0)
		cout << "BORED";
	else
		cout << "HAPPY";
	cout << endl;

	return 0;
}

