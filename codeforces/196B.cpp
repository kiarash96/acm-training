#include <iostream>
#include <string>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

const int ACTS = 4;
const int actions[ACTS][2] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
const int MaxNM = 1500;
int N, M;
string map[MaxNM];
bool mark[MaxNM][MaxNM] = {{0}};
pii coord[MaxNM][MaxNM];
bool found = false;

inline pii calc_mod(const pii &p) {
	pii res(p.first % N, p.second % M);
	if (res.first < 0)
		res.first += N;
	if (res.second < 0)
		res.second += M;
	return res;
}

void DFS(const pii &v) {
	if (found)
		return;

	pii mod = calc_mod(v);

	mark[mod.first][mod.second] = true;
	coord[mod.first][mod.second] = v;

	for (int i = 0; i < ACTS; i ++) {
		pii child(v.first + actions[i][0], v.second + actions[i][1]);
		pii c_mod = calc_mod(child);

		if (map[c_mod.first][c_mod.second] != '#') {
		   if (!mark[c_mod.first][c_mod.second])
			   DFS(child);
		   else if (coord[c_mod.first][c_mod.second] != child)
			   found = true;
		}
	}
		
}

int main() {
	ios_base::sync_with_stdio(false);

	pii start;

	cin >> N >> M;
	for (int i = 0; i < N; i ++) {
		cin >> map[i];
		int pos = map[i].find('S');
		if (pos != (int) map[i].npos)
			start = pii(i, pos);
	}

	DFS(start);

	cout << (found ? "Yes" : "No") << endl;

	return 0;
}
