#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	string N;
	int mod = 0;
	
	cin >> N;
	for (int i = 0; i < (int) N.size(); i ++)
		mod = (mod + N[i] - '0') % 3;

	if (mod)
		cout << 1 << endl << mod << endl;
	else
		cout << 2 << endl;

	return 0;
}

