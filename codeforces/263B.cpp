#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 50;
int N, K;
int size[MaxN];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < N; i ++)
		cin >> size[i];

	sort(size, size + N);
	reverse(size, size + N);

	if (K > N)
		cout << -1;
	else
		cout << size[K - 1] << " " << size[K - 1];
	cout << endl;

	return 0;
}
