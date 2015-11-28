#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Team {
	int id, score;
};

bool cmp(const Team &first, const Team &second) {
	return first.score > second.score;
}

int N;
vector<Team> teams;

int main() {
	cin >> N;
	teams.resize(N);
	for (int i = 0; i < N; i ++)
		cin >> teams[i].id >> teams[i].score;

	stable_sort(teams.begin(), teams.end(), cmp);

	for (int i = 0; i < N; i ++)
		cout << teams[i].id << " " << teams[i].score << endl;

	return 0;
}

