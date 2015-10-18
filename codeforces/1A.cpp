#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n, m, a;
	cin >> n >> m >> a;
	cout << fixed << setprecision(0) << ceil((double)n / (double)a) * ceil((double)m / (double)a) << endl;
	return 0;
}
