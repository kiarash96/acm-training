#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>
using namespace std;

int main() {
	stack<double> stack;
	long long int a;
	while(cin >> a)
		stack.push(sqrt((double)a));
	cout << fixed << setprecision(4);
	while(!stack.empty()) {
		cout << stack.top() << endl;
		stack.pop();
	}
	return 0;
}

