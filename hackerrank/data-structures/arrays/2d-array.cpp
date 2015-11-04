#include <iostream>
#include <algorithm>
using namespace std;

int arr[6][6];

int main() {
	ios::sync_with_stdio(0);
	
	for (int i = 0; i < 6; i ++)
		for (int j = 0; j < 6; j ++)
			cin >> arr[i][j];

	int ans = -9*7;
	for (int x = 1; x < 5; x ++)
		for (int y = 1; y < 5; y ++) {
			int sum = arr[x][y];
			for (int i = -1; i <= +1; i ++)
				sum += arr[x - 1][y + i];
			for (int i = -1; i <= +1; i ++)
				sum += arr[x + 1][y + i];
			
			ans = max(ans, sum);
		}

	cout << ans << endl;

	return 0;
}

