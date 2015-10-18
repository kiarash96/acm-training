#include <iostream>
using namespace std;

const int MaxN = 100;
int N;
int arr[MaxN];

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++)
		cin >> arr[i];

	int min = 0, max = 0;
	for (int i = 0; i < N; i ++) {
		if (arr[i] <= arr[min])
			min = i;
		if (arr[i] > arr[max])
			max = i;
	}

	cout << N - min - 1 + max - (max > min) << endl;

	return 0;
}
