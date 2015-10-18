#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> arr;

int main() {
	cin >> N;
	arr.resize(N);
		
	if (N == 1 || N == 2)
		cout << -1;
	else
		for (int i = N; i > 0; i --)
			cout << (i == N ? "" : " ") << i;
	cout << endl;

	return 0;
}
