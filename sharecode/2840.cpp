#include <iostream>
#include <iomanip>
#include <complex>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef complex<ld> point;

#define X real()
#define Y imag()

const int MaxN = 1000 * 1000;

int N;
point vertex[MaxN + 2];
int hull[MaxN + 2];

inline ld zcross(point u, point v) { return u.X * v.Y - u.Y * v.X; }
inline ld ccw(int O, int A, int B) { return zcross(vertex[A] - vertex[O], vertex[B] - vertex[O]); }

int main() {
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while (T --) {
		cin >> N;

		vertex[0] = point(0.0, 0.0);
		vertex[N + 1] = point(N + 1, 0.0);
		for (int i = 1; i <= N; i ++) {
			int height;
			cin >> height;
			vertex[i] = point(i, height);
		}

		int k = 0;
		for (int i = 0; i <= N + 1; i ++) {
			while (k >= 2 && ccw(hull[k - 2], hull[k - 1], i) >= 0.0) k --;
			hull[k ++] = i;
		}

		ld len = 0.0;
		for (int i = 1; i < k; i ++)
			len += abs(vertex[hull[i]] - vertex[hull[i - 1]]);

		cout << fixed << setprecision(7) << len << endl;
	}

	return 0;
}

