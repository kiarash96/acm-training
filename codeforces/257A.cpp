#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 50;
int N, M, K;
int arr[MaxN];

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i ++)
		cin >> arr[i];

	sort(arr, arr + N);

	bool can = true;
	int used = 0, done = K;
	while (done < M) {
		if (used == N) {
			can = false;
			break;
		}

		done += arr[N - used - 1] - 1;
		used ++;
	}

	if (can)
		cout << used;
	else
		cout << -1;
	cout << endl;

	return 0;
}
