#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <queue>
#include <set>

using namespace std;
string solution(string input) {
	stack<char> st;
	stack<char> big;

	for (char ch : input) {
		if (ch == '(' || ch == '[') {
			st.push(ch);
		}
		else if (ch == ')') {
			if (st.empty() || st.top() != '(') return "no";
			st.pop();
		}
		else if (ch == ']') {
			if (st.empty() || st.top() != '[') return "no";
			st.pop();
		}
	}
	return (st.empty()) ? "yes" : "no";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input; getline(cin,input);

	while (input != ".") {
		cout << solution(input) << endl;


		getline(cin, input);
	}
}