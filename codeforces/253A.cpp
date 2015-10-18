#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int N, M;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string res;

	fin >> N >> M;

	bool bg = max(N, M) == N;

	for (int i = 0; i < min(N, M); i ++)
		fout << (bg ? "BG" : "GB");

	char left = (max(N, M) == N ? 'B' : 'G');

	for (int i = 0; i < max(N, M) - min(N, M); i ++)
		fout << left;

	fout << endl;

	return 0;
}
