#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 1e5;
int N;
int arr[MaxN];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++)
		cin >> arr[i];

	int p = -1;
	for (int i = N - 2; i >= 0; i --)
		if (arr[i] > arr[i + 1]) {
			p = i;
			break;
		}

	cout << p + 1 << endl;

	return 0;
}
