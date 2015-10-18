#include <iostream>
#include <iomanip>
using namespace std;

typedef long long ll;

const int MaxN = 2 * 1e5 + 1;
int Q;
int arr[MaxN] = {0}, carry[MaxN] = {0};
ll sum = 0;
int size = 1;

int main() {
	ios::sync_with_stdio(false);

	cin >> Q;
	for (int i = 0; i < Q; i ++) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, x; // Add x to a elements
			cin >> a >> x;
			carry[a - 1] += x;
			sum += a * x;
		} else if (t == 2) {
			int x;
			cin >> x;
			arr[size ++] = x;
			sum += x;
		} else if (t == 3) {
			size --;
			sum -= carry[size] + arr[size];
			if (size - 1 >= 0)
				carry[size - 1] += carry[size];
			arr[size] = carry[size] = 0;
		}

		cout << fixed << setprecision(8) << (double) sum / size << endl;
	}

	return 0;
}
