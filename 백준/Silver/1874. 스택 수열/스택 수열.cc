#include <iostream>
using namespace std;
#include <string>
#include <stack>
string solution() {
	stack <int> st;
	int n; cin >> n;

	int current = 1;
	string result="";
	for (int i = 0; i < n; i++) {
		int num; cin >> num;

		while (current <= num) {
			st.push(current++);
			result += "+\n";
		}
		if (!st.empty() && st.top() == num) {
			st.pop();
			result += "-\n";
		}
		else {
			return "NO";
		}
	}
	return result;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// push : +, pop: -

	cout << solution();
}
