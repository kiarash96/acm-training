#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <locale>
using namespace std;

#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(0);

	int cnt = 0;
	string m2, m1;
	string str;
	while (cin >> str) {
		if (str == "END")
			break;
		else if (str == "GetFinal")
			cout << m2 << endl;
		else {
			if (cnt == 0)
				m1 = str;
			else if (cnt == 1) {
				m2 = min(m1, str);
				m1 = max(m1, str);
			} else {
				if (str > m1) {
					m2 = m1;
					m1 = str;
				} else if (str > m2)
					m2 = str;
			}
			cnt ++;
		}
	}

	return 0;
}

