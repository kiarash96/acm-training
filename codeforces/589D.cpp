#include <iostream>
#include <complex>
#include <algorithm>
using namespace std;

#define X real()
#define Y imag()

typedef complex<double> point;

const double EPS = 1e-9;

const int MaxN = 1000;
int N;
pair<point, point> list[MaxN];
int ans[MaxN] = {0};

template<typename T>
inline bool bet(T a, T b, T c) { return a <= b && b <= c; }

inline double zcross(const point &u, const point &v) { return u.X * v.Y - u.Y * v.X; }

inline bool onSameSide(const point &a, const point &b, const point &c, const point &d) {
	return zcross(a - c, d - c) * zcross(b - c, d - c) > 0.0;
}

inline bool intersect(const pair<point, point> &ab, const pair<point, point> &cd) {
	return !onSameSide(ab.first, ab.second, cd.first, cd.second) && !onSameSide(cd.first, cd.second, ab.first, ab.second);
}

int main() {
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i ++) {
		int t, s, f;
		cin >> t >> s >> f;

		list[i].first = point(t, s);
		list[i].second = point(t + abs(f - s), f);

		for (int j = 0; j < i; j ++) {
			if (abs(zcross(list[i].second - list[i].first, list[j].second - list[j].first)) <= EPS
			&&	abs(zcross(list[i].second - list[i].first, list[j].second - list[i].first)) <= EPS) {

					if (bet(list[i].first.X, list[j].first.X, list[i].second.X)
					||	bet(list[j].first.X, list[i].first.X, list[j].second.X))
						ans[i] ++, ans[j] ++;
			} else if (intersect(list[i], list[j]))
				ans[i] ++, ans[j] ++;
		}
	}

	for (int i = 0; i < N; i ++)
		cout << (i == 0 ? "" : " ") << ans[i];
	cout << endl;

	return 0;
}

