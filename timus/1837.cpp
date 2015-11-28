#include <iostream>
#include <set>
#include <map>
#include <string>
#include <queue>
using namespace std;

int N;
map<string, set<string> > list;
map<string, int> ans;
queue<string> q;

inline void add(const string &v, const int d) {
	q.push(v);
	ans[v] = d;
}

inline void BFS() {
	if (list.count("Isenbaev") > 0)
		add("Isenbaev", 0);

	while (!q.empty()) {
		string v = q.front();
		int d = ans[v];
		q.pop();

		for (set<string>::iterator iter = list[v].begin(); iter != list[v].end(); iter ++)
			if (ans.count(*iter) == 0)
				add(*iter, d + 1);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i ++) {
		string names[3];
		for (int j = 0; j < 3; j ++)
			cin >> names[j];

		list[names[0]].insert(names[1]);
		list[names[0]].insert(names[2]);

		list[names[1]].insert(names[0]);
		list[names[1]].insert(names[2]);

		list[names[2]].insert(names[0]);
		list[names[2]].insert(names[1]);
	}

	BFS();

	for (map<string, set<string> >::iterator iter = list.begin(); iter != list.end(); iter ++) {
		cout << iter->first << " ";
		if (ans.count(iter->first) > 0)
			cout << ans[iter->first];
		else
			cout << "undefined";
		cout << endl;
	}

	return 0;
}

