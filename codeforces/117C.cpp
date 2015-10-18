#include <iostream>
#include <string>
using namespace std;

const int MaxN = 5000;
int N;
string matrix[MaxN];
bool mark[MaxN] = {0};
bool found = false;

void DFS(const int v, const int p) {
	if (found)
		return;

	mark[v] = true;
	for (int i = 0; i < N; i ++)
		if (matrix[v][i] == '1') {
			if (!mark[i])
				DFS(i, v);
			else if (matrix[i][p] == '1' && !found) {
				cout << p + 1 << " " << v + 1 << " " << i + 1 << endl;
				found = true;
			}
		}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i ++)
		cin >> matrix[i];
	
	for (int i = 0; i < N; i ++)
		if (!mark[i])
			DFS(i, -1);

	if (!found)
		cout << -1 << endl;

	return 0;
}
