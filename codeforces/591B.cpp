#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int K = 'z' - 'a' + 1;
int N, M;
string str;
int pos[K];
char f[K];

int main() {
	ios::sync_with_stdio(0);

	for (int i = 0; i < K; i ++) {
		pos[i] = i;
		f[i] = i + 'a';
	}

	cin >> N >> M;
	cin >> str;
	for (int i = 0; i < M; i ++) {
		char x, y;
		cin >> x >> y;

		swap(f[pos[x - 'a']], f[pos[y - 'a']]);
		swap(pos[x - 'a'], pos[y - 'a']);
	}
	
	for (int i = 0; i < (int) str.size(); i ++)
		str[i] = f[str[i] - 'a'];
	cout << str << endl;

	return 0;
}

