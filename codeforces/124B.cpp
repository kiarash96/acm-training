#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#include <sstream>
using namespace std;

const int MaxK = 8;
const int pow10[MaxK] = {1, 10, 100, 1e3, 1e4, 1e5, 1e6, 1e7};
int N, K;
vector<string> numbers;

int calc_res(const vector<int> &perm) {
	int minNumber = numeric_limits<int>::max(), maxNumber = 0;
	for (int i = 0; i < N; i ++) {
		int num = 0;
		for (int j = 0; j < K; j ++)
			num += (numbers[i][j] - '0') * pow10[perm[j]];
		minNumber = min(minNumber, num);
		maxNumber = max(maxNumber, num);
	}

	return maxNumber - minNumber;
}

int main() {
	cin >> N >> K;
	numbers.resize(N);
	for (int i = 0; i < N; i ++)
		cin >> numbers[i];

	vector<int> perm(K);
	for (int i = 0; i < K; i ++)
		perm[i] = i;

	int ans = numeric_limits<int>::max();
	do
		ans = min(ans, calc_res(perm));
	while (next_permutation(perm.begin(), perm.end()));

	cout << ans << endl;

	return 0;
}
