#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <locale>
using namespace std;

const int MIN = 2013, MAX = 2015;

const int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dist[13] = {0};

struct Date {
	int year, month, day;

	Date() { year = month = day = 0; }

	Date(int n) {
		n ++;
		year = month = day = 0;
		while (n > 365) {
			n -= 365;
			year ++;
		}

		for (int i = 0; i < 13; i ++)
			if (n > dist[i])
				month = i + 1;

		day = n - dist[month - 1];
	}

	int toInt() {
		return dist[month - 1] + day + 365 * year;
	}

	friend ostream& operator<< (ostream &output, const Date &date) {
		return output << setw(2) << setfill('0') << date.day << "-" << setw(2) << setfill('0') << date.month << "-" << MIN + date.year;
	}

	bool isValid() const {
		return 0 <= year && year < 3 && 1 <= month && month < 13 && 1 <= day && day <= months[month];
	}
};

string input;
int freq[3 * 365 + 1] = {0};

inline int strToInt(const string &str) {
	stringstream ss(str);
	int res;
	ss >> res;
	return res;
}

void parse(const string &str) {
	Date date;
	
	string strs[3];
	strs[0] = str.substr(0, 2), strs[1] = str.substr(3, 2), strs[2] = str.substr(6, 4);

	bool ok = true;
	for (int i = 0; i < 3; i ++)
		for (int j = 0; j < (int) strs[i].size(); j ++)
			if (!isdigit(strs[i][j]))
				ok = false;
	if (!ok || str[2] != '-' || str[5] != '-')
		return;

	date.day = strToInt(strs[0]);
	date.month = strToInt(strs[1]);
	date.year = strToInt(strs[2]) - MIN;

	if (date.isValid())
		freq[date.toInt()] ++;
}

int main() {
	for (int i = 1; i < 13; i ++)
		dist[i] = dist[i - 1] + months[i];

	cin >> input;

	const int LEN = 10;
	for (int i = 0; i + LEN <= (int) input.size(); i ++)
		parse(input.substr(i, LEN));

	int ans = 0, mFreq = 0;
	for (int i = 0; i < 3 * 365 + 1; i ++)
		if (freq[i] > mFreq) {
			mFreq = freq[i];
			ans = i;
		}

	cout << Date(ans - 1) << endl;

	return 0;
}
