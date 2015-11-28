#include <iostream>
#include <iomanip>
using namespace std;

const int MaxN = 10000;
int N, M;
int votes[MaxN] = {0};

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i ++) {
		int x;
		cin >> x;
		votes[x - 1] ++;
	}

	for (int i = 0; i < N; i ++)
		cout << fixed << setprecision(2) << votes[i] * 100.0 / (double) M << "%" << endl;

	return 0;
}

