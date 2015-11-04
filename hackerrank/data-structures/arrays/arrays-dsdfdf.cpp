#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 1000;
int N;
int arr[MaxN];

int main() {
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i ++)
		cin >> arr[i];

	reverse(arr, arr + N);

	for (int i = 0; i < N; i ++)
		cout << (i == 0 ? "" : " ") << arr[i];
	cout << endl;

	return 0;
}

