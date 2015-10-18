#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	string str, ans;
	int x;

	cin >> str >> x;

	for (int i = 0; i < (int) str.size(); i ++)
		if ((int) tolower(str[i]) < x + 97)
			ans.push_back(toupper(str[i]));
		else
			ans.push_back(tolower(str[i]));

	cout << ans << endl;

	return 0;
}
