#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int counts[2] = {0};

int main() {
	cin >> str;

	for (int i = 0; i < (int) str.size(); i ++)
		if (str[i] == 'x')
			counts[0] ++;
		else
			counts[1] ++;
	
	for (int i = 0; i < max(counts[0], counts[1]) - min(counts[0], counts[1]); i ++)
		cout << (counts[0] > counts[1] ? 'x' : 'y');
	cout << endl;

	return 0;
}
