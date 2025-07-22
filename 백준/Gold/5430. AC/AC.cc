#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>

void parsing(deque<int>& dq, string input);
string solution();
string solution() {
	string command; cin >> command;
	int n; cin >> n;
	string input; cin >> input;
	deque<int> dq;
	
	parsing(dq,input);
	
	bool isReversed = false;
	for (int i = 0; i < command.size(); i++) {
		if (command[i] == 'R') {
			isReversed = !isReversed;
		}
		else{
			if (isReversed) {
				if (dq.empty()) return "error";
				dq.pop_back();
			}
			else {
				if (dq.empty()) return "error";
				dq.pop_front();
			}
		}
	}
	string result = "[";
	int length = dq.size();
	if (isReversed) {
		for (int i = length-1; i >= 0 ; i--) {
			if (i != 0) {
				result += (to_string(dq[i])+",");
			}
			else {
				result += to_string(dq[i]);
			}
		}
	}
	else {
		for (int i = 0; i < length; i++) {
			if (i != length-1) {
				result += (to_string(dq[i]) + ",");
			}
			else {
				result += to_string(dq[i]);
			}
		}
	}
	result += "]";
	return result;
}

void parsing(deque<int> &dq,string input) {
	string k = "";
	for (int i = 0; i < input.size(); i++) {
		if (isdigit(input[i])) {
			k += input[i];
		}
		else {
			if (!k.empty()) {
				dq.push_back(stoi(k));
				k = "";
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		cout << solution() << endl;
	}
}