#include <iostream>
#include <iomanip>
using namespace std;

typedef long long ll;

const int MaxN = 20;
ll C[MaxN + 1][MaxN + 1];
ll fact[MaxN + 1];

int main() {
	ios::sync_with_stdio(0);

	for (int i = 0; i <= MaxN; i ++) {
		C[i][0] = 0LL;
		C[0][i]= 1LL;
	}

	for (int j = 1; j <= MaxN; j ++)
		for (int i = 1; i <= MaxN; i ++)
			C[i][j] = C[i - 1][j - 1] + C[i][j - 1];

	fact[0] = 1LL;
	for (int i = 1; i <= MaxN; i ++)
		fact[i] = i * fact[i - 1];

	int T;
	cin >> T;
	for (int t = 0; t < T; t ++) {
		int N;
		cin >> N;
		ll sum = 0;
		for (int i = 0; i < N; i ++) {
			int x;
			cin >> x;
			sum += x;
		}

		ll a = 0LL, b = 0LL;
		for (int i = 1; i <= N; i ++) {
			a += C[i - 1][N - 1] * fact[i];
			b += C[i][N] * fact[i];
		}

		cout << fixed << setprecision(6) << sum * ((long double)a/b) << endl;
	}

	return 0;
}

