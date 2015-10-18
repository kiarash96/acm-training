#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MaxN = 52;
typedef vector<string> State;

const int ACTS = 2;
const int actions[ACTS] = {1, 3};

int N;
State start;

set<State> mark;

bool DFS(const State &state) {
	mark.insert(state);

	if (state.size() == 1)
		return true;

	int n = state.size();

	bool res = false;
		for (int i = 0; i < ACTS; i ++) {
			int ind = n - actions[i] - 1;
			if (ind >= 0 && (state[n - 1][0] == state[ind][0] || state[n - 1][1] == state[ind][1])) {
				State child = state;
				child[ind] = state[n - 1];
				child.pop_back();

				if (mark.count(child) == 0)
					res |= DFS(child);
			}
		}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	start.resize(N);
	for (int i = 0; i < N; i ++)
		cin >> start[i];

	cout << (DFS(start) ? "YES" : "NO") << endl;

	return 0;
}
