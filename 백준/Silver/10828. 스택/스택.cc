#include <iostream>
using namespace std;
#include <string>
#include <stack>
int main() {
	int N; cin >> N;

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack<int> stk;
	for (int t = 0; t < N; t++) {
		string command; cin >> command;
		if (command == "push") {
			int x; cin >> x;
			stk.push(x);
		}
		else if (command == "pop") {
			if (stk.empty()) cout << -1 << endl;
			else {
				cout << stk.top() << endl;;
				stk.pop();
			}
		}
		else if (command == "size") {
			cout << stk.size() << endl;
		}
		else if (command == "empty") {
			stk.empty() ? cout << 1 << endl : cout << 0 << endl;
		}
		else {
			if (stk.empty()) cout << -1 << endl;
			else {
				cout << stk.top() <<endl;
			}
		}
	}
}
