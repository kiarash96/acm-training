#include <iostream>
using namespace std;

int N;
int count[2] = {0};
int rec[2] = {0};

int main() {
	cin >> N;
	for (int i = 0; i < N; i ++) {
		int t, x, y;
		cin >> t >> x >> y;
		t --;
		count[t] ++;
		rec[t] += x;
	}

	for (int i = 0; i < 2; i ++) {
		if (rec[i] >= count[i] * 5)
			cout << "LIVE";
		else
			cout << "DEAD";
		cout << endl;
	}

	return 0;
}
