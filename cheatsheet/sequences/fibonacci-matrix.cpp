/*
 * Calculate nth fibonacci number in O(logn)
 */

#include <iostream>
using namespace std;

typedef long long ll;

template<typename T>
struct Matrix {
	T arr[2][2];
	inline T* operator[] (int ind) { return arr[ind]; }

	inline Matrix operator*(Matrix b) {
		Matrix res;
		res[0][0] = arr[0][0]*b[0][0] + arr[0][1]*b[1][0];		res[0][1] = arr[0][0]*b[0][1] + arr[0][1]*b[1][1];
		res[1][0] = arr[1][0]*b[0][0] + arr[1][1]*b[1][0];		res[1][1] = arr[1][0]*b[0][1] + arr[1][1]*b[1][1];
		return res;
	}

	inline Matrix pow(ll n) {
		if (n == 1)
			return (*this);
		
		Matrix m = this->pow(n/2);

		Matrix res;
		if (n % 2 == 0)
			res = m*m;
		else
			res = m*m*(*this);

		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);

	Matrix<ll> mat = {{{1, 1},
							  {1, 0}}};

	ll n;
	cin >> n;

	cout << mat.pow(n)[0][1] << endl;

	return 0;
}

