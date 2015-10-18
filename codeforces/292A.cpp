#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

const int MaxT = 1e6;
int N;
int sent[MaxT + 1] = {0};

int main() {
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i ++) {
		int t, c;
		cin >> t >> c;
		sent[t] += c;
	}

	queue<int> Q;
	ll sum = 0LL, last = 0LL, Max = 0LL;

	for (int t = 1; t <= MaxT; t ++) {
		if (Q.size() > 0) {
			last = t;
			if (-- Q.front() <= 0)
				Q.pop();
			sum --;
		}

		if (sent[t] > 0) {
			Q.push(sent[t]);
			sum += sent[t];
			Max = max(Max, sum);
		}
	}

	cout << (sum > 0 ? MaxT + sum : last) << " " << Max << endl;

	return 0;
}
