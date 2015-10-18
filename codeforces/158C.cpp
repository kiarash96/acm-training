#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int N;
vector<string> path;

void changeDir(const string &command) {
	if (command[0] == '/')
		path.clear();

	istringstream ss(command);
	string folder;
	while (getline(ss, folder, '/')) {
		if (folder.size() == 0)
			continue;
		if (folder == "..")
			path.pop_back();
		else
			path.push_back(folder);
	}
}

void print() {
	for (int i = 0; i < (int) path.size(); i ++)
		cout << "/" << path[i];
	cout << "/" << endl;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i ++) {
		string command;
		cin >> command;
		if (command == "pwd")
			print();
		else {
			cin >> command;
			changeDir(command);
		}
	}
	return 0;
}
