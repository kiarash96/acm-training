#include <iostream>
#include <cmath>
using namespace std;

int N;

int main() {
	cin >> N;
	
	int sum = 0;
	for (int i = 0; i < N; i ++) {
		int x;
		cin >> x;
		sum += x;
	}

	if (sum % N == 0)
		cout << N;
	else
		cout << N - 1;
	cout << endl;
		
	return 0;
}
