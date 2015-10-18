#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

const double RTD = 180.0 / 3.141592653589;

const int MaxN = 1e5;
int N;
double angles[MaxN];

int main() {
	cin >> N;
	for (int i = 0; i < N; i ++) {
		int x, y;
		cin >> x >> y;
		angles[i] = atan2(y, x) * RTD;
		if (angles[i] < 0.0)
			angles[i] += 360.0;
	}

	sort(angles, angles + N);
	N = unique(angles, angles + N) - angles;

	double ans = 0.0;
	for (int i = 0; i < N; i ++) {
		double diff = angles[(i + 1) % N] - angles[i];
		if (diff <= 0.0)
			diff += 360.0;
		ans = max(ans, diff);
	}

	cout << fixed << setprecision(10) << 360.0 - ans << endl;

	return 0;
}
