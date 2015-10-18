#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N;
map<int, vector<int> > list;
int len = 0;

void DFS(const int v, const int p) {
	cout << (len ++ ? " " : "") << v;

	for (int i = 0; i < (int) list[v].size(); i ++)
		if (list[v][i] != p)
			DFS(list[v][i], v);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++) {
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}

	int start = 0;
	for (map<int, vector<int> >::iterator iter = list.begin(); iter != list.end(); iter ++)
		if (iter->second.size() == 1) {
			start = iter->first;
			break;
		}

	DFS(start, -1);
	cout << endl;

	return 0;
}
