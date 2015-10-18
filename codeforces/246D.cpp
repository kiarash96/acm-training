#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <utility>
using namespace std;

int N, M;
vector<int> color;
map<int, set <int> > q;

int main() {
	cin >> N >> M;
	color.resize(N);
	for (int i = 0; i < N; i ++) {
		cin >> color[i];
		q.insert(make_pair(color[i], set<int>()));;
		q[color[i]].insert(color[i]);
	}

	for (int i = 0; i < M; i ++) {
		int u, v;
		cin >> u >> v;
		u --;
		v --;
		if (color[u] != color[v]) {
			q[color[u]].insert(color[v]);
			q[color[v]].insert(color[u]);
		}
	}
	
	int maxQ = 0, res = 0;
	for (map<int, set<int> >::iterator iter = q.begin(); iter != q.end(); iter ++)
		if ((int) iter->second.size() > maxQ) {
			maxQ = iter->second.size();
			res = iter->first;
		} else if ((int) iter->second.size() == maxQ && iter->first < res)
			res = iter->first;

	cout << res << endl;
	return 0;
}
