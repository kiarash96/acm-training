#include <iostream>
#include <sstream>
#include <string>
using namespace std;

typedef long long ll;
ll A, B, N;

int main() {
	cin >> A >> B >> N;
	
	bool ok = true;
	stringstream ss;
	ss << A;
	string str = ss.str();
	A %= B;
	for (int i = 0; i < N; i ++) {
		A = (A * 10) % B;
		int x = -1;
		for (int j = 0; j < 10; j ++)
			if ((A + j) % B == 0) {
				x = j;
				break;
			}
		
		if (x == -1) {
			ok = false;
			break;
		}

		A = (A + x) % B;
		str += char(x + '0');
	}

	if (!ok)
		cout << -1;
	else
		cout << str;
	cout << endl;

	return 0;
}
