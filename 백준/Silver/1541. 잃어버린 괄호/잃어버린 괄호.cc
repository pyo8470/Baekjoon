#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>;
using namespace std;


vector<int> num;
vector<char> oper;
void init(string input) {
	string temp = "";
	for (char ch : input) {
		if (isdigit(ch)) {
			temp += ch;
		}
		else {
			oper.push_back(ch);
			num.push_back(stoi(temp));
			temp = "";
		}
	}
	num.push_back(stoi(temp));
}
int main() {
	string input; cin >> input;
	init(input);
	// - 뒤에 또 - 나오기 전까지 쭉 괄호로 묶기
	
	
	int result = num[0];

	bool minusmode = false;
	for (int i = 0; i < oper.size();i++) {
		if (oper[i] == '-') {
			minusmode = true;
		}

		if (minusmode) {
			result -= num[i + 1];
		}
		else {
			result += num[i + 1];
		}
	}
	cout << result;
}