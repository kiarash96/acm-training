#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MaxAi = 5000 + 1;
int N;
vector<vector<int> > indices(MaxAi, vector<int>());

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	fin >> N;
	for (int i = 0; i < 2 * N; i ++) {
		int x;
		fin >> x;
		indices[x].push_back(i);
	}

	bool ok = true;
	for (int i = 0; i < MaxAi; i ++)
		if ((int) indices[i].size() > 0 && indices[i].size() % 2 == 1)
			ok = false;

	if (ok) {
		for (int i = 0; i < MaxAi; i ++)
			for (int j = 0; j < (int) indices[i].size(); j += 2)
				fout << indices[i][j] + 1 << " " << indices[i][j + 1] + 1 << endl;
	} else
		fout << -1 << endl;

	return 0;
}
