#include <cstdio>
using namespace std;

int N, Q;
int sum[10000 + 10];

int main() {
	scanf("%d", &N);
	sum[0] = 0;
	int x;
	for (int i = 1; i <= N; i ++) {
		scanf("%d", &x);
		sum[i] = sum[i - 1] + x;
	}

	scanf("%d", &Q);
	int a, b;
	for (int i = 0; i < Q; i ++) {
		scanf("%d%d", &a, &b);
		printf("%d\n", sum[b] - sum[a-1]);
	}
	return 0;
}

