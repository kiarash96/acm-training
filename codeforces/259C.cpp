#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string num;

int main() {
	cin >> num;
	int best = -1;
	for (int i = 0; i < (int) num.size(); i ++)
		if (num[i] == '0') {
			best = i;
			break;
		}

	if (best == -1)
		cout << num.substr(0, num.size() - 1);
	else
		cout << num.substr(0, best) << num.substr(best + 1);
	cout << endl;

	return 0;
}
