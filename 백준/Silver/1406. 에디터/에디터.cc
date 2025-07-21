#include <iostream>
using namespace std;
#include <string>
#include <deque>
int main() {
	string str; cin >> str;
	int M; cin >> M;
	deque<char> left;
	for (int i = 0; i < str.size(); i++) {
		left.push_back(str[i]);
	}

	deque<char> right;
	for (int t = 0; t < M; t++) {
		char command; cin >> command;
		if (command == 'L') {
			if (!left.empty()) {
				right.push_front(left.back());
				left.pop_back();
			}
		}
		else if (command == 'D') {
			if (!right.empty()) {
				left.push_back(right.front());
				right.pop_front();
			}
		}
		else if (command == 'B') {
			if (!left.empty()) {
				left.pop_back();
			}
		}
		else {
			char ch; cin >> ch;
			left.push_back(ch);
		}
	}
	for (int i = 0; i < left.size(); i++) {
		cout << left[i];
	}
	for (int i = 0; i < right.size(); i++) {
		cout << right[i];
	}
}
