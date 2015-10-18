#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> arr;
vector<int> counts;

int main() {
	cin >> N >> K;
	arr.resize(N);
	counts.resize(K, 0);
	for (int i = 0; i < N; i ++) {
		cin >> arr[i];
		arr[i] --;
	}

	int end = unique(arr.begin(), arr.end()) - arr.begin();

	for (int i = 0; i < end; i ++) {
		counts[arr[i]] ++;
		if (i != 0 && i != end - 1 && arr[i - 1] == arr[i + 1])
			counts[arr[i]] ++;
	}

	cout << max_element(counts.begin(), counts.end()) - counts.begin() + 1 << endl;

	return 0;
}
