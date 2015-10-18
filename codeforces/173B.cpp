#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

struct State {
	int x, y;
	int dir;
	int depth;
	State(const int x, const int y, const int dir, const int depth) : x(x), y(y), dir(dir), depth(depth) { }
};

const int ACTS = 4;
const int actions[ACTS][2] = {{0, -1}, {0, +1}, {-1, 0}, {+1, 0}};
const int MaxNM = 1000;
int N, M;
string map[MaxNM];
bool mark[MaxNM][MaxNM][ACTS] = {{{0}}};
bool found = false;
deque<State> Q;

inline bool bet(const int value, const int begin, const int end) {
	return begin <= value && value < end;
}

inline State doAction(const State &state, const int act) {
	State res = state;
	res.x += actions[act][0]; res.y += actions[act][1];
	return res;
}

inline void add(const State &state, bool front) {
	mark[state.x][state.y][state.dir] = true;
	if (front)
		Q.push_front(state);
	else
		Q.push_back(state);
}

inline int BFS() {
	add(State(N - 1, M - 1, 0, 0), false);

	while (!Q.empty()) {
		State state = Q.front();
		Q.pop_front();

		if (state.x == 0 && state.y == 0 && state.dir == 0)
			return state.depth;

		State child = doAction(state, state.dir);
		if (bet(child.x, 0, N) && bet(child.y, 0, M) && !mark[child.x][child.y][child.dir])
			add(child, true);

		if (map[state.x][state.y] == '#')
			for (int i = 0; i < ACTS; i ++) {
				child = state;
				child.dir = i;
				child.depth = state.depth + 1;
				if (!mark[child.x][child.y][i])
					add(child, false);
			}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i ++) 
		cin >> map[i];

	cout << BFS() << endl;

	return 0;
}
