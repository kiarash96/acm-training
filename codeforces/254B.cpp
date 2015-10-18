#include <iostream>
#include <fstream>
using namespace std;

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dist[13] = {0};

int N;
int range[2 * 365] = {0};

int convert(const int year, const int month, const int day) {
	if (month == 1)
		return day + 365 * year - 1;
	return dist[month - 1] + day + 365 * year - 1;
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	for (int i = 1; i < 12; i ++)
		dist[i] = dist[i - 1] + months[i];

	int ans = 0;

	fin >> N;
	for (int i = 0; i < N; i ++) {
		int m, d, p, t;
		fin >> m >> d >> p >> t;

		int day = convert(1, m, d);
		for (int i = day - 1; i >= day - t; i --) {
			range[i] += p;
			ans = max(ans, range[i]);
		}
	}

	fout << ans << endl;

	return 0;
}
