#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;

	deque<int> dq;
	for (int tc = 0; tc < N; tc++) {
		string command; cin >> command;
		
		if (command == "push_front") {
			int X; cin >> X;
			dq.push_front(X);
		}
		else if (command == "push_back") {
			int X; cin >> X;
			dq.push_back(X);
		}
		else {
			int result;
			if (command == "pop_front") {
				if (!dq.empty()) {
					result = dq.front();
					dq.pop_front();
				}
				else result = -1;
			}
			else if (command == "pop_back") {
				if (!dq.empty()) {
					result = dq.back();
					dq.pop_back();
				}
				else result = -1;
			}
			else if (command == "size") {
				result = dq.size();
			}
			else if (command == "empty") {
				result = dq.empty();
			}
			else if (command == "front") {
				if (!dq.empty()) {
					result = dq.front();
				}
				else result = -1;
			}
			else if (command == "back") {
				if (!dq.empty()) {
					result = dq.back();
				}
				else result = -1;
			}
			cout << result << endl;
		}
	}
}