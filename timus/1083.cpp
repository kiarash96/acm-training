#include <iostream>
#include <string>
using namespace std;

int N, K;

int main() {
	string tmp;
	cin >> N >> tmp;
	K = tmp.size();

	int res = 1;
	for (int x = N; x > 0; x -= K)
		res *= x;

	cout << res << endl;

	return 0;
}

