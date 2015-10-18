#include <iostream>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int ACTS = 4;
const int actions[ACTS][2] = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

int N;
pii start, goal;

inline bool bet(const int value, const int begin, const int end) {
	return begin <= value && value <= end;
}

inline bool isValid(const pii &pos) {
	return bet(pos.first, 0, N) && bet(pos.second, 0, N) && 
		(pos.first == 0 || pos.first == N || pos.second == 0 || pos.second == N);
}

struct State {
	pii pos, par;
	int depth;
	State(const pii &pos, const pii &par, const int depth) : pos(pos), par(par), depth(depth) { }
};

queue<State> q;

int BFS() {
	q.push(State(start, start, 0));

	while (!q.empty()) {
		State state = q.front();
		q.pop();

		if (state.pos == goal)
			return state.depth;

		for (int i = 0; i < ACTS; i ++) {
			State child(state.pos, state.pos, state.depth + 1);
			child.pos.first += actions[i][0]; child.pos.second += actions[i][1];
			if (isValid(child.pos) && child.pos != state.par)
				q.push(child);
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> start.first >> start.second >> goal.first >> goal.second;

	cout << BFS() << endl;

	return 0;
}
