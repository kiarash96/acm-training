#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string names[3] = {"chest", "biceps", "back"};
int counts[3] = {0};
int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i ++) {
		int x;
		cin >> x;
		counts[i % 3] += x;
	}

	int index = max_element(counts, counts + 3) - counts;
	cout << names[index] << endl;

	return 0;
}
