#include <iostream>
#include <string>
using namespace std;

int N, K;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	int ans = 0;
	for (int i = 0; i < N; i ++) {
		string num;
		cin >> num;
		
		int k = 0;
		for (int j = 0; j < (int) num.size(); j ++)
			if (num[j] == '4' || num[j] == '7')
				k ++;

		if (k <= K)
			ans ++;
	}

	cout << ans << endl;

	return 0;
}
