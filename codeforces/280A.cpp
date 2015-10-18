#include <iostream>
#include <complex>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#define X real()
#define Y imag()

typedef complex<double> point;

inline double zcross(const point &u, const point &v) { return u.X * v.Y - v.X * u.Y; }

const double EPS = 1e-8;
double W, H, alpha;
point vertex[2][4];
vector<point> list;

inline void intersect(const point &A, const point &B, const point &C, const point &D) {
	point AB = B - A, CD = D - C;
	point AC = C - A;
	double div = zcross(AB, CD);
	if (-EPS < div && div < EPS)
		return;

	double alpha = zcross(AC, CD) / div;
	if (-EPS < alpha && alpha < 1.0 + EPS)
		list.push_back(A + alpha * AB);
}

inline bool cmp(const point &A, const point &B) {
	return zcross(A - list[0], B - list[0]) > EPS;
}

int main() {
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(8);

	cin >> W >> H >> alpha;

	if (alpha == 0.0 || alpha == 180.0) {
		cout << W * H << endl;
		return 0;
	}

	vertex[0][0] = point(-W/2, -H/2);
	vertex[0][1] = point(+W/2, -H/2);
	vertex[0][2] = point(+W/2, +H/2);
	vertex[0][3] = point(-W/2, +H/2);

	for (int i = 0; i < 4; i ++)
		vertex[1][i] = vertex[0][i] * exp(point(0, alpha / 180.0 * M_PI));

	for (int i = 0; i < 4; i ++)
		for (int j = 0; j < 4; j ++)
			intersect(vertex[0][i], vertex[0][(i + 1) % 4], vertex[1][j], vertex[1][(j + 1) % 4]);

	sort(list.begin(), list.end(), cmp);

	double area = 0;
	for (int i = 0; i < (int) list.size(); i ++)
		area += zcross(list[i], list[(i + 1) % list.size()]);

	cout << area / 2.0 << endl;

	return 0;
}
