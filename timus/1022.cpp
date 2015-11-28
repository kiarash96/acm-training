#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int> > list;
vector<int> indegree;

int main() {
	cin >> N;
	list.resize(N);
	indegree.resize(N, 0);
	for (int i = 0; i < N; i ++) {
		int v;
		while (cin >> v) {
			if (v == 0)
				break;
			v --;
			list[i].push_back(v);
			indegree[v] ++;
		}
	}

	queue<int> q;
	vector<int> ans;

	for (int i = 0; i < N; i ++)
		if (indegree[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		ans.push_back(v);

		for (int i = 0; i < (int) list[v].size(); i ++)
			if (-- indegree[list[v][i]] == 0)
				q.push(list[v][i]);
	}

	for (int i = 0; i < N; i ++)
		cout << (i == 0 ? "" : " ") << ans[i] + 1;
	cout << endl;

	return 0;
}

