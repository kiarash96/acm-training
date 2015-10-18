#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int X, Y, A, B;
vector<pair<int, int> > res;

int main() {
	cin >> X >> Y >> A >> B;
	
	for (int i = A; i <= X; i ++)
		for (int j = B; j <= Y; j ++)
			if (i > j)
				res.push_back(make_pair(i, j));

	cout << res.size() << endl;
	for (int i = 0; i < (int) res.size(); i ++)
		cout << res[i].first << " " << res[i].second << endl;

	return 0;
}
