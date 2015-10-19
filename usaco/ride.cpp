/*
ID: kia.cel1
PROG: ride
LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

#define cin fin
#define cout fout

int main() {
	ios::sync_with_stdio(0);

	ifstream fin("ride.in");
	ofstream fout("ride.out");

	int mod[2] = {1, 1};
	for (int i = 0; i < 2; i ++) {
		string str;
		cin >> str;
		for (int j = 0; j < (int) str.size(); j ++) 
			mod[i] = (mod[i] * (str[j] - 'A' + 1))%47;
	}

	cout << (mod[0] == mod[1] ? "GO" : "STAY") << endl;

	return 0;
}

