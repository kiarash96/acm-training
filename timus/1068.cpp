#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	if(n > 0)
		cout << (n*(n+1)) / 2 << endl;
	else if(n == 0)
		cout << 1 << endl;
	else
		cout << 1 + -1 * ((n*(n-1)) / 2) << endl;
	return 0;
}

