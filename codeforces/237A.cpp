#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> arr;

int main() {
	cin >> N;
	arr.resize(N);
	for(int i = 0; i < N; i ++) {
		int h, m;
		cin >> h >> m;
		arr[i] = h * 60 + m;
	}

	sort(arr.begin(), arr.end());
	
	int value = arr.front();
	int len = 0;
	int res = 0;
	for(int i = 1; i < arr.size(); i ++) {
		if(value == arr[i]) {
			len ++;
			if(len > res)
				res = len;
		} else
			len = 0;

		value = arr[i];
	}

	cout << res + 1 << endl;

	return 0;
}
