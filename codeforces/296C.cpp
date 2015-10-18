#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Query {
	int left, right;
	ll value;
	Query() { }
};

const int MaxN = 1e5;
int N, M, K;
ll arr[MaxN] = {0}, res[MaxN];
Query op[MaxN], q[MaxN];

inline void calc(Query *query, const int size) {
	fill(res, res + MaxN, 0);

	for (int i = 0; i < size; i ++) {
		res[query[i].left] += query[i].value;
		if (query[i].right + 1 < MaxN)
			res[query[i].right + 1] -= query[i].value;
	}

	for (int i = 1; i < MaxN; i ++)
		res[i] += res[i - 1];
}

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i ++)
		cin >> arr[i];
	for (int i = 0; i < M; i ++) {
		cin >> op[i].left >> op[i].right >> op[i].value;
		op[i].left --; op[i].right --;
	}
	for (int i = 0; i < K; i ++) {
		cin >> q[i].left >> q[i].right;
		q[i].left --; q[i].right --;
		q[i].value = 1;
	}

	calc(q, K);
	for (int i = 0; i < M; i ++)
		op[i].value *= res[i];
	
	calc(op, M);
	for (int i = 0; i < N; i ++)
		arr[i] += res[i];

	for (int i = 0; i < N; i ++)
		cout << (i == 0 ? "" : " ") << arr[i];
	cout << endl;

	return 0;
}
